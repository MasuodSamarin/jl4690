#include "idle_key.h"
#include "common/msg.h"
#include "common/msg_key.h"


#ifdef SUPPORT_TM1628_KEY_READ  
   #if LED_KEY_MAX
		   const u8 idle_led_table[4][LED_KEY_MAX]=
   #else
		   const u8 idle_led_table[4][10] = 		  //AD&IO按键转换表
  #endif	 
		   {
			   /*短按*/ 	  {LEDKEY_IDLE_SHORT},
			   /*长按*/ 	  {LEDKEY_IDLE_LONG},
			   /*连按*/ 	  {LEDKEY_IDLE_HOLD},
			   /*长按抬起*/ {LEDKEY_IDLE_LONG_UP},
		   };
#endif


#ifdef adkey_max_num
const u8 idle_ad_table[4][adkey_max_num] =
#else
const u8 idle_ad_table[4][10] =
#endif
{
    /*短按*/	    {ADKEY_IDLE_SHORT},
    /*长按*/		{ADKEY_IDLE_LONG},
    /*连按*/		{ADKEY_IDLE_HOLD},
    /*长按抬起*/	{ADKEY_IDLE_LONG_UP},
};

/*******************************************************************
                            I/O按键表
*******************************************************************/
#define IOKEY_IDLE_SHORT		\
                        /*00*/    MSG_IDLE_CNT,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_IDLE_LONG		\
                        /*00*/    MSG_IDLE_CNT_LONG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define IOKEY_IDLE_HOLD		\
                        /*00*/    MSG_IDLE_CNT_HOLD,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_IDLE_LONG_UP	\
                        /*00*/    MSG_IDLE_CNT_UP,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

const u8 idle_io_table[4][10] =
{
    /*短按*/	    {IOKEY_IDLE_SHORT},
    /*长按*/		{IOKEY_IDLE_LONG},
    /*连按*/		{IOKEY_IDLE_HOLD},
    /*长按抬起*/	{IOKEY_IDLE_LONG_UP},
};



#ifdef ir_max_num
const u8 idle_ir_table[4][ir_max_num] =
#else
const u8 idle_ir_table[4][21] =
#endif
{
    /*短按*/	    {IRFF00_IDLE_KEY_SHORT},
    /*长按*/		{IRFF00_IDLE_KEY_LONG},
    /*连按*/		{IRFF00_IDLE_KEY_HOLD},
    /*长按抬起*/	{IRFF00_IDLE_KEY_LONG_UP},
};


/*******************************************************************
                            touchkey按键表
*******************************************************************/
#define TOUCHKEY_IDLE_SHORT		\
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

#define TOUCHKEY_IDLE_LONG		\
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


#define TOUCHKEY_IDLE_HOLD		\
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

#define TOUCHKEY_IDLE_LONG_UP	\
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

const u8 idle_touch_table[4][10] =
{
    /*短按*/	    {TOUCHKEY_IDLE_SHORT},
    /*长按*/		{TOUCHKEY_IDLE_LONG},
    /*连按*/		{TOUCHKEY_IDLE_HOLD},
    /*长按抬起*/	{TOUCHKEY_IDLE_LONG_UP},
};
