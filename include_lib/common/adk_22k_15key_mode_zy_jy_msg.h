/*
#define PULL_UP_RESISTANCE 10   //上拉电阻10K
#define KEYE_RES 0  //PP
#define KEYD_RES 1 // 
#define KEYC_RES 2  // 
#define KEYB_RES 3.3  // 
#define KEYA_RES 5.1  //
#define KEY9_RES 7.5 //
#define KEY8_RES 10 //   
#define KEY7_RES 15  // EQ
#define KEY6_RES 24  //next/v+
#define KEY5_RES 36  //prev/v-
#define KEY4_RES 51 //mode
#define KEY3_RES 91 //REPEAT
#define KEY2_RES 150 //STOP
#define KEY1_RES 220  //STANDBY
#define KEY0_NOKEY_RES 330
*/
/*******************************************************************
                        MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
                        /*00*/    NO_MSG,\
                        /*01*/    MSG_STANBY_KEY,\
                        /*02*/    MSG_MUSIC_STOP,\
                        /*03*/    MSG_MUSIC_RPT,\
                        /*04*/    MSG_CHANGE_WORKMODE,\
                        /*05*/    MSG_MUSIC_PREV_FILE,\
                        /*06*/    MSG_MUSIC_NEXT_FILE,\
                        /*07*/    MSG_MUSIC_EQ,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                  	/*0A*/	  NO_MSG,\
                  	/*0B*/	  NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                  	/*0D*/	  NO_MSG,\
                  	/*0E*/	  MSG_MUSIC_PP

#define ADKEY_DECODE_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG

#define ADKEY_DECODE_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG

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
                        /*01*/    MSG_STANBY_KEY,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_CHANGE_WORKMODE,\
                        /*05*/    MSG_FM_PREV_STATION,\
                        /*06*/    MSG_FM_NEXT_STATION,\
                        /*07*/    NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                  	/*0A*/	  NO_MSG,\
                  	/*0B*/	  NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                  	/*0D*/	  NO_MSG,\
                  	/*0E*/	  MSG_FM_SCAN_ALL_INIT


#define ADKEY_FM_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG


#define ADKEY_FM_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG

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
                        /*01*/    MSG_STANBY_KEY,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_CHANGE_WORKMODE,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                  	/*0A*/	  NO_MSG,\
                  	/*0B*/	  NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                  	/*0D*/	  NO_MSG,\
                  	/*0E*/	  NO_MSG
                  	


#define ADKEY_AUX_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG


#define ADKEY_AUX_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG

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
                        /*01*/    MSG_STANBY_KEY,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    MSG_CHANGE_WORKMODE,\
                        /*05*/    MSG_BT_PREV_FILE,\
                        /*06*/    MSG_BT_NEXT_FILE,\
                        /*07*/    NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                  	/*0A*/	  NO_MSG,\
                  	/*0B*/	  NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                  	/*0D*/	  NO_MSG,\
                  	/*0E*/	  MSG_BT_PP




#define ADKEY_BT_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG


#define ADKEY_BT_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG
                    	

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
                        /*00*/    MSG_STANBY_KEY,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    MSG_CHANGE_WORKMODE,\
                        /*04*/    MSG_PC_PLAY_PREV,\
                        /*05*/    MSG_PC_PLAY_NEXT,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                  	/*0A*/	  NO_MSG,\
                  	/*0B*/	  NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                  	/*0D*/	  NO_MSG,\
                  	/*0E*/	  MSG_PC_PP
                  	
#define ADKEY_USB_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG


#define ADKEY_USB_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/   NO_MSG,\
                        /*02*/   NO_MSG,\
                        /*03*/   NO_MSG,\
                        /*04*/   NO_MSG,\
                        /*05*/   MSG_VOL_DOWN,\
                        /*06*/   MSG_VOL_UP,\
                        /*07*/   NO_MSG,\
                        /*08*/  NO_MSG,\
                        /*09*/  NO_MSG,\
                    	/*0A*/	 NO_MSG,\
                  	/*0B*/	 NO_MSG,\
                  	/*0C*/	  NO_MSG,\
                    	/*0D*/	  NO_MSG,\
                    	/*0E*/	  NO_MSG

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
	/*00*/	  MSG_STANBY_KEY,\
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


