
#define IR_SYS_CODE			0xff00
#define IR_SYS_CODE1			0x7F80
#define IR_SYS_CODE2			0xDF20


#define       IRC_STANBY           			 0 /*21*/
#define       IRC_MODE                         	1      /*01*/
#define       IRC_MUTE       			     2 /*22*/
#define       IRC_PLAY_PAUSE             3     /*03*/ 
#define       IRC_PREV                         4     /*04*/
#define       IRC_NEXT                          5   /*05*/  
#define       IRC_EQ                             6   /*06*/
#define       IRC_VOL_DN                	   7       /*07*/ 
#define       IRC_VOL_UP                    	8/*08*/ 
#define       IRC_NUM0                             9  /*09*/ 
#define       IRC_REPEAT                  		 10/*10*/ 
#define       IRC_USB_SD				11/*11*/
#define       IRC_NUM1                             12 /*12*/
#define       IRC_NUM2                             13/*13*/
#define       IRC_NUM3                            14/*14*/
#define       IRC_NUM4                            15/*15*/
#define       IRC_NUM5                            16/*16*/ 
#define       IRC_NUM6                            17/*17*/ 
#define       IRC_NUM7                            18/*18*/ 
#define       IRC_NUM8                            19/*19*/
#define       IRC_NUM9                            20 /*20*/
#define       IRC_STOP				       21/*21*/
#define       IRC_AUTO                             22
#define       IRC_CH_DN                           23
#define       IRC_CH_UP                            24
#define       IRC_ONLY_PREV			 25
#define       IRC_ONLY_NEXT                    26
#define       IRC_ADD10				27
#define       IRC_RECORD                    	28



/*              
power stop	MUTE
 45      46       47

mode	  repeat	eq
44  	     40  	43

prev 	next	 pp
7 	   15 	09

v-	v+	     0
16       19  	0D

1        2		3
0C 	  18		 5E

4	  5		6
8	 1C 		5A

7	  8		9
42	 52 		4A

*/


// 003 ff00
const u8 IRTab0[] = 	   /*user code is 0xFF00*/
{
/*0x00*/0XFF,//0
/*0x01*/0XFF,// 1
/*0x02*/0XFF,//02
/*0x03*/0XFF,//03
/*0x04*/0XFF,//04
/*0x05*/0XFF,//05
/*0x06*/0XFF,//06
/*0x07*/IRC_PREV,//07
/*0x08*/IRC_NUM4,//08
/*0x09*/IRC_PLAY_PAUSE,//09
/*0x0a*/0XFF,//10
/*0x0b*/0XFF,//11
/*0x0c*/IRC_NUM1,//12
/*0x0d*/IRC_NUM0,//13
/*0x0e*/0XFF ,//14
/*0x0f*/0XFF,//15
/*0x10*/0XFF,//16
/*0x11*/0XFF,//17
/*0x12*/0XFF,//18
/*0x13*/0XFF,//19
/*0x14*/0XFF,//20
/*0x15*/IRC_NEXT,//21
/*0x16*/IRC_VOL_DN,//22
/*0x17*/0XFF,//23
/*0x18*/IRC_NUM2,//24
/*0x19*/IRC_VOL_UP,//25
/*0x1a*/0XFF,//26
/*0x1b*/0XFF,//27
/*0x1c*/IRC_NUM5,//28
/*0x1d*/0XFF,//29
/*0x1e*/0XFF,//30
/*0x1f*/0XFF,//31

//NKEY_20, NKEY_21, NKEY_22, NKEY_23, NKEY_24, NKEY_25, NKEY_26, NKEY_27, NKEY_28, NKEY_29, NKEY_2A, NKEY_2B, NKEY_2C, NKEY_2D, NKEY_2E, NKEY_2F,
//NKEY_30, NKEY_31, NKEY_32, NKEY_33, NKEY_34, NKEY_35, NKEY_36, NKEY_37, NKEY_38, NKEY_39, NKEY_3A, NKEY_3B, NKEY_3C, NKEY_3D, NKEY_3E, NKEY_3F,

/*0x40*/ IRC_REPEAT,//64
/*0x41*/0XFF,// 65
/*0x42*/IRC_NUM7,//66
/*0x43*/IRC_EQ,//67
/*0x44*/IRC_MODE,//68
/*0x45*/IRC_STANBY,//69
/*0x46*/IRC_STOP,//70
/*0x47*/IRC_MUTE,//71
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


/*              
mute  		power
1e	          	   12

1        2		3
0A 	  1B		 1F

4	  5		6
0C	 0D 		0E

7	  8		9
00	 0F 		19

scan	  0		mode
09    07           1a

ch-   ch+    repeat eq
08 		17    16  15

prev     pp	     v+
02	     01		06

next      stop		v-
03	      04		05

*/


const u8 IRTab1[] = 	   /*user code is 0x7f80*/
{
/*0x00*/IRC_NUM7,//0
/*0x01*/IRC_PLAY_PAUSE,// 1
/*0x02*/IRC_ONLY_PREV,//02
/*0x03*/IRC_ONLY_NEXT,//03
/*0x04*/IRC_STOP,//04
/*0x05*/IRC_VOL_DN,//05
/*0x06*/IRC_VOL_UP,//06
/*0x07*/IRC_NUM0,//07
/*0x08*/  IRC_CH_DN,//08
/*0x09*/IRC_AUTO,//09
/*0x0a*/  IRC_NUM1,//10
/*0x0b*/ 0XFF,//11
/*0x0c*/IRC_NUM4,//12
/*0x0d*/IRC_NUM5,//13
/*0x0e*/IRC_NUM6,//14
/*0x0f*/IRC_NUM8,//15
/*0x10*/0XFF,//16
/*0x11*/0XFF,//17
/*0x12*/IRC_STANBY,//18
/*0x13*/0XFF,//19
/*0x14*/0XFF,//20
/*0x15*/IRC_EQ,//21
/*0x16*/IRC_REPEAT,//22
/*0x17*/ IRC_CH_UP,//23
/*0x18*/ 0XFF,//24
/*0x19*/IRC_NUM9,//25
/*0x1a*/ IRC_MODE,//26
/*0x1b*/IRC_NUM2,//27
/*0x1c*/0XFF,//28
/*0x1d*/0XFF,//29
/*0x1e*/IRC_MUTE,//30
/*0x1f*/IRC_NUM3,//31

//NKEY_20, NKEY_21, NKEY_22, NKEY_23, NKEY_24, NKEY_25, NKEY_26, NKEY_27, NKEY_28, NKEY_29, NKEY_2A, NKEY_2B, NKEY_2C, NKEY_2D, NKEY_2E, NKEY_2F,
//NKEY_30, NKEY_31, NKEY_32, NKEY_33, NKEY_34, NKEY_35, NKEY_36, NKEY_37, NKEY_38, NKEY_39, NKEY_3A, NKEY_3B, NKEY_3C, NKEY_3D, NKEY_3E, NKEY_3F,

/*0x40*/ 0XFF,//64
/*0x41*/0XFF,// 65
/*0x42*/0XFF,//66
/*0x43*/0XFF,//67
/*0x44*/0XFF,//68
/*0x45*/0XFF,//69
/*0x46*/0XFF,//70
/*0x47*/ 0XFF,//71
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
/*0x5e*/0XFF,//94
/*0x5f*/0XFF,//95
};

/* 

POWER		MODE
 09        		 1D

1	  2	     3
06 	  4B  	40

4	   5		6
07 	   59 	47

7	    8    	9
0F       41  	17

0	  10+   AUTO
49 	  08      4A

STOP		MUTE
11			15
		V+
		0E

CH-		EQ		CH+
03		1F		00

		V-
		1A
		
REPEAT			E/R
01				12

PREV	PP		NEXT
0d		19		1b

*/


const u8 IRTab2[] = 	   /*user code is 0xFE01*/
{
/*0x00*/IRC_CH_UP,//0
/*0x01*/IRC_REPEAT,// 1
/*0x02*/0XFF,//02
/*0x03*/IRC_CH_DN,//03
/*0x04*/0XFF,//04
/*0x05*/0XFF,//05
/*0x06*/IRC_NUM1,//06
/*0x07*/IRC_NUM4,//07
/*0x08*/ IRC_ADD10,//08
/*0x09*/IRC_STANBY,//09
/*0x0a*/  0XFF,//10
/*0x0b*/ 0XFF,//11
/*0x0c*/0XFF,//12
/*0x0d*/IRC_ONLY_PREV,//13
/*0x0e*/IRC_VOL_UP,//14
/*0x0f*/IRC_NUM7,//15
/*0x10*/0XFF,//16
/*0x11*/IRC_STOP,//17
/*0x12*/IRC_RECORD,//18
/*0x13*/0XFF,//19
/*0x14*/0XFF,//20
/*0x15*/IRC_MUTE,//21
/*0x16*/0XFF,//22
/*0x17*/ IRC_NUM9,//23
/*0x18*/ 0XFF,//24
/*0x19*/IRC_PLAY_PAUSE,//25
/*0x1a*/ IRC_VOL_DN,//26
/*0x1b*/IRC_ONLY_NEXT,//27
/*0x1c*/0XFF,//28
/*0x1d*/IRC_MODE,//29
/*0x1e*/0XFF,//30
/*0x1f*/IRC_EQ,//31

//NKEY_20, NKEY_21, NKEY_22, NKEY_23, NKEY_24, NKEY_25, NKEY_26, NKEY_27, NKEY_28, NKEY_29, NKEY_2A, NKEY_2B, NKEY_2C, NKEY_2D, NKEY_2E, NKEY_2F,
//NKEY_30, NKEY_31, NKEY_32, NKEY_33, NKEY_34, NKEY_35, NKEY_36, NKEY_37, NKEY_38, NKEY_39, NKEY_3A, NKEY_3B, NKEY_3C, NKEY_3D, NKEY_3E, NKEY_3F,

/*0x40*/ IRC_NUM3,//64
/*0x41*/IRC_NUM8,// 65
/*0x42*/0XFF,//66
/*0x43*/0XFF,//67
/*0x44*/0XFF,//68
/*0x45*/0XFF,//69
/*0x46*/0XFF,//70
/*0x47*/ IRC_NUM6,//71
/*0x48*/0XFF,//72
/*0x49*/IRC_NUM0,//73
/*0x4a*/IRC_AUTO,//74
/*0x4b*/IRC_NUM2,//75
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
/*0x59*/IRC_NUM5,//89
/*0x5a*/0XFF,//90
/*0x5b*/0XFF,//91
/*0x5c*/0XFF,//92
/*0x5d*/0XFF,//93
/*0x5e*/0XFF,//94
/*0x5f*/0XFF,//95
};

