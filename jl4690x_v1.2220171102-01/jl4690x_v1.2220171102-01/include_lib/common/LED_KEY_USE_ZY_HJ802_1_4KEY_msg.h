

#define LED_KEY_NEXT    0 
#define LED_KEY_PP         2
#define LED_KEY_PREV     4
#define LED_KEY_MODE   5
/*******************************************************************
                        MUSIC   AD������
*******************************************************************/

#define LEDKEY_DECODE_SHORT		\
    /*00*/    MSG_MUSIC_NEXT_FILE,\
    /*01*/    MSG_MUTE,\
    /*02*/    MSG_MUSIC_PP,\
    /*03*/    MSG_MENU_MODE,\
    /*04*/    MSG_MUSIC_PREV_FILE,\
    /*05*/    MSG_CHANGE_WORKMODE,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,



#define LEDKEY_DECODE_LONG		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,

#define LEDKEY_DECODE_HOLD		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,

#define LEDKEY_DECODE_LONG_UP	\
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

#define LEDKEY_FM_SHORT		\
    /*00*/    MSG_FM_NEXT_STATION,\
    /*01*/    MSG_MUTE,\
    /*02*/    MSG_FM_SCAN_ALL_INIT,\
    /*03*/    MSG_MENU_MODE,\
    /*04*/    MSG_FM_PREV_STATION,\
    /*05*/    MSG_CHANGE_WORKMODE,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,


#define LEDKEY_FM_LONG		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,


#define LEDKEY_FM_HOLD		\
    /*00*/   MSG_VOL_UP,\
    /*01*/   NO_MSG,\
    /*02*/   NO_MSG,\
    /*03*/   NO_MSG,\
    /*04*/   MSG_VOL_DOWN,\
    /*05*/   NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,

#define LEDKEY_FM_LONG_UP	\
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

#define LEDKEY_AUX_SHORT		\
    /*00*/    NO_MSG,\
    /*01*/    MSG_MUTE,\
    /*02*/    NO_MSG,\
    /*03*/    MSG_MENU_MODE,\
    /*04*/    NO_MSG,\
    /*05*/    MSG_CHANGE_WORKMODE,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,



#define LEDKEY_AUX_LONG		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,


#define LEDKEY_AUX_HOLD		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,

#define LEDKEY_AUX_LONG_UP	\
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
 

#define LEDKEY_BT_SHORT		\
    /*00*/    MSG_BT_NEXT_FILE,\
    /*01*/    MSG_MUTE,\
    /*02*/    MSG_BT_PP,\
    /*03*/    MSG_MENU_MODE,\
    /*04*/    MSG_BT_PREV_FILE,\
    /*05*/    MSG_CHANGE_WORKMODE,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,
#define LEDKEY_BT_LONG		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,


#define LEDKEY_BT_HOLD		\
    /*00*/   MSG_VOL_UP,\
    /*01*/   NO_MSG,\
    /*02*/   NO_MSG,\
    /*03*/   NO_MSG,\
    /*04*/   MSG_VOL_DOWN,\
    /*05*/   NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,

#define LEDKEY_BT_LONG_UP	\
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
#define LEDKEY_USB_SHORT		\
    /*00*/    MSG_PC_PLAY_NEXT,\
    /*01*/    MSG_MUTE,\
    /*02*/    MSG_PC_PP,\
    /*03*/    MSG_MENU_MODE,\
    /*04*/    MSG_PC_PLAY_PREV,\
    /*05*/    MSG_CHANGE_WORKMODE,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,

#define LEDKEY_USB_LONG		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,


#define LEDKEY_USB_HOLD		\
    /*00*/    MSG_VOL_UP,\
    /*01*/    NO_MSG,\
    /*02*/    NO_MSG,\
    /*03*/    NO_MSG,\
    /*04*/    MSG_VOL_DOWN,\
    /*05*/    NO_MSG,\
    /*06*/    NO_MSG,\
    /*07*/    NO_MSG,\
    /*08*/    NO_MSG,\
    /*09*/    NO_MSG,

#define LEDKEY_USB_LONG_UP	\
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
#define LEDKEY_MAIN_SHORT		\
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

#define LEDKEY_MAIN_LONG		\
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


#define LEDKEY_MAIN_HOLD		\
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

#define LEDKEY_MAIN_LONG_UP	\
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
#define LEDKEY_IDLE_SHORT		\
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

#define LEDKEY_IDLE_LONG		\
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


#define LEDKEY_IDLE_HOLD		\
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

#define LEDKEY_IDLE_LONG_UP	\
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
                          rec ������
*******************************************************************/
#define LEDKEY_REC_SHORT		\
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

#define LEDKEY_REC_LONG		\
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


#define LEDKEY_REC_HOLD		\
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

#define LEDKEY_REC_LONG_UP	\
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

