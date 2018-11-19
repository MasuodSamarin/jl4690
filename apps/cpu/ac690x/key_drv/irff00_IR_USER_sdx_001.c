


#define IR_SYS_CODE			0x7f80

#define       IRC_NUM0                             0  /*09*/ 
#define       IRC_NUM1                             1  /*12*/
#define       IRC_NUM2                             2  /*13*/
#define       IRC_NUM3                             3  /*14*/
#define       IRC_NUM4                             4  /*15*/
#define       IRC_NUM5                             5  /*16*/ 
#define       IRC_NUM6                             6  /*17*/ 
#define       IRC_NUM7                             7  /*18*/ 
#define       IRC_NUM8                             8 /*19*/
#define       IRC_NUM9                             9  /*20*/
#define       IRC_STANBY                         10 /*20*/
#define       IRC_MODE                             11      /*01*/
#define       IRC_MUTE                             12 /*20*/
#define       IRC_PLAY_PAUSE                  13     /*03*/ 
#define       IRC_PREV                              14     /*04*/
#define       IRC_NEXT                              15   /*05*/  
#define       IRC_VOL_UP                          16/*08*/ 
#define       IRC_VOL_DN                          17       /*07*/ 
#define       IRC_USB_SD                         18
#define       IRC_EQ                                19   /*06*/
#define       IRC_REPEAT                     20/*10*/ 
#define       IRC_AUX_KEY                  21/*10*/ 
#define       IRC_FM_KEY                     22/*10*/ 
#define       IRC_FM_SCAN_KEY               23/*10*/ 


/*      
MUTE            STANBY
1E                 12

1        2		3
0A 	  1B		 1F

4	  5		6
0C	 0D 		0E

7	  8		9
00	 0F 		19

SCAN   0    MODE 
/09     07      1A

REPEAT  USB/SD     AUX  FM  
 08 	      17 	        16  15 


PREV/ch-     PP /tun+     VOL+ 
02                 01             06
 
NEXT/ch+   EQ /tun-   VOL- 
03                04               05

*/


const u8 IRTabFF00[] = 	   /*user code is 0xFF00*/
{
/*0x00*/IRC_NUM7,//0
/*0x01*/IRC_PLAY_PAUSE,// 1
/*0x02*/IRC_PREV,//02
/*0x03*/IRC_NEXT,//03
/*0x04*/IRC_EQ,//04
/*0x05*/IRC_VOL_DN,//05
/*0x06*/IRC_VOL_UP,//06
/*0x07*/IRC_NUM0,//07
/*0x08*/  IRC_REPEAT,//08
/*0x09*/IRC_FM_SCAN_KEY,//09
/*0x0a*/  IRC_NUM1,//10
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
/*0x15*/IRC_FM_KEY,//21
/*0x16*/IRC_AUX_KEY,//22
/*0x17*/ IRC_USB_SD,//23
/*0x18*/ 0XFF,//24
/*0x19*/IRC_NUM9,//25
/*0x1a*/ IRC_MODE,//26
/*0x1b*/IRC_NUM2,//27
/*0x1c*/0XFF,//28
/*0x1d*/IRC_MODE,//29
/*0x1e*/IRC_MUTE,//30
/*0x1f*/IRC_NUM3,//31

};









