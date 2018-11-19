/*--------------------------------------------------------------------------*/
/**@file     sys_cfg.h
   @brief    ϵͳ����
   @details
   @author
   @date    2015-9-3
   @note    ac46x
*/
/*----------------------------------------------------------------------------*/

#ifndef _CONFIG_
#define _CONFIG_

#include "includes.h"



///�����ջ��С���ò���
#define VM_TASK_STACK_SIZE          (1024 * 1)
#define MAIN_TASK_STACK_SIZE        (1024 * 2) //(1024 * 1)����
#define MUSIC_TASK_STACK_SIZE       (1024 * 4)
#define MUSIC_PHY_TASK_STACK_SIZE   (1024 * 4)
#define TONE_TASK_STACK_SIZE        (1024 * 4)
#define TONE_PHY_TASK_STACK_SIZE    (1024 * 2)
#define UI_TASK_STACK_SIZE          (1024 * 2)



/*
*********************************************************************
                        DEBUG MACRO
*********************************************************************
*/
#define __DEBUG         ////<����ϵͳ��ӡ���Թ���


/*
*********************************************************************
                        APPLICATION FUNCTION
*********************************************************************
*/

/*
*********************************************************************
                       ��������ʹ�� 
*********************************************************************
*/
#define EARPHONE_MODE_EN    0



/*
*********************************************************************
                        COMMON MACRO
*********************************************************************
*/
#define EQ_EN			        1       ///<EQģ�鿪��
#define EQ_UART_BDG	    		0       ///<EQ uart online dbg switch
#define DAC_SOUNDTRACK_COMPOUND 0       ///<dac�����ϲ�
#define LED_EN                  1       ///<LEDָʾʹ��
#define DAC_AUTO_MUTE_EN		1       ///<�Զ�mute
#define SYS_LVD_EN              1       ///<�������
#define KEY_TONE_EN     	    1       ///<������
#define SYS_DEFAULT_VOL         0      ///<��0��ʾʹ��Ĭ������
#define UART_UPDATA_EN          0      ///<��������
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<����˫������
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
    #define SDMMC0_EN       1
    #define SDMMC1_EN       0
    #define USB_DISK_EN     1
    #define USB_PC_EN       1
#endif

/*
*********************************************************************
                        DAC VCOMO ����
*********************************************************************
*/
#if EARPHONE_MODE_EN
    #define VCOMO_EN 	1	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#else
    #define VCOMO_EN 	0	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#endif

/*
*********************************************************************
                        APP MACRO
*********************************************************************
*/
#ifdef MINI
    #define SUPPORT_APP_RCSP_EN         0   ///<MINI_BT���ֻ�app ������ʱ��֧��
#else
    #define SUPPORT_APP_RCSP_EN         0   ///<��׼SDK���ֻ�app ������ʱ��֧��
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
#define BT_ANALOG_CFG   0//ģ������
#define BT_XOSC         0//

#if SUPPORT_APP_RCSP_EN
#define BT_BACKMODE         1             ///<������̨
#else
#define BT_BACKMODE         0             ///<������̨
#endif

#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID���յĶ���ģʽֻ֧�ַǺ�̨
#endif

#define BT_PHONE_NUMBER     1          ///<���籨��

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
#define MUSIC_DECRYPT_EN 		1	//SMP�����ļ�֧��
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
#ifdef MINI
    #define RTC_CLK_EN          0       ///<MINI_BT RTCʱ��ģʽ
#else
    #define RTC_CLK_EN          0       ///<��׼SDK RTCʱ��ģʽ
#endif

#if RTC_CLK_EN
    #define RTC_ALM_EN          1       ///<RTC����ģʽ
    #define RTC_CLK_CHECK_EN    0       ///<RTC������
#endif

/*
*********************************************************************
                        ECHO MACRO
*********************************************************************
*/
#ifdef MINI
    #define ECHO_EN             0       ///<���칦�� MINI_BT
    #define ECHO_TASK_EN        0       ///<����ģʽ MINI_BT
#else
    #define ECHO_EN             1       ///<���칦�� ��׼SDK
    #define ECHO_TASK_EN        0       ///<����ģʽ ��׼SDK
#endif

/*
*********************************************************************
                        REC MACRO
*********************************************************************
*/
#ifdef MINI
    #define REC_EN             0    ///<MINI_BT¼������
#else
    #define REC_EN             1    ///<��׼SDK¼������
#endif

#if SUPPORT_APP_RCSP_EN
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

#if SUPPORT_APP_RCSP_EN
#define UI_ENABLE                    0
#else

#ifdef MINI
    #define UI_ENABLE                0     ///<UI_��ʾ
#else
    #define UI_ENABLE                0     ///<UI_��ʾ
#endif

#endif

#if UI_ENABLE
    ///��ѡһ
    #define LCD_128X64_EN        0      ///<lcd ֧��
    #define LED_7_EN                  1      ///<led ֧��
#else
    ///����֧��
    #define LCD_128X64_EN        0
    #define LED_7_EN                   0
#endif //#if UI_ENABLE

#if LCD_128X64_EN
    #define LCD_SUPPORT_MENU     0       ///�˵���ʾ
    #define LRC_LYRICS_EN               0       ///LRC�����ʾ
#else
    ///����֧��
    #define LCD_SUPPORT_MENU     0
    #define LRC_LYRICS_EN        0
#endif//#if LCD_128X64_EN

#endif
