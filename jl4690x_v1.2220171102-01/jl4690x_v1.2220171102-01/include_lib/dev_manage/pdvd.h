
/*pdvd  header file */
#include "sdk_cfg.h"

  
#if defined(PDVD_3LINE_DATA_CLK_STB_PB10PB11PB12)  

#define PDVD_INIT()  {JL_PORTB->DIE |= (BIT(10)|BIT(11)|BIT(12)); JL_PORTB->DIR &= ~(BIT(10)|BIT(11)|BIT(12)); \
					JL_PORTB->PU |= (BIT(10)|BIT(11)|BIT(12)); JL_PORTB->PD &= ~(BIT(10)|BIT(11)|BIT(12)) ;}

#define PDVD_DATA_IN()   	{JL_PORTB->DIE |= (BIT(10)); JL_PORTB->DIR |=~(BIT(10));}
#define PDVD_DATA_READ() 	(JL_PORTB->IN&BIT(10))


#define PDVD_DAT_BIT	10
#define PDVD_CLK_BIT	11
#define PDVD_STB_BIT	12

#define PDVD_DAT_SET(x)		if(x){JL_PORTB->OUT|= BIT(PDVD_DAT_BIT);}else{JL_PORTB->OUT &= ~BIT(PDVD_DAT_BIT);}
#define PDVD_CLK_SET(x)		if(x){JL_PORTB->OUT|= BIT(PDVD_CLK_BIT);}else{JL_PORTB->OUT &= ~BIT(PDVD_CLK_BIT);}
#define PDVD_STB_SET(x)		if(x){JL_PORTB->OUT|= BIT(PDVD_STB_BIT);}else{JL_PORTB->OUT &= ~BIT(PDVD_STB_BIT);}

#endif


#define OKVOLMAX	30
#define ECHOMAX		18

#define OKVOL_NOMAL		0
#define OKVOL_DN		1
#define OKVOL_UP		2

#define ECHO_NOMAL		3
#define ECHO_DN			4
#define ECHO_UP			5

#define OKVOL_DEFAULT	15

#define ECHO_DEFAULT	10


//u16 okvolbak;
#ifdef MIC_LED_SHOW_MAX
extern u8 mic_temp_vol;
#endif
#ifdef MIC_ECHO_LED_SHOW_MAX
extern u8 mic_echo_temp_vol;
#endif

extern  u8 M62429Data[2];
 void M62429MenuPro(u8 dir);
 void M62429Init(void);
 void SetM62429Data(u8 dir);

