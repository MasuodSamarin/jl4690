#ifndef __DAC_API_H__
#define __DAC_API_H__

#include "typedef.h"
#include "cpu/dac_param.h"
//********************************************************************
//						DAC CONFIG
//********************************************************************
#if SYS_DEFAULT_VOL==32
#define MAX_SYS_VOL_L         32      ///<ϵͳ����������
#define MAX_SYS_VOL_R         32
#else
#define MAX_SYS_VOL_L         30      ///<ϵͳ����������
#define MAX_SYS_VOL_R         30
#endif

#define EARPHONE_MAX_VOL_L	  25
#define EARPHONE_MAX_VOL_R	  25


/*�����������ʹ���������ϵͳ����������*/

#ifdef SUPPORT_MODE_MAX_VOL_SINGLE_ADJUST
#ifdef SUPPORT_TIANYIN_AUX_VOL_ADJUST


#define FM_DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define FM_DIGITAL_VOL_MAX_R     31
#define FM_ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define FM_ANALOG_VOL_MAX_R      31


#define MP3_DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define MP3_DIGITAL_VOL_MAX_R     31
#define MP3_ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define MP3_ANALOG_VOL_MAX_R      31


#define BT_DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define BT_DIGITAL_VOL_MAX_R     31
#define BT_ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define BT_ANALOG_VOL_MAX_R      31


#define AUX_DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define AUX_DIGITAL_VOL_MAX_R     31
#define AUX_ANALOG_VOL_MAX_L      27      ///<ģ��ͨ������������ڼ���
#define AUX_ANALOG_VOL_MAX_R      27


#define DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define DIGITAL_VOL_MAX_R     31
#define ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define ANALOG_VOL_MAX_R      31

#elif  defined SUPPORT_ZY_VOL_ADJUST


#define FM_DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define FM_DIGITAL_VOL_MAX_R     31
#define FM_ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define FM_ANALOG_VOL_MAX_R      31


#define MP3_DIGITAL_VOL_MAX_L     27      ///<����ͨ������������ڼ���
#define MP3_DIGITAL_VOL_MAX_R     27
#define MP3_ANALOG_VOL_MAX_L      27      ///<ģ��ͨ������������ڼ���
#define MP3_ANALOG_VOL_MAX_R      27


#define BT_DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define BT_DIGITAL_VOL_MAX_R     31
#define BT_ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define BT_ANALOG_VOL_MAX_R      31


#define AUX_DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define AUX_DIGITAL_VOL_MAX_R     31
#define AUX_ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define AUX_ANALOG_VOL_MAX_R      31


#define DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define DIGITAL_VOL_MAX_R     31
#define ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define ANALOG_VOL_MAX_R      31

#else
#define FM_DIGITAL_VOL_MAX_L     26      ///<����ͨ������������ڼ���
#define FM_DIGITAL_VOL_MAX_R     26
#define FM_ANALOG_VOL_MAX_L      26      ///<ģ��ͨ������������ڼ���
#define FM_ANALOG_VOL_MAX_R      26


#define MP3_DIGITAL_VOL_MAX_L     25      ///<����ͨ������������ڼ���
#define MP3_DIGITAL_VOL_MAX_R     25
#define MP3_ANALOG_VOL_MAX_L      25      ///<ģ��ͨ������������ڼ���
#define MP3_ANALOG_VOL_MAX_R      25


#define BT_DIGITAL_VOL_MAX_L     26      ///<����ͨ������������ڼ���
#define BT_DIGITAL_VOL_MAX_R     26
#define BT_ANALOG_VOL_MAX_L      26      ///<ģ��ͨ������������ڼ���
#define BT_ANALOG_VOL_MAX_R      26


#define AUX_DIGITAL_VOL_MAX_L     26      ///<����ͨ������������ڼ���
#define AUX_DIGITAL_VOL_MAX_R     26
#define AUX_ANALOG_VOL_MAX_L      26      ///<ģ��ͨ������������ڼ���
#define AUX_ANALOG_VOL_MAX_R      26


#define DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define DIGITAL_VOL_MAX_R     31
#define ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define ANALOG_VOL_MAX_R      31
#endif
#else

#if SYS_DEFAULT_VOL==32
#define DIGITAL_VOL_MAX_L     33      ///<����ͨ������������ڼ���
#define DIGITAL_VOL_MAX_R     33
#else
#define DIGITAL_VOL_MAX_L     31      ///<����ͨ������������ڼ���
#define DIGITAL_VOL_MAX_R     31
#endif
#define ANALOG_VOL_MAX_L      31      ///<ģ��ͨ������������ڼ���
#define ANALOG_VOL_MAX_R      31
#endif


#define FADE_ON      1                ///<ͨ���л�ʹ�õ��뵭��
#define FADE_OFF     0                ///<ͨ���л���ʹ�õ��뵭��

#define AUTO_MUTE_DISABLE	  0         ///����ͨ��auto mute����
#define AUTO_MUTE_ENABLE 	 BIT(0) 	///����ͨ��auto mute����
#define AUTO_UNMUTE_FADE	 BIT(1)     ///�� FADE IN Ч��
#define AUTO_MUTE_UMUTE_DAC	 BIT(2)     ///Only fade out when auto mute
#define AUTO_FADE_CTL		 BIT(3)
#define AUTO_MUTE_CFG		 AUTO_MUTE_ENABLE | AUTO_UNMUTE_FADE

#define LDO_SLECT  LDO_1      ///LDOѡ��  DAC_VDD��Ҫ����ѡ��LDO1������Ҫ����ѡ��LDO2 ,LDO2������Ȳ��


#define BT_CHANNEL         DAC_DIGITAL_AVOL
#define MUSIC_CHANNEL      DAC_DIGITAL_AVOL
#define RTC_CHANNEL        DAC_DIGITAL_AVOL
#define FM_INSI_CHANNEL    DAC_DIGITAL_AVOL
#define FM_IIC_CHANNEL     DAC_AMUX1
#ifdef   line_user_PA1PA2  //AUX0
#define LINEIN_CHANNEL     DAC_AMUX0
#elif defined line_user_PA1
#define LINEIN_CHANNEL     DAC_AMUX0_L_ONLY
#elif defined line_user_PA3
#define LINEIN_CHANNEL     DAC_AMUX1_L_ONLY
#elif defined line_user_dacr
#define LINEIN_CHANNEL     DAC_AMUX_DAC_R
#elif defined line_user_dacl
#define LINEIN_CHANNEL     DAC_AMUX_DAC_L
#elif defined line_user_PB11PB12
#define LINEIN_CHANNEL     DAC_AMUX2
#else //line_user_PA3PA4
#define LINEIN_CHANNEL     DAC_AMUX1
#endif

#if defined SUPPORT_DOUBLE_LINEIN
#define LINEIN_CHANNEL_2     DAC_AMUX1
#endif

#if defined SUPPORT_MULTI_INPUT_MODE
#define LINEIN_CHANNEL_1     DAC_AMUX1
#endif


#define UDISK_CHANNEL      DAC_DIGITAL_AVOL


//********************************************************************
//           		DAC API FUN
//********************************************************************
///dac init api
void dac_init_api(tbool vcom_outen,u8 ldo_slect,u8 hp_type,u8 dac_isel);
void dac_on_api(tbool vcom_outen,u8 ldo_slect,u8 hp_type);
void dac_off_api();
s32 dac_reg_isr_cb_api(u32 priority,void (*callback_fun)(void *dac_buf,u8 buf_flag));

///dac channel api
s32  dac_channel_on(u8 channel, u8 fade_en);
void dac_channel_off(u8 channel, u8 fade_en);
u16 get_cur_dac_channel(void);

///dac vol setting
void set_max_dac_vol(u8 max_analog_vol_l,u8 max_analog_vol_r,u8 max_digital_vol_l,u8 max_digital_vol_r);
void set_max_sys_vol(u8 max_sys_vol_l, u8 max_sys_vol_r);
void set_sys_vol(u32 l_vol, u32 r_vol, u8 fade_en);
void init_sys_vol(u32 l_vol,u32 r_vol);
u8 get_sys_vol_api(u8 l_or_r);
u8 get_max_sys_vol(u8 l_or_r);

///dac mute api
void digit_auto_mute_set(u8 ctl,u16 packet_cnt,u16 Threshold,u8 max_cnt);
void dac_mute(u8 mute_flag, u8 fade_en);
bool is_dac_mute(void);
bool is_auto_mute(void);

///dac data processing
void dac_digital_lr2one(void *buffer,u32 len);
void reg_digital_vol_tab(void *tab);
void reg_set_sr_fun(void (*fun)(u16 rate));
void dac_set_samplerate(u16 sr, u8 wait);
u16 dac_get_samplerate(void);
void digital_vol_ctrl(void *buffer, u32 len);
u32 dac_digit_energy_value(void *buffer,u16 len);

//dac buf api
void dac_buf_init(void* dma_buf,u32 dma_buf_len,void* cbuf,u32 cbuf_len);
int get_dac_cbuf_len(void);
int get_dac_cbuf_len_param(void *arg);
int dac_read(void *buf,u32 len);
void dac_write(u8 *buf, u32 len);
void cbuf_write_dac(s16 * buf, u32 len);
void dac_cbuf_write_detect(void);
void clear_dac_buf(u8 post_ie);
void clear_dac_cbuf(u8 post_ie);
void clear_dac_dma_buf(u8 post_ie);

void dac_fade(void *ptr);
void dac_fade_ctl(u8 fade,u8 fade_speed);

void dac_trim_en(u8 en);
void dac_digital_en(u8 en);
void dac_ldo_set(u8 ldo_sel,u8 en);
void dac_ie_api(u8 en);
void amux_ch_combine(u8 lr2l,u8 lr2r);
void dac_vout_en(u8 voutl,u8 voutr);
void audio_sfr_dbg(u8 en);
void mic_2_LR(u8 left_en,u8 right_en);
void reg_dac_power_on_time_fun(void (*fun)(u8 mode));
void dac_vcm_rsel_set(u8 val);
u32 get_dac_energy_value(void);
void dac_AmuxGain_en(u8 en);

#endif  //__DAC_API_H__
