#include "LED.h"


void LED_INIT(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{   
		GPIO_InitTypeDef  GPIO_InitStructure;
      

//	if (GPIOx == GPIOA) {
//		// Enable clock for GPIOA
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

//	} else if (GPIOx == GPIOB) {
//		// Enable clock for GPIOB
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

//	} else if (GPIOx == GPIOC) {
//		// Enable clock for GPIOC
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

//	}else if (GPIOx == GPIOD) {
//		// Enable clock for GPIOD
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

//	}else if (GPIOx == GPIOE) {
//		// Enable clock for GPIOE
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

//	}else if (GPIOx == GPIOF) {
//		// Enable clock for GPIOF
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);

//	}else if (GPIOx == GPIOG) {
//		// Enable clock for GPIOG
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);

//	}
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x;			    
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  HAL_GPIO_Init(GPIOx, &GPIO_InitStructure);			    
        
} 


