#include "bt_key_deal.h"
#include "rtos/os_api.h"
#include "common/msg.h"
#include "common/app_cfg.h"
#include "bluetooth/avctp_user.h"
#include "rtos/task_manage.h"
#include "play_sel/play_sel.h"
#include "dec/decoder_phy.h"
#include "ui/led/led.h"
#include "dac/dac_api.h"
#include "dac/dac.h"
#include "ui/ui_api.h"
#include "bt_key_msg.h"
#include "key_drv/key.h"
#include "bt_ui.h"
#include "dac/eq_api.h"
#include "sys_detect.h"
#include "dac/eq.h"
#include "rcsp/rcsp_interface.h"
#include "encode/encode.h"
#include "led7_drv.h"
#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif

#define BT_REC_Hz  120000000L

RECORD_OP_API * rec_bt_api = NULL;
//REVERB_API_STRUCT * bt_reverb = NULL;
u8 test_flag=0;
BT_DIS_VAR bt_ui_var;
#include "vm/vm_api.h"

//***************************************

#if defined(support_bt_waiting_conn_filsh_led)
extern  u8 bt_line_mode;
#endif

#ifdef support_bt_pause_mute_amp
u8   bt_pause_mute_delay;
#endif
#if defined(support_bt_DISCONNECT_mute_amp)
u8 bBtDiscnnectMuteCnt;
#endif
#ifdef SUPPORT_BT_PLAY_PAUSE_VOICE				
bool bBtPlayPauseState; // 0-pause  1-play						
#endif

bool bBtConnectFlag;
#ifdef SUPPORT_BT_AUTO_BACK_CONNECT
u8 bBtAutoBackConnectCnt;		 			 
#endif	
#ifdef support_mute_led_all_flish
extern bool  mute_flag;
#endif
#ifdef SUPPORT_BT_FIRST_CONNECT_AUTO_PLAY
 bool  bFirstAutoPlayFlag;
#endif
#ifdef SUPPORT_BT_DISCONNECT_AUTO_STANDBY
u8 bBtDisconnectAutoStandbyCnt;
#endif	

#ifdef SUPPORT_SCG_VOICE
	bool bVoiceOnoff;
#endif




//***************************************
struct user_ctrl
{
    u8 is_phone_number_come;
    u8 play_phone_number_flag;
    u8 phone_prompt_tone_playing_flag;
    u8 phone_num_len;
    u8 income_phone_num[30];
    u8 user_cmd_param_buf[30];
    u8 bt_eq_mode;
    void* tone_by_file_name;
    u8 auto_connection_counter;
    u16 auto_shutdown_cnt;
};

#ifdef HAVE_MALLOC
_PLAY_SEL_PARA *psel_p = NULL;
#else
_PLAY_SEL_PARA __psel_p;
#define psel_p (&__psel_p)
#endif

static struct user_ctrl __user_val sec_used(.ram1_data);
#define user_val (&__user_val)

extern tbool mutex_resource_apply(char *resource,int prio,void (*apply_response)(), void (*release_request)());
extern void set_poweroff_wakeup_io();
extern void set_poweroff_wakeup_io_handle_register(void (*handle)(),void (*sleep_io_handle)(),void (*sleep_handle)());
extern u8 a2dp_get_status(void);
OS_MUTEX tone_manage_semp ; //= OS_MUTEX_INIT();

u8 get_bt_eq_mode(void)
{
    return user_val->bt_eq_mode;
}

void create_bt_msg_task(char *task_name)
{
    u32 err;
    err = os_task_create(TaskBtMsgStack,(void *)0,TaskBTMSGPrio,30,task_name);
    if(OS_NO_ERR != err)
    {
        puts("create bt msg fail\n");
        while(1);
    }
}

/*提示音开始，资源管理线程接口，用户不能调用*/
static void tone_mutex_play()
{
#if(BT_MODE!=NORMAL_MODE)
    return;
#endif
    puts("tone_mutex_play\n");
    play_sel("resourse",'A',psel_p);
    if(psel_p->max_file_number > 3) //报号开始
    {
        user_val->play_phone_number_flag = 1;
    }

    free_fun((void **)&psel_p);
    os_sem_post(&tone_manage_semp);
}

/*资源管理线程接口，用户不能调用*/
static void tone_mutex_stop()
{
#if(BT_MODE!=NORMAL_MODE)
    return;
#endif
    play_sel_stop();
    dac_channel_on(BT_CHANNEL, FADE_ON);

#ifdef SUPPORT_MODE_MAX_VOL_SINGLE_ADJUST
	set_max_dac_vol(BT_ANALOG_VOL_MAX_L, BT_ANALOG_VOL_MAX_R, BT_DIGITAL_VOL_MAX_L,BT_DIGITAL_VOL_MAX_R);
#endif
	
    #if NOTICE_VOICE_VOL_DEFAULT
	    set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_ON);
    #endif
	
	 #ifdef LED_SHOW_VOL_MAX
	  	 #if defined AUX_VOL_MAX||defined  MP3_VOL_MAX	  	 
	  	 	dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
	  	 	dac_ctl.sys_vol_r=dac_ctl.sys_vol_l;	  		
	  		set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_ON);
	  	 #endif
	 #endif

 	#if SUPPORT_ALL_VOICE		
 	 #ifdef SUPPORT_MUTE_VOICE
 	 #ifdef support_mute_led_all_flish
              if(mute_flag)
              	{
 			 #if defined(PA_ENABLE)
 			 	pa_mute();
 			 #endif
 			 	dac_mute(1,1);		 
 		}
 	 #endif				 	 		            
 	 #endif				 	 		            
 	 #endif				 	 		            
	
    puts("tone_mutex_stop\n");
    if( user_val->play_phone_number_flag == 1)
    {
        //来电报号提示音播完后要播要循环播提示声
        user_val->play_phone_number_flag = 0;
        update_bt_current_status(NULL, BT_STATUS_PHONE_INCOME, 0);
    }

	
}

/*获取到来电电话号码，用于报号功能*/
void hook_hfp_incoming_phone_number(char* number, u16 length)
{

    if(user_val->is_phone_number_come == 0)
    {
        puts("phone_number\n");
        put_buf((u8 *)number,length);
        user_val->is_phone_number_come = 1;
        user_val->phone_num_len = length;
        memcpy(user_val->income_phone_num,number,length);
#if BT_PHONE_NUMBER
        update_bt_current_status(NULL, BT_STATUS_PHONE_NUMBER,0);
#endif
    }
    //put_buf(user_val->income_phone_num,user_val->phone_num_len);
}


/*封装函数根据状态选择提示音*/
void user_ctrl_prompt_tone_play(u8 status,void *ptr)
{
    u8* buf_addr = NULL;
    u32 need_buf;
	
#if(BT_MODE!=NORMAL_MODE)
    return;
#endif

    if((bt_power_is_poweroff_post() && (status != BT_STATUS_FIRST_DISCONNECT))
            ||is_bt_in_background_mode())  //background not play tone
    {
        return;
    }
    puts("play_tone\n");
    if(get_remote_test_flag()&&(status == BT_STATUS_FIRST_CONNECTED))   //测试盒测试不播放提示音
    {
        return;
    }

    if((going_to_pwr_off == 1) && (status != BT_STATUS_POWER_OFF))   //软关机的时候只播关机提示音
    {
        puts("-----------powering off---------\n");
        return;
    }

    os_sem_pend(&tone_manage_semp,0);
    if(play_sel_busy())
    {
        play_sel_stop();
        puts("------------play_sel_stop----------\n");
    }
#ifdef support_bt_pause_mute_amp
    pa_umute();
    bt_pause_mute_delay=8;
    //	dac_mute(0,1);
#endif

#if defined(support_bt_DISCONNECT_mute_amp)

if(status==BT_STATUS_POWER_ON)
    bBtDiscnnectMuteCnt=6;
else
    bBtDiscnnectMuteCnt=9;	
    pa_umute();
#endif

 	#if SUPPORT_ALL_VOICE		
 	 #ifdef SUPPORT_MUTE_VOICE
 	 #ifdef support_mute_led_all_flish
              if(mute_flag)
              	{
 			 #if defined(PA_ENABLE)
 			 	pa_umute();
 			 #endif
 			 	dac_mute(0,1);		 
 		}
 	 #endif				 	 		            
 	 #endif				 	 		            
 	 #endif				 	 		            

    need_buf = sizeof(_PLAY_SEL_PARA) + 30*4;//30 file_name*sizeof(int)

    buf_addr = malloc_fun(buf_addr, need_buf, 0);

    if(buf_addr == NULL)
    {
        return ;
    }

    memset(buf_addr, 0x00, need_buf);

    psel_p = (_PLAY_SEL_PARA *)buf_addr;//malloc_fun(psel_p ,sizeof(_PLAY_SEL_PARA),0);
    buf_addr+= sizeof(_PLAY_SEL_PARA);
    psel_p->file_name = (void *)(buf_addr);//malloc_fun(psel_p->file_name,30*4,0); //电话号码至少需要11，国际号码可能很多位
    switch(status)
    {
    
    case BT_STATUS_POWER_ON:
        psel_p->max_file_number = 1;
        psel_p->delay = 10;
        psel_p->rpt_time = 1;
        //psel_p->file_name[0] = BPF_BT_MP3;

#if BT_HID_INDEPENDENT_MODE || USER_SUPPORT_PROFILE_HID

        if(__get_hid_independent_flag())
        {
            //HID独立提示音
            psel_p->file_name[0] = BPF_INIT_HID_MP3;
        }
        else
#endif
        {
		 #ifdef SUPPORT_VOICE_OFF_BT_USE_TY_VOICE        
			#if  SUPPORT_ALL_VOICE
				if(IsVoiceEnable==0)					
			            psel_p->file_name[0] = BPF_BT_NOTICE_MP3;
				else				
		 	#endif
		 #elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			
			if(bModeVoiceSelVal==0)					
		            psel_p->file_name[0] = BPF_BT_NOTICE_MP3;
			else	if(bModeVoiceSelVal==2)					
		            psel_p->file_name[0] = BPF_BT_EN_MP3;
			else
		 #elif defined SUPPORT_DOUBLE_MODE_VOICE	
			if(!bModeVoiceSelFlag)
		             psel_p->file_name[0] = BPF_BT_EN_MP3;
			else				
			
		 #elif defined SUPPORT_MODE_VOICE_ONOFF	
			if(!bModeVoiceOnoffFlag)
		             psel_p->file_name[0] = BPF_BT_NOTICE_MP3;
			else		
		 #elif defined SUPPORT_VOICE_MODE_KEY	
				if(IsVoiceEnable==0)					
			            psel_p->file_name[0] = BPF_BT_NOTICE_MP3;
				else					
		 #endif			
		 
		#if  SUPPORT_ALL_VOICE
		 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
				if(IsVoiceEnable==2)					
			            psel_p->file_name[0] = BPF_BT_EN_MP3;
				else				
		 #endif	
		 
		 #ifdef SUPPORT_SCG_VOICE
			if(bVoiceOnoff)
			            psel_p->file_name[0] = BPF_BT_EN_MP3;
			else
		 #endif

		 
		 #endif


            psel_p->file_name[0] = BPF_BT_MP3;
        }

        break;

    case BT_STATUS_POWER_OFF:
	#if !defined AC6905B_512K			

        psel_p->max_file_number = 1;
        psel_p->delay = 10;
        psel_p->rpt_time = 1;
        psel_p->file_name[0] = BPF_POWER_OFF_MP3;
	#endif
        break;

    case BT_STATUS_RESUME:
        psel_p->max_file_number = 2;
        psel_p->delay = 10;
        psel_p->rpt_time = 1;
        psel_p->file_name[0] = BPF_BT_MP3;

        if(get_curr_channel_state() != 0)
        {
            psel_p->file_name[1] = BPF_CONNECT_MP3;
        }
        else
        {
            psel_p->file_name[1] = BPF_DISCONNECT_MP3;
        }
        break;
    case BT_STATUS_FIRST_CONNECTED:
    case BT_STATUS_SECOND_CONNECTED:
        bt_power_max(0xFF);
        psel_p->max_file_number = 1;
        psel_p->delay = 10;
        psel_p->rpt_time = 1;
#if BT_HID_INDEPENDENT_MODE || USER_SUPPORT_PROFILE_HID
        if(__get_hid_independent_flag())
        {
            //HID独立提示音
            psel_p->file_name[0] = BPF_CONN_HID_MP3;
        }
        else
#endif
        {
		 #ifdef SUPPORT_VOICE_OFF_BT_USE_TY_VOICE        
			#if  SUPPORT_ALL_VOICE
				if(IsVoiceEnable==0)					
			            psel_p->file_name[0] = BPF_CONNECT_NOTICE_MP3;
				else				
		 	#endif
		 #elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			
			if(bModeVoiceSelVal==0)					
		            psel_p->file_name[0] = BPF_CONNECT_NOTICE_MP3;
			else	if(bModeVoiceSelVal==2)					
		            psel_p->file_name[0] = BPF_CONNECT_EN_MP3;
			else

		 #elif defined SUPPORT_DOUBLE_MODE_VOICE	
			if(!bModeVoiceSelFlag)
		             psel_p->file_name[0] = BPF_CONNECT_EN_MP3;
			else				
			
		 #elif defined SUPPORT_MODE_VOICE_ONOFF	
			if(!bModeVoiceOnoffFlag)
		             psel_p->file_name[0] = BPF_CONNECT_NOTICE_MP3;
			else							
		 #elif defined SUPPORT_VOICE_MODE_KEY	
				if(IsVoiceEnable==0)					
			            psel_p->file_name[0] = BPF_CONNECT_NOTICE_MP3;
				else					
		 #endif      
		 
		#if  SUPPORT_ALL_VOICE
		 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
				if(IsVoiceEnable==2)					
			            psel_p->file_name[0] = BPF_CONNECT_EN_MP3;
				else				
		 	#endif	
		 #ifdef SUPPORT_SCG_VOICE
			if(bVoiceOnoff)
			            psel_p->file_name[0] = BPF_CONNECT_EN_MP3;
			else
		 #endif


			
		 #endif
		 
            psel_p->file_name[0] = BPF_CONNECT_MP3;
        }
        break;
    case BT_STATUS_FIRST_DISCONNECT:
    case BT_STATUS_SECOND_DISCONNECT:
		
//        printf("----IsVoiceEnable----:%d\n",IsVoiceEnable);
        
        psel_p->max_file_number = 1;
        psel_p->delay = 10;
        psel_p->rpt_time = 1;
#if BT_HID_INDEPENDENT_MODE || USER_SUPPORT_PROFILE_HID
        if(__get_hid_independent_flag())
        {
            //HID独立提示音
            psel_p->file_name[0] = BPF_DISCON_HID_MP3;
        }
        else
#endif
        {
        
		 #ifdef SUPPORT_VOICE_OFF_BT_USE_TY_VOICE        
			#if  SUPPORT_ALL_VOICE
				if(IsVoiceEnable==0)					
			            psel_p->file_name[0] = BPF_DISCONNECT_NOTICE_MP3;
				else				
		 	#endif
			
		 #elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			
			if(bModeVoiceSelVal==0)					
		            psel_p->file_name[0] = BPF_DISCONNECT_NOTICE_MP3;
			else	if(bModeVoiceSelVal==2)					
		            psel_p->file_name[0] = BPF_DISCONNECT_EN_MP3;
			else
			
		 #elif defined SUPPORT_DOUBLE_MODE_VOICE	
			if(!bModeVoiceSelFlag)
		             psel_p->file_name[0] = BPF_DISCONNECT_EN_MP3;
			else				
			
		 #elif defined SUPPORT_MODE_VOICE_ONOFF	
			if(!bModeVoiceOnoffFlag)
		             psel_p->file_name[0] = BPF_DISCONNECT_NOTICE_MP3;
			else										
		 #elif defined SUPPORT_VOICE_MODE_KEY	
				if(IsVoiceEnable==0)					
			            psel_p->file_name[0] = BPF_DISCONNECT_NOTICE_MP3;
				else					
		 #endif        
		 
		#if  SUPPORT_ALL_VOICE
		 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
				if(IsVoiceEnable==2)					
			            psel_p->file_name[0] = BPF_DISCONNECT_EN_MP3;
				else				
		 	#endif

		 #ifdef SUPPORT_SCG_VOICE
			if(bVoiceOnoff)
			            psel_p->file_name[0] = BPF_DISCONNECT_EN_MP3;
			else
		 #endif

			
		 #endif
		 
           	 psel_p->file_name[0] = BPF_DISCONNECT_MP3;
        }

        break;
    case BT_STATUS_TONE_BY_FILE_NAME:
        psel_p->max_file_number = 1;
        psel_p->delay = 10;
        psel_p->rpt_time = 1;
        psel_p->file_name[0] = user_val->tone_by_file_name;
        break;
    case BT_STATUS_PHONE_INCOME:
	#if !defined AC6905B_512K			
#ifdef support_bt_pause_mute_amp
    {
        pa_umute();
        //	dac_mute(0,1);
    }
#endif
    psel_p->max_file_number = 1;
    psel_p->delay = 10;
    psel_p->rpt_time = 0;
    psel_p->file_name[0] = BPF_RING_MP3;
    user_val->play_phone_number_flag = 0;
    user_val->phone_prompt_tone_playing_flag = 1;
#endif
	
    break;
#if BT_PHONE_NUMBER
    case BT_STATUS_PHONE_NUMBER:
        if(user_val->is_phone_number_come)   //有电话号码就播放
        {
            int i;
            psel_p->max_file_number=0;

            psel_p->delay = 20;
            psel_p->rpt_time = 1;


            for(i = 0; i < user_val->phone_num_len; i++)
            {
                if((user_val->income_phone_num[i] >= 0x30) && (user_val->income_phone_num[i] <= 0x39))
                {
                    psel_p->file_name[psel_p->max_file_number] = tone_number_get_name(user_val->income_phone_num[i] - 0x30);
                    psel_p->max_file_number++;
                }

            }
            user_val->phone_prompt_tone_playing_flag = 1;
            break;//break要放在if里面，不播放直接free了
        }
#endif
    default:
//            free_fun((void **)&psel_p->file_name);
        free_fun((void **)&psel_p);
        return;
    }

    mutex_resource_apply("tone",4,tone_mutex_play,tone_mutex_stop);
    os_sem_pend(&tone_manage_semp,0);
    os_sem_post(&tone_manage_semp);
	
}

/*封装一层方便直接使用文件号播放*/
static void bt_prompt_play_by_name(void * file_name)
{
#ifdef BT_PROMPT_EN         //定义在avctp_user.h
    puts("bt_prompt_play\n");
    user_val->tone_by_file_name = file_name;
    user_ctrl_prompt_tone_play(BT_STATUS_TONE_BY_FILE_NAME, NULL);
#endif

}


static OS_MUTEX spp_mutex;
static inline int spp_mutex_init(void)
{
    return os_mutex_create(&spp_mutex);
}
static inline int spp_mutex_enter(void)
{
    os_mutex_pend(&spp_mutex,0);
    return 0;
}
static inline int spp_mutex_exit(void)
{
    return os_mutex_post(&spp_mutex);
}
static inline int spp_mutex_del(void)
{
    return os_mutex_del(&spp_mutex,OS_DEL_ALWAYS);
}

/*发送串口数据的接口，发送完再返回*/
u32 bt_spp_send_data(u8 *data,u16 len)
{
    u32 err;
    spp_mutex_enter();
    err = user_send_cmd_prepare(USER_CTRL_SPP_SEND_DATA,len,data);
    spp_mutex_exit();
    return err;
}

void bt_spp_disconnect(void)
{
    spp_mutex_enter();
    user_send_cmd_prepare(USER_CTRL_SPP_DISCONNECT,0,0);
    spp_mutex_exit();
}

/*开关可发现可连接的函数接口*/
static void bt_page_scan(u8 enble)
{
    if(enble)
    {
        if(!is_1t2_connection())
        {
            if(enble==2)//通过按键开启page_scan
            {
                user_send_cmd_prepare(USER_CTRL_WRITE_SCAN_ENABLE_KEY,0,NULL);
                user_send_cmd_prepare(USER_CTRL_WRITE_CONN_ENABLE_KEY,0,NULL);
            }
            else
            {
                user_send_cmd_prepare(USER_CTRL_WRITE_SCAN_ENABLE,0,NULL);
                user_send_cmd_prepare(USER_CTRL_WRITE_CONN_ENABLE,0,NULL);
            }

        }
    }
    else
    {
        user_send_cmd_prepare(USER_CTRL_WRITE_SCAN_DISABLE,0,NULL);
        user_send_cmd_prepare(USER_CTRL_WRITE_CONN_DISABLE,0,NULL);
    }
}

/*协议栈状态变化用户处理接口*/
static void btstack_status_change_deal(void *ptr, u8 status)
{
    update_bt_prev_status(get_bt_newest_status());
    switch(status)
    {

    case BT_STATUS_RESUME:
        user_ctrl_prompt_tone_play(BT_STATUS_RESUME,NULL);
        led_fre_set(5,0);
        break;
    case BT_STATUS_RESUME_BTSTACK:
        //协议栈要求回
        break;
    case BT_STATUS_POWER_ON:
        user_ctrl_prompt_tone_play(BT_STATUS_POWER_ON,NULL);
        led_fre_set(5,0);
        break;
    case BT_STATUS_INIT_OK:
        if(bd_work_mode == BD_PAGE_MODE)/*初始化完成进入配对模式*/
        {
            led_fre_set(7,1);
            bt_page_scan(1);
        }
        else/*初始化完成进入回连模式*/
        {
            printf("BT_STATUS_INIT_OK\n");
            /* while(play_sel_busy()) {
            	os_time_dly(1);
            }
            dac_off_control(); */
            bt_power_max(4);
            user_send_cmd_prepare(USER_CTRL_START_CONNECTION,0,NULL);
            led_fre_set(7,1);
        }
#if defined(support_bt_waiting_conn_filsh_led)
        bt_line_mode=BT_STATUS_WAITINT_CONN;
#endif
        break;
    case BT_STATUS_FIRST_CONNECTED:
        bt_power_max(0xFF);
        //if(is_auto_connect()){}  //可以判断“是回连成功返回1，非回连连接返回0”
        user_ctrl_prompt_tone_play(BT_STATUS_FIRST_CONNECTED,NULL);
        led_fre_set(100,0);
         #if UI_ENABLE
		led7_var.bBtIfConnect=1;
         #endif			   	
	 #ifdef SUPPORT_BT_FIRST_CONNECT_AUTO_PLAY
	    bFirstAutoPlayFlag=1;
	 #endif		 
        break;
    case BT_STATUS_SECOND_CONNECTED:
        bt_power_max(0xFF);
        //if(is_auto_connect()){}  //可以判断“是回连成功返回1，非回连连接返回0”
        user_ctrl_prompt_tone_play(BT_STATUS_SECOND_CONNECTED,NULL);
        led_fre_set(100,0);
         #if UI_ENABLE
		led7_var.bBtIfConnect=1;
         #endif			
	 #ifdef SUPPORT_BT_FIRST_CONNECT_AUTO_PLAY
	    bFirstAutoPlayFlag=1;
	 #endif		 		 
        break;
	 
    case BT_STATUS_FIRST_DISCONNECT:
        //printf("first_disconn:%d\n",get_total_connect_dev());
		 #ifdef SUPPORT_BT_AUTO_BACK_CONNECT
		 	bBtAutoBackConnectCnt=8;		 			 
		 #endif	
		 
	 #ifdef SUPPORT_BT_DISCONNECT_AUTO_STANDBY
	 	bBtDisconnectAutoStandbyCnt=180;// 1分半		 			 
	 #endif	

        user_ctrl_prompt_tone_play(BT_STATUS_FIRST_DISCONNECT,NULL);
        if(get_total_connect_dev()==0)
        {
            led_fre_set(7,1);
         #if UI_ENABLE
		led7_var.bBtIfConnect=0;
         #endif			   		
        }
        break;
    case BT_STATUS_SECOND_DISCONNECT:
        //printf("second_disconn:%d\n",get_total_connect_dev());
        user_ctrl_prompt_tone_play(BT_STATUS_SECOND_DISCONNECT,NULL);
        if(get_total_connect_dev()==0)
        {
            led_fre_set(7,1);
         #if UI_ENABLE
		led7_var.bBtIfConnect=0;
         #endif		
        }
		 #ifdef SUPPORT_BT_AUTO_BACK_CONNECT
		 	bBtAutoBackConnectCnt=8;		 			 
		 #endif	
		 
	 #ifdef SUPPORT_BT_DISCONNECT_AUTO_STANDBY
	 	bBtDisconnectAutoStandbyCnt=180;// 1分半		 			 
	 #endif	
		
        break;
    case BT_STATUS_PHONE_INCOME:
        digit_auto_mute_set(0,-1,-1,-1); // 关自动mute
        dac_mute(0,1);
        user_send_cmd_prepare(USER_CTRL_HFP_CALL_CURRENT,0,NULL);//发命令获取电话号码
        os_time_dly(5);
        user_ctrl_prompt_tone_play(BT_STATUS_PHONE_INCOME,NULL);
#if BT_REC_EN
        //set_sys_freq(BT_REC_Hz);
#endif
        break;
    case BT_STATUS_PHONE_OUT:
#ifdef support_bt_pause_mute_amp
    {
        pa_umute();
        //	dac_mute(0,1);
    }
#endif
    puts("phone_out\n");
        //dac_mute(0,1);

#if BT_REC_EN
        //set_sys_freq(BT_REC_Hz);
#endif
    break;

#if BT_PHONE_NUMBER
    case BT_STATUS_PHONE_NUMBER:
        user_ctrl_prompt_tone_play(BT_STATUS_PHONE_NUMBER,NULL);
        break;
#endif
    case BT_STATUS_PHONE_ACTIVE:
        user_val->play_phone_number_flag = 0;
        if(user_val->phone_prompt_tone_playing_flag)
        {
            play_sel_stop();
            user_val->phone_prompt_tone_playing_flag = 0;
        }
        break;
    case BT_STATUS_PHONE_HANGUP:
        digit_auto_mute_set(1,-1,-1,-1); // 开自动mute
        user_val->play_phone_number_flag = 0;
        user_val->is_phone_number_come = 0;
        if(user_val->phone_prompt_tone_playing_flag)
        {
            play_sel_stop();
            user_val->phone_prompt_tone_playing_flag = 0;
        }
        //后台电话回来，电话完了自动退出
        user_send_cmd_prepare(USER_CTRL_BTSTACK_SUSPEND,0,NULL);    //go back to background
#if BT_REC_EN
        os_taskq_post(OS_TASK_SELF, 1, MSG_REC_STOP);
        /* set_sys_freq(SYS_Hz); */
#endif

        break;
    default:
        break;
    }
}

///具体支持那些命令在#include "avctp_user.h"头文件有说明，
///需要实现功能时多参考#include "avctp_user.h"文件的注释。
static void btstack_key_handler(void *ptr,int *msg)
{
    static u8 play_st_ctl = 0;

    switch(msg[0])
    {
    case MSG_BT_PP:
        puts("MSG_BT_PP\n");

        if(msg[1] != 0)
        {
            play_st_ctl = (u8)msg[1];
            break;
        }

	 #ifdef support_mute_led_all_flish
	 	  mute_flag=0;
	 #endif

        printf("call_status:%d\n",get_call_status());
        if ((get_call_status() == BT_CALL_OUTGOING) ||
                (get_call_status() == BT_CALL_ALERT) )
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_HANGUP,0,NULL);
        }
        else if(get_call_status() == BT_CALL_INCOMING)
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_ANSWER,0,NULL);
        }
        else if(get_call_status() == BT_CALL_ACTIVE)
        {
            user_send_cmd_prepare(USER_CTRL_SCO_LINK,0,NULL);
        }
        else
        {
			#if  SUPPORT_ALL_VOICE
			
				#ifdef SUPPORT_BT_PLAY_PAUSE_VOICE					
				 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
				 		if(IsVoiceEnable==2)				
				 		{
							if ((BT_STATUS_PLAYING_MUSIC == get_bt_connect_status())||(BT_STATUS_CONNECTING == get_bt_connect_status()))
							{
						//	    if(bBtPlayPauseState)
						  	  if(!is_auto_mute())
								  { 
								  	bt_prompt_play_by_name(BPF_PAUSE_EN_MP3);												
								  }
								  else
								  {
								  	bt_prompt_play_by_name(BPF_PLAY_EN_MP3);										
								  }
							}						}
				 		else				
				  	#endif		 						            	
				
						if(IsVoiceEnable)					
						{
							if ((BT_STATUS_PLAYING_MUSIC == get_bt_connect_status())||(BT_STATUS_CONNECTING == get_bt_connect_status()))
							{
						//	    if(bBtPlayPauseState)
						  	  if(!is_auto_mute())
								  { 
								  	bt_prompt_play_by_name(BPF_PAUSE_MP3);												
								  }
								  else
								  {
								  	bt_prompt_play_by_name(BPF_PLAY_MP3);										
								  }
							}
						}
											
				 #endif	
		 		 #ifdef SUPPORT_SCG_VOICE
		 			if(bVoiceOnoff==1)
		 				{
							if ((BT_STATUS_PLAYING_MUSIC == get_bt_connect_status())||(BT_STATUS_CONNECTING == get_bt_connect_status()))
							{
						  	  	if(!is_auto_mute())
								  { 
								  	bt_prompt_play_by_name(BPF_PAUSE_EN_MP3);												
								  }
								  else
								  {
								  	bt_prompt_play_by_name(BPF_PLAY_EN_MP3);										
								  }
							}						
						}
		 		 #endif




				 
				 
			#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF
			
			  #ifdef  SUPPORT_PP_PREV_NEXT_VOICE	 
				 		if(bModeVoiceSelVal==2)				
				 		{
							if ((BT_STATUS_PLAYING_MUSIC == get_bt_connect_status())||(BT_STATUS_CONNECTING == get_bt_connect_status()))
							{
						  	  if(!is_auto_mute())
								  { 
								  	bt_prompt_play_by_name(BPF_PAUSE_EN_MP3);												
								  }
								  else
								  {
								  	bt_prompt_play_by_name(BPF_PLAY_EN_MP3);										
								  }
							}						}
				 		else				
						if(bModeVoiceSelVal)					
						{
							if ((BT_STATUS_PLAYING_MUSIC == get_bt_connect_status())||(BT_STATUS_CONNECTING == get_bt_connect_status()))
							{
						  	  if(!is_auto_mute())
								  { 
								  	bt_prompt_play_by_name(BPF_PAUSE_MP3);												
								  }
								  else
								  {
								  	bt_prompt_play_by_name(BPF_PLAY_MP3);										
								  }
							}
						}						
			  #endif
 			 #endif				
       
            user_send_cmd_prepare(USER_CTRL_AVCTP_OPID_PLAY,0,NULL);
        }
        break;

    case MSG_BT_NEXT_FILE:

	 #ifdef support_mute_led_all_flish
	 	  mute_flag=0;
	 #endif
	 
        puts("MSG_BT_NEXT_FILE\n");
        rcsp_set_task_status(STAUS_PLAY);
        if(get_call_status() == BT_CALL_ACTIVE)
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_VOLUME_UP,0,NULL);
        }
        else
        {
            user_send_cmd_prepare(USER_CTRL_AVCTP_OPID_NEXT,0,NULL);
		 #if  SUPPORT_ALL_VOICE		 
	 		 #ifndef SUPPORT_BT_NO_USE_PREV_NEXT_VOICE
	 	            if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
	 	               (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
	 	               (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))/*连接状态*/		 
	 	            	{		
	 		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 		 		if(IsVoiceEnable==2)				
	 		 		{
	 	           			 bt_prompt_play_by_name(BPF_NEXT_EN_MP3);	 
	 				}
	 		 		else				
	 		  	#endif	
		 		 #ifdef SUPPORT_SCG_VOICE
		 			if(bVoiceOnoff==1)
		 				{
	 	 	           			bt_prompt_play_by_name(BPF_NEXT_EN_MP3);
						}
				#else
	 				if(IsVoiceEnable)
	 				{
	 	           			 bt_prompt_play_by_name(BPF_NEXT_MP3);	 
	 	           		}
		 		 #endif

				

	 	            	}
	 				
	 		#endif






			
		#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF
		
			  #ifdef  SUPPORT_PP_PREV_NEXT_VOICE	 
	 	            if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
	 	               (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
	 	               (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))/*连接状态*/		 
	 	            	{		
	 		 		if(bModeVoiceSelVal==2)				
	 		 		{
	 	           			 bt_prompt_play_by_name(BPF_NEXT_EN_MP3);	 
	 				}
	 		 		else				
	 				if(bModeVoiceSelVal)
	 				{
	 	           			 bt_prompt_play_by_name(BPF_NEXT_MP3);	 
	 	           		}
	 	            	}						
			  #endif
		
		#endif				
        }

        break;

    case MSG_BT_PREV_FILE:

	 #ifdef support_mute_led_all_flish
	 	  mute_flag=0;
	 #endif
		
        puts("MSG_BT_PREV_FILE\n");
        rcsp_set_task_status(STAUS_PLAY);
        if(get_call_status() == BT_CALL_ACTIVE)
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_VOLUME_DOWN,0,NULL);
        }
        else
        {
            user_send_cmd_prepare(USER_CTRL_AVCTP_OPID_PREV,0,NULL);

		 #if  SUPPORT_ALL_VOICE		 
	 		 #ifndef SUPPORT_BT_NO_USE_PREV_NEXT_VOICE
	 		 
	 	            if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
	 	               (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
	 	               (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))/*连接状态*/		 
	 	            	{		
	 		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 		 		if(IsVoiceEnable==2)				
	 		 		{
	 	           			 bt_prompt_play_by_name(BPF_PREV_EN_MP3);	 
	 				}
	 		 		else				
	 		  	#endif		 						            	
		 		 #ifdef SUPPORT_SCG_VOICE

				#else
	 				if(IsVoiceEnable)
	 				{
	 	           			 bt_prompt_play_by_name(BPF_PREV_MP3);	 
	 	           		}
		 		 #endif
				 
	 		 		 #ifdef SUPPORT_SCG_VOICE
	 		 			if(bVoiceOnoff==1)
	 		 				{
	 	 	 	           			bt_prompt_play_by_name(BPF_PREV_EN_MP3);
							//	printf("22222222111111111\n");
	 						}
	 				#endif
	 	            	}
	 				
	 		#endif	




			
		#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF
		
			  #ifdef  SUPPORT_PP_PREV_NEXT_VOICE	 
	 	            if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
	 	               (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
	 	               (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))/*连接状态*/		 
	 	            	{		
	 		 		if(bModeVoiceSelVal==2)				
	 		 		{
	 	           			 bt_prompt_play_by_name(BPF_PREV_EN_MP3);	 
	 				}
	 		 		else				
	 				if(bModeVoiceSelVal)
	 				{
	 	           			 bt_prompt_play_by_name(BPF_PREV_MP3);	 
	 	           		}
	 	            	}						
			  #endif
			  
		#endif				
        }
        break;

#if EQ_EN
    case MSG_BT_MUSIC_EQ:
    {
        if(msg[1] != 0)
        {
            user_val->bt_eq_mode = msg[1]&0x0f;
        }
        else
        {
            user_val->bt_eq_mode++;
        }

        if(user_val->bt_eq_mode > 5)
        {
            user_val->bt_eq_mode = 0;
        }
        eq_mode_sw(user_val->bt_eq_mode);
    }
    printf("MSG_BT_EQ %d\n", user_val->bt_eq_mode);
    rcsp_report_status(RCSP_REPORT_EQ_VALUE);
#if LCD_SUPPORT_MENU
            UI_menu(MENU_REFRESH);
#else
            UI_menu_arg(MENU_SET_EQ,user_val->bt_eq_mode);
#endif

    break;
#endif // EQ_EN




    case MSG_BT_PAGE_SCAN:
        puts("MSG_BT_PAGE_SCAN\n");
        bt_page_scan(2);
        break;
    case MSG_BT_ANSWER_CALL:
        puts("MSG_BT_ANSWER_CALL\n");
        if(get_call_status() == BT_CALL_INCOMING)
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_ANSWER,0,NULL);
        }
        break;

    case MSG_BT_CALL_LAST_NO:
        puts("MSG_BT_CALL_LAST_NO\n");
        if(get_call_status()!=BT_CALL_HANGUP)
            break;
        if(get_last_call_type()== BT_CALL_OUTGOING)
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_LAST_NO,0,NULL);
        }
        else if(get_last_call_type() == BT_CALL_INCOMING)
        {
            user_send_cmd_prepare(USER_CTRL_DIAL_NUMBER,user_val->phone_num_len,
                                  user_val->income_phone_num);
        }
        break;

    case MSG_BT_CALL_REJECT:
        puts("MSG_BT_CALL_REJECT\n");
        if(get_call_status() != BT_CALL_HANGUP)
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_HANGUP,0,NULL);
        }
	 #ifdef SUPPORT_BT_CALL_REJECT_AND_CALL_LAST_NO_IN_ONE_KEY
	 else
	 {
	        puts("MSG_BT_CALL_LAST_NO\n");
	        if(get_call_status()!=BT_CALL_HANGUP)
	            break;
	        if(get_last_call_type()== BT_CALL_OUTGOING)
	        {
	            user_send_cmd_prepare(USER_CTRL_HFP_CALL_LAST_NO,0,NULL);
	        }
	        else if(get_last_call_type() == BT_CALL_INCOMING)
	        {
	            user_send_cmd_prepare(USER_CTRL_DIAL_NUMBER,user_val->phone_num_len,
	                                  user_val->income_phone_num);
	        }
	 }
	 #endif
        break;

    case MSG_BT_CALL_CONTROL:   //物理按键少的时候合用
        if(get_call_status() != BT_CALL_HANGUP)
        {
            user_send_cmd_prepare(USER_CTRL_HFP_CALL_HANGUP,0,NULL);
        }
        else
        {
            if(get_last_call_type() == BT_CALL_OUTGOING)
            {
                user_send_cmd_prepare(USER_CTRL_HFP_CALL_LAST_NO,0,NULL);
            }
            else if(get_last_call_type() == BT_CALL_INCOMING)
            {
                user_send_cmd_prepare(USER_CTRL_DIAL_NUMBER,user_val->phone_num_len,
                                      user_val->income_phone_num);
            }
        }
        break;

    case MSG_BT_CONNECT_CTL:
        puts("MSG_BT_CONNECT_CTL\n");
        if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
                (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
                (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))/*连接状态*/
        {
            puts("bt_disconnect\n");/*手动断开连接*/
            user_send_cmd_prepare(USER_CTRL_DISCONNECTION_HCI,0,NULL);
        }
        else
        {
            puts("bt_connect\n");/*手动连接*/
            user_send_cmd_prepare(USER_CTRL_START_CONNEC_VIA_ADDR_MANUALLY,0,NULL);
        }
        break;
#ifdef SUPPORT_BT_AUTO_BACK_CONNECT
    case MSG_BT_AUTO_BACK_CONNECT:
        puts("MSG_BT_CONNECT_CTL\n");
        {
            puts("bt_connect\n");/*手动连接*/
            user_send_cmd_prepare(USER_CTRL_START_CONNEC_VIA_ADDR_MANUALLY,0,NULL);			
        }
        break;
#endif		

#ifdef SUPPORT_BT_DISCONNECT_KEY
    case MSG_BT_DISCONNECT_KEY:
		
        if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
                (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
                (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))/*连接状态*/
        {
            puts("bt_disconnect\n");/*手动断开连接*/
            user_send_cmd_prepare(USER_CTRL_DISCONNECTION_HCI,0,NULL);
        }
		
        break;
#endif		


#if BT_HID_INDEPENDENT_MODE
    case MSG_BT_HID_CTRL:
        puts("MSG_BT_HID_CTRL\n");
        if(get_curr_channel_state() & HID_CH)
        {
            user_send_cmd_prepare(USER_CTRL_HID_DISCONNECT,0,NULL);
        }
        else
        {
            user_send_cmd_prepare(USER_CTRL_HID_CONN,0,NULL);
        }

        break;
		
    case MSG_BT_HID_TAKE_PIC:
        puts("MSG_BT_HID_TAKE_PIC\n");
        if(get_curr_channel_state() & HID_CH)
        {
            user_send_cmd_prepare(USER_CTRL_HID_BOTH,0,NULL);
        }    
        break;
		
 #ifdef SUPPORT_HID_AND_VOL_IN_ONE_KEY
		
    case MSG_BT_HID_TAKE_IOS:
        puts("MSG_BT_HID_TAKE_PIC\n");
        if(get_curr_channel_state() & HID_CH)
        {
            user_send_cmd_prepare(USER_CTRL_HID_IOS,0,NULL);
        }
	else
		os_taskq_post("MainTask", 1, MSG_VOL_DOWN);
	
        break;		
		
    case MSG_BT_HID_TAKE_ANDROID:
        puts("MSG_BT_HID_TAKE_PIC\n");
        if(get_curr_channel_state() & HID_CH)
        {
            user_send_cmd_prepare(USER_CTRL_HID_ANDROID,0,NULL);
        }
	else
		os_taskq_post("MainTask", 1, MSG_VOL_UP);
		
        break;	
#endif
#endif

//#if ECHO_EN
//        case MSG_ECHO_START:
//            if(!bt_reverb)
//            {
//                bt_reverb = reverb_init();
//            }
//            break;
//
//        case MSG_ECHO_STOP:
//            reverb_stop(bt_reverb);
//            bt_reverb = NULL;
//            break;
//#endif

    case MSG_PROMPT_PLAY:
		#if !defined AC6905B_512K			
        		bt_prompt_play_by_name(BPF_TEST_MP3);
		#endif
        break;

    case MSG_POWER_OFF:
        puts("bt_power_off\n");
        if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
                (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
                (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))
        {
            puts("bt_disconnect\n");/*连接状态下先断开连接再关机*/
            user_send_cmd_prepare(USER_CTRL_POWER_OFF,0,NULL);
        }

        /*关机提示音*/
//            user_ctrl_prompt_tone_play(BT_STATUS_POWER_OFF,NULL);
//            do{
//                os_time_dly(1);
//            }while(play_sel_busy());
//            puts("power_off_tone_end\n");
        break;

#if LCD_SUPPORT_MENU
    case MSG_ENTER_MENULIST:
        if(get_bt_connect_status() == BT_STATUS_TAKEING_PHONE)
        {
            UI_menu_arg(MENU_LIST_DISPLAY,UI_MENU_LIST_ITEM|(1<<8));
        }
        else
        {
            UI_menu_arg(MENU_LIST_DISPLAY,UI_MENU_LIST_ITEM);
        }
        break;
#endif


 #if  SUPPORT_ALL_VOICE		 
#if   SUPPORT_TY_VOICE==0
	#ifdef SUPPORT_VOICE_ONOFF_KEY_SINGLE_KEY
		case MSG_BT_VOICE_SWITCH:	

			if(IsVoiceEnable)
			{
				bStoreVoiceVal=IsVoiceEnable;
				IsVoiceEnable = 0;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_OFF); 
				 #endif			 
				
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
				 
		 		if(bStoreVoiceVal==1)												
					bt_prompt_play_by_name(BPF_VOICE_OFF_MP3);
				else
					bt_prompt_play_by_name(BPF_VOICE_OFF_EN_MP3);							 
			}
			else
			{
				IsVoiceEnable = bStoreVoiceVal;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_ON); 
				 #endif			 				
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
		 		if(IsVoiceEnable==1)												
					bt_prompt_play_by_name(BPF_VOICE_ON_MP3);
				else
					bt_prompt_play_by_name(BPF_VOICE_ON_EN_MP3);
					
			}

			break;
			
		case MSG_BT_VOICE_CHANGE:	
		 		if(IsVoiceEnable==0)				
					break;

		 		if(IsVoiceEnable==1)				
		 		{
		 			IsVoiceEnable=2;
					 #ifdef LED_SHOW_ONOFF
					 	UI_menu(MENU_VOICE_EN); 
					 #endif			 
					
			 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 #endif
								 
					bt_prompt_play_by_name(BPF_VOICE_EN_MP3);
				 }
				else
				{
					IsVoiceEnable = 1;
					 #ifdef LED_SHOW_ONOFF
					 	UI_menu(MENU_VOICE_CH); 
					 #endif			 				
			 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 #endif
									
					bt_prompt_play_by_name(BPF_VOICE_CH_MP3);
				}

			break;
			
	#else
		case MSG_BT_VOICE_SWITCH:	

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==1)				
		 		{
		 			IsVoiceEnable=2;
					 #ifdef LED_SHOW_ONOFF
					 	UI_menu(MENU_ON); 
					 #endif			 
					
			 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 #endif
								 
					bt_prompt_play_by_name(BPF_VOICE_ON_EN_MP3);
				 }
		 		else				
		  	#endif		 					
		#ifdef SUPPORT_SCG_VOICE


		#else

			if(IsVoiceEnable)
			{
				IsVoiceEnable = 0;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_OFF); 
				 #endif			 
				
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
							 
				bt_prompt_play_by_name(BPF_VOICE_OFF_MP3);
			}
			else
			{
				IsVoiceEnable = 1;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_ON); 
				 #endif			 				
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
								
				bt_prompt_play_by_name(BPF_VOICE_ON_MP3);
			}
		#endif
			break;
		 #endif
		 
	 #ifdef SUPPORT_MUTE_VOICE
	 
	    case MSG_VOICE_MUTE:
		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
	    				bt_prompt_play_by_name(BPF_MUTE_EN_MP3);			    		    				 	    		    		    	
				}
		 		else				
		  	#endif	
			if(IsVoiceEnable)
		    	{
	    			bt_prompt_play_by_name(BPF_MUTE_MP3);			    		    				 	    		    		    	
		    	}
			
	    	break;
	    case MSG_VOICE_MUTE_OFF:

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
	    				bt_prompt_play_by_name(BPF_MUTE_OFF_EN_MP3);			    		    				 	    		    		    	
				}
		 		else				
		  	#endif	
			if(IsVoiceEnable)
		    	{
	    			bt_prompt_play_by_name(BPF_MUTE_OFF_MP3);			    		    				 	    		    		    	
		    	}
	    	break;
			
	#endif

		#ifdef SUPPORT_SCG_VOICE


		#else
	    case MSG_VOICE_VOLUME_PLUS:
		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
					if(dac_ctl.sys_vol_l ==30)	
		    				bt_prompt_play_by_name(BPF_VL_MAX_EN_MP3);			    		    				 	    		    		    					 
					else		
		    				bt_prompt_play_by_name(BPF_VL_INC_EN_MP3);			    		    				 	    		    		    					 
				}
		 		else				
		  	#endif		 					
			#if SUPPORT_VOL_VOICE
			if(IsVoiceEnable)
	    		{
				if(dac_ctl.sys_vol_l ==30)	
		    				bt_prompt_play_by_name(BPF_VL_MAX_MP3);			    		    				 	    		    		    					 
				else		
		    				bt_prompt_play_by_name(BPF_VL_INC_MP3);			    		    				 	    		    		    					 
			}
			#endif
	    	break;

	    case MSG_VOICE_VOLUME_MINUS:
		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
					bt_prompt_play_by_name(BPF_VL_DEC_EN_MP3);			    		    				 	    		    		    			    		    				 	    		    		    					 
				}
		 		else				
		  	#endif		
			
			#if SUPPORT_VOL_VOICE			
			if(IsVoiceEnable)
			{
				bt_prompt_play_by_name(BPF_VL_DEC_MP3);			    		    				 	    		    		    	
			}
			#endif
			
	    	break;

	    case MSG_MAX_VOICE:
		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
	    				bt_prompt_play_by_name(BPF_VL_MAX_EN_MP3);			    		    				 	    	
				}
		 		else				
		  	#endif		 					

			#if SUPPORT_VOL_VOICE			
			if(IsVoiceEnable)
		    	{
	    			bt_prompt_play_by_name(BPF_VL_MAX_MP3);			    		    				 	    	
		    	}
		  	#endif		 					
	    	break;
	#endif		 					

			
#else 


	 #ifdef SUPPORT_VOICE_MODE_KEY

		case MSG_BT_VOICE_SWITCH:

			if(IsVoiceEnable)
			{
				IsVoiceEnable = 0;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_OFF); 
				 #endif			 
				
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
							 
				bt_prompt_play_by_name(BPF_VOICE_OFF_MP3);
			}
			else
			{
				IsVoiceEnable = 1;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_ON); 
				 #endif			 				
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
								
				bt_prompt_play_by_name(BPF_VOICE_ON_MP3);
			}
	
		break;	 
	 #endif


#endif


	 #ifdef SUPPORT_SCG_VOICE
	 	 #ifdef SUPPORT_MUTE_VOICE
	 	 
	 	 	case MSG_VOICE_MUTE:
 	 			if(bVoiceOnoff==1)
 	 			{
 	 				bt_prompt_play_by_name(BPF_MUTE_MP3);			    		    				 	    		    		    	
 	 			}
	 	 
	 	 	break;
	 	 	case MSG_VOICE_MUTE_OFF:
	 	 		if(bVoiceOnoff==1)
	 	 	 	{
	 	 	 		bt_prompt_play_by_name(BPF_MUTE_OFF_MP3);			    		    				 	    		    		    	
	 	 	 	}
	 	 	break;
	 	 
	 	 #endif
		 	case MSG_VOICE_VOLUME_PLUS:
		 		 	if(bVoiceOnoff==1)				
		 		 	{
	 		 		 	if(dac_ctl.sys_vol_l ==30)	
	 		 		 		bt_prompt_play_by_name(BPF_VL_MAX_MP3);			    		    				 	    		    		    					 
	 		 		 	else		
	 		 		 		bt_prompt_play_by_name(BPF_VL_INC_MP3);			    		    				 	    		    		    					 
		 		 	}
		 	break;
		 
		 	case MSG_VOICE_VOLUME_MINUS:
		 		 	if(bVoiceOnoff==1)				
		 		 	{
		 		 		bt_prompt_play_by_name(BPF_VL_DEC_MP3);			    		    				 	    		    		    			    		    				 	    		    		    					 
		 		 	}
		 	break;
		 
		 	case MSG_MAX_VOICE:
		 		 	if(bVoiceOnoff==1)				
		 		 	{
		 		 		bt_prompt_play_by_name(BPF_VL_MAX_MP3);			    		    				 	    	
		 		 	}
		 	break;





	 #endif







	 #ifdef SUPPORT_MIC_ONOFF_VOICE
	 
	 		case MSG_VOICE_MIC:
	 
	 			if(mic_sw)
	 	    			bt_prompt_play_by_name(BPF_MIC_ON_MP3);
	 			else
	 	    			bt_prompt_play_by_name(BPF_MIC_OFF_MP3);
	 
	 			break;
	 #endif




			
			
#endif







        case MSG_LOW_POWER:
            // puts("bt_low_power\n");
			bt_prompt_play_by_name(BPF_LOW_POWER_MP3);			
            break;

    case MSG_HALF_SECOND:
        //puts(" BT_H ");
        if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
                (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
                (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))/*连接状态*/
           {


	 	 #ifdef SUPPORT_BT_FIRST_CONNECT_AUTO_PLAY
	 	    if((bFirstAutoPlayFlag)&&(!is_auto_mute()))
	 	    	{
	 			bFirstAutoPlayFlag=0;       
	 		       user_send_cmd_prepare(USER_CTRL_AVCTP_OPID_PLAY,0,NULL);
	 		}
	 	 #endif		 

		 #ifdef support_bt_DISCONNECT_mute_amp
		             pa_umute();
		 #endif
		 
		 #ifdef SUPPORT_BT_DISCONNECT_AUTO_STANDBY
		 	bBtDisconnectAutoStandbyCnt=0;// 1分半		 			 
		 #endif	

		 #ifdef SUPPORT_BT_AUTO_BACK_CONNECT
 			bBtAutoBackConnectCnt=0;		 			 
		 #endif	

		bBtConnectFlag=1; // 0-disconnect  1-connect
            if(BT_MUSIC_STATUS_STARTING == a2dp_get_status())       /*播歌状态*/
            {
                //puts("BT_MUSIC\n");
		 #ifdef SUPPORT_BT_PLAY_MUSIC_LIGHT	
		     led_fre_set(0,0);
		 #else
                 led_fre_set(15,0);                                /*播歌慢闪*/
		 #endif
                

		 #if defined(support_bt_waiting_conn_filsh_led)
		                 bt_line_mode=BT_STATUS_PLAYING_MUSIC;
		 #endif
		 
		 #ifdef support_bt_pause_mute_amp
		                 bt_pause_mute_delay=0;
		                 if(!is_dac_mute())
		                     pa_umute();
		                 //	dac_mute(0,1);
		 #endif
		 
		 #ifdef SUPPORT_BT_PLAY_PAUSE_VOICE				
		 	bBtPlayPauseState=1; // 0-pause  1-play						
		 #endif		 

		 
                if(play_st_ctl == RCSP_CBK_MSG_COMM_PAUSE)
                {
                    puts("\nRCSP_CBK_MSG_COMM_PAUSE\n");
                    os_taskq_post(RDEF_BTMSG_TASK_NAME,1,MSG_BT_PP);
                    rcsp_set_task_status(STAUS_PAUSE);
                }
                else
                {
                    rcsp_set_task_status(STAUS_PLAY);
                }
                play_st_ctl = 0;
            }
            else if(BT_STATUS_TAKEING_PHONE == get_bt_connect_status())
            {
                ///puts("bt_phone\n");
                rcsp_set_task_status(STAUS_PAUSE);
            }
            else
            {

                ///puts("bt_other\n");
                if(play_st_ctl == RCSP_CBK_MSG_COMM_PLAY)
                {
                    puts("\nRCSP_CBK_MSG_COMM_PAUSE\n");
                    os_taskq_post(RDEF_BTMSG_TASK_NAME,1,MSG_BT_PP);
                }
                else
                {
			 #ifdef support_bt_pause_mute_amp
	                     if(bt_pause_mute_delay)
	                         bt_pause_mute_delay--;
	                     if(bt_pause_mute_delay==0 && get_call_status() == BT_CALL_HANGUP&& (play_sel_busy()==0) )
	                     {
	                         //printf("  pause 2\n");
	                         pa_mute();
	 
	                     }			 			 
			 #endif
			 
  		 #ifdef SUPPORT_BT_PLAY_PAUSE_VOICE				
  		 	bBtPlayPauseState=0; // 0-pause  1-play						
  		 #endif		 
			 


                    led_fre_set(0,0);                                /*播歌慢闪*/
                    rcsp_set_task_status(STAUS_PAUSE);
                }
                play_st_ctl = 0;
                //puts("BT_CONN\n");
                //led_fre_set(0,0);                                 /*暂停常亮*/
            }
            user_val->auto_shutdown_cnt = AUTO_SHUT_DOWN_TIME;
        }
#if 0		
        else  if(BT_STATUS_WAITINT_CONN == get_bt_connect_status()&&user_val->auto_shutdown_cnt)
        {
            //puts("BT_STATUS_WAITINT_CONN\n");
            user_val->auto_shutdown_cnt--;
      //      printf("power cnt:%d\n",user_val->auto_shutdown_cnt);
            if(user_val->auto_shutdown_cnt==0)
            {
                //软关机
                puts("*****shut down*****\n");
                going_to_pwr_off = 1;
                os_taskq_post("MainTask", 2, MSG_POWER_OFF_KEY_MSG,0x44);
            }
        }
#endif		
	 else
	 {
 		 #ifdef support_bt_DISCONNECT_mute_amp
			 if(bBtDiscnnectMuteCnt)
			 	{
				 	bBtDiscnnectMuteCnt--;
					if(bBtDiscnnectMuteCnt==1)
						{
							bBtDiscnnectMuteCnt=0;
							pa_mute();
						}
			 	}
		 #endif
		 
       //     printf("---------bBtAutoBackConnectCnt-------------%d\n",bBtAutoBackConnectCnt);
		 
		 #ifdef SUPPORT_BT_AUTO_BACK_CONNECT
		 	if(bBtAutoBackConnectCnt)
		 	{
		 		bBtAutoBackConnectCnt--;
		 		if(bBtAutoBackConnectCnt==1)
		 		{
		 			bBtAutoBackConnectCnt=9;
		                	user_val->auto_connection_counter = 6;

	                 		 os_taskq_post(BTSTACK_TASK_NAME, 1, MSG_BT_AUTO_BACK_CONNECT);
		 		}
		 	}		 			 
		 #endif	


		 #ifdef SUPPORT_BT_DISCONNECT_AUTO_STANDBY
		 	if(bBtDisconnectAutoStandbyCnt)
		 	{
		 		bBtDisconnectAutoStandbyCnt--;
		 		if(bBtDisconnectAutoStandbyCnt==1)
		 		{
		 			bBtDisconnectAutoStandbyCnt=0;
	                 		 os_taskq_post(MAIN_TASK_NAME, 1, MSG_STANBY_KEY);
		 		}
		 	}		 			 
		 #endif	

		 
	         #if UI_ENABLE
			led7_var.bBtIfConnect=0;
	         #endif			   		
		 #ifdef SUPPORT_BT_PLAY_PAUSE_VOICE				
		 	bBtPlayPauseState=0; // 0-pause  1-play						
		 #endif		 
	 
 		bBtConnectFlag=0; // 0-disconnect  1-connect
	 }

#if (SNIFF_MODE_CONF&SNIFF_EN)
        if(check_in_sniff_mode())
        {
            printf("check_in_sniff_mode ok\n");
            user_send_cmd_prepare(USER_CTRL_SNIFF_IN,0,NULL);
            //user_send_cmd_prepare(USER_CTRL_SNIFF_EXIT,0,NULL);
        }
#endif

        if((bt_ui_var.ui_bt_connect_sta != get_bt_connect_status())||
                (bt_ui_var.ui_bt_a2dp_sta != a2dp_get_status()))
        {
            bt_ui_var.ui_bt_connect_sta = get_bt_connect_status();
            bt_ui_var.ui_bt_a2dp_sta = a2dp_get_status();
            UI_menu(MENU_REFRESH);
        }
#ifdef support_be_mode_off_half_sec
//           UI_menu(MENU_MAIN);
//        UI_menu(MENU_HALF_SEC_REFRESH);
#else
           UI_menu(MENU_MAIN);
        UI_menu(MENU_HALF_SEC_REFRESH);
#endif

        break;

    case MSG_BT_STACK_STATUS_CHANGE:
        //该消息比较特殊，不属于按键产生，是协议栈状态变化产生。
        puts("MSG_BT_STACK_STATUS_CHANGE\n");
        btstack_status_change_deal(NULL, msg[1]);
        break;
    case SYS_EVENT_DEL_TASK:
        puts("SYS_EVENT_DEL_TASK\n");
        //断开和关闭协议栈
        user_send_cmd_prepare(USER_CTRL_POWER_OFF,0,NULL);
        //删除协议栈
        delete_stack_task();
        puts("del stack ok\n");
        play_sel_stop();
        if(dac_ctl.toggle == 0)
        {
            dac_on_control();
        }
        //删除消息线程
        if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
        {
            puts("del_ket_masg");
//                exit_rec_api(&rec_bt_api);
//                echo_exit_api(&bt_reverb);
            os_task_del_res_name(OS_TASK_SELF); 	//确认可删除，此函数不再返回
        }
        break;
    default:
        //echo_msg_deal_api(&bt_reverb, &key);
        break;
    }
}
#if BT_REC_EN
void bt_rec_msg_deal(int *msg)
{
    if((BT_STATUS_TAKEING_PHONE != get_bt_connect_status())&&(msg[0] == MSG_REC_START))//非通话按
    {
        return;
    }

    rec_msg_deal_api(&rec_bt_api, msg);
}
#endif
/*消息处理*/
void TaskBtMsgStack(void *p_arg)
{
    //p_arg = p_arg;
#ifdef SUPPORT_TM1628_KEY_READ
    key_msg_register("btmsg",bt_led_table,bt_ad_table,bt_io_table,bt_ir_table,NULL);
#else    
    key_msg_register("btmsg",bt_ad_table,bt_io_table,bt_ir_table,NULL);
#endif
    os_sem_create(&tone_manage_semp, 1);

    while(1)
    {
        int msg[6];
        u32 res;
        memset(msg,0x00,sizeof(msg));///need do it
        res = os_taskq_pend(0, ARRAY_SIZE(msg), msg);
        clear_wdt();
        if(res != OS_NO_ERR)
        {
            msg[0] = 0xff;
        }

        //printf("bt_msg:%d",msg[0]);
        btstack_key_handler(NULL, msg);

#if BT_REC_EN
        bt_rec_msg_deal(msg);
#endif

        Update_rcsp_Task_State(msg[0],1);

    }

}

/*主要处理上电或者有些情况蓝牙处于不能切换模式状态*/
/*不属于用户接口，协议栈回调函数*/
int msg_mask_off_in_bt()
{
#if BT_BACKMODE
    return is_bt_stack_cannot_exist();
#else
    return false;
#endif
}

/*通过任务切换进入蓝牙时回调接口*/
/*不属于用户接口，协议栈回调函数*/
void enter_btstack_task()
{
    puts("\n************************BLUETOOTH TASK********************\n");
    workmode =BT_WORK_MODE;
#ifdef SUPPORT_VM_WORK_MODE
	vm_write_api(VM_WORK_MODE,&workmode);
#endif

    SET_UI_MAIN(MENU_BT_MAIN);
    UI_menu(MENU_BT_MAIN);

#ifdef support_amP_ab_d
    Set_amp_ab_d_out() ;
    Set_AMP_IS_D();
#endif

#ifdef support_sound_4052_control
#if defined sound_4052_io_mode_6 ||defined sound_4052_io_mode_5
	AC4052_IS_BT(); 
#endif
#endif
#ifdef KOK_DETECT_AUTO_VOL_SET
///	 store_vol= dac_ctl.sys_vol_l;
	dac_ctl.sys_vol_l = 30;
	dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;
	set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);


#endif



    spp_mutex_init();
    user_val->auto_shutdown_cnt = AUTO_SHUT_DOWN_TIME;
    dac_channel_on(BT_CHANNEL, FADE_ON);
	
 #if UI_ENABLE
	led7_var.bBtIfConnect=0;
 #endif	
 
#ifdef SUPPORT_BT_AUTO_BACK_CONNECT
	bBtAutoBackConnectCnt=8;		 			 
#endif	

#ifdef SUPPORT_BT_DISCONNECT_AUTO_STANDBY
	bBtDisconnectAutoStandbyCnt=180;// 1分半		 			 
#endif	


    user_ctrl_prompt_tone_play(BT_STATUS_POWER_ON,NULL);
    printf("-------led-1\n");

	
    led_fre_set(7,1);

    bt_ui_var.bt_eq_mode = &(user_val->bt_eq_mode);
    ui_open_bt(&bt_ui_var, sizeof(BT_DIS_VAR));

#ifdef SUPPORT_PT2313
	Pt2313_ChangSource(Aud_SwBt);
#endif

#if EQ_EN
    eq_enable();
#endif // EQ_EN

    bBtConnectFlag=0; // 0-disconnect  1-connect

    SET_UI_MAIN(MENU_BT_MAIN);
    UI_menu(MENU_BT_MAIN);

}

/*不属于用户接口，协议栈回调函数*/
/*通过任务切换退出蓝牙时回调接口*/
void exist_btstack_task()
{
    user_val->play_phone_number_flag = 0;
    user_val->is_phone_number_come = 0;
    if(user_val->phone_prompt_tone_playing_flag)
    {
        play_sel_stop();
        user_val->phone_prompt_tone_playing_flag = 0;
    }
    puts("----BTSTACK  no BACKGROUND---\n");
    spp_mutex_del();
    dac_channel_off(BT_CHANNEL, FADE_ON);
    ui_close_bt();

#if EQ_EN
    eq_disable();
#endif // EQ_EN
#ifndef SUPPORT_NO_SHOW_LOAD    
SET_UI_MAIN(MENU_WAIT);
UI_menu(MENU_WAIT);
#endif

#ifdef SUPPORT_BT_LED_PRORAM	
#ifdef SUPPORT_LED_BLUE_STRING_FLASH
LED_FLASH_CHAR=0;
#ifdef LED_BT		
led7_var.wFlashIcon &=~LED_BT;
#endif
#endif		
#endif

#if BT_BACKMODE
    background_suspend();
#else
    no_background_suspend();
#endif
 #if UI_ENABLE
	led7_var.bBtIfConnect=0;
 #endif	
}

extern void sys_time_auto_connection();
void sys_time_auto_connection_caback(u8* addr)
{
    if(user_val->auto_connection_counter&&get_bt_prev_status() != BT_STATUS_SUSPEND)
    {
        bt_page_scan(0);
        printf("auto_conn_cnt1:%d\n",user_val->auto_connection_counter);
        user_val->auto_connection_counter--;
        user_send_cmd_prepare(USER_CTRL_START_CONNEC_VIA_ADDR,6,addr);
    }
}

/*不属于用户接口，协议栈回调函数*/
void bt_discon_complete_handle(u8 *addr, int reason)
{
    printf("bt_discon_complete:0x%x\n",reason);
    if(reason==0||reason==0x40 )
    {
        //连接成功
        user_val->auto_connection_counter = 0;
        return ;
    }
    else if(reason==0xfc)
    {
        //新程序没有记忆地址是无法发起回连
        puts("vm no bd_addr\n");
        bt_page_scan(1);
        return ;
    }
else if(reason==0x10)
	{
		puts("conneciton accept timeout\n");
		bt_page_scan(1);
        return ;
	}
    if (reason == 0x16)
    {
        puts("Conn Terminated by Local Host\n");
        bt_page_scan(1);
    }
    else if(reason == 0x08)
    {
        puts("\nconntime timeout\n");
        if(!get_remote_test_flag())
        {

            if(get_bt_prev_status() != BT_STATUS_SUSPEND &&
                    (get_call_status() == BT_CALL_HANGUP))
            {
                user_val->auto_connection_counter = 6;
                puts("\nsuper timeout\n");
                user_send_cmd_prepare(USER_CTRL_START_CONNEC_VIA_ADDR,6,addr);
            }
        }
        else
        {
            user_val->auto_connection_counter = 0;
            bt_page_scan(1);
        }
    }
    else if(reason == 0x04)
    {
        if(! user_val->auto_connection_counter)
        {
            puts("page timeout---\n");
            if(get_current_search_index() >= 1)
            {
                //继续搜索下一个设备
                user_send_cmd_prepare(USER_CTRL_START_CONNECTION,0,NULL);
            }
            else
            {
                bt_page_scan(1);
                bt_power_max(0xFF);
            }
        }
        else
        {
            if(get_bt_prev_status() != BT_STATUS_SUSPEND)
            {
                printf("auto_conn_cnt:%d\n",user_val->auto_connection_counter);
                user_val->auto_connection_counter--;
                if(user_val->auto_connection_counter%2)
                {
                    bt_page_scan(1);
                    sys_time_auto_connection(addr);
                }
                else
                {
                    bt_page_scan(0);
                    user_send_cmd_prepare(USER_CTRL_START_CONNEC_VIA_ADDR,6,addr);
                }
            }
        }
    }
    else if(reason == 0x0b)
    {
        puts("Connection Exist\n");
        user_send_cmd_prepare(USER_CTRL_START_CONNEC_VIA_ADDR,6,addr);
    }
}
