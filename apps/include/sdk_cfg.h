/*--------------------------------------------------------------------------*/
/**@file     sys_cfg.h
   @brief    系统配置
   @details
   @author
   @date    2015-9-3
   @note    ac46x
*/
/*----------------------------------------------------------------------------*/

#ifndef _CONFIG_
#define _CONFIG_

#include "includes.h"



///任务堆栈大小配置测试
#define VM_TASK_STACK_SIZE          (1024 * 1)
#define MAIN_TASK_STACK_SIZE        (1024 * 2) //(1024 * 1)可行
#define MUSIC_TASK_STACK_SIZE       (1024 * 4)
#define MUSIC_PHY_TASK_STACK_SIZE   (1024 * 4)
#define TONE_TASK_STACK_SIZE        (1024 * 4)
#define TONE_PHY_TASK_STACK_SIZE    (1024 * 2)
#define UI_TASK_STACK_SIZE          (1024 * 2)

//==========================================	


 //--------------------------------------------------	
// 科普豪
//  #define customer_kph_k1910_6901
//  #define customer_kph_k1953_6905c // 20170318 add
///  #define customer_kph_BJ006_BT_6903 // 20170318 add
//  #define customer_kph_BJ006_BT_WU_6903 // 20170318 add


//--------------------------------------------------	
//天韵
//  #define customer_ty_hg6901_encoder_ac6901  // nouse
// #define customer_ty_hg6905_ac6905
//  #define customer_ty_hg6905_kok_ac6905
// #define customer_ty_hg6901_ac6901
// #define customer_ty_hg6903_ac6903
// #define customer_ty_hg823_ac6905 // kok
//  #define customer_ty_hg822_ac6905 // kok
// #define customer_ty_hg823_fm_ac6905 // kok
//  #define customer_ty_06281Y_Y138_ac6901
// #define customer_ty_hg823_fm_b_ac6905 // off voice 
// #define customer_ty_hg823_fm_c_ac6905 // kok 改ir
// #define customer_ty_hg823_voice_ac6905 // kok add  voice key  mode/voice onoff

  
 //--------------------------------------------------	
// 正阳
// #define customer_zy_3066b_ac6903
// #define customer_zy_3066b_nofm_ac6903
//  #define customer_zy_3091A_ac6901
//  #define customer_zy_3091A_NOFM_ac6901
//  #define customer_zy_377A_ac6901 // 20161210 add  pt2313   Story machine 
// #define  customer_zy_3066b_voice_ac6903 // mode_voice_en 
// #define  customer_zy_0808_jy_ac6901
//  #define customer_zy_3091A_88N48_ac6901
//  #define customer_zy_3091A_88N48_NOFM_ac6901
//  #define customer_zy_3091B_7g8_ac6901 // zy_3091B_7g8_nofm_ac6901
//  #define customer_ZY_JR_PA_ac6901
//  #define customer_zy_3091B_KX5522_ac6901
// #define customer_zy_3066b_k2_ac6903
//  #define customer_zy_3091A_2REC_ac6901  // 20170103 ADD
// #define  customer_zy_3066b_voice_fffr_ac6903 // mode_voice_en 
//  #define customer_ZY_JL2015BT_ac6901
//  #define customer_ZY_JL2015BT_4210TAB_ac6901
//  #define customer_ZY_JL2015BT_XL5641_15R_ac6901 // 20170325 add
//  #define customer_ZY_JL2015BT_XL5641_NOFM_15R_ac6901 // 20170327 add
//  #define customer_zy_3091A_JC_ac6901
//  #define customer_zy_3091A_VKK15L_NOFM_ac6901 // VKK15L 807F IR+4018
//  #define customer_zy_3091A_DLED_ac6901
//  #define customer_zy_3091A_DAUX_ac6901
//  #define customer_zy_3091A_JC_NOFM_ac6901
//  #define customer_zy_6002_ac6901  // 20170113 add
//  #define customer_zy_5060_ac6901  // 20170114 add
//  #define customer_zy_3091A_88N48_zr_ac6901 // 20170114 add
//  #define customer_ZY_3091A_JW6521B_1A_AC6901 // 20170116 add 1628_led68
//  #define customer_zy_3091A_HD7369_ac6901 // 20170211 
//  #define customer_zy_3091A_TY21_ac6901 // 20170211 
// #define customer_zy_3066b_nofm_b_ac6903 // 20170213 add 
// #define customer_zy_3066b_mm_ac6903 // 20170213 add 
// #define customer_zy_3094_ac6902 // 20170213 add 
//  #define customer_zy_3091A_88N48_zr_TY21_ac6901 // 20170214 add
// #define customer_zy_3066b_mm_NOFM_ac6903 // 20170213 add 
// #define customer_zy_3066b_mm_voice_ac6903 // 20170215 add   
//   #define customer_zy_3091A_KH2401_7_tykey_ac6901  // 20170217 add
//  #define customer_zy_3091B_KX5522_b_ac6901
//  #define customer_zy_3091A_YH_ac6901
//  #define customer_zy_3091A_TY21_B_ac6901 // 20170222 MDODIFY ADKEY
//  #define customer_zy_3091B_KX5522_c_ac6901  // 20170228 add off fm
//  #define customer_zy_3091B_88N48_KX5522_ac6901
// #define customer_zy_3066b_bt_ac6903 // 20170303 add  nofm  out media to bt and power on default bt
//  #define customer_zy_3091A_TY21_88N48_ac6901 // 20170222 MDODIFY ADKEY
//  #define customer_zy_3091A_88N48_VOL_ac6901
//  #define customer_zy_3091A_KEY2_ac6901 // 20170308 ADD  1K为下一曲    2K为上一曲
//  #define customer_zy_3091A_HD7369_REC_ac6901 // 20170308 
//  #define customer_zy_3091A_88N48_NOFM_LINE_ac6901
//  #define customer_zy_3091A_40N18_NOFM_LINE_ac6901
//  #define customer_zy_3091A_HD7369_1REC_ac6901 // 20170316 IR MODIFY NOFM
//  #define customer_zy_3091B_88N48_KX5522_AUX_ac6901 // 20170316 ADD LINE  SHOW AUX
//  #define customer_zy_5061_ac6901  // 20170318 add
//  #define customer_zy_3091A_88N48_NOFM_EN_ac6901
//  #define customer_zy_3091A_88N48_OEKKER_ac6901  // 20170318 add 
//  #define customer_zy_3091A_88N48_ch_ac6901  // 20170318 add 
//  #define customer_zy_3091B_88N48_KX5522_NOFM_ac6901
//  #define customer_zy_3091A_ch_yh_nofm_ac6901  // 20170320 add 
//  #define customer_zy_3066b_mm_voice_nofm_ac6903 // 20170321 add   
//  #define customer_zy_6041_rtc_ac6901  // 20170322 add 
//  #define customer_ZY_BT1111_ac6901  // 20170324
//  #define customer_zy_3091A_BT_LS_00FF_ac6901 // 20170324 
//  #define customer_ZY_BT1111_NOFM_ac6901  // 20170324
//    #define customer_zy_3091A_usb_ac6901  // 20170328 add nop mode
//  #define customer_zy_3091A_88N48_VOL_NOFM_ac6901
//  #define customer_zy_3091A_swap_ac6901 // 20160401 add  led7_swap_io
// #define customer_zy_3066b_bt_fm_ac6903  // 20170404
//  #define customer_zy_3091A_88N48_eq_ac6901  // 20170405 add
//  #define customer_zy_3091A_88N48_EN_ac6901
//  #define customer_ZY_3091B_7G8_VM_AC6901
//  #define customer_zy_3091A_yh_6122_nofm_ac6901  // 20170406 add  modify ir
//  #define customer_zy_3091B_KX5522_D_ac6901 // 20170410 ADD OFF BT ICON
//  #define customer_zy_307LED_ac6901  // 20170411
//   #define customer_zy_5059_ac6901  // 20170413
// #define customer_zy_3066b_mm_NOFM_ch_ac6903 // 20170419 add  mode ch voice
//   #define customer_zy_6046_ac6901  // 20170422
//  #define customer_zy_3091B_88N48_KX5522_TYKEY_ac6901  // 20170422
//  #define customer_zy_3091A_JC_NOFM_VOICE_ac6901 // 20170424 ADD 
//  #define customer_zy_3091B_4018_KX5522_TYKEY_ac6901  // 20170424
//   #define customer_zy_6042_ac6901  // 20170424
//  #define customer_zy_3091B_KX5522_E_ac6901 // 20170425 ADD
//  #define customer_zy_3091A_vol28_ac6901 //20170425 add  vol dec 2step  
//  #define customer_zy_3091A_88N48_LINE_ac6901  // 20170427
//  #define customer_zy_3091B_88N48_KX5522_E_ac6901 // 20170425 ADD
//  #define customer_zy_3091A_TY21_REC_ac6901 // 20170429 modify ir EQ-REC
//  #define customer_zy_3053_ac6901 // 20170502 tm1628 pt2313 m62429
//  #define customer_zy_3053_JW_4018_ac6901 // 20170502 tm1628 pt2313 m62429
//  #define customer_zy_3053_JW_4018_LINE_ac6901 // 20171218 tm1628 pt2313 m62429
//  #define customer_zy_3091A_BT_LS_TY5112A_ac6901 // 20170506 MODIFY IR
//  #define customer_zy_3091A_vkar_ac6901  // 20170320 add 
//  #define customer_zy_3091A_88N48_SWAP_ac6901 //  20170511 ADD
//  #define customer_zy_3091B_HJ8832_ac6901  // 20170512 ADD
//  #define customer_zy_3093b_hj820_ac6901 // 20170512
//  #define customer_zy_3091A_TY21_REC_88N48_ac6901 // 20170512 ADD
//  #define customer_zy_5061_S501_ac6901  // 20170513 add
//  #define customer_zy_5061_SLT_ac6901  // 20170520 add
//#define customer_zy_2017bt_jy_ac6901  // 20170520 add
#define customer_zy_2017bt_YDL2001_VFD_35_ac6901  // 20170615 add
//#define customer_zy_2017bt_YDL2001_VFD_35_NO_FM_ac6901  // 20170615 add
// #define customer_zy_3066b_nobt_ac6903  // 20170522 add
// #define customer_zy_3066b_nofm_noaux_ac6903  // 20170523 add
//  #define customer_zy_3091A_HD7369_FOLDER_ac6901 // 20170525 ADD
//  #define customer_zy_3091A_88N48_VOICE_ac6901 // 20170424 ADD 
//  #define customer_zy_3093b_jh820_03_ac6901 // 20170512
//  #define customer_zy_3093b_hj820_jhir_ac6901 // 20170605
//  #define customer_zy_3091B_7g8_micromax_ac6901 // zy_3091B_7g8_nofm_ac6901
//  #define customer_zy_3091A_BT_7g8_micromax_ac6901 
// #define customer_zy_3066b_bt_fm_mute_ac6903  // 20170605
// #define customer_zy_2017bt_jy_fm_ac6901  // 20170520 add
//  #define customer_zy_3091A_NOFM_ch_ac6901 // 20170607 add  ch mode voice
// #define customer_zy_3066b_nop_ac6903
// #define  customer_zy_3066b_voice_BT_ac6903 // mode_voice_en  +START BT MODE
// #define customer_zy_2017bt_4018m_ac6901  // 20170613
// #define customer_ZY_2017BT_K1198KL_1_AC6901 	      // 20170613
// #define customer_ZY_2017BT_SB_BG06274A_AC6901  // 20170613
// #define customer_ZY_2017BT_K1198KL_1_NOFM_AC6901 	      // 20170613
// #define customer_ZY_JL_PA_50B_AC6905  // 20170614 ADD
// #define  customer_zy_3066b_voice_BT_V20_ac6903 // mode_voice_en  +START BT MODE  START VOL  ALWAY 20

 //--------------------------------------------------	
// 泽鑫
// #define customer_zx_hy6903_ac6903
// #define customer_zx_hy6903_nofm_ac6903
// #define customer_zx_hy6903_bt_ac6903
// #define customer_zx_k1910_ac6901
// #define customer_zx_k1910_zykey_ac6901
// #define customer_zx_k1910_tm_ac6901 //modify key
//  #define customer_zx_k1910_zykey_nofm_ac6901  // 20170421 add
//  #define customer_zx_k1910_7g8_ac6901 // 20170422  10528_7g8
// #define customer_zx_k1910_zy_ac6901 // 20170423 ADD ZY IR ZYKEY
//  #define customer_zx_k1910_7g8_ty_ac6901 // 20170424 modify ir
// #define customer_zx_k1910_nofm_ac6901
// #define customer_zx_k1910_2408_ac6901
//  #define customer_zx_hy6903_ZYKEY_ac6903
// #define customer_zx_k1910_zykey_ok_ac6901
// #define customer_zx_k1910_zykey_en_ac6901
// #define customer_zx_hy6903_ch_ac6903
// #define customer_zx_hy6903_ch_nofm_ac6903
//  #define customer_zx_k1910_zykey_b_ac6901
//  #define customer_zx_k1910_7g8_ty_b_ac6901 // 20170607 add off voice
// #define customer_zx_k1910_zykey_c_ac6901
// #define customer_zx_k1910_encord_ac6901
// #define customer_zx_k1910_4018_ac6901
// #define customer_zx_k1910_k1783_ac6901

  
 //--------------------------------------------------	

// 国威
// #define customer_gw_805d_ac6903
// #define customer_gw_slh_805d_ac6903
// #define customer_gw_bj003_ac6901
// #define customer_gw_805d_nofm_ac6903
// #define customer_gw_805d_swn_ac6903
// #define customer_gw_bj003_nofm_ac6901
//  #define customer_gw_805d_vol25_ac6903
// #define customer_gw_805d_nofm_vol15_ac6903
// #define customer_GW_805D_03_FY_AC6903
//   #define customer_gw_805d_03_SQ_ac6903
// #define customer_gw_805d_dled_ac6903
// #define customer_gw_805d_nofm_SB_ac6903
// #define customer_gw_805d_ch_ac6903
//#define customer_GW_203BT_01_QX_AC6901
//#define customer_GW_203BT_01_QX_NO_FM_AC6901
//#define customer_GW_203BT_01_VOL_50_AC6901
//#define customer_GW_203BT_01_VOL_50_MUTE_AC6901
//#define customer_GW_805F_K02
//#define customer_GW_806F_K02
//#define customer_GW_806F_K02_NO_FM_ac6901



 //--------------------------------------------------	

// 双马led-pin9 mute-pin8
// #define customer_sm_3018_ac6903
// #define customer_sm_3107_ac6903
// #define customer_sm_3106_ac6905
// #define customer_SM_TLS002_ac6901




 //--------------------------------------------------	

// 睿思
// #define customer_rs_001_ac6905
//  #define customer_rs_401a_ac6905
// #define customer_rs_e3_ac6905
  
 //--------------------------------------------------	


// 天音
//  #define customer_tianyin_ac6901
//  #define customer_tianyin_tm1628_ac6901
//  #define customer_tianyin_62429_ac6901
//    #define customer_tianyin_tm1628_JW5028B_1B_ac6901
//  #define customer_tianyin_tm1628_vol_ac6901
//  #define customer_tianyin_4018_ac6901  // 20170316 ADD
//  #define customer_tianyin_4018_dvoice_ac6901  // 20170320 ADD	
//  #define customer_tianyin_ty_power_ac6901
//  #define customer_tianyin_8426C7_ac6901  // 20170406 ADD
//  #define customer_tianyin_4018_nofm_ac6901  // 20170411  ADD
//  #define customer_tianyin_8848_ac6901  // 20170419 ADD
//  #define customer_tianyin_ty_b_power_ac6901
//  #define customer_tianyin_ty_ac6901
//  #define customer_tianyin_ty_c_power_ac6901
//  #define customer_tianyin_ty_power_c_8848_ac6901
//  #define customer_tianyin_ty_power_d_ac6901 // 20170518 add
//  #define customer_tianyin_4018_nofm_swap_ac6901  // 20170525
//  #define customer_tianyin_tm1628_vol_zykey_ac6901
 // #define customer_tianyin_ty_ac6905b //pa1
//  #define customer_tianyin_ty_line_ac6905b // pa3

  
  
// 天峰
//  #define customer_tf2131a_ac6903
  // #define customer_tf2135a_ac6901
//#define customer_tf_2138A_HJ_1600B_VFD_ac6901
//#define customer_tf_2138A_HJ_6030_C_ac6901
//#define customer_tf_2138A_DB_51_DISPLAY_ac6901


// 声视美
//  #define customer_ssm_K1937_ac6901


//柏星
//  #define customer_bx_bk887_ac6905  // 20170217 add hid
//  #define customer_bx_bk887_ac6905b  // 20170217 add hid
//  #define customer_BX_001_AC6905B // 20170217 add hid




 //符氏
 //  #define customer_fs_k122_ac6905
//  #define customer_fs_k136_ac6901  // 20170224 add 
//  #define customer_fs_k137a_ac6901  // 20170308 add 
//   #define customer_fs_k122_fm_ac6905 // 20170316 add
//   #define customer_fs_k179_ac6901 // 20170317 add
//   #define customer_fs_k125_ac6901 // 20170317 add
//   #define customer_fs_PI15_ac6901 // 20170506 add

// 俊豪
// #define customer_jh_K1972_ac6905  // 2070503 add



//铭盛佳
//#define customer_msj_K1966_V1_ac6901
//#define customer_msj_K1942_xp_ac6901



//史晨光
//#define customer_msj_K16001_V1_ac6901
//  #define customer_scg_kph_K1976_V1_BT_6903 




 //--------------------------------------------------	

#if defined(customer_kph_k1910_6901)
	#include "customer_kph_k1910_6901.h"
#elif defined(customer_ty_hg6905_ac6905)
	#include "customer_ty_hg6905_ac6905.h"
#elif defined(customer_kph_k1953_6905c)
	#include "customer_kph_k1953_6905c.h"
#elif defined(customer_zx_k1910_ac6901)
	#include "customer_zx_k1910_ac6901.h"
#elif defined(customer_zx_k1910_4018_ac6901)
	#include "customer_zx_k1910_4018_ac6901.h"
#elif defined(customer_zx_k1910_encord_ac6901)
	#include "customer_zx_k1910_encord_ac6901.h"
#elif defined(customer_zx_k1910_2408_ac6901)
	#include "customer_zx_k1910_2408_ac6901.h"
#elif defined(customer_zx_k1910_nofm_ac6901)
	#include "customer_zx_k1910_nofm_ac6901.h"
#elif defined(customer_zx_k1910_7g8_ac6901)
	#include "customer_zx_k1910_7g8_ac6901.h"
#elif defined(customer_zx_k1910_7g8_ty_ac6901)
	#include "customer_zx_k1910_7g8_ty_ac6901.h"
#elif defined(customer_zx_k1910_7g8_ty_b_ac6901)
	#include "customer_zx_k1910_7g8_ty_b_ac6901.h"
#elif defined(customer_zx_k1910_zykey_ac6901)
	#include "customer_zx_k1910_zykey_ac6901.h"
#elif defined(customer_zx_k1910_zykey_b_ac6901)
	#include "customer_zx_k1910_zykey_b_ac6901.h"
#elif defined(customer_zx_k1910_zykey_c_ac6901)
	#include "customer_zx_k1910_zykey_c_ac6901.h"
#elif defined(customer_zx_k1910_zykey_en_ac6901)
	#include "customer_zx_k1910_zykey_en_ac6901.h"
#elif defined(customer_zx_k1910_zykey_ok_ac6901)
	#include "customer_zx_k1910_zykey_ok_ac6901.h"
#elif defined(customer_zx_k1910_zy_ac6901)
	#include "customer_zx_k1910_zy_ac6901.h"
#elif defined(customer_zx_k1910_zykey_nofm_ac6901)
	#include "customer_zx_k1910_zykey_nofm_ac6901.h"
#elif defined(customer_zx_k1910_tm_ac6901)
	#include "customer_zx_k1910_tm_ac6901.h"
#elif defined(customer_ty_hg6905_kok_ac6905)
	#include "customer_ty_hg6905_kok_ac6905.h"
#elif defined(customer_ty_hg822_ac6905)
	#include "customer_ty_hg822_ac6905.h"
#elif defined(customer_ty_hg823_ac6905)
	#include "customer_ty_hg823_ac6905.h"
#elif defined(customer_ty_hg823_voice_ac6905)
	#include "customer_ty_hg823_voice_ac6905.h"
#elif defined(customer_ty_hg823_fm_ac6905)
	#include "customer_ty_hg823_fm_ac6905.h"
#elif defined(customer_ty_hg823_fm_c_ac6905)
	#include "customer_ty_hg823_fm_c_ac6905.h"
#elif defined(customer_ty_hg823_fm_b_ac6905)
	#include "customer_ty_hg823_fm_b_ac6905.h"
#elif defined(customer_zy_3066b_ac6903)
	#include "customer_zy_3066b_ac6903.h"
#elif defined(customer_zy_3066b_nop_ac6903)
	#include "customer_zy_3066b_nop_ac6903.h"
#elif defined(customer_zy_3066b_nobt_ac6903)
	#include "customer_zy_3066b_nobt_ac6903.h"
#elif defined(customer_zy_3066b_nofm_noaux_ac6903)
	#include "customer_zy_3066b_nofm_noaux_ac6903.h"
#elif defined(customer_zy_3093b_hj820_ac6901)
	#include "customer_zy_3093b_hj820_ac6901.h"
#elif defined(customer_zy_3093b_hj820_jhir_ac6901)
	#include "customer_zy_3093b_hj820_jhir_ac6901.h"
#elif defined(customer_zy_3093b_jh820_03_ac6901)
	#include "customer_zy_3093b_jh820_03_ac6901.h"
#elif defined(customer_zy_3066b_mm_ac6903)
	#include "customer_zy_3066b_mm_ac6903.h"
#elif defined(customer_zy_3066b_mm_NOFM_ch_ac6903)
	#include "customer_zy_3066b_mm_NOFM_ch_ac6903.h"
#elif defined(customer_zy_3066b_mm_NOFM_ac6903)
	#include "customer_zy_3066b_mm_NOFM_ac6903.h"
#elif defined(customer_zy_3066b_mm_voice_ac6903)
	#include "customer_zy_3066b_mm_voice_ac6903.h"
#elif defined(customer_zy_3066b_mm_voice_nofm_ac6903)
	#include "customer_zy_3066b_mm_voice_nofm_ac6903.h"
#elif defined(customer_zy_3094_ac6902)
	#include "customer_zy_3094_ac6902.h"
#elif defined(customer_zy_3066b_k2_ac6903)
	#include "customer_zy_3066b_k2_ac6903.h"
#elif defined(customer_zy_3066b_voice_ac6903)
	#include "customer_zy_3066b_voice_ac6903.h"
#elif defined(customer_zy_3066b_voice_BT_ac6903)
	#include "customer_zy_3066b_voice_BT_ac6903.h"
#elif defined(customer_zy_3066b_voice_BT_V20_ac6903)
	#include "customer_zy_3066b_voice_BT_V20_ac6903.h"
#elif defined(customer_zy_3066b_voice_fffr_ac6903)
	#include "customer_zy_3066b_voice_fffr_ac6903.h"
#elif defined(customer_zy_3066b_nofm_ac6903)
	#include "customer_zy_3066b_nofm_ac6903.h"
#elif defined(customer_zy_3066b_bt_ac6903)
	#include "customer_zy_3066b_bt_ac6903.h"
#elif defined(customer_zy_3066b_bt_fm_ac6903)
	#include "customer_zy_3066b_bt_fm_ac6903.h"
#elif defined(customer_zy_3066b_bt_fm_mute_ac6903)
	#include "customer_zy_3066b_bt_fm_mute_ac6903.h"
#elif defined(customer_zy_3066b_nofm_b_ac6903)
	#include "customer_zy_3066b_nofm_b_ac6903.h"
#elif defined(customer_gw_805d_ac6903)
	#include "customer_gw_805d_ac6903.h"
#elif defined(customer_gw_805d_ch_ac6903)
	#include "customer_gw_805d_ch_ac6903.h"
#elif defined(customer_gw_805d_dled_ac6903)
	#include "customer_gw_805d_dled_ac6903.h"
#elif defined(customer_gw_805d_03_SQ_ac6903)
	#include "customer_gw_805d_03_SQ_ac6903.h"
#elif defined(customer_gw_805d_vol25_ac6903)
	#include "customer_gw_805d_vol25_ac6903.h"
#elif defined(customer_gw_805d_swn_ac6903)
	#include "customer_gw_805d_swn_ac6903.h"
#elif defined(customer_gw_805d_nofm_ac6903)
	#include "customer_gw_805d_nofm_ac6903.h"
#elif defined(customer_gw_805d_nofm_SB_ac6903)
	#include "customer_gw_805d_nofm_SB_ac6903.h"
#elif defined(customer_GW_805D_03_FY_AC6903)
	#include "customer_GW_805D_03_FY_AC6903.h"
#elif defined(customer_gw_805d_nofm_vol15_ac6903)
	#include "customer_gw_805d_nofm_vol15_ac6903.h"
#elif defined(customer_gw_slh_805d_ac6903)
	#include "customer_gw_slh_805d_ac6903.h"
#elif defined(customer_gw_bj003_ac6901)
	#include "customer_gw_bj003_ac6901.h"
#elif defined(customer_gw_bj003_nofm_ac6901)
	#include "customer_gw_bj003_nofm_ac6901.h"
#elif defined(customer_sm_3018_ac6903)
	#include "customer_sm_3018_ac6903.h"
#elif defined(customer_sm_3107_ac6903)
	#include "customer_sm_3107_ac6903.h"
#elif defined(customer_sm_3106_ac6905)
	#include "customer_sm_3106_ac6905.h"
#elif defined(customer_rs_001_ac6905)
	#include "customer_rs_001_ac6905.h"
#elif defined(customer_rs_e3_ac6905)
	#include "customer_rs_e3_ac6905.h"
#elif defined(customer_bx_bk887_ac6905)
	#include "customer_bx_bk887_ac6905.h"
#elif defined(customer_jh_K1972_ac6905)
	#include "customer_jh_K1972_ac6905.h"
#elif defined(customer_rs_401a_ac6905)
	#include "customer_rs_401a_ac6905.h"
#elif defined(customer_zx_hy6903_ac6903)
	#include "customer_zx_hy6903_ac6903.h"
#elif defined(customer_zx_hy6903_ch_ac6903)
	#include "customer_zx_hy6903_ch_ac6903.h"
#elif defined(customer_zx_hy6903_ch_nofm_ac6903)
	#include "customer_zx_hy6903_ch_nofm_ac6903.h"
#elif defined(customer_zx_hy6903_ZYKEY_ac6903)
	#include "customer_zx_hy6903_ZYKEY_ac6903.h"
#elif defined(customer_zx_hy6903_nofm_ac6903)
	#include "customer_zx_hy6903_nofm_ac6903.h"
#elif defined(customer_zx_hy6903_bt_ac6903)
	#include "customer_zx_hy6903_bt_ac6903.h"
#elif defined(customer_fs_k122_ac6905)
	#include "customer_fs_k122_ac6905.h"
#elif defined(customer_fs_k122_fm_ac6905)
	#include "customer_fs_k122_fm_ac6905.h"
#elif defined(customer_zy_3091A_ac6901)
	#include "customer_zy_3091A_ac6901.h"
#elif defined(customer_zy_3091A_vol28_ac6901)
	#include "customer_zy_3091A_vol28_ac6901.h"
#elif defined(customer_zy_307LED_ac6901)
	#include "customer_zy_307LED_ac6901.h"
#elif defined(customer_zy_3091A_swap_ac6901)
	#include "customer_zy_3091A_swap_ac6901.h"
#elif defined(customer_zy_3091A_usb_ac6901)
	#include "customer_zy_3091A_usb_ac6901.h"
#elif defined(customer_zy_3091A_BT_LS_00FF_ac6901)
	#include "customer_zy_3091A_BT_LS_00FF_ac6901.h"
#elif defined(customer_zy_3091A_BT_LS_TY5112A_ac6901)
	#include "customer_zy_3091A_BT_LS_TY5112A_ac6901.h"
#elif defined(customer_zy_6041_rtc_ac6901)
	#include "customer_zy_6041_rtc_ac6901.h"
#elif defined(customer_zy_3091A_KEY2_ac6901)
	#include "customer_zy_3091A_KEY2_ac6901.h"
#elif defined(customer_zy_3091A_YH_ac6901)
	#include "customer_zy_3091A_YH_ac6901.h"
#elif defined(customer_zy_3091A_HD7369_ac6901)
	#include "customer_zy_3091A_HD7369_ac6901.h"
#elif defined(customer_zy_3091A_HD7369_REC_ac6901)
	#include "customer_zy_3091A_HD7369_REC_ac6901.h"
#elif defined(customer_zy_3091A_HD7369_1REC_ac6901)
	#include "customer_zy_3091A_HD7369_1REC_ac6901.h"
#elif defined(customer_zy_3091A_HD7369_FOLDER_ac6901)
	#include "customer_zy_3091A_HD7369_FOLDER_ac6901.h"
#elif defined(customer_zy_3091A_TY21_ac6901)
	#include "customer_zy_3091A_TY21_ac6901.h"
#elif defined(customer_zy_3091A_TY21_REC_ac6901)
	#include "customer_zy_3091A_TY21_REC_ac6901.h"
#elif defined(customer_zy_3091A_TY21_REC_88N48_ac6901)
	#include "customer_zy_3091A_TY21_REC_88N48_ac6901.h"
#elif defined(customer_zy_3053_ac6901)
	#include "customer_zy_3053_ac6901.h"
#elif defined(customer_zy_3091A_TY21_88N48_ac6901)
	#include "customer_zy_3091A_TY21_88N48_ac6901.h"
#elif defined(customer_zy_3091A_TY21_B_ac6901)
	#include "customer_zy_3091A_TY21_B_ac6901.h"
#elif defined(customer_zy_3091A_DLED_ac6901)
	#include "customer_zy_3091A_DLED_ac6901.h"
#elif defined(customer_zy_3091A_DAUX_ac6901)
	#include "customer_zy_3091A_DAUX_ac6901.h"
#elif defined(customer_zy_6002_ac6901)
	#include "customer_zy_6002_ac6901.h"
#elif defined(customer_zy_5059_ac6901)
	#include "customer_zy_5059_ac6901.h"
#elif defined(customer_zy_6046_ac6901)
	#include "customer_zy_6046_ac6901.h"
#elif defined(customer_zy_6042_ac6901)
	#include "customer_zy_6042_ac6901.h"
#elif defined(customer_zy_5060_ac6901)
	#include "customer_zy_5060_ac6901.h"
#elif defined(customer_zy_5061_ac6901)
	#include "customer_zy_5061_ac6901.h"
#elif defined(customer_zy_5061_S501_ac6901)
	#include "customer_zy_5061_S501_ac6901.h"
#elif defined(customer_zy_5061_SLT_ac6901)
	#include "customer_zy_5061_SLT_ac6901.h"
#elif defined(customer_zy_2017bt_jy_ac6901)
	#include "customer_zy_2017bt_jy_ac6901.h"
#elif defined(customer_zy_2017bt_4018m_ac6901)
	#include "customer_zy_2017bt_4018m_ac6901.h"
#elif defined(customer_ZY_2017BT_K1198KL_1_AC6901)
	#include "customer_ZY_2017BT_K1198KL_1_AC6901.h"
#elif defined(customer_ZY_2017BT_K1198KL_1_NOFM_AC6901)
	#include "customer_ZY_2017BT_K1198KL_1_NOFM_AC6901.h"
#elif defined(customer_ZY_JL_PA_50B_AC6905)
	#include "customer_ZY_JL_PA_50B_AC6905.h"
#elif defined(customer_ZY_2017BT_SB_BG06274A_AC6901)
	#include "customer_ZY_2017BT_SB_BG06274A_AC6901.h"
#elif defined(customer_zy_2017bt_jy_fm_ac6901)
	#include "customer_zy_2017bt_jy_fm_ac6901.h"
#elif defined(customer_zy_3091A_JC_ac6901)
	#include "customer_zy_3091A_JC_ac6901.h"
#elif defined(customer_zy_3091A_JC_NOFM_VOICE_ac6901)
	#include "customer_zy_3091A_JC_NOFM_VOICE_ac6901.h"
#elif defined(customer_zy_3091A_88N48_VOICE_ac6901)
	#include "customer_zy_3091A_88N48_VOICE_ac6901.h"
#elif defined(customer_zy_3091A_JC_NOFM_ac6901)
	#include "customer_zy_3091A_JC_NOFM_ac6901.h"
#elif defined(customer_ZY_JL2015BT_ac6901)
	#include "customer_ZY_JL2015BT_ac6901.h"
#elif defined(customer_ZY_JL2015BT_XL5641_15R_ac6901)
	#include "customer_ZY_JL2015BT_XL5641_15R_ac6901.h"
#elif defined(customer_ZY_JL2015BT_XL5641_NOFM_15R_ac6901)
	#include "customer_ZY_JL2015BT_XL5641_NOFM_15R_ac6901.h"
#elif defined(customer_ZY_BT1111_ac6901)
	#include "customer_ZY_BT1111_ac6901.h"
#elif defined(customer_ZY_BT1111_NOFM_ac6901)
	#include "customer_ZY_BT1111_NOFM_ac6901.h"
#elif defined(customer_ZY_JL2015BT_4210TAB_ac6901)
	#include "customer_ZY_JL2015BT_4210TAB_ac6901.h"
#elif defined(customer_zy_3091A_2REC_ac6901)
	#include "customer_zy_3091A_2REC_ac6901.h"
#elif defined(customer_zy_3091A_NOFM_ac6901)
	#include "customer_zy_3091A_NOFM_ac6901.h"
#elif defined(customer_zy_3091A_NOFM_ch_ac6901)
	#include "customer_zy_3091A_NOFM_ch_ac6901.h"
#elif defined(customer_zy_3091A_88N48_ac6901)
	#include "customer_zy_3091A_88N48_ac6901.h"
#elif defined(customer_zy_3091A_88N48_SWAP_ac6901)
	#include "customer_zy_3091A_88N48_SWAP_ac6901.h"
#elif defined(customer_zy_3091B_HJ8832_ac6901)
	#include "customer_zy_3091B_HJ8832_ac6901.h"
#elif defined(customer_zy_3091A_88N48_LINE_ac6901)
	#include "customer_zy_3091A_88N48_LINE_ac6901.h"
#elif defined(customer_zy_3091A_88N48_eq_ac6901)
	#include "customer_zy_3091A_88N48_eq_ac6901.h"
#elif defined(customer_zy_3091A_88N48_VOL_ac6901)
	#include "customer_zy_3091A_88N48_VOL_ac6901.h"
#elif defined(customer_zy_3091A_88N48_VOL_NOFM_ac6901)
	#include "customer_zy_3091A_88N48_VOL_NOFM_ac6901.h"
#elif defined(customer_zy_3091A_KH2401_7_tykey_ac6901)
	#include "customer_zy_3091A_KH2401_7_tykey_ac6901.h"
#elif defined(customer_ZY_3091A_JW6521B_1A_AC6901)
	#include "customer_ZY_3091A_JW6521B_1A_AC6901.h"
#elif defined(customer_zy_3091A_88N48_zr_ac6901)
	#include "customer_zy_3091A_88N48_zr_ac6901.h"
#elif defined(customer_zy_3091A_88N48_zr_TY21_ac6901)
	#include "customer_zy_3091A_88N48_zr_TY21_ac6901.h"
#elif defined(customer_ZY_JR_PA_ac6901)
	#include "customer_ZY_JR_PA_ac6901.h"
#elif defined(customer_zy_3091A_88N48_NOFM_ac6901)
	#include "customer_zy_3091A_88N48_NOFM_ac6901.h"
#elif defined(customer_zy_3091A_88N48_EN_ac6901)
	#include "customer_zy_3091A_88N48_EN_ac6901.h"
#elif defined(customer_zy_3091A_88N48_NOFM_EN_ac6901)
	#include "customer_zy_3091A_88N48_NOFM_EN_ac6901.h"
#elif defined(customer_zy_3091A_88N48_OEKKER_ac6901)
	#include "customer_zy_3091A_88N48_OEKKER_ac6901.h"
#elif defined(customer_zy_3091A_88N48_ch_ac6901)
	#include "customer_zy_3091A_88N48_ch_ac6901.h"
#elif defined(customer_zy_3091A_ch_yh_nofm_ac6901)
	#include "customer_zy_3091A_ch_yh_nofm_ac6901.h"
#elif defined(customer_zy_3091A_vkar_ac6901)
	#include "customer_zy_3091A_vkar_ac6901.h"
#elif defined(customer_zy_3091A_yh_6122_nofm_ac6901)
	#include "customer_zy_3091A_yh_6122_nofm_ac6901.h"
#elif defined(customer_zy_3091A_88N48_NOFM_LINE_ac6901)
	#include "customer_zy_3091A_88N48_NOFM_LINE_ac6901.h"
#elif defined(customer_zy_3091A_40N18_NOFM_LINE_ac6901)
	#include "customer_zy_3091A_40N18_NOFM_LINE_ac6901.h"
#elif defined(customer_zy_3091A_VKK15L_NOFM_ac6901)
	#include "customer_zy_3091A_VKK15L_NOFM_ac6901.h"
#elif defined(customer_zy_3091B_7g8_ac6901)
	#include "customer_zy_3091B_7g8_ac6901.h"
#elif defined(customer_zy_3091B_7g8_micromax_ac6901)
	#include "customer_zy_3091B_7g8_micromax_ac6901.h"
#elif defined(customer_ZY_3091B_7G8_VM_AC6901)
	#include "customer_ZY_3091B_7G8_VM_AC6901.h"
#elif defined(customer_zy_3091B_KX5522_ac6901)
	#include "customer_zy_3091B_KX5522_ac6901.h"
#elif defined(customer_zy_3091B_KX5522_E_ac6901)
	#include "customer_zy_3091B_KX5522_E_ac6901.h"
#elif defined(customer_zy_3091B_88N48_KX5522_E_ac6901)
	#include "customer_zy_3091B_88N48_KX5522_E_ac6901.h"
#elif defined(customer_zy_3091B_KX5522_D_ac6901)
	#include "customer_zy_3091B_KX5522_D_ac6901.h"
#elif defined(customer_zy_3091B_KX5522_b_ac6901)
	#include "customer_zy_3091B_KX5522_b_ac6901.h"
#elif defined(customer_zy_3091B_88N48_KX5522_ac6901)
	#include "customer_zy_3091B_88N48_KX5522_ac6901.h"
#elif defined(customer_zy_3091B_88N48_KX5522_TYKEY_ac6901)
	#include "customer_zy_3091B_88N48_KX5522_TYKEY_ac6901.h"
#elif defined(customer_zy_3091B_4018_KX5522_TYKEY_ac6901)
	#include "customer_zy_3091B_4018_KX5522_TYKEY_ac6901.h"
#elif defined(customer_zy_3091B_88N48_KX5522_AUX_ac6901)
	#include "customer_zy_3091B_88N48_KX5522_AUX_ac6901.h"
#elif defined(customer_zy_3091B_KX5522_c_ac6901)
	#include "customer_zy_3091B_KX5522_c_ac6901.h"
#elif defined(customer_zy_3091B_88N48_KX5522_NOFM_ac6901)
	#include "customer_zy_3091B_88N48_KX5522_NOFM_ac6901.h"
#elif defined(customer_zy_0808_jy_ac6901)
	#include "customer_zy_0808_jy_ac6901.h"
#elif defined(customer_tianyin_ac6901)
	#include "customer_tianyin_ac6901.h"
#elif defined(customer_tianyin_ty_power_ac6901)
	#include "customer_tianyin_ty_power_ac6901.h"
#elif defined(customer_tianyin_ty_power_d_ac6901)
	#include "customer_tianyin_ty_power_d_ac6901.h"
#elif defined(customer_tianyin_ty_b_power_ac6901)
	#include "customer_tianyin_ty_b_power_ac6901.h"
#elif defined(customer_tianyin_ty_c_power_ac6901)
	#include "customer_tianyin_ty_c_power_ac6901.h"
#elif defined(customer_tianyin_ty_power_c_8848_ac6901)
	#include "customer_tianyin_ty_power_c_8848_ac6901.h"
#elif defined(customer_tianyin_ty_ac6901)
	#include "customer_tianyin_ty_ac6901.h"
#elif defined(customer_tianyin_4018_ac6901)
	#include "customer_tianyin_4018_ac6901.h"
#elif defined(customer_tianyin_8848_ac6901)
	#include "customer_tianyin_8848_ac6901.h"
#elif defined(customer_tianyin_4018_nofm_ac6901)
	#include "customer_tianyin_4018_nofm_ac6901.h"
#elif defined(customer_tianyin_4018_nofm_swap_ac6901)
	#include "customer_tianyin_4018_nofm_swap_ac6901.h"
#elif defined(customer_tianyin_8426C7_ac6901)
	#include "customer_tianyin_8426C7_ac6901.h"
#elif defined(customer_tianyin_4018_dvoice_ac6901)
	#include "customer_tianyin_4018_dvoice_ac6901.h"
#elif defined(customer_tianyin_tm1628_ac6901)
	#include "customer_tianyin_tm1628_ac6901.h"
#elif defined(customer_tianyin_tm1628_vol_ac6901)
	#include "customer_tianyin_tm1628_vol_ac6901.h"
#elif defined(customer_tianyin_tm1628_vol_zykey_ac6901)
	#include "customer_tianyin_tm1628_vol_zykey_ac6901.h"
#elif defined(customer_tianyin_tm1628_JW5028B_1B_ac6901)
	#include "customer_tianyin_tm1628_JW5028B_1B_ac6901.h"
#elif defined(customer_tianyin_62429_ac6901)
	#include "customer_tianyin_62429_ac6901.h"
#elif defined(customer_zy_377A_ac6901)
	#include "customer_zy_377A_ac6901.h"
#elif defined(customer_ty_hg6901_ac6901)
	#include "customer_ty_hg6901_ac6901.h"
#elif defined(customer_ty_hg6901_encoder_ac6901)
	#include "customer_ty_hg6901_encoder_ac6901.h"
#elif defined(customer_ty_06281Y_Y138_ac6901)
	#include "customer_ty_06281Y_Y138_ac6901.h"
#elif defined(customer_tf2131a_ac6903)
	#include "customer_tf2131a_ac6903.h"
#elif defined(customer_tf2135a_ac6901)
	#include "customer_tf2135a_ac6901.h"
#elif defined(customer_ty_hg6903_ac6903)
	#include "customer_ty_hg6903_ac6903.h"
#elif defined(customer_ssm_K1937_ac6901)
	#include "customer_ssm_K1937_ac6901.h"
#elif defined(customer_fs_k136_ac6901)
	#include "customer_fs_k136_ac6901.h"
#elif defined(customer_fs_k137a_ac6901)
	#include "customer_fs_k137a_ac6901.h"
#elif defined(customer_fs_k179_ac6901)
	#include "customer_fs_k179_ac6901.h"
#elif defined(customer_fs_k125_ac6901)
	#include "customer_fs_k125_ac6901.h"
#elif defined(customer_fs_PI15_ac6901)
	#include "customer_fs_PI15_ac6901.h"
#elif defined(customer_zy_2017bt_YDL2001_VFD_35_ac6901)
	#include "customer_zy_2017bt_YDL2001_VFD_35_ac6901.h"	
#elif defined(customer_GW_203BT_01_QX_AC6901)
	#include "customer_GW_203BT_01_QX_AC6901.h"	
#elif defined(customer_GW_203BT_01_QX_NO_FM_AC6901)
	#include "customer_GW_203BT_01_QX_NO_FM_AC6901.h"
#elif defined(customer_GW_203BT_01_VOL_50_AC6901)
	#include "customer_GW_203BT_01_VOL_50_AC6901.h"
#elif defined(customer_zx_k1910_k1783_ac6901)
	#include "customer_zx_k1910_k1783_ac6901.h"
#elif defined(customer_tf_2138A_HJ_1600B_VFD_ac6901)
	#include "customer_tf_2138A_HJ_1600B_VFD_ac6901.h"
#elif defined(customer_BX_001_AC6905B)
	#include "customer_BX_001_AC6905B.h"
#elif defined(customer_tf_2138A_HJ_6030_C_ac6901)
	#include "customer_tf_2138A_HJ_6030_C_ac6901.h"
#elif defined(customer_zy_3053_JW_4018_ac6901)
	#include "customer_zy_3053_JW_4018_ac6901.h"
#elif defined(customer_zy_2017bt_YDL2001_VFD_35_NO_FM_ac6901)
	#include "customer_zy_2017bt_YDL2001_VFD_35_NO_FM_ac6901.h"
#elif defined(customer_tianyin_ty_ac6905b)
	#include "customer_tianyin_ty_ac6905b.h"
#elif defined(customer_tianyin_ty_line_ac6905b)
	#include "customer_tianyin_ty_line_ac6905b.h"
#elif defined(customer_zy_3091A_BT_7g8_micromax_ac6901)
	#include "customer_zy_3091A_BT_7g8_micromax_ac6901.h"
#elif defined(customer_kph_BJ006_BT_6903)
	#include "customer_kph_BJ006_BT_6903.h"	
#elif defined(customer_scg_kph_K1976_V1_BT_6903)
	#include "customer_scg_kph_K1976_V1_BT_6903.h"		
#elif defined(customer_tf_2138A_DB_51_DISPLAY_ac6901)
	#include "customer_tf_2138A_DB_51_DISPLAY_ac6901.h"		
#elif defined(customer_msj_K1966_V1_ac6901)
	#include "customer_msj_K1966_V1_ac6901.h"		
#elif defined(customer_msj_K1942_xp_ac6901)
	#include "customer_msj_K1942_xp_ac6901.h"	
#elif defined(customer_SM_TLS002_ac6901)
	#include "customer_SM_TLS002_ac6901.h"	
#elif defined(customer_msj_K16001_V1_ac6901)
	#include "customer_msj_K16001_V1_ac6901.h"	
#elif defined(customer_GW_805F_K02)
	#include "customer_GW_805F_K02.h"	
#elif defined(customer_GW_806F_K02)
	#include "customer_GW_806F_K02.h"	
#elif defined(customer_kph_BJ006_BT_WU_6903)
	#include "customer_kph_BJ006_BT_WU_6903.h"	
#elif defined(customer_GW_203BT_01_VOL_50_MUTE_AC6901)
	#include "customer_GW_203BT_01_VOL_50_MUTE_AC6901.h"	
#elif defined(customer_zy_3053_JW_4018_LINE_ac6901)
	#include "customer_zy_3053_JW_4018_LINE_ac6901.h"	
#elif defined(customer_GW_806F_K02_NO_FM_ac6901)
	#include "customer_GW_806F_K02_NO_FM_ac6901.h"	









	
	
#endif

	
//==========================================

/*

//#define cfg_muzhe_t
//#define customer_wxf_k68_6905
//#define customer_wxf_k1_6905

//智华创汇  老胡
//#define customer_zhcx_K7036_6901

//树伟
//#define custoemr_sw_k2754_sw005_6901   //

//东升
//#define custoemr_ds_k6111_6901_touch   // 

#if defined(customer_wxf_k68_6905)
	#include "customer_wxf_k68_6905.h"
#elif defined(customer_wxf_k1_6905)
	#include "customer_wxf_k1_6905.h"
#elif defined( customer_zhcx_K7036_6901)
	#include "customer_zhcx_K7036_6901.h"
#elif defined(custoemr_sw_k2754_sw005_6901)
	#include "custoemr_sw_k2754_sw005_6901.h"
#elif defined(custoemr_ds_k6111_6901_touch)
    #include "custoemr_ds_k6111_6901_touch.h"
#else
	#include "cfg_mu_test.h"
	#include "cfg_jl_old.h"
#endif
	*/

#include "config_mu_gpio_set.h"


#endif


#if 0

把PR0 作为输入口，需要如下设置。
PORTR_PU(PORTR0,1);
PORTR_PD(PORTR0,0);
PORTR_DIR(PORTR0,1);
PORTR_DIE(PORTR0,1);
PORTR_HD(PORTR0,1);
如果把PR1 或PR2 作为AD 口，需要加入下语句。
PORTR1_ADCEN_CTL(1);或PORTR2_ADCEN_CTL(1);

1、PA3 DEFAULT PULLDOWN
2、PB6 DEFAULT PULLUP
3、PR0 OUTPUT 0

#endif


//晶体偏频设置 
//bt_osc_internal_cfg(0x11,0x11);



