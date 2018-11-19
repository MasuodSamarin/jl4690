#include "sdk_cfg.h"
#include "common/app_cfg.h"
#include "rtos/os_api.h"
#include "rtos/os_cfg.h"
#include "common/error.h"
#include "stdarg.h"
#include "music.h"
#include "common/msg.h"
#include "rtos/task_manage.h"
#include "music_key.h"
#include "dec/music_api.h"
#include "vm/vm_api.h"
#include "play_sel/play_sel.h"
#include "dac/dac_api.h"
#include "dev_manage/drv_manage.h"
#include "ui/ui_api.h"
#include "ui/led/led.h"
#include "key_drv/key.h"
#include "music_prompt.h"
#include "music_info.h"
#include "music_ui.h"
#include "fat/tff.h"
#include "fat/fs_io.h"
#include "common/common.h"
#include "lyrics_api.h"
#include "rcsp/rcsp_interface.h"
#include "dac/eq_api.h"
#include "dac/dac_api.h"
#include "dac/dac.h"
#include "dac/eq.h"
#include "music_ab_rpt.h"
#include "music_decrypt.h"
#include "clock_interface.h"
#include "clock.h"
#include "dec/decoder_phy.h"
#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif
#include "ui/led/led7_drv.h"

extern void ble_server_disconnect(void);
extern u32 file_operate_get_total_lgdev();
extern void *sup_dec_phy_op(void *priv,void *data, u32 len);
extern u32 get_decode_time(void);
extern const char dec_file_ext[][3];
const struct task_info music_task_info;

//FS_DISP_NAME_T *music_play_display;
//char *music_play_tpath;
FS_DISP_NAME music_name_buf;//buf need malloc


MUSIC_DIS_VAR music_ui;
void *music_reverb;

#ifdef support_pause_stop_mute_amp
bool  pause_mute_flag;
#endif
#ifdef support_mute_led_all_flish
extern bool  mute_flag;
#endif

#ifdef support_msg_stop_key
bool  play_stop_flag;
#endif
#if defined SUPPORT_MUSIC_PREV_NEXT_VOICE||defined SUPPORT_PP_PREV_NEXT_VOICE
bool IsMusicPrevBegin=0;
bool IsMusicNextBegin=0;
u8 bPrevNextVoiceFlag;
#endif		


#ifdef SUPPORT_VOICE_ONOFF
bool bVoiceOnoff;
#endif



#if MUSIC_DECRYPT_EN
#define MUSIC_SMP_PASSWORD 0X20140606  // zy  key 
#endif
#if REC_EN
bool rec_play_sw;
#endif
u8 curr_device;
u8 getting_music_info;
extern bool dec_dev_changed;

//const char rpt_str[][7] =
//{
//    {"ALL"},
//    {"FOLDER"},
//    {"ONE"},
//    {"RANDOM"}
//};

const char rpt_str[][10] =
{
    {"ALL"},
    {"ONE_DEV"},
    {"ONE_FILE"},
    {"RANDOM"},
    {"FOLDER"},
};



//#define MUSIC_TONE_NUM 1
#define MUSIC_DEC_PHY_NAME "MusicPhyDec"
#define EF_OUT_NAME    "ef_out_task"

u8 play_mode = REPEAT_ALL;
#ifdef SUPPORT_VM_EQ_MODE
u8 eq_mode ;
#else
u8 eq_mode = 0;
#endif
#ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE
bool bMusicFirstInFlag;
#endif

/*----------------------------------------------------------------------------*/
/**@brief  musicËß£Á†ÅÂàùÂßãÂåñ
   @param  mapi_out -- Ëß£Á†ÅÊ®°ÂùóÊåáÈíà
   @return 0-ÊàêÂäü,Èùû0Â§±Ë¥•
   @note
*/
/*----------------------------------------------------------------------------*/
int music_decoder_init(MUSIC_OP_API **mapi_out)
{
    MUSIC_OP_API *mapi = NULL;
    int err_id = 0;
    u32 err;
    do
    {
        mapi = malloc_fun(mapi,sizeof(MUSIC_OP_API),0);
        if(NULL == mapi)
        {
            err_id = 1;
            break;
        }
        /*-------Ëß£Á†ÅÊé•Âè£ËµÑÊ∫êÁî≥ËØ∑----------------*/
        mapi->dop_api=malloc_fun(mapi->dop_api,sizeof(_MUSIC_API),0);
        if(NULL==mapi->dop_api)
        {
           // dec_phy_printf(" if(NULL==mapi->dop_api) \r\n");
            err_id = 2;
            break;
        }
        /*-------Êñá‰ª∂Êìç‰ΩúÂô®ËµÑÊ∫êÁî≥ËØ∑--------------*/
        mapi->fop_api=malloc_fun(mapi->fop_api,sizeof(FILE_OPERATE),0);
        if(NULL==mapi->fop_api)
        {
            //dec_phy_printf(" if(NULL==mapi->fop_api) \r\n");
            err_id = 3;
            break;
        }
#ifdef AC6905B_512K
        mapi->dop_api->dec_api.type_enable = DEC_PHY_MP3 | DEC_PHY_WAV ;//‰ΩøËÉΩÂìçÂ∫îÁöÑËß£Á†ÅÂ∫ì
#else
        mapi->dop_api->dec_api.type_enable = DEC_PHY_MP3 | DEC_PHY_WAV |  \
                                             DEC_PHY_WMA | DEC_PHY_FLAC | \
                                             DEC_PHY_APE ;//‰ΩøËÉΩÂìçÂ∫îÁöÑËß£Á†ÅÂ∫ì
#endif
        mapi->dop_api->file_type = (void*)dec_file_ext;

        mapi->dop_api->dec_api.dec_phy_name = MUSIC_DEC_PHY_NAME;

        err = os_task_create_ext(decoder_phy_task, 0, TaskMusicPhyDecPrio, 5, mapi->dop_api->dec_api.dec_phy_name, MUSIC_PHY_TASK_STACK_SIZE);
        if(OS_NO_ERR == err)
        {
            //dec_phy_printf("creat decoder_phy_task ok \n");
        }
        else
        {
            // printf("decoder_phy_task err=%08x\n",err);
            err_id = 4;
            break;
        }

        if(NULL == mapi->dop_api->io)
        {
            mapi->dop_api->io = malloc_fun(mapi->dop_api->io,sizeof(DEC_API_IO),0);
            if(NULL == mapi->dop_api->io)
            {
                //dec_phy_printf(" if(NULL == mapi->dop_api->dec_io) \r\n");
                err_id = 5;
                break;
            }
        }

        mapi->dop_api->io->father_name = "MusicTask";//Ëß£Á†ÅÁªìÊùüÁöÑÊ∂àÊÅØËøîÂõûÁªôË∞Å
        mapi->dop_api->file_num = 1;
        mapi->dop_api->dec_api.eq = eq_mode;

        //psel_enable = tone_play_by_name("MusicTask", BPF_MUSIC_MP3);
        /*-------Êñá‰ª∂Êìç‰ΩúÂô®ÂàùÂßãÂåñ‰ø°ÊÅØËµÑÊ∫êÁî≥ËØ∑--------------*/
        mapi->fop_api->fop_init = malloc_fun(mapi->fop_api->fop_init,sizeof(FILE_OPERATE_INIT),0);
        if(mapi->fop_api->fop_init==NULL)
        {
            //dec_phy_printf("mem err fop_init \n");
            err_id = 6;
            break;
        }
        mapi->fop_api->fop_init->cur_play_mode = play_mode;
        mapi->dop_api->brk = malloc_fun(mapi->dop_api->brk,sizeof(FS_BRK_POINT),0);
        mapi->dop_api->dec_api.bp_buff = &mapi->dop_api->brk->inf.brk_buff[0];

    }
    while(0);

    if(err_id != 0)
    {
        // printf("decoder init err = %d\n",err_id);
        while(1);
    }

    *mapi_out = mapi;

    return err_id;
}

/*----------------------------------------------------------------------------*/
/**@brief  Êñá‰ª∂Ëß£Á†ÅÂâçÂõûË∞ÉÂáΩÊï∞Â§ÑÁêÜ
   @param  parm -- Ëß£Á†ÅÊ®°ÂùóÊåáÈíà,dev_let-ÈÄªËæëÁõòÁ¨¶
   @return void
   @note
*/
/*----------------------------------------------------------------------------*/
void music_stop_decoder(MUSIC_OP_API *parm)
{
    _MUSIC_API *mapi;
    mapi=parm->dop_api;
    if(STOP_DEC_GOT_BRKINFO & stop_decoder(&mapi->dec_api))
    {
        file_operate_ctl(FOP_SAVE_BPINFO,parm->fop_api,&mapi->brk->inf,0);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief  Êñá‰ª∂Ëß£Á†ÅÂâçÂõûË∞ÉÂáΩÊï∞Â§ÑÁêÜ
   @param  m_op_api -- Ëß£Á†ÅÊ®°ÂùóÊåáÈíàÔºådev_let-ÈÄªËæëÁõòÁ¨¶
   @return void
   @note
*/
/*----------------------------------------------------------------------------*/
void before_decoder_callback(MUSIC_OP_API *m_op_api,u32 dev_let)
{
    music_ui.lrc_flag = FALSE;
    if(dev_let != 'A')
    {
#if LRC_LYRICS_EN
        if(0 == lrc_find(m_op_api))
        {
            music_ui.lrc_flag = TRUE;
        }
        else
        {
            // printf("lrc_init err\n");
        }
#endif

    }
    else
    {
        // puts("play a music\n");
    }

#if MUSIC_DECRYPT_EN
    get_decode_file_info(m_op_api->dop_api->io->f_p);
#endif

}

void after_decoder_callback(MUSIC_OP_API *m_op_api,u32 dev_let)
{
    if(0 == strcmp(m_op_api->dop_api->dec_api.phy_ops->dec_ops->name,"FLA"))//Ëß£Á†ÅÂô®FLAC
    {
        set_sys_freq(FLAC_SYS_Hz);
    }
    else if(0 == strcmp(m_op_api->dop_api->dec_api.phy_ops->dec_ops->name,"APE"))//Ëß£Á†ÅÂô®APE
    {
        set_sys_freq(APE_SYS_Hz);
    }
    else
    {
        set_sys_freq(SYS_Hz);
    }
}

#ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE
u8 bMediaErro;
#endif
/*----------------------------------------------------------------------------*/
/**@brief  Êñá‰ª∂Êí≠ÊîæÊÄªÂÖ•Âè£
   @param  m_op_api -- Ëß£Á†ÅÊ®°ÂùóÊåáÈíàÔºådev_sel- Á£ÅÁõòÊìç‰ΩúÊ®°Âºè dev_let-ÈÄªËæëÁõòÁ¨¶Ôºå
   @param  file_sel-Êñá‰ª∂ÈÄâÊã©Ê®°ÂºèÔºåpra--ÂèÇÊï∞
   @return 0-ÊàêÂäü,Èùû0Â§±Ë¥•
   @note
*/
/*----------------------------------------------------------------------------*/
u32 music_play_api(MUSIC_OP_API *m_op_api,ENUM_DEV_SEL_MODE dev_sel,u32 dev_let,u32 file_sel,void *pra)
{
    u32 err;
    u8 tmp8;

    getting_music_info = 0;

   // P_FUNCTION

//   reg_get_id3head(music_get_file_id3);
    music_ui.opt_state = MUSIC_OPT_BIT_SEL;

    GET_SYS_MEM_STAT();


	 #ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE

	//	 	  printf("------music_ui.ui_curr_file--------- =%d\n",music_ui.ui_curr_file);
		// 	  printf("------file_operate_get_total_phydev()--------- =%d\n",file_operate_get_total_phydev());
	//	 	  printf("------curr_device_using--------- =%d\n",curr_device_using);
	 //
	 	if(((bMediaErro==1)&&(file_operate_get_total_phydev()>1)&&(music_ui.ui_curr_file == m_op_api->fop_api->cur_lgdev_info->total_file_num))\
			||((bMediaErro==2)&&(file_operate_get_total_phydev()>1)&&(music_ui.ui_curr_file == 1)))
	 		{
				 #if SDMMC0_EN
				 	if(sd0==curr_device_using)
				 #elif SDMMC1_EN
				 	if(sd1==curr_device_using)
				 #endif		 			 
	 	                {
	 	                    curr_device_using = (u32)usb;
	 	                }
	 	                else
	 	                {
		 	                #if SDMMC0_EN
		 	                    curr_device_using = (u32)sd0;
					  #elif SDMMC1_EN
		 	                    curr_device_using = (u32)sd1;
					  #endif
	 	                }
	 		}
		
	  	 	bMediaErro=0;		
	 #endif


    err = music_play(m_op_api, dev_sel, dev_let, (ENUM_FILE_SELECT_MODE)file_sel, pra);

    if(err == SUCC_MUSIC_START_DEC)
    {
        tmp8 = (u8)file_operate_ctl(FOP_GET_PHYDEV_INFO,m_op_api->fop_api,0,0);
        // printf("-----curr_device= %d\n",tmp8);
        _FIL_HDL *f_h=(_FIL_HDL *)(m_op_api->fop_api->cur_lgdev_info->lg_hdl->file_hdl);
        FIL *pf=(FIL *)(f_h->hdl);
        // printf("pf->dir_info->fname %s\n",pf->dir_info.fname);
		
        music_file_info(m_op_api);//get_file_info

	
        music_ui.ui_curr_statu = (u32*)&m_op_api->dop_api->dec_api.phy_ops->status;
        music_ui.ui_curr_file = (u32)m_op_api->dop_api->file_num;
        music_ui.ui_total_file =m_op_api->fop_api->cur_lgdev_info->total_file_num;// (u32)file_operate_ctl(FOP_GET_TOTALFILE_NUM,m_op_api->fop_api,m_op_api->dop_api->file_type,0);
        music_ui.ui_curr_device = (u32)file_operate_ctl(FOP_GET_PHYDEV_INFO,m_op_api->fop_api,0,0);


        getting_music_info  = 0x50;

        if(curr_device != 0xff)
        {
            rcsp_report_status(RCSP_REPORT_MUSIC_FILEINFO);
        }
        else
        {
            rcsp_report_status(RCSP_REPORT_START_CONFIG);
        }

        if((dev_sel != DEV_SEL_CUR) && (tmp8 != curr_device))
        {
            curr_device = tmp8;
            // puts("send change_dev cmd\n");
        }
        rcsp_update_cur_device(curr_device);
        rcsp_set_task_status(STAUS_PLAY);
	dac_mute(0,1);


		
    }
    else
    {
        // printf("music_play_api fail!!!, 0x%x\n",err);
    }

///   music_file_info(m_op_api);//get_file_info

#if UI_ENABLE
    u8  last_device = music_ui.ui_curr_device;
    if((err != 0)&&(err != SUCC_MUSIC_START_DEC))
    {
	#ifndef SUPPORT_NO_SHOW_LOAD    
	         UI_menu(MENU_WAIT);
	 #endif
    }
    else
    {
        //get device
        music_ui.ui_curr_device = (u32)file_operate_ctl(FOP_GET_PHYDEV_INFO,m_op_api->fop_api,0,0);
        if((dev_sel != DEV_SEL_CUR) && (last_device != music_ui.ui_curr_device))
        {
            // puts("send change_dev cmd\n");
            Post_msg_to_rcsp_Task(MSG_RSCP_UPDATA_SPECIAL_STATE,(void*)(u32)STAUS_CHANGE_DEVIECE,0);
        }

        //music_file_info(m_op_api);//get_file_info

        music_ui.opt_state = MUSIC_OPT_BIT_PLAY;

       #if LED_8NUMS!=7		
		#if SUPPORT_VOICE_NUMBER
			if(input_number==0)
		#endif
	      UI_menu_mux(MENU_MUSIC_MAIN,MENU_LIST_DISPLAY);
	#endif		

    }
#endif
#ifdef support_pause_stop_mute_amp
    if(pause_mute_flag)
    {
        pa_umute();
        pause_mute_flag=0;
    }
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

       #if LED_8NUMS!=7
	#if SUPPORT_VOICE_NUMBER
		if(input_number==0)
	#endif
	       UI_menu(MENU_FILENUM);
	#endif	
	
#ifdef support_msg_stop_key
    play_stop_flag=0;
#endif
    return err;
}

/*----------------------------------------------------------------------------*/
/**@brief  Ê†πÊçÆÂÖ®Ë∑ØÂæÑÊí≠ÊîæÊñá‰ª∂
   @param  mapi -- Ëß£Á†ÅÊ®°ÂùóÊåáÈíà
   @return 0-ÊàêÂäü,Èùû0Â§±Ë¥•
   @note
*/
/*----------------------------------------------------------------------------*/
u32  music_play_by_path(MUSIC_OP_API *mapi)
#if 1//def SUPPORT_SD_USB_RECPLAY
{

#if REC_EN
{
    u32 err;
    const char path[]="/JL_REC/";
//    path="/folder1/abc.mp3";
//    path="/“Ù¿÷/";
#if 0//def support_no_play_recfile_in_music_mode
if(playrecfileflag)
{
	playrecfileflag=0;
	mapi->dop_api->file_num = rec_file_endcnt;
	err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_NEXT_FILE,&(mapi->dop_api->file_num));
}
else
{
	playrecfileflag=1;
	mapi->dop_api->file_num = rec_file_endcnt+1;
	err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
}
#endif

if(rec_play_sw)	
{
   rec_play_sw=0;
	
// 	play_mode = REPEAT_FOLDER;
// 	mapi->fop_api->fop_init->cur_play_mode = play_mode;
	
	mapi->dop_api->file_num = rec_file_endcnt+1;
//	err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
	err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
 	play_mode = REPEAT_ALL;
 	mapi->fop_api->fop_init->cur_play_mode = play_mode;
	
}

else
{

   rec_play_sw=1;
   
#if 0//def support_no_play_recfile_in_music_mode
	   playrecfileflag=0;
#endif
   //  path="/JL_REC/";
    mapi->fop_api->fop_init->filepath = (u8*)path;
  //  printf("file path : %s  \n",path);
    printf("mapi->dop_api->file_num : %d  \n",mapi->dop_api->file_num);
	

//	play_mode = REPEAT_FOLDER;
//	mapi->fop_api->fop_init->cur_play_mode = play_mode;
	mapi->dop_api->file_num = rec_file_endcnt;
//	err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
	err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));


//	play_mode = REPEAT_ONE;
//	play_mode = REPEAT_ALL;

#ifdef  SUPPORT_REC_PLAY_USE_ALL_MODE
	play_mode = REPEAT_ALL;
#else
	play_mode = REPEAT_FOLDER;
#endif
	mapi->fop_api->fop_init->cur_play_mode = play_mode;	


   #if  SUPPORT_ALL_VOICE	
	   #ifdef SUPPORT_SCG_VOICE
	 	 if(bVoiceOnoff)			
	     		{
	  	    		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PLAY_REC_FILE);
	     		}
	  	    else
	      		{
	  			os_taskq_post(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
	     		 }
	    #else
	    	if(IsVoiceEnable)
	    		{
	 	    		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PLAY_REC_FILE);
	    		}
	 	    else
	     		{
	 			os_taskq_post(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);
	    		 }
	    #endif				 
   #endif				 
		
}


    return err;
}

#else
    u32 err;
//    u8 *path;
    const char path[]="/folder1/abc.mp3";
//    path="/Èü≥‰πê/";
    mapi->fop_api->fop_init->filepath = (u8*)path;
//    printf("file path : %s  \n",path);
//    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_FILE_BYPATH,&(mapi->dop_api->file_num));
    err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_FILE_BYPATH,&(mapi->dop_api->file_num));
    return err;
#endif	
}
#else
{

#if REC_EN
{
    u32 err;
    const char path[]="/JL_REC/";
//    path="/folder1/abc.mp3";
//    path="/“Ù¿÷/";


// printf("-----music_play_by_path---rec_play_sw-- : %d  \n",rec_play_sw);


if(rec_play_sw)	
{
   rec_play_sw=0;
	
 	play_mode = REPEAT_FOLDER;
 	mapi->fop_api->fop_init->cur_play_mode = play_mode;
	
	mapi->dop_api->file_num = rec_file_endcnt+1;
	err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
 	play_mode = REPEAT_ALL;
 	mapi->fop_api->fop_init->cur_play_mode = play_mode;
	
#ifdef SUPPORT_PLAY_REC_FILE_FIRST_MUTE_AMP
	pa_umute();
	dac_mute(0,1);
#endif
	
}

else
{
   rec_play_sw=1;
  //   path="/JL_REC/";
    mapi->fop_api->fop_init->filepath = (u8*)path;
    // printf("file path : %s  \n",path);
    // printf("mapi->dop_api->file_num : %d  \n",mapi->dop_api->file_num);
	

	play_mode = REPEAT_FOLDER;
	mapi->fop_api->fop_init->cur_play_mode = play_mode;
	mapi->dop_api->file_num = rec_file_endcnt;
	err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));

#ifndef SUPPORT_REC_PLAY_USE_FOLDER_MODE
	play_mode = REPEAT_FOLDER;
	mapi->fop_api->fop_init->cur_play_mode = play_mode;
#endif
	
#ifdef SUPPORT_PLAY_REC_FILE_FIRST_MUTE_AMP
	pa_umute();
	dac_mute(0,1);
#endif
	
   #if  SUPPORT_ALL_VOICE			
   	if(IsVoiceEnable)
   		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PLAY_REC_FILE);									
   #endif				 
		
}


    return err;
}

#else
    u32 err;
//    u8 *path;
    const char path[]="/folder1/abc.mp3";
//    path="/Èü≥‰πê/";
    mapi->fop_api->fop_init->filepath = (u8*)path;
//    // printf("file path : %s  \n",path);
//    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_FILE_BYPATH,&(mapi->dop_api->file_num));
    err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_FILE_BYPATH,&(mapi->dop_api->file_num));
    return err;
#endif	
}

#endif

/*----------------------------------------------------------------------------*/
/**@brief  Ê†πÊçÆÁõÆÂΩïÊí≠ÊîæÊñá‰ª∂
   @param  mapi -- Ëß£Á†ÅÊ®°ÂùóÊåáÈíà
   @return 0-ÊàêÂäü,Èùû0Â§±Ë¥•
   @note
*/
/*----------------------------------------------------------------------------*/
u32  music_play_by_folder(MUSIC_OP_API *mapi)
{
    u32 err;
    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_PRE_FOLDER,&(mapi->dop_api->file_num));
    return err;
}

/*----------------------------------------------------------------------------*/
/**@brief  Ê†πÊçÆÊñá‰ª∂È¶ñÁ∞áÊí≠ÊîæÊñá‰ª∂
   @param  mapi -- Ëß£Á†ÅÊ®°ÂùóÊåáÈíàÔºåsclust-Êñá‰ª∂È¶ñÁ∞á
   @return 0-ÊàêÂäü,Èùû0Â§±Ë¥•
   @note
*/
/*----------------------------------------------------------------------------*/
u32 music_play_by_sclust(MUSIC_OP_API *mapi,u32 sclust)
{
    u32 err;
    mapi->fop_api->fop_init->filesclust = sclust;
    err = music_play_api(mapi,DEV_SEL_CUR,0,FOP_OPEN_FILE_BYSCLUCT,&(mapi->dop_api->file_num));
//    // printf("mapi->dop_api->file_num = %d\n",mapi->dop_api->file_num);
    return err;
}

extern void *file_operate_get_next_phydev();
DEV_HANDLE music_next_dev_type(void)
{
    DEV_HANDLE next_dev_hl;
    next_dev_hl = (DEV_HANDLE)file_operate_get_next_phydev();
    if(next_dev_hl == usb)
    {
        // puts("next_dev:usb\n");
    }
    else if(next_dev_hl == sd0)
    {
        // puts("next_dev:sd\n");
    }
    else
    {
        // puts("next_dev:NULL\n");
    }
    return next_dev_hl;
}

//---------------customer  add------------------

#ifdef SUPPORT_STORY_MACHINE

u32  music_play_by_path_dir(MUSIC_OP_API *mapi,u8 dir)
//u32  music_play_by_path_dir(MUSIC_OP_API *mapi)
{

u32 err;
u8 bDirNum;
#if 1

//const char path[]="/π≈µ‰¿÷";

//const char path[]="/π˙—ß/";
		

//mapi->fop_api->fop_init->filepath = (u8*)path;

const char path[][7]=
{
"/π≈µ‰¿÷/",
"/π˙—ß/",
"/Œ˜¿÷/",
"/“Ù¿÷/",
"/π  ¬/",
"/∂˘∏Ë/",
"/∞Ÿø∆/",
"/Ã•ΩÃ/",
"/∏˙∂¡/",
};

mapi->fop_api->fop_init->filepath = (u8*)path[dir];


#else
const char path[][7]=
{
"/π≈µ‰¿÷",
"/π˙—ß",
"/Œ˜¿÷",
"/“Ù¿÷",
"/π  ¬",
"/∂˘∏Ë",
"/∞Ÿø∆",
"/Ã•ΩÃ",
"/∏˙∂¡",
};

mapi->fop_api->fop_init->filepath = (u8*)path[dir];

const char path[]="/π≈µ‰¿÷";	
const char      	path[]="/π˙—ß";	
const char      	path[]="/Œ˜¿÷";	
const char      	path[]="/“Ù¿÷";	
const char      	path[]="/π  ¬";	
const char      	path[]="/∂˘∏Ë";			
const char      	path[]="/∞Ÿø∆";			
const char      	path[]="/Ã•ΩÃ";		
const char      	path[]="/∏˙∂¡";	

	bDirNum=dir;
switch(bDirNum)
{
	case 0:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;
	
	case 1:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;
	
	case 2:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;
	
	case 3:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;
	
	case 4:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;
	
	case 5:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;
	
	case 6:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;
	
	case 7:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;

	case 8:
    mapi->fop_api->fop_init->filepath = (u8*)path;
	break;		
	
}
#endif


    err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_FILE_BYPATH,&(mapi->dop_api->file_num));
	
	play_mode = REPEAT_FOLDER;
	mapi->fop_api->fop_init->cur_play_mode = play_mode;

    return err;


}

#endif

//---------------customer  add------------------

/*----------------------------------------------------------------------------*/
/**@brief  music ‰∏ªÁ∫øÁ®ã
   @param  p -- ËæìÂÖ•ÂèÇÊï∞
   @return void
   @note
*/
/*----------------------------------------------------------------------------*/
static void music_task(void *p)
{
    MUSIC_OP_API *mapi=NULL;
    tbool psel_enable = 0;
    u32 err,half_sec_count =0;
    tbool enable = 1;
    tbool file_auto_next = 1;
    volatile u16 wait_exit=0;
    volatile u16 wait_ok=0;
    int msg[6];
    static u32 play_time;

    music_reverb = NULL;

#ifdef support_amP_ab_d
    Set_amp_ab_d_out() ;
    Set_AMP_IS_D();
#endif
    workmode=MUSIC_WORK_MODE;

#ifdef SUPPORT_VM_WORK_MODE
	vm_write_api(VM_WORK_MODE,&workmode);
#endif

#if  SUPPORT_ALL_VOICE
	music_prompt_stopped=1;
#endif


    // puts("\n************************music TASK********************\n");
#if REC_EN
#ifdef support_only_rec_key_to_rec_mode
    muisc_to_rec_flag=0;
#endif 
#endif

#ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE
 bMusicFirstInFlag=1;
#endif

#if MUSIC_DECRYPT_EN
    cipher_init(0X20140606);
#endif // MUSIC_DECRYPT_EN

#if EQ_EN
    eq_enable();
#endif // EQ_EN

    led_fre_set(15,0);

    //os_taskq_post_msg("MusicTask",1,SYS_EVENT_PLAY_SEL_END);
//   music_prompt_flag = PROMPT_STATUS_PLAY;
//   music_prompt_stopped = 1;

//  printf("---start---curr_device_using--------- =%d\n",curr_device_using);


 #ifdef SUPPORT_OFF_MODE_VOICE
 	os_taskq_post_msg(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);


#elif defined SUPPORT_SCG_VOICE	
	if(bVoiceOnoff==1)	
		{	 

			 #ifdef SUPPORT_RECPLAY_VOICE
			 if(play_rec_last_file)		 	
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_RECPLAY_MP3); //line inÃ· æ“Ù≤•∑≈		 	
			 else
			#endif 		
		 	if(sd0==curr_device_using)
			 	psel_enable = tone_play_by_name("MusicTask", 1,BPF_MUSIC_SD_MP3); //line inÃ· æ“Ù≤•∑≈
		 	else   if(curr_device_using == usb)
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_USB_MP3); //line inÃ· æ“Ù≤•∑≈	    
		}
	else if(bVoiceOnoff==0)
	 		os_taskq_post_msg(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);	



#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	

		if(bModeVoiceSelVal==2)				
		{	 
			 #ifdef SUPPORT_RECPLAY_VOICE
			 if(play_rec_last_file)		 	
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_RECPLAY_EN_MP3); //line inÃ· æ“Ù≤•∑≈		 	
			 else
			#endif 		
		 	if(sd0==curr_device_using)
			 	psel_enable = tone_play_by_name("MusicTask", 1,BPF_MUSIC_SD_EN_MP3); //line inÃ· æ“Ù≤•∑≈
		 	else   if(curr_device_using == usb)
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_USB_EN_MP3); //line inÃ· æ“Ù≤•∑≈	    
		}
		else	if(bModeVoiceSelVal)
		{	 

			 #ifdef SUPPORT_RECPLAY_VOICE
			 if(play_rec_last_file)		 	
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_RECPLAY_MP3); //line inÃ· æ“Ù≤•∑≈		 	
			 else
			#endif 		
		 	if(sd0==curr_device_using)
			 	psel_enable = tone_play_by_name("MusicTask", 1,BPF_MUSIC_SD_MP3); //line inÃ· æ“Ù≤•∑≈
		 	else   if(curr_device_using == usb)
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_USB_MP3); //line inÃ· æ“Ù≤•∑≈	    
		}
		else
	 		os_taskq_post_msg(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);	

#elif defined SUPPORT_SCG_VOICE	
		if(bVoiceOnoff)				
		{	 
			 #ifdef SUPPORT_RECPLAY_VOICE
	 			 if(play_rec_last_file)		 	
	 			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_RECPLAY_EN_MP3); //line inÃ· æ“Ù≤•∑≈		 	
	 			 else
			#endif 		
	 		 	if(sd0==curr_device_using)
	 			 	psel_enable = tone_play_by_name("MusicTask", 1,BPF_MUSIC_SD_EN_MP3); //line inÃ· æ“Ù≤•∑≈
	 		 	else   if(curr_device_using == usb)
	 			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_USB_EN_MP3); //line inÃ· æ“Ù≤•∑≈	    
		}
		else
	 		os_taskq_post_msg(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);	

	
#elif  SUPPORT_ALL_VOICE

	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		if(IsVoiceEnable==2)				
		{	 
			 #ifdef SUPPORT_RECPLAY_VOICE
			 if(play_rec_last_file)		 	
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_RECPLAY_EN_MP3); //line inÃ· æ“Ù≤•∑≈		 	
			 else
			#endif 		
		 	if(sd0==curr_device_using)
			 	psel_enable = tone_play_by_name("MusicTask", 1,BPF_MUSIC_SD_EN_MP3); //line inÃ· æ“Ù≤•∑≈
		 	else   if(curr_device_using == usb)
			 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_USB_EN_MP3); //line inÃ· æ“Ù≤•∑≈	    
		}
		else				
	#endif		 						            	

	if(IsVoiceEnable)
	{	 

		 #ifdef SUPPORT_RECPLAY_VOICE
		 if(play_rec_last_file)		 	
		 	psel_enable = tone_play_by_name("MusicTask",1, BPF_RECPLAY_MP3); //line inÃ· æ“Ù≤•∑≈		 	
		 else
		#endif 		
	 	if(sd0==curr_device_using)
		 	psel_enable = tone_play_by_name("MusicTask", 1,BPF_MUSIC_SD_MP3); //line inÃ· æ“Ù≤•∑≈
	 	else   if(curr_device_using == usb)
		 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_USB_MP3); //line inÃ· æ“Ù≤•∑≈	    
	}
	else
 		os_taskq_post_msg(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);		

#elif defined SUPPORT_MODE_VOICE_ONOFF	

	if(bModeVoiceOnoffFlag)
	{	 
  		   psel_enable = tone_play_by_name("MusicTask", 1, BPF_MUSIC_MP3);
	}
	else
 		os_taskq_post_msg(MUSIC_TASK_NAME, 1, SYS_EVENT_PLAY_SEL_END);

#elif defined SUPPORT_DOUBLE_MODE_VOICE	

	if(bModeVoiceSelFlag)
	{	 
  		   psel_enable = tone_play_by_name("MusicTask", 1, BPF_MUSIC_MP3);
	}
	else
  		   psel_enable = tone_play_by_name("MusicTask", 1, BPF_MUSIC_EN_MP3);
	
 #else
 
 	 #if MEDIA_MODE_USB_SD_DETECT
		 #ifdef SUPPORT_RECPLAY_VOICE
		 if(play_rec_last_file)		 	
		 	psel_enable = tone_play_by_name("MusicTask",1, BPF_RECPLAY_MP3); //line inÃ· æ“Ù≤•∑≈		 	
		 else
		#endif 	
								
		 #if SDMMC0_EN
		 	if(sd0==curr_device_using)
		 #elif SDMMC1_EN
		 	if(sd1==curr_device_using)
		 #endif		 			 
		 	//						music_prompt_play(mapi,BPF_MUSIC_SD_MP3,MSG_MUSIC_PLAY);				
		 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_SD_MP3); //line inÃ· æ“Ù≤•∑≈
		 else   if(curr_device_using == usb)
		 	//						music_prompt_play(mapi,BPF_MUSIC_USB_MP3,MSG_MUSIC_PLAY);	
		 	psel_enable = tone_play_by_name("MusicTask",1, BPF_MUSIC_USB_MP3); //line inÃ· æ“Ù≤•∑≈
		 
		 else
	 #endif					
	 
  	   psel_enable = tone_play_by_name("MusicTask", 1, BPF_MUSIC_MP3);
	 
 #endif

    //dec_phy_printf("---music psel_enable %d \r\n",psel_enable);

    music_decoder_init(&mapi);
    music_decoder_info(before_decoder_callback, after_decoder_callback);

#if LRC_LYRICS_EN
    lrc_init();
#endif

    curr_device = 0xff;

    while(1)
    {
        memset(msg,0x00,sizeof(msg));
        os_taskq_pend(0, ARRAY_SIZE(msg), msg);
        if(msg[0] != MSG_HALF_SECOND)
        {
   //         // printf("\nmusic_msg= 0x%x\n",msg[0]);
        }

        clear_wdt();
        ////dec_phy_printf("---------music msg %x \r\n",msg[0]);
        err = 0;
        if ( (!enable) && (SYS_EVENT_DEL_TASK != msg[0]))
        {
            continue;
        }
        if(psel_enable)
        {
            switch(msg[0])
            {
            case SYS_EVENT_PLAY_SEL_END:
            case SYS_EVENT_BEGIN_DEC:
            case MSG_MUSIC_NEXT_FILE:
            case MSG_MUSIC_PREV_FILE:
            case MSG_MUSIC_PP:
            case MSG_MUSIC_PLAY:
            case MSG_MUSIC_PAUSE:
                msg[0] = SYS_EVENT_PLAY_SEL_END;
            case SYS_EVENT_DEL_TASK: 				//ËØ∑Ê±ÇÂà†Èô§music‰ªªÂä°
            #ifdef SUPPORT_MUSIC_RANDOM_KEY
			case MSG_MUSIC_RANDOM_PLAY:
            #endif
            
                // puts("\n----play_sel_stop------\n");
                play_sel_stop();
                psel_enable = 0;
                break;
            default:
                msg[0] = NO_MSG;
                break;
            }
        }

        mapi->dop_api->dec_api.save_brk = 0;
        lg_dev_info *tmplgdev;
        if(wait_exit)
        {
            ///<ËøõÂÖ•Âà†Èô§Áä∂ÊÄÅÔºå‰∏çÂÜçÂìçÂ∫îÂÖ∂‰ªñÊ∂àÊÅØ
            if(wait_ok)
            {
                err = os_taskq_post(MAIN_TASK_NAME, 1, MSG_CHANGE_WORKMODE);
                if(err == OS_NO_ERR)
                {
                    wait_ok = 0;
                }
            }
            if(msg[0]!=SYS_EVENT_DEL_TASK)
            {
                //dec_phy_printf("msg ddddd %08x \r\n",msg[0]);
                continue;
            }
        }
        switch(msg[0])
        {
        
        case SYS_EVENT_PLAY_SEL_END:
            //dec_phy_printf("notic music end \r\n");
            if(music_prompt_break)
            {
                // puts("music_prompt_break\n");
                music_prompt_break = 0;
                break;
            }

	 #ifdef LED_SHOW_DEVICE_PLUGIN	
	 	UI_menu(MENU_DEVICE);
	 	os_time_dly(10);
	 #endif
	 
	 	os_time_dly(10);

	 #ifdef SUPPORT_MODE_MAX_VOL_SINGLE_ADJUST
	 	set_max_dac_vol(MP3_ANALOG_VOL_MAX_L, MP3_ANALOG_VOL_MAX_R, MP3_DIGITAL_VOL_MAX_L,MP3_DIGITAL_VOL_MAX_R);
	 #endif

	    #if NOTICE_VOICE_VOL_DEFAULT
		    set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_ON);
	    #endif
	 #ifdef LED_SHOW_VOL_MAX
	  	 #if defined AUX_VOL_MAX	  	 
	  	 	dac_ctl.sys_vol_l=bVolMaxChangeToSmallVolMax;
	  	 	dac_ctl.sys_vol_r=dac_ctl.sys_vol_l;	  		
	  		set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_ON);
		#elif defined MP3_VOL_MAX
	  	 	if(dac_ctl.sys_vol_l>25)    
	  	 	dac_ctl.sys_vol_l=25;
	  	 	dac_ctl.sys_vol_r=dac_ctl.sys_vol_l;	  	
	  		set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_ON);		
	  	 #endif
	 #endif
		
            dac_channel_on(MUSIC_CHANNEL, FADE_ON);
//                SET_UI_MAIN(MENU_MUSIC_MAIN);
//                UI_menu(MENU_WAIT);
            music_ui.mapi = mapi;
	#if SUPPORT_VOICE_NUMBER
		if(input_number==0)
	#endif
            ui_open_music(&music_ui, sizeof(MUSIC_DIS_VAR));


        case SYS_EVENT_BEGIN_DEC:
            mapi->dop_api->dec_api.save_brk = 0;

//            printf("111111111111111 curr_device_using--%d\n",curr_device_using);
			
		 #ifdef MUSIC_PROMPT_EN
		 
		 	 #if defined(support_rec_stop_to_music)		
		 	 		 if(play_rec_last_file)
		 	 		  {
		 	 
		 	 			 #if REC_EN
		 	 			 	 rec_play_sw=1;;
		 	 			 #endif
		 				 
		 	 			os_time_dly(10);
		 	 			  
		 	 		  /*∆Êπ÷µƒµ˜”√’‚∏ˆ ≤ªµ˜”√ ∫Û√Ê’‚∏ˆ≤ª∆◊˜”√ Œ˚Œ˚*/
		 	 				err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
		 	 				
		 	 				  play_rec_last_file=0; 			  
		 	 				  mapi->dop_api->file_num = rec_file_endcnt; 
		 	 				 err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
		 	 
		 	 		 		 #ifdef SUPPORT_REC_PLAY_USE_FOLDER_MODE
		 	 		 			rec_play_sw=1;
		 	 		 		 	play_mode = REPEAT_FOLDER;
		 	 		 		 	mapi->fop_api->fop_init->cur_play_mode = play_mode;
		 	 		 		 #endif
		 	 				 
		 	 			   //	mapi->dop_api->file_num = 1;
		 	 			  //  err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_LAST_FILE,&(mapi->dop_api->file_num));		  
		 	 		  ////		err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_LAST_FILE,&(mapi->dop_api->file_num));
		 	 		  }	
		 	 	 #if  MEDIA_MODE_USB_SD_DETECT	
		 	 		else
		 	 		{
		 	 	 		 #ifdef SUPPORT_MUSIC_PREV_NEXT_VOICE
		 	 	 		         if(IsMusicPrevBegin)
		 	 	 		 	    {
		 	 	 		 	       IsMusicPrevBegin=0;
								   #if  SUPPORT_ALL_VOICE
			 	 	 				 music_prompt_stopped = 1;
								   #endif
		 	 	 		 		os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_PREV_FILE);
										 	 	 				
		 	 	 		 	    }
		 	 	 		 	    else if(IsMusicNextBegin)
		 	 	 		 	    {
		 	 	 		 		     	IsMusicNextBegin = 0;
								   #if  SUPPORT_ALL_VOICE
			 	 	 				 music_prompt_stopped = 1;
								   #endif
		 	 	 		 			os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_NEXT_FILE);						
		 	 	 		 	    	}
		 	 	 		 	else
		 	 	 		 #endif		
		 	 				 
		 	 		           if(prompt_play_end())
		 	 		            {

	 						 #ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE
	 							 if(bMusicFirstInFlag)
	 							 	{
	 							 		if((file_operate_get_total_phydev()>1))
	 							 			{
												curr_device_using = (u32)usb;
	 							 			}
	 								 	bMusicFirstInFlag=0;
	 									err = music_play_api(mapi,DEV_SEL_SPEC,(u32)usb,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
	 							 	}
	 								else
	 						 #endif

		 	 		                err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
		 	 		            }
		 	 		            else
		 	 		            {
		 	 		                break;
		 	 		            }
		 	 			}
		 	 		
		 	 	  #else			 
		 	 	         else  if(prompt_play_end())
		 	 	            {
		 	 	            
		 	 	                err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
		 	 	            }
		 	 	            else
		 	 	            {
		 	 	                break;
		 	 	            }
		 	 	#endif				
		 	 #else
		 	             if(prompt_play_end())
		 	             {
		 	                 err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
		 	             }
		 	             else
		 	             {
		 	                 break;
		 	             }
		 	 #endif	
		 
		 #elif defined(support_rec_stop_to_music)
		 
		    if(play_rec_last_file)
		    	{
		 
		 
		 	 	os_time_dly(10);
		 
		 	 #ifdef   support_rec_line_fm_rec_return_line_fm
		 	 #else 
		 	    	    play_rec_last_file=0;		  	  	
		 	 #endif 
		 
		 	/*∆Êπ÷µƒµ˜”√’‚∏ˆ ≤ªµ˜”√ ∫Û√Ê’‚∏ˆ≤ª∆◊˜”√ Œ˚Œ˚*/
		 		  err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
		 	 
		 		mapi->dop_api->file_num = rec_file_endcnt; 
		 	       err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
		 
		 		 #ifdef SUPPORT_REC_PLAY_USE_FOLDER_MODE
		 			rec_play_sw=1;
		 		 	play_mode = REPEAT_FOLDER;
		 		 	mapi->fop_api->fop_init->cur_play_mode = play_mode;
				#elif defined 	SUPPORT_REC_PLAY_USE_ALL_MODE
		 			rec_play_sw=1;
		 		 	play_mode = REPEAT_ALL;
		 		 	mapi->fop_api->fop_init->cur_play_mode = play_mode;				
		 		 #endif
		 	   
		      //   mapi->dop_api->file_num = 1;
		 	//  err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_LAST_FILE,&(mapi->dop_api->file_num));	  	
		         ////      err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_LAST_FILE,&(mapi->dop_api->file_num));
		 		 
		         
		    	}
		    else
		             err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
		 
		 #else
		             // puts("************************************************\n");
		             // printf("total_dev:%d\n",file_operate_get_total_lgdev());
		             // printf("usb:%d\n",dev_get_online_status(usb));
		             // printf("sd:%d\n",dev_get_online_status(sd0));
		             err = music_play_api(mapi,DEV_SEL_SPEC,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
		 #endif

            rcsp_set_music_bs_op_api(mapi);

            break;
        case SYS_EVENT_DEC_SET_END:
            // puts("----SYS_EVENT_DEC_SET_END---\n");
            rcsp_report_status(RCSP_REPORT_MUSIC_PLAYTIME);
            break;

        case SYS_EVENT_DEC_FR_END:
        case SYS_EVENT_DEC_FF_END:
        case SYS_EVENT_DEC_END:
			
	#ifdef support_rec_line_fm_rec_return_line_fm
			if(play_rec_last_file==2)   //FM
			{
			play_rec_last_file=0;
			os_taskq_post("MainTask", 1, MSG_FM_MODE_KEY);
			}
			else if ( play_rec_last_file==3)  //line 
			{
			   os_taskq_post("MainTask", 1, MSG_LINE_MODE_KEY);
			play_rec_last_file=0;

			}
			else 		
				play_rec_last_file=0;
     #endif 

	 #ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE

 //	  printf("--SYS_EVENT_DEC_END----curr_device_using----1----- =%d\n",curr_device_using);
 //	  printf("--SYS_EVENT_DEC_END----music_ui.ui_curr_file---1------ =%d\n",music_ui.ui_curr_file);
	 
	 #if 1
	 	if((file_operate_get_total_phydev()>1)&&((music_ui.ui_curr_file == mapi->fop_api->cur_lgdev_info->total_file_num)&&(music_ui.ui_curr_file !=0)))
	 		{
				 #if SDMMC0_EN
				 	if(sd0==curr_device_using)
				 #elif SDMMC1_EN
				 	if(sd1==curr_device_using)
				 #endif		 			 
	 	                {
	 	                    curr_device_using = (u32)usb;
	 	                }
	 	                else
	 	                {
		 	                #if SDMMC0_EN
		 	                    curr_device_using = (u32)sd0;
					  #elif SDMMC1_EN
		 	                    curr_device_using = (u32)sd1;
					  #endif
	 	                }
	 		}
 //	  printf("--SYS_EVENT_DEC_END----curr_device_using--2------- =%d\n",curr_device_using);
		
 //	  printf("--SYS_EVENT_DEC_END----music_ui.ui_curr_file---2------ =%d\n",music_ui.ui_curr_file);
		
	 #endif
	 #endif
			
            // puts("----SYS_EVENT_DEC_FR_END---\n");
            rcsp_report_status(RCSP_REPORT_MUSIC_PLAYTIME);



							
            //dec_phy_printf("decoder stop\r\n");
            err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_AUTO_NEXT,&(mapi->dop_api->file_num));
            break;

        case SYS_EVENT_DEV_OFFLINE:

			
            //dec_phy_printf("music SYS_EVENT_DEV_OFFLINE\n");
            tmplgdev = mapi->fop_api->cur_lgdev_info;
            if(tmplgdev)
            {
                if(tmplgdev->lg_hdl->phydev_item == (void *)msg[1])
                {
                    UI_menu(MENU_MUSIC_MAIN);
                    if((!mapi->dop_api->dec_api.phy_ops) || (DECODER_PAUSE != mapi->dop_api->dec_api.phy_ops->status))
                    {
                        ///< Ëß£Á†ÅËÆæÂ§áÈùûÊöÇÂÅúÁä∂ÊÄÅÔºåÊúâËß£Á†ÅËá™Â∑±Êä•Èîô
                        break;
                    }///elseÁöÑËß£Á†ÅÊöÇÂÅúÁä∂ÊÄÅÔºåÊúâ‰∏ã‰∏Ä‰∏™Ê∂àÊÅØSYS_EVENT_DEC_DEVICE_ERRÂ§ÑÁêÜ
                }
                else
                {
                    ///<ÈùûËß£Á†ÅËÆæÂ§á
                    UI_menu(MENU_MUSIC_MAIN);
                    break;
                }
            }
            else
                break;
			
        case SYS_EVENT_DEC_DEVICE_ERR:
            // puts("********sys device err*********\n");
            mapi->dop_api->dec_api.save_brk = 1;
            mapi->dop_api->file_num = 1;
           //  music_next_dev_type();

		#if MEDIA_MODE_USB_SD_DETECT	
	 	   if(file_operate_get_total_phydev()>=1)	
	 	   	{

			#if  SUPPORT_ALL_VOICE	
			  	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
			  		if(IsVoiceEnable==2)				
			  		{
						 #if SDMMC0_EN
						 	if(sd0==curr_device_using)
						 #elif SDMMC1_EN
						 	if(sd1==curr_device_using)
						 #endif		 			 
			 	                {
			 	                    curr_device_using = (u32)usb;
			 	                }
			 	                else
			 	                {
				 	                #if SDMMC0_EN
				 	                    curr_device_using = (u32)sd0;
							  #elif SDMMC1_EN
				 	                    curr_device_using = (u32)sd1;
							  #endif
			 	                }
				 			if((sd0==curr_device_using)||(sd1==curr_device_using))
			 			 		music_prompt_play(mapi,BPF_MUSIC_SD_EN_MP3,0xff);				
			 			 	else   if(usb==curr_device_using)
			 			 		music_prompt_play(mapi,BPF_MUSIC_USB_EN_MP3,0xff);	
	    				 }
			  		else				
			  	#endif		 						            	

			#elif defined SUPPORT_SCG_VOICE	
				if(bVoiceOnoff)		
			 	{
  	 			 #if SDMMC0_EN
  	 			 	if(sd0==curr_device_using)
  	 			 #elif SDMMC1_EN
  	 			 	if(sd1==curr_device_using)
  	 			 #endif		 			 
	 			 	{
	 			 	    curr_device_using = (u32)usb;
	 			 	}
			 		else
	 			 	{
	 			 	    	#if SDMMC0_EN
	 			 	        	curr_device_using = (u32)sd0;
	 			 		#elif SDMMC1_EN
	 			 	        	curr_device_using = (u32)sd1;
	 			 		#endif
	 			 	}
			 		if((sd0==curr_device_using)||(sd1==curr_device_using))
			 			music_prompt_play(mapi,BPF_MUSIC_SD_EN_MP3,0xff);				
			 		else   if(usb==curr_device_using)
			 			music_prompt_play(mapi,BPF_MUSIC_USB_EN_MP3,0xff);	
			 	}

		    	///		 if(IsVoiceEnable)
			
			 #elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
	    			 if(IsVoiceEnable)
			  		if(bModeVoiceSelVal==2)				
			  		{
						 #if SDMMC0_EN
						 	if(sd0==curr_device_using)
						 #elif SDMMC1_EN
						 	if(sd1==curr_device_using)
						 #endif		 			 
			 	                {
			 	                    curr_device_using = (u32)usb;
			 	                }
			 	                else
			 	                {
				 	                #if SDMMC0_EN
				 	                    curr_device_using = (u32)sd0;
							  #elif SDMMC1_EN
				 	                    curr_device_using = (u32)sd1;
							  #endif
			 	                }
				 			if((sd0==curr_device_using)||(sd1==curr_device_using))
			 			 		music_prompt_play(mapi,BPF_MUSIC_SD_EN_MP3,0xff);				
			 			 	else   if(usb==curr_device_using)
			 			 		music_prompt_play(mapi,BPF_MUSIC_USB_EN_MP3,0xff);	
	    				 }
			  		else	 if(bModeVoiceSelVal)

			#endif								
	    			 {
					 #if SDMMC0_EN
					 	if(sd0==curr_device_using)
					 #elif SDMMC1_EN
					 	if(sd1==curr_device_using)
					 #endif		 			 
		 	                {
		 	                    curr_device_using = (u32)usb;
		 	                }
		 	                else
		 	                {
			 	                #if SDMMC0_EN
			 	                    curr_device_using = (u32)sd0;
						  #elif SDMMC1_EN
			 	                    curr_device_using = (u32)sd1;
						  #endif
		 	                }
						 #if SDMMC0_EN
						 	if(sd0==curr_device_using)
						 #elif SDMMC1_EN
						 	if(sd1==curr_device_using)
						 #endif		 			 
		 			 		music_prompt_play(mapi,BPF_MUSIC_SD_MP3,0xff);				
		 			 //	psel_enable = tone_play_by_name("MusicTask", BPF_MUSIC_SD_MP3); //line inÃ· æ“Ù≤•∑≈
		 			 	else   if(usb==curr_device_using)
		 			 		music_prompt_play(mapi,BPF_MUSIC_USB_MP3,0xff);	
	    			 }
 		   }
	 	 //	psel_enable = tone_play_by_name("MusicTask", BPF_MUSIC_USB_MP3); //line inÃ· æ“Ù≤•∑≈
//	 	 	break;
	 	 #endif								
			
            err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
            break;


#ifdef SUPPORT_MUSIC_PREV_NEXT_VOICE

		case MSG_MUSIC_PREV_VOICE:		

		    if(bPrevNextVoiceFlag)
				break;
			
		 	#if defined SUPPORT_PP_PREV_NEXT_VOICE
	 			if(bModeVoiceSelVal)		 
		 	#else  
	 			if(IsVoiceEnable)
		 	#endif
	        	{
				bPrevNextVoiceFlag=4;
        			IsMusicPrevBegin = 1;
	        		IsMusicNextBegin = 0;
		 		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PREV_FILE);									
	        	}
	        	else
	        	{
				os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_PREV_FILE);
	        	}
				
        	break;

		
		case MSG_MUSIC_NEXT_VOICE:

		    if(bPrevNextVoiceFlag)
			break;
			
		 	#if defined SUPPORT_PP_PREV_NEXT_VOICE
	 			if(bModeVoiceSelVal)		 
		 	#else  
	 			if(IsVoiceEnable)
		 	#endif
	        	{
			      bPrevNextVoiceFlag=4;	        	
	        		IsMusicNextBegin = 1;
	        		IsMusicPrevBegin = 0;
		 		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_NEXT_FILE);					
	        	}
	        	else
	        	{
				os_taskq_post_msg("MusicTask", 1, MSG_MUSIC_NEXT_FILE);
	        	}
		break;		
#endif

            #ifdef SUPPORT_MUSIC_FOLDER_OPERATION
            case MSG_FOLDER_PREV:               
			   err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_PRE_FOLDER,&(mapi->dop_api->file_num));
//			   UI_menu(MENU_PREV_FOLDER);
			   os_time_dly(2);
               break;
			case MSG_FOLDER_NEXT:
			   err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_NEXT_FOLDER,&(mapi->dop_api->file_num));
//			   UI_menu(MENU_NEXT_FOLDER);
			   os_time_dly(2);
			   break;
			case MSG_FOLDER_REPEAT:			  
			   if(mapi && mapi->fop_api && mapi->fop_api->fop_init)
			   {		
			       if((play_mode!=REPEAT_FOLDER) && (play_mode!=REPEAT_ALL))
			       	play_mode=REPEAT_FOLDER;	
			       else if(play_mode==REPEAT_FOLDER)
			       	play_mode=REPEAT_ALL;
			       else if(play_mode==REPEAT_ALL)
			       	play_mode=REPEAT_FOLDER;
				   	mapi->fop_api->fop_init->cur_play_mode = play_mode;
			   }
		             rcsp_report_status(RCSP_REPORT_PLAYMODE_VALUE);
			 
			 #if LCD_SUPPORT_MENU
			             UI_menu(MENU_REFRESH);
			 #else
			             UI_menu_arg(MENU_SET_PLAY_MODE,play_mode);
			 #endif

			   break;
            #endif
			
        case MSG_MUSIC_NEXT_FILE:

               #ifdef TEST_PANEL_LED
	               bledGridValue++;
	               if(bledGridValue>LED_8GRIDS)
	               bledGridValue=0;

		 	  printf("bledGridValue =%x %x \n",bledComValue,bledGridValue);
			break;
	        #endif

			
		dac_mute(1,1);
            file_auto_next = 1;

	 	 #ifdef SUPPORT_FLASH_CHAR
	 	 	LED_FLASH_CHAR=0;
	 	 	LED_FLASH_ICON=0;			  
	 	 #endif	
		 
		 #ifdef support_mute_led_all_flish
		     mute_flag=0;
		 #endif
			
	   if(play_mode == REPEAT_ALL)   			
	             led_fre_set(15,0);
	   else if(play_mode == REPEAT_ONE)
	             led_fre_set(7,0);

	  	 #ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE
	  	 	bMediaErro=1;
	  	 #endif
	   
            //dec_phy_printf("KEY_EVENT_NEXT\r\n");
            err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_NEXT_FILE,&(mapi->dop_api->file_num));

		#if  SUPPORT_ALL_VOICE		
			#ifdef SUPPORT_SCG_VOICE
	 			if(bVoiceOnoff==1)	
	 			{
	 		 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
	 			}
			#endif

		
		#if SUPPORT_TY_VOICE==1
   			 if(IsVoiceEnable)
    			 {
		 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
    			 }
		#endif					
		#endif					

//                err=music_play_by_path(mapi);
//                err=music_play_by_folder(mapi);
            break;


        case MSG_MUSIC_PREV_FILE:
            #ifdef TEST_PANEL_LED
	                if(bledGridValue)
					bledGridValue--;					
			 	  printf("bledGridValue =%x %x \n",bledComValue,bledGridValue);
			break;
              #endif

	  	 #ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE
	  	 	bMediaErro=2;
	  	 #endif
			
		dac_mute(1,1);			
            file_auto_next = 0;
	   if(play_mode == REPEAT_ALL)   			
	             led_fre_set(15,0);
	   else if(play_mode == REPEAT_ONE)
	             led_fre_set(7,0);

		 #ifdef SUPPORT_FLASH_CHAR
		 	LED_FLASH_CHAR=0;
		 	LED_FLASH_ICON=0;			  
		 #endif		
		 
	 #ifdef support_mute_led_all_flish
	     mute_flag=0;
	 #endif
	   
            //dec_phy_printf("KEY_EVENT_PREV\r\n");
            err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_PREV_FILE,&(mapi->dop_api->file_num));

		#if  SUPPORT_ALL_VOICE	
			#ifdef SUPPORT_SCG_VOICE
	 			if(bVoiceOnoff==1)	
	 			{
	 		 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
	 			}
			#endif

		
		#if SUPPORT_TY_VOICE==1

    			 if(IsVoiceEnable)
    			 {
		 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
    			 }
		#endif					
		#endif					

//                mapi->dop_api->file_num = 1;
            break;
        case MSG_MUSIC_RPT:
            if(mapi && mapi->fop_api && mapi->fop_api->fop_init)
            {

				
		 #ifdef SUPPORT_REPEAT_ONLY_USE_ONE_ALL

		   if(play_mode == REPEAT_ALL)     //    if(play_mode >= MAX_PLAY_MODE)
		   	{
			   	#ifndef SUPPORT_REPEAT_ON_ALL_USE_LED
				    led_fre_set(7,0);			   	
				#endif
				          play_mode = REPEAT_ONE;						  
		   	}
		  else
		   	{
		   	#ifndef SUPPORT_REPEAT_ON_ALL_USE_LED
			    led_fre_set(15,0);			   	
			#endif
		         play_mode = REPEAT_ALL;		 	
			 
		   	}			  	
		 #else
		 
	                if(msg[1] != 0)
	                {
	                    //ÊåáÂÆöÈÄâÊã©
	                    play_mode = msg[1]&0xff;
	                }
	                else
	                {
	                    play_mode++;
	                }
				
		     if(play_mode >= REPEAT_ONE_LGDEV)     //    if(play_mode >= MAX_PLAY_MODE)
		     {
		         play_mode = REPEAT_ALL;
		     }
		 #endif	
		 // printf("-------play_mode -3-- %d\n",play_mode);
		 
                mapi->fop_api->fop_init->cur_play_mode = play_mode;
            }

            rcsp_report_status(RCSP_REPORT_PLAYMODE_VALUE);

#if LCD_SUPPORT_MENU
            UI_menu(MENU_REFRESH);
#else
            UI_menu_arg(MENU_SET_PLAY_MODE,play_mode);
#endif
	#if  SUPPORT_ALL_VOICE		
			 if(IsVoiceEnable)
			 {
	 			music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
			 }
	#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
		#ifdef SUPPORT_MUSIC_REPEAT_VOICE
			if(bModeVoiceSelVal)				
    			 {
	 			music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);								
    			 }	
		#endif	
	#elif defined SUPPORT_SCG_VOICE	
			if(bVoiceOnoff==1)		
				{
	 	 			music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);								
				}
	#endif					

            // printf("cur_play_mode : %s\r", &rpt_str[mapi->fop_api->fop_init->cur_play_mode-REPEAT_ALL][0] );
            break;

        case MSG_MUSIC_U_SD:
            // puts("MSG_MUSIC_U_SD\r\n");
            if(file_operate_get_total_phydev()>1)
            {
		#if MEDIA_MODE_USB_SD_DETECT	
	 		  dac_mute(1,1);
	 	#endif	 
		
      		 #ifdef support_mute_led_all_flish
		     mute_flag=0;
		 #endif
 
                mapi->dop_api->dec_api.save_brk = 1;
                led_fre_set(15,0);
                if(msg[1] == 0)
                {
                    ///led_fre_set(15,0);
                    ///mapi->dop_api->dec_api.save_brk = 1;
                    err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
					
			#if MEDIA_MODE_USB_SD_DETECT	
		 		 #if SUPPORT_ALL_VOICE	
				  	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
				  		if(IsVoiceEnable==2)				
				  		{
				  		#if SDMMC0_EN
				 			if(sd0==curr_device_using)
			 		                {
			 		                    curr_device_using = (u32)usb;
			 		                }
			 		                else
			 		                {
			 		                    curr_device_using = (u32)sd0;
			 		                }

						#else
				 			if(sd1==curr_device_using)
			 		                {
			 		                    curr_device_using = (u32)usb;
			 		                }
			 		                else
			 		                {
			 		                    curr_device_using = (u32)sd1;
			 		                }
						
						#endif

		 					 #ifdef LED_SHOW_DEVICE_PLUGIN	  
		 					 	led7_var.dwDeviceID= curr_device_using;			 
		 					 #endif					
			 			 
				 			if((sd0==curr_device_using)||(sd1==curr_device_using))
			 			 		music_prompt_play(mapi,BPF_MUSIC_SD_EN_MP3,0xff);				
			 			 	else   if(usb==curr_device_using)
			 			 		music_prompt_play(mapi,BPF_MUSIC_USB_EN_MP3,0xff);	
			 		}
				  		else				
				  	#endif		 						            					 
		 		 	 if(IsVoiceEnable)
					 	
				 #elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			 
			  		if(bModeVoiceSelVal==2)				
			  		{
						 #if SDMMC0_EN
						 	if(sd0==curr_device_using)
						 #elif SDMMC1_EN
						 	if(sd1==curr_device_using)
						 #endif		 			 
			 	                {
			 	                    curr_device_using = (u32)usb;
			 	                }
			 	                else
			 	                {
				 	                #if SDMMC0_EN
				 	                    curr_device_using = (u32)sd0;
							  #elif SDMMC1_EN
				 	                    curr_device_using = (u32)sd1;
							  #endif
			 	                }
				 			if((sd0==curr_device_using)||(sd1==curr_device_using))
			 			 		music_prompt_play(mapi,BPF_MUSIC_SD_EN_MP3,0xff);				
			 			 	else   if(usb==curr_device_using)
			 			 		music_prompt_play(mapi,BPF_MUSIC_USB_EN_MP3,0xff);	
	    				 }
			  		else	 if(bModeVoiceSelVal)		
				#elif defined SUPPORT_SCG_VOICE	
					if(bVoiceOnoff)	


					
					#endif								
		 			{
						 #if SDMMC0_EN
						 	if(sd0==curr_device_using)
						 #elif SDMMC1_EN
						 	if(sd1==curr_device_using)
						 #endif		 			 
		 		                {
		 		                    curr_device_using = (u32)usb;
		 		                }
		 		                else
		 		                {
				 	                #if SDMMC0_EN
				 	                    curr_device_using = (u32)sd0;
							  #elif SDMMC1_EN
				 	                    curr_device_using = (u32)sd1;
							  #endif
		 		                }

	 					 #ifdef LED_SHOW_DEVICE_PLUGIN	  
	 					 	led7_var.dwDeviceID= curr_device_using;			 
	 					 #endif					
						 #if SDMMC0_EN
						 	if(sd0==curr_device_using)
						 #elif SDMMC1_EN
						 	if(sd1==curr_device_using)
						 #endif		 			 
		 			 		music_prompt_play(mapi,BPF_MUSIC_SD_MP3,0xff);				
		 			 	else   if(usb==curr_device_using)
		 			 		music_prompt_play(mapi,BPF_MUSIC_USB_MP3,0xff);	
		 		}
		 	 	break;
		 	 #endif								
					
                }
                else
                {
                    ///
                    // puts("SPEC DEV\n");
                    if(msg[1] == RCSP_CBK_MSG_MUSIC_SET_DEV)
                    {
                        err = music_play_api(mapi,DEV_SEL_SPEC,msg[2],PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
                    }
                    else if(msg[1] == RCSP_CBK_MSG_MUSIC_PREV_DEV)
                    {
                        err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
                    }
                    else
                    {
                        err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
                    }
                }

            }
            break;

#if EQ_EN
        case MSG_MUSIC_EQ:

		 #ifdef TEST_PANEL_LED
		 	if(bledComValue)
		 	bledComValue--;
		 	  printf("bledGridValue =%x %x \n",bledComValue,bledGridValue);
		 	break;
		 
		 #endif

			
            if(mapi && mapi->dop_api)
            {
                if(msg[1] != 0)
                {
                    //ÊåáÂÆöÈÄâÊã©
                    eq_mode = msg[1]&0xff;
                }
                else
                {
                    eq_mode++;
                }
//
                if(eq_mode > 5)
                {
                    eq_mode = 0;
                }
                eq_mode_sw(eq_mode);
                // printf("MSG_MUSIC_EQ %d, \n ", eq_mode);
            }

            rcsp_report_status(RCSP_REPORT_EQ_VALUE);
			
		#if SUPPORT_ALL_VOICE	
	 		#if SUPPORT_TY_VOICE==0
	 		#if SUPPORT_EQ_VOICE
	 
	     			 if(IsVoiceEnable)
	     			 {
	 		 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
	    			 }
	 		#endif
	 		#endif
		#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			#ifdef SUPPORT_MUSIC_EQ_VOICE
				if(bModeVoiceSelVal)				
	    			 {
		 			music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);								
	    			 }	
			#endif
			#elif defined SUPPORT_SCG_VOICE	
				if(bVoiceOnoff==1)		
	    			 {
		 			music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);								
	    			 }				
		#endif	
		
#ifdef SUPPORT_VM_EQ_MODE
	vm_write_api(VM_WORK_MODE,&eq_mode);
#endif

#if LCD_SUPPORT_MENU
            UI_menu(MENU_REFRESH);
#else
            UI_menu_arg(MENU_SET_EQ,eq_mode);
#endif
            break;
#endif/*EQ_EN*/

        //  case MSG_MUSIC_SRC:
        //         src_mode++;
        //         if(src_mode >= 9)
        //         {
        //             src_mode = 0;
        //         }
        //    //dec_phy_printf("samplerate_change= %d\r\n",samplerate_tab[src_mode]);
        //    samplerate_change(samplerate_tab[src_mode]);
        //    break;

        case MSG_MUSIC_PP:


           #ifdef TEST_PANEL_LED
	            bledComValue++;
	            if(bledComValue>=LED_COM_MAX)
	            bledComValue=0;
				
		 	printf("bledGridValue =%x %x \n",bledComValue,bledGridValue);
			
			break;			
            #endif
			
#if UI_ENABLE
            if (UI_var.bCurMenu == MENU_INPUT_NUMBER)
            {
                os_taskq_post("MusicTask", 1, MSG_INPUT_TIMEOUT);
                break;
            }
#endif

#ifdef support_msg_stop_key
            if(play_stop_flag)
            {
                input_number=1;
                os_taskq_post("MusicTask", 1, MSG_INPUT_TIMEOUT);
                //   play_stop_flag=0;
                break;
            }
#endif

            // puts("MSG_MUSIC_PP\n");
            _DECODE_STATUS pp_s;
            pp_s = pp_decode(&mapi->dop_api->dec_api);
            if(DECODER_PAUSE == pp_s)
            {
                // puts("*PAUSE*\n");
                rcsp_set_task_status(STAUS_PAUSE);
                music_ui.opt_state = (MUSIC_OPT_BIT_PAUSE);
//                task_status = STAUS_PAUSE;

                led_fre_set(0,0);
#ifdef support_pause_stop_mute_amp
                pa_mute();
                pause_mute_flag=1;
#endif
		#if  SUPPORT_ALL_VOICE

			#ifdef  SUPPORT_SCG_VOICE	
				if(bVoiceOnoff==1)		
	     			 {
	 		 		music_prompt_play(mapi,BPF_PAUSE_EN_MP3,MSG_MUSIC_PAUSE);				
	 				
	     			 }	
			#else
	     			 if(IsVoiceEnable)
	     			 {
	 		 		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PAUSE);				
	 				
	     			 }
			#endif	

				 
		#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			#ifdef SUPPORT_PP_PREV_NEXT_VOICE
			if(bModeVoiceSelVal)				
    			 {
		 		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PAUSE);				
				
    			 }				
		#endif	
		
		#endif	

            }
            else
            {
                if(DECODER_PLAY == pp_s)
                {
                    // puts("*PLAY*\n");
//                    task_status = STAUS_PLAY;
                    rcsp_set_task_status(STAUS_PLAY);
                    music_ui.opt_state = MUSIC_OPT_BIT_PLAY;
#ifdef support_pause_stop_mute_amp
                    pa_umute();
                    pause_mute_flag=0;
#endif

                }
                else
                {
                    // puts("*STOP*\n");
//                    task_status = STAUS_STOP;
                    rcsp_set_task_status(STAUS_PAUSE);
                    music_ui.opt_state = (MUSIC_OPT_BIT_PAUSE);
                }

                led_fre_set(15,0);
				
		#if  SUPPORT_ALL_VOICE
			 #ifdef  SUPPORT_SCG_VOICE	
			 	if(bVoiceOnoff==1)		
			 	{
			 		music_prompt_play(mapi,BPF_PLAY_EN_MP3,MSG_MUSIC_PLAY);				
			 	}	
			 #else
			 	if(IsVoiceEnable)
			 	{
			 		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PLAY);				
			 	}
			 #endif

		#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			#ifdef SUPPORT_PP_PREV_NEXT_VOICE
				if(bModeVoiceSelVal)				
	    			 {
			 		music_prompt_play(mapi,BPF_NULL_MP3,MSG_MUSIC_PLAY);				
					
	    			 }	
			#endif

			
		#endif					
				
            }
//                UI_menu(MENU_MUSIC_MAIN);
            UI_menu(MENU_REFRESH);
            break;
#ifdef support_msg_stop_key
        case MSG_MUSIC_STOP:
            if (*music_ui.ui_curr_statu == DECODER_PLAY)
            {
                play_stop_flag =1;
                pp_decode(&mapi->dop_api->dec_api);
            led_fre_set(0,0);
#ifdef support_pause_stop_mute_amp
                pa_mute();
                pause_mute_flag=1;
#endif
                UI_menu(MENU_MUSIC_MAIN);
            }
            break;
#endif

        case MSG_MUSIC_FF:
            //dec_phy_printf("ff");
            if (0 == dec_ff_fr(&mapi->dop_api->dec_api,PLAY_MOD_FF,2))
            {
                music_ui.opt_state = (MUSIC_OPT_BIT_FF);
                UI_menu(MENU_MUSIC_MAIN);

                rcsp_set_task_status(STAUS_PLAY);
                ///rcsp_report_status(RCSP_REPORT_MUSIC_PLAYTIME);
            }
            clean_ab_rpt();
            break;
        case MSG_MUSIC_FR:
            //dec_phy_printf("fr");
            /* msg[1] = get_decode_time(); */
            /* if(msg[1] > 15) */
            /* { */
            /* msg[1] = 15; */
            /* } */

            if (0 == dec_ff_fr(&mapi->dop_api->dec_api,PLAY_MOD_FB,2))
            {
                music_ui.opt_state = (MUSIC_OPT_BIT_FR);
                UI_menu(MENU_MUSIC_MAIN);

                rcsp_set_task_status(STAUS_PLAY);
                ///rcsp_report_status(RCSP_REPORT_MUSIC_PLAYTIME);
            }
            clean_ab_rpt();
            break;

        case MSG_MUSIC_FFR_DONE:
            break;

        case SYS_EVENT_DECODE_END:
            break;

        case MSG_MUSIC_PLAY:
            play_sel_play_decoder(mapi->dop_api);
            rcsp_set_task_status(STAUS_PLAY);
            music_ui.opt_state = 0;
            UI_menu(MENU_REFRESH);
            break;

        case MSG_MUSIC_PAUSE:
            play_sel_pause_decoder(mapi->dop_api);
            rcsp_set_task_status(STAUS_PAUSE);
            music_ui.opt_state = (MUSIC_OPT_BIT_PAUSE);
            UI_menu(MENU_REFRESH);
            break;

        case MSG_MUSIC_PLAY_SN:
            // puts("MSG_MUSIC_PLAY_SN\n");
            if ((msg[1] <= mapi->fop_api->cur_lgdev_info->total_file_num)&&(msg[1] != 0))
            {
                mapi->dop_api->file_num = msg[1];
                err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
            }
            UI_menu(MENU_MUSIC_MAIN);
            break;

#if REC_EN
        case MSG_MUSIC_DEL_FILE:
#if 0
            ble_server_disconnect();
            break;
#endif // 1

#ifdef  support_del_all_file  	//‘≠≥ßÃ·π©  »´…æ≥˝	 


            file_auto_next = 1;
            led_fre_set(15,0);
            //dec_phy_printf("KEY_EVENT_NEXT\r\n");

            music_ui.opt_state = (MUSIC_OPT_BIT_DEL);
//                UI_menu(MENU_MUSIC_MAIN);
            UI_menu(MENU_REFRESH);

            music_stop_decoder(mapi);
            _FIL_HDL *f_h=(_FIL_HDL *)(mapi->fop_api->cur_lgdev_info->lg_hdl->file_hdl);
            FIL *pf=(FIL *)(f_h->hdl);
            err=f_unlink(pf);
            // printf("del file %08x  \n",err);



            music_ui.opt_state &= (~MUSIC_OPT_BIT_DEL);

            file_operate_ctl(FOP_GET_TOTALFILE_NUM,mapi->fop_api,mapi->dop_api->file_type,0);

            if(0 == mapi->fop_api->cur_lgdev_info->total_file_num)
            {
                err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
            }
            else
            {
                err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
            }


#else    //ΩˆΩˆ…æ≥˝¬º“ÙŒƒº˛
		 
                file_auto_next = 1;
                #ifdef support_repeat_first_flish_led
                      if(play_mode != REPEAT_ALL)
                      	  {
                      	       led_fre_set(5,0);
                      	  }
                	  else 
                #endif 		
	 #if defined(support_dcx_led_flish_mode)
	 	       led_fre_set(22,0);
	 #else 
	 	       led_fre_set(15,0);
	 #endif

            // printf("del file \r\n");

	    _FIL_HDL *f_h=(_FIL_HDL *)(mapi->fop_api->cur_lgdev_info->lg_hdl->file_hdl);
	    FIL *pf=(FIL *)(f_h->hdl);
				

  	//   // printf("fs_n_tpath:%s\n",pf->fs_n.tpath);
  	//	putbyte(pf->fs_n.tpath[1]);
  	//	putbyte(pf->fs_n.tpath[2]);
  	//	putbyte(pf->fs_n.tpath[3]);
  	//	putbyte(pf->fs_n.tpath[4]);
  	
//"/JL_REC     ≈–∂œƒø¬º
	//if(strstr(pf->fs_n.tpath,"/JL_REC")!=NULL) 
  	   if(pf->fs_n.tpath[1]=='J' &&pf->fs_n.tpath[2]=='L'&&pf->fs_n.tpath[3]=='_' &&pf->fs_n.tpath[4]=='R'&&pf->fs_n.tpath[5]=='E'&&pf->fs_n.tpath[6]=='C')	  //"/JL_REC     /"
		{
		
	       music_stop_decoder(mapi);
//		// printf("fs_n_tpath:%s\n",pf->fs_n.tpath); //¥Ú”° Œƒº˛º–√˚◊÷
	         err=f_unlink(pf);
        //       // printf("del file %08x  \n",err);
	//	// printf("fs_n_tpath:%s\n",pf->fs_n.tpath);
	
		UI_menu(MENU_REC_DEL);
		os_time_dly(150);

	 #ifdef SUPPORT_REC_PLAY_USE_FOLDER_MODE
		 	{
				rec_play_sw=0;
				play_mode = REPEAT_ALL;
				mapi->fop_api->fop_init->cur_play_mode = play_mode;				
		 	}
	 #endif
	
		err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_NEXT_FILE,&(mapi->dop_api->file_num));

		}
#endif  


            break;

#ifdef support_only_rec_key_to_rec_mode
            case MSG_REC_START:
		if(!file_operate_get_total_phydev())
			break;
                   muisc_to_rec_flag=1;
		   os_taskq_post("MainTask", 1, MSG_CHANGE_REC_MODE);
                  break;				
#endif 


case  MSG_MUSIC_PLAY_REC_FILE:

#ifdef SUPPORT_PLAY_REC_FILE_FIRST_MUTE_AMP
	pa_mute();
	dac_mute(1,1);
#endif
	
	// printf("/n--------pf->fs_n.tpath-----%s\n",pf->fs_n.tpath);
#if 1

	       err=music_play_by_path(mapi);
#else
	 if(strstr(pf->fs_n.tpath,"/JL_REC")!=NULL) //
    //  if(  music_ui.ui_curr_file >= rec_file_startcnt &&  music_ui.ui_curr_file >=rec_file_endcnt)
             {
		   mapi->dop_api->file_num = 1;
		   err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
	      }
	else
	       err=music_play_by_path(mapi);
	 //     mapi->dop_api->file_num = 1;
         //    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_FIRST_FILE,&(mapi->dop_api->file_num));
#endif	 
	break;
	 
#endif

        case SYS_EVENT_DEV_ONLINE:
			
            //dec_phy_printf("music SYS_EVENT_DEV_ONLINE\r");
            ///music_stop_decoder(mapi->dop_api);
            //dec_phy_printf("AA\r");

	#if MEDIA_MODE_USB_SD_DETECT	
 		  dac_mute(1,1);
 	#endif	 
	

     #ifdef LED_SHOW_DEVICE_PLUGIN	 
	 UI_menu(MENU_DEVICE);
	 os_time_dly(50);
	// led7_var.dwDeviceID=0;			 
     #endif
			
            mapi->dop_api->dec_api.save_brk = 1;
//                mapi->dop_api->dec_api.enable_brk = 1;
            mapi->dop_api->file_num = 1;

	#if MEDIA_MODE_USB_SD_DETECT	
		 #if SUPPORT_ALL_VOICE	
			  	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
			  		if(IsVoiceEnable==2)				
			  		{		
		 			 
			 			if((sd0==curr_device_using)||(sd1==curr_device_using))
		 			 		music_prompt_play(mapi,BPF_MUSIC_SD_EN_MP3,0xff);				
		 			 	else   if(usb==curr_device_using)
		 			 		music_prompt_play(mapi,BPF_MUSIC_USB_EN_MP3,0xff);	
		 			}
			  		else				
			  	#endif	
				
			  	 #ifdef SUPPORT_SCG_VOICE
					if(bVoiceOnoff)		

			  	#endif	


				
			 //   if(IsVoiceEnable)
					
		 #elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF	
			   if(IsVoiceEnable)

	  		if(bModeVoiceSelVal==2)				
	  		{		
 			 
	 			if((sd0==curr_device_using)||(sd1==curr_device_using))
 			 		music_prompt_play(mapi,BPF_MUSIC_SD_EN_MP3,0xff);				
 			 	else   if(usb==curr_device_using)
 			 		music_prompt_play(mapi,BPF_MUSIC_USB_EN_MP3,0xff);	
 			}				
	  		else	 if(bModeVoiceSelVal)						
		 #endif		
	 
		 	{
				 #if SDMMC0_EN
				 	if(sd0==curr_device_using)
				 #else
				 	if(sd1==curr_device_using)
				 
				 #endif
			 		music_prompt_play(mapi,BPF_MUSIC_SD_MP3,0xff);				

			 	else   if(curr_device_using == usb)
			 		music_prompt_play(mapi,BPF_MUSIC_USB_MP3,0xff);	
		 	}
	 	break;
	 #endif					

            err = music_play_api(mapi,DEV_SEL_SPEC,msg[1],PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
            //dec_phy_printf("BB\r");
            UI_menu(MENU_MUSIC_MAIN);
            break;
        case SYS_EVENT_DEL_TASK: 				//ËØ∑Ê±ÇÂà†Èô§music‰ªªÂä°
            mapi->dop_api->dec_api.save_brk = 1;
            music_stop_decoder(mapi);
            getting_music_info  = 0;
            rcsp_set_music_bs_op_api(NULL);
//                UI_menu(MENU_WAIT);
		dec_dev_changed=0;
            set_sys_freq(SYS_Hz);
            ui_close_music();
            dac_channel_off(MUSIC_CHANNEL, FADE_ON);

#if MUSIC_DECRYPT_EN
            cipher_close();
#endif

#if EQ_EN
            eq_disable();
#endif/*EQ_EN*/
//                set_flac_sys_freq(0);//set_sys_clk
            if(mapi->dop_api->dec_api.dec_phy_name)
            {
                if (os_task_del_req(mapi->dop_api->dec_api.dec_phy_name) != OS_TASK_NOT_EXIST)
                {
                    os_taskq_post_event(mapi->dop_api->dec_api.dec_phy_name, 1, SYS_EVENT_DEL_TASK);
                    do
                    {
                        OSTimeDly(1);
                    }
                    while(os_task_del_req(mapi->dop_api->dec_api.dec_phy_name) != OS_TASK_NOT_EXIST);
                    mapi->dop_api->dec_api.dec_phy_name = NULL;
                    // puts("del music dec phy succ\n");
                }
            }
            if(mapi->dop_api->dec_api.ef_enable&&mapi->dop_api->dec_api.ef_out_name)
            {
                if (os_task_del_req(mapi->dop_api->dec_api.ef_out_name) != OS_TASK_NOT_EXIST)
                {
                    os_taskq_post_event(mapi->dop_api->dec_api.ef_out_name, 1, SYS_EVENT_DEL_TASK);
                    do
                    {
                        OSTimeDly(1);
                    }
                    while(os_task_del_req(mapi->dop_api->dec_api.ef_out_name) != OS_TASK_NOT_EXIST);
                    mapi->dop_api->dec_api.ef_out_name = NULL;
                    // puts("del music ef_out_name succ\n");
                }
            }

            enable = 0;

#if LRC_LYRICS_EN
            lrc_exit();
#endif

            ///<ÂÖ≥Èó≠Êñá‰ª∂Êìç‰ΩúÂô®ÔºåÈáäÊîæËµÑÊ∫ê
            file_operate_ctl(FOP_CLOSE_LOGDEV,mapi->fop_api,0,0);
            ///<ÈáäÊîæÊñá‰ª∂Êìç‰ΩúÂô®ÂàùÂßãÂåñ‰ø°ÊÅØ

            echo_exit_api(&music_reverb);
            if(mapi->fop_api)
            {
                if(mapi->fop_api->fop_init)
                    free_fun((void**)&mapi->fop_api->fop_init);
                free_fun((void**)&mapi->fop_api);
            }
            free_fun((void**)&mapi->dop_api->brk);
            free_fun((void**)&mapi->dop_api->io);
            free_fun((void**)&mapi->dop_api);
            free_fun((void**)&mapi);

            if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
            {
                os_task_del_res_name(OS_TASK_SELF); 	//Á°ÆËÆ§ÂèØÂà†Èô§ÔºåÊ≠§ÂáΩÊï∞‰∏çÂÜçËøîÂõû
            }

            break;

        case MSG_MUSIC_SPC_FILE:
            file_auto_next = 1;
            led_fre_set(15,0);
            // printf("MSG_MUSIC_SPC_FILE-----,0x%x\n",msg[1]);
            err=music_play_by_sclust(mapi,msg[1]);
            break;

#if LCD_SUPPORT_MENU
        case MSG_ENTER_MENULIST:
            UI_menu_arg(MENU_LIST_DISPLAY,UI_MENU_LIST_ITEM);
            break;
#endif

#if 0//MUSIC_AB_RPT_EN
        case MSG_MUSIC_AB_RPT:       ///<ABÊÆµÂæ™ÁéØÊí≠ÊîæËÆæÁΩÆ
            // puts("MUSIC_AB_RPT\n");
            if(DECODER_PLAY == get_decode_statu(&mapi->dop_api->dec_api))
            {
                switch_a_b_repeat(mapi);
            }
            break;
#endif


//------------------customer  add------------------------------------

    #ifdef SUPPORT_MUSIC_RANDOM_KEY
	
		case MSG_MUSIC_RANDOM_PLAY:			  
		  if(mapi && mapi->fop_api && mapi->fop_api->fop_init)
		  { 			  
		      if(play_mode!=REPEAT_RANDOM)
			  play_mode=REPEAT_RANDOM;	
			  else
			  play_mode=REPEAT_ALL;	
			  mapi->fop_api->fop_init->cur_play_mode = play_mode;
		  }
	            rcsp_report_status(RCSP_REPORT_PLAYMODE_VALUE);

		 #if LCD_SUPPORT_MENU
		         UI_menu(MENU_REFRESH);
		 #else
		         UI_menu_arg(MENU_SET_PLAY_MODE,play_mode);
		 #endif

		break;
	 
    #endif



#if  SUPPORT_ALL_VOICE
	 #if   SUPPORT_TY_VOICE==0
	 
	 	#ifdef SUPPORT_VOICE_ONOFF_KEY_SINGLE_KEY
	 		case MSG_MUSIC_VOICE_SWITCH:	
	 		 
	 			if(IsVoiceEnable)
	 			{
	 				bStoreVoiceVal=IsVoiceEnable;
	 				IsVoiceEnable = 0;
	 				 #ifdef LED_SHOW_ONOFF
	 				 	UI_menu(MENU_OFF); 
	 				 #endif			 			 						 
	 			}
	 			else
	 			{
	 				IsVoiceEnable = bStoreVoiceVal;
	 				 #ifdef LED_SHOW_ONOFF
	 				 	UI_menu(MENU_ON); 
	 				 #endif			 									
	 			}
	 
	 			 #ifdef SUPPORT_VOICE_ENALBE_MEM
	 			 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
	 			 #endif
	 			
	 	 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);		
	 
	 			break;
	 			
	 		case MSG_MUSIC_VOICE_CHANGE:	
	 
	 			if(IsVoiceEnable==0)
	 				break;
	 
	 			if(IsVoiceEnable==1)
	 			{
	 				IsVoiceEnable=2;
	 				 #ifdef LED_SHOW_ONOFF
	 				 	UI_menu(MENU_VOICE_EN); 
	 				 #endif			 			 
	 						 
	 			}
	 			else
	 			{
	 				IsVoiceEnable = 1;
	 				 #ifdef LED_SHOW_ONOFF
	 				 	UI_menu(MENU_VOICE_CH); 
	 				 #endif			 									
	 			}
	 			
	 			 #ifdef SUPPORT_VOICE_ENALBE_MEM
	 			 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
	 			 #endif
	 			
	 	 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);		
	 			
	 
	 			break;
	 			
	 	#else
	   		case MSG_MUSIC_VOICE_SWITCH:
	 
	 		  	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 		  		if(IsVoiceEnable==1)				
	 		  		{			 			 
	 					 #ifdef LED_SHOW_ONOFF
	 					 	UI_menu(MENU_ON); 
	 					 #endif			 
	 				 	IsVoiceEnable = 2;
	 	 			}
	 		  		else				
	 		  	#endif		 
	 			
	 			 if(IsVoiceEnable)
	 			 {
	 				 #ifdef LED_SHOW_ONOFF
	 				 	UI_menu(MENU_OFF); 
	 				 #endif			 
	 			 	IsVoiceEnable = 0;
	 			 }
	 			 else
	 			 {
	 			 #ifdef LED_SHOW_ONOFF
	 			 	UI_menu(MENU_ON); 
	 			 #endif			 
	 			 	IsVoiceEnable = 1;
	 			 }
	 				
	 			 
	 			 #ifdef SUPPORT_VOICE_ENALBE_MEM
	 			 	vm_write_api(VM_VOICE_ONOFF,&IsVoiceEnable);
	 			 #endif
	 		     #ifdef SUPPORT_MUSIC_STOP_KEY
	 		         bStop_state=FALSE;
	 		     #endif	
	 			 
	 	 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
	 
	 			break; 
	 		#endif
	 		
	 	 #ifdef SUPPORT_MUTE_VOICE	
	 	    case MSG_VOICE_MUTE_OFF:
	 	    case MSG_VOICE_MUTE:					
	 	#endif
	 		case MSG_VOICE_VOLUME_PLUS:		
	 		case MSG_VOICE_VOLUME_MINUS:		
	 	 	case MSG_MAX_VOICE:
	 	 	case MSG_VOICE_NUMBER:
		 	 #ifdef SUPPORT_MIC_ONOFF_VOICE
		 	 		case MSG_VOICE_MIC:
		 	 #endif
	 		if(IsVoiceEnable)
	 	    	{
	 	 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
	 	    	}
	 		
	 	    	break;
	 #else


		 	#ifdef SUPPORT_VOICE_MODE_KEY
		 	   		case MSG_MUSIC_VOICE_SWITCH:
		 	 		 	 			
		 	 			 if(IsVoiceEnable)
		 	 			 {
		 	 				 #ifdef LED_SHOW_ONOFF
		 	 				 	UI_menu(MENU_OFF); 
		 	 				 #endif			 
		 	 			 	IsVoiceEnable = 0;
		 	 			 }
		 	 			 else
		 	 			 {
		 	 			 #ifdef LED_SHOW_ONOFF
		 	 			 	UI_menu(MENU_ON); 
		 	 			 #endif			 
		 	 			 	IsVoiceEnable = 1;
		 	 			 }
		 	 						 	 			 
		 	 		     #ifdef SUPPORT_MUSIC_STOP_KEY
		 	 		         bStop_state=FALSE;
		 	 		     #endif	
		 	 			 
		 	 	 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
		 	 
		 	 			break; 
		 	#endif

			 #ifdef SUPPORT_SCG_VOICE
	 			 #ifdef SUPPORT_MUTE_VOICE	
	 			 	case MSG_VOICE_MUTE_OFF:
	 			 	case MSG_VOICE_MUTE:					
	 			 #endif
			 		case MSG_VOICE_VOLUME_PLUS:		
			 		case MSG_VOICE_VOLUME_MINUS:		
			 		case MSG_MAX_VOICE:
			 		case MSG_VOICE_NUMBER:
	 			 #ifdef SUPPORT_MIC_ONOFF_VOICE
	 			 	case MSG_VOICE_MIC:
	 			 #endif
			 	if(bVoiceOnoff)
			 	{
			 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
			 	}
			 
			 	break;
			 
			 
			 #endif


			
 		 #ifdef SUPPORT_MIC_ONOFF_VOICE
 		 		case MSG_VOICE_MIC:
 		 		if(IsVoiceEnable)
 		 	    	{
 		 	 		music_prompt_play(mapi,BPF_NULL_MP3,msg[0]);				
 		 	    	}
 		 		
 		 	    	break;
 		 			
 		 #endif
	 #endif



#endif



#ifdef SUPPORT_STORY_MACHINE

	case MSG_MUSIC_RPT_ONE:
		
	   if(mapi && mapi->fop_api && mapi->fop_api->fop_init)
	   {		
	          play_mode=REPEAT_ONE;	
		   mapi->fop_api->fop_init->cur_play_mode = play_mode;
	   }
             rcsp_report_status(RCSP_REPORT_PLAYMODE_VALUE);
	 
	 #if LCD_SUPPORT_MENU
	             UI_menu(MENU_REFRESH);
	 #else
	             UI_menu_arg(MENU_SET_PLAY_MODE,play_mode);
	 #endif
	 
	break;

	case MSG_MUSIC_RPT_ALL:

	   if(mapi && mapi->fop_api && mapi->fop_api->fop_init)
	   {		
	          play_mode=REPEAT_ALL;	
		   mapi->fop_api->fop_init->cur_play_mode = play_mode;
	   }
             rcsp_report_status(RCSP_REPORT_PLAYMODE_VALUE);
	 
	 #if LCD_SUPPORT_MENU
	             UI_menu(MENU_REFRESH);
	 #else
	             UI_menu_arg(MENU_SET_PLAY_MODE,play_mode);
	 #endif
	break;

	case MSG_MUSIC_RPT_RAND:

	   if(mapi && mapi->fop_api && mapi->fop_api->fop_init)
	   {		
	          play_mode=REPEAT_RANDOM;	
		   mapi->fop_api->fop_init->cur_play_mode = play_mode;
	   }
             rcsp_report_status(RCSP_REPORT_PLAYMODE_VALUE);
	 
	 #if LCD_SUPPORT_MENU
	             UI_menu(MENU_REFRESH);
	 #else
	             UI_menu_arg(MENU_SET_PLAY_MODE,play_mode);
	 #endif
			 
	break;	
	
	case MSG_CLASSIC_MUSIC:		
	case MSG_GUOXUE:		
	case MSG_WEST_MUSIC:		
	case MSG_ENGLISH:		
	case MSG_STORY:		
	case MSG_SONG:		
	case MSG_ENCYCLOPEDIA:		
	case MSG_FITAL_EDUCATION:
	case MSG_LISTEN:
	       err=music_play_by_path_dir(mapi,(msg[0]-MSG_CLASSIC_MUSIC));
//	       err=music_play_by_path_dir(mapi);
	break;
		

#endif



//------------------customer  add------------------------------------

        case MSG_HALF_SECOND:

	 #ifdef SUPPORT_MUSIC_PREV_NEXT_VOICE
	 	if(bPrevNextVoiceFlag>0)
	 		bPrevNextVoiceFlag--;		
	 #endif

	//	 	  printf("--MSG_HALF_SECOND----curr_device_using--------- =%d\n",curr_device_using);
			
            play_time = get_decode_time();
            {
                music_ui.play_time = play_time;
                UI_menu(MENU_HALF_SEC_REFRESH);
            }
            half_sec_count++;
            if((half_sec_count%10) == 0)
//time 5s/
            {
                rcsp_report_status(RCSP_REPORT_MUSIC_PLAYTIME);
            }


#if MUSIC_AB_RPT_EN
            if((ab_rept.b_stage.play_time)&&(ab_rept.b_stage.play_time <= play_time))
            {
                if(ab_rept.b_stage.file_num == mapi->dop_api->file_num)
                {
                    mapi->dop_api->dec_api.bp_buff = ab_rept.a_stage->inf.brk_buff;
                    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_AB_REPEAT,&(mapi->dop_api->file_num));
                    mapi->dop_api->dec_api.bp_buff = &mapi->dop_api->brk->inf.brk_buff[0];
                }
            }
#endif // MUSIC_AB_RPT
            music_ui.opt_state &= (~(MUSIC_OPT_BIT_FF|MUSIC_OPT_BIT_FR));
            break;

        case MSG_PROMPT_PLAY:
        case MSG_LOW_POWER:
            dec_phy_puts("Music_Low_Power\n");
            music_prompt_play(mapi,BPF_LOW_POWER_MP3,msg[0]);
            break;

        case MSG_INPUT_TIMEOUT:

            if ((input_number <= mapi->fop_api->cur_lgdev_info->total_file_num)&&(input_number != 0))
            {
            
	 	 #ifdef SUPPORT_FLASH_CHAR
	 	 	LED_FLASH_CHAR=0;
	 	 	LED_FLASH_ICON=0;			  
	 	 #endif		

		 #ifdef support_mute_led_all_flish
		     mute_flag=0;
		 #endif

                mapi->dop_api->file_num = input_number;
                err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));		
            }
			
            input_number = 0;
            input_number_cnt= 0;

		 #ifdef SUPPORT_ADD10_KEY_DIRECT_PLAY		
		 	UI_menu(MENU_FILENUM);
		 #else
		 	UI_menu(MENU_MUSIC_MAIN);
		 #endif
            break;
        case SYS_EVENT_DEV_BEGIN_MOUNT:         ///<Êñ∞ËÆæÂ§áÂºÄÂßãÊûö‰∏æÔºåÁªìÊùüËß£Á†ÅÔºåÈò≤Ê≠¢Âá∫Áé∞Êñ∞ËÆæÂ§áÊûö‰∏æÊÖ¢ÔºåÂΩìÂâçËÆæÂ§áÊí≠Êîæ
            // printf("new dev mount,stop  \n");   ///<‰∏ÄÂ∞èÊÆµÔºåÂèàÂàáÊç¢Âà∞Êñ∞ËÆæÂ§á
            mapi->dop_api->dec_api.save_brk = 1;
            music_stop_decoder(mapi);
            break;
        case SYS_EVENT_DEV_MOUNT_ERR:       ///<Êñ∞ËÆæÂ§áÊûö‰∏æÂ§±Ë¥•ÔºåÁªßÁª≠ÂΩìÂâçËÆæÂ§áÊí≠Êîæ
            // printf("dev mount err\n");
            mapi->dop_api->dec_api.save_brk = 0;
            err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_BREAK_POINT,&(mapi->dop_api->file_num));
            break;
        default:
            //dec_phy_printf("dev status =%08x \n",err);
            echo_msg_deal_api(&music_reverb, msg);
            break;
        }
        u32 totalerrfile=0;
        while(0 != err)
        {
            //dec_phy_printf("--music err  : %02x\n",err);
            u32 status;

            /*
            			memset(msg,0x00,sizeof(msg));
            			status = os_taskq_pend(2, ARRAY_SIZE(msg), msg);
            			clear_wdt();

            			if(status == OS_NO_ERR)
            			{
            				switch(msg[0])
            				{
            					case SYS_EVENT_DEL_TASK:
            						os_taskq_flush(OS_TASK_SELF);
            						os_taskq_post_msg(OS_TASK_SELF,1,SYS_EVENT_DEL_TASK);
            						err = 0;
            						break;
            				}
            			}
            			else
            */
            {
                switch(err)
                {
                case FILE_OP_ERR_INIT:              ///<Êñá‰ª∂ÈÄâÊã©Âô®ÂàùÂßãÂåñÈîôËØØ
                case FILE_OP_ERR_OP_HDL:            ///<Êñá‰ª∂ÈÄâÊã©Âô®ÊåáÈíàÈîôËØØ
                case FILE_OP_ERR_LGDEV_NULL:        ///<Ê≤°ÊúâËÆæÂ§á
                case FILE_OP_ERR_NO_FILE_ALLDEV:    ///<Ê≤°ÊúâÊñá‰ª∂ÔºàÊâÄÊúâËÆæÂ§áÔºâ
                    file_operate_ctl(FOP_CLOSE_LOGDEV,0,0,0);
                    wait_exit=1;            ///<ËøõÂÖ•Á≠âÂæÖÈÄÄÂá∫Áä∂ÊÄÅ
                    wait_ok = 1;
                    /* os_taskq_flush(MAIN_TASK_NAME); */
                    /* os_taskq_post(MAIN_TASK_NAME, 1, MSG_CHANGE_WORKMODE); */
#ifdef usb_sd_out_to_bt_mode
                    if(OS_NO_ERR == os_taskq_post(MAIN_TASK_NAME, 1, MSG_BT_MODE_KEY))
#elif defined(usb_sd_out_to_line_mode)
                    if(OS_NO_ERR == os_taskq_post(MAIN_TASK_NAME, 1, MSG_LINE_MODE_KEY))
#else
                    if(OS_NO_ERR == os_taskq_post(MAIN_TASK_NAME, 1, MSG_CHANGE_WORKMODE))
#endif
                    {
                        wait_ok = 0;
                    }
                    err = 0;
                    break;
                case FILE_OP_ERR_OPEN_BPFILE:
                    //dec_phy_printf("err  : %02x\r",err);
                    mapi->dop_api->file_num = 1;
                    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_FIRST_FILE,&(mapi->dop_api->file_num));
                    break;
                case FILE_OP_ERR_NUM:               ///<ÈÄâÊã©Êñá‰ª∂ÁöÑÂ∫èÂè∑Âá∫Èîô
                    mapi->dop_api->file_num = 1;
                    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
                    break;
                case FILE_OP_ERR_LGDEV_MOUNT:
                case FILE_OP_ERR_NO_FILE_ONEDEV:    ///<ÂΩìÂâçÈÄâÊã©ÁöÑËÆæÂ§áÊ≤°ÊúâÊñá‰ª∂
                    mapi->dop_api->file_num = 1;
                    err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
                    break;
                case FILE_OP_ERR_LGDEV_NO_FIND:     ///<Ê≤°ÊâæÂà∞ÊåáÂÆöÁöÑÈÄªËæëËÆæÂ§á
                    mapi->dop_api->file_num = 1;
                    err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_SPEC_FILE,&(mapi->dop_api->file_num));
                    break;

                case SUCC_MUSIC_START_DEC:
                    err = 0;
                    file_auto_next = 1;
                    //dec_phy_printf("SUCC_MUSIC_START_DEC \r");
                    break;
                case FILE_OP_ERR_OPEN_FILE:         ///<ÊâìÂºÄÊñá‰ª∂Â§±Ë¥•
                case ERR_MUSIC_START_DEC:
                    status=file_operate_ctl(FOP_DEV_STATUS,mapi->fop_api,0,0);
                    if(status==FILE_OP_ERR_OP_HDL)
                    {
                        ///<ÈÄªËæëËÆæÂ§á‰∏çÂÜçÈìæË°®
                        err=FILE_OP_ERR_OP_HDL;
                        break;
                    }
                    else if(!status)
                    {
                        ///<ÈÄªËæëËÆæÂ§áÊéâÁ∫ø
                        err=FILE_OP_ERR_LGDEV_NO_FIND;
                        break;
                    }
                    totalerrfile++;
                    //dec_phy_printf("---total err =%08x \n",totalerrfile);
                    //dec_phy_printf("---total_file_num =%08x \n",mapi->fop_api->cur_lgdev_info->total_file_num);
                    if(totalerrfile>=mapi->fop_api->cur_lgdev_info->total_file_num)
                    {
                        ///<ÂΩìÂâçËÆæÂ§á‰∏≠Èü≥‰πêÊñá‰ª∂ÂÖ®ÈÉ®‰∏çÂèØ‰ª•Ëß£Á†ÅÔºåÂÅöÂ•ΩÊ†áËØÜ
                        file_operate_ctl(FOP_ALLFILE_ERR_LGDEV,mapi->fop_api,0,0);
                        err=FILE_OP_ERR_NO_FILE_ONEDEV;
                        totalerrfile=0;
                        break;
                    }
                    if(file_auto_next)
                    {
                        //dec_phy_printf("err next \r");
                        err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_NEXT_FILE,&(mapi->dop_api->file_num));
                    }
                    else
                    {
                        //dec_phy_printf("err priv \r");
                        err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_PREV_FILE,&(mapi->dop_api->file_num));
                    }
                    if((err!=FILE_OP_ERR_OPEN_FILE)&&(err!=ERR_MUSIC_START_DEC))
                    {
                        ///<‰∏çÂÜçÊòØÈ°∫Â∫èÊâæÔºåÊ∏ÖÁ©∫ÈîôËØØÊï∞Â≠ó
                        totalerrfile=0;
                    }
                    break;
                case ERR_MUSIC_API_NULL:
                    //dec_phy_printf("err  : %02x\r",err);
                    err = 0;
                    break;
                case FILE_OP_ERR_END_FILE:
                    mapi->dop_api->file_num = 1;
                    err = music_play_api(mapi,DEV_SEL_NEXT,0,PLAY_FIRST_FILE,&(mapi->dop_api->file_num));
                    break;
                case FILE_OP_ERR_PRE_FILE:
                    mapi->dop_api->file_num = 1;
                    err = music_play_api(mapi,DEV_SEL_PREV,0,PLAY_LAST_FILE,&(mapi->dop_api->file_num));
                    break;
                default:
                    //dec_phy_printf("err default : %02x\r",err);
                    err = music_play_api(mapi,DEV_SEL_CUR,0,PLAY_NEXT_FILE,0);
                    // printf("err my \n");
                    break;
                }
            }
        }

        {
            ////dec_phy_printf("no err\n");
        }
        Update_rcsp_Task_State(msg[0],0);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief  ÂàõÂª∫Èü≥‰πêÁ∫øÁ®ã
   @param  priv -- Á∫øÁ®ãËæìÂÖ•ÂèÇÊï∞
   @return void
   @note
*/
/*----------------------------------------------------------------------------*/
static void music_task_init(void *priv)
{
    u32 err;

//      GET_SYS_MEM_STAT();

    err = os_task_create_ext(music_task, 0, TaskMusicPrio, 50, "MusicTask", MUSIC_TASK_STACK_SIZE);
    if(OS_NO_ERR == err)
    {
  	 #ifdef SUPPORT_TM1628_KEY_READ
      	  key_msg_register("MusicTask",music_led_table,music_ad_table,NULL,music_ir_table,NULL);
	 #else    
     	   key_msg_register("MusicTask",music_ad_table,NULL,music_ir_table,NULL);
	 #endif
        // puts("open_music_task: succ\n");
    }
	
#ifdef SUPPORT_PT2313
	Pt2313_ChangSource(Aud_SwMP3);
#endif    

#ifdef support_sound_4052_control
	AC4052_IS_MP3();
#endif
#ifdef KOK_DETECT_AUTO_VOL_SET
///	 store_vol= dac_ctl.sys_vol_l;
	dac_ctl.sys_vol_l = 30;
	dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;
	set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);


#endif



#if defined(LED_ID_JW2781)
	led7_var.bEqCircleIfPlay=TRUE;
#endif
 #ifdef SUPPORT_MUSIC_PREV_NEXT_VOICE
 		bPrevNextVoiceFlag=0;		
 #endif

}

/*----------------------------------------------------------------------------*/
/**@brief  ÈÄÄÂá∫Èü≥‰πêÁ∫øÁ®ã
   @param  void
   @return void
   @note
*/
/*----------------------------------------------------------------------------*/
static void music_task_exit()
{
    if (os_task_del_req("MusicTask") != OS_TASK_NOT_EXIST)
    {
        os_taskq_post_event("MusicTask", 1, SYS_EVENT_DEL_TASK);
        do
        {
            OSTimeDly(1);
        }
        while(os_task_del_req("MusicTask") != OS_TASK_NOT_EXIST);
        // puts("del_music_task: succ\n");
    }

#ifdef SUPPORT_MUSIC_ALWAY_FIRST_PLAY_USE_MODE
	if(file_operate_get_total_phydev()>1)
                curr_device_using = (u32)usb;
#endif

//      GET_SYS_MEM_STAT();
}


TASK_REGISTER(music_task_info) =
{
    .name = "MusicTask",
    .init = music_task_init,
    .exit = music_task_exit,
};

