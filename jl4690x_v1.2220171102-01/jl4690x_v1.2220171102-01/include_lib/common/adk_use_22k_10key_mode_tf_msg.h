#if 0

#define PULL_UP_RESISTANCE 30   //上拉电阻22K
#define KEY9_RES 0   //standby
#define KEY8_RES 3.3 //pp
#define KEY7_RES 7.5  //prev/v-
#define KEY6_RES 13  //next/v+
#define KEY5_RES 20  //mode
#define KEY4_RES 30  //record
#define KEY3_RES 47   // stop
#define KEY2_RES 68   		//repeat	
#define KEY1_RES 120 		//mute	
#define KEY0_NOKEY_RES 240 	//eq	

#endif

/*******************************************************************
MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/    MSG_MUSIC_EQ,\
/*01*/    MSG_MUTE,\
/*02*/    MSG_MUSIC_RPT,\
/*03*/    MSG_MUSIC_STOP,\
/*04*/    MSG_MUSIC_PLAY_REC_FILE,\
/*05*/    MSG_CHANGE_WORKMODE,\
/*06*/    MSG_MUSIC_NEXT_FILE,\
/*07*/    MSG_MUSIC_PREV_FILE,\
/*08*/    MSG_MUSIC_PP,\
/*09*/    MSG_STANBY_KEY,


#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_REC_START,\
/*05*/    NO_MSG,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,


#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/	 MSG_VOL_UP,\
/*07*/	 MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

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
/*09*/    NO_MSG,




/*******************************************************************
FM   AD按键表
*******************************************************************/

#define ADKEY_FM_SHORT		\
/*00*/    NO_MSG,\
/*01*/    MSG_MUTE,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_CHANGE_WORKMODE,\
/*06*/    MSG_FM_NEXT_STATION,\
/*07*/    MSG_FM_PREV_STATION,\
/*08*/    MSG_FM_SCAN_ALL_INIT,\
/*09*/    MSG_STANBY_KEY,


#define ADKEY_FM_LONG		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  MSG_VOL_UP,\
/*07*/	  MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,


#define ADKEY_FM_HOLD		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	 MSG_VOL_UP,\
/*07*/	 MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,

#define ADKEY_FM_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

/*******************************************************************
LINE    AD按键表
*******************************************************************/

#define ADKEY_AUX_SHORT		\
/*00*/    NO_MSG,\
/*01*/    MSG_MUTE,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_CHANGE_WORKMODE,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_AUX_PAUSE,\
/*09*/    MSG_STANBY_KEY,


#define ADKEY_AUX_LONG		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  MSG_VOL_UP,\
/*07*/	  MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,


#define ADKEY_AUX_HOLD		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	 MSG_VOL_UP,\
/*07*/	 MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,

#define ADKEY_AUX_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,


/*******************************************************************
BT   AD按键表
*******************************************************************/


#define ADKEY_BT_SHORT		\
/*00*/    NO_MSG,\
/*01*/    MSG_MUTE,\
/*02*/    NO_MSG,\
/*03*/    MSG_MUSIC_STOP,\
/*04*/    NO_MSG,\
/*05*/    MSG_CHANGE_WORKMODE,\
/*06*/    MSG_BT_NEXT_FILE,\
/*07*/    MSG_BT_PREV_FILE,\
/*08*/    MSG_BT_PP,\
/*09*/    MSG_STANBY_KEY,


#define ADKEY_BT_LONG		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  MSG_VOL_UP,\
/*07*/	  MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,


#define ADKEY_BT_HOLD		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  MSG_VOL_UP,\
/*07*/	  MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG

#define ADKEY_BT_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

/*******************************************************************
REC    AD按键表
*******************************************************************/
#ifdef  REC_EN
#define ADKEY_ENC_SHORT		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_REC_STOP,\
/*05*/    NO_MSG,\
/*08*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,



#define ADKEY_ENC_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,


#define ADKEY_ENC_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

#define ADKEY_ENC_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,
#endif

/*******************************************************************
USB   AD按键表
*******************************************************************/
#define ADKEY_USB_SHORT		\
/*00*/    NO_MSG,\
/*01*/    MSG_MUTE,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    MSG_CHANGE_WORKMODE,\
/*06*/	  MSG_PC_PLAY_NEXT,\
/*07*/	  MSG_PC_PLAY_PREV,\
/*08*/    MSG_PC_PP,\
/*09*/    MSG_STANBY_KEY,



#define ADKEY_USB_LONG		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  MSG_VOL_UP,\
/*07*/	  MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,


#define ADKEY_USB_HOLD		\
/*00*/	  NO_MSG,\
/*01*/	  NO_MSG,\
/*02*/	  NO_MSG,\
/*03*/	  NO_MSG,\
/*04*/	  NO_MSG,\
/*05*/	  NO_MSG,\
/*06*/	  MSG_VOL_UP,\
/*07*/	  MSG_VOL_DOWN,\
/*08*/	  NO_MSG,\
/*09*/	  NO_MSG,

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
/*09*/	  NO_MSG,

/*******************************************************************
main 按键表
*******************************************************************/
#define ADKEY_MAIN_SHORT		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

#define ADKEY_MAIN_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,


#define ADKEY_MAIN_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

#define ADKEY_MAIN_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,


// STANBY  

#define ADKEY_STANBY_SHORT		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09 MSG_AUX_MUTE*/    NO_MSG ,

#define ADKEY_STANBY_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,


#define ADKEY_STANBY_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

#define ADKEY_STANBY_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

/*******************************************************************
AD按键表
*******************************************************************/
#define ADKEY_IDLE_SHORT		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/	  NO_MSG,\
/*07*/	  NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    MSG_STANBY_KEY,



#define ADKEY_IDLE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,


#define ADKEY_IDLE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

#define ADKEY_IDLE_LONG_UP	\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG,

