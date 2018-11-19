#include "includes.h"
#include "key_drv/key.h"
#include "common/msg.h"
#include "key_drv/key_drv_ad.h"
#include "key_drv/key_drv_io.h"
#include "key_drv/key_drv_ir.h"
#include "key_drv/key_drv_tch.h"
#include "key_drv/key_voice.h"
#include "timer.h"
#include "led7_drv.h"
#include "linein/dev_linein.h"

u8 key_type;        ///<按键类型
char *keymsg_task_name;
u32 input_number;	    ///<输入的数字的实际值
u8 input_number_cnt;   //输入数字个数
volatile static u8 key_invalid_flag = 0;

#ifdef adkey_max_num
u8 ad_msg_table[4][adkey_max_num];
#else
u8 ad_msg_table[4][10];
#endif
u8 io_msg_table[4][10];

#ifdef ir_max_num
u8 ir_msg_table[4][ir_max_num];
#else
u8 ir_msg_table[4][21];
#endif
extern bool is_dac_mute(void);

#ifdef SUPPORT_TM1628_KEY_READ
  #if LED_KEY_MAX
  u8 led_msg_table[4][LED_KEY_MAX];
  #else
  u8 led_msg_table[4][10];
  #endif
#endif

//u8 ad_msg_table[4][10];
//u8 io_msg_table[4][10];
//u8 ir_msg_table[4][21];
u8 touch_msg_table[4][10];

u8 get_key_invalid_flag(void)
{
    return key_invalid_flag;
}

char *menu_keytask_name;
u8 menu_keymsg_table[10];

tu8 (*get_key_tab[])(void) AT(.const_tab);
tu8 (*get_key_tab[])(void) =
{
#if KEY_AD_EN
    get_adkey_value,
#endif

#ifdef SUPPORT_TM1628_KEY_READ
    get_led_driver_key_value,
#endif

#if KEY_IO_EN
    get_iokey_value,
#endif

#if KEY_IR_EN
    get_irkey_value,

#endif

#if KEY_TCH_EN
    get_tchkey_value,
#endif
};

void key_init()
{
    key_puts("key init\n");
    s32 ret;
    keymsg_task_name = NULL;
    menu_keytask_name = NULL;
#if ( KEY_AD_EN || SYS_LVD_EN )/*ldo_in电压检测需要adc*/
    ad_key0_init();
#endif

#if KEY_IO_EN
    io_key_init();
#endif

#if KEY_IR_EN
    ret = ir_key_init();

    if(ret != TIMER_NO_ERR)
    {
        printf("IR key init error:%d!!!\n",ret);
    }
#endif

#if KEY_TCH_EN
    tch_key_init();
#endif


    ret = timer_reg_isr_fun(timer0_hl,5,key_scan,NULL);

    if(ret != TIMER_NO_ERR)
    {
        printf("key_scan err = %x\n",ret);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief   key_msg_sender
   @param   name：线程
   @param   msg：消息
   @return  void
   @note
*/
/*----------------------------------------------------------------------------*/
void key_msg_sender(char *name, u32 msg)
{
	u32 cnt = 0;
	os_taskq_count(name, &cnt);
	if(cnt > 8)
	{
		os_taskq_post_msg(name,1,msg);
	}
	else
	{
//		printf("--key_msg_sender = %s	",name);
//		printf("msg = 0x%x\n",msg);
	}
}
/*----------------------------------------------------------------------------*/
/**@brief   按键-消息转换函数
   @param   key_status：按键状态
   @param   back_last_key：最后按键值
   @return  void
   @note
*/
/*----------------------------------------------------------------------------*/
void key2msg_filter(u8 key_status, u8 back_last_key)
{
    tu8 msg = NO_MSG;

#if(BT_MODE==NORMAL_MODE)

#if KEY_TONE_EN
    //send_key_voice(500);
#endif

#ifdef SUPPORT_TM1628_KEY_READ 
    if(KEY_TYPE_LED_DRIVER== key_type)
    {    
        msg = led_msg_table[key_status][back_last_key];
    }
#endif


#if KEY_IR_EN
    if(KEY_TYPE_IR == key_type)
    {
        if(menu_keytask_name == NULL)
        {
            msg = ir_msg_table[key_status][back_last_key];
        }
        else
        {
            //菜单短按表
            if(key_status == 0)
            {
                msg = menu_keymsg_table[back_last_key];
                /* os_taskq_post_msg(menu_keytask_name, 1, msg); */
				key_msg_sender(menu_keytask_name, msg);
            }
            return;
        }

    }
#endif

#if KEY_IO_EN
    if(KEY_TYPE_IO == key_type)
    {
        msg = ad_msg_table[key_status][back_last_key];// msg = io_msg_table[key_status][back_last_key];
    }
#endif

#if KEY_TCH_EN
    if(KEY_TYPE_TOUCH == key_type)
    {
        msg = ad_msg_table[key_status][back_last_key]; //touch_msg_table[key_status][back_last_key];
    }
#endif // KEY_TCH_EN

#if KEY_AD_EN
    if(KEY_TYPE_AD == key_type)
    {

        if(menu_keytask_name == NULL)
        {
            msg = ad_msg_table[key_status][back_last_key];
        }
        else
        {
            //菜单短按表
            if(key_status == 0)
            {
                msg = menu_keymsg_table[back_last_key];
                /* os_taskq_post_msg(menu_keytask_name, 1, msg); */
				key_msg_sender(menu_keytask_name, msg);
            }
            return;
        }

    }
#endif

#ifdef SUPPORT_DISABLE_KEY_MUTE_STATE
   if((is_dac_mute())&&(msg <=0x80)&&(msg != MSG_CHANGE_WORKMODE)&&(msg != MSG_MUTE)&&(msg != MSG_VOL_UP)&&(msg != MSG_VOL_DOWN)&&(msg != MSG_STANBY_KEY))
    	{
		msg=NO_MSG;
    	}	
#endif


//    key_printf("msg:0x%02x\n",msg);
    if(msg < MSG_MAIN_MAX)
    {
         /* os_taskq_post_msg(MAIN_TASK_NAME, 1, msg); */
		 key_msg_sender(MAIN_TASK_NAME, msg);
    }
    else if(keymsg_task_name)
    {
        /* os_taskq_post_msg(keymsg_task_name, 1, msg); */
		 key_msg_sender(keymsg_task_name, msg);
    }
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief   按键去抖函数，输出稳定键值
   @param   key：键值
   @return  稳定按键
   @note    tu8 key_filter(tu8 key)
*/
/*----------------------------------------------------------------------------*/
static tu8 key_filter(tu8 key)
{
    static tu8 used_key = NO_KEY;
    static tu8 old_key;
    static tu8 key_counter;

    if (old_key != key)
    {
        key_counter = 0;
        old_key = key;
    }
    else
    {
        key_counter++;
        if (key_counter == KEY_BASE_CNT)
        {
            used_key = key;
        }
    }

    return used_key;
}

#if   KEY_IO_EN

static tu8 io_key_filter(tu8 key)
{
    static tu8 used_key_io = NO_KEY;
    static tu8 old_key_io;
    static tu8 key_counter_io;

    if (old_key_io != key)
    {
        key_counter_io = 0;
        old_key_io = key;
    }
    else
    {
        key_counter_io++;
        if (key_counter_io == KEY_BASE_CNT)
        {
            used_key_io = key;
        }
    }

    return used_key_io;
}

#endif
/*----------------------------------------------------------------------------*/
/**@brief   按键-消息转换函数,按键产生顺序：短按抬起/长按-->连按
   @param
   @param
   @return  void
   @note
*/
/*----------------------------------------------------------------------------*/
tu8 get_key_value(void)
{
    tu8 i;
    for(i = 0; i < MAX_TYPE_KEY; i++)
    {
        tu8 msg;
        tu8 (*get_key)(void);

        get_key = get_key_tab[i];
        if(NULL != get_key)
        {
        
#if KEY_IR_EN
            if(i == KEY_TYPE_IR)
            {
                msg = get_key();
//			printf("msg=======%d\n",msg);
            }
            else
#endif

#if  KEY_TCH_EN
                if(i == KEY_TYPE_TOUCH)
                {
                    msg = get_key();
                }
                else
#endif



#ifdef SUPPORT_TM1628_KEY_READ
                if(i == KEY_TYPE_LED_DRIVER)
                {
                    msg = get_key();
                }
                else
#endif

#if   KEY_IO_EN&&KEY_AD_EN    //IO AD 双模式 才区分这儿
                    if(i == KEY_TYPE_IO)
                    {
                        msg = io_key_filter(get_key());
                    }
                    else
#endif
                    {
                        msg = key_filter(get_key());
				 #ifdef MIC_CHECK_OUT_VOL_X_STEP
				 	if(g_mic_var.bDevOnline)
				 	    return NO_KEY;				 
				 #endif
                    }

            if(NO_KEY != msg)
            {
                key_type = i;
                return msg;
            }
        }
    }
    return NO_KEY;
}

/*----------------------------------------------------------------------------*/
/**@brief   按键-消息转换函数,按键产生顺序：短按抬起/长按-->连按
   @param
   @param
   @return  void
   @note
*/
/*----------------------------------------------------------------------------*/
#define KEY_DOUBLE_CLICK_CNT    35 //35*10ms
void key_scan(void *ptr)
{
    static tu8 last_key = NO_KEY;
    static tu8 key_press_counter;
    static u8  key_press_flag = 0;
    tu8 cur_key, key_status, back_last_key;

    key_voice_dac_channel();

    if(key_press_flag)
    {
        key_press_flag++;
        if(key_press_flag > KEY_DOUBLE_CLICK_CNT)
        {
            key_puts(" One_Click ");
            key_press_flag = 0;
            key2msg_filter(KEY_SHORT_UP, 0);
        }
    }

    cur_key = NO_KEY;
    back_last_key = last_key;
    cur_key = get_key_value();
//	printf("cur_key----+++++++----%d\n",cur_key);


    if(cur_key != NO_KEY)
        key_invalid_flag = 1;
    else
        key_invalid_flag = 0;

    if (cur_key == last_key)                            //长时间按键
    {
        if (cur_key == NO_KEY)
        {
            return;
        }

        key_press_counter++;

	 #if defined SUPPORT_MODE_VOICE_ONOFF||defined SUPPORT_DOUBLE_MODE_VOICE

		if(KEY_TYPE_AD == key_type)  // 75*5*2=750*4=3s
		{
	//		printf("cur_key=========%d",cur_key);
		
				if ((key_press_counter == KEY_LONG_CNT)&&(cur_key!=0x08)) //长按
				{
					key_status = KEY_LONG;
				}
	
			   else if ((key_press_counter == KEY_LONG_CNT*4)&&(cur_key==0x08))//长按
				{
					key_status = KEY_LONG;
				}
			   
				else if (key_press_counter == (KEY_LONG_CNT + KEY_HOLD_CNT)&&(cur_key!=0x08))		 //连按
				{
					key_status = KEY_HOLD;
					key_press_counter = KEY_LONG_CNT;
				}	
				else if (key_press_counter == (KEY_LONG_CNT*4 + KEY_HOLD_CNT)&&(cur_key==0x08)) 	   //连按
				{
					key_status = KEY_HOLD;
					key_press_counter = KEY_LONG_CNT*4;
				}
				else
				{
					return;
				}			
		}
		else
			
	 #endif
	 
	 	{
		        if (key_press_counter == KEY_LONG_CNT)          //长按
		        {
		            key_status = KEY_LONG;
		        }
		        else if (key_press_counter == (KEY_LONG_CNT + KEY_HOLD_CNT))        //连按
		        {
		            key_status = KEY_HOLD;
		            key_press_counter = KEY_LONG_CNT;
		        }
		        else
		        {
		            return;
		        }
	 	}
		
    }
    else  //cur_key = NO_KEY, 抬键
    {
        last_key = cur_key;
        if ((key_press_counter < KEY_LONG_CNT) && (cur_key != NO_KEY))
        {
        }
        if ((key_press_counter < KEY_LONG_CNT) && (cur_key == NO_KEY))      //短按抬起
        {
            key_press_counter = 0;
            key_status = KEY_SHORT_UP;
        }
        else if((cur_key == NO_KEY) && (key_press_counter >= KEY_LONG_CNT)) //长按抬起
        {
            key_press_counter = 0;
            key_status = KEY_LONG_UP;
            puts("[UP]");
        }
        else
        {
            key_press_counter = 0;
            return;
        }
    }
#ifdef KEY_DOUBLE_CLICK
    if(!strcmp(keymsg_task_name,"btmsg"))//蓝牙模式才有按键双击功能
    {
        if((back_last_key==0)&&(key_status==KEY_SHORT_UP))
        {
            if(key_press_flag == 0)
                key_press_flag = 1;
            if((key_press_flag > 15) && (key_press_flag <= KEY_DOUBLE_CLICK_CNT))
            {
                key_puts(" Double_Click ");
                key_press_flag = 0;
                key2msg_filter(key_status, 9);
            }
        }
        else
        {
            key2msg_filter(key_status, back_last_key);
        }
    }
    else
#endif/*KEY_DOUBLE_CLICK*/
    {
        key2msg_filter(key_status, back_last_key);
    }

}

/*----------------------------------------------------------------------------*/
/**@brief   按键消息注册
   @param
   @param
   @return  void
   @note
*/
/*----------------------------------------------------------------------------*/
#if defined(ir_max_num) &&  defined (adkey_max_num)&&  defined (SUPPORT_TM1628_KEY_READ)
void key_msg_register(char *task_name,const u8 led_key_t[4][LED_KEY_MAX],const u8 ad_key_t[4][adkey_max_num],const u8 io_key_t[4][10], const u8 ir_key_t[4][ir_max_num], const u8 touch_key_t[4][10])
#elif defined(ir_max_num) &&  defined (adkey_max_num)
void key_msg_register(char *task_name,const u8 ad_key_t[4][adkey_max_num],const u8 io_key_t[4][10], const u8 ir_key_t[4][ir_max_num], const u8 touch_key_t[4][10])
#elif defined(ir_max_num)
void key_msg_register(char *task_name,const u8 ad_key_t[4][10],const u8 io_key_t[4][10], const u8 ir_key_t[4][ir_max_num], const u8 touch_key_t[4][10])
#elif defined(adkey_max_num)
void key_msg_register(char *task_name,const u8 ad_key_t[4][adkey_max_num],const u8 io_key_t[4][10], const u8 ir_key_t[4][21], const u8 touch_key_t[4][10])
#else
void key_msg_register(char *task_name,const u8 ad_key_t[4][10],const u8 io_key_t[4][10], const u8 ir_key_t[4][21], const u8 touch_key_t[4][10])
#endif
{
    keymsg_task_name = task_name;

//#if KEY_AD_EN
//#if USE_AD_KEY0
//   if(ad_key_t)
    //    memcpy(ad_msg_table,ad_key_t,4*10);
//#endif

#ifdef SUPPORT_TM1628_KEY_READ
  if(led_key_t)
  #if LED_KEY_MAX
   memcpy(led_msg_table,led_key_t,4*LED_KEY_MAX);
  #else
  memcpy(led_msg_table,led_key_t,4*10);
  #endif
#endif


#if KEY_AD_EN ||KEY_IO_EN||KEY_TCH_EN  //所有按键 都用AD按键表
    if(ad_key_t)
#ifdef adkey_max_num
        memcpy(ad_msg_table,ad_key_t,4*adkey_max_num);
#else
        memcpy(ad_msg_table,ad_key_t,4*10);
#endif
#endif
//#endif

#if 0//KEY_IO_EN
    if(io_key_t)
        memcpy(io_msg_table,io_key_t,4*10);
#endif

#if KEY_IR_EN
#ifdef ir_max_num
    if(ir_key_t)
        memcpy(ir_msg_table,ir_key_t,4*ir_max_num);
#else
    if(ir_key_t)
        memcpy(ir_msg_table,ir_key_t,4*21);
#endif
#endif

#if KEY_TCH_EN
    // if(touch_key_t)
    //    memcpy(touch_msg_table,touch_key_t,4*10);
#endif
}


void menu_key_msg_register(char *task_name,u8 *menu_key_msg)
{
    menu_keytask_name = task_name;
    memcpy(menu_keymsg_table,menu_key_msg,10);
}

void menu_key_msg_unregister(void)
{
    menu_keytask_name = NULL;
}
