#ifndef __REC_KEY_H__
#define __REC_KEY_H__

#include "includes.h"
#ifdef adkey_max_num
extern const u8 adkey_msg_rec_table[4][adkey_max_num];
#else
extern const u8 adkey_msg_rec_table[4][10];
#endif
extern const u8 iokey_msg_rec_table[4][10];
#ifdef ir_max_num
extern const u8 irff00_msg_rec_table[4][ir_max_num];
#else
extern const u8 irff00_msg_rec_table[4][21];
#endif
extern const u8 touchkey_msg_rec_table[4][10];

#ifdef SUPPORT_TM1628_KEY_READ
  #if LED_KEY_MAX
 extern const u8 rec_led_table[4][LED_KEY_MAX];
  #else
 extern const u8 rec_led_table[4][10];
  #endif
#endif

#endif/*__REC_KEY_H__*/
