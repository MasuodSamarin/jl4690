
/*******************************************************************

#define PULL_UP_RESISTANCE 22   //上拉电阻
#define KEYF_RES 0   //PP  
#define KEYE_RES 1   //RECPLAY/REC 	 0.13
#define KEYD_RES 2    //0	 0.27
#define KEYC_RES 3.3  // MODE		0.47
#define KEYB_RES 5.1  // 1			0.62
#define KEYA_RES 7.5  // 2  		0.83
#define KEY9_RES 10  //  repeat		1V
#define KEY8_RES 15  //   3  		1.33
#define KEY7_RES 20   //  next		1.57
#define KEY6_RES 27  //   4		1.81
#define KEY5_RES 33  //   prev		1.98
#define KEY4_RES 42 //	5		2.24
#define KEY3_RES 62 //	6		2.43
#define KEY2_RES 82 // 	7		2.6
#define KEY1_RES 120 //  	8		2.78
#define KEY0_NOKEY_RES 220	//  9 3v


MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/    MSG_9,\
/*01*/    MSG_8,\
/*02*/    MSG_7,\
/*03*/    MSG_6,\
/*04*/    MSG_5,\
/*05*/    MSG_MUSIC_PREV_FILE,\
/*06*/    MSG_4,\
/*07*/    MSG_MUSIC_NEXT_FILE,\
/*08*/    MSG_3,\
/*09*/    MSG_MUSIC_RPT,\
/*0A*/	 MSG_2,\
/*0B*/	 MSG_1,\
/*0C*/	 MSG_CHANGE_WORKMODE,\
/*0D*/	 MSG_0,\
/*0E*/	 MSG_MUSIC_PLAY_REC_FILE,\
/*0F*/	 MSG_MUSIC_PP


#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    MSG_MUSIC_DEL_FILE,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 MSG_REC_START,\
/*0E*/	 NO_MSG

#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
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
/*00*/    MSG_9,\
/*01*/    MSG_8,\
/*02*/    MSG_7,\
/*03*/    MSG_6,\
/*04*/    MSG_5,\
/*05*/    MSG_FM_PREV_STATION,\
/*06*/    MSG_4,\
/*07*/    MSG_FM_NEXT_STATION,\
/*08*/    MSG_3,\
/*09*/    NO_MSG,\
/*0A*/	 MSG_2,\
/*0B*/	 MSG_1,\
/*0C*/	 MSG_CHANGE_WORKMODE,\
/*0D*/	 MSG_0,\
/*0E*/	 NO_MSG,\
/*0F*/	 MSG_FM_SCAN_ALL_INIT



#define ADKEY_FM_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG


#define ADKEY_FM_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG


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
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 MSG_CHANGE_WORKMODE,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 MSG_AUX_MUTE


#define ADKEY_AUX_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG



#define ADKEY_AUX_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG


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
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_BT_PREV_FILE,\
/*06*/    NO_MSG,\
/*07*/    MSG_BT_NEXT_FILE,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 MSG_CHANGE_WORKMODE,\
/*0D*/	 MSG_BT_PREV_FILE,\
/*0E*/	 NO_MSG,\
/*0F*/	 MSG_BT_PP



#define ADKEY_BT_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

#define ADKEY_BT_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

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
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG




#define ADKEY_USB_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_DOWN,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_UP,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

#define ADKEY_USB_LONG_UP	\
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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

// REC KEY  
#if REC_EN

/*******************************************************************
	REC   AD按键表
*******************************************************************/

#define ADKEY_ENC_SHORT		\
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
/*0E*/	 MSG_REC_STOP,\
/*0F*/	 NO_MSG

	

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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG


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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG
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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG


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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG


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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

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
/*0E*/	 NO_MSG,\
/*0F*/	 NO_MSG

