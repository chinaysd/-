#ifndef _BSP_UART1_H_
#define _BSP_UART1_H_

#include "stm8s_conf.h"

#define TX_Byte     6

#define Hight(x)    ((x >> 8)& 0xff)
#define Low(x)      (x&0xff)
#define SENDBUFSIZE      7

typedef struct 
{
    unsigned char ID;
    unsigned char ADDR;
    unsigned char DATA1;
    unsigned char DATA2;
    unsigned char CHECKSUM;
    unsigned char STOP1;
    unsigned char STOP2;
}
UART1_BUF_t;

typedef union 
{
    unsigned char Buf[SENDBUFSIZE];
    UART1_BUF_t Uart1_Buf;
}
PROTOCOL_SEND;








void Uart1_Init(void);
unsigned char Protocol_Send(unsigned char id,unsigned char addr,unsigned int Data);


#endif
