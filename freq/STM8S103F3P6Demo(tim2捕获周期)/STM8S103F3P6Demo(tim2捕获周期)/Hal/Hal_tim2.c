

#include "..\APP\Includes.h"







/*********************************************************************
 * @fn      Init_Timer2()
 *
 * @brief   ����
 *
 * @param   None.
 *
 * @return  None.
 ********************************************************************/
void Init_Timer2(void)
{
    GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);//����  ���ж�
    
    TIM2_DeInit();
    TIM2_TimeBaseInit(TIM2_PRESCALER_16, 10000);           //16��Ƶ�� 1MHZ 10000 = 10ms ���
    TIM2_ICInit(TIM2_CHANNEL_2, TIM2_ICPOLARITY_RISING, TIM2_ICSELECTION_DIRECTTI, TIM2_ICPSC_DIV1, 0x00); //����ͨ�� �������벶����������  ������������  ���벶׽Ԥ������    �˲� 
    TIM2_ClearFlag(TIM2_FLAG_CC2);                         //ָ��Ҫ����ı�־
    TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);                 //ʹ�����ϼ�������
    TIM2_ITConfig(TIM2_IT_CC2, ENABLE);                    //ʹ�����벶��ͨ��2
    TIM2_Cmd(ENABLE);  
}

