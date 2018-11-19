#include "common/app_cfg.h"
#include "rtos/os_api.h"
#include "rtos/os_cfg.h"
#include "common/msg.h"
#include "rtos/task_manage.h"
#include "usb_device.h"
#include "usb_key.h"
#include "dac/dac.h"
#include "dac/dac_api.h"
#include "play_sel/play_sel.h"
#include "dev_pc.h"
#include "dev_manage/dev_ctl.h"
#include "pc_prompt.h"
#include "sys_detect.h"
#include "pc_ui.h"
#include "key_drv/key.h"
#include "rcsp/rcsp_interface.h"

///extern void *malloc_fun(void *ptr,u32 len,char *info);
///extern void free_fun(void **ptr);

u8 usb_spk_vol_value;

//extern volatile u32 dac_energy_value;
extern u32 usb_device_unmount(void);
extern DAC_CTL dac_ctl;

#define USB_PLAY_ENERGY_MAX   (6000)

#if USB_PC_EN

#undef 	NULL
#define NULL	0
/*----------------------------------------------------------------------------*/
/**@brief  PC������ ����
   @param  p��������������ָ��
   @return ��
   @note   static void pc_card_task(void *p)
*/
/*----------------------------------------------------------------------------*/
static void pc_card_task(void *p)
{
    int msg[6];

    pc_puts("--------pc_card_task-----\n");
#ifdef support_amP_ab_d
    Set_amp_ab_d_out() ;
    Set_AMP_IS_D();
#endif
    workmode=PC_WORK_MODE;
    while(1)
    {
        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);

        switch(msg[0])
        {
        case SYS_EVENT_DEL_TASK:
            pc_puts("PCCARD_SYS_EVENT_DEL_TASK\n");
            if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
            {
                os_task_del_res_name(OS_TASK_SELF);
            }
            break;
        }
        while(1)
        {
            if(0 == app_usb_slave_online_status())
            {
                pc_puts("pc_tast_offline\n");
                break; //PC����
            }
            if(0 == ((card_reader_status *)msg[0])->working)
            {
                pc_puts("pc_card_notworking\n");
                break;
            }
            ((card_reader_status *)msg[0])->busy = 1;
            app_usb_slave_card_reader(MSG_PC_UPDATA); //����������
        }
        ((card_reader_status *)msg[0])->busy = 0;
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  PC������ ���񴴽�
   @param  priv��������������ָ��
   @return ��
   @note   static void pc_card_task_init(void *priv)
*/
/*----------------------------------------------------------------------------*/
static void pc_card_task_init(void *priv)
{

    os_task_create(pc_card_task,
                   (void*)0,
                   TaskPcCardPrio,
                   10
#if OS_TIME_SLICE_EN > 0
                   ,1
#endif
                   ,PC_CARD_TASK_NAME);

}


/*----------------------------------------------------------------------------*/
/**@brief  PC������ ����ɾ���˳�
   @param  ��
   @return ��
   @note   static void pc_card_task_exit(void)
*/
/*----------------------------------------------------------------------------*/
static void pc_card_task_exit(void)
{
    if (os_task_del_req(PC_CARD_TASK_NAME) != OS_TASK_NOT_EXIST)
    {
        puts("send pc SYS_EVENT_DEL_TASK\n");
        os_taskq_post_event(PC_CARD_TASK_NAME, 1, SYS_EVENT_DEL_TASK);
        do
        {
            OSTimeDly(1);
            putchar('D');
        }
        while(os_task_del_req(PC_CARD_TASK_NAME) != OS_TASK_NOT_EXIST);
        pc_puts("del_pc_card_task: succ\n");
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  PC ������Դ�ͷ�
   @param  susb_var��PCģʽ����ı�����Դָ��
   @return ��
   @note   void close_usb_slave(card_reader_status *card_status)
*/
/*----------------------------------------------------------------------------*/
static void close_usb_slave(card_reader_status *card_status)
{
    card_status->working = 0;
    while(card_status->busy)
    {
        pc_puts("-busy-");
        os_time_dly(5);
    }
    app_usb_slave_close(); //�ر�usb slaveģ��
    pc_card_task_exit(); //ɾ������������
}

bool change_usb_play_state(int new_st)
{
    u32 dac_energy_value = get_dac_energy_value();
    if(dac_energy_value > USB_PLAY_ENERGY_MAX)
    {
        if(new_st == RCSP_CBK_MSG_COMM_PAUSE)
        {
            return true;
        }
    }
    else
    {
        if(new_st == RCSP_CBK_MSG_COMM_PLAY)
        {
            return true;
        }
    }
    return false;
}


/*----------------------------------------------------------------------------*/
/**@brief  PC ����
   @param  p��������������ָ��
   @return ��
   @note   static void pc_task(void *p)
*/
/*----------------------------------------------------------------------------*/
static void pc_task(void *p)
{
    int msg[6];
    u32 pc_mute_status = 0;
    static card_reader_status card_status;
    u8 sync_pc_vol_flag = 0;

    pc_puts("\n************************PC TASK********************\n");

    memset(&card_status, 0x00, sizeof(card_reader_status));
//    tone_play_by_name(PC_TASK_NAME, 1,BPF_PC_MP3);

 	os_taskq_post_msg(PC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);

    /* os_time_dly(300); */

    pc_prompt_playing = 0;
    //led_fre_set(15,0);

    while(1)
    {
        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);

        if(msg[0] != MSG_HALF_SECOND)
        {
            printf("\nudisk_msg= 0x%x\n",msg[0]);
        }

        clear_wdt();
        switch(msg[0])
        {
        case SYS_EVENT_DEL_TASK:
            pc_puts("PC_SYS_EVENT_DEL_TASK 1\n");
            if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
            {
                ///UI_menu(MENU_WAIT);
                pc_puts("PC_SYS_EVENT_DEL_TASK 2\n");
                ui_close_pc();
                pc_puts("PC_SYS_EVENT_DEL_TASK3\n");
                play_sel_stop(); //�ر���ʾ��
                pc_puts("PC_SYS_EVENT_DEL_TASK4\n");
                close_usb_slave(&card_status);
                pc_puts("PC_SYS_EVENT_DEL_TASK5\n");
                os_task_del_res_name(OS_TASK_SELF);
            }

            sync_pc_vol_flag  = 0;
            break;

        case SYS_EVENT_PLAY_SEL_END: //��ʾ������
            puts("PC_SYS_EVENT_PLAY_SEL_END\n");
            play_sel_stop(); //�ر���ʾ��

            puts("PC_SYS_EVENT_PLAY_SEL_END-----\n");
#ifdef PC_PROMPT_EN
            if(pc_prompt_playing)
            {
                pc_puts("PC_play_tone_end_1\n");
                pc_prompt_playing = 0;
                dac_set_samplerate(48000,0); //DAC����������Ϊ48K
                pc_channel_on(); //��PC DACģ��ͨ��
                break;
            }
#endif
            sync_pc_vol_flag  = 6;
        case MSG_PC_MODE_INIT:
            puts("MSG_PC_MODE_INIT\n");
            if(NULL == app_usb_slave_init())
            {
                break;
            }
            card_status.busy = 1;
            ui_open_pc(NULL, 0);

        /*************** for CARD READER ******************/
        case MSG_PC_CARD_READER:
            pc_puts("MSG_PC_CARD_READER\n");
            card_status.working = 1;
            os_taskq_post_msg(PC_CARD_TASK_NAME, 1, &card_status);
            break;

        /*************** for AUDIO ******************/
        case MSG_PC_SPK_MUTE:
            pc_puts("MSG_PC_SPK_MUTE\n");
            pc_mute_status = 1;
            pc_dac_mute(1, FADE_ON);
            break;

        case MSG_PC_SPK_UNMUTE:
            pc_puts("MSG_PC_SPK_UNMUTE\n");
            pc_mute_status = 0;
            pc_dac_mute(0, FADE_ON);

        case MSG_PC_SPK_VOL:
//            puts("MSG_PC_SPK_VOL\n");
            usb_spk_vol_value = app_pc_set_speaker_vol(pc_mute_status);
            rcsp_report_status(RCSP_REPORT_VOL_VALUE);
            puts("pc_vol\n");
            if(sync_pc_vol_flag != 1)
            {
                rcsp_report_status(RCSP_REPORT_START_CONFIG);
                sync_pc_vol_flag = 1;
            }
            break;

        /*************** for HID KEY ******************/
        case MSG_PC_MUTE:
            pc_puts("p_m\n");
            app_usb_slave_hid(USB_AUDIO_MUTE);
            break;

        case MSG_PC_VOL_DOWN:
            pc_puts("vd\n");
            app_usb_slave_hid(USB_AUDIO_VOLDOWN);
            ///UI_menu(MENU_PC_VOL_DOWN);
            break;

        case MSG_PC_VOL_UP:
            pc_puts("vu\n");
            app_usb_slave_hid(USB_AUDIO_VOLUP);
            ///UI_menu(MENU_PC_VOL_UP);
            break;

        case MSG_PC_PP:
            pc_puts("pp\n");
            if(msg[1] != 0)
            {
                if(change_usb_play_state(msg[1]))
                {
                    app_usb_slave_hid(USB_AUDIO_PP);
                }
            }
            else
            {
                app_usb_slave_hid(USB_AUDIO_PP);
            }
            break;

        case MSG_PC_PLAY_NEXT:
            pc_puts("ne\n");
            app_usb_slave_hid(USB_AUDIO_NEXTFILE);
            break;

        case MSG_PC_PLAY_PREV:
            pc_puts("pr\n");
            app_usb_slave_hid(USB_AUDIO_PREFILE);
            break;

        case MSG_LOW_POWER:
            puts("pc_low_power\n");
            ///pc_prompt_play(BPF_LOW_POWER_MP3);
            break;

        /*************** for PC UPDATA ******************/
        case MSG_PC_UPDATA:
            pc_puts("MSG_PC_UPDATA\n");
            dev_updata_mode(usb_device_unmount, PC_UPDATA); //����PC����ģʽ
            break;

        case MSG_HALF_SECOND:
//            pc_puts(" PC_H ");

            if(get_dac_energy_value() > USB_PLAY_ENERGY_MAX)
            {
                rcsp_set_task_status(STAUS_PLAY);
            }
            else
            {
                rcsp_set_task_status(STAUS_PAUSE);
            }
            printf("eng = %d\n",get_dac_energy_value());
            if(sync_pc_vol_flag)
            {
                if(sync_pc_vol_flag > 2)
                {
                    sync_pc_vol_flag--;
                }
                else if(sync_pc_vol_flag == 2)
                {
                    puts("get sync_vol\n");
                    app_usb_slave_hid(USB_AUDIO_VOLUP);
                    sync_pc_vol_flag = 4;
                }
                else
                {
                    ;
                }

            }
            break;

        default:
            //pc_puts("pc_default\n");
            break;
        }

        Update_rcsp_Task_State(msg[0],1);
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  PC�����PC���������񴴽�
   @param  priv��������������ָ��
   @return ��
   @note   static void pc_task_init(void *priv)
*/
/*----------------------------------------------------------------------------*/
static void pc_task_init(void *priv)
{
    u32 err;

    //��ʼ��PC����
    err = os_task_create(pc_task,
                         (void*)0,
                         TaskPcPrio,
                         10
#if OS_TIME_SLICE_EN > 0
                         ,1
#endif
                         ,PC_TASK_NAME);

    //��ʼ������������
    pc_card_task_init(NULL);

    //����ӳ��
    if(OS_NO_ERR == err)
    {
	  #ifdef SUPPORT_TM1628_KEY_READ
	        key_msg_register(PC_TASK_NAME, usb_led_table,adkey_msg_usb_table, iokey_msg_usb_table, irff00_msg_usb_table, NULL);
	 #else    
	        key_msg_register(PC_TASK_NAME, adkey_msg_usb_table, iokey_msg_usb_table, irff00_msg_usb_table, NULL);
	 #endif
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  PC ����ɾ���˳�
   @param  ��
   @return ��
   @note   static void pc_task_exit(void)
*/
/*----------------------------------------------------------------------------*/
static void pc_task_exit(void)
{
    if (os_task_del_req(PC_TASK_NAME) != OS_TASK_NOT_EXIST)
    {
        os_taskq_post_event(PC_TASK_NAME, 1, SYS_EVENT_DEL_TASK);
        do
        {
            OSTimeDly(1);
        }
        while(os_task_del_req(PC_TASK_NAME) != OS_TASK_NOT_EXIST);
        pc_puts("del_pc_task: succ\n");
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  PC ������Ϣ
   @note   const struct task_info pc_task_info
*/
/*----------------------------------------------------------------------------*/
TASK_REGISTER(pc_task_info) =
{
    .name = PC_TASK_NAME,
    .init = pc_task_init,
    .exit = pc_task_exit,
};

#undef 	NULL

#endif
