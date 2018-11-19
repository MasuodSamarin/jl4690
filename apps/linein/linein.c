#include "common/app_cfg.h"
#include "rtos/os_api.h"
#include "rtos/os_cfg.h"
#include "common/error.h"
#include "common/msg.h"
#include "rtos/task_manage.h"
#include "linein_key.h"
#include "linein.h"
#include "dac/dac_api.h"
#include "play_sel/play_sel.h"
#include "key_drv/key.h"
#include "ui/led/led.h"
#include "dac/dac_api.h"
#include "dev_linein.h"
#include "ui/ui_api.h"
#include "dac/ladc.h"
#include "linein_prompt.h"
#include "linein_ui.h"
#include "echo/echo_api.h"
#include "echo/echo_deal.h"
#include "rcsp/rcsp_interface.h"
#include "record.h"
#include "encode/encode.h"
#include "key_drv/key_voice.h"
#include "dac/dac.h"
#include "dac/dac_api.h"
#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif
#include "led7_drv.h"
#include "vm/vm_api.h"

extern void *malloc_fun(void *ptr, u32 len, char *info);
extern void free_fun(void **ptr);

RECORD_OP_API * aux_rec = NULL;
REVERB_API_STRUCT *aux_reverb = NULL;

#ifdef support_line_pause_disp_pause
extern bool   aux_pause_mark;
#endif
#define get_mute_status   is_dac_mute

//#define AUX_AD_ENABLE
#if  SUPPORT_ALL_VOICE
extern u8 IsVoiceEnable;
extern u8 bVoiceNumber;
#endif


#ifdef SUPPORT_DOUBLE_LINEIN
#if  AUX_DETECT_EN
bool bAux2Flag;
#else
u8 bMultiExternInputSel=0;
#endif
#endif

#ifdef SUPPORT_MULTI_INPUT_MODE
u8 bMultiExternInputSel=0;
#endif
#ifdef support_mute_led_all_flish
extern bool  mute_flag;
#endif

#ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
extern u8 bModeOfAuxContained;
#endif

#ifdef SUPPORT_VOICE_ONOFF
bool bVoiceOnoff;
#endif



#if 1
#define  LDO_SELECT  LDO_1
void dac_mic_aux_open()
{
  dac_trim_en(1);
  dac_digital_en(0);
  dac_ldo_set(LDO_SELECT,0);
}

void dac_mic_aux_close()
{
  dac_trim_en(0);
  dac_digital_en(1);
  dac_ldo_set(LDO_SELECT,1);
}

#endif


/*----------------------------------------------------------------------------*/
/**@brief  AUX DAC通道选择，开启
 @param  无
 @return 无
 @note   void aux_dac_channel_on(void)
 */
/*----------------------------------------------------------------------------*/
void aux_dac_channel_on(void)
{
    if(LINEIN_CHANNEL == DAC_AMUX0)
    {
        JL_PORTA->DIR |=  (BIT(1)|BIT(2));
        JL_PORTA->DIE &= ~(BIT(1)|BIT(2));
    }
    else if(LINEIN_CHANNEL == DAC_AMUX1)
    {
        JL_PORTA->DIR |=  (BIT(4)|BIT(3));
        JL_PORTA->DIE &= ~(BIT(4)|BIT(3));
        JL_PORTA->PD  &= ~(BIT(3));//PA3 default pull_down
    }
    else if(LINEIN_CHANNEL == DAC_AMUX2)
    {
        JL_PORTB->DIR |=  (BIT(11)|BIT(12));
        JL_PORTB->DIE &= ~(BIT(11)|BIT(12));
    }
#ifdef line_user_PA3
    else if(LINEIN_CHANNEL == DAC_AMUX1_L_ONLY)
    {
        JL_PORTA->DIR |=  (BIT(3));
        JL_PORTA->DIE &= ~(BIT(3));
        JL_PORTA->PD  &= ~(BIT(3));//PA3 default pull_down
    }

#endif
#ifdef AUX_AD_ENABLE
    dac_channel_on(MUSIC_CHANNEL, FADE_ON);
    set_sys_vol(0,0,FADE_ON);
    dac_set_samplerate(48000,0);
    ladc_reg_init(ENC_LINE_LR_CHANNEL, LADC_SR48000);
    os_time_dly(35);
    set_sys_vol(dac_ctl.sys_vol_l,dac_ctl.sys_vol_r,FADE_ON);
#else
    dac_channel_on(LINEIN_CHANNEL, FADE_ON);


//aux 输出增益加大  224-->>576
#ifdef SUPPORT_AUX_OUT_GAIN_ADD
	JL_AUDIO->DAA_CON2 |= 0x40;
#endif

#ifdef LED_SHOW_SCREEN_FREQUENCE
#if defined line_user_dacr
    ladc_reg_init(ENC_DAC_LEFT_CHANNEL, LADC_SR48000);
#elif defined line_user_dacl
    ladc_reg_init(ENC_DAC_RIGHT_CHANNEL, LADC_SR48000);
#else
     ladc_reg_init(ENC_LINE_LR_CHANNEL, LADC_SR48000);
#endif
#endif

    os_time_dly(20);//wait amux channel capacitance charge ok

    os_time_dly(20);//wait amux channel capacitance charge ok

    
	 #ifdef LED_SHOW_VOL_MAX
	  	 #if defined AUX_VOL_MAX 
	  	 	if(dac_ctl.sys_vol_l>27)    
	  	 	dac_ctl.sys_vol_l=27;
	  	 	dac_ctl.sys_vol_r=dac_ctl.sys_vol_l;	  	
		#elif defined MP3_VOL_MAX
	  	 	dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
	  	 	dac_ctl.sys_vol_r=dac_ctl.sys_vol_l;	  		
	  	 #endif
	 #endif

	
    set_sys_vol(dac_ctl.sys_vol_l,dac_ctl.sys_vol_r,FADE_ON);
	 
#endif

#if ECHO_EN
    ///开启dac数字通道
    dac_trim_en(0);
    dac_digital_en(1);
#else
    ///关闭dac数字通道
    dac_trim_en(1);
    dac_digital_en(0);
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief  AUX DAC通道选择，关闭
 @param  无
 @return 无
 @note   void aux_dac_channel_off(void)
 */
/*----------------------------------------------------------------------------*/
void aux_dac_channel_off(void)
{
#ifdef AUX_AD_ENABLE
    dac_channel_off(MUSIC_CHANNEL,FADE_ON);
   // ladc_close(ENC_LINE_LR_CHANNEL);
#else
    dac_channel_off(LINEIN_CHANNEL, FADE_ON);
    dac_trim_en(0);
    dac_mute(0, 1);
#endif
}

#ifdef SUPPORT_DOUBLE_LINEIN

void aux2_dac_channel_on(void)
{

	aux_dac_channel_off();
    if(LINEIN_CHANNEL_2 == DAC_AMUX0)
    {
        JL_PORTA->DIR |=  (BIT(1)|BIT(2));
        JL_PORTA->DIE &= ~(BIT(1)|BIT(2));
    }
    else if(LINEIN_CHANNEL_2 == DAC_AMUX1)
    {
        JL_PORTA->DIR |=  (BIT(4)|BIT(3));
        JL_PORTA->DIE &= ~(BIT(4)|BIT(3));
        JL_PORTA->PD  &= ~(BIT(3));//PA3 default pull_down
    }
    else if(LINEIN_CHANNEL_2 == DAC_AMUX2)
    {
        JL_PORTB->DIR |=  (BIT(11)|BIT(12));
        JL_PORTB->DIE &= ~(BIT(11)|BIT(12));
    }


    dac_channel_on(LINEIN_CHANNEL_2, FADE_ON);

     ladc_reg_init(ENC_LINE_LR_CHANNEL, LADC_SR48000);

    os_time_dly(20);//wait amux channel capacitance charge ok
    set_sys_vol(dac_ctl.sys_vol_l,dac_ctl.sys_vol_r,FADE_ON);



#if ECHO_EN
    ///开启dac数字通道
    dac_trim_en(0);
    dac_digital_en(1);
#else
    ///关闭dac数字通道
    dac_trim_en(1);
    dac_digital_en(0);
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief  AUX DAC通道选择，关闭
 @param  无
 @return 无
 @note   void aux_dac_channel_off(void)
 */
/*----------------------------------------------------------------------------*/
void aux2_dac_channel_off(void)
{

    dac_channel_off(LINEIN_CHANNEL_2, FADE_ON);
    dac_trim_en(0);
    dac_mute(0, 1);

}
#endif

#ifdef SUPPORT_MULTI_INPUT_MODE
#ifdef SUPPOR_INPUT_AUX1
void aux1_dac_channel_on(void)
{

//	aux_dac_channel_off();
    dac_channel_off(LINEIN_CHANNEL, FADE_ON);
    os_time_dly(10);//wait amux channel capacitance charge ok
	
    if(LINEIN_CHANNEL_1 == DAC_AMUX0)
    {
        JL_PORTA->DIR |=  (BIT(1)|BIT(2));
        JL_PORTA->DIE &= ~(BIT(1)|BIT(2));
    }
    else if(LINEIN_CHANNEL_1 == DAC_AMUX1)
    {
        JL_PORTA->DIR |=  (BIT(4)|BIT(3));
        JL_PORTA->DIE &= ~(BIT(4)|BIT(3));
        JL_PORTA->PD  &= ~(BIT(3));//PA3 default pull_down
    }
    else if(LINEIN_CHANNEL_1 == DAC_AMUX2)
    {
        JL_PORTB->DIR |=  (BIT(11)|BIT(12));
        JL_PORTB->DIE &= ~(BIT(11)|BIT(12));
    }


    dac_channel_on(LINEIN_CHANNEL_1, FADE_ON);

     ladc_reg_init(ENC_LINE_LR_CHANNEL, LADC_SR48000);

    os_time_dly(20);//wait amux channel capacitance charge ok
    set_sys_vol(dac_ctl.sys_vol_l,dac_ctl.sys_vol_r,FADE_ON);



#if ECHO_EN
    ///开启dac数字通道
    dac_trim_en(0);
    dac_digital_en(1);
#else
    ///关闭dac数字通道
 //   dac_trim_en(1);
//    dac_digital_en(0);
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief  AUX DAC通道选择，关闭
 @param  无
 @return 无
 @note   void aux_dac_channel_off(void)
 */
/*----------------------------------------------------------------------------*/
void aux1_dac_channel_off(void)
{
    dac_channel_off(LINEIN_CHANNEL_1, FADE_ON);
    dac_trim_en(0);
    dac_mute(0, 1);
}
#endif
#endif

void aux_info_init(void)
{


#ifdef SUPPORT_AUX_MAX_VOL_DEC
	set_max_dac_vol(ANALOG_VOL_MAX_L-1, ANALOG_VOL_MAX_R-1, DIGITAL_VOL_MAX_L-1,DIGITAL_VOL_MAX_R-1);
#endif

#ifdef SUPPORT_MODE_MAX_VOL_SINGLE_ADJUST
	set_max_dac_vol(AUX_ANALOG_VOL_MAX_L, AUX_ANALOG_VOL_MAX_R, AUX_DIGITAL_VOL_MAX_L,AUX_DIGITAL_VOL_MAX_R);
#endif

 #ifdef SUPPORT_PT2313
 	Pt2313_ChangSource(Aud_SwAUX);
 #endif

 
#ifdef support_sound_4052_control

	AC4052_IS_AUX();
	 #if defined sound_4052_io_mode_6 ||defined sound_4052_io_mode_5||defined(sound_4052_io_mode_1)
	 	  	aux_dac_channel_on();
	 #endif

#elif defined support_off_aux_out
	  aux_dac_channel_off();
 #else
	   #ifndef LINE_IN_USE_PT2313
	  	aux_dac_channel_on();
	  #endif
#endif


#ifdef SUPPORT_DOUBLE_LINEIN
	 if(workmode==LINE_WORK_MODE_2)
	 	{
		    aux2_dac_channel_on();
	 	}
	else
#endif

#ifdef SUPPORT_MULTI_INPUT_MODE

        switch (bMultiExternInputSel)
        	{
			 case INPUT_AUX0_MODE:
	 		   aux_dac_channel_on();
			break;

	        	#ifdef SUPPOR_MP3_NOP_IN_AUX_MODE
			 case INPUT_NOP_MODE:
	 			aux_dac_channel_off();
			 	break;
	 		#endif

	        	#ifdef SUPPOR_INPUT_AUX1
			 case INPUT_AUX1_MODE:
			 	dac_mute(1,1);
				aux1_dac_channel_on();
			 	dac_mute(0,1);				
			 break;
	 		#endif

	        	#ifdef SUPPOR_INPUT_AUX2
			 case INPUT_AUX1_MODE:
			 	break;
	 		#endif

		}
#elif defined line_user_extern
 	   aux_dac_channel_off();
#else
 	   aux_dac_channel_on();
#endif
#if 0//def suppport_aux_singe_no_swap
	JL_AUDIO->DAA_CON2 |= (BIT(14)|BIT(15));//bypass控制正相反相 // BTI14左声道 bit15右声道
#endif


    //#if (AUX_REC_EN==0)
    //    ladc_reg_init(ENC_DAC_CHANNEL,LADC_SR16000);   //获取能量要初始化用于采数
    //#endif

    ui_open_aux(&aux_rec,sizeof(RECORD_OP_API **));
    /* ui_open_aux(0, 0); */
}





#ifdef SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
void mp3IdleMode_init(void)
{
  #ifdef support_sound_4052_control
    dac_channel_on(LINEIN_CHANNEL, FADE_ON);

  #else
    dac_channel_off(LINEIN_CHANNEL, FADE_ON);

  #endif



	
    SET_UI_MAIN(MENU_MP3_IDLE_MAIN);
    UI_menu(MENU_MP3_IDLE_MAIN);

#ifdef support_sound_4052_control
	AC4052_IS_MP3();
#endif


	
}
#endif


#ifdef SUPPORT_AC3_MODE_IN_LINEIN_MODE
void AC3_mode_init(void)
{
	 #ifdef support_send_ir_code // MP5 ON
	 	 	   IRSendInital(0x21);
				 os_time_dly(25);
	 #endif

#ifdef support_ac3_dac_channle_aux2
    //TRIM_EN(1);
    dac_mute(1,1);
    dac_channel_on(DAC_AMUX2, FADE_OFF);
    os_time_dly(15);  //这个参数会影响到上电第一次进入line in的冲击声。可以根据样机调整
    dac_mute(0,1);
#elif defined support_ac3_dac_channle_aux0
    //TRIM_EN(1);
    dac_mute(1,1);
    dac_channel_on(DAC_AMUX0, FADE_OFF);
    os_time_dly(15);  //这个参数会影响到上电第一次进入line in的冲击声。可以根据样机调整
    dac_mute(0,1);
#else

  #ifdef support_sound_4052_control
    dac_channel_on(LINEIN_CHANNEL, FADE_ON);

  #else
    dac_channel_on(LINEIN_CHANNEL, FADE_ON);

  #endif


#endif

#ifdef SUPPORT_PT2313
	 Pt2313_ChangSource(Aud_SwCD);
#endif

#ifdef support_sound_4052_control
	AC4052_IS_AC3(); 
#endif





   SET_UI_MAIN(MENU_AC3_MAIN);
   UI_menu(MENU_AC3_MAIN);
}
#endif


#ifdef SUPPORT_CD_MODE_IN_LINEIN_MODE
void cd_mode_init(void)
{
  #ifdef support_sound_4052_control
    dac_channel_on(LINEIN_CHANNEL, FADE_ON);

  #else
    dac_channel_off(LINEIN_CHANNEL, FADE_ON);

  #endif



  
#ifdef SUPPORT_PT2313
	 Pt2313_ChangSource(Aud_SwCD);
#endif
#ifdef support_sound_4052_control
	AC4052_IS_CD(); 
#endif

   SET_UI_MAIN(MENU_CD_MAIN);
   UI_menu(MENU_CD_MAIN);
}
#endif



#ifdef SUPPORT_DVD_MODE_IN_LINEIN_MODE
void dvd_mode_init(void)
{
  #ifdef support_sound_4052_control
    dac_channel_on(LINEIN_CHANNEL, FADE_ON);

  #else
    dac_channel_off(LINEIN_CHANNEL, FADE_ON);

  #endif

  
#ifdef SUPPORT_PT2313
	 Pt2313_ChangSource(Aud_SwVcd);
#endif

#ifdef support_sound_4052_control
	AC4052_IS_DVD();
#endif

   SET_UI_MAIN(MENU_DVD_MAIN);
   UI_menu(MENU_DVD_MAIN);
}
#endif





/*----------------------------------------------------------------------------*/
/**@brief  LINE IN 任务
 @param  p：任务间参数传递指针
 @return 无
 @note   static void linein_task(void *p)
 */
/*----------------------------------------------------------------------------*/
static void linein_task(void *p)
{
    int msg[6];
    aux_reverb = NULL;
    tbool psel_enable;

    aux_puts("\n************************LINEIN TASK********************\n");
#ifdef support_amP_ab_d
    Set_amp_ab_d_out() ;
    Set_AMP_IS_D();
#endif

#ifdef SUPPORT_MULTI_INPUT_MODE
#ifndef SUPPOR_NOP_AND_AUX_MODE
	bMultiExternInputSel=0;
#endif
#endif

#ifdef SUPPORT_DOUBLE_LINEIN
    if(workmode !=LINE_WORK_MODE_2 )
#endif
    workmode=LINE_WORK_MODE;
#ifdef SUPPORT_VM_WORK_MODE
	vm_write_api(VM_WORK_MODE,&workmode);
#endif

    malloc_stats();

    led_fre_set(0,0);


 #if defined SUPPORT_OFF_MODE_VOICE||defined SUPPORT_OFF_AUX_MODE_VOICE
 	os_taskq_post_msg(LINEIN_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);

 #elif  SUPPORT_ALL_VOICE
 
	#ifdef SUPPORT_SCG_VOICE
	 	 if(bVoiceOnoff==0)	 
	 	     {
	 		     psel_enable=0;
	 	     		os_taskq_post(LINEIN_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
	 	     }
	 	     else
	 	     	{
	 	 	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_MP3); //line in提示音播放
	 	     	}

	#else
	  	if(IsVoiceEnable==0)
	 	     {
	 		     psel_enable=0;
	 	     		os_taskq_post(LINEIN_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
	 	     }
	 	     else
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 		if(IsVoiceEnable==2)
	 		{
	 	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_EN_MP3); //line in提示音播放
	 		}
	 		else
	  	#endif
	 	     {
	 	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_MP3); //line in提示音播放
	 	     }

	#endif


#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	

 	if(bModeVoiceSelVal==0)
	     {
		     psel_enable=0;
	     		os_taskq_post(LINEIN_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
	     }
	     else
		if(bModeVoiceSelVal==2)
		{
	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_EN_MP3); //line in提示音播放
		}
		else
	     {
	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_MP3); //line in提示音播放
	     }
#elif defined SUPPORT_DOUBLE_MODE_VOICE

    if(bModeVoiceSelFlag)
	     {
	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_MP3); //line in提示音播放
	     }
	     else
	     {
	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_EN_MP3); //line in提示音播放
	     }


 #elif defined SUPPORT_MODE_VOICE_ONOFF

	if(bModeVoiceOnoffFlag)
	     {
	 	  psel_enable =  tone_play_by_name(LINEIN_TASK_NAME, 1,BPF_LINEIN_MP3); //line in提示音播放
	     }
	     else
	     {
	     	psel_enable=0;
     		os_taskq_post(LINEIN_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
	     }

 #else

 	psel_enable = tone_play_by_name(LINEIN_TASK_NAME,1, BPF_LINEIN_MP3); //line in提示音播放
 #endif

    while (1)
    {
        memset(msg, 0x00, sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);

 #if !defined SUPPORT_OFF_MODE_VOICE&&!defined SUPPORT_OFF_AUX_MODE_VOICE
        if(psel_enable)
        {
            switch(msg[0])
            {
            case SYS_EVENT_PLAY_SEL_END:
            case SYS_EVENT_DEL_TASK: 				//请求删除music任务
                puts("\n----play_sel_stop------\n");
                play_sel_stop();
                psel_enable = 0;
                break;
            default:
                msg[0] = NO_MSG;
                break;
            }
        }

#endif
	if(msg[0] != MSG_HALF_SECOND)
        {
 //           printf("\nlinein_msg= 0x%x\n",msg[0]);
        }

        clear_wdt();
        switch (msg[0])
        {
        case SYS_EVENT_DEL_TASK:
            if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
            {
                //				    UI_menu(MENU_WAIT);
                aux_puts("AUX_SYS_EVENT_DEL_TASK\n");
                ui_close_aux();

		 #ifdef support_line_pause_disp_pause
	                 aux_pause_mark=0;
		 #endif

                //                  exit_rec_api(&rec_linin_api); //停止录音和释放资源
                echo_exit_api((void **)&aux_reverb);
                exit_rec_api(&aux_rec); //停止录音和释放资源
                //				    disable_ladc(ENC_DAC_CHANNEL);
		 #ifdef SUPPORT_DOUBLE_LINEIN
			 if(workmode==LINE_WORK_MODE_2)
			     aux2_dac_channel_off();
			 else
		 #endif


             	   aux_dac_channel_off();

		 #ifdef SUPPORT_MULTI_INPUT_MODE
		 #ifdef SUPPOR_INPUT_AUX1
			 aux1_dac_channel_off();
		 #endif
		 #endif

 		  SFR(JL_AUDIO->DAA_CON2,2,2,0);		 
               os_task_del_res_name(OS_TASK_SELF);
            }
            break;

        case SYS_EVENT_PLAY_SEL_END: //提示音结束
            aux_puts("AUX_SYS_EVENT_PLAY_SEL_END\n");
            if(linein_prompt_break)
            {
                linein_prompt_break = 0;
                break;
            }
	    #if NOTICE_VOICE_VOL_DEFAULT
		    set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_ON);
	    #endif
		
	#if SUPPORT_ALL_VOICE		
	 #ifdef SUPPORT_MUTE_VOICE
	 #ifdef support_mute_led_all_flish
             if(mute_flag)
             	{
			 #if defined(PA_ENABLE)
			 	pa_mute();
			 #endif
			 	dac_mute(1,1);		 
		}
	 #endif				 	 		            
	 #endif				 	 		            
	 #endif				 	 		            
		
            aux_puts("AUX_play_tone_end\n");
        case MSG_AUX_INIT:
            aux_puts("MSG_AUX_INIT\n");
	 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
	 	switch(bModeOfAuxContained)
	 	{
	 	case mode_mp3_nodevice:
	 	 	 #ifdef SUPPORT_USE_ENCODE_AS_MODE_CHANGE	
	 	 	 	bMulitWorkmode=MUSIC_WORK_MODE;
	 	 	 #endif
	 
	 	 	 #ifdef SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
	 	 	 	mp3IdleMode_init();
	 	 	 #endif
	 	break;
	 
	 	case mode_aux:
	 
	 		workmode=LINE_WORK_MODE;				 	
	 		aux_info_init();
	 	break;
	 
	 	case mode_ac3:
		 	 #ifdef SUPPORT_USE_ENCODE_AS_MODE_CHANGE	
		 	 	bMulitWorkmode=AC3_WORK_MODE;
		 	 #endif
	 
		 	 #ifdef SUPPORT_AC3_MODE_IN_LINEIN_MODE
		 	 	AC3_mode_init();
		 	 #if 0//def support_send_ir_code // MP5 ON
	 		 	 #if 0//def support_send_ir_code
	 		 	 	send_timer=0;
	 		 	 	vol_key_sw=0;		
	 		 	 	send_timer=0;
	 		 	 	vol_key_sw=0;		
	 		 	 
	 		 	 #endif 			 
		 	 
		 	 	IRSendInital(MP5_PANEL_ON);
		 	 	os_time_dly(5);		
		 	 	IRSendInital(MP5_PANEL_ON);	
		 	 	os_time_dly(5);		
		 	 	IRSendInital(MP5_PANEL_ON);					
		 	 
		 	 #endif
		 	 
		 	 #if 0//def support_send_ir_code
		 	 	hw_IRsend_Pin_Init();
		 	 #endif
		 	 
		 	 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
		 	 	workmode=AC3_WORK_MODE;
		 	 #endif
		 	 
		 	 #endif
	 	break;
	 
	 	case mode_cd:
		 	 #ifdef SUPPORT_USE_ENCODE_AS_MODE_CHANGE	
		 	 	bMulitWorkmode=CD_WORK_MODE;
		 	 #endif
	 
		 	 #ifdef SUPPORT_CD_MODE_IN_LINEIN_MODE
		 	 	cd_mode_init();
		 	 #endif
	 	break;
	 	case mode_dvd:
		 	 #ifdef SUPPORT_USE_ENCODE_AS_MODE_CHANGE	
		 	 	bMulitWorkmode=DVD_WORK_MODE;
		 	 #endif
	 
		 	 #ifdef SUPPORT_DVD_MODE_IN_LINEIN_MODE
		 	 	dvd_mode_init();
		 	 #endif
	 	break;
	 	default:
	 		aux_info_init();
	 	break;
	 	}
	 #else
	 	aux_info_init();
	 
	 #endif
            rcsp_set_task_status(STAUS_PLAY);
            rcsp_report_status(RCSP_REPORT_START_CONFIG);
            break;
#ifdef suppout_line_puse_is_mute
        case MSG_AUX_PAUSE:
#endif

        case MSG_AUX_MUTE:

            if(msg[1] == RCSP_CBK_MSG_COMM_PLAY)
            {
                if(get_mute_status() == 0)
                {
                    break;
                }
            }
            else if(msg[1] == RCSP_CBK_MSG_COMM_PAUSE)
            {
                if(get_mute_status() != 0)
                {
                    break;
                }
            }
            else
            {
                ;
            }

            if (get_mute_status())
            {
                aux_puts("MSG_AUX_UNMUTE\n");
                dac_mute(0, 1);
                /* send_key_voice(500); */
                led_fre_set(0,0);
                rcsp_set_task_status(STAUS_PLAY);
		 #if 0//def suppport_aux_singe_no_swap
		 	JL_AUDIO->DAA_CON2 |= (BIT(14)|BIT(15));//bypass控制正相反相 // BTI14左声道 bit15右声道
		 #endif

		 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
		 	switch(bModeOfAuxContained)
		 	{
		 	case mode_aux:
		 		SET_UI_MAIN(MENU_AUX_MAIN);
		 		UI_menu(MENU_AUX_MAIN);
		 	break;
		 	case mode_ac3:
		 		 #ifdef SUPPORT_AC3_MODE_IN_LINEIN_MODE
		 		 	SET_UI_MAIN(MENU_AC3_MAIN);
		 		 	UI_menu(MENU_AC3_MAIN);
		 		 #endif
		 	break;
	 		 #ifdef SUPPORT_CD_MODE_IN_LINEIN_MODE
	 		 	case mode_cd:
	 		 	SET_UI_MAIN(MENU_CD_MAIN);
	 		 	UI_menu(MENU_CD_MAIN);
	 		 	break;
	 		 #endif
	 		 #ifdef SUPPORT_DVD_MODE_IN_LINEIN_MODE
	 		 	case mode_dvd:
	 		 	SET_UI_MAIN(MENU_DVD_MAIN);
	 		 	UI_menu(MENU_DVD_MAIN);
	 		 	break;
	 		 #endif
		 	default:
		 		SET_UI_MAIN(MENU_AUX_MAIN);
		 		UI_menu(MENU_AUX_MAIN);
		 	break;
		 	}
		 #else
		 	SET_UI_MAIN(MENU_AUX_MAIN);
		 	UI_menu(MENU_AUX_MAIN);
		 #endif





				
#ifdef PA_ENABLE
                pa_umute();
#endif
                  #ifdef SUPPORT_PT2313
                   PT2313Mute(FALSE);
                  #endif

#ifdef support_line_pause_disp_pause
                aux_pause_mark=0;
                //         SET_UI_MAIN(MENU_AUX_MAIN);
                //      UI_menu(MENU_AUX_MAIN);
#endif
            }
            else
            {

       #ifdef SUPPORT_PT2313
       	PT2313Mute(TRUE);
       #endif

                aux_puts("MSG_AUX_MUTE\n");
                os_time_dly(30);
                dac_mute(1, 1);
                led_fre_set(0,0);
                rcsp_set_task_status(STAUS_PAUSE);
#ifdef PA_ENABLE
                pa_mute();
#endif
#ifdef support_line_pause_disp_pause
                aux_pause_mark=1;
                SET_UI_LOCK(MENU_AUX_PAUSE);
                UI_menu(MENU_AUX_PAUSE);
#endif
            }
            break;

        case MSG_PROMPT_PLAY:
        case MSG_LOW_POWER:
            puts("aux_low_power\n");
            aux_dac_channel_off();
            linein_prompt_play(BPF_LOW_POWER_MP3);
            break;

#if LCD_SUPPORT_MENU
        case MSG_ENTER_MENULIST:
            UI_menu_arg(MENU_LIST_DISPLAY,UI_MENU_LIST_ITEM);
            break;
#endif


#if  SUPPORT_ALL_VOICE

#if   SUPPORT_TY_VOICE==0

	#ifdef SUPPORT_VOICE_ONOFF_KEY_SINGLE_KEY
	
		case MSG_AUX_VOICE_SWITCH:
          //	  printf("-----MSG_AUX_VOICE_SWITCH---\n");

			if(IsVoiceEnable)
			{
				bStoreVoiceVal=IsVoiceEnable;
				IsVoiceEnable = 0;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_OFF);
				 #endif

		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif

		 		if(bStoreVoiceVal==1)
					linein_prompt_play(BPF_VOICE_OFF_MP3);
				else
					linein_prompt_play(BPF_VOICE_OFF_EN_MP3);
			}
			else
			{
					IsVoiceEnable = bStoreVoiceVal;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_ON);
				 #endif
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
		 		if(IsVoiceEnable==1)
					linein_prompt_play(BPF_VOICE_ON_MP3);
				else
					linein_prompt_play(BPF_VOICE_ON_EN_MP3);

			}

			break;

		case MSG_AUX_VOICE_CHANGE:
			
          	  printf("-----MSG_AUX_VOICE_CHANGE---\n");
			
			if(IsVoiceEnable==0)
				break;

		 		if(IsVoiceEnable==1)
		 		{
		 			IsVoiceEnable=2;
					 #ifdef LED_SHOW_ONOFF
					 	UI_menu(MENU_VOICE_EN);
					 #endif

			 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 #endif

					linein_prompt_play(BPF_VOICE_EN_MP3);
				 }
				else
				{
					IsVoiceEnable = 1;
					 #ifdef LED_SHOW_ONOFF
					 	UI_menu(MENU_VOICE_CH);
					 #endif
			 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 #endif

					linein_prompt_play(BPF_VOICE_CH_MP3);
				}

			break;

	#else
		case MSG_AUX_VOICE_SWITCH:

			 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
			 		if(IsVoiceEnable==1)
			 		{
						IsVoiceEnable = 2;
						 #ifdef LED_SHOW_ONOFF
						 	UI_menu(MENU_ON);
						 #endif
	 			 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
	 			 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
	 			 		 #endif
						 linein_prompt_play(BPF_VOICE_ON_EN_MP3);
					 }
			 		else
			  	#endif


			 #ifdef SUPPORT_SCG_VOICE
			 
			 
			 
			 #else
			 
			 
			 				if(IsVoiceEnable)
			 				{
			 					IsVoiceEnable = 0;
			 				 #ifdef LED_SHOW_ONOFF
			 				 	UI_menu(MENU_OFF);
			 				 #endif
			 		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 		 #endif
			 
			 					linein_prompt_play(BPF_VOICE_OFF_MP3);
			 				}
			 				else
			 				{
			 					IsVoiceEnable = 1;
			 					 #ifdef LED_SHOW_ONOFF
			 					 	UI_menu(MENU_ON);
			 					 #endif
			 		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
			 		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
			 		 		 #endif
			 					 linein_prompt_play(BPF_VOICE_ON_MP3);
			 				}
			 
			 
			 				break;
			 
			 #endif



			#endif

	 #ifdef SUPPORT_MUTE_VOICE
	 
	    case MSG_VOICE_MUTE:
		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
	    				linein_prompt_play(BPF_MUTE_EN_MP3);			    		    				 	    		    		    	
				}
		 		else				
		  	#endif	
			if(IsVoiceEnable)
		    	{
	    			linein_prompt_play(BPF_MUTE_MP3);			    		    				 	    		    		    	
		    	}
	    	break;
	    case MSG_VOICE_MUTE_OFF:

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
	    				linein_prompt_play(BPF_MUTE_OFF_EN_MP3);			    		    				 	    		    		    	
				}
		 		else				
		  	#endif	
			if(IsVoiceEnable)
		    	{
	    			linein_prompt_play(BPF_MUTE_OFF_MP3);			    		    				 	    		    		    	
		    	}
	    	break;
			
	#endif


#ifdef SUPPORT_SCG_VOICE

#else

		case MSG_VOICE_VOLUME_PLUS:

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)
		 		{
					if(dac_ctl.sys_vol_l ==30)
		    				linein_prompt_play(BPF_VL_MAX_EN_MP3);
					else
		    				linein_prompt_play(BPF_VL_INC_EN_MP3);
				 }
		 		else
		  	#endif
			#if SUPPORT_VOL_VOICE			

			 if(IsVoiceEnable)
			 {
				if(dac_ctl.sys_vol_l ==30)
		    				linein_prompt_play(BPF_VL_MAX_MP3);
				else
		    				linein_prompt_play(BPF_VL_INC_MP3);

			 }
		  	#endif
			 break;

		case MSG_VOICE_VOLUME_MINUS:

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)
		 		{
	    				linein_prompt_play(BPF_VL_DEC_EN_MP3);
				 }
		 		else
		  	#endif
			#if SUPPORT_VOL_VOICE			

			 if(IsVoiceEnable)
			 {
	    			linein_prompt_play(BPF_VL_DEC_MP3);
			 }
		  	#endif
			 break;

		case MSG_MAX_VOICE:

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)
		 		{
	    				linein_prompt_play(BPF_VL_MAX_EN_MP3);
				 }
		 		else
		  	#endif
			#if SUPPORT_VOL_VOICE			
			if(IsVoiceEnable)
			{
	    			linein_prompt_play(BPF_VL_MAX_MP3);
			}
		  	#endif
			break;


#endif


			
#endif
	 #ifdef SUPPORT_VOICE_MODE_KEY

		case MSG_AUX_VOICE_SWITCH:

				if(IsVoiceEnable)
				{
					IsVoiceEnable = 0;
				 #ifdef LED_SHOW_ONOFF
				 	UI_menu(MENU_OFF);
				 #endif
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif

					linein_prompt_play(BPF_VOICE_OFF_MP3);
				}
				else
				{
					IsVoiceEnable = 1;
					 #ifdef LED_SHOW_ONOFF
					 	UI_menu(MENU_ON);
					 #endif
		 		 #ifdef SUPPORT_VOICE_ENALBE_MEM
		 		 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
		 		 #endif
					 linein_prompt_play(BPF_VOICE_ON_MP3);
				}


				break;	 
	 #endif


	 
		 #ifdef SUPPORT_SCG_VOICE
	 		 #ifdef SUPPORT_MUTE_VOICE
	 		 
	 		 	case MSG_VOICE_MUTE:
	 	 		 	if(bVoiceOnoff)				
	 	 		 	{
	 	 		 		linein_prompt_play(BPF_MUTE_EN_MP3);			    		    				 	    		    		    	
	 	 		 	}
	 		 	break;
	 		 	case MSG_VOICE_MUTE_OFF:
	 	 		 	if(bVoiceOnoff)				
	 	 		 	{
	 	 		 		linein_prompt_play(BPF_MUTE_OFF_EN_MP3);			    		    				 	    		    		    	
	 	 		 	}
	 		 	break;
	 		 
	 		 #endif
		 
		 	case MSG_VOICE_VOLUME_PLUS:
	 		 	if(bVoiceOnoff)
	 		 	{
	 		 		if(dac_ctl.sys_vol_l ==30)
	 		 			{
	 		 				printf("111111111222223333333\n");
	 	 		 			linein_prompt_play(BPF_VL_MAX_MP3);
	 		 			}
	 		 		else
	 		 			{
	 	 		 			linein_prompt_play(BPF_VL_INC_MP3);
	 		 				printf("==========\n");
	 		 			}
	 		 	}
		 	break;
		 
		 	case MSG_VOICE_VOLUME_MINUS:
	 		 	if(bVoiceOnoff)
	 		 	{
	 		 		linein_prompt_play(BPF_VL_DEC_MP3);
	 		 	}
		 	break;
		 
		 	case MSG_MAX_VOICE:
	 		 	if(bVoiceOnoff)
	 		 	{
	 		 		linein_prompt_play(BPF_VL_MAX_MP3);
	 		 	}
		 	break;
		 
		 #endif




	 #ifdef SUPPORT_MIC_ONOFF_VOICE
	 
	 		case MSG_VOICE_MIC:
	 
	 			if(mic_sw)
	 	    			linein_prompt_play(BPF_MIC_ON_MP3);
	 			else
	 	    			linein_prompt_play(BPF_MIC_OFF_MP3);
	 
	 			break;
	 #endif








#endif


        case MSG_HALF_SECOND:

      //      printf("-----MSG_AUX_VOICE_SWITCH---%x\n",MSG_AUX_VOICE_SWITCH);
      
  //          printf("---aux-------V- = %d\n",dac_ctl.sys_vol_l);
					
            //aux_puts(" Aux_H ");
#if AUX_REC_EN
            if(updata_enc_time(aux_rec))
            {
                UI_menu(MENU_HALF_SEC_REFRESH);
            }
#endif

            if (get_mute_status() == 0)
            {
                rcsp_set_task_status(STAUS_PLAY);
            }
            else
            {
                rcsp_set_task_status(STAUS_PAUSE);
            }

            break;

        default:
            if(msg[0] == MSG_ECHO_START)//start echo
            {
                exit_rec_api(&aux_rec); //stop rec
            }
            else if (msg[0] == MSG_REC_START)//start rec
            {
                echo_exit_api((void **)&aux_reverb);//stop echo
            }
            echo_msg_deal_api((void **)&aux_reverb, msg);
            rec_msg_deal_api(&aux_rec, msg);
            break;
        }

        Update_rcsp_Task_State(msg[0], 0);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief  LINE IN 任务创建
 @param  priv：任务间参数传递指针
 @return 无
 @note   static void linein_task_init(void *priv)
 */
/*----------------------------------------------------------------------------*/
static void linein_task_init(void *priv)
{
    u32 err;
    err = os_task_create(linein_task, (void*) 0, TaskLineinPrio, 10
#if OS_TIME_SLICE_EN > 0
                         ,1
#endif
                         , LINEIN_TASK_NAME);

    if (OS_NO_ERR == err)
    {
 	 #ifdef SUPPORT_TM1628_KEY_READ
       	key_msg_register(LINEIN_TASK_NAME, linein_led_table,linein_ad_table, linein_io_table, linein_ir_table, NULL);
	 #else    
       	key_msg_register(LINEIN_TASK_NAME, linein_ad_table, linein_io_table, linein_ir_table, NULL);
	 #endif
    }

#ifdef SUPPORT_AUX_FAST_SHOW_CHAR
    ui_open_aux(&aux_rec,sizeof(RECORD_OP_API **));
#endif
#if defined(LED_ID_JW2781)

led7_var.bEqCircleIfPlay=TRUE;
#endif

#ifdef KOK_DETECT_AUTO_VOL_SET
///	 store_vol= dac_ctl.sys_vol_l;
	dac_ctl.sys_vol_l = 30;
	dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;
	set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);


#endif




}

/*----------------------------------------------------------------------------*/
/**@brief  LINE IN 任务删除退出
 @param  无
 @return 无
 @note   static void linein_task_exit(void)
 */
/*----------------------------------------------------------------------------*/
static void linein_task_exit(void)
{
    if (os_task_del_req(LINEIN_TASK_NAME) != OS_TASK_NOT_EXIST)
    {
        os_taskq_post_event(LINEIN_TASK_NAME, 1, SYS_EVENT_DEL_TASK);
        do
        {
            OSTimeDly(1);
        }
        while (os_task_del_req(LINEIN_TASK_NAME) != OS_TASK_NOT_EXIST);
        aux_puts("del_linein_task: succ\n");
    }
#ifdef SUPPORT_AUX_MAX_VOL_DEC
set_max_dac_vol(ANALOG_VOL_MAX_L, ANALOG_VOL_MAX_R, DIGITAL_VOL_MAX_L,DIGITAL_VOL_MAX_R);
#endif

#ifdef support_sound_4052_control
	AC4052_IS_MP3();
#endif




}

/*----------------------------------------------------------------------------*/
/**@brief  LINE IN 任务信息
 @note   const struct task_info linein_task_info
 */
/*----------------------------------------------------------------------------*/
TASK_REGISTER(linein_task_info) =
{
    .name = LINEIN_TASK_NAME,
    .init = linein_task_init,
    .exit = linein_task_exit,
};
