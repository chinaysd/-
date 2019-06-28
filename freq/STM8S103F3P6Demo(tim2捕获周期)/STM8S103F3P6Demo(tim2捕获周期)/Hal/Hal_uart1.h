




#ifndef __HAL_UART1_H
#define __HAL_UART1_H



extern uint8_t Rxd_buf[20];       //��������
extern uint8_t Rxd_len;            //���ճ���
extern uint8_t Rxd_F;              //���ձ�־λ
extern uint8_t Txd_buf[20];       //��������
extern uint8_t Txd_len;            //���ͳ���
extern uint8_t Txd_F;              //���ͱ�־λ








extern void Init_UART1(void);

extern void Send(uint8_t dat);
extern void UART1_Send(uint8_t *dat,uint8_t len);
extern uint8_t Set_UART1Interrupt(uint8_t *lV_dat,uint8_t lV_len);



#endif /* __HAL_UART1_H */
