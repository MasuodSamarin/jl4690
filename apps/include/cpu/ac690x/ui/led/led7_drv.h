#ifndef	_LED7_DRV_H_
#define _LED7_DRV_H_

#include "includes.h"


 #if defined(SUPPORT_TM1628_MODE)
 #ifdef LED_ID_6030_C_VFD_1
   #define HT1628_CMD_MODE  0x00 //6grid-11seg
 #else
   #define HT1628_CMD_MODE  0x03 //6grid-11seg
 #endif
   #define HT1628_CMD_WRITE 0x40  //cmd write data to ht1628
   #define HT1628_CMD_SPEC_ADDR 0x44 //identify address cmd
   #define HT1628_CMD_NORMAL_MODE 0x40 //normal mode cmd
   #define HT1628_CMD_ADDR_SET  0xc0   //address set

	 #ifdef TM1628_DATA_CLK_STB_USE_PA15PA14PC0

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(0));JL_PORTA->DIR &= ~(BIT(15)|BIT(14));\
							   JL_PORTC->PU &= ~(BIT(0));JL_PORTA->PU &= ~(BIT(15)|BIT(14));\
				                         JL_PORTC->PD &= ~(BIT(0));JL_PORTA->PD &= ~(BIT(15)|BIT(14))

	   #define HT1628_DATA(x) if(x){JL_PORTA->OUT  |=(BIT(15));}else{JL_PORTA->OUT  &= ~(BIT(15));}
	   #define HT1628_CLK(x) if(x){JL_PORTA->OUT  |=(BIT(14));}	else{JL_PORTA->OUT  &= ~(BIT(14));}
	   #define HT1628_STB(x) if(x){JL_PORTC->OUT  |=(BIT(0));}	else{JL_PORTC->OUT  &= ~(BIT(0));}

	 #elif defined TM1628_DATA_CLK_STB_USE_PC4PC3PC2

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(2));JL_PORTC->DIR &= ~(BIT(3)|BIT(4));\
							   JL_PORTC->PU &= ~(BIT(2));JL_PORTC->PU &= ~(BIT(3)|BIT(4));\
				                         JL_PORTC->PD &= ~(BIT(2));JL_PORTC->PD &= ~(BIT(3)|BIT(4))

	   #define HT1628_DATA(x) if(x){JL_PORTC->OUT  |=(BIT(4));}else{JL_PORTC->OUT  &= ~(BIT(4));}
	   #define HT1628_CLK(x) if(x){JL_PORTC->OUT  |=(BIT(3));}	else{JL_PORTC->OUT  &= ~(BIT(3));}
	   #define HT1628_STB(x) if(x){JL_PORTC->OUT  |=(BIT(2));}	else{JL_PORTC->OUT  &= ~(BIT(2));}

	    #ifdef SUPPORT_TM1628_KEY_READ
	    #define HT1628_DATA_IN()   JL_PORTC->DIR|=BIT(4);JL_PORTC->PU|=BIT(4)
	    #define HT1628_DATA_OUT()	JL_PORTC->DIR&=~BIT(4)
	    #define HT1628_DATA_READ() 	JL_PORTC->IN&BIT(4)
	    #endif

	 #elif defined TM1628_DATA_CLK_STB_USE_PC5PC4PC3

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(5));JL_PORTC->DIR &= ~(BIT(3)|BIT(4));\
							   JL_PORTC->PU &= ~(BIT(5));JL_PORTC->PU &= ~(BIT(3)|BIT(4));\
				                         JL_PORTC->PD &= ~(BIT(5));JL_PORTC->PD &= ~(BIT(3)|BIT(4))

	   #define HT1628_DATA(x) if(x){JL_PORTC->OUT  |=(BIT(5));}else{JL_PORTC->OUT  &= ~(BIT(5));}
	   #define HT1628_CLK(x) if(x){JL_PORTC->OUT  |=(BIT(4));}	else{JL_PORTC->OUT  &= ~(BIT(4));}
	   #define HT1628_STB(x) if(x){JL_PORTC->OUT  |=(BIT(3));}	else{JL_PORTC->OUT  &= ~(BIT(3));}

	    #ifdef SUPPORT_TM1628_KEY_READ
	    #define HT1628_DATA_IN()   JL_PORTC->DIR|=BIT(5);JL_PORTC->PU|=BIT(5)
	    #define HT1628_DATA_OUT()	JL_PORTC->DIR&=~BIT(5)
	    #define HT1628_DATA_READ() 	JL_PORTC->IN&BIT(5)
	    #endif

	 #elif defined TM1628_DATA_CLK_STB_USE_PC2PC3PC4

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(2));JL_PORTC->DIR &= ~(BIT(3)|BIT(4));\
							   JL_PORTC->PU &= ~(BIT(2));JL_PORTC->PU &= ~(BIT(3)|BIT(4));\
				                         JL_PORTC->PD &= ~(BIT(2));JL_PORTC->PD &= ~(BIT(3)|BIT(4))

	   #define HT1628_DATA(x) if(x){JL_PORTC->OUT  |=(BIT(2));}else{JL_PORTC->OUT  &= ~(BIT(2));}
	   #define HT1628_CLK(x) if(x){JL_PORTC->OUT  |=(BIT(3));}	else{JL_PORTC->OUT  &= ~(BIT(3));}
	   #define HT1628_STB(x) if(x){JL_PORTC->OUT  |=(BIT(4));}	else{JL_PORTC->OUT  &= ~(BIT(4));}

	 #elif defined TM1628_DATA_CLK_STB_USE_PC0PA14PA15

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(0));JL_PORTA->DIR &= ~(BIT(15)|BIT(14));\
							   JL_PORTC->PU &= ~(BIT(0));JL_PORTA->PU &= ~(BIT(15)|BIT(14));\
				                         JL_PORTC->PD &= ~(BIT(0));JL_PORTA->PD &= ~(BIT(15)|BIT(14))

	   #define HT1628_DATA(x) if(x){JL_PORTC->OUT  |=(BIT(0));}	else{JL_PORTC->OUT  &= ~(BIT(0));}
	   #define HT1628_CLK(x) if(x){JL_PORTA->OUT  |=(BIT(14));}	else{JL_PORTA->OUT  &= ~(BIT(14));}
	   #define HT1628_STB(x) if(x){JL_PORTA->OUT  |=(BIT(15));}else{JL_PORTA->OUT  &= ~(BIT(15));}
	 #elif defined TM1628_DATA_CLK_STB_USE_PA15PC1PA14

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(1));JL_PORTA->DIR &= ~(BIT(15)|BIT(14));\
							   JL_PORTC->PU &= ~(BIT(1));JL_PORTA->PU &= ~(BIT(15)|BIT(14));\
				                         JL_PORTC->PD &= ~(BIT(1));JL_PORTA->PD &= ~(BIT(15)|BIT(14))

	   #define HT1628_DATA(x) if(x){JL_PORTA->OUT  |=(BIT(15));}	else{JL_PORTA->OUT  &= ~(BIT(15));}
	   #define HT1628_CLK(x) if(x){JL_PORTC->OUT  |=(BIT(1));}	else{JL_PORTC->OUT  &= ~(BIT(1));}
	   #define HT1628_STB(x) if(x){JL_PORTA->OUT  |=(BIT(14));}else{JL_PORTA->OUT  &= ~(BIT(14));}

	 #elif defined TM1628_DATA_CLK_STB_USE_PC0PA15PA14

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(0));JL_PORTA->DIR &= ~(BIT(15)|BIT(14));\
							   JL_PORTC->PU &= ~(BIT(0));JL_PORTA->PU &= ~(BIT(15)|BIT(14));\
				                         JL_PORTC->PD &= ~(BIT(0));JL_PORTA->PD &= ~(BIT(15)|BIT(14))

	   #define HT1628_DATA(x) if(x){JL_PORTC->OUT  |=(BIT(0));}	else{JL_PORTC->OUT  &= ~(BIT(0));}
	   #define HT1628_CLK(x) if(x){JL_PORTA->OUT  |=(BIT(15));}	else{JL_PORTA->OUT  &= ~(BIT(15));}
	   #define HT1628_STB(x) if(x){JL_PORTA->OUT  |=(BIT(14));}else{JL_PORTA->OUT  &= ~(BIT(14));}

	    #ifdef SUPPORT_TM1628_KEY_READ
	    #define HT1628_DATA_IN()   JL_PORTC->DIR|=BIT(0);JL_PORTC->PU|=BIT(0)
	    #define HT1628_DATA_OUT()	JL_PORTC->DIR&=~BIT(0)
	    #define HT1628_DATA_READ() 	JL_PORTC->IN&BIT(0)
	    #endif


	 #elif defined TM1628_DATA_CLK_STB_USE_PB9PB10PB11

	   #define HT1628_IO_INIT() JL_PORTB->DIR  &= ~(BIT(9));JL_PORTB->DIR &= ~(BIT(10)|BIT(11));\
							   JL_PORTB->PU &= ~(BIT(9));JL_PORTB->PU &= ~(BIT(10)|BIT(11));\
				                         JL_PORTB->PD &= ~(BIT(9));JL_PORTB->PD &= ~(BIT(10)|BIT(11))

	   #define HT1628_DATA(x) if(x){JL_PORTB->OUT  |=(BIT(9));}else{JL_PORTB->OUT  &= ~(BIT(9));}
	   #define HT1628_CLK(x) if(x){JL_PORTB->OUT  |=(BIT(10));}	else{JL_PORTB->OUT  &= ~(BIT(10));}
	   #define HT1628_STB(x) if(x){JL_PORTB->OUT  |=(BIT(11));}	else{JL_PORTB->OUT  &= ~(BIT(11));}

	 #endif

#elif defined(SUPPORT_TM1618_MODE)
  #define HT1618_CMD_MODE  0x00 //6grid-11seg
  #define HT1618_CMD_WRITE 0x40  //cmd write data to ht1628
  #define HT1618_CMD_SPEC_ADDR 0x44 //identify address cmd
  #define HT1618_CMD_NORMAL_MODE 0x40 //normal mode cmd
  #define HT1618_CMD_ADDR_SET  0xc0   //address set
#ifdef TM1618_DATA_CLK_STB_USE_PA15PC1PA14
  #define HT1618_IO_INIT() 	JL_PORTC->DIR &=~(BIT(1));JL_PORTC->PU&=~(BIT(1));\
                           			JL_PORTC->PD&=~(BIT(1));\
						JL_PORTA->DIR &=~(BIT(15)|BIT(14));JL_PORTA->PU&=~(BIT(14)|BIT(15));\
						JL_PORTA->PD&=~(BIT(15)|BIT(14))


  #define HT1618_CLK(x) if(x){JL_PORTC->OUT|=BIT(1);}else{JL_PORTC->OUT&=~BIT(1);}
  #define HT1618_DATA(x) if(x){JL_PORTA->OUT|=BIT(15);}else{JL_PORTA->OUT&=~BIT(15);}
  #define HT1618_STB(x) if(x){JL_PORTA->OUT|=BIT(14);}else{JL_PORTA->OUT&=~BIT(14);}
#endif



#elif defined(SUPPORT_PT6312_MODE)

  #define HT1628_CMD_MODE  0x03 //6grid-11seg
  #define HT1628_CMD_WRITE 0x40  //cmd write data to ht1628
  #define HT1628_CMD_SPEC_ADDR 0x44 //identify address cmd
  #define HT1628_CMD_NORMAL_MODE 0x40 //normal mode cmd
  #define HT1628_CMD_ADDR_SET  0xc0   //address set
#ifdef PT6312_DATA_CLK_STB_USE_PA6PA4PA0
  #define HT1628_IO_INIT() PORTA_DIR &=~(BIT(6)|BIT(4)|BIT(0));PORTA_PU&=~(BIT(6)|BIT(4)|BIT(0));\
                           PORTA_PD&=~(BIT(6)|BIT(4)|BIT(0))
  #define HT1628_CLK(x) if(x){PORTA_OUT|=BIT(4);}else{PORTA_OUT&=~BIT(4);}
  #define HT1628_DATA(x) if(x){PORTA_OUT|=BIT(0);}else{PORTA_OUT&=~BIT(0);}
  #define HT1628_STB(x) if(x){PORTA_OUT|=BIT(6);}else{PORTA_OUT&=~BIT(6);}
#elif defined (PT6312_DATA_CLK_STB_USE_PA6PA7PA8)
  #define HT1628_IO_INIT() JL_PORTA->DIR &=~(BIT(6)|BIT(7)|BIT(8));JL_PORTA->PU&=~(BIT(6)|BIT(7)|BIT(8));\
							 JL_PORTA->PD&=~(BIT(6)|BIT(7)|BIT(8))
  #define HT1628_CLK(x) if(x){JL_PORTA->OUT|=BIT(7);}else{JL_PORTA->OUT&=~BIT(7);}
  #define HT1628_DATA(x) if(x){JL_PORTA->OUT|=BIT(6);}else{JL_PORTA->OUT&=~BIT(6);}
  #define HT1628_STB(x) if(x){JL_PORTA->OUT|=BIT(8);}else{JL_PORTA->OUT&=~BIT(8);}

#elif defined TM1628_DATA_CLK_STB_USE_PC4PC3PC2

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(2));JL_PORTC->DIR &= ~(BIT(3)|BIT(4));\
							   JL_PORTC->PU &= ~(BIT(2));JL_PORTC->PU &= ~(BIT(3)|BIT(4));\
				                         JL_PORTC->PD &= ~(BIT(2));JL_PORTC->PD &= ~(BIT(3)|BIT(4))

	   #define HT1628_DATA(x) if(x){JL_PORTC->OUT  |=(BIT(4));}else{JL_PORTC->OUT  &= ~(BIT(4));}
	   #define HT1628_CLK(x) if(x){JL_PORTC->OUT  |=(BIT(3));}	else{JL_PORTC->OUT  &= ~(BIT(3));}
	   #define HT1628_STB(x) if(x){JL_PORTC->OUT  |=(BIT(2));}	else{JL_PORTC->OUT  &= ~(BIT(2));}

#elif defined TM1628_DATA_CLK_STB_USE_PC2PC3PC4

	   #define HT1628_IO_INIT() JL_PORTC->DIR  &= ~(BIT(2));JL_PORTC->DIR &= ~(BIT(3)|BIT(4));\
							   JL_PORTC->PU &= ~(BIT(2));JL_PORTC->PU &= ~(BIT(3)|BIT(4));\
				                         JL_PORTC->PD &= ~(BIT(2));JL_PORTC->PD &= ~(BIT(3)|BIT(4))

	   #define HT1628_DATA(x) if(x){JL_PORTC->OUT  |=(BIT(2));}else{JL_PORTC->OUT  &= ~(BIT(2));}
	   #define HT1628_CLK(x) if(x){JL_PORTC->OUT  |=(BIT(3));}	else{JL_PORTC->OUT  &= ~(BIT(3));}
	   #define HT1628_STB(x) if(x){JL_PORTC->OUT  |=(BIT(4));}	else{JL_PORTC->OUT  &= ~(BIT(4));}


#elif defined (TM1628_DATA_CLK_STB_USE_PR1PA9PA10)
  #define HT1628_IO_INIT() 	PORTR_DIR(PORTR1,0);PORTR_PU(PORTR1,0);PORTR_PD(PORTR1,0);\
							JL_PORTA->DIR &=~(BIT(10)|BIT(9));JL_PORTA->PU&=~(BIT(10)|BIT(9));\
							 JL_PORTA->PD&=~(BIT(10)|BIT(9))




#define HT1628_CLK(x)	 if(x){JL_PORTA->OUT|=BIT(9);} else{JL_PORTA->OUT&=~BIT(9);}
#define HT1628_DATA(x) 	 if(x){PORTR_OUT(PORTR1,1);}     else{PORTR_OUT(PORTR1,0);}
#define HT1628_STB(x) if(x){JL_PORTA->OUT|=BIT(10);}else{JL_PORTA->OUT&=~BIT(10);}


#endif





#elif defined(LCD_4x9_MODE)

#ifdef support_lcd_4x9_use_pc5432_pa1514111094321
#define BK_LIGHT(x)   //if(x){JL_PORTC->OUT|=BIT(1);JL_PORTC->DIR&=~BIT(1);JL_PORTC->PU|=BIT(1);JL_PORTC->PD&=~BIT(1);}else{JL_PORTC->OUT&=~BIT(1);JL_PORTC->DIR&=~BIT(1);JL_PORTC->PU&=~BIT(1);JL_PORTC->PD|=BIT(1);}

#define LCD_INIT()/*[5:4]:OSC*/ JL_CLOCK->CLK_CON1 &= ~(BIT(5)|BIT(4));\
     /*[6:4]:VLCDS 3.0V*/     JL_LCDC->CON0= 0x0007<<4;\
     /*//[7]:32KHZ/64*/        JL_LCDC->CON0 |= BIT(7);\
     /*//[13:12]:CHGMOD */ JL_LCDC->CON0 |= 0x0001<<12;\
     /*[3:2]:0x01:1/2 Bias 0x02:1/3 0x03:1/4*/   JL_LCDC->CON0 |= 0x0002<<2;\
     /*//[15:14] 01 com0-com3*/  JL_LCDC->CON0 &= ~(BIT(15)|BIT(14));JL_LCDC->CON0 |= BIT(14);\
     /*//[0] LCDCEN */             JL_LCDC->CON0 |= 0x01;\
     /*PA15-PA0*/                  JL_LCDC->SEG_IOEN0 = 0xCE1E;\
     /*background light on*/                      BK_LIGHT(1)

#define LCD_SEG_CLOSE()  BK_LIGHT(0);\
                       JL_LCDC->CON0=0;\
                       JL_LCDC->SEG_IOEN0=0

#define COM3_SEG(x)	{JL_PORTA->DIE &= ~0xCE1E;  JL_PORTA->DIE  |=(x&0xCE1E);}
#define COM2_SEG(x)	{JL_PORTA->HD &= ~0xCE1E;  JL_PORTA->HD |=(x&0xCE1E);}
#define COM1_SEG(x)	{JL_PORTA->PD &= ~0xCE1E;  JL_PORTA->PD |=(x&0xCE1E);}
#define COM0_SEG(x)	{JL_PORTA->PU &= ~0xCE1E;  JL_PORTA->PU |=(x&0xCE1E);}
#define LCD_SEG_CLEAR() {COM0_SEG(0x0000);COM1_SEG(0x0000);COM2_SEG(0x0000);COM3_SEG(0x0000);}
#endif

#elif defined(LED_7PIN_MODE)


	 #ifdef support_led7_user_pc0pa14pa15pc1pc2pc3pc4

	 #define   LED7_IO_INIT()         JL_PORTC->OUT  &= ~(BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->DIR  |=    (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->PU    &= ~(BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->PD    &= ~(BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->HD   &= ~(BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	 											JL_PORTA->OUT  &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->DIR  |=    (BIT(14)|BIT(15));\
	 											JL_PORTA->PU    &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->PD    &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->HD   &= ~(BIT(14)|BIT(15));\


	 #ifdef LED_7PIN_REVERSE

	 #ifdef LED_7PIN_HALF_LIGHT
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(0);    JL_PORTC->PU |= BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_set_com5()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->PU  |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com4()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->PU  |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->PU  |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com2()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->PU  |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com1()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->PU  |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->PU  |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #else
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(0);    JL_PORTC->HD |= BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_set_com5()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->HD |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com4()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->HD |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->HD |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com2()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->HD |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com1()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->HD |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #endif

	 #define   led_7_clr_seg6()       JL_PORTC->OUT &= ~BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_clr_seg5()       JL_PORTA->OUT &= ~BIT(14);   JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_clr_seg4()       JL_PORTA->OUT &= ~BIT(15);   JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_clr_seg3()       JL_PORTC->OUT &= ~BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_clr_seg2()       JL_PORTC->OUT &= ~BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_clr_seg1()       JL_PORTC->OUT &= ~BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_clr_seg0()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #else
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(0);    JL_PORTC->HD |= BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_set_com1()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->HD |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com2()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->HD |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->HD |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com4()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->HD |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com5()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->HD |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)



	 #define   led_7_clr_seg0()       JL_PORTC->OUT &= ~BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_clr_seg1()       JL_PORTA->OUT &= ~BIT(14);   JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_clr_seg2()       JL_PORTA->OUT &= ~BIT(15);   JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_clr_seg3()       JL_PORTC->OUT &= ~BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_clr_seg4()       JL_PORTC->OUT &= ~BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_clr_seg5()       JL_PORTC->OUT &= ~BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_clr_seg6()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #endif




	 #elif defined support_led7_user_pc0pa14pa15pc1pc2pc3pc4_low
	 #define   LED7_IO_INIT()         JL_PORTC->OUT  &= ~(BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->DIR  |=    (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->PU    &= ~(BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->PD    |= (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->HD   &=~ (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	 											JL_PORTA->OUT  &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->DIR  |=    (BIT(14)|BIT(15));\
	 											JL_PORTA->PU    &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->PD    |= (BIT(14)|BIT(15));\
	 											JL_PORTA->HD   &= ~(BIT(14)|BIT(15));\


	 #ifdef LED_7PIN_REVERSE

	 #ifdef LED_7PIN_HALF_LIGHT
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(0);    JL_PORTC->PU |= BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_set_com5()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->PU  |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com4()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->PU  |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->PU  |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com2()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->PU  |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com1()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->PU  |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->PU  |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #else
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(0);    JL_PORTC->HD |= BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_set_com5()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->HD |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com4()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->HD |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->HD |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com2()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->HD |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com1()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->HD |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #endif

	 #define   led_7_clr_seg6()       JL_PORTC->OUT &= ~BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_clr_seg5()       JL_PORTA->OUT &= ~BIT(14);   JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_clr_seg4()       JL_PORTA->OUT &= ~BIT(15);   JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_clr_seg3()       JL_PORTC->OUT &= ~BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_clr_seg2()       JL_PORTC->OUT &= ~BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_clr_seg1()       JL_PORTC->OUT &= ~BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_clr_seg0()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #else
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(0);    JL_PORTC->HD |= BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_set_com1()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->HD |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com2()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->HD |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->HD |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com4()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->HD |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com5()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->HD |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)



	 #define   led_7_clr_seg0()       JL_PORTC->OUT &= ~BIT(0);     JL_PORTC->DIR &= ~BIT(0)
	 #define   led_7_clr_seg1()       JL_PORTA->OUT &= ~BIT(14);   JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_clr_seg2()       JL_PORTA->OUT &= ~BIT(15);   JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_clr_seg3()       JL_PORTC->OUT &= ~BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_clr_seg4()       JL_PORTC->OUT &= ~BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_clr_seg5()       JL_PORTC->OUT &= ~BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_clr_seg6()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #endif






	 #elif defined support_led7_user_pa14pa15pc1pc2pc3pc4pc5
	 #define   LED7_IO_INIT()         JL_PORTC->OUT  &= ~(BIT(5)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->DIR  |=    (BIT(5)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->PU    &= ~(BIT(5)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->PD    &= ~(BIT(5)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	                                                                              JL_PORTC->HD   &= ~(BIT(5)|BIT(1)|BIT(2)|BIT(3)|BIT(4));\
	 											JL_PORTA->OUT  &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->DIR  |=    (BIT(14)|BIT(15));\
	 											JL_PORTA->PU    &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->PD    &= ~(BIT(14)|BIT(15));\
	 											JL_PORTA->HD   &= ~(BIT(14)|BIT(15));\


	 #ifdef LED_7PIN_REVERSE



	 #define   led_7_set_com6()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->HD |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com5()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->HD |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com4()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->HD |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->HD |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com2()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->HD |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com1()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(5);    JL_PORTC->HD |= BIT(5);     JL_PORTC->DIR &= ~BIT(5)


	 #define   led_7_clr_seg6()       JL_PORTA->OUT &= ~BIT(14);   JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_clr_seg5()       JL_PORTA->OUT &= ~BIT(15);   JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_clr_seg4()       JL_PORTC->OUT &= ~BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_clr_seg3()       JL_PORTC->OUT &= ~BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_clr_seg2()       JL_PORTC->OUT &= ~BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_clr_seg1()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_clr_seg0()       JL_PORTC->OUT &= ~BIT(5);     JL_PORTC->DIR &= ~BIT(5)

	 #else
	 #define   led_7_set_com0()        JL_PORTA->OUT|= BIT(14);  JL_PORTA->HD |= BIT(14);    JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_set_com1()        JL_PORTA->OUT|= BIT(15);  JL_PORTA->HD |= BIT(15);    JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_set_com2()        JL_PORTC->OUT|= BIT(1);    JL_PORTC->HD |= BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_set_com3()        JL_PORTC->OUT|= BIT(2);    JL_PORTC->HD |= BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_set_com4()        JL_PORTC->OUT|= BIT(3);    JL_PORTC->HD |= BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_set_com5()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(5);    JL_PORTC->HD |= BIT(5);     JL_PORTC->DIR &= ~BIT(5)



	 #define   led_7_clr_seg6()       JL_PORTA->OUT &= ~BIT(14);   JL_PORTA->DIR &= ~BIT(14)
	 #define   led_7_clr_seg5()       JL_PORTA->OUT &= ~BIT(15);   JL_PORTA->DIR &= ~BIT(15)
	 #define   led_7_clr_seg4()       JL_PORTC->OUT &= ~BIT(1);     JL_PORTC->DIR &= ~BIT(1)
	 #define   led_7_clr_seg3()       JL_PORTC->OUT &= ~BIT(2);     JL_PORTC->DIR &= ~BIT(2)
	 #define   led_7_clr_seg2()       JL_PORTC->OUT &= ~BIT(3);     JL_PORTC->DIR &= ~BIT(3)
	 #define   led_7_clr_seg1()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_clr_seg0()       JL_PORTC->OUT &= ~BIT(5);     JL_PORTC->DIR &= ~BIT(5)

	 #endif





	 #elif defined support_led7_user_pc5PC4PA7PA6PA5PA4PA3


	 #define   LED7_IO_INIT()         JL_PORTC->OUT  &= ~(BIT(5)|BIT(4));\
	                                                                              JL_PORTC->DIR  |=    (BIT(5)|BIT(4));\
	                                                                              JL_PORTC->PU    &= ~(BIT(5)|BIT(4));\
	                                                                              JL_PORTC->PD    &= ~(BIT(5)|BIT(4));\
	                                                                              JL_PORTC->HD   &= ~(BIT(5)|BIT(4));\
	 											JL_PORTA->DIE  &= ~(BIT(7)|BIT(6)|BIT(5)|BIT(4)|BIT(3));\
	 											JL_PORTA->OUT  &= ~(BIT(7)|BIT(6)|BIT(5)|BIT(4)|BIT(3));\
	 											JL_PORTA->DIR  |=    (BIT(7)|BIT(6)|BIT(5)|BIT(4)|BIT(3));\
	 											JL_PORTA->PU    &= ~(BIT(7)|BIT(6)|BIT(5)|BIT(4)|BIT(3));\
	 											JL_PORTA->PD    &= ~(BIT(7)|BIT(6)|BIT(5)|BIT(4)|BIT(3));\
	 											JL_PORTA->HD   &= ~(BIT(7)|BIT(6)|BIT(5)|BIT(4)|BIT(3));\


	 #ifdef LED_7PIN_REVERSE

	 #define   led_7_set_com6()        JL_PORTA->OUT|= BIT(3);    JL_PORTA->HD |= BIT(3);     JL_PORTA->DIR &= ~BIT(3)
	 #define   led_7_set_com5()        JL_PORTA->OUT|= BIT(4);  JL_PORTA->HD |= BIT(4);    JL_PORTA->DIR &= ~BIT(4)
	 #define   led_7_set_com4()        JL_PORTA->OUT|= BIT(5);  JL_PORTA->HD |= BIT(5);    JL_PORTA->DIR &= ~BIT(5)
	 #define   led_7_set_com3()        JL_PORTA->OUT|= BIT(6);    JL_PORTA->HD |= BIT(6);     JL_PORTA->DIR &= ~BIT(6)
	 #define   led_7_set_com2()        JL_PORTA->OUT|= BIT(7);    JL_PORTA->HD |= BIT(7);     JL_PORTA->DIR &= ~BIT(7)
	 #define   led_7_set_com1()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_set_com0()        JL_PORTC->OUT|= BIT(5);    JL_PORTC->HD |= BIT(5);     JL_PORTC->DIR &= ~BIT(5)


	 #define   led_7_clr_seg6()       JL_PORTA->OUT &= ~BIT(3);     JL_PORTA->DIR &= ~BIT(3)
	 #define   led_7_clr_seg5()       JL_PORTA->OUT &= ~BIT(4);   JL_PORTA->DIR &= ~BIT(4)
	 #define   led_7_clr_seg4()       JL_PORTA->OUT &= ~BIT(5);   JL_PORTA->DIR &= ~BIT(5)
	 #define   led_7_clr_seg3()       JL_PORTA->OUT &= ~BIT(6);     JL_PORTA->DIR &= ~BIT(6)
	 #define   led_7_clr_seg2()       JL_PORTA->OUT &= ~BIT(7);     JL_PORTA->DIR &= ~BIT(7)
	 #define   led_7_clr_seg1()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_clr_seg0()       JL_PORTC->OUT &= ~BIT(5);     JL_PORTC->DIR &= ~BIT(5)

	 #else

	 #define   led_7_set_com0()        JL_PORTA->OUT|= BIT(3);    JL_PORTA->HD |= BIT(3);     JL_PORTA->DIR &= ~BIT(3)
	 #define   led_7_set_com1()        JL_PORTA->OUT|= BIT(4);  JL_PORTA->HD |= BIT(4);    JL_PORTA->DIR &= ~BIT(4)
	 #define   led_7_set_com2()        JL_PORTA->OUT|= BIT(5);  JL_PORTA->HD |= BIT(5);    JL_PORTA->DIR &= ~BIT(5)
	 #define   led_7_set_com3()        JL_PORTA->OUT|= BIT(6);    JL_PORTA->HD |= BIT(6);     JL_PORTA->DIR &= ~BIT(6)
	 #define   led_7_set_com4()        JL_PORTA->OUT|= BIT(7);    JL_PORTA->HD |= BIT(7);     JL_PORTA->DIR &= ~BIT(7)
	 #define   led_7_set_com5()        JL_PORTC->OUT|= BIT(4);    JL_PORTC->HD |= BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_set_com6()        JL_PORTC->OUT|= BIT(5);    JL_PORTC->HD |= BIT(5);     JL_PORTC->DIR &= ~BIT(5)


	 #define   led_7_clr_seg0()       JL_PORTA->OUT &= ~BIT(3);     JL_PORTA->DIR &= ~BIT(3)
	 #define   led_7_clr_seg1()       JL_PORTA->OUT &= ~BIT(4);   JL_PORTA->DIR &= ~BIT(4)
	 #define   led_7_clr_seg2()       JL_PORTA->OUT &= ~BIT(5);   JL_PORTA->DIR &= ~BIT(5)
	 #define   led_7_clr_seg3()       JL_PORTA->OUT &= ~BIT(6);     JL_PORTA->DIR &= ~BIT(6)
	 #define   led_7_clr_seg4()       JL_PORTA->OUT &= ~BIT(7);     JL_PORTA->DIR &= ~BIT(7)
	 #define   led_7_clr_seg5()       JL_PORTC->OUT &= ~BIT(4);     JL_PORTC->DIR &= ~BIT(4)
	 #define   led_7_clr_seg6()       JL_PORTC->OUT &= ~BIT(5);     JL_PORTC->DIR &= ~BIT(5)

	 #endif


	 #endif

#endif

#if defined(SUPPORT_DOUBLE_LED7_PANEL)

typedef struct _led7_VAR
{
    u8  bCoordinateX;
    u8  bFlashChar;
    u16  bFlashIcon;
    u16 wLedIcon;
     u16 wFlashIcon;
   bool bBtIfConnect;
    u8  bShowBuff[LED_8NUMS];
    u8  bBrightness;
    u8  bShowBuff1[LED_COM_MAX];
}LED7_VAR;

#elif defined(LCD_4x9_MODE)

typedef struct _led7_VAR
{
    u8  bCoordinateX;
    u8  bFlashChar;
    #if defined LCD_ID_JXH_S6002A
    u8 wFlashIcon;
    u8 wLedIcon;
    #else
    u16 wFlashIcon;
    u16 wLedIcon;
    #endif
    u8  bShowBuff[LED_8NUMS];
    u8  bBrightness;
    u16  bShowBuff1[LED_COM_MAX];
    bool bBtIfConnect; //jude if bt connected
    u32 dwDeviceID;
    u32 blast_play_device;
}LED7_VAR;

#else
typedef struct _led7_VAR
{
    u8  bCoordinateX;
    u8  bFlashChar;
    u8  bFlashIcon;
    u16 wLedIcon;
     u16 wFlashIcon;
 #ifdef SUPPORT_EQ_FREQUENCE
 	#if defined(LED_ID_YDL2001_VFN_35)||defined(LED_ID_DB_51)
 		u32 bEqIconBuf;
	#else
 		u16 bEqIconBuf;
	#endif
 #endif

    #ifdef LED_EQ_BAR_SHOW
    u8 bEqBarBuf[LED_EQ_NUMS];
    u16 bEqBarEnergyValueBuf[LED_EQ_NUMS];
    u8 bEqMode;
    bool bEqPlayFlag;
    #endif


 #if defined(LED_ID_JW2781)||defined(LED_ID_8SD78YRG)
    u8 bCircleBuf;
#endif
 #ifdef SUPPORT_TM1628_KEY_READ
    u16 wTm1628KeyData; //H8 BYTE L8 DATA
#endif
   u32 dwDeviceID;
    u32 blast_play_device;
    bool bEqCircleIfPlay;  //use for eq/eq bar/circle if show
   bool bBtIfConnect;
#if LED_8GRIDS==14
    u16  bShowBuff[LED_8NUMS];
    u16  bShowBuff1[LED_COM_MAX];
#else
    u8  bShowBuff[LED_8NUMS];
    u8  bShowBuff1[LED_COM_MAX];
#endif
    u8  bBrightness;
}LED7_VAR;
#endif
#define LED_STATUS  led7_var.wLedIcon
#define LED_FLASH_ICON led7_var.wFlashIcon
#define LED_FLASH_CHAR led7_var.bFlashChar
extern 	LED7_VAR led7_var;
 #if defined(SUPPORT_TM1628_MODE)||defined(SUPPORT_PT6312_MODE)
#ifdef TEST_PANEL_LED
extern u8 bledComValue;
extern u8 bledGridValue;
#endif
#endif

void led7_init(void);
void led7_scan(void *param);
void led7_clear_icon(void);
void led7_show_char(u8 chardata);
void led7_show_number(u8 number);
void led7_show_Hi(void);
void led7_show_music_main(void);
void led7_show_RTC_main(void);
void led7_show_filenumber(void);
void led7_show_volume(s32 vol);
void led7_show_fm_main(void);
void led7_show_IR_number(s32);
void led7_show_pc_main(void);
void led7_show_pc_vol_up(void);
void led7_show_pc_vol_down(void);
void led7_show_aux_main(void);
void led7_show_eq(s32 arg);
void led7_show_playmode(s32 arg);
void led7_show_pause(void);
void led7_show_fm_station(void);
void led7_show_waiting(void);
void led7_show_alarm(void);
//void led7_show_nop(void);
void led7_show_rec_main(void);
void led7_show_linin_main(u8 menu);
void led7_clear(void);
void led7_show_string_menu(u8 menu);
void led7_setX(u8 X);

#ifdef support_menu_mode
void led7_show_vol_menu_main(void);
#endif
#if defined(SUPPORT_TM1628_MODE)||defined(SUPPORT_PT6312_MODE)
void WR_HT1628_Byte(u8 data);
void WR_HT1628_CMD(u8 cmd);
#endif


#if defined(SUPPORT_TM1618_MODE)
void WR_HT1618_Byte(u8 data);
void WR_HT1618_CMD(u8 cmd);
void LED_SHOW_EQ_BAR(u8 barNum,int mode,u8 steps);
void LED_EQ_BAR_PROCESS(u8 mode);

#endif



#ifdef LED_SHOW_DEVICE_PLUGIN
void led7_show_device_main(void);
#endif
#ifdef LED_SCREEN_SHOW_BAT_STATUS
void led7_show_bat_status(void);
#endif

#ifdef SUPPORT_EQ_FREQUENCE_TIMER_SCAN
void  LED_FREQUENCE_PROCESS(void);
#endif
#ifdef SUPPORT_RGB_LED_MODE
void  led7_show_rgb_led_mode_main(void);
#endif



#ifdef support_led_rgy_running
void led7_led_rgy_running_show(void);
#endif


#ifdef LED_EQ_BAR_SHOW
void LED_SHOW_EQ_BAR(u8 barNum,int mode,u8 steps);
void LED_EQ_BAR_PROCESS(u8 mode);
#endif
#ifdef SUPPORT_MUSIC_FOLDER_OPERATION
void led7_folder_show_main(void);
#endif



#ifdef SUPPORT_TM1628_KEY_READ

tu8 get_led_driver_key_value(void);

#ifdef LED_KEY_USE_ZY_HJ802_1_4KEY
#define LED_KEY_NEXT    0
#define LED_KEY_PP         2
#define LED_KEY_PREV     4
#define LED_KEY_MODE   5
#endif

#define LED_KEY_NULL 0xff
#endif


#define LED_A   BIT(0)
#define LED_B	BIT(1)
#define LED_C	BIT(2)
#define LED_D	BIT(3)
#define LED_E	BIT(4)
#define LED_F	BIT(5)
#define LED_G	BIT(6)
#define LED_H	BIT(7)
#if LED_8GRIDS==14
#define LED_I	BIT(8)
#define LED_J	BIT(9)
#define LED_K	BIT(10)
#define LED_L	BIT(11)
#define LED_M	BIT(12)
#define LED_HN	BIT(13)
#endif


#ifdef SUPPORT_EQ_FREQUENCE
#ifdef LED_ID_YDL2001_VFN_35
#define EQ_00  0x01
#define EQ_01  0x02
#define EQ_02  0x04
#define EQ_03  0x08
#define EQ_04  0x10
#define EQ_05  0x20
#define EQ_06  0x40
#define EQ_07  0x80
#define EQ_08  0x100
#define EQ_09  0x200
#define EQ_10  0x400
#define EQ_11  0x800
#define EQ_12  0x1000
#define EQ_13  0x2000
#define EQ_14  0x4000
#define EQ_15  0x8000
#define EQ_16  0x10000
#define EQ_17  0x20000
#define EQ_18  0x40000
#define EQ_19  0x80000
#define EQ_20  0x100000
#define EQ_21  0x200000
#define EQ_22  0x400000
#define EQ_23  0x800000
#define EQ_24  0x1000000
#define EQ_25  0x2000000
#define EQ_26  0x4000000
#define EQ_27  0x8000000
#define EQ_28  0x10000000
#define EQ_29  0x20000000
#define EQ_30  0x40000000
#define EQ_31  0x80000000
#elif defined(LED_ID_DB_51)
#define EQ_00  0x01
#define EQ_01  0x02
#define EQ_02  0x04
#define EQ_03  0x08
#define EQ_04  0x10
#define EQ_05  0x20
#define EQ_06  0x40
#define EQ_07  0x80
#define EQ_08  0x100
#define EQ_09  0x200
#define EQ_10  0x400
#define EQ_11  0x800
#define EQ_12  0x1000
#define EQ_13  0x2000
#define EQ_14  0x4000
#define EQ_15  0x8000
#define EQ_16  0x10000
#define EQ_17  0x20000
#define EQ_18  0x40000
#define EQ_19  0x80000
#define EQ_20  0x100000
#define EQ_21  0x200000
#define EQ_22  0x400000
#define EQ_23  0x800000


#elif defined(LED_ID_1600B_VFD)
#define EQ_00  0x01
#define EQ_01  0x02
#define EQ_02  0x04
#define EQ_03  0x08
#define EQ_04  0x10
#define EQ_05  0x20

#else
#define EQ_00  0x01
#define EQ_01  0x02
#define EQ_02  0x04
#define EQ_03  0x08
#define EQ_04  0x10
#define EQ_05  0x20
#define EQ_06  0x40
#define EQ_07  0x80
#define EQ_08  0x100
#define EQ_09  0x200
#define EQ_10  0x400
#define EQ_11  0x800
#define EQ_12  0x1000
#define EQ_13  0x2000
#define EQ_14  0x4000
#define EQ_15  0x8000
#endif
#endif


#if defined(LED_ID_4018N_2)
//LED_USB,LED_SD,LED_FM,LED_FM,LED_2POINT,LED_DOT,LED_BAT

#define LED_USB     0x01
#define LED_SD      0x02
#define LED_FM	    0x04
#define LED_AUX     0X08
#define LED_2POINT  0x10
#define LED_DOT     0X20
#define LED_BAT    0X40

#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_MHZ	    0
#define LED_BT	    0
#define LED_DVD	    0


#elif defined LED_ID_XH2401_7
   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD, LED_FM,  LED_MP3LED_2POINT

/*PLAY	USB  8 8:8.8 FM */
/*PAUSE   SD		   MP3*/

#define LED_PLAY	0x01
#define LED_PAUSE	0x02
#define LED_USB     0x04
#define LED_SD      0x08
#define LED_FM	    0x10
#define LED_MP3     0x20
#define LED_2POINT  0x40

#define LED_AUX     0
#define LED_DOT     0
#define LED_BAT    0
#define LED_MHZ	    0
#define LED_BT	    0

#elif defined LED_ID_27N60_8

/*
	tf	   fm
|||| 88:8.8 ||||
	usb	  aux
*/

//LED_SD,LED_USB,LED_FM,LED_AUX,LED_2POINT,LED_DOT

       #define LED_SD		  LED_A
       #define LED_USB		LED_B
       #define LED_FM		LED_C
	 #define LED_AUX		  LED_D
       #define LED_2POINT	  LED_E
	#define   LED_DOT         LED_F
       #define LED_MHZ	         0
       #define LED_PLAY	        0
       #define LED_PAUSE	0
       #define LED_MP3		0
#elif defined(LED_ID_JW84267_4)

/*

PLAY				MP3
PAUSE    88:8.8	       AUX
USB					FM
SD    				MHZ

*/
//LED_PLAY,LED_PAUSE,_LED_USB,LED_SD,LED_2POINT,LED_DOT,LED_MP3,LED_AUX,LED_FM,LED_MHZ


#define LED_PLAY       0x01
#define LED_PAUSE    0x02
#define LED_USB 	       0x04
#define LED_SD	       0x08
#define LED_2POINT   0x10
#define LED_DOT        0x20
#define LED_MP3		0x40
#define LED_AUX        0X80
#define LED_FM          0X100
#define LED_MHZ        0X200

#define LED_BT     0
#define LED_DVD     0

#elif defined LED_ID_SD40X18_1SRB_15
/*  8 8:8.8*/
/*  bt sd usb FM AUX  bat01 bat02 bat03*/

//LED_BT,LED_SD,LED_USB,LED_FM,LED_AUX,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
#ifdef SUPPORT_SD40X18_1SRB_15_OFF_BAT_ICON
#define LED_BT      0
#else
#define LED_BT      0x01
#endif
#define LED_SD      0x02
#define LED_USB     0x04
#define LED_FM    0x08
#define LED_AUX  0x10
#define LED_2POINT  0x20
#define LED_DOT     0x40
#define LED_BAT01   0x80
#define LED_BAT02   0x0100
#define LED_BAT03   0x0200

#define LED_RECO    0
#define LED_REPLAY  0
#define LED_MHZ	    0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0

#elif defined LED_ID_JW4018D_1B||defined LED_ID_4018_73
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/

//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
#ifdef SUPPORT_SD40X18_1SRB_15_OFF_BAT_ICON
#define LED_BT      0
#else
#define LED_BT      0x01
#endif
#define LED_SD      0x02
#define LED_USB     0x04
#define LED_RECO    0x08
#define LED_REPLAY  0x10
#define LED_2POINT  0x20
#ifdef SUPPORT_OFF_FM_DOT_ICON
#define LED_DOT     0
#else
#define LED_DOT     0x40
#endif
#define LED_BAT01   0x80
#define LED_BAT02   0x0100
#define LED_BAT03   0x0200

#define LED_MHZ	    0
#define LED_AUX     0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_FM	    0
#define LED_DVD	    0


#elif defined(LED_ID_4018D7_1B)

/*  8 8:8.8*/
/*  bt card usb fm aux  bat01 bat02 bat03*/

//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
#define LED_BT      0x01
#define LED_SD      0x02
#define LED_USB     0x04
#define LED_FM    0x08
#define LED_AUX  0x10
#define LED_2POINT  0x20
#define LED_DOT     0x40
#define LED_BAT01   0x80
#define LED_BAT02   0x0100
#define LED_BAT03   0x0200


#define LED_MHZ	    0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_RECO    0
#define LED_REPLAY  0
#elif defined(LED_ID_1600B_VFD)

#define LED_2POINT  0x01
#define LED_DOT     0x02
#define LED_AM     0x04
#define LED_AUX     0x08
#define LED_FM	    0x10
#define LED_USB     0x20
#define LED_DVD     0x40
#define LED_ECHO     0x80
#define LED_SW     0x100
#define LED_MIC     0x200
#define LED_CEN    0x400
#define LED_FRONT     0x800
#define LED_SURR     0x1000
#define LED_VOLUME     0x2000


#define LED_SD      0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_MP3     0
#define LED_MHZ	    0
#define LED_BT      0
#define LED_RECO    0
#define LED_REPLAY  0
#define LED_BAT01   0
#define LED_BAT02   0
#define LED_BAT03   0
#define LED_BAT     0
#define LED_2POINT1 0
#define LED_MIC_PRIORY 0

#elif defined(LED_ID_6030_C_VFD)
//LED_MP3,LED_FM,LED_TRE,LED_AUX,LED_SUB,LED_MVOL
#define LED_MP3     0x01
#define LED_FM	    0x02
#define LED_FRONT     0x04
#define LED_AUX     0x08
#define LED_SW     0x10
#define LED_VOLUME     0x20




#define LED_2POINT  0
#define LED_DOT     0
#define LED_AM     0
#define LED_USB     0
#define LED_DVD     0
#define LED_ECHO     0
#define LED_MIC     0
#define LED_CEN    0
#define LED_SD      0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_MHZ	    0
#define LED_BT      0
#define LED_RECO    0
#define LED_REPLAY  0
#define LED_BAT01   0
#define LED_BAT02   0
#define LED_BAT03   0
#define LED_BAT     0
#define LED_2POINT1 0
#define LED_MIC_PRIORY 0
#define LED_SURR     0
#elif defined(LED_ID_DB_51)
//LED_BT,LED_PLAY,LED_PAUSE,LED_FM,LED_AUX,LED_MP3,LED_USB,LED_SD,LED_2PIONT,LED_DOT
#define LED_BT      0x01
#define LED_PLAY	0x02
#define LED_PAUSE	0x04
#define LED_FM	    0x08
#define LED_AUX     0x10
#define LED_MP3     0x20
#define LED_USB     0x40
#define LED_SD      0x80
#define LED_2POINT  0x100
#define LED_DOT     0x200



#define LED_AM     0
#define LED_DVD     0
#define LED_ECHO     0
#define LED_SW     0
#define LED_MIC     0
#define LED_CEN    0
#define LED_FRONT     0
#define LED_SURR     0
#define LED_VOLUME     0
#define LED_MHZ	    0
#define LED_RECO    0
#define LED_REPLAY  0
#define LED_BAT01   0
#define LED_BAT02   0
#define LED_BAT03   0
#define LED_BAT     0
#define LED_2POINT1 0
#define LED_MIC_PRIORY 0
#elif defined(LED_ID_4018N_8848)
   //LED_PLAY,LED_PAUSE,LED_USB, , ,LED_DOT,LED_2POINT
   //led_fm,led_sd
#define LED_USB	    0x01
#define LED_SD      0x02
#define LED_FM		0x04
#define LED_DOT     0x08
#define LED_2POINT  0x10

#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_MP3     0
#define LED_BT 0
#define LED_MHZ	    0

#elif defined(LED_ID_JW8426C7_1B)||defined(LED_ID_SB_BG06247A)

/*
	PLAY				MP3
	PAUSE 	8:88:8.8      	AUX
	USB					FM
	SD					MHZ
*/

//LED_PLAY,LED_PAUSE,LED_USB,LED_SD,LED_2POINT,LED_DOT,LED_MP3,LED_AUX,LED_FM,LED_MHZ


#define LED_PLAY	0x01
#define LED_PAUSE	0x02
#define LED_USB     0x04
#define LED_SD      0x08
#define LED_2POINT  0x10
#define LED_DOT     0x20
#define LED_MP3     0x40
#define LED_AUX     0x80
#define LED_FM	    0x0100
#define LED_MHZ	    0x0200

#define LED_BT	    0


#elif defined LED_ID_40T18SRB

//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
#define LED_BT      0x01
#define LED_SD      0x02
#define LED_USB     0x04
#define LED_RECO    0x08
#define LED_REPLAY  0x10
#define LED_2POINT  0x20
#define LED_DOT     0x40
#define LED_BAT01   0x80
#define LED_BAT02   0x0100
#define LED_BAT03   0x0200


#define LED_MHZ	    0
#define LED_AUX     0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_DVD 0

#elif defined LED_ID_4018N_2_SCG

//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
#define LED_BT      0x01
#define LED_SD      0x02
#define LED_USB     0x04
#define LED_RECO    0x08
#define LED_REPLAY  0x10
#define LED_2POINT  0x20
#define LED_DOT     0x40
#define LED_BAT01   0x80
#define LED_BAT02   0x0100
#define LED_BAT03   0x0200


#define LED_MHZ	    0
#define LED_AUX     0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_DVD 0

#elif defined(LED_ID_JW_24017_1B_JW4018D7_1B)


   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD, LED_2POINT,LED_DOT,LED_FM,  LED_MP3,LED_BT,LED_SD1,LED_USB1,LED_RECO,LED_REPLAY,

#if 1
#define LED_PLAY	0X01
#define LED_PAUSE	0X02
#define LED_USB      0x04
#define LED_SD        0x08
#define LED_2POINT  0x10
#define LED_DOT     0x20
#define LED_FM	    0x40
#define LED_MP3     0x80
#define LED_BT        0x100
#define LED_SD1      0x200
#define LED_USB1     0x400
#define LED_RECO    0x800
#define LED_REPLAY  0x1000
#define LED_BAT01   0x2000
#define LED_BAT02   0x4000
#define LED_BAT03   0x8000
#else
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_USB     0
#define LED_SD      0
#define LED_2POINT  0
#define LED_DOT     0
#define LED_FM	    0
#define LED_MP3     0
#define LED_BT      0
#define LED_SD1      0
#define LED_USB1     0
#define LED_RECO    0
#define LED_REPLAY  0
#define LED_BAT01   0
#define LED_BAT02   0
#define LED_BAT03   0
#endif

#define LED_MHZ	    0
#define LED_AUX     0




#elif defined(LED_ID_8848)||defined(LED_ID_XH2408_7)
   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD,LED_FM,  LED_MP3, LED_DOT,LED_2POINT
#define LED_PLAY	0x01
#define LED_PAUSE	0x02
#define LED_USB     0x04
#define LED_SD      0x08
#define LED_FM	    0x10
#define LED_MP3     0x20
#define LED_DOT     0x40
#define LED_2POINT  0x80


#define LED_BT 0
#define LED_MHZ	    0
#define LED_DVD	0

#elif defined LED_ID_JW_18407_2


#define LED_BT		0x01
#define LED_MHZ	    	0x02
#define LED_AUX	  	0x04
#define LED_RECO  	0x08
#define LED_2POINT	0x10
#define LED_USB		0x20
#define LED_DOT		0x40
#define LED_SD		0x80

#define LED_BAT_FULL        0x100
#define LED_BAT_HALF       0x200
#define LED_BAT_LOW	0x400
#define LED_BAT_LOW1        0x800
#define LED_BAT_1       0x1000
#define LED_BAT_2	0x2000





#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_MP3    	 0
#define LED_ALRM       0
#define LED_DVD       0



#elif defined(LED_ID_JW4018D_4)

//LED_PLAY,LED_USB,LED_PAUSE,LED_SD,LED_FM,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03

#define LED_PLAY	0x01
#define LED_USB     0x02
#define LED_PAUSE	0x04
#define LED_SD      0x08
#define LED_FM	    0x10
#define LED_2POINT  0x20
#define LED_DOT     0x40
#define LED_BAT01   0x80
#define LED_BAT02   0x0100
#define LED_BAT03   0x0200

#define LED_BT      0
#define LED_MHZ	    0
#define LED_BAT     0
#define LED_AUX     0
#define LED_MP3     0

#elif defined(LED_ID_JW2781)

//LED_USB,LED_SD,LED_MP3,  LED_FM, LED_PLAY,  LED_PAUSE,LED_2POINT,LED_REPEAT

  #define LED_USB     0x01
  #define LED_SD		0x02
  #define LED_MP3 	0x04
  #define LED_FM	    0x08
  #define LED_PLAY  0x10
  #define LED_PAUSE 0x20
  #define LED_2POINT  0x40
  #define LED_REPEAT_ONE 0x80

  #define LED_AUX     0
  #define LED_BT      0
  #define LED_MHZ      0
#define LED_DOT     0
#define LED_REPEAT_ALL     0
#elif defined(LED_ID_8SD78YRG)

//LED_USB,LED_SD,LED_MP3,  LED_FM, LED_PLAY,  LED_PAUSE,LED_2POINT,LED_REPEAT

  #define LED_USB     0x01
  #define LED_SD		0x02
  #define LED_MP3 	0x04
  #define LED_FM	    0x08
  #define LED_PLAY  0x10
  #define LED_PAUSE 0x20
  #define LED_2POINT  0x40
  #define LED_REPEAT_ONE 0x80

  #define LED_AUX     0
  #define LED_BT      0
  #define LED_MHZ      0
#define LED_DOT     0
#define LED_REPEAT_ALL     0
#define LED_DVD     0


#elif defined(LED_ID_XL5641_15R) //


/*

	8 8:8.8

//LED_2POINT,LED_DOT

*/
#define LED_2POINT  0x01
#define LED_DOT    0x02


#define LED_FM     0
#define LED_SD      0
#define LED_USB	    0
#define LED_MP3     0
#define LED_PLAY     0
#define LED_PAUSE    0
#define LED_BT    0
#define LED_AUX     0
#define LED_MHZ	    0

#elif defined(LED_ID_SD88N27SRB_30)
   //LED_FM,LED_ALL,LED_SD,  LED_USB,LED_2POINT, LED_MUTE,  LED_MZH,LED_DOT

#define LED_FM     0x01
#define LED_ALL	0x02
#define LED_SD      0x04
#define LED_USB	    0x08
#define LED_2POINT  0x10
#define LED_MUTE     0X20
#define LED_MHZ    0X40
#define LED_DOT    0X80

#define LED_PLAY     0
#define LED_PAUSE    0
#define LED_MP3     0
#define LED_BT    0
#define LED_AUX     0
 #elif defined(LED_ID_4210TAB)


/*
FM			PLAY
USB	8 8:8.8	PAUSE
SD			MP3

//LED_FM,LED_SD,LED_USB,LED_MP3,LED_2POINT,LED_PLAY,LED_PAUSE
*/


#define LED_FM     0x01
#define LED_SD      0x02
#define LED_USB	    0x04
#define LED_MP3     0X08
#define LED_2POINT  0x10
#define LED_PLAY     0X20
#define LED_PAUSE    0X40

#define LED_BT    0
#define LED_DOT    0
#define LED_AUX     0
#define LED_MHZ	    0


#elif defined LED_ID_YDL2001_VFN_35
	//LED_PAUSE,LED_PALY,LED_ONE,LED_MP3,LED_AUX,LED_2POINT,LED_ALL

#define LED_PAUSE	0x01
#define LED_PLAY	0x02
#define LED_REPEAT_ONE 		0x04
#define LED_MP3    	0x08
#define LED_AUX     	0x10
#define LED_2POINT  0x20
#define LED_REPEAT_ALL		 0x40
#define LED_R 		0x80
#define LED_Y 		0x100
#define LED_LG 		0x200
#define LED_DVD	    	0x400





#define LED_USB    0
#define LED_SD      0
#define LED_FM	    0
#define LED_DOT     0
#define LED_BAT    0
#define LED_MHZ	    0
#define LED_BT	    0








#elif defined(LED_ID_88N45)
//LED_BT,LED_SD,LED_USB,  LED_REC,LED_RECPLAY,LED_BAT1,LED_BAT2,LED_BAT3, LED_2POINT,  LED_DOT

#define LED_BT	    0x01
#define LED_SD      0x02
#define LED_USB     0x04
#define LED_RECO    0x08
#define LED_REPLAY  0x10
#define LED_BAT01      0x20
#define LED_BAT02  0x40
#define LED_BAT03     0x80
#define LED_2POINT   0x0100
#define LED_DOT   0x0200

#define LED_MHZ	    0
#define LED_BAT     0
#define LED_AUX     0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_FM		0


#elif defined(LED_ID_TW52277_3)

/*

BAT3 BAT2 BAT1 FM SD USB REC REPLAY BT
  8 8:8.8

 */

//LED_FM,LED_SD,LED_USB,LED_REC,LED_REPLAY,LED_BT,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
#define LED_FM	    0x01
#define LED_SD      0x02
#define LED_USB     0x04
#define LED_RECO    0x08
#define LED_REPLAY  0x10
#define LED_BT      0x20
#define LED_2POINT  0x40
#define LED_DOT     0x80
#define LED_BAT01   0x0100
#define LED_BAT02   0x0200
#define LED_BAT03   0x0400

#define LED_MHZ	    0
#define LED_BAT     0
#define LED_AUX     0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0

#elif defined(LED_ID_JW18407_1B)
/*		  UP
	     L1 BAT1 R1
88:8.8       BAT2
	     L2  BAT3 R2
		  BAT4
		  DN
BT FM AUX REC USB CARD
//LED_BT,LED_FM,LED_AUX,  LED_REC,LED_USB,LED_SD, LED_2POINT,  LED_DOT,LED_BAT_K1,LED_BAT_K2,LED_BAT1,LED_BAT2,LED_BAT3,LED_BAT4

*/


#define LED_BT 		0x01
#define LED_FM		0x02
#define LED_AUX     	0X04
#define LED_RECO	0X08
#define LED_USB 		0x10
#define LED_SD	    	0x20
#define LED_2POINT   0x40
#define LED_DOT 		0x80
#define LED_BAT_K1	0X100
#define LED_BAT_K2   0X200
#define LED_BAT01	0X400
#define LED_BAT02	0X800
#define LED_BAT03	0X1000
#define LED_BAT04     0X2000


#define LED_MP3		0
#define LED_PLAY  0
#define LED_PAUSE 0
#define LED_MHZ      0

#elif defined(LED_ID_LD999B_J)

/*
	(1-2-3-4 4LED)								(1-2-3-4 4LED)
0-510-20-40-80-120-160-oo					0-510-20-40-80-120-160-oo
------------------------	知行合一	------------------------
		|||||||		  		88:8.8					|||||||
 HIFI									 			 HIFI
 				PLAY PAUSE  教材FM  AUX USB
*/
//LED_PLAY,LED_PAUSE,LED_FM,LED_AUX,LED_USB,LED_2POINT,LED_DOT

#define LED_PLAY        0x01
#define LED_PAUSE	 0x02
#define LED_FM 		 0x04
#define LED_AUX     	 0x08
#define LED_USB 		 0x10
#define LED_2POINT 	 0x20
#define LED_DOT		 0x40


#define LED_EQ00	    	0x01
#define LED_EQ01		0x02
#define LED_EQ02 		0x04
#define LED_EQ03 		0x08
#define LED_EQ04		0x10
#define LED_EQ05		0x20
#define LED_EQ06		0x40
#define LED_EQ07		0x80
#define LED_EQ08		0x100
#define LED_EQ09		0x200
#define LED_EQ10		0x400
#define LED_EQ11		0x800
#define LED_EQ12		0x1000
#define LED_EQ13		0x2000

#define LED_SD	    	 0
#define LED_MHZ      0
#define LED_MP3      0
#define LED_BT     0
#define LED_MHZ      0


#elif defined(LED_ID_JW5028B_1B)

/*
		88:8.8
PLAY				FM
PAUSE ||||00||||	AUX
USB					SD

BAT1	2	3	4
(LOW---->>>HIGH)

*/
	//LED_PLAY,LED_PAUSE,_LED_USB,_LED_2POINT,LED_FM,LED_AUX,LED_SD

#define LED_PLAY        0x01
#define LED_PAUSE	 0x02
#define LED_USB 		 0x04
#define LED_2POINT 	 0x08
#define LED_DOT		 0x10
#define LED_AUX     	 0x20
#define LED_SD	    	 0x40
#define LED_BAT01    	0x80
#define LED_BAT02	0x100
#define LED_BAT03 	0x200
#define LED_BAT04 	0x400


#define LED_EQ0    	0x01
#define LED_EQ1		0x02
#define LED_EQ2 		0x04
#define LED_EQ3 		0x08
#define LED_EQ4		0x10



#define LED_MHZ      0
#define LED_MP3      0
#define LED_BT     0
#define LED_MHZ      0

#elif defined(LCD_ID_JXH_S6002A)||defined(LCD_ID_HL_21716HNT)||defined(LCD_ID_ZSLCD)
#define LED_2POINT  0x01 //p1
#define LED_SD      0x02 //s1
#define LED_USB     0x04 //s2
#define LED_DOT     0x08 //s7

#define LED_BT      0x10 //s6
#define LED_RECO    0x20 //s5
#define LED_MUTE    0x40 //s4
#define LED_FOLDER  0x80 //s3

#define LED_REPLAY  0
#define LED_MHZ	    0
#define LED_BAT     0
#define LED_AUX     0
#define LED_MP3     0
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_FM	    0
#define LED_BAT01   0
#define LED_BAT02   0
#define LED_BAT03   0

#elif defined(LED_ID_JW6521B_1A)  // SX0212A


/*
BT	MP3		USB		SD		PLAY		PAUSE
TV	88:88:88
DVD
OPT	CDA		MP5		HDMI	MIC		MIC.VOL	   ECHO
*/
   //LED_BT,LED_MP3,LED_USB,  LED_SD, LED_PLAY,  LED_PAUSE,LED_2POINT1,LED_2POINT,LED_DOT

#define LED_BT     0x01
#define LED_MP3		0x02
#define LED_USB 	0x04
#define LED_SD	    0x08
#define LED_PLAY  0x10
#define LED_PAUSE 0x20
#define LED_2POINT1  0x40
#define LED_2POINT  0x80
#define LED_DOT 0x100
#define LED_DVD 0x200

#define LED_AUX     0
#define LED_MHZ      0

#elif defined(LED_ID_JW54627_1BB) //脙艗脙卢脗路脙楼
/*  8 8:8.8*/
#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_USB		0
#define LED_SD		0
#define LED_2POINT	LED_A
#define LED_MHZ	    0
#define LED_DOT		LED_B
#define LED_MP3     0
 #define LED_RECO     0
  #define LED_FM     0
 #define LED_2POINT1	0
#elif defined(LED_ID_ZY_308D) // tm1628

/*
USB SD PLAY			DVD	 CD   AUX

BT  PUSE       88:88	MZH     FM

 =	=	=	=	=	=	=	=

  //LED_USB,    LED_SD,   LED_PLAU,   LED_BT,LED_BT1,LED_PAUSE,LED_2POINT, LED_DVD,LED_MP3,LED_AUX,LED_MHZ,LED_FM,LED_FM1

*/
#define LED_USB 		0x01
#define LED_SD	    	0x02
#define LED_PLAY  	0x04
#define LED_BT     	0x08
#define LED_BT1     	0x10
#define LED_PAUSE 	0x20
#define LED_2POINT   0x40
#define LED_DVD 		0x80
#define LED_MP3 		0x100
#define LED_AUX     	0x200
#define LED_MHZ        0x400
#define LED_FM      	0x800
#define LED_FM1     	0x1000

#define LED_DOT		 0

 #elif defined(LED_ID_HJ820_1) // tm1628
/*

play			mp5
pause 8 8:88	mp4
bt			mp3

//LED_PLAY,LED_PAUSE,LED_BT,LED_2POINT,LED_MP5,LED_MP4,,LED_MP3

*/

#define LED_PLAY	0x01
#define LED_PAUSE	0x02
#define LED_BT		0X04
#define LED_2POINT	0X08
#define LED_MP3     	0X40

#define LED_USB		0
#define LED_SD		0
#define LED_MHZ	    0
#define LED_DOT		0


#elif defined(LED_ID_4018M)
/*  8 8:8.8*/
/*  BT SD USB FM PLAY PAUSE_L PAUSE_R*/

//LED_BT,LED_SD,LED_USB,LED_FM,LED_2POINT,LED_DOT,LED_PAUSE,LED_PAUSE2,LED_PLAY

#define LED_BT     0x01
#define LED_SD      0x02
#define LED_USB	    0x04
#define LED_FM     0X08
#define LED_2POINT  0x10
#define LED_DOT     0X20
#define LED_PAUSE    0X40
#define LED_PAUSE2    0X80
#define LED_PLAY	    0X100

#define LED_MP3	    0

#elif defined(LED_ID_SD40X18_1SRB_15_JY) //脙艗脙卢脗路脙楼
/*  8 8:8.8*/
/*  BT SD USB FM PLAY PAUSE_L PAUSE_R*/

//LED_BT,LED_SD,LED_USB,LED_FM,LED_PLAY,LED_2POINT,LED_DOT,LED_PAUSE,LED_PAUSE2


#define LED_BT     0x01
#define LED_SD      0x02
#define LED_USB	    0x04
#define LED_FM     0X08
#define LED_PLAY	 0x10
#define LED_2POINT     0X20
#define LED_DOT    	 0X40
#define LED_PAUSE    0X80
#define LED_PAUSE2   0X100

#define LED_MP3	    0

#elif defined(LED_ID_K1198KL_1)

/*

FM			PLAY
USB 8 8:88	PAUSE
SD			MP3

*/
	//LED_FM,LED_USB,LED_SD,LED_2POINT,LED_PLAY,LED_PAUSE,LED_MP3

#define LED_FM     0x01
#define LED_USB      0x02
#define LED_SD	    0x04
#define LED_2POINT	0X08
#define LED_PLAY	 0x10
#define LED_PAUSE     0X20
#define LED_MP3    	 0X40

#define LED_DOT    0




 #elif defined(LED_ID_JH820_03) // tm1628
/*


BT  DVD				_ 	_	 _	_
			88:8.8	_ 	_	 _	_
USB VCD				_ 	_	 _	_

					20 150 1K 10K

//LED_BT,LED_USB,LED_2POINT,LED_20,LED_150,LED_1K,LED_10K

*/

#define LED_BT		0X01
#define LED_USB		0X02
#define LED_2POINT	0X04
#define LED_20		0X08
#define LED_150		0X10
#define LED_1K		0X20
#define LED_10K		0X40



#define LED_PLAY	0
#define LED_PAUSE	0
#define LED_MP3     	0

#define LED_SD		0
#define LED_MHZ	    0
#define LED_DOT		0

#endif

#ifndef LED_FM
#define LED_FM      0
#endif
#ifndef LED_BT
#define LED_BT      0
#endif
#ifndef LED_AUX
#define LED_AUX      0
#endif
#ifndef LED_RECO
#define LED_RECO      0
#endif
#ifndef LED_REPLAY
#define LED_REPLAY      0
#endif


#endif	/*	_LED_H_	*/
