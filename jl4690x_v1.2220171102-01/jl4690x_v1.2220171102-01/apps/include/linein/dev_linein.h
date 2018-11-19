#ifndef __DEV_LINEIN_H__
#define __DEV_LINEIN_H__

#include "typedef.h"

#define AUX_CHECK_ENABLE   //aux模式是否被AUX在线离线消息影响


typedef enum __AUX_STATUS
{
    AUX_OFF = 0,
    AUX_ON,
    NULL_AUX,
} AUX_STATUS;

typedef struct __AUX_VAR
{
    u16 pre_status;
    u8  status_cnt;
    u8  bDevOnline;
    u32 last_sta;
} AUX_VAR;


void aux_init_api(void);
void aux_check_api(u32 info);
u32 aux_is_online(void);


#ifdef PHONE_CHECK_ENABLE
void   phone_check_api(u32 info); //耳机检测
void phone_init_api(void);
u8 phone_is_online(void);

#endif

#if MIC_CHECK_ENABLE
void  MIC_check_api(u32 info); //MIC检测
void mic_init_api(void);
u8 mic_is_online(void);
//全局变量
extern AUX_VAR g_mic_var; ///<line in检测变量
 #ifdef KOK_DETECT_AUTO_VOL_SET			
void vol_auto_inc(void);
#endif
#endif
#endif/*__DEV_LINEIN_H__*/

