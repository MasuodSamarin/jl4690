
#if 0

#define KEY9_RES 0   ///pp
#define KEY8_RES 3.6 //mic
#define KEY7_RES 6.8  //
#define KEY6_RES 9.1  // prev
#define KEY5_RES 15  //
#define KEY4_RES 24  //next
#define KEY3_RES 33  //
#define KEY2_RES 51  //mode
#define KEY1_RES 100  //rec
#define KEY0_NOKEY_RES 220 // repeat

#endif
/*******************************************************************
                        MUSIC   AD按键表
*******************************************************************/

#define ADKEY_DECODE_SHORT		\
                        /*00 220k */  MSG_MUSIC_RPT,\
                        /*01  100k*/  MSG_REC_START,\
                        /*02  51k */   MSG_CHANGE_WORKMODE,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    MSG_MUSIC_NEXT_FILE,\
                        /*05 15k */    NO_MSG,\
                        /*06 9k1*/      MSG_MUSIC_PREV_FILE,\
                        /*07  6k2*/    NO_MSG,\
                        /*08 3k*/       MSG_MIC_ONOFF,\
                        /*09 0*/         MSG_MUSIC_PP,

#define ADKEY_DECODE_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_UP,\
                        /*05*/    NO_MSG,\
                        /*06*/    MSG_VOL_DOWN,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define ADKEY_DECODE_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_UP,\
                        /*05*/    NO_MSG,\
                        /*06*/    MSG_VOL_DOWN,\
                        /*07*/    NO_MSG,\
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
                        /*00 220k */  NO_MSG,\
                        /*01  100k*/  NO_MSG,\
                        /*02  51k */   MSG_CHANGE_WORKMODE,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    MSG_FM_NEXT_STATION,\
                        /*05 15k */    NO_MSG,\
                        /*06 9k1*/      MSG_FM_PREV_STATION,\
                        /*07  6k2*/    NO_MSG,\
                        /*08 3k*/       MSG_MIC_ONOFF,\
                        /*09 0*/         MSG_FM_SEARCHING,
                        

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
                        /*09*/    NO_MSG,



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
                        /*09*/    NO_MSG,

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
                        /*00 220k */  NO_MSG,\
                        /*01  100k*/  NO_MSG,\
                        /*02  51k */   MSG_CHANGE_WORKMODE,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    NO_MSG,\
                        /*05 15k */    NO_MSG,\
                        /*06 9k1*/      NO_MSG,\
                        /*07  6k2*/    NO_MSG,\
                        /*08 3k*/       MSG_MIC_ONOFF,\
                        /*09 0*/         MSG_AUX_PAUSE,
                        


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
                        /*09*/    NO_MSG,


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
                        /*09*/    NO_MSG,

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
                        /*00 220k */  NO_MSG,\
                        /*01  100k*/  NO_MSG,\
                        /*02  51k */   MSG_CHANGE_WORKMODE,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    MSG_BT_NEXT_FILE,\
                        /*05 15k */    NO_MSG,\
                        /*06 9k1*/      MSG_BT_PREV_FILE,\
                        /*07  6k2*/    NO_MSG,\
                        /*08 3k*/       MSG_MIC_ONOFF,\
                        /*09 0*/         MSG_BT_PP,
                        
 
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
                        /*09*/    NO_MSG,



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
                        /*09*/    NO_MSG,

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
/*01*/    MSG_REC_STOP,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
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
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    MSG_CHANGE_WORKMODE,\
                        /*07*/    MSG_PC_PLAY_NEXT,\
                        /*08*/    MSG_PC_PLAY_PREV,\
                        /*09*/   MSG_PC_PP ,

#define ADKEY_USB_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    MSG_PC_VOL_UP,\
                        /*08*/    MSG_PC_VOL_DOWN,\
                        /*09*/    MSG_PC_MUTE,


#define ADKEY_USB_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    MSG_PC_VOL_UP,\
                        /*08*/    MSG_PC_VOL_DOWN,\
                        /*09*/    NO_MSG,

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
                        /*09*/    NO_MSG,

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






/*******************************************************************
                            AD按键表
*******************************************************************/
#define ADKEY_IDLE_SHORT		\
                        /*00*/    MSG_IDLE_CTL,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

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

#if RTC_CLK_EN

/*RTC  */
#define ADKEY_RTC_SHORT		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    MSG_ALM_SW    ,\
                        /*06*/    MSG_CHANGE_WORKMODE,\
                        /*07*/    MSG_RTC_PLUS,\
                        /*08*/    MSG_RTC_MINUS,\
                        /*09*/    MSG_ALM_SETTING

#define ADKEY_RTC_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    MSG_RTC_SETTING,\
                        /*07*/    MSG_RTC_PLUS,\
                        /*08*/    MSG_RTC_MINUS,\
                        /*09*/    MSG_RTC_SETTING,


#define ADKEY_RTC_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    MSG_RTC_PLUS,\
                        /*08*/    MSG_RTC_MINUS,\
                        /*09*/    NO_MSG,

#define ADKEY_RTC_LONG_UP	\
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

