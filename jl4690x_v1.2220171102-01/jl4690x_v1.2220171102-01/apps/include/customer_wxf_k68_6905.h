

/*
*********************************************************************
                        DEBUG MACRO
*********************************************************************
*/
//#define __DEBUG         ////<����ϵͳ��ӡ���Թ���


/*
*********************************************************************
                        APPLICATION FUNCTION
*********************************************************************
*/

#define EARPHONE_MODE_EN    0



#if EARPHONE_MODE_EN
    #define VCOMO_EN 	1	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#else
    #define VCOMO_EN 	0	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#endif


/*
*********************************************************************
                        COMMON MACRO
*********************************************************************
*/
#define EQ_EN			        0       ///<EQģ�鿪��
#define EQ_UART_BDG	    		0       ///<EQ uart online dbg switch
#define DAC_SOUNDTRACK_COMPOUND 0       ///<dac�����ϲ�
#define DAC_AUTO_MUTE_EN		1       ///<�Զ�mute
#define SYS_LVD_EN              1       ///<�������
#define KEY_TONE_EN     	    1       ///<������
#define UART_UPDATA_EN         0    ///<��������
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<����˫������
#endif


#define SYS_DEFAULT_VOL        30      ///<��0��ʾʹ��Ĭ������


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

#define BT_BACKMODE         0            ///<������̨


#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID���յĶ���ģʽֻ֧�ַǺ�̨
#endif

#define BT_PHONE_NUMBER                    1          ///<���籨��
#define AUTO_SHUT_DOWN_TIME         0          ///�����������Զ��ػ���ʱ��u16���ͣ�0��ʾ���Զ��ػ�

/*
*********************************************************************
                       ��Դ���� 
*********************************************************************
*/
#define    PWR_NO_CHANGE     0     //   0:  no change   
#define    PWR_LDO33         1     //   1:  LDOIN 5v -> VDDIO 3.3v -> DVDD 1.2v
#define    PWR_LDO15         2     //   2:  LDOIN 5v -> LDO   1.5v -> DVDD 1.2v, support bluetooth
#define    PWR_DCDC15        3     //   3:  LDOIN 5v -> DCDC  1.5v -> DVDD 1.2v, support bluetooth


#define PWR_MODE_SELECT    PWR_LDO15

/*
*********************************************************************
                       �͹������� 
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
                       оƬ��װ���� 
*********************************************************************
*/
#define RTCVDD_TYPE              0          //RTCVDD��û�а����Ҫ��1,Ŀǰ��Ӧ��װоƬAC6905
#define BTAVDD_TYPE              0          //BTAVDDû�а����Ҫ��1 ��Ŀǰ��Ӧ��װоƬAC6907A,AC6908A


/*
*********************************************************************
                        MUSIC MACRO
*********************************************************************
*/
#define MUSIC_DECRYPT_EN 		0	//SMP�����ļ�֧��
#define MUSIC_AB_RPT_EN 		0	//AB�ϵ�֧��


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
    #define REC_EN             0   ///<��׼SDK¼������


#if 0 //SUPPORT_APP_RCSP_EN
    #undef  REC_EN
    #define REC_EN         0         ///<�ֻ�APPģʽ��֧��¼��
#endif

#if REC_EN
	#define BT_REC_EN		0       ///<����¼��ʹ��
	#define MIC_REC_EN		1       ///<MIC¼��ʹ��
	#define FM_REC_EN		1       ///<FM¼��ʹ��
	#define AUX_REC_EN		1       ///<AUX¼��ʹ��
#endif


/*
*********************************************************************
                        UI MACRO
*********************************************************************
*/


   #define UI_ENABLE               0    ///<UI_��ʾ
 

#if 0//UI_ENABLE
    ///��ѡһ
    #define LCD_128X64_EN         0      ///<lcd ֧��
    #define LED_7_EN                       1      ///<led ֧��     
    #define LCD_SUPPORT_MENU     0       ///�˵���ʾ
    #define LRC_LYRICS_EN                 0       ///LRC�����ʾ





    #define support_led7_user_pc0pa14pa15pc1pc2pc3pc4
    #define support_aux_led_disp_line     //������ʾ"LINE"
    #define support_led_disp_pause
    #define support_mute_led_all_flish    //MUTE����

	
 #endif 





 



#define muteh_key_mode   1

#if muteh_key_mode
#define KEY_AD_EN           1   ///<AD����ʹ��
#define KEY_IO_EN             0   ///<IO����ʹ��
#define KEY_IR_EN             0   ///<����ң��ʹ��,PA9
#define KEY_TCH_EN         0   ///<��������ʹ��
#endif 

#if KEY_AD_EN  
#define adk_user_pb9
#define support_k68_1key_mode
#endif 

#define    adk_user_k68_key   



#define LED_EN                  1       ///<LEDָʾʹ��
#define  PP_LED_USER_PC5

//MUTE IO 
    #define   PA_ENABLE
#ifdef PA_ENABLE  
        #define  pa_mute_use_pin_PC4 //pa_mute_use_pin_PA11    // pa_mute_use_pin_PR0 //
    //    #define   mute_io_L_is_mute   //  ��MUTE   ������Ϊ��MUTE    
      #define support_vol_is_0_mute_amp	//������0 MUTE ����
//      #define support_pause_stop_mute_amp
  //    #define  support_bt_pause_mute_amp		  	
#endif 

//AB/D
//#define support_amP_ab_d
//#define amp_ab_d_user_PB6  


#if KEY_TONE_EN
#define  support_vol_max_tone_en  0
#endif 


/*���������LINE�¼�� PC15 ��ʱ MUTE */
#define PHONE_CHECK_ENABLE
#ifdef PHONE_CHECK_ENABLE
 #define  support_phone_chack_user_PB12   //support_phone_chack_user_PA9  //
#endif 


//line ���
#define    line_user_PA3PA4  //AUX0 

#define AUX_DETECT_EN  1
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PB11
    #define  support_line_unline_to_next_mode   //AUX �����ߵ���һ��ģʽ
  //  #define AUX_OUT_WITHOUT_CNT  //�γ���ȥ��

#endif 

///#define  power_on_no_usb_sd_to_bt 


#define support_off_usb_dp    //����USB_DP Ϊ����
#define support_off_PB13        //����PB13Ϊ����
#define support_off_phone_call    //��ͨ��



//��������
#define power_on_wait_power_key_down
#define support_io_power_on_off    //����MOS��
#define  power_on_off_user_PB10 
#define support_power_off_voice
//#define support_short_push_key_power_on   
#define ENABLE_POWER_ON_KEY_WAIT













