

/*******************************************************************
                        IR music   按键表
*******************************************************************/





#define IRFF00_DECODE_KEY_SHORT			\
										/*0*/    MSG_STANBY_KEY,\
										/*1*/    MSG_CHANGE_WORKMODE,\
										/*2*/    MSG_MUTE,\
										/*3*/    MSG_MUSIC_PP,\
										/*4*/    MSG_MUSIC_PREV_FILE,\
										/*5*/    MSG_MUSIC_NEXT_FILE,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    MSG_MUSIC_U_SD,\
										/*9*/    MSG_FM_MODE_KEY,\
										/*10*/    MSG_BT_MODE_KEY,\
										/*11*/    MSG_LINE_MODE_KEY,\
										/*12*/    NO_MSG,\
										/*13*/    MSG_LOW_POWER_DEF_VOL,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG
	
								

#define IRFF00_DECODE_KEY_LONG			\
										/*0*/    NO_MSG,\
										/*1*/    NO_MSG,\
										/*2*/    NO_MSG,\
										/*3*/    NO_MSG,\
										/*4*/    MSG_MUSIC_FR,\
										/*5*/    MSG_MUSIC_FF,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    NO_MSG,\
										/*9*/    NO_MSG,\
										/*10*/    NO_MSG,\
										/*11*/    NO_MSG,\
										/*12*/    NO_MSG,\
										/*13*/    NO_MSG,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG
										

#define IRFF00_DECODE_KEY_HOLD			\
										/*0*/    NO_MSG,\
										/*1*/    NO_MSG,\
										/*2*/    NO_MSG,\
										/*3*/    NO_MSG,\
										/*4*/    MSG_MUSIC_FR,\
										/*5*/    MSG_MUSIC_FF,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    NO_MSG,\
										/*9*/    NO_MSG,\
										/*10*/    NO_MSG,\
										/*11*/    NO_MSG,\
										/*12*/    NO_MSG,\
										/*13*/    NO_MSG,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG


#define IRFF00_DECODE_KEY_LONG_UP 		\
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
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG
	






/*******************************************************************
                          FM   IR按键表
*******************************************************************/




#define IRFF00_FM_KEY_SHORT			\
										/*0*/    MSG_STANBY_KEY,\
										/*1*/    MSG_CHANGE_WORKMODE,\
										/*2*/    MSG_MUTE,\
										/*3*/    MSG_MUSIC_PP,\
										/*4*/    MSG_FM_PREV_STATION,\
										/*5*/    MSG_FM_NEXT_STATION,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    MSG_MUSIC_MODE_KEY,\
										/*9*/    NO_MSG,\
										/*10*/    MSG_BT_MODE_KEY,\
										/*11*/    MSG_LINE_MODE_KEY,\
										/*12*/    MSG_FM_SCAN_ALL_INIT,\
										/*13*/    MSG_LOW_POWER_DEF_VOL,\
										/*14*/    MSG_FM_PREV_STEP,\
										/*15*/    MSG_FM_NEXT_STEP




#define IRFF00_FM_KEY_LONG			\
							/*00*/    NO_MSG,\
							/*01*/    NO_MSG,\
							/*02*/    NO_MSG,\
							/*03*/    NO_MSG,\
							/*04*/    MSG_FM_SCAN_ALL_DOWN,\
							/*05*/    MSG_FM_SCAN_ALL_UP,\
							/*06*/    MSG_VOL_UP,\
							/*07*/    MSG_VOL_DOWN,\
							/*08*/    NO_MSG,\
							/*09*/    NO_MSG,\
							/*10*/    NO_MSG,\
							/*11*/    NO_MSG,\
							/*12*/    NO_MSG,\
							/*13*/    NO_MSG,\
                                                 /*14*/    MSG_FM_PREV_STEP,\
                                                     /*15*/    MSG_FM_NEXT_STEP


#define IRFF00_FM_KEY_HOLD			\
							/*00*/    NO_MSG,\
							/*01*/    NO_MSG,\
							/*02*/    NO_MSG,\
							/*03*/    NO_MSG,\
							/*04*/    NO_MSG,\
							/*05*/    NO_MSG,\
							/*06*/    MSG_VOL_UP,\
							/*07*/    MSG_VOL_DOWN,\
							/*08*/    NO_MSG,\
							/*09*/    NO_MSG,\
							/*10*/    NO_MSG,\
							/*11*/    NO_MSG,\
							/*12*/    NO_MSG,\
							/*13*/    NO_MSG,\
                                                 /*14*/    MSG_FM_PREV_STEP,\
                                                 /*15*/    MSG_FM_NEXT_STEP



#define IRFF00_FM_KEY_LONG_UP 		\
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
							/*10*/    NO_MSG,\
							/*11*/    NO_MSG,\
							/*12*/    NO_MSG,\
							/*13*/    NO_MSG,\
							/*14*/    NO_MSG,\
							/*15*/    NO_MSG




/*******************************************************************
                     line        IR按键表
*******************************************************************/




#define IRFF00_AUX_KEY_SHORT			\
				  							/*0*/    MSG_STANBY_KEY,\
				  							/*1*/    MSG_CHANGE_WORKMODE,\
				  							/*2*/    MSG_MUTE,\
				  							/*3*/    NO_MSG,\
				  							/*4*/    NO_MSG,\
				  							/*5*/    NO_MSG,\
				  							/*6*/    MSG_VOL_UP,\
				  							/*7*/    MSG_VOL_DOWN,\
				  							/*8*/    MSG_MUSIC_MODE_KEY,\
				  							/*9*/    MSG_FM_MODE_KEY,\
				  							/*10*/    MSG_BT_MODE_KEY,\
				  							/*11*/    NO_MSG,\
				  							/*12*/    NO_MSG,\
				  							/*13*/    MSG_LOW_POWER_DEF_VOL,\
				  							/*14*/    NO_MSG,\
				  							/*15*/    NO_MSG 



#define IRFF00_AUX_KEY_LONG			\
										/*0*/    NO_MSG,\
										/*1*/    NO_MSG,\
										/*2*/    NO_MSG,\
										/*3*/    NO_MSG,\
										/*4*/    NO_MSG,\
										/*5*/    NO_MSG,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    NO_MSG,\
										/*9*/    NO_MSG,\
										/*10*/    NO_MSG,\
										/*11*/    NO_MSG,\
										/*12*/    NO_MSG,\
										/*13*/    NO_MSG,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG


#define IRFF00_AUX_KEY_HOLD			\
										/*0*/    NO_MSG,\
										/*1*/    NO_MSG,\
										/*2*/    NO_MSG,\
										/*3*/    NO_MSG,\
										/*4*/    NO_MSG,\
										/*5*/    NO_MSG,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    NO_MSG,\
										/*9*/    NO_MSG,\
										/*10*/    NO_MSG,\
										/*11*/    NO_MSG,\
										/*12*/    NO_MSG,\
										/*13*/    NO_MSG,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG

#define IRFF00_AUX_KEY_LONG_UP 		\
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
					      							/*10*/    NO_MSG,\
					      							/*11*/    NO_MSG,\
					      							/*12*/    NO_MSG,\
					      							/*13*/    NO_MSG,\
					      							/*14*/    NO_MSG,\
					      							/*15*/    NO_MSG




/*******************************************************************
                        IR BT   按键表
*******************************************************************/



#define IRFF00_BT_SHORT			\
					  						/*0*/    MSG_STANBY_KEY,\
				  							/*1*/    MSG_CHANGE_WORKMODE,\
				  							/*2*/    MSG_MUTE,\
				  							/*3*/    MSG_BT_PP,\
				  							/*4*/    MSG_BT_PREV_FILE,\
				  							/*5*/    MSG_BT_NEXT_FILE,\
				  							/*6*/    MSG_VOL_UP ,\
				  							/*7*/   MSG_VOL_DOWN  ,\
				  							/*8*/    MSG_MUSIC_MODE_KEY,\
				  							/*9*/    MSG_FM_MODE_KEY,\
				  							/*10*/    NO_MSG,\
				  							/*11*/    MSG_LINE_MODE_KEY,\
				  							/*12*/    NO_MSG,\
				  							/*13*/    MSG_LOW_POWER_DEF_VOL,\
				  							/*14*/    NO_MSG,\
				  							/*15*/    NO_MSG        
	


			//		/*09*/    MSG_BT_HID_CTRL,\
                     //           /*10*/    MSG_BT_HID_DISCONN,\
			
#define IRFF00_BT_LONG			\
										/*0*/    NO_MSG,\
										/*1*/    NO_MSG,\
										/*2*/    NO_MSG,\
										/*3*/    NO_MSG,\
										/*4*/    NO_MSG,\
										/*5*/    NO_MSG,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    NO_MSG,\
										/*9*/    NO_MSG,\
										/*10*/    NO_MSG,\
										/*11*/    NO_MSG,\
										/*12*/    NO_MSG,\
										/*13*/    NO_MSG,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG 

#define IRFF00_BT_HOLD			\
										/*0*/    NO_MSG,\
										/*1*/    NO_MSG,\
										/*2*/    NO_MSG,\
										/*3*/    NO_MSG,\
										/*4*/    NO_MSG,\
										/*5*/    NO_MSG,\
										/*6*/    MSG_VOL_UP,\
										/*7*/    MSG_VOL_DOWN,\
										/*8*/    NO_MSG,\
										/*9*/    NO_MSG,\
										/*10*/    NO_MSG,\
										/*11*/    NO_MSG,\
										/*12*/    NO_MSG,\
										/*13*/    NO_MSG,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG

#define IRFF00_BT_LONG_UP 		\
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
              								/*10*/    NO_MSG,\
              								/*11*/    NO_MSG,\
              								/*12*/    NO_MSG,\
              								/*13*/    NO_MSG,\
              								/*14*/    NO_MSG,\
              								/*15*/    NO_MSG



/*******************************************************************
                      usb      IR按键表
*******************************************************************/



#define IRFF00_USB_KEY_SHORT			\
										/*10*/    NO_MSG,\
										/*11*/    NO_MSG,\
										/*12*/    NO_MSG,\
										/*13*/    NO_MSG,\
										/*14*/    NO_MSG,\
										/*15*/    NO_MSG,\
										/*16*/    NO_MSG,\
										/*17*/    NO_MSG,\
										/*18*/    NO_MSG,\
										/*19*/    NO_MSG,\
										/*20*/    NO_MSG,\
										/*21*/    NO_MSG,\
										/*22*/    NO_MSG,\
										/*23*/    NO_MSG,\
										/*24*/    NO_MSG,\
										/*25*/    NO_MSG

										

#define IRFF00_USB_KEY_LONG			\
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
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG


#define IRFF00_USB_KEY_HOLD			\
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
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG,


#define IRFF00_USB_KEY_LONG_UP 		\
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
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG



/*******************************************************************
                     MAIN       IR按键表
*******************************************************************/
#define IRFF00_MAIN_KEY_SHORT			\
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG,\
								/*16*/    NO_MSG,\
								/*17*/    NO_MSG,\
								/*18*/    MSG_MUSIC_MODE_KEY,\
								/*19*/    MSG_MUSIC_EQ,\
								/*20*/    NO_MSG,\
								/*21*/    NO_MSG,\
								/*22*/    NO_MSG,\
								/*23*/    NO_MSG,\
								/*24*/    NO_MSG,\
								/*25*/    NO_MSG




#define IRFF00_MAIN_KEY_LONG			\
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
                             								/*10*/    NO_MSG,\
                             								/*11*/    NO_MSG,\
                             								/*12*/    NO_MSG,\
                             								/*13*/    NO_MSG,\
                             								/*14*/    NO_MSG,\
                             								/*15*/    NO_MSG



#define IRFF00_MAIN_KEY_HOLD			\
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
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG


#define IRFF00_MAIN_KEY_LONG_UP 		\
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
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG



/*******************************************************************
                     IDE        IR按键表
*******************************************************************/

#define IRFF00_IDLE_KEY_SHORT			\
							/*10*/    MSG_STANBY_KEY,\
							/*11*/    NO_MSG,\
							/*12*/    NO_MSG,\
							/*13*/    NO_MSG,\
							/*14*/    NO_MSG,\
							/*15*/    NO_MSG,\
							/*16*/    NO_MSG,\
							/*17*/    NO_MSG,\
							/*18*/    NO_MSG,\
							/*19*/    NO_MSG,\
							/*20*/    NO_MSG,\
							/*21*/    NO_MSG,\
							/*22*/    NO_MSG,\
							/*23*/    NO_MSG,\
							/*24*/    NO_MSG,\
							/*25*/    NO_MSG 


#define IRFF00_IDLE_KEY_LONG			\
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
							/*10*/    NO_MSG,\
							/*11*/    NO_MSG,\
							/*12*/    NO_MSG,\
							/*13*/    NO_MSG,\
							/*14*/    NO_MSG,\
							/*15*/    NO_MSG,


#define IRFF00_IDLE_KEY_HOLD			\
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
							/*10*/    NO_MSG,\
							/*11*/    NO_MSG,\
							/*12*/    NO_MSG,\
							/*13*/    NO_MSG,\
							/*14*/    NO_MSG,\
							/*15*/    NO_MSG

#define IRFF00_IDLE_KEY_LONG_UP 		\
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
							/*10*/    NO_MSG,\
							/*11*/    NO_MSG,\
							/*12*/    NO_MSG,\
							/*13*/    NO_MSG,\
							/*14*/    NO_MSG,\
							/*15*/    NO_MSG,

