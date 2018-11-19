#include "key_drv/key_drv_ir.h"
#include "includes.h"
#include "timer.h"
#include "key_drv/key.h"
#include "clock_api.h"
#if KEY_IR_EN


#define IR_FF00	 0xff00
IR_CODE  ir_code;       ///<红外遥控信息
u16 timer1_pad;
__timer_handle *timer1_hl;


#if defined(IR_USE_DOUBLE_TY_00FF_807F_22KEY)
#include "IR_USE_DOUBLE_TY_00FF_807F_22KEY.c"
#elif defined(IR_USER_GW_003_00FF_24KEY)
#include "IR_USER_GW_003_00FF_24KEY.c"
#elif defined(IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY)
#include "IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY.c"
#elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_VOICE_TY)
#include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_VOICE_TY.c"
#elif defined(IR_ZX_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC)
#include "IR_ZX_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC.c"
#elif defined(IR_USE_DOUBLE_TY_00FF_807F_22KEY_ZX)
#include "IR_USE_DOUBLE_TY_00FF_807F_22KEY_ZX.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_SLT)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_SLT.c"
#elif defined(IR_ZY_THREE_GENERAL_MICROMAX_00FF_807F_01FE_25KEY)
#include "IR_ZY_THREE_GENERAL_MICROMAX_00FF_807F_01FE_25KEY.c"
#elif defined(IR_FS_JW_29J_00dF_29KEY)
#include "IR_FS_JW_29J_00dF_29KEY.c"
#elif defined(IR_USE_DOUBLE_GW_00FF_807F_26KEY)
#include "IR_USE_DOUBLE_GW_00FF_807F_26KEY.c"
#elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC)
#include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC.c"
#elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC_S501)
#include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_REC_S501.c"
#elif defined(IR_ZY_DOUBLE_GENERAL_TY5112A_00FF_HD7369_807F_30KEY)
#include "IR_ZY_DOUBLE_GENERAL_TY5112A_00FF_HD7369_807F_30KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_HJ820_00FF_807F_01FE_27KEY)
#include "IR_ZY_THREE_GENERAL_HJ820_00FF_807F_01FE_27KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_28KEY_REC)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_28KEY_REC.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_01FE_27KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_01FE_27KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_DF20_29KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_KX5522_807F_DF20_29KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_25KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_25KEY.c"
#elif defined(IR_USE_DOUBLE_ZY2119_00FF_IR101_807F_22KEY)
#include "IR_USE_DOUBLE_ZY2119_00FF_IR101_807F_22KEY.c"
#elif defined(IR_USE_TIANYUN_00FF_23KEY)
#include "IR_USE_TIANYUN_00FF_23KEY.c"
#elif defined(IR_USE_FS_00FF_21KEY)
#include "IR_USE_FS_00FF_21KEY.c"
#elif defined(IR_TY_THREE_GENERAL_FF00_7F00_7F80_28KEY)
#include "IR_TY_THREE_GENERAL_FF00_7F00_7F80_28KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_ZR_807F_01FE_25KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_ZR_807F_01FE_25KEY.c"
#elif defined(IR_TY_THREE_GENERAL_FF00_7F00_7F80_30KEY_REC)
#include "IR_TY_THREE_GENERAL_FF00_7F00_7F80_30KEY_REC.c"
#elif defined(IR_USE_DOUBLE_GW_00FF_807F_26KEY)
#include "IR_USE_DOUBLE_GW_00FF_807F_26KEY.c"
#elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY)
#include "IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY.c"
#elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY_2)
#include "IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_27KEY_2.c"
#elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_29KEY_ECHO)
#include "IR_TY_THREE_GENERAL_TY_00FF_HD7369_807F_30CF_29KEY_ECHO.c"
#elif defined(IR_TF_THREE_GENERAL_FF00_FD02_7F80)
#include "IR_TF_THREE_GENERAL_FF00_FD02_7F80.c"
#elif defined(IR_TF_THREE_GENERAL_FF00_FD02_HD7369_7F80)
#include "IR_TF_THREE_GENERAL_FF00_FD02_HD7369_7F80.c"
#elif defined(IR_ZY_GSJ_01FE_45KEY)
#include "IR_ZY_GSJ_01FE_45KEY.c"
#elif defined(IR_SSM_THREE_GENERAL_FF00_7F80_04FB_REC)
#include "IR_SSM_THREE_GENERAL_FF00_7F80_04FB_REC.c"
#elif defined(IR_TY_THREE_GENERAL_FF00_7F00_TY_7F80_31KEY_REC)
#include "IR_TY_THREE_GENERAL_FF00_7F00_TY_7F80_31KEY_REC.c"
#elif defined(IR_JY_DOUBLE_00FF_807F_26KEY)
#include "IR_JY_DOUBLE_00FF_807F_26KEY.c"
#elif defined(IR_ZY_DOUBLE_00FF_807F_27KEY)
#include "IR_ZY_DOUBLE_00FF_807F_27KEY.c"
#elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY)
#include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_27KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_TY21_807F_01FE_27KEY.c"
#elif defined(IR_USE_DOUBLE_ZY2119_00FF_SM_807F_25KEY)
#include "IR_USE_DOUBLE_ZY2119_00FF_SM_807F_25KEY.c"
#elif defined(IR_USE_DOUBLE_ZY2119_00FF_SM_BT_807F_25KEY)
#include "IR_USE_DOUBLE_ZY2119_00FF_SM_BT_807F_25KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_VOICE)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY_VOICE.c"
#elif defined(IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC)
#include "IR_ZY_DOUBLE_GENERAL_TY_00FF_HD7369_807F_30KEY_1REC.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_7F00_31KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_VKK15L_807F_01FE_7F00_31KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_IR101_807F_01FE_32KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_IR101_807F_01FE_32KEY.c"
#elif defined(IR_ZX_FE01_21KEY)
#include "IR_ZX_FE01_21KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_30KEY)
#include "IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_30KEY.c"
#elif defined(IR_USE_JH_00FF_6KEY)
#include "IR_USE_JH_00FF_6KEY.c"
#elif defined(IR_ZY_THREE_GENERAL_JH820_00FF_807F_01FE_27KEY)
#include "IR_ZY_THREE_GENERAL_JH820_00FF_807F_01FE_27KEY.c"
#elif defined(IR_TF_THREE_GENERAL_FF00_20DF)
#include "IR_TF_THREE_GENERAL_FF00_20DF.c"
#elif defined(IR_TY_THREE_GENERAL_TY_00FF_HD_7369_807F_30CF)
#include "IR_TY_THREE_GENERAL_TY_00FF_HD_7369_807F_30CF.c"
#elif defined(IR_TF_DB_51_THREE_GENERAL_FF00_20DF)
#include "IR_TF_DB_51_THREE_GENERAL_FF00_20DF.c"
#elif defined(IR_USE_DOUBLE_SCG_00FF_807F_22KEY)
#include "IR_USE_DOUBLE_SCG_00FF_807F_22KEY.c"
#elif defined(IR_USE_MSJ_20DF_26KEY)
#include "IR_USE_MSJ_20DF_26KEY.c"
#elif defined(IR_SM_THREE_GENERAL_00FF_807F_02FD_25KEY)
#include "IR_SM_THREE_GENERAL_00FF_807F_02FD_25KEY.c"
#elif defined(IR_USE_SCG_DOUBLE_ZY2119_00FF_807F_22KEY)
#include "IR_USE_SCG_DOUBLE_ZY2119_00FF_807F_22KEY.c"








//---------------------------------------------------
#elif defined(IR_USER_KPL_001)
#include "irc_kpl_001.c"
#elif defined(IR_USER_KPL_001_A)
#include "irc_kpl_001_A.c"	 //无VOL +-
#elif defined( IR_USER_KPL_001_B)
#include "irc_kpl_001_B.c"	  //001 交换 pp  next
#elif defined(IR_USER_KPL_002)
#include "irc_kpl_002.c"
#elif defined(ir_kpl_touch_to_ir)  //触摸 IC发遥控码
#include "ir_kpl_touch_to_ir.c"
#elif defined(IR_USER_KPL_003_a)
#include "irc_kpl_003_a.c"	//无VOL +-
#elif defined(IR_USER_KPL_003)
#include "irc_kpl_003.c"
#elif defined(IR_USER_KPL_003_3)   // PP_SCAN   onlyusb/sd
#include "irc_kpl_003_3.c"
#elif defined(IR_USER_KPL_006)
#include "irc_kpl_006.c"
#elif defined(IR_USER_yj_001)
#include "irc_yj_001.c"
#elif defined(ir_kpl_HY_ir_001)
#include "ir_kpl_HY_ir_001.c"
#elif defined(ir_kpl_00d_ir)
#include "irff00_ir_kpl_00d_ir.h"
#elif defined(ir_kpl_008_ir)
#include "irff00_ir_kpl_008_ir.c"
#elif defined(IR_USER_sdx_001)
#include "irff00_IR_USER_sdx_001.c"
#elif defined(IR_USER_hongfa_001)
#include "IR_USER_hongfa_001.c"
#elif defined(ir_kpl_007_ir)
#include "irff00_ir_kpl_007_ir.c"
#elif defined(ir_kpl_008_and_01a_ir)
#define support_double_ir
#include "irff00_ir_kpl_008_ir.c"
#include "irc_kpl_01a.c"
#elif defined(ir_kpl_008_and_01b_ir)
#define support_double_ir
#include "irff00_ir_kpl_008_ir.c"
#include "irc_kpl_01b.c"
#elif defined(IR_USER_yi_zdy_001)
#include "IR_USER_yi_zdy_001.c"
#elif defined(ir_kpl_008_and_gl_001_ir)
#define support_double_ir
#include "irff00_ir_kpl_008_ir.c"
#include "irc_gl_001.c"
#elif defined(IR_USER_hcx_2ir)
#define support_double_ir
#include "IR_USER_hcx_2ir.c"
#elif defined(IR_USER_sx_ir1)
#include "IR_USER_sx_ir1.c"
#elif defined(IR_USER_sx_ir2)
#include "IR_USER_sx_ir2.c"
#elif defined(IR_USER_xxw_001)
#include "IR_xxw_001.c"
#elif defined(IR_USER_HY_T8_001)
#include "IR_USER_HY_T8_001.c"
#elif defined(ir_gld_ske02_ir)
#include "ir_gld_ske02_ir.c"
#elif defined(IR_USER_yx208)   //USB_SD--->MENU
#include "IR_USER_yx208.c"
#elif defined(IR_USER_xp_003)
#include "IR_USER_xp_003.c"
#elif defined(IR_USER_xp_003_2)
#include "IR_USER_xp_003_2.c"

#elif defined(IR_USER_xp_003_2_kph_001)
#define support_double_ir

#include "IR_USER_xp_003_2.c"
#include "irc_kpl_001.c"
#elif defined(IR_USER_001_and_xpir)  //多乐声 双遥控
#define  support_double_ir
#include "IR_USER_001_and_xpir.h"
#elif defined(IR_USER_tc_001)
#include "IR_USER_tc_001.c"
#elif defined(IR_USER_wes_ir_116_2700b)
#define support_double_ir
#include "IR_USER_wes_ir_116_2700b.c"
#else
const u8 IRTabFF00[] =
{
    0XFF
};
#endif

/*----------------------------------------------------------------------------*/
/**@brief   ad按键初始化
   @param   void
   @param   void
   @return  void
   @note    void ad_key0_init(void)
*/
/*----------------------------------------------------------------------------*/
void ir_timeout(void *param)
{
    ir_code.boverflow++;
    if (ir_code.boverflow > 56) //56*2ms ~= 112ms
    {
        //puts("ir_to\n");
        ir_code.bState = 0;
    }
}

/*----------------------------------------------------------------------------*/
/**@brief   time1红外中断服务函数
   @param   void
   @param   void
   @return  void
   @note    void timer1_ir_isr(void)
*/
/*----------------------------------------------------------------------------*/
void timer1_isr(void)
{
    u16 bCap1;
    u8 cap = 0;
//    TMR1_CON |= BIT(14);
//    bCap1 = TMR1_PRD;
//    TMR1_CNT =0;
    bCap1=timer_ctrl(timer1_hl,TIMER_CMD_GET_PRDNUM,0,NULL);
    timer_ctrl(timer1_hl,TIMER_CMD_SET_CNT,0,NULL);
    cap = bCap1 /timer1_pad; ///ms

    if (cap <= 1)
    {
        ir_code.wData >>= 1;
        ir_code.bState++;
        ir_code.boverflow = 0;
    }
    else if (cap == 2)
    {
        ir_code.wData >>= 1;
        ir_code.bState++;
        ir_code.wData |= 0x8000;
        ir_code.boverflow = 0;
    }
    /*13ms-Sync*/
    /*
    else if ((cap == 13) || (cap < 8) || (cap > 110))
    {
        ir_code.bState = 0;
    }
    else
    {
        ir_code.boverflow = 0;
    }
    */

    else if((cap == 13)&&(ir_code.boverflow < 8))
    {
        ir_code.bState = 0;
    }
    else if((cap < 8)&&(ir_code.boverflow < 5))
    {
        ir_code.bState = 0;
    }
    else if((cap >110)&&(ir_code.boverflow > 53))
    {
        ir_code.bState = 0;
    }
    else if((cap >20)&&(ir_code.boverflow > 53)) //溢出情况下 （12M 48M）
    {
        ir_code.bState = 0;
    }
    else
    {
        ir_code.boverflow = 0;
    }

    if (ir_code.bState == 16)
    {
        ir_code.wUserCode = ir_code.wData;
        //printf("%x\n",ir_code.wData);
    }
    if (ir_code.bState == 32)
    {
        //printf("%x\n",ir_code.wData);
    }
}
/*----------------------------------------------------------------------------*/
/**@brief   ir按键初始化
   @param   void
   @param   void
   @return  void
   @note    void ir_key_init(void)
*/
/*----------------------------------------------------------------------------*/
s32 ir_key_init(void)
{
    //timer1
    s32 ret = 0;
    key_puts("ir key init\n");

    __timer_param timer_param;
    timer1_hl = timer_open(TIMER1,TIMER_MAX_ISR_FUN);
    if(NULL==timer1_hl)
    {
        return TIMER_DRV_OPEN_ERR;
    }
    timer_param.work_mode=TIMER_WORK_MODE_CAPTURE_IODN;
    timer_param.tick_time=1000;//1ms
    ret = timer_init_api(timer1_hl,&timer_param);
    if(ret != TIMER_NO_ERR)
        return ret;

#if 1
#ifdef IR_IO_PA_X
    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_SET,IR_PORTA(IR_IO_PA_X),NULL);///IRFLT IO SEL
#elif defined IR_IO_PB_X
    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_SET,IR_PORTB(IR_IO_PB_X),NULL);///IRFLT IO SEL
#elif defined IR_IO_PC_X
    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_SET,IR_PORTC(IR_IO_PC_X),NULL);///IRFLT IO SEL
#elif defined IR_IO_PD_X
    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_SET,IR_PORTD(IR_IO_PD_X),NULL);///IRFLT IO SEL
#else
    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_SET,IR_PORTA(14),NULL);///IRFLT IO SEL
#endif

#else
#ifdef IR_IO
    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_SET,IR_IO,NULL);///IRFLT IO SEL
#else
    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_SET,IR_PORTA(14),NULL);///IRFLT IO SEL
#endif
#endif
    if(ret!=TIMER_NO_ERR)
        return ret;

    timer1_pad=timer_ctrl(timer1_hl,TIMER_CMD_GET_START_PRDNUM,0,NULL);

    ret=timer_reg_isr_callback_fun(timer1_hl,4,timer1_isr);
    if(ret!=TIMER_NO_ERR)
        return ret;

    ret=timer_start(timer1_hl);
    if(ret!=TIMER_NO_ERR)
        return ret;


    ret = timer_reg_isr_fun(timer0_hl,1,ir_timeout,NULL);


    if(ret != TIMER_NO_ERR)
        return ret;
    return 0;
}

/*----------------------------------------------------------------------------*/
/**@brief   获取ir按键值
   @param   void
   @param   void
   @return  void
   @note    void get_irkey_value(void)
*/
/*----------------------------------------------------------------------------*/
tu8 get_irkey_value(void)
{
    tu8 tkey = 0xff;
    tu8 ir_code_temp = 0xff;

    if (ir_code.bState != 32)
    {
        return tkey;
    }

    ir_code_temp = (u8)ir_code.wData;


#ifdef __DEBUG
//  printf(" key=0x%x  sys_code=0x%x \n",ir_code_temp,ir_code.wUserCode);
//  printf("  111111111111111111\n");

#endif

    if ((((u8*)&ir_code.wData)[0] ^ ((u8*)&ir_code.wData)[1]) == 0xff)
    {
	 #ifdef IR_SYS_CODE
	         if (ir_code.wUserCode == IR_SYS_CODE)
	 #else
	         if (ir_code.wUserCode == 0xFF00)
	 #endif
        {
            if(ir_code_temp>0x20)
                ir_code_temp-=0X20;
	#ifdef IR_NUMS		
            tkey = IRTab0[ir_code_temp];
	#else
            tkey = IRTab0[ir_code_temp];
	#endif
        }

 #if IR_NUMS>=2
	 else if(ir_code.wUserCode == IR_SYS_CODE1)
		 {
		  ir_code_temp=(u8)ir_code.wData;
		  
		  if(ir_code_temp>0x20)
		  ir_code_temp -=0x20;
		  tkey = IRTab1[ir_code_temp];	  
		 }
#endif

 #if IR_NUMS>=3
 

#if defined IR_SSM_THREE_GENERAL_FF00_7F80_04FB_REC||defined SSM_Q535_OPTI_FE01_04FB_REC_AC4601||defined IR_SSM_THREE_GENERAL_FF00_7F80_04FB_INTROL

#if 0
/*0x20*/ IRC_PLAY_PAUSE,//68
/*0x21*/IRC_NUM9,// 78
/*0x22*/IRC_MODE,//80
/*0x23*/IRC_NUM2,//98
/*0x24*/IRC_STANBY,//c0
/*0x25*/IRC_NUM1,//d8
/*0x26*/IRC_REPEAT,//e0
/*0x27*/ IRC_NUM8,//e8
/*0x28*/IRC_NUM0,//f8
/*0x29*/IRC_PREV,//a8
/*0x2b*/IRC_NUM5,//b8

#endif

		 else if(ir_code.wUserCode == IR_SYS_CODE2)
			 {
				  ir_code_temp=(u8)ir_code.wData;
				  
				  if(ir_code_temp==0x68)
				   ir_code_temp =0x20;
				  else if(ir_code_temp==0x78)
				   ir_code_temp =0x21;
				  else if(ir_code_temp==0x80)
				   ir_code_temp =0x22;
				  else if(ir_code_temp==0x98)
				   ir_code_temp =0x23;
				  else if(ir_code_temp==0xc0)
				   ir_code_temp =0x24;
				  else if(ir_code_temp==0xd8)
				   ir_code_temp =0x25;
				  else if(ir_code_temp==0xe0)
				   ir_code_temp =0x26;
				  else if(ir_code_temp==0xe8)
				   ir_code_temp =0x27;
				  else if(ir_code_temp==0xf8)
				   ir_code_temp =0x28;
				  else if(ir_code_temp==0xa8)
				   ir_code_temp =0x29;
				  else if(ir_code_temp==0xb8)
				   ir_code_temp =0x2b;				  
				  
				  tkey = IRTab2[ir_code_temp];	  
			 }		 
#else
		 else if(ir_code.wUserCode == IR_SYS_CODE2)
			 {
			  ir_code_temp=(u8)ir_code.wData;
			  if(ir_code_temp>0x20)
			  ir_code_temp -=0x20;
			  tkey = IRTab2[ir_code_temp];	  
			 //  tkey = IRTab1[(u8)ir_code.wData];
			 }
#endif		 
#endif


 #if IR_NUMS>=4
	 else if(ir_code.wUserCode == IR_SYS_CODE3)
		 {
		  ir_code_temp=(u8)ir_code.wData;
		  
		  if(ir_code_temp>0x20)
		  ir_code_temp -=0x20;
		  tkey = IRTab3[ir_code_temp];	  
		 }
#endif

#ifdef support_double_ir
        else
        {
            if(ir_code_temp>0x20)
                ir_code_temp-=0X20;
            tkey = IRTabFF00_2[ir_code_temp];
        }
#endif

    }
    else
    {
        ir_code.bState = 0;
    }




    return tkey;
}

#if 0
{
    tu8 tkey = 0xff;
    if (ir_code.bState != 32)
    {
        return tkey;
    }

    if ((((u8*)&ir_code.wData)[0] ^ ((u8*)&ir_code.wData)[1]) == 0xff)
    {
        if (ir_code.wUserCode == 0xFF00)
        {
            tkey = IRTabFF00[(u8)ir_code.wData];
        }
    }
    else
    {
        ir_code.bState = 0;
    }
    return tkey;
}
#endif
s32 ir_key_ck_reset(void)
{
    s32 ret = 0;
    __timer_param timer_param;
    puts("ir_clk_reset\n");

    timer_param.work_mode=TIMER_WORK_MODE_CAPTURE_IODN;
    timer_param.tick_time=1000;//1ms

    ret = timer_init_api(timer1_hl,&timer_param);
    if(ret != TIMER_NO_ERR)
    {
        printf("timer_init err = %x\n",ret);
        return ret;
    }

    ret=timer_start(timer1_hl);
    if(ret!=TIMER_NO_ERR)
    {
        printf("timer_start err = %x\n",ret);
        return ret;
    }

    ret=timer_ctrl(timer1_hl,TIMER_CMD_IRFLT_CLK_SET,0,NULL);///IRFLT IO SEL
    if(ret!=TIMER_NO_ERR)
    {
        printf("irft err = %x\n",ret);
        return ret;
    }

    timer1_pad=timer_ctrl(timer1_hl,TIMER_CMD_GET_START_PRDNUM,0,NULL);
    puts("ir_clk_ok\n");
    return TIMER_NO_ERR;
}
#else

SET(interrupt(""))void timer1_isr(void)
{

}
#endif/*KEY_IR_EN*/



