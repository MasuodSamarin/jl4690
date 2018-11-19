
#include "dac/dac_api.h"
#include "dac/dac.h"
#include "common/common.h"
extern  u8   light_mode_mark;   //  0  OFF  1 EQ  2 跑马


extern u8   to_mcu_data_on;   // 0 禁止发送  1允许发送
 
 
u8  led_mode,led_colour;


void  k1_to_mcu_data (void )  
{
u8  temp,i ;


  temp=0xa0|led_mode<<3|led_colour;

    for(i=0;i<8;i++)
    {
        if(temp&0x80)
			Set_DAT_H();
		else 
			Set_DAT_L();	
		
         Set_CLK_L();  //---------|
        delay(200);
        temp<<=1;//-------|
         Set_CLK_H();  ;//---------|___|----/上升沿有效
        delay(200);
    }

	Set_DAT_H();

}





void  led_disp_eq(void *param)  
{


u8	eq_count;
u32  dac_energy_value;

static u8 rgb_led_coumt;

	dac_energy_value=  get_dac_energy_value();

  set_all_led_io_is_out();		



  switch(light_mode_mark)
  	{
        case 0: led_mode=0;led_colour=0; break;	
        case 1: led_mode=2;led_colour=0x04; break;	
        case 2: led_mode=2;led_colour=0x02; break;	
        case 3: led_mode=2;led_colour=0x01; break;	
        case 4: led_mode=2;led_colour=0x03; break;	
        case 5: led_mode=2;led_colour=0x05; break;	
        case 6: led_mode=1;led_colour=0; break;	
        case 7: led_mode=2;led_colour=0; break;	//eq
     //   case 8: led_mode=0;led_colour=0; break;	

      }

  

          
if(light_mode_mark==7)
                 {         
                   
                 		rgb_led_coumt++;

                         if(rgb_led_coumt==7)
					Set_DAT_L();//---|______   启动位 20MS
						
                 		if(rgb_led_coumt>8)
                 		{
                 		rgb_led_coumt=0;
                 		}
                 		else 
                 		return; 	  
                 
                 
								 
                 eq_count =(dac_energy_value>>12)/5%4;
                                 
                 	//	eq_count=eq_count%4;	
                   
                 		switch(eq_count)
                 					{
								case 0: 	led_colour=0;	break;                 					
								case 1: 	led_colour=0x04;	break;
								case 2: 	led_colour=0x02;	break;
								case 3: 	led_colour=0x01;	break;                 
                 					}
						k1_to_mcu_data();
                   
                 }
   else if(to_mcu_data_on) 
   	  {
           if(to_mcu_data_on==1)
	             Set_DAT_L();//---|______   启动位 20MS

				 
               to_mcu_data_on++;   //一次为10MS
                   if(to_mcu_data_on==3)   //给足30MS
                   	{
                   	to_mcu_data_on=0; //关闭发送信号标子
                    k1_to_mcu_data();
			 }

          }
}








