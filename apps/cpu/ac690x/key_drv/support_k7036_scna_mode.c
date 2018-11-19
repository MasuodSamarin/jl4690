
#include "common/msg_key.h"

tu8 get_iokey_value(void)
{

    if(IS_KEY0_DOWN()){
      //  puts(" KEY0 ");
        return PKEY_MODE_POWER;
    }
    return NO_KEY;
}


