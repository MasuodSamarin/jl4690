
#include "common/msg_key.h"
#include "common/common.h"


tu8 get_iokey_value(void)
{

	  tu8 key_num = NO_KEY;
	
	  KEY_INIT();
	  
	  delay(50);
	  
	  if(IS_KEY0_DOWN())
	  {
		  key_puts("KEY1\n");
	  
		  return  PKEY_PP;	
	  }
	  if(IS_KEY1_DOWN())
	  {
		  key_puts("KEY2\n");
		  return  PKEY_PREV;  
	  }
	   if(IS_KEY2_DOWN())
	  {
		  key_puts("KEY3\n");
		  return  PKEY_NEXT; 
	  }
	if(IS_KEY3_DOWN())
	  {
		  key_puts("KEY4\n");
		  return  PKEY_STOP;	//prev
	  }

	  if(IS_KEY4_DOWN())
		{
		  key_puts("KEY5\n");
			return	PKEY_REPEAT;	  //prev
		}

	  
		  SET_KEY4_LOW();	
		  
		  delay(50);
		  
			if(IS_KEY0_DOWN())
			  {
		  key_puts("KEY6\n");
			   key_num= PKEY_EQ;	//pp 
			  }
		  
		  if(IS_KEY1_DOWN())
			{
		  key_puts("KEY7\n");
			 key_num= PKEY_VOL_DN;	  //pp 
			}
		  if(IS_KEY2_DOWN())
			{
		  key_puts("KEY8\n");
			 key_num= PKEY_VOL_UP;	  //pp 
			}
		  if(IS_KEY3_DOWN())
			{
		  key_puts("KEY9\n");
			 key_num= PKEY_MODE;	  //pp 
			}
		  
		SET_KEY4_HIGH();  
		
	  return key_num;

		
}


