#include "sdk_cfg.h"
#include "common/app_cfg.h"
#include "encode/encode.h"
#include "rtos/os_api.h"
#include "rtos/os_cfg.h"
#include "common/error.h"
#include "common/msg.h"
#include "rtos/task_manage.h"
#include "dac/dac_api.h"
#include "fm/fm_radio.h"
#include "fm/fm_api.h"
#include "fm_key.h"
#include "play_sel/play_sel.h"
#include "key_drv/key.h"
#include "ui/led/led.h"
#include "fm_prompt.h"
#include "echo/echo_api.h"
#include "record.h"
#include "clock_api.h"
#include "common/common.h"
#include "rcsp/rcsp_interface.h"
#include "fm_ui.h"
#include "fm_inside.h"
#include "clock.h"
#include "dac.h"
#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif
#include "led7_drv.h"
#include "vm/vm_api.h"

#if FM_RADIO_EN

#if  SUPPORT_FM_OPTION_VOICE		 
#if  SUPPORT_ALL_VOICE		 
u8 IsFmSearchBegin;
u8 IsFmSearchEnd;  
#endif
#endif


#ifdef SUPPORT_VOICE_ONOFF
bool bVoiceOnoff;
#endif



extern void *malloc_fun(void *ptr,u32 len,char *info);
extern void free_fun(void **ptr);

RECORD_OP_API * rec_fm_api = NULL;
static void set_fm_channel(void);
static void del_fm_channel(u8 chl_num);
static void save_fm_channel(u16 save_freq);

FM_MODE_VAR *fm_mode_var;       ///>FM状态结构体
FM_INFO *fm_info;               ///>FM存台信息
void *fm_reverb;

extern u8 eq_mode;
#ifdef support_mute_led_all_flish
extern bool  mute_flag;
#endif
#ifdef  SUPPORT_FM_SCAN_FINISH_DAC_MUTE    
u8 bFmScanEndMuteDacTimer;
#endif
#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
u8 bFmMuteTimer;
extern u8 bFmUmuteTimer;
#endif

/*----------------------------------------------------------------------------*/
/**@brief  FM录音过程消息过滤函数
   @param  msg；接收到的消息
   @return 1：不需要过滤，0：过滤
   @note   static bool fm_msg_filter(int msg)
   @note   FM不同工作状态时，部分消息不能进行处理，如还没初始化不能搜台等操作
*/
/*----------------------------------------------------------------------------*/
#if FM_REC_EN
static bool fm_rec_msg_filter(RECORD_OP_API * rec_fm_api, int msg)
{
    if(rec_fm_api)
    {
        if(rec_fm_api->rec_ctl->enable != ENC_STOP)//正在录音，不响应以下消息
        {
		 #if  SUPPORT_FM_OPTION_VOICE		   
		             if((msg == MSG_FM_SCAN_ALL_INIT)
		                     ||(msg == MSG_FM_SCAN_ALL)
		                      ||(msg == MSG_FM_SEARCHING)
		                    ||(msg == MSG_FM_SCAN_ALL_UP)
		                     ||(msg == MSG_FM_SCAN_ALL_DOWN))
		 #else
		             if((msg == MSG_FM_SCAN_ALL_INIT)
		                     ||(msg == MSG_FM_SCAN_ALL)
		                    ||(msg == MSG_FM_SCAN_ALL_UP)
		                     ||(msg == MSG_FM_SCAN_ALL_DOWN))
		 #endif
            {
                return 0;
            }
        }
    }
    return 1;
}
#endif

/*----------------------------------------------------------------------------*/
/**@brief  FM消息过滤函数
   @param  msg；接收到的消息
   @return 1：不需要过滤，0：过滤
   @note   static bool fm_msg_filter(int msg)
   @note   FM不同工作状态时，部分消息不能进行处理，如还没初始化不能搜台等操作
*/
/*----------------------------------------------------------------------------*/
static bool fm_msg_filter(int msg)
{
    ///FM 任何情况，都必须响应SYS_EVENT_DEL_TASK消息

    if(fm_mode_var->scan_mode == FM_UNACTIVE)///FM 还没初始化完成(正在播放提示音)，不响应其他消息
    {
        if((msg == SYS_EVENT_DEL_TASK)
                ||(msg == SYS_EVENT_PLAY_SEL_END)
                ||(msg == MSG_ENCODE_ERR)
                ||(msg == SYS_EVENT_DEV_OFFLINE))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
	 #if  SUPPORT_FM_OPTION_VOICE		 
	     else if(fm_mode_var->scan_mode >= FM_SCAN_BUSY)    ///FM正在搜台，只响应部分按键
	     {
	         if((msg == SYS_EVENT_DEL_TASK)||\
	                 (msg == SYS_EVENT_PLAY_SEL_END)||\
	                 (msg == MSG_FM_SCAN_ALL)||\
	                 (msg == MSG_FM_SEARCHING)||\
	                 (msg == MSG_FM_SCAN_ALL_INIT)||\
	                 (msg == SYS_EVENT_SYSCLK_NOTFIT_DEVMOUNT)||\
	                 (msg == SYS_EVENT_DEV_MOUNT_ERR)||\
	                 (msg == MSG_ENCODE_ERR)||\
	                 (msg == MSG_MUSIC_EQ)||\
	                 (msg == SYS_EVENT_DEV_OFFLINE))
	                 
     #elif defined SUPORT_FM_PP_CANEL_SCAN
	 
	     else if(fm_mode_var->scan_mode >= FM_SCAN_BUSY)    ///FM正在搜台，只响应部分按键
	     {
	         if((msg == SYS_EVENT_DEL_TASK)||\
	                 (msg == SYS_EVENT_PLAY_SEL_END)||\
	                 (msg == MSG_FM_SCAN_ALL)||\
	                 (msg == MSG_FM_PP)||\
	                 (msg == MSG_FM_SCAN_ALL_INIT)||\
	                 (msg == SYS_EVENT_SYSCLK_NOTFIT_DEVMOUNT)||\
	                 (msg == SYS_EVENT_DEV_MOUNT_ERR)||\
	                 (msg == MSG_ENCODE_ERR)||\
	                 (msg == MSG_MUSIC_EQ)||\
	                 (msg == SYS_EVENT_DEV_OFFLINE))		 
	 #else
	 
	     else if(fm_mode_var->scan_mode >= FM_SCAN_BUSY)    ///FM正在搜台，只响应部分按键
	     {
	         if((msg == SYS_EVENT_DEL_TASK)||\
	                 (msg == SYS_EVENT_PLAY_SEL_END)||\
	                 (msg == MSG_FM_SCAN_ALL)||\
	                 (msg == MSG_FM_SCAN_ALL_INIT)||\
	                 (msg == SYS_EVENT_SYSCLK_NOTFIT_DEVMOUNT)||\
	                 (msg == SYS_EVENT_DEV_MOUNT_ERR)||\
	                 (msg == MSG_ENCODE_ERR)||\
	                 (msg == MSG_MUSIC_EQ)||\
	                 (msg == SYS_EVENT_DEV_OFFLINE))
	                 
	 #endif
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else            ///一般情况下，不进行过滤
    {
        return 1;
    }
}

/*----------------------------------------------------------------------------*/
/**@brief  FM模式主线程
   @param  p：NULL
   @return NULL
   @note   static void fm_radio_task(void *p)
*/
/*----------------------------------------------------------------------------*/
u8 fm_init_flag = 1;
static void fm_radio_task(void *p)
{
    int msg[3];
    u8 scan_counter=0;
    u32 res;

    fm_reverb = NULL;
    fm_init_flag = 1;
    fm_puts("\n***********************RADIO TASK********************\n");

//    rcsp_app_start(RDEF_RADIO_TASK_NAME);

#if defined(LED_ID_JW2781)
led7_var.bEqCircleIfPlay=TRUE;
#endif

    workmode=RADIO_WORK_MODE;
#ifdef SUPPORT_VM_WORK_MODE
	vm_write_api(VM_WORK_MODE,&workmode);
#endif

    led_fre_set(0,0);
    fm_arg_open();                          //FM
    
 #ifdef SUPPORT_OFF_MODE_VOICE
 	os_taskq_post_msg(FM_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);

#elif   SUPPORT_FM_OPTION_VOICE

  #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
  	if(IsVoiceEnable==2)				
  	{			 			 	
      	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_EN_MP3);  //FM提示音播放
  	}
  	else				
  #endif		 						            					 		 			 					

    if(IsVoiceEnable)
    {
    	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_MP3);  //FM提示音播放
    }
    else
    {
		os_taskq_post(FM_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
    }
#elif defined(SUPPORT_SCG_VOICE)
	if(bVoiceOnoff==0)
		{
	 		os_taskq_post(FM_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
		}
	else if(bVoiceOnoff==1)
		{
		     	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_MP3);  //FM提示音播放
		}


#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	

  	if(bModeVoiceSelVal==2)				
  	{			 			 	
      	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_EN_MP3);  //FM提示音播放
  	}
  	else	 if(bModeVoiceSelVal)
	    {
	    	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_MP3);  //FM提示音播放
	    }
	    else
	    {
			os_taskq_post(FM_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
	    }
		
#elif defined SUPPORT_DOUBLE_MODE_VOICE	

    if(bModeVoiceSelFlag)
    {
    	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_MP3);  //FM提示音播放
    }
    else
    {
    	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_EN_MP3);  //FM提示音播放
    }

#elif defined SUPPORT_MODE_VOICE_ONOFF	
    if(bModeVoiceOnoffFlag)
    {
    	tone_play_by_name(FM_TASK_NAME, 1,BPF_RADIO_MP3);  //FM提示音播放
    }
    else
    {
		os_taskq_post(FM_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
    }
	
 #else
    tone_play_by_name(FM_TASK_NAME,1,BPF_RADIO_MP3);  //FM提示音播放
 #endif

    while(1)
    {
        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);

        if(msg[0] != MSG_HALF_SECOND)
        {
            printf("\nfm_msg=   0x%x\n",msg[0]);
        }

        clear_wdt();
        if(!fm_msg_filter(msg[0]))//根据FM状态，过滤消息
            continue;
#if FM_REC_EN
        if(!fm_rec_msg_filter(rec_fm_api, msg[0]))//根据FM录音状态，过滤消息
            continue;
#endif
        switch(msg[0])
        {

        case SYS_EVENT_DEL_TASK:
            fm_puts("get_SYS_EVENT_DEL_TASK\n");
            if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
            {
                play_sel_stop(); //关闭提示音
                SET_UI_UNLOCK();
//                UI_menu(MENU_WAIT);
		 #ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
		 	 SET_REXTERN_POWER_FM_SCAN_IO(0);
		 #endif	
                ui_close_fm();
                exit_rec_api(&rec_fm_api); //停止录音和释放资源
                echo_exit_api(&fm_reverb);
                fm_radio_powerdown();
                dac_set_samplerate(24000,1);
                os_task_del_res_name(OS_TASK_SELF);
            }
            break;

        case SYS_EVENT_PLAY_SEL_END: //提示音结束
            puts("fm pley sel end\n");
            if(fm_prompt_break)
            {
                fm_prompt_break = 0;
                break;
            }
            play_sel_stop(); //关闭提示音
#ifdef support_amP_ab_d
            Set_amp_ab_d_out() ;
            Set_FM_IS_AB();
#endif
#ifdef SUPPORT_MODE_MAX_VOL_SINGLE_ADJUST
	set_max_dac_vol(FM_ANALOG_VOL_MAX_L, FM_ANALOG_VOL_MAX_R, FM_DIGITAL_VOL_MAX_L,FM_DIGITAL_VOL_MAX_R);
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

#ifdef FM_PROMPT_EN
            if(fm_init_flag)
            {
                fm_init_flag = 0;
                res = fm_radio_init();
            }
            else
            {
                dac_channel_on(FM_INSI_CHANNEL, FADE_ON);
                dac_set_samplerate(FM_DAC_OUT_SAMPLERATE,1);
                fm_module_mute(0);
                res = TRUE;

		 #if  SUPPORT_FM_OPTION_VOICE		 
		 
                if(IsFmSearchBegin)
			    {
				fm_mode_var->scan_mode = FM_SCAN_STOP;
				os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL_INIT);
			    }
			    else if(IsFmSearchEnd)
			    {
				     	IsFmSearchBegin = 0;
					led_fre_set(0,0);						
					os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_NEXT_STATION);
				    	fm_mode_var->scan_mode = FM_SCAN_STOP;						
			    	}
				
		#endif
				
            }
#else
            res = fm_radio_init();
#endif
            if(res)
            {
///                rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
                rcsp_report_status(RCSP_REPORT_START_CONFIG);
                rcsp_set_task_status(STAUS_PLAY);
                fm_mode_var->fm_rec_op = &rec_fm_api;
                ui_open_fm(&fm_mode_var,sizeof(FM_MODE_VAR**));
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
				
            }
            else
            {
                fm_puts("init_fm_err\n");
                os_taskq_post_msg(MAIN_TASK_NAME,1,MSG_CHANGE_WORKMODE);
            }
            break;

#if  SUPPORT_FM_OPTION_VOICE		 
        case MSG_FM_SEARCHING:	
			
	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 	if(IsVoiceEnable==2)				
	 	{			 			 	
	        	  if(IsFmSearchBegin)
	        	  	{
		        	  	IsFmSearchBegin=0;
					os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL_INIT);
				  }
			  else
			  	{
		        		IsFmSearchBegin = 1;
		        		IsFmSearchEnd = 0;
		        		fm_prompt_play(BPF_FM_SCAN_EN_MP3);	
			  	}
		}
	 	else				
	 #endif		 						            					 		 			 					

			
		if(IsVoiceEnable)
        	{
        	  if(IsFmSearchBegin)
        	  	{
	        	  	IsFmSearchBegin=0;
				os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL_INIT);
			  }
			  else
			  	{
		        		IsFmSearchBegin = 1;
		        		IsFmSearchEnd = 0;
		        		fm_prompt_play(BPF_FM_SCAN_MP3);	
			  	}
        	}
        	else
        	{
			os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL_INIT);
        	}
        	break;
#endif


        case  MSG_FM_SCAN_ALL_INIT:
            fm_printf("MSG_FM_SCAN_ALL_INIT\n");
            led_fre_set(5,0);
            if (fm_mode_var->scan_mode == FM_SCAN_STOP)
            {
                fm_module_mute(1);
                os_time_dly(50);
                fm_info->dat[FM_CHAN]=0;
                fm_info->dat[FM_FRE]=0;
                clear_all_fm_point();
                fm_mode_var->wTotalChannel = 0;
                fm_mode_var->wFreChannel = 0;
                fm_mode_var->wFreq = MIN_FRE - 1;//自动搜索从最低的频点开始
                scan_counter = MAX_CHANNL;
                fm_mode_var->scan_mode = FM_SCAN_ALL;
                rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
		 #ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
		 	dac_mute(1,1);
		 	os_time_dly(10);		 
		 	SET_REXTERN_POWER_FM_SCAN_IO(1);
		 	os_time_dly(10);
		 	dac_mute(0,1);			 
		 #endif	
		 
		 #ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
		 	bFmMuteTimer=3;
		 	bFmUmuteTimer=0;
		 #endif
				
            }
            else
            {
                scan_counter = 1;//再搜索一个频点就停止
            }

//            rcsp_set_task_status(STAUS_SEARCHING);
//            task_status = STAUS_SEARCHING;

        case  MSG_FM_SCAN_ALL:
            //fm_printf("MSG_FM_SCAN_ALL\n");
            if (fm_radio_scan(fm_mode_var->scan_mode))
            {
                if (fm_mode_var->scan_mode == FM_SCAN_ALL)
                {
                    ///Update_rcsp_Task_State(msg[0],1);
///                    rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
                    rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
		#ifndef SUPPORT_FM_SCAN_PREVIEW_DISABLE
                    /// Wait one second
                    res = 10;
                    while(res)
                    {
                        Update_rcsp_Task_State(msg[0],1);
	                led_fre_set(0,0);	
			#ifdef FM_SCAN_STATION_VAL		
                        os_time_dly(FM_SCAN_STATION_VAL);// 20
                       #else
                        os_time_dly(10);// 20					   
			  #endif
					   
                        res--;
                    }
		#endif	
		
          		  led_fre_set(5,0);
                }
                else
                {
                    fm_mode_var->scan_mode = FM_SCAN_STOP;
                    led_fre_set(0,0);
                    SET_UI_UNLOCK();
///                    rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
                    rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
                    break;
                }
            }
			
            scan_counter--;
            if (scan_counter == 0)
            {
                if (fm_mode_var->scan_mode == FM_SCAN_ALL)                 //全频点搜索结束，播放第一个台
                {
			 #if  SUPPORT_FM_OPTION_VOICE	
			 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
			 	 	if(IsVoiceEnable==2)				
			 	 	{			 			 	
			               	 SET_UI_UNLOCK();
				              SET_UI_MAIN(MENU_FM_MAIN);
			                     led_fre_set(0,0);
			         	
						IsFmSearchBegin = 0;
						IsFmSearchEnd = 1;
						fm_prompt_play(BPF_FM_SCAN_END_EN_MP3);	
						break;	
			 		}
			 	 	else				
			 	 #endif		 						            					 		 			 					
			 
		 		if(IsVoiceEnable)
		         	{
		               	 SET_UI_UNLOCK();
			              SET_UI_MAIN(MENU_FM_MAIN);
		                     led_fre_set(0,0);
		         	
					IsFmSearchBegin = 0;
					IsFmSearchEnd = 1;
					fm_prompt_play(BPF_FM_SCAN_END_MP3);	
					break;			
			         }
			 #endif

			 #ifdef  SUPPORT_FM_SCAN_FINISH_DAC_MUTE    
				 bFmScanEndMuteDacTimer=4;
                   		 dac_mute(1,1);
			 #endif
			 
			 #ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
			 	 SET_REXTERN_POWER_FM_SCAN_IO(0);
			 #endif	
	 		 #ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
	 		 	bFmMuteTimer=0;
	 		 	bFmUmuteTimer=4;
	 		 #endif
			 
                    os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_NEXT_STATION);
                    fm_mode_var->scan_mode = FM_SCAN_STOP;
                    fm_printf("FM_SCAN_OVER \n");
                    rcsp_set_task_status(STAUS_PLAY);
                }
                else                            //半自动搜索，播放当前频点
                {
			 #ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
			 	 SET_REXTERN_POWER_FM_SCAN_IO(0);
			 #endif	
  	 		 #ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
	 		 	bFmMuteTimer=0;
	 		 	bFmUmuteTimer=4;
	 		 #endif
              
                    fm_mode_var->scan_mode = FM_SCAN_STOP;
                    fm_module_mute(0);
                    fm_printf("FM_SCAN_OVER else \n");

                }
                led_fre_set(0,0);
                SET_UI_UNLOCK();
                rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
///                rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
            }
            else       //搜索过程
            {
                os_time_dly(1);
                if(fm_mode_var->scan_mode != FM_SCAN_STOP)
                {
                    os_sched_lock();
                    res = os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL);
                    if(res == OS_Q_FULL)
                    {
                        os_taskq_flush_name(FM_TASK_NAME);
                        os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL);
                    }
                    os_sched_unlock();

                }
            }

            if(fm_mode_var->scan_mode == FM_SCAN_STOP)
            {
//                task_status = STAUS_PLAY;
///                rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
                rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
                rcsp_set_task_status(STAUS_PLAY);
            }
            else
            {
//                task_status = STAUS_SEARCHING;
            }

            break;

        case MSG_FM_SCAN_ALL_DOWN:
   	     led_fre_set(5,0);			
            fm_printf("MSG_FM_SCAN_ALL_DOWN\n");
            /* fm_mode_var->scan_mode = FM_SCAN_NEXT; */
            fm_mode_var->scan_mode = FM_SCAN_PREV;
            os_taskq_post(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL);
            break;

        case MSG_FM_SCAN_ALL_UP:
   	     led_fre_set(5,0);			
            fm_printf("MSG_FM_SCAN_ALL_UP\n");
            /* fm_mode_var->scan_mode = FM_SCAN_PREV; */
            fm_mode_var->scan_mode = FM_SCAN_NEXT;
            os_taskq_post(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL);
            break;

        case  MSG_FM_PREV_STEP:
            fm_printf("MSG_FM_PREV_STEP\n");
            res=fm_module_set_fre(FM_FRE_DEC);
            if(res)
            {
                save_fm_point(fm_mode_var->wFreq - MIN_FRE);
                fm_mode_var->wTotalChannel = get_total_mem_channel();
            }
            fm_mode_var->wFreChannel = get_channel_via_fre(fm_mode_var->wFreq - MIN_FRE);
            fm_info->dat[FM_FRE]=fm_mode_var->wFreq - MIN_FRE;
            fm_info->dat[FM_CHAN]=fm_mode_var->wFreChannel;
            fm_save_info();
            fm_module_mute(0);
            if(!res)
            {
                fm_mode_var->wFreChannel = 0;
            }
            UI_menu(MENU_FM_MAIN);
            rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
//            task_status = STAUS_PLAY;
            break;

        case MSG_FM_NEXT_STEP:
            fm_printf("MSG_FM_NEXT_STEP\n");
            res=fm_module_set_fre(FM_FRE_INC);
            if(res)
            {
                save_fm_point(fm_mode_var->wFreq - MIN_FRE);
                fm_mode_var->wTotalChannel = get_total_mem_channel();
            }
            fm_mode_var->wFreChannel = get_channel_via_fre(fm_mode_var->wFreq - MIN_FRE);
            fm_info->dat[FM_FRE]=fm_mode_var->wFreq - MIN_FRE;
            fm_info->dat[FM_CHAN]=fm_mode_var->wFreChannel;
            fm_save_info();
            fm_module_mute(0);
            if(!res)
            {
                fm_mode_var->wFreChannel = 0;
            }
            UI_menu(MENU_FM_MAIN);
            rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
//            task_status = STAUS_PLAY;
            break;

#if   SUPPORT_FM_OPTION_VOICE

        case MSG_FM_PREV_STATION:

            if (fm_mode_var->wTotalChannel == 0)
            	{
	         #ifdef SUPPORT_SINGLE_WIRE_COMMUNICATION
	                  my_fm_data();
	         #endif            	
                break;
            	}	
          	  fm_mode_var->wFreChannel -= 1;

				 if ((fm_mode_var->wFreChannel == 0) || (fm_mode_var->wFreChannel == 0xff))
				 {
						 fm_mode_var->wFreChannel = fm_mode_var->wTotalChannel;
				 }
				 else if (fm_mode_var->wFreChannel > fm_mode_var->wTotalChannel)
				 {
						 fm_mode_var->wTotalChannel = get_total_mem_channel();
						 fm_mode_var->wFreChannel = 1;
				 }
				 
				 fm_mode_var->wLastwTotalChannel=fm_mode_var->wTotalChannel;
				 fm_mode_var->wFreq = get_fre_via_channle(fm_mode_var->wFreChannel) + MIN_FRE;			 //根据台号找频点
				 fm_module_set_fre(FM_CUR_FRE);
				 fm_info->dat[FM_FRE]=fm_mode_var->wFreq - MIN_FRE;
				 fm_info->dat[FM_CHAN]=fm_mode_var->wFreChannel;

				 fm_save_info();
				 fm_module_mute(0);

				 UI_menu(MENU_FM_CHANNEL);
			  #if   SUPPORT_FM_OPTION_VOICE
			 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
			 	 	if(IsVoiceEnable==2)				
			 	 	{			 			 	
			           	 	fm_prompt_play(BPF_LAST_CH_EN_MP3);
			 		}
			 	 	else				
			 	 #endif		 						            					 		 			 					
							   	
				if(IsVoiceEnable)
			            {
			            	fm_prompt_play(BPF_LAST_CH_MP3);
			            }		
			   #endif			
				 
			break;
			
			
        case MSG_FM_NEXT_STATION:


		 
            if (fm_mode_var->wTotalChannel == 0)
            {
	        #ifdef SUPPORT_SINGLE_WIRE_COMMUNICATION
	                 my_fm_data();
	        #endif     
			
                fm_module_mute(0);
                break;
            }

            fm_mode_var->wFreChannel++;
            if ((fm_mode_var->wFreChannel == 0) || (fm_mode_var->wFreChannel == 0xff))
            {
                fm_mode_var->wFreChannel = fm_mode_var->wTotalChannel;
            }
            else if (fm_mode_var->wFreChannel > fm_mode_var->wTotalChannel)
            {
                fm_mode_var->wTotalChannel = get_total_mem_channel();
                fm_mode_var->wFreChannel = 1;
            }
            fm_mode_var->wLastwTotalChannel=fm_mode_var->wTotalChannel;
            fm_mode_var->wFreq = get_fre_via_channle(fm_mode_var->wFreChannel) + MIN_FRE;				//根据台号找频点
  		  fm_module_set_fre(FM_CUR_FRE);
            fm_info->dat[FM_FRE]=fm_mode_var->wFreq - MIN_FRE;
            fm_info->dat[FM_CHAN]=fm_mode_var->wFreChannel;

		
            fm_save_info();
            fm_module_mute(0);


            UI_menu(MENU_FM_CHANNEL);

	  #if   SUPPORT_FM_OPTION_VOICE
	       if(IsFmSearchEnd)
	       	{
			       IsFmSearchEnd=0;	  
			   break;
	       	}
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 	 	if(IsVoiceEnable==2)				
	 	 	{			 			 	
	           	 	fm_prompt_play(BPF_NEXT_CH_EN_MP3);
	 		}
	 	 	else				
	 	 #endif		 						            					 		 			 							   
		if(IsVoiceEnable)
	            {
	            	fm_prompt_play(BPF_NEXT_CH_MP3);
	            }		
	   #endif			
			
            break;
			
#else

        case MSG_FM_PREV_STATION:
	//		printf("111111111111\n");
            fm_printf("MSG_FM_PREV_STATION\n");
            if (fm_mode_var->wTotalChannel == 0)
                break;
            fm_mode_var->wFreChannel -= 2;

        case MSG_FM_NEXT_STATION:
	//		printf("22222222222222\n");
			
            fm_printf("MSG_FM_NEXT_STATION\n");
            fm_mode_var->wFreChannel++;
            set_fm_channel();
			
            break;
#endif
#if 0
        case MSG_FM_SELECT_CHANNEL:
            fm_mode_var->wFreChannel = msg[1];
            set_fm_channel();
            rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
            break;
        case MSG_FM_SELECT_FREQ:
            fm_mode_var->wFreq = msg[1];
            fm_mode_var->wFreChannel = get_channel_via_fre(fm_mode_var->wFreq - MIN_FRE);
            fm_module_set_fre(FM_CUR_FRE);
            fm_module_mute(0);
            rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
            break;
#endif

        case MSG_FM_PP:
            /* fm_msg_printf(); //for fm_scan_debug */
#if UI_ENABLE
            if (UI_var.bCurMenu == MENU_INPUT_NUMBER)   //暂停和播放
            {
                os_taskq_post(FM_TASK_NAME, 1, MSG_INPUT_TIMEOUT);
                break;
            }
#endif

#if defined SUPORT_FM_PP_CANEL_SCAN
	if (fm_mode_var->scan_mode == FM_SCAN_ALL)
	{
		os_taskq_post_msg(FM_TASK_NAME, 1, MSG_FM_SCAN_ALL_INIT);
		break;
	}
#endif

            if(msg[1] == RCSP_CBK_MSG_COMM_PLAY)
            {
                if(fm_mode_var->fm_mute != 0)
                {
                    fm_module_mute(0);
                }
            }
            else if(msg[1] == RCSP_CBK_MSG_COMM_PAUSE)
            {
                if(fm_mode_var->fm_mute == 0)
                {
                    fm_module_mute(1);
                }
            }
            else
            {
                if(fm_mode_var->fm_mute == 0)
                {
                    fm_module_mute(1);
                }
                else
                {
                    fm_module_mute(0);
                }
            }

            if(fm_mode_var->fm_mute == 0)
            {
                rcsp_set_task_status(STAUS_PLAY);
            }
            else
            {
                rcsp_set_task_status(STAUS_PAUSE);
            }

            break;
#if 0
        case MSG_FM_DEL_CHANNEL:
            del_fm_channel((u8)msg[1]);
            rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
            break;

        case MSG_FM_SAVE_CHANNEL:
            save_fm_channel((u16)msg[1]);
            rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
            break;
#endif			
        /*
                case MSG_MUSIC_PP:
        #if UI_ENABLE
                    if (UI_var.bCurMenu == MENU_INPUT_NUMBER)   //暂停和播放
                    {
                        os_taskq_post(FM_TASK_NAME, 1, MSG_INPUT_TIMEOUT);
                        break;
                    }
        #endif
                    break;
        */
        case MSG_INPUT_TIMEOUT:
            /*由红外界面返回*/
            if (input_number <= MAX_CHANNL)							//输入的是台号
            {
                msg[0] = get_fre_via_channle(input_number);
                if (msg[0] != 0xff)
                {
                    fm_mode_var->wFreq = msg[0] + MIN_FRE;
                    fm_mode_var->wFreChannel = input_number;
                    fm_module_set_fre(FM_CUR_FRE);
                    fm_module_mute(0);					
                    UI_menu(MENU_FM_DISP_FRE);
                    rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
                }
            }
            else if ((input_number >= MIN_FRE) && (input_number <= MAX_FRE)) //输入的是频点
            {
                fm_mode_var->wFreq = input_number;
                fm_mode_var->wFreChannel = get_channel_via_fre(fm_mode_var->wFreq - MIN_FRE);
                fm_module_set_fre(FM_CUR_FRE);
                fm_module_mute(0);
                rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
            }
            input_number = 0;
            input_number_cnt= 0;
            UI_menu(MENU_FM_MAIN);

            break;

        case MSG_PROMPT_PLAY:
        case MSG_LOW_POWER:
            puts("fm_low_power\n");
            fm_prompt_play(BPF_LOW_POWER_MP3);
            break;

#if LCD_SUPPORT_MENU
        case MSG_ENTER_MENULIST:
            UI_menu_arg(MENU_LIST_DISPLAY,UI_MENU_LIST_ITEM);
            break;
#endif

#if   SUPPORT_ALL_VOICE

#if   SUPPORT_TY_VOICE==0

	#ifdef SUPPORT_VOICE_ONOFF_KEY_SINGLE_KEY
		case MSG_FM_VOICE_SWITCH:	

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
					fm_prompt_play(BPF_VOICE_OFF_MP3);
				else
					fm_prompt_play(BPF_VOICE_OFF_EN_MP3);							 
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
					fm_prompt_play(BPF_VOICE_ON_MP3);
				else
					fm_prompt_play(BPF_VOICE_ON_EN_MP3);
					
			}

			break;
			
		case MSG_FM_VOICE_CHANGE:	

		 		if(IsVoiceEnable==1)				
		 		{
		 			IsVoiceEnable=2;
					 #ifdef LED_SHOW_ONOFF
					 	UI_menu(MENU_VOICE_EN); 
					 #endif			 
					
			 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 #endif
								 
					fm_prompt_play(BPF_VOICE_EN_MP3);
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
									
					fm_prompt_play(BPF_VOICE_CH_MP3);
				}

			break;
			
	#else
	
		case MSG_FM_VOICE_SWITCH:	

	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==1)				
		 	{			 			 
				 IsVoiceEnable = 2;
				 
				 #ifdef LED_SHOW_ONOFF
					 UI_menu(MENU_ON); 
				 #endif				
				 #ifdef SUPPORT_VOICE_ENALBE_MEM
					 vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
				 #endif
				 
				 fm_prompt_play(BPF_VOICE_ON_EN_MP3);			 	
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
	 	 				 
	 	 				 fm_prompt_play(BPF_VOICE_OFF_MP3);	
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
	 	 				
	 	 				 fm_prompt_play(BPF_VOICE_ON_MP3);	
	 	 			}	
	 	 		
	 	 			break;	
	 	 
	 	 #endif

		#endif


	 #ifdef SUPPORT_MUTE_VOICE
	 
	    case MSG_VOICE_MUTE:
		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
	    				fm_prompt_play(BPF_MUTE_EN_MP3);			    		    				 	    		    		    	
				}
		 		else				
		  	#endif	
			if(IsVoiceEnable)
		    	{
	    			fm_prompt_play(BPF_MUTE_MP3);			    		    				 	    		    		    	
		    	}
	    	break;
	    case MSG_VOICE_MUTE_OFF:

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
	    				fm_prompt_play(BPF_MUTE_OFF_EN_MP3);			    		    				 	    		    		    	
				}
		 		else				
		  	#endif	
			if(IsVoiceEnable)
		    	{
	    			fm_prompt_play(BPF_MUTE_OFF_MP3);			    		    				 	    		    		    	
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
		    				fm_prompt_play(BPF_VL_MAX_EN_MP3);			    		    				 	    		    		    					 
				else		
		    				fm_prompt_play(BPF_VL_INC_EN_MP3);			    		    				 	    		    		    					 
			}
		 	else				
		 #endif		 						            					 		 			 					
			#if SUPPORT_VOL_VOICE			
			
			 if(IsVoiceEnable)
			 {		
				if(dac_ctl.sys_vol_l ==30)	
		    				fm_prompt_play(BPF_VL_MAX_MP3);			    		    				 	    		    		    					 
				else		
		    				fm_prompt_play(BPF_VL_INC_MP3);			    		    				 	    		    		    					 
			 }
		 #endif		 						            					 		 			 					
			 break;		
		
		case MSG_VOICE_VOLUME_MINUS:
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==2)				
		 	{			 			 	
    				fm_prompt_play(BPF_VL_DEC_EN_MP3);			    		    				 	    		    		    					 
			}
		 	else				
		 #endif		 						            					 		 			 					
			#if SUPPORT_VOL_VOICE			

			 if(IsVoiceEnable)
			 {
	    			fm_prompt_play(BPF_VL_DEC_MP3);			    		    				 
			 }
			 #endif		 						            					 		 			 					
		 break;

	    case MSG_MAX_VOICE:
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==2)				
		 	{			 			 	
    				fm_prompt_play(BPF_VL_MAX_EN_MP3);			    		    				 	    		    		    					 
			}
		 	else				
		 #endif		 						            					 		 			 					
			#if SUPPORT_VOL_VOICE			

		if(IsVoiceEnable)
	    	{
	    			fm_prompt_play(BPF_VL_MAX_MP3);			    		    				 
	    	 		    		    				 
	    	}
		 #endif		 						            					 		 			 					
	    	break;	
#endif
		


#else

	 #ifdef SUPPORT_VOICE_MODE_KEY

		case MSG_FM_VOICE_SWITCH:

			if(IsVoiceEnable)
			{
				 IsVoiceEnable = 0;
				 
				 #ifdef LED_SHOW_ONOFF
					 UI_menu(MENU_OFF); 
				 #endif				
				 #ifdef SUPPORT_VOICE_ENALBE_MEM
					 vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
				 #endif
				 
				 fm_prompt_play(BPF_VOICE_OFF_MP3);	
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
				
				 fm_prompt_play(BPF_VOICE_ON_MP3);	
			}	
		break;	 
	 #endif


#endif





		 #ifdef SUPPORT_SCG_VOICE
		 
	 		 #ifdef SUPPORT_MUTE_VOICE
	 		 
	 		 	case MSG_VOICE_MUTE:
	 	 		 	if(bVoiceOnoff)				
	 	 		 	{
	 	 		 		fm_prompt_play(BPF_MUTE_EN_MP3);			    		    				 	    		    		    	
	 	 		 	}
	 		 	break;
	 			
	 		 	case MSG_VOICE_MUTE_OFF:
	 		 
	 		 	if(bVoiceOnoff)				
	 		 	{
	 		 		fm_prompt_play(BPF_MUTE_OFF_EN_MP3);			    		    				 	    		    		    	
	 		 	}
	 		 	break;
	 		 
	 		 #endif
		 
		 
		 	case MSG_VOICE_VOLUME_PLUS:
	 		 	if(bVoiceOnoff)				
	 		 	{			 			 
	 		 		if(dac_ctl.sys_vol_l ==30)	
	 		 			fm_prompt_play(BPF_VL_MAX_MP3);			    		    				 	    		    		    					 
	 		 		else		
	 		 			fm_prompt_play(BPF_VL_INC_MP3);			    		    				 	    		    		    					 
	 		 	}
		 	break;		
		 
		 	case MSG_VOICE_VOLUME_MINUS:
		 		if(bVoiceOnoff)				
	 		 	{			 			 	
	 		 		fm_prompt_play(BPF_VL_DEC_MP3);			    		    				 	    		    		    					 
	 		 	}
		 	break;
		 
		 	case MSG_MAX_VOICE:
		 		if(bVoiceOnoff)				
	 		 	{			 			 	
	 		 		fm_prompt_play(BPF_VL_MAX_MP3);			    		    				 	    		    		    					 
	 		 	}
		 	break;	
		 
		 
		 #endif






#ifdef SUPPORT_SCG_VOICE

  #if SUPPORT_VOICE_NUMBER

	    case MSG_VOICE_NUMBER:

		if(IsVoiceEnable)
	    	{
			if(bVoiceNumber == 0)	
		            {
		            	 tone_play_by_name(FM_TASK_NAME, 1,BPF_0_EN_MP3);
		            }
		            else if(bVoiceNumber == 1)
		            {
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_1_EN_MP3);
		            }
		            else if(bVoiceNumber == 2)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_2_EN_MP3);
		            }
		            else if(bVoiceNumber == 3)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_3_EN_MP3);
		            }
		            else if(bVoiceNumber == 4)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_4_EN_MP3);
		            }
		            else if(bVoiceNumber == 5)
		            {		            
		           		 tone_play_by_name(FM_TASK_NAME,1, BPF_5_EN_MP3);
		            }
		            else if(bVoiceNumber == 6)
		            {
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_6_EN_MP3);
		            }
		            else if(bVoiceNumber == 7)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_7_EN_MP3);
		            }
		            else if(bVoiceNumber == 8)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_8_EN_MP3);
		            }
		            else if(bVoiceNumber == 9)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_9_EN_MP3);
		            }
	    	 		    		    				 
	    	}
	    	break;	

 	#endif	



#else


  #if SUPPORT_VOICE_NUMBER

	    case MSG_VOICE_NUMBER:

		if(IsVoiceEnable)
	    	{
			if(bVoiceNumber == 0)	
		            {
		            	 tone_play_by_name(FM_TASK_NAME, 1,BPF_0_MP3);
		            }
		            else if(bVoiceNumber == 1)
		            {
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_1_MP3);
		            }
		            else if(bVoiceNumber == 2)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_2_MP3);
		            }
		            else if(bVoiceNumber == 3)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_3_MP3);
		            }
		            else if(bVoiceNumber == 4)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_4_MP3);
		            }
		            else if(bVoiceNumber == 5)
		            {		            
		           		 tone_play_by_name(FM_TASK_NAME,1, BPF_5_MP3);
		            }
		            else if(bVoiceNumber == 6)
		            {
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_6_MP3);
		            }
		            else if(bVoiceNumber == 7)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_7_MP3);
		            }
		            else if(bVoiceNumber == 8)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME,1, BPF_8_MP3);
		            }
		            else if(bVoiceNumber == 9)
		            {
		            
		            	tone_play_by_name(FM_TASK_NAME, 1,BPF_9_MP3);
		            }
	    	 		    		    				 
	    	}
	    	break;	

 	#endif	


#endif



#ifdef SUPPORT_MIC_ONOFF_VOICE

		case MSG_VOICE_MIC:

			if(mic_sw)
	    			fm_prompt_play(BPF_MIC_ON_MP3);
			else
	    			fm_prompt_play(BPF_MIC_OFF_MP3);

			break;
#endif


#endif	


        case MSG_HALF_SECOND:
			
#if FM_REC_EN
            if(updata_enc_time(rec_fm_api))
            {
                UI_menu(MENU_HALF_SEC_REFRESH);
            }
#endif


			 #ifdef  SUPPORT_FM_SCAN_FINISH_DAC_MUTE    
			 if(bFmScanEndMuteDacTimer)
			 	{
			 	bFmScanEndMuteDacTimer--;
				if(bFmScanEndMuteDacTimer==1)
					{
						 bFmScanEndMuteDacTimer=0;
				     		 dac_mute(0,1);
					 }
			 	}
              
			 #endif

            if(fm_mode_var->scan_mode == FM_SCAN_STOP)
            {
                if(fm_mode_var->fm_mute == 0)
                {
                    rcsp_set_task_status(STAUS_PLAY);
                }
                else
                {
                    rcsp_set_task_status(STAUS_PAUSE);
                }
            }

            break;

#if 1//EQ_EN
        case MSG_MUSIC_EQ:
        {
            if(msg[1] != 0)
            {
                //指定选择
                eq_mode = msg[1]&0x0f;
            }
            else
            {
                eq_mode++;
            }
            if(eq_mode > 5)
            {
                eq_mode = 0;
            }
//                EQ_module_ChangeGain((int*)eq_filter,(int*)eq_seg_gain[eq_mode],eq_global_gain[eq_mode]);
            printf("MSG_FM_EQ %d, \n ", eq_mode);
        }
        rcsp_report_status(RCSP_REPORT_EQ_VALUE);
        break;
#endif/*EQ_EN*/


        default:
            if(msg[0] == MSG_ECHO_START)//start echo
            {
                exit_rec_api(&rec_fm_api); //stop rec
            }
            else if (msg[0] == MSG_REC_START)//start rec
            {
                echo_exit_api(&fm_reverb);//stop echo
            }
            echo_msg_deal_api(&fm_reverb, msg);
            rec_msg_deal_api(&rec_fm_api, msg);
            break;
        }
        Update_rcsp_Task_State(msg[0],1);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief  FM模式主线程初始化
   @param  priv：NULL
   @return NULL
   @note   static void fm_radio_task_init(void *priv)
*/
/*----------------------------------------------------------------------------*/
static void fm_radio_task_init(void *priv)
{
    u32 err;

    err = os_task_create(fm_radio_task,
                         (void*)0,
                         TaskFMradioPrio,
                         50
#if OS_TIME_SLICE_EN > 0
                         ,1
#endif
                         ,FM_TASK_NAME);

    if(OS_NO_ERR == err)
    {
	 #ifdef SUPPORT_TM1628_KEY_READ
	         key_msg_register(FM_TASK_NAME,fm_led_table,fm_ad_table,fm_io_table,fm_ir_table,NULL);
	 #else    
	         key_msg_register(FM_TASK_NAME,fm_ad_table,fm_io_table,fm_ir_table,NULL);
	 #endif
    
    }

#ifdef SUPPORT_PT2313
		Pt2313_ChangSource(Aud_SwRadio);
#endif


#ifdef support_sound_4052_control
#if defined sound_4052_io_mode_6 ||defined sound_4052_io_mode_5
	AC4052_IS_FM(); 
#endif
#endif
#ifdef KOK_DETECT_AUTO_VOL_SET
///	 store_vol= dac_ctl.sys_vol_l;
	dac_ctl.sys_vol_l = 30;
	dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;
	set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);


#endif




}

/*----------------------------------------------------------------------------*/
/**@brief  FM模式退出
   @param  NULL
   @return NULL
   @note   static void fm_radio_task_exit(void)
*/
/*----------------------------------------------------------------------------*/
static void fm_radio_task_exit(void)
{
    /*先关闭FM模块线程，再关闭FM变采样线程*/
    if (os_task_del_req(FM_TASK_NAME) != OS_TASK_NOT_EXIST)
    {
        os_taskq_flush_name(FM_TASK_NAME);
        os_taskq_post_msg(FM_TASK_NAME, 1, SYS_EVENT_DEL_TASK);
        do
        {
//            fm_puts("fm_wating-01\n");
            OSTimeDly(1);
        }
        while(os_task_del_req(FM_TASK_NAME) != OS_TASK_NOT_EXIST);
        fm_puts("clos_fm_task_succ-01\n");
    }
}

static void set_fm_channel(void)
{
    if (fm_mode_var->wTotalChannel == 0)
    {
        fm_mode_var->wFreChannel = 0;
        fm_mode_var->wFreq = 875;
        fm_module_set_fre(FM_CUR_FRE);
        fm_module_mute(0);
        return;
    }

    if ((fm_mode_var->wFreChannel == 0) || (fm_mode_var->wFreChannel == 0xff))
    {
        fm_mode_var->wFreChannel = fm_mode_var->wTotalChannel;
    }
    else if (fm_mode_var->wFreChannel > fm_mode_var->wTotalChannel)
    {
        fm_mode_var->wTotalChannel = get_total_mem_channel();
        fm_mode_var->wFreChannel = 1;
    }
    fm_mode_var->wLastwTotalChannel=fm_mode_var->wTotalChannel;
    fm_mode_var->wFreq = get_fre_via_channle(fm_mode_var->wFreChannel) + MIN_FRE;				//根据台号找频点
    fm_module_set_fre(FM_CUR_FRE);
    fm_info->dat[FM_FRE]=fm_mode_var->wFreq - MIN_FRE;
    fm_info->dat[FM_CHAN]=fm_mode_var->wFreChannel;
    fm_save_info();
    fm_module_mute(0);
	
    UI_menu(MENU_FM_CHANNEL);
//    rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
//    task_status = STAUS_PLAY;
}

static void del_fm_channel(u8 chl_num)
{
    u8 i=0;
    u8 j=0;
    u8 byte=0;
    u8 channel=0;

    if (fm_mode_var->wTotalChannel == 0)
    {
        fm_module_mute(0);
        return;
    }
    if ((chl_num == 0) || (chl_num > fm_mode_var->wTotalChannel))
    {
        return;
    }

    //找到channel 有效频点 标记位
    for(i = 0; i < MEM_FM_LEN; i++)
    {
        byte = fm_info->dat[FM_CHANNL + i];
        for(j=0; j < 8; j++)
        {
            if((byte & (1<<j)) != 0)
            {
                channel++;
                if(chl_num == channel )
                {
                    fm_info->dat[FM_CHANNL + i] &= (~(1<<j));
                    goto del_end;
                }
            }
        }
    }

    return;

del_end:

    fm_save_info();

    fm_mode_var->wTotalChannel--;
    if(fm_mode_var->wTotalChannel == 0)
    {
        fm_mode_var->wFreq = 0;
        fm_module_mute(0);
    }
    else
    {
        if(chl_num < fm_mode_var->wFreChannel)
        {
            //删除当前播放的之前电台
            fm_mode_var->wFreChannel--;
        }

        if (fm_mode_var->wFreChannel > fm_mode_var->wTotalChannel)
        {
            fm_mode_var->wFreChannel = 1;
        }
    }

    set_fm_channel();

///    rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
///    rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
}

static void save_fm_channel(u16 save_freq)
{
    u8 i=0;
    u8 j=0;
    u8 byte=0,byte1;
    u8 channel=0;

    byte = save_freq - MIN_FRE;
    i = (byte >>3);
    if(i >= MEM_FM_LEN)
    {
        return;
    }

    j = (byte &0x07);

    if((fm_info->dat[FM_CHANNL + i] & (1<<j)) != 0)
    {
        //already save
        return;
    }
    fm_info->dat[FM_CHANNL + i] |= (1<<j);

    fm_save_info();

    //确定 channel num
    for(i = 0; i < MEM_FM_LEN; i++)
    {
        byte1 = fm_info->dat[FM_CHANNL + i];
        for(j=0; j < 8; j++)
        {
            if((byte1 & (1<<j)) != 0)
            {
                channel++;
                if(byte == (i*8+j))
                {
                    goto save_end;
                }
            }
        }
    }

save_end:

    fm_mode_var->wTotalChannel++;
    fm_mode_var->wFreChannel = channel;
    set_fm_channel();

///    rcsp_report_status(RCSP_REPORT_RADIO_TABLE);
///    rcsp_report_status(RCSP_REPORT_RADIO_CHANNEL);
}

TASK_REGISTER(fm_radio_task_info) =
{
    .name = FM_TASK_NAME,
    .init = fm_radio_task_init,
    .exit = fm_radio_task_exit,
};


#endif
