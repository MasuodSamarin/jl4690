
#include "common/msg_key.h"
#include "common/common.h"


tu8 get_iokey_value(void)
{

		//key_puts("get_iokey_value\n");
		tu8 key_num = NO_KEY;
	KEY_INIT();
	
	delay(50);
		if(IS_KEY1_DOWN()){
			//key_puts(" KEY0 ");
			return PKEY_MODE;
		}
		if(IS_KEY2_DOWN()){
			//key_puts(" KEY1 ");
			return PKEY_NEXT;
		}
		if(IS_KEY3_DOWN())
			{
			//key_puts(" KEY2 ");
			return PKEY_PREV;
		}

	
		  KEY2_OUT_L();		  
		  delay(50);
		  if(IS_KEY3_DOWN())//
		  {
			key_num=PKEY_PP;
			//  return 4;
		  }
		    KEY2_OUT_H();
			
		return key_num;

}


