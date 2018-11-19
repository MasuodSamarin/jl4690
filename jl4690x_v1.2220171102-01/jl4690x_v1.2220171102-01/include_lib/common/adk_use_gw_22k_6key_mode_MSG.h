


#define PULL_UP_RESISTANCE 22   //上拉电阻10K
#define KEYA_RES  0  // mode
#define KEY9_RES  3 // prev
#define KEY8_RES 6.2 // NEXT
#define KEY7_RES 9.1   //stanby		
#define KEY6_RES 15  // pp	
#define KEY5_RES 24  //  prev/v-	
#define KEY4_RES 33 // eq	
#define KEY3_RES 51 //  	next/v+
#define KEY2_RES 100//onoff
#define KEY1_RES 150 // 	rpt
#define KEY0_NOKEY_RES 330	 //	



/*******************************************************************
                        MUSIC   AD按键表
*******************************************************************/

#define ADKEY_DECODE_SHORT		\
                        /*00*/    MSG_MUSIC_RPT,\
                        /*00 220k */  MSG_MUSIC_RPT,\
                        /*01  100k*/  MSG_SW_ENCODER,\
                        /*02  51k */   MSG_MUSIC_NEXT_FILE,\
                        /*03  33k*/    MSG_MUSIC_EQ,\
                        /*04 24k */    MSG_MUSIC_PREV_FILE,\
                        /*05 15k */    MSG_MUSIC_PP,\
                        /*06 9k1*/      MSG_STANBY_KEY,\
                        /*07  6k2*/    MSG_MUSIC_NEXT_FILE,\
                        /*08 3k*/       MSG_MUSIC_PREV_FILE,\
                        /*09 0*/        MSG_CHANGE_WORKMODE ,

#define ADKEY_DECODE_LONG		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define ADKEY_DECODE_HOLD		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
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

#ifdef LONG_PP_KEY_AS_FM_SCAN
#define ADKEY_FM_SHORT		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG ,\
                        /*05*/    NO_MSG,\
                        /*06*/    MSG_CHANGE_WORKMODE,\
                        /*07*/    MSG_FM_NEXT_STATION,\
                        /*08*/    MSG_FM_PREV_STATION,\
                        /*09*/    MSG_FM_PP,

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
                        /*09*/    MSG_FM_SCAN_ALL_INIT,
#else 
#define ADKEY_FM_SHORT		\
                        /*00*/    NO_MSG,\
                        /*00 220k */  NO_MSG,\
                        /*01  100k*/  MSG_SW_ENCODER,\
                        /*02  51k */   MSG_FM_NEXT_STATION,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    MSG_FM_PREV_STATION,\
                        /*05 15k */    MSG_FM_SCAN_ALL_INIT,\
                        /*06 9k1*/      MSG_STANBY_KEY,\
                        /*07  6k2*/    MSG_FM_NEXT_STATION,\
                        /*08 3k*/       MSG_FM_PREV_STATION,\
                        /*09 0*/        MSG_CHANGE_WORKMODE ,

#define ADKEY_FM_LONG		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,
#endif 

#define ADKEY_FM_HOLD		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
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
                        /*00*/    NO_MSG,\
                        /*00 220k */  NO_MSG,\
                        /*01  100k*/  MSG_SW_ENCODER,\
                        /*02  51k */   NO_MSG,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    NO_MSG,\
                        /*05 15k */    NO_MSG,\
                        /*06 9k1*/      MSG_STANBY_KEY,\
                        /*07  6k2*/    NO_MSG,\
                        /*08 3k*/       NO_MSG,\
                        /*09 0*/        MSG_CHANGE_WORKMODE ,

#define ADKEY_AUX_LONG		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define ADKEY_AUX_HOLD		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
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
                        /*00*/    NO_MSG,\
                        /*00 220k */  NO_MSG,\
                        /*01  100k*/  MSG_SW_ENCODER,\
                        /*02  51k */   MSG_BT_NEXT_FILE,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    MSG_BT_PREV_FILE,\
                        /*05 15k */    MSG_BT_PP,\
                        /*06 9k1*/      MSG_STANBY_KEY,\
                        /*07  6k2*/    MSG_BT_NEXT_FILE,\
                        /*08 3k*/       MSG_BT_PREV_FILE,\
                        /*09 0*/        MSG_CHANGE_WORKMODE ,

#ifdef SUPOORT_LONG_PP_AS_BT_CONNECT_CTL
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
                        /*09*/    MSG_BT_CONNECT_CTL,   //断开连接
#elif defined(SUPOORT_LONG_MODE_AS_BT_CONNECT_CTL)
#define ADKEY_BT_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    MSG_BT_CONNECT_CTL,\
                        /*07*/    MSG_VOL_UP,\
                        /*08*/    MSG_VOL_DOWN,\
                        /*09*/    NO_MSG,   
#elif defined(SUPOORT_LONG_PP_AS_BT_CALL_REJECT)
#define ADKEY_BT_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    MSG_BT_CALL_REJECT,

#else 
#define ADKEY_BT_LONG		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#endif 

#define ADKEY_BT_HOLD		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
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
/*00*/    MSG_REC_PP,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*08*/    MSG_CHANGE_WORKMODE,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_REC_START,



#define ADKEY_ENC_LONG		\
/*00*/    MSG_CHANGE_WORKMODE,\
/*01*/    NO_MSG,\
/*02*/    NO_MSG,\
/*03*/    NO_MSG,\
/*04*/    NO_MSG,\
/*05*/    NO_MSG,\
/*06*/    NO_MSG,\
/*07*/    NO_MSG,\
/*07*/    NO_MSG,\
/*08*/    MSG_REC_STOP,


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
                        /*00 220k */  NO_MSG,\
                        /*01  100k*/  MSG_SW_ENCODER,\
                        /*02  51k */   MSG_PC_PLAY_NEXT,\
                        /*03  33k*/    NO_MSG,\
                        /*04 24k */    MSG_PC_PLAY_PREV,\
                        /*05 15k */    MSG_PC_PP,\
                        /*06 9k1*/      MSG_STANBY_KEY,\
                        /*07  6k2*/    MSG_PC_PLAY_NEXT,\
                        /*08 3k*/       MSG_PC_PLAY_PREV,\
                        /*09 0*/        MSG_CHANGE_WORKMODE,

#define ADKEY_USB_LONG		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define ADKEY_USB_HOLD		\
                        /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_VOL_DOWN,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
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
                        /*06*/    MSG_STANBY_KEY,\
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
	                  /*00*/    NO_MSG,\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    MSG_STANBY_KEY,\
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



