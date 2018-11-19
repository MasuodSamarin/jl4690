

#define IR_SYS_CODE			0x7f80

/*码值太大 在代码内 减 0XA0*/
/*      
      A0
     mode

PREV     NEXT  
   A1        A2

     PP
     A3
*/

const u8 IRTabFF00[] = 	   /*user code is 0xFF00*/
{
/*0x00*/IRC_MODE,//0
/*0x01*/IRC_PREV,// 1
/*0x02*/IRC_NEXT,//02
/*0x03*/IRC_PLAY_PAUSE,//03
/*0x04*/0XFF,//04
/*0x05*/0XFF,//05
/*0x06*/0XFF,//06
/*0x07*/0XFF,//07
/*0x08*/  0XFF,//08
/*0x09*/  0XFF,//09
/*0x0a*/  0XFF,//10
/*0x0b*/  0XFF,//11
/*0x0c*/  0XFF,//12
/*0x0d*/  0XFF,//13
/*0x0e*/  0XFF,//14
/*0x0f*/  0XFF,//15

};







