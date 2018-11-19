#include "rec_key.h"
#include "common/msg.h"
#include "sdk_cfg.h"
#include "common/msg_key.h"

#if REC_EN


#ifdef SUPPORT_TM1628_KEY_READ  
   #if LED_KEY_MAX
		   const u8 rec_led_table[4][LED_KEY_MAX]=
   #else
		   const u8 rec_led_table[4][10] = 		  //AD&IO按键转换表
  #endif	 
		   {
			   /*短按*/ 	  {LEDKEY_REC_SHORT},
			   /*长按*/ 	  {LEDKEY_REC_LONG},
			   /*连按*/ 	  {LEDKEY_REC_HOLD},
			   /*长按抬起*/ {LEDKEY_REC_LONG_UP},
		   };
#endif



#ifdef adkey_max_num
const u8 adkey_msg_rec_table[4][adkey_max_num] =
#else
const u8 adkey_msg_rec_table[4][10] =
#endif
{
    /*短按*/	    {ADKEY_ENC_SHORT},
    /*长按*/		{ADKEY_ENC_LONG},
    /*连按*/		{ADKEY_ENC_HOLD},
    /*长按抬起*/	{ADKEY_ENC_LONG_UP},
};

/*******************************************************************
                            I/O按键表
*******************************************************************/
#define IOKEY_ENC_SHORT		\
                        /*00*/    MSG_REC_START,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_ENC_LONG		\
                        /*00*/    MSG_CHANGE_WORKMODE,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define IOKEY_ENC_HOLD		\
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

#define IOKEY_ENC_LONG_UP	\
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

const u8 iokey_msg_rec_table[4][10] =
{
    /*短按*/	    {IOKEY_ENC_SHORT},
    /*长按*/		{IOKEY_ENC_LONG},
    /*连按*/		{IOKEY_ENC_HOLD},
    /*长按抬起*/	{IOKEY_ENC_LONG_UP},
};

/*******************************************************************
                            IR按键表
*******************************************************************/

#ifdef ir_max_num
const u8 irff00_msg_rec_table[4][ir_max_num] =
#else
const u8 irff00_msg_rec_table[4][21] =
#endif
{
    /*短按*/	    {IRFF00_ENC_KEY_SHORT},
    /*长按*/		{IRFF00_ENC_KEY_LONG},
    /*连按*/		{IRFF00_ENC_KEY_HOLD},
    /*长按抬起*/	{IRFF00_ENC_KEY_LONG_UP},
};

/*******************************************************************
                            touchkey按键表
*******************************************************************/
#define TOUCHKEY_ENC_SHORT		\
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

#define TOUCHKEY_ENC_LONG		\
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


#define TOUCHKEY_ENC_HOLD		\
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

#define TOUCHKEY_ENC_LONG_UP	\
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

const u8 touchkey_msg_rec_table[4][10] =
{
    /*短按*/	    {TOUCHKEY_ENC_SHORT},
    /*长按*/		{TOUCHKEY_ENC_LONG},
    /*连按*/		{TOUCHKEY_ENC_HOLD},
    /*长按抬起*/	{TOUCHKEY_ENC_LONG_UP},
};

#endif
