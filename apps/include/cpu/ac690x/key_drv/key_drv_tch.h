#ifndef	_TOUCH_KEY_API_H_
#define _TOUCH_KEY_API_H_

#include "includes.h"
#include "key_drv/key.h"

#if KEY_TCH_EN

#ifdef ds_k6111_key_mode
#define TOUCH_KEY_CH_MAX	5   //16
#define  TOUCH_IO_TYPE   1     ///0--PORT A,1--PORT B,2--PORT C,3--PORT D

//ռ��PB8~PB15
#define  TCH_PORT_OUT     JL_PORTB->OUT
#define  TCH_PORT_HD       JL_PORTB->HD
#define  TCH_PORT_DIR      JL_PORTB->DIR
#define  TCH_PORT_PD       JL_PORTB->PD
#define  TCH_PORT_PU       JL_PORTB->PU

#else 
#define TOUCH_KEY_CH_MAX	1//16
#define  TOUCH_IO_TYPE   0 ///0--PORT A,1--PORT B,2--PORT C,3--PORT D

//ռ��PB8~PB15
#define  TCH_PORT_OUT     JL_PORTA->OUT
#define  TCH_PORT_HD       JL_PORTA->HD
#define  TCH_PORT_DIR      JL_PORTA->DIR
#define  TCH_PORT_PD       JL_PORTA->PD
#define  TCH_PORT_PU       JL_PORTA->PU

#endif 

typedef struct _CTM_KEY_VAR
{
    s32 touch_release_buf[TOUCH_KEY_CH_MAX]; 		//�����ͷ�ֵ�˲���buffer
    u16 touch_cnt_buf[TOUCH_KEY_CH_MAX];			//��������ֵ�˲���buffer
    s16 FLT1CFG1;					//�˲���1���ò���1
    s16 FLT1CFG2;					//�˲���1���ò���2, ����(-RELEASECFG0)<<FLT1CFG0
    s16 PRESSCFG;					//�����о�����
    s16 RELEASECFG0;				//�ͷ��о�����0
    s16 RELEASECFG1;				//�ͷ��о�����1
    s8  FLT0CFG;					//�˲���0���ò���(0/1/2/3)
    s8  FLT1CFG0;					//�˲���1���ò���0
    u16 touch_key_state;			//����״̬��־����ʱ���ܱ��жϸ�д���������������Ҫ���˱�־���Ƴ������д���
    u8  touch_init_cnt[TOUCH_KEY_CH_MAX];				//��ʼ������������0ʱ���г�ʼ��
} sCTM_KEY_VAR;





//IO port denfine
#define  TCH_KEY0_IO_BIT   7
#define  TCH_KEY1_IO_BIT   8
#define  TCH_KEY2_IO_BIT   9
//#define  TCH_KEY3_IO_BIT   11
//#define  TCH_KEY4_IO_BIT   12
//#define  TCH_KEY5_IO_BIT   13
//#define  TCH_KEY6_IO_BIT   14



tu8 get_tchkey_value(void);
void tch_key_init(void);
void scan_capkey(void);

extern u8 touchkey_short_msg;
extern u8 g_touch_len; //����������

#endif

#endif  /*  _TOUCH_KEY_API_H_   */


