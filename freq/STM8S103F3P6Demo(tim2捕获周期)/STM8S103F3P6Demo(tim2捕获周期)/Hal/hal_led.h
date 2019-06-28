#ifndef _HAL_LED_H_
#define _HAL_LED_H_

#include "..\STM8S_Driver\inc\stm8s.h"



#define LED_PORT      GPIOD
#define LED_PIN       GPIO_PIN_2
#define LED_SET(X)    ((X)?(GPIO_WriteHigh(LED_PORT,LED_PIN)):(GPIO_WriteLow(LED_PORT,LED_PIN)))












void Led_Init(void);


#endif
