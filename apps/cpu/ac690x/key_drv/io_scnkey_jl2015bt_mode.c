
#include "common/msg_key.h"
#include "common/common.h"

//	PP-PB11	PREV-PB10	NEXT-PB9	MODE-PB8	REPEAT-PB12

tu8 get_iokey_value(void)
{

	//key_puts("get_iokey_value\n");
	tu8 key_num = NO_KEY;
	KEY_INIT();
	
	delay(50);
	
	if(IS_KEY0_DOWN()){
		//key_puts(" KEY0 ");
		return PKEY_PP;
	}
	if(IS_KEY1_DOWN()){
		//key_puts(" KEY1 ");
		return PKEY_PREV;
	}
	if(IS_KEY2_DOWN()){
		//key_puts(" KEY2 ");
		return PKEY_NEXT;
	}
	if(IS_KEY3_DOWN())
		{
		//key_puts(" KEY3 ");
		return PKEY_MODE;
	}		
	if(IS_KEY4_DOWN())
		{
		//key_puts(" KEY4 ");
		return PKEY_REPEAT;
	}
		
	return key_num;

}


