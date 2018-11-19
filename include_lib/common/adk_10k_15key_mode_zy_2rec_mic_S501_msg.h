
/*******************************************************************

#define PULL_UP_RESISTANCE 10   //上拉电阻10K
#define KEYE_RES 0  //PP/rec
#define KEYD_RES 1 	 //rec/recplay0.3
#define KEYC_RES 2  	 //null	0.55
#define KEYB_RES 3.3 //mode/recplay	0.8
#define KEYA_RES 4.7  //null  		1v
#define KEY9_RES 5.6 //null		1.2
#define KEY8_RES 7.5 //bt  		1.4
#define KEY7_RES 10   //repeat/del	1.65
#define KEY6_RES 12  // rgb			1.8
#define KEY5_RES 15  //eq			2.0
#define KEY4_RES 20 //next/v+	2.2	
#define KEY3_RES 33 //prev/v-		2.5
#define KEY2_RES 56 //mic		2.8
#define KEY1_RES 68 // mute		2.87
#define KEY0_NOKEY_RES 100	 //stop	 3v

MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/    MSG_MUSIC_STOP,\
/*01*/    MSG_MUTE,\
/*02*/     MSG_MIC_ONOFF,\
/*03*/     MSG_MUSIC_PREV_FILE,\
/*04*/     MSG_MUSIC_NEXT_FILE,\
/*05*/     MSG_MUSIC_EQ,\
/*06*/     NO_MSG,\
/*07*/     MSG_MUSIC_RPT,\
/*08*/     MSG_BT_MODE_KEY,\
/*09*/  	 NO_MSG,\
/*0A*/	  NO_MSG,\
/*0B*/	  MSG_CHANGE_WORKMODE,\
/*0C*/	  NO_MSG,\
/*0D*/	   MSG_REC_START,\
/*0E*/	  MSG_MUSIC_PP

#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_MUSIC_FR,\
/*04*/    MSG_MUSIC_FF,\
/*05*/    MSG_RGB_LED_MODE,\
/*06*/    NO_MSG,\
/*07*/    MSG_MUSIC_DEL_FILE,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 MSG_MUSIC_PLAY_REC_FILE,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_MUSIC_FR,\
/*04*/    MSG_MUSIC_FF,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_DECODE_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG



/*******************************************************************
FM   AD按键表
*******************************************************************/

#define ADKEY_FM_SHORT		\
/*00*/    NO_MSG,\
/*01*/    MSG_MUTE,\
/*02*/     MSG_MIC_ONOFF,\
/*03*/     MSG_FM_PREV_STATION,\
/*04*/     MSG_FM_NEXT_STATION,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     MSG_BT_MODE_KEY,\
/*09*/     NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	  MSG_CHANGE_WORKMODE,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	  MSG_FM_SCAN_ALL_INIT


#define ADKEY_FM_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_FM_SCAN_ALL_DOWN,\
/*04*/    MSG_FM_SCAN_ALL_UP,\
/*05*/    MSG_RGB_LED_MODE,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_FM_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_FM_LONG_UP	\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

/*******************************************************************
LINE    AD按键表
*******************************************************************/

#define ADKEY_AUX_SHORT		\
/*00*/    NO_MSG,\
/*01*/    MSG_MUTE,\
/*02*/    MSG_MIC_ONOFF,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_BT_MODE_KEY,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	   MSG_CHANGE_WORKMODE,\
/*0C*/	   NO_MSG,\
/*0D*/	   NO_MSG,\
/*0E*/	  MSG_AUX_MUTE

#define ADKEY_AUX_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_RGB_LED_MODE,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG



#define ADKEY_AUX_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_AUX_LONG_UP	\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

/*******************************************************************
BT   AD按键表
*******************************************************************/

#define ADKEY_BT_SHORT		\
/*00*/    NO_MSG,\
/*01*/    MSG_MUTE,\
/*02*/    MSG_MIC_ONOFF,\
/*03*/    MSG_BT_PREV_FILE,\
/*04*/    MSG_BT_NEXT_FILE,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_BT_MODE_KEY,\
/*09*/    NO_MSG,\
/*0A*/	NO_MSG,\
/*0B*/	 MSG_CHANGE_WORKMODE,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	  MSG_BT_PP

#define ADKEY_BT_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_RGB_LED_MODE,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_BT_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_BT_LONG_UP	\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


/*******************************************************************
USB   AD按键表
*******************************************************************/
#define ADKEY_USB_SHORT		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/   MSG_MIC_ONOFF,\
/*03*/   MSG_PC_PLAY_PREV,\
/*04*/   MSG_PC_PLAY_NEXT,\
/*05*/   NO_MSG,\
/*06*/   NO_MSG,\
/*07*/   NO_MSG,\
/*08*/    MSG_BT_MODE_KEY,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	  MSG_CHANGE_WORKMODE,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	  MSG_PC_PP

#define ADKEY_USB_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_PC_VOL_DOWN,\
/*04*/    MSG_PC_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG




#define ADKEY_USB_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_PC_VOL_DOWN,\
/*04*/    MSG_PC_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_USB_LONG_UP	\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

// REC KEY  
#if REC_EN

/*******************************************************************
	REC   AD按键表
*******************************************************************/

#define ADKEY_ENC_SHORT		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 MSG_REC_STOP,\
/*0E*/	 NO_MSG

#define ADKEY_ENC_LONG		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_ENC_HOLD		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_ENC_LONG_UP	\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG
#endif

/*******************************************************************
main 按键表
*******************************************************************/
#define ADKEY_MAIN_SHORT		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_MAIN_LONG		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_MAIN_HOLD		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_MAIN_LONG_UP	\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

/*******************************************************************
AD按键表
*******************************************************************/
#define ADKEY_IDLE_SHORT		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_IDLE_LONG		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG


#define ADKEY_IDLE_HOLD		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_IDLE_LONG_UP	\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

