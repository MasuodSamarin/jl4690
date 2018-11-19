#include "sdk_cfg.h"
#include "sys_detect.h"
#include "key_drv/key_drv_ad.h"
#include "rtos/task_manage.h"
#include "file_operate/file_op.h"
#include "key_drv/key.h"
#include "ui/led/led.h"
#include "dac/dac.h"
#include "key_drv/key_voice.h"
#include "linein/dev_linein.h"
#include "rtc/rtc.h"
#include "uart.h"
#include "vm/vm_api.h"
#ifdef SUPPORT_LOW_POWER_DELAY_DET
extern u8 bLowPowerDetDelay;
#endif
#ifdef SUPPORT_BAT_DETECT
#ifdef AMP_MUTE_ENABLE
extern  u8 bPowerOnAmpMuteTimer;
#endif
#endif
#if defined SUPPORT_JH_POWER_SWITCH_IO
bool bStandbyModeFlag; // 0-power on   1-standby 
#endif
#if defined SUPPORT_POWER_ON_IN_IDLE_MODE
bool  bPowerOnIdleFlag;
#endif
#ifdef SUPPORT_LED_LOW_SHOW_LDO
u8 bLowPowerShowFlag;					 
#endif


#ifdef SUPPORT_LOW_POWER_STANBY
bool bLowPowerFlag;
#endif


u8 soft_poweroff_cnt = 0;
u8 going_to_pwr_off = 0;
u8 going_to_pwr_off;
u8 bd_work_mode;
extern void soft_poweroff();
/*----------------------------------------------------------------------------*/
/**@brief
   @param  void
   @return void
   @note   void sys_init(void)
*/
/*----------------------------------------------------------------------------*/
void sys_init(void)
{

#if RTC_CLK_EN
    irtc_hw_init();
#endif // RTC_CLK_EN
#if UART_UPDATA_EN
    uart_update_init();
#endif
    usb_2_io();

    key_init();
    //led_init();
#if  AUX_DETECT_EN
    aux_init_api(); //AUX init
#endif
#ifdef PHONE_CHECK_ENABLE
    phone_init_api();
#endif
#if MIC_CHECK_ENABLE
    mic_init_api();
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief  软开关控制
   @param  ctl :power_on or power_off
   @return null
   @note   void soft_power_ctl(u8 ctl)
*/
/*----------------------------------------------------------------------------*/
void soft_power_ctl(u8 ctl)
{
#if 0   //soft power ctl by mos transistor
    if(PWR_ON == ctl)
    {
        led_init();
        JL_PORTA->DIR &= ~BIT(14);
        JL_PORTA->OUT |= BIT(14);
    }
    else
    {
        LVD_CON &= ~BIT(2);
        //LED_INIT_DIS();
        JL_PORTA->DIR &= ~BIT(14);
        JL_PORTA->OUT &= ~BIT(14);
    }
#else   //soft power ctl by power off

    if(PWR_ON == ctl)
    {

    }
    else
    {
        printf("soft off\n");
        soft_poweroff();
    }

#endif
}
/*----------------------------------------------------------------------------*/
/**@brief   power off 检测延时关机
   @param   null
   @return  null
   @note    void check_power_off(void)
*/
/*----------------------------------------------------------------------------*/
void check_power_off(void)
{
    if(soft_poweroff_cnt)
    {
        if(--soft_poweroff_cnt == 0)
        {
            soft_power_ctl(PWR_OFF);
        }
    }
}
/*----------------------------------------------------------------------------*/
/**@brief   关闭IO长按复位功能
   @param   null
   @return  null
   @note    void clr_PINR_ctl(void)
*/
/*----------------------------------------------------------------------------*/
void clr_PINR_ctl(void)
{
    rtc_module_port_4s_reset(PORTR2, 0, 0 );
}

//static u32 start_charge_cnt = 0;
void charge_detect(void)
{
#if CHARGE_POWER_OFF
	JL_PORTA->DIR |= BIT(3);
	JL_PORTA->PU  &= ~BIT(3);
	JL_PORTA->PD  |= BIT(3);

	if(JL_PORTA->IN & BIT(3))
	{
		start_charge_cnt ++;
		if(start_charge_cnt > 50)
		{
			going_to_pwr_off = 1;
			os_taskq_post("MainTask", 2, MSG_POWER_OFF_KEY_MSG ,0x44);
		}
	}
	else
	{
		start_charge_cnt = 0;
	}
#endif
}
/*----------------------------------------------------------------------------*/
/**@brief  实时电量检测
   @param  void
   @return void
   @note   void battery_check(void *)
*/
/*----------------------------------------------------------------------------*/
#if SYS_LVD_EN

u8 charge_full_flag = 0;             //充满电标志
#define CHARGE_PROTECT_VOLTAGE 42    //保护电压
static u32 charge_full_cnt = 0;
static u32 repeat_charge_cnt = 0;
extern void set_pwrmd(u8 mode);
extern u32 get_fast_charge_sta(void);
u8 send_msg_flag = 0;
static u8 send_msg_cnt = 0;


#define POWER_CHECK_CNT   100 //POWER_CHECK_CNT*10ms
u16 unit_cnt = 0;             //计数单位时间POWER_CHECK_CNT*10ms
u16 low_warn_cnt = 0;         //单位时间内监测到报警电压次数
u16 low_off_cnt = 0;          //单位时间内监测到关机电压次数
static u8 charge_cnt = 0;     //充电检测计数
extern u8 is_pwrtimer_en();

static u8 low_voice_cnt = 0;
volatile u8 low_power_flag = 0;
#if defined(SUPPORT_FS_BAT_DET_MODE)
extern u8 bBatMode;
#endif
#if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5
bool bLowePoweStanbyFlag;
#endif

#ifdef support_ic_chack_dc_in
u8 bBatModeVal; // 0 full 1half  2 low
bool bDcInVal;
#endif

#ifdef SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ
u8 bBatModeValMsj; // 0 full 1half  2 low
extern bool bDcInValMsj;
extern bool bStandbyModeFlagMsj;
extern bool SwFlag;

#endif






#ifdef support_battery_mode_check

#ifdef support_gw_kf3223_1   // 1.8 H   1.8--1.6 L 1.6 L 闪
 u8  ldo_power_mod;  
#define BAT_ADC_FULL              18
#define  BAT_ADC_HIGH            18
#define BAT_ADC_HALF              18
#define BAT_ADC_LOW               16
#define BAT_ADC_LOW_OFF       0

#elif defined support_sd_4018_3bat||defined support_led7_JW4018D7
 u8  ldo_power_mod;  
#define BAT_ADC_FULL              23
#define  BAT_ADC_HIGH             20
#define BAT_ADC_HALF              18
#define BAT_ADC_LOW               16
#define BAT_ADC_LOW1               12
#define BAT_ADC_LOW_OFF       10
#elif defined LED_ID_JW_18407_2
 u8  ldo_power_mod;  

#if 1
#define BAT_ADC_FULL              275
#define  BAT_ADC_HIGH             255
#define BAT_ADC_HALF              235
#define BAT_ADC_LOW               200
#define BAT_ADC_LOW1               120
#define BAT_ADC_LOW_OFF       100
#else
#define BAT_ADC_FULL              230
#define  BAT_ADC_HIGH             200
#define BAT_ADC_HALF              180
#define BAT_ADC_LOW               160
#define BAT_ADC_LOW1               120
#define BAT_ADC_LOW_OFF       100
#endif
#else
 u8  ldo_power_mod;  
#define BAT_ADC_FULL              41
#define  BAT_ADC_HIGH            39
#define BAT_ADC_HALF              37
#define BAT_ADC_LOW               33
#define BAT_ADC_LOW_OFF       30
#endif
 #endif 







void battery_check(void *prt)
{
    u16 val;
    u8 cnt;

#ifdef SUPPORT_LOW_POWER_DELAY_DET
	if(bLowPowerDetDelay>0)
	return;
#endif

#ifdef SUPPORT_BAT_DETECT
#ifdef AMP_MUTE_ENABLE
	if(bPowerOnAmpMuteTimer>0)
	return;
#endif
#endif


#ifdef support_battery_mode_check
    static u8 ldo_power_count, current_ldo_voltage,old_ldo_voltage;
#endif 




#ifdef SUPPORT_BAT_DETECT
#ifndef SUPPORT_JH_POWER_SWITCH_IO
#ifdef AMP_MUTE_ENABLE
  if((workmode ==STANBY_WORK_MODE )||(workmode ==MAIN_WORK_MODE )||(bPowerOnAmpMuteTimer>0))
	return;
#else
  if((workmode ==STANBY_WORK_MODE )||(workmode ==MAIN_WORK_MODE ))
	return;
#endif
#endif
#endif

	charge_detect();

#ifdef SUPPORT_BAT_DET_USE_EXTERN_AD_COMPARION
   u16 ad_comparion_value=adc_value[AD_CH_AD_COMPARION];//1023;//led7_var.wAdc_value;
   u16 bat_value_temp=adc_value[AD_CH_BAT];//1023;//led7_var.wAdc_value;


   val=bat_value_temp;

#else
    val = get_battery_level();
#endif
    unit_cnt++;




#ifdef  SUPPORT_BAT_DETECT_LOW_POWER_MODE_1

// 小于固定电压led显示bat  10秒后关机 设置关机IO

    if(val < LOW_POER_VOLTOGE_VAL)
        low_warn_cnt++;

    if(unit_cnt >= POWER_CHECK_CNT) // 1s
    {
        //printf("val:%d,low_off_cnt:%d,low_warn_cnt:%d\n",val,low_off_cnt,low_warn_cnt);

		cnt = 10;

        if(low_warn_cnt > POWER_CHECK_CNT/2)//低电关机0.5s
        {
            puts("\n*******Low Power********\n");
	     low_power_flag = 1;

		  if(low_off_cnt<10)
			 low_off_cnt++;
		else  if(low_off_cnt==10) // 10s
		 	{
//				dac_mute(1,1);
				 #ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
				 	LOW_POWER_OFF_USE_EXTERN_IO(0);
				 #endif

		 		low_off_cnt=11;
		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
		 	}
        }
	else
  	{
  		low_power_flag = 0;
  	}


        unit_cnt = 0;
//        low_off_cnt = 0;
        low_warn_cnt = 0;
    }

#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_2

/*
	2、当检测电压低于1.90V时。
	POWER(26)脚输出低电平
	MUTE(25)脚输出高电平
	LED屏闪动5秒后
	LOW-V(41)脚输出低电平。
*/

    if(val < LOW_POER_VOLTOGE_VAL)
        low_warn_cnt++;

    if(unit_cnt >= POWER_CHECK_CNT) // 1s
    {
        //printf("val:%d,low_off_cnt:%d,low_warn_cnt:%d\n",val,low_off_cnt,low_warn_cnt);

		cnt = 10;

        if(low_warn_cnt > POWER_CHECK_CNT/2)//低电关机0.5s
        {
            puts("\n*******Low Power********\n");
	     low_power_flag = 1;


		 if(low_off_cnt<10)
		 	{
				 low_off_cnt++;
				 if(low_off_cnt==1)
				 {
					#ifdef AMP_POWER_ENABLE
					AMP_POWER_IO(0);
					#endif
					AMP_MUTE_IO(1);
				 }
		 	}
		else  if(low_off_cnt==10) // 5 S
		 	{
//				dac_mute(1,1);
				 #ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
				 	LOW_POWER_OFF_USE_EXTERN_IO(0);
				 #endif

		 		low_off_cnt=6;
		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
		 	}
        }
	else
  	{
  		low_power_flag = 0;
  	}


        unit_cnt = 0;
//        low_off_cnt = 0;
        low_warn_cnt = 0;
    }
#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_8

/*
	2、当检测电压低于1.90V时。
	POWER(26)脚输出低电平
	MUTE(25)脚输出高电平
	显示-bLO 5秒后	关机
	LOW-V(41)脚输出低电平。
*/

    if(val < LOW_POER_VOLTOGE_VAL)
        low_warn_cnt++;

    if(unit_cnt >= POWER_CHECK_CNT) // 1s
    {
        //printf("val:%d,low_off_cnt:%d,low_warn_cnt:%d\n",val,low_off_cnt,low_warn_cnt);

		cnt = 10;

        if(low_warn_cnt > POWER_CHECK_CNT/2)//低电关机0.5s
        {
            puts("\n*******Low Power********\n");
	     low_power_flag = 1;


		 if(low_off_cnt<10)
		 	{
				 low_off_cnt++;
				 if(low_off_cnt==1)
				 {
					#ifdef AMP_POWER_ENABLE
					AMP_POWER_IO(0);
					#endif
					AMP_MUTE_IO(1);
					 #ifdef SUPPORT_LED_LOW_SHOW_LDO
						 bLowPowerShowFlag=1;
					 #endif
				 }
		 	}
		else  if(low_off_cnt==10) // 5 S
		 	{
//				dac_mute(1,1);
				 #ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
				 	LOW_POWER_OFF_USE_EXTERN_IO(0);
				 #endif
					 #ifdef SUPPORT_LED_LOW_SHOW_LDO
						 bLowPowerShowFlag=0;
					 #endif
		 		low_off_cnt=6;
		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
		 	}
        }
	else
  	{
					 #ifdef SUPPORT_LED_LOW_SHOW_LDO
						 bLowPowerShowFlag=0;
					 #endif
  	
  		low_power_flag = 0;
  	}


        unit_cnt = 0;
//        low_off_cnt = 0;
        low_warn_cnt = 0;
    }

#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_3
// 2.26V少四格（说电池电量不足2M报一次）
// 10ms

	if(bBatMode==4)
	{

		low_off_cnt++;
		if(low_off_cnt==12000)  // 12000-2min
			low_off_cnt=0;

		if(low_off_cnt==15)
			{
				low_power_flag = 1;
				os_taskq_post_msg(keymsg_task_name, 1, MSG_LOW_POWER);
			}
		else
			low_power_flag = 0;


	}
	else
	{
		low_power_flag = 0;
		low_off_cnt=0;
	}

#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_4



// 小于固定电压led显示bat  10秒后待机

    if(val < LOW_POER_VOLTOGE_VAL)
        low_warn_cnt++;

    if(unit_cnt >= POWER_CHECK_CNT) // 1s
    {
        //printf("val:%d,low_off_cnt:%d,low_warn_cnt:%d\n",val,low_off_cnt,low_warn_cnt);

		cnt = 10;

        if(low_warn_cnt > POWER_CHECK_CNT/2)//低电关机0.5s
        {
            puts("\n*******Low Power********\n");
	     low_power_flag = 1;

		  if(low_off_cnt<10)
			 low_off_cnt++;
		else  if(low_off_cnt==10) // 10s
		 	{
//				dac_mute(1,1);
		 		low_off_cnt=11;
		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
		 	}
        }
	else
  	{
  		low_power_flag = 0;
  	}


        unit_cnt = 0;
//        low_off_cnt = 0;
        low_warn_cnt = 0;
    }

#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_6

// 小于固定电压led显示bat  提示报低电语音 低电 1分钟后待机

    if(val < LOW_POER_VOLTOGE_VAL)
        low_warn_cnt++;
 #if KEY_TONE_EN && SUPPORT_LOW_POWER_TONE
	 else
		low_off_cnt=0;
#endif
    if(unit_cnt >= POWER_CHECK_CNT) // 1s
    {
        //printf("val:%d,low_off_cnt:%d,low_warn_cnt:%d\n",val,low_off_cnt,low_warn_cnt);

		cnt = 10;

        if(low_warn_cnt > POWER_CHECK_CNT/2)//低电关机0.5s
        {
            puts("\n*******Low Power********\n");
	     low_power_flag = 1;

		  if(low_off_cnt<60)
		  	{
		  	
			 	low_off_cnt++;
				
//				if((low_off_cnt%11==0)||(low_off_cnt==1))

					
		 		 #if KEY_TONE_EN && SUPPORT_LOW_POWER_TONE
					if((low_off_cnt>=50))		
						{
						   low_off_cnt=50;
		 		             	   send_key_voice(800);
						}
		 		 #else
					if((low_off_cnt%15==0))
		 				os_taskq_post_msg(keymsg_task_name, 1, MSG_LOW_POWER);		 
		 		 #endif											
		  	}
#if 1		  
		else  if(low_off_cnt==60) // 10s
		 	{
//				dac_mute(1,1);
		 		low_off_cnt=0;
//		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
		 	}
#else
		else  if(low_off_cnt==60) // 10s
		 	{
//				dac_mute(1,1);
		 		low_off_cnt=61;
		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
		 	}
#endif		
        }
	else
  	{
 		low_power_flag = 0;
  	}


        unit_cnt = 0;
//        low_off_cnt = 0;
        low_warn_cnt = 0;
    }

	
#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5

 // 低于2.82V少一格，2.68V少二格，2.56V少三格，
 // 2.38V少四格（亮电池框说电池电量不足） 2.2V待机电池框闪

// 10ms
static u8 bLowpowerStandbyCnt;


	if(bBatMode==4)
	{
		bLowpowerStandbyCnt=0;
		low_off_cnt++;
		if(low_off_cnt==12000)  // 12000-2min
			low_off_cnt=0;
#ifdef SUPPORT_LOW_POWER_AMP_MUTE_IS_HIGH
		if(low_off_cnt==800)  // 12000-2min
		{
	        	set_mute_io_high();
		}
#endif
		if(low_off_cnt==15)
			{
			 #ifdef SUPPORT_LOW_POWER_AMP_MUTE_IS_HIGH
 			        set_mute_io_low();
			 #endif
			 #ifdef SUPPORT_LOW_POWER_VOICE
				os_taskq_post_msg(keymsg_task_name, 1, MSG_LOW_POWER);
			 #endif
				low_power_flag = 1;
			}
	 		else
	 			low_power_flag = 0;
	}
	else if(bBatMode==5)
	{
		if(bLowpowerStandbyCnt<100)
			bLowpowerStandbyCnt++;

		if(bLowpowerStandbyCnt==100)
			{
				 bLowpowerStandbyCnt=101;
				 bLowePoweStanbyFlag=1;
		          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
			}
	}
	else
	{
		bLowpowerStandbyCnt=0;
		low_power_flag = 0;
		low_off_cnt=0;
	}

#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ

//低电红灯快闪   低电待机

// 小于固定电压led显示bat  提示报低电语音 低电 1分钟后待机

//   u16 bat_value;

#define BAT_13 1023*13/33
#define BAT_15 1023*15/33
#define BAT_18 1023*18/33
#define BAT_20 1023*20/33


   u16 bat_value=adc_value[AD_CH_BAT];//1023;//led7_var.wAdc_value;



#ifdef support_ic_chack_dc_in

	MSJ_DC_DET_IO_IS_IN();
	if(MSJ_DC_DET_READ())
	{
		bDcInValMsj=1;		
	}
	else
		bDcInValMsj=0;
	
#endif
SW_IO_IS_IN();
	if(SW_IN_CHECK())
		{
			SwFlag=1;
		}
	else
		{
			SwFlag=0;
		}



	static u8 bCnt=0,bBatTemp1=0,bBatTemp2=0,bBatTemp3=0,bBatTemp4=0;

	if(unit_cnt>20) // 200ms
		{
			unit_cnt=0;
			bCnt++;
			
		//		printf("---bat---val---------%d\n",val);

		      if(val> 20)
			        bBatTemp1++;
			else if(val > 18)
				bBatTemp2++;
			else if(val > 15)
				bBatTemp3++;
			else //if(val > 15)
				bBatTemp4++;			
			if(bCnt==20)	  //	4000ms		
			    {
			        if(bBatTemp1)
			        {
					 bBatModeValMsj=0;
			       }
				else if(bBatTemp2)
				{
			 		bBatModeValMsj=1;
				}
				else if(bBatTemp3)
				{
			 		bBatModeValMsj=2;
			        }
				else if(bBatTemp4)
				{
			 		bBatModeValMsj=3;
			        }				
			        bCnt = 0;
			        bBatTemp1 = 0;
			        bBatTemp2 = 0;
			        bBatTemp3 = 0;
					
					
				  
				  	  SW_IO_IS_IN();
				  	 
				  	 if((!SW_IN_CHECK())&&(!bStandbyModeFlagMsj))
				  	 {
						bStandbyModeFlagMsj=1;
				          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);						
					 }
					 
					printf("------bBatModeValMsj---------%d\n",bBatModeValMsj);
					printf("------bStandbyModeFlagMsj---------%d\n",bStandbyModeFlagMsj);
					 



			    }



		}
#elif defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_7

//低电红灯快闪   低电待机

// 小于固定电压led显示bat  提示报低电语音 低电 1分钟后待机

#ifdef support_ic_chack_dc_in

	DC_DET_IO_IS_IN();
	if(DC_DET_READ())
	{
		bDcInVal=1;		
	}
	else
		bDcInVal=0;
	
#endif

	static u8 bCnt=0,bBatTemp1=0,bBatTemp2=0,bBatTemp3=0;

	if(unit_cnt>20) // 200ms
		{
			unit_cnt=0;
			bCnt++;
			
		//		printf("---bat---val---------%d\n",val);

			
		      if(val > 25)
			        bBatTemp1++;
			else if(val > 20)
				bBatTemp2++;
			else //if(val > BAT_21)
				bBatTemp3++;
			
			if(bCnt==20)	  //	4000ms		
			    {
			        if(bBatTemp1)
			        {
					 bBatModeVal=0;
			       }
				else if(bBatTemp2)
				{
			 		bBatModeVal=1;
				}
				else if(bBatTemp3)
				{
			 		bBatModeVal=2;
#if 0				
				       low_power_flag = 1;

					  if(low_off_cnt<60)
					  	{					  	
						 	low_off_cnt++;																					
					  	}
					else  if(low_off_cnt==60) // 10s
					 	{
					 		bBatModeVal=2;
					 		low_off_cnt=0;
					          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);
					 	}
#endif				
			        }
				
			        bCnt = 0;
			        bBatTemp1 = 0;
			        bBatTemp2 = 0;
			        bBatTemp3 = 0;
					
					
				  #if defined SUPPORT_JH_POWER_SWITCH_IO
				  
				  	  SET_POWER_SWITCH_IN();
				  	 
				  	 if((!POWER_SWITCH_CHECK())&&(!bStandbyModeFlag))
				  	 {
						bStandbyModeFlag=1;
				          	 os_taskq_post_msg("MainTask", 1, MSG_STANBY_KEY);						
					 }
					 
					printf("------bBatModeVal---------%d\n",bBatModeVal);
					printf("------bStandbyModeFlag---------%d\n",bStandbyModeFlag);
					 
				  #endif



			    }



		}
	
#elif defined(SUPPORT_LOW_POWER_STANBY)


    if(val < LOW_POER_VOLTOGE_VAL)
        low_warn_cnt++;

    if(unit_cnt >= POWER_CHECK_CNT) // 1s
    {

		cnt = 10;

	         if(low_warn_cnt > POWER_CHECK_CNT/2)//低电关机0.5s
	         {
	 	     low_power_flag = 1;
	 
	 		  if(low_off_cnt<10)
	 			 low_off_cnt++;
	 		else  if(low_off_cnt==10)
	 		 	{
	 				 #ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
	 				 	LOW_POWER_OFF_USE_EXTERN_IO(0);
	 				 #endif
	 
	 		 		low_off_cnt=11;
	 	 			DC_DET_IO_IS_IN();
	 	 		  	if((!DC_DET_READ())&&(!bLowPowerFlag))
	 	 		  	{
	 	 				 bLowPowerFlag = 1;
	 	 				os_taskq_post_msg("MainTask",1,MSG_STANBY_KEY);
	 	 		  	}
	 			}
	         }
	 	else
	   	{
	   		low_power_flag = 0;
	   	}
	 
	 
	         unit_cnt = 0;
	         low_warn_cnt = 0;

  	}

#ifdef support_battery_mode_check



/* LOD 电压状态 */

    old_ldo_voltage=current_ldo_voltage;

#if 0//def  support_ic_chack_dc_in
		DC_DET_IO_IS_IN();
		if( DC_DET_READ())
 		{
		    if(val > 269)  //    4.1V   2.75
		     {
		       current_ldo_voltage=1;	    //满
		     }
		     else
		     {
		       current_ldo_voltage=2;     //  高
		     }		 
	 }
		
	else
#endif
	 {
	    if(val > BAT_ADC_FULL)  //    4.1V  
	     {
	       current_ldo_voltage=1;	    //满
	     }
	     else if(val > BAT_ADC_HIGH)   // 3.9v  
	     {
	       current_ldo_voltage=2;     //  高
	     }
	     else if(val > BAT_ADC_HALF)   // 3.7V   
	     {
	       current_ldo_voltage=3;    //半
	     }
	     else if(val > BAT_ADC_LOW)   //    //3.3V   
	     {
	       current_ldo_voltage=4;   //低
	     }
	     else if(val > BAT_ADC_LOW1)   //    //3.3V   
	     {
	       current_ldo_voltage=5;   //低
	     }	
	     else if(val > BAT_ADC_LOW_OFF)    //  3V   
	     {
	       current_ldo_voltage=6;   //低低
	     }
	     else
	      current_ldo_voltage=7;    //低关机
	 
	 }

    if( current_ldo_voltage==old_ldo_voltage)	 	
             ldo_power_count++;
	 else 
	 	ldo_power_count=0;
	 
        if(ldo_power_count>50)
        {
            ldo_power_mod = old_ldo_voltage;
		ldo_power_count=55;  //避免++溢出	
		
        }

#endif 

	
#else

    if(val < 31)
        low_off_cnt++;
    if(val < 33)
        low_warn_cnt++;

    if(unit_cnt >= POWER_CHECK_CNT) // 1s
    {
        //printf("val:%d,low_off_cnt:%d,low_warn_cnt:%d\n",val,low_off_cnt,low_warn_cnt);
		if(is_sniff_mode())
			cnt = 4;
		else if(is_pwrtimer_en())
			cnt = 4;
		else
			cnt = 10;


        if(low_off_cnt > POWER_CHECK_CNT/2)//低电关机
        {
            puts("\n*******Low Power********\n");
	     low_power_flag = 1;
            os_taskq_post(MAIN_TASK_NAME,1,MSG_LOW_POWER);
        }
        else if(low_warn_cnt > POWER_CHECK_CNT/2)//低电提醒
			{
				low_power_flag = 1;
			//	if(!going_to_pwr_off)
			//	{
			//	RGB_R_LED_ON();
			//	RGB_B_LED_OFF();
			//	}

                             #ifdef support_low_power_voice
	                             low_voice_cnt ++;
	                             if(low_voice_cnt > cnt)
	                             {
	                             /* puts("\n**Low Power,Please Charge Soon!!!**\n"); */
	                             low_voice_cnt = 0;
	                             os_taskq_post(MAIN_TASK_NAME,1,MSG_LOW_POWER_VOICE);
	                             }

                             #elif support_low_power_key_voice
	                             puts("\n**Low Power,Please Charge Soon!!!**\n");
	                             going_to_pwr_off = 1;
	                             send_key_voice(500);
                             #else

                             #endif


			}
		else
		{
		//	if(low_power_flag)
			//{
			//	RGB_R_LED_OFF();
				//RGB_B_LED_OFF();
			//}
			low_power_flag = 0;
		}





        unit_cnt = 0;
        low_off_cnt = 0;
        low_warn_cnt = 0;
    }
#endif

}
#endif

/*----------------------------------------------------------------------------*/
/**@brief  恢复USB口为普通IO口
   @param  USB_IO_CON
   BIT(15)-BIT(8):  --   --   --   --  DMIN DPIN  --    --
   BIT(7) -BIT(0): DMPU DPPU DMPD DPPD DMIE DPIE DMOUT DPOUT
   @return void
   @note   void usb_2_io(void)

*/
/*----------------------------------------------------------------------------*/
void usb_2_io(void)
{
//    sys_det_puts("USB_2_IO\n");
    JL_USB->CON0 |= BIT(0)|BIT(1);//PHY_ON(enable)  IO_MODE(enable)
    JL_USB->IO_CON = (BIT(3)|BIT(2));//IO输入
}

/*----------------------------------------------------------------------------*/
/**@brief   watch dog timer config
   @param   void
   @return  void
   @note
 */
/*----------------------------------------------------------------------------*/
/*
cfg:1010:1s  1011:2s    1100:4s
    1101:8s  1110:16s   1111:32s
*/
void open_wdt(u8 cfg)//开看门狗
{
    CPU_SR_ALLOC();
    OS_ENTER_CRITICAL();
    //puts("open_wdt\n");
    JL_CRC->REG  = 0X6EA5;
    JL_SYSTEM->WDT_CON  = cfg&0x0f;
    JL_SYSTEM->WDT_CON &= ~BIT(5);
    JL_SYSTEM->WDT_CON |=  BIT(4);
    JL_CRC->REG  = 0XAAAA;
    OS_EXIT_CRITICAL();
}

void close_wdt(void)//关看门狗
{
    CPU_SR_ALLOC();
    OS_ENTER_CRITICAL();
    //puts("close_wdt\");
    JL_CRC->REG = 0x6EA5;
    JL_SYSTEM->WDT_CON &= ~BIT(4);
    JL_CRC->REG = 0;
    OS_EXIT_CRITICAL();
}

void clear_wdt(void)//清看门狗
{
    //puts(" clr_wdt ");
    JL_SYSTEM->WDT_CON |= BIT(6);
}

/*----------------------------------------------------------------------------*/
/**@brief  	sd data multiplex
   @param   void
   @return  void
   @note
 */
/*----------------------------------------------------------------------------*/
#if SD_DADA_MULT
u16 adc_value_PA1;
u8 g_aux_online_flag;
extern u32 get_sd0_dev_busy_status_api(void);
extern void close_sd0_controller(void);
extern void release_sd0_controller(void);
void sd_data_multiplex(void)
{
    u16 res = 0;
    static u8 dev_online_cnt,dev_offline_cnt,adc_timeout_cnt,adc_err_cnt;

    //if(task_start_complete == 0)
    //return;

    if(!get_sd0_dev_busy_status_api())
    {
        adc_busy_flag = 1;

        //CPU_SR_ALLOC();
        //OS_ENTER_CRITICAL();

        //关闭 sd controller
        close_sd0_controller();

        //设置PA1 IO
        JL_PORTA->DIR |= BIT(1);
        JL_PORTA->HD &= ~BIT(1);
        JL_PORTA->PU |= BIT(1);
        JL_PORTA->PD &= ~BIT(1);
        JL_PORTA->DIE &= ~BIT(1);

        //启动ADC
        //adc_ch_sel(AD_KEY_PA1);
        res = adc_res_api(AD_KEY_PA1);
        res = adc_res_api(get_next_adc_ch());

        //恢复 sd io
        JL_PORTA->DIR &= ~BIT(1);
        JL_PORTA->HD |= BIT(1);
        JL_PORTA->PU |= BIT(1);
        JL_PORTA->DIE |= BIT(1);

        //恢复 sd controller
        release_sd0_controller();
        //OS_EXIT_CRITICAL();
        adc_busy_flag = 0;
    }
    else
    {
        putchar('B');
        return;
    }

    adc_value_PA1 = (res*33)/0x3ffL;
    if(++adc_timeout_cnt > 20)
    {
        //printf("online_cnt:%d     offline_cnt:%d       err_cnt:%d\n"   ,dev_online_cnt,dev_offline_cnt,adc_err_cnt);
        if(dev_online_cnt > 13)
        {
            //puts("aux_online\n");
            g_aux_online_flag = 1;
        }
        else if(dev_offline_cnt > 13)
        {
            //puts("*************aux_offline*************\n");
            g_aux_online_flag = 0;
        }
        dev_online_cnt = 0;
        adc_timeout_cnt = 0;
        dev_offline_cnt = 0;
        adc_err_cnt = 0;
    }

    if((adc_value_PA1>27)&&(adc_value_PA1<31))
    {
        dev_online_cnt++;
    }
    else if(adc_value_PA1 >= 31)
    {
        dev_offline_cnt++;
    }
    else
    {
        adc_err_cnt++;
        printf("\n========err======= %d   %d  \n",res,adc_value_PA1);
    }
    //printf("adc_val:%d,online_cnt:%d,offline_cnt:%d\n",adc_value_PA1,dev_online_cnt,dev_offline_cnt);
    printf("[%d]",adc_value_PA1);
}
#endif //SD_DADA_MULT

/*----------------------------------------------------------------------------*/
/**@brief  	pwm4_cfg
   @param	toggle:switch
  			pre_div:0-2-4-8-16-32-64-128(div = 0~7)
			duty:duty/16(dety = 0~15)
   @return  void
   @note    pwm4 clk = lsb_clk/16div(default:48M/16 = 3M)
 */
/*----------------------------------------------------------------------------*/
void pwm4_cfg(u8 toggle,u8 pre_div,u8 duty)
{
    u8 pwm4_scaler;
    u8 pwm4_duty;
    if(toggle)
    {
        pwm4_scaler = pre_div & 0x7;
        pwm4_duty = duty & 0xF;
        JL_PWM4->CON = (pwm4_scaler << 4) | pwm4_duty;
        JL_IOMAP->CON1 |= BIT(11)|BIT(12)|BIT(13);
        //JL_PORTA->DIR &= ~BIT(2);JL_PORTA->PU |= BIT(2);JL_PORTA->PD |= BIT(2);
    }
    else
    {
        JL_PWM4->CON = 0;
        JL_IOMAP->CON1 &= ~(BIT(11)|BIT(12)|BIT(13));
    }
}


#if defined support_sw_chack
u8	 bPowerSwFlag;
#endif
#ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
u8 bModeOfAuxContained;
#endif

void power_up_task(void)
{

  os_time_dly(150);


#if defined SUPPORT_VM_WORK_MODE

	vm_read_api(VM_WORK_MODE,&workmode);

	if(workmode>BT_WORK_MODE)
	    workmode=LINE_WORK_MODE;
	
	 if(workmode==LINE_WORK_MODE)
	      task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
	 else if(workmode==RADIO_WORK_MODE)
	      task_switch(FM_TASK_NAME, 0, SWITCH_SPEC_TASK);			
	 else if(workmode==BT_WORK_MODE)
	      task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);
	 else  if(!file_operate_get_total_phydev())
	 	
	        task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
	   else
      		  task_switch(MUSIC_TASK_NAME, 0,SWITCH_SPEC_TASK);
#elif defined support_sw_chack

	 SW_IO_IS_IN();

	if(SW_IN_CHECK())
	{

		bPowerSwFlag=0;
	    if(!file_operate_get_total_phydev())
	        task_switch("LineinTask", 0, SWITCH_SPEC_TASK);
	    else
	        task_switch("MusicTask", 0,SWITCH_SPEC_TASK);


			printf("bPowerSwFlag+++++++======%d\n",bPowerSwFlag);

		
	}
	else
		{
			bPowerSwFlag=1;
			workmode =STANBY_WORK_MODE;
			task_switch("IdleTask", 0,SWITCH_SPEC_TASK);
			printf("bPowerSwFlag======%d\n",bPowerSwFlag);
		}

#elif defined SUPPORT_POWER_ON_IN_IDLE_MODE

	bPowerOnIdleFlag=1;
 	task_switch(IDLE_TASK_NAME, 0,SWITCH_SPEC_TASK);

#elif defined SUPPORT_JH_POWER_SWITCH_IO

	  SET_POWER_SWITCH_IN();
	 
	 if(!POWER_SWITCH_CHECK())
	 {
		bStandbyModeFlag=1;	 
	 	task_switch(IDLE_TASK_NAME, 0,SWITCH_SPEC_TASK);
	 }
	 else
	         task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);
	
 	
#elif defined SUPPORT_POWER_ON_TONE

	 #ifdef SUPPORT_MODE_VOICE_EN_CH_ONOFF
		if((bModeVoiceSelVal==0)||(bModeVoiceSelVal==2))
		{		
			 if(!file_operate_get_total_phydev())   
			        task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
			     else
			        task_switch(MUSIC_TASK_NAME, 0,SWITCH_SPEC_TASK);
		}
		else
		{
			bPowerOnVoiceFlag=1;
			task_switch(IDLE_TASK_NAME, 0,SWITCH_SPEC_TASK);
		}
			
	 
	 #else
	 	bPowerOnVoiceFlag=1;
	         task_switch(IDLE_TASK_NAME, 0,SWITCH_SPEC_TASK);
	 #endif

#elif defined support_power_on_check_line

   if(file_operate_get_total_phydev())
        task_switch(MUSIC_TASK_NAME, 0,SWITCH_SPEC_TASK);
   else if(aux_is_online())
        task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
    else
        task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);



 #elif defined power_on_no_usb_sd_to_bt
   if(file_operate_get_total_phydev())
        task_switch(MUSIC_TASK_NAME, 0,SWITCH_SPEC_TASK);
    else
        task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);
#elif defined(power_on_no_usb_sd_to_nop)
    if(!file_operate_get_total_phydev())
    	{
		bModeOfAuxContained=mode_mp3_nodevice;
		task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
    	}
    else
        task_switch(MUSIC_TASK_NAME, 0,SWITCH_SPEC_TASK);

#elif defined(power_on_no_usb_sd_to_line)

    if(!file_operate_get_total_phydev())
        task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
    else
        task_switch(MUSIC_TASK_NAME, 0,SWITCH_SPEC_TASK);

#else

    task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);

#endif


}


#ifdef support_sw_chack

bool bIcPowerDcDetFlag;


#ifdef SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ

void ic_power_check_task(void)
{
	static u8 cnt;

	if((workmode==STANBY_WORK_MODE)||(workmode==MAIN_WORK_MODE))
		return;

	 SW_IO_IS_IN ();
	 MSJ_DC_DET_IO_IS_IN();

		cnt++;

		if(cnt==7)
		{
			cnt=0;
			if((!SW_IN_CHECK())&&(MSJ_DC_DET_READ())&&(!bIcPowerDcDetFlag))
			{
				bIcPowerDcDetFlag=1;
				os_taskq_post("MainTask",1,MSG_STANBY_KEY);
				printf("bIcPowerDcDetFlag======%d\n",bIcPowerDcDetFlag);

			}
		}


		
}

#else

void ic_power_check_task(void)
{
	static u8 cnt;

	if((workmode==STANBY_WORK_MODE)||(workmode==MAIN_WORK_MODE))
		return;

	 SW_IO_IS_IN ();
	 DC_DET_IO_IS_IN();

		cnt++;

		if(cnt==7)
		{
			cnt=0;
			if((SW_IN_CHECK1())&&(DC_DET_READ())&&(!bIcPowerDcDetFlag))
			{
				bIcPowerDcDetFlag=1;
				os_taskq_post("MainTask",1,MSG_STANBY_KEY);
			}
		}


		
}

#endif
#endif





#ifdef SUPPORT_PHONE_OUT_UMUTE_AMP

#include "dec/decoder_phy.h"
#include "music_ui.h"
extern bool bBtConnectFlag;


bool pa_auto_mute_state()
{

#if 1
   MUSIC_DIS_VAR *music_var;

	if(compare_task_name(MUSIC_TASK_NAME))
	   music_var = (MUSIC_DIS_VAR*)UI_var.ui_buf_adr;

	if (((compare_task_name(MUSIC_TASK_NAME))&&(*music_var->ui_curr_statu == DECODER_PLAY))\
 	||((compare_task_name(BTMSG_TASK_NAME))&&bBtConnectFlag)\
 	||(compare_task_name(LINEIN_TASK_NAME))||(compare_task_name(FM_TASK_NAME))\
 	||(play_sel_busy()))
#endif
              return 1;
	else
		return 0;

}
#endif



#ifdef SUPPORT_RGB_LED_MODE

#include "clock.h"

/*  RGB_IO_PA1PA2PB3  */

extern  u8   light_mode_mark;  
extern bool colour_run ;

#ifdef  SUPPORT_RGB_IO_PA1PA2PB3

#define LED_R_IO (1)
#define LED_G_IO (2)
#define LED_B_IO (3)

#ifdef SUPPORT_IO_ANGLOG_OUTPUT_PWM  // PA1


//------------------------------------------------------------------------------------
//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_INIT()         do{JL_PORTA->PD &= ~BIT((LED_R_IO));JL_PORTA->PU &= ~BIT((LED_R_IO));JL_PORTA->DIR &=~ BIT((LED_R_IO));JL_PORTA->DIE |=BIT((LED_R_IO));}while(0);
		
//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_ON()         do{JL_PORTA->OUT |= BIT((LED_R_IO));}while(0);

#define RGB_R_LED_OFF()        do{JL_PORTA->OUT &= ~BIT((LED_R_IO));}while(0);

//------------------------------------------------------------------------------------
//红光初始化 （用timer2通过PB3输出）
#define RGB_G_LED_INIT()         do{JL_PORTA->PD &= ~BIT(LED_G_IO);JL_PORTA->PU &= ~BIT(LED_G_IO);JL_PORTA->DIR &=~ BIT(LED_G_IO);JL_PORTA->DIE |=BIT(LED_G_IO);}while(0);
		
//红光初始化 （用timer2通过PB3输出）
#define RGB_G_LED_ON()         do{JL_PORTA->OUT |= BIT((LED_G_IO));}while(0);

#define RGB_G_LED_OFF()        do{JL_PORTA->OUT &= ~BIT(LED_G_IO);}while(0);


#else
//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_ON()         do{JL_PORTA->DIR &= ~BIT(LED_R_IO);JL_PORTA->PU |= BIT(LED_R_IO);JL_PORTA->PD |= BIT(LED_R_IO);\
                                                    JL_PORTA->DIE &= ~BIT(LED_R_IO);}while(0);

#define RGB_R_LED_OFF()        do{JL_PORTA->DIR &= ~BIT(LED_R_IO);JL_PORTA->PU &= ~BIT(LED_R_IO);\
                                                        JL_PORTA->PD  &= ~BIT(LED_R_IO);JL_PORTA->OUT &= ~BIT(LED_R_IO);\
                                                        JL_PORTA->DIE &= ~BIT(LED_R_IO);}while(0);


//绿光初始化 （用timer3通过OUT_CH1输出）
#define RGB_G_LED_ON()         do{JL_PORTA->DIR &= ~BIT(LED_G_IO);JL_PORTA->PU |= BIT(LED_G_IO);JL_PORTA->PD |= BIT(LED_G_IO);\
                                                          JL_PORTA->DIE |= BIT(LED_G_IO);}while(0);

#define RGB_G_LED_OFF()        do{JL_PORTA->DIR &= ~BIT(LED_G_IO);JL_PORTA->PU &= ~BIT(LED_G_IO);\
                                                        JL_PORTA->PD  &= ~BIT(LED_G_IO);JL_PORTA->OUT &= ~BIT(LED_G_IO);\
                                                        JL_PORTA->DIE &= ~BIT(LED_G_IO);}while(0);
#endif


//蓝光初始化（用timer1通过OUT_CH0输出）
#define RGB_B_LED_ON()         do{JL_PORTB->DIR &= ~BIT(LED_B_IO);JL_PORTB->PU &= ~BIT(LED_B_IO);JL_PORTB->PD &= ~BIT(LED_B_IO);\
                                                         JL_PORTB->DIE |= BIT(LED_B_IO);}while(0);

#define RGB_B_LED_OFF()        do{JL_PORTB->DIR &= ~BIT(LED_B_IO);JL_PORTB->PU &= ~BIT(LED_B_IO);\
                                                       JL_PORTB->PD  &= ~BIT(LED_B_IO);JL_PORTB->OUT &= ~BIT(LED_B_IO);JL_TIMER2->CON = 0x0000;\
                               				 JL_PORTB->DIE &= ~BIT(LED_B_IO);}while(0);

#elif defined SUPPORT_RGB_IO_P10PA9PB3


#define LED_R_IO (10)
#define LED_G_IO (9)
#define LED_B_IO (3)


#ifdef SUPPORT_IO_ANGLOG_OUTPUT_PWM  // PA1


//------------------------------------------------------------------------------------
//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_INIT()         do{JL_PORTA->PD &= ~BIT((LED_R_IO));JL_PORTA->PU &= ~BIT((LED_R_IO));JL_PORTA->DIR &=~ BIT((LED_R_IO));JL_PORTA->DIE |=BIT((LED_R_IO));}while(0);
		
//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_ON()         do{JL_PORTA->OUT |= BIT((LED_R_IO));}while(0);

#define RGB_R_LED_OFF()        do{JL_PORTA->OUT &= ~BIT((LED_R_IO));}while(0);

//------------------------------------------------------------------------------------
//红光初始化 （用timer2通过PB3输出）
#define RGB_G_LED_INIT()         do{JL_PORTA->PD &= ~BIT(LED_G_IO);JL_PORTA->PU &= ~BIT(LED_G_IO);JL_PORTA->DIR &=~ BIT(LED_G_IO);JL_PORTA->DIE |=BIT(LED_G_IO);}while(0);
		
//红光初始化 （用timer2通过PB3输出）
#define RGB_G_LED_ON()         do{JL_PORTA->OUT |= BIT((LED_G_IO));}while(0);

#define RGB_G_LED_OFF()        do{JL_PORTA->OUT &= ~BIT(LED_G_IO);}while(0);


#else

//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_ON()         do{JL_PORTA->DIR &= ~BIT(LED_R_IO);JL_PORTA->PU |= BIT(LED_R_IO);JL_PORTA->PD |= BIT(LED_R_IO);\
                                                    JL_PORTA->DIE &= ~BIT(LED_R_IO);}while(0);

#define RGB_R_LED_OFF()        do{JL_PORTA->DIR &= ~BIT(LED_R_IO);JL_PORTA->PU &= ~BIT(LED_R_IO);\
                                                        JL_PORTA->PD  &= ~BIT(LED_R_IO);JL_PORTA->OUT &= ~BIT(LED_R_IO);\
                                                        JL_PORTA->DIE &= ~BIT(LED_R_IO);}while(0);


//绿光初始化 （用timer3通过OUT_CH1输出）
#define RGB_G_LED_ON()         do{JL_PORTA->DIR &= ~BIT(LED_G_IO);JL_PORTA->PU |= BIT(LED_G_IO);JL_PORTA->PD |= BIT(LED_G_IO);\
                                                          JL_PORTA->DIE |= BIT(LED_G_IO);}while(0);

#define RGB_G_LED_OFF()        do{JL_PORTA->DIR &= ~BIT(LED_G_IO);JL_PORTA->PU &= ~BIT(LED_G_IO);\
                                                        JL_PORTA->PD  &= ~BIT(LED_G_IO);JL_PORTA->OUT &= ~BIT(LED_G_IO);\
                                                        JL_PORTA->DIE &= ~BIT(LED_G_IO);}while(0);
#endif

#ifdef SUPPORT_USE_RGB_ALL_ANGLOG


//------------------------------------------------------------------------------------
//蓝光初始化（用timer1通过OUT_CH0输出）
#define RGB_B_LED_INIT()         do{JL_PORTB->PD &= ~BIT(LED_B_IO);JL_PORTB->PU &= ~BIT(LED_B_IO);JL_PORTB->DIR &=~ BIT(LED_B_IO);JL_PORTB->DIE |=BIT(LED_B_IO);}while(0);

#define RGB_B_LED_ON()         do{JL_PORTB->OUT |= BIT(LED_B_IO);}while(0);

#define RGB_B_LED_OFF()        do{JL_PORTB->OUT &= ~BIT(LED_B_IO);}while(0);
//------------------------------------------------------------------------------------


#else


//蓝光初始化（用timer1通过OUT_CH0输出）
#define RGB_B_LED_ON()         do{JL_PORTB->DIR &= ~BIT(LED_B_IO);JL_PORTB->PU &= ~BIT(LED_B_IO);JL_PORTB->PD &= ~BIT(LED_B_IO);\
                                                         JL_PORTB->DIE |= BIT(LED_B_IO);}while(0);

#define RGB_B_LED_OFF()        do{JL_PORTB->DIR &= ~BIT(LED_B_IO);JL_PORTB->PU &= ~BIT(LED_B_IO);\
                                                       JL_PORTB->PD  &= ~BIT(LED_B_IO);JL_PORTB->OUT &= ~BIT(LED_B_IO);JL_TIMER2->CON = 0x0000;\
                               				 JL_PORTB->DIE &= ~BIT(LED_B_IO);}while(0);

#endif

#elif defined SUPPORT_RGB_IO_PA9PA4PA10

#define LED_R_IO (9)
#define LED_G_IO (4)
#define LED_B_IO (10)

//------------------------------------------------------------------------------------
//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_INIT()         do{JL_PORTA->PD &= ~BIT((LED_R_IO));JL_PORTA->PU &= ~BIT((LED_R_IO));JL_PORTA->DIR &=~ BIT((LED_R_IO));JL_PORTA->DIE |=BIT((LED_R_IO));}while(0);
		
//红光初始化 （用timer2通过PB3输出）
#define RGB_R_LED_ON()         do{JL_PORTA->OUT |= BIT((LED_R_IO));}while(0);

#define RGB_R_LED_OFF()        do{JL_PORTA->OUT &= ~BIT((LED_R_IO));}while(0);

//------------------------------------------------------------------------------------
//红光初始化 （用timer2通过PB3输出）
#define RGB_G_LED_INIT()         do{JL_PORTA->PD &= ~BIT(LED_G_IO);JL_PORTA->PU &= ~BIT(LED_G_IO);JL_PORTA->DIR &=~ BIT(LED_G_IO);JL_PORTA->DIE |=BIT(LED_G_IO);}while(0);
		
//红光初始化 （用timer2通过PB3输出）
#define RGB_G_LED_ON()         do{JL_PORTA->OUT |= BIT((LED_G_IO));}while(0);

#define RGB_G_LED_OFF()        do{JL_PORTA->OUT &= ~BIT(LED_G_IO);}while(0);


//------------------------------------------------------------------------------------
//蓝光初始化（用timer1通过OUT_CH0输出）
#define RGB_B_LED_INIT()         do{JL_PORTA->PD &= ~BIT(LED_B_IO);JL_PORTA->PU &= ~BIT(LED_B_IO);JL_PORTA->DIR &=~ BIT(LED_B_IO);JL_PORTA->DIE |=BIT(LED_B_IO);}while(0);

#define RGB_B_LED_ON()         do{JL_PORTA->OUT |= BIT(LED_B_IO);}while(0);

#define RGB_B_LED_OFF()        do{JL_PORTA->OUT &= ~BIT(LED_B_IO);}while(0);
//------------------------------------------------------------------------------------



#endif
u8  red_pwm;
u8  green_pwm;
u8  blue_pwm;


 void rgb_pwm_init(void) //(OUT_CH_SEL out_ch,u8 prescale,u8 duty,u32 fre)
{
//    puts("--do--\n");
 //   if(out_ch == OUT_CH0_SEL)//blue

#ifdef SUPPORT_IO_ANGLOG_OUTPUT_PWM  // PA1

	RGB_R_LED_INIT();
	RGB_G_LED_INIT();
#ifdef SUPPORT_USE_RGB_ALL_ANGLOG
	RGB_B_LED_INIT();
#endif

#else 

  {
        //PWM1,blue,PA4
        //如果有PA4 就必须用PA4   因只要设了PWM1 PA4 就是PWM功能 奇怪的问题  后期再验证 
//        puts("-blue-\n");


	JL_IOMAP->CON1 &= ~(0x0700);
	JL_IOMAP->CON1 |= 0x0300;//pwm1

	JL_TIMER1->CON = 0x0000;
	JL_TIMER1->PRD = 2000;
	JL_TIMER1->PWM =0;// (2000*50)/100;默认关
	JL_TIMER1->CON = (1<<4) | (1<<8)| (1<<0) |(2<<2); //
	RGB_R_LED_ON();
    }


//    else if(out_ch == OUT_CH1_SEL)//
    {
        //PB9 
//        puts("-green&white-\n");
        JL_IOMAP->CON1 &= ~(0x3800);
        JL_IOMAP->CON1 |= 0x1800;//pwm3

        JL_TIMER3->CON = 0x0000;
        JL_TIMER3->PRD = 2000;
        JL_TIMER3->PWM = 0;//(2000*50)/100;默认关
        JL_TIMER3->CON =  (1<<4) | (1<<8)| (1<<0) | (2<<2); //
        RGB_G_LED_ON();
    }
#endif

//    else if(out_ch == OUT_ASSIGN_PORT)//
    {
        //PWM2,red,PB3
//        puts("-red-\n");

//        JL_IOMAP->CON1 &= ~(0x3800);
//        JL_IOMAP->CON1 |= 0xCD000;//pwm2


        JL_TIMER2->CON = 0x0000;
        JL_TIMER2->PRD = 2000;
        JL_TIMER2->PWM = 0;//(8000*50)/100; 默认关
        JL_TIMER2->CON =  (1<<4) | (1<<8)| (1<<0) | (2<<2); //
        
        

/*
		JL_TIMER2->CON = 0x0000;
        JL_TIMER2->PRD = sys_clk/(div*fre);
        JL_TIMER2->PWM = (JL_TIMER2->PRD*duty)/USE_DENOMINATOR;
        JL_TIMER2->CON =  (prescale<<4) | (1<<8)| (1<<0) | (2<<2); //
*/   

	}


}
 #ifdef SUPPORT_IO_ANGLOG_OUTPUT_PWM  // PA1
u16 bRgbRedPwmVal,bRgbGreenPwmVal,bRgbBluePwmVal;
 void red_pwm_scan(void) 
{
	static u16 cnt,cnt1,cnt2;

	if(red_pwm==0)
	{
		RGB_R_LED_OFF();	
	}
	
	if(green_pwm==0)
	{
		RGB_G_LED_OFF();	
	}	
			

	cnt++;
	
	if(cnt<bRgbRedPwmVal)
	{	
    	  if(red_pwm>0)	
    	  	{
		RGB_R_LED_ON();
    	  	}
	}
	else
	{
		RGB_R_LED_OFF();
	}
	
	cnt1++;
	
	if(cnt1<bRgbGreenPwmVal)
	{	
    	    if(green_pwm>0)	
	 	{
		 RGB_G_LED_ON();		
	 	}
	}
	else
	{
		RGB_G_LED_OFF();
	}

#ifdef SUPPORT_USE_RGB_ALL_ANGLOG

	if(blue_pwm==0)
	{
		RGB_B_LED_OFF();	
	}
	cnt2++;
	
	if(cnt2<bRgbBluePwmVal)
	{	
    	    if(blue_pwm>0)	
	 	{
		 RGB_B_LED_ON();		
	 	}
	}
	else
	{
		RGB_B_LED_OFF();
	}
	
   if(cnt2>50)
    cnt2=0;

#endif

   if(cnt>50)
    cnt=0;
   
   if(cnt1>50)
    cnt1=0;
   
 }

#endif


 void red_pwm_set(void) 
 {
 
 #ifdef SUPPORT_IO_ANGLOG_OUTPUT_PWM  
 
	bRgbRedPwmVal= (50*red_pwm)/250;	
 
 
#else
   JL_TIMER1->PWM = (2000*red_pwm)/250;	     
#endif

 }

  void green_pwm_set(void) 
 {
 #ifdef SUPPORT_IO_ANGLOG_OUTPUT_PWM  

	bRgbGreenPwmVal= (50*green_pwm)/250;	
 
#else
   JL_TIMER3->PWM = (2000*green_pwm)/250;	     
#endif
 
 }
  
 void blue_pwm_set(void) 
 {
 #ifdef SUPPORT_USE_RGB_ALL_ANGLOG
	bRgbBluePwmVal= (50*blue_pwm)/250;	
#else
  JL_TIMER2->PWM = (2000*blue_pwm)/250;

 #endif
}

 void off_rgb_pwm_set(void) 
 {
JL_TIMER1->PWM = 0;	     
JL_TIMER3->PWM = 0;	     
JL_TIMER2->PWM = 0;	     

 }


#define EN_0 65500*1/5
#define EN_1 65500*2/5
#define EN_2 65500*3/5
#define EN_3 65500*4/5
#define EN_4 65500*5/5

#define   RGB_MAX_VOL    250
#define   RGB_D_MAX_VOL    (RGB_MAX_VOL*2)
#define   RGB_ALL_MAX_VOL    (RGB_MAX_VOL*14)
#define   RGB_ALL_DET_MAX_VOL    (RGB_MAX_VOL*7)

u8 Get_dac_energy(u16 energy)
{
 static u8 bEnergyVal,bEnergyValOld,bCnt,bCnt1;
 #if 0
	 if(energy<=EN_0)bEnergyVal= 0;
	 if(energy<=EN_1)bEnergyVal= 1;
	 if(energy<=EN_2)bEnergyVal= 2;
	 if(energy<=EN_3)bEnergyVal= 3;
	 bEnergyVal= 4;
#else
	bEnergyVal=(u8)(energy/1638);

//		printf("----1---energy----------%x\n",energy);
//		printf("----1---bEnergyVal----------%d\n",bEnergyVal);

#endif
		return bEnergyVal;
#if 0
	if((bEnergyVal>0)&&(++bCnt>=10))
	{
		bCnt=11;
		bEnergyValOld=bEnergyVal;	
	}			
	 else if(bEnergyVal==0)
	 {
		bEnergyValOld=bEnergyVal;	
		bCnt=0;
	 }
	 	
	if(bEnergyValOld==bEnergyVal)
	{
		return bEnergyVal;
	 }
	else
	{
		return bEnergyValOld;
	 }
#endif	
		 
}	

u8 bRgbMode;
u16 bRgbModeCnt;
// bRgbMode - 0-R 1-B  2-G  3-RB-紫 4-RG-黄 5-R255-G125-255 -橙 6-BG-青7-7swap  8-off
void  led_disp_eq(void)  
{

 static u8 bEnergyVal,bMode,bEnergyOut,bModeCnt;
 static u16 bRgbTimer,bRgbAutoTimer,bEnergyVal2;

#if 1

	bEnergyVal2=(u16)(get_dac_energy_value()>>8);

	bEnergyVal=Get_dac_energy(bEnergyVal2);

	
	if((bEnergyVal>0)&&(dac_ctl.sys_vol_l!=0))
		{
			bEnergyOut=bEnergyVal;
			bMode=RGB_MODE_RGB_DET;
			
		}
	else
		{
			bEnergyOut=0;		
			bMode=bRgbMode;
		}

	//		bMode=RGB_MODE_RGB_DET;



#if 1
       if(compare_task_name("IdleTask"))
		bMode=RGB_MODE_OFF;
	   
#endif
#else

	bEnergyVal2=(u16)(get_dac_energy_value()>>8);

	bEnergyVal=Get_dac_energy(bEnergyVal2);


			bMode=bRgbMode;

		printf("----1---bEnergyVal----------%d\n",bEnergyVal);

#endif

 	 		 	
	switch(bMode)	
	{
		case RGB_MODE_R:					
		case RGB_MODE_G:			
		case RGB_MODE_B:
		case RGB_MODE_RB:			 
		case RGB_MODE_RG:			 
		case RGB_MODE_RG2:
		case RGB_MODE_BG:
			bRgbAutoTimer=0;
			bRgbTimer=0;
			led_rgb(bMode);			 			 
		break;
		case RGB_MODE_RGB:
			
			if(bRgbTimer<RGB_ALL_MAX_VOL)
				bRgbTimer++;
			else
				bRgbTimer=0;
			 bModeCnt=(u8)(bRgbTimer/RGB_D_MAX_VOL);
			 
			led_rgb(bModeCnt);			 			 			
			
			break;
		
		case RGB_MODE_RGB_DET:
			

			if(bRgbMode==RGB_MODE_OFF)
			{
				off_rgb_pwm_set();
				break;
			}		
			
			if(bRgbAutoTimer<RGB_ALL_DET_MAX_VOL)
				bRgbAutoTimer++;
			else
				bRgbAutoTimer=0;
			
			if(bRgbMode==RGB_MODE_RGB)
				 bModeCnt=bRgbAutoTimer/(RGB_MAX_VOL);
			 else
				 bModeCnt=bRgbMode;//bRgbAutoTimer/(RGB_MAX_VOL);
			 	
//			printf("----1---bModeCnt----------%d\n",bModeCnt);
//			printf("----1---bRgbMode----------%d\n",bRgbMode);

				if(bEnergyVal==1)
				{
					led_rgb_auto(bModeCnt,0);
				}
				else if(bEnergyVal<=3)
					led_rgb_auto(bModeCnt,bEnergyVal*2);
				else if(bEnergyVal<=6)
					led_rgb_auto(bModeCnt,bEnergyVal*6);
				else if(bEnergyVal<=9)
					led_rgb_auto(bModeCnt,bEnergyVal*9);	
				else if(bEnergyVal<=15)
					led_rgb_auto(bModeCnt,bEnergyVal*10);					
				else 
					led_rgb_auto(bModeCnt,RGB_MAX_VOL);
					
			break;		
			
		case RGB_MODE_OFF:
			
				red_pwm=0;
				green_pwm=0;
				blue_pwm=0;	
				off_rgb_pwm_set();
			break;

	}
}


// bRgbMode - 0-R 1-B  2-G  3-RB-紫 4-RG-黄 5-R255-G128-0 -橙 6-BG-青// 7-7swap  8-off

void  led_rgb(u8 bMode)
{

	 if(bRgbModeCnt<RGB_D_MAX_VOL)
		bRgbModeCnt++;		
	 else
		bRgbModeCnt=0;	
	 		 	
	switch(bMode)	
	{
		case RGB_MODE_R:
			 if(bRgbModeCnt<RGB_MAX_VOL)
				red_pwm=bRgbModeCnt;
			 else
				red_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 	
			green_pwm=0;
			blue_pwm=0;		
			break;
			
		case RGB_MODE_G:
			
			red_pwm=0;
			 if(bRgbModeCnt<RGB_MAX_VOL)
				green_pwm=bRgbModeCnt;
			 else
				green_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 	
			blue_pwm=0;
			
			break;
		case RGB_MODE_B:
			red_pwm=0;
			green_pwm=0;
			 if(bRgbModeCnt<RGB_MAX_VOL)
				blue_pwm=bRgbModeCnt;
			 else
				blue_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 	
			break;
		case RGB_MODE_RB:  //紫色255 0  255

			 if(bRgbModeCnt<RGB_MAX_VOL)
				red_pwm=bRgbModeCnt;
			 else
				red_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 
			 green_pwm=0;
			 
			 if(bRgbModeCnt<RGB_MAX_VOL)
				blue_pwm=bRgbModeCnt;
			 else
				blue_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 
			 
			break;
			
		case RGB_MODE_RG: // 黄色255 255 0

			 if(bRgbModeCnt<RGB_MAX_VOL)
				red_pwm=bRgbModeCnt;
			 else
				red_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 
			 if(bRgbModeCnt<RGB_MAX_VOL)
				green_pwm=bRgbModeCnt*2/3;
			 else
				green_pwm=(RGB_D_MAX_VOL-bRgbModeCnt)*2/3;
			 
			 blue_pwm=0;
			 
			break;
			
		case RGB_MODE_RG2:  // 橙色  255 128 0

			 if(bRgbModeCnt<RGB_MAX_VOL)
				red_pwm=bRgbModeCnt;
			 else
				red_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 
			 if(bRgbModeCnt<RGB_MAX_VOL)
				green_pwm=bRgbModeCnt*1/2;
			 else
				green_pwm=(RGB_D_MAX_VOL-bRgbModeCnt)*1/2;
			 
			 blue_pwm=0;
			 
			break;
			
		case RGB_MODE_BG:// 青色 0 255 255

			 red_pwm=0;

			 if(bRgbModeCnt<RGB_MAX_VOL)
				blue_pwm=bRgbModeCnt;
			 else
				blue_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 
			 if(bRgbModeCnt<RGB_MAX_VOL)
				green_pwm=bRgbModeCnt;
			 else
				green_pwm=RGB_D_MAX_VOL-bRgbModeCnt;
			 			 
			break;
			
	}
	
	red_pwm_set(); 
	green_pwm_set();
	blue_pwm_set();
}


void  led_rgb_auto(u8 bMode,u16 bRgbTime)
{

static u8 bRTime,bGTime,bBTime,bRgbTimerCnt;


//	bRgbTimerCnt=bRgbTime/100;

//	bRgbTime=bRgbTime*5;

	switch(bMode)	
	{
		case RGB_MODE_R:
				red_pwm=bRgbTime;
				green_pwm=0;
				blue_pwm=0;		
			break;
			
		case RGB_MODE_G:			
				red_pwm=0;
				green_pwm=bRgbTime;
				blue_pwm=0;		
			
			break;
		case RGB_MODE_B:
				red_pwm=0;
				green_pwm=0;
				blue_pwm=bRgbTime;				 	
			break;
			
		case RGB_MODE_RB:
				red_pwm=bRgbTime;
				blue_pwm=bRgbTime;
				green_pwm=0;				 
			 
			break;	
			
		case RGB_MODE_RG:
				red_pwm=bRgbTime;
				green_pwm=bRgbTime;
				blue_pwm=0;				 
			 
			break;

		case RGB_MODE_RG2:
				red_pwm=bRgbTime;
				green_pwm=0;							
				blue_pwm=50+bRgbTime/2;
			break;
		
		case RGB_MODE_BG:
				red_pwm=0;
				green_pwm=bRgbTime;				 
				blue_pwm=bRgbTime;
				
			break;
						
	}

	green_pwm_set();
	blue_pwm_set();
	red_pwm_set(); 
}

#endif



