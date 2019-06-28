#include "system.h"






void System_Init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV8);    //内部时钟16M
    Test_Init();
    Uart1_Init();
    Timer2_Init();
    enableInterrupts();
}

#if 0
void Delay_Time(unsigned int Time)
{
     static unsigned int i,j;
     for(i = Time; i > 0 ; i --)
     {
          for(j =200;j > 0 ;j --);
     }
}
#endif

void System_Handle(void)
{    
    #if 1
    static unsigned char Cnts;
     ++ Cnts;
     if(Cnts & 0x01)
     {
         TEST_SET(1);
         //Protocol_Send(0xfa,0xfb,0x01);
         //Delay_Time(5000);
     }
     else
     {
         TEST_SET(0);
         //Protocol_Send(0xfa,0xfb,0x02);
         //Delay_Time(5000);
     }
     #endif
}





