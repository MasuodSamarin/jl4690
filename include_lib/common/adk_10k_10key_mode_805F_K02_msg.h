
#define KEY9_RES 0 //pp
#define KEY8_RES 3 //prev/v-
#define KEY7_RES 6.2   //next/v+
#define KEY6_RES 9.1  //mode
#define KEY5_RES 15  //eq		
#define KEY4_RES 24 //rpt
#define KEY3_RES 33 //stop
#define KEY2_RES 51 //mute
#define KEY1_RES 100 //rec
#define KEY0_NOKEY_RES 220

/*******************************************************************
MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/     MSG_MUSIC_PLAY_REC_FILE,\
/*01*/     MSG_MUSIC_PLAY_REC_FILE,\
/*02*/     MSG_MUTE,\
/*03*/     MSG_MUSIC_STOP,\
/*04*/   	 MSG_MUSIC_RPT,\
/*05*/     MSG_MUSIC_EQ,\
/*06*/     MSG_CHANGE_WORKMODE,\
/*07*/     MSG_MUSIC_NEXT_FILE,\
/*08*/     MSG_MUSIC_PREV_FILE,\
/*09*/  	  MSG_MUSIC_PP


#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    MSG_REC_START,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG


#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG



#define ADKEY_DECODE_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG




/*******************************************************************
FM   AD按键表
*******************************************************************/

#define ADKEY_FM_SHORT		\
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     MSG_MUTE,\
/*03*/     NO_MSG,\
/*04*/   	 NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     MSG_CHANGE_WORKMODE,\
/*07*/     MSG_FM_NEXT_STATION,\
/*08*/     MSG_FM_PREV_STATION,\
/*09*/  	  MSG_FM_SCAN_ALL_INIT

#define ADKEY_FM_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG



#define ADKEY_FM_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG



#define ADKEY_FM_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG
/*******************************************************************
LINE    AD按键表
*******************************************************************/

#define ADKEY_AUX_SHORT		\
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     MSG_MUTE,\
/*03*/     NO_MSG,\
/*04*/   	 NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     MSG_CHANGE_WORKMODE,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/  	  MSG_AUX_MUTE


#define ADKEY_AUX_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG



#define ADKEY_AUX_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG



#define ADKEY_AUX_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG

/*******************************************************************
BT   AD按键表
*******************************************************************/

#define ADKEY_BT_SHORT		\
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     MSG_MUTE,\
/*03*/     NO_MSG,\
/*04*/   	 NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     MSG_CHANGE_WORKMODE,\
/*07*/     MSG_BT_NEXT_FILE,\
/*08*/     MSG_BT_PREV_FILE,\
/*09*/  	  MSG_BT_PP
	

#define ADKEY_BT_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG


#define ADKEY_BT_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG



#define ADKEY_BT_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG


/*******************************************************************
USB   AD按键表
*******************************************************************/
#define ADKEY_USB_SHORT		\
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     MSG_MUTE,\
/*03*/     NO_MSG,\
/*04*/   	 NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     MSG_CHANGE_WORKMODE,\
/*07*/     MSG_PC_PLAY_NEXT,\
/*08*/     MSG_PC_PLAY_PREV,\
/*09*/  	  MSG_PC_PP

#define ADKEY_USB_LONG		\
/*00*/    NO_MSG,\
/*01*/    MSG_REC_START,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG





#define ADKEY_USB_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    MSG_VOL_DOWN,\
/*09*/    NO_MSG

#define ADKEY_USB_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG


// REC KEY  
#if REC_EN

/*******************************************************************
	REC   AD按键表
*******************************************************************/

#define ADKEY_ENC_SHORT		\
/*00*/	  MSG_REC_STOP,\
/*01*/	  MSG_REC_STOP,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,\

#define ADKEY_ENC_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG


#define ADKEY_ENC_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG

#define ADKEY_ENC_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG
#endif

/*******************************************************************
main 按键表
*******************************************************************/
#define ADKEY_MAIN_SHORT		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG
#define ADKEY_MAIN_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG

#define ADKEY_MAIN_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG

#define ADKEY_MAIN_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG

/*******************************************************************
AD按键表
*******************************************************************/
#define ADKEY_IDLE_SHORT		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     MSG_STANBY_KEY,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG

#define ADKEY_IDLE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG


#define ADKEY_IDLE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG


#define ADKEY_IDLE_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/     NO_MSG



