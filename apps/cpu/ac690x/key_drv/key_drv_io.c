#include "includes.h"
#include "key_drv/key.h"
#include "key_drv/key_drv_io.h"


#if KEY_IO_EN

/*----------------------------------------------------------------------------*/
/**@brief   io按键初始化
   @param   void
   @param   void
   @return  void
   @note    void io_key_init(void)
*/
/*----------------------------------------------------------------------------*/
void io_key_init(void)
{
    KEY_INIT();
}

/*----------------------------------------------------------------------------*/
/**@brief   获取IO按键电平值
   @param   void
   @param   void
   @return  key_num:io按键号
   @note    tu8 get_iokey_value(void)
*/
/*----------------------------------------------------------------------------*/
#ifdef support_k7036_scna_mode
#include "support_k7036_scna_mode.c"
#elif defined(io_scnkey_k2754_mode)
#include "io_scnkey_k2754_mode.c"
#elif defined(io_scnkey_jl2015bt_mode)
#include "io_scnkey_jl2015bt_mode.c"
#elif defined(io_scnkey_jl2015bt_jy_9key_mode)
#include "io_scnkey_jl2015bt_jy_9key_mode.c"
#elif defined(io_scnkey_jl2017bt_ydl2001_mode)
#include "io_scnkey_jl2017bt_ydl2001_mode.c"
#else

tu8 get_iokey_value(void)
{
    //key_puts("get_iokey_value\n");
    tu8 key_num = NO_KEY;

    if(IS_KEY0_DOWN())
    {
        key_puts(" KEY0 ");
        return 0;
    }
    if(IS_KEY1_DOWN())
    {
        key_puts(" KEY1 ");
        return 1;
    }
    if(IS_KEY2_DOWN())
    {
        key_puts(" KEY2 ");
        return 2;
    }
    if(IS_KEY3_DOWN())
    {
        key_puts(" KEY3 ");
        return 3;
    }

//    KEY1_OUT_L();
//    if(IS_KEY2_DOWN())//
//    {
//        PORTA_OUT |= BIT(13);
//        return 4;
//    }
    return key_num;
}

#endif/*KEY_IO_EN*/
#endif/*KEY_IO_EN*/
