


 #define IR_SYS_CODE		0x7f80


/*      
power mode   mute
 12      1a       1e

 pp     pre         next   
01  	     02  	03

eq      voldec  volinc   
04 	   05 	              06

0          rep      usb-sd/scan    
07       08           	09

1        2		3
0a 	  1b		 1f

4	  5		6
0c	 0d 		0e

7	  8		9
00	 0f 		19

*/

#ifdef support_double_ir
const u8 IRTabFF00_2[] = 	   /*user code is 0xFF00*/
#else 
const u8 IRTabFF00[] = 	   /*user code is 0xFF00*/
#endif 
{
/*0x00*/IRC_NUM7,//0
/*0x01*/IRC_ONLY_PLAY_PAUSE   ,// 1
/*0x02*/IRC_PREV ,//02
/*0x03*/IRC_NEXT,//03
/*0x04*/IRC_EQ  ,//04
/*0x05*/IRC_VOL_DN ,//05
/*0x06*/IRC_VOL_UP,//06
/*0x07*/IRC_NUM0,//07
/*0x08*/IRC_REPEAT  ,//08
/*0x09*/IRC_USB_SD_FM_SCAN ,//09
/*0x0a*/IRC_NUM1,//10
/*0x0b*/ 0XFF,//11
/*0x0c*/IRC_NUM4,//12
/*0x0d*/IRC_NUM5,//13
/*0x0e*/ IRC_NUM6,//14
/*0x0f*/IRC_NUM8,//15
/*0x10*/0XFF,//16
/*0x11*/0XFF,//17
/*0x12*/IRC_STANBY,//18
/*0x13*/0XFF,//19
/*0x14*/0XFF,//20
/*0x15*/0XFF,//21
/*0x16*/0XFF,//22
/*0x17*/ 0XFF,//23
/*0x18*/ 0XFF,//24
/*0x19*/IRC_NUM9,//25
/*0x1a*/ IRC_MODE,//26
/*0x1b*/IRC_NUM2,//27
/*0x1c*/0XFF,//28
/*0x1d*/0XFF,//29
/*0x1e*/IRC_MUTE,//30
/*0x1f*/IRC_NUM3,//31
};









