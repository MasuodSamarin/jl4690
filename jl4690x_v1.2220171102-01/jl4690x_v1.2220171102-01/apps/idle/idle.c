#include "common/app_cfg.h"
#include "rtos/os_api.h"
#include "rtos/os_cfg.h"
#include "common/error.h"
#include "common/msg.h"
#include "rtos/task_manage.h"
#include "sys_detect.h"
#include "dac/dac_api.h"
#include "play_sel/play_sel.h"
#include "key_drv/key.h"
#include "idle_key.h"
#include "idle.h"
#include "dac/dac.h"
#include "ui/ui_api.h"
#include "led7_drv.h"
#include "sys_detect.h"

#include "rcsp/rcsp_interface.h"
#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif
#if defined(SUPPORT_FS_BAT_DET_MODE)
extern u8 bBatMode;
#endif
#if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5
extern bool bLowePoweStanbyFlag;
#endif
#if defined SUPPORT_JH_POWER_SWITCH_IO
extern bool bStandbyModeFlag;
#endif
#ifdef AMP_MUTE_ENABLE
extern  u8 bPowerOnAmpMuteTimer;
#endif


#ifdef SUPPORT_LOW_POWER_STANBY
bool bLowPowerFlag;	
#endif

#if defined support_sw_chack
u8 bPowerSwFlag;
bool bIcPowerDcDetFlag;
#endif


#ifdef SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ
extern bool bStandbyModeFlagMsj;
bool	bLowPowerFlag;	
bool	bIcPowerDcDetFlag;	
u8	 bPowerSwFlag;
bool	SwFlag;	

#endif






extern void *malloc_fun(void *ptr,u32 len,char *info);
extern void free_fun(void **ptr);
/*----------------------------------------------------------------------------*/
/**@brief  Idle 任务
   @param  p：任务间参数传递指针
   @return 无
   @note   static void idle_task(void *p)
*/
/*----------------------------------------------------------------------------*/
static void idle_task(void *p)
{
    int msg[3];

    idle_puts("\n************************Idle TASK********************\n");
    //led_fre_set(15,0);

#ifdef SUPPORT_STANDBY_MODE_AMP_MUTE
#if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5
#if defined(PA_ENABLE)
	if(bLowePoweStanbyFlag)
	 pa_mute();
#endif
#endif
#endif

#ifdef support_stanby_mod

#ifdef SUPPORT_IDLE_MODE_SHOW_2POINT_FLASH

        SET_UI_MAIN(MENU_STANBY_MAIN);
        UI_menu(MENU_STANBY_MAIN);

#elif defined(SUPPORT_LOW_POWER_STANBY)
	DC_DET_IO_IS_IN(); //充电检测

if(bLowPowerFlag||bIcPowerDcDetFlag||bPowerSwFlag)
   {   
   
	   if(!DC_DET_READ())
	   	{
		   UI_menu(MENU_STANBY_OFF); //SHOW OFF
		   os_time_dly(80);   	
		   os_time_dly(80);
		   SET_UI_MAIN(MENU_STANBY_MAIN); //show ----
		   UI_menu(MENU_STANBY_MAIN);   	
		   printf("low power ------");
	   	}
	   else
	   	{
		   UI_menu(MENU_STANBY_OFF);
		   os_time_dly(80);
		   os_time_dly(80); 	   
		   SET_UI_MAIN(MENU_STANBY_MAIN); // show null
		   UI_menu(MENU_STANBY_MAIN);
		   printf("low power +++++++");
	   	}
   }
else if( workmode==STANBY_WORK_MODE)
{
	 UI_menu(MENU_STANBY_OFF);
	 os_time_dly(80);
	 SET_UI_MAIN(MENU_STANBY_MAIN);
	 UI_menu(MENU_STANBY_MAIN);
}
#elif defined(SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ)
	MSJ_DC_DET_IO_IS_IN(); //充电检测

if(bStandbyModeFlagMsj||bIcPowerDcDetFlag||bPowerSwFlag)
   {   
   
	   if(!MSJ_DC_DET_READ())
	   	{
		   UI_menu(MENU_STANBY_OFF); //SHOW OFF
		   os_time_dly(80);   	
		   os_time_dly(80);
		   SET_UI_MAIN(MENU_STANBY_MAIN); //show ----
		   UI_menu(MENU_STANBY_MAIN);   	
		   printf("low power ------");
	   	}
	   else
	   	{
		   UI_menu(MENU_STANBY_OFF);
		   os_time_dly(80);
		   os_time_dly(80); 	   
		   SET_UI_MAIN(MENU_STANBY_MAIN); // show null
		   UI_menu(MENU_STANBY_MAIN);
		   printf("low power +++++++");
	   	}
   }
else if( workmode==STANBY_WORK_MODE)
{
	 UI_menu(MENU_STANBY_OFF);
	 os_time_dly(80);
	 SET_UI_MAIN(MENU_STANBY_MAIN);
	 UI_menu(MENU_STANBY_MAIN);
}
#else

#if defined(SUPPORT_FS_BAT_DET_MODE)
	if((bBatMode!=5)&&(workmode==STANBY_WORK_MODE))
#else
    if( workmode==STANBY_WORK_MODE)
#endif
    {
        UI_menu(MENU_STANBY_OFF);
        os_time_dly(80);
        os_time_dly(80);		
        SET_UI_MAIN(MENU_STANBY_MAIN);
        UI_menu(MENU_STANBY_MAIN);
    }
    else
    {
        SET_UI_MAIN(MENU_STANBY_MAIN);
        UI_menu(MENU_STANBY_MAIN);
    }
#endif

#endif


#if defined SUPPORT_POWER_ON_TONE

	if(bPowerOnVoiceFlag)
		{
		     #ifdef SUPPORT_POWER_ON_TONE_SHOW_HI
		             SET_UI_MAIN(MENU_POWER_UP);
		             UI_menu(MENU_POWER_UP);
		     #endif
		
		        tone_play_by_name(IDLE_TASK_NAME,1,BPF_WELCOME_MP3);
		}
    else
	    os_taskq_post_msg(IDLE_TASK_NAME, 1, MSG_IDLE_MODE); //触发idle模块初始化

#elif defined support_power_off_voice


    if( workmode ==POWER_OFF_WORK_MODE)
        tone_play_by_name(IDLE_TASK_NAME,1,BPF_POWER_OFF);
    else
        os_taskq_post_msg(IDLE_TASK_NAME, 1, MSG_IDLE_MODE);
	
	
#else
    os_taskq_post_msg(IDLE_TASK_NAME, 1, MSG_IDLE_MODE); //触发idle模块初始化
#endif

    while(1)
    {
        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);
        clear_wdt();
        switch(msg[0])
        {
        
        case SYS_EVENT_DEL_TASK:
            if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
            {
                idle_puts("IDLE_SYS_EVENT_DEL_TASK\n");
		#if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_1||defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_4
			low_off_cnt=0;
		#endif
		  #if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5
		  	 bLowePoweStanbyFlag=0;
		  #endif
		  
		 #if defined SUPPORT_JH_POWER_SWITCH_IO
		 	bStandbyModeFlag=0;
		 #endif

                //play_sel_stop(); //关闭提示音
                os_task_del_res_name(OS_TASK_SELF);
            }
            break;

        case SYS_EVENT_PLAY_SEL_END: //提示音结束
            idle_puts("IDLE_SYS_EVENT_PLAY_SEL_END\n");
            //play_sel_stop(); //关闭提示音
            idle_puts("IDEL_play_tone_end\n");
			
		 #if defined SUPPORT_POWER_ON_TONE
		 			
		 	if(bPowerOnVoiceFlag)
		 	{
			       bPowerOnVoiceFlag = 0;	
				   
				if(!file_operate_get_total_phydev())
			            {
			            #ifdef power_on_no_usb_sd_to_bt
			                os_taskq_post("MainTask", 2, SYS_EVENT_TASK_RUN_REQ, "BtStackTask");
					#else
			                os_taskq_post("MainTask", 2, SYS_EVENT_TASK_RUN_REQ, "LineinTask");
					#endif
			            }
			            else
			            {
			                os_taskq_post("MainTask", 2, SYS_EVENT_TASK_RUN_REQ, "MusicTask");
			            }
			            
			            break;
		 	}
		     else
			 	
		 #endif	
		 
  	          os_taskq_post_msg(IDLE_TASK_NAME, 1, MSG_IDLE_MODE);
			
		 #ifdef support_power_off_voice
		 
		             if( workmode ==POWER_OFF_WORK_MODE)
		             {
		                 LED_INIT_DIS();
		 		 #if defined(PA_ENABLE)
		 		                 pa_mute();
		 		 #endif
		 		                 dac_off_control();
		 		 
		 		 #ifdef support_io_power_on_off
		 		                 Set_power_on_off_io_is_out();
		 		                 Set_power_on_off_io_is_LOW();
		 		                 //   going_to_pwr_off = 0;
		 		                 // soft_power_ctl(PWR_OFF);
		 		 #elif defined(support_690x_ic_rtc_stanby)
		 		                 //  idle_puts("IC待机\n");
		 		                 going_to_pwr_off = 0;
		 		                 soft_power_ctl(PWR_OFF);
		 		 #endif
		 
		             }
					 
		 #endif
            break;

        case MSG_IDLE_MODE:
			
            puts("MSG_IDLE_MODE\n");
//                ui_open_idle(NULL,0);
            //low_power_mode(WAKEUP_13,WAKEUP_DOWN_EDGE);
            break;


        case MSG_IDLE_CTL:
            puts("MSG_IDLE_CTL\n");
            os_taskq_post_msg(MAIN_TASK_NAME, 1, MSG_EXIT_IDLE_TASK);
            break;

        case MSG_HALF_SECOND:

		 #if defined SUPPORT_JH_POWER_SWITCH_IO
	  	  	SET_POWER_SWITCH_IN();				  	 
		 	if((bStandbyModeFlag)&&(POWER_SWITCH_CHECK()))
		 	{
		          	 os_taskq_post_msg("MainTask", 1, MSG_BT_MODE_KEY);  					 	
			}
		#elif defined SUPPORT_IDLE_MODE_SHOW_2POINT_FLASH

		        UI_menu(MENU_STANBY_MAIN);
		
		 #endif
		 
		 #if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ
	  	  	SW_IO_IS_IN();	
		 	MSJ_DC_DET_IO_IS_IN();
		 	if((bStandbyModeFlagMsj)&&(SW_IN_CHECK())&&(MSJ_DC_DET_READ()))
		 	{
		 		bStandbyModeFlagMsj=0;
		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);  					 	
			}
			else  if((SW_IN_CHECK())&&(MSJ_DC_DET_READ())&&(bPowerSwFlag==1))
			   {
				puts("idle	MSG_HALF_SECOND  2222 \n");			   
				  bPowerSwFlag=2;
				   os_taskq_post("MainTask",1,MSG_STANBY_KEY);
			 }
			else  if((SW_IN_CHECK())&&(MSJ_DC_DET_READ())&&(bIcPowerDcDetFlag))
			   {
				puts("idle	MSG_HALF_SECOND  333 \n");			   
				  bIcPowerDcDetFlag=0;
				   os_taskq_post("MainTask",1,MSG_STANBY_KEY);
			 }
		 #endif


	 #ifdef SUPPORT_LOW_POWER_STANBY
	 
			  SW_IO_IS_IN();	  
			 DC_DET_IO_IS_IN();
			 if(( SW_IN_CHECK())&&(DC_DET_READ())&&(bLowPowerFlag))
			   {			   
				   puts("idle  MSG_HALF_SECOND  1111 \n");
			   	  bLowPowerFlag=0;
				   os_taskq_post("MainTask",1,MSG_STANBY_KEY);
			 }			 
			else  if(( SW_IN_CHECK())&&(DC_DET_READ())&&(bPowerSwFlag==1))
			   {
				puts("idle	MSG_HALF_SECOND  2222 \n");			   
				  bPowerSwFlag=2;
				   os_taskq_post("MainTask",1,MSG_STANBY_KEY);
			 }
			else  if(( SW_IN_CHECK())&&(DC_DET_READ())&&(bIcPowerDcDetFlag))
			   {
				puts("idle	MSG_HALF_SECOND  333 \n");			   
				  bIcPowerDcDetFlag=0;
				   os_taskq_post("MainTask",1,MSG_STANBY_KEY);
			 }
			
	 #endif










			
            //idle_puts(" Idle_H ");
            break;

        default:
            break;
        }
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  IDLE 任务创建
   @param  priv：任务间参数传递指针
   @return 无
   @note   static void idle_task_init(void *priv)
*/
/*----------------------------------------------------------------------------*/
static void idle_task_init(void *priv)
{
    u32 err;
    err = os_task_create(idle_task,
                         (void*)0,
                         TaskIdlePrio,
                         10
#if OS_TIME_SLICE_EN > 0
                         ,1
#endif
                         ,IDLE_TASK_NAME);

    if(OS_NO_ERR == err)
    {
	 #ifdef SUPPORT_TM1628_KEY_READ
	        key_msg_register(IDLE_TASK_NAME,idle_led_table, idle_ad_table, idle_io_table, idle_ir_table, NULL);
	 #else    
        	key_msg_register(IDLE_TASK_NAME, idle_ad_table, idle_io_table, idle_ir_table, NULL);
	 #endif
    
    }

#ifdef SUPPORT_PT2313
	Pt2313_ChangSource(Aud_SwNoting);
#endif
#if defined(LED_ID_JW2781)
   led7_var.bEqCircleIfPlay=FALSE;
#endif

#ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
	 SET_REXTERN_POWER_FM_SCAN_IO(1);
#endif
#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
	 SET_REXTERN_POWER_FM_MUTE_IO(1);
#endif

#ifdef AMP_MUTE_ENABLE   
#ifdef  SUPPORT_AMP_STANDBY_MUTE
	AMP_MUTE_IO(1);
#endif
#endif

	workmode=STANBY_WORK_MODE;

}


/*----------------------------------------------------------------------------*/
/**@brief  IDLE 任务删除退出
   @param  无
   @return 无
   @note   static void idle_task_exit(void)
*/
/*----------------------------------------------------------------------------*/
static void idle_task_exit(void)
{
    if (os_task_del_req(IDLE_TASK_NAME) != OS_TASK_NOT_EXIST)
    {
        os_taskq_post_event(IDLE_TASK_NAME, 1, SYS_EVENT_DEL_TASK);
        do
        {
            OSTimeDly(1);
        }
        while(os_task_del_req(IDLE_TASK_NAME) != OS_TASK_NOT_EXIST);
        idle_puts("del_idle_task: succ\n");
    }
#ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
	 SET_REXTERN_POWER_FM_SCAN_IO(0);
#endif	
#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
	bFmUmuteTimer=4;
#endif

#ifdef SUPPORT_LOW_POWER_STANBY
	bLowPowerFlag=0;	
#endif

#ifdef SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ
	bLowPowerFlag=0;	
#endif





#ifdef AMP_MUTE_ENABLE   
#ifdef  SUPPORT_AMP_STANDBY_MUTE
#ifdef AMP_IDLE_MUTE_DELAY_DISABLE_TIMER
	bPowerOnAmpMuteTimer=AMP_IDLE_MUTE_DELAY_DISABLE_TIMER;
#else
	AMP_MUTE_IO(0);
#endif
#endif
#endif

}


/*----------------------------------------------------------------------------*/
/**@brief  IDLE 任务信息
   @note   const struct task_info idle_task_info
*/
/*----------------------------------------------------------------------------*/
TASK_REGISTER(idle_task_info) =
{
    .name = IDLE_TASK_NAME,
    .init = idle_task_init,
    .exit = idle_task_exit,
};
