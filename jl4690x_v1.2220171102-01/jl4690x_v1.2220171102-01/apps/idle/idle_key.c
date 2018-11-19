#include "idle_key.h"
#include "common/msg.h"
#include "common/msg_key.h"


#ifdef SUPPORT_TM1628_KEY_READ  
   #if LED_KEY_MAX
		   const u8 idle_led_table[4][LED_KEY_MAX]=
   #else
		   const u8 idle_led_table[4][10] = 		  //AD&IO����ת����
  #endif	 
		   {
			   /*�̰�*/ 	  {LEDKEY_IDLE_SHORT},
			   /*����*/ 	  {LEDKEY_IDLE_LONG},
			   /*����*/ 	  {LEDKEY_IDLE_HOLD},
			   /*����̧��*/ {LEDKEY_IDLE_LONG_UP},
		   };
#endif


#ifdef adkey_max_num
const u8 idle_ad_table[4][adkey_max_num] =
#else
const u8 idle_ad_table[4][10] =
#endif
{
    /*�̰�*/	    {ADKEY_IDLE_SHORT},
    /*����*/		{ADKEY_IDLE_LONG},
    /*����*/		{ADKEY_IDLE_HOLD},
    /*����̧��*/	{ADKEY_IDLE_LONG_UP},
};

/*******************************************************************
                            I/O������
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
    /*�̰�*/	    {IOKEY_IDLE_SHORT},
    /*����*/		{IOKEY_IDLE_LONG},
    /*����*/		{IOKEY_IDLE_HOLD},
    /*����̧��*/	{IOKEY_IDLE_LONG_UP},
};



#ifdef ir_max_num
const u8 idle_ir_table[4][ir_max_num] =
#else
const u8 idle_ir_table[4][21] =
#endif
{
    /*�̰�*/	    {IRFF00_IDLE_KEY_SHORT},
    /*����*/		{IRFF00_IDLE_KEY_LONG},
    /*����*/		{IRFF00_IDLE_KEY_HOLD},
    /*����̧��*/	{IRFF00_IDLE_KEY_LONG_UP},
};


/*******************************************************************
                            touchkey������
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
    /*�̰�*/	    {TOUCHKEY_IDLE_SHORT},
    /*����*/		{TOUCHKEY_IDLE_LONG},
    /*����*/		{TOUCHKEY_IDLE_HOLD},
    /*����̧��*/	{TOUCHKEY_IDLE_LONG_UP},
};
