#include "bsp_test.h"





void Test_Init(void)
{
     GPIO_Init(TEST_PORT,TEST_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
     TEST_SET(0);
}



