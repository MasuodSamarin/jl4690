/***********************************Jieli tech************************************************
  File : timer.c
  By   : Juntham
  date : 2014-07-04 11:21
********************************************************************************************/
#include "sdk_cfg.h"
#include "timer.h"
#include "common/jiffies.h"
#include "rtos/os_api.h"
#include "key_drv/key.h"
#include "rtos/task_manage.h"
#include "clock_api.h"
#include "rtc/rtc.h"
#include "sys_detect.h"
#include "ui/led/led.h"
#include "key_drv/key_drv_ad.h"
#include "key_drv/key_drv_ir.h"
#include "ui/led/led7_drv.h"
#include "irq_api.h"
#include "linein/dev_linein.h"
#include "dev_manage/encoder.h"
#ifdef support_sw_chack
extern void ic_power_check_task(void);
#endif

/*
中断用到的变量可以都定义到结构体，
然后通过接口获取，方便管理
*/
extern void sys_timer_schedule();

///定时器0计数器，时间片轮换
__timer_handle  *timer0_hl;
u16 t0_cnt1;
u16 t0_cnt2;

extern u8 power_on_cnt;
#ifdef SUPPORT_LOW_POWER_DELAY_DET
extern u8 bLowPowerDetDelay;
#endif
#ifdef AMP_MUTE_ENABLE
 extern u8 bPowerOnAmpMuteTimer;
#endif
#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
extern u8 bFmUmuteTimer;
extern u8 bFmMuteTimer;
#endif

#ifdef support_power_on_dly
extern u8 bPowerOnMuteTimer; // jsuo 
#include "dac/dac.h"
#endif


/*----------------------------------------------------------------------------*/
/**@brief  get halfsec flag
   @param
   @return
   @note

 */
/*----------------------------------------------------------------------------*/
#if defined(SUPPORT_DOUBLE_LED7_PANEL)
u16 get_sys_halfsec(void)
{
    return g_var.sys_halfsec;
}
#else
u8 get_sys_halfsec(void)
{
    return g_var.sys_halfsec;
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief  get 2ms's count
   @param
   @return counkt
   @note

 */
/*----------------------------------------------------------------------------*/
u32 get_sys_2msCount(void)
{
    return g_var.g_2ms_seed;
}
int fun_printf;

void halfsec_msg_sender(char *name, u32 msg)
{
	u32 cnt = 0;
	os_taskq_count(name, &cnt);
	if(cnt > 8)
	{
		os_taskq_post_msg(name,1,msg);
		fun_printf = 0;

	}
	else
	{
		u32 tmp;	
		fun_printf++;
		OS_TCB *self_task = os_get_task_tcb(OS_TASK_SELF);
		// printf("--half_second = %s	",name);
		// printf("msg = 0x%x\n",msg);
	}
}


 void timer0_isr_callback()
 {
     t0_cnt1++;
     t0_cnt2++;
     g_var.g_2ms_seed++;


     if((t0_cnt1 % 5) == 0)
     {
         OSTimeTick();
     }
 
    #ifdef SUPPORT_RGB_LED_MODE
        if((t0_cnt2 % 12) == 0)
    	 led_disp_eq();	   
    #endif
 
 
     if((t0_cnt2 % 5) == 0)
     {    
         sys_timer_schedule();
 
 	 #if RCSP_LIGHT_HW
 	         light_timer_10ms();
 	 #endif
 
     }
 	
  #ifdef KOK_DETECT_AUTO_VOL_SET	
#ifdef KOK_AUTO_VOL_TIMER  
	  if(t0_cnt2%25==0)
#else
	  if(t0_cnt2%55==0)
#endif
	 	vol_auto_inc();
 #endif
 
 
 #ifdef SUPPORT_ENCODER   
 if(t0_cnt2%2==0){
 	ENC_Encoder();
 	#ifdef SUPPORT_TWO_ENCODER
 	ENC_Encoder1();
 	#endif
 	}
 
 #ifdef SUPPORT_ENCODE_flash_led
     if((t0_cnt2 % 8) == 0)
 		ENC_Encoder_Led();
 #endif
 
 #endif
 #ifdef SUPPORT_AMP_MUTE_FS_CONTROL
 	if(t0_cnt2%20==0)
 	 amp_mute_state_det();
 #endif
 
 #ifdef SUPPORT_EQ_FREQUENCE_TIMER_SCAN
 	#ifdef LED_ID_YDL2001_VFN_35
	  	if(t0_cnt2%20==0)
	  		{
	 	  		LED_FREQUENCE_PROCESS();
	 			 #ifdef LED_EQ_BAR_SHOW
	 			 	LED_EQ_BAR_PROCESS(led7_var.bEqMode);
	 			 #endif	  			
	  		}

	#else
	  	if(t0_cnt2%1==0)
	  	LED_FREQUENCE_PROCESS();
	#endif

 #endif
 
     if(t0_cnt1 == 250)
     {
         t0_cnt1 = 0;
    //      puts("half..."); 
    
 //	printf("JL_TIMER0->PRD:%4x,JL_TIMER0->CON:%4x\n",JL_TIMER0->PRD,JL_TIMER0->CON);

 
#ifdef support_sw_chack
	ic_power_check_task();
#endif

 #if EARPHONE_MODE_EN
 		if(power_on_cnt)
 		{
 			power_on_cnt --;	
 			/* // printf("on cnt:%d\n",power_on_cnt); */
 		}
 #endif

#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
 	 if(bFmUmuteTimer)
 	 {
 	    bFmUmuteTimer--;
 	    if(bFmUmuteTimer==1)
 	    	{
 		    	 bFmUmuteTimer=0;
			SET_REXTERN_POWER_FM_MUTE_IO(0);
 	    	}
 	 }
#endif
 #ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
	 if(bFmMuteTimer)
	 	{
		 	bFmMuteTimer--;
			if(bFmMuteTimer==1)
				{
					 bFmMuteTimer=0;
			     		 SET_REXTERN_POWER_FM_MUTE_IO(1);
				 }
	 	}
 #endif

 
 #ifdef SUPPORT_MIC_ONOFF_SHOW
 	 if(bLedShowOnoffTimer)
 	 {
 	    bLedShowOnoffTimer--;
 	    if(bLedShowOnoffTimer==1)
 	    	{
 		    	 bLedShowOnoffTimer=0;
 			 UI_menu(MENU_REFRESH);
 	    	}
 	 }
 #endif 			
 
 #ifdef SUPPORT_POWER_ON_FREQUENCE_DELAY_SHOW
 	 if(bFrequencePowerOnDelayVal)
 	 {
 	    bFrequencePowerOnDelayVal--;
 	    if(bFrequencePowerOnDelayVal==1)
 	    	{
 		    	 bFrequencePowerOnDelayVal=0;
 	    	}
 	 }
 
 #endif
 
  
 #ifdef support_AMP_POWER_ON_SET
 	 if(bPowerOnAmpTimer)
 	 {
 	    bPowerOnAmpTimer--;
 	    if(bPowerOnAmpTimer==1)
 	    	{
 		    	 bPowerOnAmpTimer=0;
 	 		Set_AMP_POWER_ON_IS_LOW();
 	    	}
 	 }
 
 #endif
 
 #ifdef AMP_MUTE_ENABLE
 	 if(bPowerOnAmpMuteTimer)
 	 {
 	    bPowerOnAmpMuteTimer--;
 	    if(bPowerOnAmpMuteTimer==1)
 	    	{
 		    	 bPowerOnAmpMuteTimer=0;
 			AMP_MUTE_IO(0);
 	    	}
 	 }
 
 #endif
 
 	// printf("--------bLedShowOnoffTimer---------%d \n",bLedShowOnoffTimer);

 #ifdef SUPPORT_LOW_POWER_DELAY_DET
 
 	 if(bLowPowerDetDelay)
 	 {
 	    bLowPowerDetDelay--;
 	    if(bLowPowerDetDelay==1)
 	    	{
 		    	 bLowPowerDetDelay=0;
 	    	}
 	 }
 #endif


	#ifdef support_power_on_dly
		if(bPowerOnMuteTimer)			// jsuo
		{
		   bPowerOnMuteTimer--;
		   if(bPowerOnMuteTimer==1)
			   {
					bPowerOnMuteTimer=0;
					#ifdef PA_ENABLE
						pa_umute();
					#endif
	 				 #ifdef support_power_on_mute
	 				 	set_power_on_mute_io_low();
	 				 #endif
			   }
		}
#endif




 
 
 		
         g_var.sys_halfsec = !g_var.sys_halfsec;//led7 driver
 		halfsec_msg_sender(keymsg_task_name,MSG_HALF_SECOND);
     }
 
 #if RTC_CLK_CHECK_EN
     if(OSA_CON & BIT(7))
     {
         rest_rtc_osc();
         OSA_CON |= BIT(6);
     }
 #endif
 
     struct list_head *pos;
     __timer_handle  *timer;
     list_for_each(pos,&(timer0_hl->list))
     {
         timer = list_entry(pos,__timer_handle,list);
 
         if(++timer->cnt >= timer->time)
         {
             timer->cnt = 0;
             if(timer->handler)
             {
                 timer->handler(timer->param);
             }
         }
     }
 }



s32 timer0_init(void)
{
    s32 ret;
    __timer_param   timer_parm;
    timer_module_on();
    timer0_hl = timer_open(TIMER0,TIMER_MAX_ISR_FUN);
    if(NULL == timer0_hl)
    {
        // printf("timer_open err");
        ret = TIMER_DRV_OPEN_ERR;
        return ret;
    }
    timer_parm.work_mode  = TIMER_WORK_MODE_COUNTER;


    timer_parm.tick_time  = 2000;//(2ms)
	
    ret = timer_init_api(timer0_hl,&timer_parm);

    if(ret != TIMER_NO_ERR)
    {
        // printf("timer_init err = %x\n",ret);
        return ret;
    }

    ret = timer_start(timer0_hl);
    if(ret != TIMER_NO_ERR)
    {
        // printf("timer_start err = %x\n",ret);
        return ret;
    }
    ret = timer_reg_isr_callback_fun(timer0_hl,1,timer0_isr_callback);
    if(ret != TIMER_NO_ERR)
    {
        // printf("timer_reg_isr_callback_fun err = %x\n",ret);
        return ret;
    }
    return ret;
}

s32 timer0_clk_reset(void)
{
    s32 ret;
    __timer_param   timer_parm;
    puts("timer_clk_reset\n");

    timer_parm.work_mode  = TIMER_WORK_MODE_COUNTER;
	

    timer_parm.tick_time  = 2000;//(2ms)

    ret = timer_init_api(timer0_hl,&timer_parm);
    if(ret != TIMER_NO_ERR)
    {
        // printf("timer_init err = %x\n",ret);
        return ret;
    }

    ret = timer_start(timer0_hl);
    if(ret != TIMER_NO_ERR)
    {
        // printf("timer_start err = %x\n",ret);
        return ret;
    }

    puts("timer_init_OK\n");
    return ret;
}



//static struct clock_switch clock_switch_timer;

//CLOCK_SWITCH_USER_REGISTER(CLOCK_SWITCH_EXIT, &clock_switch_timer, timer0_clk_reset, "TIMER1");




#ifdef SUPPORT_TIME3_AS_RGB

///定时器0计数器，时间片轮换
__timer_handle  *timer3_hl;
u16 t3_cnt1;

 void timer3_isr_callback()
 {

 #if 0
 #if 1

static u8 flag = 0;
if(flag){ //自己使用示波器或逻辑分析仪测量频率
	// puts("PA11-1...");//\n
	JL_PORTA->DIR &= ~BIT(13);
	JL_PORTA->OUT |= BIT(13);
	flag = 0;
}else{
	// puts("PA11-0...");//\n
	JL_PORTA->DIR &= ~BIT(13);
	JL_PORTA->OUT &= ~BIT(13);
	flag = 1;
}
#endif

//	printf("JL_TIMER2->PRD:%4x,JL_TIMER2->CON:%4x\n",JL_TIMER2->PRD,JL_TIMER2->CON);

 #else
 
     t3_cnt1++;
 
    #ifdef SUPPORT_RGB_LED_MODE
        if((t3_cnt1 % 500) == 0)
    	 led_disp_eq();
 
 	 #ifdef SUPPORT_IO_ANGLOG_OUTPUT_PWM  // PA1
 	     red_pwm_scan();
 	 #endif
 	   
    #endif
	 

#endif

 }
s32 timer3_init(void)
{
    s32 ret;
    __timer_param   timer_parm;

    timer3_hl = timer_open(TIMER3,TIMER_MAX_ISR_FUN);
    if(NULL == timer3_hl)
    {
         printf("timer_open err");
        ret = TIMER_DRV_OPEN_ERR;
        return ret;
    }
	
    timer_parm.work_mode  = TIMER_WORK_MODE_COUNTER;

    timer_parm.tick_time  =   2000/200;//(2ms)
	
    ret = timer_init_api(timer3_hl,&timer_parm);

    if(ret != TIMER_NO_ERR)
    {
        printf("timer_init err = %x\n",ret);
        return ret;
    }

    ret = timer_start(timer3_hl);
    if(ret != TIMER_NO_ERR)
    {
         printf("timer_start err = %x\n",ret);
        return ret;
    }
    ret = timer_reg_isr_callback_fun(timer3_hl,5,timer3_isr_callback);
    if(ret != TIMER_NO_ERR)
    {
         printf("timer_reg_isr_callback_fun err = %x\n",ret);
        return ret;
    }
 //       printf("---------timer_init ok----------\n");



	JL_TIMER3->PRD = 0x7530/200;/// 30000/15M/40 == 2ms/40 == 50us
	JL_TIMER3->CON = 0x11;//60M/4 == 15M(4 分频)
//	printf("JL_TIMER2->PRD:%4x,JL_TIMER2->CON:%4x\n",JL_TIMER2->PRD,JL_TIMER2->CON);

    return ret;
}


s32 timer3_clk_reset(void)
{
    s32 ret;
    __timer_param   timer_parm;
    puts("timer_clk_reset\n");

    timer_parm.work_mode  = TIMER_WORK_MODE_COUNTER;
	

    timer_parm.tick_time  = 2000/4;//(2ms)

    ret = timer_init_api(timer3_hl,&timer_parm);
    if(ret != TIMER_NO_ERR)
    {
        // printf("timer_init err = %x\n",ret);
        return ret;
    }

    ret = timer_start(timer3_hl);
    if(ret != TIMER_NO_ERR)
    {
        // printf("timer_start err = %x\n",ret);
        return ret;
    }
	
	JL_TIMER3->PRD = 0x7530/4;/// 30000/15M/40 == 2ms/40 == 50us
	JL_TIMER3->CON = 0x11;//60M/4 == 15M(4 分频)
	printf("JL_TIMER2->PRD:%4x,JL_TIMER2->CON:%4x\n",JL_TIMER2->PRD,JL_TIMER2->CON);

    puts("timer_init_OK\n");
    return ret;
}


#endif


