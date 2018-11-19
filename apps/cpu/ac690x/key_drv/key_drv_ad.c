#include "includes.h"
#include "key_drv/key_drv_ad.h"
#include "key_drv/key.h"
#include "clock_api.h"
#include "adc_api.h"
#include "timer.h"
#include "sys_detect.h"
#include "rtc/rtc_api.h"

#ifdef PP_LED_USER_ADKEY
bool g_ad_led_flag;
#endif

#define AD_KEY_IO_PAX   6
u16 adc_value[MAX_AD_CHANNEL];
const u32 ad_table[] =
{
#if KEY_AD_EN
	 #ifdef adk_user_pa3
	     AD_KEY_PA3,
	 #elif defined(adk_user_pa4)
	     AD_KEY_PA4,
	 #elif defined(adk_user_pa5)
	     AD_KEY_PA5,
	 #elif defined(adk_user_pa6)
	     AD_KEY_PA6,
	 #elif defined(adk_user_pa9)
	     AD_KEY_PA9,
	 #elif defined(adk_user_pb9)
	     AD_KEY_PB9,
	 #elif defined(adk_user_pb7)
	     AD_KEY_PB7,
	 #elif defined(adk_user_pr1)
	     AD_KEY_PR1,
        #elif defined(adk_user_pa9pa10)
	     AD_KEY_PA9,
	     AD_KEY_PA10,
	 #elif defined(adk_user_pb11)
	     AD_KEY_PB11,
	 #else
	 #error(" 请设置 ADK IO ")
	 #endif
#endif

#ifdef EQ_ADC_VALUE_DETECT
#ifdef EQ_DETECT_PIN_USE_PB11
	AD_KEY_PB11,
#elif defined EQ_DETECT_PIN_USE_PB12
	AD_KEY_PB12,
#elif defined EQ_DETECT_PIN_USE_PA3
	AD_KEY_PA3,
#elif defined EQ_DETECT_PIN_USE_PA9
	AD_KEY_PA9,
#elif defined EQ_DETECT_PIN_USE_PA10

	AD_KEY_PA10,

#endif
#endif


#ifdef KOK_DETECT_USE_IO_ADC_VALUE
	#ifdef support_mic_check_user_PB9
		  AD_KEY_PB9,
	#elif defined support_mic_check_user_PB10
		     AD_KEY_PB10,
	#elif defined support_mic_check_user_PB11
		     AD_KEY_PB11,		     
	#elif defined support_mic_check_user_PB7
		  AD_KEY_PB7,
	#elif defined support_mic_check_user_PA3
		  AD_KEY_PA3,
	
	#endif
#endif

#ifdef SUPPORT_BAT_DETECT
#if defined(DETECT_EXTERNAL_BAT_USE_PB10)
			AD_KEY_PB10,
#elif defined DETECT_EXTERNAL_BAT_USE_PB11
			AD_KEY_PB11,
#elif defined DETECT_EXTERNAL_BAT_USE_PB9
			AD_KEY_PB9,
#elif defined DETECT_EXTERNAL_BAT_USE_PB12
			AD_KEY_PB12,
#elif defined DETECT_EXTERNAL_BAT_USE_PA4
			AD_KEY_PA4,
#elif defined DETECT_EXTERNAL_BAT_USE_PA10
			AD_KEY_PA10,
#endif

#ifdef SUPPORT_BAT_DET_USE_EXTERN_AD_COMPARION
#ifdef AD_COMPARION_USE_PB11  // 2.5V
			AD_KEY_PB11,
#elif defined AD_COMPARION_USE_PB9
			AD_KEY_PB9,
#endif
#endif
#endif


#ifdef SUPPORT_AMP_MUTE_EXTERN_AD_DET
#ifdef support_phone_chack_user_PB12
	AD_KEY_PB12,
#elif defined support_phone_chack_user_PB10
	AD_KEY_PB10,
#endif
#endif

    AD_KEY_LDOIN,
    AD_KEY_LDOREF,
};


#ifdef ADK_USE_15KEY_MODE

#define AD_RES_PULL  (u32)(PULL_UP_RESISTANCE*1000)

#define AD_RES1     (u32)(KEY0_NOKEY_RES*1000)
#define AD_RES2     (u32)(KEY1_RES*1000)
#define AD_RES3     (u32)(KEY2_RES*1000)
#define AD_RES4     (u32)(KEY3_RES*1000)
#define AD_RES5     (u32)(KEY4_RES*1000)
#define AD_RES6     (u32)(KEY5_RES*1000)
#define AD_RES7     (u32)(KEY6_RES*1000)
#define AD_RES8     (u32)(KEY7_RES*1000)
#define AD_RES9     (u32)(KEY8_RES*1000)
#define AD_RESA     (u32)(KEY9_RES*1000)
#define AD_RESB     (u32)(KEYA_RES*1000)
#define AD_RESC     (u32)(KEYB_RES*1000)
#define AD_RESD     (u32)(KEYC_RES*1000)
#define AD_RESE     (u32)(KEYD_RES*1000)
#define AD_RESF     (u32)(KEYE_RES*1000)


#define AD_VDD      (u32)0x3FF
#define AD_VOL1     (u32)(AD_RES1*100/(AD_RES1+AD_RES_PULL))*AD_VDD/100
#define AD_VOL2     (u32)(AD_RES2*100/(AD_RES2+AD_RES_PULL))*AD_VDD/100
#define AD_VOL3     (u32)(AD_RES3*100/(AD_RES3+AD_RES_PULL))*AD_VDD/100
#define AD_VOL4     (u32)(AD_RES4*100/(AD_RES4+AD_RES_PULL))*AD_VDD/100
#define AD_VOL5     (u32)(AD_RES5*100/(AD_RES5+AD_RES_PULL))*AD_VDD/100
#define AD_VOL6     (u32)(AD_RES6*100/(AD_RES6+AD_RES_PULL))*AD_VDD/100
#define AD_VOL7     (u32)(AD_RES7*100/(AD_RES7+AD_RES_PULL))*AD_VDD/100
#define AD_VOL8     (u32)(AD_RES8*100/(AD_RES8+AD_RES_PULL))*AD_VDD/100
#define AD_VOL9     (u32)(AD_RES9*100/(AD_RES9+AD_RES_PULL))*AD_VDD/100
#define AD_VOLA     (u32)(AD_RESA*100/(AD_RESA+AD_RES_PULL))*AD_VDD/100
#define AD_VOLB     (u32)(AD_RESB*100/(AD_RESB+AD_RES_PULL))*AD_VDD/100
#define AD_VOLC     (u32)(AD_RESC*100/(AD_RESC+AD_RES_PULL))*AD_VDD/100
#define AD_VOLD     (u32)(AD_RESD*100/(AD_RESD+AD_RES_PULL))*AD_VDD/100
#define AD_VOLE     (u32)(AD_RESE*100/(AD_RESE+AD_RES_PULL))*AD_VDD/100
#define AD_VOLF     (u32)0x0000

#define AD_GND      (u32)0x0000

#define AD_NOKEY    ((((u16)AD_VDD - AD_VOL1)/2) + AD_VOL1)
#define ADKEY1_0     ((((u16)AD_VOL1 - AD_VOL2)/2) + AD_VOL2)
#define ADKEY1_1     ((((u16)AD_VOL2 - AD_VOL3)/2) + AD_VOL3)
#define ADKEY1_2     ((((u16)AD_VOL3 - AD_VOL4)/2) + AD_VOL4)
#define ADKEY1_3     ((((u16)AD_VOL4 - AD_VOL5)/2) + AD_VOL5)
#define ADKEY1_4    ((((u16)AD_VOL5 - AD_VOL6)/2) + AD_VOL6)
#define ADKEY1_5     ((((u16)AD_VOL6 - AD_VOL7)/2) + AD_VOL7)
#define ADKEY1_6     ((((u16)AD_VOL7 - AD_VOL8)/2) + AD_VOL8)
#define ADKEY1_7     ((((u16)AD_VOL8 - AD_VOL9)/2) + AD_VOL9)
#define ADKEY1_8     ((((u16)AD_VOL9- AD_VOLA)/2) + AD_VOLA)
#define ADKEY1_9     ((((u16)AD_VOLA- AD_VOLB)/2) + AD_VOLB)
#define ADKEY1_A     ((((u16)AD_VOLB- AD_VOLC)/2) + AD_VOLC)
#define ADKEY1_B     ((((u16)AD_VOLC- AD_VOLD)/2) + AD_VOLD)
#define ADKEY1_C     ((((u16)AD_VOLD- AD_VOLE)/2) + AD_VOLE)
#define ADKEY1_D     ((((u16)AD_VOLE- AD_VOLF)/2) + AD_VOLF)

const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8,ADKEY1_9,
    ADKEY1_A,ADKEY1_B,ADKEY1_C,ADKEY1_D
};

#elif defined(ADK_USE_16KEY_MODE)

#define AD_RES_PULL  (u32)(PULL_UP_RESISTANCE*1000)

#define AD_RES0     (u32)(KEY0_NOKEY_RES*1000)
#define AD_RES1     (u32)(KEY1_RES*1000)
#define AD_RES2     (u32)(KEY2_RES*1000)
#define AD_RES3     (u32)(KEY3_RES*1000)
#define AD_RES4     (u32)(KEY4_RES*1000)
#define AD_RES5     (u32)(KEY5_RES*1000)
#define AD_RES6     (u32)(KEY6_RES*1000)
#define AD_RES7     (u32)(KEY7_RES*1000)
#define AD_RES8     (u32)(KEY8_RES*1000)
#define AD_RES9     (u32)(KEY9_RES*1000)
#define AD_RESA     (u32)(KEYA_RES*1000)
#define AD_RESB     (u32)(KEYB_RES*1000)
#define AD_RESC     (u32)(KEYC_RES*1000)
#define AD_RESD     (u32)(KEYD_RES*1000)
#define AD_RESE     (u32)(KEYE_RES*1000)
#define AD_RESF     (u32)(KEYF_RES*1000)

#define AD_VDD      (u32)0x3FF
#define AD_VOL0     (u32)(AD_RES0*100/(AD_RES0+AD_RES_PULL))*AD_VDD/100
#define AD_VOL1     (u32)(AD_RES1*100/(AD_RES1+AD_RES_PULL))*AD_VDD/100
#define AD_VOL2     (u32)(AD_RES2*100/(AD_RES2+AD_RES_PULL))*AD_VDD/100
#define AD_VOL3     (u32)(AD_RES3*100/(AD_RES3+AD_RES_PULL))*AD_VDD/100
#define AD_VOL4     (u32)(AD_RES4*100/(AD_RES4+AD_RES_PULL))*AD_VDD/100
#define AD_VOL5     (u32)(AD_RES5*100/(AD_RES5+AD_RES_PULL))*AD_VDD/100
#define AD_VOL6     (u32)(AD_RES6*100/(AD_RES6+AD_RES_PULL))*AD_VDD/100
#define AD_VOL7     (u32)(AD_RES7*100/(AD_RES7+AD_RES_PULL))*AD_VDD/100
#define AD_VOL8     (u32)(AD_RES8*100/(AD_RES8+AD_RES_PULL))*AD_VDD/100
#define AD_VOL9     (u32)(AD_RES9*100/(AD_RES9+AD_RES_PULL))*AD_VDD/100
#define AD_VOLA     (u32)(AD_RESA*100/(AD_RESA+AD_RES_PULL))*AD_VDD/100
#define AD_VOLB     (u32)(AD_RESB*100/(AD_RESB+AD_RES_PULL))*AD_VDD/100
#define AD_VOLC     (u32)(AD_RESC*100/(AD_RESC+AD_RES_PULL))*AD_VDD/100
#define AD_VOLD     (u32)(AD_RESD*100/(AD_RESD+AD_RES_PULL))*AD_VDD/100
#define AD_VOLE     (u32)(AD_RESE*100/(AD_RESE+AD_RES_PULL))*AD_VDD/100
#define AD_VOLF     (u32)0x0000

#define AD_GND      (u32)0x0000

#define AD_NOKEY     ((((u16)AD_VDD - AD_VOL0)/2) + AD_VOL0)
#define ADKEY1_0     ((((u16)AD_VOL0 - AD_VOL1)/2) + AD_VOL1)
#define ADKEY1_1     ((((u16)AD_VOL1 - AD_VOL2)/2) + AD_VOL2)
#define ADKEY1_2     ((((u16)AD_VOL2 - AD_VOL3)/2) + AD_VOL3)
#define ADKEY1_3     ((((u16)AD_VOL3 - AD_VOL4)/2) + AD_VOL4)
#define ADKEY1_4     ((((u16)AD_VOL4 - AD_VOL5)/2) + AD_VOL5)
#define ADKEY1_5     ((((u16)AD_VOL5 - AD_VOL6)/2) + AD_VOL6)
#define ADKEY1_6     ((((u16)AD_VOL6 - AD_VOL7)/2) + AD_VOL7)
#define ADKEY1_7     ((((u16)AD_VOL7 - AD_VOL8)/2) + AD_VOL8)
#define ADKEY1_8     ((((u16)AD_VOL8- AD_VOL9)/2) + AD_VOL9)
#define ADKEY1_9     ((((u16)AD_VOL9- AD_VOLA)/2) + AD_VOLA)
#define ADKEY1_A     ((((u16)AD_VOLA- AD_VOLB)/2) + AD_VOLB)
#define ADKEY1_B     ((((u16)AD_VOLB- AD_VOLC)/2) + AD_VOLC)
#define ADKEY1_C     ((((u16)AD_VOLC- AD_VOLD)/2) + AD_VOLD)
#define ADKEY1_D     ((((u16)AD_VOLD- AD_VOLE)/2) + AD_VOLE)
#define ADKEY1_E     ((((u16)AD_VOLE- AD_VOLF)/2) + AD_VOLF)

const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8,ADKEY1_9,
    ADKEY1_A,ADKEY1_B,ADKEY1_C,ADKEY1_D,ADKEY1_E
};


#elif defined(ADK_USE_12KEY_MODE)
#define AD_RES_PULL  (u32)(PULL_UP_RESISTANCE*1000)

#define AD_RES1     (u32)(KEY0_NOKEY_RES*1000)
#define AD_RES2     (u32)(KEY1_RES*1000)
#define AD_RES3     (u32)(KEY2_RES*1000)
#define AD_RES4     (u32)(KEY3_RES*1000)
#define AD_RES5     (u32)(KEY4_RES*1000)
#define AD_RES6     (u32)(KEY5_RES*1000)
#define AD_RES7     (u32)(KEY6_RES*1000)
#define AD_RES8     (u32)(KEY7_RES*1000)
#define AD_RES9     (u32)(KEY8_RES*1000)
#define AD_RESA     (u32)(KEY9_RES*1000)
#define AD_RESB     (u32)(KEYA_RES*1000)
#define AD_RESC     (u32)(KEYB_RES*1000)

#define AD_VDD      (u32)0x3FF
#define AD_VOL1     (u32)(AD_RES1*100/(AD_RES1+AD_RES_PULL))*AD_VDD/100
#define AD_VOL2     (u32)(AD_RES2*100/(AD_RES2+AD_RES_PULL))*AD_VDD/100
#define AD_VOL3     (u32)(AD_RES3*100/(AD_RES3+AD_RES_PULL))*AD_VDD/100
#define AD_VOL4     (u32)(AD_RES4*100/(AD_RES4+AD_RES_PULL))*AD_VDD/100
#define AD_VOL5     (u32)(AD_RES5*100/(AD_RES5+AD_RES_PULL))*AD_VDD/100
#define AD_VOL6     (u32)(AD_RES6*100/(AD_RES6+AD_RES_PULL))*AD_VDD/100
#define AD_VOL7     (u32)(AD_RES7*100/(AD_RES7+AD_RES_PULL))*AD_VDD/100
#define AD_VOL8     (u32)(AD_RES8*100/(AD_RES8+AD_RES_PULL))*AD_VDD/100
#define AD_VOL9     (u32)(AD_RES9*100/(AD_RES9+AD_RES_PULL))*AD_VDD/100
#define AD_VOLA     (u32)(AD_RESA*100/(AD_RESA+AD_RES_PULL))*AD_VDD/100
#define AD_VOLB     (u32)(AD_RESB*100/(AD_RESB+AD_RES_PULL))*AD_VDD/100
#define AD_VOLC     (u32)0x0000

#define AD_GND      (u32)0x0000

#define AD_NOKEY    ((((u16)AD_VDD - AD_VOL1)/2) + AD_VOL1)
#define ADKEY1_0     ((((u16)AD_VOL1 - AD_VOL2)/2) + AD_VOL2)
#define ADKEY1_1     ((((u16)AD_VOL2 - AD_VOL3)/2) + AD_VOL3)
#define ADKEY1_2     ((((u16)AD_VOL3 - AD_VOL4)/2) + AD_VOL4)
#define ADKEY1_3     ((((u16)AD_VOL4 - AD_VOL5)/2) + AD_VOL5)
#define ADKEY1_4    ((((u16)AD_VOL5 - AD_VOL6)/2) + AD_VOL6)
#define ADKEY1_5     ((((u16)AD_VOL6 - AD_VOL7)/2) + AD_VOL7)
#define ADKEY1_6     ((((u16)AD_VOL7 - AD_VOL8)/2) + AD_VOL8)
#define ADKEY1_7     ((((u16)AD_VOL8 - AD_VOL9)/2) + AD_VOL9)
#define ADKEY1_8     ((((u16)AD_VOL9- AD_VOLA)/2) + AD_VOLA)
#define ADKEY1_9     ((((u16)AD_VOLA- AD_VOLB)/2) + AD_VOLB)
#define ADKEY1_A     ((((u16)AD_VOLB- AD_VOLC)/2) + AD_VOLC)


const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8,ADKEY1_9,
    ADKEY1_A,
};
#elif defined(ADK_USE_11KEY_MODE)
#define AD_RES_PULL  (u32)(PULL_UP_RESISTANCE*1000)

#define AD_RES1     (u32)(KEY0_NOKEY_RES*1000)
#define AD_RES2     (u32)(KEY1_RES*1000)
#define AD_RES3     (u32)(KEY2_RES*1000)
#define AD_RES4     (u32)(KEY3_RES*1000)
#define AD_RES5     (u32)(KEY4_RES*1000)
#define AD_RES6     (u32)(KEY5_RES*1000)
#define AD_RES7     (u32)(KEY6_RES*1000)
#define AD_RES8     (u32)(KEY7_RES*1000)
#define AD_RES9     (u32)(KEY8_RES*1000)
#define AD_RESA     (u32)(KEY9_RES*1000)
#define AD_RESB     (u32)(KEYA_RES*1000)

#define AD_VDD      (u32)0x3FF
#define AD_VOL1     (u32)(AD_RES1*100/(AD_RES1+AD_RES_PULL))*AD_VDD/100
#define AD_VOL2     (u32)(AD_RES2*100/(AD_RES2+AD_RES_PULL))*AD_VDD/100
#define AD_VOL3     (u32)(AD_RES3*100/(AD_RES3+AD_RES_PULL))*AD_VDD/100
#define AD_VOL4     (u32)(AD_RES4*100/(AD_RES4+AD_RES_PULL))*AD_VDD/100
#define AD_VOL5     (u32)(AD_RES5*100/(AD_RES5+AD_RES_PULL))*AD_VDD/100
#define AD_VOL6     (u32)(AD_RES6*100/(AD_RES6+AD_RES_PULL))*AD_VDD/100
#define AD_VOL7     (u32)(AD_RES7*100/(AD_RES7+AD_RES_PULL))*AD_VDD/100
#define AD_VOL8     (u32)(AD_RES8*100/(AD_RES8+AD_RES_PULL))*AD_VDD/100
#define AD_VOL9     (u32)(AD_RES9*100/(AD_RES9+AD_RES_PULL))*AD_VDD/100
#define AD_VOLA     (u32)(AD_RESA*100/(AD_RESA+AD_RES_PULL))*AD_VDD/100
#define AD_VOLB     (u32)0x0000

#define AD_GND      (u32)0x0000

#define AD_NOKEY    ((((u16)AD_VDD - AD_VOL1)/2) + AD_VOL1)
#define ADKEY1_0     ((((u16)AD_VOL1 - AD_VOL2)/2) + AD_VOL2)
#define ADKEY1_1     ((((u16)AD_VOL2 - AD_VOL3)/2) + AD_VOL3)
#define ADKEY1_2     ((((u16)AD_VOL3 - AD_VOL4)/2) + AD_VOL4)
#define ADKEY1_3     ((((u16)AD_VOL4 - AD_VOL5)/2) + AD_VOL5)
#define ADKEY1_4    ((((u16)AD_VOL5 - AD_VOL6)/2) + AD_VOL6)
#define ADKEY1_5     ((((u16)AD_VOL6 - AD_VOL7)/2) + AD_VOL7)
#define ADKEY1_6     ((((u16)AD_VOL7 - AD_VOL8)/2) + AD_VOL8)
#define ADKEY1_7     ((((u16)AD_VOL8 - AD_VOL9)/2) + AD_VOL9)
#define ADKEY1_8     ((((u16)AD_VOL9- AD_VOLA)/2) + AD_VOLA)
#define ADKEY1_9     ((((u16)AD_VOLA- AD_VOLB)/2) + AD_VOLB)


const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8,ADKEY1_9,
};
#elif defined(adk_22k_10key_pull_high_1)

/*
PLAY/PAUSE	电阻值:0R  长按录音
REC			电阻值:1K
RECOLAY		电阻值:3K3
MODE		电阻值:7K5
REPEA/DEL	电阻值:10K
EQ			电阻值:15K
NEXT/VOL+	电阻值:20K
PREV/VOL-	电阻值:33K
FOL+		电阻值:56K
STOP		电阻值:100K
*/


#define ADC10_33   (0x3ffL)
#define ADC10_30   (0x3ffL*27/33)
#define ADC10_27   (0x3ffL*23/33)
#define ADC10_23   (0x3ffL*20/33)
#define ADC10_20   (0x3ffL*16/33)
#define ADC10_16   (0x3ffL*13/33)
#define ADC10_13   (0x3ffL*10/33)
#define ADC10_10   (0x3ffL*8/33)
#define ADC10_07   (0x3ffL*4/33)
#define ADC10_04   (0x3ffL*2/33)
#define ADC10_00   (0)

#define AD_NOKEY        ((ADC10_33 + ADC10_30)/2)
#define ADKEY1_0		((ADC10_30 + ADC10_27)/2)
#define ADKEY1_1		((ADC10_27 + ADC10_23)/2)
#define ADKEY1_2		((ADC10_23 + ADC10_20)/2)
#define ADKEY1_3		((ADC10_20 + ADC10_16)/2)
#define ADKEY1_4		((ADC10_16 + ADC10_13)/2)
#define ADKEY1_5		((ADC10_13 + ADC10_10)/2)
#define ADKEY1_6		((ADC10_10 + ADC10_07)/2)
#define ADKEY1_7		((ADC10_07 + ADC10_04)/2)
#define ADKEY1_8		((ADC10_04 + ADC10_00)/2)

const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8
};



#elif defined(ADK_USE_10KEY_MODE)

#define AD_RES_PULL  (u32)(PULL_UP_RESISTANCE*1000)

#define AD_RES1     (u32)(KEY0_NOKEY_RES*1000)
#define AD_RES2     (u32)(KEY1_RES*1000)
#define AD_RES3     (u32)(KEY2_RES*1000)
#define AD_RES4     (u32)(KEY3_RES*1000)
#define AD_RES5     (u32)(KEY4_RES*1000)
#define AD_RES6     (u32)(KEY5_RES*1000)
#define AD_RES7     (u32)(KEY6_RES*1000)
#define AD_RES8     (u32)(KEY7_RES*1000)
#define AD_RES9     (u32)(KEY8_RES*1000)
#define AD_RESA     (u32)(KEY9_RES*1000)

#define AD_VDD      (u32)0x3FF
#define AD_VOL1     (u32)(AD_RES1*100/(AD_RES1+AD_RES_PULL))*AD_VDD/100  // 2.97
#define AD_VOL2     (u32)(AD_RES2*100/(AD_RES2+AD_RES_PULL))*AD_VDD/100
#define AD_VOL3     (u32)(AD_RES3*100/(AD_RES3+AD_RES_PULL))*AD_VDD/100
#define AD_VOL4     (u32)(AD_RES4*100/(AD_RES4+AD_RES_PULL))*AD_VDD/100
#define AD_VOL5     (u32)(AD_RES5*100/(AD_RES5+AD_RES_PULL))*AD_VDD/100
#define AD_VOL6     (u32)(AD_RES6*100/(AD_RES6+AD_RES_PULL))*AD_VDD/100
#define AD_VOL7     (u32)(AD_RES7*100/(AD_RES7+AD_RES_PULL))*AD_VDD/100
#define AD_VOL8     (u32)(AD_RES8*100/(AD_RES8+AD_RES_PULL))*AD_VDD/100
#define AD_VOL9     (u32)(AD_RES9*100/(AD_RES9+AD_RES_PULL))*AD_VDD/100
#define AD_VOLA     (u32)0x0000

#define AD_GND      (u32)0x0000

#define AD_NOKEY    ((((u16)AD_VDD - AD_VOL1)/2) + AD_VOL1)
#define ADKEY1_0     ((((u16)AD_VOL1 - AD_VOL2)/2) + AD_VOL2)
#define ADKEY1_1     ((((u16)AD_VOL2 - AD_VOL3)/2) + AD_VOL3)
#define ADKEY1_2     ((((u16)AD_VOL3 - AD_VOL4)/2) + AD_VOL4)
#define ADKEY1_3     ((((u16)AD_VOL4 - AD_VOL5)/2) + AD_VOL5)
#define ADKEY1_4    ((((u16)AD_VOL5 - AD_VOL6)/2) + AD_VOL6)
#define ADKEY1_5     ((((u16)AD_VOL6 - AD_VOL7)/2) + AD_VOL7)
#define ADKEY1_6     ((((u16)AD_VOL7 - AD_VOL8)/2) + AD_VOL8)
#define ADKEY1_7     ((((u16)AD_VOL8 - AD_VOL9)/2) + AD_VOL9)
#define ADKEY1_8     ((((u16)AD_VOL9- AD_VOLA)/2) + AD_VOLA)

const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8
};

#elif defined GENERAL_10K_PULL_HIGHT

// 0.818797	1.262963		1.572251		1.980000		2.329412		2.532558		2.759016		3.0	3.156522
#define ADC10_33   (0x3ffL)
#define ADC10_30   (0x3ffL*32/33)
#define ADC10_27   (0x3ffL*30/33)
#define ADC10_23   (0x3ffL*28/33)
#define ADC10_20   (0x3ffL*25/33)
#define ADC10_17   (0x3ffL*23/33)
#define ADC10_13   (0x3ffL*20/33)
#define ADC10_10   (0x3ffL*15/33)
#define ADC10_07   (0x3ffL*12/33)
#define ADC10_04   (0x3ffL*8/33)
#define ADC10_00   (0)

#define AD_NOKEY        ((ADC10_33 + ADC10_30)/2)
#define ADKEY1_0		((ADC10_30 + ADC10_27)/2)
#define ADKEY1_1		((ADC10_27 + ADC10_23)/2)
#define ADKEY1_2		((ADC10_23 + ADC10_20)/2)
#define ADKEY1_3		((ADC10_20 + ADC10_17)/2)
#define ADKEY1_4		((ADC10_17 + ADC10_13)/2)
#define ADKEY1_5		((ADC10_13 + ADC10_10)/2)
#define ADKEY1_6		((ADC10_10 + ADC10_07)/2)
#define ADKEY1_7		((ADC10_07 + ADC10_04)/2)
#define ADKEY1_8		((ADC10_04 + ADC10_00)/2)

const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8
};


#else
#define ADC10_33   (0x3ffL)
#define ADC10_30   (0x3ffL*30/33)
#define ADC10_27   (0x3ffL*27/33)
#define ADC10_23   (0x3ffL*23/33)
#define ADC10_20   (0x3ffL*20/33)
#define ADC10_17   (0x3ffL*17/33)
#define ADC10_13   (0x3ffL*13/33)
#define ADC10_10   (0x3ffL*10/33)
#define ADC10_07   (0x3ffL*07/33)
#define ADC10_04   (0x3ffL*04/33)
#define ADC10_00   (0)

#define AD_NOKEY        ((ADC10_33 + ADC10_30)/2)
#define ADKEY1_0		((ADC10_30 + ADC10_27)/2)
#define ADKEY1_1		((ADC10_27 + ADC10_23)/2)
#define ADKEY1_2		((ADC10_23 + ADC10_20)/2)
#define ADKEY1_3		((ADC10_20 + ADC10_17)/2)
#define ADKEY1_4		((ADC10_17 + ADC10_13)/2)
#define ADKEY1_5		((ADC10_13 + ADC10_10)/2)
#define ADKEY1_6		((ADC10_10 + ADC10_07)/2)
#define ADKEY1_7		((ADC10_07 + ADC10_04)/2)
#define ADKEY1_8		((ADC10_04 + ADC10_00)/2)

const u16 ad_key_table[] =
{
    ADKEY1_0,ADKEY1_1,ADKEY1_2,ADKEY1_3,ADKEY1_4,
    ADKEY1_5,ADKEY1_6,ADKEY1_7,ADKEY1_8
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
#define ADC_LVD_LDO5V	0
#define ADC_LVD_VBAT	1
void ad_key0_init(void)
{
    s32 ret;
    key_puts("ad key init\n");

#if KEY_AD_EN

#ifdef adk_user_pa3
    JL_PORTA->PD &= ~BIT(3);
    JL_PORTA->PU &= ~BIT(3);
    JL_PORTA->DIR |= BIT(3);
    JL_PORTA->DIE &= ~BIT(3);
#elif defined(adk_user_pa4)
    JL_PORTA->PD &= ~BIT(4);
    JL_PORTA->PU &= ~BIT(4);
    JL_PORTA->DIR |= BIT(4);
    JL_PORTA->DIE &= ~BIT(4);
#elif defined(adk_user_pa5)
    JL_PORTA->PD &= ~BIT(5);
    JL_PORTA->PU &= ~BIT(5);
    JL_PORTA->DIR |= BIT(5);
    JL_PORTA->DIE &= ~BIT(5);
#elif defined(adk_user_pa6)
    JL_PORTA->PD &= ~BIT(6);
    JL_PORTA->PU &= ~BIT(6);
    JL_PORTA->DIR |= BIT(6);
    JL_PORTA->DIE &= ~BIT(6);
#elif defined(adk_user_pa9)
    JL_PORTA->PD &= ~BIT(9);
    JL_PORTA->PU &= ~BIT(9);
    JL_PORTA->DIR |= BIT(9);
    JL_PORTA->DIE &= ~BIT(9);

#elif defined(adk_user_pa9pa10)

    JL_PORTA->PD &= ~BIT(9);
    JL_PORTA->PU &= ~BIT(9);
    JL_PORTA->DIR |= BIT(9);
    JL_PORTA->DIE &= ~BIT(9);

    JL_PORTA->PD &= ~BIT(10);
    JL_PORTA->PU &= ~BIT(10);
    JL_PORTA->DIR |= BIT(10);
    JL_PORTA->DIE &= ~BIT(10);

#elif defined(adk_user_pa10)
    JL_PORTA->PD &= ~BIT(10);
    JL_PORTA->PU &= ~BIT(10);
    JL_PORTA->DIR |= BIT(10);
    JL_PORTA->DIE &= ~BIT(10);
#elif defined(adk_user_pb9)
    JL_PORTB->PD &= ~BIT(9);
    JL_PORTB->PU &= ~BIT(9);
    JL_PORTB->DIR |= BIT(9);
    JL_PORTB->DIE &= ~BIT(9);
#elif defined(adk_user_pb7)
    JL_PORTB->PD &= ~BIT(7);
    JL_PORTB->PU &= ~BIT(7);
    JL_PORTB->DIR |= BIT(7);
    JL_PORTB->DIE &= ~BIT(7);
#elif defined(adk_user_pr1)

	PORTR_PU(PORTR1,0);
	PORTR_PD(PORTR1,0);
	PORTR_DIR(PORTR1,1);
	PORTR_DIE(PORTR1,0);
	PORTR1_ADCEN_CTL(1);  //开PR1 ADC 功能

#elif defined(adk_user_pb11)
    JL_PORTB->PD &= ~BIT(11);
    JL_PORTB->PU &= ~BIT(11);
    JL_PORTB->DIR |= BIT(11);
    JL_PORTB->DIE &= ~BIT(11);
#else
#error(" 请设置 ADK IO ")
#endif


#endif


#if defined(DETECT_EXTERNAL_BAT_USE_PB10)
	JL_PORTB->PD &= ~BIT(10);
	JL_PORTB->PU &= ~BIT(10);
	JL_PORTB->DIR |= BIT(10);
	JL_PORTB->DIE &= ~BIT(10);
#elif defined DETECT_EXTERNAL_BAT_USE_PB11
	JL_PORTB->PD &= ~BIT(11);
	JL_PORTB->PU &= ~BIT(11);
	JL_PORTB->DIR |= BIT(11);
	JL_PORTB->DIE &= ~BIT(11);
#elif defined DETECT_EXTERNAL_BAT_USE_PB9
	JL_PORTB->PD &= ~BIT(9);
	JL_PORTB->PU &= ~BIT(9);
	JL_PORTB->DIR |= BIT(9);
	JL_PORTB->DIE &= ~BIT(9);
#elif defined DETECT_EXTERNAL_BAT_USE_PB12
	JL_PORTB->PD &= ~BIT(12);
	JL_PORTB->PU &= ~BIT(12);
	JL_PORTB->DIR |= BIT(12);
	JL_PORTB->DIE &= ~BIT(12);
#elif defined DETECT_EXTERNAL_BAT_USE_PA4
	JL_PORTA->PD &= ~BIT(4);
	JL_PORTA->PU &= ~BIT(4);
	JL_PORTA->DIR |= BIT(4);
	JL_PORTA->DIE &= ~BIT(4);
#elif defined DETECT_EXTERNAL_BAT_USE_PA10
	JL_PORTA->PD &= ~BIT(10);
	JL_PORTA->PU &= ~BIT(10);
	JL_PORTA->DIR |= BIT(10);
	JL_PORTA->DIE &= ~BIT(10);

#endif

#ifdef SUPPORT_BAT_DET_USE_EXTERN_AD_COMPARION
#ifdef AD_COMPARION_USE_PB11  // 2.5V
	JL_PORTB->PD &= ~BIT(11);
	JL_PORTB->PU &= ~BIT(11);
	JL_PORTB->DIR |= BIT(11);
	JL_PORTB->DIE &= ~BIT(11);
#elif defined AD_COMPARION_USE_PB9
      JL_PORTB->PD &= ~BIT(9);
      JL_PORTB->PU &= ~BIT(9);
      JL_PORTB->DIR |= BIT(9);
      JL_PORTB->DIE &= ~BIT(9);
#endif
#endif


#ifdef EQ_ADC_VALUE_DETECT
#ifdef EQ_DETECT_PIN_USE_PB11
	JL_PORTB->PD &= ~BIT(11);
	JL_PORTB->PU &= ~BIT(11);
	JL_PORTB->DIR |= BIT(11);
	JL_PORTB->DIE &= ~BIT(11);
#elif defined 	EQ_DETECT_PIN_USE_PB12
	JL_PORTB->PD &= ~BIT(12);
	JL_PORTB->PU &= ~BIT(12);
	JL_PORTB->DIR |= BIT(12);
	JL_PORTB->DIE &= ~BIT(12);
#elif defined EQ_DETECT_PIN_USE_PA3
	JL_PORTA->PD &= ~BIT(3);
	JL_PORTA->PU &= ~BIT(3);
	JL_PORTA->DIR |= BIT(3);
	JL_PORTA->DIE &= ~BIT(3);
#elif defined EQ_DETECT_PIN_USE_PA9
	JL_PORTA->PD &= ~BIT(9);
	JL_PORTA->PU &= ~BIT(9);
	JL_PORTA->DIR |= BIT(9);
	JL_PORTA->DIE &= ~BIT(9);
#elif defined EQ_DETECT_PIN_USE_PA10
	JL_PORTA->PD &= ~BIT(10);
	JL_PORTA->PU &= ~BIT(10);
	JL_PORTA->DIR |= BIT(10);
	JL_PORTA->DIE &= ~BIT(10);
#endif
#endif


#ifdef SUPPORT_AMP_MUTE_EXTERN_AD_DET
#ifdef support_phone_chack_user_PB12
	JL_PORTB->PD &= ~BIT(12);
	JL_PORTB->PU &= ~BIT(12);
	JL_PORTB->DIR |= BIT(12);
	JL_PORTB->DIE &= ~BIT(12);
#elif defined support_phone_chack_user_PB10

	JL_PORTB->PD &= ~BIT(10);
	JL_PORTB->PU &= ~BIT(10);
	JL_PORTB->DIR |= BIT(10);
	JL_PORTB->DIE &= ~BIT(10);

#endif
#endif

#ifdef KOK_DETECT_USE_IO_ADC_VALUE
	#ifdef support_mic_check_user_PB9
	    JL_PORTB->PD &= ~BIT(9);
	    JL_PORTB->PU &= ~BIT(9);
	    JL_PORTB->DIR |= BIT(9);
	    JL_PORTB->DIE &= ~BIT(9);
	#elif defined support_mic_check_user_PB7
	    JL_PORTB->PD &= ~BIT(7);
	    JL_PORTB->PU &= ~BIT(7);
	    JL_PORTB->DIR |= BIT(7);
	    JL_PORTB->DIE &= ~BIT(7);
	#elif defined support_mic_check_user_PB10
	    JL_PORTB->PD &= ~BIT(10);
	    JL_PORTB->PU &= ~BIT(10);
	    JL_PORTB->DIR |= BIT(10);
	    JL_PORTB->DIE &= ~BIT(10);
	#elif defined support_mic_check_user_PB11
	    JL_PORTB->PD |= BIT(11);
	    JL_PORTB->PU &= ~BIT(11);
	    JL_PORTB->DIR |= BIT(11);
	    JL_PORTB->DIE &= ~BIT(11);		
	#elif defined support_mic_check_user_PA3
	    JL_PORTA->PD &= ~BIT(3);
	    JL_PORTA->PU &= ~BIT(3);
	    JL_PORTA->DIR |= BIT(3);
	    JL_PORTA->DIE &= ~BIT(3);

	#endif
#endif

    adc_init_api(ad_table[0],clock_get_lsb_freq(),SYS_LVD_EN);

#if SYS_LVD_EN
    //adc_lvd_ch_sel(ADC_LVD_LDO5V);

  ret = timer_reg_isr_fun(timer0_hl,5,(void *)battery_check,NULL);


    if(ret != TIMER_NO_ERR)
    {
        // printf("battery_check err = %x\n",ret);
    }
#endif//SYS_LVD_EN


    ret = timer_reg_isr_fun(timer0_hl,1,adc_scan,NULL);

    if(ret != TIMER_NO_ERR)
    {
        // printf("adc_scan err = %x\n",ret);
    }
}


void ad_key0_init_io()
{
#if KEY_AD_EN
	if(ad_table[0] == AD_KEY_PR1)
	{
		/* // printf("AD_KEY_PR1\n"); */
		PORTR_PU(PORTR1,0);
		PORTR_PD(PORTR1,0);
		PORTR_DIR(PORTR1,1);
		PORTR_DIE(PORTR1,0);
		PORTR1_ADCEN_CTL(1);  //开PR1 ADC 功能
	}
	else if(ad_table[0] == AD_KEY_PR2)
	{
		/* // printf("AD_KEY_PR2\n"); */
		PORTR_PU(PORTR2,0);
		PORTR_PD(PORTR2,0);
		PORTR_DIR(PORTR2,1);
		PORTR_DIE(PORTR2,0);
		PORTR2_ADCEN_CTL(1);  //开PR2 ADC 功能
	}
#endif
}


void ad_key0_clk_reset(void)
{
    adc_init_api(ad_table[0],clock_get_lsb_freq(),SYS_LVD_EN);
}

/*----------------------------------------------------------------------------*/
/**@brief   ad通道采样函数
   @param   void
   @param   void
   @return  void
   @note    void adc_scan(void)
*/
/*----------------------------------------------------------------------------*/
u8 next_channel;
volatile u8 adc_busy_flag = 0;
void adc_scan(void *param)
{
    if(adc_busy_flag)
        return;

    static u8 channel = 0;
    next_channel = channel + 1;
    if(next_channel == MAX_AD_CHANNEL)
        next_channel = 0;



    adc_value[channel++] = adc_res_api(ad_table[next_channel]);

    if (channel == MAX_AD_CHANNEL)
        channel = 0;

#ifdef PP_LED_USER_ADKEY

#if defined PP_LED_USER_PB9_LOW
    if(channel==0)
    {
	g_ad_led_flag=1;

	    JL_PORTB->PD &= ~BIT(9);
	    JL_PORTB->PU &= ~BIT(9);
	    JL_PORTB->DIR |= BIT(9);
	    JL_PORTB->DIE &= ~BIT(9);

    }
    else
    {
        g_ad_led_flag=0;

	    JL_PORTB->PD  |=BIT(9);
	    JL_PORTB->PU &=~BIT(9);
	    JL_PORTB->DIR &=~ BIT(9);
	    JL_PORTB->DIE |=BIT(9);

    }

#endif
#endif


}

u32 get_next_adc_ch(void)
{
    return ad_table[next_channel];
}

/*----------------------------------------------------------------------------*/
/**@brief   获取ad按键值
   @param   void
   @param   void
   @return  key_number
   @note    tu8 get_adkey_value(void)
*/
/*----------------------------------------------------------------------------*/
tu8 get_adkey_value(void)
{
#if KEY_AD_EN
    tu8 key_number;
 	u32 value;
	u32 LDO_ref;
    u32 key_value;

#if 1
	key_value = adc_value[AD_CH_KEY];
#else
    value = adc_value[AD_CH_KEY];
	LDO_ref  = adc_value[AD_CH_LDOREF];

	key_value = 124*value/LDO_ref;
#endif
    //   // printf("key_2:0x%x\n",key_value);

//	// printf("value:%d   key:%d\n",key_number,dac_var.cur_sys_vol_l);

#ifdef  support_k68_1key_mode
    //if ((key_value < (0x3ffL*15 /33)) && ( power_delay<250 ))
    //   power_delay++;

    //if(power_delay>200)
    //	power_ok=1;

    // if(power_ok)
    {
        if (key_value < (0x3ffL*15 /33))
            return NO_KEY;
        else
            return 9;
    }

#else

	 #ifdef support_line_chack_user_ad
	 	if (key_value > VOL_AD_NOKEY)
	 		{
	 			return NO_KEY;
	 		}
	 	else if (key_value > VOL_AD_AUX_IN)
			{
	 			return NO_KEY;
	 		}
	 #else
	    if (key_value > AD_NOKEY)
		{
			 #ifdef SUPPORT_PANEL_KEY_USE_TWO_AD_IO
			 	key_value=adc_value[AD_CH_KEY1];
			 	if(key_value>AD_NOKEY)
			 #endif
			return NO_KEY;
		}
	 #endif

    for (key_number = 0; key_number < sizeof (ad_key_table) / sizeof (ad_key_table[0]); key_number++)
    {
        if (key_value > ad_key_table[key_number])
            break;
    }

	    #ifdef SUPPORT_PANEL_KEY_USE_TWO_AD_IO
			if(adc_value[AD_CH_KEY]>AD_NOKEY)
	 	    #ifdef ADK_USE_11KEY_MODE
	 			key_number+=11;
	 	    #elif defined(ADK_USE_12KEY_MODE)
	 			key_number+=12;
	 	    #elif defined(ADK_USE_13KEY_MODE)
	 			key_number+=13;
	 	    #else
	 			key_number+=10;
	 	    #endif
	    #endif
//		 // printf("adkey_value:%d   key_num:0x%x\n",key_value*33/0x3ff,key_number);

    return key_number;
#endif
#else
    return 0xff;
#endif
}
/*----------------------------------------------------------------------------*/
/**@brief   获取电池电量
   @param   void
   @param   void
   @return  电池电量值
   @note    tu8 get_battery_level(void)
*/
/*----------------------------------------------------------------------------*/
u16 get_battery_level(void)
{
   #ifdef SUPPORT_BAT_DETECT_USE_IO

   	 u16 battery_value,LDOIN_12;
   	 LDOIN_12 = adc_value[AD_CH_BAT];

   	 #if LOW_POER_VOLTOGE_VAL>100
   		 battery_value= LDOIN_12*33/0x3ff*10;
   	 #else
   		 battery_value= LDOIN_12*33/0x3ff;
   	 #endif

   	 return battery_value;
   #else

       u16 battery_value,LDOIN_12,LDO_ref;
       LDOIN_12 = adc_value[AD_CH_LDOIN];
       LDO_ref  = adc_value[AD_CH_LDOREF];//0x181,1.2v

	battery_value = (((u16)LDOIN_12*372)/10)/((u16)LDO_ref); //针对AC69
       /* battery_value = (((u16)LDOIN_12*368)/10)/((u16)LDO_ref); */
       /* // printf("battery_value:0x%x    0x%x   %d\n",LDOIN_12,LDO_ref,battery_value); */
       return battery_value;

   #endif
}
