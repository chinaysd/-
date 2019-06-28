




#ifndef __HAL_UART1_H
#define __HAL_UART1_H



extern uint8_t Rxd_buf[20];       //接收数组
extern uint8_t Rxd_len;            //接收长度
extern uint8_t Rxd_F;              //接收标志位
extern uint8_t Txd_buf[20];       //发送数组
extern uint8_t Txd_len;            //发送长度
extern uint8_t Txd_F;              //发送标志位








extern void Init_UART1(void);

extern void Send(uint8_t dat);
extern void UART1_Send(uint8_t *dat,uint8_t len);
extern uint8_t Set_UART1Interrupt(uint8_t *lV_dat,uint8_t lV_len);



#endif /* __HAL_UART1_H */
