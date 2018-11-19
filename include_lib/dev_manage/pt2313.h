
/***********************************************************************************************
 *	Processer :
 *	Compiler :
 *	File:
 *	Description:
 *	Date: 2007.04.26
 *	Last update time:
 *	Writer :	SQG
 *	revision:1.00

***********************************************************************************************/


#ifndef _AUDIO_2313_H_
#define _AUDIO_2313_H_

#ifdef _AUDIO_2313_C_
#define _AUDIO_2313_
#else
#define _AUDIO_2313_	extern
#endif

#include "sdk_cfg.h"





#define Aud_PT2313Adr			0x88

#define Aud_FLMuteVal			0x9F
#define Aud_FRMuteVal			0xBF
#define Aud_RLMuteVal			0xDF
#define Aud_RRMuteVal			0xFF


//pt2313 地址
#define AudAdd_VOL			0x00
#define AudAdd_RL			0xC0
#define AudAdd_RR			0xE0
#define AudAdd_FL			0x80
#define AudAdd_FR			0xA0
#define AudAdd_SWITCH		0x40
#define AudAdd_BASS			0x60
#define AudAdd_TREB			0x70


/* pt2313data[8]  划分*/
#define PT_VOLUME			0
#define PT_RL				1
#define PT_RR				2
#define PT_FL				3
#define PT_FR				4
#define PT_BASS				5
#define PT_TREB				6
#define PT_SWITCH			7



/*vol plus or minus*/
#define PT2313_VOL_PLUS 0
#define PT2313_VOL_MINUS 1

//void PT2313SetData(unsigned char dir,unsigned char snum)
//dir  对应的功能

#define PT_VOL_NOMAL	0x00
#define PT_VOL_UP		0x01
#define PT_VOL_DN		0x02

#define PT_RL_NOMAL		0x03
#define PT_RL_UP		0x04
#define PT_RL_DN		0x05

#define PT_RR_NOMAL	0x06
#define PT_RR_UP		0x07
#define PT_RR_DN		0x08

#define PT_FL_NOMAL		0x09
#define PT_FL_UP		0x0A
#define PT_FL_DN		0x0B

#define PT_FR_NOMAL	0x0C
#define PT_FR_UP		0x0D
#define PT_FR_DN		0x0E

#define PT_BASS_NOMAL	0x0F
#define PT_BASS_UP		0x10
#define PT_BASS_DN		0x11

#define PT_TREB_NOMAL	0x12
#define PT_TREB_UP		0x13
#define PT_TREB_DN		0x14

//  最大 VOL  设置
#ifdef MAIN_VOL_MAX
#define AudVOLMAX			MAIN_VOL_MAX
#else
#define AudVOLMAX			0x3F
#endif
#define AudBALMAX		       0x1f //重低音
//#define AudswLMAX			0x1f //环绕 
#ifdef support_main_vol_max_show_99
#define AudswLMAX			99 //环绕 
#elif defined(support_sw_vol_max_show_30)
#define AudswLMAX			30 //环绕 
#else
#define AudswLMAX			62 //环绕 
#endif

#define MAX_TONE		    	14

//----------Aud Switch--------
//***bit 8,7,6 must be 010
//---------------------------------
//bit 0 and bit 1
//bit 2
#define Aud_SwLoud				0x04
//bit 3 and bit 4
//#define Aud_Sw11_25dB			0x00
//#define Aud_Sw7_5dB				0x08
//#define Aud_Sw3_75dB			0x10
//#define Aud_Sw0dB				0x18



#if defined(PT2313_CLK_DATA_USE_PB9PB10)
#define PT2313_DATA_BIT	10
#define PT2313_CLK_BIT 	9

   #define PT2313_data_out()   JL_PORTB->DIR &= ~(BIT(PT2313_DATA_BIT)); JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_h()     JL_PORTB->OUT  |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_l()     JL_PORTB->OUT  &=~ (BIT(PT2313_DATA_BIT))
   
   #define PT2313_data_in()     JL_PORTB->DIR |= (BIT(PT2313_DATA_BIT));JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data()     ((JL_PORTB->IN>>PT2313_DATA_BIT)&(BIT(0)))
   
   #define PT2313_clk_out()    JL_PORTB->DIR &= ~(BIT(PT2313_CLK_BIT));JL_PORTB->PU |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_h()      JL_PORTB->OUT  |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_l()      JL_PORTB->OUT  &=~ (BIT(PT2313_CLK_BIT))
   
#elif defined PT2313_CLK_DATA_USE_PB10PB9

#define PT2313_DATA_BIT	9
#define PT2313_CLK_BIT 		10

   #define PT2313_data_out()   JL_PORTB->DIR &= ~(BIT(PT2313_DATA_BIT)); JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_h()     JL_PORTB->OUT  |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_l()     JL_PORTB->OUT  &=~ (BIT(PT2313_DATA_BIT))
   
   #define PT2313_data_in()     JL_PORTB->DIR |= (BIT(PT2313_DATA_BIT));JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data()     ((JL_PORTB->IN>>PT2313_DATA_BIT)&(BIT(0)))
   
   #define PT2313_clk_out()    JL_PORTB->DIR &= ~(BIT(PT2313_CLK_BIT));JL_PORTB->PU |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_h()      JL_PORTB->OUT  |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_l()      JL_PORTB->OUT  &=~ (BIT(PT2313_CLK_BIT))
#elif defined PT2313_CLK_DATA_USE_PB12PB10

#define PT2313_DATA_BIT	12
#define PT2313_CLK_BIT 		10

   #define PT2313_data_out()   JL_PORTB->DIR &= ~(BIT(PT2313_DATA_BIT)); JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_h()     JL_PORTB->OUT  |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_l()     JL_PORTB->OUT  &=~ (BIT(PT2313_DATA_BIT))
   
   #define PT2313_data_in()     JL_PORTB->DIR |= (BIT(PT2313_DATA_BIT));JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data()     ((JL_PORTB->IN>>PT2313_DATA_BIT)&(BIT(0)))
   
   #define PT2313_clk_out()    JL_PORTB->DIR &= ~(BIT(PT2313_CLK_BIT));JL_PORTB->PU |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_h()      JL_PORTB->OUT  |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_l()      JL_PORTB->OUT  &=~ (BIT(PT2313_CLK_BIT))
#elif defined PT2313_CLK_DATA_USE_PC5PA4

#define PT2313_DATA_BIT	4
#define PT2313_CLK_BIT 		5

   #define PT2313_data_out()   JL_PORTA->DIR &= ~(BIT(PT2313_DATA_BIT)); JL_PORTA->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_h()     JL_PORTA->OUT  |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_l()     JL_PORTA->OUT  &=~ (BIT(PT2313_DATA_BIT))
   
   #define PT2313_data_in()     JL_PORTA->DIR |= (BIT(PT2313_DATA_BIT));JL_PORTA->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data()     ((JL_PORTA->IN>>PT2313_DATA_BIT)&(BIT(0)))
   
   #define PT2313_clk_out()    JL_PORTC->DIR &= ~(BIT(PT2313_CLK_BIT));JL_PORTC->PU |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_h()      JL_PORTC->OUT  |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_l()      JL_PORTC->OUT  &=~ (BIT(PT2313_CLK_BIT))
   

#elif defined PT2313_CLK_DATA_USE_PC0PB10

#define PT2313_DATA_BIT	10
#define PT2313_CLK_BIT 	0

   #define PT2313_data_out()   JL_PORTB->DIR &= ~(BIT(PT2313_DATA_BIT)); JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_h()     JL_PORTB->OUT  |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data_l()     JL_PORTB->OUT  &=~ (BIT(PT2313_DATA_BIT))
   
   #define PT2313_data_in()     JL_PORTB->DIR |= (BIT(PT2313_DATA_BIT));JL_PORTB->PU |= (BIT(PT2313_DATA_BIT))
   #define PT2313_data()     ((JL_PORTB->IN>>PT2313_DATA_BIT)&(BIT(0)))
   
   #define PT2313_clk_out()    JL_PORTC->DIR &= ~(BIT(PT2313_CLK_BIT));JL_PORTC->PU |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_h()      JL_PORTC->OUT  |= (BIT(PT2313_CLK_BIT))
   #define PT2313_clk_l()      JL_PORTC->OUT  &=~ (BIT(PT2313_CLK_BIT))

#endif


//-------------Aud Item-----------

_AUDIO_2313_ u8  pt2313data[8];
_AUDIO_2313_ void Pt2313_ChangSource(u8 curmode);
_AUDIO_2313_ void PT2313_Init(void);
_AUDIO_2313_ void PT2313SetEQ(u8 dir);
_AUDIO_2313_ void PT2313_SetVol(u8  AUD_VolVal);
_AUDIO_2313_ void PT2313Mute(u8 OnOff);
_AUDIO_2313_ void PT2313SetData(u8 dir,u8 snum);
_AUDIO_2313_ void PT2313MenuPro(u8  dir);

_AUDIO_2313_  void AUD_SetLoud(bool OnOff);
_AUDIO_2313_ void  PT2313_reset(void);

#ifdef SUPPORT_PT2314
extern  u8 pt2314data[8];
_AUDIO_2313_ void PT2314SetData(u8 dir,u8 snum);
#endif
void PT2313_KEY_PROCESS(u8 menuMode,bool volPlusMinus);










#endif

