
#define PULL_UP_RESISTANCE 10   //��������
#define KEY9_RES 0 //pp
#define KEY8_RES 3.3 //mode
#define KEY7_RES 5.1   //v-
#define KEY6_RES 7.5  // v+
#define KEY5_RES 10  //mv-
#define KEY4_RES 15 //mv+
#define KEY3_RES 20 //next
#define KEY2_RES 33 //prve
#define KEY1_RES 56 // menu
#define KEY0_NOKEY_RES 220	 

/*******************************************************************
MUSIC   AD������
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
/*00*/     NO_MSG,\
/*01*/     MSG_MENU_MODE,\
/*02*/     MSG_MUSIC_PREV_FILE,\
/*03*/     MSG_MUSIC_NEXT_FILE,\
/*04*/   	 MSG_MIC_UP,\
/*05*/     MSG_MIC_DN,\
/*06*/     MSG_VOL_UP,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  MSG_MUSIC_PP


#define ADKEY_DECODE_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG


#define ADKEY_DECODE_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
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
FM   AD������
*******************************************************************/

#define ADKEY_FM_SHORT		\
/*00*/     NO_MSG,\
/*01*/     MSG_MENU_MODE,\
/*02*/     MSG_FM_PREV_STATION,\
/*03*/     MSG_FM_NEXT_STATION,\
/*04*/   	 MSG_MIC_UP,\
/*05*/     MSG_MIC_DN,\
/*06*/     MSG_VOL_UP,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  MSG_FM_SCAN_ALL_INIT


#define ADKEY_FM_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG



#define ADKEY_FM_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
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
LINE    AD������
*******************************************************************/

#define ADKEY_AUX_SHORT		\
/*00*/     NO_MSG,\
/*01*/     MSG_MENU_MODE,\
/*02*/     NO_MSG,\
/*03*/     NO_MSG,\
/*04*/   	 MSG_MIC_UP,\
/*05*/     MSG_MIC_DN,\
/*06*/     MSG_VOL_UP,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  MSG_AUX_MUTE



#define ADKEY_AUX_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG


#define ADKEY_AUX_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
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
BT   AD������
*******************************************************************/

#define ADKEY_BT_SHORT		\
/*00*/     NO_MSG,\
/*01*/     MSG_MENU_MODE,\
/*02*/     MSG_BT_PREV_FILE,\
/*03*/     MSG_BT_NEXT_FILE,\
/*04*/   	 MSG_MIC_UP,\
/*05*/     MSG_MIC_DN,\
/*06*/     MSG_VOL_UP,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  MSG_BT_PP
	

#define ADKEY_BT_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG

#define ADKEY_BT_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
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
USB   AD������
*******************************************************************/
#define ADKEY_USB_SHORT		\
/*00*/     NO_MSG,\
/*01*/     MSG_MENU_MODE,\
/*02*/     MSG_PC_PLAY_PREV,\
/*03*/     MSG_PC_PLAY_NEXT,\
/*04*/   	 MSG_MIC_UP,\
/*05*/     MSG_MIC_DN,\
/*06*/     MSG_VOL_UP,\
/*07*/     MSG_VOL_DOWN,\
/*08*/     MSG_CHANGE_WORKMODE,\
/*09*/  	  MSG_PC_PP

#define ADKEY_USB_LONG		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
/*09*/    NO_MSG





#define ADKEY_USB_HOLD		\
/*00*/    NO_MSG,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    MSG_MIC_UP,\
/*05*/    MSG_MIC_DN,\
/*06*/    MSG_VOL_UP,\
/*07*/    MSG_VOL_DOWN,\
/*08*/    NO_MSG,\
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
	REC   AD������
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
main ������
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
AD������
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


