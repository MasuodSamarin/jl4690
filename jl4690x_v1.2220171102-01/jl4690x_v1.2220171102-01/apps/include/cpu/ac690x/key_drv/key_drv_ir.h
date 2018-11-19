#ifndef __KEY_DRV_IR_H__
#define __KEY_DRV_IR_H__

#include "includes.h"
#include "key_drv/key.h"

/*------------------------------------------------------------------------
 *  IRFLT IO SEL：
 *  0x00--0x0f   PA[0:15]
 *  0x10--0x1f   PB[0:15]
 *  0x20--0x2f   PC[0:15] 
 *  0x30--0x37   PD[0:7]
 *  0x38--0x3d   Reserved
 *  0x3e         USBDP
 *  0x3f         USBDM
 * ----------------------------------------------------------------------*/
#define IR_PORTA(x) (0x00 + x)
#define IR_PORTB(x) (0x10 + x)
#define IR_PORTC(x) (0x20 + x)
#define IR_PORTD(x) (0x30 + x)

#define IR_USBDP    (0x3E)
#define IR_USBDM 	(0x3F)



#if KEY_IR_EN

#if defined(SUPPORT_IR_USE_SINGLE_MSG) ||defined(ir_kpl_HY_ir_001) ||defined(IR_USER_sdx_001) ||defined(IR_USER_hcx_2ir) ||defined(ir_user_kpl_ty_msg_0to_light) \
	||defined IR_USER_sx_ir1 ||defined IR_USER_wes_ir_116_2700b    //按键表内定义

#else 

#define       IRC_NUM0                             0  /*09*/ 
#define       IRC_NUM1                             1  /*12*/
#define       IRC_NUM2                             2  /*13*/
#define       IRC_NUM3                             3  /*14*/
#define       IRC_NUM4                             4  /*15*/
#define       IRC_NUM5                             5  /*16*/ 
#define       IRC_NUM6                             6  /*17*/ 
#define       IRC_NUM7                             7  /*18*/ 
#define       IRC_NUM8                             8 /*19*/
#define       IRC_NUM9                             9  /*20*/
#define       IRC_STANBY                         10 /*20*/
#define       IRC_MODE                             11      /*01*/
#define       IRC_MUTE                             12 /*20*/
#define       IRC_PLAY_PAUSE                  13     /*03*/ 
#define       IRC_PREV                              14     /*04*/
#define       IRC_NEXT                              15   /*05*/  
#define       IRC_VOL_UP                          16/*08*/ 
#define       IRC_VOL_DN                          17       /*07*/ 
#define       IRC_USB_SD                         18
#define       IRC_EQ                             19   /*06*/
#define       IRC_REPEAT                     20/*10*/ 
#define       IRC_FM_CHINC                 21 /*21*/
#define       IRC_FM_CHDEC                 22 /*22*/
#define       IRC_BT_MODE                          23

#define       IRC_ADD100                      24/*11*/
#define       IRC_ONLY_PREV                  25     /*04  不复合 CH-*/
#define       IRC_ONLY_NEXT                  26   /*05    不复合 CH+*/  
#define       IRC_STOP                                27 

#define       IRC_USB_SD_FM_SCAN             28
#define       IRC_ONLY_PLAY_PAUSE            29
#define       IRC_FM_MODE                           30
#define       IRC_LINE_MODE                        31
#define       IRC_MUSIC_MODE                      32

#endif 


typedef struct _IR_CODE
{
    u16 wData;          //<键值
    u8  bState;         //<接收状态
    u16 wUserCode;      //<用户码
    u8  boverflow;      //<红外信号超时
} IR_CODE;

tu8 get_irkey_value(void);
extern void ir_count(void);
extern s32 ir_key_init(void);
extern  u8  ir_key_get_value(void);
extern  u8  ir_key_pressed_to_msg(u8 key_style, u8 key_num);
extern void ir_timeout(void *param);
extern void set_ir_clk(void);
extern s32 ir_key_ck_reset(void);
#endif

extern u16 timer2_pad;

#endif

