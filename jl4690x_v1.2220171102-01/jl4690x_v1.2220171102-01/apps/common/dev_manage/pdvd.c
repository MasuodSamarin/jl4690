#include "sdk_cfg.h"

#ifdef SUPPORT_3LINE_HZWY_PDVD
#include "dev_manage\pdvd.h"
#include "common/common.h"

/******************************************



*******************************************/

 u16 Pdvd_Data[6];


void PDVD_delay(void)
{
    delay(5);
}

u16 PDVD_READ_BYTE(void)
{
 u8 i;
 u16 btemp=0;

HT1628_STB(0);   
delayus();

 for(i=0;i<11;i++){   
   PDVD_CLK_SET(0);  //---------|
   PDVD_delay();    
   PDVD_CLK_SET(1);
   PDVD_delay(); 
   if(PDVD_DATA_READ())
   btemp|=BIT(i);
   PDVD_delay();   
 }
   PDVD_delay();
   HT1628_STB(1);
   
  return btemp;
}


void Pdvd_Init(void)
{

    PDVD_INIT();

    M62429Data[0]=OKVOL_DEFAULT;	
    M62429Data[1]=ECHO_DEFAULT;
    SetM62429Data(OKVOL_NOMAL);
	
}



#endif

