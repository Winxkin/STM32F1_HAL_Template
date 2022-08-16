#include "rdm6300.h"

uart_callback_t uart_callback = NULL;




void RDM6300_Init(UART_num UARTx,UART_HandleTypeDef *s_UARTHandle)
{
	GPIO_InitTypeDef GPIO_InitStructure;
		
	if(UARTx == UART1)
	{
		__USART1_CLK_ENABLE();
		__GPIOA_CLK_ENABLE();
		GPIO_InitStructure.Pin = GPIO_PIN_9;
	  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	  GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		GPIO_InitStructure.Pin = GPIO_PIN_10;
	  GPIO_InitStructure.Mode = GPIO_MODE_AF_OD;
		HAL_GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		s_UARTHandle->Instance = USART1;
	}
	else if(UARTx == UART2)
	{
		__USART2_CLK_ENABLE();
		__GPIOA_CLK_ENABLE();
		GPIO_InitStructure.Pin = GPIO_PIN_2;
	  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	  GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		GPIO_InitStructure.Pin = GPIO_PIN_3;
	  GPIO_InitStructure.Mode = GPIO_MODE_AF_OD;
		HAL_GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		s_UARTHandle->Instance = USART2;
	
	}
	else if(UARTx == UART3)
	{
		__USART3_CLK_ENABLE();
		__GPIOB_CLK_ENABLE();
		GPIO_InitStructure.Pin = GPIO_PIN_10;
	  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	  GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		GPIO_InitStructure.Pin = GPIO_PIN_11;
	  GPIO_InitStructure.Mode = GPIO_MODE_AF_OD;
		HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		s_UARTHandle->Instance = USART3;
	}
	
	s_UARTHandle->Init.BaudRate = 9600;
	s_UARTHandle->Init.WordLength = UART_WORDLENGTH_8B;
	s_UARTHandle->Init.StopBits = UART_STOPBITS_1;
	s_UARTHandle->Init.Parity = UART_PARITY_NONE;
	s_UARTHandle->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	s_UARTHandle->Init.Mode = UART_MODE_TX_RX;

	
	HAL_UART_Init(s_UARTHandle);
  
}


void RDM6300_get_id(UART_HandleTypeDef *hUART,uint8_t *pData, uint16_t Size)
{
	HAL_UART_Receive_IT(hUART,pData,Size);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uart_callback();
}



void RDM6300_set_callback(void *cb)
{
	uart_callback = cb;
}