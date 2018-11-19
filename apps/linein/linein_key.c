#include "linein_key.h"
#include "common/msg.h"

#include "common/msg_key.h"

/*******************************************************************
                            AD������
*******************************************************************/
#ifdef SUPPORT_TM1628_KEY_READ  
   #if LED_KEY_MAX
		   const u8 linein_led_table[4][LED_KEY_MAX]=
   #else
		   const u8 linein_led_table[4][10] = 		  //AD&IO����ת����
  #endif	 
		   {
			   /*�̰�*/ 	  {LEDKEY_AUX_SHORT},
			   /*����*/ 	  {LEDKEY_AUX_LONG},
			   /*����*/ 	  {LEDKEY_AUX_HOLD},
			   /*����̧��*/ {LEDKEY_AUX_LONG_UP},
		   };
#endif


#ifdef adkey_max_num
const u8 linein_ad_table[4][adkey_max_num] =
#else
const u8 linein_ad_table[4][10] =
#endif
{
    /*�̰�*/	    {ADKEY_AUX_SHORT},
    /*����*/		{ADKEY_AUX_LONG},
    /*����*/		{ADKEY_AUX_HOLD},
    /*����̧��*/	{ADKEY_AUX_LONG_UP},
};
/*******************************************************************
                            I/O������
*******************************************************************/
#define IOKEY_AUX_SHORT		\
                        /*00*/    MSG_AUX_MUTE,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_AUX_LONG		\
                        /*00*/    MSG_CHANGE_WORKMODE,\
                        /*01*/    MSG_VOL_UP,\
                        /*02*/    MSG_VOL_DOWN,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define IOKEY_AUX_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    MSG_VOL_UP,\
                        /*02*/    MSG_VOL_DOWN,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_AUX_LONG_UP	\
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

const u8 linein_io_table[4][10] =
{
    /*�̰�*/	    {IOKEY_AUX_SHORT},
    /*����*/		{IOKEY_AUX_LONG},
    /*����*/		{IOKEY_AUX_HOLD},
    /*����̧��*/	{IOKEY_AUX_LONG_UP},
};


#ifdef ir_max_num
const u8 linein_ir_table[4][ir_max_num] =
#else
const u8 linein_ir_table[4][21] =
#endif

{
    /*�̰�*/	    {IRFF00_AUX_KEY_SHORT},
    /*����*/		{IRFF00_AUX_KEY_LONG},
    /*����*/		{IRFF00_AUX_KEY_HOLD},
    /*����̧��*/	{IRFF00_AUX_KEY_LONG_UP},
};


/*******************************************************************
                            touchkey������
*******************************************************************/
#define TOUCHKEY_AUX_SHORT		\
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

#define TOUCHKEY_AUX_LONG		\
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


#define TOUCHKEY_AUX_HOLD		\
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

#define TOUCHKEY_AUX_LONG_UP	\
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

const u8 linein_touch_table[4][10] =
{
    /*�̰�*/	    {TOUCHKEY_AUX_SHORT},
    /*����*/		{TOUCHKEY_AUX_LONG},
    /*����*/		{TOUCHKEY_AUX_HOLD},
    /*����̧��*/	{TOUCHKEY_AUX_LONG_UP},
};
