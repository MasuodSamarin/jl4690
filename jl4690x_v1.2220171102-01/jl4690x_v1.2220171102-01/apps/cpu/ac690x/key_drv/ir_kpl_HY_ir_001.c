




#define IR_SYS_CODE			0xff00

#define       IRC_STANBY                       0 
#define       IRC_MODE                         1     
#define       IRC_MUTE                         2 
#define       IRC_PLAY_PAUSE                   3    
#define       IRC_PREV                         4     
#define       IRC_NEXT                         5  
#define       IRC_VOL_UP                       6
#define       IRC_VOL_DN                       7       
#define       IRC_USB_SD                8
#define       IRC_FM                    9
#define       IRC_BT                    10
#define       IRC_AUX                   11
#define       IRC_FM_SCAN          12   
#define       IRC_RESET                    13
#define       IRC_FM_STEP_DN           14 
#define       IRC_FM_STEP_UP               15 



/*      

power USD   MUTE
 45      46       47

FM     BT         AUX     
44      40  	43

PREV    NEXT    PP   
07 	   15 	09

V-       V+         RESET
16       19  	0d

SCAN    SEEK-   SEEK+
0c 	  18		 5e

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
/*0x07*/IRC_PREV,//07
/*0x08*/  0XFF,//08
/*0x09*/IRC_PLAY_PAUSE,//09
/*0x0a*/  0XFF,//10
/*0x0b*/ 0XFF,//11
/*0x0c*/IRC_FM_SCAN,//12
/*0x0d*/IRC_RESET,//13
/*0x0e*/ 0XFF,//14
/*0x0f*/0XFF,//15
/*0x10*/0XFF,//16
/*0x11*/0XFF,//17
/*0x12*/0XFF,//18
/*0x13*/0XFF,//19
/*0x14*/0XFF,//20
/*0x15*/IRC_NEXT,//21
/*0x16*/IRC_VOL_UP,//22
/*0x17*/ 0XFF,//23
/*0x18*/ IRC_FM_STEP_DN,//24
/*0x19*/IRC_VOL_DN,//25
/*0x1a*/ 0XFF,//26
/*0x1b*/0XFF,//27
/*0x1c*/0XFF,//28
/*0x1d*/0XFF,//29
/*0x1e*/0XFF,//30
/*0x1f*/0XFF,//31


/*0x40*/ IRC_BT,//64
/*0x41*/0XFF,// 65
/*0x42*/0XFF,//66
/*0x43*/IRC_AUX,//67
/*0x44*/IRC_FM,//68
/*0x45*/IRC_STANBY,//69
/*0x46*/ IRC_USB_SD,//70
/*0x47*/ IRC_MUTE,//71
/*0x48*/0XFF,//72
/*0x49*/0XFF,//73
/*0x4a*/0XFF,//74
/*0x4b*/0XFF,//75
/*0x4c*/0XFF,//76
/*0x4d*/0XFF,//77
/*0x4e*/0XFF,//78
/*0x4f*/0XFF,//79
/*0x50*/0XFF,//80
/*0x51*/0XFF,//81
/*0x52*/ 0XFF,//82
/*0x53*/0XFF,//83
/*0x54*/0XFF,//84
/*0x55*/ 0XFF,//85
/*0x56*/ 0XFF,//86
/*0x57*/0XFF,//87
/*0x58*/0XFF,//88
/*0x59*/0XFF,//89
/*0x5a*/0XFF,//90
/*0x5b*/0XFF,//91
/*0x5c*/0XFF,//92
/*0x5d*/0XFF,//93
/*0x5e*/IRC_FM_STEP_UP,//94
/*0x5f*/0XFF,//95
};





