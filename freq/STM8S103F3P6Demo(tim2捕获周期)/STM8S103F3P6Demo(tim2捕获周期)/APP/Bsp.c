

#include "..\APP\Includes.h"







void Bsp_Init(void)
{
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);    //�ڲ�ʱ��16M
  Led_Init();
  Init_UART1();
  Init_Timer2();
  enableInterrupts();
  UART1_Send("hello",5);
}

void Delay_Time(unsigned int Time)
{
  static unsigned int i,j;
  for(i = Time; i > 0 ;i --)
  {
     for(j = 200;j > 0 ;j --);
  }
}


void Bsp_Function(void)
{
  static unsigned char Cnts;
  ++Cnts;
  if(Cnts & 0x01)
  {
      LED_SET(1);
      Delay_Time(2000);
  }
  else
  {
      LED_SET(0);
      Delay_Time(2000);
  }
  
  
}











