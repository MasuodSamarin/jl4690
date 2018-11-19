

/*
*********************************************************************
                        DEBUG MACRO
*********************************************************************
*/
//#define __DEBUG         ////<开启系统打印调试功能


/*
*********************************************************************
                        APPLICATION FUNCTION
*********************************************************************
*/

#define EARPHONE_MODE_EN    0



#if EARPHONE_MODE_EN
    #define VCOMO_EN 	1	//是否选择VCMO直推耳机
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#else
    #define VCOMO_EN 	0	//是否选择VCMO直推耳机
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#endif


/*
*********************************************************************
                        COMMON MACRO
*********************************************************************
*/
#define EQ_EN			        0       ///<EQ模块开关
#define EQ_UART_BDG	    		0       ///<EQ uart online dbg switch
#define DAC_SOUNDTRACK_COMPOUND 0       ///<dac声道合并
#define DAC_AUTO_MUTE_EN		1       ///<自动mute
#define SYS_LVD_EN              1       ///<电量监测
#define KEY_TONE_EN     	    1       ///<按键音
#define UART_UPDATA_EN         0    ///<串口升级
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<按键双击功能
#endif


#define SYS_DEFAULT_VOL        30      ///<非0表示使用默认音量


/*
*********************************************************************
                        DEVICE MACRO
*********************************************************************
*/
#ifdef MINI
    #define SDMMC0_EN         0
    #define SDMMC1_EN         0
    #define USB_DISK_EN      0
    #define USB_PC_EN          0
#else
    #define SDMMC0_EN       1
    #define SDMMC1_EN       0
    #define USB_DISK_EN     1
    #define USB_PC_EN       1
#endif

/*
*********************************************************************
                        APP MACRO
*********************************************************************
*/

  #define SUPPORT_APP_RCSP_EN         0   ///<标准SDK，手机app 功能暂时不支持

#if SUPPORT_APP_RCSP_EN
    #define RCSP_LIGHT_HW               1   //light hardware support
#else
    #define RCSP_LIGHT_HW               0
#endif


/*
*********************************************************************
                        BT MACRO
*********************************************************************
*/
#include "bluetooth/bluetooth_api.h"

#define BT_MODE      NORMAL_MODE

#if BT_MODE==TEST_FCC_MODE
  #undef UART_UPDATA_EN
  #define UART_UPDATA_EN  0
#endif

#define BT_ANALOG_CFG   0//模拟配置
#define BT_XOSC         0//

#define BT_BACKMODE         0            ///<蓝牙后台


#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID拍照的独立模式只支持非后台
#endif

#define BT_PHONE_NUMBER                    1          ///<来电报号
#define AUTO_SHUT_DOWN_TIME         0          ///蓝牙无连接自动关机计时，u16类型，0表示不自动关机

/*
*********************************************************************
                       电源设置 
*********************************************************************
*/
#define    PWR_NO_CHANGE     0     //   0:  no change   
#define    PWR_LDO33         1     //   1:  LDOIN 5v -> VDDIO 3.3v -> DVDD 1.2v
#define    PWR_LDO15         2     //   2:  LDOIN 5v -> LDO   1.5v -> DVDD 1.2v, support bluetooth
#define    PWR_DCDC15        3     //   3:  LDOIN 5v -> DCDC  1.5v -> DVDD 1.2v, support bluetooth


#define PWR_MODE_SELECT    PWR_LDO15

/*
*********************************************************************
                       低功耗设置 
*********************************************************************
*/
#define    BT_OSC           0
#define    RTC_OSCH         1
#define    RTC_OSCL         2


    #define SNIFF_MODE_CONF    0//SNIFF_EN
    #define BT_LOW_POWER_MODE  0//BT_POWER_DOWN_EN //BT_POWER_OFF_EN
    #define LOWPOWER_OSC_TYPE  BT_OSC//RTC_OSCL//BT_OSC
    #define LOWPOWER_OSC_HZ    24000000L//32768L//24000000L


#define BLE_BREDR_MODE      BT_BREDR_EN
/*
*********************************************************************
                       芯片封装配置 
*********************************************************************
*/
#define RTCVDD_TYPE              0          //RTCVDD口没有绑出来要置1,目前对应封装芯片AC6905
#define BTAVDD_TYPE              0          //BTAVDD没有绑出来要置1 ，目前对应封装芯片AC6907A,AC6908A


/*
*********************************************************************
                        MUSIC MACRO
*********************************************************************
*/
#define MUSIC_DECRYPT_EN 		0	//SMP加密文件支持
#define MUSIC_AB_RPT_EN 		0	//AB断点支持


#define DEC_TYPE_MP3_ENABLE         ///<MP3
#define DEC_TYPE_SBC_ENABLE         ///<SBC

#ifndef MINI
    #define DEC_TYPE_WAV_ENABLE     ///<3K_code_space
    #define DEC_TYPE_FLAC_ENABLE    ///<5K_code_space
    #define DEC_TYPE_APE_ENABLE     ///<8K_code_space
    #define DEC_TYPE_WMA_ENABLE     ///<30K_code_space
    // #define DEC_TYPE_F1A_ENABLE     ///<30K_code_space
#endif



/*
*********************************************************************
                        FM MACRO
*********************************************************************
*/
#ifdef MINI
    #define FM_RADIO_EN         0       ///<MINI_BT
#else
    #define FM_RADIO_EN         1       ///<标准SDK
#endif

#if FM_RADIO_EN
    #define RDA5807                 0       ///<RDA5807FM
    #define BK1080                  0       ///<BK1080FM
    #define QN8035                  0       ///<QN8035FM
    #define FM_INSIDE               1       ///<芯片内部FM
#endif

/*
*********************************************************************
                        RTC MACRO
*********************************************************************
*/
  #define RTC_CLK_EN          0       ///<标准SDK RTC时钟模式

#if RTC_CLK_EN
    #define RTC_ALM_EN          1       ///<RTC闹钟模式
    #define RTC_CLK_CHECK_EN    0       ///<RTC晶振检测
#endif

/*
*********************************************************************
                        ECHO MACRO
*********************************************************************
*/
  #define ECHO_EN                      0       ///<混响功能 标准SDK
  #define ECHO_TASK_EN        0       ///<混响模式 标准SDK

/*
*********************************************************************
                        REC MACRO
*********************************************************************
*/
    #define REC_EN             0   ///<标准SDK录音功能


#if 0 //SUPPORT_APP_RCSP_EN
    #undef  REC_EN
    #define REC_EN         0         ///<手机APP模式不支持录音
#endif

#if REC_EN
	#define BT_REC_EN		0       ///<蓝牙录音使能
	#define MIC_REC_EN		1       ///<MIC录音使能
	#define FM_REC_EN		1       ///<FM录音使能
	#define AUX_REC_EN		1       ///<AUX录音使能
#endif


/*
*********************************************************************
                        UI MACRO
*********************************************************************
*/


   #define UI_ENABLE               0    ///<UI_显示
 

#if 0//UI_ENABLE
    ///二选一
    #define LCD_128X64_EN         0      ///<lcd 支持
    #define LED_7_EN                       1      ///<led 支持     
    #define LCD_SUPPORT_MENU     0       ///菜单显示
    #define LRC_LYRICS_EN                 0       ///LRC歌词显示





    #define support_led7_user_pc0pa14pa15pc1pc2pc3pc4
    #define support_aux_led_disp_line     //屏上显示"LINE"
    #define support_led_disp_pause
    #define support_mute_led_all_flish    //MUTE闪屏

	
 #endif 





 



#define muteh_key_mode   1

#if muteh_key_mode
#define KEY_AD_EN           1   ///<AD按键使能
#define KEY_IO_EN             0   ///<IO按键使能
#define KEY_IR_EN             0   ///<红外遥控使能,PA9
#define KEY_TCH_EN         0   ///<触摸按键使能
#endif 

#if KEY_AD_EN  
#define adk_user_pb9
#define support_k68_1key_mode
#endif 

#define    adk_user_k68_key   



#define LED_EN                  1       ///<LED指示使能
#define  PP_LED_USER_PC5

//MUTE IO 
    #define   PA_ENABLE
#ifdef PA_ENABLE  
        #define  pa_mute_use_pin_PC4 //pa_mute_use_pin_PA11    // pa_mute_use_pin_PR0 //
    //    #define   mute_io_L_is_mute   //  低MUTE   不定义为高MUTE    
      #define support_vol_is_0_mute_amp	//音量到0 MUTE 功放
//      #define support_pause_stop_mute_amp
  //    #define  support_bt_pause_mute_amp		  	
#endif 

//AB/D
//#define support_amP_ab_d
//#define amp_ab_d_user_PB6  


#if KEY_TONE_EN
#define  support_vol_max_tone_en  0
#endif 


/*接这个做在LINE下检测 PC15 低时 MUTE */
#define PHONE_CHECK_ENABLE
#ifdef PHONE_CHECK_ENABLE
 #define  support_phone_chack_user_PB12   //support_phone_chack_user_PA9  //
#endif 


//line 检测
#define    line_user_PA3PA4  //AUX0 

#define AUX_DETECT_EN  1
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PB11
    #define  support_line_unline_to_next_mode   //AUX 不在线到下一个模式
  //  #define AUX_OUT_WITHOUT_CNT  //拔出不去抖

#endif 

///#define  power_on_no_usb_sd_to_bt 


#define support_off_usb_dp    //设置USB_DP 为输入
#define support_off_PB13        //设置PB13为输入
#define support_off_phone_call    //关通话



//软开机设置
#define power_on_wait_power_key_down
#define support_io_power_on_off    //控制MOS管
#define  power_on_off_user_PB10 
#define support_power_off_voice
//#define support_short_push_key_power_on   
#define ENABLE_POWER_ON_KEY_WAIT













