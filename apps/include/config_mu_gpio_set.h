
/**********************  MUZHE IO SET  **************************/

/*  line 检测   */

#if   AUX_DETECT_EN
              #ifdef support_line_chack_user_PC10
                  #define AUX_IO_BIT    BIT(10)
                  #define AUX_DIR_SET    (JL_PORTC->DIR |= AUX_IO_BIT)
                  #define AUX_PU_SET      (JL_PORTC->PU  |= AUX_IO_BIT)
                  #define AUX_IN_CHECK  (JL_PORTC->IN  &  AUX_IO_BIT)
              #elif defined(support_line_chack_user_PC11)
                     #define AUX_IO_BIT    BIT(11)
                     #define AUX_DIR_SET    (JL_PORTC->DIR |= AUX_IO_BIT)
                  #ifdef support_line_chack_high
                       #define AUX_PU_SET      (JL_PORTC->PU |= AUX_IO_BIT)
                      #define AUX_IN_CHECK  (!(JL_PORTC->IN  &  AUX_IO_BIT))	
                  #else 
                      #define AUX_PU_SET      (JL_PORTC->PU  |= AUX_IO_BIT)
                      #define AUX_IN_CHECK  (JL_PORTC->IN  &  AUX_IO_BIT)	
                  #endif 
	      #elif defined( support_line_chack_user_PC13)
                  #define AUX_IO_BIT    BIT(13)
                  #define AUX_DIR_SET    (JL_PORTC->DIR |= AUX_IO_BIT)
                  #define AUX_PU_SET      (JL_PORTC->PU  |= AUX_IO_BIT)
                  #define AUX_IN_CHECK  (JL_PORTC->IN  &  AUX_IO_BIT)		  
			
		 #elif defined( support_line_chack_user_PC15)
                  #define AUX_IO_BIT    BIT(15)
                  #define AUX_DIR_SET    PORTC_DIE |=AUX_IO_BIT; JL_PORTC->DIR |= AUX_IO_BIT;
                  #define AUX_PU_SET      (JL_PORTC->PU  |= AUX_IO_BIT)
                  #define AUX_IN_CHECK  (JL_PORTC->IN  &  AUX_IO_BIT)				  
		#elif defined(support_line_chack_user_PA1) 
                    #define AUX_IO_BIT    BIT(1)
                    #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
		#ifdef support_io_is_h_line_in
                    #define AUX_PU_SET     JL_PORTA->PU &=~ BIT(1);; 
                    #define AUX_IN_CHECK  (!(JL_PORTA->IN  &  AUX_IO_BIT))  		
		#else 
                    #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  		
		#endif 	
		#elif defined(support_line_chack_user_PA11) 
                    #define AUX_IO_BIT    BIT(11)
                    #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
		#ifdef support_io_is_h_line_in
                    #define AUX_PU_SET     JL_PORTA->PU &=~ BIT(1);; 
                    #define AUX_IN_CHECK  (!(JL_PORTA->IN  &  AUX_IO_BIT))  		
		#else 
                    #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  		
		#endif 	
		
		#elif defined(support_line_chack_user_PA3) 
		
                    #define AUX_IO_BIT    BIT(3)
                    #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
		#ifdef support_io_is_h_line_in
                    #define AUX_PU_SET     JL_PORTA->PU &=~ BIT(1);; 
                    #define AUX_IN_CHECK  (!(JL_PORTA->IN  &  AUX_IO_BIT))  		
		#else 
                    #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  		
		#endif 
		#elif defined(support_line_chack_user_PA4) 
                    #define AUX_IO_BIT    BIT(4)
                    #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  				 
              #elif defined(support_line_chack_user_PA5) 
                    #define AUX_IO_BIT    BIT(5)
                    #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  	
		 #elif defined(support_line_chack_user_PA6) 
                    #define AUX_IO_BIT    BIT(6)
                    #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  				
              #elif defined(support_line_chack_user_PA8) 
                   #define AUX_IO_BIT    BIT(8)
                   #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                   #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                   #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  	     
	        #elif defined(support_line_chack_user_PA9) 
                   #define AUX_IO_BIT    BIT(9)
                   #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                   #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                   #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  	    		   
              #elif defined(support_line_chack_user_PA10) 
                   #define AUX_IO_BIT    BIT(10)
                   #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                   #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                   #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  
		#elif defined(support_line_chack_user_PA14) 
                   #define AUX_IO_BIT    BIT(14)
                   #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                   #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                   #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  	
		#elif defined(support_line_chack_user_PA15) 
                   #define AUX_IO_BIT    BIT(15)
                   #define AUX_DIR_SET   (JL_PORTA->DIR |= AUX_IO_BIT)
                   #define AUX_PU_SET    (JL_PORTA->PU  |= AUX_IO_BIT)
                   #define AUX_IN_CHECK  (JL_PORTA->IN  &  AUX_IO_BIT)  		   
	        #elif defined(support_line_chack_user_PB6) 
                    #define AUX_IO_BIT    BIT(6)
                    #define AUX_DIR_SET       (JL_PORTB->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET          (JL_PORTB->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK     (JL_PORTB->IN  &  AUX_IO_BIT)  	
		  #elif defined(support_line_chack_user_PB7) 
                    #define AUX_IO_BIT    BIT(7)
                    #define AUX_DIR_SET       (JL_PORTB->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET          (JL_PORTB->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK     (JL_PORTB->IN  &  AUX_IO_BIT)  	
		  #elif defined(support_line_chack_user_PR1) 
		  		  
                    #define AUX_IO_BIT    PORTR1
                    #define AUX_DIR_SET       {PORTR_DIR(AUX_IO_BIT,1);}
                    #define AUX_PU_SET          {PORTR_PU(AUX_IO_BIT,1);PORTR_PD(AUX_IO_BIT,0);}
                    #define AUX_IN_CHECK      (PORTR_IN(AUX_IO_BIT))  		
					
		  #elif defined(support_line_chack_user_PB9) 
                    #define AUX_IO_BIT    BIT(9)
                    #define AUX_DIR_SET       (JL_PORTB->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET          (JL_PORTB->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK     (JL_PORTB->IN  &  AUX_IO_BIT)  	
		  #elif defined(support_line_chack_user_PB10) 
                    #define AUX_IO_BIT    BIT(10)
                    #define AUX_DIR_SET       (JL_PORTB->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET          (JL_PORTB->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK     (JL_PORTB->IN  &  AUX_IO_BIT)  	
		  #elif defined(support_line_chack_user_pb12) 
                    #define AUX_IO_BIT    BIT(12)
                    #define AUX_DIR_SET       (JL_PORTB->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET          (JL_PORTB->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK     (JL_PORTB->IN  &  AUX_IO_BIT)  	
		  #elif defined(support_line_chack_user_PB11) 
                    #define AUX_IO_BIT    BIT(11)
                    #define AUX_DIR_SET       (JL_PORTB->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET          (JL_PORTB->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK     (JL_PORTB->IN  &  AUX_IO_BIT)  		
		  #elif defined(support_line_chack_user_PB13) 
                    #define AUX_IO_BIT    BIT(13)
                    #define AUX_DIR_SET       (JL_PORTB->DIR |= AUX_IO_BIT)
                    #define AUX_PU_SET          (JL_PORTB->PU  |= AUX_IO_BIT)
                    #define AUX_IN_CHECK     (JL_PORTB->IN  &  AUX_IO_BIT)  							
          #elif defined(support_line_chack_user_ADK_220K)||defined(support_line_chack_user_SD_PA2)
            #define AUX_DIR_SET      
            #define AUX_PU_SET        
            #define AUX_IN_CHECK    
          #elif defined(support_line_chack_user_USBDM)
            #define USB_DM_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(1)) | ((x & 0x1)<<1))
            #define USB_DM_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(3)) | ((x & 0x1)<<3))
            #define USB_DM_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(5)) | ((x & 0x1)<<5))
            #define USB_DM_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(7)) | ((x & 0x1)<<7))   
            #define USB_DM_IN()       (USB_CON0&0x10000)>>16
            
            
            #define AUX_DIR_SET       USB_DM_DIR(1) 
            #define AUX_PU_SET         USB_DM_PU(1) 
            #define AUX_IN_CHECK     USB_DM_IN()		 
            
            
         #elif defined(support_line_chack_user_USBDP)
            
            #define USB_DP_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(0)) | ((x & 0x1)<<0))
            #define USB_DP_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(2)) | ((x & 0x1)<<2))
            #define USB_DP_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(4)) | ((x & 0x1)<<4))
            #define USB_DP_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(6)) | ((x & 0x1)<<6))
            	//      #define USB_DP_IN()     USB_CON0& (1L << (17))   
            
            #define AUX_DIR_SET       USB_DP_DIR(1)  
            #define AUX_PU_SET         USB_DP_PU(1) 
            #define AUX_IN_CHECK   (USB_CON0&0x20000) >>17
			
      #elif defined(support_line_chack_user_ad) 
           #define AUX_IO_BIT  
           #define AUX_DIR_SET 
           #define AUX_PU_SET   
           #define AUX_IN_CHECK 
				   
          #elif defined(support_line_chack_user_PA8) 		   

              #else 
              #error("请设置	line det IO ")
              #endif 
#endif 


/*  耳机  检测   */
#ifdef PHONE_CHECK_ENABLE
#ifndef SUPPORT_AMP_MUTE_EXTERN_AD_DET

    #ifdef   support_phone_chack_user_PA9
    	    #define PHONE_IO_BIT    BIT(9)
    	    #define PHONE_DIR_SET   (JL_PORTA->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTA->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTA->IN  &  PHONE_IO_BIT)  	
    #elif defined(support_phone_chack_user_PA2)	
    	    #define PHONE_IO_BIT    BIT(2)
    	    #define PHONE_DIR_SET   (JL_PORTA->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTA->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTA->IN  &  PHONE_IO_BIT)  		
    #elif defined(support_phone_chack_user_PA6)
	
    	    #define PHONE_IO_BIT    BIT(6)
    	    #define PHONE_DIR_SET   (JL_PORTA->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTA->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTA->IN  &  PHONE_IO_BIT)  
    #elif defined(support_phone_chack_user_PA7)
	
    	    #define PHONE_IO_BIT    BIT(7)
    	    #define PHONE_DIR_SET   (JL_PORTA->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTA->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTA->IN  &  PHONE_IO_BIT)  	
    #elif defined(support_phone_chack_user_PA8)	
    	    #define PHONE_IO_BIT    BIT(8)
    	    #define PHONE_DIR_SET   (JL_PORTA->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTA->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTA->IN  &  PHONE_IO_BIT)  				
   #elif defined(support_phone_chack_user_PA4)
    	    #define PHONE_IO_BIT    BIT(4)
    	    #define PHONE_DIR_SET   (JL_PORTA->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTA->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTA->IN  &  PHONE_IO_BIT)  

#elif defined(support_phone_chack_user_PB6) 	
	    #define PHONE_IO_BIT    BIT(6)
    	    #define PHONE_DIR_SET      (JL_PORTB->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET         (JL_PORTB->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK   (JL_PORTB->IN  &  PHONE_IO_BIT)  	
   #elif defined(support_phone_chack_user_PB7)
    	    #define PHONE_IO_BIT    BIT(7)
    	    #define PHONE_DIR_SET      (JL_PORTB->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET         (JL_PORTB->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK   (JL_PORTB->IN  &  PHONE_IO_BIT)  
			
   #elif defined(support_phone_chack_user_PB8)
    	    #define PHONE_IO_BIT    BIT(8)
    	    #define PHONE_DIR_SET      (JL_PORTB->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET         (JL_PORTB->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK   (JL_PORTB->IN  &  PHONE_IO_BIT)  

   #elif defined(support_phone_chack_user_PB12)
    	    #define PHONE_IO_BIT    BIT(12)
    	    #define PHONE_DIR_SET      (JL_PORTB->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET         (JL_PORTB->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK   (JL_PORTB->IN  &  PHONE_IO_BIT)  
   #elif defined(support_phone_chack_user_PB10)
    	    #define PHONE_IO_BIT    BIT(10)
    	    #define PHONE_DIR_SET      {JL_PORTB->DIR |= PHONE_IO_BIT;JL_PORTB->DIE |= PHONE_IO_BIT}
    	    #define PHONE_PU_SET         (JL_PORTB->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK   (JL_PORTB->IN  &  PHONE_IO_BIT)  			
    #elif defined(support_phone_chack_user_PC10)
    	    #define PHONE_IO_BIT    BIT(10)
    	    #define PHONE_DIR_SET   (JL_PORTC->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTC->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTC->IN  &  PHONE_IO_BIT)  	
    #elif defined(support_phone_chack_user_PC11)
    	    #define PHONE_IO_BIT    BIT(11)
    	    #define PHONE_DIR_SET   (JL_PORTC->DIR |= PHONE_IO_BIT)
    	    #define PHONE_PU_SET    (JL_PORTC->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTC->IN  &  PHONE_IO_BIT)  		
	
    #elif defined(support_phone_chack_user_PC15)
	    #define PHONE_IO_BIT    BIT(15)
    	    #define PHONE_DIR_SET   PORTC_DIE |=PHONE_IO_BIT; JL_PORTC->DIR |= PHONE_IO_BIT
    	    #define PHONE_PU_SET    (JL_PORTC->PU  |= PHONE_IO_BIT)
    	    #define PHONE_IN_CHECK  (JL_PORTC->IN  &  PHONE_IO_BIT)  	
    #elif defined(support_phone_chack_user_SD_PA2)	
    	    #define PHONE_DIR_SET 
    	    #define PHONE_PU_SET    
    	    #define PHONE_IN_CHECK 
    #else 
                 #error("请设置耳机 det IO ")
    #endif 
#endif 
#endif 


#ifdef SUPPORT_ENCODE_flash_led

#ifdef ENCODE_LED_USE_PC0

#define ENCODE_LED_IO(x)   {if(x){JL_PORTC->DIR &= ~BIT(0);JL_PORTC->OUT |= BIT(0);}else {JL_PORTC->DIR &= ~BIT(0);JL_PORTC->OUT &=~ BIT(0);}}

#endif

#endif





//MIC检测
#if  MIC_CHECK_ENABLE

#ifdef KOK_DETECT_USE_IO_ADC_VALUE
             // ("使用AD 做话筒检测 ")
#elif   defined  support_mic_chack_user_PB9
           #define MIC_IO_BIT    BIT(9)
    	    #define MIC_DIR_SET       (JL_PORTB->DIR |= MIC_IO_BIT)
	#ifdef support_high_mic_in	
           #define MIC_PU_SET		(JL_PORTB->PD  |= MIC_IO_BIT)
	#else 
    	    #define MIC_PU_SET          (JL_PORTB->PU  |= MIC_IO_BIT)
         #endif 
 	  #define MIC_IN_CHECK      (JL_PORTB->IN  &  MIC_IO_BIT)  	
		
#elif   defined  support_mic_check_user_PB11

           #define MIC_IO_BIT    BIT(11)
    	    #define MIC_DIR_SET       {JL_PORTB->DIR |= MIC_IO_BIT;JL_PORTB->DIE |= MIC_IO_BIT;}
	#ifdef support_high_mic_in	
           #define MIC_PU_SET		(JL_PORTB->PD  |= MIC_IO_BIT)
	#else 
    	    #define MIC_PU_SET          (JL_PORTB->PU  |= MIC_IO_BIT)
         #endif 
			#define MIC_IN_CHECK      (JL_PORTB->IN  &  MIC_IO_BIT)  	
#elif   defined  support_mic_check_user_PA9

           #define MIC_IO_BIT    BIT(9)
    	    #define MIC_DIR_SET       (JL_PORTA->DIR |= MIC_IO_BIT)
	#ifdef support_high_mic_in	
           #define MIC_PU_SET		(JL_PORTA->PD  |= MIC_IO_BIT)
	#else 
    	    #define MIC_PU_SET          (JL_PORTA->PU  |= MIC_IO_BIT)
         #endif 
		 
	 #define MIC_IN_CHECK      (JL_PORTA->IN  &  MIC_IO_BIT)  
#elif   defined  support_mic_check_user_PA1

           #define MIC_IO_BIT    BIT(1)
    	    #define MIC_DIR_SET       (JL_PORTA->DIR |= MIC_IO_BIT)
	#ifdef support_high_mic_in	
           #define MIC_PU_SET		(JL_PORTA->PD  |= MIC_IO_BIT)
	#else 
    	    #define MIC_PU_SET          (JL_PORTA->PU  |= MIC_IO_BIT)
         #endif 
		 
	 #define MIC_IN_CHECK      (JL_PORTA->IN  &  MIC_IO_BIT)  	 


	 
#elif   defined  support_mic_check_user_PB10

           #define MIC_IO_BIT    BIT(10)
    	    #define MIC_DIR_SET       (JL_PORTB->DIR |= MIC_IO_BIT)
	#ifdef support_high_mic_in	
           #define MIC_PU_SET		(JL_PORTB->PD  |= MIC_IO_BIT)
	#else 
    	    #define MIC_PU_SET          (JL_PORTB->PU  |= MIC_IO_BIT)
         #endif 
		 
	 #define MIC_IN_CHECK      (JL_PORTB->IN  &  MIC_IO_BIT)  
			
    #elif defined(support_mic_check_user_PC5)
           #define MIC_IO_BIT    BIT(5)
    	    #define MIC_DIR_SET       (JL_PORTC->DIR |= MIC_IO_BIT)
	#ifdef support_on_io_dn_10k 
	    #define MIC_PU_SET        (JL_PORTC->PD  |= MIC_IO_BIT) 
       #else 
	     #define MIC_PU_SET        (JL_PORTC->PU  |= MIC_IO_BIT)
	  #endif 
	#define MIC_IN_CHECK     (JL_PORTC->IN & MIC_IO_BIT)  
	
#elif defined(support_mic_chack_user_PB7)
            #define MIC_IO_BIT       BIT(7)
    	    #define MIC_DIR_SET      (JL_PORTB->DIR |= MIC_IO_BIT)
     #ifdef support_on_io_dn_10k 			
            #define MIC_PU_SET       (JL_PORTB->PD  |= MIC_IO_BIT)
     #else  
             #define MIC_PU_SET		 (JL_PORTB->PU	|= MIC_IO_BIT)
     #endif 
    	    #define MIC_IN_CHECK     (JL_PORTB->IN  &  MIC_IO_BIT)  				
#elif defined(support_mic_chack_user_PB8)
            #define MIC_IO_BIT       BIT(8)
    	    #define MIC_DIR_SET      (JL_PORTB->DIR |= MIC_IO_BIT)
    	    #define MIC_PU_SET       (JL_PORTB->PU  |= MIC_IO_BIT)
    	    #define MIC_IN_CHECK     (JL_PORTB->IN  &  MIC_IO_BIT)  				
#elif defined(support_mic_chack_user_PB10)
            #define MIC_IO_BIT       BIT(10)
    	    #define MIC_DIR_SET      (JL_PORTB->DIR |= MIC_IO_BIT)
    	    #define MIC_PU_SET       (JL_PORTB->PU  |= MIC_IO_BIT)
    	    #define MIC_IN_CHECK     (JL_PORTB->IN  &  MIC_IO_BIT)  				
   #elif defined( support_mic_chack_user_PB6)
           #define MIC_IO_BIT    BIT(6)
    	    #define MIC_DIR_SET       (JL_PORTB->DIR |= MIC_IO_BIT)
    	    #define MIC_PU_SET          (JL_PORTB->PU  |= MIC_IO_BIT)
    	    #define MIC_IN_CHECK      (JL_PORTB->IN  &  MIC_IO_BIT)  				
    #elif defined(support_mic_chack_user_PC10)
           #define MIC_IO_BIT    BIT(10)
    	    #define MIC_DIR_SET       (JL_PORTC->DIR |= MIC_IO_BIT)
	#ifdef support_on_io_dn_10k 
	    #define MIC_PU_SET        (JL_PORTC->PD  |= MIC_IO_BIT) 
       #else 
	     #define MIC_PU_SET        (JL_PORTC->PU  |= MIC_IO_BIT)
	  #endif 
	#define MIC_IN_CHECK     (JL_PORTC->IN  &  MIC_IO_BIT)  
	
    #elif defined(support_mic_chack_user_PC11)
           #define MIC_IO_BIT    BIT(11)
    	    #define MIC_DIR_SET       (JL_PORTC->DIR |= MIC_IO_BIT)
	#ifdef support_on_io_dn_10k 
	    #define MIC_PU_SET        (JL_PORTC->PD  |= MIC_IO_BIT) 
       #else 
	     #define MIC_PU_SET        (JL_PORTC->PU  |= MIC_IO_BIT)
	  #endif 
	    #define MIC_IN_CHECK     (JL_PORTC->IN  &  MIC_IO_BIT)  		
    #elif defined(support_mic_chack_user_PA4)
           #define MIC_IO_BIT    BIT(4)
    	    #define MIC_DIR_SET       (JL_PORTA->DIR |= MIC_IO_BIT)
	#ifdef support_on_io_dn_10k 
	    #define MIC_PU_SET        (JL_PORTA->PD  |= MIC_IO_BIT) 
       #else 
	     #define MIC_PU_SET        (JL_PORTA->PU  |= MIC_IO_BIT)
	  #endif 
	#define MIC_IN_CHECK         (JL_PORTA->IN  &  MIC_IO_BIT)  
#elif defined(support_mic_chack_user_PA6)
            #define MIC_IO_BIT	 BIT(6)
            #define MIC_DIR_SET 	  (JL_PORTA->DIR |= MIC_IO_BIT)
            #ifdef support_on_io_dn_10k 
            #define MIC_PU_SET		  (JL_PORTA->PD  |= MIC_IO_BIT) 
            #else 
            #define MIC_PU_SET 	   (JL_PORTA->PU  |= MIC_IO_BIT)
            #endif 
            #define MIC_IN_CHECK		 (JL_PORTA->IN	&  MIC_IO_BIT)	

    #elif defined(support_mic_chack_user_PA8)
           #define MIC_IO_BIT    BIT(8)
    	    #define MIC_DIR_SET       (JL_PORTA->DIR |= MIC_IO_BIT)
	#ifdef support_on_io_dn_10k 
	    #define MIC_PU_SET        (JL_PORTA->PD  |= MIC_IO_BIT) 
       #else 
	     #define MIC_PU_SET        (JL_PORTA->PU  |= MIC_IO_BIT)
	  #endif 
	#define MIC_IN_CHECK         (JL_PORTA->IN  &  MIC_IO_BIT)  
	
   #else 
        #error("请设置MIC  det IO ")
   #endif
#endif 
   

/*  PP LED    */

#if LED_EN
     #ifdef PP_LED_USER_PB7
         #define LED_BIT                BIT(7)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()          JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()        JL_PORTB->OUT &= ~LED_BIT;
     #elif defined(PP_LED_USER_PB6)	 
	 #define LED_BIT                BIT(6)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTB->OUT &= ~LED_BIT;
     #elif defined(PP_LED_USER_PB8)	 
	 #define LED_BIT                BIT(8)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTB->OUT &= ~LED_BIT;		 
     #elif defined(PP_LED_USER_PB9)	 
	 #define LED_BIT                BIT(9)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTB->OUT &= ~LED_BIT;
     #elif defined(PP_LED_USER_PB9_LOW)	 
	 #define LED_BIT                BIT(9)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_OFF()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_ON()         JL_PORTB->OUT &= ~LED_BIT;
		 
	#elif defined(PP_LED_USER_PB10)	 
	 #define LED_BIT                BIT(10)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTB->OUT &= ~LED_BIT;
	#elif defined(PP_LED_USER_PB11)	 
	 #define LED_BIT                BIT(11)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTB->OUT &= ~LED_BIT;	 
	#elif defined(PP_LED_USER_PB12)	 
	 #define LED_BIT                BIT(12)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTB->OUT &= ~LED_BIT;	 
	#elif defined(PP_LED_USER_PB13)	 
	 #define LED_BIT                BIT(13)
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTB->OUT &= ~LED_BIT;	 		 
  #elif defined(PP_LED_USER_PC2)	 
	 #define LED_BIT                BIT(2)
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTC->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTC->OUT &= ~LED_BIT;		
		 
    #elif defined(PP_LED_USER_PC4)	 
	#ifdef led_low_light
	 #define LED_BIT                BIT(4)
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &=~ LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &=~ LED_BIT;JL_PORTC->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTC->OUT &=~ LED_BIT;
         #define B_LED_OFF()         JL_PORTC->OUT |= LED_BIT;	
	#else
	 #define LED_BIT                BIT(4)
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTC->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTC->OUT &= ~LED_BIT;	
	#endif

		 
    #elif defined(PP_LED_USER_PC5)	 
	 #define LED_BIT                BIT(5)
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTC->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTC->OUT &= ~LED_BIT;	
		 
	#elif defined(PP_LED_USER_PC10)	 
	 #define LED_BIT                BIT(10)
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTC->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTC->OUT &= ~LED_BIT;	
	#elif defined(PP_LED_USER_PC14)	 
	 #define LED_BIT                BIT(14)
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTC->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTC->OUT &= ~LED_BIT;	
	#elif defined(PP_LED_USER_PC0)	 
	 #define LED_BIT                BIT(0)
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTC->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTC->OUT &= ~LED_BIT;	


		 
	#elif defined(PP_LED_USER_PR2)	 	 
	 
            #define LED_INIT_EN()     {PORTR_DIR(PORTR2,0);}
            #define LED_INIT_DIS()    {PORTR_PU(PORTR2,0);PORTR_PD(PORTR2,0);PORTR_DIR(PORTR2,1);}
            #define B_LED_ON()          {PORTR_OUT(PORTR1,1);}
            #define B_LED_OFF()         {PORTR_OUT(PORTR1,0); }           
            
	#elif defined(PP_LED_USER_PC14_PR1)	 	 
	 #define LED_BIT                BIT(14)
	 
            #define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;PORTR_DIR(PORTR1,0);}
            #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
            #define B_LED_ON()          {JL_PORTC->OUT |= LED_BIT;PORTR_OUT(PORTR1,1);}
            #define B_LED_OFF()         {JL_PORTC->OUT &= ~LED_BIT;	 PORTR_OUT(PORTR1,0); }           
	 
    #elif defined(PP_LED_USER_PC12)  
          #define LED_BIT				BIT(12)
          #define LED_INIT_EN()	   {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT; PORTC_DIE |=BIT(12); }
          #define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
            #if defined( led_io_is_low_light)
		    #define B_LED_ON() 		JL_PORTC->OUT &= ~LED_BIT
                  #define B_LED_OFF()		 JL_PORTC->OUT |= LED_BIT	
            #else 		  
                  #define B_LED_ON() 		  JL_PORTC->OUT |= LED_BIT
                  #define B_LED_OFF()		 JL_PORTC->OUT &= ~LED_BIT	
            #endif 		  
	#elif defined(PP_LED_USER_PA0)	
         #define LED_BIT                BIT(0)
         #define LED_INIT_EN()   //  {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()         JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;  JL_PORTA->OUT &= ~LED_BIT;
         #define B_LED_OFF()         LED_INIT_DIS(); //LED_INIT_EN();  JL_PORTA->OUT |= LED_BIT; 	 
		 
   #elif defined(PP_LED_USER_PA3) 
		#define LED_BIT 			   BIT(3)
		#define LED_INIT_EN()	  {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
		#define LED_INIT_DIS()	  {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
		#define B_LED_ON()			 JL_PORTA->OUT |= LED_BIT;
		#define B_LED_OFF() 		JL_PORTA->OUT &= ~LED_BIT;	
   #elif defined(PP_LED_USER_Pa7) 
		#define LED_BIT 			   BIT(7)
		#define LED_INIT_EN()	  {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
		#define LED_INIT_DIS()	  {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
		#define B_LED_ON()			 JL_PORTA->OUT |= LED_BIT;
		#define B_LED_OFF() 		JL_PORTA->OUT &= ~LED_BIT;	


		
#elif defined(PP_LED_USER_PA2) 
	 #define LED_BIT				BIT(2)
	 #define LED_INIT_EN()	   {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
	 #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
	 #define B_LED_ON() 		  JL_PORTA->OUT |= LED_BIT;
	 #define B_LED_OFF()		 JL_PORTA->OUT &= ~LED_BIT;  

     #elif defined(PP_LED_USER_PA4)	
         #define LED_BIT                BIT(4)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;	 
     #elif defined(PP_LED_USER_PA5)	
         #define LED_BIT                BIT(5)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;	 		 
     #elif defined(PP_LED_USER_PA6)	
         #define LED_BIT                BIT(6)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;
     #elif defined(PP_LED_USER_PA7)	
         #define LED_BIT                BIT(7)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;		 
     #elif defined(PP_LED_USER_PA8)	
         #define LED_BIT                BIT(8)

	#ifdef support_PA8_ad_io_led
            #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
            #define LED_INIT_DIS()   {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
            #define B_LED_ON()      LED_INIT_EN() ;   JL_PORTA->OUT &= ~LED_BIT;//  LED_INIT_EN();  JL_PORTA->OUT &= ~LED_BIT;
            #define B_LED_OFF()    LED_INIT_EN() ;  JL_PORTA->OUT |= LED_BIT;//JL_PORTA->DIR |= LED_BIT;;// LED_INIT_DIS(); //LED_INIT_EN();  JL_PORTA->OUT |= LED_BIT; 	 
	#else 
             #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
             #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
             #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
             #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;
	#endif 	 
     #elif defined(PP_LED_USER_PA9)	
         #define LED_BIT                BIT(9)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;	 
     #elif defined(PP_LED_USER_PA15)	
         #define LED_BIT                BIT(15)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;	
     #elif defined(PP_LED_USER_PA10)	
         #define LED_BIT                BIT(10)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;			 
     #elif defined(PP_LED_USER_PA11)	
         #define LED_BIT                BIT(11)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;		
     #elif defined(PP_LED_USER_PA14)	
         #define LED_BIT                BIT(14)
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
	#ifdef support_PA14_ad_io_led
            #define B_LED_ON()            LED_INIT_EN();  JL_PORTA->OUT &= ~LED_BIT;
            #define B_LED_OFF()         LED_INIT_DIS(); //LED_INIT_EN();  JL_PORTA->OUT |= LED_BIT; 	 
	 
       #elif defined( led_io_is_low_light)
	   #define B_LED_ON()           JL_PORTA->OUT &= ~LED_BIT;	 
         #define B_LED_OFF()         JL_PORTA->OUT |= LED_BIT;
	#else 
         #define B_LED_ON()           JL_PORTA->OUT |= LED_BIT;
         #define B_LED_OFF()         JL_PORTA->OUT &= ~LED_BIT;	
	#endif 

	
#elif defined(PP_LED_USER_PA15)    
          #define LED_BIT 			   BIT(15)
          #define LED_INIT_EN()	  {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
          #define LED_INIT_DIS()	  {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
          #define B_LED_ON()			 JL_PORTA->OUT |= LED_BIT;
          #define B_LED_OFF() 		JL_PORTA->OUT &= ~LED_BIT;	 	
     #elif defined(PP_LED_USER_PA10PA11_LOW)
         #define LED_BIT               ( BIT(10)|BIT(11))	
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT &= ~BIT(11);
         #define B_LED_OFF()         JL_PORTA->OUT |= BIT(11);
		 
         #define R_LED_ON()           JL_PORTA->OUT &= ~BIT(10);
         #define R_LED_OFF()         JL_PORTA->OUT |=BIT(10);	
#elif defined(PP_LED_USER_PA4PA3)    
	   #define LED_BIT               ( BIT(3)|BIT(4))	
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
		 
         #define B_LED_ON()          JL_PORTA->OUT |= BIT(3); 
         #define B_LED_OFF()          JL_PORTA->OUT &= ~BIT(3);
		 
         #define R_LED_ON()           JL_PORTA->OUT |= BIT(4);
         #define R_LED_OFF()         JL_PORTA->OUT &=~BIT(4);	
#elif defined(PP_LED_USER_PC4PB13)    
         #define LED_INIT_EN()     {JL_PORTC->PU &= ~BIT(4);JL_PORTC->PD &= ~BIT(4);JL_PORTC->DIR &= ~BIT(4);\
		 	JL_PORTB->PU &= ~BIT(13);JL_PORTB->PD &= ~BIT(13);JL_PORTB->DIR &= ~BIT(13);}
         #define LED_INIT_DIS()    {JL_PORTC->PU &= ~BIT(4);JL_PORTC->PD &= ~BIT(4);JL_PORTC->DIR |= BIT(4);\
		 	JL_PORTB->PU &= ~BIT(13);JL_PORTB->PD &= ~BIT(13);JL_PORTB->DIR |= BIT(13);}
		 
         #define B_LED_ON()          JL_PORTC->OUT |= BIT(4); 
         #define B_LED_OFF()          JL_PORTC->OUT &= ~BIT(4);
		 
         #define R_LED_ON()           JL_PORTB->OUT |= BIT(13);
         #define R_LED_OFF()         JL_PORTB->OUT &=~BIT(13);	
#elif defined(PP_LED_USER_PB8PB9)
	#define LED_BIT 			  ( BIT(9)|BIT(8))   
	#define LED_INIT_EN()	     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
	#define LED_INIT_DIS()	     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
	#define B_LED_ON()		       JL_PORTB->OUT |= BIT(8);
	#define B_LED_OFF() 	      JL_PORTB->OUT &= ~BIT(8);
					  
	#define R_LED_ON()		     JL_PORTB->OUT |=BIT(9); 	
	#define R_LED_OFF() 	     JL_PORTB->OUT &= ~BIT(9); 	

		 
#elif defined(PP_LED_USER_PC10PC11)
	#define LED_BIT 			  ( BIT(10)|BIT(11))   
	#define LED_INIT_EN()	     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
	#define LED_INIT_DIS()	     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
	#define B_LED_ON()		      JL_PORTC->OUT &= ~BIT(11);
	#define B_LED_OFF() 	      JL_PORTC->OUT |= BIT(11);
			 
	#define R_LED_ON()		      JL_PORTC->OUT &= ~BIT(10);
	#define R_LED_OFF() 		JL_PORTC->OUT |=BIT(10); 		 
		 
     #elif defined(PP_LED_USER_PA14_PA11)	
         #define LED_BIT               ( BIT(14)|BIT(11))	
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT &= ~BIT(14);
         #define B_LED_OFF()         JL_PORTA->OUT |= BIT(14);
		 
         #define line_LED_ON()           JL_PORTA->OUT &= ~BIT(11);
         #define LINE_LED_OFF()         JL_PORTA->OUT |=BIT(11);	
	#elif defined( PP_LED_USER_PA9PA11)
	   #define LED_BIT               ( BIT(9)|BIT(11))	
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
		 
         #define B_LED_ON()          JL_PORTA->OUT |= BIT(9); 
         #define B_LED_OFF()          JL_PORTA->OUT &= ~BIT(9);
		 
         #define R_LED_ON()           JL_PORTA->OUT |= BIT(11);
         #define R_LED_OFF()         JL_PORTA->OUT &=~BIT(11);	
	 
       #elif defined(PP_LED_USER_PA14_PA15)		 
	     #define LED_BIT               ( BIT(14)|BIT(15))	
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |=BIT(15);
         #define B_LED_OFF()         JL_PORTA->OUT &=~ BIT(15);
		 
         #define R_LED_ON()           JL_PORTA->OUT |= BIT(14);
         #define R_LED_OFF()         JL_PORTA->OUT &=~BIT(14);	
		 
       #elif defined(PP_LED_USER_PB10PB9)		 
	     #define LED_BIT               ( BIT(10)|BIT(9))	
         #define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTB->OUT |=BIT(9);
         #define B_LED_OFF()         JL_PORTB->OUT &=~ BIT(9);
		 
         #define R_LED_ON()           JL_PORTB->OUT |= BIT(10);
         #define R_LED_OFF()         JL_PORTB->OUT &=~BIT(10);	
      #elif defined(PP_LED_USER_PB2USBDM)
	     #define USB_DM_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(1)) | ((x & 0x1)<<1))
           #define USB_DM_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(3)) | ((x & 0x1)<<3))
           #define USB_DM_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(5)) | ((x & 0x1)<<5))
           #define USB_DM_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(7)) | ((x & 0x1)<<7))   
		   
                #define LED_BIT 	    BIT(2)	   
                #define LED_INIT_EN()         {USB_DM_DIR(0)  ;JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}		
                #define LED_INIT_DIS()        {USB_DM_DIR(1) ;JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}		
                #define B_LED_ON()               USB_DM_OUT(0);
                #define B_LED_OFF()             USB_DM_OUT(1); 	
                #define R_LED_ON()	         JL_PORTB->OUT &= ~LED_BIT;
                #define R_LED_OFF() 		  JL_PORTB->OUT |= LED_BIT; 
		 
	 #elif defined(PP_LED_USER_USBDP)
		 
		 #define USB_DP_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(0)) | ((x & 0x1)<<0))
		 #define USB_DP_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(2)) | ((x & 0x1)<<2))
		 #define USB_DP_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(4)) | ((x & 0x1)<<4))
		 #define USB_DP_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(6)) | ((x & 0x1)<<6))
		 #define USB_DP_IN()        USB_CON0&BIT(17)          
		 
		 
		 
		 #define LED_INIT_EN()      USB_DP_DIR(0) 		
		 #define LED_INIT_DIS()     USB_DP_DIR(1) 		
		 #define B_LED_ON()         USB_DP_OUT(1);
		 #define B_LED_OFF()        USB_DP_OUT(0); 	
    #elif defined(PP_LED_USER_USBDM) 

           #define USB_DM_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(1)) | ((x & 0x1)<<1))
           #define USB_DM_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(3)) | ((x & 0x1)<<3))
           #define USB_DM_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(5)) | ((x & 0x1)<<5))
           #define USB_DM_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(7)) | ((x & 0x1)<<7))   
           
		 #define LED_INIT_EN()      USB_DM_DIR(0) 		
		 #define LED_INIT_DIS()     USB_DM_DIR(1) 		
		 #define B_LED_ON()         USB_DM_OUT(1);
		 #define B_LED_OFF()        USB_DM_OUT(0); 			 
		 
     #elif defined(PP_LED_USER_PA7_PA8)
              #define LED_BIT               ( BIT(7)|BIT(8))	
              #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
              #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
              #define B_LED_ON()           JL_PORTA->OUT |=BIT(8);
              #define B_LED_OFF()         JL_PORTA->OUT &=~ BIT(8);
              
              #define R_LED_ON()           JL_PORTA->OUT |= BIT(7);
              #define R_LED_OFF()         JL_PORTA->OUT &=~BIT(7);
   #elif defined(PP_LED_USER_PA8_PA7)
              #define LED_BIT               ( BIT(7)|BIT(8))	
              #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
              #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
			  
              #define B_LED_ON()           JL_PORTA->OUT |=BIT(7);
              #define B_LED_OFF()         JL_PORTA->OUT &=~ BIT(7);
              
              #define R_LED_ON()           JL_PORTA->OUT |= BIT(8);
              #define R_LED_OFF()         JL_PORTA->OUT &=~BIT(8);

    #elif defined(PP_LED_USER_PA4_PA5)
              #define LED_BIT               ( BIT(4)|BIT(5))	
              #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
              #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
              #define B_LED_ON()           JL_PORTA->OUT |=BIT(4);
              #define B_LED_OFF()         JL_PORTA->OUT &=~ BIT(4);
              
              #define R_LED_ON()           JL_PORTA->OUT |= BIT(5);
              #define R_LED_OFF()         JL_PORTA->OUT &=~BIT(5);		 
			  
	#elif defined(PP_LED_USER_PA456)
	    #define LED_BIT               ( BIT(4)|BIT(5)|BIT(6))	
         #define LED_INIT_EN()     {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR &= ~LED_BIT;}
         #define LED_INIT_DIS()    {JL_PORTA->PU &= ~LED_BIT;JL_PORTA->PD &= ~LED_BIT;JL_PORTA->DIR |= LED_BIT;}
         #define B_LED_ON()           JL_PORTA->OUT |=BIT(4);
         #define B_LED_OFF()         JL_PORTA->OUT &=~ BIT(4);
		 
         #define M_LED_ON()           JL_PORTA->OUT |= BIT(5);
         #define M_LED_OFF()         JL_PORTA->OUT &=~BIT(5);	
		 
         #define A_LED_ON()           JL_PORTA->OUT |= BIT(6);
         #define A_LED_OFF()         JL_PORTA->OUT &=~BIT(6);			 
		 
       #else 
               #error("请设置	PP 灯IO ")
     #endif 	

	 
#else

    #define LED_INIT_EN()     
    #define LED_INIT_DIS()    
    #define B_LED_ON()          
    #define B_LED_OFF()      
#endif 

   


// mute 

#ifdef PA_ENABLE
      	
        #if defined(pa_mute_use_pin_PA6)                
            #define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(6)	
            #define set_mute_io_high()        JL_PORTA->OUT |= BIT(6)          
            #define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(6) 
	 #elif defined(pa_mute_use_pin_PA4)        
            #define set_mute_io_is_out()       JL_PORTA->DIR &= ~BIT(4)	
            #define set_mute_io_high()      JL_PORTA->OUT |= BIT(4)        
            #define set_mute_io_low()        JL_PORTA->OUT &= ~BIT(4)     
	 #elif defined(pa_mute_use_pin_PA5)        
            #define set_mute_io_is_out()       JL_PORTA->DIR &= ~BIT(5)	
            #define set_mute_io_high()      JL_PORTA->OUT |= BIT(5)        
            #define set_mute_io_low()        JL_PORTA->OUT &= ~BIT(5)     		
	 #elif defined(pa_mute_use_pin_PA3)        
            #define set_mute_io_is_out()       JL_PORTA->DIR &= ~BIT(3)	
            #define set_mute_io_high()      JL_PORTA->OUT |= BIT(3)        
            #define set_mute_io_low()        JL_PORTA->OUT &= ~BIT(3)     
        #elif defined(pa_mute_use_pin_PA7)        
            #define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(7)	
            #define set_mute_io_high()        JL_PORTA->OUT |= BIT(7)          
            #define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(7)     
	 #elif defined(pa_mute_use_pin_PA8)        
            #define set_mute_io_is_out()       JL_PORTA->DIR &= ~BIT(8)	
            #define set_mute_io_high()      JL_PORTA->OUT |= BIT(8)        
            #define set_mute_io_low()        JL_PORTA->OUT &= ~BIT(8)    	
	 #elif defined(pa_mute_use_pin_PA9)        
            #define set_mute_io_is_out()        JL_PORTA->DIR &= ~BIT(9)	
            #define set_mute_io_high()          JL_PORTA->OUT |= BIT(9)        
            #define set_mute_io_low()            JL_PORTA->OUT &= ~BIT(9)    			
        #elif defined(pa_mute_use_pin_PA14)        
            #define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(14)	
            #define set_mute_io_high()        JL_PORTA->OUT |= BIT(14)          
            #define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(14)    
	  #elif defined(pa_mute_use_pin_PA15)        
            #define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(14)	
            #define set_mute_io_high()        JL_PORTA->OUT |= BIT(14)          
            #define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(14)    		
        #elif defined(pa_mute_use_pin_PA11)        
	 #ifdef support_mute_low
	 	#define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(11);  JL_PORTA->DIE |= BIT(11);	
	 	#define set_mute_io_high()        JL_PORTA->OUT |= BIT(11); JL_PORTA->PD &= ~BIT(11)           
	 	#define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(11);JL_PORTA->PD |= BIT(11)     
	 #else
	 	#define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(11)	
		#define set_mute_io_high()        JL_PORTA->OUT |= BIT(11)          
	 	#define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(11)   	
	 #endif
	 
        #elif defined(pa_mute_use_pin_PA10)        
            #define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(10)	
            #define set_mute_io_high()        JL_PORTA->OUT |= BIT(10)          
            #define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(10)     	
	  #elif defined(pa_mute_use_pin_PA0)        
            #define set_mute_io_is_out()      JL_PORTA->DIR &= ~BIT(0)	
            #define set_mute_io_high()        JL_PORTA->OUT |= BIT(0)          
            #define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(0)     			
        #elif defined(pa_mute_use_pin_PB11)
        
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(11)	
            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(11)          
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(11)     
        #elif defined(pa_mute_use_pin_PB13)
#if 1
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(13)	
            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(13)          
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(13)    		
#else
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(13);  JL_PORTB->DIE |= BIT(13);	

            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(13); JL_PORTB->PD &= ~BIT(13)           
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(13);JL_PORTB->PD |= BIT(13)     
#endif
        #elif defined(pa_mute_use_pin_PB1)        
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(1)	
            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(1)          
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(1)   
        #elif defined(pa_mute_use_pin_Pb0)        
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(0)	
            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(0)          
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(0)   

			
	 #elif defined(pa_mute_use_pin_PB2)        
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(2)	
            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(2)          
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(2)  		
	#elif defined(pa_mute_use_pin_PB10PB9)
	     #define set_mute_io_is_out()      JL_PORTB->DIR &= ~(BIT(10)|BIT(9))	 
            #define set_mute_io_high_ab()     JL_PORTB->OUT |= BIT(10);  JL_PORTB->OUT &= ~(BIT(9))		        
             #define set_mute_io_high()	    JL_PORTB->OUT |= BIT(10)|BIT(9)				
            #define set_mute_io_low()         JL_PORTB->OUT &= ~(BIT(10) |BIT(9))			
	 #elif defined(pa_mute_use_pin_PB10)       

             	 #ifdef support_inside_push
                         #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(10);  PORTB_HD|= BIT(10)	
             	 #else 
                         #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(10)	 
             	#endif 		
                         #define set_mute_io_high()        JL_PORTB->OUT |= BIT(10)          
                         #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(10)  	
			
	 #elif defined(pa_mute_use_pin_PB8)        
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(8)	
            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(8)          
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(8)  			
	 #elif defined(pa_mute_use_pin_PB7)        
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(7)	
            #define set_mute_io_high()         JL_PORTB->OUT |= BIT(7)          
            #define set_mute_io_low()          JL_PORTB->OUT &= ~BIT(7)  		
	 #elif defined(pa_mute_use_pin_PB6)        
            #define set_mute_io_is_out()      JL_PORTB->DIR &= ~BIT(6)	
            #define set_mute_io_high()        JL_PORTB->OUT |= BIT(6)          
            #define set_mute_io_low()         JL_PORTB->OUT &= ~BIT(6)  
	   #elif defined(pa_mute_use_pin_PC4)         
                #define  set_mute_io_is_out()        JL_PORTC->DIR &= ~BIT(4)
                #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(4)
                #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(4)  	
	   #elif defined(pa_mute_use_pin_PC5)       
	   
    	    #define MUTE_IO_BIT    5
                #define  set_mute_io_is_out()        JL_PORTC->DIR &= ~BIT(MUTE_IO_BIT)
                #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(MUTE_IO_BIT)
                #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(MUTE_IO_BIT)  
				
         #elif defined(pa_mute_use_pin_PC10)         
                #define  set_mute_io_is_out()        JL_PORTC->DIR &= ~BIT(10)
                #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(10)
                #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(10)  			
         #elif defined(pa_mute_use_pin_PC11)
                  #define  set_mute_io_is_out()    JL_PORTC->DIR &= ~BIT(11)
                 #define  set_mute_io_high()       JL_PORTC->OUT|= BIT(11)
                 #define  set_mute_io_low()        JL_PORTC->OUT &= ~BIT(11)           	
         #elif defined(pa_mute_use_pin_PC12)
            #define  set_mute_io_is_out()       PORTC_DIE |=BIT(12);  JL_PORTC->DIR &= ~BIT(12)
            #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(12)
            #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(12)   
     #elif defined(pa_mute_use_pin_PA11_PA10)        
            #define set_mute_io_is_out()      JL_PORTA->DIR &= ~(BIT(11)|BIT(10))				
            #define set_mute_io_high()        JL_PORTA->OUT |= BIT(10)          
            #define set_mute_io_low()         JL_PORTA->OUT &= ~BIT(10)   
			
            #define  set_amp_d_high()		  JL_PORTA->OUT|= BIT(11)
            #define  set_amp_ab_low()	   JL_PORTA->OUT &= ~BIT(11)   
			
	  #elif defined(pa_mute_use_pin_PC12PC10)
            #define  set_mute_io_is_out()       PORTC_DIE |=BIT(12)|BIT(10);  JL_PORTC->DIR &= ~(BIT(12)|BIT(10))
            #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(12)
            #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(12)   
			
           #define  set_amp_d_high() 		 JL_PORTC->OUT|= BIT(10)
           #define  set_amp_ab_low()		  JL_PORTC->OUT &= ~BIT(10)   

	  #elif defined(pa_mute_use_pin_PC11PA0)
            #define  set_mute_io_is_out()       JL_PORTC->DIE |=BIT(11);  JL_PORTC->DIR &= ~(BIT(11));PORTA_DIE |=BIT(0);  JL_PORTA->DIR &= ~(BIT(0))
            #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(12)
            #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(12)   
			
           #define  set_amp_d_high() 		 JL_PORTA->OUT|= BIT(0)
           #define  set_amp_ab_low()		  JL_PORTA->OUT &= ~BIT(0)   

			
	 #elif defined(pa_mute_use_pin_PC13)
            #define  set_mute_io_is_out()       JL_PORTC->DIE |=BIT(13);  JL_PORTC->DIR &= ~BIT(13)
            #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(13)
            #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(13)   	
	 #elif defined(pa_mute_use_pin_PC14)
            #define  set_mute_io_is_out()       JL_PORTC->DIE |=BIT(14);  JL_PORTC->DIR &= ~BIT(14)
            #define  set_mute_io_high()          JL_PORTC->OUT|= BIT(14)
            #define  set_mute_io_low()            JL_PORTC->OUT &= ~BIT(14)   			
         #elif defined(pa_mute_use_pin_PC15)
            #define  set_mute_io_is_out()      JL_PORTC->DIE |=BIT(15);  JL_PORTC->DIR &= ~BIT(15)
            #define  set_mute_io_high()         JL_PORTC->OUT|= BIT(15)
            #define  set_mute_io_low()        JL_PORTC->OUT &= ~BIT(15)   
         #elif defined(pa_mute_use_pin_PC1)
            #define  set_mute_io_is_out()      JL_PORTC->DIE |=BIT(1);  JL_PORTC->DIR &= ~BIT(1)
            #define  set_mute_io_high()         JL_PORTC->OUT|= BIT(1)
            #define  set_mute_io_low()        JL_PORTC->OUT &= ~BIT(1)   
        	
         #elif defined(pa_mute_use_pin_PC2)
            #define  set_mute_io_is_out()        JL_PORTC->DIR &= ~BIT(2)
            #define  set_mute_io_high()       JL_PORTC->OUT|= BIT(2)
            #define  set_mute_io_low()        JL_PORTC->OUT &= ~BIT(2)   	
	#elif defined(pa_mute_use_pin_PR0)
            #define  set_mute_io_is_out()            PORTR_DIR(PORTR0,0)
            #define  set_mute_io_high()              PORTR_OUT(PORTR0,1)
            #define  set_mute_io_low()                PORTR_OUT(PORTR0,0)  	
	#elif defined(pa_mute_use_pin_USB_DP)

          #define USB_DP_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(0)) | ((x & 0x1)<<0))
          #define USB_DP_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(2)) | ((x & 0x1)<<2))
          #define USB_DP_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(4)) | ((x & 0x1)<<4))
          #define USB_DP_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(6)) | ((x & 0x1)<<6))
          #define USB_DP_IN()        USB_CON0&BIT(17)          
          
          #define  set_mute_io_is_out()    USB_DP_DIR(0)
          #define  set_mute_io_high()       USB_DP_OUT(1)
          #define  set_mute_io_low()        USB_DP_OUT(0) 
		  
    #elif defined(pa_mute_use_pin_USB_DM) 

           #define USB_DM_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(1)) | ((x & 0x1)<<1))
           #define USB_DM_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(3)) | ((x & 0x1)<<3))
           #define USB_DM_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(5)) | ((x & 0x1)<<5))
           #define USB_DM_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(7)) | ((x & 0x1)<<7))   
           
          #define  set_mute_io_is_out()    USB_DM_DIR(0)
          #define  set_mute_io_high()      USB_DM_OUT(1)
          #define  set_mute_io_low()       USB_DM_OUT(0) 	
				
        #elif defined(supper_two_pin_mute_pa7_pa6)
        //defined(pa_mute_use_pin_PC11)

        #else  // nop 
        
            #define  set_mute_io_is_out()      
            #define  set_mute_io_high()     
            #define  set_mute_io_low()    
        
          //      #error(" 请设置 检测mute IO ") 
        #endif 
#endif 


//功放静音
#ifdef support_power_on_mute
#ifdef power_on__mute_use_pin_PA11
#define set_power_on_mute_io_is_out()	  	JL_PORTA->DIR &= ~BIT(11) 
#define set_power_on_mute_io_high()		JL_PORTA->OUT |= BIT(11)			
#define set_power_on_mute_io_low()		JL_PORTA->OUT &= ~BIT(11) 	
#endif
#endif










// 手电筒

#ifdef support_led_LIGHT_MODE
      #if defined(support_led_eq_user_PA9)
                 #define  set_led_light_io_is_out()        JL_PORTA->DIR &= ~(BIT(9))      	                                         
                 #define  set_led_light_io_off()              JL_PORTA->OUT  &= ~(BIT(9))           		                                                 
                 #define    Set_led_light_io_is_on()        JL_PORTA->OUT|= BIT(9) 
	#elif defined(support_led_eq_user_PC13)
               #define  set_led_light_io_is_out()        PORTC_DIE |=BIT(13);  JL_PORTC->DIR &= ~(BIT(13))      	                                         
               #define  set_led_light_io_off()              JL_PORTC->OUT  &= ~(BIT(13))           		                                                 
               #define    Set_led_light_io_is_on()        JL_PORTC->OUT|= BIT(13) 
	#elif defined(support_led_eq_user_PC11)
               #define  set_led_light_io_is_out()        PORTC_DIE |=BIT(11);  JL_PORTC->DIR &= ~(BIT(11))      	                                         
               #define  set_led_light_io_off()              JL_PORTC->OUT  &= ~(BIT(11))           		                                                 
               #define    Set_led_light_io_is_on()        JL_PORTC->OUT|= BIT(11) 		   
	 #elif defined(support_led_eq_user_PB9)
                 #define  set_led_light_io_is_out()        JL_PORTB->DIR &= ~(BIT(9))      	                                         
                 #define  set_led_light_io_off()              JL_PORTB->OUT  &= ~(BIT(9))           		                                                 
                 #define    Set_led_light_io_is_on()       JL_PORTB->OUT|= BIT(9) 	
	  #elif defined(support_led_eq_user_PB6)
	            #define  set_led_light_io_is_out()        JL_PORTB->DIR &= ~(BIT(6))      	                                         
	            #define  set_led_light_io_off()              JL_PORTB->OUT  &= ~(BIT(6))           		                                                 
	            #define    Set_led_light_io_is_on()          JL_PORTB->OUT|= BIT(6) 				 
	  #elif defined(support_led_eq_user_PB7)
	            #define  set_led_light_io_is_out()        JL_PORTB->DIR &= ~(BIT(7))      	                                         
	            #define  set_led_light_io_off()              JL_PORTB->OUT  &= ~(BIT(7))           		                                                 
	            #define    Set_led_light_io_is_on()          JL_PORTB->OUT|= BIT(7) 	
	 #elif defined(support_led_eq_user_PA4)
                 #define  set_led_light_io_is_out()        JL_PORTA->DIR &= ~(BIT(4))      	                                         
                 #define  set_led_light_io_off()              JL_PORTA->OUT  &= ~(BIT(4))           		                                                 
                 #define    Set_led_light_io_is_on()       JL_PORTA->OUT|= BIT(4) 			
	 #elif defined(support_led_eq_user_PA6)
                 #define  set_led_light_io_is_out()        JL_PORTA->DIR &= ~(BIT(6))      	                                         
                 #define  set_led_light_io_off()              JL_PORTA->OUT  &= ~(BIT(6))           		                                                 
                 #define    Set_led_light_io_is_on()       JL_PORTA->OUT|= BIT(6) 	
	 #elif defined(support_led_eq_user_PA7)
                 #define  set_led_light_io_is_out()        JL_PORTA->DIR &= ~(BIT(7))      	                                         
                 #define  set_led_light_io_off()              JL_PORTA->OUT  &= ~(BIT(7))           		                                                 
                 #define    Set_led_light_io_is_on()       JL_PORTA->OUT|= BIT(7) 	
				 
	 #elif defined(support_led_eq_user_PA15)
                 #define  set_led_light_io_is_out()        JL_PORTA->DIR &= ~(BIT(15))      	                                         
                 #define  set_led_light_io_off()              JL_PORTA->OUT  &= ~(BIT(15))           		                                                 
                 #define    Set_led_light_io_is_on()       JL_PORTA->OUT|= BIT(15) 				 
	 #elif defined(support_led_eq_user_PB8)
                 #define  set_led_light_io_is_out()        JL_PORTB->DIR &= ~(BIT(8))      	
		#ifdef support_led_is_low_on
	                 #define  set_led_light_io_off()            	 JL_PORTB->OUT|= BIT(8) 			                                                 
	                 #define    Set_led_light_io_is_on()       JL_PORTB->OUT  &= ~(BIT(8))           
		#else 
	                 #define  set_led_light_io_off()              JL_PORTB->OUT  &= ~(BIT(8))           		                                                 
	                 #define    Set_led_light_io_is_on()        JL_PORTB->OUT|= BIT(8) 		
		#endif 		
	 #elif defined(support_led_eq_user_PB10)
                 #define  set_led_light_io_is_out()        JL_PORTB->DIR &= ~(BIT(10))      	
		#ifdef support_led_is_low_on
	                 #define  set_led_light_io_off()            	 JL_PORTB->OUT|= BIT(10) 			                                                 
	                 #define    Set_led_light_io_is_on()       JL_PORTB->OUT  &= ~(BIT(10))           
		#else 
	                 #define  set_led_light_io_off()              JL_PORTB->OUT  &= ~(BIT(10))           		                                                 
	                 #define    Set_led_light_io_is_on()        JL_PORTB->OUT|= BIT(10) 		
	#endif 	
      #else 
               #error(" 请设置 手电筒控制IO ") 
      
      #endif 
#endif 


// 频谱显示
#ifdef  support_led_eq_disp    //支持发光管频谱显示
   #ifdef  support_led_eq_user_PA15PB6PB7PB8PB9PB10
             #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10));\
              		                                               JL_PORTB->PU |= BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10);\
              		                                               JL_PORTA->DIR &= ~(BIT(15));\
              		                                               JL_PORTA->PU |= BIT(15)
             
             #define  set_all_led_io_off()          JL_PORTB->OUT  &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) ;\
             		                                                     JL_PORTA->OUT&= ~(BIT(15));  

     #ifdef support_rdt_2536_mode
                   #define    Set_6_led_io_is_on()                  JL_PORTA->OUT|= BIT(15) 
                  #define    Set_5_led_io_is_on()           	  JL_PORTB->OUT|= BIT(6) 
                  #define    Set_4_led_io_is_on()           	  JL_PORTB->OUT|= BIT(7) 
                  #define    Set_3_led_io_is_on()                 JL_PORTB->OUT|= BIT(8)       
                  #define    Set_2_led_io_is_on()     	         JL_PORTB->OUT|= BIT(9)          
                  #define    Set_1_led_io_is_on()                 JL_PORTB->OUT|= BIT(10) 	
     #else                  
                  #define    Set_1_led_io_is_on()                  JL_PORTA->OUT|= BIT(15) 
                  #define    Set_6_led_io_is_on()           	  JL_PORTB->OUT|= BIT(6) 
                  #define    Set_5_led_io_is_on()           	  JL_PORTB->OUT|= BIT(7) 
                  #define    Set_4_led_io_is_on()                 JL_PORTB->OUT|= BIT(8)       
                  #define    Set_3_led_io_is_on()     	         JL_PORTB->OUT|= BIT(9)          
                  #define    Set_2_led_io_is_on()                 JL_PORTB->OUT|= BIT(10) 	
     #endif 	

#elif defined(support_led_eq_user_PA14DPPC15)


#define USB_DP_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(0)) | ((x & 0x1)<<0))
#define USB_DP_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(2)) | ((x & 0x1)<<2))
#define USB_DP_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(4)) | ((x & 0x1)<<4))
#define USB_DP_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(6)) | ((x & 0x1)<<6))





             #define  set_all_led_io_is_out()       PORTC_DIE |=BIT(15);  JL_PORTC->DIR &= ~BIT(15);\
                                                                            JL_PORTA->DIR &= ~(BIT(14));\
			                                                      USB_DP_DIR(0)
              		                       
 
 
              		                                              
             
             #define  set_all_led_io_off()          JL_PORTC->OUT&= ~BIT(15); USB_DP_OUT(0) ;JL_PORTA->OUT&= ~BIT(14) 
             		                                                    

           #define    Set_3_led_io_is_on()                 JL_PORTC->OUT|= BIT(15)
           #define    Set_2_led_io_is_on()     	      USB_DP_OUT(1)      
           #define    Set_1_led_io_is_on()                 JL_PORTA->OUT |= BIT(14) 
			 
#elif defined(support_led_eq_user_PC10PC11PB6PB7PB8PA5)
          #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(5));\
                                                                        JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8));\
                                                                        JL_PORTC->DIR &= ~(BIT(10)|BIT(11))                          
          		                                             
     		                                             
          #define  set_all_led_io_off()          JL_PORTA->OUT  |= (BIT(5)) ;\
                                                                       JL_PORTB->OUT  |= (BIT(7)|BIT(8)|BIT(6)) ; \
                                                                       JL_PORTC->OUT |= (BIT(10)|BIT(11))
                    
          #define    Set_1_led_io_is_on()            JL_PORTC->OUT &= ~BIT(10);   
          #define    Set_2_led_io_is_on()             JL_PORTC->OUT &= ~BIT(11);      
          #define    Set_3_led_io_is_on()     	 JL_PORTB->OUT &= ~BIT(8); 
          #define    Set_4_led_io_is_on()             JL_PORTB->OUT &= ~BIT(7);   
          #define    Set_5_led_io_is_on()             JL_PORTB->OUT &= ~BIT(6);    
          #define    Set_6_led_io_is_on()             JL_PORTA->OUT &= ~BIT(5);  
          
#elif defined(support_led_eq_user_PA1PA2)
#define  set_all_led_io_is_out()     PORTA_DIE |=(BIT(1)|BIT(2));JL_PORTA->DIR &= ~(BIT(1)|BIT(2))                                      
#define  set_all_led_io_off()              JL_PORTA->OUT  |= (BIT(1)|BIT(2)) 
#define    Set_1_led_io_is_on()             JL_PORTA->OUT &= ~BIT(1)   
#define    Set_2_led_io_is_on()             JL_PORTA->OUT &= ~BIT(2)

#elif defined(support_led_eq_user_PB6PB8PB9PB10PC15)

#define  set_all_led_io_is_out()          JL_PORTB->DIR &= ~(BIT(6)|BIT(8)|BIT(9)|BIT(10));\
	                                                     PORTB_HD  |= (BIT(6)|BIT(8)|BIT(9)|BIT(10)); \
                                                           JL_PORTC->DIR &= ~BIT(15); PORTC_DIE |=BIT(15);  PORTC_HD |= BIT(15)              
		                                             

#define  set_all_led_io_off()               JL_PORTB->OUT  &= ~(BIT(6)|BIT(8)|BIT(9)|BIT(10)) ; \
                                                             JL_PORTC->OUT  &= ~(BIT(15))


#define    Set_1_led_io_is_on()             JL_PORTC->OUT|= BIT(15)   
#define    Set_2_led_io_is_on()            JL_PORTB->OUT |= BIT(10)
#define    Set_3_led_io_is_on()     	      JL_PORTB->OUT  |=BIT(9)
#define    Set_4_led_io_is_on()            JL_PORTB->OUT |= BIT(8) 
#define    Set_5_led_io_is_on()            JL_PORTB->OUT |= BIT(6)

#elif defined(support_led_eq_user_PB8PB7PB9PB10)

#define  set_all_led_io_is_out()          JL_PORTB->DIR &= ~(BIT(7)|BIT(8)|BIT(9)|BIT(10));\
	                                                     PORTB_HD  |= (BIT(7)|BIT(8)|BIT(9)|BIT(10)); \
                                                          
		                                             

#define  set_all_led_io_off()               JL_PORTB->OUT  &= ~(BIT(7)|BIT(8)|BIT(9)|BIT(10)) ; \
                                                            


#define    Set_1_led_io_is_on()            JL_PORTB->OUT |= BIT(8)
#define    Set_2_led_io_is_on()     	      JL_PORTB->OUT  |=BIT(7)
#define    Set_3_led_io_is_on()            JL_PORTB->OUT |= BIT(9) 
#define    Set_4_led_io_is_on()            JL_PORTB->OUT |= BIT(10)


#elif defined(support_led_eq_user_PB6PB7PB8PB9PB10PA4PC10)

#define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(4));\
                                                              JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10));\
                                                              PORTB_HD  |= BIT(6);   JL_PORTC->DIR &= ~(BIT(10))                           
		                                             
		                                   

#define  set_all_led_io_off()          JL_PORTA->OUT  |= (BIT(4)) ;\
                                                             JL_PORTB->OUT  |= (BIT(7)|BIT(8)|BIT(9)|BIT(10)) ; \
                                                             JL_PORTC->OUT |= (BIT(10))


#define    Set_1_led_io_is_on()             JL_PORTA->OUT &= ~BIT(4);         
#define    Set_2_led_io_is_on()             JL_PORTC->OUT &= ~BIT(10); 
#define    Set_3_led_io_is_on()     	      JL_PORTB->OUT &= ~BIT(10); 
#define    Set_4_led_io_is_on()             JL_PORTB->OUT &= ~BIT(9);   
#define    Set_5_led_io_is_on()             JL_PORTB->OUT &= ~BIT(8);    
#define    Set_6_led_io_is_on()             JL_PORTB->OUT &= ~BIT(7);  

#define    Set_7_led_io_is_on()     	      JL_PORTB->OUT|= BIT(6);  

#elif defined(support_led_eq_user_B7PB8PB9PB10_PA4TOPA6_PC10)
             #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(7)|BIT(8)|BIT(9)|BIT(10));\
              		                                               PORTB_HD |= BIT(7)|BIT(8)|BIT(9)|BIT(10);\
              		                                               JL_PORTA->DIR &= ~(BIT(4)|BIT(5)|BIT(6));\
              		                                               PORTA_HD |= BIT(4)|BIT(5)|BIT(6);\
              		                                               JL_PORTC->DIR &= ~(BIT(10));\
              		                                               PORTC_HD |= BIT(10)
             
             #define  set_all_led_io_off()          JL_PORTB->OUT  &= ~(BIT(7)|BIT(8)|BIT(9)|BIT(10)) ;\
			 	                                              JL_PORTA->OUT  &= ~(BIT(4)|BIT(5)|BIT(6)) ;\
             		                                                     JL_PORTC->OUT&= ~(BIT(10));  

          #define    Set_1_led_io_is_on()           	        JL_PORTC->OUT|= BIT(10); JL_PORTB->OUT|= BIT(10)
          #define    Set_2_led_io_is_on()                    JL_PORTA->OUT|= BIT(4);  JL_PORTB->OUT|= BIT(9)   
          #define    Set_3_led_io_is_on()     	        JL_PORTA->OUT|= BIT(5);   JL_PORTB->OUT|= BIT(8)       
          #define    Set_4_led_io_is_on()                    JL_PORTA->OUT|= BIT(6) ;	 JL_PORTB->OUT|= BIT(7) 
			 
			 
 #elif defined(support_led_eq_user_PA9PA10PA11PA14PA15)
	  #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15));\
              		                                           JL_PORTA->PU |= BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15);\
     
             
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)) ;\
             		                                                 

          #define    Set_1_led_io_is_on()           	 JL_PORTA->OUT|= BIT(9) 
          #define    Set_2_led_io_is_on()                  JL_PORTA->OUT|= BIT(10)       
          #define    Set_3_led_io_is_on()     	        JL_PORTA->OUT|= BIT(11)          
          #define    Set_4_led_io_is_on()                  JL_PORTA->OUT|= BIT(14) 	
	   #define    Set_5_led_io_is_on()                  JL_PORTA->OUT|= BIT(15) 	
	  
    #elif defined(support_led_eq_user_PA8PA9PA10PA11PA14PA15)
	  #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15))
              		                                       
     
             
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)) ;\
             		                                                 

          #define    Set_1_led_io_is_on()                    JL_PORTA->OUT|= BIT(8) 	
          #define    Set_2_led_io_is_on()           	        JL_PORTA->OUT|= BIT(9) 
          #define    Set_3_led_io_is_on()                    JL_PORTA->OUT|= BIT(10)       
          #define    Set_4_led_io_is_on()     	         JL_PORTA->OUT|= BIT(11)          
          #define    Set_5_led_io_is_on()                    JL_PORTA->OUT|= BIT(14) 	
	   #define    Set_6_led_io_is_on()                    JL_PORTA->OUT|= BIT(15) 	
    #elif defined(support_led_eq_user_PA8PA9PA10PA11PA14)
	  #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14))           		                                       
          
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)) 
             		                                                 

          #define    Set_1_led_io_is_on()                    JL_PORTA->OUT|= BIT(8) 	
          #define    Set_2_led_io_is_on()           	        JL_PORTA->OUT|= BIT(9) 
          #define    Set_3_led_io_is_on()                    JL_PORTA->OUT|= BIT(10)       
          #define    Set_4_led_io_is_on()     	         JL_PORTA->OUT|= BIT(11)          
          #define    Set_5_led_io_is_on()                    JL_PORTA->OUT|= BIT(14) 	
    #elif defined(support_led_eq_user_PA6PA7PA8PA9)
	  #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9))     		                                         
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9))              		                                                 
           #define    Set_4_led_io_is_on()           	    JL_PORTA->OUT|= BIT(6) 
           #define    Set_3_led_io_is_on()                     JL_PORTA->OUT|= BIT(7)       
           #define    Set_2_led_io_is_on()     	           JL_PORTA->OUT|= BIT(8)          
           #define    Set_1_led_io_is_on()                     JL_PORTA->OUT|= BIT(9) 	
   

    #elif defined(support_led_eq_user_PA9PA10PA11PA14)
	  #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(9)|BIT(10)|BIT(11)|BIT(14));\
              		                                           JL_PORTA->PU |= BIT(9)|BIT(10)|BIT(11)|BIT(14);\
     
             
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(9)|BIT(10)|BIT(11)|BIT(14)) ;\
             		                                                 
         #ifdef support_zht_z179_mode
                   #define    Set_4_led_io_is_on()           	        JL_PORTA->OUT|= BIT(9) 
                   #define    Set_3_led_io_is_on()                    JL_PORTA->OUT|= BIT(10)       
                   #define    Set_2_led_io_is_on()     	         JL_PORTA->OUT|= BIT(11)          
                   #define    Set_1_led_io_is_on()                    JL_PORTA->OUT|= BIT(14) 
         #else 
                   #define    Set_1_led_io_is_on()           	        JL_PORTA->OUT|= BIT(9) 
                   #define    Set_2_led_io_is_on()                    JL_PORTA->OUT|= BIT(10)       
                   #define    Set_3_led_io_is_on()     	         JL_PORTA->OUT|= BIT(11)          
                   #define    Set_4_led_io_is_on()                    JL_PORTA->OUT|= BIT(14) 	
         #endif 	
#elif defined(support_led_eq_user_PA6__PA15)	

              #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15));\
                                                                            PORTA_HD|=(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15))              		                                   
                                        
              
              #define  set_all_led_io_off()          JL_PORTA->OUT  |= (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)) ;\
              
              
              #define    Set_4_led_io_is_on()             JL_PORTA->OUT &= ~BIT(7); 
              #define    Set_3_led_io_is_on()             JL_PORTA->OUT &= ~BIT(9);  
              #define    Set_2_led_io_is_on()     	     JL_PORTA->OUT &= ~BIT(11);     
              #define    Set_1_led_io_is_on()             JL_PORTA->OUT &= ~BIT(15);   
              #define    Set_8_led_io_is_on()             JL_PORTA->OUT &= ~BIT(14);  
              #define    Set_7_led_io_is_on()             JL_PORTA->OUT &= ~BIT(10);  
              #define    Set_6_led_io_is_on()     	      JL_PORTA->OUT &= ~BIT(8);  
              #define    Set_5_led_io_is_on()             JL_PORTA->OUT &= ~BIT(6);      
#elif defined( support_led_eq_user_PB10pb9pb8pa10pa8)
 #define  set_all_led_io_is_out()		  JL_PORTB->DIR &= ~(BIT(10)|BIT(9)|BIT(8)); \
								         PORTB_HD |= BIT(10)|BIT(9)|BIT(8);\														
									  PORTC_DIE |=BIT(10);	JL_PORTC->DIR &= ~BIT(10);	 PORTC_HD |= BIT(10);\			  
                                                                JL_PORTA->DIR &= ~(BIT(8));     PORTA_HD |= BIT(8)
                                                                
   #define	set_all_led_io_off()		  JL_PORTB->OUT  &= ~(BIT(10)|BIT(9)|BIT(8)) ;	JL_PORTC->OUT &= ~BIT(10)  ;JL_PORTA->OUT &= ~BIT(4)  
	   
#define    Set_1_led_io_is_on() 		 JL_PORTB->OUT|= BIT(10) 
#define    Set_2_led_io_is_on() 		 JL_PORTB->OUT|= BIT(9) 	 
#define    Set_3_led_io_is_on() 		 JL_PORTB->OUT|= BIT(8) 		
#define    Set_4_led_io_is_on() 		 JL_PORTC->OUT|= BIT(10)	  
#define    Set_5_led_io_is_on() 		 JL_PORTA->OUT|= BIT(8)	  

#elif defined( support_led_eq_user_PB7pb8pb9pa10pa6)
 #define  set_all_led_io_is_out()		  JL_PORTB->DIR &= ~(BIT(10)|BIT(9)|BIT(8)|BIT(7)); \
								         PORTB_HD |= BIT(10)|BIT(9)|BIT(8)|BIT(7);\														
                                                                JL_PORTA->DIR &= ~(BIT(6));     PORTA_HD |= BIT(6)
                                                                
   #define	set_all_led_io_off()		  JL_PORTB->OUT  &= ~(BIT(10)|BIT(9)|BIT(8)|BIT(7)) ;	JL_PORTA->OUT &= ~BIT(6)  
	   
#define    Set_1_led_io_is_on() 		 JL_PORTB->OUT|= BIT(10) 
#define    Set_2_led_io_is_on() 		 JL_PORTB->OUT|= BIT(9) 	 
#define    Set_3_led_io_is_on() 		 JL_PORTB->OUT|= BIT(7) 		
#define    Set_4_led_io_is_on() 		 JL_PORTB->OUT|= BIT(8)	  
#define    Set_5_led_io_is_on() 		 JL_PORTA->OUT|= BIT(6)	  

#elif defined( support_led_eq_user_PB10pb9pb8pc15)

     #define  set_all_led_io_is_out()	      JL_PORTB->DIR &= ~(BIT(10)|BIT(9)|BIT(8)); \
								      PORTB_HD |= BIT(10)|BIT(9)|BIT(8);\													    
                                                   	      PORTC_DIE |=BIT(15);  JL_PORTC->DIR &= ~BIT(15);   PORTC_HD |= BIT(15)


       #define	set_all_led_io_off()		  JL_PORTB->OUT  &= ~(BIT(10)|BIT(9)|BIT(8)) ;  JL_PORTC->OUT &= ~BIT(15)  
     	   
   	#define    Set_1_led_io_is_on() 		 JL_PORTB->OUT|= BIT(10) 
	#define    Set_2_led_io_is_on() 		 JL_PORTB->OUT|= BIT(9)		 
	#define    Set_3_led_io_is_on() 		 JL_PORTB->OUT|= BIT(8)			
	#define    Set_4_led_io_is_on() 		 JL_PORTC->OUT|= BIT(15)	  



#elif defined(support_led_eq_user_PB6PB7PB8PB9PB10_PA4TOPAPA5_PC10)

#define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15));\
	                                                JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10));\
	                                                JL_PORTC->DIR &= ~(BIT(10))
		                                   


#define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)); \
                                                            JL_PORTB->OUT  &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)); \
                                                            JL_PORTC->OUT &= ~(BIT(10))


#define    Set_1_led_io_is_on()            JL_PORTB->OUT|= BIT(10);  JL_PORTC->OUT|= BIT(10);
#define    Set_2_led_io_is_on()            JL_PORTB->OUT|= BIT(9);   JL_PORTA->OUT|= BIT(4);         
#define    Set_3_led_io_is_on()     	    JL_PORTB->OUT|= BIT(8);  JL_PORTA->OUT|= BIT(5);              
#define    Set_4_led_io_is_on()             JL_PORTB->OUT|= BIT(7);   JL_PORTA->OUT|= BIT(6); 
#define    Set_5_led_io_is_on()             JL_PORTB->OUT|= BIT(6);  JL_PORTA->OUT|= BIT(7);   
#define    Set_6_led_io_is_on()             JL_PORTA->OUT|= BIT(15);  JL_PORTA->OUT|= BIT(8);     
#define    Set_7_led_io_is_on()     	      JL_PORTA->OUT|= BIT(14);  JL_PORTA->OUT|= BIT(9);         
#define    Set_8_led_io_is_on()             JL_PORTA->OUT|= BIT(11);  JL_PORTA->OUT|= BIT(10);        

#elif defined(support_led_eq_user_PB6PB7PB8PB9P_PA4TOPAPA15_PC10)
#define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)); \
													JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9));\
													JL_PORTC->DIR &= ~(BIT(10))		                                  


#define  set_all_led_io_off()          JL_PORTA->OUT  &=  ~(BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)); \
                                                            JL_PORTB->OUT   &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)); \
                                                            JL_PORTC->OUT  &= ~(BIT(10))


#define    Set_5_G_led_io_is_on()            JL_PORTA->OUT |= BIT(10) 
#define    Set_5_R_led_io_is_on()            JL_PORTA->OUT |= BIT(11) 
#define    Set_5_B_led_io_is_on()            JL_PORTA->OUT |= BIT(14) 

#define    Set_4_G_led_io_is_on()            JL_PORTA->OUT |= BIT(15) 
#define    Set_4_R_led_io_is_on()            JL_PORTB->OUT |= BIT(6) 
#define    Set_4_B_led_io_is_on()            JL_PORTB->OUT |= BIT(7) 

#define    Set_3_G_led_io_is_on()            JL_PORTB->OUT |= BIT(8) 
#define    Set_3_R_led_io_is_on()            JL_PORTB->OUT |= BIT(9) 
#define    Set_3_B_led_io_is_on()            JL_PORTC->OUT |= BIT(10) 

#define    Set_2_G_led_io_is_on()            JL_PORTA->OUT |= BIT(4) 
#define    Set_2_R_led_io_is_on()            JL_PORTA->OUT |= BIT(5) 
#define    Set_2_B_led_io_is_on()            JL_PORTA->OUT |= BIT(6) 

#define    Set_1_G_led_io_is_on()            JL_PORTA->OUT |= BIT(7) 
#define    Set_1_R_led_io_is_on()            JL_PORTA->OUT |= BIT(8) 
#define    Set_1_B_led_io_is_on()            JL_PORTA->OUT |= BIT(9) 


#elif defined(support_led_eq_user_PA14PA15PC0PC1PC2)
	  #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(15)|BIT(14)); \
              		                                     JL_PORTA->PU |= BIT(15)|BIT(14);\
              		                                     JL_PORTC->DIR &= ~(BIT(0)|BIT(1)|BIT(2)); \
              		                                     JL_PORTC->PU |= BIT(0)|BIT(1)|BIT(2)
     
             
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(15)|BIT(14)); JL_PORTC->OUT  &= ~(BIT(0)|BIT(1)|BIT(2));\
             		                                                 

           #define    Set_1_led_io_is_on()          JL_PORTC->OUT|= BIT(0)       
           #define    Set_2_led_io_is_on()     	 JL_PORTA->OUT|= BIT(14)          
           #define    Set_3_led_io_is_on()            JL_PORTA->OUT|= BIT(15) 	
           #define    Set_4_led_io_is_on() 		 JL_PORTC->OUT|= BIT(1)		
           #define    Set_5_led_io_is_on() 		 JL_PORTC->OUT|= BIT(2)	

#elif defined(support_led_eq_user_PA15PA14PA11PA10)
	  #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(15)|BIT(14)|BIT(11)|BIT(10)); \
              		                                           JL_PORTA->PU |= BIT(15)|BIT(14)|BIT(11)|BIT(10);\
     
             
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(15)|BIT(14)|BIT(11)|BIT(10)) ; \
             		                                                 

          #define    Set_4_led_io_is_on()           	  JL_PORTA->OUT|= BIT(10) 
          #define    Set_1_led_io_is_on()                    JL_PORTA->OUT|= BIT(11)       
          #define    Set_2_led_io_is_on()     	         JL_PORTA->OUT|= BIT(15)          
          #define    Set_3_led_io_is_on()                    JL_PORTA->OUT|= BIT(14) 	

#elif defined(support_led_eq_user_PA4PA5PA6PA8)
	  #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(6)|BIT(7)); \
	  										JL_PORTA->DIR &= ~(BIT(5)|BIT(6))
								           
								                               
         #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(5)|BIT(6));   JL_PORTB->OUT  &= ~(BIT(6)|BIT(7)) ;             		                                                 

          #define    Set_1_led_io_is_on()         JL_PORTB->OUT|= BIT(7) 
          #define    Set_2_led_io_is_on()         JL_PORTB->OUT|= BIT(6)       
          #define    Set_3_led_io_is_on()     	  JL_PORTA->OUT|= BIT(5)          
          #define    Set_4_led_io_is_on()         JL_PORTA->OUT|= BIT(6) 

#elif defined(support_led_eq_user_PA6PA7PA8)
     #define  set_all_led_io_is_out()	 JL_PORTA->DIR &= ~(BIT(6)|BIT(7)|BIT(8))								 
      
      #define   set_all_led_io_off()		   JL_PORTA->OUT  &= ~(BIT(6)|BIT(7)|BIT(8))
      #define   Set_1_led_io_is_on() 	   JL_PORTA->OUT|= BIT(6) 
      #define   Set_2_led_io_is_on() 	   JL_PORTA->OUT|= BIT(7) 
      #define   Set_3_led_io_is_on() 	   JL_PORTA->OUT|= BIT(8) 
  

#elif defined(support_led_eq_user_PB6PB7)
             #define  set_all_led_io_is_out()	        JL_PORTB->DIR &= ~(BIT(6)|BIT(7)) 												  
             
             #define	set_all_led_io_off()		JL_PORTB->OUT  &= ~(BIT(6)|BIT(7)) ;   														   
             
             #define    Set_2_led_io_is_on() 		  JL_PORTB->OUT|= BIT(6)		   
             #define    Set_1_led_io_is_on() 		   JL_PORTB->OUT|= BIT(7) 

#elif defined(support_led_eq_user_PB7)	
        #define   set_all_led_io_is_out()		   JL_PORTB->DIR &= ~(BIT(7))												 
        #define    set_all_led_io_off() 	          JL_PORTB->OUT  &= ~(BIT(7)) 				  
        #define    Set_1_led_io_is_on() 		    JL_PORTB->OUT|= BIT(7) 

#elif defined( support_led_eq_user_PB6PB7PB8PB9PB10PA15)
             #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)); \
              		                                               JL_PORTB->PU |= BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10); \
              		                                               JL_PORTA->DIR &= ~(BIT(15));\
              		                                               JL_PORTA->PU |= BIT(15)

             
             #define  set_all_led_io_off()          JL_PORTB->OUT  &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)); \
			 	                                               JL_PORTA->OUT  &= ~BIT(15)
			 
             #define    Set_1_led_io_is_on()           	  JL_PORTA->OUT|= BIT(15) 
             #define    Set_2_led_io_is_on()           	  JL_PORTB->OUT|= BIT(6) 
             #define    Set_3_led_io_is_on()           	  JL_PORTB->OUT|= BIT(7) 
             #define    Set_4_led_io_is_on()                 JL_PORTB->OUT|= BIT(8)       
             #define    Set_5_led_io_is_on()     	         JL_PORTB->OUT|= BIT(9)          
             #define    Set_6_led_io_is_on()                 JL_PORTB->OUT|= BIT(10) 	

    #elif defined(support_led_eq_user_PA6PA7PA8PA9PA10PA11)			 
             #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11))           		                                          
            
             #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11))
			 
             #define    Set_1_led_io_is_on()           	  JL_PORTA->OUT|= BIT(6) 
             #define    Set_2_led_io_is_on()           	  JL_PORTA->OUT|= BIT(7) 
             #define    Set_3_led_io_is_on()           	  JL_PORTA->OUT|= BIT(8) 
             #define    Set_4_led_io_is_on()                 JL_PORTA->OUT|= BIT(9)       
             #define    Set_5_led_io_is_on()     	         JL_PORTA->OUT|= BIT(10)          
             #define    Set_6_led_io_is_on()                 JL_PORTA->OUT|= BIT(11) 	
#elif defined(support_led_eq_user_PA4PB8PB9PB10PC10)
      #define  set_all_led_io_is_out()	JL_PORTA->DIR &= ~BIT(4);  JL_PORTB->DIR &= ~(BIT(8)|BIT(9)|BIT(10)); 	JL_PORTC->DIR &= ~BIT(10);\	
		                                                  PORTA_HD |=  BIT(4);    PORTB_HD |= (BIT(8)|BIT(9)|BIT(10));   PORTC_HD |= BIT(10);

                           
      #define  set_all_led_io_off()		JL_PORTA->OUT&= ~BIT(4);  JL_PORTB->OUT&= ~(BIT(8)|BIT(9)|BIT(10)); 	JL_PORTC->OUT &= ~BIT(10)
         
      #define    Set_1_led_io_is_on() 			 JL_PORTA->OUT|= BIT(4) 
      #define    Set_2_led_io_is_on() 			 JL_PORTB->OUT|= BIT(8) 
      #define    Set_3_led_io_is_on() 			 JL_PORTB->OUT|= BIT(9) 
      #define    Set_4_led_io_is_on() 			 JL_PORTB->OUT|= BIT(10)		 
      #define    Set_5_led_io_is_on() 			JL_PORTC->OUT|= BIT(10) 		 


   #elif defined(support_led_eq_user_PB6PB7PB8PB9PB10)
	#ifdef support_led_low_light
	       #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10));\
		                                                         	JL_PORTB->PU |= BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)
              		                                             

             #define  set_all_led_io_off()          JL_PORTB->OUT  |= (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10))              
             
             #define    Set_1_led_io_is_on()           	  JL_PORTB->OUT &= ~BIT(6) 
             #define    Set_2_led_io_is_on()           	  JL_PORTB->OUT &= ~BIT(7) 
             #define    Set_3_led_io_is_on()                 JL_PORTB->OUT &= ~BIT(8)       
             #define    Set_4_led_io_is_on()     	         JL_PORTB->OUT &= ~BIT(9)          
             #define    Set_5_led_io_is_on()                 JL_PORTB->OUT &= ~BIT(10) 	
	#else 
	       #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)); \
              		                                               JL_PORTB->PU |= BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)

             #define  set_all_led_io_off()          JL_PORTB->OUT  &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10))              
             
             #define    Set_5_led_io_is_on()           	  JL_PORTB->OUT|= BIT(6) 
             #define    Set_4_led_io_is_on()           	  JL_PORTB->OUT|= BIT(7) 
             #define    Set_3_led_io_is_on()                 JL_PORTB->OUT|= BIT(8)       
             #define    Set_2_led_io_is_on()     	         JL_PORTB->OUT|= BIT(9)          
             #define    Set_1_led_io_is_on()                 JL_PORTB->OUT|= BIT(10) 	
	#endif 	
#elif defined(support_led_eq_user_PB6PB7PB8)
             #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(7)|BIT(8)|BIT(6)); \
              		                                               JL_PORTB->PU |= BIT(6)|BIT(7)|BIT(8)
             
             #define  set_all_led_io_off()          JL_PORTB->OUT  &= ~(BIT(7)|BIT(8)|BIT(6))              
             
             #define    Set_1_led_io_is_on()                 JL_PORTB->OUT|= BIT(6)       
             #define    Set_2_led_io_is_on()     	         JL_PORTB->OUT|= BIT(7)          
             #define    Set_3_led_io_is_on()                 JL_PORTB->OUT|= BIT(8) 	

#elif defined(support_led_eq_user_PA11PA14PA15)
             #define  set_all_led_io_is_out()       JL_PORTA->DIR &= ~(BIT(11)|BIT(14)|BIT(15)); \
              		                                           JL_PORTA->PU |= BIT(11)|BIT(14)|BIT(15)
             
             #define  set_all_led_io_off()              JL_PORTA->OUT  &= ~(BIT(11)|BIT(14)|BIT(15))              
             
             #define    Set_1_led_io_is_on()         JL_PORTA->OUT|= BIT(11)       
             #define    Set_2_led_io_is_on()     	  JL_PORTA->OUT|= BIT(15)          
             #define    Set_3_led_io_is_on()         JL_PORTA->OUT|= BIT(14) 	
			 
	      #define    Set_1_led_io_is_off()         JL_PORTA->OUT &= ~BIT(11)       
             #define    Set_2_led_io_is_off()     	  JL_PORTA->OUT &= ~BIT(15)          
             #define    Set_3_led_io_is_off()         JL_PORTA->OUT &= ~BIT(14) 		
			 
#elif defined(support_led_eq_user_PB6PB7PB8PB9)
             #define  set_all_led_io_is_out()	 JL_PORTB->DIR &= ~(BIT(7)|BIT(8)|BIT(6)|BIT(9)); \
             													  JL_PORTB->PU |= BIT(6)|BIT(7)|BIT(8)|BIT(9)
             
             
             #define  set_all_led_io_off()		   JL_PORTB->OUT  &= ~(BIT(7)|BIT(8)|BIT(6)|BIT(9))			  
             
             #define    Set_1_led_io_is_on() 				JL_PORTB->OUT|= BIT(6)		 
             #define    Set_2_led_io_is_on() 				JL_PORTB->OUT|= BIT(7)			
             #define    Set_3_led_io_is_on() 				JL_PORTB->OUT|= BIT(8)	   
             #define    Set_4_led_io_is_on() 			       JL_PORTB->OUT|= BIT(9)	  


#elif defined(support_led_eq_user_PA14PA11)

             #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(14)|BIT(11))     		                                        
            
             #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(14)|BIT(11))
			 
             #define    Set_1_led_io_is_on()           	  JL_PORTA->OUT|= BIT(14) 
             #define    Set_2_led_io_is_on()           	  JL_PORTA->OUT|= BIT(11) 

#elif defined(support_led_eq_user_PA14PA11PA10)
               #define  set_all_led_io_is_out()	    JL_PORTA->DIR &= ~(BIT(14)|BIT(11)|BIT(10))	               
               #define  set_all_led_io_off()		   JL_PORTA->OUT  &= ~(BIT(14)|BIT(11)|BIT(10))       
			   
               #define    Set_3_led_io_is_on() 	  JL_PORTA->OUT|= BIT(14) 
               #define    Set_2_led_io_is_on() 	  JL_PORTA->OUT|= BIT(11) 
               #define    Set_1_led_io_is_on() 	  JL_PORTA->OUT|= BIT(10) 
#elif defined(support_led_eq_user_PA14PA11PA10PC12)
               #define  set_all_led_io_is_out()	    JL_PORTA->DIR &= ~(BIT(14)|BIT(11)|BIT(10));	 JL_PORTC->DIR &= ~(BIT(12)) ;JL_PORTA->PU &= ~BIT(8);JL_PORTA->PD &= ~BIT(8);              
               #define  set_all_led_io_off()		   JL_PORTA->OUT  &= ~(BIT(14)|BIT(11)|BIT(10));    JL_PORTC->OUT  &= ~(BIT(12))      

              #define     Set_1_led_io_is_on() 	 JL_PORTC->OUT|= BIT(12) 			   
               #define    Set_2_led_io_is_on() 	  JL_PORTA->OUT|= BIT(14) 
               #define    Set_3_led_io_is_on() 	  JL_PORTA->OUT|= BIT(11) 
               #define    Set_4_led_io_is_on() 	  JL_PORTA->OUT|= BIT(10) 

 #elif defined(support_led_eq_user_PB7PB8PB9P)
             #define  set_all_led_io_is_out()     JL_PORTB->DIR &= ~(BIT(7)|BIT(8)|BIT(9)); \
              		                                               JL_PORTB->PU |= BIT(7)|BIT(8)|BIT(9)

             
             #define  set_all_led_io_off()          JL_PORTB->OUT  &= ~(BIT(7)|BIT(8)|BIT(9))              
             
             #define    Set_1_led_io_is_on()                 JL_PORTB->OUT|= BIT(7)       
             #define    Set_2_led_io_is_on()     	         JL_PORTB->OUT|= BIT(8)          
             #define    Set_3_led_io_is_on()                 JL_PORTB->OUT|= BIT(9) 	

 #elif defined(support_led_eq_user_PA147PA11PA10)
             #define  set_all_led_io_is_out()     JL_PORTA->DIR &= ~(BIT(8)|BIT(11)|BIT(14))
              		                                             

             
             #define  set_all_led_io_off()          JL_PORTA->OUT  &= ~(BIT(8)|BIT(11)|BIT(14))              
             
             #define    Set_1_led_io_is_on()                 JL_PORTA->OUT |= BIT(8)       
             #define    Set_2_led_io_is_on()     	         JL_PORTA->OUT |= BIT(11)          
             #define    Set_3_led_io_is_on()                 JL_PORTA->OUT |= BIT(14) 	
			 
#elif defined(support_led_eq_user_PA4_TO_PA15)

       #define eq_led_com_seg_is_out() JL_PORTA->DIR &= ~(BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15));
	   
               
          #define eq_led_com_1_is_h()   JL_PORTA->OUT|= BIT(7)   
          #define eq_led_com_1_is_l()    JL_PORTA->OUT &= ~BIT(7)   
		  
          #define eq_led_com_2_is_h()   JL_PORTA->OUT|= BIT(8)   
          #define eq_led_com_2_is_l()    JL_PORTA->OUT &= ~BIT(8)   
		  
          #define eq_led_com_3_is_h()   JL_PORTA->OUT|= BIT(9)   
          #define eq_led_com_3_is_l()    JL_PORTA->OUT &= ~BIT(9)   
		  
          #define eq_led_com_4_is_h()   JL_PORTA->OUT|= BIT(10)   
          #define eq_led_com_4_is_l()    JL_PORTA->OUT &= ~BIT(10)  		  
          
          #define eq_led_all_com_is_l()  JL_PORTA->OUT &= ~(BIT(7)|BIT(8)|BIT(9)|BIT(10))          
          
          #define eq_led_SEG_A_is_h()  JL_PORTA->OUT|= BIT(4)    
          #define eq_led_SEG_A_is_l()  JL_PORTA->OUT &= ~BIT(4)  
          
          #define eq_led_SEG_B_is_h()  JL_PORTA->OUT|= BIT(5)     
          #define eq_led_SEG_B_is_l()  JL_PORTA->OUT &= ~BIT(5)  
          
          #define eq_led_SEG_C_is_h()  JL_PORTA->OUT|= BIT(6)    
          #define eq_led_SEG_C_is_l()  JL_PORTA->OUT &= ~BIT(6) 
          
          #define eq_led_SEG_D_is_h()  JL_PORTA->OUT|= BIT(11)   
          #define eq_led_SEG_D_is_l()  JL_PORTA->OUT &= ~BIT(11)  
          
          #define eq_led_SEG_E_is_h()  JL_PORTA->OUT|= BIT(14)   
          #define eq_led_SEG_E_is_l()  JL_PORTA->OUT &= ~BIT(14)           

	   #define eq_led_SEG_F_is_h()  JL_PORTA->OUT|= BIT(15)   
          #define eq_led_SEG_F_is_l()  JL_PORTA->OUT &= ~BIT(15)       	  
         
          #define eq_led_all_seg_is_H()      JL_PORTA->OUT |= BIT(4)|BIT(5)|BIT(6)|BIT(11)|BIT(14)|BIT(15)   
          #define eq_led_all_seg_is_L()      JL_PORTA->OUT &= ~(BIT(4)|BIT(5)|BIT(6)|BIT(11)|BIT(14)|BIT(15))   


#elif defined(support_led_eq_user_PB4toPA15_PB6TOPB10)
          #define eq_led_com_seg_is_out() JL_PORTA->DIR &= ~(BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)); \
                                                                       JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10));

		                                                 //     JL_PORTA->PU|=  (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15))
                                                                 //     JL_PORTB->PU|=  (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)); 
          
               
          #define eq_led_com_1_is_h()   JL_PORTA->OUT|= BIT(4)   
          #define eq_led_com_1_is_l()    JL_PORTA->OUT &= ~BIT(4)   
		  
          #define eq_led_com_2_is_h()   JL_PORTA->OUT|= BIT(5)   
          #define eq_led_com_2_is_l()    JL_PORTA->OUT &= ~BIT(5)   
		  
          #define eq_led_com_3_is_h()   JL_PORTA->OUT|= BIT(6)   
          #define eq_led_com_3_is_l()    JL_PORTA->OUT &= ~BIT(6)   
		  
          #define eq_led_com_4_is_h()   JL_PORTA->OUT|= BIT(7)   
          #define eq_led_com_4_is_l()    JL_PORTA->OUT &= ~BIT(7)  
		  
          #define eq_led_all_com_is_l()  JL_PORTA->OUT &= ~(BIT(4)|BIT(5)|BIT(6)|BIT(7))
          #define eq_led_all_seg_is_l()  JL_PORTA->OUT &= ~(BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)); \
                                                                 JL_PORTB->OUT &=~( BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10));   




#elif defined(support_led_eq_user_COMEPA910111415_SEG_PB678910)
          #define eq_led_com_seg_is_out() JL_PORTA->DIR &= ~(BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)); \
                                                                       PORTA_HD  |=  (BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15)); \
                                                                       JL_PORTB->DIR &= ~(BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)); \
                                                                       PORTB_HD  |=  (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)); 
          
               
          #define eq_led_com_1_is_h()   JL_PORTA->OUT|= BIT(9)   
          #define eq_led_com_1_is_l()    JL_PORTA->OUT &= ~BIT(9)   
		  
          #define eq_led_com_2_is_h()   JL_PORTA->OUT|= BIT(10)   
          #define eq_led_com_2_is_l()    JL_PORTA->OUT &= ~BIT(10)   
		  
          #define eq_led_com_3_is_h()   JL_PORTA->OUT|= BIT(11)   
          #define eq_led_com_3_is_l()    JL_PORTA->OUT &= ~BIT(11)   
		  
          #define eq_led_com_4_is_h()   JL_PORTA->OUT|= BIT(14)   
          #define eq_led_com_4_is_l()    JL_PORTA->OUT &= ~BIT(14)  
		  
          #define eq_led_com_5_is_h()   JL_PORTA->OUT|= BIT(15)   
          #define eq_led_com_5_is_l()   JL_PORTA->OUT &= ~BIT(15)   

          
          #define eq_led_all_com_is_l()  JL_PORTA->OUT &= ~(BIT(9)|BIT(10)|BIT(11)|BIT(14)|BIT(15));
          
          
          #define eq_led_SEG_A_is_h()  JL_PORTB->OUT|= BIT(6)    
          #define eq_led_SEG_A_is_l()  JL_PORTB->OUT &= ~BIT(6)  
          
          #define eq_led_SEG_B_is_h()  JL_PORTB->OUT|= BIT(7)     
          #define eq_led_SEG_B_is_l()  JL_PORTB->OUT &= ~BIT(7)  
          
          #define eq_led_SEG_C_is_h()  JL_PORTB->OUT|= BIT(8)    
          #define eq_led_SEG_C_is_l()  JL_PORTB->OUT &= ~BIT(8) 
          
          #define eq_led_SEG_D_is_h()  JL_PORTB->OUT|= BIT(9)   
          #define eq_led_SEG_D_is_l()  JL_PORTB->OUT &= ~BIT(9)  
          
          #define eq_led_SEG_E_is_h()  JL_PORTB->OUT|= BIT(10)   
          #define eq_led_SEG_E_is_l()  JL_PORTB->OUT &= ~BIT(10)            
         
          #define eq_led_all_seg_is_H()      JL_PORTB->OUT |= BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10);   

#elif  defined(support_led_eq_user_PB6PB7PB8PB9_PA1PA5PA6PA7)
   //   PA1 ->PWM3  
  //    PB6 ->PWM0  
       #define eq_led_com_seg_is_out() JL_PORTA->DIR &= ~(BIT(5)|BIT(6)|BIT(7)); \
                                                                    PORTA_HD  |=  BIT(5)|BIT(6)|BIT(7); \
                                                                    JL_PORTB->DIR &= ~(BIT(7)|BIT(8)|BIT(9)); \
                                                                    PORTB_HD  |=  BIT(7)|BIT(8)|BIT(9);  
   
      #define bat_led_R_1_is_l()    JL_PORTA->OUT &= ~BIT(5)     //充电R
      #define bat_led_G_1_is_l()    JL_PORTA->OUT &= ~BIT(6)      //充电G
      #define bat_led_B_1_is_l()    JL_PORTA->OUT &= ~BIT(7)      //充电B

      #define bat_led_R_1_is_h()    JL_PORTA->OUT |= BIT(5)     //充电R
      #define bat_led_G_1_is_h()    JL_PORTA->OUT |= BIT(6)      //充电G
      #define bat_led_B_1_is_h()    JL_PORTA->OUT |= BIT(7)      //充电B
      
	  
      #define mod_led_R_1_is_l()    JL_PORTB->OUT &= ~BIT(9)     //状态R
      #define mod_led_G_1_is_l()    JL_PORTB->OUT &= ~BIT(8)     //状态G
      #define mod_led_B_1_is_l()    JL_PORTB->OUT &= ~BIT(7)     //状态 B      
     
      #define mod_led_R_1_is_h()    JL_PORTB->OUT |= BIT(9)     //状态R      
      #define mod_led_G_1_is_h()    JL_PORTB->OUT |= BIT(8)     //状态G      
      #define mod_led_B_1_is_h()    JL_PORTB->OUT |= BIT(7)     //状态 B

#elif defined(support_led_eq_user_PA4PC3)

             #define  set_all_led_io_is_out()	       JL_PORTA->DIR &= ~(BIT(4)); JL_PORTC->DIR &= ~(BIT(3));\
			 	                                                 JL_PORTA->PU |= BIT(4);        JL_PORTC->PU &= BIT(3);              
              
              
             #define    Set_CLK_H() 				JL_PORTA->OUT |= BIT(4) 	  	  
             #define    Set_CLK_L() 				JL_PORTA->OUT &= ~(BIT(4))  
             #define    Set_DAT_H() 				JL_PORTC->OUT |= BIT(3) 
             #define    Set_DAT_L() 				JL_PORTC->OUT &= ~(BIT(3)) 		  



#elif defined(support_led_eq_user_PA1PA2PA3)
             #define  set_all_led_io_is_out()	 JL_PORTA->DIR &= ~(BIT(1)|BIT(2)|BIT(3))
             													 
              
              
             #define  set_all_led_io_off()		   JL_PORTA->OUT  &= ~(BIT(1)|BIT(2)|BIT(3))				
              
             #define    Set_3_led_io_is_on() 				JL_PORTA->OUT |= BIT(1) 	  
             #define    Set_2_led_io_is_on() 				JL_PORTA->OUT |= BIT(2)		  
             #define    Set_1_led_io_is_on() 				JL_PORTA->OUT |= BIT(3)   
	  
#elif defined(support_led_eq_user_PA4TOPA15) ||defined(support_no_single_mute_amp)||defined(support_led_eq_user_4x9_k1106_mode) \
	 || defined(support_led_eq_user_pa14_pa11_pa8_pa5)
	
     /* 这儿不定义 在文件内部定义*/
 #else 
    #error(" 请设置eq led  IO ") 
   #endif 
#endif 




/* 软开机   用IO口来打开MOS管 */
#ifdef   support_io_power_on_off   //IO 口控制MOS管开关
       #ifdef      power_on_off_user_PA7
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(7);
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(7)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(7)  
   #elif defined( power_on_off_user_PA4)
       #define    Set_power_on_off_io_is_out()         JL_PORTA->DIR &= ~BIT(4); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(4)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(4)       	
   #elif defined( power_on_off_user_PA5)
       #define    Set_power_on_off_io_is_out()         JL_PORTA->DIR &= ~BIT(5); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(5)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(5)   
   #elif defined( power_on_off_user_PA1)
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(1); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(1)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(1)   	   
   #elif defined( power_on_off_user_PA8)
       #define    Set_power_on_off_io_is_out()         JL_PORTA->DIR &= ~BIT(8); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(8)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(8)    
   #elif defined( power_on_off_user_PA11)
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(11); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(11)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(11)    	 	   
   #elif defined( power_on_off_user_PA10)
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(10); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(10)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(10)    	   
   #elif defined( power_on_off_user_PA12)
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(12); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(12)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(12)       
   #elif defined( power_on_off_user_PA13)
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(13); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(13)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(13) 
   #elif defined( power_on_off_user_PA14)
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(14); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(14)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(14) 	   
   #elif defined( power_on_off_user_PA15)
       #define    Set_power_on_off_io_is_out()        JL_PORTA->DIR &= ~BIT(15); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTA->OUT|= BIT(15)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTA->OUT &= ~BIT(15) 	
   #elif defined(power_on_off_user_PB6)
        #define POWER_EN_BIT    BIT(6)
        #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~POWER_EN_BIT;
        #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= POWER_EN_BIT
        #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~POWER_EN_BIT  	
   #elif defined(power_on_off_user_PB7)
        #define POWER_EN_BIT    BIT(7)
        #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~POWER_EN_BIT;
        #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= POWER_EN_BIT
        #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~POWER_EN_BIT    		
   #elif defined(power_on_off_user_PB8)
        #define POWER_EN_BIT    BIT(8)
        #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~POWER_EN_BIT; 
        #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= POWER_EN_BIT
        #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~POWER_EN_BIT    
#elif defined(power_on_off_user_PB9)
	 #define POWER_EN_BIT	 BIT(9)
	 #define	Set_power_on_off_io_is_out()		JL_PORTB->DIR &= ~POWER_EN_BIT; 
	 #define	Set_power_on_off_io_is_HIGH()		JL_PORTB->OUT|= POWER_EN_BIT
	 #define	Set_power_on_off_io_is_LOW()		JL_PORTB->OUT &= ~POWER_EN_BIT	  
		
   #elif defined(power_on_off_user_PB10)
        #define POWER_EN_BIT    BIT(10)
        #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~POWER_EN_BIT;
        #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= POWER_EN_BIT
        #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~POWER_EN_BIT    	
   #elif defined(power_on_off_user_PB11)
       #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~BIT(11); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= BIT(11)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~BIT(11)      
   #elif defined( power_on_off_user_PB12)
       #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~BIT(12); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= BIT(12)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~BIT(12)      
   #elif defined( power_on_off_user_PB13)
       #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~BIT(13); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= BIT(13)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~BIT(13)      
	   
   #elif defined( power_on_off_user_PB14)
       #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~BIT(14); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= BIT(14)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~BIT(14)     
   #elif defined( power_on_off_user_PB15)
       #define    Set_power_on_off_io_is_out()        JL_PORTB->DIR &= ~BIT(15); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTB->OUT|= BIT(15)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTB->OUT &= ~BIT(15)   
   #elif defined(power_on_off_user_PC10)	   
       #define    Set_power_on_off_io_is_out()        PORTC_DIE |=BIT(10);  JL_PORTC->DIR &= ~BIT(10); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTC->OUT|= BIT(10)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTC->OUT &= ~BIT(10)  		   
   #elif defined(power_on_off_user_PC12)	   
       #define    Set_power_on_off_io_is_out()        PORTC_DIE |=BIT(12);  JL_PORTC->DIR &= ~BIT(12); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTC->OUT|= BIT(12)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTC->OUT &= ~BIT(12)  	 
   #elif defined(power_on_off_user_PC15)	   
       #define    Set_power_on_off_io_is_out()        PORTC_DIE |=BIT(15);  JL_PORTC->DIR &= ~BIT(15); 
       #define    Set_power_on_off_io_is_HIGH()      JL_PORTC->OUT|= BIT(15)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTC->OUT &= ~BIT(15)  	   	   
   #elif defined(power_on_off_user_PC2)	   
       #define    Set_power_on_off_io_is_out()        JL_PORTC->DIR &= ~BIT(2); 
       #define    Set_power_on_off_io_is_HIGH()       JL_PORTC->OUT|= BIT(2)
       #define    Set_power_on_off_io_is_LOW()        JL_PORTC->OUT &= ~BIT(2)  
  #elif defined(power_on_off_user_PD0)	   
        #define    Set_power_on_off_io_is_out()        PORTD_DIR &= ~BIT(0); 
        #define    Set_power_on_off_io_is_HIGH()       PORTD_OUT|= BIT(0)
        #define    Set_power_on_off_io_is_LOW()        PORTD_OUT &= ~BIT(0)      
  #elif defined(power_on_off_user_PD1)	   
        #define    Set_power_on_off_io_is_out()        PORTD_DIR &= ~BIT(1);
        #define    Set_power_on_off_io_is_HIGH()       PORTD_OUT|= BIT(1)
        #define    Set_power_on_off_io_is_LOW()        PORTD_OUT &= ~BIT(1)    	

#elif defined(support_io_power_USB_DM)
        #define USB_DM_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(1)) | ((x & 0x1)<<1))
        #define USB_DM_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(3)) | ((x & 0x1)<<3))
        #define USB_DM_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(5)) | ((x & 0x1)<<5))
        #define USB_DM_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(7)) | ((x & 0x1)<<7))   
        
        
        #define    Set_power_on_off_io_is_out()     USB_DM_DIR(0) 
        #define    Set_power_on_off_io_is_HIGH()       USB_DM_OUT(1);
        #define    Set_power_on_off_io_is_LOW()       USB_DM_OUT(0);	


#elif defined(support_io_power_USB_DP)

           #define USB_DP_OUT(x) 	 USB_IO_CON = ((USB_IO_CON & ~BIT(0)) | ((x & 0x1)<<0))
           #define USB_DP_DIR(x) 	 USB_IO_CON = ((USB_IO_CON & ~BIT(2)) | ((x & 0x1)<<2))
           #define USB_DP_PD(x)		 USB_IO_CON = ((USB_IO_CON & ~BIT(4)) | ((x & 0x1)<<4))
           #define USB_DP_PU(x)		 USB_IO_CON = ((USB_IO_CON & ~BIT(6)) | ((x & 0x1)<<6))
           #define USB_DP_IN()		 USB_CON0&BIT(17)		   

      
        
        #define    Set_power_on_off_io_is_out()          USB_DP_DIR(0) 
        #define    Set_power_on_off_io_is_HIGH()       USB_DP_OUT(1);
        #define    Set_power_on_off_io_is_LOW()         USB_DP_OUT(0);			
		
   #else 
         #error(" 请设置 MOS 管控制 io ") 
      #endif 
#endif 






#ifdef  support_ic_chack_dc_in  //检测是否外接电源
     #ifdef  chack_dc_in_user_PD0	   
       #define     DC_DET_IO_IS_IN()    PORTD_DIR |= BIT(0);   PORTD_PU &= ~BIT(0); PORTD_PD  |= BIT(0);
	#define     DC_DET_READ()           PORTD_IN & BIT(0) 
    #elif defined(chack_dc_in_user_PD1)	
         #ifdef support_ext_down_10k
		 #define     DC_DET_IO_IS_IN()    PORTD_DIR |= BIT(1);   PORTD_PU &= ~BIT(1); 
		 #define     DC_DET_READ()           PORTD_IN & BIT(1) 
         #else 
      	 	#define     DC_DET_IO_IS_IN()    PORTD_DIR |= BIT(1);   PORTD_PU &= ~BIT(1); PORTD_PD   |=BIT(1);
      	 	#define     DC_DET_READ()           PORTD_IN & BIT(1) 
     	#endif  
    #elif defined(chack_dc_in_user_PA7)	
           #ifdef support_ext_down_10k
   	 #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(7);   JL_PORTA->PU &= ~BIT(7); JL_PORTA->PD   &=~BIT(7);
   	#define     DC_DET_READ()           JL_PORTA->IN & BIT(7) 	
          #else      
   	 #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(7);   JL_PORTA->PU &= ~BIT(7); JL_PORTA->PD   |=BIT(7);
   	#define     DC_DET_READ()           JL_PORTA->IN & BIT(7) 	
   	#endif 
#elif defined(chack_dc_in_user_PA8) 

       #ifdef support_ext_down_10k
       #define	 DC_DET_IO_IS_IN()	  JL_PORTA->DIR |= BIT(8);	 JL_PORTA->PU &= ~BIT(8); JL_PORTA->PD	 &=~BIT(8);
       #define 	DC_DET_READ()			JL_PORTA->IN & BIT(8)	
       #else 	 
       #define	 DC_DET_IO_IS_IN()	  JL_PORTA->DIR |= BIT(8);	 JL_PORTA->PU &= ~BIT(8); JL_PORTA->PD	 |=BIT(8);
       #define 	DC_DET_READ()			JL_PORTA->IN & BIT(8)	
       #endif 

	
     #elif defined(chack_dc_in_user_PA6)
              #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(6);   JL_PORTA->PU &= ~BIT(6); JL_PORTA->PD   &=~BIT(6);
              #define     DC_DET_READ()           JL_PORTA->IN & BIT(6) 	
              #else      
              #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(6);   JL_PORTA->PU &= ~BIT(6); JL_PORTA->PD   |=BIT(6);
              #define     DC_DET_READ()           JL_PORTA->IN & BIT(6) 	
              #endif 
    #elif defined(chack_dc_in_user_PA12)	
           #ifdef support_ext_down_10k
    	 #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(12);   JL_PORTA->PU &= ~BIT(12); JL_PORTA->PD   &=~BIT(12);
    	#define     DC_DET_READ()           JL_PORTA->IN & BIT(12) 	
          #else      
   	 #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(12);   JL_PORTA->PU &= ~BIT(12); JL_PORTA->PD   |=BIT(12);
   	#define     DC_DET_READ()           JL_PORTA->IN & BIT(12) 	
   	#endif 
    #elif defined(chack_dc_in_user_PA0)	
           #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(0);   JL_PORTA->PU &= ~BIT(0); JL_PORTA->PD   &=~BIT(0);
              #define     DC_DET_READ()           JL_PORTA->IN & BIT(0) 	
           #else      
             #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(0);   JL_PORTA->PU &= ~BIT(0); JL_PORTA->PD   |=BIT(0);
             #define     DC_DET_READ()           JL_PORTA->IN & BIT(0) 	
           #endif 	
    #elif defined(chack_dc_in_user_PA11)	
           #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(11);   JL_PORTA->PU &= ~BIT(11); JL_PORTA->PD   &=~BIT(11);
              #define     DC_DET_READ()           JL_PORTA->IN & BIT(11) 	
           #else      
             #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(11);   JL_PORTA->PU &= ~BIT(11); JL_PORTA->PD   |=BIT(11);
             #define     DC_DET_READ()           JL_PORTA->IN & BIT(11) 	
           #endif 		   
    #elif defined(chack_dc_in_user_PA13)	
           #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(13);   JL_PORTA->PU &= ~BIT(13); JL_PORTA->PD   &=~BIT(13);
              #define     DC_DET_READ()           JL_PORTA->IN & BIT(13) 	
           #else      
             #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(13);   JL_PORTA->PU &= ~BIT(13); JL_PORTA->PD   |=BIT(13);
             #define     DC_DET_READ()           JL_PORTA->IN & BIT(13) 	
           #endif 
    #elif defined(chack_dc_in_user_PA4)	    	
           #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(4);   JL_PORTA->PU &= ~BIT(4); JL_PORTA->PD   &=~BIT(4);
           #define     DC_DET_READ()        JL_PORTA->IN & BIT(4) 		
    #elif defined(chack_dc_in_user_PA2)	    	
           #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(2);   JL_PORTA->PU &= ~BIT(2); JL_PORTA->PD   &=~BIT(2);
           #define     DC_DET_READ()        JL_PORTA->IN & BIT(2) 	

    #elif defined(chack_dc_in_msj_user_PA2)	    	
           #define     MSJ_DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(2);   JL_PORTA->PU &= ~BIT(2); JL_PORTA->PD   &=~BIT(2);
           #define     MSJ_DC_DET_READ()        JL_PORTA->IN & BIT(2) 	
		   
    #elif defined(chack_dc_in_user_PA5)	    
           #define     DC_DET_IO_IS_IN()    JL_PORTA->DIR |= BIT(5);   JL_PORTA->PU &= ~BIT(5); JL_PORTA->PD   &=~BIT(5);
           #define     DC_DET_READ()        JL_PORTA->IN & BIT(5) 
		   
    #elif defined(chack_dc_in_user_PA3) 	
	   #define	   DC_DET_IO_IS_IN()	JL_PORTA->DIR |= BIT(3);   JL_PORTA->PU &= ~BIT(3); JL_PORTA->PD   &=~BIT(3);
	   #define	   DC_DET_READ()		   JL_PORTA->IN & BIT(3)		
		   
    #elif defined(chack_dc_in_user_PB6)	
         #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(6);   JL_PORTB->PU &= ~BIT(6); JL_PORTB->PD   &=~BIT(6);
              #define     DC_DET_READ()           JL_PORTB->IN & BIT(6) 	
         #else      
            #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(6);   JL_PORTB->PU &= ~BIT(6); JL_PORTB->PD   |=BIT(6);
            #define     DC_DET_READ()           JL_PORTB->IN & BIT(6) 	
         #endif 	
    #elif defined(chack_dc_in_user_PB7)	
         #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(7);   JL_PORTB->PU &= ~BIT(7); JL_PORTB->PD   &=~BIT(7);
              #define     DC_DET_READ()           JL_PORTB->IN & BIT(7) 	
         #else      
            #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(7);   JL_PORTB->PU &= ~BIT(7); JL_PORTB->PD   |=BIT(7);
            #define     DC_DET_READ()           JL_PORTB->IN & BIT(7) 	
         #endif 		
    #elif defined(chack_dc_in_user_PB9)	
         #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(9);   JL_PORTB->PU &= ~BIT(9); JL_PORTB->PD   &=~BIT(9);
              #define     DC_DET_READ()           JL_PORTB->IN & BIT(9) 	
         #else      
            #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(9);   JL_PORTB->PU &= ~BIT(9); JL_PORTB->PD   |=BIT(9);
            #define     DC_DET_READ()           JL_PORTB->IN & BIT(9) 	
         #endif 		
    #elif defined(chack_dc_in_user_PB10)	
         #ifdef support_ext_down_10k
              #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(10);   JL_PORTB->PU &= ~BIT(10); JL_PORTB->PD   &=~BIT(10);
              #define     DC_DET_READ()           JL_PORTB->IN & BIT(10) 	
         #else      
            #define     DC_DET_IO_IS_IN()    JL_PORTB->DIR |= BIT(10);   JL_PORTB->PU &= ~BIT(10); JL_PORTB->PD |=BIT(10);
            #define     DC_DET_READ()           JL_PORTB->IN & BIT(10) 	
         #endif 	
    #elif defined(chack_dc_in_user_PC10)	
         #ifdef support_ext_down_10k
         #define     DC_DET_IO_IS_IN()    JL_PORTC->DIR |= BIT(10);   JL_PORTC->PU &= ~BIT(10); JL_PORTC->PD   &=~BIT(10);
         #define     DC_DET_READ()           JL_PORTC->IN & BIT(10) 	
         #else      
         #define     DC_DET_IO_IS_IN()    JL_PORTC->DIR |= BIT(10);   JL_PORTC->PU &= ~BIT(10); JL_PORTC->PD   |=BIT(10);
         #define     DC_DET_READ()           JL_PORTC->IN & BIT(10) 	
         #endif 		 
    #elif defined(chack_dc_in_user_PC15)	
         #ifdef support_ext_down_10k
         #define     DC_DET_IO_IS_IN()    JL_PORTC->DIR |= BIT(15);   JL_PORTC->PU &= ~BIT(15); JL_PORTC->PD   &=~BIT(15);
         #define     DC_DET_READ()           JL_PORTC->IN & BIT(15) 	
         #else      
         #define     DC_DET_IO_IS_IN()    JL_PORTC->DIR |= BIT(15);   JL_PORTC->PU &= ~BIT(15); JL_PORTC->PD   |=BIT(15);
         #define     DC_DET_READ()           JL_PORTC->IN & BIT(15) 	
         #endif 
    #else 
        #error(" 请设置 检测外接电源检测IO ") 
    #endif 
#endif 



//开关检测
#ifdef support_sw_chack
#ifdef support_sw_chack_user_PB9
	 #define SW_IO_IS_IN()     JL_PORTB->DIR |= BIT(9); JL_PORTB->PU &= ~BIT(9); JL_PORTB->PD   |=BIT(9);
	 #define SW_IN_CHECK()     JL_PORTB->IN   &   BIT(9)
	 #define SW_IN_CHECK1()     !(JL_PORTB->IN   &   BIT(9))
#elif defined(support_sw_chack_user_PB10)
	 #define SW_IO_IS_IN()     JL_PORTB->DIR |= BIT(10); JL_PORTB->PU &= ~BIT(10); JL_PORTB->PD   |=BIT(10);
	 #define SW_IN_CHECK()     JL_PORTB->IN   &   BIT(10)
	 #define SW_IN_CHECK1()     !(JL_PORTB->IN   &   BIT(10))
#elif defined(support_sw_chack_user_PC5)
	 #define SW_IO_IS_IN()     JL_PORTC->DIR |= BIT(5); JL_PORTC->PU &= ~BIT(5); JL_PORTC->PD   |=BIT(5);
	 #define SW_IN_CHECK()     JL_PORTC->IN   &   BIT(5)
	 #define SW_IN_CHECK1()     !(JL_PORTC->IN   &   BIT(5))
#endif
#endif





#ifdef support_sound_4052_control

#ifdef sound_4052_io_ab_pc3pa11
#define AC4052_A_OFF()	{JL_PORTC->OUT &=~ BIT(5);JL_PORTC->PU &=~BIT(5);JL_PORTC->PD |= BIT(5);JL_PORTC->DIR &= ~BIT(5);}//A 
#define AC4052_A_ON() 	{JL_PORTC->OUT |= BIT(5);JL_PORTC->PU |=BIT(5);JL_PORTC->PD &=~ BIT(5);JL_PORTC->DIR &= ~BIT(5);}
#define AC4052_B_OFF()	{JL_PORTA->OUT &=~ BIT(4);JL_PORTA->PU &=~BIT(4);JL_PORTA->PD |= BIT(4);JL_PORTA->DIR &= ~BIT(4);}//B 
#define AC4052_B_ON() 	{JL_PORTA->OUT |= BIT(4);JL_PORTA->PU |=BIT(4);JL_PORTA->PD &=~ BIT(4);JL_PORTA->DIR &= ~BIT(4);}
#endif
	
#ifdef  sound_4052_io_mode_1
/*
		A B
DVD		0 0
CD		1 0
AUX		0 1
MP3/BT	1 1
*/
#define AC4052_IS_DVD()	{AC4052_A_OFF();AC4052_B_ON();}
#define AC4052_IS_AC3() 	{AC4052_A_ON();AC4052_B_OFF();}
#define AC4052_IS_AUX()	{AC4052_A_ON();AC4052_B_ON();}
#define AC4052_IS_MP3() 	{AC4052_A_OFF();AC4052_B_OFF();}

#elif defined sound_4052_io_mode_2
/*
		A B
DVD		0 1
CD		1 0
AUX		1 1
MP3/BT	0 0
*/

#define AC4052_IS_DVD()	{AC4052_A_OFF();AC4052_B_ON();}
#define AC4052_IS_CD() 	{AC4052_A_ON();AC4052_B_OFF();}
#define AC4052_IS_AUX()	{AC4052_A_ON();AC4052_B_ON();}
#define AC4052_IS_MP3() 	{AC4052_A_OFF();AC4052_B_OFF();}

#elif defined sound_4052_io_mode_3
/*
		A B
DVD		0 0
CD		1 0
AUX		1 1
MP3/BT	0 1
*/

#define AC4052_IS_DVD()	{AC4052_A_OFF();AC4052_B_OFF();}
#define AC4052_IS_CD() 	{AC4052_A_ON();AC4052_B_OFF();}
#define AC4052_IS_AUX()	{AC4052_A_ON();AC4052_B_ON();}
#define AC4052_IS_MP3() 	{AC4052_A_OFF();AC4052_B_ON();}
#elif defined sound_4052_io_mode_4

/*
		A B
DVD		1 0
CD		0 1
AUX		0 0
MP3/BT	1 1

*/
#define AC4052_IS_DVD()	{AC4052_A_ON();AC4052_B_OFF();}
#define AC4052_IS_CD() 	{AC4052_A_OFF();AC4052_B_ON();}
#define AC4052_IS_AUX()	{AC4052_A_OFF();AC4052_B_OFF();}
#define AC4052_IS_MP3() 	{AC4052_A_ON();AC4052_B_ON();}

#elif defined sound_4052_io_mode_5

/*
		ABCDEF
AC3		100010
DVD		010001
CD		001011
MP3/BT	000100



*/

#define AC4052_IS_AC3()	{AC4052_A_ON();AC4052_B_OFF();AC4052_C_OFF();AC4052_D_OFF();AC4052_E_ON();AC4052_F_OFF();}
#define AC4052_IS_DVD() 	{AC4052_A_OFF();AC4052_B_ON();AC4052_C_OFF();AC4052_D_OFF();AC4052_E_OFF();AC4052_F_ON();}
#define AC4052_IS_CD()	{AC4052_A_OFF();AC4052_B_OFF();AC4052_C_ON();AC4052_D_OFF();AC4052_E_ON();AC4052_F_ON();}
#define AC4052_IS_MP3() 	{AC4052_A_OFF();AC4052_B_OFF();AC4052_C_OFF();AC4052_D_ON();AC4052_E_OFF();AC4052_F_OFF();}

#define AC4052_IS_AUX() 	{AC4052_A_OFF();AC4052_B_OFF();AC4052_C_OFF();AC4052_D_ON();AC4052_E_OFF();AC4052_F_OFF();}
#define AC4052_IS_MP3() 	{AC4052_A_OFF();AC4052_B_OFF();AC4052_C_OFF();AC4052_D_ON();AC4052_E_OFF();AC4052_F_OFF();}
#define AC4052_IS_FM() 	{AC4052_A_OFF();AC4052_B_OFF();AC4052_C_OFF();AC4052_D_ON();AC4052_E_OFF();AC4052_F_OFF();}
#define AC4052_IS_BT() 	{AC4052_A_OFF();AC4052_B_OFF();AC4052_C_OFF();AC4052_D_ON();AC4052_E_OFF();AC4052_F_OFF();}



#endif
#endif








//功放AB/D类切换  
#ifdef   support_amP_ab_d
       #ifdef    amp_ab_d_user_PC2
                   #define Set_amp_ab_d_out()         JL_PORTC->DIR &= ~BIT(2); JL_PORTC->PU |= BIT(2) 
                   #define Set_FM_IS_AB()                 JL_PORTC->OUT &= ~BIT(2) 
                   #define Set_AMP_IS_D()                 JL_PORTC->OUT|= BIT(2)
       #elif defined(amp_ab_d_user_PC4)
                   #define AB_D_IO_BIT    4	   
                   #define Set_amp_ab_d_out()         JL_PORTC->DIR &= ~BIT(AB_D_IO_BIT); JL_PORTC->PU |= BIT(AB_D_IO_BIT) 
		 #ifdef amp_ab_d_alway_is_high
                    #define Set_FM_IS_AB()                  JL_PORTC->OUT|= BIT(AB_D_IO_BIT)	
                    #define Set_AMP_IS_D()                 JL_PORTC->OUT|= BIT(AB_D_IO_BIT)	
		#elif defined amp_ab_d_alway_is_low
                    #define Set_FM_IS_AB()                 JL_PORTC->OUT &= ~BIT(AB_D_IO_BIT) 	
                    #define Set_AMP_IS_D()                  JL_PORTC->OUT &= ~BIT(AB_D_IO_BIT) 		
		 #else
                    #define Set_FM_IS_AB()                 JL_PORTC->OUT &= ~BIT(AB_D_IO_BIT) 
                    #define Set_AMP_IS_D()                 JL_PORTC->OUT|= BIT(AB_D_IO_BIT)
		 #endif	
       #elif defined(amp_ab_d_user_PC5)
                   #define AB_D_IO_BIT    5	   
                   #define Set_amp_ab_d_out()         JL_PORTC->DIR &= ~BIT(AB_D_IO_BIT); JL_PORTC->PU |= BIT(AB_D_IO_BIT) 
		 #ifdef amp_ab_d_alway_is_high
                    #define Set_FM_IS_AB()                  JL_PORTC->OUT|= BIT(AB_D_IO_BIT)	
                    #define Set_AMP_IS_D()                 JL_PORTC->OUT|= BIT(AB_D_IO_BIT)	
		#elif defined amp_ab_d_alway_is_low
                    #define Set_FM_IS_AB()                 JL_PORTC->OUT &= ~BIT(AB_D_IO_BIT) 	
                    #define Set_AMP_IS_D()                  JL_PORTC->OUT &= ~BIT(AB_D_IO_BIT) 		
		 #else
                    #define Set_FM_IS_AB()                 JL_PORTC->OUT &= ~BIT(AB_D_IO_BIT) 
                    #define Set_AMP_IS_D()                 JL_PORTC->OUT|= BIT(AB_D_IO_BIT)
		 #endif			 
       #elif defined(amp_ab_d_user_PC14)
                   #define Set_amp_ab_d_out()         JL_PORTC->DIR &= ~BIT(14); JL_PORTC->PU |= BIT(14) 
                   #define Set_FM_IS_AB()                 JL_PORTC->OUT &= ~BIT(14) 
                   #define Set_AMP_IS_D()                 JL_PORTC->OUT|= BIT(14)
       #elif   defined(amp_ab_d_user_PD1)
                   #define Set_amp_ab_d_out()          PORTD_DIR &= ~BIT(1); JL_PORTC->PU |= BIT(1) 
                   #define Set_FM_IS_AB()              PORTD_OUT &= ~BIT(1) 
                   #define Set_AMP_IS_D()              PORTD_OUT|= BIT(1)	
       #elif   defined(amp_ab_d_user_PD0)
                   #define Set_amp_ab_d_out()          PORTD_DIR &= ~BIT(0); PORTD_PU |= BIT(0) 
                   #define Set_FM_IS_AB()              PORTD_OUT &= ~BIT(0) 
                   #define Set_AMP_IS_D()              PORTD_OUT|= BIT(0)
       #elif   defined(amp_ab_d_user_PA0)
                   #define Set_amp_ab_d_out()         JL_PORTA->DIR &= ~BIT(0); JL_PORTA->PU |= BIT(0) 
                   #define Set_FM_IS_AB()                JL_PORTA->OUT &= ~BIT(0) 
                   #define Set_AMP_IS_D()                JL_PORTA->OUT|= BIT(0)				   
       #elif   defined(amp_ab_d_user_PA4)
                   #define Set_amp_ab_d_out()           JL_PORTA->DIR &= ~BIT(4); JL_PORTA->PU |= BIT(4) 
                   #define Set_FM_IS_AB()               JL_PORTA->OUT &= ~BIT(4) 
                   #define Set_AMP_IS_D()               JL_PORTA->OUT|= BIT(4)		
	   #elif   defined(amp_ab_d_user_PA6)
                   #define Set_amp_ab_d_out()           JL_PORTA->DIR &= ~BIT(6); JL_PORTA->PU |= BIT(6) 
                   #define Set_FM_IS_AB()               JL_PORTA->OUT &= ~BIT(6) 
                   #define Set_AMP_IS_D()               JL_PORTA->OUT|= BIT(6)				   
	 #elif   defined(amp_ab_d_user_PA8)
                   #define Set_amp_ab_d_out()           JL_PORTA->DIR &= ~BIT(8); JL_PORTA->PU &= ~BIT(8) ;JL_PORTA->PD&= ~BIT(8) 
                   #define Set_FM_IS_AB()                    JL_PORTA->OUT &= ~BIT(8) 
                   #define Set_AMP_IS_D()                    JL_PORTA->OUT|= BIT(8)	
	 #elif   defined(amp_ab_d_user_PA10)
                   #define Set_amp_ab_d_out()           JL_PORTA->DIR &= ~BIT(10); JL_PORTA->PU |= BIT(10) 
                   #define Set_FM_IS_AB()                   JL_PORTA->OUT &= ~BIT(10) 
                   #define Set_AMP_IS_D()                   JL_PORTA->OUT|= BIT(10)	
         #elif   defined(amp_ab_d_user_PA13)
	              #define Set_amp_ab_d_out()          JL_PORTA->DIR &= ~BIT(13); JL_PORTA->PU |= BIT(13)          
	              #define Set_FM_IS_AB()                 JL_PORTA->OUT &= ~BIT(13) 
	              #define Set_AMP_IS_D()                 JL_PORTA->OUT|= BIT(13)	  
        #elif	defined(amp_ab_d_user_PA14)
	              #define Set_amp_ab_d_out()			JL_PORTA->DIR &= ~BIT(14); JL_PORTA->PU |= BIT(14)			
	              #define Set_FM_IS_AB()				JL_PORTA->OUT &= ~BIT(14) 
	              #define Set_AMP_IS_D()				JL_PORTA->OUT|= BIT(14)    
         #elif	defined(amp_ab_d_user_PA15)
	              #define Set_amp_ab_d_out()		 JL_PORTA->DIR &= ~BIT(15); JL_PORTA->PU |= BIT(15)			
	              #define Set_FM_IS_AB()			 JL_PORTA->OUT &= ~BIT(15) 
	              #define Set_AMP_IS_D()			 JL_PORTA->OUT|= BIT(15)    	
       #elif   defined(amp_ab_d_user_PA7)
                   #define Set_amp_ab_d_out()           JL_PORTA->DIR &= ~BIT(7); JL_PORTA->PU |= BIT(7) 
                   #define Set_FM_IS_AB()               JL_PORTA->OUT &= ~BIT(7) 
                   #define Set_AMP_IS_D()               JL_PORTA->OUT|= BIT(7)	
       #elif defined(amp_ab_d_user_PD1_PA7)
       		    #define Set_amp_ab_d_out()          PORTD_DIR &= ~BIT(1); JL_PORTC->PU |= BIT(1);JL_PORTA->DIR &= ~BIT(7); JL_PORTA->PU |= BIT(7)  
                   #define Set_FM_IS_AB()              PORTD_OUT &= ~BIT(1) ; JL_PORTA->OUT|= BIT(7)
                   #define Set_AMP_IS_D()              PORTD_OUT|= BIT(1)	; JL_PORTA->OUT &= ~BIT(7)
       #elif   defined(amp_ab_d_user_PB6)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(6); JL_PORTB->PU |= BIT(6)          
                   #define Set_FM_IS_AB()                  JL_PORTB->OUT &= ~BIT(6) 
                   #define Set_AMP_IS_D()                  JL_PORTB->OUT|= BIT(6)	    	

          #elif	defined(amp_ab_d_user_PA7_PA9)
			#define Set_amp_ab_d_out()			JL_PORTA->DIR &= ~(BIT(7)|BIT(9)); JL_PORTA->PU |= (BIT(7)|BIT(9))		  
			#define Set_FM_IS_AB()				JL_PORTA->OUT &= ~(BIT(7)|BIT(9)) 
			#define Set_AMP_IS_D()				JL_PORTA->OUT|= (BIT(7)|BIT(9))						   
       #elif   defined(amp_ab_d_user_PB7)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(7); JL_PORTB->PU |= BIT(7)          
                   #define Set_FM_IS_AB()              JL_PORTB->OUT &= ~BIT(7) 
                   #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(7)	      
       #elif   defined(amp_ab_d_user_PB8)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(8); JL_PORTB->PU |= BIT(8)          
                   #define Set_FM_IS_AB()              JL_PORTB->OUT &= ~BIT(8) 
                   #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(8)	      			
       #elif   defined(amp_ab_d_user_PB9)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(9); JL_PORTB->PU |= BIT(9)          
                   #define Set_FM_IS_AB()                  JL_PORTB->OUT &= ~BIT(9) 
                   #define Set_AMP_IS_D()                  JL_PORTB->OUT|= BIT(9)	       
	#elif defined(amp_ab_d_user_PB9_PB8)

	            #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~(BIT(9)|BIT(8)); JL_PORTB->PU |= (BIT(9)|BIT(8))          
                   #define Set_FM_IS_AB()                  JL_PORTB->OUT &= ~(BIT(9)|BIT(8)) 
                   #define Set_AMP_IS_D()                  JL_PORTB->OUT|= (BIT(9)|BIT(8))	      
				   
       #elif   defined(amp_ab_d_user_PB10)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(10); JL_PORTB->PU |= BIT(10)     
                   #ifdef support_low_is_d_amp
                   #define Set_FM_IS_AB()             JL_PORTB->OUT|= BIT(10)    
                   #define Set_AMP_IS_D()              JL_PORTB->OUT &= ~BIT(10) 	    
                   #else 
                   #define Set_FM_IS_AB()              JL_PORTB->OUT &= ~BIT(10) 
                   #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(10)	    
                   #endif 
       #elif   defined(amp_ab_d_user_PC10)
                     #define Set_amp_ab_d_out()          JL_PORTC->DIR &= ~BIT(10); JL_PORTC->PU |= BIT(10)     
                     #ifdef support_low_is_d_amp
                     #define Set_FM_IS_AB()              JL_PORTC->OUT|= BIT(10)    
                     #define Set_AMP_IS_D()              JL_PORTC->OUT &= ~BIT(10) 	    
                     #else 
                     #define Set_FM_IS_AB()              JL_PORTC->OUT &= ~BIT(10) 
                     #define Set_AMP_IS_D()              JL_PORTC->OUT|= BIT(10)	    
                     #endif 	
	 #elif   defined(amp_ab_d_user_PC11)
                     #define Set_amp_ab_d_out()          JL_PORTC->DIR &= ~BIT(11); JL_PORTC->PU |= BIT(11)     
                     #ifdef support_low_is_d_amp
                     #define Set_FM_IS_AB()              JL_PORTC->OUT|= BIT(11)    
                     #define Set_AMP_IS_D()              JL_PORTC->OUT &= ~BIT(11) 	    
                     #else 
                     #define Set_FM_IS_AB()              JL_PORTC->OUT &= ~BIT(11) 
                     #define Set_AMP_IS_D()              JL_PORTC->OUT|= BIT(11)	    
                     #endif 	
    #elif	defined(amp_ab_d_user_PC15)
				#define Set_amp_ab_d_out()			 PORTC_DIE |=BIT(15); JL_PORTC->DIR &= ~BIT(15); JL_PORTC->PU |= BIT(15)	   
				#ifdef support_low_is_d_amp
				#define Set_FM_IS_AB()				JL_PORTC->OUT|= BIT(15)    
				#define Set_AMP_IS_D()				JL_PORTC->OUT &= ~BIT(15)	   
				#else 
				#define Set_FM_IS_AB()				JL_PORTC->OUT &= ~BIT(15)
				#define Set_AMP_IS_D()				JL_PORTC->OUT|= BIT(15) 	   
				#endif	   					 
       #elif   defined(amp_ab_d_user_PB1)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(1); JL_PORTB->PU |= BIT(1)          
                   #define Set_FM_IS_AB()              JL_PORTB->OUT &= ~BIT(1) 
                   #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(1)	          
       #elif   defined(amp_ab_d_user_PB13)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(13); JL_PORTB->PU |= BIT(13)          
                   #define Set_FM_IS_AB()              JL_PORTB->OUT &= ~BIT(13) 
                   #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(13)	            
       
       #elif   defined(amp_ab_d_user_PB12)
                   #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(12); JL_PORTB->PU |= BIT(12)          
                   #define Set_FM_IS_AB()              JL_PORTB->OUT &= ~BIT(12) 
                   #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(12)	            
       #elif   defined(amp_ab_d_user_PA12)
                   #define Set_amp_ab_d_out()          JL_PORTA->DIR &= ~BIT(12); JL_PORTA->PU |= BIT(12)          
                   #define Set_FM_IS_AB()              JL_PORTA->OUT &= ~BIT(12) 
                   #define Set_AMP_IS_D()              JL_PORTA->OUT|= BIT(12)	     


       #elif defined(amp_ab_d_user_USB_DM) 

                 #define USB_DM_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(1)) | ((x & 0x1)<<1))
                 #define USB_DM_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(3)) | ((x & 0x1)<<3))
                 #define USB_DM_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(5)) | ((x & 0x1)<<5))
                 #define USB_DM_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(7)) | ((x & 0x1)<<7))   
				 
               #define  Set_amp_ab_d_out()    USB_DM_DIR(0) 		                                                      
               #define  Set_AMP_IS_D()          USB_DM_OUT(1);
               #define  Set_FM_IS_AB()          USB_DM_OUT(0);

	 #elif defined(amp_ab_d_user_USB_DP)
		 
		 	  #define USB_DP_OUT(x) 	 USB_IO_CON = ((USB_IO_CON & ~BIT(0)) | ((x & 0x1)<<0))
		 	  #define USB_DP_DIR(x) 	 USB_IO_CON = ((USB_IO_CON & ~BIT(2)) | ((x & 0x1)<<2))
		 	  #define USB_DP_PD(x)		 USB_IO_CON = ((USB_IO_CON & ~BIT(4)) | ((x & 0x1)<<4))
		 	  #define USB_DP_PU(x)		 USB_IO_CON = ((USB_IO_CON & ~BIT(6)) | ((x & 0x1)<<6))
		 	  #define USB_DP_IN()		 USB_CON0&BIT(17)		   
		 	  
              #define  Set_amp_ab_d_out()    USB_DP_DIR(0)															   
              #define  Set_AMP_IS_D() 		 USB_DP_OUT(1)
              #define  Set_FM_IS_AB() 		 USB_DP_OUT(0)			   
				   
       #elif   defined(amp_ab_d_user_PB15)
             #ifdef amp_amp_add_mos
                     #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(15); JL_PORTB->PU |= BIT(15) 
                     #define Set_FM_IS_AB()                   JL_PORTB->OUT|= BIT(15)	
                     #define Set_AMP_IS_D()                  JL_PORTB->OUT &= ~BIT(15)  
             #else 
                  #define Set_amp_ab_d_out()          JL_PORTB->DIR &= ~BIT(15); JL_PORTB->PU |= BIT(15) 

                #ifdef customer_MLH_LFFD            
                            #define Set_FM_IS_AB()             // JL_PORTB->OUT &= ~BIT(15) 
                            #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(15)	           
                #else 
                            
                            #define Set_FM_IS_AB()              JL_PORTB->OUT &= ~BIT(15) 
                            #define Set_AMP_IS_D()              JL_PORTB->OUT|= BIT(15)	            
                #endif 			  
     	
             #endif 		
       #else 
           #error("please support_amP_ab_d ")
       
       #endif 
#endif 


#if 0//def SUPPORT_ENCODE

#if defined(Encode_user_PA8PA9)
   #define ENCODE_JL_PORTB->IN()    JL_PORTA->DIR |= BIT(8)|BIT(9);    JL_PORTA->PU|=  BIT(8)|BIT(9)
   #define  BM_DN_IS_H()    	  JL_PORTA->IN & BIT(9) 
   #define  BM_UP_IS_H()             JL_PORTA->IN & BIT(8) 
#elif defined(Encode_user_PA5PA6)
   #define ENCODE_JL_PORTB->IN()    JL_PORTA->DIR |= BIT(5)|BIT(6);    JL_PORTA->PU|=  BIT(5)|BIT(6)
   #define  BM_DN_IS_H()    	  JL_PORTA->IN & BIT(5) 
   #define  BM_UP_IS_H()             JL_PORTA->IN & BIT(6) 
#elif defined(Encode_user_PA6PB10)
   #define ENCODE_JL_PORTB->IN()      do{ JL_PORTA->PU |=BIT(6); JL_PORTA->DIR |=BIT(6);\
                                                                   JL_PORTB->PU |=BIT(10); JL_PORTB->DIR |=BIT(10);}while(0)
   #define  BM_DN_IS_H()    	(!(JL_PORTA->IN&BIT(6)))
   #define  BM_UP_IS_H()            (!(JL_PORTB->IN&BIT(10))) 
#elif defined(Encode_user_PB9PB10)
   #define ENCODE_JL_PORTB->IN()      do{  JL_PORTB->PU |=BIT(9)|BIT(10); JL_PORTB->DIR |=BIT(9)|BIT(10);}while(0)
   #define  BM_DN_IS_H()    	(!(JL_PORTB->IN&BIT(9)))
   #define  BM_UP_IS_H()            (!(JL_PORTB->IN&BIT(10))) 
 #elif defined(Encode_user_PC11PC10)
    #define ENCODE_JL_PORTB->IN()      do{  JL_PORTC->PU |=BIT(11)|BIT(10); JL_PORTC->DIR |=BIT(11)|BIT(10);}while(0)
   #define  BM_DN_IS_H()         	(!(JL_PORTC->IN&BIT(11)))  
   #define  BM_UP_IS_H()              (!(JL_PORTC->IN&BIT(10)))        
#elif defined(Encode_user_PC10PC11)
   #define ENCODE_JL_PORTB->IN()      do{  JL_PORTC->PU |=BIT(11)|BIT(10); JL_PORTC->DIR |=BIT(11)|BIT(10);}while(0)
   #define  BM_DN_IS_H()    	(!(JL_PORTC->IN&BIT(10)))
   #define  BM_UP_IS_H()            (!(JL_PORTC->IN&BIT(11)))    
#elif defined(Encode_user_PB7PB8)
   #define ENCODE_JL_PORTB->IN()      do{  JL_PORTB->PU |=BIT(7)|BIT(8); JL_PORTB->DIR |=BIT(7)|BIT(7);}while(0)
   #define  BM_DN_IS_H()    	      (!(JL_PORTB->IN&BIT(7)))
   #define  BM_UP_IS_H()                 (!(JL_PORTB->IN&BIT(8))) 
#elif defined(Encode_user_PA6_PA7)
  #define ENCODE_JL_PORTB->IN()    JL_PORTA->DIR |= BIT(6)|BIT(7);    JL_PORTA->PU|=  BIT(6)|BIT(7)
    #ifdef gld_023_encode
      #define  BM_UP_IS_H()        JL_PORTA->IN & BIT(6) 
      #define  BM_DN_IS_H()        JL_PORTA->IN & BIT(7) 
    #else   
      #define  BM_DN_IS_H()        JL_PORTA->IN & BIT(6) 
      #define  BM_UP_IS_H()        JL_PORTA->IN & BIT(7) 
    #endif 
#elif defined(Encode_user_PA2_PB10)

    #define ENCODE_JL_PORTB->IN()   PORTA_DIE |= BIT(2);  JL_PORTA->DIR |= BIT(2);    JL_PORTA->PU|=  BIT(2);JL_PORTB->DIR |= BIT(10);   JL_PORTB->PU|=  BIT(10);
    #define  BM_UP_IS_H()             JL_PORTA->IN & BIT(2) 
    #define  BM_DN_IS_H()             JL_PORTB->IN & BIT(10) 
	
#else
  #error(" 请设置 编码器的 IO ") 

#endif 
#endif 




#ifdef  support_fm_mode_io_chack
#ifdef  fm_mode_io_chack_user_PC11
      #define FM_MODE_IO_IN()    JL_PORTC->DIR |= BIT(11);    JL_PORTC->PU|=  BIT(11)
      #define  FM_IO_IS_l()    	      (!(JL_PORTC->IN & BIT(11)))
#else 
#endif 
#endif 

#ifdef  support_bt_mode_io_chack
  #ifdef  fm_mode_io_chack_user_PC10
     #define BT_MODE_IO_IN()    JL_PORTC->DIR |= BIT(10);    JL_PORTC->PU|=  BIT(10)
    #define  BT_IO_IS_l()    	      (!(JL_PORTC->IN & BIT(10))) 
     #else 
  #endif 
#endif 


#ifdef support_stanby_led
   #if defined(stanby_led_pin_PB9)                
             #define stanby_led_io_is_out()      JL_PORTB->DIR &= ~BIT(9)	
             #define stanby_led_OFF()               JL_PORTB->OUT |= BIT(9)          
             #define stanby_led_ON()                 JL_PORTB->OUT &= ~BIT(9) 
   #elif defined(stanby_led_pin_PA4)
             #define stanby_led_io_is_out()      JL_PORTA->DIR &= ~BIT(4)	
	#ifdef support_stanby_led_is_low
	      #define stanby_led_OFF()                JL_PORTA->OUT |= BIT(4)          
             #define stanby_led_ON()                  JL_PORTA->OUT &= ~BIT(4)      
	#else 
             #define stanby_led_OFF()               JL_PORTA->OUT &= ~BIT(4)       
             #define stanby_led_ON()                 JL_PORTA->OUT |= BIT(4)     
        #endif 
   #elif  defined(stanby_led_pin_PB10)                
             #define stanby_led_io_is_out()      JL_PORTB->DIR &= ~BIT(10)	
	#ifdef stanby_io_low_stanby	
	      #define stanby_led_OFF()               JL_PORTB->OUT |= BIT(10)          
             #define stanby_led_ON()                 JL_PORTB->OUT &= ~BIT(10) 
	#else 
	        #define stanby_led_OFF()              JL_PORTB->OUT &= ~BIT(10)            
             #define stanby_led_ON()                JL_PORTB->OUT |= BIT(10)   

	#endif 
  #elif defined(stanby_led_pin_PB6)
             #define stanby_led_io_is_out()      JL_PORTB->DIR &= ~BIT(6)	
             #ifdef support_stanby_io_is_low		 
                  #define stanby_led_OFF()              JL_PORTB->OUT |= BIT(6)   
                  #define stanby_led_ON()                JL_PORTB->OUT &= ~BIT(6)         
             #else 
                  #define stanby_led_OFF()               JL_PORTB->OUT &= ~BIT(6)       
                  #define stanby_led_ON()                 JL_PORTB->OUT |= BIT(6)   
             #endif 
#elif defined(stanby_led_pin_PB6PB7)
             #define stanby_led_io_is_out()		    JL_PORTB->DIR &= ~(BIT(6)|BIT(7))   
             #define stanby_led_OFF()			   { JL_PORTB->OUT &= ~BIT(6);JL_PORTB->OUT |= BIT(7);}
             #define stanby_led_ON()			   {  JL_PORTB->OUT |= BIT(6); JL_PORTB->OUT &= ~BIT(7);}	 

#elif defined(stanby_led_pin_PB7)
             #define stanby_led_io_is_out()      JL_PORTB->DIR &= ~BIT(7)	
             #ifdef support_stanby_io_is_low		 
                  #define stanby_led_OFF()              JL_PORTB->OUT |= BIT(7)   
                  #define stanby_led_ON()                JL_PORTB->OUT &= ~BIT(7)         
             #else 
                  #define stanby_led_OFF()               JL_PORTB->OUT &= ~BIT(7)       
                  #define stanby_led_ON()                 JL_PORTB->OUT |= BIT(7)   
             #endif 
#elif defined(stanby_led_pin_PA6)
             #define stanby_led_io_is_out()           JL_PORTA->DIR &= ~BIT(6)	
             #ifdef support_stanby_io_is_low		 
                  #define stanby_led_OFF()              JL_PORTA->OUT |= BIT(6)   
                  #define stanby_led_ON()                JL_PORTA->OUT &= ~BIT(6)         
             #else 
                  #define stanby_led_OFF()               JL_PORTA->OUT &= ~BIT(6)       
                  #define stanby_led_ON()                 JL_PORTA->OUT |= BIT(6)   
             #endif 			 
   #else 
         #error(" set_stanby_led IO ") 
   #endif 
#endif 

//-------AMP  ONLY POWER ON SET------------------------
#ifdef support_AMP_POWER_ON_SET
#ifdef AMP_POWER_ON_IO_PC14

#define AMP_POWER_ON_IO_BIT    4	   
#define Set_AMP_POWER_ON_out()		JL_PORTC->DIR &= ~BIT(AMP_POWER_ON_IO_BIT); JL_PORTC->PU |= BIT(AMP_POWER_ON_IO_BIT) 
#define Set_AMP_POWER_ON_H()		JL_PORTC->OUT|= BIT(AMP_POWER_ON_IO_BIT)	
#define Set_AMP_POWER_ON_L()		JL_PORTC->OUT &= ~BIT(AMP_POWER_ON_IO_BIT) 		


#else 
         #error(" PLAY SET support_AMP_POWER_ON_SET   IO ") 

#endif 
#ifdef support_AMP_IO_ALWAY_HIGH
#define Set_AMP_POWER_ON_IS_HIGHT()	{Set_AMP_POWER_ON_out();Set_AMP_POWER_ON_L();}
#define Set_AMP_POWER_ON_IS_LOW()		{Set_AMP_POWER_ON_out();Set_AMP_POWER_ON_H();}
#else
#define Set_AMP_POWER_ON_IS_HIGHT()	{Set_AMP_POWER_ON_out();Set_AMP_POWER_ON_H();}
#define Set_AMP_POWER_ON_IS_LOW()		{Set_AMP_POWER_ON_out();Set_AMP_POWER_ON_L();}
#endif

#endif 




#ifdef SUPPORT_DOUBLE_LED7_PANEL
#ifdef DOUBLE_LED7_DET_IO_PR2


#define DOUBLE_LED7_DET_INIT() {PORTR_PU(PORTR2,1);PORTR_PD(PORTR2,0);PORTR_HD(PORTR0,1);PORTR_DIR(PORTR2,1); PORTR_DIE(PORTR2,0);PORTR2_ADCEN_CTL(0);}
#define DOUBLE_LED7_DET_IO_IS_L()    (!PORTR_IN(PORTR2))  //PP PR2

#elif defined DOUBLE_LED7_DET_IO_PC5

#define DLED7_IO_BIT    BIT(5)
#define DOUBLE_LED7_DET_INIT() {JL_PORTC->DIR |= DLED7_IO_BIT;JL_PORTC->PU  |= DLED7_IO_BIT; }
#define DOUBLE_LED7_DET_IO_IS_L()    (!(JL_PORTC->IN & DLED7_IO_BIT))
#else
         #error(" PLAY SET DOUBLE_LED7_DET_IO   IO ") 
#endif 
#endif 


#ifdef SUPPORT_REPEAT_ON_ALL_USE_LED
#ifdef REPEAT_ON_ALL_LED_IO_PA9PA10

#define repeat_one_all_led_io_out()      JL_PORTA->DIR &= ~(BIT(9)|BIT(10))	
#define repeat_one_led_io_is_high()                JL_PORTA->OUT |= BIT(9)          
#define repeat_one_led_io_is_low()                 JL_PORTA->OUT &= ~BIT(9)   
#define repeat_all_led_io_is_high()                JL_PORTA->OUT |= BIT(10)          
#define repeat_all_led_io_is_low()                 JL_PORTA->OUT &= ~BIT(10)   

#elif defined REPEAT_ON_ALL_LED_IO_PA9PA4

#define repeat_one_all_led_io_out()      JL_PORTA->DIR &= ~(BIT(9)|BIT(4))	
#define repeat_one_led_io_is_high()                JL_PORTA->OUT |= BIT(9)          
#define repeat_one_led_io_is_low()                 JL_PORTA->OUT &= ~BIT(9)   
#define repeat_all_led_io_is_high()                JL_PORTA->OUT |= BIT(4)          
#define repeat_all_led_io_is_low()                 JL_PORTA->OUT &= ~BIT(4)   
#else
         #error(" PLAY SET REPEAT_ON_ALL_LED_IO_PA9PA10   IO ") 

#endif
#endif


#ifdef SUPPORT_BAT_DETECT
#ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
#ifdef LOW_POWER_OFF_USE_EXTERN_IO_PA10
#define LOW_POWER_OFF_USE_EXTERN_IO(x)   {if(x){JL_PORTA->DIR &= ~BIT(10);JL_PORTA->OUT |= BIT(10);}else {JL_PORTA->DIR &= ~BIT(10);JL_PORTA->OUT &=~ BIT(10);}}
#elif defined LOW_POWER_OFF_USE_EXTERN_IO_PB12
#define LOW_POWER_OFF_USE_EXTERN_IO(x)   {if(x){JL_PORTB->DIR &= ~BIT(12);JL_PORTB->OUT |= BIT(12);}else {JL_PORTB->DIR &= ~BIT(12);JL_PORTB->OUT &=~ BIT(12);}}
#endif
#endif
#endif

#if 1//def SUPPORT_BAT_DETECT
//-----------AMP POWER ON OFF------------------------------------
#ifdef AMP_POWER_ENABLE   
#ifdef  AMP_POWER_IO_PA10
#define AMP_POWER_IO(x)   {if(x){JL_PORTA->DIE |= BIT(10);JL_PORTA->DIR &= ~BIT(10);JL_PORTA->OUT |= BIT(10);}else {JL_PORTA->DIE |= BIT(10);JL_PORTA->DIR &= ~BIT(10);JL_PORTA->OUT &=~ BIT(10);}}
#endif 
#endif 
//---------POWER ON  MUTE 1S  AND LOW POWER MUTE 5S--------------------
#ifdef AMP_MUTE_ENABLE   
#ifdef  AMP_MUTE_IO_PA11
#ifdef support_vol_is_0_mute_amp
#define AMP_MUTE_IO(x)   {if(x){JL_PORTA->DIR &= ~BIT(11);JL_PORTA->OUT &=~ BIT(11);}else {JL_PORTA->DIR &= ~BIT(11);JL_PORTA->OUT |= BIT(11);}}
#else
#define AMP_MUTE_IO(x)   {if(x){JL_PORTA->DIR &= ~BIT(11);JL_PORTA->OUT |= BIT(11);}else {JL_PORTA->DIR &= ~BIT(11);JL_PORTA->OUT &=~ BIT(11);}}
#endif
#elif defined AMP_MUTE_IO_PB10
#define AMP_IO_BIT  10
#define AMP_MUTE_IO(x)   {if(x){JL_PORTB->DIR &= ~BIT(AMP_IO_BIT);JL_PORTB->OUT |= BIT(AMP_IO_BIT);}else {JL_PORTB->DIR &= ~BIT(AMP_IO_BIT);JL_PORTB->OUT &=~ BIT(AMP_IO_BIT);}}
#elif defined AMP_MUTE_IO_PB13
#define AMP_IO_BIT  13
#define AMP_MUTE_IO(x)   {if(x){JL_PORTB->DIR &= ~BIT(AMP_IO_BIT);JL_PORTB->OUT |= BIT(AMP_IO_BIT);}else {JL_PORTB->DIR &= ~BIT(AMP_IO_BIT);JL_PORTB->OUT &=~ BIT(AMP_IO_BIT);}}
#elif defined AMP_MUTE_IO_PC5
#define AMP_MUTE_IO(x)   {if(x){JL_PORTC->DIR &= ~BIT(5);JL_PORTC->OUT |= BIT(5);}else {JL_PORTC->DIR &= ~BIT(5);JL_PORTC->OUT &=~ BIT(5);}}
#elif defined AMP_MUTE_IO_PC4
#ifdef mute_io_L_is_mute
#define AMP_MUTE_IO(x)   {if(x){JL_PORTC->DIR &= ~BIT(4);JL_PORTC->OUT &=~ BIT(4);}else {JL_PORTC->DIR &= ~BIT(4);JL_PORTC->OUT |= BIT(4);}}
#else
#define AMP_MUTE_IO(x)   {if(x){JL_PORTC->DIR &= ~BIT(4);JL_PORTC->OUT |= BIT(4);}else {JL_PORTC->DIR &= ~BIT(4);JL_PORTC->OUT &=~ BIT(4);}}
#endif 
#endif 
#endif 
#endif 


#ifdef SUPPORT_REC_MODE_EXTERN_IO_VOLTOGE   
#ifdef   REC_EXTERN_IO_USE_PA11
#define SET_REC_EXTERN_IO(x)   {if(x){JL_PORTA->DIR &= ~BIT(11);JL_PORTA->OUT |= BIT(11);}else {JL_PORTA->DIR &= ~BIT(11);JL_PORTA->OUT &=~ BIT(11);}}
#endif
#endif

#ifdef SUPPORT_EXTERN_POWER_FM_SCAN_IO
#ifdef EXTERN_POWER_FM_SCAN_IO_USB_PA4
#define SET_REXTERN_POWER_FM_SCAN_IO(x)   {if(x){JL_PORTA->DIR &= ~BIT(4);JL_PORTA->OUT |= BIT(4);}else {JL_PORTA->DIR &= ~BIT(4);JL_PORTA->OUT &=~ BIT(4);}}
#endif
#endif

#ifdef SUPPORT_EXTERN_POWER_FM_MUTE_IO
#ifdef EXTERN_POWER_FM_MUTE_IO_USB_PA3
#define SET_REXTERN_POWER_FM_MUTE_IO(x)   {if(x){JL_PORTA->DIR &= ~BIT(3);JL_PORTA->OUT |= BIT(3);}else {JL_PORTA->DIR &= ~BIT(3);JL_PORTA->OUT &=~ BIT(3);}}
#endif
#endif

#ifdef SUPPORT_ENCODE_flash_led
#ifdef ENC_LED_IO_USE_PA3
#define SET_ENC_LED_IO(x)   {if(x){JL_PORTA->DIR &= ~BIT(3);JL_PORTA->OUT |= BIT(3);}else {JL_PORTA->DIR &= ~BIT(3);JL_PORTA->OUT &=~ BIT(3);}}
#elif defined(ENCODE_LED_USE_PC0)
#define SET_ENC_LED_IO(x)   {if(x){JL_PORTC->DIR &= ~BIT(0);JL_PORTC->OUT |= BIT(0);}else {JL_PORTC->DIR &= ~BIT(0);JL_PORTC->OUT &=~ BIT(0);}}
#elif defined(ENC_led_io_PB12)
#define SET_ENC_LED_IO(x)   {if(x){JL_PORTB->DIR &= ~BIT(12);JL_PORTB->OUT |= BIT(12);}else {JL_PORTB->DIR &= ~BIT(12);JL_PORTB->OUT &=~ BIT(12);}}
#endif
#endif

#ifdef SUPPORT_JH_BAT_DOUBLE_LED
#ifdef JH_BAT_DOUBLE_LED_USB_PA4PC3  // PA4-R PC3-G
#define SET_R_LED(x)   {if(x){JL_PORTA->DIR &= ~BIT(4);JL_PORTA->OUT |= BIT(4);}else {JL_PORTA->DIR &= ~BIT(4);JL_PORTA->OUT &=~ BIT(4);}}
#define SET_G_LED(x)   {if(x){JL_PORTC->DIR &= ~BIT(3);JL_PORTC->OUT |= BIT(3);}else {JL_PORTC->DIR &= ~BIT(3);JL_PORTC->OUT &=~ BIT(3);}}
#endif
#endif


#ifdef SUPPORT_JH_POWER_SWITCH_IO
#ifdef POWER_SWITCH_IO_USE_PB11  // PA4-R PC3-G
#define SET_POWER_SWITCH_IN()   {JL_PORTB->DIE |= BIT(11);JL_PORTB->DIR |= BIT(11);JL_PORTB->PD  |= BIT(11);}
#define POWER_SWITCH_CHECK()   (JL_PORTB->IN&BIT(11))
#endif
#endif


#ifdef SUPPORT_SMJ_BAT_THREE_LED
#ifdef MSJ_BAT_THREE_LED_USB_PB12PB10PB9 
#define SET_LOW_LED(x)   {if(x){JL_PORTB->DIR &= ~BIT(12);JL_PORTB->OUT |= BIT(12);}else {JL_PORTB->DIR &= ~BIT(12);JL_PORTB->OUT &=~ BIT(12);}}
#define SET_NOL_LED(x)   {if(x){JL_PORTB->DIR &= ~BIT(10);JL_PORTB->OUT |= BIT(10);}else {JL_PORTB->DIR &= ~BIT(10);JL_PORTB->OUT &=~ BIT(10);}}
#define SET_CHACK_LED(x)   {if(x){JL_PORTB->DIR &= ~BIT(9);JL_PORTB->OUT |= BIT(9);}else {JL_PORTB->DIR &= ~BIT(9);JL_PORTB->OUT &=~ BIT(9);}}
#endif
#endif




//============================================================

/*

#define USB_DP_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(0)) | ((x & 0x1)<<0))
#define USB_DP_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(2)) | ((x & 0x1)<<2))
#define USB_DP_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(4)) | ((x & 0x1)<<4))
#define USB_DP_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(6)) | ((x & 0x1)<<6))
#define USB_DP_IN()        USB_CON0&BIT(17)

#define USB_DM_OUT(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(1)) | ((x & 0x1)<<1))
#define USB_DM_DIR(x)      USB_IO_CON = ((USB_IO_CON & ~BIT(3)) | ((x & 0x1)<<3))
#define USB_DM_PD(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(5)) | ((x & 0x1)<<5))
#define USB_DM_PU(x)       USB_IO_CON = ((USB_IO_CON & ~BIT(7)) | ((x & 0x1)<<7))
#define USB_DM_IN()        USB_CON0&BIT(16)

*/
//-----------------global variable define-----------------------
#ifdef support_msg_stop_key
extern bool  play_stop_flag;
#endif


