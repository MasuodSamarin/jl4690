

/*
GPIO SET:
	LED7-TY IO	PA10-AMP_POWER PA11-MUTE
	AUX0-PA1PA2		PB11-BAT_DET		PB12-POWER_IO	PB3-IR	PB10-LED1
	PB9-ADKEY	PA9-MIC_ONOFF
	SD1-PB0_DAT_PB1_CMD_PB2_CLK	
	
1°¢ø™ª˙ ±LOW-V(41)Ω≈ ‰≥ˆ∏ﬂµÁ∆Ω
	POWER(26)Ω≈ ‰≥ˆ∏ﬂµÁ∆Ω°£
	MUTE(25)Ω≈ ‰≥ˆ∏ﬂµÁ∆Ω£¨1√Î∫Û ‰≥ˆµÕµÁ∆Ω
2°¢µ±ºÏ≤‚µÁ—πµÕ”⁄1.90V ±°£
LED∆¡…¡∂Ø5√Î∫Û
LOW-V(41)Ω≈ ‰≥ˆµÕµÁ∆Ω°£
POWER(26)Ω≈ ‰≥ˆµÕµÁ∆Ω
MUTE(25)Ω≈ ‰≥ˆ∏ﬂµÁ∆Ω
3°¢∞¥“£øÿMUTE/‘›Õ£º¸ ±,Õ‚≤øMUTEΩ≈≤ª±‰£®ƒ⁄≤øæ≤“Ù£©
4°¢∞¥“£øÿµÁ‘¥º¸πÿª˙ ±,MUTEΩ≈ ‰≥ˆ∏ﬂµÁ∆Ω£¨
LOW-V/POWERΩ≈≤ª±‰°£
“ÚŒ™MUTEΩ≈ «øÿ÷∆π¶∑≈ICæ≤“Ùµƒ°£
5 °¢BTJCµÁ¡øºÏ≤‚Ω≈Àµ√˜£∫
µ±µÁ¡øºÏ≤‚Ω≈ «1.9V ±£¨œ‘ æ∆¡µÁ¡øµ⁄“ª∏Ò…¡∂Ø
µ±µÁ¡øºÏ≤‚Ω≈ «2.1V ±£¨œ‘ æ∆¡µÁ¡øµ⁄“ª∏Ò≥£¡¡
µ±µÁ¡øºÏ≤‚Ω≈ «2.3V ±£¨œ‘ æ∆¡µÁ¡øµ⁄∂˛∏Ò≥£¡¡
µ±µÁ¡øºÏ≤‚Ω≈ «2.5V ±£¨œ‘ æ∆¡µÁ¡øµ⁄»˝∏Ò≥£¡¡
6 °¢27Ω≈Ω”ª∞Õ≤”≈œ»£∫
1°¢µ±41Ω≈ºÏ≤‚µÁ—πµÕµÁ∆Ω ±£¨“Ù¿÷“Ù¡øºıµΩ15º∂°£
2°¢µ±41Ω≈ª÷∏¥∏ﬂµÁ∆Ω ±£¨“Ù¿÷“Ù¡ø–¯º∂º”µΩ◊Ó¥Û°
£
*/


/*
*********************************************************************
                        DEBUG MACRO
*********************************************************************
*/

//#define __DEBUG         ////<ø™∆ÙœµÕ≥¥Ú”°µ˜ ‘π¶ƒ‹

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



#define EQ_EN			        1       ///<EQƒ£øÈø™πÿ
#define EQ_UART_BDG	    		0       ///<EQ uart online dbg switch
#define DAC_SOUNDTRACK_COMPOUND 0       ///<dac…˘µ¿∫œ≤¢
#define DAC_AUTO_MUTE_EN		1       ///<◊‘∂Ømute
#define SYS_LVD_EN              1       ///<µÁ¡øº‡≤‚
#define KEY_TONE_EN     	    1       ///<∞¥º¸“Ù
#define UART_UPDATA_EN          0      ///<¥Æø⁄…˝º∂
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<∞¥º¸À´ª˜π¶ƒ‹
#endif

//=================================================
// 1-VOL SET JSUO
#define SYS_DEFAULT_VOL        30      ///<∑«0±Ì æ π”√ƒ¨»œ“Ù¡ø
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
    #define VCOMO_EN 	1	// «∑Ò—°‘ÒVCMO÷±Õ∆∂˙ª˙
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#else
    #define VCOMO_EN 	0	// «∑Ò—°‘ÒVCMO÷±Õ∆∂˙ª˙
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#endif


/*
*********************************************************************
                        APP MACRO
*********************************************************************
*/

  #define SUPPORT_APP_RCSP_EN         0   ///<±Í◊ºSDK£¨ ÷ª˙app π¶ƒ‹‘› ±≤ª÷ß≥÷

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

#define BT_ANALOG_CFG   0//ƒ£ƒ‚≈‰÷√
#define BT_XOSC         0//

#define BT_BACKMODE         0             ///<¿∂—¿∫ÛÃ®


#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID≈ƒ’’µƒ∂¿¡¢ƒ£ Ω÷ª÷ß≥÷∑«∫ÛÃ®
#endif

#define BT_PHONE_NUMBER                    0          ///<¿¥µÁ±®∫≈
#if EARPHONE_MODE_EN
	#define AUTO_SHUT_DOWN_TIME 3*2*60          ///¿∂—¿Œﬁ¡¨Ω”◊‘∂Øπÿª˙º∆ ±£¨u16¿‡–Õ£¨0±Ì æ≤ª◊‘∂Øπÿª˙
#else
	#define AUTO_SHUT_DOWN_TIME 0          ///¿∂—¿Œﬁ¡¨Ω”◊‘∂Øπÿª˙º∆ ±£¨u16¿‡–Õ£¨0±Ì æ≤ª◊‘∂Øπÿª˙
#endif

/*
*********************************************************************
                       µÁ‘¥…Ë÷√ 
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
                       µÕπ¶∫ƒ…Ë÷√ 
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

#define D2SH_DIS_SW         0          //d2sh dis sw  rtcvddø⁄√ª”–¿≠≥ˆ¿¥“™÷√1
#define BLE_BREDR_MODE      BT_BREDR_EN


/*
*********************************************************************
                       –æ∆¨∑‚◊∞≈‰÷√ 
*********************************************************************
*/

#define RTCVDD_TYPE              0          //RTCVDDø⁄√ª”–∞Û≥ˆ¿¥“™÷√1,ƒø«∞∂‘”¶∑‚◊∞–æ∆¨AC6905
#define BTAVDD_TYPE              0          //BTAVDD√ª”–∞Û≥ˆ¿¥“™÷√1 £¨ƒø«∞∂‘”¶∑‚◊∞–æ∆¨AC6907A,AC6908A

/*
*********************************************************************
    MUSIC MACRO
*********************************************************************
*/
#define MUSIC_DECRYPT_EN 		0	//SMPº”√‹Œƒº˛÷ß≥÷
#define MUSIC_AB_RPT_EN 		1	//AB∂œµ„÷ß≥÷


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
    #define FM_RADIO_EN         1       ///<±Í◊ºSDK
#endif

#if FM_RADIO_EN
    #define RDA5807                 0       ///<RDA5807FM
    #define BK1080                  0       ///<BK1080FM
    #define QN8035                  0       ///<QN8035FM
    #define FM_INSIDE               1       ///<–æ∆¨ƒ⁄≤øFM
#endif

/*
*********************************************************************
                        RTC MACRO
*********************************************************************
*/
  #define RTC_CLK_EN          0       ///<±Í◊ºSDK RTC ±÷”ƒ£ Ω

#if RTC_CLK_EN
    #define RTC_ALM_EN          1       ///<RTCƒ÷÷”ƒ£ Ω
    #define RTC_CLK_CHECK_EN    0       ///<RTCæß’ÒºÏ≤‚
#endif

/*
*********************************************************************
                        ECHO MACRO
*********************************************************************
*/
  #define ECHO_EN                      0       ///<ªÏœÏπ¶ƒ‹ ±Í◊ºSDK
  #define ECHO_TASK_EN        0       ///<ªÏœÏƒ£ Ω ±Í◊ºSDK

/*
*********************************************************************
                        REC MACRO
*********************************************************************
*/
// 4- REC EN	JSUO

    #define REC_EN             1   ///<±Í◊ºSDK¬º“Ùπ¶ƒ‹

#if REC_EN

#define support_rec_stop_to_music
#define support_only_rec_key_to_rec_mode
#define support_music_key_mode
#define SUPPORT_RECPLAY_STATE

#define SUPPORT_REC_SHOW_TIME_BUG // SDK  NO SHOWTIME

//#define support_off_mode_change_voice
//#define support_fm_key_mode
//#define support_bt_key_mode
//#define support_line_key_mode

extern u16 rec_file_startcnt;
extern u16 rec_file_endcnt;
extern bool  muisc_to_rec_flag;
#ifdef support_rec_line_fm_rec_return_line_fm
extern u8   play_rec_last_file;   
#else 
extern  bool  play_rec_last_file;   
#endif 
#endif


#if 0 //SUPPORT_APP_RCSP_EN
    #undef  REC_EN
    #define REC_EN         0         ///< ÷ª˙APPƒ£ Ω≤ª÷ß≥÷¬º“Ù
#endif

#if REC_EN
	#define BT_REC_EN		0       ///<¿∂—¿¬º“Ù πƒ‹
	#define MIC_REC_EN		1       ///<MIC¬º“Ù πƒ‹
	#define FM_REC_EN		0       ///<FM¬º“Ù πƒ‹
	#define AUX_REC_EN		0       ///<AUX¬º“Ù πƒ‹
#endif


/*
*********************************************************************
                        UI MACRO
*********************************************************************
*/

// 5- UI	EN	JSUO

   #define UI_ENABLE                1     ///<UI_œ‘ æ
 

#if  UI_ENABLE
    ///∂˛—°“ª
    #define LCD_128X64_EN         0      ///<lcd ÷ß≥÷
    #define LED_7_EN                       1      ///<led ÷ß≥÷     
    #define LCD_SUPPORT_MENU     0       ///≤Àµ•œ‘ æ
    #define LRC_LYRICS_EN                 0       ///LRC∏Ë¥ œ‘ æ


#define support_led7_user_pc0pa14pa15pc1pc2pc3pc4
#define LED_7PIN_MODE
//#define LED_7PIN_REVERSE
	
#define LED_ID_88N45
#ifdef LED_ID_88N45
#define LED_COM_MAX 7
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 10
#endif

#define SUPPORT_FLASH_ICON
#define SUPPORT_FLASH_CHAR

#define SUPPORT_BT_LED_PRORAM


#ifdef SUPPORT_FLASH_CHAR
#define SUPPORT_LED_BLUE_STRING_FLASH
#define SUPPORT_MUTE_FLASH
//#define MUTE_FLASH_ZERO_VOL
#endif
#define SUPPORT_EQ_SHOW_CHAR

//#define support_aux_led_disp_line     //∆¡…œœ‘ æ"LINE"
#define support_led_disp_pause
#define support_mute_led_all_flish    //MUTE…¡∆¡
#define SUPPORT_NO_SHOW_LOAD	
 #endif 


//*********************************************************************
 

//-------ADKEY--------------------------------------------------------


#define muteh_key_mode   1

#if muteh_key_mode
#define KEY_AD_EN       1   ///<AD∞¥º¸ πƒ‹
#define KEY_IO_EN       0   ///<IO∞¥º¸ πƒ‹
#define KEY_IR_EN       1   ///<∫ÏÕ‚“£øÿ πƒ‹,PA9
#define KEY_TCH_EN      0   ///<¥•√˛∞¥º¸ πƒ‹
#endif 

#if KEY_AD_EN  
//#define adk_user_pa9
#define adk_user_pb9
#endif 

#if  0//KEY_IO_EN         ///<IO∞¥º¸ πƒ‹
#define support_io_scan_user_PR2               // π”√ PR2 …®√Ë∞¥º¸
#define support_poweroff_wakeup_io_PR2   
#define support_k7036_scna_mode
#define support_690x_ic_rtc_stanby    //IC RTC-¥˝ª˙ƒ£ Ω
#define support_power_off_voice           //”–πÿª˙”Ô“Ù 
#endif 

// 7k5-bt
#define adk_10k_15key_mode_zy_2rec_mic

//--------------------------
#define support_bt_key_mode


#define ADK_USE_15KEY_MODE

#ifdef ADK_USE_15KEY_MODE
#define adkey_max_num	15

#define PULL_UP_RESISTANCE 10   //…œ¿≠µÁ◊Ë
#define KEYE_RES 0  //PP
#define KEYD_RES 1 	 //REC/RECPLAY
#define KEYC_RES 2  	 // 
#define KEYB_RES 3.3 //mode		0.8
#define KEYA_RES 4.7  //null  		1v
#define KEY9_RES 5.6 //null		1.2
#define KEY8_RES 7.5 //bt  		1.4
#define KEY7_RES 10   //repeat		1.65
#define KEY6_RES 12  // 			1.8
#define KEY5_RES 15  //eq			2.0
#define KEY4_RES 20 //next/v+		2.2	
#define KEY3_RES 33 //prev/v-		2.5
#define KEY2_RES 56 //standby		2.8
#define KEY1_RES 68 // mute		2.87
#define KEY0_NOKEY_RES 100	 //stop	 3v
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

#if KEY_IR_EN         ///<∫ÏÕ‚“£øÿ πƒ‹,PA9
//#define  IR_IO_PA_X     14  // PA14
#define  IR_IO_PB_X     3  // PB3
//#define  IR_IO_PC_X     14  // PC14
//#define  IR_IO_PD_X     14  // PD14

//#define IR_USE_DOUBLE_TY_00FF_807F_22KEY
//#define IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY
//#define  ir_max_num     22
//#define  IR_NUMS     2

#define IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY
#define  ir_max_num     25
#define IR_NUMS 3

#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod 

#endif 

//-------LED---------------------------------------

#define LED_EN                  1       ///<LED÷∏ æ πƒ‹
//#define  PP_LED_USER_PB9
#define  PP_LED_USER_PB10

//-------MUTE---------------------------------------
//MUTE IO 
//    #define   PA_ENABLE
#ifdef PA_ENABLE   
//        #define  pa_mute_use_pin_PA11_PA10    // pa_mute_use_pin_PR0 //
        #define  pa_mute_use_pin_PA11// pa_mute_use_pin_PR0 //
//       #define   mute_io_L_is_mute   //  µÕMUTE   ≤ª∂®“ÂŒ™∏ﬂMUTE    
      #define support_vol_is_0_mute_amp	//“Ù¡øµΩ0 MUTE π¶∑≈
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


// AUX DETECT SET
#define AUX_DETECT_EN      0
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PA3
    #define  support_line_unline_to_next_mode   //CHANGE_WORKMODE AUX UNLINE TO NEXT MODE
  //  #define AUX_OUT_WITHOUT_CNT  //PLUS OUT DELAY    ∑¿∂∂
#endif 

//#define  SUPPORT_MULTI_INPUT_MODE
#ifdef SUPPORT_MULTI_INPUT_MODE
extern u8 bMultiExternInputSel;
#define    line2_user_PA3PA4  //AUX1
#define    SUPPOR_INPUT_AUX1  //AUX1\
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


//-------ELSE ---------------------------------------
//#define  support_msg_light_key
#ifdef support_msg_light_key
#define Light_max_mode   2
#define  support_default_light_on
#endif 

#if KEY_TONE_EN
#define  support_vol_max_tone_en  0
#endif 

// ∆µ∆◊œ‘ æ
//#define support_led_eq_disp    //÷ß≥÷∑¢π‚π‹∆µ∆◊œ‘ æ
//#define support_led_eq_user_PA14PA15PC0PC1PC2  
//#define support_led_eq_is_5led_user_k7036    //
//----------------------------------------------

#define MEDIA_MODE_USB_SD_DETECT 0
#if  MEDIA_MODE_USB_SD_DETECT	
u32 curr_device_using;
#endif

//---FM  STATION  ADJUST-------------------------
#define FM_SCAN_MODE_ZY_DATA_AMP

//----------------------------------------------

//MICºÏ≤‚
#define MIC_CHECK_ENABLE	1
#if MIC_CHECK_ENABLE
 #define MIC_ONOFF_KEY	1
// #define  support_mic_check_user_PB11
 #define  support_mic_check_user_PA9
//#define   KOK_DETECT_USE_IO_ADC_VALUE
// #define  support_on_io_dn_10k
// #define  support_high_mic_in
//#define MIC_CHECK_OFF_DELAY_TIME  
#define MIC_CHECK_TIMER  20


#define KOK_DETECT_AUTO_VOL_SET
#define AUTO_VOL_SET_DEC  15

#define SUPPORT_MIC_ONOFF_SHOW  
#ifdef SUPPORT_MIC_ONOFF_SHOW
extern u8 bLedShowOnoffTimer;
#endif
//  #define support_high_mic_in 
extern bool mic_sw;  // 0-off  1-on
 extern bool auto_vol_sw; // 0 off   1 on
 extern  u8 store_vol; // 
 extern  u8 bPowerOnAmpMuteTimer; // 

#endif 


//----------------------------------------------
	
//*****BAT DETECT *****//
 #define SUPPORT_BAT_DETECT
#ifdef SUPPORT_BAT_DETECT
#define SUPPORT_BAT_DETECT_USE_IO
#define DETECT_EXTERNAL_BAT_USE_PB11
#define LED_SCREEN_SHOW_BAT_STATUS

//#define SUPPORT_BAT_DETECT_LOW_POWER_MODE_1
#define SUPPORT_BAT_DETECT_LOW_POWER_MODE_2


#define SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
#ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
#define LOW_POWER_OFF_USE_EXTERN_IO_PB12
//#define SUPPORT_LOW_POWER_LED_SHOW_BAT_FLASH
#define SUPPORT_LOW_POWER_USE_LED_SHOW
#define SUPPORT_LOW_POWER_LED_ALL_SCREEN_FLASH
#define SUPPORT_LOW_POWER_DISABLE_MUTE_KEY
#define LOW_POER_VOLTOGE_VAL   19
extern u16 low_off_cnt;
extern volatile u8 low_power_flag;
#endif

//-----------AMP POWER ON OFF------------------------------------
#define   AMP_POWER_ENABLE
#ifdef AMP_POWER_ENABLE   
        #define  AMP_POWER_IO_PA10
#endif 
//---------POWER ON  MUTE 1S  AND LOW POWER MUTE 5S--------------------
#define   AMP_MUTE_ENABLE
#ifdef AMP_MUTE_ENABLE   
#define  AMP_POWER_ON_MUTE_TIMER  3
#define  AMP_MUTE_IO_PA11
#endif 

#define  SUPPORT_LOW_POWER_DELAY_DET
#define  POWER_ON_LOW_POWER_DELAY_VAL	16

#endif


