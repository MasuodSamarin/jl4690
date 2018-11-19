/*--------------------------------------------------------------------------*/
/**@file    LED.c
   @brief   LED ƒ£øÈ«˝∂ØΩ”ø⁄∫Ø ˝
   @details
   @author  bingquan Cai
   @date    2012-8-30
   @note    AC319N
*/

/*----------------------------------------------------------------------------*/
#include "ui/ui_api.h"

#if UI_ENABLE

#include "ui/ui_common.h"
#include "ui/led/led7_drv.h"
#include "fm_radio.h"
#include "dec/decoder_phy.h"
#include "music_ui.h"
#include "music.h"
#include "timer.h"
#include "key_drv/key.h"
#include "key_drv/key_drv_ad.h"
#include "file_operate/file_op.h"
//#include "play_file.h"
#include "dac/dac.h"
#include "rtc_setting.h"
#include "bluetooth/avctp_user.h"
#include "rtos/task_manage.h"
#ifdef SUPPORT_PT2313
#include "dev_manage\pt2313.h"
#endif
  #include "dev_manage/drv_manage.h"
//#include "dac/dac_api.h"
#include "common/common.h"
#include "sys_detect.h"


 u8  ldo_power_mod;  


#ifdef TEST_PANEL_LED
u8 bledComValue;
u8 bledGridValue;
#endif

#ifdef SUPPORT_M62429
#include "dev_manage\M62429.h"
#endif
#include "rtc/rtc_api.h"

extern bool is_dac_mute(void);

#if defined(support_bt_waiting_conn_filsh_led)
u8 bt_line_mode;
#endif
#ifdef SUPPORT_RECPLAY_STATE
extern bool bIfRecordFolder;
#endif

#if REC_EN
#include "encode/encode.h"
#endif

#ifdef support_mute_led_all_flish
extern bool mute_flag;
#endif

#ifdef support_menu_mode
u8 menumode;
#endif


#ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
u8 bModeOfAuxContained;
#endif




#if defined( support_line_pause_disp_pause)  ||defined(support_fm_pause_disp_pause)
bool   aux_pause_mark;
#endif
#ifdef SUPPORT_LOW_POWER_DELAY_DET
extern u8 bLowPowerDetDelay;
#endif
#if LED_SHOW_VOL_MAX
extern u8 bVolMaxChangeToSmallVolMax;
#endif

LED7_VAR led7_var;

#if LED_8GRIDS==14

const  u16 LED_NUMBER[10] =
{
    /*0*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F),
    /*1*/
    (u8)(LED_B | LED_C),
    /*2*/
    (u8)(LED_A | LED_B | LED_D | LED_E | LED_G| LED_H),
    /*3*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_G| LED_H),
    /*4*/
    (u8)(LED_B | LED_C | LED_F | LED_G| LED_H),
    /*5*/
    (u8)(LED_A | LED_C | LED_D | LED_F | LED_G| LED_H),
    /*6*/
    (u8)(LED_A | LED_C | LED_D | LED_E | LED_F | LED_G| LED_H),
    /*7*/
    (u8)(LED_A | LED_B | LED_C),
    /*8*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F | LED_G| LED_H),
    /*9*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_F | LED_G| LED_H),
};

const  u16 LED_LARGE_LETTER[26] =
{
    0xF7,0xFC,0x39,0xDE,0XF9,///<ABCDE
    0xF1,0xC0,0xF6,0x06,0x0E,///<FGHIJ
    0x2430,0x38,0x0536,0x37,0x3f,///<KLMNO
    0xF3,0xC0,0x20F3,0xEd,0x1201,///<PQRST
    0x3e,0x3e,0xC0,0xC0,0xC0,///<UVWXY
    0xc09///<Z
};

const  u16 LED_SMALL_LETTER[26] =
{
    0xF7,0xFC,0x39,0xDE,0XF9,///<ABCDE
    0xF1,0xC0,0xF6,0x06,0x0E,///<FGHIJ
    0x2430,0x38,0xC0,0x37,0x3f,///<KLMNO
    0xF3,0xC0,0xD0,0xEd,0x1201,///<PQRST
    0x3e,0x3e,0xC0,0xC0,0xC0,///<UVWXY
    0xc09///<Z
};

#else
const  u8 LED_NUMBER[10] =
{
    /*0*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F),
    /*1*/
    (u8)(LED_B | LED_C),
    /*2*/
    (u8)(LED_A | LED_B | LED_D | LED_E | LED_G),
    /*3*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_G),
    /*4*/
    (u8)(LED_B | LED_C | LED_F | LED_G),
    /*5*/
    (u8)(LED_A | LED_C | LED_D | LED_F | LED_G),
    /*6*/
    (u8)(LED_A | LED_C | LED_D | LED_E | LED_F | LED_G),
    /*7*/
    (u8)(LED_A | LED_B | LED_C),
    /*8*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F | LED_G),
    /*9*/
    (u8)(LED_A | LED_B | LED_C | LED_D | LED_F | LED_G),
};
#ifdef SUPPORT_HI_I_SHOW_LEFIT
const  u8 LED_LARGE_LETTER[26] =
{
    0x77,0x7C,0x39,0x5e,0x79,///<ABCDE
    0x71,0x40,0x76,0x30,0x0E,///<FGHIJ
    0x40,0x38,0x37,0x37,0x3f,///<KLMNO
    0x73,0x40,0x50,0x6d,0x78,///<PQRST
    0x3e,0x3e,0x40,0x76,0x40,///<UVWXY
    0x5b///<Z
};

const  u8 LED_SMALL_LETTER[26] =
{
    0x77,0x7C,0x58,0x5e,0x79,///<abcde
    0x71,0x40,0x76,0x30,0x0E,///<fghij
    0x40,0x38,0x37,0x54,0x5c,///<klmno
    0x73,0x67,0x50,0x6d,0x78,///<pqrst
    0x3e,0x3e,0x40,0x76,0x40,///<uvwxy
    0x6e///<z
};
#else
const  u8 LED_LARGE_LETTER[26] =
{
    0x77,0x7C,0x39,0x5e,0x79,///<ABCDE
    0x71,0x40,0x76,0x06,0x0E,///<FGHIJ
    0x40,0x38,0x37,0x37,0x3f,///<KLMNO
    0x73,0x40,0x50,0x6d,0x78,///<PQRST
    0x3e,0x3e,0x40,0x76,0x6e,///<UVWXY
    0x5b///<Z
};
const  u8 LED_SMALL_LETTER[26] =
{
    0x77,0x7C,0x58,0x5e,0x79,///<abcde
    0x71,0x40,0x76,0x06,0x0E,///<fghij
    0x40,0x38,0x37,0x54,0x5c,///<klmno
    0x73,0x67,0x50,0x6d,0x78,///<pqrst
    0x3e,0x3e,0x40,0x76,0x6e,///<uvwxy
    0x5b///<z
};

#endif


#endif

#if defined(LED_ID_4018N_2)
//  8 8:8.8
//   usb sd fm aux bat

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={

	//LED_USB,LED_SD,LED_FM,LED_AUX,LED_2POINT,LED_DOT,LED_BAT
	   0X0020, 0X0220,	0X0502,0X0010,0X0208, 0X0610,0X0240
};

#elif defined(LED_ID_4018N_2_SCG)
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	0X0020, 0X0502,0X0220,0X0010,0X0604, 0X0208,0X0610,0X0601,0X0602,0X0608
};

#elif defined(LED_ID_40T18SRB)
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0101,0x0201,0x0008,0x0010,0x0301,0x0002,0x0004},
/*num1*/	{0x0202,0x0302,0x0110,0x0502,0x0402,0x0104,0x0108},
/*num2*/ 	{0x0310,0x0404,0x0408,0x0020,0x0220,0x0208,0x0210},
/*num3*/	{0x0540,0x0620,0x0510,0x0320,0x0508,0x0420,0x0610},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	0X0040, 0X0401,0X0120,0X0140,0X0340, 0X0304,0X0440,0X0601,0X0602,0X0608
};

#elif defined(LED_ID_8848)

/*PLAY	USB  8 8:8.8 FM */
/*PAUSE   SD		   MP3*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD, LED_FM,  LED_MP3,LED_DOT,LED_2POINT
    // 0X0020, 0X0220,  0X0502,0X0010,0X0604, 0X0240,0X0610,0X0208,
	 0X0020, 0X0220,	0X0502,0X0010,0X0604, 0X0240,0X0612,0X0208, //led 8426 ∂‡¡ÀLED_MHZ 0x0602
};
#elif defined(LED_ID_4018N_8848)
/*PLAY	USB  8 8:8.8 FM */
/*PAUSE   SD		   MP3*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
   //LED_PLAY,LED_PAUSE,LED_USB, , ,LED_DOT,LED_2POINT
   //led_fm,led_sd
	 0X0020, 0X0220,	0X0502,0X0612,0X0208
};
#elif defined(LED_ID_JW_18407_2)

/*PLAY	USB  8 8:8.8 FM */
/*PAUSE   SD		   MP3*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_FM,LED_AUX,LED_REC,LED_PIONT,LED_USB,LED_DOT,LED_SD,LED_BAT1,LED_BAT2,LED_BAT3,LED_BAT4,LED_BAT5,LED_BAT6
	0X0020,0X0502,0X0220,0X0010,0X0208,0X0604,0X0610,0X0240,0X0040,0X0140,0X0340,0X0608,0X0601,0X0602
};

#elif defined(LED_ID_JW_24017_1B_JW4018D7_1B) // SUPPORT_DOUBLE_LED7_PANEL

/*PLAY	USB  8 8:8.8 FM */
/*PAUSE   SD		     MP3*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
// 0x0601  as  null
#define ICON_NULL  0x0000

const u16 led_icon_value[LED_ICON_NUMS]={

   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD, LED_2POINT,LED_DOT,LED_FM,  LED_MP3,LED_BT,LED_SD1,LED_USB1,LED_RECO,LED_REPLAY,LED_BAT01,LED_BAT02,LED_BAT03
     0X0020, 0X0220,  0X0502,0X0010,0X0208,0X0610,0X0604, 0X0240,ICON_NULL,ICON_NULL,ICON_NULL,ICON_NULL,ICON_NULL,ICON_NULL,ICON_NULL,ICON_NULL
};


/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
// LED_ID_JW4018D_1B ICON
const u16 led_icon_value1[LED_ICON_NUMS]={

   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD, LED_2POINT,LED_DOT,LED_FM,  LED_MP3,LED_BT,LED_SD1,LED_USB1,LED_RECO,LED_REPLAY,LED_BAT01,LED_BAT02,LED_BAT03,
      ICON_NULL, ICON_NULL,  ICON_NULL,ICON_NULL,0X0208,0X0610,ICON_NULL,ICON_NULL,0X0020, 0X0502,0X0220,0X0010,0X0604,0X0040,0X0140,0X0340
};

#elif defined LED_ID_27N60_8

/*
	tf	   fm
|||| 88:8.8 ||||
	usb	  aux
*/


const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0608,0x0340,0x0040,0x0508,0x0320,0x0601,0x0140},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_SD,LED_USB,LED_FM,LED_AUX,LED_2POINT,LED_DOT
	0X0020, 0X0502,0X0240,0X0604,0X0208, 0X0602
};
const u16 led_EQ[LED_EQ_NUMS]={
    0x0420,0x0510,0x0010,0x0220,0x0440,0x0610,0x0620,0x0540
};

#elif defined(LED_ID_JW84267_4)

/*
		
PLAY				MP3
PAUSE    88:8.8	       AUX
USB					FM
SD    				MHZ

*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};

const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_PLAY,LED_PAUSE,_LED_USB,LED_SD,LED_2POINT,LED_DOT,LED_MP3,LED_AUX,LED_FM,LED_MHZ
	  	0X0020,	0X0220,		0X0502,0X0010,	0X0208,	0X0610,	0X0240,	0X0601,	0X0604,	0X0602,
};



#elif defined(LED_ID_SD88N27SRB_30)

/*
	FM			REEPAT
	SD	88:8.8	MUTE
	USB			MHZ
*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
   //LED_FM,LED_ALL,LED_SD,  LED_USB,LED_2POINT, LED_MUTE,  LED_MZH,LED_DOT
	 0X0020, 0X0220,	0X0502,0X0010,0X0208, 0X0604, 0X0240,0X0610,
};
#elif defined(LED_ID_JW8426C7_1B) 
/*
	PLAY				MP3
	PAUSE 	8:88:8.8      	AUX
	USB					FM
	SD					MHZ
*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0001,0x0002,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};


const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_PLAY,LED_PAUSE,LED_USB,LED_SD,LED_2POINT,LED_DOT,LED_MP3,LED_AUX,LED_FM,LED_MHZ
	  0X0020, 0X0220,   0X0502 ,0X0010,0X0208,0X0610,0X0240,0X0601, 0x0604,0x0602
};

#elif defined(LED_ID_SB_BG06247A) 
/*
	PLAY				MP3
	PAUSE 	8:88:8.8      	AUX
	USB					FM
	SD					MHZ
*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};


const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_PLAY,LED_PAUSE,LED_USB,LED_SD,LED_2POINT,LED_DOT,LED_MP3,LED_AUX,LED_FM,LED_MHZ
	  0X0020, 0X0220,   0X0502 ,0X0010,0X0208,0X0610,0X0240,0X0601, 0x0604,0x0602
};
#elif defined(LED_ID_XH2401_7)

/*PLAY	USB  8 8:8.8 FM */
/*PAUSE   SD		   MP3*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0101,0x0201,0x0301,0x0401,0x0501,0x0601,0x0202},
/*num1*/ 	{0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0104},
/*num2*/ 	{0x0304,0x0404,0x0504,0x604,0x0408,0x0508,0x0608},
/*num3*/ 	{0x0208,0x0210,0x0220,0x0240,0x0310,0x0320,0x0340},
};
const u16 led_icon_value[LED_ICON_NUMS]={
   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD, LED_FM,  LED_MP3LED_2POINT
    // 0X0020, 0X0220,  0X0502,0X0010,0X0604, 0X0240,0X0610,0X0208,
	 0X0302, 0X0402,	0X0502,0X0602,0X0120, 0X0140,0X0108,
};

#elif defined(LED_ID_XH2408_7)

/*PLAY	USB  8 8:8.8 FM */
/*PAUSE   SD		   MP3*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0101,0x0201,0x0008,0x0010,0x0301,0x0002,0x0004},
/*num1*/ 	{0x0202,0x0302,0x0110,0x0502,0x0402,0x0104,0x0108},
/*num2*/ 	{0x0310,0x0404,0x0408,0x0020,0x0220,0x0208,0x0210},
/*num3*/ 	{0x0540,0x0620,0x0510,0x0320,0x0508,0x0420,0x0610},
};
const u16 led_icon_value[LED_ICON_NUMS]={
   //LED_PLAY,LED_PAUSE,LED_USB,  LED_SD,LED_FM,  LED_MP3, LED_DOT,LED_2POINT   
	 0X0501, 0X0504,	0X0120,0X0401, 0X0240,0X0604,0X0440,0X0304
};

#elif defined(LED_ID_88N45)

/*BT   USB  8 8:8.8 BAT 1 2 3 */
/*SD   REC		   RECPLAY */
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
//LED_BT,LED_SD,LED_USB,  LED_REC,LED_RECPLAY,LED_BAT1,LED_BAT2,LED_BAT3, LED_2POINT,  LED_DOT
0X0601, 0X0010,	0X0502,0X0602,0X0608, 0X0040,0X0140,0X0340, 0X0208,0X0610
};

#elif defined(LED_ID_JW18407_1B)

/*		  UP
	     L1 BAT1 R1
88:8.8       BAT2
	     L2  BAT3 R2
		  BAT4
		  DN
BT FM AUX REC USB CARD

*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
//LED_BT,LED_FM,LED_AUX,  LED_REC,LED_USB,LED_SD,, LED_2POINT,  LED_DOT,LED_BAT_K1,LED_BAT_K2,LED_BAT1,LED_BAT2,LED_BAT3,LED_BAT4
0X0020, 0X0502,0X0220,0X0010,0X0604, 0X0240,0X0208,0X0610, 0X0601,0X0602,0X0040,0X0140, 0X0340,0X0608
};

#elif defined(LED_ID_JW4018D_1B) //√É≈í√É¬¨√Ç¬∑√É¬•
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	0X0020, 0X0502,0X0220,0X0010,0X0604, 0X0208,0X0610,0X0040,0X0140,0X0340
};

#elif defined(LED_ID_SD40X18_1SRB_15) //√É≈í√É¬¨√Ç¬∑√É¬•
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_SD,LED_USB,LED_FM,LED_AUX,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	0X0020, 0X0502,0X0220,0X0010,0X0604, 0X0208,0X0610,0X0040,0X0140,0X0340
};

#elif defined(LED_ID_JW4018D_4)

/*  8 8:8.8*/
/*  play usb pause sd fm  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_PLAY,LED_USB,LED_PAUSE,LED_SD,LED_FM,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	  0X0020, 0X0502,0X0220,0X0010,0X0604, 0X0208,0X0610,0X0040,0X0140,0X0340
};

#elif defined(LED_ID_4018_73)
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0101,0x0201,0x0008,0x0010,0x0301,0x0002,0x0004},
/*num1*/	{0x0202,0x0302,0x0110,0x0502,0x0402,0x0104,0x0108},
/*num2*/ 	{0x0310,0x0404,0x0408,0x0020,0x0220,0x0208,0x0210},
/*num3*/	{0x0540,0x0620,0x0510,0x0320,0x0508,0x0420,0x0610},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_SD,LED_USB,LED_RECO,LED_REPLAY,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	0X0501, 0X0120,0X0504,0X0401,0X0604, 0X0304,0X0440,0X0040,0X0140,0X0340
};

#elif defined(LED_ID_4018D7_1B)
/*  8 8:8.8*/
/*  bt card usb fm aux  bat01 bat02 bat03*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0101,0x0201,0x0008,0x0010,0x0301,0x0002,0x0004},
/*num1*/	{0x0202,0x0302,0x0110,0x0502,0x0402,0x0104,0x0108},
/*num2*/ 	{0x0310,0x0404,0x0408,0x0020,0x0220,0x0208,0x0210},
/*num3*/	{0x0540,0x0620,0x0510,0x0320,0x0508,0x0420,0x0610},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_SD,LED_USB,LED_FM,LED_AUX,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	0X0501, 0X0120,0X0504,0X0401,0X0604, 0X0304,0X0440,0X0040,0X0140,0X0340
};


#elif defined(LED_ID_1600B_VFD) //√É≈í√É¬¨√Ç¬∑√É¬•
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0D02,0x0B02,0x0902,0x0702,0x0502,0x0302,0x0102},
/*num1*/ 	{0x0D01,0x0B01,0x0901,0x0701,0x0501,0x0301,0x0101},
/*num2*/ 	{0x0C80,0x0A80,0x0880,0x0680,0x0480,0x0280,0x0080},
/*num3*/ 	{0x0C08,0x0A08,0x0808,0x0608,0x0408,0x0208,0x0008},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_2PIONT,LED_DOT,LED_AM,LED_AUX,LED_FM,LED_USB,LED_DVD,LED_ECHO,LED_SW,LED_MIC,LED_CEN,LED_FRONT,LED_SURR,LED_VOLUME
	0x0201,0x0001,0x0C04,0x0C01,0x0004,0x0A04,0x0A01,0x0204,0x0804,0x0801,0x0404,0x0604,0x0601,0x0401

};

#if 1
const u16 led_EQ[LED_EQ_NUMS]={
	0x0C62,0x0A62,0x0862,0x0670,0x0470,0x0270
};
#endif



#elif defined(LED_ID_6030_C_VFD)
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0204,0x0d02,0x0310,0x0210,0x0308,0x0208,0x0201},
/*num1*/ 	{0x0004,0x0d01,0x0110,0x0010,0x0108,0x0008,0x0001},  
/*num1*/	  {0,0,0,0,0,0,0},  
/*num0*/	{0,0,0,0,0,0,0},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_MP3,LED_FM,LED_TRE,LED_AUX,LED_sw,LED_MVOL
	0x0404,0x0402,0x0401,0x0d04,0x0510,0x0410
};









#elif defined(LED_ID_JW5028B_1B)

/*
		88:8.8
PLAY				FM
PAUSE ||||00||||	AUX
USB					SD

BAT4	3	2	1
(LOW---->>>HIGH)

*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0102,0x0302,0x0502,0x0702,0x0902,0x0B02,0x0D02},
/*num1*/	{0x0101,0x0301,0x0501,0x0701,0x0901,0x0B01,0x0D01},
/*num2*/ 	{0x0080,0x0280,0x0480,0x0680,0x0880,0x0A80,0x0C80},
/*num3*/	{0x0001,0x0201,0x0401,0x0601,0x0801,0x0A01,0x0C01},
};

const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_PLAY,LED_PAUSE,_LED_USB,_LED_2POINT,LED_FM,LED_AUX,LED_SD,LED_BAT01,LED_BAT02,LED_BAT03,LED_BAT04
	0X0002, 0X0202,0X0402,0X0802,0X0C02, 0X0A02,0X0602,0X0040,0X0020,0X0010,0X0008
};

const u16 led_EQ[LED_EQ_NUMS]={0x0C04,0x0A04,0x0804,0x0604,0x0404};

#elif defined(LED_ID_LD999B_J)

/*
	(1-2-3-4 4LED)								(1-2-3-4 4LED)
0-510-20-40-80-120-160-oo					0-510-20-40-80-120-160-oo
------------------------	÷™––∫œ“ª	------------------------
		|||||||		  		88:8.8					|||||||
 HIFI									 			 HIFI
 				PLAY PAUSE  ΩÃ≤ƒFM  AUX USB
*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0C01,0x0A01,0x0801,0x0601,0x0401,0x0201,0x0001},
/*num1*/	{0x0C02,0x0A02,0x0802,0x0602,0x0402,0x0202,0x0002},
/*num2*/ 	{0x0C04,0x0A04,0x0804,0x0604,0x0404,0x0204,0x0004},
/*num3*/	{0x0C08,0x0A08,0x0808,0x0608,0x0408,0x0208,0x0008},
};

const u16 led_icon_value[LED_ICON_NUMS]={
//LED_PLAY,LED_PAUSE,LED_FM,LED_AUX,LED_USB,LED_2POINT,LED_DOT
	0X0c10, 0X0a10,0X0610,0X0410,0X0210, 0X0010,0X0702
};
// HIFI_L-0480	HIFI_R-0280
// EQ_L_U: 0C80  0A80  0880  0680
// EQ_R_U: 0D01  0B01  0901  0701
// HEARD_CHAR: 0B02 0902  0501  0301

const u16 led_EQ[LED_EQ_NUMS]={0x0C20,0x0a20,0x0820,0x0620,0x0420,0x0220,0x0020,0x0C40,0x0a40,0x0840,0x0640,0x0440,0x0240,0x0040};

#elif defined(LED_ID_JW2781)  // ZY_2036_LED


//usb play  888:88:88 repeat
/* sd pause            dts  */
/* mp3 fm    	         ac3  */
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0001,0x0201,0x0401,0x0601,0x0801,0x0A01,0x0C01},
/*num1*/ 	{0x0002,0x0202,0x0402,0x0602,0x0802,0x0A02,0x0C02},
/*num2*/ 	{0x0080,0x0280,0x0480,0x0680,0x0880,0x0A80,0x0C80},
/*num3*/ 	{0x0004,0x0204,0x0404,0x0604,0x0804,0x0A04,0x0C04},
/*num4*/	{0x0008,0x0208,0x0408,0x0608,0x0808,0x0A08,0x0C08},
/*num5*/	{0x0010,0x0210,0x0410,0x0610,0x0810,0x0A10,0x0C10},
/*num6*/	{0x0020,0x0220,0x0420,0x0620,0x0820,0x0A20,0x0C20},
};

const u16 led_icon_value[LED_ICON_NUMS]={
   //LED_USB,LED_SD,LED_MP3,  LED_FM, LED_PLAY,  LED_PAUSE,LED_2POINT,LED_REPEAT
     0X0102,0X0302,0X0502,0X0702,0X0902,   0X0B02  ,0X0440,0X0040
};

const u16 led_circle_value[8]={
  0x0901,0x0d02,0x0101,0x0301,0x0b01,0x0d01,0x0701,0x0501
};



#elif defined(LED_ID_8SD78YRG)  // ZY_2036_LED


//usb play  888:88:88 repeat
/* sd pause            dts  */
/* mp3 fm    	         ac3  */
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0001,0x0201,0x0401,0x0601,0x0801,0x0A01,0x0C01},
/*num1*/ 	{0x0002,0x0202,0x0402,0x0602,0x0802,0x0A02,0x0C02},
/*num2*/ 	{0x0080,0x0280,0x0480,0x0680,0x0880,0x0A80,0x0C80},
/*num3*/ 	{0x0004,0x0204,0x0404,0x0604,0x0804,0x0A04,0x0C04},
/*num4*/	{0x0008,0x0208,0x0408,0x0608,0x0808,0x0A08,0x0C08},
/*num5*/	{0x0010,0x0210,0x0410,0x0610,0x0810,0x0A10,0x0C10},
/*num6*/	{0x0020,0x0220,0x0420,0x0620,0x0820,0x0A20,0x0C20},
};

const u16 led_icon_value[LED_ICON_NUMS]={
   //LED_USB,LED_SD,LED_MP3,  LED_FM, LED_PLAY,  LED_PAUSE,LED_2POINT,LED_REPEAT
     0X0102,0X0302,0X0502,0X0702,0X0902,   0X0B02  ,0X0440,0X0040
};

const u16 led_circle_value[8]={
  0x0901,0x0d02,0x0101,0x0301,0x0b01,0x0d01,0x0701,0x0501
  	
};

#elif defined(LED_ID_JW6521B_1A)  // SX0212A


/*
BT	MP3		USB		SD		PLAY		PAUSE
TV	88:88:88
DVD
OPT	CDA		MP5		HDMI	MIC		MIC.VOL	   ECHO
*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ ///7PIN LED
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G LED_H LED_I LED_J LED_K LED_L LED_M LED_N */
/*num0*/ 	{0x0980,0x0920,0x0910,0x0840,0x0901,0x0902,0x0810,0x0808,0x0904,0x0908,0x0820,0x0804,0x0802,0x0801},
/*num1*/ 	{0x0B80,0x0B20,0x0B10,0x0A40,0x0B01,0x0B02,0x0A10,0x0A08,0x0b04,0x0b08,0x0a20,0x0a04,0x0a02,0x0a01},
/*num2*/ 	{0x0D80,0x0D20,0x0D10,0x0C40,0x0D01,0x0D02,0x0C10,0x0C08,0x0d04,0x0d08,0x0c20,0x0c04,0x0c02,0x0c01},
/*num3*/ 	{0x0F80,0x0F20,0x0F10,0x0E40,0x0F01,0x0F02,0x0E10,0x0E08,0x0f04,0x0f08,0x0e20,0x0e04,0x0e02,0x0e01},
/*num4*/	{0x0180,0x0120,0x0110,0x0040,0x0101,0x0102,0x0010,0x0008,0x0104,0x0108,0x0020,0x0004,0x0002,0x0001},
/*num5*/	{0x0380,0x0320,0x0310,0x0240,0x0301,0x0302,0x0210,0x0208,0x0304,0x0308,0x0220,0x0204,0x0202,0x0201},
};

const u16 led_icon_value[LED_ICON_NUMS]={
   //LED_BT,LED_MP3,LED_USB,  LED_SD, LED_PLAY,  LED_PAUSE,LED_2POINT1,LED_2POINT,LED_DOT,LED_DVD
     0X0510,0X0440,0X0480,0X0501,0X0502,   0X0504  ,0X0708,0X0704,0X0620,0X0540
};


#elif defined(LED_ID_4210TAB)
/*
FM			PLAY
USB	8 8:8.8	PAUSE
SD			MP3
//LED_FM,LED_SD,LED_USB,LED_MP3,LED_2POINT,LED_PLAY,LED_PAUSE

*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_FM,LED_SD,LED_USB,LED_MP3,LED_2POINT,LED_PLAY,LED_PAUSE
	    0X0020, 0X0010,0X0502,0X0240,0X0208, 0X0220,0X0604
};

#elif defined(LED_ID_YDL2001_VFN_35)
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0910,0x0920,0x0908,0x0902,0x0904,0x0940,0x0980},
/*num1*/ 	{0x0710,0x0720,0x0708,0x0702,0x0704,0x0740,0x0780},
/*num2*/ 	{0x0640,0x0620,0x0604,0x0601,0x0602,0x0610,0x0608},
/*num3*/ 	{0x0510,0x0520,0x0508,0x0502,0x0504,0x0540,0x0580},
/*num4*/ 	{0x0440,0x0420,0x0404,0x0401,0x0402,0x0410,0x0408},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_PAUSE,LED_PALY,LED_ONE,LED_MP3,LED_AUX,LED_2POINT,LED_ALL,led_r,led_y,led_g,led_dvd
	 0X0801,0X0802,0X0804,0X0810,0,0X0501,0X0808,0X0820,0X0840,0X0880,0X0480
};
#if 0
const u16 led_EQ[LED_EQ_NUMS][LED_EQ_BAR_GRIDS]={
/*BAR0*/	{0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080},
/*BAR1*/	{0x0101,0x0102,0x0104,0x0108,0x0180,0x0140,0x0120,0x0110},
/*BAR2*/	{0x0201,0x0202,0x0204,0x0208,0x0210,0x0220,0x0240,0x0280},
/*BAR3*/	{0x0301,0x0302,0x0301,0x0308,0x0380,0x0340,0x0320,0x0310},
};
#else


const u32 led_EQ[LED_EQ_NUMS]={ 
	#if 0
	0x0003,0x0103,0x0203,0x0303,
	0x000c,0x010c,0x020c,0x030c,
	0x0030,0x01c0,0x0230,0x03c0,
	0x00c0,0x0130,0x02c0,0x0330,
	#else
	0x0001,0x0101,0x0201,0x0301,
	0x0002,0x0102,0x0202,0x0302,
	0x0004,0x0104,0x0204,0x0304,
	0x0008,0x0108,0x0208,0x0308,
	
	0x0010,0x0180,0x0210,0x0380,
	0x0020,0x0140,0x0220,0x0340,
	0x0040,0x0120,0x0240,0x0320,
	0x0080,0x0110,0x0280,0x0310,
	#endif
};
	#endif

#elif defined(LED_ID_DB_51) //√É≈í√É¬¨√Ç¬∑√É¬•
/*  8 8:8.8*/
/*  bt sd usb reco replay  bat01 bat02 bat03*/
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0001,0x0201,0x0401,0x0601,0x0801,0x0A01,0x0C01,0x0002,0x0602,0x0402,0x0202,0x0802,0x0a02,0x0c02},
/*num1*/ 	{0x0004,0x0204,0x0404,0x0604,0x0804,0x0A04,0x0C04,0x0008,0x0608,0x0408,0x0208,0x0808,0x0a08,0x0c08},
/*num2*/ 	{0x0010,0x0210,0x0410,0x0610,0x0810,0x0A10,0x0C10,0x0020,0x0620,0x0420,0x0220,0x0820,0x0a20,0x0c20},
/*num3*/ 	{0x0040,0x0240,0x0440,0x0640,0x0840,0x0A40,0x0C40,0,0,0,0,0,0,0},
/*num1*/ 	{0x0080,0x0280,0x0480,0x0680,0x0880,0x0A80,0x0C80,0,0,0,0,0,0,0},
/*num2*/ 	{0x0101,0x0301,0x0501,0x0701,0x0901,0x0B01,0x0D01,0,0,0,0,0,0,0},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_BT,LED_PLAY,LED_PAUSE,LED_FM,LED_AUX,LED_MP3,LED_USB,LED_SD,LED_2POINT,LED_DOT
	0x0102,0x0502,0x0702,0x0504,0x0704,0x0904,0x0B04,0x0D04,0x0708,0x0508

};

#if 1
const u32 led_EQ[LED_EQ_NUMS]={
	0x0908,0x0310,0x0B10,0x0520,0x0D20,0x0740,
	0x0B08,0x0510,0x0D10,0x0720,0x0140,0x0940,
	0x0D08,0x0710,0x0120,0x0920,0x0340,0x0B40,
	0x0110,0x0910,0x0320,0x0B20,0x0540,0x0D40,

};
#endif

#elif defined(LED_ID_TW52277_3) //√å√¨¬∑√•
/*

BAT3 BAT2 BAT1 FM SD USB REC REPLAY BT
  8 8:8.8

 */

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
       /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/    {0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/    {0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/    {0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/    {0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_FM,LED_SD,LED_USB,LED_REC,LED_REPLAY,LED_BT,LED_2POINT,LED_DOT,LED_BAT01,LED_BAT02,LED_BAT03
	0X0240, 0X0502,0X0220,0X0010,0X0604, 0X0020,0X0208,0X0610,0X0601,0X0602,0x0340
};


#elif defined(LED_ID_XL5641_15R) //
/*

  8 8:8.8

 */

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
       /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/    {0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/    {0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/    {0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/    {0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_2POINT,LED_DTO
	0X0208, 0X0610
};
///--------------------------------------------
// LCD_4x9_MODE
#elif defined(LCD_ID_JXH_S6002A)
const  u16 led_nums[LED_8NUMS][LED_8GRIDS] ={ ///< √É¬ê√É‚Äö7√Ç¬∂√É¬è√É≈†√É¬Ω√É‚Äö√É¬´√Ç¬π√É≈ì√É‚Äî√Ç¬™√Ç¬ª√Ç¬ª√Ç¬±√É¬≠
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040},
/*num1*/ 	{0x0101,0x0102,0x0104,0x0108,0x0110,0x0120,0x0140},
/*num2*/ 	{0x0201,0x0202,0x0204,0x0208,0x0210,0x0220,0x0240},
/*num3*/ 	{0x0301,0x0302,0x0304,0x0308,0x0310,0x0320,0x0340},
};
//const u16 led_icon_nums[LED_ICON_NUMS]={ ///√Ç¬∂√É‚Äù√É‚Äú√Ç¬¶16√É≈Ω√Ç¬ªBIT
  //ICON_USB,ICON_SD,ICON_FM,ICON_DECIMAL,ICON_MINSEC_DEVIATE,ICON_MUTE,ICON_RAN,ICON_REPEAT,
//     0X0000, 0X0000,  0X0000,0X0000,0X0000, 0X0000,0X0000,0X0000,
//};
#elif defined(LCD_ID_ZSLCD)
/*
	sd		   (fm radio |||
	usb	88:8.8  mzhe) --same fm_dot
	folder mute rec bt
*/
const  u16 led_nums[LED_8NUMS][LED_8GRIDS] ={ ///< √É¬ê√É‚Äö7√Ç¬∂√É¬è√É≈†√É¬Ω√É‚Äö√É¬´√Ç¬π√É≈ì√É‚Äî√Ç¬™√Ç¬ª√Ç¬ª√Ç¬±√É¬≠
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0301,0x0302,0x0304,0x0308,0x0310,0x0320,0x0340},
/*num1*/ 	{0x0201,0x0202,0x0204,0x0208,0x0210,0x0220,0x0240},
/*num2*/ 	{0x0101,0x0102,0x0104,0x0108,0x0110,0x0120,0x0140},
/*num3*/ 	{0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040},
};


#elif defined(LCD_ID_HL_21716HNT) 

/*					0003			0009			0011			0015
sd		fm		0002	0103	0004	0109	0010	0111	0014	0115
00-01	0314		0102			0104			0110			0114
				0202	0203	0204	0209	0210	2011	0214	0215
usb		bt			0303			0309			0311			0315
0101	0301

foler		mute	:		REC
0201	0302	0310	0304
	
//  15 14 11 10 9  4 3 2 1 

sd		88:8.8		fm
usb
	folder  mute rec 	bt
(.=fm)

*/


const  u16 led_nums[LED_8NUMS][LED_8GRIDS] ={ ///< √É¬ê√É‚Äö7√Ç¬∂√É¬è√É≈†√É¬Ω√É‚Äö√É¬´√Ç¬π√É≈ì√É‚Äî√Ç¬™√Ç¬ª√Ç¬ª√Ç¬±√É¬≠
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0102,0x0202,0x0302,0x0201,0x0001,0x0101},
/*num1*/ 	{0x0008,0x0108,0x0208,0x0308,0x0204,0x0004,0x0104},
/*num2*/ 	{0x0020,0x0120,0x0220,0x0320,0x0210,0x0010,0x0110},
/*num3*/ 	{0x0080,0x0180,0x0280,0x0380,0x0240,0x0040,0x0140},
};
///--------------------------------------------

#elif defined(LED_ID_JW54627_1BB) //√É≈í√É¬¨√Ç¬∑√É¬•
/*  8 8:8.8*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_2POINT,LED_DOT
	0X0208, 0X0610
};

#elif defined(LED_ID_HJ820_1) // tm1628
/* 

play			mp5
pause 8 8:88	mp4
bt			mp3

*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0001,0x0201,0x0401,0x0601,0x0801,0x0A01,0x0C01},
/*num1*/ 	{0x0101,0x0301,0x0501,0x0701,0x0901,0x0B01,0x0D01},
/*num2*/ 	{0x0102,0x0302,0x0502,0x0702,0x0902,0x0B02,0x0D02},
/*num3*/ 	{0x0080,0x0280,0x0480,0x0680,0x0880,0x0A80,0x0C80},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_PLAY,LED_PAUSE,LED_BT,LED_2POINT,LED_MP5,LED_MP4,,LED_MP3
	0X0002, 0X0402, 0X0602, 0X0A02, 0X0202, 0X0C02, 0X0802
};

#elif defined(LED_ID_JH820_03) // tm1628

/* 

BT  DVD				_ 	_	 _	_
			88:8.8	_ 	_	 _	_
USB VCD				_ 	_	 _	_

					20 150 1K 10K

*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0404,0x0408,0x0410,0x0420,0x0440,0x0402,0x0401},
/*num1*/ 	{0x0a04,0x0a08,0x0a10,0x0a20,0x0a40,0x0a02,0x0a01},
/*num2*/ 	{0x0c04,0x0c08,0x0c10,0x0c20,0x0c40,0x0c02,0x0c01},
/*num3*/ 	{0x0004,0x0008,0x0010,0x0020,0x0040,0x0002,0x0001},
};

const u16 led_icon_value[LED_ICON_NUMS]={ 
//LED_BT,LED_USB,LED_2POINT,LED_20,LED_150,LED_1K,LED_10K
0X0804, 0X0810, 0X0808, 0X0220, 0X0820, 0X0620, 0X0801
};

const u16 led_EQ[LED_EQ_NUMS]={ 
    0x0210,0x0208,0x0204,
    0x0201,0x0202,0x0240,
    0x0610,0x0608,0x0604,
    0x0601,0x0602,0x0640,
};


#elif defined(LED_ID_ZY_308D) // tm1628

/*
USB SD PLAY			DVD	 MP3   AUX

B-T  PUSE       88:88	MZH     FM

 =	=	=	=	=	=	=	=

 
*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040},
/*num1*/ 	{0x0201,0x0202,0x0204,0x0208,0x0210,0x0220,0x0240},
/*num2*/ 	{0x0401,0x0402,0x0404,0x0408,0x0410,0x0420,0x0440},
/*num3*/ 	{0x0601,0x0602,0x0604,0x0608,0x0610,0x0620,0x0640},
};

const u16 led_icon_value[LED_ICON_NUMS]={ 
  //LED_USB,    LED_SD,   LED_PLAU,   LED_BT,LED_BT1,LED_PAUSE,LED_2POINT, LED_DVD,LED_MP3,LED_AUX,LED_MHZ,LED_FM,LED_FM1
     0X0801, 0X0802,0X0840,0X0804,0X0808,0X0820,0X0A02,0X0c01,0X0c02,0X0c40,0X0c04,0X0c10,0X0c20
};

const u16 led_EQ[LED_EQ_NUMS]={ 
    0x0a04,0x0a40,0x0a20,0x0810,
    0x0a08,0x0a10,0x0a01,0x0c08,
};


#elif defined(LED_ID_4018M)
/*  8 8:8.8*/
/*  BT SD USB FM PLAY PAUSE_L PAUSE_R*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={ 
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={ 
	//LED_BT,LED_SD,LED_USB,LED_FM,LED_2POINT,LED_DOT,LED_PAUSE,LED_PAUSE2,LED_PLAY
	   0X0601, 0X0010,	0X0502,0X0602,0X0208, 0X0610,0X0040,0X0140,0X0608
};

#elif defined(LED_ID_SD40X18_1SRB_15_JY) //√É≈í√É¬¨√Ç¬∑√É¬•

/*  8 8:8.8*/
/*  bt sd usb FM PLAY  PAUSE PAUSE_2 */
const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_BT,LED_SD,LED_USB,LED_FM,LED_PLAY,LED_2POINT,LED_DOT,LED_PAUSE,LED_PAUSE2
	0X0020, 0X0502,0X0220,0X0010,0X0604, 0X0208,0X0610,0X0040,0X0140
};
#elif defined(LED_ID_K1198KL_1)

/*

FM			PLAY
USB 8 8:88	PAUSE
SD			MP3

*/

const u16 led_8grid_value[LED_8NUMS][LED_8GRIDS] ={
      /*   LED_A   LED_B   LED_C  LED_D   LED_E   LED_F  LED_G */
/*num0*/ 	{0x0002,0x0004,0x0301,0x0401,0x0008,0x0101,0x0201},
/*num1*/ 	{0x0104,0x0108,0x0402,0x0120,0x0110,0x0202,0x0302},
/*num2*/ 	{0x0408,0x0210,0x0310,0x0501,0x0504,0x0304,0x0404},
/*num3*/ 	{0x0620,0x0540,0x0420,0x0508,0x0320,0x0510,0x0440},
};
const u16 led_icon_value[LED_ICON_NUMS]={
	//LED_FM,LED_USB,LED_SD,LED_2POINT,LED_PLAY,LED_PAUSE,LED_MP3
	0X0020, 0X0502,0X0010,0X0208,0X0220, 0X0604,0X0240
};
#endif



#if LED_8NUMS==7

		 #if defined(LED_ID_JW2781)||defined(LED_ID_8SD78YRG)

		 	 const u8 playmodestr[][8] =
		 	 {
		 	     "  ALL  ",
		 	     "  Fold ",
		 	     "  ONE  ",
		 	     "  rAn  ",
		 	 };

		 	 const u8 menu_string[][8] =
			{
		 	     " HELLO ",
		 	     "LOAdIN9",
		 	     "  bLUE ",
		 	     "  PC   ",
		 	     "  UP   ",
		 	     "  dN   ",
			#ifdef support_aux_led_disp_line
		 	     "LINE IN",
		 	  #elif defined support_aux_led_disp_only_line
		 	     " LINE  ",
		 	 #else
		 	     "    AUX",
			 #endif

		 	     " -AL-  ",
			 	     "  ON   ",
			 	     " 0FF   ",
			 	     
			 	     "  CH   ",
			 	     "  EN   ",
		 	     
			 #ifdef support_stanby_mod
			 	     "       ",
			 	     "  0FF  ",
			 #endif
		 	} ;

		 	 const u8 other_string[][8]=
		 	 {
		 	     "  Eq",
		 	     " VOL ",
		 	     "   P ",
		 	     " NOP   ",
			     " NOP   ",
			     #if REC_EN
			     " rec   ",
			     #endif
		 	 };

		 	 #ifdef LED_SHOW_DEVICE_PLUGIN
		 	 const u8 device_string[][8]=
		 	 {
		 	   "USb----",
		 	   "Sd-----"
		 	 };
		 	 #endif

		 #endif
#elif LED_8NUMS==6

		 	 const u8 playmodestr[][8] =
		 	 {
		 	     " ALL  ",
		 	     " Fold ",
		 	     " ONE  ",
		 	     " rAn  ",
		 	 };

		 	 const u8 menu_string[][8] =
			{
		 	     "HELLO ",
		 	     " LOAd ",
		 	     " bLUE ",
		 	     "  PC  ",
		 	     "  UP  ",
		 	     "  dN  ",
			#ifdef support_aux_led_disp_line
		 	     " LINE ",
		 	 #else
		 	     "  AUH ",
			 #endif
		 	     " -AL- ",
	 		 #ifdef SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
	 		 #ifdef support_nop_show_usb
	 		     " USb",
	 		 #elif defined support_nop_show_nodi
	 		     "NOdi",
	 		   #else
	 		     "NO  ",
	 		 #endif
	 		 #endif
	 		 #if defined(SUPPORT_AC3_MODE_IN_LINEIN_MODE)
	 		 #ifdef support_ac3_show_OPTI_CHAR
	 		     "OPTi  ",
	 		  #elif defined(support_ac3_show_vide_CHAR)
	 		        " UIdE ",
	 		  #else
	 		     " AC-3 ",
	 		 #endif	
	 		 #endif
	 		 #if defined(SUPPORT_CD_MODE_IN_LINEIN_MODE)
	 		     "  Cd  ",
	 		 #endif
	 		 #if defined(SUPPORT_DVD_MODE_IN_LINEIN_MODE)
	 		     " dUd  ",
	 		 #endif
			 
	 		     " ON  ",
	 		     " OFF  ",
	 		 #if 1
	 		      " CH ",
	 		      " EN ",
	 		 #endif

			 #ifdef support_stanby_mod
			 	     "      ",
			 	     " 0FF  ",
			 #endif
		 	} ;

		 	 const u8 other_string[][7]=
		 	 {
		 	     " Eq ",
		 	     "VOL ",
		 	     "  P ",
		 	     " NOP  ",
			     " NOP  ",
		 		 #if  REC_EN
		 		     " rec  ",
		 		     " dEL  ",
		 		     " ENd  ",
		 		 #endif
		 	 };

		 	 #ifdef LED_SHOW_DEVICE_PLUGIN
		 	 const u8 device_string[][8]=
		 	 {
		 	   "USb---",
		 	   "Sd----"
		 	 };
		 	 #endif
#elif defined(LED_ID_6030_C_VFD)
		 const u8 playmodestr[][5] =
		 {
		     "ALL ",
		     "Fold",
		     "ONE",
		     "rAn ",
		 };

		 const u8 menu_string[][5] =
		 {

		     "HI  ",
		     "LOAd",
		 #ifdef SUPPORT_BLUE_SHOW_BT_STRING
		     "bt  ",
		 #else
		     "bLUE",
		 #endif
		     "PC  ",
		     "UP  ",
		     "dN  ",
		 #ifdef support_aux_led_disp_line
		     "LINE",
		 #elif defined(support_aux_led_disp_CD)
		     "CD  ",
		 #else
		     " AUX",
		 #endif
		     "AL  ",
		 #ifdef SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
		 #ifdef support_nop_show_usb
		     " USb",
		 #elif defined support_nop_show_nodi
		     "NOdi",
		   #else
		     "NO  ",
		 #endif
		 #endif
		 #if defined(SUPPORT_AC3_MODE_IN_LINEIN_MODE)
		 #ifdef support_ac3_show_OPTI_CHAR
		     "OPTi",
		  #elif defined(support_ac3_show_vide_CHAR)
		        "UIdE",
		  #else
		     "AC-3",
		 #endif	
		 #endif
		 #if defined(SUPPORT_CD_MODE_IN_LINEIN_MODE)
		     "Cd  ",
		 #endif
		 #if defined(SUPPORT_DVD_MODE_IN_LINEIN_MODE)
		     "dUd ",
		 #endif


		 
		     " ON ",
		     " OFF",

		 #if 1
		      " CH ",
		      " EN ",
		 #endif

		 #ifdef support_stanby_mod
		 #ifdef SUPPORT_STANDBY_NO_SHOW_OFF
		     "    ",
		     "    ",
	      #elif defined SUPPORT_IDLE_SHOW_STBY
		     "STBY",
		     "STBY",
		 #else
		     "    ",
		     " 0FF",
	       #endif
		 #endif

		 #ifdef support_ksw_nop_mode
		     " USb",
		     "-Sd-",
		 #endif
		 #if  REC_EN
		     " rec",
		     " dEL",
		     " ENd",
		 #endif

		 };





		 const u8 other_string[][5]=
		 {
		     "E",
		 #ifdef support_vol_display_v_
		     "",
		  #elif defined(support_1628_show_vol_v)
		     "",
		 #else
		     "",
		 #endif
		     "",
		     " NOP",
		     " rec",
		     " 0N ",
		     " 0FF"
		 };

 	 #ifdef LED_SHOW_DEVICE_PLUGIN
 	 const u8 device_string[][5]=
 	 {
 	   " USb ",
 	   " Sd "
 	 };
 	 #endif


#else //  #if LED_8NUMS==7


		 const u8 playmodestr[][5] =
		 {
		     " ALL ",
		     "Fold",
		     " ONE ",
		     " rAn",
		 };

		 const u8 menu_string[][5] =
		 {
			 #ifdef LED_ID_YDL2001_VFN_35
			 	"HELLO",
			 #else
			 	" HI ",
			 #endif
		 //    " Lod",
		     "LOAd",
		 #ifdef SUPPORT_BLUE_SHOW_BT_STRING
		     " bt  ",
		 #else
		     "bLUE ",
		 #endif
		     " PC ",
		     " UP ",
		     " dN ",
		 #ifdef support_aux_led_disp_line
		     "LINE",
		 #elif defined(support_aux_led_disp_CD)
		     " Cd  ",
		 #else
		     " AUX",
		 #endif
		     "-AL-",
		 #ifdef SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
		 #ifdef support_nop_show_usb
		     " USb",
		 #elif defined support_nop_show_nodi
		     "NOdi",
	 	#elif defined support_nop_show_nc_
	 		"-NC-",
	 	#else
		     " NO ",
		 #endif
		 #endif
		 #if defined(SUPPORT_AC3_MODE_IN_LINEIN_MODE)
		 #ifdef support_ac3_show_OPTI_CHAR
		     "OPTi",
		  #elif defined(support_ac3_show_vide_CHAR)
		        "UIdE",
		  #else
		     "AC-3 ",
		 #endif	
		 #endif
		 #if defined(SUPPORT_CD_MODE_IN_LINEIN_MODE)
		     " Cd ",
		 #endif
		 #if defined(SUPPORT_DVD_MODE_IN_LINEIN_MODE)
		     " dUd",
		 #endif


		 
		     " ON  ",
		     " OFF  ",

		 #if 1
		      " CH ",
		      " EN ",
		 #endif

		 #ifdef support_stanby_mod
		 #ifdef SUPPORT_STANDBY_NO_SHOW_OFF
		     "    ",
		     "    ",
	      #elif defined SUPPORT_IDLE_SHOW_STBY
		     "STBY",
		     "STBY",
		 #else
		     "    ",
		     " 0FF  ",
	       #endif
		 #endif

		 #ifdef support_ksw_nop_mode
		     " USb",
		     "-Sd-",
		 #endif
		 #if  REC_EN
		     " rec",
		     " dEL",
		     " ENd",
		 #endif

		 };





		 const u8 other_string[][5]=
		 {
		     "Eq ",
		 #ifdef support_vol_display_v_
		     "V-",
		  #elif defined(support_1628_show_vol_v)
		     "V ",
		    #elif defined(LED_ID_YDL2001_VFN_35)
			 " V ",
		 #else
		     "V ",
		 #endif
		     "P ",
		     " NOP",
		     " rec",
		     " 0N ",
		     " 0FF"
		 };

 	 #ifdef LED_SHOW_DEVICE_PLUGIN
 	 const u8 device_string[][5]=
 	 {
 	 #ifdef LED_ID_YDL2001_VFN_35
 	   " USb ",
 	   " Sd  "
	 #else
 	   " USb ",
 	   " Sd "
  	 #endif
	   
 	 };
 	 #endif

#endif



/* MODE 0  clear  1 set  2 or(|) ) */
#define   cl_icon    0
#define   set_icon  1
#define   or_icon   2

#if 1//defined(SUPPORT_DOUBLE_LED7_PANEL)
void LED7_DISP_ICON(u8 mode, u16 data)
#else
void LED7_DISP_ICON(u8 mode, u8 data)
#endif

{

    if(data==0 && mode==1)
    {
        LED_STATUS =0;
        return;
    }
    else
    {
        if(mode==1)
            LED_STATUS = data;
        else if(mode==2)
            LED_STATUS |= data;
        else
            LED_STATUS &= ~data;
    }
}
/*----------------------------------------------------------------------------*/
/**@brief   Musicƒ£ Ω …Ë±∏œ‘ æ
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_dev(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_dev(u8 dev)
{
//    /*Music Device type*/


    if((music_ui.ui_curr_device == SD0_DEVICE)||(music_ui.ui_curr_device == SD1_DEVICE))
    {

	 #if REC_EN
	         if((g_rec_ctl)&&(ENC_STOP != g_rec_ctl->enable))
	         	{
		   		#if defined(SUPPORT_DOUBLE_LED7_PANEL)
		   	            led7_var.wFlashIcon |=LED_SD1;
		   		#endif
	 	            led7_var.wFlashIcon |=LED_SD;
	         	}
	         else
	         	{
	 	  		#if defined(SUPPORT_DOUBLE_LED7_PANEL)
 		            		led7_var.wFlashIcon &=~LED_SD1;
	 	  		#endif
	 	            led7_var.wFlashIcon &=~LED_SD;
	         	}
	 #endif

            LED_STATUS&=~LED_USB;
	 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
	 		LED7_DISP_ICON(or_icon,LED_SD1);//   LED_STATUS |= LED_SD;
	 #endif
    	    	LED7_DISP_ICON(or_icon,LED_SD);//   LED_STATUS |= LED_SD;

    }
    else if(music_ui.ui_curr_device == USB_DEVICE)
    {
	 #if REC_EN
	         if((g_rec_ctl)&&(ENC_STOP != g_rec_ctl->enable))
	          	{
	 		 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
	 		   	            led7_var.wFlashIcon |=LED_USB1;
	 		 #endif
	  	            led7_var.wFlashIcon |=LED_USB;
	          	}

	         else
	          	{
	 	  		 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
	 	   		            led7_var.wFlashIcon &=~LED_USB1;
	 	  		 #endif
	  	            led7_var.wFlashIcon &=~LED_USB;
	          	}
	 #endif
	  	            LED_STATUS&=~LED_SD;

	 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
       	 LED7_DISP_ICON(or_icon,LED_USB1);	//   LED_STATUS |= LED_USB;
	 #endif
       	 LED7_DISP_ICON(or_icon,LED_USB);	//   LED_STATUS |= LED_USB;
    }
}

/*----------------------------------------------------------------------------*/
/**@brief   led7_drv ◊¥Ã¨Œªª∫¥Ê«Â≥˝∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_clear_icon(void)
*/
/*----------------------------------------------------------------------------*/
void led7_clear_icon(void)
{

    led7_var.bFlashChar = 0;
    led7_var.wFlashIcon = 0;
//    led7_var.bShowBuff[4] = 0;
#ifndef LED_SCREEN_SHOW_BAT_STATUS
    led7_var.wLedIcon = 0;
#endif

}

/*----------------------------------------------------------------------------*/
/**@brief   led7_drv œ‘ æ◊¯±Í…Ë÷√
   @param   x£∫œ‘ æ∫·◊¯±Í
   @return  void
   @author  Change.tsai
   @note    void led7_setX(u8 X)
*/
/*----------------------------------------------------------------------------*/
void led7_setX(u8 X)
{
    led7_var.bCoordinateX = X;
}

/*----------------------------------------------------------------------------*/
/**@brief   LED «Â∆¡∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_null(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_null(void)
{
    led7_clear_icon();
    led7_var.bShowBuff[0] = 0;
    led7_var.bShowBuff[1] = 0;
    led7_var.bShowBuff[2] = 0;
    led7_var.bShowBuff[3] = 0;
    #if defined(LCD_4x9_MODE)
    LCD_SEG_CLEAR();
    #endif
	
}

/*----------------------------------------------------------------------------*/
/**@brief   led7_drv …®√Ë∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_init(void)
*/
/*----------------------------------------------------------------------------*/
void led7_init(void)
{

#ifndef SUPPORT_NO_USE_PANEL
    led7_clear();
    s32 ret;

#if defined(SUPPORT_TM1628_MODE)||defined(SUPPORT_PT6312_MODE)
#ifdef SUPPORT_TIME0_1MS
	ret = timer_reg_isr_fun(timer0_hl,6,led7_scan,NULL);
#elif defined(SUPPORT_TM1618_MODE)
	ret = timer_reg_isr_fun(timer0_hl,1,led7_scan,NULL);
#else
	ret = timer_reg_isr_fun(timer0_hl,3,led7_scan,NULL);

#endif
#else
#ifdef SUPPORT_TIME0_1MS
	ret = timer_reg_isr_fun(timer0_hl,2,led7_scan,NULL);

#else
	ret = timer_reg_isr_fun(timer0_hl,1,led7_scan,NULL);

#endif
#endif

    if(ret != TIMER_NO_ERR)
    {
        printf("led7_scan err = %x\n",ret);
    }
#endif
}

/*----------------------------------------------------------------------------*/
/**@brief   led7_drv µ•∏ˆ◊÷∑˚œ‘ æ∫Ø ˝
   @param   chardata£∫œ‘ æ◊÷∑˚
   @return  void
   @author  Change.tsai
   @note    void led7_show_char(u8 chardata)
*/
/*----------------------------------------------------------------------------*/
void led7_show_char(u8 chardata)
{
    //±ÿ–Î±£÷§¥´»Îµƒ≤Œ ˝∑˚∫œ∑∂Œß£¨≥Ã–Ú≤ª◊˜≈–∂œ
    //if ((chardata < ' ') || (chardata > '~') || (led7_var.bCoordinateX > 4))
    //{
    //    return;
    //}
    if ((chardata >= '0') && (chardata <= '9'))
    {
        led7_var.bShowBuff[led7_var.bCoordinateX++] = LED_NUMBER[chardata - '0'];
    }
    else if ((chardata >= 'a') && (chardata <= 'z'))
    {
        led7_var.bShowBuff[led7_var.bCoordinateX++] = LED_SMALL_LETTER[chardata - 'a'];
    }
    else if ((chardata >= 'A') && (chardata <= 'Z'))
    {
        led7_var.bShowBuff[led7_var.bCoordinateX++] = LED_LARGE_LETTER[chardata - 'A'];
    }
    else if (chardata == ':')
    {
        LED7_DISP_ICON(or_icon,LED_2POINT); //LED_STATUS |= LED_2POINT;
    }
    else if (chardata == ' ')
    {
        led7_var.bShowBuff[led7_var.bCoordinateX++] = 0;
    }
    else //if (chardata == '-')     //≤ªø…œ‘ æ
    {
        led7_var.bShowBuff[led7_var.bCoordinateX++] = BIT(6);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief   led7_drv ◊÷∑˚¥Æœ‘ æ∫Ø ˝
   @param   *str£∫◊÷∑˚¥Æµƒ÷∏’Î   offset£∫œ‘ æ∆´“∆¡ø
   @return  void
   @author  Change.tsai
   @note    void led7_show_string(u8 *str)
*/
/*----------------------------------------------------------------------------*/
void led7_show_string(u8 *str)
{
    while (0 != *str)
    {
        led7_show_char(*str++);
    }
}

/*----------------------------------------------------------------------------*/
/** @brief:
    @param:
    @return:
    @author:
    @note:
*/
/*----------------------------------------------------------------------------*/
void led7_show_string_menu(u8 menu)
{
static u8  bBtCharCnt;

    if(menu >= (sizeof(menu_string)/5))
    {
        printf("*strid(%d) is over!\n",menu);
    }
    else
    {

		 #ifdef support_bt_waiting_conn_filsh_led

		         if(menu==2 )
		         {
		 		 #ifdef LED_BT
		 		 #ifdef support_waiting_conn_all_led_flash
		 		             if(bt_line_mode &&bt_line_mode<BT_STATUS_AUTO_CONNECTINT)
		 		             {
		 		                 led7_var.wFlashIcon |= LED_BT;
		 		                 led7_var.bFlashChar |= 0xF;
		 		             }
		 		             else
		 		             {
		 		                 led7_var.wFlashIcon = 0;
		 		                 led7_var.bFlashChar = 0;
		 		             }
		 		 #else
		 		             if(bt_line_mode &&bt_line_mode <BT_STATUS_AUTO_CONNECTINT)
		 		                 led7_var.wFlashIcon |= LED_BT;
		 		             else
		 		                 led7_var.wFlashIcon = 0;
		 		 #endif
		 		 #else
		 		             if(bt_line_mode &&bt_line_mode <BT_STATUS_AUTO_CONNECTINT)
		 		 #ifdef T9LED_7_8LED_DISP
		 		                 led7_var.bFlashChar |= 0x7F;
		 		 #else
		 		                 led7_var.bFlashChar |= 0xF;
		 		 #endif
		 		             else
		 		                 led7_var.bFlashChar = 0x0;
		 		 #endif


		 	 #if LED_PLAY
		 	             if(BT_STATUS_PLAYING_MUSIC == get_bt_connect_status())
		 	                 LED7_DISP_ICON(or_icon,LED_PLAY);
		 	             else
		 	                 LED7_DISP_ICON(cl_icon,LED_PLAY);
		 	 #endif


		 	 #ifdef LED_BT
		 	             LED7_DISP_ICON(or_icon,LED_BT); // LED_STATUS |= LED_BT;
		 	 #endif
		         }

		 #endif

		 #if 1//def LED_SCREEN_SHOW_BAT_STATUS
		 
			 if(menu==MENU_WAIT)
			 	{
				  	LED7_DISP_ICON(cl_icon,LED_2POINT);
			 	}
			 
			 if(menu==MENU_BT_MAIN)
			 {
			 // 	LED7_DISP_ICON(cl_icon,LED_PLAY | LED_PAUSE);
			  	LED7_DISP_ICON(cl_icon,LED_SD|LED_USB);
			  	LED7_DISP_ICON(cl_icon,LED_2POINT);
			  	LED7_DISP_ICON(cl_icon,LED_FM|LED_DOT);
			  	LED7_DISP_ICON(cl_icon,LED_AUX);
			  	LED7_DISP_ICON(cl_icon,LED_RECO);
			  	LED7_DISP_ICON(cl_icon,LED_REPLAY);
 				LED7_DISP_ICON(cl_icon,LED_MP3);
				 #ifdef LED_FM1
				      LED_STATUS &=~(LED_FM1);	
				 #endif
				 #ifdef LED_ALL
				      LED_STATUS &=~(LED_ALL);	
				 #endif
				#ifdef LED_MHZ
			 	LED7_DISP_ICON(cl_icon,LED_MHZ);
				#endif				 			
			 }
			 if(menu==MENU_BT_MAIN)
			 {
			 
			  	LED7_DISP_ICON(cl_icon,LED_PLAY | LED_PAUSE); 
			  	LED7_DISP_ICON(cl_icon,LED_SD|LED_USB); 
			  	LED7_DISP_ICON(cl_icon,LED_2POINT); 
			  	LED7_DISP_ICON(cl_icon,LED_FM|LED_DOT); 
			  	LED7_DISP_ICON(cl_icon,LED_AUX|LED_DVD); 	
			  	LED7_DISP_ICON(cl_icon,LED_RECO); 
			  	LED7_DISP_ICON(cl_icon,LED_REPLAY); 
			 		 #ifdef LED_FM1
			 		      LED_STATUS &=~(LED_FM1);	
			 		 #endif
			 		 #ifdef LED_ALL
			 		      LED_STATUS &=~(LED_ALL);	
			 		 #endif
			 		#ifdef LED_MHZ
			 	 	LED7_DISP_ICON(cl_icon,LED_MHZ);
			 		#endif	
			  #ifdef support_bt_mode_char_running

			 	if(BT_STATUS_AUTO_CONNECTINT== get_bt_connect_status())
			 		{
			 
			 		 	if(bBtCharCnt<1)
			 		 	            led7_show_string((u8 *)"   b");
			 		 	else if(bBtCharCnt<2)
			 		 	            led7_show_string((u8 *)"  bL");
			 		 	else if(bBtCharCnt<3)
			 		 	            led7_show_string((u8 *)" bLU");
			 		 	else if(bBtCharCnt<4)
			 		 	            led7_show_string((u8 *)"bLUE");
			 		 	else if(bBtCharCnt<5)
			 		 	            led7_show_string((u8 *)"LUE ");
			 		 	else if(bBtCharCnt<6)
			 		 	            led7_show_string((u8 *)"UE  ");
			 		 	else if(bBtCharCnt<7)
			 		 	            led7_show_string((u8 *)"E   ");
			 		 
			 		 
			 		 	bBtCharCnt++;
			 		 	if(bBtCharCnt>6)
			 		 		bBtCharCnt=0;	
			 		}
			 	
			 	if (BT_STATUS_WAITINT_CONN ==get_bt_connect_status())
			 		{
			 		
			 		 	if(bBtCharCnt<1)
			 		 	            led7_show_string((u8 *)"   b");
			 		 	else if(bBtCharCnt<2)
			 		 	            led7_show_string((u8 *)"  bL");
			 		 	else if(bBtCharCnt<3)
			 		 	            led7_show_string((u8 *)" bLU");
			 		 	else if(bBtCharCnt<4)
			 		 	            led7_show_string((u8 *)"bLUE");
			 		 	else if(bBtCharCnt<5)
			 		 	            led7_show_string((u8 *)"LUE ");
			 		 	else if(bBtCharCnt<6)
			 		 	            led7_show_string((u8 *)"UE  ");
			 		 	else if(bBtCharCnt<7)
			 		 	            led7_show_string((u8 *)"E   ");
			 		 
			 		 
			 		 	bBtCharCnt++;
			 		 	if(bBtCharCnt>6)
			 		 		bBtCharCnt=0;				
			 		}
			 	else
			 		{
			 		 	led7_show_string((u8 *)"bLUE");
			 		}

	 			 #endif

			 
			 }





			 
			 if((menu==MENU_ON)||(menu==MENU_OFF))			 	
		 	{
			  	LED7_DISP_ICON(cl_icon,LED_2POINT);
			  	LED7_DISP_ICON(cl_icon,LED_DOT);
			 }
			 if((menu==MENU_STANBY_OFF)||(menu==MENU_STANBY_MAIN))
			 {
				 #ifdef LED_PAUSE2
				 	LED_STATUS &= ~LED_PAUSE2;
				 #endif
			  	LED7_DISP_ICON(cl_icon,LED_BT|LED_PLAY | LED_PAUSE);
			  	LED7_DISP_ICON(cl_icon,LED_SD|LED_USB);
			  	LED7_DISP_ICON(cl_icon,LED_2POINT);
			  	LED7_DISP_ICON(cl_icon,LED_FM|LED_DOT);
			  	LED7_DISP_ICON(cl_icon,LED_AUX);
			  	LED7_DISP_ICON(cl_icon,LED_RECO);
			  	LED7_DISP_ICON(cl_icon,LED_REPLAY);
 				LED7_DISP_ICON(cl_icon,LED_MP3);
		 	 #ifdef LED_DVD
				 	 LED_STATUS &=~(LED_DVD);	
		 	 #endif
				 #ifdef LED_FM1
				      LED_STATUS &=~(LED_FM1);	
				 #endif
				#ifdef LED_BT1
				      LED_STATUS &=~(LED_BT1);	
				 #endif
				 #ifdef LED_ALL
				      LED_STATUS &=~(LED_ALL);	
				 #endif
			 	#ifdef LED_MHZ
			  	LED7_DISP_ICON(cl_icon,LED_MHZ);
			 	#endif				 
		 		#if defined SUPPORT_IDLE_MODE_SHOW_2POINT_FLASH
		 		 	LED_STATUS= LED_2POINT;
		 		 	led7_var.wFlashIcon = LED_2POINT;
		 		#endif				
			 }
			 
		 #endif

	if(menu==MENU_REC_DEL)
	 	LED7_DISP_ICON(cl_icon,LED_2POINT);

#ifdef LED_AUX
        if(menu==MENU_AUX_MAIN)
        	{

		 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
		 	if((bModeOfAuxContained==mode_ac3)||(bModeOfAuxContained==mode_dvd))
		 	{
		 		LED7_DISP_ICON(cl_icon,LED_AUX);	// LED_STATUS |= LED_AUX;
		 	}
		 	else if(bModeOfAuxContained==mode_aux)
	 		{
	 			LED7_DISP_ICON(or_icon,LED_AUX);	// LED_STATUS |= LED_AUX;
	 		}
		 #else
	 		LED7_DISP_ICON(or_icon,LED_AUX);	// LED_STATUS |= LED_AUX;
		 #endif




		
		 #ifdef LED_ID_6030_C_VFD
		//		UI_menu(MENU_VOL_MENU);
			 itoa2(pt2313data[PT_VOLUME]);
			 led7_show_string((u8 *)bcd_number);
	 		LED7_DISP_ICON(or_icon,LED_VOLUME);
		#elif defined(LED_ID_YDL2001_VFN_35)
			    led7_show_string((u8 *)" AUX  ");
	
		#else
			#ifdef support_aux_led_disp_line
				#ifdef LED_ID_DB_51
	 		           led7_show_string((u8 *)" LINE ");
				#else
	 		           led7_show_string((u8 *)"LINE");
				#endif
			#elif defined(support_aux_led_disp_line_in)
		           led7_show_string((u8 *)"LINE IN");			
			#elif defined(support_aux_led_disp_aux)
		           led7_show_string((u8 *)" AUX");
			#endif
		 
	 	#endif
		 
        	}
		else
#endif



	 #ifdef SUPPORT_DOUBLE_LINEIN
	        if((menu==MENU_AUX_MAIN)&&(workmode ==LINE_WORK_MODE_2 ))
	             led7_show_string((u8 *)" CD ");
	 	 else
	 #endif


	 #ifdef support_stanby_mod
		 #if defined(support_stanby_sanyang_disp___) ||defined(support_stanby_filsh__)
		         if(workmode==STANBY_WORK_MODE)
		             led7_var.bFlashChar |= 0xF;
		 #endif
	         if(workmode==STANBY_WORK_MODE && menu==MENU_WAIT)
	         {
	             led7_show_string((u8 *)"	");
	         }
	         else
	 #endif

            led7_show_string((u8 *)menu_string[menu]);
    }
}

void led7_show_linin_main(u8 menu)
{

#ifdef SUPPORT_MULTI_INPUT_MODE

	LED7_DISP_ICON(cl_icon,LED_PLAY | LED_PAUSE);
	LED7_DISP_ICON(cl_icon,LED_SD|LED_USB);
	LED7_DISP_ICON(cl_icon,LED_FM|LED_DOT);
	LED7_DISP_ICON(cl_icon,LED_2POINT);
 	LED7_DISP_ICON(cl_icon,LED_BT);
 	LED7_DISP_ICON(cl_icon,LED_RECO);
 	LED7_DISP_ICON(cl_icon,LED_REPLAY);
 	LED7_DISP_ICON(cl_icon,LED_MP3);
	 #ifdef LED_PAUSE2
	 	LED_STATUS &= ~LED_PAUSE2;
	 #endif
	
	 #ifdef LED_FM1
	      LED_STATUS &=~(LED_FM1);	
	 #endif
	#ifdef LED_BT1
	      LED_STATUS &=~(LED_BT1);	
	 #endif
	#ifdef LED_MHZ
 	LED7_DISP_ICON(cl_icon,LED_MHZ);
	#endif
	
	 #ifdef LED_ALL
	 	 LED_STATUS &=~(LED_ALL);	
	 #endif
	 
        switch (bMultiExternInputSel)
        	{
			 case INPUT_AUX0_MODE:
		 	 #ifdef LED_DVD
				 	 LED_STATUS &=~(LED_DVD);	
		 	 #endif
			  #ifdef LED_AUX
			              LED7_DISP_ICON(or_icon,LED_AUX);	// LED_STATUS |= LED_AUX;
			  #endif
				    led7_show_string_menu(menu);
			break;

	        	#ifdef SUPPOR_MP3_NOP_IN_AUX_MODE
	 			 case INPUT_NOP_MODE:
	 				#ifdef SUPPORT_MP3_NOP_SHOW__NC_
	 		 			    led7_show_string((u8 *)"-NC-");
	 				#else
	 		 			    led7_show_string((u8 *)" USB");
	 				#endif
	 		 	break;
	 		#endif

	        	#ifdef SUPPOR_INPUT_AUX1
			 case INPUT_AUX1_MODE:

		 	 #ifdef LED_DVD
		 	 	 LED_STATUS |=(LED_DVD);	
		 	 #endif
			 	 LED_STATUS &=~(LED_AUX);	

			 	#ifdef SUPPORT_AUX1_SHOW_DVD
				    led7_show_string((u8 *)" DVD");
				#elif defined(LED_ID_YDL2001_VFN_35)
				    led7_show_string((u8 *)" DVD ");
				#elif defined(SUPPORT_AUX1_SHOW_AC_3)
				    led7_show_string((u8 *)"AC-3");
				#else
				    led7_show_string((u8 *)"AUX1");
				#endif
			 break;
	 		#endif

	        	#ifdef SUPPOR_INPUT_AUX2
			 case INPUT_AUX1_MODE:
			    led7_show_string((u8 *)"AUX2");
			break;
	 		#endif
		}
#else
//    led7_var.wLedIcon = 0;
	 #ifdef LED_PAUSE2
	 	LED_STATUS &= ~LED_PAUSE2;
	 #endif

	LED7_DISP_ICON(cl_icon,LED_PLAY | LED_PAUSE);
	LED7_DISP_ICON(cl_icon,LED_SD|LED_USB);
	LED7_DISP_ICON(cl_icon,LED_FM|LED_DOT);
	LED7_DISP_ICON(cl_icon,LED_2POINT);
 	LED7_DISP_ICON(cl_icon,LED_BT);
 	LED7_DISP_ICON(cl_icon,LED_RECO);
 	LED7_DISP_ICON(cl_icon,LED_REPLAY);
 	LED7_DISP_ICON(cl_icon,LED_MP3);
	 #ifdef LED_FM1
	      LED_STATUS &=~(LED_FM1);	
	 #endif
	#ifdef LED_BT1
	      LED_STATUS &=~(LED_BT1);	
	 #endif
	#ifdef LED_MHZ
 	LED7_DISP_ICON(cl_icon,LED_MHZ);
	#endif
	 #ifdef LED_ALL
	 	 LED_STATUS &=~(LED_ALL);	
	 #endif
 	 #if 0//def SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
	 	if(workmode==AC3_WORK_MODE)
	 		{
				 #ifdef LED_DVD
				 	LED7_DISP_ICON(set_icon,LED_DVD);
				 #endif
				 #ifdef LED_DVD
				 	LED7_DISP_ICON(cl_icon,LED_AUX);
				 #endif
				 
	 		}
 	 	
 	 #endif
		 #ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
		 	if((bModeOfAuxContained==mode_ac3)||(bModeOfAuxContained==mode_dvd))
		 	{
		 		LED7_DISP_ICON(cl_icon,LED_AUX);	// LED_STATUS |= LED_AUX;
		 	}
		 	else if(bModeOfAuxContained==mode_aux)
	 		{
	 			LED7_DISP_ICON(or_icon,LED_AUX);	// LED_STATUS |= LED_AUX;
	 		}
		 #else
			  #ifdef LED_AUX
			              LED7_DISP_ICON(or_icon,LED_AUX);	// LED_STATUS |= LED_AUX;
			  #endif
		 #endif


    led7_show_string_menu(menu);
#endif

#if REC_EN

    RECORD_OP_API * rec_var_p;
    REC_CTL * rec_ctl_var;

    rec_var_p = *(RECORD_OP_API **)UI_var.ui_buf_adr;
    if((UI_var.ui_buf_adr)&&(rec_var_p))
    {
        rec_ctl_var = rec_var_p->rec_ctl;

        LED7_DISP_ICON(cl_icon,LED_PLAY | LED_PAUSE);  //LED_STATUS &= ~(LED_PLAY | LED_PAUSE);
        LED7_DISP_ICON(cl_icon,LED_SD|LED_USB); // LED_STATUS &= ~(LED_SD|LED_USB);
	 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
        LED7_DISP_ICON(cl_icon,LED_SD1|LED_USB1); // LED_STATUS &= ~(LED_SD|LED_USB);
	 #endif
 	 #ifdef LED_PAUSE2
 	 	LED_STATUS &= ~LED_PAUSE2;
 	 #endif

	#ifdef SUPPORT_AC3_MODE_IN_LINEIN_MODE
	if((menu == MENU_AUX_MAIN)||(menu == MENU_AC3_MAIN)||(menu == MENU_BT_MAIN))
	#else
        if((menu == MENU_AUX_MAIN)||(menu == MENU_BT_MAIN))
	#endif
        {
            if((rec_ctl_var)&&(ENC_STOP !=rec_ctl_var->enable))
            {
                if (ENC_STAR == rec_ctl_var->enable)
                    LED7_DISP_ICON(or_icon,LED_PLAY);  //LED_STATUS |= LED_PLAY;
                else if(ENC_PAUS == rec_ctl_var->enable)
                	{
	                    LED7_DISP_ICON(or_icon,LED_PAUSE);  //LED_STATUS |= LED_PAUSE;
			 	 #ifdef LED_PAUSE2
			 	 	LED_STATUS |= LED_PAUSE2;			 
			 	 #endif                    
                	}
                led7_show_dev(rec_ctl_var->curr_device);
            }
        }
    }
#endif
}


#if defined( support_line_pause_disp_pause)  ||defined(support_fm_pause_disp_pause)
void led7_show_linin_fm_pause(void)
{
    led7_show_string((u8 *)"PAUS");
    LED7_DISP_ICON(set_icon, 0); //  LED_STATUS=0;
}
#endif

/*----------------------------------------------------------------------------*/
/**@brief   Music ≤•∑≈Œƒº˛∫≈œ‘ æ∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_filenumber(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_filenumber(void)
{

#if 1//def LED_SCREEN_SHOW_BAT_STATUS
 	LED7_DISP_ICON(cl_icon,LED_2POINT);
#endif
 #ifdef SUPPORT_TY_8848_OFF_ICON
    LED_STATUS &=~(LED_MP3|LED_PLAY);
 #endif



#ifdef LED_ID_6030_C_VFD
MUSIC_DIS_VAR *music_var;

music_var = (MUSIC_DIS_VAR*)UI_var.ui_buf_adr;


if(music_var)
{
	/*Music File Number info*/
	//printf("ui_music.ui_play_file_num = %u----\n",ui_music.ui_play_file_num);
	itoa2(music_var->ui_curr_file);
	led7_show_string((u8 *)bcd_number);
}
LED7_DISP_ICON(or_icon,LED_MP3);


#else


#if LED_8NUMS==7|| LED_8NUMS==6//||LED_8NUMS==5
	led7_show_music_main();
#else
    MUSIC_DIS_VAR *music_var;

    music_var = (MUSIC_DIS_VAR*)UI_var.ui_buf_adr;

    if(music_var)
    {
        /*Music File Number info*/
        //printf("ui_music.ui_play_file_num = %u----\n",ui_music.ui_play_file_num);
    #if LED_8NUMS==5
	led7_show_string((u8 *)" ");
    #elif LED_8NUMS==7
	led7_show_string((u8 *)"   ");
    #endif
        itoa4(music_var->ui_curr_file);
        led7_show_string((u8 *)bcd_number);
    }
#endif
#endif

}


/*----------------------------------------------------------------------------*/
/**@brief   ∫ÏÕ‚ ‰»ÎŒƒº˛∫≈œ‘ æ∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_IR_number(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_IR_number(s32 arg)
{
    u16 ir_num;
    ir_num = (u16)(arg&0xffff);
    /*IR File Number info*/
	
	// show erro
	if(ir_num>9999)
		return;
	

#if 1//def LED_SCREEN_SHOW_BAT_STATUS
 	LED7_DISP_ICON(cl_icon,LED_DOT);
 	LED7_DISP_ICON(cl_icon,LED_2POINT);
#endif

 #ifdef SUPPORT_TY_8848_OFF_ICON
    LED_STATUS &=~(LED_USB|LED_SD|LED_MP3|LED_PLAY|LED_FM);
 #endif

   #if LED_8NUMS==5
   	led7_show_char('0');
   #elif LED_8NUMS==7
    led7_show_string((u8 *)"   ");
   #elif LED_8NUMS==6
    led7_show_string((u8 *)" ");
   #endif
    itoa4(ir_num);
    led7_show_string((u8 *)bcd_number);

   #if LED_8NUMS==6
    led7_show_string((u8 *)" ");
   #endif
}

/*----------------------------------------------------------------------------*/
/**@brief   Musicƒ£ Ω œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_music_main(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_music_main(void)
{
    //led7_show_string((u8*)"MUSI");
    u32 play_time;
    MUSIC_DIS_VAR *music_var;


{
 	LED7_DISP_ICON(cl_icon,LED_FM|LED_DOT);
 	LED7_DISP_ICON(cl_icon,LED_AUX);
 	LED7_DISP_ICON(cl_icon,LED_BT);
	 #ifdef LED_DVD
	 	 LED_STATUS &=~(LED_DVD);	
	 #endif
	 #ifdef LED_FM1
	      LED_STATUS &=~(LED_FM1);	
	 #endif
	 #ifdef LED_BT1
	 LED_STATUS &=~(LED_BT1);	
	 #endif
 	LED7_DISP_ICON(cl_icon,LED_RECO);
	#ifdef LED_MHZ
 	LED7_DISP_ICON(cl_icon,LED_MHZ);
	#endif
}


 #ifdef LED_ID_6030_C_VFD
 
		 LED7_DISP_ICON(or_icon,LED_MP3);
	//	UI_menu(MENU_VOL_MENU);
			 itoa2(pt2313data[PT_VOLUME]);
			 led7_show_string((u8 *)bcd_number);
			 LED7_DISP_ICON(or_icon,LED_VOLUME);
#else


#ifdef support_led_disp_pause

	 #ifdef support_music_play_pause_PROMPT_EN
	     if (*music_ui.ui_curr_statu == DECODER_PAUSE ||dec_status == DECODER_PAUSE)
	 #else
	     if (*music_ui.ui_curr_statu == DECODER_PAUSE)
	 #endif
	     {
	 	 #if 0//defined(support_led_user_1888)||defined(support_1888_eq_led)
		 		 #ifdef support_msg_stop_key
	 		         if( play_stop_flag)
	 		             led7_show_string((u8 *)" STO")  ;
	 		         else
		 		 #endif
		 		             led7_show_string((u8 *)" PAU")  ;

		 		         LED7_DISP_ICON(or_icon,LED_MP3);
 		 #elif  defined(MEW_LED_7_8LED_DISP)||defined(T9LED_7_8LED_DISP)
		 		 #ifdef MEW_LED_7_8LED_DISP
	 		         disc_run_mode =3;
	 		         led7_var.bFlashChar |= 0x7F;
		 		 #endif
		 		 #ifdef support_msg_stop_key
	 		         if( play_stop_flag)
	 		             led7_show_string((u8 *)"TOP   S")   ;  //STOP  // 5671234
	 		         else
		 		 #endif
	 		         {
	 		             led7_show_string((u8 *)"USE  PA");  //PAUSE
			 		 #if LED_PAUSE
		 		             LED7_DISP_ICON(or_icon,LED_PAUSE );//  LED_STATUS |= LED_PLAY;
			 		 #endif
	 		         }
	 		         LED7_DISP_ICON(or_icon,LED_MP3);

	 	 #else  //

			 #ifdef support_msg_stop_key
				 if( play_stop_flag)
				 	{
				 	   #if LED_8NUMS==5
				 	     led7_show_string((u8 *)" STOP");
				 	   #elif LED_8NUMS==7
				 	     led7_show_string((u8 *)"STOP   ");
				 	   #elif LED_8NUMS==6
				 	     led7_show_string((u8 *)"STOP  ");
				 	   #else
				 	     led7_show_string((u8 *)"STOP")	;
				 	   #endif
					 }
			 else
			 #endif
			         {
			 	   #if LED_8NUMS==5
			 	     led7_show_string((u8 *)" PAUS");
			 	   #elif LED_8NUMS==7
			 	     led7_show_string((u8 *)"PAUSE  ");
			 	   #elif LED_8NUMS==6
			 	     led7_show_string((u8 *)"PAUSE ");
			 	   #else
			 	     led7_show_string((u8 *)"PAUS")	;
			 	   #endif

			             LED7_DISP_ICON(or_icon,LED_PAUSE );
				 	 #ifdef LED_PAUSE2
				 	 	LED_STATUS |= LED_PAUSE2;			 
				 	 #endif
				   
				 #ifdef   support_play_flash_play_iocn
					 led7_var.wFlashIcon &=~LED_PLAY;
				 #endif
			         }
	               	 LED7_DISP_ICON(cl_icon,LED_PLAY); 					 
			         LED7_DISP_ICON(or_icon,LED_MP3);
			         LED7_DISP_ICON(cl_icon,LED_2POINT);
			 #if LED_2POINT1
			 	LED_STATUS &=~(LED_2POINT1);
			 #endif

			 
			 #if LED_MP3
			 	LED_STATUS &=~(LED_MP3);
			 #endif

	 	 #endif
	     }
	     else
#endif

	 #if defined support_msg_stop_key && !defined support_led_disp_pause
		 if( play_stop_flag)
		 	{
		 	   #if LED_8NUMS==5
		 	     led7_show_string((u8 *)" STOP");
		 	   #elif LED_8NUMS==7
		 	     led7_show_string((u8 *)"STOP   ");
		 	   #elif LED_8NUMS==6
		 	     led7_show_string((u8 *)" STOP ");
		 	   #else
		 	     led7_show_string((u8 *)"STOP")	;
		 	   #endif
			 }
	 else
	 #endif

    {
        music_var = (MUSIC_DIS_VAR*)UI_var.ui_buf_adr;

        if(music_var)
        {
            /*Music Play time info*/
            play_time = music_var->play_time;


	    #if LED_8NUMS==5
		 	     led7_show_string((u8 *)" ");
	    #elif LED_8NUMS==7  //show cur file num

		    itoa3(music_var->ui_curr_file%1000);
		    led7_show_string((u8 *)bcd_number);

	    #elif LED_8NUMS==6  //show cur file num

		    itoa2(music_var->ui_curr_file%100);
		    led7_show_string((u8 *)bcd_number);
	    #endif

            itoa2(play_time/60);
            led7_show_string((u8 *)bcd_number);

            itoa2(play_time%60);
            led7_show_string((u8 *)bcd_number);

            /* led7_show_dev(); */
            led7_show_dev(music_var->ui_curr_device);

            //   LED_STATUS |= LED_2POINT | LED_MP3;
            LED7_DISP_ICON(or_icon,LED_MP3|LED_2POINT);
 	 #if LED_2POINT1
	     LED_STATUS &=~(LED_2POINT1);
	 #endif


           if (*music_var->ui_curr_statu == DECODER_PLAY)
            {
                LED7_DISP_ICON(or_icon,LED_PLAY);  // LED_STATUS |= LED_PLAY;
                LED7_DISP_ICON(cl_icon,LED_PAUSE); //LED_STATUS &= ~LED_PAUSE;
                led7_var.wFlashIcon |= LED_2POINT;
	         #if 	defined(LED_ID_JW2781)
	 		led7_var.bEqCircleIfPlay=TRUE;
	 	#endif
	 	 #if LED_2POINT1
	 	     LED_STATUS |=(LED_2POINT1);
	 	 #endif
		 	 #ifdef LED_PAUSE2
		 	 	LED_STATUS &= ~LED_PAUSE2;
		 	 #endif

            }
            else if (*music_var->ui_curr_statu == DECODER_PAUSE)
            {
	        #if 	   defined(LED_ID_JW2781)
	 		led7_var.bEqCircleIfPlay=FALSE;
	        #endif

                LED7_DISP_ICON(cl_icon,LED_PLAY);  //LED_STATUS &= ~LED_PLAY;
                LED7_DISP_ICON(or_icon,LED_PAUSE);   //LED_STATUS |= LED_PAUSE;
	 	 #ifdef LED_PAUSE2
	 	 	LED_STATUS |= LED_PAUSE2;
	 	 #endif




		 
            }

        }


#ifdef LED_ALL
	if(play_mode == REPEAT_ALL)
	     LED_STATUS |=(LED_ALL);
	else
	     LED_STATUS &=~(LED_ALL);	
#endif

        //
        //    if(mute)
        //    {
        //        led7_var.wFlashIcon |= LED_MP3;
        //        led7_var.bFlashChar = 0x0f;
        //    }
        //    else
        //    {
        //        led7_var.wFlashIcon &= ~LED_MP3;
        //        led7_var.bFlashChar = 0x00;
        //    }
    }

#endif

	 
}

/*----------------------------------------------------------------------------*/
/**@brief   EQœ‘ æ∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_eq(s32 arg)
*/
/*----------------------------------------------------------------------------*/
void led7_show_eq(s32 arg)
{

#if 1//def LED_SCREEN_SHOW_BAT_STATUS
 	LED7_DISP_ICON(cl_icon,LED_2POINT);
#endif
 #ifdef SUPPORT_TY_8848_OFF_ICON
    LED_STATUS &=~(LED_MP3|LED_PLAY);
 #endif

#ifdef SUPPORT_EQ_SHOW_CHAR
    u8 eq_cnt;
    eq_cnt = (u8)arg;

   #if LED_8NUMS==7
	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)" NOr   ");
				break;
			case 1:
				   led7_show_string((u8 *)" rOC   ");
				break;
			case 2:
				   led7_show_string((u8 *)" POP   ");
				break;
			case 3:
				   led7_show_string((u8 *)" CLA   ");
				break;
			case 4:
				   led7_show_string((u8 *)" JAZ   ");
				break;
			case 5:
				   led7_show_string((u8 *)" SOF   ");
				break;
			default:
			    break;
	   }
	   
	   	

#else
	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)" NOr");
				break;
			case 1:
				   led7_show_string((u8 *)" rOC");
				break;
			case 2:
				   led7_show_string((u8 *)" POP");
				break;
			case 3:
				   led7_show_string((u8 *)" CLA");
				break;
			case 4:
				   led7_show_string((u8 *)" JAZ");
				break;
			case 5:
				   led7_show_string((u8 *)" SOF");
				break;
			default:
			    break;
	   }
#endif
	
#elif defined SUPPORT_EQ_ZY_LED6_SHOW_CHAR
// 3£∫EQÀ≥–Ú£∫NORMAL-POP-ROCK-JAZZ-CLASSI-COUNTR

    u8 eq_cnt;
    eq_cnt = (u8)arg;

	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)"NORMAL");
				break;
			case 1:
				   led7_show_string((u8 *)"  POP ");
				break;
			case 2:
				   led7_show_string((u8 *)" ROCK");
				break;
			case 3:
				   led7_show_string((u8 *)" JAZZ ");

				break;
			case 4:
				   led7_show_string((u8 *)"CLASSI");
				break;
			case 5:
				   led7_show_string((u8 *)"COUNTR");
				break;
			default:
			    break;
	   }
#elif defined SUPPORT_EQ_ZY_JY_SHOW_CHAR
// 3£∫EQÀ≥–Ú£∫NOR-POP-ROC-JAZ-CLA-COU

    u8 eq_cnt;
    eq_cnt = (u8)arg;

   #if LED_8NUMS==7
	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)"NOr    ");
				break;
			case 1:
				   led7_show_string((u8 *)"POP    ");
				break;
			case 2:
				   led7_show_string((u8 *)"rOC    ");
				break;
			case 3:
				   led7_show_string((u8 *)"JAZ    ");

				break;
			case 4:
				   led7_show_string((u8 *)"CLA    ");
				break;
			case 5:
				   led7_show_string((u8 *)"COU    ");
				break;
			default:
			    break;
	   }



   #elif LED_8NUMS==6

	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)"NOr   ");
				break;
			case 1:
				   led7_show_string((u8 *)"POP   ");
				break;
			case 2:
				   led7_show_string((u8 *)"rOC   ");
				break;
			case 3:
				   led7_show_string((u8 *)"JAZ   ");

				break;
			case 4:
				   led7_show_string((u8 *)"CLA   ");
				break;
			case 5:
				   led7_show_string((u8 *)"COU   ");
				break;
			default:
			    break;
	   }

   #elif LED_8NUMS==5
	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)" NOr ");
				break;
			case 1:
				   led7_show_string((u8 *)" POP ");
				break;
			case 2:
				   led7_show_string((u8 *)" rOC ");
				break;
			case 3:
				   led7_show_string((u8 *)" JAZ ");

				break;
			case 4:
				   led7_show_string((u8 *)" CLA ");
				break;
			case 5:
				   led7_show_string((u8 *)" COU ");
				break;
			default:
			    break;
	   }

  #else
	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)" NOr");
				break;
			case 1:
				   led7_show_string((u8 *)" POP");
				break;
			case 2:
				   led7_show_string((u8 *)" rOC");
				break;
			case 3:
				   led7_show_string((u8 *)" JAZ");

				break;
			case 4:
				   led7_show_string((u8 *)" CLA");
				break;
			case 5:
				   led7_show_string((u8 *)" COU");
				break;
			default:
			    break;
	   }
	#endif

#elif defined SUPPORT_EQ_ZY_SHOW_CHAR
// 3£∫EQÀ≥–Ú£∫NOR-POP-ROC-JAZ-CLA-COU

    u8 eq_cnt;
    eq_cnt = (u8)arg;

	   switch(eq_cnt)
	   	{
		     case 0:
				   led7_show_string((u8 *)"  NOr  ");
				break;
			case 1:
				   led7_show_string((u8 *)"  POP  ");
				break;
			case 2:
				   led7_show_string((u8 *)"  rOC  ");
				break;
			case 3:
				   led7_show_string((u8 *)"  JAZ  ");

				break;
			case 4:
				   led7_show_string((u8 *)"  CLA  ");
				break;
			case 5:
				   led7_show_string((u8 *)"  COU  ");
				break;
			default:
			    break;
	   }
#elif defined SUPPORT_EQ_SHOW_VXX
    u8 eq_cnt;
    eq_cnt = (u8)arg;

    led7_show_string((u8 *)other_string[0]);
    itoa2(eq_cnt);
    led7_show_string((u8 *)bcd_number);

#else
    u8 eq_cnt;
    eq_cnt = (u8)arg;

    led7_show_string((u8 *)other_string[0]);
    led7_show_char(eq_cnt%10 + '0');
	
#if LED_8NUMS==7
    led7_show_string((u8 *)"  ");
#endif	

#endif

LED7_DISP_ICON(cl_icon,LED_2POINT);
 #if LED_2POINT1
     LED_STATUS &=~(LED_2POINT1);
 #endif

}

/*----------------------------------------------------------------------------*/
/**@brief   —≠ª∑ƒ£ Ωœ‘ æ∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_playmode(s32 arg)
*/
/*----------------------------------------------------------------------------*/
void led7_show_playmode(s32 arg)
{
    u8 pm_cnt;

#if 1//def LED_SCREEN_SHOW_BAT_STATUS
 	LED7_DISP_ICON(cl_icon,LED_2POINT);
#endif
 #ifdef SUPPORT_TY_8848_OFF_ICON
    LED_STATUS &=~(LED_MP3|LED_PLAY);
 #endif

    pm_cnt = (u8)arg;
    led7_show_string((u8 *)&playmodestr[pm_cnt-FOP_MAX-1][0]);
}

/*----------------------------------------------------------------------------*/
/**@brief   “Ù¡øœ‘ æ∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_volume(s32 vol)
*/
/*----------------------------------------------------------------------------*/
void led7_show_volume(s32 vol)
{
    u8 tmp_vol;

 #if LED_2POINT
     LED_STATUS &=~(LED_2POINT);
 #endif
 
 #ifdef SUPPORT_TY_8848_OFF_ICON
    LED_STATUS &=~(LED_USB|LED_SD|LED_MP3|LED_PLAY);
 #endif

    tmp_vol = (u8)vol;
    led7_show_string((u8 *)other_string[1]);

    #if LED_SHOW_VOL_MAX
       itoa2(bVolMaxChangeToSmallVolMax);
    #else
 	   itoa2(tmp_vol);
    #endif

    led7_show_string((u8 *)bcd_number);
    LED7_DISP_ICON(cl_icon,LED_2POINT|LED_DOT);
 #if LED_2POINT1
     LED_STATUS &=~(LED_2POINT1);
 #endif

}

/*----------------------------------------------------------------------------*/
/**@brief   FM ƒ£ Ω÷˜ΩÁ√Ê
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_fm_main(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_fm_main(void)
{
    /*FM - Frequency*/

#ifdef LED_MHZ
        LED7_DISP_ICON(or_icon,LED_MHZ);  //LED_STATUS |= LED_MHZ;
#endif

#ifdef  LED_FM
        LED7_DISP_ICON(or_icon,LED_FM);  //LED_STATUS |= LED_MHZ;
#endif
 #ifdef LED_FM1
      LED_STATUS |=(LED_FM1);	
 #endif

#ifdef  LED_DOT
        LED7_DISP_ICON(or_icon,LED_DOT);  //LED_STATUS |= LED_MHZ;
#endif
	 #ifdef LED_PAUSE2
	 	LED_STATUS &= ~LED_PAUSE2;
	 #endif

	LED7_DISP_ICON(cl_icon,LED_PLAY | LED_PAUSE);
	LED7_DISP_ICON(cl_icon,LED_SD|LED_USB);
	LED7_DISP_ICON(cl_icon,LED_2POINT);
 	LED7_DISP_ICON(cl_icon,LED_AUX);
 	LED7_DISP_ICON(cl_icon,LED_BT);
	 #ifdef LED_DVD
	 	 LED_STATUS &=~(LED_DVD);	
	 #endif
	 #ifdef LED_BT1
	 LED_STATUS &=~(LED_BT1);	
	 #endif
 	LED7_DISP_ICON(cl_icon,LED_RECO);
 	LED7_DISP_ICON(cl_icon,LED_MP3);
 	LED7_DISP_ICON(cl_icon,LED_REPLAY);
#ifdef LED_ALL
	     LED_STATUS &=~(LED_ALL);	
#endif

#ifdef LED_ID_6030_C_VFD

	itoa2(pt2313data[PT_VOLUME]);
	led7_show_string((u8 *)bcd_number);
	LED7_DISP_ICON(or_icon,LED_VOLUME);





#else


	
#if 1
    FM_MODE_VAR * fm_var;

    if(!UI_var.ui_buf_adr)
        return;

    fm_var = *(FM_MODE_VAR **)UI_var.ui_buf_adr;


    if(fm_var)
    {

    #if LED_8NUMS==5
        led7_show_char(' ');
    #elif LED_8NUMS==6
	#ifdef LED_ID_DB_51

	#else
	    itoa2(fm_var->wFreChannel%100);
	    led7_show_string((u8 *)bcd_number);
	#endif

    #elif LED_8NUMS==7
	led7_show_char('p');
	    itoa2(fm_var->wFreChannel%100);
	    led7_show_string((u8 *)bcd_number);
    #endif


        itoa4(fm_var->wFreq);

        if (fm_var->wFreq <= 999)
            bcd_number[0] = ' ';

        led7_show_string((u8 *)bcd_number);

	#ifdef LED_ID_DB_51
	    itoa2(fm_var->wFreChannel%100);
	    led7_show_string((u8 *)bcd_number);
	#endif




#if REC_EN

        RECORD_OP_API * rec_var_p;
        REC_CTL * rec_ctl_var;

        if((fm_var->fm_rec_op)&&(*(RECORD_OP_API **)(fm_var->fm_rec_op)))
        {
            rec_var_p = *(RECORD_OP_API **)fm_var->fm_rec_op;
            rec_ctl_var = rec_var_p->rec_ctl;

            if((rec_ctl_var)&&(ENC_STOP != rec_ctl_var->enable))
            {
			 #ifdef LED_PAUSE2
			 	LED_STATUS &= ~LED_PAUSE2;
			 #endif

                LED7_DISP_ICON(cl_icon,LED_PLAY | LED_PAUSE);	//LED_STATUS &= ~(LED_PLAY | LED_PAUSE);
                LED7_DISP_ICON(cl_icon,LED_SD|LED_USB);	//LED_STATUS &= ~(LED_SD|LED_USB);
	 	 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
	                 LED7_DISP_ICON(cl_icon,LED_SD1|LED_USB1);	//LED_STATUS &= ~(LED_SD|LED_USB);
	 	 #endif

                /* led7_show_dev(); */
                led7_show_dev(rec_ctl_var->curr_device);
                if (ENC_STAR == rec_ctl_var->enable)
                	{
	                    LED7_DISP_ICON(or_icon,LED_SD|LED_USB);// LED_STATUS |= LED_PLAY;
		 	 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
	                    LED7_DISP_ICON(or_icon,LED_SD1|LED_USB1);// LED_STATUS |= LED_PLAY;
		 	 #endif

                	}
                else if(ENC_PAUS == rec_ctl_var->enable)
                	{
		 	 #if defined(SUPPORT_DOUBLE_LED7_PANEL)
	                    LED7_DISP_ICON(or_icon,LED_SD1|LED_USB1); // LED_STATUS |= LED_PAUSE;
		 	 #endif
	                    LED7_DISP_ICON(or_icon,LED_SD|LED_USB); // LED_STATUS |= LED_PAUSE;
			}
             }

        }

#endif

    }

#endif // 0

#endif // 0

}

/*----------------------------------------------------------------------------*/
/**@brief   FM ƒ£ Ω÷˜ΩÁ√Ê
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_fm_station(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_fm_station(void)
{
//    /*FM - Station*/

#if 1//def LED_SCREEN_SHOW_BAT_STATUS
 	LED7_DISP_ICON(cl_icon,LED_DOT);
#endif
	#ifdef LED_MHZ
 	LED7_DISP_ICON(cl_icon,LED_MHZ);
	#endif
	
 #ifdef SUPPORT_TY_8848_OFF_ICON
    LED_STATUS &=~(LED_FM);
 #endif

#ifdef LED_ID_6030_C_VFD
	     	 #ifdef  LED_FM
	     	 	   LED7_DISP_ICON(or_icon,LED_FM);	//LED_STATUS |= LED_MHZ;
	     	 #endif



				 itoa2(pt2313data[PT_VOLUME]);
				 led7_show_string((u8 *)bcd_number);
				 LED7_DISP_ICON(or_icon,LED_VOLUME);




#else




 #if (LED_8NUMS==7||LED_8NUMS==8||LED_8NUMS==6)

	led7_show_fm_main();

#else
	 #if 1
	     FM_MODE_VAR * fm_var;

	     if(!UI_var.ui_buf_adr)
	         return;

	     fm_var = *(FM_MODE_VAR **)UI_var.ui_buf_adr;
	 #ifdef  LED_FM
	     LED7_DISP_ICON(or_icon,LED_FM);  //LED_STATUS |= LED_MHZ;
	 #endif
 #ifdef LED_FM1
      LED_STATUS |=(LED_FM1);	
 #endif
	     if(fm_var)
	     {
	         led7_show_string((u8 *)other_string[2]);
	         itoa2(fm_var->wFreChannel);
	         led7_show_string((u8 *)bcd_number);
	     }
	 #endif
#endif
#endif

}

#if 1 //RTC_CLK_EN
/*----------------------------------------------------------------------------*/
/**@brief   RTC œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_RTC_main(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_RTC_main(void)
{
    RTC_SETTING * rtc_var;
    RTC_TIME *ui_time;

    rtc_var = (RTC_SETTING *)UI_var.ui_buf_adr;

    if(rtc_var)
    {
        ui_time = rtc_var->calendar_set.curr_rtc_time;

        itoa2(ui_time->bHour);
        led7_show_string((u8 *)bcd_number);
        itoa2(ui_time->bMin);
        led7_show_string((u8 *)bcd_number);

        led7_var.wFlashIcon |= LED_2POINT;
        LED7_DISP_ICON(or_icon,LED_2POINT); // LED_STATUS |= LED_2POINT;

        if(rtc_var->rtc_set_mode == RTC_SET_MODE)
        {
            if(rtc_var->calendar_set.coordinate == COORDINATE_MIN)
                led7_var.bFlashChar = BIT(0)|BIT(1);
            else
                led7_var.bFlashChar = BIT(2)|BIT(3);
        }
        else
            led7_var.bFlashChar = 0;
    }
}

/*----------------------------------------------------------------------------*/
/**@brief   Alarm œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_show_alarm(void)
*/
/*----------------------------------------------------------------------------*/
#if 1 //RTC_ALM_EN
void led7_show_alarm(void)
{
    RTC_SETTING * rtc_var;
    RTC_TIME *ui_time;
    rtc_var = (RTC_SETTING *)UI_var.ui_buf_adr;

    if(rtc_var)
    {
        puts("led7_show_alarm\n");

        ui_time = rtc_var->alarm_set.curr_alm_time;
        itoa2(ui_time->bHour);
        led7_show_string((u8 *)bcd_number);
        itoa2(ui_time->bMin);
        led7_show_string((u8 *)bcd_number);

        LED7_DISP_ICON(or_icon,LED_2POINT); //  LED_STATUS |= LED_2POINT;

        if(rtc_var->rtc_set_mode == ALM_SET_MODE)
        {
            if(rtc_var->alarm_set.coordinate == COORDINATE_MIN)
                led7_var.bFlashChar = BIT(0)|BIT(1);
            else
                led7_var.bFlashChar = BIT(2)|BIT(3);
        }

        /*Alarm info - Switch On/Off*/
        if (rtc_var->alarm_set.alarm_sw)
        {
            LED7_DISP_ICON(or_icon,LED_PLAY); // LED_STATUS |= LED_PLAY;
        }
        else
        {
            LED7_DISP_ICON(or_icon,LED_PAUSE); // LED_STATUS |= LED_PAUSE;
   	 #ifdef LED_PAUSE2
	 	LED_STATUS |= LED_PAUSE2;
	 #endif
     }
    }
}
#endif
#endif

#if REC_EN
/*----------------------------------------------------------------------------*/
/**@brief   REC œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void led7_show_rec_start(void)
*/
/*----------------------------------------------------------------------------*/
static void led7_show_rec_start(REC_CTL * rec_ctl_var)
{

    u32 rec_time;


//    LED_STATUS &= ~(LED_PLAY | LED_PAUSE);

//    if(rec_ctl_var)
    {


        rec_time = rec_ctl_var->file_info.enc_time_cnt;


	printf("--------rec_time-----------%2x",rec_time);

	#if LED_8NUMS==7
	    led7_show_string((u8 *)"rec");
	#elif LED_8NUMS==6
	    led7_show_string((u8 *)"re");
        #endif

        itoa2(rec_time/60);
        led7_show_string((u8 *)bcd_number);

        itoa2(rec_time%60);
        led7_show_string((u8 *)bcd_number);

        /* led7_show_dev(); */
        led7_show_dev(rec_ctl_var->curr_device);

        LED7_DISP_ICON(or_icon,LED_2POINT); //LED_STATUS |= LED_2POINT; //| LED_PLAY;




#if defined(SUPPORT_DOUBLE_LED7_PANEL)

	     if((music_ui.ui_curr_device == SD0_DEVICE)||(music_ui.ui_curr_device == SD1_DEVICE))
	     {
				{
				 	  LED_FLASH_ICON |= LED_SD1;
				         LED_STATUS&= ~LED_USB1;
				}

			    {
				  LED_FLASH_ICON |= LED_SD;
			        LED_STATUS&= ~LED_USB;

			    }
	     }
	     else if(music_ui.ui_curr_device == USB_DEVICE)
	     {
			     {
			 	  LED_FLASH_ICON |= LED_USB1;
			          LED_STATUS &= ~LED_SD1;
			 	}
			    {
				  LED_FLASH_ICON |= LED_USB;
			         LED_STATUS &= ~LED_SD;
				}
	     }

#else
#if defined LED_USB||defined LED_SD
    if((music_ui.ui_curr_device == SD0_DEVICE)||(music_ui.ui_curr_device == SD1_DEVICE))
    {
		LED_FLASH_ICON |= LED_SD;
		LED_STATUS&= ~LED_USB;

    }
    else if(music_ui.ui_curr_device == USB_DEVICE)
    {
		LED_FLASH_ICON |= LED_USB;
		LED_STATUS &= ~LED_SD;
	}
#endif

#endif

        if (ENC_STAR == rec_ctl_var->enable)
            LED7_DISP_ICON(or_icon,LED_PLAY);//LED_STATUS |= LED_PLAY;
        else if (ENC_PAUS == rec_ctl_var->enable)
        	{
            LED7_DISP_ICON(or_icon,LED_PAUSE);//LED_STATUS |= LED_PAUSE;
		 #ifdef LED_PAUSE2
		 	LED_STATUS |= LED_PAUSE2;
		 #endif
            
        	}

    }
}

/*----------------------------------------------------------------------------*/
/**@brief   REC œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void led7_show_rec_main(void)
*/
/*----------------------------------------------------------------------------*/
void led7_show_rec_main(void)
{
    RECORD_OP_API * rec_var_p;
    REC_CTL * rec_ctl_var;
 #if LED_2POINT1
     LED_STATUS &=~(LED_2POINT1);
 #endif

      LED_STATUS &=~(LED_PLAY | LED_PAUSE|LED_2POINT|LED_SD|LED_USB);
	 #ifdef LED_PAUSE2
	 	LED_STATUS &= ~LED_PAUSE2;
	 #endif

#if defined(SUPPORT_DOUBLE_LED7_PANEL)
  LED_STATUS &= ~(LED_SD1|LED_USB1);
#endif

#ifdef LED_RECO
	LED7_DISP_ICON(or_icon,LED_RECO);
	LED_FLASH_ICON|=LED_RECO;
#endif

    if(UI_var.ui_buf_adr)
    {
        rec_var_p = *(RECORD_OP_API **)UI_var.ui_buf_adr;
        if(rec_var_p)
        {
            rec_ctl_var = rec_var_p->rec_ctl;
            if((rec_ctl_var)&&(ENC_STOP != rec_ctl_var->enable))
            {

                led7_show_rec_start(rec_ctl_var);
                return;
            }
        }
    }

    led7_show_string((u8 *)other_string[4]);
}

#endif


/*----------------------------------------------------------------------------*/
///-------------CUSTOMER  UI  ADD---JSUO-----------------------------------
/*----------------------------------------------------------------------------*/

#ifdef LED_SHOW_SCREEN_FREQUENCE
#include "dac/dac_api.h"

/*----------------------------------------------------------------------------*/
/**@brief   EQ     œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void LED_FREQUENCE_PROCESS  (void)
*/
/*----------------------------------------------------------------------------*/
#ifdef LED_EQ_BAR_SHOW
u8 STEPS_TO_HEX(u8 steps)
{
u8 returnResult=0;
switch(steps)
{
   case 0:
    returnResult=0;
   case 1:
   returnResult=0x01;
   break;
   case 2:
   returnResult=0x03;
   break;
   case 3:
   returnResult=0x07;
   break;
   case 4:
   returnResult=0x0f;
   break;
   case 5:
   returnResult=0x1f;
   break;
   case 6:
   returnResult=0x3f;
   break;
   case 7:
   returnResult=0x7f;
   break;
   case 8:
   returnResult=0xff;
   break;

}
return returnResult;
}
void LED_SHOW_EQ_BAR(u8 barNum,int mode,u8 steps)
{
  if(mode==-1)
  	{ //clear all eq bar value
   		led7_var.bEqBarBuf[0]=0;
   		led7_var.bEqBarBuf[1]=0;
  		led7_var.bEqBarBuf[2]=0;
   		led7_var.bEqBarBuf[3]=0;
 	    #if LED_EQ_NUMS>=5
 	    led7_var.bEqBarBuf[4]=0;
 	    #endif
  	}
  else
  	{
     		switch(mode)
			{
		          case 0://bottom to top grid by grid
		          		led7_var.bEqBarBuf[barNum]=STEPS_TO_HEX(steps);
		          break;
		          case 1://top to bottom grid by grid
		          		led7_var.bEqBarBuf[barNum]=STEPS_TO_HEX(steps)<<((LED_EQ_BAR_GRIDS)-steps);
		          break;
		          case 2://only one grid bottom to top
		          		led7_var.bEqBarBuf[barNum]=BIT(steps);
		          break;
		          case 3://only one grid top to bottom
		          		led7_var.bEqBarBuf[barNum]=BIT((LED_EQ_BAR_GRIDS)-steps);
		          break;
     			}
  	}
}

void LED_SHOW_EQ_IDLE(void)
{
   static u8 cnt,steps,mode;
   cnt++;
   if(cnt>10)
   	{
     		 cnt=0;
      		steps++;
      		if(steps>(LED_EQ_BAR_GRIDS))
			{
      				steps=1;
      				mode++;
      				if(mode>3)
					mode=0;
      			}
      }
   if(cnt==10)
   	{
      		LED_SHOW_EQ_BAR(0,mode,steps);
      		LED_SHOW_EQ_BAR(1,mode,steps);
      		LED_SHOW_EQ_BAR(2,mode,steps);
      		LED_SHOW_EQ_BAR(3,mode,steps);
		      #if LED_EQ_NUMS>=5
		      LED_SHOW_EQ_BAR(4,mode,steps);
		      #endif
   }
}
#if LED_EQ_BAR_GRIDS==8
#define EN_18 65500*1/8
#define EN_28 65500*2/8
#define EN_38 65500*3/8
#define EN_48 65500*4/8
#define EN_58 65500*5/8
#define EN_68 65500*6/8
#define EN_78 65500*7/8
#define EN_88 65500
#elif LED_EQ_BAR_GRIDS==4
#ifdef EQ_ADC_VALUE_DETECT

#define EN_PER 1023*20/(33*4)
#define EN_14 EN_PER*1
#define EN_24 EN_PER*2
#define EN_34 EN_PER*3
#define EN_44 EN_PER*4

#else
#define EN_14 65500*1/4
#define EN_24 65500*2/4
#define EN_34 65500*3/4
#define EN_44 65500
#endif
#endif
u8 ENERGY_TO_STEPS(u16 energy)
{
#if LED_EQ_BAR_GRIDS==8
  if(energy<=EN_18)return 0;
  if(energy<=EN_28)return 1;
  if(energy<=EN_38)return 2;
  if(energy<=EN_48)return 3;
  if(energy<=EN_58)return 4;
  if(energy<=EN_68)return 5;
  if(energy<=EN_78)return 6;
  if(energy<=EN_88)return 7;
  return 7; //default
#elif LED_EQ_BAR_GRIDS==4
  #if defined LED_ID_ZX001||defined LED_ID_JW1676_1B||defined LED_ID_JM_4169_B||defined LED_ID_CYJ_4211
  if(energy<100)return 0;
  else if((energy>=100)&&(energy<EN_14))return 1;
  else if((energy>=EN_14)&&(energy<EN_24))return 2;
  else if((energy>=EN_24)&&(energy<EN_34))return 3;
  else if((energy>=EN_34)&&(energy<=EN_44))return 4;
  else return 4;
  #else
  if(energy<=EN_14)return 0;
  if(energy<=EN_24)return 1;
  if(energy<=EN_34)return 2;
  if(energy<=EN_44)return 3;
  return 3;
  #endif
#endif
}
void GET_LED_EQ_BAR_VALUE(void)
{
   static u8 cnt=0;
#ifdef EQ_ADC_VALUE_DETECT
   led7_var.bEqBarEnergyValueBuf[cnt]=adc_value[AD_CH_EQ];
#else
   led7_var.bEqBarEnergyValueBuf[cnt]=get_dac_energy_value();
#endif
   cnt++;
   if(cnt>=LED_EQ_NUMS)
   cnt=0;
}
void LED_EQ_BAR_PROCESS(u8 mode)
{
  static u8 cnt=0,bPowerOnCnt,bIdledCnt,barCnt=0;
  bPowerOnCnt++;
  if(bPowerOnCnt>25)
  	bPowerOnCnt=26;
  if(bPowerOnCnt<25)
  	return; //eq show too earlier

    cnt++;

    if(cnt<25)return;
    if(cnt==25)cnt=0;

#ifdef support_rec_no_eq
  if((compare_task_name("IdleTask"))||(compare_task_name("RECTask")))
  {
      LED_SHOW_EQ_BAR(0,-1,0);
      LED_SHOW_EQ_BAR(1,-1,0);
      LED_SHOW_EQ_BAR(2,-1,0);
      LED_SHOW_EQ_BAR(3,-1,0);
      #if LED_EQ_NUMS>=5
      LED_SHOW_EQ_BAR(4,-1,0);
      #endif
      return;
  }

#else
  if(compare_task_name("IdleTask"))
  {
      LED_SHOW_EQ_BAR(0,-1,0);
      LED_SHOW_EQ_BAR(1,-1,0);
      LED_SHOW_EQ_BAR(2,-1,0);
      LED_SHOW_EQ_BAR(3,-1,0);
      #if LED_EQ_NUMS>=5
      LED_SHOW_EQ_BAR(4,-1,0);
      #endif
      return;
  }
 #endif
#ifdef SUPPORT_MUTE_FLASH
  #ifdef EQ_ADC_VALUE_DETECT
    #ifdef SUPPORT_PT2313
  	if(mute_flag|| adc_value[AD_CH_EQ]<10 ||pt2313data[PT_VOLUME]==0){
   #else
 	 if(mute_flag|| adc_value[AD_CH_EQ]<10){
	#endif
  #else
  #ifdef SUPPORT_PT2313
  if(mute_flag|| get_dac_energy_value()<100 ||pt2313data[PT_VOLUME]==0){
  #else
  if(mute_flag|| get_dac_energy_value()<100){
  #endif
  #endif
   if(bIdledCnt<10)
   	bIdledCnt++;
  if(bIdledCnt==10)
  	{
  		LED_SHOW_EQ_IDLE();
  		return;
 	 }
  }
  else
  	{
  		bIdledCnt=0;
  //led7_var.bEqCircleIfPlay=TRUE;
  }
#endif

printf("get_dac_energy_value-----%d\n",get_dac_energy_value);





 #ifdef EQ_DETECT_ANALOG_SIGNAL
   LED_SHOW_EQ_BAR(0,mode,led7_var.wEqADC_Value);
   LED_SHOW_EQ_BAR(1,mode,led7_var.wEqADC_Value);
   LED_SHOW_EQ_BAR(2,mode,led7_var.wEqADC_Value);
   LED_SHOW_EQ_BAR(3,mode,led7_var.wEqADC_Value);
  #if LED_EQ_NUMS>=5
   LED_SHOW_EQ_BAR(4,mode,led7_var.wEqADC_Value);
  #endif
 #else
  LED_SHOW_EQ_BAR(0,mode,ENERGY_TO_STEPS(led7_var.bEqBarEnergyValueBuf[0]));
  LED_SHOW_EQ_BAR(1,mode,ENERGY_TO_STEPS(led7_var.bEqBarEnergyValueBuf[1]));
  LED_SHOW_EQ_BAR(2,mode,ENERGY_TO_STEPS(led7_var.bEqBarEnergyValueBuf[2]));
  LED_SHOW_EQ_BAR(3,mode,ENERGY_TO_STEPS(led7_var.bEqBarEnergyValueBuf[3]));
  #if LED_EQ_NUMS>=5
  LED_SHOW_EQ_BAR(4,mode,ENERGY_TO_STEPS(led7_var.bEqBarEnergyValueBuf[4]));
  #endif
 #endif

}


#else



#define EN_MAX 65500
#if defined LED_ID_JW5028B_1B
#define EN_0 65500*1/8
#define EN_1 65500*3/8
#define EN_2 65500*5/8
#define EN_3 65500*7/8
#define EN_4 65500*8/8

#elif defined(LED_ID_LD999B_J)
#ifdef ZY_LED_ID_LD999B_J_EQ

#define EN_0 1023*1/21
#define EN_1 1023*2/21
#define EN_2 1023*3/21
#define EN_3 1023*4/21
#define EN_4 1023*5/21
#define EN_5 1023*6/21
#define EN_6 1023*7/21
#else
#define EN_0 1023*1/21
#define EN_1 1023*2/21
#define EN_2 1023*3/21
#define EN_3 1023*4/21
#define EN_4 1023*5/21
#define EN_5 1023*6/21
#define EN_6 1023*7/21
#endif
#elif defined(LED_ID_1600B_VFD)
#ifdef EQ_ADC_VALUE_DETECT

#define AD_00 1023*1/6
#define AD_01 1023*2/6
#define AD_02 1023*3/6
#define AD_03 1023*4/6
#define AD_04 1023*5/6
#define AD_05 1023*6/6
#else

#define EN_0 65500*1/6
#define EN_1 65500*2/6
#define EN_2 65500*3/6
#define EN_3 65500*4/6
#define EN_4 65500*5/6
#define EN_5 65500*6/6

#endif

#elif defined LED_ID_ZY_308D
#ifdef EQ_ADC_VALUE_DETECT
#define EN_0 1023*1/5
#define EN_1 1023*2/5
#define EN_2 1023*3/5
#define EN_3 1023*4/5
#define EN_4 1023*5/5
#else
#define EN_0 65500*1/8
#define EN_1 65500*3/8
#define EN_2 65500*5/8
#define EN_3 65500*7/8
#define EN_4 65500*8/8
#endif

#elif defined LED_ID_YDL2001_VFN_35
#define EN_0 65500*1/10
#define EN_1 65500*2/10
#define EN_2 65500*3/10
#define EN_3 65500*4/10
#define EN_4 65500*5/10
#define EN_5 65500*6/10
#define EN_6 65500*7/10
#define EN_7 65500*8/10
#elif defined(LED_ID_DB_51)

#define EN_0 65500*1/4
#define EN_1 65500*2/4
#define EN_2 65500*3/4
#define EN_3 65500*4/4

#elif defined(LED_ID_JH820_03) // tm1628
#define EN_0 65500*1/4
#define EN_1 65500*2/4
#define EN_2 65500*3/4
#else
#define EN_0 65500*1/5
#define EN_1 65500*2/5
#define EN_2 65500*3/5
#define EN_3 65500*4/5
#define EN_4 65500*5/5
#endif

#if 1 //def SUPPORT_AUX_FREQ
extern u32 energy_value;
#endif

   u8 ENERGY_TO_STEPS(u16 energy)
   {

	 #ifndef EQ_ADC_VALUE_DETECT
		  if(workmode==LINE_WORK_MODE)
		  	energy=energy_value;
	 #endif

	 #if defined(LED_ID_LD999B_J)

	 	 if(energy<=EN_0)return 0;
	 	 if(energy<=EN_1)return 1;
	 	 if(energy<=EN_2)return 2;
	 	 if(energy<=EN_3)return 3;
	 	 if(energy<=EN_4)return 4;
	 	 if(energy<=EN_5)return 5;
	 	 if(energy<=EN_6)return 6;
	 	 return 7; //default

	 #elif defined(LED_ID_YDL2001_VFN_35)
	 	 if(energy<=EN_0)return 0;
	 	 if(energy<=EN_1)return 1;
	 	 if(energy<=EN_2)return 2;
	 	 if(energy<=EN_3)return 3;
	 	 if(energy<=EN_4)return 4;
	 	 if(energy<=EN_5)return 5;
	 	 if(energy<=EN_6)return 6;
	 	 if(energy<=EN_7)return 7;
	 	 return 8; //default
	 #elif defined(LED_ID_1600B_VFD)
	 #ifdef EQ_ADC_VALUE_DETECT
	 	if( mute_flag==TRUE)
	 	return 0;
	 
	 	if(energy<=13)return 0;
	 	if(energy<=AD_01)return 1;
	 	if(energy<=AD_02)return 2;
	 	if(energy<=AD_03)return 3;
	 	if(energy<=AD_04)return 4;
	 	if(energy<=AD_05)return 5;
	 	return 6; //default
	 #else
	 	if( mute_flag==TRUE)
	 	return 0;
	 
	 	if(energy<=25)return 0;
	 	if(energy<=EN_1)return 1;
	 	if(energy<=EN_2)return 2;
	 	if(energy<=EN_3)return 3;
	 	if(energy<=EN_4)return 4;
	 	if(energy<=EN_5)return 5;
	 	return 6; //default
	 
	 
	 #endif
	 #elif defined(LED_ID_DB_51)
	 	if(energy<=EN_0)return 0;
	 	if(energy<=EN_1)return 1;
	 	if(energy<=EN_2)return 2;
	 	if(energy<=EN_3)return 3;
	 return 4; //default	 #elif defined(LED_ID_JH820_03) // tm1628
	 	 if(energy<=EN_0)return 0;
	 	 if(energy<=EN_1)return 1;
	 	 if(energy<=EN_2)return 2;
	 	 return 3; //default	 	 
	 #else
	 	 if(energy<=EN_0)return 0;
	 	 if(energy<=EN_1)return 1;
	 	 if(energy<=EN_2)return 2;
	 	 if(energy<=EN_3)return 3;
	 	 return 4; //default
	 #endif
   }

#if defined LED_ID_JW5028B_1B


void	led_no_single_freq(void)
{
   static u8 cnt=1;

     switch(cnt)
	   {
	       case 1:
	       case 9:
	       case 17:
		       led7_var.bEqIconBuf=EQ_00;
	       break;
	       case 2:
	       case 8:
		       led7_var.bEqIconBuf=EQ_01;
	       break;
	       case 3:
	       case 7:
		       led7_var.bEqIconBuf=EQ_02;
	       break;
	       case 4:
	       case 6:

		       led7_var.bEqIconBuf=EQ_03;
	       break;
	       case 5:
		       led7_var.bEqIconBuf=EQ_04;
	       break;

	       case 10:
	       case 16:
		       led7_var.bEqIconBuf=EQ_00|EQ_01;
	       break;

	       case 11:
	       case 15:
		       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02;
	       break;

	       case 12:
	       case 14:
		       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03;
	       break;
	       case 13:
	       case 19:
	       case 21:
		       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04;
	       break;

		default:

		       led7_var.bEqIconBuf=0;
		break;

	 }
	cnt++;
if(cnt>=23)
	cnt=0;
 }

#elif defined(LED_ID_DB_51)
void	led_no_single_freq(void)
{
   static u8 cnt=1;
switch(cnt)
   {		
	   case 1:
	   case 9:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05;
	   break;
	   case 2:
	   case 8:
		   led7_var.bEqIconBuf=EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11;
	   break;
	   case 3:
	   case 7:
		   led7_var.bEqIconBuf=EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17;
	   break;
	   case 4:	
	   case 6:	
		   led7_var.bEqIconBuf=EQ_18|EQ_19|EQ_20|EQ_21|EQ_22|EQ_23;
	   break;		
	   case 5:
		   led7_var.bEqIconBuf=0;	
	   break;
	   case 10:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05;
	   break;
	   case 11:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05|EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11;
	   break;	 
	   case 12:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05|EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11|EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17;
	   break;
	   case 13:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05|EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11|EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17|EQ_18|EQ_19|EQ_20|EQ_21|EQ_22|EQ_23;
	   break;
	   case 14:
		   led7_var.bEqIconBuf=0;
	   break;	   
	   case 15:
		   led7_var.bEqIconBuf=EQ_18|EQ_19|EQ_20|EQ_21|EQ_22|EQ_23;
	   break;
	   case 16:
		   led7_var.bEqIconBuf=EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17|EQ_18|EQ_19|EQ_20|EQ_21|EQ_22|EQ_23;
	   break;
	   case 17:
		   led7_var.bEqIconBuf=EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11|EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17|EQ_18|EQ_19|EQ_20|EQ_21|EQ_22|EQ_23;
	   break;
	   case 18:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05|EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11|EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17|EQ_18|EQ_19|EQ_20|EQ_21|EQ_22|EQ_23;
	   break;
	default:
		   led7_var.bEqIconBuf=0;	
	break;

 }

cnt++;
if(cnt>=19)
	cnt=0;

}

#elif defined(LED_ID_JH820_03) // tm1628


void	led_no_single_freq(void)
{
   static u8 cnt=1;

     switch(cnt)
	   {
	       case 1:
	       case 5:
	       case 9:
		       led7_var.bEqIconBuf=EQ_00|EQ_03|EQ_06|EQ_09;
	       break;
	       case 2:
	       case 4:
		       led7_var.bEqIconBuf=EQ_01|EQ_04|EQ_07|EQ_10;
	       break;
	       case 3:
		       led7_var.bEqIconBuf=EQ_02|EQ_05|EQ_08|EQ_11;
	       break;

	       case 6:
	       case 8:
		       led7_var.bEqIconBuf=EQ_00|EQ_03|EQ_06|EQ_09|EQ_01|EQ_04|EQ_07|EQ_10;
	       break;
	       case 7:
	       case 11:
	       case 13:
	       case 15:
	     	  led7_var.bEqIconBuf=EQ_00|EQ_03|EQ_06|EQ_09|EQ_01|EQ_04|EQ_07|EQ_10|EQ_02|EQ_05|EQ_08|EQ_11;
	       break;		   
		default:

		       led7_var.bEqIconBuf=0;
		break;

	 }
	cnt++;
if(cnt>=17)
	cnt=0;
 }
#elif defined(LED_ID_1600B_VFD)

void	led_no_single_freq(void)
{
   static u8 cnt;

//printf("(cnt---1111--==%d\n",cnt);

switch(cnt)
   {		
	   case 1:
	   case 11:
	   case 21:
	   	
		   led7_var.bEqIconBuf=EQ_00;
	   break;
	   case 2:
	   case 10:
		   led7_var.bEqIconBuf=EQ_01;
	   break;
	   case 3:
            case 9:
		   led7_var.bEqIconBuf=EQ_02;
	   break;
	   case 4:	
	   case 8:	
		   led7_var.bEqIconBuf=EQ_03;
	   break;		   
	   case 5:
	   case 7:
		   led7_var.bEqIconBuf=EQ_04;
	   break;
	   case 6:
		   led7_var.bEqIconBuf=EQ_05;
	   break;	 

	   
	   case 12:
	   case 20:
		   led7_var.bEqIconBuf=EQ_00|EQ_01;
	   break;
	   
	   case 13:
	   case 19:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02;
	   break;
	   
	   case 14:
	   case 18:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03;
	   break;
	   case 15:
	   case 17:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04;
	   break;		   

	   case 16:
	   case 22:
	   case 24:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05;
	   break;	
	default:

		   led7_var.bEqIconBuf=0;	
	break;

 }

cnt++;
if(cnt>=25)
	cnt=0;



 }

#elif defined(LED_ID_ZY_308D)

void	led_no_single_freq(void)
{
   static u8 cnt=1;

     switch(cnt)
	   {
	       case 1:
	       case 7:
	       case 13:
		       led7_var.bEqIconBuf=EQ_00|EQ_04;
	       break;
	       case 2:
	       case 6:
		       led7_var.bEqIconBuf=EQ_01|EQ_05;
	       break;
	       case 3:
	       case 5:
		       led7_var.bEqIconBuf=EQ_02|EQ_06;
	       break;
	       case 4:
		       led7_var.bEqIconBuf=EQ_03|EQ_07;
	       break;
	       case 8:
	       case 12:
		       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_04|EQ_05;
	       break;

	       case 9:
	       case 11:
		       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_04|EQ_05|EQ_06;
	       break;

	       case 10:
	       case 15:
	       case 17:
	       case 19:
		       led7_var.bEqIconBuf=0xff;
	       break;

		default:

		       led7_var.bEqIconBuf=0;
		break;

	 }
	cnt++;
if(cnt>=21)
	cnt=0;
 }

#elif defined(LED_ID_LD999B_J)

void	led_no_single_freq(void)
{
   static u8 cnt=1;

     switch(cnt)
	   {
	       case 1:
	       case 13:
	       case 25:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ07;
	       break;
	       case 2:
	       case 12:
	       led7_var.bEqIconBuf=LED_EQ01|LED_EQ08;
	       break;
	       case 3:
	       case 11:
	       led7_var.bEqIconBuf=LED_EQ02|LED_EQ09;
	       break;
	       case 4:
	       case 10:

	       led7_var.bEqIconBuf=LED_EQ03|LED_EQ10;
	       break;
	       case 5:
	       case 9:
	       led7_var.bEqIconBuf=LED_EQ04|LED_EQ11;
	       break;

	       case 6:
	       case 8:
	       led7_var.bEqIconBuf=LED_EQ05|LED_EQ12;
	       break;

	       case 7:
	       led7_var.bEqIconBuf=LED_EQ06|LED_EQ13;
	       break;

	       case 14:
	       case 24:
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ07|LED_EQ08;
	       break;
	       case 15:
	       case 23:
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ07|LED_EQ08|LED_EQ09;
	       break;
	       case 16:
	       case 22:

	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10;
	       break;
	       case 17:
	       case 21:
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11;
	       break;

	       case 18:
	       case 20:
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ05|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11|LED_EQ12;
	       break;

	       case 19:
	       case 27:
	       case 29:
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ05|LED_EQ06|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11|LED_EQ12|LED_EQ13;
	       break;


		default:

		       led7_var.bEqIconBuf=0;
		break;

	 }
	cnt++;
if(cnt>=31)
	cnt=0;
 }

#elif defined(LED_ID_YDL2001_VFN_35)

void	led_no_single_freq(void)
{
   static u8 cnt=1;

     switch(cnt)
	   {
	       case 1:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03;
	       break;
	       case 2:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03|EQ_24|EQ_05|EQ_26|EQ_07;
	       break;
	       case 3:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03|EQ_24|EQ_05|EQ_26|EQ_07|EQ_20|EQ_09|EQ_22|EQ_11;
	       break;
	       case 4:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03|EQ_24|EQ_05|EQ_26|EQ_07|EQ_20|EQ_09|EQ_22|EQ_11|EQ_16|EQ_13|EQ_18|EQ_15;
	       break;
	       case 5:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03|EQ_24|EQ_05|EQ_26|EQ_07|EQ_20|EQ_09|EQ_22|EQ_11|EQ_16|EQ_13|EQ_18|EQ_15|EQ_12|EQ_17|EQ_14|EQ_19;
	       break;

	       case 6:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03|EQ_24|EQ_05|EQ_26|EQ_07|EQ_20|EQ_09|EQ_22|EQ_11|EQ_16|EQ_13|EQ_18|EQ_15|EQ_12|EQ_17|EQ_14|EQ_19\
			   	|EQ_08|EQ_21|EQ_10|EQ_23;
	       break;

	       case 7:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03|EQ_24|EQ_05|EQ_26|EQ_07|EQ_20|EQ_09|EQ_22|EQ_11|EQ_16|EQ_13|EQ_18|EQ_15|EQ_12|EQ_17|EQ_14|EQ_19\
			   	|EQ_08|EQ_21|EQ_10|EQ_23|EQ_04|EQ_25|EQ_06|EQ_27;
	       break;
	       case 8:
		       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03|EQ_24|EQ_05|EQ_26|EQ_07|EQ_20|EQ_09|EQ_22|EQ_11|EQ_16|EQ_13|EQ_18|EQ_15|EQ_12|EQ_17|EQ_14|EQ_19\
			   	|EQ_08|EQ_21|EQ_10|EQ_23|EQ_04|EQ_25|EQ_06|EQ_27|EQ_00|EQ_29|EQ_02|EQ_31;
		break;
	       case 9:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31;
	       break;
	       case 10:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31|EQ_04|EQ_25|EQ_06|EQ_27;
	       break;
	       case 11:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31|EQ_04|EQ_25|EQ_06|EQ_27|EQ_08|EQ_21|EQ_10|EQ_23;
	       break;

	       case 12:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31|EQ_04|EQ_25|EQ_06|EQ_27|EQ_08|EQ_21|EQ_10|EQ_23|EQ_12|EQ_17|EQ_14|EQ_19;
	       break;

	       case 13:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31|EQ_04|EQ_25|EQ_06|EQ_27|EQ_08|EQ_21|EQ_10|EQ_23|EQ_12|EQ_17|EQ_14|EQ_19|EQ_16|EQ_13|EQ_18|EQ_15;
	       break;
	       case 14:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31|EQ_04|EQ_25|EQ_06|EQ_27|EQ_08|EQ_21|EQ_10|EQ_23|EQ_12|EQ_17|EQ_14|EQ_19|EQ_16|EQ_13|EQ_18|EQ_15\
		   					|EQ_20|EQ_09|EQ_22|EQ_11;

	       break;
	       case 15:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31|EQ_04|EQ_25|EQ_06|EQ_27|EQ_08|EQ_21|EQ_10|EQ_23|EQ_12|EQ_17|EQ_14|EQ_19|EQ_16|EQ_13|EQ_18|EQ_15\
		   					|EQ_20|EQ_09|EQ_22|EQ_11|EQ_24|EQ_05|EQ_26|EQ_07;
	       break;
	       case 16:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31|EQ_04|EQ_25|EQ_06|EQ_27|EQ_08|EQ_21|EQ_10|EQ_23|EQ_12|EQ_17|EQ_14|EQ_19|EQ_16|EQ_13|EQ_18|EQ_15\
		   					|EQ_20|EQ_09|EQ_22|EQ_11|EQ_24|EQ_05|EQ_26|EQ_07|EQ_28|EQ_01|EQ_30|EQ_03;
	       break;
	       case 17:
	       case 32:
		   	
	       led7_var.bEqIconBuf=EQ_28|EQ_01|EQ_30|EQ_03;
	       break;
	       case 18:
	       case 31:
		   	
	       led7_var.bEqIconBuf=EQ_24|EQ_05|EQ_26|EQ_07;
	       break;
	       case 19:
	       case 30:
		   	
	       led7_var.bEqIconBuf=EQ_20|EQ_09|EQ_22|EQ_11;
	       break;
	       case 20:
	       case 29:
		   	
	       led7_var.bEqIconBuf=EQ_16|EQ_13|EQ_18|EQ_15;
	       break;
	       case 21:
	       case 28:
		   	
	       led7_var.bEqIconBuf=EQ_12|EQ_17|EQ_14|EQ_19;
	       break;
	       case 22:
	       case 27:
	       led7_var.bEqIconBuf=EQ_08|EQ_21|EQ_10|EQ_23;
	       break;
	       case 23:
	       case 26:
		   	
	       led7_var.bEqIconBuf=EQ_04|EQ_25|EQ_06|EQ_27;
	       break;
	       case 24:
	       case 25:
	       led7_var.bEqIconBuf=EQ_00|EQ_29|EQ_02|EQ_31;
	       break;



		   
		default:

		       led7_var.bEqIconBuf=0;
		break;

	 }
	cnt++;
		if(cnt>=32)
			cnt=0;
 }
#endif

  void LED_FREQUENCE_PROCESS(void)
  {

    static u8  cnt=0;
  static  u8  cnt1=0;
  static  u8  bFreqVal,bFreqValOld;

#ifdef SUPPORT_POWER_ON_FREQUENCE_DELAY_SHOW
	 if(bFrequencePowerOnDelayVal)
	 {
          	led7_var.bEqIconBuf=0;
     		 return;
	 }
#endif
       if(compare_task_name("IdleTask"))
       	{	   	
			led7_var.bEqIconBuf=0;
			return;
       	}
	   
#if defined(LED_ID_JH820_03) // tm1628
	LED_STATUS|=LED_20|LED_150|LED_1K|LED_10K;
#endif
	   
    cnt++;

   //  printf("111   (ENERGY_TO_STEPS(get_dac_energy_value())) %d \n",get_dac_energy_value());

#if defined LED_ID_27N60_8

    if(cnt<30)return;
    if(cnt==30)cnt=0;

    switch(ENERGY_TO_STEPS(get_dac_energy_value()))
	{
	       case 0:
	          #if 0//defined LED_ID_27N60_8

	  		cnt1++;

		      	 if(cnt1>=15)
		      	   {
		      		   cnt1=9;
		   		led7_var.bEqIconBuf=0;
		      		   led_no_single_freq();
		      		}
			#else
		          	led7_var.bEqIconBuf=0;
			#endif
	       break;
	       case 1:
	       led7_var.bEqIconBuf=EQ_00|EQ_04;
	       break;
	       case 2:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_04|EQ_05;
	       break;
	       case 3:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_04|EQ_05|EQ_06;
	       break;
	       case 4:
	       led7_var.bEqIconBuf=0xff;
	       break;

    }

#elif defined(LED_ID_DB_51)
    if(cnt<2)return;
    if(cnt==2)cnt=0;

    switch(ENERGY_TO_STEPS(get_dac_energy_value()))	
	{
	       case 0:
		   	#if 1
	  		cnt1++;
	  
		      	 if(cnt1>=15)
		      	   {	   
		      		   cnt1=9;
		   		led7_var.bEqIconBuf=0;				   
		      		   led_no_single_freq();	
		      		}
			#else
			
		          	led7_var.bEqIconBuf=0;   
			#endif
			
	       break;	   
	       case 1:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05;
	       break;
	       case 2:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05|EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11;
	       break;
	       case 3:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05|EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11|EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17;
	       break;	   
	       case 4:
		   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05|EQ_06|EQ_07|EQ_08|EQ_09|EQ_10|EQ_11|EQ_12|EQ_13|EQ_14|EQ_15|EQ_16|EQ_17|EQ_18|EQ_19|EQ_20|EQ_21|EQ_22|EQ_23;
	       break;	   

    }

	
#elif defined LED_ID_1600B_VFD

    if(cnt<2)
	return;
    if(cnt==2)
	cnt=0;
		
#ifdef EQ_ADC_VALUE_DETECT
switch(ENERGY_TO_STEPS(adc_value[AD_CH_EQ]))
{
#else
switch(ENERGY_TO_STEPS(get_dac_energy_value()))
{
#endif

	       case 0:
		   	#if 1
		 	  		cnt1++;
		 	  
		 		      	 if(cnt1>=15)
		 		      	   {	   
		 		      		   cnt1=9;
		 		   //	        	   led7_var.bEqIconBuf=0;				   
		 		      		   led_no_single_freq();	
		 		      		}	 	   			
			#else
			
		          	led7_var.bEqIconBuf=0;   
			#endif
			
	       break;	
			
	       case 1:
	      		 led7_var.bEqIconBuf=EQ_00;
	       break;
	       case 2:
	       		led7_var.bEqIconBuf=EQ_00|EQ_01;
	       break;
	       case 3:
	       		led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02;
	       break;	   
	       case 4:
	       		led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03;
	       break;	 
	       case 5:
	       		led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04;
	       break;	
	       case 6:
			   led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04|EQ_05;
	       break;	
	       case 7:
				  led7_var.bEqIconBuf=0xff;   
		break;


		   

    }

	

#elif defined(LED_ID_LD999B_J)

	bFreqVal=ENERGY_TO_STEPS(adc_value[AD_CH_EQ]);

    if(cnt<18)
    	{
	    	bFreqValOld+=bFreqVal;
		return;
    	}

    if(cnt==18)cnt=0;	
	bFreqVal=bFreqValOld/17;


#if 0	
	if(bFreqVal!=0)
	{
		  if(bFreqValOld<bFreqVal-6)
			bFreqVal=bFreqValOld+1;		
		else if(bFreqValOld>bFreqVal-5)
			bFreqVal=bFreqValOld+2;
		else if(bFreqValOld>bFreqVal-4)
			bFreqVal=bFreqValOld+1;
	}
#endif

    switch(bFreqVal)
	{
	       case 0:
		   	#if 1
	  		cnt1++;

		      	 if(cnt1>=140)
		      	   {
		      		   cnt1=128;
		   		led7_var.bEqIconBuf=0;
		      		   led_no_single_freq();
		      		}
			#else
		  		cnt1++;

			      	 if(cnt1>=15)
			      	   {
			      		   cnt1=9;
				          	led7_var.bEqIconBuf=0;
			      		}
			#endif
	       break;

	       case 1:
		   	cnt1=0;
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ07;
	       break;
	       case 2:
		   	cnt1=0;
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ07|LED_EQ08;
	       break;
	       case 3:
		   	cnt1=0;
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ07|LED_EQ08|LED_EQ09;
	       break;
	       case 4:
		   	cnt1=0;
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10;
	       break;
	       case 5:
		   	cnt1=0;
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11;
	       break;
	       case 6:
		   	cnt1=0;
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ05|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11|LED_EQ12;
	       break;
	       case 7:
		   	cnt1=0;
	       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ05|LED_EQ06|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11|LED_EQ12|LED_EQ13;
	       break;

    }
	
	bFreqValOld=bFreqVal;



#elif defined(LED_ID_YDL2001_VFN_35)
    if(cnt<2)
		return;
    if(cnt==2)
		cnt=0;
if(workmode==RADIO_WORK_MODE)
{
	led7_var.bEqIconBuf=0;
}
else
{
    switch(ENERGY_TO_STEPS(get_dac_energy_value()))
	{
	       case 0:
		   	#if 1
	  		cnt1++;

		      	 if(cnt1>=15)
		      	   {
		      		   cnt1=9;
		   		led7_var.bEqIconBuf=0;
		      		   led_no_single_freq();
		      		}
			#else

		          	led7_var.bEqIconBuf=0;
			#endif

	       break;
	       case 1:
		       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03;
		break;
	       case 2:
		       led7_var.bEqIconBuf=EQ_16
			   				    |EQ_12|EQ_15\
			   				    |EQ_08|EQ_09|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
	       break;
	       case 3:
		       led7_var.bEqIconBuf=EQ_21\
			   				    |EQ_17|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
		break;
	       case 4:
		       led7_var.bEqIconBuf=EQ_24\
			   				    |EQ_20|EQ_22\
			   				    |EQ_16|EQ_18\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
		break;
	       case 5:
		       led7_var.bEqIconBuf=EQ_25\
			   				    |EQ_21|EQ_22\
			   				    |EQ_17|EQ_18|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
		break;
	       case 6:
		       led7_var.bEqIconBuf=EQ_26\
			   				    |EQ_20|EQ_22\
			   				    |EQ_16|EQ_17|EQ_18\
			   				    |EQ_12|EQ_13|EQ_14\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
		break;		   
	       case 7:
		       led7_var.bEqIconBuf=EQ_19\
			   				    |EQ_13|EQ_15\
			   				    |EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

	       break;
	       case 8:
		       led7_var.bEqIconBuf=EQ_22\
			   				    |EQ_17|EQ_18\
			   				    |EQ_12|EQ_13|EQ_14\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

	       break;
	       case 9:
		       led7_var.bEqIconBuf=EQ_30\
			   				    |EQ_24|EQ_26\
			   				    |EQ_20|EQ_22\
			   				    |EQ_16|EQ_18|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
	       break;		
	       case 10:
		       led7_var.bEqIconBuf=EQ_29\
			   				    |EQ_25|EQ_27\
			   				    |EQ_21|EQ_23\
			   				    |EQ_17|EQ_18|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
	       break;
	       case 11:
		       led7_var.bEqIconBuf=EQ_20|EQ_22\
			   				    |EQ_16|EQ_18|EQ_19\
			   				    |EQ_12|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
	       break;
	       case 12:
		       led7_var.bEqIconBuf=EQ_12|EQ_14\
			   				    |EQ_08|EQ_10\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

	       break;	
	       case 13:
		       led7_var.bEqIconBuf=EQ_22\
			   				    |EQ_18|EQ_19\
			   				    |EQ_14|EQ_15\
			   				    |EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;
	       break;
	       case 14:
			       led7_var.bEqIconBuf=EQ_20\
			   				    |EQ_16|EQ_17\
			   				    |EQ_12|EQ_13|EQ_14\
			   				    |EQ_08|EQ_09|EQ_10\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

	       break;
	       case 15:
		       led7_var.bEqIconBuf=EQ_28\
			   				    |EQ_24\
			   				    |EQ_20\
			   				    |EQ_16|EQ_18\
			   				    |EQ_12|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

	       break;	
	       case 16:
		       led7_var.bEqIconBuf=EQ_27\
			   				    |EQ_21|EQ_23\
			   				    |EQ_17|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

		break;
	       case 17:
		       led7_var.bEqIconBuf=EQ_28\
			   				    |EQ_24|EQ_26\
			   				    |EQ_20|EQ_22\
			   				    |EQ_16|EQ_18|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

		break;
	       case 18:
		       led7_var.bEqIconBuf=EQ_29\
			   				    |EQ_25|EQ_27\
			   				    |EQ_21|EQ_22|EQ_23\
			   				    |EQ_17|EQ_18|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

		break;
	       case 19:
		       led7_var.bEqIconBuf=EQ_30|EQ_26|EQ_20|EQ_22|EQ_16|EQ_18|EQ_19\
			   				    |EQ_12|EQ_13|EQ_14|EQ_15\
			   				    |EQ_08|EQ_09|EQ_10|EQ_11\
			   				    |EQ_04|EQ_05|EQ_06|EQ_07\
			   				    |EQ_00|EQ_01|EQ_02|EQ_03;

		break;		
		
    }
}



#elif defined(LED_ID_JH820_03) // tm1628

    if(cnt<2)return;
    if(cnt==2)cnt=0;

    switch(ENERGY_TO_STEPS(get_dac_energy_value()))
	{
	       case 0:
		   	#if 1
	  		cnt1++;

		      	 if(cnt1>=15)
		      	   {
		      		   cnt1=9;
		   		led7_var.bEqIconBuf=0;
		      		   led_no_single_freq();
		      		}
			#else

		          	led7_var.bEqIconBuf=0;
			#endif

	       break;
	       case 1:
	       led7_var.bEqIconBuf=EQ_00|EQ_03|EQ_06|EQ_09;
	       break;
	       case 2:
	       led7_var.bEqIconBuf=EQ_00|EQ_03|EQ_06|EQ_09|EQ_01|EQ_04|EQ_07|EQ_10;
	       break;
	       case 3:
	       led7_var.bEqIconBuf=EQ_00|EQ_03|EQ_06|EQ_09|EQ_01|EQ_04|EQ_07|EQ_10|EQ_02|EQ_05|EQ_08|EQ_11;
	       break;
		   
    }
	

#elif defined LED_ID_JW5028B_1B

    if(cnt<2)return;
    if(cnt==2)cnt=0;

    switch(ENERGY_TO_STEPS(get_dac_energy_value()))
	{
	       case 0:
		   	#if 1
	  		cnt1++;

		      	 if(cnt1>=15)
		      	   {
		      		   cnt1=9;
		   		led7_var.bEqIconBuf=0;
		      		   led_no_single_freq();
		      		}
			#else

		          	led7_var.bEqIconBuf=0;
			#endif

	       break;
	       case 1:
	       led7_var.bEqIconBuf=EQ_00|EQ_01;
	       break;
	       case 2:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02;
	       break;
	       case 3:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03;
	       break;
	       case 4:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_03|EQ_04;
	       break;

    }
	
#elif defined LED_ID_ZY_308D

    if(cnt<2)return;
    if(cnt==2)cnt=0;

	#ifdef EQ_ADC_VALUE_DETECT
	    switch(ENERGY_TO_STEPS(adc_value[AD_CH_EQ]))
	#else
	    switch(ENERGY_TO_STEPS(get_dac_energy_value()))
	#endif
	{
	       case 0:
		   	
	  		cnt1++;

		      	 if(cnt1>=15)
		      	   {
		      		   cnt1=9;
		   		led7_var.bEqIconBuf=0;
		      		   led_no_single_freq();
		      		}


	       break;
	       case 1:
	       led7_var.bEqIconBuf=EQ_00|EQ_04;
	       break;
	       case 2:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_04|EQ_05;
	       break;
	       case 3:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_04|EQ_05|EQ_06;
	       break;
	       case 4:
	       led7_var.bEqIconBuf=0xff;
	       break;


    }
#else

    if(cnt<25)return;
    if(cnt==25)cnt=0;

    switch(ENERGY_TO_STEPS(get_dac_energy_value()))
	{
	       case 0:
	          #if 0//defined LED_ID_27N60_8

	  		cnt1++;

		      	 if(cnt1>=15)
		      	   {
		      		   cnt1=9;
		   		led7_var.bEqIconBuf=0;
		      		   led_no_single_freq();
		      		}
			#else
		          	led7_var.bEqIconBuf=0;
			#endif
	       break;
	       case 1:
	       led7_var.bEqIconBuf=EQ_00|EQ_04;
	       break;
	       case 2:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_04|EQ_05;
	       break;
	       case 3:
	       led7_var.bEqIconBuf=EQ_00|EQ_01|EQ_02|EQ_04|EQ_05|EQ_06;
	       break;
	       case 4:
	       led7_var.bEqIconBuf=0xff;
	       break;

    }

#endif





  }


#if 0//def SUPPORT_EQ_FREQUENCE_TIMER_SCAN

 u8 bEqVal,bEqValSave,bEqCnt;
#define ADC_COUNTER 5

void  Disp_freq(void)
{
    static u8 timesw, temp;

	if(workmode==STANBY_WORK_MODE)
		return;
	
	bEqVal=ENERGY_TO_STEPS(adc_value[AD_CH_EQ]);

    if(bEqCnt<ADC_COUNTER)
    {
        bEqValSave+=bEqVal;
        bEqCnt++;
        return;
    }
    else
        bEqCnt=0;

    temp=(bEqValSave/ADC_COUNTER);

    if(temp>=7)
        temp=7;

	if(temp==0)
    	{
		   if((timesw++>150))
		   {
			timesw=0;
			 led_no_single_freq();			
		   }
	}
	else
	{
		timesw=0;
			
	    switch(temp)			
	 	{
		       case 1:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ07;
		       break;
		       case 2:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ07|LED_EQ08;
		       break;
		       case 3:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ07|LED_EQ08|LED_EQ09;
		       break;
		       case 4:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10;
		       break;
		       case 5:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11;
		       break;
		       case 6:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ05|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11|LED_EQ12;
		       break;
		       case 7:
		       led7_var.bEqIconBuf=LED_EQ00|LED_EQ01|LED_EQ02|LED_EQ03|LED_EQ04|LED_EQ05|LED_EQ06|LED_EQ07|LED_EQ08|LED_EQ09|LED_EQ10|LED_EQ11|LED_EQ12|LED_EQ13;
		       break;			   
	 	}
	}
}

#endif

#endif
#endif


#ifdef support_menu_mode

/*----------------------------------------------------------------------------*/
/**@brief   PT2313   œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void LED7_SHOW_VOL_MENU(void)
*/
/*----------------------------------------------------------------------------*/

void led7_show_vol_menu_main(void)
{
  u8 temp;
  
      LED7_DISP_ICON(cl_icon,LED_2POINT|LED_DOT);
 #if LED_2POINT1
     LED_STATUS &=~(LED_2POINT1);
 #endif





  switch(menumode)
  	{
		 #ifdef Support_MSG_MIC_ECO_VOL_KEY
		 	case	MENU_OK_VOL_MODE:
		 		 #if LED_8NUMS==5
		 		 	led7_show_string((u8 *)" N ");
		 		 #elif  LED_8NUMS==7
		 		 	led7_show_string((u8 *)" NIC ");
		 		 #else
	 			 #ifdef LED_ID_6030_C_VFD
	 			 	led7_show_string((u8 *)"");
	 			 #else
	 			 	led7_show_string((u8 *)" N");
	 			 
	 			 #endif
		 		 #endif
		 			printf("--M62429Data[0]--%d\n",M62429Data[0]);
		 			itoa2(M62429Data[0]);
		 			led7_show_string((u8 *)bcd_number);
					 #if defined( LED_ID_1600B_VFD)||defined(LED_ID_6030_C_VFD)
					 	LED_STATUS|=LED_MIC;
					 	LED_STATUS&=~(LED_SW|LED_ECHO|LED_FRONT|LED_SURR|LED_VOLUME);
					 #endif
		 
		 
		 
		 	break;
		 	case	MENU_ECHO_MODE:
		 		 #if LED_8NUMS==5
		 		 	led7_show_string((u8 *)" E ");
		 		 #elif  LED_8NUMS==7
		 		 	led7_show_string((u8 *)"ECHO ");
		 		 #else
	 			 #ifdef LED_ID_6030_C_VFD
	 			 	led7_show_string((u8 *)"");
	 			 #else
	 			 	led7_show_string((u8 *)" E");
	 			 
	 			 #endif
		 		 #endif
		 			printf("--M62429Data[0]--%d\n",M62429Data[1]);
		 			itoa2(M62429Data[1]);
		 			led7_show_string((u8 *)bcd_number);
		 
			 		 #if defined( LED_ID_1600B_VFD)||defined(LED_ID_6030_C_VFD)
					 	LED_STATUS|=LED_ECHO;
					 	LED_STATUS&=~(LED_SW|LED_MIC|LED_FRONT|LED_SURR|LED_VOLUME);
			 		 #endif
		 
		 
		 
		 	break;
		 #endif

         #ifdef SUPPORT_MAIN_VOL_KEY
		 case  MENU_MAIN_VOL_MODE:
	              #if LED_8NUMS==5
	 			 led7_show_string((u8 *)" V ");
	 	      #elif LED_8NUMS==7
	 			 led7_show_string((u8 *)"VOL ");
	              #else
	 			 #ifdef support_1628_show_vol_v
	 			 	led7_show_string((u8 *)"V");
	 			#elif defined(support_3053_show_vol_v)
					 led7_show_string((u8 *)"V ");
	 			 #else
	 			 #ifdef LED_ID_6030_C_VFD
	 			 	led7_show_string((u8 *)"");
	 			 #else
	 			 	led7_show_string((u8 *)"V");
	 			 #endif
	 
	 			 #endif
	 		 #endif
	 		 #if AudVOLMAX>=100
	 			 itoa3(pt2313data[PT_VOLUME]);
	 		 #else
	 			 itoa2(pt2313data[PT_VOLUME]);
	 		 #endif
			 	led7_show_string((u8 *)bcd_number);
	 		#if defined( LED_ID_1600B_VFD)||defined(LED_ID_6030_C_VFD)
				LED_STATUS|=LED_VOLUME;
				LED_STATUS&=~(LED_SW|LED_MIC|LED_FRONT|LED_SURR|LED_ECHO);
	 		 #endif

		 
		 break;
	 #endif
        #ifdef SUPPORT_MSG_FRONT_LEFT
		 case  MENU_FRONT_LEFT_MODE:
		             #if LED_8NUMS==5
		 			led7_show_string((u8 *)" FL");
		             #else
		 			 led7_show_string((u8 *)"FL");
		 			#endif
			 		itoa2(pt2313data[PT_FL]);
			 		led7_show_string((u8 *)bcd_number);
		 break;
        #endif
        #ifdef SUPPORT_MSG_FRONT_RIGHT
		 case  MENU_FRONT_RIGHT_MODE:
		              #if LED_8NUMS==5
		 			 led7_show_string((u8 *)" Fr");
		              #else
		 			 led7_show_string((u8 *)"Fr");
		 			 #endif
			 		itoa2(pt2313data[PT_FR]);
			 		led7_show_string((u8 *)bcd_number);
		 break;
       #endif
         #ifdef Support_MSG_SWVOL
		 case  MENU_SWVOLL_MODE:
	 		    #ifdef LED_SWVOL_SHOW_b
	 	               #if LED_8NUMS==5
	 	 			    led7_show_string((u8 *)" b ");
	 	               #else
	 	 				led7_show_string((u8 *)"b ");
	 	 		  #endif
	 				   
	 			#elif defined(LED_SWVOL_SHOW_s)
				#ifdef LED_ID_6030_C_VFD
					led7_show_string((u8 *)"");
				#else
	 				led7_show_string((u8 *)"S ");
				#endif


				#else
	 	               #if LED_8NUMS==5
	 	 			     led7_show_string((u8 *)" Sb");
	 	 	      #elif LED_8NUMS==7
	 	 			 led7_show_string((u8 *)"SUb ");
	 	               #else

	 				led7_show_string((u8 *)"Sb");
	  	 		  #endif
	 			#endif

	 		 #if AudBALMAX>=100
	 	    		#ifdef pt2313_use_rf_lf_as_sub// 0x0a
	 				 itoa3(pt2313data[PT_FL]);
	 	     		#else
	 				 itoa3(pt2313data[PT_RL]);
	 	    		#endif
	 		 #else
	 	    		#ifdef pt2313_use_rf_lf_as_sub// 0x0a
	 				 itoa2(pt2313data[PT_FL]);
	 	     		#else
	 				 itoa2(pt2313data[PT_RL]);
	 	    		#endif
	 		 #endif

					 led7_show_string((u8 *)bcd_number);
			#if defined( LED_ID_1600B_VFD)||defined(LED_ID_6030_C_VFD)
				LED_STATUS|=LED_SW;
				LED_STATUS&=~(LED_ECHO|LED_MIC|LED_FRONT|LED_SURR|LED_VOLUME);
			 #endif


		 
			 break;
         #endif
         #ifdef Support_MSG_BASS
		 case  MENU_BASS_MODE:
			 temp =pt2313data[PT_BASS];  //PT_BASS
			 if(temp<MAX_TONE/2)
			 {
				 temp = MAX_TONE/2-temp;
		                 #if LED_8NUMS==5
		 				 led7_show_string((u8 *)" b-");
			 	      #elif LED_8NUMS==7
			 			 led7_show_string((u8 *)"baS -");
		                 #else
	 	 			 #ifdef LED_ID_6030_C_VFD
	 	 			 	led7_show_string((u8 *)"");
	 	 			 #else
	 		 				 led7_show_string((u8 *)"b-");
	 	 			 #endif

						 
		  		 #endif
			 }
			 else
			 {
				 temp = temp-MAX_TONE/2;
				 #if LED_8NUMS==5
				 led7_show_string((u8 *)" b ");
		 	      #elif LED_8NUMS==7
		 			 led7_show_string((u8 *)"baS  ");
				 #else
	 	 			 #ifdef LED_ID_6030_C_VFD
	 	 			 	led7_show_string((u8 *)"");
	 	 			 #else
	 		 				 led7_show_string((u8 *)"b ");
	 	 			 #endif
				
				 #endif
			 }
        	#ifdef supper_bass_treble_max_28
				 temp*=2;
          	#endif
          	itoa2(temp);
			led7_show_string((u8 *)bcd_number);
			 break;
        #endif
        #ifdef Support_MSG_TREBLE
		case  MENU_TREBLE_MODE:
			temp =pt2313data[PT_TREB];
			if(temp<MAX_TONE/2)
			{
				temp = MAX_TONE/2-temp;
				#ifdef LED_TREBLE_SHOW_H
				    #if LED_8NUMS==5
	  				led7_show_string((u8 *)" H-");
		 	      #elif LED_8NUMS==7
		 			 led7_show_string((u8 *)"trb -");
				    #else
	 	 			 #ifdef LED_ID_6030_C_VFD
	 	 			 	led7_show_string((u8 *)"");
	 	 			 #else
	 	  				led7_show_string((u8 *)"H-");
	 	 			 #endif


					
	  				#endif
				#else
				    #if LED_8NUMS==5
					led7_show_string((u8 *)" t-");
		 	      #elif LED_8NUMS==7
		 			 led7_show_string((u8 *)"trb -");
				    #else
					led7_show_string((u8 *)"t-");
					#endif
				#endif
			}
			else
			{
				temp = temp-MAX_TONE/2;
               #ifdef LED_TREBLE_SHOW_H
                   #if LED_8NUMS==5
				   led7_show_string((u8 *)" H ");
	 	      #elif LED_8NUMS==7
	 			 led7_show_string((u8 *)"trb  ");
                   #else
	 	 			 #ifdef LED_ID_6030_C_VFD
	 	 			 	led7_show_string((u8 *)"");
	 	 			 #else
	 	  				led7_show_string((u8 *)"H ");
	 	 			 #endif
				   #endif
               #else
                  #if LED_8NUMS==5
					led7_show_string((u8 *)" t ");
	 	      #elif LED_8NUMS==7
	 			 led7_show_string((u8 *)"trb  ");
                  #else
					led7_show_string((u8 *)"t ");
				  #endif
			   #endif
			}
     		#ifdef supper_bass_treble_max_28
					temp*=2;
    		#endif
    		itoa2(temp);
    		led7_show_string((u8 *)bcd_number);

			#if defined( LED_ID_1600B_VFD)||defined(LED_ID_6030_C_VFD)
				LED_STATUS|=LED_FRONT;
				LED_STATUS&=~(LED_ECHO|LED_MIC|LED_SURR|LED_VOLUME|LED_SW);
			 #endif


			
			break;
        #endif
  }
}
#endif

#ifdef Support_MSG_RESET

/*----------------------------------------------------------------------------*/
/**@brief   RESET     œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void LED7_SHOW_RESET(void)
*/
/*----------------------------------------------------------------------------*/

void LED7_SHOW_RESET(void)
{
    #if LED_8NUMS==5
	led7_show_string((u8 *)"rESEt");
    #else
    led7_show_string((u8 *)"rESt");
    #endif
}
#endif


#ifdef SUPPORT_BT_LED_PRORAM

/*----------------------------------------------------------------------------*/
/**@brief   BLUE  ICON  CHAR      œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void blueToothLedProc(void)
*/
/*----------------------------------------------------------------------------*/

void blueToothLedProc(void)
{
    if(compare_task_name(BTSTACK_TASK_NAME))
    	{
		if(led7_var.bBtIfConnect)
		{
			#ifndef SUPPORT_BT_NO_USE_PLAY_PAUSE_ICON		
			 #if LED_PLAY
			 	if(BT_STATUS_PLAYING_MUSIC == get_bt_connect_status())
			 	{
				 	LED_STATUS|=LED_PLAY;
				 	LED_STATUS&=~LED_PAUSE;
					 #ifdef LED_PAUSE2
					 	LED_STATUS &= ~LED_PAUSE2;
					 #endif
			 	}
			 	else
			 	{
				 	 #ifdef LED_PAUSE2
				 	 	LED_STATUS |= LED_PAUSE2;
				 	 #endif
				 	LED_STATUS|=LED_PAUSE;
				 	LED_STATUS&=~LED_PLAY;
			 	}
			 #endif
			 #endif

			#ifdef LED_BT
				#ifdef SUPPORT_LED_BLUE_BT_ICON_FLASH_CONNECT
				    LED_STATUS|=LED_BT;
				    led7_var.wFlashIcon |=LED_BT;
				#elif defined SUPPORT_LED_BLUE_BT_ICON_ALWAY_LIGHT				
				    LED_STATUS|=LED_BT;
				    led7_var.wFlashIcon &=~LED_BT;
				#else
				    LED_STATUS|=LED_BT;
				    led7_var.wFlashIcon &=~LED_BT;
			 	 #ifdef LED_BT1
			 	 	LED_STATUS |=(LED_BT1);	
				    led7_var.wFlashIcon &=~LED_BT1;
			 	 #endif
				#endif
				
			#endif
			 #ifdef SUPPORT_LED_BLUE_STRING_FLASH
			 	   LED_FLASH_CHAR=0;
			 #endif
		}
		else
		{
			 #if LED_PLAY
			 	LED_STATUS&=~LED_PAUSE;
			 	LED_STATUS&=~LED_PLAY;
			 #endif
			 	 #ifdef LED_PAUSE2
			 	 	LED_STATUS &= ~LED_PAUSE2;
			 	 #endif

			#ifdef LED_BT
				#ifdef SUPPORT_LED_BLUE_BT_ICON_FLASH_CONNECT
				    LED_STATUS|=LED_BT;
				    led7_var.wFlashIcon &=~LED_BT;
				#elif defined SUPPORT_LED_BLUE_BT_ICON_ALWAY_LIGHT				
				    LED_STATUS|=LED_BT;
				    led7_var.wFlashIcon &=~LED_BT;					
				#else
				    LED_STATUS|=LED_BT;
				    led7_var.wFlashIcon |=LED_BT;
					
			 	 #ifdef LED_BT1
			 	 	LED_STATUS |=(LED_BT1);	
				    led7_var.wFlashIcon |=LED_BT1;
			 	 #endif
				 
				#endif
				
			#endif
			 #ifdef SUPPORT_LED_BLUE_STRING_FLASH
			 	LED_FLASH_CHAR=0xff;
			 #endif
		 }
    	}
}
#endif


#ifdef LED_SCREEN_SHOW_BAT_STATUS

#define BAT_15 1023*15/33
#define BAT_16 1023*16/33
#define BAT_17 1023*17/33
#define BAT_18 1023*18/33
#define BAT_19 1023*19/33
#define BAT_21 1023*21/33
#define BAT_23 1023*23/33
#define BAT_24 1023*24/33
#define BAT_25 1023*25/33
#define BAT_262 1023*262/(33*10)
#define BAT_226 1023*226/(33*10)


/*----------------------------------------------------------------------------*/
/**@brief   BAT  SCREEN       œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void led7_show_bat_status(void)
*/
/*----------------------------------------------------------------------------*/
#if defined(SUPPORT_FS_BAT_DET_MODE)
u8 bBatMode;
#endif
#if defined SUPPORT_BAT_DETECT_LOW_POWER_MODE_5
extern bool bLowePoweStanbyFlag;
#endif

void led7_show_bat_status(void)
{

#ifdef SUPPORT_BAT_DETECT_USE_IO

#ifdef SUPPORT_BAT_DET_USE_EXTERN_AD_COMPARION
   u16 ad_comparion_value=adc_value[AD_CH_AD_COMPARION];//1023;//led7_var.wAdc_value;
   u16 bat_value_temp=adc_value[AD_CH_BAT];//1023;//led7_var.wAdc_value;

   u16 bat_value;

   bat_value=bat_value_temp;


#else
   u16 bat_value=adc_value[AD_CH_BAT];//1023;//led7_var.wAdc_value;

#endif



   #if defined(LED_ID_88N45)||defined(LED_ID_JW_24017_1B_JW4018D7_1B)||defined(LED_ID_JW4018D_1B)\
   	||defined(LED_ID_SD40X18_1SRB_15)

	static u8 bCnt=0,bTimeCnt=0;
	static u8 btemp1=0,btemp2=0,btemp3=0,btemp4=0;


	 #ifdef SUPPORT_LOW_POWER_DELAY_DET
	 
	 //ø™ª˙µÁ≥ÿ∑≈µÁÃ´¬˝—” ±7s∫ÛºÏ≤‚µÁ≥ÿµÁ—π
	 	if(bLowPowerDetDelay>0)
	   	{
	 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
	 		LED_FLASH_ICON&=~LED_BAT03;
	 		LED_STATUS|=(LED_BAT03);
	 		return;
	   	}
	 #endif

// SUPPORT_BAT_DET_TIMER_ADJUST_TIANYIN    
// 10s ºÏ≤‚“ª¥Œ ¡¨–¯3¥Œ±‰ªØ

         bCnt++;

	 {
	 	#ifdef SUPPORT_BAT_DET_TIMER_ADJUST_TIANYIN
	 		       if(bCnt>250)
		 #else
	 		       if(bCnt>2)		 
		 #endif
	 		 	{
	 		 	        bCnt=0;
	 		 	        bTimeCnt++;

	 		 		if(bat_value>BAT_25)btemp1++;
	 		 		else if(bat_value>BAT_23)btemp2++;
	 		 		else if(bat_value>BAT_21)btemp3++;
	 		 		else btemp4++;
					
		 	 	#ifdef SUPPORT_BAT_DET_TIMER_ADJUST_TIANYIN
		 	 		         if(bTimeCnt==30)
		 		 #else
		 	 		         if(bTimeCnt==10)
		 		 #endif

	 		 	{
				//	printf("-----bat_value--1111---%d\n",bat_value);

	 		 		if(btemp1)
	 		 		{
		 		 		LED_FLASH_ICON&=~LED_BAT03;
	 		 			LED_STATUS|=(LED_BAT01|LED_BAT02|LED_BAT03);
	 		 		}
	 		 		else if(btemp2)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT01);
		 		 		LED_FLASH_ICON&=~LED_BAT03;
	 		 			LED_STATUS|=(LED_BAT02|LED_BAT03);
	 		 		}
	 		 		else if(btemp3)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
		 		 		LED_FLASH_ICON&=~LED_BAT03;
	 		 			LED_STATUS|=(LED_BAT03);
	 		 		}
	 		 		else if(btemp4)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
	 		 			   LED_STATUS|=LED_BAT03;
	 		 			   LED_FLASH_ICON|=LED_BAT03;
	 		 		  }
	 		 		   bTimeCnt=0;
	 		 		   btemp1=0;
	 		 		   btemp2=0;
	 		 		   btemp3=0;
	 		 		   btemp4=0;
	 		 	 }
	 		       }
	 		}

	 #elif defined(LED_ID_40T18SRB)

	static u8 bCnt=0,bTimeCnt=0;
	static u8 btemp1=0,btemp2=0,btemp3=0,btemp4=0,btemp5=0;


	 #ifdef SUPPORT_LOW_POWER_DELAY_DET
	 
	 //ø™ª˙µÁ≥ÿ∑≈µÁÃ´¬˝—” ±7s∫ÛºÏ≤‚µÁ≥ÿµÁ—π
	 	if(bLowPowerDetDelay>0)
	   	{
	 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
	 		LED_FLASH_ICON&=~LED_BAT03;
	 		LED_STATUS|=(LED_BAT03);
	 		return;
	   	}
	 #endif

         bCnt++;

	 {
	 		       if(bCnt>2)
	 		 	{
	 		 	        bCnt=0;
	 		 	        bTimeCnt++;

	 		 		if(bat_value>BAT_25)btemp1++;
	 		 		else if(bat_value>BAT_23)btemp2++;
	 		 		else if(bat_value>BAT_21)btemp3++;
	 		 		else if(bat_value>BAT_15) btemp4++;
					else btemp5++;
						
	 		         if(bTimeCnt==10)
	 		 	{
				//	printf("-----bat_value--1111---%d\n",bat_value);

	 		 		if(btemp1)
	 		 		{
		 		 		LED_FLASH_ICON&=~LED_BAT03;
	 		 			LED_STATUS|=(LED_BAT01|LED_BAT02|LED_BAT03);
	 		 		}
	 		 		else if(btemp2)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT01);
		 		 		LED_FLASH_ICON&=~LED_BAT03;
	 		 			LED_STATUS|=(LED_BAT02|LED_BAT03);
	 		 		}
	 		 		else if(btemp3)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
		 		 		LED_FLASH_ICON&=~LED_BAT03;
	 		 			LED_STATUS|=(LED_BAT03);
	 		 		}
	 		 		else if(btemp4)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
	 		 			   LED_STATUS|=LED_BAT03;
	 		 			   LED_FLASH_ICON|=LED_BAT03;
	 		 		  }
	 		 		else if(btemp4)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02|LED_BAT03);
		 		 		LED_FLASH_ICON&=~LED_BAT03;
	 		 		  }					
	 		 		   bTimeCnt=0;
	 		 		   btemp1=0;
	 		 		   btemp2=0;
	 		 		   btemp3=0;
	 		 		   btemp4=0;
	 		 		   btemp5=0;
	 		 	 }
	 		       }
	 		}

#elif defined(LED_ID_JW_18407_2)

	static u16  bat_cnt;
	static u16 cnt;
	static u8 bCnt=0,bTimeCnt=0;
	static u8 btemp1=0,btemp2=0,btemp3=0,btemp4=0,btemp5=0;



	

#define BAT_300 1023*300/330 //  5V  low power mode
#define BAT_290 1023*290/330 //  5V  low power mode
#define BAT_280 1023*280/330 // 
#define BAT_270 1023*270/330  //  5V  low power mode
#define BAT_260 1023*260/330  //  5V  low power mode

#define BAT_275       1023*275/330
#define  BAT_255      1023*255/330
#define BAT_235       1023*235/330
#define BAT_200       1023*200/330
#define BAT_120       1023*120/330
#define BAT_100       1023*100/330



#ifdef  support_ic_chack_dc_in


		SW_IO_IS_IN();	  
		DC_DET_IO_IS_IN();
		if(((DC_DET_READ())&&( SW_IN_CHECK())&&(workmode==STANBY_WORK_MODE))||((DC_DET_READ())&&(SW_IN_CHECK1()))||((DC_DET_READ())&&( SW_IN_CHECK())))
 		{
 			LED_FLASH_ICON&=~LED_BAT_LOW1;

		    if(bat_value>BAT_300)  //    4.1V   2.75
		     {
				LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1);				
		     }
		     else
		     {
				switch (cnt)
				{
					case  0 :
						LED_STATUS |= (LED_BAT_LOW1|LED_BAT_1 |LED_BAT_2);
						LED_STATUS&=~(LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW);
					break;		
					
					case  300 :
						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_LOW|LED_BAT_LOW1);
						LED_STATUS&=~(LED_BAT_FULL |LED_BAT_HALF);
						
					break;		
					case  600 :
						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1);		
						LED_STATUS&=~LED_BAT_FULL;

					break;		
					case  900 :
						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1);		

					break;		
				}
				cnt++;
				if(cnt>1200)
					cnt=0;
			   
		     }		 
			 
	 }
	else //if((!DC_DET_READ())&&( SW_IN_CHECK()))
#endif
		{

			#if 1
         		bCnt++;

	 	 	 {
	 	 	 		       if(bCnt>20)
	 	 	 		 	{
	 	 	 		 	        bCnt=0;
	 	 	 		 	        bTimeCnt++;
	 	 
	 	 	 		 		if(bat_value>BAT_275)btemp1++;
	 	 	 		 		else if(bat_value>BAT_255)btemp2++;
	 	 	 		 		else if(bat_value>BAT_235)btemp3++;
	 	 	 		 		else if(bat_value>BAT_200) btemp4++;
	 	 					else btemp5++;
	 	 						
	 	 	 		         if(bTimeCnt==10)
	 	 	 		 	{
	 	 
	 	 	 		 		if(btemp1)
	 	 	 		 		{
		 						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1);
	 	 	 		 		}
	 	 	 		 		else if(btemp2)
	 	 	 		 		{
		 						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1);
								LED_STATUS &=~ (LED_BAT_FULL);
	 	 	 		 		}
	 	 	 		 		else if(btemp3)
	 	 	 		 		{
		 						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_LOW|LED_BAT_LOW1);
		 						LED_STATUS &=~ (LED_BAT_FULL |LED_BAT_HALF);
								
	 	 	 		 		}
	 	 	 		 		else if(btemp4)
	 	 	 		 		{
		 						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_LOW1);
		 						LED_STATUS &=~ (LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW);
								
	 	 	 		 		  }
	 	 	 		 		else if(btemp5)
	 	 	 		 		{
               		 		 		LED_STATUS&=~(LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW);
               	 		 			LED_STATUS|=(LED_BAT_1 |LED_BAT_2|LED_BAT_LOW1);
               	 		 			LED_FLASH_ICON|=(LED_BAT_LOW1);
	 	 	 		 		  }					
	 	 	 		 		   bTimeCnt=0;
	 	 	 		 		   btemp1=0;
	 	 	 		 		   btemp2=0;
	 	 	 		 		   btemp3=0;
	 	 	 		 		   btemp4=0;
	 	 	 		 		   btemp5=0;
	 	 	 		 	 }
	 	 	 		       }
	 	 	 	}
			#else
				switch (ldo_power_mod)
				{
					case  1 :
						LED_STATUS |= (LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1|LED_BAT_1 |LED_BAT_2);
					break;		
					case 2:
						LED_STATUS &=~ LED_BAT_FULL;
						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1);
					break;		
					case 3:
						LED_STATUS &=~(LED_BAT_FULL |LED_BAT_HALF );
						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_LOW|LED_BAT_LOW1);
					break;
					case 4:
						LED_STATUS &=~(LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW);
						LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_LOW1);
					break;

					
					case 5:
			//		default:
						bat_cnt++;
						if (bat_cnt >210)
							{
								LED_STATUS &=~ (LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW);
								LED_STATUS |= (LED_BAT_1 |LED_BAT_2|LED_BAT_LOW1);
							}
						
						else
							{						
								LED_STATUS = (LED_BAT_1 |LED_BAT_2);
								LED_STATUS &=~ (LED_BAT_FULL |LED_BAT_HALF|LED_BAT_LOW|LED_BAT_LOW1);
							}

						if (bat_cnt >420)
						bat_cnt=0;
					break;
					
					
				}
			#endif

		}



	 
	 #elif defined(LED_ID_JW5028B_1B)

	static u8 bCnt=0,bTimeCnt=0;
	static u8 btemp1=0,btemp2=0,btemp3=0,btemp4=0,btemp5=0;

         bCnt++;

	 {
	 		       if(bCnt>5)
	 		 	{
	 		 	        bCnt=0;
	 		 	        bTimeCnt++;

	 		 		if(bat_value>BAT_25)btemp1++;
	 		 		else if(bat_value>BAT_23)btemp2++;
	 		 		else if(bat_value>BAT_21)btemp3++;
	 		 		else btemp4++;

	 		         if(bTimeCnt==20)
	 		 	{

	 		 		if(btemp1)
	 		 		{
	 		 			LED_FLASH_ICON&=~(LED_BAT04);
	 		 			LED_STATUS|=(LED_BAT01|LED_BAT02|LED_BAT03|LED_BAT04);
	 		 		}
	 		 		else if(btemp2)
	 		 		{
	 		 			LED_FLASH_ICON&=~(LED_BAT04);
		 		 		LED_STATUS&=~(LED_BAT01);
	 		 			LED_STATUS|=(LED_BAT02|LED_BAT03|LED_BAT04);
	 		 		}
	 		 		else if(btemp3)
	 		 		{
	 		 			LED_FLASH_ICON&=~(LED_BAT04);
						LED_STATUS&=~(LED_BAT02|LED_BAT01);
	 		 			LED_STATUS|=(LED_BAT03|LED_BAT04);
	 		 		  }
	 		 		else if(btemp4)
	 		 		{
		 		 		LED_STATUS&=~(LED_BAT02|LED_BAT03|LED_BAT01);
	 		 			LED_STATUS|=(LED_BAT04);
	 		 			LED_FLASH_ICON|=(LED_BAT04);

	 		 		  }

	 		 		   bTimeCnt=0;
	 		 		   btemp1=0;
	 		 		   btemp2=0;
	 		 		   btemp3=0;
	 		 		   btemp4=0;
	 		 	 }
	 		       }
	 		}


	 #elif defined(LED_ID_JW18407_1B)  // SUPPORT_FS_BAT_DET_MODE

		 #ifdef SUPPORT_BAT_DETECT_LOW_POWER_MODE_5

		 // µÕ”⁄2.82V…Ÿ“ª∏Ò£¨2.68V…Ÿ∂˛∏Ò£¨2.56V…Ÿ»˝∏Ò£¨
		 // 2.38V…ŸÀƒ∏Ò£®¡¡µÁ≥ÿøÚÀµµÁ≥ÿµÁ¡ø≤ª◊„£© 2.2V¥˝ª˙µÁ≥ÿøÚ…¡
		 	static u16 bCnt=0;
		 	static u16 btemp1=0,btemp2=0,btemp3=0,btemp4=0,btemp5=0,btemp6=0;
		 	static u8 bTimeCnt=0;


			if(bLowePoweStanbyFlag)
	 		{
		 		LED_STATUS&=~(LED_BAT01|LED_BAT02|LED_BAT03|LED_BAT04);
	 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
	 			LED_FLASH_ICON|=(LED_BAT_K1|LED_BAT_K2);
				return;
	 		  }


		          bCnt++;

		 	 {
		 	 		       if(bCnt>100)// 300ms check onice
		 	 		 	{
		 	 		 	        bCnt=0;
		 	 		 	        bTimeCnt++;
			 		 		// 280  268  256  237  222

							if(bBatMode==4)
								{
				 	 		 		if(bat_value<(226*(ad_comparion_value/25)/10))btemp6++;
								}
							else  // 286  274 261 242  226 
								{
									#ifdef SUPPORT_FS_K137A_BAT_VAL
					 	 		 		if(bat_value>(277*(ad_comparion_value/25)/10))btemp1++;
					 	 		 		else if(bat_value>(269*(ad_comparion_value/25)/10))btemp2++;
					 	 		 		else if(bat_value>(256*(ad_comparion_value/25)/10))btemp3++;
					 	 		 		else if(bat_value>(242*(ad_comparion_value/25)/10))btemp4++;
					 	 		 		else  if(bat_value>(226*(ad_comparion_value/25)/10))btemp5++;
										else if(bat_value<(226*(ad_comparion_value/25)/10))btemp6++;
									#else
					 	 		 		if(bat_value>(286*(ad_comparion_value/25)/10))btemp1++;
					 	 		 		else if(bat_value>(274*(ad_comparion_value/25)/10))btemp2++;
					 	 		 		else if(bat_value>(261*(ad_comparion_value/25)/10))btemp3++;
					 	 		 		else if(bat_value>(242*(ad_comparion_value/25)/10))btemp4++;
					 	 		 		else  if(bat_value>(226*(ad_comparion_value/25)/10))btemp5++;
										else if(bat_value<(226*(ad_comparion_value/25)/10))btemp6++;
									#endif
								
								}

		 	 		       if(bTimeCnt==25) // 10m
		 	 		 	{
		 					bTimeCnt=0;

		 	 		 		if(btemp1>=25)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 	 		 		   	btemp6=0;
		 						bBatMode=0;
		 	 		 		}
		 	 		 		else if(btemp2>=25)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 	 		 		   	btemp6=0;
		 						bBatMode=1;
		 	 		 		}
		 	 		 		else if(btemp3>=25)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 	 		 		   	btemp6=0;
		 						bBatMode=2;
		 	 		 		}
		 	 		 		else if(btemp4>=25)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp6=0;
		 	 		 		   	btemp5=0;
		 						bBatMode=3;
		 	 		 		  }
		 	 		 		else if(btemp5>=25)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 	 		 		   	btemp6=0;
		 						bBatMode=4;
		 	 		 		  }
		 	 		 		else if(btemp6>=25)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 	 		 		   	btemp6=0;
		 						bBatMode=5;
		 	 		 		  }
		 	 		 	 }

		 	 		 		if(bBatMode==0)
		 	 		 		{
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT01|LED_BAT02|LED_BAT03|LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		}
		 	 		 		else if(bBatMode==1)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT02|LED_BAT03|LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		}
		 	 		 		else if(bBatMode==2)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT03|LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		}
		 	 		 		else if(bBatMode==3)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02|LED_BAT03);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		  }
		 	 		 		else if(bBatMode==4)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02|LED_BAT03|LED_BAT04);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		  }
		 	 		 		else if(bBatMode==5)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02|LED_BAT03|LED_BAT04);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_FLASH_ICON|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 		  }
		 	 		       }
		 	 		}


		 #else

		 // µÕ”⁄2.62V…Ÿ“ª∏Ò£¨2.5V…Ÿ∂˛∏Ò£¨2.4V…Ÿ»˝∏Ò£¨2.26V…ŸÀƒ∏Ò£®ÀµµÁ≥ÿµÁ¡ø≤ª◊„£©
		 // µÕ”⁄2.62V…Ÿ“ª∏Ò£¨2.5V…Ÿ∂˛∏Ò£¨2.35V…Ÿ»˝∏Ò£¨2.22V…ŸÀƒ∏Ò£®ÀµµÁ≥ÿµÁ¡ø≤ª◊„£©
		 	static u16 bCnt=0;
		 	static u16 btemp1=0,btemp2=0,btemp3=0,btemp4=0,btemp5=0;
		 	static u8 bTimeCnt=0;



		          bCnt++;

		 	 {
		 	 		       if(bCnt>25)// 200ms
		 	 		 	{
		 	 		 	        bCnt=0;
		 	 		 	        bTimeCnt++;

		 //					printf("-----bat_value--1111---%2d\n",bat_value);
		 //					printf("-----(262*(ad_comparion_value/25)/10)--1111---%2d\n",(262*(ad_comparion_value/25)/10));
		 //					printf("-----(250*(ad_comparion_value/25)/10)--1111---%2d\n",(250*(ad_comparion_value/25)/10));
		 //					printf("-----(240*(ad_comparion_value/25)/10)--1111---%2d\n",(240*(ad_comparion_value/25)/10));
		 // 					printf("-----(226*(ad_comparion_value/25)/10)--1111---%2d\n",(226*(ad_comparion_value/25)/10));

		 	 		 		if(bat_value>(263*(ad_comparion_value/25)/10))btemp1++;
		 	 		 		else if(bat_value>(253*(ad_comparion_value/25)/10))btemp2++;
		 	 		 		else if(bat_value>(238*(ad_comparion_value/25)/10))btemp3++;
		 	 		 		else if(bat_value>(229*(ad_comparion_value/25)/10))btemp4++;
		 	 		 		else  if(bat_value<(225*(ad_comparion_value/25)/10))btemp5++;

		 	 		       if(bTimeCnt==50) // 10m
		 	 		 	{
		 					bTimeCnt=0;

		 	 		 		if(btemp1>=30)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 						bBatMode=0;
		 	 		 		}
		 	 		 		else if(btemp2>=30)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 						bBatMode=1;
		 	 		 		}
		 	 		 		else if(btemp3>=30)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 						bBatMode=2;
		 	 		 		}
		 	 		 		else if(btemp4>=30)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 						bBatMode=3;
		 	 		 		  }
		 	 		 		else if(btemp5>=30)
		 	 		 		{
		 	 		 		   	btemp1=0;
		 	 		 		   	btemp2=0;
		 	 		 		   	btemp3=0;
		 	 		 		   	btemp4=0;
		 	 		 		   	btemp5=0;
		 						bBatMode=4;
		 	 		 		  }
		 	 		 	 }

		 	 		 		if(bBatMode==0)
		 	 		 		{
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT01|LED_BAT02|LED_BAT03|LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		}
		 	 		 		else if(bBatMode==1)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT02|LED_BAT03|LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		}
		 	 		 		else if(bBatMode==2)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT03|LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		}
		 	 		 		else if(bBatMode==3)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02|LED_BAT03);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_STATUS|=(LED_BAT04);
		 	 		 			LED_FLASH_ICON&=~(LED_BAT_K1|LED_BAT_K2);
		 	 		 		  }
		 	 		 		else if(bBatMode==4)
		 	 		 		{
		 		 		 		LED_STATUS&=~(LED_BAT01|LED_BAT02|LED_BAT03|LED_BAT04);
		 	 		 			LED_STATUS|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 			LED_FLASH_ICON|=(LED_BAT_K1|LED_BAT_K2);
		 	 		 		  }
		 	 		       }
		 	 		}

	    	#endif

	   #endif
  #endif
}

#endif


#ifdef SUPPORT_LOW_POWER_USE_LED_SHOW

/*----------------------------------------------------------------------------*/
/**@brief   MUTE  STATE       œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void led7_low_power_show(void)
*/
/*----------------------------------------------------------------------------*/


void led7_low_power_show(void)
{


if(workmode ==STANBY_WORK_MODE )
	return;

  #ifdef SUPPORT_LOW_POWER_LED_SHOW_BAT_FLASH

	if(low_power_flag)
	{
	    led7_var.bShowBuff[0]=0;
	    led7_var.bShowBuff[1]=0x7c;
	    led7_var.bShowBuff[2]=0x77;
	    led7_var.bShowBuff[3]=0x78;
	    LED_STATUS &=~(LED_2POINT|LED_DOT);
	    LED_FLASH_ICON &=~(LED_2POINT|LED_DOT);
	 #if LED_2POINT1
	     LED_STATUS &=~(LED_2POINT1);
	     LED_FLASH_ICON &=~(LED_2POINT1);
	 #endif
	}

#elif defined SUPPORT_LOW_POWER_LED_ALL_SCREEN_FLASH
	if(low_power_flag)
		{
		     LED_FLASH_CHAR=0xff;
		     LED_FLASH_ICON=0xffff;
		}
#endif
}

#endif


#ifdef SUPPORT_LED_LOW_SHOW_LDO
extern u8 bLowPowerShowFlag;					 

/*----------------------------------------------------------------------------*/
/**@brief   MUTE  STATE       œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void led7_mute_flash(void)
*/
/*----------------------------------------------------------------------------*/


void led7_low_power_show_flah(void)
{

  if(!bLowPowerShowFlag)
  {
	  return;
  }
  

	    LED_STATUS &=~(LED_2POINT|LED_DOT|LED_FM);

	    led7_var.bShowBuff[0]=0x40;
	    led7_var.bShowBuff[1]=0x7C;
	    led7_var.bShowBuff[2]=0x38;
	    led7_var.bShowBuff[3]=0x3f;



	     LED_FLASH_CHAR=0xff;
	     LED_FLASH_ICON=0xffff;

}
#endif

#ifdef SUPPORT_MUTE_FLASH

/*----------------------------------------------------------------------------*/
/**@brief   MUTE  STATE       œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void led7_mute_flash(void)
*/
/*----------------------------------------------------------------------------*/


void led7_mute_flash(void)
{

  if(!mute_flag)
  {
	  return;
  }
  

  #if defined(SUPPORT_LED7_SHOW_V00_MUTE_STATE)
  
	 #ifdef SUPPORT_TY_8848_OFF_ICON
	    LED_STATUS &=~(LED_USB|LED_SD|LED_MP3|LED_PLAY|LED_FM);
	 #endif

    #if LED_8NUMS==6  //show cur file num
	    led7_var.bShowBuff[0]=0x3e;
	    led7_var.bShowBuff[1]=0x3f;
	    led7_var.bShowBuff[2]=0x38;
	    led7_var.bShowBuff[3]=0;
	    led7_var.bShowBuff[4]=0x3f;
	    led7_var.bShowBuff[5]=0x3f;
	     LED_FLASH_CHAR=0xff;
	     LED_FLASH_ICON=0xffff;
    #elif LED_8NUMS==7  //show cur file num
	    led7_var.bShowBuff[0]=0;	
	    led7_var.bShowBuff[1]=0x3e;
	    led7_var.bShowBuff[2]=0x3f;
	    led7_var.bShowBuff[3]=0x38;
	    led7_var.bShowBuff[4]=0;
	    led7_var.bShowBuff[5]=0x3f;
	    led7_var.bShowBuff[6]=0x3f;

	     LED_FLASH_CHAR=0xff;
	     LED_FLASH_ICON=0xffff;		 
	#else
//	led7_show_string((u8 *)" V00");
	    led7_var.bShowBuff[0]=0x3e;
	    led7_var.bShowBuff[1]=0;
	    led7_var.bShowBuff[2]=0x3f;
	    led7_var.bShowBuff[3]=0x3f;
 	#endif
		LED_STATUS=0;
	    LED_STATUS &=~(LED_2POINT|LED_DOT);
	    LED_FLASH_ICON &=~(LED_2POINT|LED_DOT);

	 #ifdef SUPPORT_MUTE_STATE_OFF_USB_SD_ICON
		 LED_STATUS &=~(LED_USB|LED_SD);
	 #endif

	 #if LED_2POINT1
	     LED_STATUS &=~(LED_2POINT1);
	     LED_FLASH_ICON &=~(LED_2POINT1);
	 #endif
  #endif

  #if defined(MUTE_FLASH_ALL_SCREEN)
	     LED_FLASH_CHAR=0xff;
	     LED_FLASH_ICON=0xffff;
  #endif
}
#endif


#ifdef SUPPORT_MIC_ONOFF_SHOW
u8 bLedShowOnoffTimer;

/*----------------------------------------------------------------------------*/
/**@brief   MUTE  STATE       œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void led7_mute_flash(void)
*/
/*----------------------------------------------------------------------------*/

void led7_onoff_show(void)
{

  if(workmode ==STANBY_WORK_MODE )
	return;
  

  if(bLedShowOnoffTimer==0)
  	return;
  


	if(mic_sw)
		{
		    led7_var.bShowBuff[0]=0;
		    led7_var.bShowBuff[1]=0x3f;//O
		    led7_var.bShowBuff[2]=0x37; //N
		    led7_var.bShowBuff[3]=0;
		}
	else
		{
		    led7_var.bShowBuff[0]=0;
		    led7_var.bShowBuff[1]=0x3f;//O
		    led7_var.bShowBuff[2]=0x71; //F
		    led7_var.bShowBuff[3]=0x71;//F
		}
	    LED_STATUS &=~(LED_2POINT|LED_DOT);
	    LED_FLASH_ICON &=~(LED_2POINT|LED_DOT);
	#if LED_2POINT1
	    LED_STATUS &=~(LED_2POINT1);
	    LED_FLASH_ICON &=~(LED_2POINT1);
	#endif

}
#endif

#ifdef support_led_rgy_running

void led7_led_rgy_running_show(void)
{
	static u16 mode;
	static u16 cnt;
	 	 switch(mode)
		 {
			case 1:
					    LED_STATUS &=~LED_R;
					    LED_STATUS |=(LED_Y|LED_LG);
			break;
			case 2:
					    LED_STATUS &=~LED_Y;
					    LED_STATUS |=(LED_R|LED_LG);
			break;
			case 3:
					    LED_STATUS &=~LED_LG;
					    LED_STATUS |=(LED_R|LED_Y);
			break;
	 	 }
	 	 if(*music_ui.ui_curr_statu != DECODER_PAUSE)
		 	 cnt++;
	 	 if(cnt>20)
		 {
		 	 cnt=0;
		 	 mode++;
		 	 if(mode>3)
			 	mode=1;
	 	 }
	#if 0
	  if(compare_task_name("MusicTask"))
	  {

	  }

	 else
	 	{
		 	switch(mode)
		 		{
		 			case 50:
		 					    LED_STATUS &=~LED_R;
		 					    LED_STATUS |=(LED_Y|LED_LG);
		 			break;
		 			case 100:
		 					    LED_STATUS &=~LED_Y;
		 					    LED_STATUS |=(LED_R|LED_LG);
		 			break;
		 			case 150:
		 					    LED_STATUS &=~LED_LG;
		 					    LED_STATUS |=(LED_R|LED_Y);
		 			break;
		 		}
		 
		 		 	 mode++;
		 		 	 if(mode>150)
		 			 	mode=50;	 		
	 	}
	

#endif

	
}



#endif

#ifdef LED_ID_1600B_VFD
void led7_1660b_show(void)
{

	 if(workmode==STANBY_WORK_MODE)
	 {
	 	
	     led7_var.bShowBuff[0x0c]&=~0x10;    
	     led7_var.bShowBuff[0x0a]&=~0x10;    
	     led7_var.bShowBuff[0x08]&=~0x10;    
	     led7_var.bShowBuff[0x00]&=~0x10;
	 }
	 else
	 {
	     led7_var.bShowBuff[0x0c]|=0x10;    
	     led7_var.bShowBuff[0x0a]|=0x10;    
	     led7_var.bShowBuff[0x08]|=0x10;    
	     led7_var.bShowBuff[0x00]|=0x10;	
	 }

}
#endif






/*----------------------------------------------------------------------------*/
/**@brief   TM1628  SEND XX     œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void (void)
*/
/*----------------------------------------------------------------------------*/



#if defined(SUPPORT_TM1628_MODE)||defined(SUPPORT_PT6312_MODE)

#define  delayus()  delay(5)




void  WR_HT1628_Byte(u8 data)
{
    u8 i;


    for(i=0; i<8; i++)
    {
        HT1628_DATA(data&0x01);
        HT1628_CLK(0);  //---------|
        delayus();
        data>>=1;//-------|
        HT1628_CLK(1);  ;//---------|___|----/√É‚Ä∞√É¬è√É‚Ä∞√É¬Ω√É‚Äò√ÉÀú√É‚Äú√É¬ê√É¬ê√Ç¬?
        delayus();
    }
    HT1628_DATA(0);
}



void  WR_HT1628_CMD(u8 cmd)
{

    HT1628_STB(0) ;//√É‚Ä†√Ç¬¨√É‚Äò√Ç¬°√Ç¬£√Ç¬?√É‚Äú√É¬ê√É¬ê√Ç¬?
    delayus();
    WR_HT1628_Byte(cmd);
    HT1628_STB(1);//√É‚Ä†√Ç¬¨√É‚Äò√Ç¬°√Ç¬£√Ç¬?√É‚Äú√É¬ê√É¬ê√Ç¬?
    HT1628_DATA(0);
    delayus();
    delayus();

}
#ifdef SUPPORT_TM1628_KEY_READ
u8 HT1628_READ_BYTE(void)
{
 u8 i,btemp=0;
 for(i=0;i<8;i++){   
   HT1628_CLK(0);  //---------|
   delayus();    
   delayus(); 
   HT1628_CLK(1);
   delayus(); 
   if(HT1628_DATA_READ())
   btemp|=BIT(i);
   delayus();   
   delayus();
}
  return btemp;
}
void HT1628_READ_KEY_PROCESS(void)
{
   u8 i;
   HT1628_STB(0);   
   delayus();
   WR_HT1628_Byte(0x42);
   delayus();
   delayus();
  // HT1628_DATA(1);
  // delayus();
   HT1628_DATA_IN();   
   delayus();
   for(i=0;i<TM1628_SCAN_BYTE;i++){
   led7_var.wTm1628KeyData=((i<<8)|HT1628_READ_BYTE());
   if(led7_var.wTm1628KeyData&0x00ff)break;
   }      
   delayus();
   HT1628_STB(1);
   HT1628_DATA_OUT();
}
 tu8 get_led_driver_key_value(void)
{

//printf("-----led7_var.wTm1628KeyData--------%4x\n",led7_var.wTm1628KeyData);
	
#ifdef LED_KEY_USE_ZY_HJ802_1_4KEY

   if(led7_var.wTm1628KeyData==0x0001) return LED_KEY_PP;   //pp
   if(led7_var.wTm1628KeyData==0x0002) return LED_KEY_PREV;   //prev
   if(led7_var.wTm1628KeyData==0x0008) return LED_KEY_MODE;  // mode
   if(led7_var.wTm1628KeyData==0x0010) return LED_KEY_NEXT; // next
   
#endif

  
  return LED_KEY_NULL;
} 

#endif


#endif

#ifdef SUPPORT_TM1618_MODE
#define  delayus()  delay(5)
void  WR_TM1618_Byte(u8 data)
{
    u8 i;


    for(i=0; i<8; i++)
    {
        HT1618_DATA(data&0x01);
        HT1618_CLK(0);  //---------|
        delayus();
        data>>=1;//-------|
        HT1618_CLK(1);  ;
        delayus();
    }
    HT1618_DATA(0);
}



void WR_TM1618_CMD(u8 cmd)
{


    HT1618_STB(0) ;
    delayus();
    WR_TM1618_Byte(cmd);
    HT1618_STB(1);
    HT1618_DATA(0);
    delayus();
    delayus();

}

#endif


/*----------------------------------------------------------------------------*/
/**@brief   LED7  7G8  CIRCLE ◊™≈Ã     œ‘ æΩÁ√Ê
   @param   void
   @return  void
   @note    void LED_CIRCLE_PROCESS(void)
*/
/*----------------------------------------------------------------------------*/


#if defined(LED_ID_JW2781)||defined(LED_ID_8SD78YRG)
void LED_CIRCLE_PROCESS(void)
{
static u8 cnt=0;
static u8 mode=0;
#ifdef LED_ID_JW2781_ZX_MODE
	//  if(compare_task_name("MusicTask"))
	  {
	 	 led7_var.bCircleBuf=0xff;
	 	 switch(mode)
		 {
		 	   case 0:
		 		   led7_var.bCircleBuf&=~(BIT(0)|BIT(4));
		   	       break;
		 	   case 1:
		 		   led7_var.bCircleBuf&=~(BIT(1)|BIT(5));
		 	       break;
		 	   case 2:
		 		   led7_var.bCircleBuf&=~(BIT(2)|BIT(6));
		 	       break;
		 	   case 3:
		 		   led7_var.bCircleBuf&=~(BIT(3)|BIT(7));
		 	      break;
	 	 }
 	 if(((*music_ui.ui_curr_statu != DECODER_PAUSE)&&(compare_task_name("MusicTask")))||(!compare_task_name("MusicTask")))
		 	 cnt++;
	 	 if(cnt>6)
		 {
		 	 cnt=0;
		 	 mode++;
		 	 if(mode>3)mode=0;
	 	 }
	  }

//	 else
	// 	led7_var.bCircleBuf=0;
#else
	  if(compare_task_name("MusicTask"))
	  {
	 	 led7_var.bCircleBuf=0xff;
	 	 switch(mode)
		 {
		 	   case 0:
		 		   led7_var.bCircleBuf&=~(BIT(0)|BIT(4));
		   	       break;
		 	   case 1:
		 		   led7_var.bCircleBuf&=~(BIT(1)|BIT(5));
		 	       break;
		 	   case 2:
		 		   led7_var.bCircleBuf&=~(BIT(2)|BIT(6));
		 	       break;
		 	   case 3:
		 		   led7_var.bCircleBuf&=~(BIT(3)|BIT(7));
		 	      break;
	 	 }
	 	 if(*music_ui.ui_curr_statu != DECODER_PAUSE)
		 	 cnt++;
	 	 if(cnt>2)
		 {
		 	 cnt=0;
		 	 mode++;
		 	 if(mode>3)mode=0;
	 	 }
	  }

	 else
	 	led7_var.bCircleBuf=0;

#endif

}
#endif



  #ifdef LED_SHOW_DEVICE_PLUGIN

void led7_show_device_main(void)
{
    if(led7_var.dwDeviceID==usb )
    {
        LED_STATUS |= LED_USB;
        LED_STATUS &=~ LED_2POINT;
	 led7_show_string((u8 *)device_string[0]);
    }
    else if((led7_var.dwDeviceID==sd0 )||(led7_var.dwDeviceID==sd1))
    {
        LED_STATUS |= LED_SD;
	 LED_STATUS &=~ LED_2POINT;
	 led7_show_string((u8 *)device_string[1]);
    }
}
#endif


#ifdef SUPPORT_RGB_LED_MODE
extern u8 bRgbMode;
#include "sys_detect.h"
const u8 rgb_string[][5]=
{
"LED",
" 0FF"
};
void  led7_show_rgb_led_mode_main(void)
{

	    LED_STATUS &=~(LED_2POINT|LED_DOT);

	if(bRgbMode==RGB_MODE_OFF)
		led7_show_string((u8 *)rgb_string[1]);
	else
		{
			led7_show_string((u8 *)rgb_string[0]);
			led7_show_char(bRgbMode%10 + '0');
		}
	
}
#endif

/*----------------------------------------------------------------------------*/
///-------------CUSTOMER  UI  ADD---JSUO-----------------------------------
/*----------------------------------------------------------------------------*/


#if defined(SUPPORT_TM1628_MODE)

void LED_drive7(void)
{
   u8 i,j;
   #ifdef LED_ID_DB_51
    u32 temp1,temp2;
    u32 temp;
   #else
    u16 temp1,temp2;
    u16 temp;
#endif


    led7_var.bShowBuff1[0]=0;
    led7_var.bShowBuff1[1]=0;
    led7_var.bShowBuff1[2]=0;
    led7_var.bShowBuff1[3]=0;
    led7_var.bShowBuff1[4]=0;
    led7_var.bShowBuff1[5]=0;
    led7_var.bShowBuff1[6]=0;
    led7_var.bShowBuff1[7]=0;
    led7_var.bShowBuff1[8]=0;
    led7_var.bShowBuff1[9]=0;
    led7_var.bShowBuff1[10]=0;
    led7_var.bShowBuff1[11]=0;
    led7_var.bShowBuff1[12]=0;
    #if LED_COM_MAX>=14
    led7_var.bShowBuff1[13]=0;
    #endif
    #if LED_COM_MAX>=15
    led7_var.bShowBuff1[14]=0;
    #endif
    #if LED_COM_MAX>=16
    led7_var.bShowBuff1[15]=0;
    #endif

#ifdef SUPPORT_BT_LED_PRORAM
    if(compare_task_name("BtStackTask"))
     blueToothLedProc();
#endif

    #if defined(LED_ID_JW2781)||defined(LED_ID_8SD78YRG)
    LED_CIRCLE_PROCESS();
    #endif


 #if LED_REPEAT_ONE||LED_REPEAT_ALL

 		LED_STATUS&=~(LED_REPEAT_ONE|LED_REPEAT_ALL);
 		 #ifdef SUPPORT_FLASH_ICON
 		 	LED_FLASH_ICON&=~LED_REPEAT_ONE;
 		 #endif

 	if(compare_task_name("MusicTask"))
 	{
 		if(play_mode==REPEAT_ONE)
 		{
 		    LED_STATUS|=LED_REPEAT_ONE;
 		    #ifdef SUPPORT_FLASH_ICON
 			LED_FLASH_ICON|=LED_REPEAT_ONE;
 		    #endif
 		}
 		else if(play_mode==REPEAT_ALL)
 			LED_STATUS|=LED_REPEAT_ALL;
 	}
 #endif

     #ifdef LED_SCREEN_SHOW_BAT_STATUS
	 led7_show_bat_status();
    #endif

    #ifdef SUPPORT_MUTE_FLASH
	    led7_mute_flash();
    #endif

#if defined(SUPPORT_EQ_FREQUENCE)
	 LED_FREQUENCE_PROCESS();
#endif


#ifdef LED_ID_1600B_VFD
	if(workmode==STANBY_WORK_MODE)
	{
	   
		led7_var.bShowBuff1[0x0c]&=~0x10;	
		led7_var.bShowBuff1[0x0a]&=~0x10;	
		led7_var.bShowBuff1[0x08]&=~0x10;	
		led7_var.bShowBuff1[0x00]&=~0x10;
		
		led7_var.bEqIconBuf=0;	
  		LED_STATUS&=~(LED_SW|LED_ECHO|LED_FRONT|LED_SURR|LED_VOLUME|LED_MIC);
	}
	else
	{
		led7_var.bShowBuff1[0x0c]|=0x10;    
		led7_var.bShowBuff1[0x0a]|=0x10;    
		led7_var.bShowBuff1[0x08]|=0x10;    
		led7_var.bShowBuff1[0x00]|=0x10;    
		
		 #if defined(SUPPORT_EQ_FREQUENCE)
		 	LED_FREQUENCE_PROCESS();
		 #endif


	}
#endif





	#if LED_EQ_NUMS>=LED_ICON_NUMS

	for(i=0;i<LED_EQ_NUMS;i++)
	{

	 #ifdef SUPPORT_EQ_FREQUENCE
	 	temp2=led7_var.bEqIconBuf;
	       if(temp2&BIT(i))
	          led7_var.bShowBuff1[led_EQ[i]>>8]|=led_EQ[i];

		 #if defined(LED_ID_LD999B_J)
			// HIFI_L-0480	HIFI_R-0280
			// EQ_L_U: 0C80  0A80  0880  0680
			// EQ_R_U: 0D01  0B01  0901  0701
			// HEARD_CHAR: 0B02 0902  0501  0301

			if(workmode!=STANBY_WORK_MODE)
				{
				 	 led7_var.bShowBuff1[0X04]|=0X80;
				 	 led7_var.bShowBuff1[0X02]|=0X80;
				 	 led7_var.bShowBuff1[0X0C]|=0X80;
				 	 led7_var.bShowBuff1[0X0A]|=0X80;
				 	 led7_var.bShowBuff1[0X08]|=0X80;
				 	 led7_var.bShowBuff1[0X06]|=0X80;
				 	 led7_var.bShowBuff1[0X0D]|=0X01;
				 	 led7_var.bShowBuff1[0X0B]|=0X01;
				 	 led7_var.bShowBuff1[0X09]|=0X01;
				 	 led7_var.bShowBuff1[0X07]|=0X01;
					//  ÷™––∫œ“ª
				 	// led7_var.bShowBuff1[0X0B]|=0X02;
				 	 //led7_var.bShowBuff1[0X09]|=0X02;
				 	 //led7_var.bShowBuff1[0X05]|=0X01;
				 	 //led7_var.bShowBuff1[0X03]|=0X01;
				}
		 #endif

	 #endif


		 if(i<LED_ICON_NUMS)
		 	{
				temp1=led7_var.wLedIcon;

			     #ifdef SUPPORT_FLASH_ICON
			 	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
			 	temp1&=~(led7_var.wFlashIcon);
			     #endif

				 if(temp1&BIT(i))
				 {
					 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
				 }
				#if defined(LED_ID_JW2781)||defined(LED_ID_8SD78YRG)
					if(i<8 && (led7_var.bCircleBuf&BIT(i)))
						led7_var.bShowBuff1[led_circle_value[i]>>8]|=led_circle_value[i];
				#endif
		 	}


		 if(i<LED_8NUMS)
		 {
			 temp=led7_var.bShowBuff[i];
		     #ifdef SUPPORT_FLASH_CHAR
			 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
				 temp=0;
		     #endif
			 for(j=0;j<LED_8GRIDS;j++)
			 if(temp&BIT(j))
			 led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
		 }
	 }


	#elif LED_ICON_NUMS>=LED_8NUMS

	for(i=0;i<LED_ICON_NUMS;i++)
	{

	 #ifdef SUPPORT_EQ_FREQUENCE
	 	temp2=led7_var.bEqIconBuf;
	       if(temp2&BIT(i))
	          led7_var.bShowBuff1[led_EQ[i]>>8]|=led_EQ[i];
	 #endif



		temp1=led7_var.wLedIcon;

	     #ifdef SUPPORT_FLASH_ICON
	 	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
	 	temp1&=~(led7_var.wFlashIcon);
	     #endif

		 if(temp1&BIT(i))
		 {
			 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
		 }
		#if defined(LED_ID_JW2781)||defined(LED_ID_8SD78YRG)
			if(i<8 && (led7_var.bCircleBuf&BIT(i)))
				led7_var.bShowBuff1[led_circle_value[i]>>8]|=led_circle_value[i];
		#endif


		 if(i<LED_8NUMS)
		 {
			 temp=led7_var.bShowBuff[i];
		     #ifdef SUPPORT_FLASH_CHAR
			 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
				 temp=0;
		     #endif
			 for(j=0;j<LED_8GRIDS;j++)
			 if(temp&BIT(j))
			 led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
		 }
	 }

    #else



 	for(i=0;i<LED_8NUMS;i++)
 	{
 		if(i<LED_ICON_NUMS)
 		{
 			 if(temp1&BIT(i))
 			 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
 		 }

 		temp=led7_var.bShowBuff[i];
 	    #ifdef SUPPORT_FLASH_CHAR
 		if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
 		temp=0;
 	    #endif
 		for(j=0;j<LED_8GRIDS;j++)
 			if(temp&BIT(j))
 			led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
 	}


   #endif

}
#elif defined(SUPPORT_TM1618_MODE)

void LED_drive7(void)
{

	u8 i,j,temp,temp2,temp3;

    u16 temp1;

    led7_var.bShowBuff1[0]=0;
    led7_var.bShowBuff1[1]=0;
    led7_var.bShowBuff1[2]=0;
    led7_var.bShowBuff1[3]=0;
    led7_var.bShowBuff1[4]=0;
    led7_var.bShowBuff1[5]=0;
    led7_var.bShowBuff1[6]=0;
    led7_var.bShowBuff1[7]=0;
    led7_var.bShowBuff1[8]=0;
    led7_var.bShowBuff1[9]=0;
    led7_var.bShowBuff1[10]=0;
    led7_var.bShowBuff1[11]=0;
    led7_var.bShowBuff1[12]=0;  
#if LED_COM_MAX>=14
    led7_var.bShowBuff1[13]=0;
#endif
#if LED_COM_MAX>=15
    led7_var.bShowBuff1[14]=0;    
#endif




	
    if(compare_task_name("BtStackTask"))
     	blueToothLedProc();

#ifdef SUPPORT_MUTE_FLASH
	led7_mute_flash();
#endif





#if LED_REPLAY
    if(compare_task_name("MusicTask"))
    
    if(play_mode==REPEAT_ONE)
    {
	       LED_STATUS|=LED_REPLAY;
	   #ifdef SUPPORT_FLASH_ICON
	       LED_FLASH_ICON|=LED_REPLAY;
	   #endif
    }
    else
	{
		LED_STATUS&=~LED_REPLAY;
		  #ifdef SUPPORT_FLASH_ICON
				LED_FLASH_ICON&=~LED_REPLAY;
		  #endif
  	  }
#endif

 #if LED_REPEAT_ONE||LED_REPEAT_ALL
 
 		LED_STATUS&=~(LED_REPEAT_ONE|LED_REPEAT_ALL);
 		 #ifdef SUPPORT_FLASH_ICON
 		 	LED_FLASH_ICON&=~LED_REPEAT_ONE;
 		 #endif
 		 
 	if(compare_task_name("MusicTask"))
 	{
 		if(play_mode==REPEAT_ONE)
 		{
 		    LED_STATUS|=LED_REPEAT_ONE;
 		    #ifdef SUPPORT_FLASH_ICON
 			LED_FLASH_ICON|=LED_REPEAT_ONE;
 		    #endif
 		}
 		else if(play_mode==REPEAT_ALL)
 			LED_STATUS|=LED_REPEAT_ALL;
 	}
 #endif

		temp1=led7_var.wLedIcon;
	    #ifdef SUPPORT_FLASH_ICON
			if( g_var.sys_halfsec &&led7_var.wFlashIcon)
			temp1&=~(led7_var.wFlashIcon);
	    #endif

	

	#if LED_ICON_NUMS>=LED_8NUMS
	for(i=0;i<LED_ICON_NUMS;i++)
	{
		 if(temp1&BIT(i))
		 {
				 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];		 
		 }
		 if(i<LED_8NUMS)
		{
			temp=led7_var.bShowBuff[i];
			#ifdef SUPPORT_FLASH_CHAR
				if( g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
					temp=0;
			#endif
				for(j=0;j<LED_8GRIDS;j++)	 
					if(temp&BIT(j))
						led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j]; 
		}
	 }



	
    #else   



 	for(i=0;i<LED_8NUMS;i++)
 	{	
 		if(i<LED_ICON_NUMS)
 		{
 			 if(temp1&BIT(i))
 			 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
 		 }
 		 
 		temp=led7_var.bShowBuff[i];
 	    #ifdef SUPPORT_FLASH_CHAR
 		if( g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
 		temp=0;
 	    #endif
 		for(j=0;j<LED_8GRIDS;j++)	
 			{
	  			if(temp&BIT(j))
	 			led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];				
 			}

 	}


   #endif
}




#elif defined(SUPPORT_PT6312_MODE) // VFD_ID_HNV06SC44T
void LED_drive7(void)
{
    u8 i,j,temp;
    u16 temp1;
    u32 temp2;

    
    led7_var.bShowBuff1[0]=0;
    led7_var.bShowBuff1[1]=0;
    led7_var.bShowBuff1[2]=0;
    led7_var.bShowBuff1[3]=0;
    led7_var.bShowBuff1[4]=0;
    led7_var.bShowBuff1[5]=0;
    led7_var.bShowBuff1[6]=0;    
    led7_var.bShowBuff1[7]=0;    
    led7_var.bShowBuff1[8]=0;
    led7_var.bShowBuff1[10]=0;
   led7_var.bShowBuff1[11]=0;
   led7_var.bShowBuff1[12]=0;
#if LED_COM_MAX>=14
    led7_var.bShowBuff1[13]=0;
#endif
#if LED_COM_MAX>=15
    led7_var.bShowBuff1[14]=0;    
#endif

#if 1

    if(compare_task_name("BtStackTask"))
     blueToothLedProc();



	
    #if defined(VFD_ID_YDL2001_35)||defined(VFD_ID_406N)
	      #ifdef SOME_ICON_synchronization_WITH_HELLO
	      		 if(led7_var.bSynchronizationFlag)
	      #endif      
      		LED_CIRCLE_PROCESS();
    #endif

	



#if LED_REPEAT_ONE||LED_REPEAT_ALL
	LED_STATUS&=~(LED_REPEAT_ONE|LED_REPEAT_ALL);
#ifdef SUPPORT_FLASH_ICON
	LED_FLASH_ICON&=~LED_REPEAT_ONE;
#endif


if(compare_task_name("MusicTask"))
	{
		if(play_mode==REPEAT_ONE)
		{
    			LED_STATUS|=LED_REPEAT_ONE;
		     #ifdef SUPPORT_FLASH_ICON
		 		LED_FLASH_ICON|=LED_REPEAT_ONE;
		     #endif
   		 }
		else if(play_mode==REPEAT_ALL)
			LED_STATUS|=LED_REPEAT_ALL;
}
#endif


	
    #ifdef SUPPORT_MUTE_FLASH
   	led7_mute_flash();
    #endif




	 #ifdef support_led_rgy_running
		if(compare_task_name("IdleTask")||(workmode==RADIO_WORK_MODE))
			LED_STATUS &=~(LED_R|LED_Y|LED_R);
		else
			led7_led_rgy_running_show();
	 #endif


                   #if defined(SUPPORT_EQ_FREQUENCE)
                   #if !defined(SUPPORT_EQ_FREQUENCE_TIMER_SCAN)
				   #ifdef LED_ID_YDL2001_VFN_35
				   		if(workmode==RADIO_WORK_MODE)
				   			{
				   				led7_var.bEqIconBuf=0;
				   			}
						else
		                    			 LED_FREQUENCE_PROCESS();
				   #else
		                    	 LED_FREQUENCE_PROCESS();
				   #endif
                   #endif
                   #endif









#ifdef LED_ID_YDL2001_VFN_35
if((workmode==MUSIC_WORK_MODE)||(workmode==RADIO_WORK_MODE)||(workmode==LINE_WORK_MODE)||(workmode==BT_WORK_MODE))
{
	     led7_var.bShowBuff1[0x09]&=~0x10;    
	     led7_var.bShowBuff1[0x09]&=~0x20;    
	     led7_var.bShowBuff1[0x09]&=~0x08;    
	     led7_var.bShowBuff1[0x09]&=~0x02;
	     led7_var.bShowBuff1[0x09]&=~0x04;    
	     led7_var.bShowBuff1[0x09]&=~0x40;    
	     led7_var.bShowBuff1[0x09]&=~0x80;    
	     led7_var.bShowBuff1[0x09]&=~0x01;    
		 
}

#endif
	
	temp1=led7_var.wLedIcon;
    #ifdef SUPPORT_FLASH_ICON
	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
	temp1&=~(led7_var.wFlashIcon);
    #endif
#endif

	#if LED_ICON_NUMS>=LED_8NUMS
		for(i=0;i<LED_ICON_NUMS;i++)
			{
		 		if(temp1&BIT(i))
		 			led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];	 

				 #ifdef SUPPORT_EQ_FREQUENCE
				 	temp2=led7_var.bEqIconBuf;
				 		if(temp2&BIT(i))
				 			{
				 				led7_var.bShowBuff1[led_EQ[i]>>8]|=led_EQ[i];
				 			}
				 				
				 #endif



		 
		 		if(i<LED_8NUMS)
				{
					 temp=led7_var.bShowBuff[i];
			 	     #ifdef SUPPORT_FLASH_CHAR
			 		 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
			 		 	temp=0;
			 	     #endif
	     
		 			for(j=0;j<LED_8GRIDS;j++)	 
			 			if(temp&BIT(j))
			 				led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j]; 
		 		}
		 	}

	#elif LED_EQ_NUMS >=LED_ICON_NUMS
		 	for(i=0;i<LED_EQ_NUMS;i++)
		 	{

			 	 #ifdef SUPPORT_EQ_FREQUENCE	
		 		 	temp2=led7_var.bEqIconBuf;
		 		       if(temp2&BIT(i))
		 		          led7_var.bShowBuff1[led_EQ[i]>>8]|=led_EQ[i];
			 	 #endif

		 		if(i<LED_ICON_NUMS)
		 		{
				 	temp1=led7_var.wLedIcon;
				     #ifdef SUPPORT_FLASH_ICON
				 	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
				 	temp1&=~(led7_var.wFlashIcon);
				     #endif
			 		 if(temp1&BIT(i))
			 		 {
			 			 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
			 		 }
		 		}

		 		 if(i<LED_8NUMS)
				 {
			 		 temp=led7_var.bShowBuff[i];
			 	     #ifdef SUPPORT_FLASH_CHAR
			 		 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
			 			 temp=0;
			 	     #endif
			 		 for(j=0;j<LED_8GRIDS;j++)
			 			 if(temp&BIT(j))
			 			 led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
		 		 }


		 	 }


		
    #else   
		for(i=0;i<LED_8NUMS;i++)
			{	
				if(i<LED_ICON_NUMS)
					{
		 				if(temp1&BIT(i))
		 					led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
		 			}
		 
			temp=led7_var.bShowBuff[i];

		 	    #ifdef SUPPORT_FLASH_CHAR
		 			if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
		 				temp=0;
		 	    #endif
				for(j=0;j<LED_8GRIDS;j++)	
					if(temp&BIT(j))
						led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
			}	
   #endif
}


#elif defined LCD_4x9_MODE

#if defined LCD_ID_HL_21716HNT  // GW  LCD

void LED_drive7(void)
{
    u8 i,j,temp,temp2;
    u8 temp1;

    led7_var.bShowBuff1[0]=0;
    led7_var.bShowBuff1[1]=0;
    led7_var.bShowBuff1[2]=0;
    led7_var.bShowBuff1[3]=0;
    
    if(compare_task_name("BtStackTask")){
      if(led7_var.bBtIfConnect){
       LED_STATUS|=LED_BT;
       LED_FLASH_ICON&=~LED_BT;
      }
      else{
		  LED_STATUS|=LED_BT;
		  LED_FLASH_ICON|=LED_BT;
		  }
    }
    else
    {
		LED_STATUS&=~LED_BT;
		LED_FLASH_ICON&=~LED_BT;
    }
    
   if(compare_task_name("MusicTask"))
    {
    #if LED_REPLAY
		if(play_mode==REPEAT_ONE)
		{
		   LED_STATUS|=LED_REPLAY;
        #ifdef SUPPORT_FLASH_ICON
		   LED_FLASH_ICON|=LED_REPLAY;
        #endif
		}
		else{
			LED_STATUS&=~LED_REPLAY;
         #ifdef SUPPORT_FLASH_ICON
			LED_FLASH_ICON&=~LED_REPLAY;
      #endif
 		}
    #endif
#if 0//LED_FOLDER
		if(play_mode==REPEAT_FOLDER)
		{
		   LED_STATUS|=LED_FOLDER;
	#ifdef SUPPORT_FLASH_ICON
		   LED_FLASH_ICON|=LED_FOLDER;
	#endif
		}
		else{
			LED_STATUS&=~LED_FOLDER;
	 #ifdef SUPPORT_FLASH_ICON
			LED_FLASH_ICON&=~LED_FOLDER;
  #endif
 		}
#endif
    }
    else{
  #if LED_REPLAY
	  LED_STATUS|=LED_REPLAY;
  #ifdef SUPPORT_FLASH_ICON
	 LED_FLASH_ICON|=LED_REPLAY;
  #endif
  #endif
    
  #if LED_FOLDER
	LED_STATUS&=~LED_FOLDER;
	LED_FLASH_ICON&=~LED_FOLDER;
  #endif
    }
    #ifdef LED_SCREEN_SHOW_BAT_STATUS
	 led7_show_bat_status();
    #endif
    #ifdef SUPPORT_MUTE_FLASH
    led7_mute_flash();
    #endif
	temp1=led7_var.wLedIcon;
    #ifdef SUPPORT_FLASH_ICON
	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
	temp1&=~(led7_var.wFlashIcon);
    #endif
	

	if(temp1&LED_2POINT) led7_var.bShowBuff1[3]|=BIT(10);
	if(temp1&LED_SD) led7_var.bShowBuff1[0]|=BIT(1);
	if(temp1&LED_USB) led7_var.bShowBuff1[1]|=BIT(1);
	if(temp1&LED_DOT) led7_var.bShowBuff1[3]|=BIT(14);

	if(temp1&LED_BT) led7_var.bShowBuff1[3]|=BIT(1);
	if(temp1&LED_RECO) led7_var.bShowBuff1[3]|=BIT(4);
	if(temp1&LED_MUTE) led7_var.bShowBuff1[3]|=BIT(2);
	if(temp1&LED_FOLDER) led7_var.bShowBuff1[2]|=BIT(1);

	for(i=0;i<LED_8NUMS;i++){
	 temp=led7_var.bShowBuff[i];
     #ifdef SUPPORT_FLASH_CHAR
	 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
	 temp=0;
     #endif

	 for(j=0;j<LED_8GRIDS;j++)	 
		 if(temp&BIT(j)){
		    temp2=led_nums[i][j];
		    switch(temp2){
		      case 0x01:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(2);
			      break;
		      case 0x02:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(3);
			      break;
		      case 0x04:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(4);
			      break;
		      case 0x08:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(9);
			      break;
		      case 0x10:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(10);
			      break;
		      case 0x20:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(11);
			      break;
		      case 0x40:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(14);
			      break;
		      case 0x80:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(15);
			      break;
		    }
		 }
	 }
}

#elif defined LCD_ID_ZSLCD

void LED_drive7(void)
{
    u8 i,j,temp,temp2;
    u8 temp1;

    led7_var.bShowBuff1[0]=0;
    led7_var.bShowBuff1[1]=0;
    led7_var.bShowBuff1[2]=0;
    led7_var.bShowBuff1[3]=0;
    
    if(compare_task_name("BtStackTask")){
      if(led7_var.bBtIfConnect){
       LED_STATUS|=LED_BT;
       LED_FLASH_ICON&=~LED_BT;
      }
      else{
		  LED_STATUS|=LED_BT;
		  LED_FLASH_ICON|=LED_BT;
		  }
    }
    else{
		LED_STATUS&=~LED_BT;
		LED_FLASH_ICON&=~LED_BT;
    }
   if(compare_task_name("MusicTask"))
    {
    #if LED_REPLAY
		if(play_mode==REPEAT_ONE)
		{
		   LED_STATUS|=LED_REPLAY;
        #ifdef SUPPORT_FLASH_ICON
		   LED_FLASH_ICON|=LED_REPLAY;
        #endif
		}
		else{
			LED_STATUS&=~LED_REPLAY;
         #ifdef SUPPORT_FLASH_ICON
			LED_FLASH_ICON&=~LED_REPLAY;
      #endif
 		}
    #endif
#if 0//LED_FOLDER
		if(play_mode==REPEAT_FOLDER)
		{
		   LED_STATUS|=LED_FOLDER;
	#ifdef SUPPORT_FLASH_ICON
		   LED_FLASH_ICON|=LED_FOLDER;
	#endif
		}
		else{
			LED_STATUS&=~LED_FOLDER;
	 #ifdef SUPPORT_FLASH_ICON
			LED_FLASH_ICON&=~LED_FOLDER;
  #endif
 		}
#endif
    }
    else{
  #if LED_REPLAY
	  LED_STATUS|=LED_REPLAY;
  #ifdef SUPPORT_FLASH_ICON
	 LED_FLASH_ICON|=LED_REPLAY;
  #endif
  #endif
    
  #if LED_FOLDER
	LED_STATUS&=~LED_FOLDER;
	LED_FLASH_ICON&=~LED_FOLDER;
  #endif
    }
    #ifdef LED_SCREEN_SHOW_BAT_STATUS
	 led7_show_bat_status();
    #endif
    #ifdef SUPPORT_MUTE_FLASH
    led7_mute_flash();
    #endif
	temp1=led7_var.wLedIcon;
    #ifdef SUPPORT_FLASH_ICON
	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
	temp1&=~(led7_var.wFlashIcon);
    #endif


	if(temp1&LED_2POINT) led7_var.bShowBuff1[3]|=BIT(14);
	if(temp1&LED_SD) led7_var.bShowBuff1[2]|=BIT(14);
	if(temp1&LED_USB) led7_var.bShowBuff1[1]|=BIT(14);
	if(temp1&LED_DOT) led7_var.bShowBuff1[0]|=BIT(14);

	if(temp1&LED_BT) led7_var.bShowBuff1[3]|=BIT(15);
	if(temp1&LED_RECO) led7_var.bShowBuff1[2]|=BIT(15);
	if(temp1&LED_MUTE) led7_var.bShowBuff1[1]|=BIT(15);
	if(temp1&LED_FOLDER) led7_var.bShowBuff1[0]|=BIT(15);

	for(i=0;i<LED_8NUMS;i++){
	 temp=led7_var.bShowBuff[i];
     #ifdef SUPPORT_FLASH_CHAR
	 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
	 temp=0;
     #endif
	 // 1100 1111 1101 0000

	 for(j=0;j<LED_8GRIDS;j++)	 
		 if(temp&BIT(j)){
		    temp2=led_nums[i][j];
		    switch(temp2){
		      case 0x01:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(1);
			      break;
		      case 0x02:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(2);
			      break;
		      case 0x04:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(3);
			      break;
		      case 0x08:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(4);
			      break;
		      case 0x10:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(9);
			      break;
		      case 0x20:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(10);
			      break;
		      case 0x40:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(11);
			      break;
		      case 0x80:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(12);
			      break;
		    }
		 }
	 }
}


#elif defined LCD_ID_JXH_S6002A
void LED_drive7(void)
{
    u8 i,j,temp,temp2;
    u8 temp1;

    led7_var.bShowBuff1[0]=0;
    led7_var.bShowBuff1[1]=0;
    led7_var.bShowBuff1[2]=0;
    led7_var.bShowBuff1[3]=0;
    
    if(compare_task_name("BtStackTask")){
      if(led7_var.bBtIfConnect){
       LED_STATUS|=LED_BT;
       LED_FLASH_ICON&=~LED_BT;
      }
      else{
		  LED_STATUS|=LED_BT;
		  LED_FLASH_ICON|=LED_BT;
		  }
    }
    else{
		LED_STATUS&=~LED_BT;
		LED_FLASH_ICON&=~LED_BT;
    }
   if(compare_task_name("MusicTask"))
    {
    #if LED_REPLAY
		if(play_mode==REPEAT_ONE)
		{
		   LED_STATUS|=LED_REPLAY;
        #ifdef SUPPORT_FLASH_ICON
		   LED_FLASH_ICON|=LED_REPLAY;
        #endif
		}
		else{
			LED_STATUS&=~LED_REPLAY;
         #ifdef SUPPORT_FLASH_ICON
			LED_FLASH_ICON&=~LED_REPLAY;
      #endif
 		}
    #endif
#if 0//LED_FOLDER
		if(play_mode==REPEAT_FOLDER)
		{
		   LED_STATUS|=LED_FOLDER;
	#ifdef SUPPORT_FLASH_ICON
		   LED_FLASH_ICON|=LED_FOLDER;
	#endif
		}
		else{
			LED_STATUS&=~LED_FOLDER;
	 #ifdef SUPPORT_FLASH_ICON
			LED_FLASH_ICON&=~LED_FOLDER;
  #endif
 		}
#endif
    }
    else
 {
  #if LED_REPLAY
	  LED_STATUS|=LED_REPLAY;
  #ifdef SUPPORT_FLASH_ICON
	 LED_FLASH_ICON|=LED_REPLAY;
  #endif
  #endif
    
  #if LED_FOLDER
	LED_STATUS&=~LED_FOLDER;
	LED_FLASH_ICON&=~LED_FOLDER;
  #endif
    }
    #ifdef LED_SCREEN_SHOW_BAT_STATUS
	 led7_show_bat_status();
    #endif
    #ifdef SUPPORT_MUTE_FLASH
    led7_mute_flash();
    #endif

	
	temp1=led7_var.wLedIcon;
    #ifdef SUPPORT_FLASH_ICON
	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
	temp1&=~(led7_var.wFlashIcon);
    #endif


	if(temp1&LED_2POINT) led7_var.bShowBuff1[3]|=BIT(10);
	if(temp1&LED_SD) led7_var.bShowBuff1[0]|=BIT(1);
	if(temp1&LED_USB) led7_var.bShowBuff1[1]|=BIT(1);
	if(temp1&LED_DOT) led7_var.bShowBuff1[3]|=BIT(14);

	if(temp1&LED_BT) led7_var.bShowBuff1[3]|=BIT(1);
	if(temp1&LED_RECO) led7_var.bShowBuff1[3]|=BIT(3);
	if(temp1&LED_MUTE) led7_var.bShowBuff1[3]|=BIT(2);
	if(temp1&LED_FOLDER) led7_var.bShowBuff1[2]|=BIT(1);

	for(i=0;i<LED_8NUMS;i++){
	 temp=led7_var.bShowBuff[i];
     #ifdef SUPPORT_FLASH_CHAR
	 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
	 temp=0;
     #endif

	 for(j=0;j<LED_8GRIDS;j++)	 
		 if(temp&BIT(j)){
		    temp2=led_nums[i][j];
		    switch(temp2){
		      case 0x01:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(2);
			      break;
		      case 0x02:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(3);
			      break;
		      case 0x04:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(4);
			      break;
		      case 0x08:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(9);
			      break;
		      case 0x10:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(10);
			      break;
		      case 0x20:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(11);
			      break;
		      case 0x40:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(14);
			      break;
		      case 0x80:
				  led7_var.bShowBuff1[led_nums[i][j]>>8]|=BIT(15);
			      break;
		    }
		 }
	 }
}

#endif

#else  //#if defined(SUPPORT_TM1628_MODE)


void LED_drive7(void)
{
    u8 i,j,temp;
    u16 temp1;
#if LED_EQ_NUMS >=LED_ICON_NUMS
    u16 temp2;
#endif

    led7_var.bShowBuff1[0]=0;
    led7_var.bShowBuff1[1]=0;
    led7_var.bShowBuff1[2]=0;
    led7_var.bShowBuff1[3]=0;
    led7_var.bShowBuff1[4]=0;
    led7_var.bShowBuff1[5]=0;
    led7_var.bShowBuff1[6]=0;


#ifdef SUPPORT_RECPLAY_STATE
#ifdef LED_REPLAY

//       if(compare_task_name("MusicTask"))
	if(workmode==MUSIC_WORK_MODE)
   	{
	   if(bIfRecordFolder)
        	{
			LED_STATUS|=LED_REPLAY;
		//	LED_FLASH_ICON|=LED_REPLAY;
        	}
	   else
        	{
			LED_STATUS&=~LED_REPLAY;
		//	LED_FLASH_ICON&=~LED_REPLAY;
        	}


   	  }

#endif
#endif


#ifdef SUPPORT_BT_LED_PRORAM
    	 blueToothLedProc();
#endif

#if defined(SUPPORT_EQ_FREQUENCE)
#if !defined(SUPPORT_EQ_FREQUENCE_TIMER_SCAN)
	 LED_FREQUENCE_PROCESS();
#endif
#endif


    #ifdef LED_SCREEN_SHOW_BAT_STATUS
	 led7_show_bat_status();
    #endif

    #ifdef SUPPORT_MUTE_FLASH
	    led7_mute_flash();
    #endif

#ifdef SUPPORT_LED_LOW_SHOW_LDO
	    led7_low_power_show_flah();
#endif	
    #ifdef SUPPORT_MIC_ONOFF_SHOW
    	led7_onoff_show();
    #endif
    #ifdef SUPPORT_LOW_POWER_USE_LED_SHOW
	    led7_low_power_show();
    #endif

#ifdef SUPPORT_LED7_OFF_BAT_ICON
	 LED_STATUS&=~LED_BT;
#endif

	#if LED_EQ_NUMS >=LED_ICON_NUMS

		 	for(i=0;i<LED_EQ_NUMS;i++)
		 	{

			 	 #ifdef SUPPORT_EQ_FREQUENCE	 // LED_ID_27N60_8
		 		 	temp2=led7_var.bEqIconBuf;
		 		       if(temp2&BIT(i))
		 		          led7_var.bShowBuff1[led_EQ[i]>>8]|=led_EQ[i];
			 	 #endif

		 		if(i<LED_ICON_NUMS)
		 		{
				 	temp1=led7_var.wLedIcon;
				     #ifdef SUPPORT_FLASH_ICON
				 	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
				 	temp1&=~(led7_var.wFlashIcon);
				     #endif
			 		 if(temp1&BIT(i))
			 		 {
			 			 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
			 		 }
		 		}

		 		 if(i<LED_8NUMS)
				 {
			 		 temp=led7_var.bShowBuff[i];
			 	     #ifdef SUPPORT_FLASH_CHAR
			 		 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
			 			 temp=0;
			 	     #endif
			 		 for(j=0;j<LED_8GRIDS;j++)
			 			 if(temp&BIT(j))
			 			 led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
		 		 }


		 	 }
	#elif  LED_ICON_NUMS >=LED_8NUMS
	
		  	for(i=0;i<LED_ICON_NUMS;i++)
		  	{


		 		 temp1=led7_var.wLedIcon;

		 	     #ifdef SUPPORT_FLASH_ICON
		 	 	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
		 	 		temp1&=~(led7_var.wFlashIcon);
		 	     #endif


		 	#if defined(SUPPORT_DOUBLE_LED7_PANEL)

			 	#if defined(LED_ID_JW_24017_1B_JW4018D7_1B)


			 		if(bLed7SelFlag)
			 		{

					//	LED_STATUS&=~(LED_PLAY|LED_PAUSE|LED_USB|LED_SD|LED_FM|LED_MP3);
			 			 if(temp1&BIT(i))
			 				 led7_var.bShowBuff1[led_icon_value1[i]>>8]|=led_icon_value1[i];
			 		}
			 		else
			 		{
			 			 if(temp1&BIT(i))
			 				 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];
			 		}

			  	#endif

		 	#else

		 		 if(temp1&BIT(i))
			 		 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];

		  	#endif

		 		 if(i<LED_8NUMS)
		 		 {
		 			 temp=led7_var.bShowBuff[i];
		 		     #ifdef SUPPORT_FLASH_CHAR
		 			 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
		 			 temp=0;
		 		     #endif
		 			 for(j=0;j<LED_8GRIDS;j++)
		 				 if(temp&BIT(j))
		 				 led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
		 		 }
		  	}
			
	#else

		  	for(i=0;i<LED_8NUMS;i++)
		  	{

		 		 if(i<LED_ICON_NUMS)
		 		 {
			 		 temp1=led7_var.wLedIcon;

			 	     #ifdef SUPPORT_FLASH_ICON
			 	 	if(g_var.sys_halfsec &&led7_var.wFlashIcon)
			 	 		temp1&=~(led7_var.wFlashIcon);
			 	     #endif

			 		 if(temp1&BIT(i))
				 		 led7_var.bShowBuff1[led_icon_value[i]>>8]|=led_icon_value[i];				 
	 		 	}

		 		 {
		 			 temp=led7_var.bShowBuff[i];
		 		     #ifdef SUPPORT_FLASH_CHAR
		 			 if(g_var.sys_halfsec &&(led7_var.bFlashChar & BIT(i)))
		 			 temp=0;
		 		     #endif
		 			 for(j=0;j<LED_8GRIDS;j++)
		 				 if(temp&BIT(j))
		 				 led7_var.bShowBuff1[led_8grid_value[i][j]>>8]|=led_8grid_value[i][j];
		 		 }
		  	}

	 #endif

}

#endif


/*----------------------------------------------------------------------------*/
/**@brief   LED«Â∆¡∫Ø ˝
   @param   x£∫œ‘ æ∫·◊¯±Í
   @return  void
   @author  Change.tsai
   @note    void led7_clear(void)
*/
/*----------------------------------------------------------------------------*/
void led7_clear(void)
{
 #if defined(LED_7PIN_MODE)
    LED7_IO_INIT();
 #endif
}

/*----------------------------------------------------------------------------*/
/**@brief   LED…®√Ë∫Ø ˝
   @param   void
   @return  void
   @author  Change.tsai
   @note    void led7_scan(void *param)
*/
/*----------------------------------------------------------------------------*/
void led7_scan(void *param)
{

#if defined(SUPPORT_TM1628_MODE)

#ifdef TEST_PANEL_LED

	 	static u8 flash_cnt=0,cnt=0;
	 	u8 i,j,seg;
	 	cnt++;
	 	HT1628_IO_INIT();

		 #if 0 //def TEST_SHOW_ALL
		 //  HT1628_IO_INIT();
		  // HT1628_CLK(1);
		  // HT1628_DATA(1);
		  // HT1628_STB(1);
		    #if 1

		 	WR_HT1628_CMD(TM1628_MODE);
		 	for(i=0;i<LED_COM_MAX;i++){
		 		HT1628_STB(0) ;
		 		WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù	add-C0	C2
		 		WR_HT1628_Byte(0xff);
		 		HT1628_STB(1) ;
		 	}
		 	 WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
		 #endif
		 #else
		 	WR_HT1628_CMD(TM1628_MODE);//√è√î√ä¬æ√Ñ¬£√ä¬Ω  7√é¬ª 10¬∂√é
		 	HT1628_STB(0) ;//√Ü¬¨√ë¬°¬£¬¨0√ì√ê√ê¬ß
		 	if(cnt>LED_COM_MAX) cnt=0;
		 	if(bledComValue==cnt)
		 	{   //flash_cnt++;
		 		WR_HT1628_Byte(0xc0+cnt);//√è√î√ä¬æ√ä√Ω¬æ√ù¬µ√ò√ñ¬∑
		 //		if(flash_cnt<10){
		 //		WR_HT1628_Byte(0xff);//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 //		}
		 //		else{
		 //		if(flash_cnt==20)flash_cnt=0;
		 //		WR_HT1628_Byte(0xff&(~BIT(bledGridValue)));//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 //	  	}
		 		WR_HT1628_Byte(BIT(bledGridValue));//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 	}
		 	else
		 	{
		 		WR_HT1628_Byte(0xc0+cnt);//√è√î√ä¬æ√ä√Ω¬æ√ù¬µ√ò√ñ¬∑
		 		WR_HT1628_Byte(0);//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 	}
		 	HT1628_STB(1) ;//√Ü¬¨√ë¬°¬£¬¨1√ä√ç¬∑√Ö
		 	delayus();
		 	delayus();
		 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
		 #endif
#else

static u8	cnt=0;//,
u8 i;

#if defined(LED_ID_JW6521B_1A)||defined(LED_ID_1600B_VFD)||defined(LED_ID_8SD78YRG)||defined(LED_ID_DB_51)

	 switch(cnt)
	 {
		 case 0:

			 LED_drive7();

		 break;

		 case 1:
			 HT1628_IO_INIT();
			 WR_HT1628_CMD(TM1628_MODE);
			 WR_HT1628_CMD(0x44); //auto increment
			   for(i=0;i<3;i++)
			   {
				HT1628_STB(0) ;
				WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
				WR_HT1628_Byte(led7_var.bShowBuff1[i]);
				HT1628_STB(1) ;
			  }
		 break;

		 case 2:
		 	  for(i=3;i<6;i++)
		 		  {
		 			HT1628_STB(0) ;
		 			WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
				WR_HT1628_Byte(led7_var.bShowBuff1[i]);
		 		  HT1628_STB(1) ;
		 		  }
		 break;

		 case 3:
		 	  for(i=6;i<9;i++)
		 		  {
		 			HT1628_STB(0) ;
		 			WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
				WR_HT1628_Byte(led7_var.bShowBuff1[i]);
		 		  HT1628_STB(1) ;
		 		  }
		 break;


			 case 4:
			 	  for(i=9;i<12;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
				WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 break;

			 case 5:
			 	  for(i=12;i<15;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
					WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
			 break;

			 case 6:
			 	  for(i=15;i<LED_COM_MAX;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
					WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
			 break;



	 }

	cnt++;

	    if(cnt>6) cnt=0;


#else

 //       printf("------ led7_scan cnt = %d\n",cnt);

	 switch(cnt)
	 {
		 case 0:

			 LED_drive7();

		 break;

		 case 1:
			 HT1628_IO_INIT();
			 WR_HT1628_CMD(TM1628_MODE);
			 WR_HT1628_CMD(0x44); //auto increment
			   for(i=0;i<3;i++)
			   {
				HT1628_STB(0) ;
				WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
				WR_HT1628_Byte(led7_var.bShowBuff1[i]);
				HT1628_STB(1) ;
			  }
		 break;

		 case 2:
		 	  for(i=3;i<6;i++)
		 		  {
		 			HT1628_STB(0) ;
		 			WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
		 		  WR_HT1628_Byte(led7_var.bShowBuff1[i]);
		 		  HT1628_STB(1) ;
		 		  }
		 break;

		 case 3:
		 	  for(i=6;i<9;i++)
		 		  {
		 			HT1628_STB(0) ;
		 			WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
		 		  WR_HT1628_Byte(led7_var.bShowBuff1[i]);
		 		  HT1628_STB(1) ;
		 		  }
		 break;

		 #if LED_COM_MAX==13

			 case 4:
			 	  for(i=9;i<LED_COM_MAX;i++)
			 		  {
			 			HT1628_STB(0) ;
			 			WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
			 		  WR_HT1628_Byte(led7_var.bShowBuff1[i]);
			 		  HT1628_STB(1) ;
			 		  }
			 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
			 break;

			 #ifdef SUPPORT_TM1628_KEY_READ
				 case 5:
				   HT1628_READ_KEY_PROCESS();
				   break;
			 #endif

		#elif LED_COM_MAX==16

			 case 4:
			 	  for(i=9;i<12;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
					WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 break;

			 case 5:
			 	  for(i=12;i<15;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
					WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
			 break;

			 case 6:
			 	  for(i=15;i<LED_COM_MAX;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
					WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
			 break;


		 #else

			 case 4:
			 	  for(i=9;i<12;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
					WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 break;

			 case 5:
			 	  for(i=12;i<LED_COM_MAX;i++)
		 		  {
					HT1628_STB(0) ;
					WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù  add-C0  C2
					WR_HT1628_Byte(led7_var.bShowBuff1[i]);
					HT1628_STB(1) ;
		 		  }
			 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
			 break;

			 #ifdef SUPPORT_TM1628_KEY_READ
				 case 6:
				   HT1628_READ_KEY_PROCESS();
			   break;
			 #endif

		 #endif

	 }

	cnt++;

	 #if LED_COM_MAX==13
	   #ifdef SUPPORT_TM1628_KEY_READ
	    if(cnt>5) cnt=0;
	   #else
	    if(cnt>4) cnt=0;
	   #endif
	  #elif LED_COM_MAX==16
	    if(cnt>6) cnt=0;
	 #else
	    #ifdef SUPPORT_TM1628_KEY_READ
	    if(cnt>6) cnt=0;
	    #else
	    if(cnt>5) cnt=0;
	    #endif
	 #endif

#endif

#endif
#elif defined(SUPPORT_TM1618_MODE)

#ifdef TEST_PANEL_LED
			static u8 flash_cnt=0,cnt=0;									 
			u8 i,j,seg; 	 
			cnt++;	
			HT1618_IO_INIT();
		 #ifdef TEST_SHOW_ALL
			   HT1618_IO_INIT();
			   HT1618_CLK(1);
			   HT1618_DATA(1);
			   HT1618_STB(1);
		    #if 1
				WR_TM1618_CMD(TM1618_MODE);
				for(i=0;i<LED_COM_MAX;i++)
				{
					HT1618_STB(0) ;
					WR_TM1618_Byte(0xc0+i);
					WR_TM1618_Byte(0xff);
					HT1618_STB(1) ;
				}
				 WR_TM1618_CMD(0x8f);
		#endif
				 
		 #else	
				WR_TM1618_CMD(TM1618_MODE);
				HT1618_STB(0) ;
				if(cnt>14) 
					cnt=0;
				if(bledComValue==cnt)
				{	//flash_cnt++;
					WR_TM1618_Byte(0xc0+cnt);									 
					WR_TM1618_Byte(BIT(bledGridValue));
				}
				else
				{
					WR_TM1618_Byte(0xc0+cnt);
					WR_TM1618_Byte(0);
				}
				HT1618_STB(1) ;
				delayus();
				delayus();
				WR_TM1618_CMD(0x8f);
#endif
		 
#else
	static u8	cnt=0;//,
	u8 i;
			
			switch(cnt)
			{
			case 0:
				LED_drive7();
			break;				
			case 1:
				HT1618_IO_INIT();
				WR_TM1618_CMD(TM1618_MODE); 	
				WR_TM1618_CMD(HT1618_CMD_SPEC_ADDR);
				for(i=0;i<LED_COM_MAX;i++)
				{
					HT1618_STB(0) ;
					WR_TM1618_Byte(0xc0+i);
					WR_TM1618_Byte(led7_var.bShowBuff1[i]);
					HT1618_STB(1) ;
				}
				WR_TM1618_CMD(0x8f);
			break;
			}
			cnt++;
			if(cnt>1) cnt=0;
#endif


#elif defined(SUPPORT_PT6312_MODE) // VFD_ID_HNV06SC44T

	 #ifdef TEST_PANEL_LED
	 	static u8 flash_cnt=0,cnt=0;                                     
	 	u8 i,j,seg;	 	 
	 	cnt++;	
	 	HT1628_IO_INIT();
	 	 #ifdef TEST_SHOW_ALL
	 	 //  HT1628_IO_INIT();
	 	  // HT1628_CLK(1);
	 	  // HT1628_DATA(1);
	 	  // HT1628_STB(1);
	 	  
	 	    #if 1
	 	 	WR_HT1628_CMD(0x02);										   
	 	 	for(i=0;i<LED_COM_MAX;i++){
	 	 		HT1628_STB(0) ;
	 	 		WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù	add-C0	C2
	 	 		WR_HT1628_Byte(0xff);
	 	 		HT1628_STB(1) ;
	 	 	}
	 	 	 WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
	 	 #endif
	 	 #else
	 	 #if 1
		 	WR_HT1628_CMD(0x01);//√è√î√ä¬æ√Ñ¬£√ä¬Ω  7√é¬ª 10¬∂√é
		 	HT1628_STB(0) ;//√Ü¬¨√ë¬°¬£¬¨0√ì√ê√ê¬ß
		 	if(cnt>24) cnt=0;
		 	if(bledComValue==cnt)
		 	{   //flash_cnt++;
		 		WR_HT1628_Byte(0xc0+cnt);//√è√î√ä¬æ√ä√Ω¬æ√ù¬µ√ò√ñ¬∑
		 //		if(flash_cnt<10){
		 //		WR_HT1628_Byte(0xff);//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 //		}
		 //		else{
		 //		if(flash_cnt==20)flash_cnt=0;
		 //		WR_HT1628_Byte(0xff&(~BIT(bledGridValue)));//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 //	  	}											 
		 		WR_HT1628_Byte(BIT(bledGridValue));//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 	}
		 	else
		 	{
		 		WR_HT1628_Byte(0xc0+cnt);//√è√î√ä¬æ√ä√Ω¬æ√ù¬µ√ò√ñ¬∑
		 		WR_HT1628_Byte(0);//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
		 	}
		 	HT1628_STB(1) ;//√Ü¬¨√ë¬°¬£¬¨1√ä√ç¬∑√Ö
		 	delayus();
		 	delayus();
		 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
		 	

	 	 #else
	 	 	WR_HT1628_CMD(0x01);//√è√î√ä¬æ√Ñ¬£√ä¬Ω  7√é¬ª 10¬∂√é
	 	 	HT1628_STB(0) ;//√Ü¬¨√ë¬°¬£¬¨0√ì√ê√ê¬ß
	 	 	if(cnt>=LED_COM_MAX) cnt=0;
	 	 	if(bledComValue==cnt)
	 	 	{   flash_cnt++;
	 	 		WR_HT1628_Byte(0xc0+cnt);//√è√î√ä¬æ√ä√Ω¬æ√ù¬µ√ò√ñ¬∑
	 	 		if(flash_cnt<10){
	 	 		WR_HT1628_Byte(0xff);//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
	 	 		}
	 	 		else{
	 	 		if(flash_cnt==20)flash_cnt=0;
	 	 		WR_HT1628_Byte(0xff&(~BIT(bledGridValue)));//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
	 	 	  	}											 
	 	 	}
	 	 	else
	 	 	{
	 	 		WR_HT1628_Byte(0xc0+cnt);//√è√î√ä¬æ√ä√Ω¬æ√ù¬µ√ò√ñ¬∑
	 	 		WR_HT1628_Byte(0);//√è√î√ä¬æ√ä√Ω¬æ√ù	  add-0
	 	 	}
	 	 	HT1628_STB(1) ;//√Ü¬¨√ë¬°¬£¬¨1√ä√ç¬∑√Ö
	 	 	delayus();
	 	 	delayus();
	 	 	WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
	 	 #endif
	 	 #endif
	 #else
	 static u8	cnt=0;//,
	 u8 i;



	 
	 switch(cnt)
	 	{
	 	case 0:
			
	 			LED_drive7();
	 	break;		
		
	 	case 1:
	 			HT1628_IO_INIT();
	 			WR_HT1628_CMD(0x02);											
	 			for(i=0;i<11;i++)
		 	 	{
		 	 		HT1628_STB(0) ;
		 	 		WR_HT1628_Byte(0xc0+i);//√è√î√ä¬æ√ä√Ω¬æ√ù	 add-C0  C2
		 		 	WR_HT1628_Byte(led7_var.bShowBuff1[i]);
		 	 		HT1628_STB(1) ;
		 	 	}
	 				WR_HT1628_CMD(0x8f);//√ã√ç√Å√Å¬∂√à√ñ¬∏√Å√Æ
	 	break;
	 	}
	 cnt++;
	 	if(cnt>1) 
			cnt=0;
	 #endif




#elif defined(LCD_4x9_MODE)

#if 0
/*num0*/ 	{0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040},
/*num1*/ 	{0x0101,0x0102,0x0104,0x0108,0x0110,0x0120,0x0140},
/*num2*/ 	{0x0201,0x0202,0x0204,0x0208,0x0210,0x0220,0x0240},
/*num3*/ 	{0x0301,0x0302,0x0304,0x0308,0x0310,0x0320,0x0340},
#endif

/*					0003			0009			0011			0015
sd		fm		0002	0103	0004	0109	0010	0111	0014	0115
00-01	0314		0102			0104			0110			0114
				0202	0203	0204	0209	0210	2011	0214	0215
usb		bt			0303			0309			0311			0315
0101	0301

foler		mute	:		REC
0201	0302	0310	0304
	
//  15 14 11 10 9  4 3 2 1 

sd		88:8.8		fm
usb
	folder  mute rec 	bt
(.=fm)

*/

#if 1


	LED_drive7();
#else
	led7_var.bShowBuff1[0]=0x0002;
	led7_var.bShowBuff1[1]=0;
	led7_var.bShowBuff1[2]=0;
	led7_var.bShowBuff1[3]=0;// 0xce1e		
#endif	
	COM0_SEG(led7_var.bShowBuff1[0]);
	COM1_SEG(led7_var.bShowBuff1[1]);
	COM2_SEG(led7_var.bShowBuff1[2]);
	COM3_SEG(led7_var.bShowBuff1[3]);
	#if defined(SUPPORT_LCD_5COM_8SEG_MODE)
	COM4_SEG(led7_var.bShowBuff1[4]);
	#endif

#else


    static u8 cnt;
    u8 seg;

    LED_drive7();

    seg = led7_var.bShowBuff1[cnt];

    led7_clear();


    switch(cnt)
    {
    case 0:
        led_7_set_com0();
        break;
    case 1:
        led_7_set_com1();
        break;
    case 2:
        led_7_set_com2();
        break;
    case 3:
        led_7_set_com3();
        break;
    case 4:
        led_7_set_com4();
        break;
    case 5:
        led_7_set_com5();
        break;

    case 6:
        led_7_set_com6();
        break;

    default :
        break;
    }

    if(seg & BIT(0))
    {
        led_7_clr_seg0();
    }
    if(seg & BIT(1))
    {
        led_7_clr_seg1();
    }
    if(seg & BIT(2))
    {
        led_7_clr_seg2();
    }
    if(seg & BIT(3))
    {
        led_7_clr_seg3();
    }
    if(seg & BIT(4))
    {
        led_7_clr_seg4();
    }
    if(seg & BIT(5))
    {
        led_7_clr_seg5();
    }

    if(seg & BIT(6))
    {
        led_7_clr_seg6();
    }




    cnt = (cnt >= 6) ? 0 : cnt+1;

#endif

}


#endif






