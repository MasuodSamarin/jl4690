/*******************************************************************************************
 File Name: dac.c

 Version: 1.00

 Discription:


 Author:yulin deng

 Email :flowingfeeze@163.com

 Date:2014-01-13 17:00:21

 Copyright:(c)JIELI  2011  @ , All Rights Reserved.
 *******************************************************************************************/
#include "sdk_cfg.h"
#include "dac/dac_api.h"
#include "dac/eq_api.h"
#include "cbuf/circular_buf.h"
#include "vm/vm_api.h"
#include "key_drv/key_voice.h"
#include "rtos/os_api.h"
#include "aec/aec_api.h"
#include "echo/echo_api.h"
#include "common/app_cfg.h"
#include "dac/ladc.h"
#include "common/common.h"
#include "cpu/dac_param.h"
#include "dac/dac.h"
#include "dac/eq.h"
#include "timer.h"
#include "echo/echo_deal.h"
#include "play_sel/play_sel.h"
#include "linein/dev_linein.h"
#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif
#if LED_SHOW_VOL_MAX
extern u8 bVolMaxChangeToSmallVolMax;
#endif

#define DAC_SINE_DEBUG	0

u8 dac_read_en;
DAC_CTL dac_ctl;
#ifdef SUPPORT_BAT_DETECT
#ifdef AMP_MUTE_ENABLE 
extern  u8 bPowerOnAmpMuteTimer;
#endif
#endif

#ifdef support_power_on_dly
extern u8 bPowerOnMuteTimer; // jsuo 
#endif



/*----------------------------------------------------------------------------*/
/** @brief:数字音量表，必须通过注册函数注册到库内，
                而且长度必须是DIGITAL_VOL_MAX_L+1
    @param:
    @return:
    @author:Juntham
    @note:
*/
/*----------------------------------------------------------------------------*/

#if SUPPORT_MAX_VOL_VAL==27  //  600mv

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    7525,
    8000,
    8600,
    9292, //29
    9892,
    9992
};
#elif SUPPORT_MAX_VOL_VAL==26
const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    7525,
    7700,
    7900,
    8200, //29
    8400,
    8600
};

#elif SUPPORT_MAX_VOL_VAL==25

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3530,
    3898,
    4016,
    4413,
    4825,
    5200,
    5600,
    6292, //29
    6713,
    7013
};


#elif SYS_DEFAULT_VOL==32  //  850mv

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    8025,
    9592,
    11466,
    12000,
    13000,    
    15200, // 31
    16000,
    16384
};

#elif SYS_DEFAULT_VOL==29  //  850mv

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    8025,
    9592,
    11466,
    12000,
    13000,    
    15200, // 31
    15500,
    15900
};


#elif SUPPORT_MAX_VOL_VAL==29  //  850mv

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    8025,
    9592,
    11466,
    12800, //29
    13800,
    15200
};

#elif ((SUPPORT_MAX_VOL_VAL==28)||((SYS_VOL_MAX==30)&& (LED_SHOW_VOL_MAX==32)))

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    8025,
    9592,
    9962,
    10800, //29
    11466,
    16384
};
#elif SUPPORT_MAX_VOL_VAL==32

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    8025,
    9592,
    11466,
    15200, //29
    16800,
    17384
};

#else  // 1v

const u16 digital_vol_tab[DIGITAL_VOL_MAX_L+1]=
{
    0	,
    93	,
    111	,
    132	,
    158	,
    189	,
    226	,
    270	,
    323	,
    386	,  //9
    462	,
    552	,
    660	,
    789	,
    943	,
    1127,
    1347,
    1610,
    1925,
    2301,  //19
    2751,
    3288,
    3930,
    4698,
    5616,
    6713,
    8025,
    9592,
    11466,
    15200, //29
    16000,
    16384
};
#endif
u32 dac_output_counter()
{
    return 0;
}

void dac_set_remote_counter(u32 counter,u32 time)
{

}

void dac_int_enable(void)
{
    dac_read_en = 0;
    dac_ie_api(1);
    dac_mute(0,1);
}
void dac_int_disable(void)
{
    dac_mute(1,1);
    dac_ie_api(0);
}

void dac_sr_cb(u16 rate)
{
    //printf("dac_sr_cb,rate = %d\n",rate);
#if ECHO_EN
    set_reverb_sr(rate);
#endif
#if EQ_EN
    eq_samplerate_sw(rate);
#endif

#if KEY_TONE_EN
    set_key_voice_sr(rate);
#endif
}

void dac_power_on_time(u8 mode)
{
    if(mode == 2)
    {
        puts("dac_off_delay\n");
        os_time_dly(15);
        //delay(0xAFFF*70);//120ms

    }
    else if(mode == 1)
    {
        puts("dac_power_on quickly\n");
        //delay(0xAFFF*70);//120ms
        os_time_dly(15);
    }
    else
    {
        puts("dac_power_on slowly\n");
        delay(0xAFFF*300);//600ms
    }
}

const u8 sine_buf_32K[] =
{
    0x00, 0x00, 0x00, 0x00, 0xae, 0x11, 0xae, 0x11, 0xad, 0x22, 0xad, 0x22, 0x58, 0x32, 0x58, 0x32, 0x13,
    0x40, 0x13, 0x40, 0x58, 0x4b, 0x58, 0x4b, 0xb8, 0x53, 0xb8, 0x53, 0xe0, 0x58, 0xe0, 0x58, 0x9e, 0x5a,
    0x9e, 0x5a, 0xe0, 0x58, 0xe0, 0x58, 0xb8, 0x53, 0xb8, 0x53, 0x58, 0x4b, 0x58, 0x4b, 0x13, 0x40, 0x13,
    0x40, 0x58, 0x32, 0x58, 0x32, 0xad, 0x22, 0xad, 0x22, 0xae, 0x11, 0xae, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x52, 0xee, 0x52, 0xee, 0x53, 0xdd, 0x53, 0xdd, 0xa8, 0xcd, 0xa8, 0xcd, 0xed, 0xbf, 0xed, 0xbf, 0xa8,
    0xb4, 0xa8, 0xb4, 0x48, 0xac, 0x48, 0xac, 0x20, 0xa7, 0x20, 0xa7, 0x62, 0xa5, 0x62, 0xa5, 0x20, 0xa7,
    0x20, 0xa7, 0x48, 0xac, 0x48, 0xac, 0xa8, 0xb4, 0xa8, 0xb4, 0xed, 0xbf, 0xed, 0xbf, 0xa8, 0xcd, 0xa8,
    0xcd, 0x53, 0xdd, 0x53, 0xdd, 0x52, 0xee, 0x52, 0xee
};

int dac_cbuf_enough(void)
{
    if((get_dac_cbuf_len() >= OUTPUT_BUF_SIZE /2)
#if ECHO_EN
            ||(cbuf_get_data_len_echo()>= (cbuf_get_space_len_echo()/2))
#endif
      )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*-----------------------------------------------------------------*/
/**@brief  LINE IN ��������
 @param  p��
 @return ��
 @note   void dac_lr_change(void*buffer,u32 len)
 */
/*-----------------------------------------------------------------*/
#ifdef suppport_aux_singe_no_swap
void dac_lr_change(void*buffer,u32 len)
{
	u32 i=0;
	s16 *buff=buffer;
	s16 tmp1,tmp2;
	len>>=1;



	while(i<len)
		{
			tmp1=buff[i];
			tmp2=buff[i+1];
			buff[i]=tmp2;
			buff[i+1]=tmp1;
			i+=2;
		}
}
#endif



/*----------------------------------------------------------------------------*/
/** @brief:  DAC isr callback function
    @param:
    @return:
    @author:
    @note:
*/
/*----------------------------------------------------------------------------*/
static u32 read_buf[DAC_SAMPLE_POINT] AT(.dac_buf_sec);
void dac_isr_callback(void *dac_buf,u8 buf_flag)
{
#if DAC_SINE_DEBUG
    memcpy(dac_buf,sine_buf_32K,128);
    return;
#endif

    if(0 == dac_read_en)
    {
        if(dac_cbuf_enough() != 0)
        {
            memset(dac_buf,0x00,DAC_BUF_LEN);
#if KEY_TONE_EN
            add_key_voice((s16*)dac_buf,DAC_SAMPLE_POINT*2);
#endif
            dac_digit_energy_value(dac_buf, DAC_BUF_LEN);
            return;
        }
        dac_read_en = 1;
    }

    if(dac_read(read_buf,DAC_BUF_LEN) != DAC_BUF_LEN)
    {
        dac_read_en = 0;
    }
#if ECHO_EN
    cbuf_mixture_echo(read_buf,DAC_BUF_LEN);
#endif

#if KEY_TONE_EN
    add_key_voice((s16*)read_buf,DAC_SAMPLE_POINT*2);
#endif

    if(is_dac_mute())
    {
        memset(read_buf,0x00,DAC_BUF_LEN);
    }
#if DAC_SOUNDTRACK_COMPOUND
    else
    {
        dac_digital_lr2one(read_buf,DAC_BUF_LEN);
    }
#endif
#ifdef suppport_aux_singe_no_swap
	dac_lr_change(read_buf,DAC_BUF_LEN);
#endif

    dac_digit_energy_value(read_buf, DAC_BUF_LEN);
    digital_vol_ctrl(read_buf, DAC_BUF_LEN);

#if REC_BT_EN
    bt_rec_get_data(dac_buf,DAC_BUF_LEN);
#endif

    if(aec_interface.fill_dac_echo_buf)
    {
        aec_interface.fill_dac_echo_buf((s16*)read_buf,DAC_SAMPLE_POINT << 1);
    }

#if EQ_EN
    eq_run((short*)read_buf,(short*)dac_buf,DAC_SAMPLE_POINT);
#else
    memcpy(dac_buf,read_buf,DAC_BUF_LEN);
#endif

    dac_cbuf_write_detect();
}

/*----------------------------------------------------------------------------*/
/** @brief: Audio Moudule initial
    @param:
    @return:
    @author:Juntham
    @note:
*/
/*----------------------------------------------------------------------------*/
static u32 dac_buf[2][DAC_SAMPLE_POINT] AT(.dac_buf_sec);
void audio_buf_init(void)
{
    puts("audio buf init\n");
    dac_ctl.dma_buf_len = DAC_BUF_LEN;
    dac_ctl.cbuf_len = OUTPUT_BUF_SIZE;
    dac_ctl.dac_dma_buf = (u8*)dac_buf;
    //dac_ctl.dac_dma_buf = malloc(dac_ctl.dma_buf_len*2);
    //ASSERT(dac_ctl.dac_dma_buf);
    dac_ctl.dac_cbuf = malloc(dac_ctl.cbuf_len);
    ASSERT(dac_ctl.dac_cbuf);

    memset(dac_ctl.dac_dma_buf,0x00,sizeof(dac_buf));
    dac_buf_init(dac_ctl.dac_dma_buf,dac_ctl.dma_buf_len,dac_ctl.dac_cbuf,dac_ctl.cbuf_len);
}

void audio_init(void)
{
#if EQ_EN
    eq_init();
#endif

#if KEY_TONE_EN
    key_voice_init();
#endif

    dac_read_en = 0;

    reg_set_sr_fun(dac_sr_cb);
    reg_dac_power_on_time_fun(dac_power_on_time);
    //dac_vcm_rsel_set(0);

    memset(&dac_ctl,0x00,sizeof(DAC_CTL));
    set_max_dac_vol(ANALOG_VOL_MAX_L, ANALOG_VOL_MAX_R, DIGITAL_VOL_MAX_L,DIGITAL_VOL_MAX_R);
#if EARPHONE_MODE_EN
    set_max_sys_vol(EARPHONE_MAX_VOL_L, EARPHONE_MAX_VOL_R);
#else
    set_max_sys_vol(MAX_SYS_VOL_L, MAX_SYS_VOL_R);
#endif

    reg_digital_vol_tab((void *)digital_vol_tab);

    audio_buf_init();

#if VCOMO_EN
    dac_init_api(VCOMO_EN, LDO_SLECT, DAC_CHANNEL_SLECT,DAC_ISEL_THIRD);
#else
    dac_init_api(VCOMO_EN, LDO_SLECT, DAC_CHANNEL_SLECT,DAC_ISEL5U);
#endif
    dac_ctl.toggle = 1;

    timer_reg_isr_fun(timer0_hl,5,dac_check,NULL);

    dac_reg_isr_cb_api(3,dac_isr_callback);

    s32 ret;
    ret = timer_reg_isr_fun(timer0_hl,1,dac_fade,NULL);
    if(ret != TIMER_NO_ERR)
    {
        printf("reg dac_fade err = %x\n",ret);
    }
    //os_time_dly(20);



#if SYS_DEFAULT_VOL
    dac_ctl.sys_vol_l = SYS_DEFAULT_VOL;
    //printf("phone_vol:%d\n",dac_ctl.phone_vol);
#else

    ///read sys vol from vm
    vm_read_api(VM_SYS_VOL, &dac_ctl.sys_vol_l);
    vm_read_api(VM_PHONE_VOL,&dac_ctl.phone_vol);
    //printf("---------vm_vol:%d\n",dac_ctl.sys_vol_l);
    //printf("phone_vol:%d\n",dac_ctl.phone_vol);

	 #ifdef RESET_DEFAULT_VOL
	 
		 #ifdef LED_SHOW_VOL_MAX
		 
		     if(dac_ctl.sys_vol_l < 3)
		     {
		  	 #if LED_SHOW_VOL_MAX==60 && SYS_VOL_MAX==30
		          dac_ctl.sys_vol_l = 18;
		 	  bVolMaxChangeToSmallVolMax=dac_ctl.sys_vol_l*2;
		    	 #elif LED_SHOW_VOL_MAX==62 && SYS_VOL_MAX==30
		 	         dac_ctl.sys_vol_l = RESET_DEFAULT_VOL;
		 		  bVolMaxChangeToSmallVolMax=28;	 
			  
		    	 #elif LED_SHOW_VOL_MAX==32 && SYS_VOL_MAX==30
		 	         dac_ctl.sys_vol_l = RESET_DEFAULT_VOL-2;
		 		  bVolMaxChangeToSmallVolMax=RESET_DEFAULT_VOL;	
				  
		    	 #elif LED_SHOW_VOL_MAX==30 && SYS_VOL_MAX==26
				 
		 	         dac_ctl.sys_vol_l = SYS_VOL_MAX;
		 		  bVolMaxChangeToSmallVolMax=RESET_DEFAULT_VOL;	
				  
		 	  #else
		 	         dac_ctl.sys_vol_l = RESET_DEFAULT_VOL-2;
		 		  bVolMaxChangeToSmallVolMax=RESET_DEFAULT_VOL;	  
		 	 #endif		
		     }
		 	
		     if(dac_ctl.sys_vol_l > 30)
		     {
		     #ifdef SYS_VOL_MAX
		         dac_ctl.sys_vol_l = SYS_VOL_MAX;
			 #else
		         dac_ctl.sys_vol_l = 30;
			 #endif
		 	 #if LED_SHOW_VOL_MAX==60 && SYS_VOL_MAX==30
		 	  bVolMaxChangeToSmallVolMax=dac_ctl.sys_vol_l*2;
		    	 #elif LED_SHOW_VOL_MAX==62 && SYS_VOL_MAX==30
		 	  bVolMaxChangeToSmallVolMax=dac_ctl.sys_vol_l*2+2;			 
		    	 #elif LED_SHOW_VOL_MAX==32 && SYS_VOL_MAX==30
		 	  bVolMaxChangeToSmallVolMax=LED_SHOW_VOL_MAX;
		    	 #elif LED_SHOW_VOL_MAX==30 && SYS_VOL_MAX==26
		 	  bVolMaxChangeToSmallVolMax=RESET_DEFAULT_VOL;	
				 
		 	 #endif		
		     }
		 
		 #else
		 
		     if(dac_ctl.sys_vol_l < RESET_MIN_VOL)
		     {
		         dac_ctl.sys_vol_l = RESET_DEFAULT_VOL;
		     }
		     if(dac_ctl.sys_vol_l > MAX_SYS_VOL_L)
		     {
		         dac_ctl.sys_vol_l = RESET_DEFAULT_VOL;
		     }
		 
		 #endif
	 
	 
	 #else
	     if(dac_ctl.sys_vol_l < 10)
	     {
	         dac_ctl.sys_vol_l = 22;
	     }
	     if(dac_ctl.sys_vol_l > MAX_SYS_VOL_L)
	     {
	         dac_ctl.sys_vol_l = MAX_SYS_VOL_L;
	     }
	 #endif
	 
#endif

    dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;




    init_sys_vol(dac_ctl.sys_vol_l,dac_ctl.sys_vol_r);
    dac_set_samplerate(32000,1);
}

void dac_on_control()
{
    puts("***dac_on***");
    dac_ctl.toggle = 1;
    dac_on_api(VCOMO_EN, LDO_SLECT, DAC_CHANNEL_SLECT);
    set_sys_vol(dac_ctl.sys_vol_l,dac_ctl.sys_vol_r,FADE_ON);

}

void dac_off_control()
{
    puts("***dac_off***");
    if(play_sel_busy())
    {
        puts("--busy,return\n");
        //return;
    }
    //set_sys_vol(0,0,FADE_OFF);
    dac_off_api();
    dac_ctl.toggle = 0;
}

void dac_check()
{
    if(dac_ctl.sniff_check)
    {
        //printf("[%d %d]",key_voice_busy(),dac_ctl.keyvoice_check);
        if((key_voice_busy() == 0) && (dac_ctl.keyvoice_check))
        {
            puts("dac_check_end\n");
            dac_ctl.keyvoice_check = 0;
            dac_ctl.sniff_check = 0;
        }
    }
}

#ifdef PA_ENABLE

/*----------------------------------------------------------------------------*/
/**@brief  mute
   @param   void
   @return  void
   @author  minzong zhang
   @note    void pa_mute()
*/
/*----------------------------------------------------------------------------*/

void  pa_mute_io_set(void)
{
    set_mute_io_is_out();
}
void  pa_mute(void)
{

#ifdef support_phone_first_mic
    if(mic_is_online()&& !phone_is_online())
        return;
#else
	 #if  MIC_CHECK_ENABLE
	     if(mic_is_online())
	         return;
	 #endif
#endif

#ifdef SUPPORT_PHONE_OUT_UMUTE_AMP
    if(phone_is_online())
        return;
#endif

#ifdef SUPPORT_PT2313
	 PT2313Mute(TRUE);
#endif



#ifdef  mute_io_L_is_mute
    set_mute_io_low();
#ifdef support_xa9901_ab_d_mode
    set_amp_ab_low();
#endif
#else
    set_mute_io_high();
#endif




}
/*----------------------------------------------------------------------------*/
/**@brief  umute
   @param   void
   @return  void
   @author  minzong zhang
   @note    void pa_umute()
*/
/*----------------------------------------------------------------------------*/
#if SYS_LVD_EN
extern volatile u8 low_power_flag;
#if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5
extern bool bLowePoweStanbyFlag;
#endif
#endif

void pa_umute(void)
{

#ifdef support_power_on_dly
	if(bPowerOnMuteTimer>0)// jsuo 	
		return;
#endif


#ifdef SUPPORT_BAT_DETECT
#ifdef SUPPORT_POWER_ON_MUTE_AMP_DELAY
	if(bPowerOnAmpMuteTimer)	 
	 return;
#endif
#endif

#ifdef SUPPORT_LOW_POWER_AMP_MUTE_IS_HIGH

	if(low_power_flag)
		{ // low power  amp alway  is h
		        set_mute_io_high();	  				
			 return;
		}
#endif

#ifdef SUPPORT_STANDBY_MODE_AMP_MUTE
#if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5
#if defined(PA_ENABLE)
	if(bLowePoweStanbyFlag)
		return;
#endif
#endif
#endif

#ifdef PHONE_CHECK_ENABLE	     //߲⹦UMUTE
#ifndef SUPPORT_PHONE_OUT_UMUTE_AMP

#ifdef support_phone_only_aux_mode
    if(workmode ==LINE_WORK_MODE &&phone_is_online())
#elif defined(support_phone_only_tape_phono_mode)
    if((workmode ==TAPE_WORK_MODE|| workmode ==PHONO_WORK_MODE)&&phone_is_online())
#else
    if(phone_is_online())
#endif
        return;
#endif
#endif


#ifdef SUPPORT_PT2313
	  PT2313Mute(FALSE);
#endif


#ifdef  mute_io_L_is_mute
#ifdef support_md4132_amp
    set_mute_io_low();
    os_time_dly(1);
    set_mute_io_high();   // 1^
    delay(50);
    set_mute_io_low();
    delay(50);
    set_mute_io_high();   // 2^
    delay(50);
    set_mute_io_low();
    delay(50);
    set_mute_io_high();    // 3^
    delay(50);
    set_mute_io_low();
    delay(50);
    set_mute_io_high();     // 4^
    delay(50);
	
#elif defined(support_mix2051_amp)

    //	set_mute_io_low();
    //      os_time_dly(1);

    set_mute_io_high();   //
    os_time_dly(2);

    set_mute_io_low();
    delay(700);
    set_mute_io_high();   // 1^
    delay(700);

    set_mute_io_low();
    delay(700);
    set_mute_io_high();	 // 2^
    delay(700);

    set_mute_io_low();
    delay(700);
    set_mute_io_high();	// 3^
    delay(700);
    if( workmode ==RADIO_WORK_MODE)
    {
        set_mute_io_low();
        delay(700);
        set_mute_io_high();	  // 4^
        delay(700);
    }

#elif defined(support_NS4159_amp)
    set_mute_io_low();
    os_time_dly(1);
    set_mute_io_high();   // 1^
    delay(50);
    set_mute_io_low();
    delay(50);
    set_mute_io_high();   // 2^
#elif  defined(pa_mute_use_pin_PB10PB9)
    if( workmode ==RADIO_WORK_MODE)
    {
        set_mute_io_high_ab();
    }
    else
        set_mute_io_high();
#elif defined( support_xa9901_ab_d_mode)

    if( workmode ==RADIO_WORK_MODE)
        set_amp_ab_low();
    else
        set_amp_d_high();

    set_mute_io_high();
#else
    set_mute_io_high();
#endif
#else
    set_mute_io_low();
#endif



}

#endif





