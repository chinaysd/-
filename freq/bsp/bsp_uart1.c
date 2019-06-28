#include "bsp_uart1.h"
#include "string.h"



void Uart1_Init(void)
{
    UART1_DeInit();
    UART1_Init(9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TX_ENABLE);
    UART1_Cmd(ENABLE);   
}

static int  UART_SentByte(unsigned char Byte){

    while(UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET);
    UART1_SendData8(Byte);
    return 0;
}


static unsigned char SendData(PROTOCOL_SEND *p)
{
     static unsigned char i;
     for(i = 0 ; i < SENDBUFSIZE; i ++)
     {
         UART_SentByte(p->Buf[i]);
     }
     return 0;
}

unsigned char Protocol_Send(unsigned char id,unsigned char addr,unsigned int Data)
{
     PROTOCOL_SEND buf;
     memset(&buf,0,sizeof(buf));
     buf.Uart1_Buf.ID = id;
     buf.Uart1_Buf.ADDR = addr;
     buf.Uart1_Buf.DATA1 = Hight(Data);
     buf.Uart1_Buf.DATA2 = Low(Data);
     buf.Uart1_Buf.CHECKSUM = (unsigned char)(buf.Uart1_Buf.ID+buf.Uart1_Buf.ADDR+buf.Uart1_Buf.DATA1+buf.Uart1_Buf.DATA2);
     buf.Uart1_Buf.STOP1 = 0x0d;
     buf.Uart1_Buf.STOP2 = 0x0a;
     return SendData(&buf);
}



