#include "sdk_cfg.h"
#include "dev_linein.h"
#include "dev_manage/device_driver.h"
#include "common/msg.h"
#include "linein.h"
#include "rtc/rtc_api.h"
#include "key_drv/key_drv_ad.h"

//ȫ�ֱ���
AUX_VAR g_aux_var; ///<line in������
#if  AUX_DETECT_EN

#ifdef support_line_chack_user_ad  //330K

u16 aux_check_adc_value(void)
{
    if(adc_value[AD_CH_KEY]>VOL_AD_NOKEY)
	      return TRUE;
    else if((adc_value[AD_CH_KEY]<VOL_AD_NOKEY)&&(adc_value[AD_CH_KEY]>VOL_AD_AUX_IN))
       return FALSE;
   else
        return TRUE;  	

}

#endif

/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼��ʵ�庯��
   @param  cnt������˲�����
   @return �������
   @note   AUX_STATUS linein_check(u8 cnt)
*/
/*----------------------------------------------------------------------------*/
AUX_STATUS linein_check(u8 cnt)
{
    u16 cur_aux_status;

#ifdef support_line_chack_user_ad  //330K
    cur_aux_status = aux_check_adc_value(); //��ȡ��ǰAUX״̬
#else	
    cur_aux_status = AUX_IN_CHECK; //��ȡ��ǰAUX״̬
#endif    

//printf("--------cur_aux_status---------------%x\n",cur_aux_status);

    if(cur_aux_status != g_aux_var.pre_status)
    {
        g_aux_var.pre_status = cur_aux_status;
        g_aux_var.status_cnt = 0;
//	printf("--------111--------------\n");
		
    }
    else
    {
//	printf("--------g_aux_var.status_cnt---------------%x\n",g_aux_var.status_cnt);
//	printf("--------g_aux_var.bDevOnline---------------%x\n",g_aux_var.bDevOnline);
//	printf("--------g_aux_var.pre_status---------------%x\n",g_aux_var.pre_status);
	
	g_aux_var.status_cnt++;
    }

#ifdef AUX_OUT_WITHOUT_CNT
///*//////�γ���ȥ��////////
    if((AUX_ON == g_aux_var.bDevOnline) && g_aux_var.pre_status)
    {
        g_aux_var.bDevOnline = AUX_OFF;
        return AUX_OFF;
    }
///*/////////////////////
#endif

    if(g_aux_var.status_cnt < cnt) //����
    {
//	printf("--------333--------------\n");    
        return NULL_AUX;
    }
	
    g_aux_var.status_cnt = 0;

    ///��⵽AUX����
    if((AUX_OFF == g_aux_var.bDevOnline) && (!g_aux_var.pre_status))
    {
//	printf("--------g_aux_var.bDevOnline---------------%x\n",g_aux_var.bDevOnline);
    
        g_aux_var.bDevOnline = AUX_ON;
        return AUX_ON;
    }
#ifndef AUX_OUT_WITHOUT_CNT
    ///��⵽AUX�γ�
    else if((AUX_ON == g_aux_var.bDevOnline) && g_aux_var.pre_status)
    {
        g_aux_var.bDevOnline = AUX_OFF;
//	printf("--------g_aux_var.bDevOnline---------------%x\n",g_aux_var.bDevOnline);		
        return AUX_OFF;
    }
#endif
//	printf("--------444--------------\n");

    return NULL_AUX;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼����Ⱥ���
   @param  ��
   @return �������
   @note   s32 aux_detect(void)
*/
/*----------------------------------------------------------------------------*/
s32 aux_detect(void)
{
    u32 dev_cur_sta = DEV_HOLD;
    AUX_STATUS res;

    res = linein_check(20); //aux���߼�⣬ȥ������Ϊ50
    
    if(AUX_OFF == res)
    {
        aux_puts("AUX_off\n");
        dev_cur_sta = DEV_OFFLINE;
    }
    else if(AUX_ON == res)
    {
        aux_puts("AUX_on\n");
        dev_cur_sta = DEV_ONLINE;
    }

    if(g_aux_var.last_sta == dev_cur_sta)
    {
        return DEV_HOLD;//�豸״̬���ֲ���
    }

    g_aux_var.last_sta = dev_cur_sta;

    return dev_cur_sta;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ����״̬
   @param  ��
   @return LINE IN�������
   @note   u32 aux_is_online(void)
*/
/*----------------------------------------------------------------------------*/
u32 aux_is_online(void)
{
    return g_aux_var.bDevOnline;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ģ���ʼ������
   @param  ��
   @return ��
   @note   void aux_init_api(void)
*/
/*----------------------------------------------------------------------------*/
void aux_init_api(void)
{
    /*linein check port set*/
    AUX_DIR_SET;
    AUX_PU_SET;
    my_memset((u8 *)&g_aux_var, 0, sizeof(AUX_VAR));
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN �����б�
   @note   const u8 aux_event_tab[]
*/
/*----------------------------------------------------------------------------*/
const u8 aux_event_tab[] =
{
    SYS_EVENT_AUX_OUT, //LINE IN�γ�
    SYS_EVENT_AUX_IN,  //LINE IN����
};


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼��API����
   @param  ��
   @return ��
   @note   void aux_check_api(void)
*/
/*----------------------------------------------------------------------------*/
void aux_check_api(u32 info)
{
    s32 dev_status;

    dev_status = aux_detect();
    if(dev_status != DEV_HOLD)
    {
		 #ifdef SUPPORT_DOUBLE_LINEIN
		      bAux2Flag=dev_status;
		 #endif                
    
        os_taskq_post_event(MAIN_TASK_NAME, 2, aux_event_tab[dev_status],info);
    }
}
#endif

#ifdef PHONE_CHECK_ENABLE

//ȫ�ֱ���
AUX_VAR g_phone_var; ///<line in������



#ifdef SUPPORT_AMP_MUTE_EXTERN_AD_DET  //330K

u16 phone_check_adc_value(void)
{

	u16 ad_comparion_value=adc_value[AD_CH_AD_COMPARION];//1023;//led7_var.wAdc_value;	
	u16 bAdValue=adc_value[AD_CH_EXTERN_AMP];//1023;//led7_var.wAdc_value;


	//printf("--------bAdValue--------%d\n",bAdValue);

    if(bAdValue>(203*(ad_comparion_value/25)/10))
	return TRUE; 
   else
        return FALSE; 	

}

#endif


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼��ʵ�庯��
   @param  cnt������˲�����
   @return �������
*/
/*----------------------------------------------------------------------------*/
AUX_STATUS phone_check(u8 cnt)
{
    u16 cur_phone_status;

#if defined(support_phone_chack_user_PC15)
    PHONE_DIR_SET ;
    PHONE_PU_SET  ;
#endif

#if defined(support_phone_chack_user_SD_PA2) ||defined(support_dls_user_pa5_check_phone_line)
    cur_phone_status =   adk_phone_flag;
#elif defined SUPPORT_AMP_MUTE_EXTERN_AD_DET  //330K
    cur_phone_status = phone_check_adc_value(); //��ȡ��ǰAUX״̬
#else
    cur_phone_status = PHONE_IN_CHECK; //��ȡ��ǰAUX״̬
#endif

    if(cur_phone_status != g_phone_var.pre_status)
    {
        g_phone_var.pre_status = cur_phone_status;
        g_phone_var.status_cnt = 0;
    }
    else
    {
        g_phone_var.status_cnt++;
    }
	
    if(g_phone_var.status_cnt < cnt) //����
    {
        return NULL_AUX;
    }
    g_phone_var.status_cnt = 0;

    ///��⵽��������
    if((AUX_OFF == g_phone_var.bDevOnline) && (!g_phone_var.pre_status))
    {
        g_phone_var.bDevOnline = AUX_ON;
        return AUX_ON;
    }
    ///��⵽�����γ�
    else if((AUX_ON == g_phone_var.bDevOnline) && g_phone_var.pre_status)
    {
        g_phone_var.bDevOnline = AUX_OFF;
        return AUX_OFF;
    }

    return NULL_AUX;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼����Ⱥ���
   @param  ��
   @return �������
*/
/*----------------------------------------------------------------------------*/
s32 phone_detect(void)
{
    u32 dev_cur_sta = DEV_HOLD;
    AUX_STATUS res;

    res = phone_check(50); //aux���߼�⣬ȥ������Ϊ50
    
    if(AUX_OFF == res)
    {
        aux_puts("phone_off\n");
        dev_cur_sta = DEV_OFFLINE;
    }
    else if(AUX_ON == res)
    {
        aux_puts("phone_on\n");
        dev_cur_sta = DEV_ONLINE;
    }

    if(g_phone_var.last_sta == dev_cur_sta)
    {
        return DEV_HOLD;//�豸״̬���ֲ���
    }

    g_phone_var.last_sta = dev_cur_sta;

    return dev_cur_sta;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ����״̬
   @param  ��
   @return LINE IN�������
   @note   u8 aux_is_online(void)
*/
/*----------------------------------------------------------------------------*/
u8 phone_is_online(void)
{
    return g_phone_var.bDevOnline;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ģ���ʼ������
   @param  ��
   @return ��
   @note   void aux_init_api(void)
*/
/*----------------------------------------------------------------------------*/
void phone_init_api(void)
{
#if !defined SUPPORT_AMP_MUTE_EXTERN_AD_DET  //330K

    PHONE_DIR_SET;
    PHONE_PU_SET;
#endif	
    my_memset((u8 *)&g_phone_var, 0, sizeof(AUX_VAR));
}






/*----------------------------------------------------------------------------*/
/**@brief  LINE IN �����б�
   @note   const u8 aux_event_tab[]
*/
/*----------------------------------------------------------------------------*/
const u8 PHONE_event_tab[] =
{
    SYS_EVENT_PHONE_OUT, //PHONE  IN�γ�
    SYS_EVENT_PHONE_IN,  //PHONE IN����
};



/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼��API����
   @param  ��
   @return ��
   @note   void aux_check_api(void)
*/
/*----------------------------------------------------------------------------*/
void phone_check_api(u32 info)
{
    s32 dev_status;
	
	if(play_rec_last_file)
	return;

    dev_status = phone_detect();
    if(dev_status != DEV_HOLD)
    {
        os_taskq_post_event("MainTask", 2, PHONE_event_tab[dev_status],info);
    }
}
#endif

/*----------------------------------------------------------------------------*/
/*
		 ��Ͳ���ȼ��
*/
/*----------------------------------------------------------------------------*/

#if MIC_CHECK_ENABLE	

#ifdef MIC_CHECK_OUT_VOL_X_STEP	
u8 bMicSysVolBuf;
#include "dac/dac.h"
#endif

#ifdef KOK_DETECT_USE_IO_ADC_VALUE
#include "key_drv/key_drv_ad.h"
#include "dac/dac_api.h"
#ifdef KOK_DETECT_USE_ADKEY_AS_DET

 #define KOK_VOLATAGE  1023*32/33 

#define KOK_VOLATAGE_ADKEY_NOKEY  1023*29/33 
#else
//#define KOK_VOLATAGE  1023*4/33 
#define KOK_VOLATAGE  1023*1/33 
#endif

u16 kok_check_adc_value(void)
{

//    printf("--AD_CH_KOK ---  %d\n",adc_value[AD_CH_KOK]);
//    if(adc_value[AD_CH_KOK]==1023)
	 #ifdef KOK_DETECT_USE_ADKEY_AS_DET	 
	     if((adc_value[AD_CH_KOK]<KOK_VOLATAGE)&&(adc_value[AD_CH_KOK]>KOK_VOLATAGE_ADKEY_NOKEY))
	       return FALSE ;
	     else 
	       return TRUE;
	 
	 #else
	 
	     if(adc_value[AD_CH_KOK]>KOK_VOLATAGE)
	       return FALSE;
	     else
	       return TRUE;
	 #endif

}
#endif


//ȫ�ֱ���
AUX_VAR g_mic_var; ///<line in������


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼��ʵ�庯��
   @param  cnt������˲�����
   @return �������
*/
/*----------------------------------------------------------------------------*/
AUX_STATUS mic_check(u8 cnt)
{
    u16 cur_mic_status;

    #ifdef KOK_DETECT_USE_IO_ADC_VALUE
    cur_mic_status=kok_check_adc_value();
    #else
    cur_mic_status = MIC_IN_CHECK; //��ȡ��ǰAUX״̬
    #endif

    if(cur_mic_status != g_mic_var.pre_status)
    {
        g_mic_var.pre_status = cur_mic_status;
        g_mic_var.status_cnt = 0;
    }
    else
    {
        g_mic_var.status_cnt++;
    }
    if(g_mic_var.status_cnt < cnt) //����
    {
        return NULL_AUX;
    }
    g_mic_var.status_cnt = 0;

 #ifdef support_high_mic_in
    ///��⵽��������
    if((AUX_OFF == g_mic_var.bDevOnline) && ( g_mic_var.pre_status))
    {

           g_mic_var.bDevOnline = AUX_ON;
             return AUX_ON;
  
    }
    ///��⵽�����γ�
    else if((AUX_ON == g_mic_var.bDevOnline) && !g_mic_var.pre_status)
    {

            g_mic_var.bDevOnline = AUX_OFF;
            return AUX_OFF; 
    }

#else 
	

    ///��⵽��������
    if((AUX_OFF == g_mic_var.bDevOnline) && (!g_mic_var.pre_status))
    {

           g_mic_var.bDevOnline = AUX_ON;
             return AUX_ON; 
    }
    ///��⵽�����γ�
    else if((AUX_ON == g_mic_var.bDevOnline) && g_mic_var.pre_status)
    {
            g_mic_var.bDevOnline = AUX_OFF;
            return AUX_OFF; 

    }
#endif 
	

    return NULL_AUX;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼����Ⱥ���
   @param  ��
   @return �������
*/
/*----------------------------------------------------------------------------*/

s32 mic_detect(void)
{
    u32 dev_cur_sta = DEV_HOLD;
    AUX_STATUS res;
	
#ifdef MIC_CHECK_OFF_DELAY_TIME  
static bool bMicOffCnt=0;

	if(bMicOffCnt)
	    res = mic_check(80); //aux���߼�⣬ȥ������Ϊ50		
	else
#endif


#ifdef MIC_CHECK_TIMER		
	    res = mic_check(MIC_CHECK_TIMER); //aux���߼�⣬ȥ������Ϊ50
#else
	    res = mic_check(20); //aux���߼�⣬ȥ������Ϊ50
#endif



   #ifdef MIC_CHECK_OFF_DELAY_TIME  
   
    if(AUX_OFF == res)
    {
        bMicOffCnt=0;    
   	 dev_cur_sta = DEV_OFFLINE;
		
    }
    else if(AUX_ON == res)
    {
        bMicOffCnt=1;    
        printf("mic-i\n");
        dev_cur_sta = DEV_ONLINE;

		
    }
		
#else

    if(AUX_OFF == res)
    {
        printf("mic-o \n");
        dev_cur_sta = DEV_OFFLINE;
    }

    else if(AUX_ON == res)
    {
        printf("mic-i\n");
        dev_cur_sta = DEV_ONLINE;
    }
		
#endif	

     if(g_mic_var.last_sta == dev_cur_sta)
     {
         return DEV_HOLD;//�豸״̬���ֲ���
     }
 	
     g_mic_var.last_sta = dev_cur_sta;

    return dev_cur_sta;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ����״̬
   @param  ��
   @return LINE IN�������
   @note   u8 aux_is_online(void)
*/
/*----------------------------------------------------------------------------*/
u8 mic_is_online(void)
{
    return g_mic_var.bDevOnline;
}


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ģ���ʼ������
   @param  ��
   @return ��
   @note   void aux_init_api(void)
*/
/*----------------------------------------------------------------------------*/
void mic_init_api(void)
{

#if !defined(KOK_DETECT_USE_IO_ADC_VALUE)
    MIC_DIR_SET;
   MIC_PU_SET;
#endif    
    my_memset((u8 *)&g_mic_var, 0, sizeof(AUX_VAR));
}






/*----------------------------------------------------------------------------*/
/**@brief  LINE IN �����б�
   @note   const u8 aux_event_tab[]
*/
/*----------------------------------------------------------------------------*/
const u8 MIC_event_tab[] =
{
    SYS_EVENT_MIC_OUT, //PHONE  IN�γ�
    SYS_EVENT_MIC_IN,  //PHONE IN����
};


/*----------------------------------------------------------------------------*/
/**@brief  LINE IN ���߼��API����
   @param  ��
   @return ��
   @note   void aux_check_api(void)
*/
/*----------------------------------------------------------------------------*/
 #ifdef KOK_DETECT_AUTO_VOL_SET			
 bool auto_vol_sw; // 0 off   1 on
 u8 store_vol; // 
#include "dac/dac.h"
#include "ui/ui_api.h"

void vol_auto_inc(void)
{
	static bool store_vol_sw;

	if(store_vol_sw!=auto_vol_sw)
	{
		if((auto_vol_sw==1)&&(dac_ctl.sys_vol_l >AUTO_VOL_SET_DEC))
		{
			dac_ctl.sys_vol_l=AUTO_VOL_SET_DEC;
			dac_ctl.sys_vol_r=dac_ctl.sys_vol_l;
	                set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);	
		}
	}
	
	 if((auto_vol_sw==0)&&(dac_ctl.sys_vol_l <store_vol))
	  {
	 	dac_ctl.sys_vol_l++;
	 	dac_ctl.sys_vol_r=dac_ctl.sys_vol_l;
	 	set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);
	 	UI_menu(MENU_MAIN_VOL);
	 	 #if 0
	 	 	if(dac_ctl.sys_vol_l ==store_vol)
	 	 	{
	 	 	vm_cache_write(VM_SYS_VOL,&dac_ctl.sys_vol_l,2);	
	 	 	}		   
	 	 #endif
	}
	 
	store_vol_sw=auto_vol_sw;

}
 

#endif


void MIC_check_api(u32 info)
{
    s32 dev_status;
	
  //  MIC_DIR_SET;
    dev_status = mic_detect();

//	printf("-----mic_sw-------%d",mic_sw);

	//	printf("--------dev_status--------%d\n",dev_status);	
	
    if(dev_status != DEV_HOLD)
    {
		 #if  MIC_ONOFF_KEY
		 
			#ifdef MIC_CHECK_OUT_VOL_X_STEP	
			

			         if(dev_status==DEV_ONLINE)  
				  {		 		
					
			 		if(mic_sw) 
			 			{
//			             			dac_mute(1,1);

							bMicSysVolBuf=dac_ctl.sys_vol_l;
							dac_ctl.sys_vol_l = 10;
							dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;
							set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);
									
			 			}
			       //      else
			             	{
//			 		      dac_mute(0,1);			  
//							dac_ctl.sys_vol_l = bMicSysVolBuf;
//							dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;
//							set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);

			             	}
						 				
			            }
			         else if(dev_status==DEV_OFFLINE)
			             	{
				 		if(mic_sw) 
				             	{
	//			 		      dac_mute(0,1);			  
							dac_ctl.sys_vol_l = bMicSysVolBuf;
							dac_ctl.sys_vol_r = dac_ctl.sys_vol_l;
							set_sys_vol(dac_ctl.sys_vol_l, dac_ctl.sys_vol_r, FADE_OFF);
				         	}

			             	}
			//#elif defined KOK_DETECT_AUTO_VOL_SET
			//         if(dev_status==DEV_ONLINE) 
			//		auto_vol_sw=1;		
			//	 else if(dev_status==DEV_OFFLINE)
			//		auto_vol_sw=0;		
		 //	printf("--------auto_vol_sw---------------%d\n",auto_vol_sw);
			#else
			
			         if(dev_status==DEV_ONLINE)  
				  {		 							
			 		if(mic_sw) 
		 			{
						#ifdef KOK_DETECT_AUTO_VOL_SET
							auto_vol_sw=1;		
						#else
		             				dac_mute(1,1);
						#endif
		 			}
			             else
			             	{
						#ifdef KOK_DETECT_AUTO_VOL_SET
							auto_vol_sw=0;
						#else
			 		    		  dac_mute(0,1);		
						#endif
			             	}
						 				
			            }
			         else if(dev_status==DEV_OFFLINE)
			         	{					 
						#ifdef KOK_DETECT_AUTO_VOL_SET
							auto_vol_sw=0;		
						#else
					 		dac_mute(0,1);
						#endif
			         	}
			#endif
			
		 #else		
		         os_taskq_post_event("MainTask", 2, MIC_event_tab[dev_status],info);
		 #endif
    }
}
#endif 



