
#define IR_SYS_CODE			0xFE01



#define       IRC_STANBY           			 0 /*21*/
#define       IRC_MODE                         	1      /*01*/
#define       IRC_MUTE       			     2 /*22*/
#define       IRC_PLAY_PAUSE             3     /*03*/ 
#define       IRC_PREV                         4     /*04*/
#define       IRC_NEXT                          5   /*05*/  
#define       IRC_EQ                             6   /*06*/
#define       IRC_VOL_DN                   7       /*07*/ 
#define       IRC_VOL_UP                    8/*08*/ 
#define       IRC_NUM0                             9  /*09*/ 
#define       IRC_REP_ONE                   10/*10*/ 
#define       IRC_FM_SCAN				11/*11*/
#define       IRC_NUM1                             12 /*12*/
#define       IRC_NUM2                             13/*13*/
#define       IRC_NUM3                            14/*14*/
#define       IRC_NUM4                            15/*15*/
#define       IRC_NUM5                            16/*16*/ 
#define       IRC_NUM6                            17/*17*/ 
#define       IRC_NUM7                            18/*18*/ 
#define       IRC_NUM8                            19/*19*/
#define       IRC_NUM9                            20 /*20*/
#define       IRC_REP_ALL				21/*21*/
#define       IRC_REP_RAND                     22
#define       IRC_SEL_PLAY                      23
#define       IRC_BASS_UP				24
#define       IRC_BASS_DN				25
#define       IRC_TREBLE_UP			26
#define       IRC_TREBLE_DN			27
#define       IRC_MUSIC_FR				28
#define       IRC_MUSIC_FF				29
#define       IRC_CLASSIC_MUSIC		30 //¹ÅµäÀÖ
#define       IRC_GUOXUE				31  //¹úÑ§
#define       IRC_WEST_MUSIC			32   // Î÷ÀÖ
#define       IRC_ENGLISH				33	//Ó¢Óï
#define       IRC_STORY				34	//¹ÊÊÂ
#define       IRC_SONG					35	// ¶ù¸è
#define       IRC_ENCYCLOPEDIA		36  // °Ù¿Æ 
#define       IRC_FITAL_EDUCATION		37 //Ì¥½Ì
#define       IRC_LISTEN				38 // ¸ú¶Á
#define       IRC_NULL					39





/*  

------------------
power		mute
1c			08

repone repall rand  sequential(Ë³Ðò²¥·Å)
56		57	1f	5b

1		2	3	eq
55		5e	51	59

4		5	6	0
10		52	50	5c

7		8	9	Ñ¡¶Î
01		5f	19	58

------------------

bass+			treb+
18				17
		up
		1a

	fr	ok	ff
	47	06	07

		dn
		48
bass-			treb-
49				0a

------------------
v+		mode	prev 
4b		03		09

v-		search	next
4f		42		05

------------------

FR		PP		FF
54		16		15

¹ÅµäÀÖ	¹úÑ§ Î÷ÀÖ
50			12		11

Ó¢Óï	¹ÊÊÂ	¶ù¸è
4c		0e		0d

°Ù¿Æ Ì¥½Ì	¸ú¶Á
41		0c		10

------------------
*/


// 003 ff00
const u8 IRTab0[] = 	   /*user code is 0xFF00*/
{
/*0x00*/0XFF,//0
/*0x01*/IRC_NUM7,// 1
/*0x02*/0XFF,//02
/*0x03*/IRC_MODE,//03
/*0x04*/0XFF,//04
/*0x05*/IRC_NEXT,//05
/*0x06*/IRC_PLAY_PAUSE,//06
/*0x07*/IRC_MUSIC_FF,//07
/*0x08*/IRC_MUTE,//08
/*0x09*/IRC_PREV,//09
/*0x0a*/IRC_TREBLE_DN,//10
/*0x0b*/0XFF,//11
/*0x0c*/IRC_FITAL_EDUCATION,//12
/*0x0d*/IRC_SONG,//13
/*0x0e*/IRC_STORY ,//14
/*0x0f*/0XFF,//15
/*0x10*/IRC_LISTEN,//16
/*0x11*/IRC_WEST_MUSIC,//17
/*0x12*/IRC_GUOXUE,//18
/*0x13*/0XFF,//19
/*0x14*/0XFF,//20
/*0x15*/IRC_MUSIC_FF,//21
/*0x16*/IRC_PLAY_PAUSE,//22
/*0x17*/IRC_TREBLE_UP,//23
/*0x18*/IRC_BASS_UP,//24
/*0x19*/IRC_NUM9,//25
/*0x1a*/IRC_PREV,//26
/*0x1b*/0XFF,//27
/*0x1c*/IRC_STANBY,//28
/*0x1d*/IRC_NUM4,//29
/*0x1e*/0XFF,//30
/*0x1f*/IRC_REP_RAND,//31

//NKEY_20, NKEY_21, NKEY_22, NKEY_23, NKEY_24, NKEY_25, NKEY_26, NKEY_27, NKEY_28, NKEY_29, NKEY_2A, NKEY_2B, NKEY_2C, NKEY_2D, NKEY_2E, NKEY_2F,
//NKEY_30, NKEY_31, NKEY_32, NKEY_33, NKEY_34, NKEY_35, NKEY_36, NKEY_37, NKEY_38, NKEY_39, NKEY_3A, NKEY_3B, NKEY_3C, NKEY_3D, NKEY_3E, NKEY_3F,

/*0x40*/ 0XFF,//64
/*0x41*/IRC_ENCYCLOPEDIA,// 65
/*0x42*/IRC_FM_SCAN,//66
/*0x43*/0XFF,//67
/*0x44*/0XFF,//68
/*0x45*/0XFF,//69
/*0x46*/0XFF,//70
/*0x47*/IRC_MUSIC_FR,//71
/*0x48*/IRC_NEXT,//72
/*0x49*/IRC_BASS_DN,//73
/*0x4a*/0XFF,//74
/*0x4b*/IRC_VOL_UP,//75
/*0x4c*/IRC_ENGLISH,//76
/*0x4d*/0XFF,//77
/*0x4e*/0XFF,//78
/*0x4f*/IRC_VOL_DN,//79
/*0x50*/IRC_CLASSIC_MUSIC,//80
/*0x51*/IRC_NUM3,//81
/*0x52*/ IRC_NUM5,//82
/*0x53*/0XFF,//83
/*0x54*/IRC_MUSIC_FR,//84
/*0x55*/ IRC_NUM1,//85
/*0x56*/ IRC_REP_ONE,//86
/*0x57*/IRC_REP_ALL,//87
/*0x58*/IRC_SEL_PLAY,//88
/*0x59*/IRC_EQ,//89
/*0x5a*/0XFF,//90
/*0x5b*/IRC_REP_ALL,//91
/*0x5c*/IRC_NUM0,//92
/*0x5d*/IRC_NUM6,//93
/*0x5e*/IRC_NUM2,//94
/*0x5f*/IRC_NUM8,//95
};

