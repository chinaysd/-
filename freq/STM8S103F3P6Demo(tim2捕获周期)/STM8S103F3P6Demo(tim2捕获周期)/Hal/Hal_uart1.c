


#include "..\APP\Includes.h"


uint8_t Rxd_buf[20];       //接收数组
uint8_t Rxd_len;            //接收长度
uint8_t Rxd_F;              //接收标志位
uint8_t Txd_buf[20];       //发送数组
uint8_t Txd_len;            //发送长度
uint8_t Txd_F;              //发送标志位



/*********************************************************************
 * @fn      Init_UART1()
 *
 * @brief   初始化串口
 *
 * @param   None.
 *
 * @return  None.
 ********************************************************************/
void Init_UART1(void)
{
  UART1_DeInit();                            //恢复串口所有寄存器
  UART1_Init((u32)9600,                      //波特率9600
             UART1_WORDLENGTH_8D,            //8位
             UART1_STOPBITS_1,               //停止位1
             UART1_PARITY_NO,               
             UART1_SYNCMODE_CLOCK_DISABLE,   
             UART1_MODE_TXRX_ENABLE);
  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);  //使能接收中断
//  UART1_ITConfig(UART1_IT_TC, ENABLE);       //使能发送中断  发送中断使能是那里需要才使能
  UART1_Cmd(ENABLE);
}

/*********************************************************************
 * @fn      Send()
 *
 * @brief   单字节发送数据
 *
 * @param   dat.
 *
 * @return  None.
 ********************************************************************/
void Send(uint8_t dat)
{
  while(( UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET));
    UART1_SendData8(dat);
}




/*********************************************************************
 * @fn      UART1_Send()
 *
 * @brief   查询发送数据
 *
 * @param   dat len
 *
 * @return  None.
 ********************************************************************/
void UART1_Send(uint8_t *dat,uint8_t len)
{
  uint8_t i = 0;
  for(i=0; i<len; i++)
  {
    while(( UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET));
    UART1_SendData8(*dat++);
  }
}


/*********************************************************************
 * @fn      UART1_Send()
 *
 * @brief   中断发送数据
 *
 * @param   lV_dat lV_len
 *
 * @return  None.
 ********************************************************************/
uint8_t Set_UART1Interrupt(uint8_t *lV_dat,uint8_t lV_len)
{
  if(Txd_len != 0)
  {
    return FALSE;
  }
  
  for(Txd_len=0;Txd_len <lV_len;Txd_len++)  //将数据装到全局变量中
    Txd_buf[Txd_len]=lV_dat[Txd_len];
  
  UART1_ITConfig(UART1_IT_TC, ENABLE);       //使能发送中断  
  return TRUE;
}


