#ifndef TIMER_H
#define TIMER_H

#include "typedef.h"
#include "cpu/timer_api.h"
#include "sdk_cfg.h"

#ifdef SUPPORT_TIME3_AS_RGB
s32 timer3_init();
s32 timer3_clk_reset(void);
#endif

s32 timer0_init();
void timer1_init();
void timer1_isr();

void set_tick_timer(u32 hz );
void init_tick_timer(u32 hz);
s32 timer0_clk_reset(void);

extern u32 make_seed(void);
extern u32 get_sys_2msCount(void);

#if defined(SUPPORT_DOUBLE_LED7_PANEL)
extern u16 get_sys_halfsec(void);
#else
extern u8 get_sys_halfsec(void);
#endif


extern __timer_handle  *timer0_hl;

#if defined(SUPPORT_DOUBLE_LED7_PANEL)
struct sys_global_var_str
{
    volatile u16 sys_halfsec;
    volatile u32 g_2ms_seed ;
};

#else
struct sys_global_var_str
{
    volatile u8 sys_halfsec;
    volatile u32 g_2ms_seed ;
};

#endif


struct sys_global_var_str g_var;

#endif

