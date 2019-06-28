
#ifndef _INCLUDE_H
#define _INCLUDE_H

#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <stdarg.h>



#include "..\STM8S_Driver\inc\stm8s.h"
#include "..\APP\Bsp.h"
#include "..\Hal\Hal_tim2.h"
#include "..\Hal\Hal_uart1.h"
#include "..\Hal\hal_led.h"

#define ABS(x,y) ((x>y)?(x-y):(y-x))    //���������ľ���ֵ
#define MAX(a,b) (a>b)?a:b              //�����ֵ
#define MIN(a,b) (a<b)?a:b              //����Сֵ
#define VOID (void)                     //�޷���


#endif /* __INCLUDE_H */
