

/*******************************************************************
                        IR music   ������
*******************************************************************/
#define IRFF00_DECODE_KEY_SHORT			\
	/*00*/	  MSG_STANBY_KEY,\
	/*01*/	  MSG_CHANGE_WORKMODE,\
	/*02*/	  MSG_MUTE,\
	/*03*/	  MSG_MUSIC_PP,\
	/*04*/	  MSG_MUSIC_PREV_FILE,\
	/*05*/	  MSG_MUSIC_NEXT_FILE,\
	/*06*/	  MSG_MUSIC_EQ,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  MSG_0,\
	/*10*/	  MSG_MUSIC_RPT,\
	/*11*/	  MSG_MUSIC_U_SD,\
	/*12*/	  MSG_1,\
	/*13*/	  MSG_2,\
	/*14*/	  MSG_3,\
	/*15*/	  MSG_4,\
	/*16*/	  MSG_5,\
	/*17*/	  MSG_6,\
	/*18*/	  MSG_7,\
	/*19*/	  MSG_8,\
	/*20*/	  MSG_9,\
	/*21*/	 NO_MSG,\
	/*22*/	  MSG_FOLDER_NEXT,\
	/*23*/	  MSG_FOLDER_PREV,\
	/*24*/	  MSG_LINE_MODE_KEY,\
	/*25*/	  MSG_FM_MODE_KEY,\
	/*26*/	  MSG_MUSIC_U_SD,\
	/*27*/	  MSG_ADD_100,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP
	

#define IRFF00_DECODE_KEY_LONG			\
	 /*00*/    NO_MSG,\
	 /*01*/    NO_MSG,\
	 /*02*/    NO_MSG,\
	 /*03*/    NO_MSG,\
	 /*04*/    MSG_MUSIC_FR,\
	 /*05*/    MSG_MUSIC_FF,\
	 /*06*/    MSG_REC_START,\
	 /*07*/    MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  MSG_MUSIC_PLAY_REC_FILE,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP



#define IRFF00_DECODE_KEY_HOLD			\
	 /*00*/    NO_MSG,\
	 /*01*/    NO_MSG,\
	 /*02*/    NO_MSG,\
	 /*03*/    NO_MSG,\
	 /*04*/    MSG_MUSIC_FR,\
	 /*05*/    MSG_MUSIC_FF,\
	 /*06*/    NO_MSG,\
	 /*07*/    MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP



#define IRFF00_DECODE_KEY_LONG_UP 		\
	 /*00*/    NO_MSG,\
	 /*01*/    NO_MSG,\
	 /*02*/    NO_MSG,\
	 /*03*/    NO_MSG,\
	 /*04*/    NO_MSG,\
	 /*05*/    NO_MSG,\
	 /*06*/    NO_MSG,\
	 /*07*/    NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG



/*******************************************************************
                          FM   IR������
*******************************************************************/
#define IRFF00_FM_KEY_SHORT			\
	/*00*/	  MSG_STANBY_KEY,\
	/*01*/	  MSG_CHANGE_WORKMODE,\
	/*02*/	  MSG_MUTE,\
	/*03*/	  NO_MSG,\
	/*04*/	  MSG_FM_PREV_STATION,\
	/*05*/	  MSG_FM_NEXT_STATION,\
	/*06*/	  MSG_MUSIC_EQ,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  MSG_0,\
	/*10*/	  MSG_MUSIC_RPT,\
	/*11*/	  MSG_MUSIC_MODE_KEY,\
	/*12*/	  MSG_1,\
	/*13*/	  MSG_2,\
	/*14*/	  MSG_3,\
	/*15*/	  MSG_4,\
	/*16*/	  MSG_5,\
	/*17*/	  MSG_6,\
	/*18*/	  MSG_7,\
	/*19*/	  MSG_8,\
	/*20*/	  MSG_9,\
	/*21*/	 MSG_FM_SCAN_ALL_INIT,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  MSG_LINE_MODE_KEY,\
	/*25*/	  MSG_FM_MODE_KEY,\
	/*26*/	  MSG_FM_SCAN_ALL_INIT,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP


#define IRFF00_FM_KEY_LONG			\
	 /*00*/    NO_MSG,\
	 /*01*/    NO_MSG,\
	 /*02*/    NO_MSG,\
	 /*03*/    NO_MSG,\
	 /*04*/    NO_MSG,\
	 /*05*/    NO_MSG,\
	 /*06*/    NO_MSG,\
	 /*07*/    MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP



#define IRFF00_FM_KEY_HOLD			\
	 /*00*/    NO_MSG,\
	 /*01*/    NO_MSG,\
	 /*02*/    NO_MSG,\
	 /*03*/    NO_MSG,\
	 /*04*/    NO_MSG,\
	 /*05*/    NO_MSG,\
	 /*06*/    NO_MSG,\
	 /*07*/    MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP
	

#define IRFF00_FM_KEY_LONG_UP 		\
	 /*00*/    NO_MSG,\
	 /*01*/    NO_MSG,\
	 /*02*/    NO_MSG,\
	 /*03*/    NO_MSG,\
	 /*04*/    NO_MSG,\
	 /*05*/    NO_MSG,\
	 /*06*/    NO_MSG,\
	 /*07*/    NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG



/*******************************************************************
                     line        IR������
*******************************************************************/
#define IRFF00_AUX_KEY_SHORT			\
	/*00*/	  MSG_STANBY_KEY,\
	/*01*/	  MSG_CHANGE_WORKMODE,\
	/*02*/	  MSG_MUTE,\
	/*03*/	  MSG_AUX_MUTE,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  MSG_MUSIC_MODE_KEY,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  MSG_LINE_MODE_KEY,\
	/*25*/	  MSG_FM_MODE_KEY,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP
	

#define IRFF00_AUX_KEY_LONG			\
	/*00*/	  NO_MSG,\
	/*01*/	  NO_MSG,\
	/*02*/	  NO_MSG,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP


#define IRFF00_AUX_KEY_HOLD			\
	/*00*/	  NO_MSG,\
	/*01*/	  NO_MSG,\
	/*02*/	  NO_MSG,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP

#define IRFF00_AUX_KEY_LONG_UP 		\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


/*******************************************************************
                        IR BT   ������
*******************************************************************/



#define IRFF00_BT_SHORT			\
	/*00*/	  MSG_STANBY_KEY,\
	/*01*/	  MSG_CHANGE_WORKMODE,\
	/*02*/	  MSG_MUTE,\
	/*03*/	  MSG_BT_PP,\
	/*04*/	  MSG_BT_PREV_FILE,\
	/*05*/	  MSG_BT_NEXT_FILE,\
	/*06*/	  MSG_BT_MUSIC_EQ,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  MSG_0,\
	/*10*/	  NO_MSG,\
	/*11*/	  MSG_MUSIC_MODE_KEY,\
	/*12*/	  MSG_1,\
	/*13*/	  MSG_2,\
	/*14*/	  MSG_3,\
	/*15*/	  MSG_4,\
	/*16*/	  MSG_5,\
	/*17*/	  MSG_6,\
	/*18*/	  MSG_7,\
	/*19*/	  MSG_8,\
	/*20*/	  MSG_9,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  MSG_LINE_MODE_KEY,\
	/*25*/	  MSG_FM_MODE_KEY,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP
	
			
#define IRFF00_BT_LONG			\
	/*00*/	  NO_MSG,\
	/*01*/	  NO_MSG,\
	/*02*/	  NO_MSG,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP



#define IRFF00_BT_HOLD			\
	/*00*/	  NO_MSG,\
	/*01*/	  NO_MSG,\
	/*02*/	  NO_MSG,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  MSG_MIC_DN,\
	/*29*/	  MSG_MIC_UP


#define IRFF00_BT_LONG_UP 		\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


/*******************************************************************
                        IR enc   ������
*******************************************************************/


#define IRFF00_ENC_KEY_SHORT			\
	/*00*/	  NO_MSG,\
	/*01*/	  NO_MSG,\
	/*02*/	  NO_MSG,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  MSG_REC_STOP,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


			
#define IRFF00_ENC_KEY_LONG			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG



#define IRFF00_ENC_KEY_HOLD			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


#define IRFF00_ENC_KEY_LONG_UP 		\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG




/*******************************************************************
                      usb      IR������
*******************************************************************/



#define IRFF00_USB_KEY_SHORT			\
	/*00*/	  MSG_STANBY_KEY,\
	/*01*/	  MSG_CHANGE_WORKMODE,\
	/*02*/	  MSG_MUTE,\
	/*03*/	  MSG_PC_PP,\
	/*04*/	  MSG_PC_PLAY_PREV,\
	/*05*/	  MSG_PC_PLAY_NEXT,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG
	
										

#define IRFF00_USB_KEY_LONG			\
	/*00*/	  NO_MSG,\
	/*01*/	  NO_MSG,\
	/*02*/	  NO_MSG,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG
	

#define IRFF00_USB_KEY_HOLD			\
	/*00*/	  NO_MSG,\
	/*01*/	  NO_MSG,\
	/*02*/	  NO_MSG,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_VOL_DOWN,\
	/*08*/	  MSG_VOL_UP,\
	/*09*/	  NO_MSG,\
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


#define IRFF00_USB_KEY_LONG_UP 		\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


/*******************************************************************
                     MAIN       IR������
*******************************************************************/
#define IRFF00_MAIN_KEY_SHORT			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG



#define IRFF00_MAIN_KEY_LONG			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


#define IRFF00_MAIN_KEY_HOLD			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG

#define IRFF00_MAIN_KEY_LONG_UP 		\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


/*******************************************************************
                            IR������
*******************************************************************/
#define IRFF00_IDLE_KEY_SHORT			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


#define IRFF00_IDLE_KEY_LONG			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG
	

#define IRFF00_IDLE_KEY_HOLD			\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG


#define IRFF00_IDLE_KEY_LONG_UP 		\
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
	/*10*/	  NO_MSG,\
	/*11*/	  NO_MSG,\
	/*12*/	  NO_MSG,\
	/*13*/	  NO_MSG,\
	/*14*/	  NO_MSG,\
	/*15*/	  NO_MSG,\
	/*16*/	  NO_MSG,\
	/*17*/	  NO_MSG,\
	/*18*/	  NO_MSG,\
	/*19*/	  NO_MSG,\
	/*20*/	  NO_MSG,\
	/*21*/	 NO_MSG,\
	/*22*/	  NO_MSG,\
	/*23*/	  NO_MSG,\
	/*24*/	  NO_MSG,\
	/*25*/	  NO_MSG,\
	/*26*/	  NO_MSG,\
	/*27*/	  NO_MSG,\
	/*28*/	  NO_MSG,\
	/*29*/	  NO_MSG




