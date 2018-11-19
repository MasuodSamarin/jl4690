

/*******************************************************************


#define PULL_UP_RESISTANCE 2.7   //上拉电阻10K
#define KEYE_RES 0  //PP
#define KEYD_RES 0.22 // LINE		
#define KEYC_RES 0.47 	 // PREV
#define KEYB_RES 0.68  	 // FM
#define KEYA_RES 1 		// NEXT	
#define KEY9_RES  1.5  // REC
#define KEY8_RES 2.4 // EQ	
#define KEY7_RES 3.3 // NEXT/V+		
#define KEY6_RES 4.7   // PREV/V-	
#define KEY5_RES 5.6  // 	MODE
#define KEY4_RES 10  //  STOP	
#define KEY3_RES 15 // REPEAT	
#define KEY2_RES 18 //  	
#define KEY1_RES 19 // 			
#define KEY0_NOKEY_RES 20	 //	

                        MUSIC   AD按键表
*******************************************************************/
#define ADKEY_DECODE_SHORT		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    MSG_MUSIC_RPT,\
                        /*04*/    MSG_MUSIC_STOP,\
                        /*05*/    MSG_CHANGE_WORKMODE,\
                        /*06*/    MSG_MUSIC_PREV_FILE,\
                        /*07*/    MSG_MUSIC_NEXT_FILE,\
                        /*08*/    MSG_MUSIC_EQ,\
                        /*09*/   MSG_MUSIC_PLAY_REC_FILE,\
                  	/*0A*/	  MSG_MUSIC_NEXT_FILE,\
                  	/*0B*/	  MSG_FM_MODE_KEY,\
                  	/*0C*/	  MSG_MUSIC_PREV_FILE,\
                  	/*0D*/	  MSG_MIC_ONOFF,\
                  	/*0E*/	  MSG_MUSIC_PP

#define ADKEY_DECODE_LONG		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    MSG_MUSIC_VOICE_SWITCH,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
			/*09*/    MSG_REC_START,\
			/*0A*/	 NO_MSG,\
			/*0B*/	 NO_MSG,\
			/*0C*/	 NO_MSG,\
			/*0D*/	 NO_MSG,\
			/*0E*/	 NO_MSG

#define ADKEY_DECODE_HOLD		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    NO_MSG,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
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
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    MSG_CHANGE_WORKMODE,\
			/*06*/    MSG_FM_PREV_STATION,\
			/*07*/    MSG_FM_NEXT_STATION,\
			/*08*/    NO_MSG,\
			/*09*/   NO_MSG,\
			/*0A*/	  MSG_FM_NEXT_STATION,\
			/*0B*/	  MSG_FM_MODE_KEY,\
			/*0C*/	  MSG_FM_PREV_STATION,\
			/*0D*/	  MSG_MIC_ONOFF,\
			/*0E*/	  MSG_FM_PP

#if  SUPPORT_FM_OPTION_VOICE

#define ADKEY_FM_LONG		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    MSG_MIC_ONOFF,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
			/*09*/    NO_MSG,\
			/*0A*/	 NO_MSG,\
			/*0B*/	 NO_MSG,\
			/*0C*/	 NO_MSG,\
			/*0D*/	 NO_MSG,\
			/*0E*/	 MSG_FM_SEARCHING
			
#else
	
#define ADKEY_FM_LONG		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    MSG_FM_VOICE_SWITCH,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
			/*09*/    NO_MSG,\
			/*0A*/	 NO_MSG,\
			/*0B*/	 NO_MSG,\
			/*0C*/	 NO_MSG,\
			/*0D*/	 NO_MSG,\
			/*0E*/	 MSG_FM_SCAN_ALL_INIT

#endif

#define ADKEY_FM_HOLD		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    NO_MSG,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
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
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    MSG_CHANGE_WORKMODE,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/   NO_MSG,\
                  	/*0A*/	  NO_MSG,\
                  	/*0B*/	  MSG_FM_MODE_KEY,\
                  	/*0C*/	  NO_MSG,\
                  	/*0D*/	  MSG_MIC_ONOFF,\
                  	/*0E*/	  MSG_AUX_MUTE


#define ADKEY_AUX_LONG		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    MSG_AUX_VOICE_SWITCH,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
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
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    NO_MSG,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
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
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    MSG_CHANGE_WORKMODE,\
                        /*06*/    MSG_BT_PREV_FILE,\
                        /*07*/    MSG_BT_NEXT_FILE,\
                        /*08*/    NO_MSG,\
                        /*09*/   NO_MSG,\
                  	/*0A*/	  MSG_BT_NEXT_FILE,\
                  	/*0B*/	  MSG_FM_MODE_KEY,\
                  	/*0C*/	  MSG_BT_PREV_FILE,\
                  	/*0D*/	  MSG_MIC_ONOFF,\
                  	/*0E*/	  MSG_BT_PP
                  	
                  	
#define ADKEY_BT_LONG		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    MSG_BT_VOICE_SWITCH,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
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
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    NO_MSG,\
			/*06*/    MSG_VOL_DOWN,\
			/*07*/    MSG_VOL_UP,\
			/*08*/    NO_MSG,\
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
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    MSG_CHANGE_WORKMODE,\
                        /*06*/    MSG_PC_PLAY_PREV,\
                        /*07*/    MSG_PC_PLAY_NEXT,\
                        /*08*/    NO_MSG,\
                        /*09*/   NO_MSG,\
                  	/*0A*/	  MSG_PC_PLAY_NEXT,\
                  	/*0B*/	  MSG_FM_MODE_KEY,\
                  	/*0C*/	  MSG_PC_PLAY_PREV,\
                  	/*0D*/	  MSG_LINE_MODE_KEY,\
                  	/*0E*/	  MSG_PC_PP

#define ADKEY_USB_LONG		\
			/*00*/    NO_MSG,\
			/*01*/    NO_MSG,\
			/*02*/    NO_MSG,\
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    MSG_MIC_ONOFF,\
			/*06*/    MSG_PC_VOL_DOWN,\
			/*07*/    MSG_PC_VOL_UP,\
			/*08*/    NO_MSG,\
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
			/*03*/    NO_MSG,\
			/*04*/    NO_MSG,\
			/*05*/    NO_MSG,\
			/*06*/    MSG_PC_VOL_DOWN,\
			/*07*/    MSG_PC_VOL_UP,\
			/*08*/    NO_MSG,\
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
	/*09*/	  MSG_REC_STOP,\
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
	/*01*/	  MSG_STANBY_KEY,\
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
                        
