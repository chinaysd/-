#ifndef _BSP_TEST_H_
#define _BSP_TEST_H_

#include "stm8s_conf.h"


#define TEST_PORT      GPIOD
#define TEST_PIN       GPIO_PIN_2
#define TEST_SET(X)    ((X)?(GPIO_WriteHigh(TEST_PORT,TEST_PIN)):(GPIO_WriteLow(TEST_PORT,TEST_PIN)))








void Test_Init(void);


#endif



