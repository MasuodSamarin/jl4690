

#define      PKEY_STOP                         5
#define      PKEY_VOL_UP                       1
#define      PKEY_VOL_DN                       2
#define      PKEY_EQ                                3
#define      PKEY_REPEAT                         4
#define      PKEY_MODE                            6
#define      PKEY_NEXT                             7
#define      PKEY_PREV                             8
#define      PKEY_PP                                9

/*******************************************************************
                        MUSIC   AD������
*******************************************************************/

#define ADKEY_DECODE_SHORT		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  MSG_MUSIC_EQ,\
	/*04*/	  MSG_MUSIC_RPT,\
	/*05*/	  MSG_MUSIC_STOP,\
	/*06*/	  MSG_CHANGE_WORKMODE,\
	/*07*/	  MSG_MUSIC_NEXT_FILE,\
	/*08*/	  MSG_MUSIC_PREV_FILE,\
	/*09*/	  MSG_MUSIC_PP,

#define ADKEY_DECODE_LONG		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,


#define ADKEY_DECODE_HOLD		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,

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
                        FM   AD������
*******************************************************************/

#define ADKEY_FM_SHORT		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  MSG_CHANGE_WORKMODE,\
	/*07*/	  MSG_FM_NEXT_STATION,\
	/*08*/	  MSG_FM_PREV_STATION,\
	/*09*/	  MSG_FM_SCAN_ALL_INIT,

#define ADKEY_FM_LONG		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  MSG_FM_SCAN_ALL_UP,\
	/*08*/	  MSG_FM_SCAN_ALL_DOWN,\
	/*09*/	  NO_MSG,


#define ADKEY_FM_HOLD		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
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
                         LINE    AD������
*******************************************************************/

#define ADKEY_AUX_SHORT		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  MSG_CHANGE_WORKMODE,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  MSG_AUX_PAUSE,

#define ADKEY_AUX_LONG		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,


#define ADKEY_AUX_HOLD		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
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
                         BT   AD������
*******************************************************************/


#define ADKEY_BT_SHORT		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  MSG_BT_MUSIC_EQ,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  MSG_CHANGE_WORKMODE,\
	/*07*/	  MSG_BT_NEXT_FILE,\
	/*08*/	  MSG_BT_PREV_FILE,\
	/*09*/	  MSG_BT_PP,

#define ADKEY_BT_LONG		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,


#define ADKEY_BT_HOLD		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,

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
                         USB   AD������
*******************************************************************/
#define ADKEY_USB_SHORT		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  MSG_CHANGE_WORKMODE,\
	/*07*/	  MSG_PC_PLAY_NEXT,\
	/*08*/	  MSG_PC_PLAY_PREV,\
	/*09*/	  MSG_PC_PP,

#define ADKEY_USB_LONG		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,


#define ADKEY_USB_HOLD		\
	/*00*/	  NO_MSG,\
	/*01*/	  MSG_VOL_UP,\
	/*02*/	  MSG_VOL_DOWN,\
	/*03*/	  NO_MSG,\
	/*04*/	  NO_MSG,\
	/*05*/	  NO_MSG,\
	/*06*/	  NO_MSG,\
	/*07*/	  NO_MSG,\
	/*08*/	  NO_MSG,\
	/*09*/	  NO_MSG,

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
                            main ������
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
                            AD������
*******************************************************************/
#define ADKEY_IDLE_SHORT		\
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


// REC KEY  
#if REC_EN

/*******************************************************************
REC   AD������
*******************************************************************/

#define ADKEY_ENC_SHORT		\
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
#define ADKEY_ENC_LONG		\
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

