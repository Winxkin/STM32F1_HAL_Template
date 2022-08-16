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




void RDM6300_Init(UART_num UARTx,UART_HandleTypeDef *s_UARTHandle);
uint64_t RDM6300_get_id(uint8_t *strdata, uint8_t *msg_head, uint8_t *msg_tail);
void RDM6300_convert_tag(uint8_t *tagarray, uint64_t tag );


#endif 