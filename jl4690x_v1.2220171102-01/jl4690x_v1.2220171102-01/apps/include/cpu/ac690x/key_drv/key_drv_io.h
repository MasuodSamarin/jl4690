#ifndef __KEY_DRV_IO_H__
#define __KEY_DRV_IO_H__

#include "sdk_cfg.h"
#include "sys_detect.h"
#include "rtc/rtc_api.h"

#if KEY_IO_EN

#ifdef MINI
// #define IS_KEY0_DOWN()    (!PORTR_IN(PORTR2))  //PP PR2
// #define IS_KEY1_DOWN()    (!(JL_PORTA->IN&BIT(1))) //V+
// #define IS_KEY2_DOWN()    0                    //V-
// #define IS_KEY3_DOWN()    0
// #define KEY_INIT()        do{PORTR_PU(PORTR2,1);PORTR_PD(PORTR2,0); JL_PORTA->PU |= BIT(1);JL_PORTA->PD &= ~BIT(1);\
// PORTR_DIR(PORTR1,1);JL_PORTA->DIR |= BIT(1);}while(0)
//set usb_io to key_io
#define IS_KEY0_DOWN()    (!PORTR_IN(PORTR2))  //PP PR2
#define IS_KEY1_DOWN()    (!USB_IO_DP_IN())       //V+
#define IS_KEY2_DOWN()    (!USB_IO_DM_IN())       //V-
#define IS_KEY3_DOWN()    0
#define KEY_INIT()        do{PORTR_PU(PORTR2,1);PORTR_PD(PORTR2,0);PORTR_DIR(PORTR2,1);\
	   							USB_DM_PU(1);USB_DM_PD(0);USB_DM_DIR(1);\
	   							USB_DP_PU(1);USB_DP_PD(0);USB_DP_DIR(1);\
  							   }while(0)
#elif defined(support_io_scan_user_PR2)
#define IS_KEY0_DOWN()	  (!PORTR_IN(PORTR2))  //PP PR0
#define KEY_INIT()		  do{PORTR_PU(PORTR2,1);PORTR_PD(PORTR2,0); PORTR_DIR(PORTR2,1);}while(0)
#elif defined(support_io_scan_user_PB8PB9PB11)
#define IS_KEY1_DOWN()	  (!(JL_PORTB->IN&BIT(8)))
#define IS_KEY2_DOWN()	  (!(JL_PORTB->IN&BIT(9)))
#define IS_KEY3_DOWN()	  (!(JL_PORTB->IN&BIT(11)))
//     #define IS_KEY3_DOWN()	  0
#define KEY2_OUT_L()	  do{JL_PORTB->DIR &= ~BIT(9);JL_PORTA->OUT &= ~BIT(9);}while(0)
#define KEY2_OUT_H()	  do{JL_PORTB->DIR &= ~BIT(9);JL_PORTA->OUT |=BIT(9);}while(0)
//     #define KEY2_OUT_L()	  do{JL_PORTB->DIR &= ~BIT(9);JL_PORTA->OUT &= ~BIT(9);}while(0)
#define KEY_INIT()		  do{JL_PORTB->PU |= BIT(8)|BIT(9)|BIT(11);JL_PORTB->DIR |= BIT(8)|BIT(9)|BIT(11);}while(0)

#elif defined(support_io_scan_user_PB11PB10PB9PB8PB12)
#define IS_KEY0_DOWN()	  (!(JL_PORTB->IN&BIT(11)))
#define IS_KEY1_DOWN()	  (!(JL_PORTB->IN&BIT(10)))
#define IS_KEY2_DOWN()	  (!(JL_PORTB->IN&BIT(9)))
#define IS_KEY3_DOWN()	  (!(JL_PORTB->IN&BIT(8)))
#define IS_KEY4_DOWN()	  (!(JL_PORTB->IN&BIT(12)))
#define KEY_INIT() do{JL_PORTB->PU |= BIT(11)|BIT(10)|BIT(9)|BIT(8)|BIT(12);JL_PORTB->DIR |= BIT(11)|BIT(10)|BIT(9)|BIT(8)|BIT(12);}while(0)



#elif defined(support_io_scan_user_PB8PB9PB10PB11PB12)
#define IS_KEY0_DOWN()	  (!(JL_PORTB->IN&BIT(12)))
#define IS_KEY1_DOWN()	  (!(JL_PORTB->IN&BIT(11)))
#define IS_KEY2_DOWN()	  (!(JL_PORTB->IN&BIT(10)))
#define IS_KEY3_DOWN()	  (!(JL_PORTB->IN&BIT(9)))
#define IS_KEY4_DOWN()	  (!(JL_PORTB->IN&BIT(8)))
#define KEY_INIT() do{JL_PORTB->PU |= BIT(11)|BIT(10)|BIT(9)|BIT(8)|BIT(12);JL_PORTB->DIR |= BIT(11)|BIT(10)|BIT(9)|BIT(8)|BIT(12);}while(0)

#define  SET_KEY0_LOW()	do{JL_PORTB->DIR &= ~BIT(8);JL_PORTB->OUT &= ~BIT(8);}while(0)
#define  SET_KEY0_HIGH()do{JL_PORTB->DIR &= ~BIT(8);JL_PORTB->OUT |=BIT(8);}while(0)


#elif defined(support_io_scan_user_PB12PB11PB10PB9PB3)

#define IS_KEY4_DOWN()	  (!(JL_PORTB->IN&BIT(3)))
#define IS_KEY3_DOWN()	  (!(JL_PORTB->IN&BIT(9)))
#define IS_KEY2_DOWN()	  (!(JL_PORTB->IN&BIT(10)))
#define IS_KEY1_DOWN()	  (!(JL_PORTB->IN&BIT(11)))
#define IS_KEY0_DOWN()	  (!(JL_PORTB->IN&BIT(12)))

#define KEY_INIT() do{JL_PORTB->PU |= BIT(11)|BIT(10)|BIT(9)|BIT(3)|BIT(12);JL_PORTB->DIR |= BIT(11)|BIT(10)|BIT(9)|BIT(3)|BIT(12);}while(0)

#define  SET_KEY4_LOW()	do{JL_PORTB->DIR &= ~BIT(3);JL_PORTB->OUT &= ~BIT(3);}while(0)
#define  SET_KEY4_HIGH()do{JL_PORTB->DIR &= ~BIT(3);JL_PORTB->OUT |=BIT(3);}while(0)

#else
#define IS_KEY0_DOWN()    (!(JL_PORTB->IN&BIT(8)))
#define IS_KEY1_DOWN()    (!(JL_PORTB->IN&BIT(9)))
#define IS_KEY2_DOWN()    (!(JL_PORTB->IN&BIT(10)))
#define IS_KEY3_DOWN()    0
//#define KEY1_OUT_L()      do{PORTA_DIR &= ~BIT(13);PORTA_OUT &= ~BIT(13);}while(0)
#define KEY_INIT()        do{JL_PORTB->PU |= BIT(8)|BIT(9)|BIT(10);JL_PORTB->DIR |= BIT(8)|BIT(9)|BIT(10);}while(0)
#endif/*MINI_BT*/


tu8 get_iokey_value(void);
extern void io_key_init(void);
extern  u8  io_key_get_value(void);
extern  u8  io_key_pressed_to_msg(u8 key_style, u8 key_num);

#endif/*KEY_IO_EN*/
#endif/*__KEY_DRV_IO_H__*/
