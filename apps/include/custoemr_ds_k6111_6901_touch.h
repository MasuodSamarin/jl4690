
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

/*
*********************************************************************
                       耳机功能使能 
*********************************************************************
*/
#define EARPHONE_MODE_EN    0



/*
*********************************************************************
                        COMMON MACRO
*********************************************************************
*/
#define EQ_EN			        1       ///<EQ模块开关
#define EQ_UART_BDG	    		0       ///<EQ uart online dbg switch
#define DAC_SOUNDTRACK_COMPOUND 0       ///<dac声道合并
#define DAC_AUTO_MUTE_EN		1       ///<自动mute
#define SYS_LVD_EN              1       ///<电量监测
#define KEY_TONE_EN     	    1       ///<按键音
#define UART_UPDATA_EN          0      ///<串口升级
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<按键双击功能
#endif

#define SYS_DEFAULT_VOL         0     ///<非0表示使用默认音量

#if  SYS_DEFAULT_VOL
#else 
#define RESET_DEFAULT_VOL   25 
#define RESET_MIN_VOL             10
#endif 


/*
*********************************************************************
                        DEVICE MACRO
*********************************************************************
*/
#ifdef MINI
    #define SDMMC0_EN       0
    #define SDMMC1_EN       0
    #define USB_DISK_EN     0
    #define USB_PC_EN       0
#else
    #define SDMMC0_EN       0
    #define SDMMC1_EN      1
    #define USB_DISK_EN     1
    #define USB_PC_EN       1
     #define  user_sd_1_a	//  PC3- DAT     PC4 -  CMD     PC5 -CLK
#endif

/*
*********************************************************************
                        DAC VCOMO 配置
*********************************************************************
*/
#if EARPHONE_MODE_EN
    #define VCOMO_EN 	1	//是否选择VCMO直推耳机
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#else
    #define VCOMO_EN 	0	//是否选择VCMO直推耳机
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#endif

/*
*********************************************************************
                        APP MACRO
*********************************************************************
*/
#ifdef MINI
    #define SUPPORT_APP_RCSP_EN         0   ///<MINI_BT，手机app 功能暂时不支持
#else
    #define SUPPORT_APP_RCSP_EN         0   ///<标准SDK，手机app 功能暂时不支持
#endif // MINI_BT

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

#if SUPPORT_APP_RCSP_EN
#define BT_BACKMODE         1             ///<蓝牙后台
#else
#define BT_BACKMODE         0             ///<蓝牙后台
#endif

#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID拍照的独立模式只支持非后台
#endif

#define BT_PHONE_NUMBER     1          ///<来电报号

#if EARPHONE_MODE_EN
	#define AUTO_SHUT_DOWN_TIME 3*2*60          ///蓝牙无连接自动关机计时，u16类型，0表示不自动关机
#else
	#define AUTO_SHUT_DOWN_TIME 0          ///蓝牙无连接自动关机计时，u16类型，0表示不自动关机
#endif

/*
*********************************************************************
                       电源设置 
*********************************************************************
*/
#define    PWR_NO_CHANGE     0     //   0:  no change   
#define    PWR_LDO33         1     //   1:  LDOIN 5v -> VDDIO 3.3v -> DVDD 1.2v
#define    PWR_LDO15         2     //   2:  LDOIN 5v -> LDO   1.5v -> DVDD 1.2v, support bluetooth
#define    PWR_DCDC15        3     //   3:  LDOIN 5v -> DCDC  1.5v -> DVDD 1.2v, support bluetooth

#if EARPHONE_MODE_EN
	#define PWR_MODE_SELECT      PWR_DCDC15 
#else
	#define PWR_MODE_SELECT      PWR_LDO15
#endif

/*
*********************************************************************
                       低功耗设置 
*********************************************************************
*/
#define    BT_OSC           0
#define    RTC_OSCH         1
#define    RTC_OSCL         2

#if EARPHONE_MODE_EN
    #define SNIFF_MODE_CONF    SNIFF_EN
    #define BT_LOW_POWER_MODE  BT_POWER_DOWN_EN //BT_POWER_OFF_EN
    #define LOWPOWER_OSC_TYPE  BT_OSC
    #define LOWPOWER_OSC_HZ    24000000L
#else
    #define SNIFF_MODE_CONF    0//SNIFF_EN
    #define BT_LOW_POWER_MODE  0//BT_POWER_DOWN_EN //BT_POWER_OFF_EN
    #define LOWPOWER_OSC_TYPE  BT_OSC//RTC_OSCL//BT_OSC
    #define LOWPOWER_OSC_HZ    24000000L//32768L//24000000L
#endif

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
#define MUSIC_DECRYPT_EN 		1	//SMP加密文件支持
#define MUSIC_AB_RPT_EN 		1	//AB断点支持


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
#ifdef MINI
    #define RTC_CLK_EN          0       ///<MINI_BT RTC时钟模式
#else
    #define RTC_CLK_EN          0       ///<标准SDK RTC时钟模式
#endif

#if RTC_CLK_EN
    #define RTC_ALM_EN          1       ///<RTC闹钟模式
    #define RTC_CLK_CHECK_EN    0       ///<RTC晶振检测
#endif

/*
*********************************************************************
                        ECHO MACRO
*********************************************************************
*/
#ifdef MINI
    #define ECHO_EN             0       ///<混响功能 MINI_BT
    #define ECHO_TASK_EN        0       ///<混响模式 MINI_BT
#else
    #define ECHO_EN             0       ///<混响功能 标准SDK
    #define ECHO_TASK_EN        0       ///<混响模式 标准SDK
#endif

/*
*********************************************************************
                        REC MACRO
*********************************************************************
*/
#ifdef MINI
    #define REC_EN             0    ///<MINI_BT录音功能
#else
    #define REC_EN             0   ///<标准SDK录音功能
#endif

#if SUPPORT_APP_RCSP_EN
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

 #define UI_ENABLE                0     ///<UI_显示
 
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
    #define support_bt_waiting_conn_filsh_led   //等待连接 LED 闪闪


    //#define  led_io_180_mirror   
	
 #endif 

#define muteh_key_mode   1

#if muteh_key_mode
#define KEY_AD_EN         0   ///<AD按键使能
#define KEY_IO_EN         0  ///<IO按键使能
#define KEY_IR_EN          0  ///<红外遥控使能,PA9
#define KEY_TCH_EN      1   ///<触摸按键使能
#endif 

#if 0//KEY_AD_EN  
#define adk_user_pa9
#endif 

#if  0// KEY_IO_EN
#define support_io_scan_user_PB8PB9PB11
#define io_scnkey_k2754_mode
#endif 

#if  KEY_TCH_EN
#define  ds_k6111_key_mode  

#endif 

#define adk_user_6_key_mode


#if 0  //KEY_IR_EN         ///<红外遥控使能,PA9
#define  IR_IO     0x1a      //PB10  ==0x1a   
#define IR_USER_KPL_002  //IR_USER_KPL_003    //    
#define ir_user_kpl_ty_msg
#define  ir_max_num     33
#define   support_stanby_mod 
#endif 

#define LED_EN                  1  ///<LED指示使能
#define  PP_LED_USER_PC2

//MUTE IO 
    #define   PA_ENABLE
#ifdef PA_ENABLE   //这个案子无MUTE脚  站位
        #define  pa_mute_use_pin_PA11    // pa_mute_use_pin_PR0 //
    //    #define   mute_io_L_is_mute   //  低MUTE   不定义为高MUTE    
      #define support_vol_is_0_mute_amp	//音量到0 MUTE 功放
      #define support_pause_stop_mute_amp
      #define support_bt_DISCONNECT_mute_amp
      #define  support_bt_pause_mute_amp	
	  
	
#endif 

//AB/D
#define support_amP_ab_d
#define amp_ab_d_user_PA10  


#if KEY_TONE_EN
#define  support_vol_max_tone_en  1
#endif 




//line 检测
#define    line_user_PA1PA2  //AUX0 

#define AUX_DETECT_EN    1
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PA3
    #define  support_line_unline_to_next_mode   //AUX 不在线到下一个模式
  //  #define AUX_OUT_WITHOUT_CNT  //拔出不去抖

#endif 

#define  power_on_no_usb_sd_to_bt  //power_on_no_usb_sd_to_line   //
//#define  usb_sd_out_to_bt_mode    //#define  usb_sd_out_to_line_mode


#define suppout_line_puse_is_mute 
//#define support_line_pause_disp_pause

//低电提示
//#define support_low_power_voice  //support_low_power_key_voice

