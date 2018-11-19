/*encoder.h file*/
#include "sdk_cfg.h"
#include "rtc/rtc_api.h"

#ifdef SUPPORT_ENCODER


#if defined(ENCODE_PIN_USE_PC4C3)  
  #define ENCODE_PORTB_IN()		JL_PORTC->DIR |= (BIT(4)|BIT(3));	 JL_PORTC->PU|= (BIT(4)|BIT(3));  
  #define  BM_DN_IS_H()			(JL_PORTC->IN & BIT(4) )
  #define  BM_UP_IS_H()			(JL_PORTC->IN & BIT(3))     
 #elif defined(ENCODE_PIN_USE_PC1C2)  
  #define ENCODE_PORTB_IN()		JL_PORTC->DIR |= (BIT(1)|BIT(2));	 JL_PORTC->PU|= (BIT(1)|BIT(2));  
  #define  BM_DN_IS_H()			(JL_PORTC->IN & BIT(1) )
  #define  BM_UP_IS_H()			(JL_PORTC->IN & BIT(2))     
 #elif defined(ENCODE_PIN_USE_PA10PA11)  
    #define ENCODE_PORTB_IN()	JL_PORTA->DIR |= (BIT(10)|BIT(11));	 JL_PORTA->PU|= (BIT(10)|BIT(11));  
  #define  BM_DN_IS_H()			(JL_PORTA->IN & BIT(10) )
  #define  BM_UP_IS_H()			(JL_PORTA->IN & BIT(11))     
 #elif defined(ENCODE_PIN_USE_PB10PB11)  
    #define ENCODE_PORTB_IN()	JL_PORTB->DIR |= (BIT(10)|BIT(11));	 JL_PORTB->PU|= (BIT(10)|BIT(11));  
  #define  BM_DN_IS_H()			(JL_PORTB->IN & BIT(10) )
  #define  BM_UP_IS_H()			(JL_PORTB->IN & BIT(11))   

 #elif defined(ENCODE_PIN_USE_DU_PB11PB10)  
    #define ENCODE_PORTB_IN()	JL_PORTB->DIR |= (BIT(10)|BIT(11));	 JL_PORTB->PU|= (BIT(10)|BIT(11));  
  #define  BM_DN_IS_H()			(JL_PORTB->IN & BIT(11) )
  #define  BM_UP_IS_H()			(JL_PORTB->IN & BIT(10))   
  
 #elif defined(ENCODE_PIN_USE_PA4PB11)  
    #define ENCODE_PORTB_IN()	JL_PORTA->DIR |= (BIT(4));JL_PORTB->DIR |= (BIT(11));	 JL_PORTA->PU|= (BIT(4));   JL_PORTB->PU|= (BIT(11));  
  #define  BM_DN_IS_H()			(JL_PORTA->IN & BIT(4) )
  #define  BM_UP_IS_H()			(JL_PORTB->IN & BIT(11))     
 #elif defined(ENCODE_PIN_USE_PR1PR3)  
    #define ENCODE_PORTB_IN()	PORTR_DIR(PORTR1,1);PORTR_DIR(PORTR3,1); PORTR_DIE(PORTR3,1);PORTR_PU(PORTR1,1); PORTR_PU(PORTR3,1);  PORTR_PD(PORTR1,0); PORTR_PD(PORTR3,0);
  #define  BM_DN_IS_H()			(PORTR_IN(PORTR1))
  #define  BM_UP_IS_H()			(PORTR_IN(PORTR3))    
   #elif defined(ENCODE_PIN_USE_PR3PR1)  
    #define ENCODE_PORTB_IN()	PORTR_DIR(PORTR1,1);PORTR_DIR(PORTR3,1); PORTR_DIE(PORTR3,1);PORTR_PU(PORTR1,1); PORTR_PU(PORTR3,1);  PORTR_PD(PORTR1,0); PORTR_PD(PORTR3,0);
  #define  BM_DN_IS_H()			(PORTR_IN(PORTR3))
  #define  BM_UP_IS_H()			(PORTR_IN(PORTR1))    
  #elif defined (ENCODE_PIN_USE_PB12B11)
  #define ENCODE_PORTB_IN()	JL_PORTB->DIR |= (BIT(11)|BIT(12));	 JL_PORTB->PU|= (BIT(11)|BIT(12));  
  #define  BM_DN_IS_H()			(JL_PORTB->IN & BIT(11)) 
  #define  BM_UP_IS_H()			(JL_PORTB->IN & BIT(12))

  
#endif

#ifdef SUPPORT_TWO_ENCODER
  #ifdef ENCODE1_PIN_USE_PC2C1
  #define ENCODE_PORTB_IN1()	JL_PORTC->DIR |= (BIT(2)|BIT(1));	 JL_PORTC->PU|= (BIT(2)|BIT(1));  
  #define  BM_DN_IS_H1()			(JL_PORTC->IN & BIT(2)) 
  #define  BM_UP_IS_H1()			(JL_PORTC->IN & BIT(1))
  #elif defined(ENCODE1_PIN_USE_PC1C2)  
   #define ENCODE_PORTB_IN1()	JL_PORTC->DIR |= (BIT(2)|BIT(1));	 JL_PORTC->PU|= (BIT(2)|BIT(1));  
  #define  BM_DN_IS_H1()			(JL_PORTC->IN & BIT(1)) 
  #define  BM_UP_IS_H1()			(JL_PORTC->IN & BIT(2))
 #elif defined(ENCODE1_PIN_USE_PC4C3)  
   #define ENCODE_PORTB_IN1()	JL_PORTC->DIR |= (BIT(4)|BIT(3));	 JL_PORTC->PU|= (BIT(4)|BIT(3));  
  #define  BM_DN_IS_H1()			(JL_PORTC->IN & BIT(4)) 
  #define  BM_UP_IS_H1()			(JL_PORTC->IN & BIT(3))  
  #endif
#endif

void ENC_Encoder(void);
#ifdef SUPPORT_ENCODE_flash_led
void ENC_Encoder_Led(void);
#endif

#ifdef SUPPORT_TWO_ENCODER
void ENC_Encoder1(void);
#endif
#endif
