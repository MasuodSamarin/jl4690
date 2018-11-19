
#include "dac/dac_api.h"
#include "dac/dac.h"

extern  u8   light_mode_mark;   //  0  OFF  1 EQ  2 ����

void  led_disp_eq(void *param)  
{


u8	eq_count,temp_vv;
u32  dac_energy_value;

static u8 rgb_led_coumt;
static u8 rgb_disp_mode=20;
static u8 no_singal_time;

	dac_energy_value=  get_dac_energy_value();


          if( dac_energy_value<0x1000)	//���źż�ʱ
          no_singal_time++;
          else 
          no_singal_time=0;
          
          if(no_singal_time>100)
          no_singal_time=110;
          
          set_all_led_io_is_out();		

if(light_mode_mark== 0	||workmode==STANBY_WORK_MODE)
           {
           set_all_led_io_off();	 
           
           }
else if (light_mode_mark==2||no_singal_time>100||dac_ctl.sys_vol_l ==0)	//���ź�
              {
              rgb_led_coumt++;
              if(rgb_led_coumt>50)
              {
              rgb_led_coumt=0;
              rgb_disp_mode++;
              }
              else 
              return;
              
              if(rgb_disp_mode>6)
              rgb_disp_mode=0; 
              
              set_all_led_io_off();	 
              
              switch(rgb_disp_mode)
              {
              case 0:   Set_1_led_io_is_on(); 	return; 
              case 1:   Set_2_led_io_is_on(); 	return; 
              case 2:   Set_3_led_io_is_on(); 	return; 
              case 3:   Set_4_led_io_is_on(); 	return; 
              case 4:   Set_5_led_io_is_on(); 	return; 
              case 5:   Set_2_led_io_is_on(); Set_4_led_io_is_on();	return; 
              case 6:   Set_3_led_io_is_on(); Set_5_led_io_is_on();	return; 
              
              }
              }

else	 /*Ƶ����ʾģʽ*/
                 {
                 
                 rgb_disp_mode=20;//��֤�����0 ��ʼ
                   
                 		rgb_led_coumt++;
                 		if(rgb_led_coumt>8)
                 		{
                 		rgb_led_coumt=0;
                 		}
                 		else 
                 		return; 	  
                 
                 
                   if(dac_ctl.sys_vol_l >10)
                 	temp_vv=(dac_ctl.sys_vol_l -1)/5+1;
                   else 
                 	temp_vv=2;										 
                 eq_count =(dac_energy_value>>12)/5%temp_vv;
                 
                 		set_all_led_io_off(); 
                   
                 	//	eq_count=eq_count%4;	
                   
                 		switch(eq_count)
                 					{
                 					case 0: 		break;
                 					case 1: 
                 					Set_1_led_io_is_on();	
                 					break;
                 
                 					case 2: 
                 					Set_1_led_io_is_on(); Set_2_led_io_is_on(); 
                 					break;
                 					case 3: 
                 					Set_1_led_io_is_on(); Set_2_led_io_is_on(); Set_3_led_io_is_on(); 
                 					break;		  
                 					case 4: 
                 					Set_1_led_io_is_on(); Set_2_led_io_is_on(); Set_3_led_io_is_on(); 
                 					Set_4_led_io_is_on(); 
                 					break;		
                 					case 5: 
                 					Set_1_led_io_is_on();	Set_2_led_io_is_on(); Set_3_led_io_is_on(); 
                 					Set_4_led_io_is_on();	Set_5_led_io_is_on(); 
                 					break;	
                 
                 					}
                   
                 }
}








