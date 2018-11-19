/*--------------------------------------------------------------------------*/
/**@file     fm_inside.c
   @brief    �ڲ������ײ�����
   @details
   @author
   @date   2011-3-30
   @note
*/
/*----------------------------------------------------------------------------*/
#include "sdk_cfg.h"
#include "clock_api.h"
#include "fm/fm_api.h"
#include "fm_inside.h"
#include "fm/fm_radio.h"
#include "fm_inside_api.h"
#include "dac/src_api.h"
#include "dac/dac_api.h"
#include "dac/dac.h"
#include "play_sel/play_sel.h"
#if	FM_INSIDE

struct fm_config_dat *fm_set_p = NULL;

extern RECORD_OP_API * rec_fm_api;
/*----------------------------------------------------------------------------*/
/**@brief  FM������������
   @param  buf��FM��Ƶ���ݵ�ַ
   @param  len��FM��Ƶ���ݳ���
   @return ��
   @note   ���������������
*/
/*----------------------------------------------------------------------------*/
#if 0
static const u8 fm_sine_buf_32K[] =
{
    0x00, 0x00, 0xae, 0x11, 0xad, 0x22, 0x58, 0x32,
    0x13, 0x40, 0x58, 0x4b, 0xb8, 0x53, 0xe0, 0x58,
    0x9e, 0x5a, 0xe0, 0x58, 0xb8, 0x53, 0x58, 0x4b,
    0x13, 0x40, 0x58, 0x32, 0xad, 0x22, 0xae, 0x11,
    0x00, 0x00, 0x52, 0xee, 0x53, 0xdd, 0xa8, 0xcd,
    0xed, 0xbf, 0xa8, 0xb4, 0x48, 0xac, 0x20, 0xa7,
    0x62, 0xa5, 0x20, 0xa7, 0x48, 0xac, 0xa8, 0xb4,
    0xed, 0xbf, 0xa8, 0xcd, 0x53, 0xdd, 0x52, 0xee

    /* 0x01, 0x00, 0x02, 0x00, 0xae, 0x11, 0xae, 0x11, 0xad, 0x22, 0xad, 0x22, 0x58, 0x32, 0x58, 0x32, 0x13, */
    /* 0x40, 0x13, 0x40, 0x58, 0x4b, 0x58, 0x4b, 0xb8, 0x53, 0xb8, 0x53, 0xe0, 0x58, 0xe0, 0x58, 0x9e, 0x5a, */
    /* 0x9e, 0x5a, 0xe0, 0x58, 0xe0, 0x58, 0xb8, 0x53, 0xb8, 0x53, 0x58, 0x4b, 0x58, 0x4b, 0x13, 0x40, 0x13, */
    /* 0x40, 0x58, 0x32, 0x58, 0x32, 0xad, 0x22, 0xad, 0x22, 0xae, 0x11, 0xae, 0x11, 0x00, 0x00, 0x00, 0x00, */
    /* 0x52, 0xee, 0x52, 0xee, 0x53, 0xdd, 0x53, 0xdd, 0xa8, 0xcd, 0xa8, 0xcd, 0xed, 0xbf, 0xed, 0xbf, 0xa8, */
    /* 0xb4, 0xa8, 0xb4, 0x48, 0xac, 0x48, 0xac, 0x20, 0xa7, 0x20, 0xa7, 0x62, 0xa5, 0x62, 0xa5, 0x20, 0xa7, */
    /* 0x20, 0xa7, 0x48, 0xac, 0x48, 0xac, 0xa8, 0xb4, 0xa8, 0xb4, 0xed, 0xbf, 0xed, 0xbf, 0xa8, 0xcd, 0xa8, */
    /* 0xcd, 0x53, 0xdd, 0x53, 0xdd, 0x52, 0xee, 0x52, 0xee */
};
#endif

void fm_rec_dac(s16 *buf, u32 len)
{

#if 1//FM_REC_EN
    u8 fm_rec_buf[0x40];
    s16 *dp = (s16 *)fm_rec_buf;
    u32 rec_point;
    if((rec_fm_api != NULL) && (rec_fm_api->rec_ctl != NULL))
    {
        if(rec_fm_api->rec_ctl->enable == ENC_STAR)
        {
            /* rec_fm_api->rec_ctl->ladc.save_ladc_buf(&rec_fm_api->rec_ctl->ladc,fm_sine_buf_32K,0,64); */
            /* rec_fm_api->rec_ctl->ladc.save_ladc_buf(&rec_fm_api->rec_ctl->ladc,fm_sine_buf_32K,1,64); */

            for(rec_point = 0; rec_point < 0x20; rec_point++)
            {
                dp[rec_point] = buf[rec_point*2];//all left channel data
            }
            rec_fm_api->rec_ctl->ladc.save_ladc_buf(&rec_fm_api->rec_ctl->ladc, dp, 0, 0x40);

            for(rec_point = 0; rec_point < 0x20; rec_point++)
            {
                dp[rec_point] = buf[rec_point*2+1];//all right channel data
            }
            rec_fm_api->rec_ctl->ladc.save_ladc_buf(&rec_fm_api->rec_ctl->ladc, dp, 1, 0x40);
        }
    }

#endif

}
#define FM_FADEIN_VAL	100
static u16 fm_fadein_cnt = 0;
static void fm_dac_out(s16 *buf, u32 len)///len��byteΪ��λ
{
    if(fm_fadein_cnt)
    {
        fm_fadein_cnt--;
        /* printf(" %d ",fm_fadein_cnt); */
        return;
    }

    //stop fm output when prompt playing
    if(play_sel_busy())
        return;

    if(fm_mode_var && fm_mode_var->fm_mute)//MUTE
    {
        memset(buf,0x00,len);
    }

    /* putchar('F'); */
    cbuf_write_dac(buf, len);

    fm_rec_dac(buf, len);
}

/*----------------------------------------------------------------------------*/
/**@brief  FM driver �������
   @param  buf��FM��Ƶ���ݵ�ַ
   @param  len��FM��Ƶ���ݳ���
   @return ��
   @note
*/
/*----------------------------------------------------------------------------*/
static void fm_drv_data_out(void * buf, u32 len)
{
    src_write_data_api(buf,len);
}

/*----------------------------------------------------------------------------*/
/**@brief  FM src �����ʹ������
   @param  flag -- ����
   @param
   @return ��
   @note
*/
/*----------------------------------------------------------------------------*/
static void src_md_fm_ctl(int flag)
{
    src_param_t src_p;

    if(flag == 1)
    {
        puts("fm_src_start\n");
        src_p.in_chinc = 1;
        src_p.in_spinc = 2;
        src_p.out_chinc = 1;
        src_p.out_spinc = 2;
        src_p.in_rate = 41667;
        src_p.out_rate = FM_DAC_OUT_SAMPLERATE;
        src_p.nchannel = 2;
        src_p.output_cbk = (void *)fm_dac_out;
        src_init_api(&src_p);
    }
    else
    {
        src_exit_api();
        puts("fm_src_stop\n");
    }

}

///--------------------------FM_INSIDE_API------------------------

void fm_inside_init(void)
{
    bool mute_flag;

    mute_flag = is_dac_mute();
    if(mute_flag == 0)
    {
        dac_mute(1,1);
    }

    set_fm_dac_out_fun(fm_drv_data_out);
    src_md_fm_ctl(1);
    dac_set_samplerate(FM_DAC_OUT_SAMPLERATE,1);
    dac_channel_on(FM_INSI_CHANNEL, FADE_ON);

    fm_inside_module_open();

#if 0//def FM_SCAN_MODE_DATA_AMP

    //FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	180, 		75, 	58, 	50);

    //FM��̨����2���ã��ֱ��Ӧ��				//agc_threshold	//rssi		//(reserve)	//(reserve)	//agc_max	//(reserve)
    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	-30, 			180, 		0, 			0, 			9, 			0);

    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);



#elif 0//defined   FM_SCAN_MODE_129   // 20161129 add

/*
	 ��̨�������
	 nrs ���ź�ǿ������ֵ
	 nc1 ���źŹ�����������ֵ
	 nc2 ���źŷ�ֵ��������ֵ
	 ncc : nc1���ֵ��nc2���ֵ�Ĳ�ֵ
	 
	 noise_scan: ����Ϊ1ʱ�򣬻�ȡ��ƽ���ź�ǿ�ȣ����Խ������������Ϊ0��
	 noise_pga: �����ڲ�����������ڷ�Χ����noise_scan����1ʱ���ȡ�õ���
	 cnr����̨���ź�ǿ���жϷ�ֵ��ֵԽС����̨Խ�ࡣ
	 agc_max���Զ��������ֵ��Χ������ֵ9����Χ��0-9����
	 (reserve)���������޸ı���ֵ

����ǰƵ����ź�ǿ�ȣ�nrs��������
����������nc1��С����ֵ
��ֵ������nc2��С����ֵ
 nccС����ֵ
 �����ĸ�����ͬʱ���������̨Ϊ��̨��	 
*/

// -----1.29   ԭʼ����------

	//FM��̨����1���ã��ֱ��Ӧ��	//nrs	//nc1	//nc2	//ncc
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		55, 	45, 	40);
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		75, 	65, 	60);

	//FM��̨����2���ã��ֱ��Ӧ��	//noise_scan	//noise_pga	//cnr	//(reserve)	//agc_max	//(reserve)
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			2,		10, 			9, 			0);
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			3,		10, 			9, 			0);

// -----1.29   ԭʼ����------


    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);

	
#elif 0//defined   FM_SCAN_MODE_1   // 20161129 add

    //FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 200, 150,  150);

    //FM��̨����2���ã��ֱ��Ӧ��				//agc_threshold	//rssi		//(reserve)	//(reserve)	//agc_max	//(reserve)
    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	-30, 			1000, 		0, 			0, 			9, 			0);

    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);


#elif 0//defined   FM_SCAN_MODE_2   // 20161129 add
	
    //FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
   fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 100, 100,  50);

//-------------nei ----   -30---------------

// 9--11  
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 100, 200,  50);
// 10  
 //  fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 200, 50,  50);


// --12--- ԭʼ����------ -30
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	200, 		90, 	58, 	55);

//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 100, 50,  50);
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 150, 100,  50);

// 14  10  10 	-30
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 200, 100,  50);

// 13  -14   -30
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 100, 100,  60);
//-------------nei -----   -30-------------


//-------------nei ---   -25---------------

//  12--14  
//   fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  200, 100, 100,  50);

//-------------nei ---   -25---------------

    //FM��̨����2���ã��ֱ��Ӧ��				//agc_threshold	//rssi		//(reserve)	//(reserve)	//agc_max	//(reserve)
    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	-25, 			1000, 		0, 			0, 			9, 			0);

    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);

#elif defined   FM_SCAN_MODE_ZY_DATA_AMP   // 20170228 add



// --------------------15--7-------
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		45, 	35, 	30);
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			3,		10, 			6, 			0);
//---------------------------------



// -----1.215   --13--5----

	//FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		55, 	45, 	40);

	//FM��̨����2���ã��ֱ��Ӧ��	//noise_scan	//noise_pga	//cnr	//(reserve)	//agc_max	//(reserve)
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			5,		10, 			9, 			0);


// -----1.215   ------


    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);
	
#elif defined   FM_SCAN_MODE_KPH_DATA_AMP  


// --------------------15--7-------
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		100, 	100, 	100);
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			3,		10, 			6, 			0);
//--------------------------------

    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);	
	
#else 

// -----1.215   ------

	//FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		55, 	45, 	40);

	//FM��̨����2���ã��ֱ��Ӧ��				//noise_scan	//noise_pga	//cnr	//(reserve)	//agc_max	//(reserve)
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			2,		10, 			9, 			0);


// -----1.215   ------


	//FM��̨����1���ã��ֱ��Ӧ��	//nrs	//nc1	//nc2	//ncc
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		75, 	65, 	60);

	//FM��̨����2���ã��ֱ��Ӧ��	//noise_scan	//noise_pga	//cnr	//(reserve)	//agc_max	//(reserve)
	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			3,		10, 			9, 			0);

// -----1.210  KPH  SET   26 STATION  20161226 ADD ------




// -----1.29   ԭʼ����------

	//FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	4, 		55, 	45, 	40);

	//FM��̨����2���ã��ֱ��Ӧ��				//noise_scan	//noise_pga	//cnr	//(reserve)	//agc_max	//(reserve)
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	0, 				8, 			2,		10, 			9, 			0);

// -----1.29   ԭʼ����------



// ----1.28- ԭʼ����------
    //FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	200, 		90, 	58, 	55);

    //FM��̨����2���ã��ֱ��Ӧ��				//agc_threshold	//rssi		//(reserve)	//(reserve)	//agc_max	//(reserve)
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	-30, 			1000, 		0, 			0, 			9, 			0);
// ----1.28- ԭʼ����------

//--------6901 use------28-̨����---------------------
    //FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	50, 		20, 	20, 	20);
    //FM��̨����2���ã��ֱ��Ӧ��				//agc_threshold	//rssi		//(reserve)	//(reserve)	//agc_max	//(reserve)
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	-30, 			200, 		0, 			0, 			9, 			0);
//--------6901------28-̨����---------------------


//--------��ʯ�����õĲ���----ac6903 use-
//	fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1,  150,  150,  100,  100);
//    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	-30, 			1000, 		0, 			0, 			9, 			0);
//--------��ʯ�����õĲ���

    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);
	
//--------------28----------------------
#if 0  // sdk  default   
    //FM��̨����1���ã��ֱ��Ӧ��				//nrs	//nc1	//nc2	//ncc
    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG1, 	200, 		90, 	58, 	55);

    //FM��̨����2���ã��ֱ��Ӧ��				//agc_threshold	//rssi		//(reserve)	//(reserve)	//agc_max	//(reserve)
    fm_inside_io_ctrl(SET_FM_INSIDE_SCAN_ARG2, 	-30, 			1000, 		0, 			0, 			9, 			0);

    //ϵͳʱ�ӻ�ȡ�������ڲ�FMģ��
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_CLK, OSC_Hz/1000000);

    //FM�ڲ�����ѡ��0��BT_OSC	,1��RTC_OSC
    fm_inside_io_ctrl(SET_FM_INSIDE_OSC_SEL, 0);
#endif

#endif

    //FM��̨��Ϣ��ӡ
#ifdef __DEBUG
    fm_inside_io_ctrl(SET_FM_INSIDE_PRINTF, 1);
#endif


    fm_inside_on(0);

    fm_set_stereo(0);
    /* fm_set_abw(48); */

    dac_mute(mute_flag,1);//recover mute status
    fm_fadein_cnt = FM_FADEIN_VAL;
}

bool fm_inside_set_fre(u16 fre)
{
    u8 udat8;
    u32 freq;
    freq = fre*FM_STEP;
    udat8 = set_fm_inside_freq(freq);
    fm_printf("fre = %u  %d\n", fre, udat8);
    return udat8;
}

bool fm_inside_read_id(void)
{
    return read_fm_inside_id();
}

void fm_inside_powerdown(void)
{
    fm_inside_off();
    src_md_fm_ctl(0);
    dac_channel_off(FM_INSI_CHANNEL, FADE_ON);
}

void fm_inside_mute(u8 flag)
{
    /* dac_mute(flag,1); */
    /* fm_mode_var->fm_mute = flag; */
}


#endif // FM_INSIDE
