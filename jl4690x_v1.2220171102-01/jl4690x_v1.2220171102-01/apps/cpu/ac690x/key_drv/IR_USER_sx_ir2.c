
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
#define       IRC_EQ                                   19   /*06*/
#define       IRC_REPEAT                         20/*10*/ 
#define       IRC_TREBLE_UP                 21 /*21*/
#define       IRC_TREBLE_DN                 22 /*22*/
#define       IRC_BT_MODE                          23

#define       IRC_ADD100                           24/*11*/
#define       IRC_BASS_UP                       25    
#define       IRC_BASS_DN                       26   
#define       IRC_21_51CH                           27 

#define       IRC_USB_SD_FM_SCAN             28
#define       IRC_ONLY_PLAY_PAUSE            29
#define       IRC_FM_MODE                           30
#define       IRC_LINE_MODE                        31
#define       IRC_MUSIC_MODE                      32


#define IR_SYS_CODE			0x5780


/*      
power     mute 
 51              4b

  T+     B+       mode
 53      45  	      13

 T-        B-       0
 52 	   5c      16

1        2	     3
4F 	 08	    1D

4	  5		6
4A	44 		40

7	  8		9
49	 0C 	      1B


2.1/0A           5.1/1E

        VOL+/12

PREV /03   pp/5D     next /0E
        
      VOL-/07

    eq/   02      repeat/10

*/


const u8 IRTabFF00[] = 	   /*user code is 0xFF00*/
{
/*0x00*/0XFF,//0
/*0x01*/0XFF,// 1
/*0x02*/IRC_EQ,//02
/*0x03*/IRC_PREV,//03
/*0x04*/0XFF,//04
/*0x05*/0XFF,//05
/*0x06*/0XFF,//06
/*0x07*/IRC_VOL_DN,//07
/*0x08*/  IRC_NUM2,//08
/*0x09*/IRC_BASS_DN,//09
/*0x0a*/  IRC_21_51CH,//10
/*0x0b*/ 0XFF,//11
/*0x0c*/IRC_NUM8,//12
/*0x0d*/IRC_NUM0,//13
/*0x0e*/ IRC_NEXT,//14
/*0x0f*/0XFF,//15
/*0x10*/IRC_REPEAT,//16
/*0x11*/0XFF,//17
/*0x12*/IRC_VOL_UP,//18
/*0x13*/IRC_MODE,//19
/*0x14*/0XFF,//20
/*0x15*/IRC_TREBLE_DN,//21
/*0x16*/IRC_NUM0,//22
/*0x17*/ 0XFF,//23
/*0x18*/ IRC_NUM2,//24
/*0x19*/IRC_21_51CH,//25
/*0x1a*/ 0XFF,//26
/*0x1b*/IRC_NUM9,//27
/*0x1c*/IRC_NUM5,//28
/*0x1d*/IRC_NUM3,//29
/*0x1e*/IRC_21_51CH,//30
/*0x1f*/0XFF,//31


/*0x40*/ IRC_NUM6,//64
/*0x41*/0XFF,// 65
/*0x42*/IRC_NUM7,//66
/*0x43*/IRC_BASS_UP,//67
/*0x44*/IRC_NUM5,//68
/*0x45*/IRC_BASS_UP,//69
/*0x46*/ IRC_PLAY_PAUSE,//70
/*0x47*/ IRC_NEXT,//71
/*0x48*/0XFF,//72
/*0x49*/IRC_NUM7,//73
/*0x4a*/IRC_NUM4,//74
/*0x4b*/IRC_MUTE,//75
/*0x4c*/0XFF,//76
/*0x4d*/0XFF,//77
/*0x4e*/0XFF,//78
/*0x4f*/IRC_NUM1,//79
/*0x50*/0XFF,//80
/*0x51*/IRC_STANBY,//81
/*0x52*/ IRC_TREBLE_DN,//82
/*0x53*/ IRC_TREBLE_UP,//83
/*0x54*/0XFF,//84
/*0x55*/ 0XFF,//85
/*0x56*/ 0XFF,//86
/*0x57*/0XFF,//87
/*0x58*/0XFF,//88
/*0x59*/0XFF,//89
/*0x5a*/IRC_NUM6,//90
/*0x5b*/0XFF,//91
/*0x5c*/IRC_BASS_DN,//92
/*0x5d*/IRC_PLAY_PAUSE,//93
/*0x5e*/IRC_NUM3,//94
/*0x5f*/0XFF,//95
};









