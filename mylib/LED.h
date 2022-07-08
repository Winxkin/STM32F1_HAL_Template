#ifndef __LED_H
#define __LED_H 			    

#include "stm32f1xx_hal_gpio.h"

#include "stdio.h"	


void LED_INIT(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x);



#endif
