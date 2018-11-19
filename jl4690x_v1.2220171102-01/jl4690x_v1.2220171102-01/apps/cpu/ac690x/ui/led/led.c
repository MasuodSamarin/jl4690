#include "ui/led/led.h"
#include "timer.h"
#include "rtc/rtc_api.h"
#include "music.h"
#include "file_operate/file_op.h"

extern tbool is_sniff_mode();
u32 g_led_fre = 0; ///<led fre
u8 g_led_flash = 0;///<b_led and r_led flash

extern volatile u8 low_power_flag;
#if defined SUPPORT_JH_POWER_SWITCH_IO
extern bool bStandbyModeFlag;
#endif


#ifdef SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ
u8 bBatModeValMsj; // 0 full 1half  2 low
bool bDcInValMsj;
bool bStandbyModeFlagMsj;
bool SwFlag;

#endif


/*----------------------------------------------------------------------------*/
/**@brief   LED初始化函数
   @param   void
   @return  void
   @note    void led_init(void)
*/
/*----------------------------------------------------------------------------*/
void led_init(void)
{
#if LED_EN
    LED_INIT_EN();
    //B_LED_ON();
    //R_LED_ON();
    s32 ret;

    ret = timer_reg_isr_fun(timer0_hl,5,led_scan,NULL);


    if(ret != TIMER_NO_ERR)
    {
        printf("led_scan err = %x\n",ret);
    }
#endif
#ifdef support_led_eq_disp
    timer_reg_isr_fun(timer0_hl,5,led_disp_eq,NULL);
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief   LED关闭函数
   @param   void
   @return  void
   @note    void led_close(void)
*/
/*----------------------------------------------------------------------------*/
void led_close(void)
{
    LED_INIT_DIS();
}

/*----------------------------------------------------------------------------*/
/**@brief   LED打开函数
   @param   void
   @return  void
   @note    void led_open(void)
*/
/*----------------------------------------------------------------------------*/
void led_open(void)
{
    LED_INIT_EN();
}

/*----------------------------------------------------------------------------*/
/**@brief   LED频率设置函数(50ms*fre = 实际闪烁频率)
   @param   fre:led闪烁频率 （注：当fre = 0时，表示led常亮）
            led_flash:表示B_led和R_led是否互闪
   @return  void
   @note    实际闪烁频率 = fre*5*scan_fre
            例如scan_fre = 10ms
                led_fre_set(10,0)
            则：
                led实际闪烁频率 = 10*5*10 = 500ms = 0.5s
*/
/*----------------------------------------------------------------------------*/
void led_fre_set(u32 fre,u8 led_flash)
{
    g_led_fre = fre*5;
    g_led_flash = led_flash;
}

/*----------------------------------------------------------------------------*/
/**@brief   led扫描函数
   @param   void
   @return  void
   @note    void led_scan(void *param)
*/
/*----------------------------------------------------------------------------*/
extern u8 is_pwrtimer_en();
#ifdef PP_LED_USER_ADKEY
extern bool g_ad_led_flag;
#endif

#ifdef support_ic_chack_dc_in
extern u8 bBatModeVal;
extern bool bDcInVal;
#endif

void led_scan(void *param)
{
#if LED_EN
    static u32 led_cnt;


#ifdef PP_LED_USER_ADKEY		
    if(g_ad_led_flag)
        return;		
#endif


#if EARPHONE_MODE_EN
		   if(going_to_pwr_off || low_power_flag)		   //关机或者低电的时候不扫描灯
			   return 1;
#endif

#ifndef SUPPORT_JH_BAT_DOUBLE_LED
    if(is_sniff_mode())/*sniff状态led在bt_configs_user.c中的对应接口扫描*/
        return;
    if(is_pwrtimer_en())
       return;
#endif


#ifdef SUPPORT_GW_BJ2003_BT_PROGRAME

		  if( workmode==BT_WORK_MODE)
		  	{
		       	    if(g_led_fre==0)  /*红蓝灯常亮*/
		       	    {
		       	        led_cnt = 0;
		       	        B_LED_ON();
		       	    }
		       	    else                  /*红蓝灯闪*/
		       	    {
		       	        led_cnt++;
		       	        if(led_cnt > g_led_fre)
		       	        {
		       	            if(led_cnt >= g_led_fre*2)
		       	                led_cnt = 0;
		       	            B_LED_ON();
		       	        }
		       	        else if(led_cnt > 0)
		       	        {
		       	            B_LED_OFF();
		       	        }
		       	    }
		  	}
		  else
		  	return;

#endif




#ifdef SUPPORT_REPEAT_ON_ALL_USE_LED

	repeat_one_all_led_io_out();
	if(workmode==MUSIC_WORK_MODE)
	{
		if(play_mode==REPEAT_ONE)
		{
			repeat_one_led_io_is_high();
			repeat_all_led_io_is_low();
		}
		else if(play_mode==REPEAT_ALL)
		{
			repeat_one_led_io_is_low();
			repeat_all_led_io_is_high();
		}
	}			 
	else 
	{
		repeat_one_led_io_is_low();
		repeat_all_led_io_is_low();
	}

#endif

#ifdef SUPPORT_JH_BAT_DOUBLE_LED
#ifdef support_ic_chack_dc_in
    static u16 cnt,cnt1;

	//  3s  R FLASH  ONCE  
    if((workmode==STANBY_WORK_MODE)&&(!bStandbyModeFlag)&&(!(bDcInVal)))
   	    {
   	        B_LED_OFF();		
		SET_R_LED(0);
		
		cnt++;
		if(cnt<450)		
			{
				SET_G_LED(0);
			}
		else if(cnt==450)
			{
				SET_G_LED(1);
			}

		if(cnt>=500)	
			cnt=0;	
		
		 return;
   	    }

	
	// 0 full 1half  2 low

	// 充电充满 蓝灯亮红灯灭
	if(((bDcInVal)&&(bBatModeVal==0))||((!bDcInVal)&&(bBatModeVal!=2)))
	{
		SET_R_LED(0);
		SET_G_LED(1);
	}
	else if(bDcInVal)  // 充电未充满绿灯灭红灯亮
	{
		SET_R_LED(1);
		SET_G_LED(0);
	}
	else if(bBatModeVal==2)
	{
		cnt1++;
		
		SET_G_LED(0);
		cnt++;
		if(cnt<25)		
			{
			SET_R_LED(0);
			}
		else if(cnt==25)
			{
			SET_R_LED(1);
			}

		if(cnt>=50)				
			cnt=0;			
	}


	    if( workmode==LINE_WORK_MODE)
   	    {
   	        led_cnt = 0;
   	        B_LED_OFF();		
		 return;
   	    }
			
#endif
#endif



#ifdef SUPPORT_SMJ_BAT_THREE_LED
#ifdef support_ic_chack_dc_in
    static u16 cnt,cnt1;

//bDcInValMsj   充电标志 1 充电 0  不充电
//bBatModeValMsj   电量模式  0 满电 1 半电 2 低电 3 低电关机
//bStandbyModeFlagMsj  低电关机标志
//bIcPowerDcDetFlag 上电低电检测
//




    if((workmode==STANBY_WORK_MODE)&&(!bStandbyModeFlagMsj)&&((bDcInValMsj=1)))
   	    {

		 SET_LOW_LED(0);
		 SET_NOL_LED(0);
		 B_LED_OFF();
		cnt++;
		if(cnt<200)		
			{
				SET_CHACK_LED(0);
			}
		else if(cnt==220)
			{
				SET_CHACK_LED(1);
			}

		if(cnt>=350)	
			cnt=0;	
		
		 return;
   	    }


	


//bDcInValMsj   充电标志 1 充电 0  不充电
//bBatModeValMsj   电量模式  0 满电 1 半电 2 低电 3 低电关机
//bStandbyModeFlagMsj  低电关机标志
//bIcPowerDcDetFlag 上电低电检测
//SwFlag     开机检查1 开机 0 关机




	if(((bDcInValMsj)&&(bBatModeValMsj!=3))||((bDcInValMsj)&&(bBatModeValMsj!=2)))  // 充电未充满
	{
		cnt1++;
		
		 SET_LOW_LED(0);
		 SET_NOL_LED(0);
		 cnt++;
		if(cnt<50)		
			{
		 		 SET_CHACK_LED(1);
			}
		else if(cnt==100)
			{
		 		 SET_CHACK_LED(0);
		 	}

		if(cnt>=150)				
			cnt=0;	
	}
	else if((bDcInValMsj)&&(bBatModeValMsj==0))//  满电
	{
		 SET_LOW_LED(0);
		 SET_NOL_LED(0);
		 SET_CHACK_LED(1);
	}
	
	else if(((!bDcInValMsj)&&(bBatModeValMsj==0))||((!bDcInValMsj)&&(bBatModeValMsj==1)))   //   电量正常
	{
		 SET_LOW_LED(0);
		 SET_NOL_LED(1);
		 SET_CHACK_LED(0);
	}
	
	else if((!bDcInValMsj)&&(bBatModeValMsj==2))    //低电闪
	{
		cnt1++;
		
		 SET_NOL_LED(0);
		 SET_CHACK_LED(0);
		 cnt++;
		if(cnt<25)		
			{
		 		 SET_LOW_LED(1);
			}
		else if(cnt==25)
			{
		 		 SET_LOW_LED(0);
		 	}

		if(cnt>=50)				
			cnt=0;			
	}

#if 0

	
	else if((bDcInValMsj=1)&&(bBatModeValMsj==2))    //低电充电
		{
	 		cnt1++;
	 		
	 		 SET_NOL_LED(0);

	 		 cnt++;
	 		if(cnt<25)		
	 			{
	 		 		 SET_LOW_LED(1);
					 SET_CHACK_LED(1);
	 			}
	 		else if(cnt==25)
	 			{
	 		 		 SET_LOW_LED(0);
	 		 		SET_CHACK_LED(0);
	 		 	}
	 
	 		if(cnt>=50)				
	 			cnt=0;				
		}

#endif
			
#endif
#endif





       #if defined SUPPORT_GW_SLH_DOUBLE_LED ||defined SUPPORT_DOUBLE_LED
	   
	    if( workmode==STANBY_WORK_MODE)
	   	    {
	   	        led_cnt = 0;
	   	        B_LED_OFF();
	   	        R_LED_OFF();
			 return;
	   	    }
		
		  if( workmode==BT_WORK_MODE)
		  	{
	       	            B_LED_OFF();		  	
		       	    if(g_led_fre==0)  /*红蓝灯常亮*/
		       	    {
		       	        led_cnt = 0;
		       	        R_LED_ON();
		       	    }
		       	    else                  /*红蓝灯闪*/
		       	    {
		       	        led_cnt++;
		       	        if(led_cnt > g_led_fre)
		       	        {
		       	            if(led_cnt >= g_led_fre*2)
		       	                led_cnt = 0;
		       	            R_LED_ON();
		       	        }
		       	        else if(led_cnt > 0)
		       	        {
		       	            R_LED_OFF();
		       	        }
		       	    }
		  	}
		  else
		  	{
		       	           R_LED_OFF();
		  	
		       	    if(g_led_fre==0)  /*红蓝灯常亮*/
		       	    {
		       	        led_cnt = 0;
		       	        B_LED_ON();
		       	    }
		       	    else                  /*红蓝灯闪*/
		       	    {
		       	        led_cnt++;
		       	        if(led_cnt > g_led_fre)
		       	        {
		       	            if(led_cnt >= g_led_fre*2)
		       	                led_cnt = 0;
		       	            B_LED_ON();
		       	        }
		       	        else if(led_cnt > 0)
		       	        {
		       	            B_LED_OFF();
		       	        }
		       	    }
		  	}
		  	  

	  
       #else ////单灯

	    if( workmode==STANBY_WORK_MODE)
	   	    {
		//        printf("led_scan B_LED_OFF\n");
	   	    
	   	        led_cnt = 0;
	   	        B_LED_OFF();
			return;
	   	    }
	
       	    if(g_led_fre==0)  /*红蓝灯常亮*/
       	    {
       	        led_cnt = 0;
       	        B_LED_ON();
       	    }
       	    else                  /*红蓝灯闪*/
       	    {
       	        led_cnt++;
       	        if(led_cnt > g_led_fre)
       	        {
       	            if(led_cnt >= g_led_fre*2)
       	                led_cnt = 0;
       	            B_LED_ON();
       	        }
       	        else if(led_cnt > 0)
       	        {
       	            B_LED_OFF();
       	        }
       	    }
			
       #endif
#endif
}




#ifdef support_led_eq_disp
#ifdef  support_led_eq_is_5led_user_k7036
   #include "led_eq_is_5led_user_k7036.c"
#elif defined(support_led_eq_is_K1_mode)
   #include "support_led_eq_is_K1_mode.c"
#else
#error(" 请设置eq_ led.c")
#endif
#endif
