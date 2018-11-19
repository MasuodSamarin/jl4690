

/*
GPIO SET:
	ADKEY-PA9	IR-PB3 	AUX0-PA1PA2		MIC-PB13	MUTE-PA11 	FREQ_DET-PA3
	SD1-PB0_DAT_PB1_CMD_PB2_CLK	PA4PB11-ENCORD	
	PT2313_CLK-PB10	PT2313_DATA-PB9  PT2313_IN-9-13-MP3  PT2313_IN-10-14-AUX 	
	M62429-CLK-PB12		12-ECHO   78-VOL
	TM1628-DATCLKSTB-PC5PC4PC3
*/

/*
*********************************************************************
                        DEBUG MACRO
*********************************************************************
*/

// #define __DEBUG         ////<开启系统打印调试功能

/*
*********************************************************************
                        APPLICATION FUNCTION
*********************************************************************
*/
#define AC6901A_OFF_IO  // JSUO ADD  20161111


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
#define SYS_LVD_EN              0       ///<电量监测
#define KEY_TONE_EN     	    1       ///<按键音
#define UART_UPDATA_EN          0      ///<串口升级
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<按键双击功能
#endif

//=================================================
// 1-VOL SET JSUO
#define SYS_DEFAULT_VOL        30      ///<非0表示使用默认音量
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
// 2- SD USB PC  EN	JSUO

    #define SDMMC0_EN       0
    #define SDMMC1_EN       1
    #define USB_DISK_EN     1
    #define USB_PC_EN        1



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

#define BT_BACKMODE         0             ///<蓝牙后台


#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID拍照的独立模式只支持非后台
#endif

#define BT_PHONE_NUMBER                    0          ///<来电报号
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

#define D2SH_DIS_SW         0          //d2sh dis sw  rtcvdd口没有拉出来要置1
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

//  2.5  ---     MUSIC  SMP  PASSWORD  SET	JSUO

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
// 3- FM EN	JSUO

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
// 4- REC EN	JSUO

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

// 5- UI	EN	JSUO

   #define UI_ENABLE                1     ///<UI_显示
 

#if  UI_ENABLE
    ///二选一
    #define LCD_128X64_EN         0      ///<lcd 支持
    #define LED_7_EN                       1      ///<led 支持     
    #define LCD_SUPPORT_MENU     0       ///菜单显示
    #define LRC_LYRICS_EN                 0       ///LRC歌词显示



//#define SUPPORT_TM1628_MODE
#ifdef SUPPORT_TM1628_MODE
//#define TEST_PANEL_LED

//#define LED_ID_JW2781
//#define LED_ID_JW5028B_1B // SD-5029YPG
#define LED_ID_LD999B_J  
#define TM1628_MODE 0x03
//#define TM1628_DATA_CLK_STB_USE_PA15PA14PC0
//#define TM1628_DATA_CLK_STB_USE_PC0PA14PA15
#define TM1628_DATA_CLK_STB_USE_PC5PC4PC3
#define LED_COM_MAX 14
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 7
#define LED_EQ_NUMS  14


#define LED_SHOW_SCREEN_FREQUENCE
#ifdef LED_SHOW_SCREEN_FREQUENCE
#define SUPPORT_EQ_FREQUENCE
#define EQ_ADC_VALUE_DETECT  
#define SUPPORT_POWER_ON_FREQUENCE_DELAY_SHOW  
extern u8 bFrequencePowerOnDelayVal;

//#define EQ_DETECT_PIN_USE_PB11
#define EQ_DETECT_PIN_USE_PA3
#define SUPPORT_EQ_FREQUENCE_TIMER_SCAN
#endif
#endif


#define LED_7PIN_MODE
#ifdef LED_7PIN_MODE
#define support_led7_user_pc0pa14pa15pc1pc2pc3pc4
//#define LED_7PIN_REVERSE
	
//#define LED_ID_4018N_2
#ifdef LED_ID_4018N_2
#define LED_COM_MAX 7
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 7
#endif


#define LED_ID_JW4018D_1B
#ifdef LED_ID_JW4018D_1B
#define LED_COM_MAX 7
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 10
#endif


#endif

#define SUPPORT_FLASH_ICON
#define SUPPORT_FLASH_CHAR

#define SUPPORT_BT_LED_PRORAM


#ifdef SUPPORT_FLASH_CHAR
#define SUPPORT_LED_BLUE_STRING_FLASH
#define SUPPORT_MUTE_FLASH
#define MUTE_FLASH_ALL_SCREEN
//#define MUTE_FLASH_ZERO_VOL
#endif

//#define support_aux_led_disp_line     //屏上显示"LINE"
//#define support_aux_led_disp_aux     //屏上显示"LINE"
#define support_aux_led_disp_auxI     //屏上显示"LINE"
#define support_led_disp_pause
#define support_mute_led_all_flish    //MUTE闪屏
#define SUPPORT_NO_SHOW_LOAD	
#define SUPPORT_SD40X18_1SRB_15_OFF_BAT_ICON
 #endif 


//*********************************************************************
 

//-------ADKEY--------------------------------------------------------


#define muteh_key_mode   1

#if muteh_key_mode
#define KEY_AD_EN       1   ///<AD按键使能
#define KEY_IO_EN       0   ///<IO按键使能
#define KEY_IR_EN       1   ///<红外遥控使能,PA9
#define KEY_TCH_EN      0   ///<触摸按键使能
#endif 

#if KEY_AD_EN  
#define adk_user_pa9
#endif 

#if  0//KEY_IO_EN         ///<IO按键使能
#define support_io_scan_user_PR2               //使用 PR2 扫描按键
#define support_poweroff_wakeup_io_PR2   
#define support_k7036_scna_mode
#define support_690x_ic_rtc_stanby    //IC RTC-待机模式
#define support_power_off_voice           //有关机语音 
#endif 


//#define adk_22k_10key_mode_zy_3053
#define adk_10k_10key_mode_zy_3053

//--------------------------
#define support_bt_key_mode


#define ADK_USE_10KEY_MODE

#ifdef ADK_USE_10KEY_MODE
#define adkey_max_num	10

#define PULL_UP_RESISTANCE 10   //上拉电阻
#define KEY9_RES 0 //pp
#define KEY8_RES 3.3 //mode
#define KEY7_RES 5.1   //v-
#define KEY6_RES 7.5  // v+
#define KEY5_RES 10  //mv-
#define KEY4_RES 15 //mv+
#define KEY3_RES 20 //next
#define KEY2_RES 33 //prve
#define KEY1_RES 56 // menu
#define KEY0_NOKEY_RES 220	 
#endif

//#define adk_user_6_key_mode_and_power
//#define adk_use_22k_6key_mode
#ifdef adk_use_22k_6key_mode
//#define LONG_PP_KEY_AS_FM_SCAN
//#define SUPOORT_LONG_PP_AS_BT_CALL_REJECT
//#define SUPOORT_LONG_MODE_AS_BT_CONNECT_CTL
//#define SUPOORT_LONG_PP_AS_BT_CONNECT_CTL
#endif

//-------IR---------------------------------------

#if KEY_IR_EN         ///<红外遥控使能,PA9
//#define  IR_IO_PA_X     14  // PA14
#define  IR_IO_PB_X     3  // PB3
//#define  IR_IO_PC_X     14  // PC14
//#define  IR_IO_PD_X     14  // PD14

//#define IR_USE_DOUBLE_TY_00FF_807F_22KEY
//#define IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY
//#define  ir_max_num     22
//#define  IR_NUMS     2

//#define IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY
//#define IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_30KEY
#ifdef IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_30KEY
#define  ir_max_num     30
#define IR_NUMS 3
#endif


#define IR_ZY_THREE_GENERAL_YK2119_00FF_IR101_807F_01FE_32KEY
#ifdef IR_ZY_THREE_GENERAL_YK2119_00FF_IR101_807F_01FE_32KEY
#define  ir_max_num     32
#define IR_NUMS 3
#define SUPPORT_MUSIC_FOLDER_OPERATION // folder prev next repeat key
#endif


//#define IR_ZY_GSJ_01FE_45KEY
//#define  ir_max_num     40

#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod 
#endif 

//-------LED---------------------------------------

#define LED_EN                  0       ///<LED指示使能
//#define  PP_LED_USER_PB9
#define  PP_LED_USER_PA3

//-------MUTE---------------------------------------
//MUTE IO 
    #define   PA_ENABLE
#ifdef PA_ENABLE   
//        #define  pa_mute_use_pin_PA11_PA10    // pa_mute_use_pin_PR0 //
        #define  pa_mute_use_pin_PA11// pa_mute_use_pin_PR0 //
//       #define   mute_io_L_is_mute   //  低MUTE   不定义为高MUTE    
      #define support_vol_is_0_mute_amp	//音量到0 MUTE 功放
//      #define support_pause_stop_mute_amp
//      #define  support_bt_pause_mute_amp		  	
//        #define support_xa9901_ab_d_mode
#endif 

//-------AB/D---------------------------------------
//#define support_amP_ab_d
//#define amp_ab_d_user_PB6  





//-------LINE DET---------------------------------------

//LINE INPUT IO SELECT
#define    line_user_PA1PA2  //AUX0 
//#define    line_user_extern  //extern  pt2313


// AUX DETECT SET
#define AUX_DETECT_EN      0
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PA3
    #define  support_line_unline_to_next_mode   //CHANGE_WORKMODE AUX UNLINE TO NEXT MODE
  //  #define AUX_OUT_WITHOUT_CNT  //PLUS OUT DELAY    防抖
#endif 

//-------POWER ON SET ---------------------------------------
//#define  power_on_no_usb_sd_to_bt 
#define  power_on_no_usb_sd_to_line   
//#define  usb_sd_out_to_bt_mode   
#define  usb_sd_out_to_line_mode   



//-------GENERAL  SET----------------------------------
#define SUPPORT_BT_AUTO_PLAY	1  // BT MUSIC AUTO PLAY
#define SUPPORT_OFF_PHONE_CALL   1 // OFF PHONE 
#define SUPPORT_OFF_MODE_VOICE     // OFF MUSIC LINE FM MODE VOICE
#define SUPPORT_REPEAT_ONLY_USE_ONE_ALL
//#define SUPPORT_STORY_MACHINE

//-------fm scan mode set-------------------------------------
//#define  FM_SCAN_MODE_DATA_AMP   



//-------ELSE ---------------------------------------
//#define  support_msg_light_key
#ifdef support_msg_light_key
#define Light_max_mode   2
#define  support_default_light_on
#endif 

#if KEY_TONE_EN
#define  support_vol_max_tone_en  0
#endif 

// 频谱显示
//#define support_led_eq_disp    //支持发光管频谱显示
//#define support_led_eq_user_PA14PA15PC0PC1PC2  
//#define support_led_eq_is_5led_user_k7036    //
//----------------------------------------------



	/* 外置功放IC，话筒IC*/
#define SUPPORT_PT2313
#ifdef SUPPORT_PT2313
//#define PT2313_CLK_DATA_USE_PA15PA14
//#define PT2313_CLK_DATA_USE_PB10PB9
#define PT2313_CLK_DATA_USE_PB12PB10
//#define PT2313_CLK_DATA_USE_PB9PB10

// #define pt2313_use_rf_lf_as_sub

/*
 PIN9-R3 PIN10-R2 PIN11-R1 
 PIN13-L3 PIN14-L2 PIN15-L1 
 0X02 	    0X01 		0X00
 */
 
	
	//配套2313 通道设置
	
#define Aud_SwRadio				0x02		//Stereo 2
#define Aud_SwMP3				0x02		//Stereo 2
#define Aud_SwBt			       0x02		//Stereo 2
#define Aud_SwAUX				0x02		//Stereo 1
#define Aud_SwCD				0x01		//Stereo 1
#define Aud_SwVcd				0x03		//Stereo 3
#define Aud_SwNoting			0x03		//Stereo 4  *



#if 0

#define MAIN_VOL_MAX         60
#define VOLUME_DEFUALT       30
#define SWVOL_DEFUALT        28
#define  FLFR_DEFUALT           28  //这个 值是设 左右喇叭的 起始值  软件内没有减价这个值  如果音量过大可以减小这个值  最大31 
#define BASS_DEFAULT 	7
#define TREBLE_DEFAULT 9

#else
#define MAIN_VOL_MAX         48
#define VOLUME_DEFUALT       23
#define SWVOL_DEFUALT        28
#define  FLFR_DEFUALT           28  //这个 值是设 左右喇叭的 起始值  软件内没有减价这个值  如果音量过大可以减小这个值  最大31 
#define BASS_DEFAULT 	7
#define TREBLE_DEFAULT 10

#define support_main_vol_max_show_48

#endif




#define support_sw_vol_max_show_30
#define support_3053_show_vol_v
	//#define support_mute_key
//#define Support_MSG_RESET
	//#define Support_MSG_MUSIC_STOP
//#define SUPPORT_MSG_FRONT_LEFT
//#define SUPPORT_MSG_FRONT_RIGHT
#define Support_MSG_BASS
#define Support_MSG_TREBLE
#define Support_MSG_SWVOL
#define Support_MSG_MIC_ECO_VOL_KEY
	
	//#define Support_MSG_DSP
	//#define Support_MSG_LOUDNESS
#define SUPPORT_MAIN_VOL_KEY  
#define supper_user_pt2313_ctrl_main_vol
#define support_menu_mode     //多个模式 MENU键切换  用VOL +- 调节
#ifdef support_menu_mode
extern u8 menumode;
#endif

#define supper_bass_treble_max_28
	//#define MENU_NOT_SWTICH_MAIN_VOL
#define LED_TREBLE_SHOW_H
// #define LED_SWVOL_SHOW_b
#define LINE_IN_USE_PT2313
#ifdef support_menu_mode
	enum
	{
		MENU_MAIN_VOL_MODE=0,
		MENU_TREBLE_MODE,		   
		MENU_SWVOLL_MODE,
		MENU_OK_VOL_MODE,
		MENU_ECHO_MODE,
		MENU_MAX_MODE,
		MENU_BASS_MODE,
		MENU_FRONT_LEFT_MODE,
		MENU_FRONT_RIGHT_MODE,
		MENU_SL_MODE, //surround L
		MENU_SR_MODE //surround R
	};
#endif 
	
#endif
	
#define SUPPORT_M62429
#ifdef SUPPORT_M62429
//#define M62429_CLK_DATA_USE_PA4PA3
//#define M62429_CLK_DATA_USE_PB12PB9
#define M62429_CLK_DATA_USE_PB10PB9
//#define support_use_pin1pin2_as_mic_vol
#define KARAOKE_MIC_DEFAULT_VOL		18

//#define MIC_LED_SHOW_MAX 32
#ifdef MIC_LED_SHOW_MAX
#define MIC_LED_SHOW_DEFAULT_VOL 26
#endif
	
//#define MIC_ECHO_LED_SHOW_MAX 32
#ifdef MIC_ECHO_LED_SHOW_MAX
#define MIC_ECHO_LED_SHOW_DEFAULT 26
#endif
	
#endif
	
#define SUPPORT_ENCODER
#ifdef SUPPORT_ENCODER
#define ENCODE_PIN_USE_PA4PB11
#endif


//#define  SUPPORT_MULTI_INPUT_MODE
#ifdef SUPPORT_MULTI_INPUT_MODE
extern u8 bMultiExternInputSel;
//#define   line2_user_PA3PA4  //AUX1
#define   lineI_user_PAaPA2 //AUX1
#define   SUPPOR_INPUT_AUX1  //AUX1
//#define  SUPPORT_AUX1_SHOW_DVD
//#define    SUPPOR_INPUT_AUX2  //AUX2
//#define    SUPPOR_MP3_NOP_IN_AUX_MODE
enum
{
    INPUT_AUX0_MODE=0,
    INPUT_AUX1_MODE,
    INPUT_MAX_MODE,
    INPUT_AUX2_MODE,
    INPUT_NOP_MODE,
};

#endif

#define SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE //no device but want to under at mp3 mode
#ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
enum{
	mode_aux=0,
	mode_ac3,
	mode_linein_max,
	mode_dvd,
	mode_mp3_nodevice,
	mode_cd,
}MODE_IN_LINEIN;
#define LINEIN_MULTIPLY_DEFAULT_MODE 0
//#define SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
#define SUPPORT_AC3_MODE_IN_LINEIN_MODE
//#define SUPPORT_CD_MODE_IN_LINEIN_MODE
#define SUPPORT_DVD_MODE_IN_LINEIN_MODE
//#define support_ac3_show_OPTI_CHAR
#define support_ac3_show_AUX
#define MODE_KEY_MP3_PREV_MODE "BtStackTask"
#define MODE_KEY_MP3_NEXT_MODE "LineinTask"
#endif




