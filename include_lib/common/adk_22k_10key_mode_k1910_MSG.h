
/*******************************************************************

#define PULL_UP_RESISTANCE 22   //上拉电阻
#define KEYA_RES 0  //pp/rec
#define KEY9_RES 1 // null
#define KEY8_RES 3.3 // mode
#define KEY7_RES 7.5   //   bt
#define KEY6_RES 10  //   repeat
#define KEY5_RES 15  //  	eq
#define KEY4_RES 20 // next
#define KEY3_RES 33 //  prev
#define KEY2_RES 56 // fol+
#define KEY1_RES 100 //stop
#define KEY0_NOKEY_RES 220	 //

MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/     NO_MSG,\
/*01*/     MSG_MUSIC_STOP,\
/*02*/     MSG_MUSIC_FFR_DONE,\
/*03*/     MSG_MUSIC_PREV_FILE,\
/*04*/     MSG_MUSIC_NEXT_FILE,\
/*05*/     MSG_MUSIC_EQ,\
/*06*/     MSG_MUSIC_RPT,\
/*07*/     MSG_BT_MODE_KEY,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  NO_MSG,\
/*0A*/	  MSG_MUSIC_PP

#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    MSG_MUSIC_DEL_FILE,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    MSG_VOL_UP,\
/*0A*/	 NO_MSG
#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG

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
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     MSG_FM_PREV_STATION,\
/*04*/     MSG_FM_NEXT_STATION,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     MSG_BT_MODE_KEY,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  NO_MSG,\
/*0A*/	  MSG_FM_SCAN_ALL_INIT


#define ADKEY_FM_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG


#define ADKEY_FM_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG


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
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     NO_MSG,\
/*04*/     NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     MSG_BT_MODE_KEY,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  NO_MSG,\
/*0A*/	  MSG_AUX_PAUSE
	
#define ADKEY_AUX_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG

#define ADKEY_AUX_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG


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
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     MSG_BT_PREV_FILE,\
/*04*/     MSG_BT_NEXT_FILE,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  NO_MSG,\
/*0A*/	  MSG_BT_PP



#define ADKEY_BT_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG


#define ADKEY_BT_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG

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
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     MSG_PC_PLAY_PREV,\
/*04*/     MSG_PC_PLAY_NEXT,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  NO_MSG,\
/*0A*/	  MSG_PC_PP


#define ADKEY_USB_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG




#define ADKEY_USB_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    MSG_VOL_UP,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG


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
/*00*/     NO_MSG,\
/*01*/     NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     NO_MSG,\
/*04*/     NO_MSG,\
/*05*/     NO_MSG,\
/*06*/     NO_MSG,\
/*07*/     NO_MSG,\
/*08*/     NO_MSG,\
/*09*/  	  MSG_REC_STOP,\
/*0A*/	  NO_MSG


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

