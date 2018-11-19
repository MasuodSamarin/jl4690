
/*******************************************************************
#define PULL_UP_RESISTANCE 10   //上拉电阻
#define KEYE_RES 0  //eq
#define KEYD_RES 1.2 	 //repeat	0.3
#define KEYC_RES 2.4 	 //pp	0.55
#define KEYB_RES 3.3 //null		0.8
#define KEYA_RES 4.3  //mode  		1v
#define KEY9_RES 5.1 //null		1.2
#define KEY8_RES 6.6 //v+  		1.4
#define KEY7_RES 10   //v-		1.65
#define KEY6_RES 12  // 			1.8
#define KEY5_RES 16  //next/v+			2.0
#define KEY4_RES 20 // 			2.2	
#define KEY3_RES 27 //prev/v-		2.4
#define KEY2_RES 47 //folder+		2.7
#define KEY1_RES 68 // null		2.87
#define KEY0_NOKEY_RES 100	 //stop	 3v

MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/    MSG_MUSIC_STOP,\
/*01*/    NO_MSG,\
/*02*/     MSG_FOLDER_NEXT,\
/*03*/     MSG_MUSIC_PREV_FILE,\
/*04*/     NO_MSG,\
/*05*/     MSG_MUSIC_NEXT_FILE,\
/*06*/     NO_MSG,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_VOL_UP,\
/*09*/  	  NO_MSG ,\
/*0A*/	  MSG_CHANGE_WORKMODE,\
/*0B*/	  NO_MSG ,\
/*0C*/	  MSG_MUSIC_PP ,\
/*0D*/	  MSG_MUSIC_RPT ,\
/*0E*/	  MSG_MUSIC_EQ 

#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
/*09*/    NO_MSG,\
/*0A*/	 NO_MSG,\
/*0B*/	 NO_MSG,\
/*0C*/	 NO_MSG,\
/*0D*/	 NO_MSG,\
/*0E*/	 NO_MSG

#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
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
/*01*/    NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     MSG_FM_PREV_STATION,\
/*04*/     NO_MSG,\
/*05*/     MSG_FM_NEXT_STATION,\
/*06*/     NO_MSG,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_VOL_UP,\
/*09*/  	  NO_MSG ,\
/*0A*/	  MSG_CHANGE_WORKMODE,\
/*0B*/	  NO_MSG ,\
/*0C*/	  MSG_FM_SCAN_ALL_INIT ,\
/*0D*/	  NO_MSG ,\
/*0E*/	  NO_MSG 



#define ADKEY_FM_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
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
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
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
/*01*/    NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     MSG_VOL_DOWN,\
/*04*/     NO_MSG,\
/*05*/     MSG_VOL_UP,\
/*06*/     NO_MSG,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_VOL_UP,\
/*09*/  	  NO_MSG ,\
/*0A*/	  MSG_CHANGE_WORKMODE,\
/*0B*/	  NO_MSG ,\
/*0C*/	  MSG_AUX_MUTE ,\
/*0D*/	  NO_MSG ,\
/*0E*/	  NO_MSG 


#define ADKEY_AUX_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
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
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
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
/*01*/    NO_MSG,\
/*02*/     NO_MSG,\
/*03*/     MSG_BT_PREV_FILE,\
/*04*/     NO_MSG,\
/*05*/     MSG_BT_NEXT_FILE,\
/*06*/     NO_MSG,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_VOL_UP,\
/*09*/  	  NO_MSG ,\
/*0A*/	  MSG_CHANGE_WORKMODE,\
/*0B*/	  NO_MSG ,\
/*0C*/	  MSG_BT_PP ,\
/*0D*/	  NO_MSG ,\
/*0E*/	  NO_MSG 


#define ADKEY_BT_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
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
/*03*/    MSG_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    MSG_VOL_UP,\
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
/*02*/     NO_MSG,\
/*03*/     MSG_PC_PLAY_PREV,\
/*04*/     NO_MSG,\
/*05*/     MSG_PC_PLAY_NEXT,\
/*06*/     NO_MSG,\
/*07*/     MSG_PC_VOL_DOWN,\
/*08*/     MSG_PC_VOL_UP,\
/*09*/  	  NO_MSG ,\
/*0A*/	  MSG_CHANGE_WORKMODE,\
/*0B*/	  NO_MSG ,\
/*0C*/	  MSG_PC_PP ,\
/*0D*/	  NO_MSG ,\
/*0E*/	  NO_MSG 


#define ADKEY_USB_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    MSG_PC_VOL_DOWN,\
/*04*/    NO_MSG,\
/*05*/    MSG_PC_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_PC_VOL_DOWN,\
/*08*/    MSG_PC_VOL_UP,\
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
/*04*/    NO_MSG,\
/*05*/    MSG_PC_VOL_UP,\
/*06*/    NO_MSG,\
/*07*/    MSG_PC_VOL_DOWN,\
/*08*/    MSG_PC_VOL_UP,\
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

