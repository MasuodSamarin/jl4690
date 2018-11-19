#ifndef MSG_H
#define MSG_H

#include "typedef.h"
#include "sdk_cfg.h"

#define NO_MSG 0xff

#if 0//defined customer_zy_377A_ac6901||defined customer_zy_5059_ac6901

	 enum
	 {
	     MSG_0 = 0,
	     MSG_1,
	     MSG_2,
	     MSG_3,
	     MSG_4,
	     MSG_5,
	     MSG_6,
	     MSG_7,
	     MSG_8,
	     MSG_9,
	     MSG_VOL_UP,
	     MSG_VOL_DOWN,
	     MSG_MUTE,
	     MSG_POWER_OFF,
	 //    MSG_POWER_OFF_HOLD,
	     MSG_POWER_KEY_UP,
	     MSG_POWER_OFF_KEY_MSG,// --10
	     MSG_POWER_ON,
	     MSG_UPDATA,
	     MSG_LOW_POWER,    
	     MSG_LOW_POWER_VOICE,
	     ///-------work_mode---------------
	     MSG_CHANGE_WORKMODE,
	     MSG_NEXT_WORKMODE,
	 //    MSG_PRE_WORKMOD,
	     MSG_LAST_WORKMOD,
	 
	 //	MSG_ENTER_SLEEP_MODE,
	 
	 #if 1//REC_EN	
	 	MSG_CHANGE_REC_MODE,
	 #endif 
	     
	 #if 1 //def support_msg_light_key
	     MSG_LIGHT_KEY,
	 #endif
	 
	 #if  1//MIC_CHECK_ENABLE
	 #if  1//MIC_ONOFF_KEY
	 	MSG_MIC_ONOFF,
	 #endif	
	 #endif	
	 
	 #if 1//def support_menu_mode   
	 	MSG_MENU_MODE,	  
	 #endif
	 
	 #if 1 //def SUPPORT_PT2313
	 
	 #if 1//def  SUPPORT_MAIN_VOL_KEY
	 	MSG_MAIN_VOL_UP,	
	 	MSG_MAIN_VOL_DN,
	 #endif	  	
	 #if 1//def SUPPORT_MSG_FRONT_LEFT
	 	MSG_FRONT_LEFT_UP,
	 	MSG_FRONT_LEFT_DN,
	 #endif
	 #if 1//def SUPPORT_MSG_FRONT_RIGHT  // 20
	 	MSG_FRONT_RIGHT_UP,
	 	MSG_FRONT_RIGHT_DN,
	 #endif
	 #if 1//def Support_MSG_BASS
	 	MSG_BASS_UP,	
	 	MSG_BASS_DN,
	 #endif 
	 #if 1//def Support_MSG_TREBLE
	 	MSG_TREBLE_UP,				  
	 	MSG_TREBLE_DN,	 
	 #endif 	
	 					
	 #if 1//def Support_MSG_SWVOL
	 	MSG_SWVOL_UP,				   
	 	MSG_SWVOL_DN,  
	 #endif 	
	 
	 #endif
	 
	 
	 #if 1//def Support_MSG_MIC_ECO_VOL_KEY
	 	MSG_MIC_UP,
	 	MSG_MIC_DN,
	 	MSG_ECHO_UP,
	 	MSG_ECHO_DN,
	 	//MSG_ECHO_KEY,
	 	//MSG_OK_VOL_KEY,	 
	 #endif
	 
	 #if 1//def Support_MSG_RESET
	 	MSG_RESET_KEY,
	 #endif
	 
	 #if 1//def SUPPORT_MUSIC_RANDOM_KEY
	 	MSG_MUSIC_RANDOM_PLAY, // 2c
	 #endif
	 #if 1//def SUPPORT_REC_ONE_KEY_PLAY
	 	MSG_COM_REC_REPLAY,
	 #endif
	 
	     MSG_STANBY_KEY,
	     MSG_ADD_100,
	     MSG_MUSIC_MODE_KEY, 
	     MSG_FM_MODE_KEY,
	     MSG_LINE_MODE_KEY,
	     MSG_BT_MODE_KEY,  //0x1d
	 
	 #if 1//def SUPPORT_MODE_VOICE_ONOFF
	 	MSG_MODE_VOICE_ONOFF,
	 #endif
	 
	 #if 1//def SUPPORT_DOUBLE_MODE_VOICE		 
	 	MSG_MODE_VOICE_SEL,
	 #endif
	 
	     // UI MAIN
	     MSG_ENTER_MENUMAIN,
	     ///-------main_msg，此消息前的消息发送到MAIN线程---------------
	     MSG_MAIN_MAX,
	 
	     ///-------music app---------------
	     MSG_MUSIC_NEXT_FILE ,
	     MSG_MUSIC_PREV_FILE,
	     MSG_MUSIC_PP,
	     MSG_MUSIC_PLAY,
	     MSG_MUSIC_PAUSE,
	     MSG_MUSIC_STOP,
	     MSG_MUSIC_FF,
	     MSG_MUSIC_FR,
	     MSG_MUSIC_FFR_DONE,
	     MSG_MUSIC_RPT,
	     MSG_MUSIC_EQ,
	     MSG_MUSIC_U_SD,
	     MSG_MUSIC_DEL_FILE,
	     MSG_MUSIC_PLAY_REC_FILE,
	     MSG_MUSIC_SPC_FILE,
	 #if MUSIC_AB_RPT_EN
	     MSG_MUSIC_AB_RPT,
	 #endif    
	     MSG_MUSIC_PLAY_SN,
	 
	 	MSG_FOLDER_NEXT,		
	 	MSG_FOLDER_PREV,		
	 	MSG_FOLDER_REPEAT,		
	 
	 	MSG_MUSIC_RPT_ONE,
	 	MSG_MUSIC_RPT_ALL,
	 	MSG_MUSIC_RPT_RAND,
	 	MSG_CLASSIC_MUSIC,
	 	MSG_GUOXUE,
	 	MSG_WEST_MUSIC,
	 	MSG_ENGLISH,
	 	MSG_STORY,
	 	MSG_SONG,
	 	MSG_ENCYCLOPEDIA,
	 	MSG_FITAL_EDUCATION,
	 	MSG_LISTEN,
	 
	     ///-------FM app---------------
	     MSG_FM_SCAN_ALL_INIT ,
	 
	     
	     MSG_FM_INIT,
	     MSG_FM_SCAN_ALL,
	     MSG_FM_PREV_STATION,
	     MSG_FM_NEXT_STATION,
	     MSG_FM_SCAN_ALL_DOWN,
	     MSG_FM_SCAN_ALL_UP,
	     MSG_FM_PREV_STEP,
	     MSG_FM_NEXT_STEP,
	 //    MSG_SRC,
	 //    MSG_FM_SELECT_CHANNEL,
	     MSG_FM_PP,
	 //    MSG_FM_DEL_CHANNEL,
	 //    MSG_FM_SAVE_CHANNEL,
	 //    MSG_FM_SELECT_FREQ,
	     ///-------BT app---------------
	     MSG_BT_NEXT_FILE ,// = 0x6a
	     MSG_BT_PREV_FILE,
	     MSG_BT_PP,
	     MSG_BT_CALL_LAST_NO,
	     MSG_BT_CALL_CONTROL,
	     MSG_BT_CALL_REJECT,
	     MSG_BT_ANSWER_CALL,
	 //    MSG_BT_SHUTTER,
	 //    MSG_BT_RESET,
	     MSG_BT_STACK_STATUS_CHANGE,
	     MSG_TEST_HFP,
	     MSG_DISCONNECT_ALL_LINK,
	     MSG_BT_CONNECT_CTL,
	     MSG_BT_HID_CTRL,
	     MSG_BT_HID_TAKE_PIC,
	     MSG_BT_HID_TAKE_IOS,    
	     MSG_BT_HID_TAKE_ANDROID,       
	     MSG_BT_MUSIC_EQ,
	     MSG_BT_PAGE_SCAN,
	     MSG_DISP_MENU,///自动刷新界面
	 #if   1// SUPPORT_ALL_VOICE
	 	MSG_BT_VOICE_SWITCH,	
	 #endif
	 
	     ///-------AUX app---------------
	     MSG_AUX_INIT ,
	     MSG_AUX_MUTE,
	     MSG_AUX_PAUSE,
	 #if   1// SUPPORT_ALL_VOICE
	 	MSG_AUX_VOICE_SWITCH,	
	 #endif
	 
	     ///-------PC app---------------
	     MSG_PC_MODE_INIT, //= 0x80,
	     MSG_PC_CARD_READER,
	     MSG_PC_SPK_MUTE,
	     MSG_PC_SPK_UNMUTE,
	     MSG_PC_SPK_VOL,
	     MSG_PC_MUTE,
	     MSG_PC_VOL_UP,
	     MSG_PC_VOL_DOWN,
	     MSG_PC_PP,
	     MSG_PC_PLAY_NEXT,
	     MSG_PC_PLAY_PREV,
	     MSG_PC_UPDATA,
	     MSG_PC_SPK_PP,
	     
	 #if RTC_CLK_EN
	     ///-------RTC app---------------
	     MSG_RTC_INIT ,
	     MSG_RTC_SETTING,
	     MSG_ALM_SETTING,
	     MSG_ALM_SW,
	     MSG_ALM_ON,
	     MSG_RTC_PLUS,
	     MSG_RTC_MINUS,
	     MSG_RTC_POWER_DOWN,
	 #endif
	 
	     ///-------ENCODE app---------------
	     MSG_REC_INIT,
	     MSG_REC_START,
	     MSG_REC_STOP,
	     MSG_REC_PP,
	     MSG_ENCODE_ERR,
	 
	     MSG_ECHO_START,
	     MSG_ECHO_STOP,
	 
	     ///-------IDLE app--------------
	     MSG_IDLE_MODE,
	     MSG_IDLE_CTL,
	     MSG_ENTER_IDLE_TASK,
	     MSG_EXIT_IDLE_TASK,
	     MSG_IDLE_CNT,
	     MSG_IDLE_CNT_LONG,
	     MSG_IDLE_CNT_HOLD,
	     MSG_IDLE_CNT_UP,
	     
	 #if   1// SUPPORT_ALL_VOICE
	 	 MSG_VOICE_MUTE,   
	 	 MSG_VOICE_VOLUME_PLUS,   
	 	 MSG_VOICE_VOLUME_MINUS, 
	 	 MSG_MAX_VOICE,  
	 	 MSG_VOICE_NUMBER,  
	 #if 1//def SUPPORT_MIC_ONOFF_VOICE
	 	 MSG_VOICE_MIC,
	 #endif	 
	 #endif
	 
	     MSG_PROMPT_PLAY,
	 
	     MSG_INPUT_TIMEOUT,
	     MSG_HALF_SECOND,
	     MSG_ENTER_MENULIST,
	 
	     MSG_DAC_ON,
	     MSG_DAC_OFF,
	 
	     //解码器消息
	     SYS_EVENT_BEGIN_DEC = 0xB0,
	     SYS_EVENT_DEC_FR_END,
	     SYS_EVENT_DEC_FF_END,
	     SYS_EVENT_DEC_END,
	     SYS_EVENT_DEC_DEVICE_ERR,	 
	     SYS_EVENT_DEC_SET_END,
	 
	     SYS_EVENT_PLAY_SEL_END,
	     MSG_NULL = 0xff,
	 };
#else  // customer_zy_377A_ac6901
	 enum
	 {
	     MSG_0 = 0,
	     MSG_1,
	     MSG_2,
	     MSG_3,
	     MSG_4,
	     MSG_5,
	     MSG_6,
	     MSG_7,
	     MSG_8,
	     MSG_9,
	     MSG_VOL_UP,
	     MSG_VOL_DOWN,
	     MSG_MUTE,
	     MSG_POWER_OFF,
	     MSG_POWER_KEY_UP,
	     MSG_POWER_OFF_KEY_MSG,
	     MSG_POWER_ON,// ---------10
	     MSG_UPDATA,
	     MSG_LOW_POWER,    
	     MSG_LOW_POWER_VOICE,
	     MSG_CHANGE_WORKMODE,
	     MSG_NEXT_WORKMODE,
	     MSG_LAST_WORKMOD,	 
	 	MSG_CHANGE_REC_MODE,	     	 
	 	MSG_MIC_ONOFF,	 
	 	MSG_MENU_MODE,	  	 
	 	MSG_MIC_UP,
	 	MSG_MIC_DN,
	 	MSG_ECHO_UP,
	 	MSG_ECHO_DN,	 
	 	MSG_RESET_KEY,	 
	 	MSG_MUSIC_RANDOM_PLAY, // 
	 	MSG_COM_REC_REPLAY,  // ---------20	 
	     MSG_STANBY_KEY,
	     MSG_ADD_100,
	     MSG_MUSIC_MODE_KEY, 
	     MSG_FM_MODE_KEY,
	     MSG_LINE_MODE_KEY,
	     MSG_BT_MODE_KEY,  //0x1d	 
	 	MSG_MODE_VOICE_ONOFF,	 
	 	MSG_MODE_VOICE_SEL,	 
		MSG_VOICE_EN_CH,
		MSG_VOICE_ON,
		MSG_VOICE_OFF,	

	 #if 1 //def SUPPORT_PT2313
	 
	 #if 1//def  SUPPORT_MAIN_VOL_KEY
	 	MSG_MAIN_VOL_UP,	
	 	MSG_MAIN_VOL_DN,
	 #endif	  	
	 #if 1//def SUPPORT_MSG_FRONT_LEFT
	 	MSG_FRONT_LEFT_UP,
	 	MSG_FRONT_LEFT_DN,
	 #endif
	 #if 1//def SUPPORT_MSG_FRONT_RIGHT  // 20
	 	MSG_FRONT_RIGHT_UP,
	 	MSG_FRONT_RIGHT_DN,
	 #endif
	 #if 1//def Support_MSG_BASS
	 	MSG_BASS_UP,	
	 	MSG_BASS_DN,
	 #endif 
	 #if 1//def Support_MSG_TREBLE
	 	MSG_TREBLE_UP,				  
	 	MSG_TREBLE_DN,	 
	 #endif 	
	 					
	 #if 1//def Support_MSG_SWVOL
	 	MSG_SWVOL_UP,				   
	 	MSG_SWVOL_DN,  
	 #endif 	
	 
	 #endif
	 #if 1//def support_enconder_onoff
	 	MSG_SW_ENCODER,
	 #endif

	 #if 1//def support_cd_key_mode
		 MSG_CD_MODE_KEY,
	 #endif
	 #if 1//def support_dvd_key_mode
		 MSG_DVD_MODE_KEY,
	 #endif
	 #if 1//def support_ac3_key_mode
	 	MSG_AC3_MODE_KEY,
	 #endif

	 #if 1//def SUPPORT_VOICE_ONOFF
	 	MSG_VOICE_ONOFF,
	 #endif

	 
	 #if 1//def SUPPORT_RGB_LED_MODE
	 	MSG_RGB_LED_MODE,  
	 #endif
		
	     MSG_ENTER_MENUMAIN,
	     MSG_MAIN_MAX,	 
	     ///-------music app---------------
	     MSG_MUSIC_NEXT_FILE ,
	     MSG_MUSIC_PREV_FILE,
	     MSG_MUSIC_PP,
	     MSG_MUSIC_PLAY,
	     MSG_MUSIC_PAUSE,
	     MSG_MUSIC_STOP,
	     MSG_MUSIC_FF,
	     MSG_MUSIC_FR,
	     MSG_MUSIC_FFR_DONE,
	     MSG_MUSIC_RPT,
	     MSG_MUSIC_EQ,
	     MSG_MUSIC_U_SD,
	     MSG_MUSIC_DEL_FILE,
	     MSG_MUSIC_PLAY_REC_FILE,
	     MSG_MUSIC_SPC_FILE,
	     MSG_MUSIC_PLAY_SN,
	 	MSG_MUSIC_VOICE_SWITCH,	
	 	MSG_MUSIC_PREV_VOICE,	
	 	MSG_MUSIC_NEXT_VOICE,		 
	 	MSG_FOLDER_NEXT,		
	 	MSG_FOLDER_PREV,		
	 	MSG_FOLDER_REPEAT,		
	 	MSG_MUSIC_VOICE_CHANGE,
	     ///-------FM app---------------
	     MSG_FM_SCAN_ALL_INIT ,	     
	     MSG_FM_INIT,
	     MSG_FM_SCAN_ALL,
	     MSG_FM_PREV_STATION,
	     MSG_FM_NEXT_STATION,
	     MSG_FM_SCAN_ALL_DOWN,
	     MSG_FM_SCAN_ALL_UP,
	     MSG_FM_PREV_STEP,
	     MSG_FM_NEXT_STEP,
	     MSG_FM_PP,
	 	MSG_FM_SEARCHING,
	 	MSG_FM_VOICE_SWITCH,	
	 	MSG_FM_VOICE_CHANGE, 
	     ///-------BT app---------------
	     MSG_BT_NEXT_FILE ,
	     MSG_BT_PREV_FILE,
	     MSG_BT_PP,
	     MSG_BT_CALL_LAST_NO,
	     MSG_BT_CALL_CONTROL,
	     MSG_BT_CALL_REJECT,
	     MSG_BT_ANSWER_CALL,
	     MSG_BT_STACK_STATUS_CHANGE,
	     MSG_TEST_HFP,
	     MSG_DISCONNECT_ALL_LINK,
	     MSG_BT_CONNECT_CTL,
	     MSG_BT_HID_CTRL,
	     MSG_BT_HID_TAKE_PIC,
	     MSG_BT_HID_TAKE_IOS,    
	     MSG_BT_HID_TAKE_ANDROID,    
	     MSG_BT_MUSIC_EQ,
	     MSG_BT_PAGE_SCAN,
	     MSG_DISP_MENU,///自动刷新界面
	 	MSG_BT_VOICE_SWITCH,	
	 	MSG_BT_AUTO_BACK_CONNECT,
	 	MSG_BT_VOICE_CHANGE,	 
	 	MSG_BT_DISCONNECT_KEY,	 
	     ///-------AUX app---------------
	     MSG_AUX_INIT ,
	     MSG_AUX_MUTE,
	     MSG_AUX_PAUSE,
	 	MSG_AUX_VOICE_SWITCH,	
	 	MSG_AUX_VOICE_CHANGE,	 
	     ///-------PC app---------------
	     MSG_PC_MODE_INIT, //= 0x80,
	     MSG_PC_CARD_READER,
	     MSG_PC_SPK_MUTE,
	     MSG_PC_SPK_UNMUTE,
	     MSG_PC_SPK_VOL,
	     MSG_PC_MUTE,
	     MSG_PC_VOL_UP,
	     MSG_PC_VOL_DOWN,
	     MSG_PC_PP,
	     MSG_PC_PLAY_NEXT,
	     MSG_PC_PLAY_PREV,
	     MSG_PC_UPDATA,
	     MSG_PC_SPK_PP,	     	 
	     ///-------ENCODE app---------------
	     MSG_REC_INIT,
	     MSG_REC_START,
	     MSG_REC_STOP,
	     MSG_REC_PP,
	     MSG_ENCODE_ERR,	 
	     MSG_ECHO_START,
	     MSG_ECHO_STOP,	 
	     ///-------IDLE app--------------
	     MSG_IDLE_MODE,
	     MSG_IDLE_CTL,
	     MSG_ENTER_IDLE_TASK,
	     MSG_EXIT_IDLE_TASK,
	     MSG_IDLE_CNT,
	     MSG_IDLE_CNT_LONG,
	     MSG_IDLE_CNT_HOLD,
	     MSG_IDLE_CNT_UP,	     
	 	 MSG_VOICE_MUTE,   
	 	 MSG_VOICE_MUTE_OFF,   
	 	 MSG_VOICE_VOLUME_PLUS,   
	 	 MSG_VOICE_VOLUME_MINUS, 
	 	 MSG_MAX_VOICE,  
	 	 MSG_VOICE_NUMBER,  
	 	 MSG_VOICE_MIC,	 
	     MSG_PROMPT_PLAY,	 
	     MSG_INPUT_TIMEOUT,
	     MSG_HALF_SECOND,
	     MSG_ENTER_MENULIST,	 
	     MSG_DAC_ON,
	     MSG_DAC_OFF,	 
	     //解码器消息
	     SYS_EVENT_BEGIN_DEC = 0xB0,
	     SYS_EVENT_DEC_FR_END,
	     SYS_EVENT_DEC_FF_END,
	     SYS_EVENT_DEC_END,
	     SYS_EVENT_DEC_DEVICE_ERR,	 
	     SYS_EVENT_DEC_SET_END,	 
	     SYS_EVENT_PLAY_SEL_END,
	     MSG_NULL = 0xff,
	 };

#endif


enum
{
//	SYS_MSG_0 = 0x40,

    SYS_EVENT_DEV_ONLINE = 0xc0,
    SYS_EVENT_DEV_OFFLINE,
    SYS_EVENT_LGDEV_ONLINE,
    SYS_EVENT_LGDEV_OFFLINE,
    SYS_EVENT_SYSCLK_NOTFIT_DEVMOUNT,   ///<当前系统时钟不满足设备枚举需求，收到此消息，切换进music
    SYS_EVENT_AUX_IN,           ///<AUX插入
    SYS_EVENT_AUX_OUT,          ///<AUX拔出
    SYS_EVENT_PC_IN,            ///<PC 插入
    SYS_EVENT_PC_OUT,           ///<PC 拔出
    SYS_EVENT_DECODE_END,
    SYS_EVENT_STORE_BP,
    SYS_EVENT_RESTORE_BP,
    SYS_EVENT_DEL_TASK,
    SYS_EVENT_TONE_END,
    SYS_EVENT_RES_MANAGE_RUN,
    SYS_EVENT_TASK_EXIT_REQ,
    SYS_EVENT_TASK_RUN_REQ,// d0
    SYS_EVENT_BT_BACKCON,       ///<蓝牙在后台才连接成功，由用户选择处理
    SYS_EVENT_BT_BACKDISCON,    ///<蓝牙在后台断开成功，由用户选择处理
    SYS_EVENT_DEV_BEGIN_MOUNT,
    SYS_EVENT_DEV_MOUNT_ERR,
    SYS_EVENT_SYS_TIMER_DELAY,
    SYS_EVENT_PHONE_IN, 		  ///er插入
    SYS_EVENT_PHONE_OUT,		  ///<AUX拔出
    SYS_EVENT_MIC_IN,			///er插入
    SYS_EVENT_MIC_OUT,			///<AUX拔出
};

enum
{
    MSG_RSCP_SEND_DATA = 0x3001,    //raw data send
    MSG_RSCP_RECIEVE_DATA,
    //pack send
    MSG_RSCP_CHANGE_WORDMODE_ACTION,
    MSG_RSCP_UPDATA_SPECIAL_STATE,
    MSG_RSCP_REPORT_FRAME,
    MSG_RSCP_REPORT_CTL_STATE,
    MSG_RSCP_REPORT_LIGHT_STATE,
    MSG_RSCP_REPORT_LONGFRAME,
    MSG_RSCP_REPORT_ID3_INFO,

};



struct event_head
{
    const char *str;
    int len;
    char data[0];
};

enum
{
    MAIN_WORK_MODE=0,
    MUSIC_WORK_MODE,
    LINE_WORK_MODE,
    LINE_WORK_MODE_2,
    AC3_WORK_MODE,
    RADIO_WORK_MODE,
    BT_WORK_MODE,
    PC_WORK_MODE,
    STANBY_WORK_MODE,  //待机模式
    REC_WORK_MODE,
    RTC_WORK_MODE,
    NOP_WORK_MODE,   //空模式
    POWER_OFF_WORK_MODE,
    FM_AM_WORK_MODE,
    LIGHT_WORK_MODE,
    ECHO_WORK_MODE,

};

extern u8   workmode;
#endif



