#ifndef _BT_KEY_MSG_
#define _BT_KEY_MSG_

//extern const u8 bt_ad_table[4][10];
//extern const u8 bt_io_table[4][10];
//extern const u8 bt_ir_table[4][21];
//extern const u8 bt_touch_table[4][10];

#ifdef SUPPORT_TM1628_KEY_READ
  #if LED_KEY_MAX
 extern const u8 bt_led_table[4][LED_KEY_MAX];
  #else
 extern const u8 bt_led_table[4][10];
  #endif
#endif


#ifdef adkey_max_num
extern const u8 bt_ad_table[4][adkey_max_num];
#else 
extern const u8 bt_ad_table[4][10];
#endif 
extern const u8 bt_io_table[4][10];


#ifdef ir_max_num
extern const u8 bt_ir_table[4][ir_max_num];
#else 
extern const u8 bt_ir_table[4][21];
#endif 
extern const u8 bt_touch_table[4][10];

#endif/*_BT_KEY_MSG_*/
