#ifndef __USB_KEY_H__
#define __USB_KEY_H__

#include "sdk_cfg.h"

//extern const u8 adkey_msg_usb_table[4][10];
//extern const u8 iokey_msg_usb_table[4][10];
//extern const u8 irff00_msg_usb_table[4][21];
extern const u8 touchkey_msg_usb_table[4][10];


#ifdef adkey_max_num
extern const u8 adkey_msg_usb_table[4][adkey_max_num];
#else
extern const u8 adkey_msg_usb_table[4][10];
#endif
extern const u8 iokey_msg_usb_table[4][10];


#ifdef ir_max_num
extern const u8 irff00_msg_usb_table[4][ir_max_num];
#else
extern const u8 irff00_msg_usb_table[4][21];
#endif

#ifdef SUPPORT_TM1628_KEY_READ
  #if LED_KEY_MAX
 extern const u8 usb_led_table[4][LED_KEY_MAX];
  #else
 extern const u8 usb_led_table[4][10];
  #endif
#endif


#endif
