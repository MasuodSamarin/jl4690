

/*
GPIO SET:
	ADKEY-PB9	IR-PC5 	LED-PC4	
	AUX-DACR		MIC-PB13	
	SD0-PB10_DAT_PB11_CMD_PB12_CLK	

*/



/*
*********************************************************************
                        DEBUG MACRO
*********************************************************************
*/

//  #define __DEBUG         ////<����ϵͳ��ӡ���Թ���

/*
*********************************************************************
                        APPLICATION FUNCTION
*********************************************************************
*/
#define AC6905A_OFF_IO  // JSUO ADD  20161114


#define EARPHONE_MODE_EN    0

/*
*********************************************************************
                        COMMON MACRO
*********************************************************************
*/



#define EQ_EN			        1       ///<EQģ�鿪��
#define EQ_UART_BDG	    		0       ///<EQ uart online dbg switch
#ifdef AC6905A_OFF_IO
#define DAC_SOUNDTRACK_COMPOUND 1       ///<dac�����ϲ�
#else
#define DAC_SOUNDTRACK_COMPOUND 0       ///<dac�����ϲ�
#endif
#define DAC_AUTO_MUTE_EN		1       ///<�Զ�mute
#define SYS_LVD_EN              0       ///<�������
#define KEY_TONE_EN     	    1       ///<������
#define UART_UPDATA_EN          0      ///<��������
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<����˫������
#endif

//=================================================
// 1-VOL SET JSUO
#define SYS_DEFAULT_VOL        30      ///<��0��ʾʹ��Ĭ������
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

    #define SDMMC0_EN       1
    #define SDMMC1_EN       0
    #define USB_DISK_EN     1
    #define USB_PC_EN        1



#if EARPHONE_MODE_EN
    #define VCOMO_EN 	1	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#else
    #define VCOMO_EN 	0	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT DAC_L_CHANNEL // DAC_L_R_CHANNEL
#endif


/*
*********************************************************************
                        APP MACRO
*********************************************************************
*/

  #define SUPPORT_APP_RCSP_EN         0   ///<��׼SDK���ֻ�app ������ʱ��֧��

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

#define BT_ANALOG_CFG   0//ģ������
#define BT_XOSC         0//

#define BT_BACKMODE         0             ///<������̨


#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID���յĶ���ģʽֻ֧�ַǺ�̨
#endif

#define BT_PHONE_NUMBER                    0          ///<���籨��
#if EARPHONE_MODE_EN
	#define AUTO_SHUT_DOWN_TIME 3*2*60          ///�����������Զ��ػ���ʱ��u16���ͣ�0��ʾ���Զ��ػ�
#else
	#define AUTO_SHUT_DOWN_TIME 0          ///�����������Զ��ػ���ʱ��u16���ͣ�0��ʾ���Զ��ػ�
#endif

/*
*********************************************************************
                       ��Դ���� 
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
                       �͹������� 
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

#define D2SH_DIS_SW         0          //d2sh dis sw  rtcvdd��û��������Ҫ��1
#define BLE_BREDR_MODE      BT_BREDR_EN


/*
*********************************************************************
                       оƬ��װ���� 
*********************************************************************
*/

#define RTCVDD_TYPE              1          //RTCVDD��û�а����Ҫ��1,Ŀǰ��Ӧ��װоƬAC6905
#define BTAVDD_TYPE              0          //BTAVDDû�а����Ҫ��1 ��Ŀǰ��Ӧ��װоƬAC6907A,AC6908A

/*
*********************************************************************
    MUSIC MACRO
*********************************************************************
*/
#define MUSIC_DECRYPT_EN 		0	//SMP�����ļ�֧��
#define MUSIC_AB_RPT_EN 		1	//AB�ϵ�֧��


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
    #define FM_RADIO_EN         1       ///<��׼SDK
#endif

#if FM_RADIO_EN
    #define RDA5807                 0       ///<RDA5807FM
    #define BK1080                  0       ///<BK1080FM
    #define QN8035                  0       ///<QN8035FM
    #define FM_INSIDE               1       ///<оƬ�ڲ�FM
#endif

/*
*********************************************************************
                        RTC MACRO
*********************************************************************
*/
  #define RTC_CLK_EN          0       ///<��׼SDK RTCʱ��ģʽ

#if RTC_CLK_EN
    #define RTC_ALM_EN          1       ///<RTC����ģʽ
    #define RTC_CLK_CHECK_EN    0       ///<RTC������
#endif

/*
*********************************************************************
                        ECHO MACRO
*********************************************************************
*/
  #define ECHO_EN                      0       ///<���칦�� ��׼SDK
  #define ECHO_TASK_EN        0       ///<����ģʽ ��׼SDK

/*
*********************************************************************
                        REC MACRO
*********************************************************************
*/
// 4- REC EN	JSUO

    #define REC_EN             1   ///<��׼SDK¼������

#if REC_EN

#define support_rec_stop_to_music
#define support_only_rec_key_to_rec_mode
#define support_music_key_mode
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
    #define REC_EN         0         ///<�ֻ�APPģʽ��֧��¼��
#endif

#if REC_EN
	#define BT_REC_EN		0       ///<����¼��ʹ��
	#define MIC_REC_EN		1       ///<MIC¼��ʹ��
	#define FM_REC_EN		0       ///<FM¼��ʹ��
	#define AUX_REC_EN		0       ///<AUX¼��ʹ��
#endif


/*
*********************************************************************
                        UI MACRO
*********************************************************************
*/

// 5- UI	EN	JSUO
#define SUPPORT_NO_USE_PANEL

#define UI_ENABLE                1     ///<UI_��ʾ
 

#if  UI_ENABLE
    ///��ѡһ
    #define LCD_128X64_EN         0      ///<lcd ֧��
    #define LED_7_EN                       1      ///<led ֧��     
    #define LCD_SUPPORT_MENU     0       ///�˵���ʾ
    #define LRC_LYRICS_EN                 0       ///LRC�����ʾ


#define support_led7_user_pc0pa14pa15pc1pc2pc3pc4
#define LED_7PIN_MODE
#define LED_7PIN_REVERSE
	
#define LED_ID_4018N_2
#ifdef LED_ID_4018N_2
#define LED_COM_MAX 7
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 7
#endif

#define SUPPORT_FLASH_ICON
#define SUPPORT_FLASH_CHAR

#define SUPPORT_BT_LED_PRORAM


#ifdef SUPPORT_FLASH_CHAR
#define SUPPORT_LED_BLUE_STRING_FLASH
#define SUPPORT_MUTE_FLASH
//#define MUTE_FLASH_ZERO_VOL
#endif

#define support_aux_led_disp_line     //������ʾ"LINE"
#define support_led_disp_pause
#define support_mute_led_all_flish    //MUTE����
#define SUPPORT_NO_SHOW_LOAD	
 #endif 


//*********************************************************************
 

//-------ADKEY--------------------------------------------------------


#define muteh_key_mode   1

#if muteh_key_mode
#define KEY_AD_EN       1   ///<AD����ʹ��
#define KEY_IO_EN       0   ///<IO����ʹ��
#define KEY_IR_EN       1   ///<����ң��ʹ��,PA9
#define KEY_TCH_EN      0   ///<��������ʹ��
#endif 

#if KEY_AD_EN  
#define adk_user_pb9
#endif 

#if  0//KEY_IO_EN         ///<IO����ʹ��
#define support_io_scan_user_PR2               //ʹ�� PR2 ɨ�谴��
#define support_poweroff_wakeup_io_PR2   
#define support_k7036_scna_mode
#define support_690x_ic_rtc_stanby    //IC RTC-����ģʽ
#define support_power_off_voice           //�йػ����� 
#endif 

//#define adk_user_6_key_mode_and_power
//#define adk_use_22k_6key_mode
#define adk_use_2k7_13key_mode_ty_kok

#define ADK_USE_15KEY_MODE

//#define ADK_USE_10KEY_MODE
#ifdef ADK_USE_15KEY_MODE
#define adkey_max_num	15
#define PULL_UP_RESISTANCE 2.7   //��������10K
#define KEYE_RES 0  //PP
#define KEYD_RES 0.22 // MIC		
#define KEYC_RES 0.47 	 // PREV
#define KEYB_RES 0.68  	 // FM
#define KEYA_RES 1 		// NEXT	
#define KEY9_RES  1.5  // REC
#define KEY8_RES 2.4 // EQ	
#define KEY7_RES 3.3 // NEXT/V+		
#define KEY6_RES 4.7   // PREV/V-	
#define KEY5_RES 5.6  // 	MODE
#define KEY4_RES 10  //  STOP	
#define KEY3_RES 15 // REPEAT	
#define KEY2_RES 21 //  	
#define KEY1_RES 22 // 			
#define KEY0_NOKEY_RES 24	 //	
#endif
#ifdef adk_use_22k_6key_mode
//#define LONG_PP_KEY_AS_FM_SCAN
//#define SUPOORT_LONG_PP_AS_BT_CALL_REJECT
//#define SUPOORT_LONG_MODE_AS_BT_CONNECT_CTL
//#define SUPOORT_LONG_PP_AS_BT_CONNECT_CTL
#endif


//-------IR---------------------------------------

#if KEY_IR_EN         ///<����ң��ʹ��,PA9
//#define  IR_IO_PA_X     14  // PA14
//#define  IR_IO_PB_X     3  // PB3
#define  IR_IO_PC_X     5  // PC5
//#define  IR_IO_PD_X     14  // PD14

#define IR_TY_THREE_GENERAL_FF00_7F00_7F80_30KEY_REC

#ifdef IR_TY_THREE_GENERAL_FF00_7F00_7F80_30KEY_REC
#define  ir_max_num  30
#define IR_NUMS 3	
//-------------------------------------------
#define support_100add_is_10add
#define support_fm_key_mode
#define support_music_key_mode
#define support_bt_key_mode
#define support_line_key_mode
#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod
//-------------------------------------------

#endif



#endif 



//-------LED---------------------------------------

#define LED_EN                  1       ///<LEDָʾʹ��
#define  PP_LED_USER_PC4


//-------MUTE---------------------------------------
//MUTE IO 
//    #define   PA_ENABLE
#ifdef PA_ENABLE   
//        #define  pa_mute_use_pin_PA11_PA10    // pa_mute_use_pin_PR0 //
        #define  pa_mute_use_pin_PA11// pa_mute_use_pin_PR0 //
//       #define   mute_io_L_is_mute   //  ��MUTE   ������Ϊ��MUTE    
      #define support_vol_is_0_mute_amp	//������0 MUTE ����
//      #define support_pause_stop_mute_amp
//      #define  support_bt_pause_mute_amp		  	
//        #define support_xa9901_ab_d_mode
#endif 

//-------AB/D---------------------------------------
//#define support_amP_ab_d
//#define amp_ab_d_user_PB6  





//-------LINE DET---------------------------------------

//LINE INPUT IO SELECT
//#define    line_user_PA1PA2  //AUX0 
#define    line_user_dacr  //DACR

// AUX DETECT SET
#define AUX_DETECT_EN      0
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PA3
    #define  support_line_unline_to_next_mode   //CHANGE_WORKMODE AUX UNLINE TO NEXT MODE
  //  #define AUX_OUT_WITHOUT_CNT  //PLUS OUT DELAY    ����
#endif 

//-------POWER ON SET ---------------------------------------
//#define  power_on_no_usb_sd_to_bt 
#define  power_on_no_usb_sd_to_line   
//#define  usb_sd_out_to_bt_mode   
#define  usb_sd_out_to_line_mode   




//-------GENERAL  SET----------------------------------
#define SUPPORT_BT_AUTO_PLAY	1  // BT MUSIC AUTO PLAY
#define SUPPORT_OFF_PHONE_CALL   1 // OFF PHONE 
//#define SUPPORT_OFF_MODE_VOICE     // OFF MUSIC LINE FM MODE VOICE
#define SUPPORT_REPEAT_ONLY_USE_ONE_ALL



//-------fm scan mode set-------------------------------------
#define  FM_SCAN_MODE_DATA_AMP   
// #define  FM_SCAN_MODE_1



//-------ELSE ---------------------------------------
//#define  support_msg_light_key
#ifdef support_msg_light_key
#define Light_max_mode   2
#define  support_default_light_on
#endif 

#if KEY_TONE_EN
#define  support_vol_max_tone_en  0
#endif 

// Ƶ����ʾ
//#define support_led_eq_disp    //֧�ַ����Ƶ����ʾ
//#define support_led_eq_user_PA14PA15PC0PC1PC2  
//#define support_led_eq_is_5led_user_k7036    //
//----------------------------------------------


//============================================
#define SUPPORT_ALL_VOICE	1
#if  SUPPORT_ALL_VOICE
#define SUPPORT_FM_OPTION_VOICE 0 // PREV NEXT SEARCH SEARCH_END vol+- mute v_on v_off
#define SUPPORT_LINE_OPTION_VOICE 0 // PREV NEXT SEARCH SEARCH_END vol+- mute v_on v_off
#define SUPPORT_TY_VOICE 	1 // BT_MUSIC(PREV NEXT PLAY PAUSE    repeatone MICON MICOFF ) 
#define SUPPORT_VOICE_NUMBER 0
#define SUPPORT_MIC_ONOFF_VOICE
//#define SUPPORT_POWER_ON_TONE
#if defined SUPPORT_POWER_ON_TONE
bool  bPowerOnVoiceFlag;
#endif

extern u8 IsVoiceEnable;	
extern u8 bVoiceNumber;
#define LINEIN_PROMPT_EN
#define BT_PROMPT_EN
#define FM_PROMPT_EN
#define POWER_ON_VOICE_DEFAULT	1  //0-OFF  1-ON
#define SUPPORT_MUSIC_PREV_NEXT_VOICE
extern bool prompt_played,music_prompt_stopped;
#define MEDIA_MODE_USB_SD_DETECT 1
#if  MEDIA_MODE_USB_SD_DETECT	
u32 curr_device_using;
#endif
#define SUPPORT_RECPLAY_VOICE  // 21061213 add
#else 
#define MEDIA_MODE_USB_SD_DETECT 1
#if  MEDIA_MODE_USB_SD_DETECT	
u32 curr_device_using;
#endif

#endif 


//============================================

//MIC���
#define MIC_CHECK_ENABLE	1
#if MIC_CHECK_ENABLE
 #define MIC_ONOFF_KEY	1
// #define  support_mic_check_user_PA14
 #define  support_mic_check_user_PB9
#define   KOK_DETECT_USE_IO_ADC_VALUE
#define   KOK_DETECT_USE_ADKEY_AS_DET
#define MIC_CHECK_OFF_DELAY_TIME  

#define MIC_CHECK_TIMER  10

#define MIC_CHECK_OUT_VOL_X_STEP  // mic set  sys vol is 1.

//  #define support_high_mic_in 
extern bool mic_sw;  // 0-off  1-on

#endif 


//============================================

