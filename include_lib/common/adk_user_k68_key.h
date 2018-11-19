




#define      PKEY_LIGHT                          2
#define      PKEY_MODE                              3
#define      PKEY_NEXT                             4
#define      PKEY_PREV                             5
#define      PKEY_PP                                 6
#define      PKEY_POWER_OFF                8

/*******************************************************************
                        MUSIC   AD按键表
*******************************************************************/

#define ADKEY_DECODE_SHORT		\
							/*00  220k */       NO_MSG,\
							/*01  100k*/        NO_MSG,\
							/*02   51k*/         NO_MSG,\
							/*03   00*/         NO_MSG,\
							/*04   24 2v*/     NO_MSG,\
							/*05   9k1 1.6v */  NO_MSG,\
							/*06  3K 1.2v  */    NO_MSG ,\
							/*07 二极管*/         NO_MSG,\
							/*08 二极管*/          NO_MSG,\
							/*09 0R */              MSG_MUSIC_PP

#define ADKEY_DECODE_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    MSG_POWER_OFF


#define ADKEY_DECODE_HOLD		\
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
                        /*09*/    NO_MSG




/*******************************************************************
                        FM   AD按键表
*******************************************************************/

#define ADKEY_FM_SHORT		\
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


#define ADKEY_FM_LONG		\
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

#define ADKEY_FM_HOLD		\
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




#define ADKEY_AUX_LONG		\
                                             /*00   */ NO_MSG,\
                                             /*01  */  NO_MSG,\
                                             /*02*/	  NO_MSG,\
                                             /*03*/	  NO_MSG,\
                                             /*04*/	  NO_MSG,\
                                             /*05*/	  NO_MSG,\
                                             /*06*/	  NO_MSG,\
                                             /*07*/	  NO_MSG,\
                                             /*08*/	  NO_MSG,\
                                             /*09*/	  MSG_POWER_OFF,






#define ADKEY_AUX_HOLD		\
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
							/*00   */   NO_MSG,\
							/*01  */    NO_MSG,\
							/*02*/	  NO_MSG,\
							/*03*/	  NO_MSG,\
							/*04*/	  NO_MSG,\
							/*05*/	  NO_MSG,\
							/*06*/	  NO_MSG,\
							/*07*/	  NO_MSG,\
							/*08*/	  NO_MSG,\
							/*09*/	  MSG_BT_PP,
							




#define ADKEY_BT_LONG		\
                                            /*00   */	NO_MSG,\
                                            /*01  */	NO_MSG,\
                                            /*02*/	  NO_MSG,\
                                            /*03*/	  NO_MSG,\
                                            /*04*/	  NO_MSG,\
                                            /*05*/	  NO_MSG,\
                                            /*06*/	  NO_MSG,\
                                            /*07*/	  NO_MSG,\
                                            /*08*/	  NO_MSG,\
                                            /*09*/	  MSG_POWER_OFF,


							
	          


#define ADKEY_BT_HOLD		\
                                           /*00*/    NO_MSG,\
                                           /*01*/    NO_MSG,\
                                           /*02*/    NO_MSG,\
                                           /*03*/    NO_MSG,\
                                           /*04*/    NO_MSG,\
                                           /*05*/    NO_MSG,\
                                           /*06*/    NO_MSG,\
                                           /*07*/    NO_MSG,\
                                           /*08*/    NO_MSG,\
                                           /*09*/    NO_MSG

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
                         USB   AD按键表
*******************************************************************/
#define ADKEY_USB_SHORT		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG ,

#define ADKEY_USB_LONG		\
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


#define ADKEY_USB_HOLD		\
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
                        /*09*/    MSG_POWER_OFF,


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

