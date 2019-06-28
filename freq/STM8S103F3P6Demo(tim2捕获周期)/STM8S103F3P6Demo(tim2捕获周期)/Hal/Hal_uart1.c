


#include "..\APP\Includes.h"


uint8_t Rxd_buf[20];       //��������
uint8_t Rxd_len;            //���ճ���
uint8_t Rxd_F;              //���ձ�־λ
uint8_t Txd_buf[20];       //��������
uint8_t Txd_len;            //���ͳ���
uint8_t Txd_F;              //���ͱ�־λ



/*********************************************************************
 * @fn      Init_UART1()
 *
 * @brief   ��ʼ������
 *
 * @param   None.
 *
 * @return  None.
 ********************************************************************/
void Init_UART1(void)
{
  UART1_DeInit();                            //�ָ��������мĴ���
  UART1_Init((u32)9600,                      //������9600
             UART1_WORDLENGTH_8D,            //8λ
             UART1_STOPBITS_1,               //ֹͣλ1
             UART1_PARITY_NO,               
             UART1_SYNCMODE_CLOCK_DISABLE,   
             UART1_MODE_TXRX_ENABLE);
  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);  //ʹ�ܽ����ж�
//  UART1_ITConfig(UART1_IT_TC, ENABLE);       //ʹ�ܷ����ж�  �����ж�ʹ����������Ҫ��ʹ��
  UART1_Cmd(ENABLE);
}

/*********************************************************************
 * @fn      Send()
 *
 * @brief   ���ֽڷ�������
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
 * @brief   ��ѯ��������
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
 * @brief   �жϷ�������
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
  
  for(Txd_len=0;Txd_len <lV_len;Txd_len++)  //������װ��ȫ�ֱ�����
    Txd_buf[Txd_len]=lV_dat[Txd_len];
  
  UART1_ITConfig(UART1_IT_TC, ENABLE);       //ʹ�ܷ����ж�  
  return TRUE;
}


