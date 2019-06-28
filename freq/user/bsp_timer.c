#include "bsp_timer.h"


void Timer2_Init(void)
{
    #if 0
    GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);//输入  无中断
    
    TIM2_DeInit();
    TIM2_TimeBaseInit(TIM2_PRESCALER_16, 10000-1);           //16分频， 1MHZ 10000 = 10ms 溢出
    TIM2_ICInit(TIM2_CHANNEL_2, TIM2_ICPOLARITY_RISING, TIM2_ICSELECTION_DIRECTTI, TIM2_ICPSC_DIV1, 0x00); //设置通道 设置输入捕获上升触发  捕获输入引脚  输入捕捉预定标器    滤波 
    TIM2_ClearFlag(TIM2_FLAG_CC2);                         //指定要清除的标志
    TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);                 //使能向上计数功能
    TIM2_ITConfig(TIM2_IT_CC2, ENABLE);                    //使能输入捕获通道2
    TIM2_Cmd(ENABLE); 
    #else
    {

    }
    
}



