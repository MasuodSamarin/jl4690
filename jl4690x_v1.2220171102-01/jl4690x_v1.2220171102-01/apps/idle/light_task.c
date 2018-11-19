
#include "common/app_cfg.h"
#include "rtos/os_api.h"
#include "rtos/os_cfg.h"
#include "common/error.h"
#include "common/msg.h"
#include "rtos/task_manage.h"
#include "sys_detect.h"
#include "dac/dac_api.h"
#include "play_sel/play_sel.h"
#include "key_drv/key.h"
#include "idle_key.h"
#include "idle.h"

#include "rcsp/rcsp_interface.h"

extern void *malloc_fun(void *ptr,u32 len,char *info);
extern void free_fun(void **ptr);
extern void test_fw_led_mode(void);
extern void light_scene_frame_deal_test(void);
/*----------------------------------------------------------------------------*/
/**@brief  Idle ����
   @param  p��������������ָ��
   @return ��
   @note   static void idle_task(void *p)
*/
/*----------------------------------------------------------------------------*/
static void light_task(void *p)
{
    int msg[3];

    puts("\n************************light TASK********************\n");
    //led_fre_set(15,0);
    //tone_play(RDEF_LIGHT_TASK_NAME, BPF_RING_MP3); //Idle��ʾ������
//    tone_play_by_name(RDEF_LIGHT_TASK_NAME,1, BPF_RING_MP3); //line in��ʾ������
    os_taskq_post_msg(RDEF_LIGHT_TASK_NAME, 1, MSG_IDLE_MODE); //����idleģ���ʼ��

    while(1)
    {
        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);
        clear_wdt();
        switch(msg[0])
        {
        case SYS_EVENT_DEL_TASK:
            if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
            {
                puts("IDLE_SYS_EVENT_DEL_TASK\n");
                //play_sel_stop(); //�ر���ʾ��
                os_task_del_res_name(OS_TASK_SELF);
            }
            break;

        case SYS_EVENT_PLAY_SEL_END: //��ʾ������
            puts("IDLE_SYS_EVENT_PLAY_SEL_END\n");
            //play_sel_stop(); //�ر���ʾ��
            puts("IDEL_play_tone_end\n");
            os_taskq_post_msg(RDEF_LIGHT_TASK_NAME, 1, MSG_IDLE_MODE);
            break;

        case MSG_IDLE_MODE:
            puts("MSG_IDLE_MODE\n");
//                ui_open_idle(NULL,0);
            //low_power_mode(WAKEUP_13,WAKEUP_DOWN_EDGE);
            break;

        case MSG_IDLE_CTL:
            puts("MSG_IDLE_CTL\n");
            os_taskq_post_msg("MainTask", 1, MSG_EXIT_IDLE_TASK);
            break;

        case MSG_HALF_SECOND:
            ///puts(" light_H ");
//            test_fw_led_mode();
//            light_scene_frame_deal_test();
            break;

        default:
            break;
        }
        Update_rcsp_Task_State(msg[0],0);
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  IDLE ���񴴽�
   @param  priv��������������ָ��
   @return ��
   @note   static void idle_task_init(void *priv)
*/
/*----------------------------------------------------------------------------*/
static void light_task_init(void *priv)
{
    u32 err;
    err = os_task_create(light_task,
                         (void*)0,
                         TaskIdlePrio,
                         10
#if OS_TIME_SLICE_EN > 0
                         ,1
#endif
                         ,RDEF_LIGHT_TASK_NAME);

    if(OS_NO_ERR == err)
    {
	 #ifdef SUPPORT_TM1628_KEY_READ
        key_msg_register(RDEF_LIGHT_TASK_NAME, idle_led_table,idle_ad_table, idle_io_table, idle_ir_table, NULL);
	 #else    
        key_msg_register(RDEF_LIGHT_TASK_NAME, idle_ad_table, idle_io_table, idle_ir_table, NULL);
	 #endif
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  IDLE ����ɾ���˳�
   @param  ��
   @return ��
   @note   static void idle_task_exit(void)
*/
/*----------------------------------------------------------------------------*/
static void light_task_exit(void)
{
    if (os_task_del_req(RDEF_LIGHT_TASK_NAME) != OS_TASK_NOT_EXIST)
    {
        os_taskq_post_event(RDEF_LIGHT_TASK_NAME, 1, SYS_EVENT_DEL_TASK);
        do
        {
            OSTimeDly(1);
        }
        while(os_task_del_req(RDEF_LIGHT_TASK_NAME) != OS_TASK_NOT_EXIST);
        puts("del_light_task: succ\n");
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  IDLE ������Ϣ
   @note   const struct task_info idle_task_info
*/
/*----------------------------------------------------------------------------*/
TASK_REGISTER(light_task_info) =
{
    .name = RDEF_LIGHT_TASK_NAME,
    .init = light_task_init,
    .exit = light_task_exit,
};
