
/*******************************************************************

#define PULL_UP_RESISTANCE 10   //上拉电阻10K
#define KEYE_RES 0  //PP
#define KEYD_RES 0.47 //NULL		0.15
#define KEYC_RES 1 	 //next/ff	0.3
#define KEYB_RES 2  	 //prev/fr	0.55
#define KEYA_RES 3.3 //mode		0.8
#define KEY9_RES 4.7  //v-  		1v
#define KEY8_RES 5.6 //v+			1.2
#define KEY7_RES 7.5 //bt  			1.4
#define KEY6_RES 10   //repeat		1.65
#define KEY5_RES 12  // 			1.8
#define KEY4_RES 15  //eq			2.0
#define KEY3_RES 20 //next/v+	2.2	
#define KEY2_RES 33 //prev/v-		2.5
#define KEY1_RES 56 //standby		2.8
#define KEY0_NOKEY_RES 100	 //	 3v

MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/    MSG_MUSIC_STOP,\
/*01*/    MSG_MUTE,\
/*02*/     MSG_STANBY_KEY,\
/*03*/     MSG_MUSIC_PREV_VOICE,\
/*04*/     MSG_MUSIC_NEXT_VOICE,\
/*05*/     MSG_MUSIC_EQ,\
/*06*/     NO_MSG,\
/*07*/     MSG_MUSIC_RPT,\
/*08*/     MSG_VOL_DOWN,\
/*09*/  	 MSG_VOL_UP,\
/*0A*/	  NO_MSG,\
/*0B*/	  MSG_CHANGE_WORKMODE,\
/*0C*/	  MSG_MUSIC_PREV_FILE,\
/*0D*/	  MSG_MUSIC_NEXT_FILE,\
/*0E*/	  MSG_MUSIC_PP

#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	 MSG_MUSIC_VOICE_SWITCH,\
/*0C*/	 MSG_MUSIC_FR,\
/*0D*/	 MSG_MUSIC_FF,\
/*0E*/	 MSG_MUSIC_VOICE_CHANGE

#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 MSG_MUSIC_FR,\
/*0D*/	 MSG_MUSIC_FF,\
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
/*02*/     MSG_STANBY_KEY,\
/*03*/     MSG_FM_PREV_STATION,\
/*04*/     MSG_FM_NEXT_STATION,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     MSG_VOL_DOWN,\
/*09*/     MSG_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	  MSG_CHANGE_WORKMODE,\
/*0C*/	  MSG_FM_PREV_STATION,\
/*0D*/	  MSG_FM_NEXT_STATION,\
/*0E*/	  MSG_FM_SCAN_ALL_INIT


#define ADKEY_FM_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	 MSG_FM_VOICE_SWITCH,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 MSG_FM_VOICE_CHANGE


#define ADKEY_FM_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
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
/*02*/    MSG_STANBY_KEY,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	   MSG_CHANGE_WORKMODE,\
/*0C*/	   NO_MSG,\
/*0D*/	   NO_MSG,\
/*0E*/	  MSG_AUX_MUTE

#define ADKEY_AUX_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	 MSG_AUX_VOICE_SWITCH,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 MSG_AUX_VOICE_CHANGE



#define ADKEY_AUX_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
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
/*02*/    MSG_STANBY_KEY,\
/*03*/    MSG_BT_PREV_FILE,\
/*04*/    MSG_BT_NEXT_FILE,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
/*0A*/	NO_MSG,\
/*0B*/	 MSG_CHANGE_WORKMODE,\
/*0C*/	 MSG_BT_PREV_FILE,\
/*0D*/	 MSG_BT_NEXT_FILE,\
/*0E*/	  MSG_BT_PP

#define ADKEY_BT_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	 MSG_AUX_VOICE_SWITCH,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 MSG_AUX_VOICE_CHANGE


#define ADKEY_BT_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    MSG_VOL_UP,\
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
/*02*/   MSG_STANBY_KEY,\
/*03*/   MSG_PC_PLAY_PREV,\
/*04*/   MSG_PC_PLAY_NEXT,\
/*05*/   NO_MSG,\
/*06*/   NO_MSG,\
/*07*/   NO_MSG,\
/*08*/   MSG_PC_VOL_DOWN,\
/*09*/  	MSG_PC_VOL_UP,\
/*0A*/	 NO_MSG,\
/*0B*/	  MSG_CHANGE_WORKMODE,\
/*0C*/	  MSG_PC_PLAY_PREV,\
/*0D*/	  MSG_PC_PLAY_NEXT,\
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
/*08*/    MSG_PC_VOL_DOWN,\
/*09*/    MSG_PC_VOL_UP,\
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
/*08*/    MSG_PC_VOL_DOWN,\
/*09*/    MSG_PC_VOL_UP,\
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
/*0D*/	 NO_MSG,\
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
/*02*/	  MSG_STANBY_KEY,\
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

