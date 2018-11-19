
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
#define       IRC_EQ                             19   /*06*/
#define       IRC_REPEAT                     20/*10*/ 
#define       IRC_TREBLE_UP                 21 /*21*/
#define       IRC_TREBLE_DN                 22 /*22*/
#define       IRC_BT_MODE                          23

#define       IRC_ADD100                      24/*11*/
#define       IRC_BASS_UP                  25     /*04  不复合 CH-*/
#define       IRC_BASS_DN                  26   /*05    不复合 CH+*/  
#define       IRC_21_51CH                           27 

#define       IRC_USB_SD_FM_SCAN             28
#define       IRC_ONLY_PLAY_PAUSE            29
#define       IRC_FM_MODE                           30
#define       IRC_LINE_MODE                        31
#define       IRC_MUSIC_MODE                      32


#define IR_SYS_CODE			0xff00


/*      
PREV  PP   NEXT 
 45      46       47

V+     T+     B+
44      40  	43

V-       T-        B-  
07 	   15 	   09

MODE     21/51       0
16       19    	0d

1        2		3
0c 	  18		 5e

4	  5		6
08	 1c 		5a

7	  8		9
42	 52 		4a

*/


const u8 IRTabFF00[] = 	   /*user code is 0xFF00*/
{
/*0x00*/0XFF,//0
/*0x01*/0XFF,// 1
/*0x02*/0XFF,//02
/*0x03*/0XFF,//03
/*0x04*/0XFF,//04
/*0x05*/0XFF,//05
/*0x06*/0XFF,//06
/*0x07*/IRC_VOL_DN,//07
/*0x08*/  IRC_NUM4,//08
/*0x09*/IRC_BASS_DN,//09
/*0x0a*/  0XFF,//10
/*0x0b*/ 0XFF,//11
/*0x0c*/IRC_NUM1,//12
/*0x0d*/IRC_NUM0,//13
/*0x0e*/ 0XFF,//14
/*0x0f*/0XFF,//15
/*0x10*/0XFF,//16
/*0x11*/0XFF,//17
/*0x12*/0XFF,//18
/*0x13*/0XFF,//19
/*0x14*/0XFF,//20
/*0x15*/IRC_TREBLE_DN,//21
/*0x16*/IRC_MODE,//22
/*0x17*/ 0XFF,//23
/*0x18*/ IRC_NUM2,//24
/*0x19*/IRC_21_51CH,//25
/*0x1a*/ 0XFF,//26
/*0x1b*/0XFF,//27
/*0x1c*/IRC_NUM5,//28
/*0x1d*/0XFF,//29
/*0x1e*/0XFF,//30
/*0x1f*/0XFF,//31


/*0x40*/ IRC_TREBLE_UP,//64
/*0x41*/0XFF,// 65
/*0x42*/IRC_NUM7,//66
/*0x43*/IRC_BASS_UP,//67
/*0x44*/IRC_VOL_UP,//68
/*0x45*/IRC_PREV,//69
/*0x46*/ IRC_PLAY_PAUSE,//70
/*0x47*/ IRC_NEXT,//71
/*0x48*/0XFF,//72
/*0x49*/0XFF,//73
/*0x4a*/IRC_NUM9,//74
/*0x4b*/0XFF,//75
/*0x4c*/0XFF,//76
/*0x4d*/0XFF,//77
/*0x4e*/0XFF,//78
/*0x4f*/0XFF,//79
/*0x50*/0XFF,//80
/*0x51*/0XFF,//81
/*0x52*/ IRC_NUM8,//82
/*0x53*/0XFF,//83
/*0x54*/0XFF,//84
/*0x55*/ 0XFF,//85
/*0x56*/ 0XFF,//86
/*0x57*/0XFF,//87
/*0x58*/0XFF,//88
/*0x59*/0XFF,//89
/*0x5a*/IRC_NUM6,//90
/*0x5b*/0XFF,//91
/*0x5c*/0XFF,//92
/*0x5d*/0XFF,//93
/*0x5e*/IRC_NUM3,//94
/*0x5f*/0XFF,//95
};









