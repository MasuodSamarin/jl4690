#ifndef _PLAY_SEL_H_
#define _PLAY_SEL_H_

#include "includes.h"
#include "sdk_cfg.h"
#include "bluetooth/avctp_user.h"
#include "dec/music_api.h"

//#define DEC_SEL_DEBUG
#ifdef DEC_SEL_DEBUG
#define dsel_printf printf
#define dsel_puts puts
#else
#define dsel_printf(...)
#define dsel_puts(...)
#endif


#define BT_CFG_FILE             "bt_cfg.bin"  /*蓝牙配置文件默认放在第一个文件，与库对应，不可修改成其它值*/
#define EQ_CFG_FILE             "eq_cfg.bin"



#if  SUPPORT_ALL_VOICE
	 #if SUPPORT_TY_VOICE
	 
	 	 #define BPF_BT_MP3              "bt.***"
	 	 #define BPF_RADIO_MP3           "radio.***"
	 	 #define BPF_LINEIN_MP3          "linein.***"
	 	 #define BPF_MUSIC_MP3           "music.***"
	 	 #define BPF_PC_MP3              "pc.***"
	 	 #define BPF_REC_MP3             "record.***"
	 	 #define BPF_RECPLAY_MP3             "recplay.***"
	 	 
	 	 #define BPF_WAIT_MP3            "wait.***"
	 	 #define BPF_CONNECT_MP3         "connect.***"
	 	 #define BPF_DISCONNECT_MP3      "disconnect.***"
	 	 #define BPF_RING_MP3            "ring.***"
	 	 
	 	 #define BPF_0_MP3               "0.***"
	 	 #define BPF_1_MP3               "1.***"
	 	 #define BPF_2_MP3               "2.***"
	 	 #define BPF_3_MP3               "3.***"
	 	 #define BPF_4_MP3               "4.***"
	 	 #define BPF_5_MP3               "5.***"
	 	 #define BPF_6_MP3               "6.***"
	 	 #define BPF_7_MP3               "7.***"
	 	 #define BPF_8_MP3               "8.***"
	 	 #define BPF_9_MP3               "9.***"
	 	 
	 	 #if MEDIA_MODE_USB_SD_DETECT	
	 	 #define BPF_MUSIC_USB_MP3      "usb.***"
	 	 #define BPF_MUSIC_SD_MP3     "sd.***"
	 	 #endif
	 	 
	 	 #define BPF_PLAY_MP3               "play.***"
	 	 #define BPF_PAUSE_MP3               "pause.***"
	 	 #define BPF_PREV_MP3               "last.***"
	 	 #define BPF_NEXT_MP3               "next.***"
	 	 #define BPF_REP_ONE_MP3               "rep_one.***"
	 	 #define BPF_REP_ALL_MP3               "rep_all.***"
	 	 //#define BPF_NORMAL_MP3               "normal.***"
	 	 //#define BPF_POP_MP3               "pop.***"
	 	 //#define BPF_ROCK_MP3               "rock.***"
	 	 //#define BPF_JAZZ_MP3               "jazz.***"
	 	 //#define BPF_CLASS_MP3               "class.***"
	 	 //#define BPF_SOFT_MP3               "soft.***"
	 	 
	 	 //#define BPF_VL_DEC_MP3               "vol_dec.***"
	 	 //#define BPF_VL_INC_MP3               "vol_inc.***"
	 	 //#define BPF_VL_MAX_MP3              "vol_max.***"
	 	 //#define BPF_MUTE_MP3      		 "mute.***"
	 	 //#define BPF_FM_SCAN_MP3         "fm_scan.***"
	 	 //#define BPF_LAST_CH_MP3         "last_ch.***"
	 	 //#define BPF_NEXT_CH_MP3           "next_ch.***"
	 	 //#define BPF_FM_SCAN_END_MP3     "fm_scan_end.***"
	 #ifdef SUPPORT_VOICE_MODE_KEY	 	 
	 	 #define BPF_VOICE_ON_MP3           "v_on.***"
	 	 #define BPF_VOICE_OFF_MP3         "v_off.***"
	 	 #define BPF_BT_NOTICE_MP3              "bt_n.***"
	 	 #define BPF_CONNECT_NOTICE_MP3         "connect_n.***"
	 	 #define BPF_DISCONNECT_NOTICE_MP3      "disconnect_n.***"		 
	 #endif	 	 
	 	 #define BPF_MIC_ON_MP3           "mic_on.***"
	 	 #define BPF_MIC_OFF_MP3         "mic_off.***"
	 	 
	 	 
	 	 #define BPF_LOW_POWER_MP3       "test.***"
	 	 #define BPF_NULL_MP3       "test.***"
	 	 #define BPF_TEST_MP3       		"test.***"
	 	 #define BPF_POWER_OFF       		"power_off.***"
	 	 #define BPF_POWER_OFF_MP3       "power_off.***"
	 #elif defined(SUPPORT_SCG_VOICE)	 	

	 	 #define BPF_BT_MP3              "bt.***"
	 	 #define BPF_RADIO_MP3           "radio.***"
	 	 #define BPF_LINEIN_MP3          "linein.***"
	 	 #define BPF_MUSIC_MP3           "music.***"
	 	 #define BPF_PC_MP3              "pc.***"
	 	 #define BPF_REC_MP3             "rec.***"
	 	 #define BPF_RECPLAY_MP3             "recplay.***"
	 	 
	 	 #define BPF_WAIT_MP3            "wait.***"
	 	 #define BPF_CONNECT_MP3         "connect.***"
	 	 #define BPF_DISCONNECT_MP3      "disconnect.***"
	 	 #define BPF_RING_MP3            "ring.***"
	 	 #if MEDIA_MODE_USB_SD_DETECT	
	 	 #define BPF_MUSIC_USB_MP3      "usb.***"
	 	 #define BPF_MUSIC_SD_MP3     "sd.***"
	 	 #endif
	 
		 	 #define BPF_0_EN_MP3               "0_en.***"
		 	 #define BPF_1_EN_MP3               "1_en.***"
		 	 #define BPF_2_EN_MP3               "2_en.***"
		 	 #define BPF_3_EN_MP3               "3_en.***"
		 	 #define BPF_4_EN_MP3               "4_en.***"
		 	 #define BPF_5_EN_MP3               "5_en.***"
		 	 #define BPF_6_EN_MP3               "6_en.***"
		 	 #define BPF_7_EN_MP3               "7_en.***"
		 	 #define BPF_8_EN_MP3               "8_en.***"
		 	 #define BPF_9_EN_MP3               "9_en.***"



	 	 	 #define BPF_RADIO_EN_MP3           "radio.***"
	 	 	 #define BPF_LINEIN_EN_MP3          "linein.***"
	 	 	 #define BPF_MUSIC_EN_MP3           "music.***"
	 	 	 #define BPF_PC_EN_MP3              "pc.***"
	 	 	 #define BPF_REC_EN_MP3             "record.***"
	 	 	 #define BPF_RECPLAY_EN_MP3             "recplay.***"
	 	 	 #define BPF_RING_EN_MP3            "ring.***"
			 #define BPF_BT_EN_MP3              "bt_en.***"
			 #define BPF_CONNECT_EN_MP3         "connect_en.***"
			 #define BPF_DISCONNECT_EN_MP3      "discon_en.***"		 	 
		 	 #define BPF_FM_SCAN_EN_MP3         "fm_scan_en.***"
		 	 #define BPF_PREV_EN_MP3               "prev_en.***"
		 	 #define BPF_LAST_CH_EN_MP3         "last_ch_en.***"
			 #ifdef SUPPORT_MUTE_VOICE		 
		 	 #define BPF_MUTE_EN_MP3      		 "mute_en.***"
		 	 #define BPF_MUTE_OFF_EN_MP3      		 "mute_off_en.***"		 
			 #endif
		 	 #define BPF_NEXT_EN_MP3               "next_en.***"				 
		 	 #define BPF_NEXT_CH_EN_MP3           "next_ch_en.***"
		 	 #define BPF_PAUSE_EN_MP3               "pause_en.***"
		 	 #define BPF_PLAY_EN_MP3               "play_en.***"
		 	 #define BPF_REP_ONE_EN_MP3               "rep_one_en.***"
		 	 #define BPF_REP_ALL_EN_MP3               "rep_all_en.***"
		 	 #if MEDIA_MODE_USB_SD_DETECT	
		 	 #define BPF_MUSIC_USB_EN_MP3      "usb_en.***"
		 	 #define BPF_MUSIC_SD_EN_MP3     "sd_en.***"
		 	 #endif
		 	 #define BPF_VOICE_ON_EN_MP3           "v_on_en.***"
		 	 #define BPF_VOICE_OFF_EN_MP3         "v_off_en.***"
	 	 	#define BPF_MIC_ON_MP3           "mic_on.***"
	 	 	#define BPF_MIC_OFF_MP3         "mic_off.***"
		 	 	 	 
		 #ifdef SUPPORT_EQ_VOICE			 
		 	 #define BPF_NORMAL_EN_MP3               "normal_en.***"
		 	 #define BPF_POP_EN_MP3               "pop_en.***"
		 	 #define BPF_ROCK_EN_MP3               "rock_en.***"
		 	 #define BPF_JAZZ_EN_MP3               "jazz_en.***"
		 	 #define BPF_CLASS_EN_MP3               "class_en.***"
		 	 #define BPF_SOFT_EN_MP3               "soft_en.***"
	 	 #endif
		 
		 #ifdef SUPPORT_VOL_VOICE		 
		 
		 	 #define BPF_VL_DEC_MP3               "vl_dec_en.***"
		 	 #define BPF_VL_INC_MP3               "vl_inc_en.***"
		 	 #define BPF_VL_MAX_MP3              "vl_max_en.***"
	 	 #endif
			 
			 
		 	 #define BPF_FM_SCAN_END_EN_MP3     "fm_end_en.***"		 

		
	 	 #define BPF_LOW_POWER_MP3       "test.***"
	 	 #define BPF_NULL_MP3       "test.***"
	 	 #define BPF_TEST_MP3       		"test.***"
	 	 #define BPF_POWER_OFF       		"power_off.***"
	 	 #define BPF_POWER_OFF_MP3       "power_off.***"



	 
	 #else
	 	 #define BPF_BT_MP3              "bt.***"
	 	 #define BPF_RADIO_MP3           "radio.***"
	 	 #define BPF_LINEIN_MP3          "linein.***"
	 	 #define BPF_MUSIC_MP3           "music.***"
	 	 #define BPF_PC_MP3              "pc.***"
	 	 #define BPF_REC_MP3             "record.***"
	 	 #ifdef SUPPORT_RECPLAY_VOICE
	 	 #define BPF_RECPLAY_MP3             "recplay.***"
	 	 #endif
	 	 
	 	 #define BPF_WAIT_MP3            "wait.***"
	 	 #define BPF_CONNECT_MP3         "connect.***"
	 	 #define BPF_DISCONNECT_MP3      "disconnect.***"
	 	 #define BPF_RING_MP3            "ring.***"
	 	 #if BT_PHONE_NUMBER||SUPPORT_VOICE_NUMBER
	 	 #define BPF_0_MP3               "0.***"
	 	 #define BPF_1_MP3               "1.***"
	 	 #define BPF_2_MP3               "2.***"
	 	 #define BPF_3_MP3               "3.***"
	 	 #define BPF_4_MP3               "4.***"
	 	 #define BPF_5_MP3               "5.***"
	 	 #define BPF_6_MP3               "6.***"
	 	 #define BPF_7_MP3               "7.***"
	 	 #define BPF_8_MP3               "8.***"
	 	 #define BPF_9_MP3               "9.***"
	 	 #endif
		 
	 	 #if MEDIA_MODE_USB_SD_DETECT	
	 	 #define BPF_MUSIC_USB_MP3      "usb.***"
	 	 #define BPF_MUSIC_SD_MP3     "sd.***"
	 	 #endif
	 	 
	 	 #ifdef SUPPORT_POWER_ON_TONE
	 	 #define BPF_WELCOME_MP3      "welcome.***"
	 	 #endif
	 	 
	 	 #define BPF_PLAY_MP3               "play.***"
	 	 #define BPF_PAUSE_MP3               "pause.***"
	 	 #define BPF_PREV_MP3               "last.***"
	 	 #define BPF_NEXT_MP3               "next.***"
	 	 #define BPF_REP_ONE_MP3               "rep_one.***"
	 	 #define BPF_REP_ALL_MP3               "rep_all.***"
		 #ifdef SUPPORT_EQ_VOICE
	 	 #define BPF_NORMAL_MP3               "normal.***"
	 	 #define BPF_POP_MP3               "pop.***"
	 	 #define BPF_ROCK_MP3               "rock.***"
	 	 #define BPF_JAZZ_MP3               "jazz.***"
	 	 #define BPF_CLASS_MP3               "class.***"
	 	 #define BPF_SOFT_MP3               "soft.***"
	 	 #endif
		 
		 #if SUPPORT_VOL_VOICE		 
	 	 #define BPF_VL_DEC_MP3               "vol_dec.***"
	 	 #define BPF_VL_INC_MP3               "vol_inc.***"
	 	 #define BPF_VL_MAX_MP3              "vol_max.***"
		 #endif
		 #ifdef SUPPORT_MUTE_VOICE		 
	 	 #define BPF_MUTE_MP3      		 "mute.***"
	 	 #define BPF_MUTE_OFF_MP3  		 "mute_off.***"		 
		 #endif
	 	 #define BPF_FM_SCAN_MP3         "fm_scan.***"
	 	 #define BPF_LAST_CH_MP3         "last_ch.***"
	 	 #define BPF_NEXT_CH_MP3           "next_ch.***"
	 	 #define BPF_FM_SCAN_END_MP3     "fm_scan_end.***"
	 	 #define BPF_VOICE_ON_MP3           "v_on.***"
	 	 #define BPF_VOICE_OFF_MP3         "v_off.***"
	 	 #define BPF_MIC_ON_MP3           "mic_on.***"
	 	 #define BPF_MIC_OFF_MP3         "mic_off.***"
	 	 
	 	 #ifdef SUPPORT_VOICE_OFF_BT_USE_TY_VOICE        
	 	 #define BPF_BT_NOTICE_MP3              "bt_n.***"
	 	 #define BPF_CONNECT_NOTICE_MP3         "connect_n.***"
	 	 #define BPF_DISCONNECT_NOTICE_MP3      "disconnect_n.***"
	 	 #endif        
		 
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 
		 	 #if BT_PHONE_NUMBER||SUPPORT_VOICE_NUMBER
		 	 #define BPF_0_EN_MP3               "0_en.***"
		 	 #define BPF_1_EN_MP3               "1_en.***"
		 	 #define BPF_2_EN_MP3               "2_en.***"
		 	 #define BPF_3_EN_MP3               "3_en.***"
		 	 #define BPF_4_EN_MP3               "4_en.***"
		 	 #define BPF_5_EN_MP3               "5_en.***"
		 	 #define BPF_6_EN_MP3               "6_en.***"
		 	 #define BPF_7_EN_MP3               "7_en.***"
		 	 #define BPF_8_EN_MP3               "8_en.***"
		 	 #define BPF_9_EN_MP3               "9_en.***"
		 	 #endif
		 
			 #define BPF_BT_EN_MP3              "bt_en.***"
				 #define BPF_CONNECT_EN_MP3         "connect_en.***"
			 #define BPF_DISCONNECT_EN_MP3      "discon_en.***"		 	 
		 	 #define BPF_FM_SCAN_EN_MP3         "fm_scan_en.***"
		 	 #define BPF_PREV_EN_MP3               "last_en.***"
		 	 #define BPF_LAST_CH_EN_MP3         "last_ch_en.***"
			 #define BPF_LINEIN_EN_MP3          "linein_en.***"
			 #ifdef SUPPORT_MUTE_VOICE		 
		 	 #define BPF_MUTE_EN_MP3      		 "mute_en.***"
		 	 #define BPF_MUTE_OFF_EN_MP3      		 "mute_off_en.***"		 
			 #endif
		 	 #define BPF_NEXT_EN_MP3               "next_en.***"				 
		 	 #define BPF_NEXT_CH_EN_MP3           "next_ch_en.***"
		 	 #define BPF_PAUSE_EN_MP3               "pause_en.***"
		 	 #define BPF_PLAY_EN_MP3               "play_en.***"
			 #define BPF_RADIO_EN_MP3           "radio_en.***"
		 	 #define BPF_REC_EN_MP3             "rec_en.***"
		 	 #ifdef SUPPORT_RECPLAY_VOICE
	 		 #define BPF_RECPLAY_EN_MP3             "recplay_en.***"
		 	 #endif
		 	 #define BPF_REP_ONE_EN_MP3               "rep_one_en.***"
		 	 #define BPF_REP_ALL_EN_MP3               "rep_all_en.***"
		 	 #if MEDIA_MODE_USB_SD_DETECT	
		 	 #define BPF_MUSIC_USB_EN_MP3      "usb_en.***"
		 	 #define BPF_MUSIC_SD_EN_MP3     "sd_en.***"
		 	 #endif
		 	 #define BPF_VOICE_ON_EN_MP3           "v_on_en.***"
		 	 #define BPF_VOICE_OFF_EN_MP3         "v_off_en.***"
		 	 #define BPF_VOICE_CH_MP3         		  "v_ch.***"
		 	 #define BPF_VOICE_EN_MP3       		 "v_en.***"


			 #define BPF_MUSIC_EN_MP3           "music_en.***"
		 
		 	 	 	 
		 #ifdef SUPPORT_EQ_VOICE			 
		 	 #define BPF_NORMAL_EN_MP3               "normal_en.***"
		 	 #define BPF_POP_EN_MP3               "pop_en.***"
		 	 #define BPF_ROCK_EN_MP3               "rock_en.***"
		 	 #define BPF_JAZZ_EN_MP3               "jazz_en.***"
		 	 #define BPF_CLASS_EN_MP3               "class_en.***"
		 	 #define BPF_SOFT_EN_MP3               "soft_en.***"
	 	 #endif
		 
		 #ifdef SUPPORT_VOL_VOICE		 
		 
		 	 #define BPF_VL_DEC_EN_MP3               "vol_dec_en.***"
		 	 #define BPF_VL_INC_EN_MP3               "vol_inc_en.***"
		 	 #define BPF_VL_MAX_EN_MP3              "vol_max_en.***"
	 	 #endif
			 
			 
		 	 #define BPF_FM_SCAN_END_EN_MP3     "fm_end_en.***"		 

		#endif	 	 
		
	 	 #define BPF_LOW_POWER_MP3       "test.***"
	 	 #define BPF_NULL_MP3       "test.***"
	 	 #define BPF_TEST_MP3       		"test.***"
	 	 #define BPF_POWER_OFF       		"power_off.***"
	 	 #define BPF_POWER_OFF_MP3       "power_off.***"
	 #endif

#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF

	 #define BPF_BT_MP3              "bt.***"
	 #define BPF_RADIO_MP3           "radio.***"
	 #define BPF_LINEIN_MP3          "linein.***"
	 #define BPF_MUSIC_MP3           "music.***"
	 #define BPF_PC_MP3              "pc.***"
	 #define BPF_REC_MP3             "record.***"	 
	 #define BPF_WAIT_MP3            "wait.***"
	 #define BPF_CONNECT_MP3         "connect.***"
	 #define BPF_DISCONNECT_MP3      "disconnect.***"
	 #define BPF_RING_MP3            "ring.***"	 
	 #if MEDIA_MODE_USB_SD_DETECT	
	 #define BPF_MUSIC_USB_MP3      "usb.***"
	 #define BPF_MUSIC_SD_MP3     "sd.***"
	 #endif	 
	 #ifdef SUPPORT_POWER_ON_TONE
	 #define BPF_WELCOME_MP3      "welcome.***"
	 #endif
	 #define BPF_BT_NOTICE_MP3              "bt_n.***"
	 #define BPF_CONNECT_NOTICE_MP3         "connect_n.***"
	 #define BPF_DISCONNECT_NOTICE_MP3      "disconnect_n.***"
	 #define BPF_BT_EN_MP3              "bt_en.***"
	 #define BPF_CONNECT_EN_MP3         "connect_en.***"
	 #define BPF_DISCONNECT_EN_MP3      "discon_en.***"		 	 
	 #define BPF_LINEIN_EN_MP3          "linein_en.***"	 
	 #define BPF_RADIO_EN_MP3           "radio_en.***"	 
	 #if MEDIA_MODE_USB_SD_DETECT	
	 #define BPF_MUSIC_USB_EN_MP3      "usb_en.***"
	 #define BPF_MUSIC_SD_EN_MP3     "sd_en.***"
	 #endif	 
	 #define BPF_REC_EN_MP3             "record_en.***"






		 
     #ifdef SUPPORT_PP_PREV_NEXT_VOICE
     #define BPF_PLAY_MP3               "play.***"
     #define BPF_PAUSE_MP3               "pause.***"
     #define BPF_PREV_MP3               "last.***"
     #define BPF_NEXT_MP3               "next.***"	 
     #define BPF_PAUSE_EN_MP3             "pause_en.***"
     #define BPF_PLAY_EN_MP3               "play_en.***"	 
     #define BPF_PREV_EN_MP3               "last_en.***"
     #define BPF_NEXT_EN_MP3               "next_en.***"	     
     #endif
     #ifdef SUPPORT_MUSIC_REPEAT_VOICE
     #define BPF_REP_ONE_MP3               "rep_one.***"
     #define BPF_REP_ALL_MP3               "rep_all.***"			 
     #define BPF_REP_ONE_EN_MP3          "rep_one_en.***"
     #define BPF_REP_ALL_EN_MP3          "rep_all_en.***"
     
     #endif
     #ifdef SUPPORT_MUSIC_EQ_VOICE
     #define BPF_NORMAL_MP3               "normal.***"
     #define BPF_POP_MP3               "pop.***"
     #define BPF_ROCK_MP3               "rock.***"
     #define BPF_JAZZ_MP3               "jazz.***"
     #define BPF_CLASS_MP3               "class.***"
     #define BPF_SOFT_MP3               "soft.***"			 
     
     #define BPF_NORMAL_EN_MP3         "normal_en.***"
     #define BPF_POP_EN_MP3               "pop_en.***"
     #define BPF_ROCK_EN_MP3               "rock_en.***"
     #define BPF_JAZZ_EN_MP3               "jazz_en.***"
     #define BPF_CLASS_EN_MP3               "class_en.***"
     #define BPF_SOFT_EN_MP3               "soft_en.***"	 
     #endif
	 
	 #define BPF_LOW_POWER_MP3       "test.***"
	 #define BPF_NULL_MP3       "test.***"
	 #define BPF_TEST_MP3       		"test.***"
	 #define BPF_POWER_OFF       		"power_off.***"
	 #define BPF_POWER_OFF_MP3       "power_off.***"

#elif defined SUPPORT_DOUBLE_MODE_VOICE

#define BPF_BT_MP3              "bt.***"
#define BPF_RADIO_MP3           "radio.***"
#define BPF_LINEIN_MP3          "linein.***"
#define BPF_MUSIC_MP3           "music.***"
#define BPF_REC_MP3             "record.***"

#define BPF_WAIT_MP3            "wait.***"
#define BPF_POWER_OFF_MP3       "power_off.***"
#define BPF_CONNECT_MP3         "connect.***"
#define BPF_DISCONNECT_MP3      "disconnect.***"
#define BPF_RING_MP3            "ring.***"

#define BPF_0_MP3               "0.***"
#define BPF_1_MP3               "1.***"
#define BPF_2_MP3               "2.***"
#define BPF_3_MP3               "3.***"
#define BPF_4_MP3               "4.***"
#define BPF_5_MP3               "5.***"
#define BPF_6_MP3               "6.***"
#define BPF_7_MP3               "7.***"
#define BPF_8_MP3               "8.***"
#define BPF_9_MP3               "9.***"

#define BPF_LOW_POWER_MP3       "test.***"

#define BPF_TEST_MP3       		"test.***"
#define BPF_POWER_OFF       		"power_off.***"



#define BPF_RADIO_EN_MP3           "radio_en.***"
#define BPF_LINEIN_EN_MP3          "linein_en.***"
#define BPF_MUSIC_EN_MP3           "music_en.***"
#define BPF_REC_EN_MP3             "record_en.***"
#define BPF_BT_EN_MP3              "bt_en.***"
#define BPF_WAIT_EN_MP3            "wait_en.***"
#define BPF_CONNECT_EN_MP3         "connect_en.***"
#define BPF_DISCONNECT_EN_MP3      "disconnect_e.***"



#elif defined AC6905B_512K

#define BPF_BT_MP3              "bt.***"
#define BPF_RADIO_MP3           "radio.***"
#define BPF_LINEIN_MP3          "linein.***"
#define BPF_MUSIC_MP3           "music.***"
#define BPF_CONNECT_MP3         "connect.***"
#define BPF_DISCONNECT_MP3      "disconnect.***"
#define BPF_LOW_POWER_MP3       "lowpower.***"


#if BT_HID_INDEPENDENT_MODE || USER_SUPPORT_PROFILE_HID
#define BPF_INIT_HID_MP3               "hid.***"
#define BPF_CONN_HID_MP3               "conn_hid.***"
#define BPF_DISCON_HID_MP3               "discon_hid.***"
#endif

#else
#define BPF_BT_MP3              "bt.***"
#define BPF_PC_MP3              "pc.***"
#define BPF_RADIO_MP3           "radio.***"
#define BPF_LINEIN_MP3          "linein.***"
#define BPF_MUSIC_MP3           "music.***"
#define BPF_RTC_MP3             "rtc.***"
#define BPF_PC_MP3              "pc.***"
#define BPF_ECHO_MP3            "echo.***"
#define BPF_REC_MP3             "record.***"

#define BPF_WAIT_MP3            "wait.***"
#define BPF_POWER_OFF_MP3       "power_off.***"
#define BPF_CONNECT_MP3         "connect.***"
#define BPF_DISCONNECT_MP3      "disconnect.***"
#define BPF_RING_MP3            "ring.***"

#if BT_PHONE_NUMBER||SUPPORT_VOICE_NUMBER
#define BPF_0_MP3               "0.***"
#define BPF_1_MP3               "1.***"
#define BPF_2_MP3               "2.***"
#define BPF_3_MP3               "3.***"
#define BPF_4_MP3               "4.***"
#define BPF_5_MP3               "5.***"
#define BPF_6_MP3               "6.***"
#define BPF_7_MP3               "7.***"
#define BPF_8_MP3               "8.***"
#define BPF_9_MP3               "9.***"
#endif

#if BT_HID_INDEPENDENT_MODE || USER_SUPPORT_PROFILE_HID
#define BPF_INIT_HID_MP3               "hid.***"
#define BPF_CONN_HID_MP3               "conn_hid.***"
#define BPF_DISCON_HID_MP3               "discon_hid.***"
#endif

#if MEDIA_MODE_USB_SD_DETECT	
#define BPF_MUSIC_USB_MP3      "usb.***"
#define BPF_MUSIC_SD_MP3     "sd.***"
#endif

#ifdef SUPPORT_POWER_ON_TONE
#define BPF_WELCOME_MP3      "welcome.***"
#endif

#ifdef SUPPORT_LOW_POWER_VOICE
#define BPF_LOW_POWER_MP3      "lowpower.***"
#else
#define BPF_LOW_POWER_MP3       "test.***"
#endif
#define BPF_MUSIC_PLAY_MP3      "test.***"
#define BPF_MUSIC_PAUSE_MP3     "test.***"
#define BPF_TEST_MP3       		"test.***"
#define BPF_POWER_OFF       		"power_off.***"



#if defined SUPPORT_MODE_VOICE_ONOFF	
#define BPF_BT_NOTICE_MP3              "bt_n.***"
#define BPF_CONNECT_NOTICE_MP3         "connect_n.***"
#define BPF_DISCONNECT_NOTICE_MP3      "disconnect_n.***"
#endif

#endif

typedef struct __PLAY_SEL_PARA //para
{
    u32 max_file_number;
    u32 rpt_time;
    u32 delay;
    u32 *file_number;       //文件号播放
    void **file_name;         //文件名播放
} _PLAY_SEL_PARA;
/////*/

typedef struct __PLAY_SEL_API
{
    u32 device_sel;
    _PLAY_SEL_PARA *file_par;
    tbool busy;
    tbool alive;
    void *father_name;
} _PLAY_SEL_API;

tbool play_sel(void *name,u32 device_sel,_PLAY_SEL_PARA *file_par);
tbool play_sel_busy(void);
tbool play_sel_stop(void);
void play_sel_play_decoder(_MUSIC_API *mapi);
void play_sel_pause_decoder(_MUSIC_API *mapi);
tbool tone_play(void *task_name, u32 file_num);
// tbool tone_play_by_name(void *task_name, void * file_name);
tbool tone_play_by_name(void *task_name, u32 total_file, ...);
void * tone_number_get_name(u32 number);
#endif
