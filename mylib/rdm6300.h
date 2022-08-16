#ifndef __RDM6300_H
#define __RDM6300_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"
#include "stm32f1xx_hal_uart.h"

typedef enum
{
	UART1 = 1,
	UART2 = 2,
	UART3 = 3,
} UART_num;

typedef void (*uart_callback_t) (void);


void RDM6300_Init(UART_num UARTx,UART_HandleTypeDef *s_UARTHandle);
void RDM6300_set_callback(void *cb);
void RDM6300_get_id(UART_HandleTypeDef *hUART,uint8_t *pData, uint16_t Size);


#endif 