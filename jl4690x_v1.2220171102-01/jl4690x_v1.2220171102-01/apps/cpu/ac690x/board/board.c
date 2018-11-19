#include "sdk_cfg.h"
#include "timer.h"
#include "key_drv/key.h"
#include "key_drv/key.h"
#include "common/flash_cfg.h"
#include "vm/vm_api.h"
#include "rtos/os_api.h"
#include "common/common.h"
#include "clock_api.h"
#include "sys_detect.h"
#include "uart.h"
#include "hw_cpu.h"
#include "cpu.h"
#include "dac/dac.h"
#include "dac/ladc.h"
#include "irq_api.h"
#include "uart_api.h"
#include "uart_param.h"
#include "rtc/rtc_api.h"
#include "update.h"
#define FLASH_BASE_ADDR 0x1000000

extern OS_TCB  *OSTCBCur[1];
extern u8 vmm_fat[192];
extern u32 pm_usd_map[(MAX_SDRAM_SIZE + ((32*PAGE_SIZE)-1))/(32*PAGE_SIZE)];
extern void set_sydf_header_base(u32 base);
extern void set_cache_base(u32 base);
extern void bt_app_cfg();
extern void set_pwrmd(u8 sm);
extern u8 read_reset_power();
extern int main_task_init(void);
extern int TaskBtTest();

APP_USE_FLASH_SYS_CFG app_use_flash_cfg;

AT(.ver_magic_start)
const char ver_start_magic[] = {0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x5F, 0x73, 0x74, 0x61, 0x72, 0x74, 0x00};

AT(.ver_magic_end)
const char ver_end_magic[] = {0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x5F, 0x65, 0x6E, 0x64, 0x00};



/*----------------------------------------------------------------------------*/
/**@brief  异常错误中断服务程序
   @param
   @return
   @note
 */
/*----------------------------------------------------------------------------*/
void exception_isr(void )
{
    u32 tmp;

    ///printf rets & reti
    asm("mov %0, RETS " : "=r" (tmp));

	printf("\nRETS=0x%x\n", tmp);

	printf("DEBUG_MSG = 0x%x\n", JL_DEBUG->MSG);
	printf("PRP MMU_MSG = 0x%x\n", JL_DEBUG->PRP_MMU_MSG);
	printf("LSB MMU MSG = 0x%x\n", JL_DEBUG->LSB_MMU_MSG_CH);
	printf("PRP WR LIMIT MSG = 0x%x\n", JL_DEBUG->PRP_WR_LIMIT_MSG);
	printf("LSB WR LIMIT MSG = 0x%x\n", JL_DEBUG->LSB_WR_LIMIT_CH);

	asm("mov %0, RETI " : "=r" (tmp));

	printf("\nRETI=0x%x\n", tmp);
//	printf_buf((u8 *)MMU_TAG_ADDR0, 256);
     //JL_POWER->CON |= BIT(4); //异常后软复位
    while(1);
    /* JL_POWER->CON |= BIT(4); //异常后软复位 */
}
/* IRQ_REGISTER(IRQ_EXCEPTION_IDX, exception_isr);
 */

/*----------------------------------------------------------------------------*/
/**@brief  poweroff_ram_fun
   @param
   @return
   @note

 */
/*----------------------------------------------------------------------------*/
void poweroff_ram_fun()
{
    // close_wdt();//关看门狗
    uart_init(UART_BAUD_RAE); //<串口波特率
    delay(10000);
//    putchar('X');
//    putchar('K');
//    putchar('O');
    //puts("\n  ------ run ram ------- \n");
}


/*$PAGE*/


void set_g_sys_cfg(FLASH_SYS_CFG *sys_cfg,u32 cfg_addr)
{
    memcpy(sys_cfg, (void*)(FLASH_BASE_ADDR + cfg_addr), sizeof(FLASH_SYS_CFG));
    app_use_flash_cfg.cfg_zone_addr = sys_cfg->flash_cfg.cfg_zone_addr;
    app_use_flash_cfg.flash_size = sys_cfg->flash_cfg.flash_size;
    app_use_flash_cfg.cfg_zone_size = sys_cfg->flash_cfg.cfg_zone_size;
#if 0
    printf("flash_id : %x\n",   sys_cfg->flash_cfg.flash_id);
    printf("flash_size : %x\n",   sys_cfg->flash_cfg.flash_size);
    printf("flash_file_size : %x\n",   sys_cfg->flash_cfg.flash_file_size);
    printf("sdfile_head_addr : %x\n",   sys_cfg->flash_cfg.sdfile_head_addr);
    printf("spi_run_mode : %x\n",   sys_cfg->flash_cfg.spi_run_mode);
    printf("spi_div : %x\n",   sys_cfg->flash_cfg.spi_div);
    printf("flash_base : %x\n",   sys_cfg->flash_cfg.flash_base);
    printf("protected_arg : %x\n",   sys_cfg->flash_cfg.protected_arg);
    printf("cfg_zone_addr : %x\n",   sys_cfg->flash_cfg.cfg_zone_addr);
    printf("cfg_zone_size : %x\n",   sys_cfg->flash_cfg.cfg_zone_size);

    printf("sdram_refresh_cycle : %x\n",   sys_cfg->sdr_cfg.sdram_refresh_cycle);
    printf("sdram_refresh_time : %x\n",   sys_cfg->sdr_cfg.sdram_refresh_time);
    printf("sdram_cas_latency : %x\n",   sys_cfg->sdr_cfg.sdram_cas_latency);
    printf("sdram_trfc : %x\n",   sys_cfg->sdr_cfg.sdram_trfc);
    printf("sdram_trp : %x\n",   sys_cfg->sdr_cfg.sdram_trp);
    printf("sdram_trcd : %x\n",   sys_cfg->sdr_cfg.sdram_trcd);
    printf("sdram_colum : %x\n",   sys_cfg->sdr_cfg.sdram_colum);
    printf("sdram_clk_hd_en : %x\n",   sys_cfg->sdr_cfg.sdram_clk_hd_en);
    printf("sdram_trrd : %x\n",   sys_cfg->sdr_cfg.sdram_trrd);
    printf("sdram_clkoe : %x\n",   sys_cfg->sdr_cfg.sdram_clkoe);
    printf("sdram_size : %x\n",   sys_cfg->sdr_cfg.sdram_size);
    printf("sdram_fast_clock_rate : %x\n",   sys_cfg->sdr_cfg.sdram_fast_clock_rate);

    printf("pll_sel : %x\n",   sys_cfg->clk_cfg.pll_sel);
    printf("osc_freq : %x\n",   sys_cfg->clk_cfg.osc_freq);
    printf("osc_src :%x\n",   sys_cfg->clk_cfg.osc_src);
    printf("osc_hc_en : %x\n",   sys_cfg->clk_cfg.osc_hc_en);
    printf("osc_1pin_en : %x\n",   sys_cfg->clk_cfg.osc_1pin_en);
    printf("---------------------------------------------\r\n");
#endif
}
u8  wake_up_io;
void wake_io_check(void)
{
	u8 reg;
 	reg = get_wake_up_io();
	wake_up_io=reg;
	
    printf("wake up io:%x\n",reg);
	
/*
    if(reg & BIT(0))
    {
		puts("-WK_PR0\n");        
    }
    else if(reg & BIT(1))
    {
		puts("-WK_PR1\n");       
    }
    else if(reg & BIT(2))
    {
		puts("-WK_PR2\n");  
    }
    else if(reg & BIT(3))
    {
		puts("-WK_PR3\n");  
    }
    */
}

/*----------------------------------------------------------------------------*/
/**@brief  system start enter
   @param  cfg_addr - g_sys_cfg's addr ， addr - app_file's addr，res - no used
   @return
   @note

 */

/*----------------------------------------------------------------------------*/
extern void power_init(u8 mode);
extern void set_poweroff_wakeup_io();
extern void set_poweroff_wakeup_io_handle_register(void (*handle)(),void (*sleep_io_handle)(),void (*sleep_handle)());
extern void ldo5v_detect_deal(u8 mode); 
extern void set_vddio_level(u8 level);
extern void low_power_mode(u16 wakeup_cfg , u8 wakeup_edge);
extern void set_sleep_mode_wakeup_io();
extern void set_sleep_before_close_irq();
extern void enter_sleep_mode();
void  board_main(u32 cfg_addr, u32 addr, u32 res,u32 update_flag)
{
    u32 tmp;
    FLASH_SYS_CFG sys_cfg;

	update_check(update_flag);

    clock_init(SYS_CLOCK_IN, OSC_Hz, SYS_Hz);

	open_wdt(0x0f);			//set wd 32s
    uart_init(UART_BAUD_RAE); //<串口波特率

    /* printf("SFC_BAUD=%d\n", JL_SFC->BAUD); */
    /* printf("hsb_clk_hz= %u HZ\n", clock_get_sys_freq()); */
    /* printf("lsb_clk_hz= %u HZ\n", clock_get_lsb_freq()); */

	puts("\n\n***************************AC69_PowerUp**********************************\n");
 
	//查看哪个PR口唤醒softpoweroff
	wake_io_check();
    u8 *protect_info;
    protect_info=(u8 *)0x40000;
    printf_buf(protect_info,32);
    printf("--JL_POWER->CON-- : 0x%x\n", JL_POWER->CON>>5);//0:PWR_ON 1:LVD 2:WDT 3:SRST 4:POWEROFF 

    set_g_sys_cfg(&sys_cfg, cfg_addr);

	__asm__ volatile ("mov %0,ie0" : "=r"(tmp));
	printf("ie0 =%08x \n",tmp);
	__asm__ volatile ("mov %0,icfg" : "=r"(tmp));
	printf("icfg =%08x \n",tmp);
	
	/* printf("syd_cfg_addr=0x%x\n", cfg_addr); */
    set_sydf_header_base(sys_cfg.flash_cfg.sdfile_head_addr);

    set_cache_base(FLASH_BASE_ADDR);

    if(vm_init_api(&sys_cfg.flash_cfg))
	{
		while(1)
		{
		   puts("vm_init_api err\n");	
		}
	}

    vm_open_all();
    bt_app_cfg();

	/* 2:LDO  3:DCDC*/
	power_init(PWR_MODE_SELECT);

	/*LDO模式默认VDDIO是3.3V DCDC模式默认是3.0V*/
	set_vddio_level(1); //VDDIO设置成3.3V


#if 0    //设置打印PA3
	JL_IOMAP->CON1 &= ~( BIT(11)|BIT(12)|BIT(13));
	JL_PORTA->DIR &= ~BIT(3);
	JL_PORTA->PU |= BIT(3);
	JL_PORTA->PD |= BIT(3);

	/* USB_DM_PU(1); */
	/* USB_DM_PD(1); */
	/* USB_DM_DIR(0); */
#endif

#if 0  // jsuo mark
	/*
		set_poweroff_wakeup_io : set soft poweroff wakeup IO and wakeup edge  
		set_sleep_mode_wakeup_io: set sleep mode wakeup IO and wakeup edge
	*/
	
	set_poweroff_wakeup_io_handle_register(set_poweroff_wakeup_io,set_sleep_mode_wakeup_io,set_sleep_before_close_irq); 

	if(device_is_first_start()||device_is_updata_over())
	{
		puts("device first_start or updata_over\n");	
	}
	else
	{
	   ldo5v_detect_deal(1);
	}
#endif

 #ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
 	LOW_POWER_OFF_USE_EXTERN_IO(1);	
 #endif


  timer0_init();
 
#ifdef SUPPORT_TIME3_AS_RGB
	timer3_init();
#endif

    sys_init();

    main_task_init();
    OSStart();
    irq_global_enable();
    __asm__ volatile ("mov %0,ie0" : "=r"(tmp));
    printf("ie0 =%08x \n",tmp);
    __asm__ volatile ("mov %0,ie1" : "=r"(tmp));
    printf("ie1 =%08x \n",tmp);
	__asm__ volatile ("mov %0,icfg" : "=r"(tmp));
    printf("icfg =%08x \n",tmp);
    while(1)
    {
        __asm__ volatile ("idle");
        __asm__ volatile ("nop");
        __asm__ volatile ("nop");
    }
}
volatile unsigned long jiffies;


