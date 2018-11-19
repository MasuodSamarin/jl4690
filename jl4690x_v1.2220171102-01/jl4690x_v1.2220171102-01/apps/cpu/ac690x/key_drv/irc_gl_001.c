/*******************************************************************************************
File Name:  IRFF00.h

Version:    1.00

Discription: ºìÍâ°´¼ü±í 0xFF00

Author:     Caibingquan

Email:      change.tsai@gmail.com

Date:       2012.06.04

Copyright:(c) 2012 , All Rights Reserved.
*******************************************************************************************/



/*    sys 2261  

power pp   MUTE
 16      15    14

0e     0d     0c
0      100+  200+

1        2		3
0a	  09		 08

4	  5		6
06	 05 		04

7	  8		9
01	   02 	00

stop   prev  10
 12     11    eq 

 vol-  pp    vol+
 1a    19     18
       
rep     prev    usb/sd
1e       1d     c  

*/

#ifdef support_double_ir
#define IR_SYS_CODE2			2261
const u8 IRTabFF00_2[] = 	   /*user code is 0xFF00*/
#else 
#define IR_SYS_CODE			2261
const u8 IRTabFF00[] = 	   /*user code is 0xFF00*/
#endif 
{
/*0x00*/IRC_NUM9,  //0
/*0x01*/IRC_NUM7,// 1
/*0x02*/IRC_NUM8,//02
/*0x03*/IRC_MODE,//03
/*0x04*/0XFF,//04
/*0x05*/IRC_NUM5,//05
/*0x06*/IRC_NUM4,//06
/*0x07*/IRC_EQ,//07
/*0x08*/  IRC_NUM3,//08
/*0x09*/  IRC_NUM2,//09
/*0x0a*/  IRC_NUM1,//10
/*0x0b*/ IRC_NUM0,//11
/*0x0c*/0xff,//12
/*0x0d*/IRC_ADD100,//13
/*0x0e*/ IRC_NUM0,//14
/*0x0f*/0XFF,//15
/*0x10*/IRC_EQ,//16
/*0x11*/IRC_NEXT,//17
/*0x12*/IRC_STOP,//18
/*0x13*/0XFF,//19
/*0x14*/IRC_MUTE,//20
/*0x15*/IRC_MODE,//21
/*0x16*/IRC_STANBY,//22
/*0x17*/ 0XFF,//23
/*0x18*/ IRC_VOL_DN,//24
/*0x19*/IRC_PLAY_PAUSE,//25
/*0x1a*/ IRC_VOL_DN,//26
/*0x1b*/0XFF,//27
/*0x1c*/IRC_USB_SD,//28
/*0x1d*/IRC_PREV,//29
/*0x1e*/IRC_REPEAT,//30
/*0x1f*/0XFF,//31

};


