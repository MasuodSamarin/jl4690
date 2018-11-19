#include "main_key.h"
#include "common/msg.h"

#include "common/msg_key.h"

#ifdef SUPPORT_TM1628_KEY_READ  
   #if LED_KEY_MAX
	   const u8 main_led_table[4][LED_KEY_MAX]=
   #else
	   const u8 main_led_table[4][10] =			  //AD&IO����ת����
  #endif	 
	   {
		   /*�̰�*/ 	  {LEDKEY_MAIN_SHORT},
		   /*����*/ 	  {LEDKEY_MAIN_LONG},
		   /*����*/ 	  {LEDKEY_MAIN_HOLD},
		   /*����̧��*/ {LEDKEY_MAIN_LONG_UP},
	   };
#endif


#ifdef adkey_max_num
const u8 main_ad_table[4][adkey_max_num] =
#else
const u8 main_ad_table[4][10] =
#endif
{
    /*�̰�*/	    {ADKEY_MAIN_SHORT},
    /*����*/		{ADKEY_MAIN_LONG},
    /*����*/		{ADKEY_MAIN_HOLD},
    /*����̧��*/	{ADKEY_MAIN_LONG_UP},
};

/*******************************************************************
                            I/O������
*******************************************************************/
#define IOKEY_MAIN_SHORT		\
                        /*00*/    MSG_POWER_KEY_UP,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_MAIN_LONG		\
                        /*00*/    MSG_POWER_ON,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define IOKEY_MAIN_HOLD		\
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

#define IOKEY_MAIN_LONG_UP	\
                        /*00*/    MSG_POWER_KEY_UP,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

const u8 main_io_table[4][10] =
{
    /*�̰�*/	    {IOKEY_MAIN_SHORT},
    /*����*/		{IOKEY_MAIN_LONG},
    /*����*/		{IOKEY_MAIN_HOLD},
    /*����̧��*/	{IOKEY_MAIN_LONG_UP},
};


#ifdef ir_max_num
const u8 main_ir_table[4][ir_max_num] =
#else
const u8 main_ir_table[4][21] =
#endif

{
    /*�̰�*/	    {IRFF00_MAIN_KEY_SHORT},
    /*����*/		{IRFF00_MAIN_KEY_LONG},
    /*����*/		{IRFF00_MAIN_KEY_HOLD},
    /*����̧��*/	{IRFF00_MAIN_KEY_LONG_UP},
};


/*******************************************************************
                            touchkey������
*******************************************************************/
#define TOUCHKEY_MAIN_SHORT		\
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

#define TOUCHKEY_MAIN_LONG		\
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


#define TOUCHKEY_MAIN_HOLD		\
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

#define TOUCHKEY_MAIN_LONG_UP	\
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

const u8 main_touch_table[4][10] =
{
    /*�̰�*/	    {TOUCHKEY_MAIN_SHORT},
    /*����*/		{TOUCHKEY_MAIN_LONG},
    /*����*/		{TOUCHKEY_MAIN_HOLD},
    /*����̧��*/	{TOUCHKEY_MAIN_LONG_UP},
};

