
#include "sdk_cfg.h"


#ifdef   adk_use_22k_6key_mode                //  pp prev next mode nop  rep eq 
       #include "adk_use_22k_6key_mode_msg.h"   
#elif defined(adk_use_2k7_13key_mode_ty)
      #include "adk_use_2k7_13key_mode_ty_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_folder)
      #include "adk_10k_15key_mode_zy_rec_folder_msg.h"  
#elif defined(adk_22k_10key_mode_zy_3053)
      #include "adk_22k_10key_mode_zy_3053_msg.h"  
#elif defined(adk_10k_10key_mode_zy_3053)
      #include "adk_10k_10key_mode_zy_3053_msg.h"  	  
#elif defined(adk_10k_15key_mode_zy_2rec_mic_S501)
      #include "adk_10k_15key_mode_zy_2rec_mic_S501_msg.h"  
#elif defined(adk_10k_15key_mode_zy_ok)
      #include "adk_10k_15key_mode_zy_ok_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_zx)
      #include "adk_10k_15key_mode_zy_rec_zx_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_zx_pprec)
      #include "adk_10k_15key_mode_zy_rec_zx_pprec_msg.h"  
#elif defined(adk_use_2k7_13key_mode_ty_kok_voice)
      #include "adk_use_2k7_13key_mode_ty_kok_voice_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_voice_ty)
      #include "adk_10k_15key_mode_zy_rec_voice_ty_msg.h"  
#elif defined(adk_10k_15key_mode_zy)
      #include "adk_10k_15key_mode_zy_msg.h"  
#elif defined(adk_22k_15key_mode_gw)
      #include "adk_22k_15key_mode_gw_msg.h"  
#elif defined(adk_22k_15key_mode_gw_sq)
      #include "adk_22k_15key_mode_gw_sq_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_menu)
      #include "adk_10k_15key_mode_zy_rec_menu_msg.h"  
#elif defined(adk_22k_15key_mode_gw_single_prev_next)
      #include "adk_22k_15key_mode_gw_single_prev_next_msg.h"  
#elif defined(adk_10k_15key_mode_zy_2rec_mic_rgb)
      #include "adk_10k_15key_mode_zy_2rec_mic_rgb_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_menu)
      #include "adk_10k_15key_mode_zy_rec_menu_msg.h"  
#elif defined(adk_use_10k_24key_mode_tianyin_voice_3)
      #include "adk_use_10k_24key_mode_tianyin_voice_3_msg.h"  
#elif defined(adk_use_10k_12key_mode_tianyin)
      #include "adk_use_10k_12key_mode_tianyin_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_mic)
      #include "adk_10k_15key_mode_zy_rec_mic_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_voice_yh)
      #include "adk_10k_15key_mode_zy_rec_voice_yh_msg.h"  
#elif defined(adk_22k_15key_mode_zx)
      #include "adk_22k_15key_mode_zx_msg.h"  
#elif defined(adk_22k_10key_mode_zx)
      #include "adk_22k_10key_mode_zx_msg.h"  	  
#elif defined(adk_use_22k_10key_mode_fs)
      #include "adk_use_22k_10key_mode_fs_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_4)
      #include "adk_10k_15key_mode_zy_rec_4_msg.h"  
#elif defined(adk_use_2k7_13key_mode_ty_kok)
      #include "adk_use_2k7_13key_mode_ty_kok_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_voice)
      #include "adk_10k_15key_mode_zy_rec_voice_msg.h"  
#elif defined(adk_10k_15key_mode_zy_1)
      #include "adk_10k_15key_mode_zy_1_msg.h"  
#elif defined(adk_use_22k_3key_mode_rs)
      #include "adk_use_22k_3key_mode_rs_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec)&& !defined(LED_KEY_USE_ZY_HJ802_1_4KEY)
      #include "adk_10k_15key_mode_zy_rec_msg.h"  
#elif defined(LED_KEY_USE_ZY_HJ802_1_4KEY)
      #include "adk_10k_15key_mode_zy_rec_msg.h"  
      #include "LED_KEY_USE_ZY_HJ802_1_4KEY_MSG.h"  	  
#elif defined(adk_10k_15key_mode_zy_rec_hj8832)
      #include "adk_10k_15key_mode_zy_rec_hj8832_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_bt111)
      #include "adk_10k_15key_mode_zy_rec_bt111_msg.h"  
#elif defined(adk_use_22k_6key_mode_gw)
      #include "adk_use_22k_6key_mode_gw_msg.h"  
#elif defined(adk_use_10k_24key_mode_tianyin)
      #include "adk_use_10k_24key_mode_tianyin_msg.h"  
#elif defined(adk_use_10k_24key_mode_tianyin_zykey)
      #include "adk_use_10k_24key_mode_tianyin_zykey_msg.h"  
#elif defined(adk_use_22k_10key_mode_tf)
      #include "adk_use_22k_10key_mode_tf_msg.h"  
#elif defined(adk_22k_24key_mode_ssm_rec)
      #include "adk_22k_24key_mode_ssm_rec_msg.h"  
#elif defined(adk_use_22k_2key_mode_rs)
      #include "adk_use_22k_2key_mode_rs_msg.h"  
#elif defined(adk_use_22k_3key_mode)
      #include "adk_use_22k_3key_mode_msg.h"  
#elif defined(adk_22k_15key_mode_zy_jy)
      #include "adk_22k_15key_mode_zy_jy_msg.h"  
#elif defined(adk_22k_15key_mode_zy_jy_308d)
      #include "adk_22k_15key_mode_zy_jy_308d_msg.h"  
#elif defined(adk_10k_15key_mode_zy_kx)
      #include "adk_10k_15key_mode_zy_kx_msg.h"  
#elif defined(adk_10k_15key_mode_zy_k2)
      #include "adk_10k_15key_mode_zy_k2_msg.h"  
#elif defined(adk_10k_15key_mode_zy_2rec)
      #include "adk_10k_15key_mode_zy_2rec_msg.h"  
#elif defined(adk_10k_15key_mode_zy_cy)
      #include "adk_10k_15key_mode_zy_cy_msg.h"  
#elif defined(adk_user_6_key_mode)
      #include "adk_user_6_key_mode_msg.h"  
#elif defined(adk_user_6_key_mode_bt1111)
      #include "adk_user_6_key_mode_bt1111_msg.h"  
#elif defined(adk_user_9_key_mode)
      #include "adk_user_9_key_mode_msg.h"  
#elif defined(adk_use_22k_7key_mode_tf)
      #include "adk_use_22k_7key_mode_tf_msg.h"  
#elif defined(adk_10k_16key_mode_zy_rec)
      #include "adk_10k_16key_mode_zy_rec_msg.h"  
#elif defined(adk_10k_15key_mode_zy_2rec_mic)
      #include "adk_10k_15key_mode_zy_2rec_mic_msg.h"  
#elif defined(adk_10k_15key_mode_zy_ppmode)
      #include "adk_10k_15key_mode_zy_ppmode_msg.h"  
#elif defined(adk_10k_15key_mode_zy_mm)
      #include "adk_10k_15key_mode_zy_mm_msg.h"  
#elif defined(adk_10k_15key_mode_zy_zr)
      #include "adk_10k_15key_mode_zy_zr_msg.h"  
#elif defined(adk_10k_15key_mode_zy_mm_voice)
      #include "adk_10k_15key_mode_zy_mm_voice_msg.h"  
#elif defined(adk_10k_15key_mode_zy_ty)
      #include "adk_10k_15key_mode_zy_ty_msg.h"  
#elif defined(adk_use_22k_4key_mode_hid)
      #include "adk_use_22k_4key_mode_hid_msg.h"  
#elif defined(adk_10k_15key_mode_zy_kx2)
      #include "adk_10k_15key_mode_zy_kx2_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_2)
      #include "adk_10k_15key_mode_zy_rec_2_msg.h"  
#elif defined(adk_use_10k_10key_mode_fs)
      #include "adk_use_10k_10key_mode_fs_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_3)
      #include "adk_10k_15key_mode_zy_rec_3_msg.h"  
#elif defined(adk_10k_15key_mode_zy_2)
      #include "adk_10k_15key_mode_zy_2_msg.h"  
#elif defined(adk_use_10k_24key_mode_tianyin_voice)
      #include "adk_use_10k_24key_mode_tianyin_voice_msg.h"  
#elif defined(adk_use_10k_24key_mode_tianyin_DVOICE)
      #include "adk_use_10k_24key_mode_tianyin_DVOICE_msg.h"  
#elif defined(adk_10k_15key_mode_zx_tm)
      #include "adk_10k_15key_mode_zx_tm_msg.h"  
#elif defined(adk_use_10k_24key_mode_tianyin_voice_2)
      #include "adk_use_10k_24key_mode_tianyin_voice_2_msg.h"  
#elif defined(adk_10k_15key_mode_ty_rec)
      #include "adk_10k_15key_mode_ty_rec_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rec_voice_all)  // en+ch+notice
      #include "adk_10k_15key_mode_zy_rec_voice_all_msg.h"  
#elif defined(adk_10k_15key_mode_zy_rgb_led)  
      #include "adk_10k_15key_mode_zy_rgb_led_msg.h"  
#elif defined(adk_use_10k_12key_mode_tianyin_2)  
      #include "adk_use_10k_12key_mode_tianyin_2_msg.h"  
#elif defined(adk_22k_15key_mode_gw_PP_MODE)  
      #include "adk_22k_15key_mode_gw_PP_MODE_MSG.h"  
#elif defined(adk_use_gw_22k_6key_mode)  
      #include "adk_use_gw_22k_6key_mode_MSG.h"  
#elif defined(adk_use_10key_mode_tf2138_1600B)  
      #include "adk_use_10key_mode_tf2138_1600B_MSG.h"  
#elif defined(adk_user_6_key_mode_ydl2001)  
      #include "adk_user_6_key_mode_ydl2001_MSG.h"  
#elif defined(adk_22k_10key_mode_k1910)  
      #include "adk_22k_10key_mode_k1910_MSG.h"  
#elif defined(adk_22k_10key_mode_ty)  
      #include "adk_22k_10key_mode_ty_MSG.h"  
#elif defined(adk_22k_10key_mode_kph_bj006)  
      #include "adk_22k_10key_mode_kph_bj006_msg.h"  
#elif defined(adk_user_4_key_msj_rec_key)  
      #include "adk_user_4_key_msj_rec_key_msg.h"  
#elif defined(adk_22k_10key_mode_sm_rec)  
      #include "adk_22k_10key_mode_sm_rec_msg.h"  
#elif defined(adk_10k_15key_mode_scg_rec)  
      #include "adk_10k_15key_mode_scg_rec_msg.h"  
#elif defined(adk_10k_10key_mode_805F_K02)  
      #include "adk_10k_10key_mode_805F_K02_msg.h"  
#elif defined(adk_10k_10key_mode_806F_K02)  
      #include "adk_10k_10key_mode_806F_K02_msg.h"  

	  
//------------------------------------------------------	   
#elif defined(adk_user_6_key_mode_and_power)
      #include "adk_ty_6key_mode_and_powe_msg.h"     //通用6键 MDOE 和POWER 共用 
#elif defined(adk_user_k68_key)
   #include "adk_user_k68_key.h"  
#elif defined(adk_user_07vpowerpp_4key_mode_10)
   #include "adk_user_07vpowerpp_4key_mode_10.h"  //二极管  light/Power   prev  next    pp/mode 
 
#else 
    #error("请设置	KEY MSG ")
#endif 


// ir 

#ifdef IR_USE_DOUBLE_TY_00FF_807F_22KEY
    #include "IR_USE_DOUBLE_TY_00FF_807F_22KEY_MSG.h" 
 #elif defined(IR_USER_GW_003_00FF_24KEY)
    #include "IR_USER_GW_003_00FF_24KEY_MSG.h" 
 #elif defined(IR_USE_DOUBLE_TY_00FF_807F_22KEY_ZX)
    #include "IR_USE_DOUBLE_TY_00FF_807F_22KEY_ZX_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_SLT)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_SLT_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_MICROMAX_00FF_807F_01FE_25KEY)
    #include "IR_ZY_THREE_GENERAL_MICROMAX_00FF_807F_01FE_25KEY_MSG.h" 
 #elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC)
    #include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC_MSG.h" 
 #elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC_S501)
    #include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC_S501_MSG.h" 
 #elif defined(IR_ZY_DOUBLE_GENERAL_TY5112A_00FF_HD7369_807F_30KEY)
    #include "IR_ZY_DOUBLE_GENERAL_TY5112A_00FF_HD7369_807F_30KEY_MSG.h" 
 #elif defined(IR_USE_DOUBLE_GW_00FF_807F_26KEY)
    #include "IR_USE_DOUBLE_GW_00FF_807F_26KEY_MSG.h" 
 #elif defined(IR_USE_DOUBLE_ZY2119_00FF_IR101_807F_22KEY)
    #include "IR_USE_DOUBLE_ZY2119_00FF_IR101_807F_22KEY_MSG.h" 
 #elif defined(IR_USE_TIANYUN_00FF_23KEY)
    #include "IR_USE_TIANYUN_00FF_23KEY_MSG.h" 
 #elif defined(IR_USE_FS_00FF_21KEY)
    #include "IR_USE_FS_00FF_21KEY_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_HJ820_00FF_807F_01FE_27KEY)
    #include "IR_ZY_THREE_GENERAL_HJ820_00FF_807F_01FE_27KEY_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_25KEY)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_25KEY_MSG.h" 
 #elif defined(IR_TY_THREE_GENERAL_FF00_7F00_7F80_28KEY)
    #include "IR_TY_THREE_GENERAL_FF00_7F00_7F80_28KEY_MSG.h" 
 #elif defined(IR_TY_THREE_GENERAL_FF00_7F00_7F80_30KEY_REC)
    #include "IR_TY_THREE_GENERAL_FF00_7F00_7F80_30KEY_REC_MSG.h" 
 #elif defined(IR_USE_DOUBLE_GW_00FF_807F_26KEY)
    #include "IR_USE_DOUBLE_GW_00FF_807F_26KEY_MSG.h" 
 #elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY)
    #include "IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY_MSG.h" 
 #elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY_2)
    #include "IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY_2_MSG.h" 
 #elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_29KEY_ECHO)
    #include "IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_29KEY_ECHO_MSG.h" 
 #elif defined(IR_ZY_GSJ_01FE_45KEY)
    #include "IR_ZY_GSJ_01FE_45KEY_MSG.h" 
 #elif defined(IR_SSM_THREE_GENERAL_FF00_7F80_04FB_REC)
    #include "IR_SSM_THREE_GENERAL_FF00_7F80_04FB_REC_MSG.h" 
 #elif defined(IR_TY_THREE_GENERAL_FF00_7F00_TY_7F80_31KEY_REC)
    #include "IR_TY_THREE_GENERAL_FF00_7F00_TY_7F80_31KEY_REC_MSG.h" 
#elif defined(IR_JY_DOUBLE_00FF_807F_26KEY)
      #include "IR_JY_DOUBLE_00FF_807F_26KEY_msg.h"  
#elif defined(IR_ZY_DOUBLE_00FF_807F_27KEY)
      #include "IR_ZY_DOUBLE_00FF_807F_27KEY_msg.h"  	  
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_01FE_27KEY)
      #include "IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_01FE_27KEY_msg.h"  
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_DF20_29KEY)
      #include "IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_DF20_29KEY_msg.h"  
#elif defined(IR_TF_THREE_GENERAL_FF00_FD02_7F80)
      #include "IR_TF_THREE_GENERAL_FF00_FD02_7F80_msg.h"  
#elif defined(IR_TF_THREE_GENERAL_FF00_FD02_HD7369_7F80)
      #include "IR_TF_THREE_GENERAL_FF00_FD02_HD7369_7F80_msg.h"  
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_ZR_807F_01FE_25KEY)
      #include "IR_ZY_THREE_GENERAL_YK2119_00FF_ZR_807F_01FE_25KEY_msg.h"  
#elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY)
      #include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_msg.h"  
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_27KEY)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_27KEY_MSG.h" 
 #elif defined(IR_USE_DOUBLE_ZY2119_00FF_SM_807F_25KEY)
    #include "IR_USE_DOUBLE_ZY2119_00FF_SM_807F_25KEY_MSG.h" 
 #elif defined(IR_USE_DOUBLE_ZY2119_00FF_SM_BT_807F_25KEY)
    #include "IR_USE_DOUBLE_ZY2119_00FF_SM_BT_807F_25KEY_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_VOICE)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_VOICE_MSG.h" 
 #elif defined(IR_FS_JW_29J_00dF_29KEY)
    #include "IR_FS_JW_29J_00dF_29KEY_MSG.h" 
 #elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC)
    #include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_7F00_31KEY)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_7F00_31KEY_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_IR101_807F_01FE_32KEY)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_IR101_807F_01FE_32KEY_MSG.h" 
 #elif defined(IR_ZX_FE01_21KEY)
    #include "IR_ZX_FE01_21KEY_MSG.h" 
 #elif defined(IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY)
    #include "IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_28KEY_REC)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_28KEY_REC_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_30KEY)
    #include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_30KEY_MSG.h" 
 #elif defined(IR_USE_JH_00FF_6KEY)
    #include "IR_USE_JH_00FF_6KEY_MSG.h" 
 #elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_VOICE_TY)
    #include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_VOICE_TY_MSG.h" 
 #elif defined(IR_ZY_THREE_GENERAL_JH820_00FF_807F_01FE_27KEY)
    #include "IR_ZY_THREE_GENERAL_JH820_00FF_807F_01FE_27KEY_MSG.h" 
 #elif defined(IR_TF_THREE_GENERAL_FF00_20DF)
    #include "IR_TF_THREE_GENERAL_FF00_20DF_MSG.h" 
 #elif defined(IR_ZX_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC)
    #include "IR_ZX_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC_MSG.h" 
 #elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD_7369_807F_30CF)
    #include "IR_TY_THREE_GENERAL_TY_00FF_HD_7369_807F_30CF_MSG.h" 
 #elif defined(IR_TF_DB_51_THREE_GENERAL_FF00_20DF)
    #include "IR_TF_DB_51_THREE_GENERAL_FF00_20DF_MSG.h" 
 #elif defined(IR_USE_DOUBLE_SCG_00FF_807F_22KEY)
    #include "IR_USE_DOUBLE_SCG_00FF_807F_22KEY_MSG.h" 
 #elif defined(IR_USE_MSJ_20DF_26KEY)
    #include "IR_USE_MSJ_20DF_26KEY_MSG.h" 
 #elif defined(IR_SM_THREE_GENERAL_00FF_807F_02FD_25KEY)
    #include "IR_SM_THREE_GENERAL_00FF_807F_02FD_25KEY_MSG.h" 
 #elif defined(IR_USE_SCG_DOUBLE_ZY2119_00FF_807F_22KEY)
    #include "IR_USE_SCG_DOUBLE_ZY2119_00FF_807F_22KEY_MSG.h" 






	

//--------------------------------------
 #elif defined(ir_user_kpl_ty_msg)
    #include "ir_ty_32key_msg.h" 
 #elif defined(ir_user_kpl_ty_mod_and_light)
    #include "ir_user_kpl_ty_mod_and_light.h"  //
 #elif defined(ir_user_kpl_ty_msg_3)    //// 通用 USB/SD/SCAN 仅仅  SCAN  
    #include "ir_ty_32key_msg_3.h" 
 #elif defined(ir_user_kpl_ty_pp_rec_msg)
  #include "ir_ty_32key_msg_2.h"
 #elif defined(ir_user_kpl_ty_pp_rec_msg_ls_mod)
  #include "ir_user_kpl_ty_pp_rec_msg_ls_mod.h"
 #elif defined(ir_kpl_HY_ir_001)
  #include "ir_hy_16key_msg.h"
 #elif defined(ir_user_kpl_ty_msg_2)    //改FM CH+- 为fm_step+-
 #include "ir_ty_32key_msg_2.h"
 #elif defined(ir_user_sdx_001_msg)
  #include "ir_user_sdx_001_msg.h"
#elif defined(ir_user_kpl_ty_msg_3)   //长按 上下台 短按 半自动扫台  长按MODE light 	
    #include "ir_user_kpl_ty_msg_3.h"
 #elif defined(ir_user_hy_repeat_is_rec_msg)
  #include "ir_user_hy_repeat_is_rec_msg.h"
#elif defined(ir_user_hcx_msg)
   #include "ir_user_hcx_msg.h" 
#elif defined(IR_USER_sx_ir1_msg)
    #include "IR_USER_sx_ir1_msg.h" 
#elif defined(ir_user_kpl_yx208_msg) 
   #include "ir_user_kpl_yx208_msg.h" 
#elif defined(ir_user_ir_116_2700b_msg)   
    #include "ir_user_ir_116_2700b_msg.h" 
#elif defined(ir_user_kpl_ty_msg_0to_light)
    #include "ir_user_kpl_ty_msg_0to_light.h" 
#elif defined(ir_user_kpl_ty_msg_0to_light_2)   // 100+ 10+ 
    #include "ir_user_kpl_ty_msg_0to_light_2.h" 
#elif defined(ir_user_kpl_ty_msg_out_fm)	    
    #include "ir_user_kpl_ty_msg_out_fm.h" 
#else 
 #include "ir_ty_21key_msg.h"
#endif 


