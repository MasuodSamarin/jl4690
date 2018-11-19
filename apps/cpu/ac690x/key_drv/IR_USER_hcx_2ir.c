


#define IR_SYS_CODE			0xff00

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
#define       IRC_FM_CHINC                 21 /*21*/
#define       IRC_FM_CHDEC                 22 /*22*/
#define       IRC_BT_MODE                          23

#define       IRC_ADD100                      24/*11*/
#define       IRC_ONLY_PREV                  25     /*04  不复合 CH-*/
#define       IRC_ONLY_NEXT                  26   /*05    不复合 CH+*/  
#define       IRC_STOP                                27 

#define       IRC_FM_SCAN                            28
#define       IRC_ONLY_PLAY_PAUSE            29
#define       IRC_FM_STEP_DN                      30
#define       IRC_FM_STEP_UP                      31
#define       IRC_MUSIC_MODE                      32



/*      
stanby             mute
   5f                    1d

step+       auto		ch+
4f 	       4e            5e

0f	     		         ch-
step-                     11


vol+/50    vol-/ 45   pp/13  
 prev /51   next/12  mode /4d



1/0b    2/16     3/1f    4/54

5/4b    6/53     7/56    8/0c

9/46    0/0d   eq/09    repeat/47

*/


const u8 IRTabFF00[] = 	   /*user code is 0xFF00*/
{
/*0x00*/IRC_NUM7,//0
/*0x01*/0XFF,// 1
/*0x02*/0XFF,//02
/*0x03*/0XFF,//03
/*0x04*/0XFF,//04
/*0x05*/0XFF,//05
/*0x06*/0XFF,//06
/*0x07*/0XFF,//07
/*0x08*/  0XFF,//08
/*0x09*/IRC_EQ,//09
/*0x0a*/  0XFF,//10
/*0x0b*/ IRC_NUM1,//11
/*0x0c*/IRC_NUM8,//12
/*0x0d*/IRC_NUM0,//13
/*0x0e*/ 0XFF,//14
/*0x0f*/IRC_FM_STEP_DN,//15
/*0x10*/0XFF,//16
/*0x11*/IRC_FM_CHDEC,//17
/*0x12*/IRC_ONLY_NEXT,//18
/*0x13*/IRC_ONLY_PLAY_PAUSE,//19
/*0x14*/0XFF,//20
/*0x15*/0XFF,//21
/*0x16*/IRC_NUM2,//22
/*0x17*/ IRC_USB_SD,//23
/*0x18*/ 0XFF,//24
/*0x19*/IRC_NUM9,//25
/*0x1a*/ IRC_MODE,//26
/*0x1b*/IRC_NUM2,//27
/*0x1c*/0XFF,//28
/*0x1d*/IRC_MUTE,//29
/*0x1e*/IRC_MUTE,//30
/*0x1f*/IRC_NUM3,//31

/*0x40*/ IRC_FM_CHINC,//64
/*0x41*/0XFF,// 65
/*0x42*/IRC_NUM7,//66
/*0x43*/IRC_EQ,//67
/*0x44*/IRC_FM_CHDEC,//68
/*0x45*/IRC_VOL_DN,//69
/*0x46*/ IRC_NUM9,//70
/*0x47*/ IRC_REPEAT,//71
/*0x48*/0XFF,//72
/*0x49*/0XFF,//73
/*0x4a*/IRC_NUM9,//74
/*0x4b*/IRC_NUM5,//75
/*0x4c*/0XFF,//76
/*0x4d*/IRC_MODE,//77
/*0x4e*/IRC_FM_SCAN,//78
/*0x4f*/IRC_FM_STEP_UP,//79
/*0x50*/IRC_VOL_UP,//80
/*0x51*/IRC_ONLY_PREV,//81
/*0x52*/ IRC_NUM8,//82
/*0x53*/IRC_NUM6,//83
/*0x54*/IRC_NUM4,//84
/*0x55*/ 0XFF,//85
/*0x56*/ IRC_NUM7,//86
/*0x57*/0XFF,//87
/*0x58*/0XFF,//88
/*0x59*/0XFF,//89
/*0x5a*/IRC_NUM6,//90
/*0x5b*/0XFF,//91
/*0x5c*/0XFF,//92
/*0x5d*/0XFF,//93
/*0x5e*/IRC_FM_CHINC,//94
/*0x5f*/IRC_STANBY,//95

};

//DF20
const u8 IRTabFF00_2[] = 	   /*user code is 0xFF00*/
	{
	/*0x00*/IRC_FM_STEP_UP,//0
	/*0x01*/IRC_FM_CHDEC,// 1
	/*0x02*/0XFF,//02
	/*0x03*/IRC_FM_STEP_DN,//03
	/*0x04*/0XFF,//04
	/*0x05*/0XFF,//05
	/*0x06*/0XFF,//06
	/*0x07*/0XFF,//07
	/*0x08*/  0XFF,//08
	/*0x09*/IRC_STANBY,//09
	/*0x0a*/  0XFF,//10
	/*0x0b*/ IRC_NUM1,//11
	/*0x0c*/IRC_NUM8,//12
	/*0x0d*/IRC_MODE,//13
	/*0x0e*/ IRC_VOL_UP,//14
	/*0x0f*/IRC_FM_CHINC,//15
	/*0x10*/0XFF,//16
	/*0x11*/IRC_ONLY_PREV,//17
	/*0x12*/IRC_FM_SCAN,//18
	/*0x13*/IRC_ONLY_PLAY_PAUSE,//19
	/*0x14*/0XFF,//20
	/*0x15*/IRC_ONLY_PLAY_PAUSE,//21
	/*0x16*/IRC_NUM2,//22
	/*0x17*/ IRC_ONLY_NEXT,//23
	/*0x18*/ 0XFF,//24
	/*0x19*/IRC_EQ,//25
	/*0x1a*/ IRC_VOL_DN,//26
	/*0x1b*/IRC_REPEAT,//27
	/*0x1c*/0XFF,//28
	/*0x1d*/0XFF,//29
	/*0x1e*/0XFF,//30
	/*0x1f*/IRC_MUTE,//31
	
	};







