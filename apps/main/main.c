#include "sdk_cfg.h"
#include "includes.h"
#include "main_key.h"
#include "rtos/os_api.h"
#include "common/app_cfg.h"
#include "dev_manage/dev_ctl.h"
#include "file_operate/file_op_err.h"
#include "rtos/task_manage.h"
#include "usb_device.h"
#include "key_drv/key.h"
#include "common/flash_cfg.h"
#include "vm/vm_api.h"
#include "ui/ui_api.h"
#include "rcsp/rcsp_interface.h"
#include "dac/dac_api.h"
#include "linein.h"
#include "sys_detect.h"
#include "bluetooth/avctp_user.h"
#include "key_drv/key_drv_io.h"
#include "ui/led/led.h"
#include "key_drv/key_voice.h"
#include "dac/dac.h"
#include "rtc/rtc_api.h"
#include "update.h"
#include "file_operate/file_op.h"
#include "clock_api.h"
#include "irq_api.h"
#include "linein/dev_linein.h"
#include "music_ui.h"

///************************************************

#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif
#ifdef SUPPORT_M62429
#include "dev_manage\M62429.h"
#endif
#include "ui/led/led7_drv.h"

#ifdef AMP_MUTE_ENABLE
 u8 bPowerOnAmpMuteTimer;
#endif

#ifdef SUPPORT_LOW_POWER_DELAY_DET
u8 bLowPowerDetDelay;
#endif
#ifdef SUPPORT_ADD10_KEY_DIRECT_PLAY
#include "dec/decoder_phy.h"
#include "music_ui.h"
#endif

#ifdef SUPPORT_POWER_ON_FREQUENCE_DELAY_SHOW
u8 bFrequencePowerOnDelayVal;
#endif

#if defined( support_line_pause_disp_pause)  ||defined(support_fm_pause_disp_pause)
extern bool   aux_pause_mark;
#endif

#ifdef power_on_wait_power_key_down
void main_powerup_wait(void);
#endif


#ifdef support_msg_light_key
u8   light_mode_mark=0;   //  0  OFF  1 EQ  2 ≈‹¬Ì
#endif
#if  SUPPORT_ALL_VOICE
u8 IsVoiceEnable;
u8 bVoiceNumber;
#ifdef SUPPORT_VOICE_ONOFF_KEY_SINGLE_KEY
u8 bStoreVoiceVal;
#endif
#endif

#ifdef SUPPORT_MODE_VOICE_ONOFF
#ifdef SUPPORT_DEFAULT_VOCE_ON	
u8 bModeVoiceOnoffFlag=1;
#else
u8 bModeVoiceOnoffFlag=0;
#endif
#endif
#ifdef SUPPORT_DOUBLE_MODE_VOICE
u8 bModeVoiceSelFlag;	// 0-en  1-ch
#endif

#if  MIC_ONOFF_KEY
#include "music_ui.h"
bool mic_sw;
#endif

#ifdef SUPPORT_DOUBLE_LED7_PANEL
bool bLed7SelFlag; // 0--1panel   1-2panel
#endif

#ifdef SUPPORT_MODE_VOICE_EN_CH_ONOFF
u8 bModeVoiceSelVal; //0-off  1-ch  2-en
u8 bStoreModeVoiceSelVal; //0-off  1-ch  2-en
#endif


#ifdef SUPPORT_VOICE_ONOFF
bool bVoiceOnoff;
#endif



#ifdef SUPPORT_VM_EQ_MODE
extern u8 eq_mode ;
#endif

#ifdef SUPORT_MODE_KEY_REC_FILE_CHANGE
#ifdef SUPPORT_RECPLAY_STATE
extern bool bIfRecordFolder;
#endif
#if REC_EN
extern bool rec_play_sw;
#endif
#endif

#ifdef SUPPORT_RGB_LED_MODE
extern u8 bRgbMode;
extern u16 bRgbModeCnt;
#include "sys_detect.h"
#endif

#if defined SUPPORT_POWER_ON_IN_IDLE_MODE
extern bool  bPowerOnIdleFlag;
#endif
#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
u8 bFmUmuteTimer;
#endif


#ifdef support_enconder_onoff
u8 sw_encoder;
#endif


#ifdef SUPPORT_LOW_POWER_STANBY
bool bLowPowerFlag;

#endif

#ifdef SUPPORT_BAT_DETECT_LOW_POWER_MODE_MSJ
bool	bLowPowerFlag;	
#endif



#if defined support_sw_chack
extern u8	 bPowerSwFlag;
#endif


 #ifdef SUPPORT_ENCODE_flash_led
 #ifdef SUPPORT_ENCODE_VOL_KEY_FLASH_LED
 extern u8 ENCODE_flash_led_time;
 #endif
 #endif

#ifdef support_power_on_dly
u8 bPowerOnMuteTimer;  // jsuo
#endif


#ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
#if LINEIN_MULTIPLY_DEFAULT_MODE
u8 bModeOfAuxContained=LINEIN_MULTIPLY_DEFAULT_MODE;
#else
u8 bModeOfAuxContained=0;
#endif
#endif

bool usb_to_sd_flag;



///************************************************
#include "encode/encode.h"

bool dec_dev_changed = 0;

extern void enter_sleep_mode(void);
enum{
	WAKEUP_0 = 0,
	WAKEUP_1,
	WAKEUP_2,
	WAKEUP_3,
	WAKEUP_4,
	WAKEUP_5,
	WAKEUP_6,
	WAKEUP_7,
	WAKEUP_8,
	WAKEUP_9,
	WAKEUP_10,
	WAKEUP_11,
	WAKEUP_12,
	WAKEUP_13,
	WAKEUP_14,
	WAKEUP_15,
};

#define WAKEUP_UP_EDGE     0x0f
#define WAKEUP_DOWN_EDGE   0xf0


extern volatile u8 low_power_flag;


extern tbool mutex_resource_apply(char *resource,int prio,void (*apply_response)(), void (*release_request)());
extern tbool mutex_resource_release(char *resource);
extern void resourse_manage_init(void);
extern void user_ctrl_prompt_tone_play(u8 status,void *ptr);
extern tbool play_sel_busy(void);

extern u32 lg_dev_status_chg(u32 status,void *parm,u32 lgdevnum);
extern u32 lg_dev_mount(void *parm,u8 first_let,u32 total_lgdev);
extern u8 *dev_get_phydev_name(void *drv_it);

extern volatile u8 low_power_flag;
extern void set_poweroff_wakeup_io_handle_register(void (*handle)(),void (*sleep_io_handle)(),void (*sleep_handle)());

extern volatile u8 new_lg_dev_let;

extern void ble_init_config(void);
extern void light_init(void);
extern void fm_radio_powerdown(void);
extern void enter_sleep_mode(void);


#ifdef  support_led_eq_is_K1_mode
u8     to_mcu_data_on;
#endif


u8   workmode;
bool  add_100_flag;
#ifdef support_mute_led_all_flish
bool  mute_flag;
#endif


u8 power_on_cnt = 0;




#if EARPHONE_MODE_EN
void set_power_on_cnt(u8 cnt)
{
	power_on_cnt = cnt;
}
#endif


void set_poweroff_wakeup_io()
{
	u8 wakeup_io_en = 0;
	u8 wakeup_edge = 0;

	//BIT(0)  PR0 : 0 disable  1 enable
	//BIT(1)  PR1 : 0 disable  1 enable
	//BIT(2)  PR2 : 0 disable  1 enable
	//BIT(3)  PR3 : 0 disable  1 enable
	/* wakeup_io_en |= WAKE_UP_PR0 | WAKE_UP_PR1 | WAKE_UP_PR2 | WAKE_UP_PR3; */
	wakeup_io_en |=  WAKE_UP_PR2;

	//BIT(4)  PR0 : 0 rising dege  1 failling edge
	//BIT(5)  PR1 : 0 rising dege  1 failling edge
	//BIT(6)  PR2 : 0 rising dege  1 failling edge
	//BIT(7)  PR3 : 0 rising dege  1 failling edge
	/* wakeup_edge |= EDGE_PR0 | EDGE_PR1 | EDGE_PR2 | EDGE_PR3;     //failling edge */
	/* wakeup_edge &= ~(EDGE_PR0 | EDGE_PR1 | EDGE_PR2 | EDGE_PR3);  //rising dege */
	wakeup_edge |= EDGE_PR2;     //failling edge

	soft_poweroff_wakeup_io(wakeup_io_en , wakeup_edge);
}

#ifdef AC6901A_OFF_IO
void AC6901A_NOUSER_IO(void)
{

	PORTR_DIR(PORTR1,1);
	PORTR_PU(PORTR1,0);
	PORTR_PD(PORTR1,0);

	PORTR_DIR(PORTR2,1);
	PORTR_PU(PORTR2,0);
	PORTR_PD(PORTR2,0);

	PORTR_DIR(PORTR3,1);
	PORTR_PU(PORTR3,0);
	PORTR_PD(PORTR3,0);


JL_PORTB->DIR |= (BIT(5)|BIT(6)|BIT(7)|BIT(8));
JL_PORTB->PU &= ~(BIT(5)|BIT(6)|BIT(7)|BIT(8));
JL_PORTB->PD &= ~(BIT(5)|BIT(6)|BIT(7)|BIT(8));
JL_PORTB->DIE |= (BIT(5)|BIT(6)|BIT(7)|BIT(8));

}

#elif defined AC6905A_OFF_IO
void AC6905A_NOUSER_IO(void)
{
#ifdef AC6905A_OFF_IO_JH

JL_PORTB->DIR |= (BIT(13));
JL_PORTB->PU &= ~(BIT(13));
JL_PORTB->PD &= ~(BIT(13));
JL_PORTB->DIE |= (BIT(13));

#elif defined(AC6905A_OFF_IO_TY)
JL_PORTB->DIR |= (BIT(13));
JL_PORTB->PU &= ~(BIT(13));
JL_PORTB->PD &= ~(BIT(13));
JL_PORTB->DIE |= (BIT(13));


JL_PORTA->DIR |= (BIT(4));
JL_PORTA->PU &= ~(BIT(4));
JL_PORTA->PD &= ~(BIT(4));
JL_PORTA->DIE |= (BIT(4));


#else
JL_PORTA->DIR |= (BIT(3));
JL_PORTA->PU &= ~(BIT(3));
JL_PORTA->PD &= ~(BIT(3));
JL_PORTA->DIE |= (BIT(3));

JL_PORTA->DIR |= (BIT(4));
JL_PORTA->PU &= ~(BIT(4));
JL_PORTA->PD &= ~(BIT(4));
JL_PORTA->DIE |= (BIT(4));

JL_PORTC->DIR |= (BIT(3));
JL_PORTC->PU &= ~(BIT(3));
JL_PORTC->PD &= ~(BIT(3));
JL_PORTC->DIE |= (BIT(3));
#endif

}

#elif defined AC6905C_OFF_IO
void AC6905A_NOUSER_IO(void)
{

JL_PORTA->DIR |= (BIT(3));
JL_PORTA->PU &= ~(BIT(3));
JL_PORTA->PD &= ~(BIT(3));
JL_PORTA->DIE |= (BIT(3));

JL_PORTA->DIR |= (BIT(4));
JL_PORTA->PU &= ~(BIT(4));
JL_PORTA->PD &= ~(BIT(4));
JL_PORTA->DIE |= (BIT(4));

JL_PORTC->DIR |= (BIT(3));
JL_PORTC->PU &= ~(BIT(3));
JL_PORTC->PD &= ~(BIT(3));
JL_PORTC->DIE |= (BIT(3));

}


#elif defined AC6902B_OFF_IO
void AC6905A_NOUSER_IO(void)
{

JL_PORTB->DIR |= (BIT(13));
JL_PORTB->PU &= ~(BIT(13));
JL_PORTB->PD &= ~(BIT(13));
JL_PORTB->DIE |= (BIT(13));


}



#endif
/*enter sleep mode wakeup IO setting*/
void enter_sleep_mode_set(u16 wakeup_cfg , u8 wakeup_edge)
{


#if 0
	return;

#else
	close_wdt();

	dac_off_control();  //close dac mudule
    JL_AUDIO->LADC_CON = 0;
    JL_AUDIO->ADA_CON0 = 0;
    JL_AUDIO->ADA_CON1 = 0;
    JL_AUDIO->ADA_CON2 = 0;

	JL_AUDIO->DAA_CON0 = 0;
	JL_AUDIO->DAA_CON1 = 0;
	JL_AUDIO->DAA_CON2 = 0;
	JL_AUDIO->DAA_CON3 = 0;
	JL_AUDIO->DAA_CON4 = 0;
	JL_AUDIO->DAA_CON5 = 0;

	JL_WAKEUP->CON0 = 0;      //wakeup enbale
	JL_WAKEUP->CON1 = 0;      //wakeup edge
	JL_WAKEUP->CON2 = 0xffff; //wakeup pending(clear)

	switch(wakeup_cfg)
	{
		case WAKEUP_0:
			break;

		case WAKEUP_1:
			break;

		case WAKEUP_2:
			printf("WAKEUP_2\n");
			JL_WAKEUP->CON2 |= BIT(2);
			JL_PORTA->DIR |= BIT(8);
			JL_PORTA->DIE |= BIT(8);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTA->PU |= BIT(8);
				JL_PORTA->PD &= ~BIT(8);
				JL_WAKEUP->CON1 |= BIT(2);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTA->PU &= ~BIT(8);
				JL_PORTA->PD |= BIT(8);
				JL_WAKEUP->CON1 &= ~BIT(2);
			}
			JL_WAKEUP->CON0 |= BIT(2);
			break;

		case WAKEUP_3:
			printf("WAKEUP_3\n");
			JL_WAKEUP->CON2 |= BIT(3);
			JL_PORTA->DIR |= BIT(10);
			JL_PORTA->DIE |= BIT(10);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTA->PU |= BIT(10);
				JL_PORTA->PD &= ~BIT(10);
				JL_WAKEUP->CON1 |= BIT(3);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTA->PU &= ~BIT(10);
				JL_PORTA->PD |= BIT(10);
				JL_WAKEUP->CON1 &= ~BIT(3);
			}
			JL_WAKEUP->CON0 |= BIT(3);
			break;

		case WAKEUP_4:
			printf("WAKEUP_4\n");
			JL_WAKEUP->CON2 |= BIT(4);
			JL_PORTA->DIR |= BIT(14);
			JL_PORTA->DIE |= BIT(14);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTA->PU |= BIT(14);
				JL_PORTA->PD &= ~BIT(14);
				JL_WAKEUP->CON1 |= BIT(4);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTA->PU &= ~BIT(14);
				JL_PORTA->PD |= BIT(14);
				JL_WAKEUP->CON1 &= ~BIT(4);
			}
			JL_WAKEUP->CON0 |= BIT(4);
			break;
		case WAKEUP_5:
			break;
		case WAKEUP_6:
			break;
		case WAKEUP_7:
			break;
		case WAKEUP_8:
			printf("WAKEUP_8\n");
			JL_WAKEUP->CON2 |= BIT(8);
			JL_PORTA->DIR |= BIT(3);
			JL_PORTA->DIE |= BIT(3);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTA->PU |= BIT(3);
				JL_PORTA->PD &= ~BIT(3);
				JL_WAKEUP->CON1 |= BIT(8);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTA->PU &= ~BIT(3);
				JL_PORTA->PD |= BIT(3);
				JL_WAKEUP->CON1 &= ~BIT(8);
			}
			JL_WAKEUP->CON0 |= BIT(8);
			break;
		case WAKEUP_9:
			printf("WAKEUP_9\n");
			JL_WAKEUP->CON2 |= BIT(9);
			JL_PORTA->DIR |= BIT(5);
			JL_PORTA->DIE |= BIT(5);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTA->PU |= BIT(5);
				JL_PORTA->PD &= ~BIT(5);
				JL_WAKEUP->CON1 |= BIT(9);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTA->PU &= ~BIT(5);
				JL_PORTA->PD |= BIT(5);
				JL_WAKEUP->CON1 &= ~BIT(9);
			}
			JL_WAKEUP->CON0 |= BIT(9);
			break;
		case WAKEUP_10:
			printf("WAKEUP_10\n");
			JL_WAKEUP->CON2 |= BIT(10);
			JL_PORTB->DIR |= BIT(0);
			JL_PORTB->DIE |= BIT(0);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTB->PU |= BIT(0);
				JL_PORTB->PD &= ~BIT(0);
				JL_WAKEUP->CON1 |= BIT(10);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTB->PU &= ~BIT(0);
				JL_PORTB->PD |= BIT(0);
				JL_WAKEUP->CON1 &= ~BIT(10);
			}
			JL_WAKEUP->CON0 |= BIT(10);
			break;
		case WAKEUP_11:
			printf("WAKEUP_11\n");
			JL_WAKEUP->CON2 |= BIT(11);
			JL_PORTB->DIR |= BIT(2);
			JL_PORTB->DIE |= BIT(2);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTB->PU |= BIT(2);
				JL_PORTB->PD &= ~BIT(2);
				JL_WAKEUP->CON1 |= BIT(11);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTB->PU &= ~BIT(2);
				JL_PORTB->PD |= BIT(2);
				JL_WAKEUP->CON1 &= ~BIT(11);
			}
			JL_WAKEUP->CON0 |= BIT(11);
			break;
		case WAKEUP_12:
			printf("WAKEUP_12\n");
			JL_WAKEUP->CON2 |= BIT(12);
			JL_PORTB->DIR |= BIT(9);
			JL_PORTB->DIE |= BIT(9);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTB->PU |= BIT(9);
				JL_PORTB->PD &= ~BIT(9);
				JL_WAKEUP->CON1 |= BIT(12);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTB->PU &= ~BIT(9);
				JL_PORTB->PD |= BIT(9);
				JL_WAKEUP->CON1 &= ~BIT(12);
			}
			JL_WAKEUP->CON0 |= BIT(12);
			break;
		case WAKEUP_13:
			printf("WAKEUP_13\n");
			JL_WAKEUP->CON2 |= BIT(13);
			JL_PORTB->DIR |= BIT(11);
			JL_PORTB->DIE |= BIT(11);
			if(wakeup_edge == WAKEUP_DOWN_EDGE)
			{
				printf("WAKEUP_DOWN_EDGE\n");
				JL_PORTB->PU |= BIT(11);
				JL_PORTB->PD &= ~BIT(11);
				JL_WAKEUP->CON1 |= BIT(13);
			}
			else
			{
				printf("WAKEUP_UP_EDGE\n");
				JL_PORTB->PU &= ~BIT(11);
				JL_PORTB->PD |= BIT(11);
				JL_WAKEUP->CON1 &= ~BIT(13);
			}
			JL_WAKEUP->CON0 |= BIT(13);
			break;
		case WAKEUP_14:
			break;
		case WAKEUP_15:
			break;

		default:
			return;
	}
#endif
}

/*sleep mode wakeup io setting function*/
void set_sleep_mode_wakeup_io()
{
	enter_sleep_mode_set(WAKEUP_4,WAKEUP_DOWN_EDGE);
}

/*sleep mode before close IRQ callback fuction*/
void set_sleep_before_close_irq()
{
#if FM_RADIO_EN
    if(compare_task_name(FM_TASK_NAME))
	{
    	fm_radio_powerdown();
	}
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief  main task
   @param
   @return
   @note   task always running,can't delete

 */
/*----------------------------------------------------------------------------*/

extern void ram1_fast_run_standby(void);
extern void call_main_deal();
extern u32 test_power_off(u32 usec);
extern u32 pc_limh;
extern u32 pc_liml;
extern void delay(u32 d);

//static u32 power_off_cnt = 0;

static void delay_us(u32 n)
{
    delay(n*(SYS_Hz/1000000L));
}


extern const u32 ad_table[];
extern void adc_init_api(u32 channel,u32 lsb_clk,u8 lvd_en);
extern void adc_scan(void *param);
extern u16 get_battery_level(void);

//static u8 low_power_cnt = 0;
//static u32 normal_power_cnt = 0;

/* mode 1:power on     2:power off*/
void ldo5v_detect_deal(u8 mode)
{
   // static u32 delay_2ms_cnt = 0;
  //  u8 val = 0;
   // u8 tmp;

#if EARPHONE_MODE_EN
    adc_init_api(ad_table[0],clock_get_lsb_freq(),SYS_LVD_EN);
    /*check if low power*/
    if(mode == 1)
    {
        LED_INIT_EN();
        while(1)
        {
            clear_wdt();
            delay_us(2000); //2ms
            delay_2ms_cnt++;
            adc_scan(NULL);


            if((delay_2ms_cnt % 5) == 0)   //10ms
            {
                delay_2ms_cnt = 0;
                /*battery check*/
                val = get_battery_level();
                /* printf("battery : %d\n",val); */
                if(val < 31)
                {
                    low_power_cnt++;
                    if(low_power_cnt > 10)
                    {
                        R_LED_ON();
                        B_LED_OFF();
                        delay_us(200000); //1s
                        soft_power_ctl(PWR_OFF);
                    }
                }
                else
                {
                    normal_power_cnt++;
                    if(normal_power_cnt > 10)  //normal power
                    {
                        delay_2ms_cnt = 0;
					#if CHARGE_POWER_OFF    //can not power on when charging
						JL_PORTA->DIR |= BIT(3);
						JL_PORTA->PU  &= ~BIT(3);
						JL_PORTA->PD  |= BIT(3);
					#endif
                        while(1)
                        {
                            clear_wdt();
                            delay_us(2000); //2ms

                        #if KEY_IO_EN
						#if CHARGE_POWER_OFF
							if(IS_KEY0_DOWN() && !(JL_PORTA->IN & BIT(3))) 	//can not power on when charging
						#else
							if(IS_KEY0_DOWN())
						#endif
                        #else
                        	if(1)
                        #endif
                            {
                                putchar('+');
                                delay_2ms_cnt++;
                                if(delay_2ms_cnt > 40)
                                {
                                    R_LED_ON();
                                    B_LED_OFF();
                                    goto __POWER_ON;
                                }
                            }
                            else
                            {
                                putchar('-');
                                delay_2ms_cnt = 0;
                                soft_power_ctl(PWR_OFF);
                            }
                        }
                    }
                }
            }
        }
 __POWER_ON:   }
#endif



    return;
}

/*----------------------------------------------------------------------------
	sys  vol show set
---------------------------------------------------------------------------*/
#if LED_SHOW_VOL_MAX

u8 bVolMaxChangeToSmallVolMax=RESET_DEFAULT_VOL;

void sysVolMaxChangeToUserVolMaxProc(bool bVolIncOrMinus)
{
 #if 	SYS_VOL_MAX==30 && LED_SHOW_VOL_MAX==60

 if(bVolIncOrMinus){//vol plus
  bVolMaxChangeToSmallVolMax++;
  if(bVolMaxChangeToSmallVolMax>60){
	 bVolMaxChangeToSmallVolMax=60;
	 dac_ctl.sys_vol_l =SYS_VOL_MAX;
	 }else
		if(bVolMaxChangeToSmallVolMax%2==0){
		 if(dac_ctl.sys_vol_l  < SYS_VOL_MAX )
		dac_ctl.sys_vol_l++;
		}
 }
  else{//vol minus
	  if(bVolMaxChangeToSmallVolMax) bVolMaxChangeToSmallVolMax--;
	  if(bVolMaxChangeToSmallVolMax==60)dac_ctl.sys_vol_l=SYS_VOL_MAX;
	  if(bVolMaxChangeToSmallVolMax<=1) {
	    dac_ctl.sys_vol_l=0;
	  }
	  if(bVolMaxChangeToSmallVolMax>=1) {
	    if(bVolMaxChangeToSmallVolMax%2==0) {
	         if(dac_ctl.sys_vol_l)
	          	dac_ctl.sys_vol_l--;
	          }
	  }
  }
 #elif SYS_VOL_MAX==25 && LED_SHOW_VOL_MAX==60

  if(bVolIncOrMinus)
  {//vol plus
	  bVolMaxChangeToSmallVolMax++;
	  if(bVolMaxChangeToSmallVolMax>60)
	  	{
			 bVolMaxChangeToSmallVolMax=60;
			 dac_ctl.sys_vol_l =SYS_VOL_MAX;
		 }
		else if(bVolMaxChangeToSmallVolMax<=5)
		{
			 dac_ctl.sys_vol_l =0;
		}	  
		else if(bVolMaxChangeToSmallVolMax%2==0)
		{
		 	if(dac_ctl.sys_vol_l  < SYS_VOL_MAX )
				dac_ctl.sys_vol_l++;
		}
    }
  else
  	{//vol minus
	  if(bVolMaxChangeToSmallVolMax)
	  	bVolMaxChangeToSmallVolMax--;
	  if(bVolMaxChangeToSmallVolMax==60)
	  	dac_ctl.sys_vol_l=SYS_VOL_MAX;
	  if(bVolMaxChangeToSmallVolMax<=5) 
	  	{
	    		dac_ctl.sys_vol_l=0;
	 	 }
	 else  if(bVolMaxChangeToSmallVolMax%2==0) 
	 	{
	         if(dac_ctl.sys_vol_l)
	          	dac_ctl.sys_vol_l--;
	       }
  }

 #elif SYS_VOL_MAX==30 && LED_SHOW_VOL_MAX==62

  if(bVolIncOrMinus)
  {//vol plus
	  bVolMaxChangeToSmallVolMax++;
	  if(bVolMaxChangeToSmallVolMax>62)
	  	{
			 bVolMaxChangeToSmallVolMax=62;
			 dac_ctl.sys_vol_l =SYS_VOL_MAX;
		 }
		else if(bVolMaxChangeToSmallVolMax%2==0){
		 if(dac_ctl.sys_vol_l  < SYS_VOL_MAX )
		dac_ctl.sys_vol_l++;
		}
    }
  else
  	{//vol minus
	  if(bVolMaxChangeToSmallVolMax) bVolMaxChangeToSmallVolMax--;
	  if(bVolMaxChangeToSmallVolMax==62)dac_ctl.sys_vol_l=SYS_VOL_MAX;
	  if(bVolMaxChangeToSmallVolMax<=2) {
	    dac_ctl.sys_vol_l=0;
	  }
	 else  if(bVolMaxChangeToSmallVolMax%2==0) {
	         if(dac_ctl.sys_vol_l)
	          	dac_ctl.sys_vol_l--;
	          }
  }

  #elif MP3_VOL_MAX==25 && LED_SHOW_VOL_MAX==30

 if(bVolIncOrMinus){//vol plus
  bVolMaxChangeToSmallVolMax++;
  if(bVolMaxChangeToSmallVolMax>30){
	 bVolMaxChangeToSmallVolMax=30;
	 dac_ctl.sys_vol_l =MP3_VOL_MAX;
	 }
  else
	{
	     if(dac_ctl.sys_vol_l  < MP3_VOL_MAX )
		dac_ctl.sys_vol_l++;
	}
 }
  else{//vol minus
	  if(bVolMaxChangeToSmallVolMax) bVolMaxChangeToSmallVolMax--;
	  if(bVolMaxChangeToSmallVolMax==30)dac_ctl.sys_vol_l=MP3_VOL_MAX;
	  if(bVolMaxChangeToSmallVolMax<=5) {
	    dac_ctl.sys_vol_l=0;
	  }
	  if(bVolMaxChangeToSmallVolMax>=5) {
	     {
	         if(dac_ctl.sys_vol_l)
	          	dac_ctl.sys_vol_l--;
	         }
	  }
  } 

  
 #elif AUX_VOL_MAX==27 && LED_SHOW_VOL_MAX==30

 if(bVolIncOrMinus){//vol plus
  bVolMaxChangeToSmallVolMax++;
  if(bVolMaxChangeToSmallVolMax>30){
	 bVolMaxChangeToSmallVolMax=30;
	 dac_ctl.sys_vol_l =AUX_VOL_MAX;
	 }
 else if(bVolMaxChangeToSmallVolMax>=AUX_VOL_MAX){
	   dac_ctl.sys_vol_l =AUX_VOL_MAX;
	 }
  else
		{
		     if(dac_ctl.sys_vol_l  < AUX_VOL_MAX )
			dac_ctl.sys_vol_l++;
		}
 }
  else{//vol minus
	  if(bVolMaxChangeToSmallVolMax) bVolMaxChangeToSmallVolMax--;
	  if(bVolMaxChangeToSmallVolMax==30)dac_ctl.sys_vol_l=AUX_VOL_MAX;
	  if(bVolMaxChangeToSmallVolMax<=3) {
	    dac_ctl.sys_vol_l=0;
	  }
	  if(bVolMaxChangeToSmallVolMax>=3) {
	     {
	         if(dac_ctl.sys_vol_l)
	          	dac_ctl.sys_vol_l--;
	         }
	  }
  } 
  

  #elif SYS_VOL_MAX==26 && LED_SHOW_VOL_MAX==30
  
  if(bVolIncOrMinus){//vol plus
  bVolMaxChangeToSmallVolMax++;
  if(bVolMaxChangeToSmallVolMax>30){
	 bVolMaxChangeToSmallVolMax=30;
	 dac_ctl.sys_vol_l =SYS_VOL_MAX;
	 }
 else if(bVolMaxChangeToSmallVolMax>=SYS_VOL_MAX){
	   dac_ctl.sys_vol_l =SYS_VOL_MAX;
	 }
  else
		{
		     if(dac_ctl.sys_vol_l  < SYS_VOL_MAX )
			dac_ctl.sys_vol_l++;
		}
 }
  else{//vol minus
	  if(bVolMaxChangeToSmallVolMax) bVolMaxChangeToSmallVolMax--;
	  if(bVolMaxChangeToSmallVolMax==30)dac_ctl.sys_vol_l=SYS_VOL_MAX;
	  if(bVolMaxChangeToSmallVolMax<=4) {
	    dac_ctl.sys_vol_l=0;
	  }
	  if(bVolMaxChangeToSmallVolMax>=3) {
	     {
	         if(dac_ctl.sys_vol_l)
	          	dac_ctl.sys_vol_l--;
	         }
	  }
  } 
  
 #elif SYS_VOL_MAX==30 && LED_SHOW_VOL_MAX==32

 if(bVolIncOrMinus){//vol plus
  bVolMaxChangeToSmallVolMax++;
  if(bVolMaxChangeToSmallVolMax>32){
	 bVolMaxChangeToSmallVolMax=32;
	 dac_ctl.sys_vol_l =SYS_VOL_MAX;
	 }else
		{
		     if(dac_ctl.sys_vol_l  < SYS_VOL_MAX )
			dac_ctl.sys_vol_l++;
		}
 }
  else{//vol minus
	  if(bVolMaxChangeToSmallVolMax) bVolMaxChangeToSmallVolMax--;
	  if(bVolMaxChangeToSmallVolMax==32)dac_ctl.sys_vol_l=SYS_VOL_MAX;
	  if(bVolMaxChangeToSmallVolMax<=2) {
	    dac_ctl.sys_vol_l=0;
	  }
	  if(bVolMaxChangeToSmallVolMax>=2) {
	     {
	         if(dac_ctl.sys_vol_l)
	          	dac_ctl.sys_vol_l--;
	         }
	  }
  } 
#endif
}
//#elif BT_VOL_MAX

#endif

/*----------------------------------------------------------------------------
	sys  start  io  init  jsuo add 20160811
---------------------------------------------------------------------------*/

void main_sys_io_init(void)
{

#if  MIC_ONOFF_KEY
    MUSIC_DIS_VAR *pp_state;
#endif

#if defined(PA_ENABLE)
    pa_mute_io_set();
    pa_mute();
#endif

#ifdef support_power_on_dly
bPowerOnMuteTimer=9;  // jsuo
	 #ifdef support_power_on_mute
	 	set_power_on_mute_io_is_out();
	 	set_power_on_mute_io_high();
	 #endif

#endif

  #if defined(LCD_4x9_MODE)
	  LCD_INIT();
  #endif
#ifdef SUPPORT_RGB_LED_MODE
	  rgb_pwm_init();
  #endif

#ifdef SUPPORT_PT2313
	  PT2313_Init();
#ifdef SWVOL_LED_SHOW_MAX
	swvol_temp_vol=SWVOL_LED_SHOW_DEFAULT;
#endif
#endif
#ifdef SUPPORT_M62429
		  M62429Init();
#endif
#ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
	 SET_REXTERN_POWER_FM_SCAN_IO(0);
#endif	

#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
	bFmUmuteTimer=9;
	SET_REXTERN_POWER_FM_MUTE_IO(1);
#endif

#ifdef SUPPORT_POWER_ON_FREQUENCE_DELAY_SHOW
	bFrequencePowerOnDelayVal=8;
#endif


#ifdef SUPPORT_BAT_DETECT
#ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
	LOW_POWER_OFF_USE_EXTERN_IO(1);
#endif

#ifdef AMP_POWER_ENABLE
	AMP_POWER_IO(1);
#endif

#ifdef AMP_MUTE_ENABLE
	bPowerOnAmpMuteTimer=AMP_POWER_ON_MUTE_TIMER;
	AMP_MUTE_IO(1);
#endif

#endif


#ifdef SUPPORT_POWER_ON_DELAY_TIMER
  os_time_dly(50);
#endif

#ifdef SUPPORT_LOW_POWER_DELAY_DET
	bLowPowerDetDelay=POWER_ON_LOW_POWER_DELAY_VAL;
#endif

#ifdef support_AMP_POWER_ON_SET
 bPowerOnAmpTimer=AMP_POWER_ON_TIMER;
 Set_AMP_POWER_ON_IS_HIGHT();
#endif

 #if defined(AMP_AB_D)
 	AMP_AB_D_IO_IS_OUT();
 	AMP_AB_D_IO_D();
 #endif

 #ifdef KOK_DETECT_USE_IO_ADC_VALUE
 	#ifdef support_mic_check_user_PA14
 		PORTA_OUT&= ~BIT(14);
 		PORTA_PD |= BIT(14);
 		PORTA_PU &= ~BIT(14);
 		PORTA_DIR &=~ BIT(14);
 		PORTA_DIE |= BIT(14);
 	#endif
 #endif


    /*****************muzhe *************************/
#ifdef support_off_usb_dm
    USB_DM_DIR(0);
    USB_DM_PD(0) ;
    USB_DM_PU(0) ;
#endif
#ifdef support_off_usb_dp
    USB_DP_DIR(0);
    USB_DP_PD(0);
    USB_DP_PU(0) ;
#endif

#ifdef support_off_PB13
    JL_PORTB->DIR|=  BIT(13);
    JL_PORTB->PU &= ~BIT(13) ;
    JL_PORTB->PD&= ~BIT(13) ;
#endif




#ifdef AC6901A_OFF_IO
 	AC6901A_NOUSER_IO();
#elif defined AC6905A_OFF_IO
 	AC6905A_NOUSER_IO();
#endif



#ifdef SUPPORT_DOUBLE_LED7_PANEL

	 DOUBLE_LED7_DET_INIT()

	if(DOUBLE_LED7_DET_IO_IS_L())
		bLed7SelFlag=0;
	else
		bLed7SelFlag=1;

	printf("---bLed7SelFlag---%d\n",bLed7SelFlag);

#endif


#ifdef support_msg_light_key   //∆µ∆◊…¡µ∆ƒ£ Ω

#ifdef  support_led_eq_is_K1_mode
     to_mcu_data_on=1;
#endif

#ifdef support_default_light_on   //ƒ¨»œø™ª˙µ∆ƒ£ Ω1
    light_mode_mark=1;
#endif


#ifdef support_led_LIGHT_MODE   // ÷µÁÕ≤
    set_led_light_io_is_out();
    if( light_mode_mark)
        Set_led_light_io_is_on();
    else
        set_led_light_io_off();

#endif

#endif


#if  MIC_ONOFF_KEY
vm_read_api(VM_MIC_ONOFF,&mic_sw);
if(mic_sw>=1)
	mic_sw=0;
#endif




/*************************************************************/

#if   SUPPORT_ALL_VOICE
	 #ifdef SUPPORT_VOICE_ENALBE_MEM
	 
	 		vm_read_api(VM_VOICE_ONOFF,&IsVoiceEnable);
	 
	 	 #ifdef  SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 		if(IsVoiceEnable>2)
	 		{
	 			IsVoiceEnable=POWER_ON_VOICE_DEFAULT;
	 		}
	 		
	 		if(IsVoiceEnable==0)
	 			bStoreVoiceVal=POWER_ON_VOICE_DEFAULT;
	 		
	 	 #elif defined POWER_ON_VOICE_DEFAULT
	 		if(IsVoiceEnable>1)
	 		{
	 			IsVoiceEnable=POWER_ON_VOICE_DEFAULT;
	 		}
	 	 #endif
	 
	 #else
	 	 #ifdef  POWER_ON_VOICE_DEFAULT
	 	 		IsVoiceEnable=POWER_ON_VOICE_DEFAULT;
	 	 #else
	 	 		IsVoiceEnable=1;
	 	 #endif
	 
	 #endif

#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF

		vm_read_api(VM_VOICE_ONOFF,&bModeVoiceSelVal);

		if(bModeVoiceSelVal>2)
		{
			bModeVoiceSelVal=POWER_ON_VOICE_DEFAULT;
		}
		
		vm_read_api(VM_MODE_VOICE_ONOFF,&bStoreModeVoiceSelVal);
		
		if((bStoreModeVoiceSelVal>2)||(bStoreModeVoiceSelVal==0))
		{
			bStoreModeVoiceSelVal=POWER_ON_VOICE_DEFAULT;
		}

		
#endif


#if defined SUPPORT_MODE_VOICE_ONOFF
	vm_read_api(VM_MODE_VOICE_ONOFF,&bModeVoiceOnoffFlag);

	if(bModeVoiceOnoffFlag>1)
	{
		 #ifdef SUPPORT_DEFAULT_VOCE_ON	
		 		bModeVoiceOnoffFlag=1;
		 #else
		 		bModeVoiceOnoffFlag=0;
		 
		 #endif
	}

#endif


#ifdef SUPPORT_VM_EQ_MODE

	vm_read_api(VM_WORK_MODE,&eq_mode);

	if(eq_mode>5)
	{
		eq_mode=0;
	}
#endif


#if defined SUPPORT_DOUBLE_MODE_VOICE
	bModeVoiceSelFlag=1;
#endif

#ifdef SUPPORT_SCG_VOICE
#ifdef SUPPORT_VOICE_ONOFF
	 vm_read_api(VM_VOICE_ONOFF,&bVoiceOnoff);
	if(bVoiceOnoff>1)
		{
			bVoiceOnoff=0;
		}
#endif
#endif






}
//------------------------------------------------------------------
extern void printf_test(void);
static void TaskMain(void *p)
{
    int msg[6];
    u32 status;
    u32 bt_status=0;
    #ifdef SUPPORT_ADD10_KEY_DIRECT_PLAY
    MUSIC_DIS_VAR *music_p10;
    #endif
    curr_task = NULL;
    soft_poweroff_cnt = 0;
    going_to_pwr_off = 0;
#if(BT_MODE!=NORMAL_MODE)
    bd_work_mode = BD_PAGE_MODE;
#else
    bd_work_mode = BD_CONN_MODE;
#endif
    puts("****TaskMain********\n");

    update_deal(UPDATE_OK_WHILE);

#if 0
#include "iic.h"
    eeprom_verify();
    while(1);
#endif


#ifdef power_on_wait_power_key_down
    main_powerup_wait();
#endif


    //SFR(JL_SYSTEM->LDO_CON,7,3,1);
    workmode=MAIN_WORK_MODE;
    led_init();

    main_sys_io_init();  // jsuo add 20160811

    JL_SYSTEM->LVD_CON |= BIT(2);
#if DAC_AUTO_MUTE_EN
    digit_auto_mute_set(AUTO_MUTE_CFG, 4, 1200, 200);
#endif
    resourse_manage_init();
    vm_cache_start();
    audio_init();
    dev_ctrl_sys_init(0);

#if RCSP_LIGHT_HW
    light_init();
#endif

#if EARPHONE_MODE_EN
	set_power_on_cnt(6);
#endif
#ifdef SUPPORT_POWEN_ON_DELAY_XTIMER
  os_time_dly(SUPPORT_POWEN_ON_DELAY_XTIMER);
#endif

    while(1)
    {
        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);
        clear_wdt();

        if(msg[0] != MSG_HALF_SECOND)
        {
            printf("\nmain_msg= 0x%x\n",msg[0]);
        }

        //printf("main_msg %08x %08x \n",msg[0],msg[1]);
        switch(msg[0])
        {
        case SYS_EVENT_LGDEV_ONLINE:
            printf("LGDEV ONLINE--%08x-%08x\n",msg[1],msg[2]);

	 		#if MEDIA_MODE_USB_SD_DETECT
			#if SDMMC0_EN
	 	                if((sd0==msg[1])||(usb==msg[1]))
			#else
	 	                if((sd1==msg[1])||(usb==msg[1]))
			#endif
	 	                {
	 	                    curr_device_using=msg[1];
	 	                }
	 		 #endif

            status=lg_dev_status_chg(SYS_EVENT_LGDEV_ONLINE,(void *)msg[1],msg[2]);
            if((status!=FILE_OP_ERR_LGDEV_FULL)/*&&(status!='A')*/)
            {

                if(((char)status == 'A'))       ///< SPIFLASHËÆæÂ§ámount
                {
                    puts("up\n");
                    lg_dev_mount((void *)msg[1],status,msg[2]);
                    puts("power up\n");

#if UI_ENABLE
                    ui_init_api();///±ÿ–Îπ“‘ÿflash∫Û≤≈ƒ‹≥ı ºªØLCDœ‘ æ
                    UI_menu(MENU_POWER_UP);
#endif

#ifdef  MINI
#if defined(PA_ENABLE)
                    pa_umute();
#endif

                    power_up_task();//      task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);
#else
                    //	puts("*************Select Task***************\n");
#if defined(PA_ENABLE)
                    pa_umute();
#endif
                    power_up_task();
                    //     task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);
                    //task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
//                    task_switch(RTC_TASK_NAME, 0,SWITCH_SPEC_TASK);
#endif // MINI_BT

                    os_taskq_post_event((char *)"CheckTask", 1, SYS_EVENT_LGDEV_ONLINE);
                    break;
                }
                else
                {
                    printf("\n---------new phydev name: %s ---------\n",dev_get_phydev_name((void *)msg[1]));
                    rcsp_device_change(dev_get_phydev_name((void *)msg[1]));
                    new_lg_dev_let=status;
                }
#ifdef POWERUP_DEV_IGNORE
                if(!msg[3])
                    break;
#endif


#ifdef support_stanby_mod
                if(workmode ==STANBY_WORK_MODE )
                    break;
#endif
                if((os_time_get() > 220) && (!bt_status))  //200
                {
                    if(compare_task_name(UDISK_TASK_NAME)) ///<PC Audio
                        break;

			#ifdef SUPPORT_POWER_ON_IDLE_MODE_ERRO // don't check  media
	                    if(compare_task_name(IDLE_TASK_NAME)) ///<PC Audio
	                        break;
	               #endif


			 #ifdef LED_SHOW_DEVICE_PLUGIN
			 	led7_var.dwDeviceID= msg[1];
			 #endif

                    if((task_switch(MUSIC_TASK_NAME, 0,SWITCH_SPEC_TASK)==RUN_TASK_ERR_HAS_RPT))
                    {
                        printf("music has run...\n");
                        os_taskq_post_event((char *)MUSIC_TASK_NAME, 2, SYS_EVENT_DEV_ONLINE,status);
                    }
                }
            }
            break;

        case SYS_EVENT_LGDEV_OFFLINE:
			
            printf("------dev offline ---\n");
            os_taskq_post_event((char *)keymsg_task_name, 2, SYS_EVENT_DEV_OFFLINE,msg[1]);
            lg_dev_status_chg(SYS_EVENT_LGDEV_OFFLINE,(void *)msg[1],1);
            break;

        case SYS_EVENT_AUX_IN:
            puts("SYS_EVENT_AUX_IN\n");
			
	 #ifndef SUPPORT_AUX_IN_WAKE_UP_STANDBY
	 #ifdef support_stanby_mod
	         if(workmode ==STANBY_WORK_MODE )
	             break;
	 #endif
	 #endif

 #if  AUX_DETECT_EN

	 #ifdef SUPPORT_DOUBLE_LINEIN
	             if(workmode ==LINE_WORK_MODE )
	             	{
	             		 workmode=LINE_WORK_MODE_2;
	 	 		os_taskq_post_msg("LineinTask", 1, MSG_AUX_INIT);
	             	}
	 		else
	 		{
	             	      workmode=LINE_WORK_MODE_2;
	 	            if(os_time_get() > 200)
	 	                task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);
	 		}
	 #else
            if(os_time_get() > 200)
                task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);

	 #endif
#else
            if(os_time_get() > 200)
                task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);
#endif

            break;

        case SYS_EVENT_AUX_OUT:
#ifdef support_stanby_mod
            if(workmode ==STANBY_WORK_MODE )
                break;
#endif
            puts("SYS_EVENT_AUX_OUT\n");
            if(compare_task_name(LINEIN_TASK_NAME))
                task_switch(0,0,SWITCH_NEXT_TASK);
            break;

        case SYS_EVENT_PC_IN:
#ifdef support_stanby_mod
            if(workmode ==STANBY_WORK_MODE )
                break;
#endif
            puts("SYS_EVENT_PC_IN\n");
            if(os_time_get() > 200)
                task_switch(PC_TASK_NAME, 0, SWITCH_SPEC_TASK);
            break;

        case SYS_EVENT_PC_OUT:
#ifdef support_stanby_mod
            if(workmode ==STANBY_WORK_MODE )
                break;
#endif
            puts("SYS_EVENT_PC_OUT\n");
            if(compare_task_name(UDISK_TASK_NAME))
                task_switch(0, 0, SWITCH_NEXT_TASK);
            break;

#if RTC_ALM_EN
        case MSG_ALM_ON:
            puts("\n\n\n\n------MSG_ALM_ON\n");
            task_switch("RTCTask",0,SWITCH_SPEC_TASK);
//            Post_msg_to_rcsp_Task(MSG_RSCP_CHANGE_WORDMODE_ACTION,0,0);
            break;
#endif

        case MSG_CHANGE_WORKMODE:
            puts("MSG_CHANGE_WORKMODE\n");

#ifdef support_stanby_mod
            if(workmode ==STANBY_WORK_MODE )
                break;
#endif


#ifdef SUPORT_MODE_KEY_REC_FILE_CHANGE
	if(compare_task_name(MUSIC_TASK_NAME))
	 {
		if(bIfRecordFolder)
			{
				rec_play_sw=1;
		 		os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_PLAY_REC_FILE);
				break;
			}
	 }
#endif

#ifdef SUPPORT_DOUBLE_LINEIN

#if  AUX_DETECT_EN
            if((workmode ==LINE_WORK_MODE)&&(bAux2Flag))
            	{
           	 	workmode =LINE_WORK_MODE_2;
	 		os_taskq_post_msg("LineinTask", 1, MSG_AUX_INIT);
			break;
            	}
		else

#endif
#endif


#ifdef SUPPORT_MULTI_INPUT_MODE


	 #ifdef SUPPOR_NOP_AND_AUX_MODE
	 
	 	if((compare_task_name(FM_TASK_NAME)))
	 	{
		 	bMultiExternInputSel=INPUT_AUX0_MODE;

                	task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
	 		 break;
	 	}

	 #endif


	if(compare_task_name(LINEIN_TASK_NAME))
	{
		bMultiExternInputSel++;
		 if(bMultiExternInputSel<INPUT_MAX_MODE)
		 {
		 	 os_taskq_post_msg(LINEIN_TASK_NAME, 1, MSG_AUX_INIT);
			 break;
		 }
		 else
		 	bMultiExternInputSel=0;
	}


#endif


		 if(!strcmp(curr_task->name,"MusicTask"))
		 {
//	            puts("\n\n\n\n--dec_dev_changed 11111----   \n\nn\nn");

//		 printf("11111------------dec_dev_changed==%d \n",dec_dev_changed);
//		 printf("222222----file_operate_get_total_phydev()==%x \n",file_operate_get_total_phydev());

		 	if((file_operate_get_total_phydev()>1) && (!dec_dev_changed))
		 	{
//	            puts("\n\n\n\n--dec_dev_changed 222222----   \n\nn\nn");

		 		dec_dev_changed=1;
		 		os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_U_SD);
		 		break;
		 	}
		 }


   #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE

	#ifdef TF_A30_MP3_AUX_FM_BT

		 if(workmode==BT_WORK_MODE)
		   {
			   if(!(file_operate_get_total_phydev()))
			   {
				   bModeOfAuxContained=1;
					task_switch("LineinTask",0,SWITCH_SPEC_TASK);
				   break;
			   }
			   else
			   {
					  task_switch("MusicTask",0,SWITCH_SPEC_TASK);
					  break;
			   }
		   }
		 if(compare_task_name("LineinTask"))
		 {
		   if(bModeOfAuxContained==0)
		   {
			  bModeOfAuxContained=mode_aux;
				os_taskq_post_msg("LineinTask", 1, MSG_AUX_VOICE_PLAY); //¬¥¬•¬∑¬¢AUX√Ñ¬£¬ø√©¬≥√µ√ä¬º¬ª¬Ø
			  break;
		   }
		 }

	#endif

		 if(compare_task_name("LineinTask"))
		 {
			 bModeOfAuxContained++;

			   #if AUX_DGND_DETECT_EN  //aux use io  connect GND to judge if into linein mode
				  #ifdef AUX_DETECT_LOW_REMOVE
				   if(!AUX_IN_CHECK)
			  #else
				  if(AUX_IN_CHECK)
			  #endif
			   {
				   if(bModeOfAuxContained==mode_aux)
					  bModeOfAuxContained++;
			   }
			   #endif

			if(bModeOfAuxContained<mode_linein_max)
			{
				os_taskq_post_msg("LineinTask", 1, MSG_AUX_INIT); //¬¥¬•¬∑¬¢AUX√Ñ¬£¬ø√©¬≥√µ√ä¬º¬ª¬Ø
				break;
			}
			else
			   bModeOfAuxContained=0;
		}
	#ifdef SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
			else if(compare_task_name("MusicTask"))
			{
			 #if AUX_DGND_DETECT_EN
				  #ifdef AUX_DETECT_LOW_REMOVE
					   if(AUX_IN_CHECK)
				  #else
					  if(!AUX_IN_CHECK)
				  #endif
					 {
					  bModeOfAuxContained=mode_aux;
					  task_switch(0,0,SWITCH_NEXT_TASK);
					  break;
				   }
				   else
					   bModeOfAuxContained=mode_aux;
			 #endif

					   bModeOfAuxContained=mode_mp3_nodevice;
					 	if(usb_to_sd_flag==0 && compare_task_name("MusicTask")&& file_operate_get_total_phydev()>1)
					 	{
					 		os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_U_SD);
					 		usb_to_sd_flag =1;
					 		break;
					 	}								   
					 	else
					 	{
					 		bModeOfAuxContained=mode_aux;
					 		task_switch(LINEIN_TASK_NAME, 0,SWITCH_SPEC_TASK);
					 		break;
					 	}

					 	if(compare_task_name(LINEIN_TASK_NAME))
					 	{
					 		bModeOfAuxContained++;
					 		 if(bModeOfAuxContained<mode_linein_max)
					 		 {
					 		 	 os_taskq_post_msg(LINEIN_TASK_NAME, 1, MSG_AUX_INIT);
					 			 break;
					 		 }
					 		 else
					 		 	bModeOfAuxContained=0;
					 	}
						
		   }
   #endif
#endif






	 #ifdef SUPPORT_MULTI_INPUT_MODE
	 #ifdef SUPPOR_MP3_NOP_IN_AUX_MODE

	#if FM_RADIO_EN

	 	if((compare_task_name(BTSTACK_TASK_NAME))&&(file_operate_get_total_phydev()==0))
	 	{
                	task_switch(FM_TASK_NAME, 0, SWITCH_SPEC_TASK);
	 		 break;
	 	}

	 	if((compare_task_name(MUSIC_TASK_NAME)))
	 	{
                	task_switch(FM_TASK_NAME, 0, SWITCH_SPEC_TASK);
	 		 break;
	 	}
		
	#else
	
	 	if((compare_task_name(BTSTACK_TASK_NAME))&&(file_operate_get_total_phydev()==0))
	 	{
  		 	bMultiExternInputSel=0;
                	task_switch(LINEIN_TASK_NAME, 0, SWITCH_SPEC_TASK);
	 		 break;
	 	}

	 	if((compare_task_name(MUSIC_TASK_NAME)))
	 	{
                	task_switch(BTSTACK_TASK_NAME, 0, SWITCH_SPEC_TASK);
	 		 break;
	 	}
	#endif
	 #endif
	 #endif


#if !EARPHONE_MODE_EN
            task_switch(0,0,SWITCH_NEXT_TASK);
#endif
//            Post_msg_to_rcsp_Task(MSG_RSCP_CHANGE_WORDMODE_ACTION,0,0);
            break;

        case SYS_EVENT_TASK_RUN_REQ:
            task_switch((char *)msg[1], 0,SWITCH_SPEC_TASK);
//            Post_msg_to_rcsp_Task(MSG_RSCP_CHANGE_WORDMODE_ACTION,0,0);
            break;


        case SYS_EVENT_DEV_BEGIN_MOUNT:
            if(compare_task_name(MUSIC_TASK_NAME))
            {
                os_taskq_post_event((char *)MUSIC_TASK_NAME, 1, SYS_EVENT_DEV_BEGIN_MOUNT);
            }
            break;
        case SYS_EVENT_DEV_MOUNT_ERR:
            puts("SYS_EVENT_DEV_MOUNT_ERR\n");
            if(compare_task_name(MUSIC_TASK_NAME))
            {
                os_taskq_post_event((char *)MUSIC_TASK_NAME, 1, SYS_EVENT_DEV_MOUNT_ERR);
            }
            break;

        case MSG_VOL_DOWN:

	#ifdef SUPPORT_CHENGE_VOL_PLAY_MUSIC
	
		if(music_ui.opt_state==MUSIC_OPT_BIT_PAUSE)
	            os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_PLAY);

	#endif


	 #ifdef SUPPORT_ENCODE_flash_led
	 #ifdef SUPPORT_ENCODE_VOL_KEY_FLASH_LED
	  ENCODE_flash_led_time=4;
	 #endif
	 #endif



	 #if BT_HID_INDEPENDENT_MODE || USER_SUPPORT_PROFILE_HID
	 #ifdef SUPPORT_HID_AND_VOL_IN_ONE_KEY
	         if(get_curr_channel_state() & HID_CH)
	 		break;
	 #endif
	 #endif

	 #ifdef support_mute_led_all_flish
	             mute_flag=0;
	 #endif

      #ifdef SUPPORT_PT2313
		  PT2313_KEY_PROCESS(menumode,FALSE);
      #else
                 #ifdef LED_SHOW_VOL_MAX
				  #ifdef AUX_VOL_MAX

 					if(compare_task_name(LINEIN_TASK_NAME))
 						sysVolMaxChangeToUserVolMaxProc(FALSE);
 					else if(bVolMaxChangeToSmallVolMax)
					{
 						bVolMaxChangeToSmallVolMax--;
 						dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
 					}
				  #elif defined MP3_VOL_MAX
 					if(compare_task_name(MUSIC_TASK_NAME))
 						sysVolMaxChangeToUserVolMaxProc(FALSE);
 					else if(bVolMaxChangeToSmallVolMax)
					{
 						bVolMaxChangeToSmallVolMax--;
 						dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
 					}				  
				#else
					sysVolMaxChangeToUserVolMaxProc(FALSE);
				 #endif
                #else
		            if(dac_ctl.sys_vol_l)
		                dac_ctl.sys_vol_l--;
                #endif

            user_send_cmd_prepare(USER_CTRL_AVCTP_OPID_SEND_VOL,0,NULL);
            printf("V- = %d\n",dac_ctl.sys_vol_l);
            dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;

 	#endif

                printf("set_vol=  %d\n",dac_ctl.sys_vol_l);

	  #ifdef KOK_DETECT_AUTO_VOL_SET
	 	 store_vol= dac_ctl.sys_vol_l;
	 #endif

	 #if defined(PA_ENABLE) &&defined(support_vol_is_0_mute_amp)
            	 #ifdef SUPPORT_PT2313
                			if((pt2313data[PT_VOLUME]==0)&&!mute_flag)
				 	{
					//	dac_mute(1,1);
					//	pa_mute();		
					 	os_taskq_post("MainTask", 1, MSG_MUTE);
				 	}
            	 #else
		     if(  dac_ctl.sys_vol_r==0)
		     	{
	                dac_mute(1,1);
		         pa_mute();
		     	}
		 #endif
	 #endif

             #ifdef SUPPORT_PT2313
		  if((is_dac_mute()) && (pt2313data[PT_VOLUME]>0))/*muteÁä∂ÊÄÅ‰∏ãÔºåÂä†ÂáèÈü≥ÈáèËß£mute*/
            #else
         	   if(is_dac_mute()&&( dac_ctl.sys_vol_r))
            #endif
	            {
			 #if defined(PA_ENABLE)
			     if(dac_ctl.sys_vol_r)
			         pa_umute();
			 #endif
	                dac_mute(0,1);
			 #ifdef SUPPORT_FLASH_CHAR
			 	LED_FLASH_CHAR=0;
			 	LED_FLASH_ICON=0;
			 #endif
	            }


             #ifdef SUPPORT_PT2313

               #if UI_ENABLE
	            UI_menu_arg(MENU_VOL_MENU,0);
               #endif

             #else

	          	  set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);

			 #if (SYS_DEFAULT_VOL==0)
			         vm_cache_write(VM_SYS_VOL,&dac_ctl.sys_vol_l,2);
			 #endif

	            UI_menu_arg(MENU_MAIN_VOL,0);

	            rcsp_report_status(RCSP_REPORT_VOL_VALUE);


			#if   SUPPORT_ALL_VOICE
			#if SUPPORT_VOL_VOICE
	//		  if (UI_var.bMenuReturnCnt == 0)
	               	 os_taskq_post_msg(keymsg_task_name, 1, MSG_VOICE_VOLUME_MINUS);
			#endif
			#endif

	 	#endif

            break;

        case MSG_VOL_UP:


	#ifdef SUPPORT_CHENGE_VOL_PLAY_MUSIC
		if(music_ui.opt_state==MUSIC_OPT_BIT_PAUSE)
	            os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_PLAY);

	#endif

	 #ifdef SUPPORT_ENCODE_flash_led
	 #ifdef SUPPORT_ENCODE_VOL_KEY_FLASH_LED
	  ENCODE_flash_led_time=4;
	 #endif
	 #endif





	 #if BT_HID_INDEPENDENT_MODE || USER_SUPPORT_PROFILE_HID
	 #ifdef SUPPORT_HID_AND_VOL_IN_ONE_KEY
	         if(get_curr_channel_state() & HID_CH)
	 		break;
	 #endif
	 #endif
	 // ¥¶¿Ì◊Ó¥Û…˘“Ù ± ∞¥“Ù¡øº”ºı …˘“Ùª·Õª»ªº”¥Û  °£°£ ∏„≤ª∂Æ°£°£
	 #ifdef SUPPORT_TIANYIN_AUX_VOL_ADJUST
	 	                if(dac_ctl.sys_vol_l == MAX_SYS_VOL_L)
	 	                	{
				            UI_menu_arg(MENU_MAIN_VOL,0);
						break;
	 	                	}
	#endif

              #ifdef SUPPORT_PT2313
				 PT2313_KEY_PROCESS(menumode,TRUE);
              #else

            if(msg[1]&0x80)
            {
                dac_ctl.sys_vol_l = (u8)(msg[1]&0x7f);
    //            printf("set_vol=  %d\n",dac_ctl.sys_vol_l);
                 #ifdef LED_SHOW_VOL_MAX
				  #ifdef AUX_VOL_MAX
 					if(compare_task_name(LINEIN_TASK_NAME))
 						sysVolMaxChangeToUserVolMaxProc(TRUE);
 					else if(bVolMaxChangeToSmallVolMax < MAX_SYS_VOL_L)
					{
 						bVolMaxChangeToSmallVolMax++;
 						dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
 					}
				  #elif defined MP3_VOL_MAX
 					if(compare_task_name(MUSIC_TASK_NAME))
 						sysVolMaxChangeToUserVolMaxProc(TRUE);
 					else if(bVolMaxChangeToSmallVolMax < MAX_SYS_VOL_L)
					{
 						bVolMaxChangeToSmallVolMax++;
 						dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
 					}				  
				#else
					sysVolMaxChangeToUserVolMaxProc(TRUE);
				 #endif
				 
                #else
	                if(dac_ctl.sys_vol_l < MAX_SYS_VOL_L)
	                    dac_ctl.sys_vol_l++;
                #endif
            }
            else
            {
                 #ifdef LED_SHOW_VOL_MAX
				  #ifdef AUX_VOL_MAX
 					if(compare_task_name(LINEIN_TASK_NAME))
 						sysVolMaxChangeToUserVolMaxProc(TRUE);
 					else if(bVolMaxChangeToSmallVolMax < MAX_SYS_VOL_L)
					{
 						bVolMaxChangeToSmallVolMax++;
 						dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
 					}
				  #elif defined MP3_VOL_MAX
 					if(compare_task_name(MUSIC_TASK_NAME))
 						sysVolMaxChangeToUserVolMaxProc(TRUE);
 					else if(bVolMaxChangeToSmallVolMax < MAX_SYS_VOL_L)
					{
 						bVolMaxChangeToSmallVolMax++;
 						dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
 					}				  
				#else
					sysVolMaxChangeToUserVolMaxProc(TRUE);
				 #endif
				 
                #else
	                if(dac_ctl.sys_vol_l < MAX_SYS_VOL_L)
	                    dac_ctl.sys_vol_l++;
                #endif

                user_send_cmd_prepare(USER_CTRL_AVCTP_OPID_SEND_VOL,0,NULL);
            }

                printf("set_vol=  %d\n",dac_ctl.sys_vol_l);

		 #ifdef support_mute_led_all_flish
		         mute_flag=0;
		 #endif
		 
		 #if KEY_TONE_EN && support_vol_max_tone_en
		         if(dac_ctl.sys_vol_l == MAX_SYS_VOL_L)
		             send_key_voice(500);
		 #endif

	            printf("V+ = %d\n",dac_ctl.sys_vol_l);
	            dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;

		#endif

		  #ifdef KOK_DETECT_AUTO_VOL_SET
		 	 store_vol= dac_ctl.sys_vol_l;
		 #endif


		 #if defined(PA_ENABLE) &&defined(support_vol_is_0_mute_amp)
			 #ifdef SUPPORT_PT2313
				 if(pt2313data[PT_VOLUME]==1)
				 	{
            					if(is_dac_mute())
					 	{
					 		dac_mute(0,1);
		 					 #if defined(PA_ENABLE)
		 					 	pa_umute();
		 					 #endif
			                   #ifdef SUPPORT_MUTE_FLASH
			 				   if(mute_flag)
							   {
			 				   	mute_flag=FALSE;
			 				   	LED_FLASH_CHAR=0;
			 				   	LED_FLASH_ICON=0;
			 				   }
			                  #endif
					 	}
				 	}
			#else

				 #ifdef support_v0l_add_2
				 	if(  dac_ctl.sys_vol_r==2)
				 #else
				 	if(  dac_ctl.sys_vol_r==1)
				 #endif
				 	pa_umute();
				 #endif
				 
				 	if(is_dac_mute())
				 	{
				 	dac_mute(0,1);
				 #if defined(PA_ENABLE)
				 	pa_umute();
				 #endif
				 	//led_fre_set(15,0);
				 #ifdef SUPPORT_FLASH_CHAR
				 	LED_FLASH_CHAR=0;
				 	LED_FLASH_ICON=0;
				 #endif
				 	}
			
			#endif
		 	


           #ifdef SUPPORT_PT2313
                 #if UI_ENABLE
      	          	  UI_menu_arg(MENU_VOL_MENU,0);
           	   #endif
           #else

	            set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);
			 #if (SYS_DEFAULT_VOL==0)
			         vm_cache_write(VM_SYS_VOL,&dac_ctl.sys_vol_l,2);
			 #endif
	            UI_menu_arg(MENU_MAIN_VOL,0);

	            rcsp_report_status(RCSP_REPORT_VOL_VALUE);

			#if   SUPPORT_ALL_VOICE
			#if SUPPORT_VOL_VOICE
	//		  if (UI_var.bMenuReturnCnt == 0)
	               	 os_taskq_post_msg(keymsg_task_name, 1, MSG_VOICE_VOLUME_PLUS);
			#endif
			#endif
	   #endif

            break;

        case MSG_MUTE:

		 #if defined SUPPORT_LOW_POWER_DISABLE_MUTE_KEY
		 if(low_power_flag)
				break;
		 #endif

            puts("MSG_MUTE\n");
		 #ifdef support_line_pause_disp_pause
		             aux_pause_mark=0;
		             SET_UI_UNLOCK();
		 #endif
            if(is_dac_mute())
            {
                dac_mute(0,1);
			#ifdef support_mute_key_out_H
		 		 #if defined(PA_ENABLE)
		 	                 pa_mute();
		 		 #endif
			#else
		 		 #if defined(PA_ENABLE)
		 	                 pa_umute();
		 		 #endif
			#endif

		 #ifdef support_mute_led_all_flish
		                 mute_flag=0;
		 #endif
              #ifdef SUPPORT_FLASH_CHAR
 			    LED_FLASH_CHAR=0;
			    LED_FLASH_ICON=0;
              #endif
		   #if defined(SUPPORT_LED7_SHOW_V00_MUTE_STATE)
			    LED_FLASH_ICON=0;
		   	    LED_FLASH_CHAR=0;
			if(workmode==LINE_WORK_MODE)
       	            	 UI_menu(MENU_AUX_MAIN);
			else if(workmode==RADIO_WORK_MODE)
	                   	 UI_menu(MENU_FM_MAIN);
		  #endif
		  
		#if SUPPORT_ALL_VOICE		
		 #ifdef SUPPORT_MUTE_VOICE
                     os_taskq_post_msg(keymsg_task_name, 1, MSG_VOICE_MUTE_OFF);				
		#endif
		#endif
		 #ifdef support_sound_4052_control
		 #ifdef support_sound_4052_mute_state_control
		 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
		 	 if(compare_task_name("LineinTask"))
		 	 	{
		 	 	   if(bModeOfAuxContained==mode_dvd)
		 	 	   	{
		 	 			AC4052_IS_DVD();	
		 	 	   	}
		 		   else  if(bModeOfAuxContained==mode_ac3)
		 		   	{
				   		AC4052_IS_AC3();
		 		   	}
		 		   else  if(bModeOfAuxContained==mode_aux)
		 		   	{
		 	 			AC4052_IS_AUX();
		 		   	}
		 	 	}				 
		 #endif			 				 
		 #endif
		 #endif




		
		  
            }
            else
            {
            
		 #if defined(PA_ENABLE)
		                 pa_mute();
		 #endif
		                 dac_mute(1,1);
		 #ifdef support_mute_led_all_flish
		                 mute_flag=1;
		 #endif

		#if SUPPORT_ALL_VOICE		
		 #ifdef SUPPORT_MUTE_VOICE
                     os_taskq_post_msg(keymsg_task_name, 1, MSG_VOICE_MUTE);				
		#endif
		#endif
		 #ifdef support_sound_4052_control
	 		 #ifdef support_sound_4052_mute_state_control
	 		 	if(compare_task_name("LineinTask"))
	 		 	{
	 		 		AC4052_IS_MP3();					   
	 		 	}
	 		 #endif
		 #endif



		

            }
            break;

        case MSG_LOW_POWER:
            puts("**MSG_LOW_POWER,auto shutdown**\n");
            going_to_pwr_off = 0;
            soft_power_ctl(PWR_OFF);
            /* task_switch(IDLE_TASK_NAME,0,SWITCH_SPEC_TASK); */
            break;
#if 0

        case MSG_POWER_OFF:
            puts("\n*************power_off******************\n");
#if EARPHONE_MODE_EN
			if(power_on_cnt)
				break;
#endif
    		if(keymsg_task_name)
   			{
                /* os_taskq_post_msg(keymsg_task_name, 1, MSG_PROMPT_PLAY); */
    		}

            if(get_call_status() != BT_CALL_HANGUP)
            {
				going_to_pwr_off = 0xFF;
                user_send_cmd_prepare(USER_CTRL_HFP_CALL_HANGUP,0,NULL);
				break;
            }
			else
			{
				/* putchar('a'); */
				if(going_to_pwr_off != 0xFF)
					going_to_pwr_off = 1;
			}

			if(!low_power_flag)
			{
				R_LED_OFF();
				B_LED_OFF();
			}

            os_taskq_post(MAIN_TASK_NAME,1,MSG_POWER_OFF_KEY_MSG);
            break;
#endif

	case MSG_LOW_POWER_VOICE:
		send_key_voice(500);
		break;

		#if 0
        case MSG_POWER_OFF_HOLD:
            /* puts("MSG_POWER_OFF_HOLD\n"); */
//			if(!low_power_flag)
			{
//				R_LED_OFF();
//				B_LED_OFF();
			}
            break;
#endif
        case MSG_POWER_KEY_UP:
            if(going_to_pwr_off == 0xFF)
            {
                going_to_pwr_off = 0;
            }
            break;

        case MSG_POWER_OFF_KEY_MSG:
#if 0			
            puts("MSG_POWER_OFF_KEY_MSG\n");

            if(going_to_pwr_off == 0xFF)
            {
                going_to_pwr_off = 0;
                break;
            }

            if((BT_STATUS_CONNECTING == get_bt_connect_status())   ||
                    (BT_STATUS_TAKEING_PHONE == get_bt_connect_status())||
                    (BT_STATUS_PLAYING_MUSIC == get_bt_connect_status()))
            {
                /* puts("bt_disconnect\n"); */
                user_send_cmd_prepare(USER_CTRL_POWER_OFF,0,NULL);
            }

            user_ctrl_prompt_tone_play(BT_STATUS_POWER_OFF,NULL);
            do
            {
                os_time_dly(1);
            }
            while(play_sel_busy());

            set_sys_vol(0,0,FADE_ON);
            dac_off_control();

            ldo5v_detect_deal(2);
            if(going_to_pwr_off)
            {
                soft_power_ctl(PWR_OFF);
		  going_to_pwr_off = 0;
            }
#endif			
            break;

        case MSG_DAC_ON:
            puts("main_dac_on\n");
            dac_on_control();
            break;
        case MSG_DAC_OFF:
            puts("main_dac_off\n");
            dac_off_control();
			break;
#if 0
		case MSG_ENTER_SLEEP_MODE:
			puts("MSG_ENTER_SLEEP_MODE\n");
			enter_sleep_mode();
			break;
#endif
        case MSG_UPDATA:
            if(msg[1])
            {
                dev_updata_mode(NULL,BT_UPDATA);
            }
            else
            {
                dev_updata_mode(0,UART_UPDATA);
            }
            break;
        case MSG_0:
        case MSG_1:
        case MSG_2:
        case MSG_3:
        case MSG_4:
        case MSG_5:
        case MSG_6:
        case MSG_7:
        case MSG_8:
        case MSG_9:

            if(add_100_flag)
            {
                add_100_flag=0;
                input_number+=msg[0];

            }
            else
            {
                input_number = input_number * 10 + msg[0];
                input_number_cnt++;
            }
            if ((input_number > 9999) ||(input_number_cnt>4))
            {
                input_number = msg[0];
                input_number_cnt= 1;
            }
            printf("input_number = %u   \n",input_number);

#if UI_ENABLE
            UI_menu_arg(MENU_INPUT_NUMBER,input_number|(input_number_cnt<<24));
#endif

		#if   SUPPORT_ALL_VOICE
		  #if SUPPORT_VOICE_NUMBER
			bVoiceNumber=msg[0];
                     os_taskq_post_msg(keymsg_task_name, 1, MSG_VOICE_NUMBER);
		  #endif
		#endif

            break;

        case MSG_ADD_100:

#if UI_ENABLE


	 #ifdef SUPPORT_ADD10_KEY_DIRECT_PLAY


		music_p10 = (MUSIC_DIS_VAR*)UI_var.ui_buf_adr;

		input_number=music_p10->ui_curr_file+10;

		if (input_number > 9999)
			input_number=10;



		os_taskq_post_msg(keymsg_task_name, 1, MSG_INPUT_TIMEOUT);

	 #else
	            //	if (input_number > 999)
	            //	input_number = 0;
		 #ifdef support_100add_is_10add
		             if(add_100_flag)
		                 input_number+= 10;
		             else
		                 input_number= 10;
		             add_100_flag=1;
		 #elif defined( support_add100_ad10_dls_mode)
		             input_number+= 100;
		             add_100_flag=1;
		 #else
		             //  if(add_100_flag)
		             input_number+= 100;
		             // else
		             //	input_number= 100;
		             add_100_flag=1;

		 #endif

	            if (input_number > 9999)
	                input_number=100;
	            //printf("input_number = %u   \n",input_number);
	            UI_menu_arg(MENU_INPUT_NUMBER,input_number);
	#endif

#endif
            break;
#if LCD_SUPPORT_MENU
        case MSG_ENTER_MENUMAIN:
            UI_menu_arg(MENU_LIST_DISPLAY,UI_MENU_LIST_MAIN);
            break;
#endif
        case SYS_EVENT_SYS_TIMER_DELAY:
            break;
        /**************************************mzuhe  add  *************************/


        case MSG_POWER_OFF:

#if EARPHONE_MODE_EN
	if(power_on_cnt)
		break;
#endif

#ifdef support_power_off_voice
            workmode =POWER_OFF_WORK_MODE;
            task_switch("IdleTask", 0,SWITCH_SPEC_TASK);
#else    // defined(support_low_power_mode)


            puts("\n*************power_off******************\n");

            if(keymsg_task_name)
            {
                /* os_taskq_post_msg(keymsg_task_name, 1, MSG_PROMPT_PLAY); */
            }

            dac_off_control();
            going_to_pwr_off = 1;
//            os_taskq_post(MAIN_TASK_NAME,1,MSG_POWER_OFF_HOLD);
#endif

            break;




#ifdef PHONE_CHECK_ENABLE
#ifdef SUPPORT_PHONE_OUT_UMUTE_AMP
        case   SYS_EVENT_PHONE_OUT:
		if (pa_auto_mute_state())
			pa_umute();
		else
           		 pa_mute();

            break;
        case   SYS_EVENT_PHONE_IN:
            pa_umute();
  //          pa_mute();
            break;
#else
        case   SYS_EVENT_PHONE_OUT:
            pa_umute();
            break;
        case   SYS_EVENT_PHONE_IN:
            pa_mute();
            break;
#endif
#endif
//--------------------------------------------------------------------------------------------------
//				CUSTOMER   ADD
//--------------------------------------------------------------------------------------------------

#ifdef support_msg_light_key

        case MSG_LIGHT_KEY:
            light_mode_mark++;
            if(light_mode_mark>Light_max_mode)
                light_mode_mark=0;
#ifdef  support_led_eq_is_K1_mode
     to_mcu_data_on=1;
#endif
#ifdef support_led_LIGHT_MODE
            set_led_light_io_is_out();
            if( light_mode_mark)
                Set_led_light_io_is_on();
            else
                set_led_light_io_off();
#endif

#if KEY_TONE_EN && defined(support_light_key_tone)
            send_key_voice(200);
#endif
            break;

#endif


//-----------STANDBY BY------

#ifdef support_stanby_mod

        case MSG_STANBY_KEY:

	 #if defined support_sw_chack
		 SW_IO_IS_IN();

	 	if((workmode ==STANBY_WORK_MODE )&&((bLowPowerFlag)||(!( SW_IN_CHECK()))))
	 		break;

		
		if(workmode !=STANBY_WORK_MODE )
		{
		    	workmode =STANBY_WORK_MODE;
                	task_switch("IdleTask", 0,SWITCH_SPEC_TASK);
		 }
		else
			{			
			    workmode =0;
				 #if defined support_sw_chack
				 	if(bPowerSwFlag==2)
				 		{

					 		bPowerSwFlag=0;
					 		task_switch("MusicTask", 0,SWITCH_SPEC_TASK);
				 		}
				 	else
				 #endif
			    task_switch(0,0,SWITCH_LAST_TASK);

		     }


		
	#else
            if(workmode !=STANBY_WORK_MODE )
            {

                workmode =STANBY_WORK_MODE;
		 #if defined(support_stanby_led)
		 	stanby_led_ON();
		 #endif
                {
                    workmode =STANBY_WORK_MODE;
                    task_switch("IdleTask", 0,SWITCH_SPEC_TASK);

                }
            }
            else
            {
			 #if defined(support_stanby_led)
			 	//stanby_led_io_is_out();
			 	stanby_led_OFF();
			 	//	stanby_led_ON();
			 #endif
			 #ifdef support_msg_light_key   //∆µ∆◊…¡µ∆ƒ£ Ω
				 #ifdef support_default_light_on   //ƒ¨»œø™ª˙µ∆ƒ£ Ω1
				                 light_mode_mark=1;
				 #endif
				 #ifdef support_stanby_no_off_light

				 #else
			 		 #ifdef support_led_LIGHT_MODE   // ÷µÁÕ≤
			 	                 set_led_light_io_is_out();
			 	                 if( light_mode_mark)
			 	                 {
			 	                     Set_led_light_io_is_on();
			 	                 }
			 	                 else
			 	                 {
			 	                     set_led_light_io_off();
			 	                 }
			 		 #endif
				 #endif

			 #endif

	                workmode =0;

			 
			 #ifdef support_stanby_mod
			#ifndef SUPPORT_NO_SHOW_LOAD    		 
			     {
			         SET_UI_MAIN(MENU_WAIT);
			         UI_menu(MENU_WAIT);
			     }
			 #endif
			 #endif

		 #if defined SUPPORT_POWER_ON_IN_IDLE_MODE
		 	if(bPowerOnIdleFlag)
		 	{
		 		bPowerOnIdleFlag=0;
		 
		 		if(!file_operate_get_total_phydev())
		 	            {
		 	            #ifdef power_on_no_usb_sd_to_bt
		 	                os_taskq_post("MainTask", 2, SYS_EVENT_TASK_RUN_REQ, "BtStackTask");
		 			#else
		 	                os_taskq_post("MainTask", 2, SYS_EVENT_TASK_RUN_REQ, "LineinTask");
		 			#endif
		 	            }
		 	            else
		 	            {
		 	                os_taskq_post("MainTask", 2, SYS_EVENT_TASK_RUN_REQ, "MusicTask");
		 	            }
		 		break;				
		 	}
		 #endif

			 #ifdef support_stanby_up_run_vol

			 #elif defined( support_stanby_up_to_line)
			     task_switch(LINEIN_TASK_NAME, 0,SWITCH_SPEC_TASK);
			 #else
			     task_switch(0,0,SWITCH_LAST_TASK);
			     // task_switch("MusicTask", 0,SWITCH_SPEC_TASK);
			 #endif

            }


	 #endif








            break;
#endif

//--------SINGLE MODE  ---------------

#if REC_EN
	case MSG_CHANGE_REC_MODE:

              task_switch("RECTask",0,SWITCH_SPEC_TASK);
		break;
#endif


#ifdef support_music_key_mode
        case MSG_MUSIC_MODE_KEY:

		 #ifdef support_io_switch_bt_mp3

		     if(file_operate_get_total_phydev())
		         task_switch("MusicTask", 0,SWITCH_SPEC_TASK);
		     else
		         task_switch("FMRadioTask", 0,SWITCH_SPEC_TASK);

		 #else
	             if(workmode ==MUSIC_WORK_MODE)
	                 break;
	 		 #ifdef 	support_dls_rec_usb_sd_out_to_mp3

	 		             if(file_operate_get_total_phydev())
	 		                 task_switch("MusicTask", 0,SWITCH_SPEC_TASK);
	 		             else
	 		             {
	 		                 workmode=NOP_WORK_MODE;
	 		                 task_switch("IdleTask", 0,SWITCH_SPEC_TASK);
	 		             }
	 		 #else
	 		 #if defined(support_ksw_nop_mode) ||defined(support_user_nop_mode)           //”–ø’ƒ£ ΩŒﬁUSB SD “≤“™«Ûƒ‹◊™»Î
	 		             if(file_operate_get_total_phydev())
	 		                 task_switch("MusicTask", 0,SWITCH_SPEC_TASK);
	 		             else
	 		             {
	 		                 workmode=NOP_WORK_MODE;
	 		                 task_switch("IdleTask", 0,SWITCH_SPEC_TASK);
	 		             }
	 		 #else
	 		             if(file_operate_get_total_phydev())
	 		                 task_switch("MusicTask", 0,SWITCH_SPEC_TASK);

	 		 #endif
	 		 #endif
		 #endif
         break;

#endif

#ifdef  support_fm_key_mode
        case MSG_FM_MODE_KEY:
            if(workmode !=RADIO_WORK_MODE)
                task_switch(FM_TASK_NAME,0,SWITCH_SPEC_TASK);
            break;
#endif

#if defined( support_bt_key_mode) ||defined(usb_sd_out_to_bt_mode)
        case MSG_BT_MODE_KEY:
            if(workmode !=BT_WORK_MODE)
                task_switch("BtStackTask", 0,SWITCH_SPEC_TASK);
            break;
#endif

#if  defined( support_line_key_mode)||defined(usb_sd_out_to_line_mode)
        case MSG_LINE_MODE_KEY:
		 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE   
		 
		 	if(!compare_task_name(LINEIN_TASK_NAME))
				{
		 			bModeOfAuxContained=mode_aux;	 
		 			task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);
		 		}
			else
				{
		 			if(bModeOfAuxContained!=mode_aux)
						{
		 					bModeOfAuxContained=mode_aux; 	 
		 					os_taskq_post_msg(LINEIN_TASK_NAME, 1, MSG_AUX_INIT); //¬¥¬•¬∑¬¢AUX√Ñ¬£¬ø√©¬≥√µ√ä¬º¬ª¬Ø
		 				}
		 		}
		 #else

			 #if AUX_DETECT_EN &&defined(support_line_unline_to_next_mode)
			 	if(!aux_is_online())
			 		break;
			 #endif			
			 	if(workmode !=LINE_WORK_MODE)
			 		task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);

			
		 #endif


			

            break;
#endif


 #if  defined( support_dvd_key_mode)
 	case MSG_DVD_MODE_KEY:		
		  #ifdef support_sound_4052_control	
		  	AC4052_IS_DVD();				 
		  #endif	
 
 
		  #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE	
		  	if(!compare_task_name(LINEIN_TASK_NAME))
				{
		  			bModeOfAuxContained=mode_dvd;    
		  			task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);
		  		}
			else
				{
		  			if(bModeOfAuxContained!=mode_dvd)
						{
		  					bModeOfAuxContained=mode_dvd;	   
		  					os_taskq_post_msg(LINEIN_TASK_NAME, 1, MSG_AUX_INIT); //¬¥¬•¬∑¬¢AUX√Ñ¬£¬ø√©¬≥√µ√ä¬º¬ª¬Ø
		  				}
		  		}
		  #endif
 	break;
 #endif
#if  defined( support_cd_key_mode)
        case MSG_CD_MODE_KEY:		
	 	 #ifdef support_sound_4052_control	
		 #ifdef SUPPORT_CD_MODE_IN_LINEIN_MODE
	 			AC4052_IS_CD();		
	 	 #endif	
	 	 #endif	
				 	
		 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE	
		 	if(!compare_task_name(LINEIN_TASK_NAME))
				{
		 			bModeOfAuxContained=mode_cd;    
		 			task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);
		 		}
			else
				{
		 			if(bModeOfAuxContained!=mode_cd)
						{
		 					bModeOfAuxContained=mode_cd;	   
		 					os_taskq_post_msg(LINEIN_TASK_NAME, 1, MSG_AUX_INIT); //¬¥¬•¬∑¬¢AUX√Ñ¬£¬ø√©¬≥√µ√ä¬º¬ª¬Ø
		 				}
		 		}
		 #endif
            break;
#endif




#ifdef support_ac3_key_mode
	case MSG_AC3_MODE_KEY:
		 #ifdef support_sound_4052_control	
		 	AC4052_IS_AC3();			 
		 #endif	

		 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE   
		 	if(!compare_task_name(LINEIN_TASK_NAME))
				{
		 			bModeOfAuxContained=mode_ac3;    
		 			task_switch(LINEIN_TASK_NAME,0,SWITCH_SPEC_TASK);
		 		}
			else
				{
		 			if(bModeOfAuxContained!=mode_ac3)
						{
		 					bModeOfAuxContained=mode_ac3;	   
		 					os_taskq_post_msg(LINEIN_TASK_NAME, 1, MSG_AUX_INIT); //¬¥¬•¬∑¬¢AUX√Ñ¬£¬ø√©¬≥√µ√ä¬º¬ª¬Ø
		 				}
		 		}
		 #endif
	break;
#endif
 











#ifdef support_usb_sd_key
        case  MSG_MUSIC_USB:
            usb_sd_key_flag=1;
            if(workmode ==MUSIC_WORK_MODE)
                os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_U_SD);
            else
                task_switch("MusicTask", 0,SWITCH_SPEC_TASK);
            break;
        case MSG_MUSIC_SD:
            usb_sd_key_flag=2;

            if(workmode ==MUSIC_WORK_MODE)
                os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_U_SD);
            else
                task_switch("MusicTask", 0,SWITCH_SPEC_TASK);
            break;
#endif

//--------MIC  ONOFF    ---------------

#if MIC_CHECK_ENABLE
	 #if  MIC_ONOFF_KEY
                 case MSG_MIC_ONOFF:
 			if(mic_sw)
 			{
 				mic_sw=0;
				 #ifdef SUPPORT_MIC_ONOFF_SHOW
					bLedShowOnoffTimer=5;
				 #endif


 				 #ifdef support_music_pp_state

 				  if(workmode==LINE_WORK_MODE)
 				       led_fre_set(0,0);
 				 else  if(workmode==MUSIC_WORK_MODE)
 				  	{
 					  	  led_fre_set(15,0);
 				  	}
 				 #endif
 			}
 			else
 			{
				 #ifdef SUPPORT_MIC_ONOFF_SHOW
					bLedShowOnoffTimer=5;
				 #endif

 		//		led_fre_set(7,0);
 			//	os_time_dly(5);
 				mic_sw=1;
 			}

	 		 #ifdef SUPPORT_MIC_ONOFF_VOICE
	                   os_taskq_post_msg(keymsg_task_name, 1, MSG_VOICE_MIC);
	 		 #endif


	 		vm_write_api(VM_MIC_ONOFF,&mic_sw);


			 
 		   break;
	 #endif
#endif

//--------PT2313   ----------------------

	 #ifdef SUPPORT_MAIN_VOL_KEY
	 	 #if SUPPORT_MAIN_VOL_ALL_KEY
	 	 	case MSG_MAIN_VOL_UP:
				if(menumode==MENU_MAIN_VOL_MODE)
					{
					//	menumode=MENU_MAIN_VOL_MODE;
						os_taskq_post_msg("MainTask", 1, MSG_VOL_UP);
					//	PT2313SetData(msg[0]-MSG_MAIN_VOL_UP+1 ,1);
					}
				else if(menumode==MENU_BASS_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_BASS_UP);
					}
				else if(menumode==MENU_TREBLE_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_TREBLE_UP);
					}
				else if(menumode==MENU_ECHO_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_ECHO_UP);
					}
				else if(menumode==MENU_OK_VOL_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_MIC_UP);
					}
				else if(menumode==MENU_SWVOLL_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_SWVOL_UP);
					}

				 #if UI_ENABLE
				 	UI_menu(MENU_VOL_MENU);
				 #endif


		 	break;

	 	 	case MSG_MAIN_VOL_DN:
				if(menumode==MENU_MAIN_VOL_MODE)
					{
					//	menumode=MENU_MAIN_VOL_MODE;
						os_taskq_post_msg("MainTask", 1, MSG_VOL_DOWN);
					printf("MENU_MAIN_VOL_MODE====%d\n",MENU_MAIN_VOL_MODE);
					}
				else if(menumode==MENU_BASS_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_BASS_DN);
						printf("MENU_BASS_MODE====%d\n",MENU_BASS_MODE);

					}
				else if(menumode==MENU_TREBLE_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_TREBLE_DN);
						printf("MENU_TREBLE_MODE====%d\n",MENU_TREBLE_MODE);
					}
				else if(menumode==MENU_ECHO_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_ECHO_DN);

						printf("MENU_ECHO_MODE====%d\n",MENU_ECHO_MODE);
					}
				else if(menumode==MENU_OK_VOL_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_MIC_DN);

						printf("MENU_OK_VOL_MODE====%d\n",MENU_OK_VOL_MODE);
					}
				else if(menumode==MENU_SWVOLL_MODE)
					{
						os_taskq_post_msg("MainTask", 1, MSG_SWVOL_DN);
						printf("MENU_SWVOLL_MODE====%d\n",MENU_SWVOLL_MODE);
					}


				 #if UI_ENABLE
				 	UI_menu(MENU_VOL_MENU);
				 #endif



		 	break;

	 	 #else
	 	 	case MSG_MAIN_VOL_UP:
	 	 	case MSG_MAIN_VOL_DN:
	 	 		menumode=MENU_MAIN_VOL_MODE;
	 		 #ifdef supper_user_pt2313_ctrl_main_vol
	 		 	// PT_VOL_NOMAL	  0x00	   PT_VOL_UP  0x01		 PT_VOL_DN		  0x02
	 		 	PT2313SetData(msg[0]-MSG_MAIN_VOL_UP+1 ,1);
	 		 #endif
	 		 #ifdef SWOL_ACTION_WITH_MAIN_VOL_ADJUST
	 		 	PT2313SetData(msg[0]-MSG_MAIN_VOL_UP+0x04 ,2);
	 		 #endif
	 		 #if UI_ENABLE
	 		 	UI_menu(MENU_VOL_MENU);
	 		 #endif
	 	 	break;
	 	 #endif
	#endif

	 #ifdef SUPPORT_MSG_FRONT_LEFT
	 	case MSG_FRONT_LEFT_UP:
	 	case MSG_FRONT_LEFT_DN:
		 	menumode=MENU_FRONT_LEFT_MODE;
		 	PT2313SetData(msg[0]-MSG_FRONT_LEFT_UP+0x0A ,1);
		 #if UI_ENABLE
		 	UI_menu(MENU_VOL_MENU);
		 #endif
	 	break;
	 #endif

	 #ifdef SUPPORT_MSG_FRONT_RIGHT
	 	case MSG_FRONT_RIGHT_UP:
	 	case MSG_FRONT_RIGHT_DN:
		 	menumode=MENU_FRONT_RIGHT_MODE;
		 	PT2313SetData(msg[0]-MSG_FRONT_RIGHT_UP+0x0D ,1);
		 #if UI_ENABLE
		 	UI_menu(MENU_VOL_MENU);
	 	#endif
	 	break;
	 #endif

	 #ifdef	Support_MSG_BASS
	 	case MSG_BASS_UP:
	 	case MSG_BASS_DN:
		 	menumode=MENU_BASS_MODE;
		 	// PT_BASS_NOMAL  0x0F	  PT_BASS_UP	   0x10    PT_BASS_DN	   0x11
		 	PT2313SetData(msg[0]-MSG_BASS_UP+0x10 ,1);
		 #if UI_ENABLE
		 	UI_menu(MENU_VOL_MENU);
		 #endif
	 	break;
	 #endif

	 #ifdef  Support_MSG_TREBLE
	 	case MSG_TREBLE_UP:
	 	case MSG_TREBLE_DN:
		 	menumode= MENU_TREBLE_MODE;
		 	// PT_TREB_NOMAL	0x12	PT_TREB_UP		0x13   PT_TREB_DN		0x14
		 	PT2313SetData(msg[0]-MSG_TREBLE_UP+0x13 ,1);
		 #if UI_ENABLE
		 	UI_menu(MENU_VOL_MENU);
		 #endif
	 	break;
	 #endif

	 #ifdef Support_MSG_SWVOL
	 	case MSG_SWVOL_UP:
	 	case MSG_SWVOL_DN:
		 	menumode= MENU_SWVOLL_MODE;
		 	// PT_RL_NOMAL	0x03	  PT_RL_UP		 0x04		PT_RL_DN	   0x05
		 	// PT_FL_NOMAL	0x09	  PT_FL_UP		 0x0A		PT_FL_DN	   0x0B
		 	/*¬æ√õ¬≥¬ø √ä¬π√ì√É RR RL √ó√∂√ñ√ò¬µ√ç√í√¥
		 	¬π√∫√é¬¢911√ä¬π√ì√ÉFL FR√ó√∂√ñ√ò¬µ√ç√í√¥*/
		 #ifdef pt2313_use_rf_lf_as_sub	// 0x0a
		 	PT2313SetData(msg[0]-MSG_SWVOL_UP+0x0A ,2); // 2 √ê√®√ì√É√ç¬¨√ä¬±¬µ√∑ RR RL
		 #else
		 	PT2313SetData(msg[0]-MSG_SWVOL_UP+0x04 ,2); // 2 √ê√®√ì√É√ç¬¨√ä¬±¬µ√∑ RR RL
		 #endif
		 #if UI_ENABLE
		 	UI_menu(MENU_VOL_MENU);
		 #endif
	 	break;
	 #endif

	 #ifdef support_menu_mode
	 	case MSG_MENU_MODE:
		 	menumode++;
		 #ifdef ENCODER1_ADJUST_MIC_VOL
		 	if(menumode==MENU_OK_VOL_MODE)menumode=MENU_ECHO_MODE;
		 #endif
		 	if(menumode>=MENU_MAX_MODE)
		 	{
		 #ifdef MENU_NOT_SWTICH_MAIN_VOL
		 	menumode=1;
		 #else
		 	menumode=0;
		 #endif
		 	}
		 #if UI_ENABLE
		 	UI_menu(MENU_VOL_MENU);
		 #endif
	 	break;
	 #endif



	 #ifdef Support_MSG_RESET
	 	case MSG_RESET_KEY:
		 #ifdef	SUPPORT_PT2313
		 	PT2313_reset();
		 #endif
		 	menumode=MENU_MAIN_VOL_MODE;
		 #if UI_ENABLE
		 	UI_menu(MENU_RESET);
		 #endif
	 	break;
	 #endif


//--------  M62429  -----------------------

#if defined(SUPPORT_M62429)

	 case MSG_MIC_UP:
	 	 #ifdef support_use_pin1pin2_as_mic_vol
	 	 	M62429MenuPro(4);	//	4 -> ok vol ++	  1-> ehco ++
	 	 #else
	 	 	M62429MenuPro(1);	//	4 -> ok vol ++	  1-> ehco ++
	 	 #endif
	 	   #ifdef support_menu_mode
	 		menumode=MENU_OK_VOL_MODE;
	 	   #endif
	 	 #if UI_ENABLE
	 	 	UI_menu(MENU_VOL_MENU);
	 	 #endif
	 break;

	 case MSG_ECHO_UP:
		 #ifdef support_use_pin1pin2_as_mic_vol
			 M62429MenuPro(1);
		 #else
			 M62429MenuPro(4);	//	4 -> ok vol ++	  1-> ehco ++
		 #endif
		 menumode=MENU_ECHO_MODE;

		 #ifdef SUPPORT_MIC_ECHO_VM
			 vm_write_api(VM_MIC_ECHO,&M62429Data[1]);
		 #endif

		 #if UI_ENABLE
			 UI_menu(MENU_VOL_MENU);
		 #endif
	 break;

	 case MSG_MIC_DN:
		 #ifdef support_use_pin1pin2_as_mic_vol
			 M62429MenuPro(5);
		 #else
			 M62429MenuPro(2);	//	5 -> ok vol --	  2-> ehco --
		 #endif
		 menumode=MENU_OK_VOL_MODE;
		 #if UI_ENABLE
			 UI_menu(MENU_VOL_MENU);
		 #endif
	 break;

	 case MSG_ECHO_DN:
		 #ifdef support_use_pin1pin2_as_mic_vol
			 M62429MenuPro(2);
		 #else
			 M62429MenuPro(5);	//	5 -> ok vol --	  2-> ehco --
		 #endif
		 menumode=MENU_ECHO_MODE;
		 #ifdef SUPPORT_MIC_ECHO_VM
			 vm_write_api(VM_MIC_ECHO,&M62429Data[1]);
		 #endif

		 #if UI_ENABLE
			 UI_menu(MENU_VOL_MENU);
		 #endif
	 break;
#endif

#ifdef SUPPORT_REC_ONE_KEY_PLAY

	case MSG_COM_REC_REPLAY:

		  if(compare_task_name(FM_TASK_NAME)||compare_task_name(LINEIN_TASK_NAME)||compare_task_name("BtStackTask")||compare_task_name("RECTask"))
		  {
			if((g_rec_ctl)&&(ENC_STOP != g_rec_ctl->enable))
			{	//recording,stop first
			      if(compare_task_name(FM_TASK_NAME))
	                  os_taskq_post(FM_TASK_NAME, 1, MSG_REC_STOP);

				      else if(compare_task_name(LINEIN_TASK_NAME))
	                  os_taskq_post(LINEIN_TASK_NAME, 1, MSG_REC_STOP);

				      else if(compare_task_name("BtStackTask"))
	                  os_taskq_post("BtStackTask", 1, MSG_REC_STOP);

				      else if(compare_task_name("RECTask"))
	                  os_taskq_post("RECTask", 1, MSG_REC_STOP);
	                  os_time_dly(100);
		   	 }

	           if(file_operate_get_total_phydev())
			{
	      		   play_rec_last_file=1;
	                  os_taskq_post("MainTask", 1, MSG_MUSIC_MODE_KEY);
	                }
		  }

	break;
#endif

#if defined SUPPORT_DOUBLE_MODE_VOICE

	case MSG_MODE_VOICE_SEL:

	if(bModeVoiceSelFlag==0)
	{
		bModeVoiceSelFlag=1;

            UI_menu(MENU_VOICE_CH);
	}
	else
	{
		bModeVoiceSelFlag=0;
		UI_menu(MENU_VOICE_EN);
	}

	// vm_write_api(VM_MODE_VOICE_ONOFF,&bModeVoiceOnoffFlag);

#endif

#if defined SUPPORT_MODE_VOICE_ONOFF

	case MSG_MODE_VOICE_ONOFF:

	if(bModeVoiceOnoffFlag==0)
	{
		bModeVoiceOnoffFlag=1;

            UI_menu(MENU_ON);
	}
	else
	{
		bModeVoiceOnoffFlag=0;
		UI_menu(MENU_OFF);
	}

	 vm_write_api(VM_MODE_VOICE_ONOFF,&bModeVoiceOnoffFlag);
		break;
#endif

#ifdef SUPPORT_MODE_VOICE_EN_CH_ONOFF

	case MSG_VOICE_ON:
		
		if(bModeVoiceSelVal==0)
		{
			bModeVoiceSelVal = bStoreModeVoiceSelVal;
			 #ifdef LED_SHOW_ONOFF
			 	UI_menu(MENU_ON); 
			 #endif			 									
			vm_write_api(VM_VOICE_ONOFF,&bModeVoiceSelVal);
		}			 
	break;
	
	case MSG_VOICE_OFF:

		if(bModeVoiceSelVal>0)
		{
			bStoreModeVoiceSelVal=bModeVoiceSelVal;
			bModeVoiceSelVal = 0;
			 #ifdef LED_SHOW_ONOFF
			 	UI_menu(MENU_OFF); 
			 #endif	
			vm_write_api(VM_VOICE_ONOFF,&bModeVoiceSelVal);
			vm_write_api(VM_MODE_VOICE_ONOFF,&bStoreModeVoiceSelVal);			 
		}

	break;
	
	case MSG_VOICE_EN_CH:

			if(bModeVoiceSelVal==0)
				break;

			if(bModeVoiceSelVal==1)
			{
				bModeVoiceSelVal=2;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_VOICE_EN); 
				 #endif			 			 						 
			}
			else
			{
				bModeVoiceSelVal = 1;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_VOICE_CH); 
				 #endif			 									
			}
 			bStoreModeVoiceSelVal=bModeVoiceSelVal;
			
	 		vm_write_api(VM_VOICE_ONOFF,&bModeVoiceSelVal);
			vm_write_api(VM_MODE_VOICE_ONOFF,&bStoreModeVoiceSelVal);			 
			
	break;
			 
#endif
#ifdef SUPPORT_SCG_VOICE
#ifdef SUPPORT_VOICE_ONOFF
	case MSG_VOICE_ONOFF:

			if(bVoiceOnoff==1)
			{
				bVoiceOnoff=0;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_OFF); 
				 #endif			 			 						 
			}
			else
			{
				bVoiceOnoff = 1;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_ON); 
				 #endif			 									
			}

			printf("bVoiceOnoff===========%d\n",bVoiceOnoff);
 			//bStoreModeVoiceSelVal=bModeVoiceSelVal;
			
	 		vm_write_api(VM_VOICE_ONOFF,&bVoiceOnoff);
		//	vm_write_api(VM_MODE_VOICE_ONOFF,&bStoreModeVoiceSelVal);			 
			
	break;


#endif
#endif




	 #ifdef SUPPORT_RGB_LED_MODE
	 
		case MSG_RGB_LED_MODE:
			bRgbMode++;
			if(bRgbMode>=RGB_MODE_MAX)
				bRgbMode=RGB_MODE_R;
			
			bRgbModeCnt=0;

		 	UI_menu(MENU_RGB_MODE); 

		break;
	
	 #endif


#ifdef support_enconder_onoff
	case MSG_SW_ENCODER:
		if(sw_encoder==1)
			{
				sw_encoder=0;
			}
		else 
			{
			  	sw_encoder=1;
			}


			 #ifdef LED_SHOW_ONOFF
			 	UI_menu(MENU_OFF); 
			 #endif	
		
		break;
		
#endif






//--------------------------------------------------------------------------------------------------
//				CUSTOMER   ADD
//--------------------------------------------------------------------------------------------------


            //case MSG_HALF_SECOND:
            // puts("half-sec \n");
            //break;
        }
    }
}

/*----------------------------------------------------------------------------*/
/**@brief  ¥¥Ω®main task
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
int main_task_init(void)
{
    u32 err;
    puts("create main task\n");
    err = os_task_create_ext(TaskMain,
                             (void*)0,
                             TaskMainPrio,
                             10
                             ,MAIN_TASK_NAME,
                             MAIN_TASK_STACK_SIZE
                            );

    if(OS_NO_ERR == err)
    {
  	 #ifdef SUPPORT_TM1628_KEY_READ
   	    key_msg_register(MAIN_TASK_NAME, main_led_table,main_ad_table, main_io_table, main_ir_table, NULL);
	 #else    
	       key_msg_register(MAIN_TASK_NAME, main_ad_table, main_io_table, main_ir_table, NULL);
	 #endif
    }
    else
    {
        printf("main task err = %08x \n",err);
    }

    return 0;
}
#ifdef power_on_wait_power_key_down
void main_powerup_wait(void)
{

    int msg[6];
//	int key_statu = 0xff;

#if defined(ENABLE_POWER_ON_KEY_WAIT) ||defined(support_light_key_ctrl_mos)
    u8 time_cnt0=0;
#endif

    puts("****powerup_wait********\n");


    while(1)
    {

        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);
        //   os_taskq_pend(0, 1, &key_statu);
        clear_wdt();


        //printf("main_msg %08x %08x \n",msg[0],msg[1]);
        switch(msg[0])
        {
        case MSG_POWER_OFF:
#ifdef support_io_power_on_off
            Set_power_on_off_io_is_out();
            Set_power_on_off_io_is_HIGH();
#endif
            //  	   soft_poweroff_cnt = 0;

            puts("****powerup_1********\n");
            return;

        case MSG_HALF_SECOND:
#if defined(ENABLE_POWER_ON_KEY_WAIT)&&defined(support_io_power_on_off)
            if(time_cnt0++>6)
            {
                Set_power_on_off_io_is_out();
                Set_power_on_off_io_is_HIGH();
                //	power_on_flag=1;
                puts("****powerup_3********\n");
                return;
            }
#elif   defined(ENABLE_POWER_ON_KEY_WAIT)
            if(time_cnt0++>6)
            {
                //	power_on_flag=1;
                return;
            }
#endif
            //	puts(" powerup_half\n ");
            break;
        }


    }

}
#endif






