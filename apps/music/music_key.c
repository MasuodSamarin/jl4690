#include "music_key.h"
#include "common/msg.h"

#include "common/msg_key.h"

/*******************************************************************
                            AD按键表
*******************************************************************/
#ifdef SUPPORT_TM1628_KEY_READ  
   #if LED_KEY_MAX
	   const u8 music_led_table[4][LED_KEY_MAX]=
   #else
	   const u8 music_led_table[4][10] =			  //AD&IO按键转换表
  #endif	 
	   {
		   /*短按*/ 	  {LEDKEY_DECODE_SHORT},
		   /*长按*/ 	  {LEDKEY_DECODE_LONG},
		   /*连按*/ 	  {LEDKEY_DECODE_HOLD},
		   /*长按抬起*/ {LEDKEY_DECODE_LONG_UP},
	   };
#endif


#ifdef adkey_max_num
const u8 music_ad_table[4][adkey_max_num] =
#else
const u8 music_ad_table[4][10] =
#endif
{
    /*短按*/	    {ADKEY_DECODE_SHORT},
    /*长按*/		{ADKEY_DECODE_LONG},
    /*连按*/		{ADKEY_DECODE_HOLD},
    /*长按抬起*/	{ADKEY_DECODE_LONG_UP},
};


/*******************************************************************
                            I/O按键表
*******************************************************************/
#define IOKEY_DECODE_SHORT		\
                        /*00*/    MSG_MUSIC_PP,\
                        /*01*/    MSG_MUSIC_NEXT_FILE,\
                        /*02*/    MSG_MUSIC_PREV_FILE,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_DECODE_LONG		\
                        /*00*/    MSG_CHANGE_WORKMODE,\
                        /*01*/    MSG_VOL_UP,\
                        /*02*/    MSG_VOL_DOWN,\
                        /*03*/    MSG_MUSIC_FR,\
                        /*04*/    MSG_MUSIC_FF,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    MSG_VOL_UP,


#define IOKEY_DECODE_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    MSG_VOL_UP,\
                        /*02*/    MSG_VOL_DOWN,\
                        /*03*/    MSG_MUSIC_FR,\
                        /*04*/    MSG_MUSIC_FF,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_DECODE_LONG_UP	\
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

const u8 music_io_table[4][10] =
{
    /*短按*/	    {IOKEY_DECODE_SHORT},
    /*长按*/		{IOKEY_DECODE_LONG},
    /*连按*/		{IOKEY_DECODE_HOLD},
    /*长按抬起*/	{IOKEY_DECODE_LONG_UP},
};


///************红外按键表**************************/

#ifdef ir_max_num
const u8 music_ir_table[4][ir_max_num] =
#else
const u8 music_ir_table[4][21] =
#endif
{
    /*短按*/	    {IRFF00_DECODE_KEY_SHORT},
    /*长按*/		{IRFF00_DECODE_KEY_LONG},
    /*连按*/		{IRFF00_DECODE_KEY_HOLD},
    /*长按抬起*/	{IRFF00_DECODE_KEY_LONG_UP},
};

/*******************************************************************
                            touchkey按键表
*******************************************************************/
#define TOUCHKEY_DECODE_SHORT		\
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

#define TOUCHKEY_DECODE_LONG		\
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


#define TOUCHKEY_DECODE_HOLD		\
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

#define TOUCHKEY_DECODE_LONG_UP	\
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

const u8 music_touch_table[4][10] =
{
    /*短按*/	    {TOUCHKEY_DECODE_SHORT},
    /*长按*/		{TOUCHKEY_DECODE_LONG},
    /*连按*/		{TOUCHKEY_DECODE_HOLD},
    /*长按抬起*/	{TOUCHKEY_DECODE_LONG_UP},
};
