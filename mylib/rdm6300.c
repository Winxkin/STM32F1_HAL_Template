#include "rdm6300.h"

const uint8_t BUFFER_SIZE = 14; 
const uint8_t DATA_SIZE = 10; // 10byte data (2byte version + 8byte tag)
const uint8_t DATA_VERSION_SIZE = 2; // 2byte version (actual meaning of these two bytes 
const uint8_t DATA_TAG_SIZE = 8; // 8byte tag
const uint8_t CHECKSUM_SIZE = 2; // 2byte checksum




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

uint64_t RDM6300_hex_to_value(uint8_t *str, unsigned int length)
{
		uint8_t *copy = malloc((sizeof(char) * length) + 1); 
		memcpy(copy, str, sizeof(char) * length);
		copy[length] = '\0'; 
		long value = strtol(copy, NULL, 16);
		 free(copy);
	return value;

}




uint64_t RDM6300_get_id(uint8_t *strdata, uint8_t *msg_head, uint8_t *msg_tail)
{
  *msg_head = strdata[0];
  uint8_t *msg_data = strdata+ 1; // 10 byte => data contains 2byte version + 8byte tag

 // uint8_t *msg_data_version = msg_data;
  uint8_t *msg_data_tag = msg_data + 2;
  uint8_t *msg_checksum = strdata + 11; // 2 byte
  *msg_tail = strdata[13];
	
	uint64_t tag = RDM6300_hex_to_value(msg_data_tag, DATA_TAG_SIZE);
	
	 long checksum = 0;
	for (int i = 0; i < DATA_SIZE; i+= CHECKSUM_SIZE) {
      long val = RDM6300_hex_to_value(msg_data + i, CHECKSUM_SIZE);
      checksum ^= val;
	}
	if (checksum == RDM6300_hex_to_value(msg_checksum, CHECKSUM_SIZE)) { 
      return tag;
	} else {
      return 0;
	}
	return tag;
}

void RDM6300_convert_tag(uint8_t *tagarray, uint64_t tag )
{

	  tagarray[0] = tag >> 8*0;
    tagarray[1] = tag >> 8*1;
    tagarray[2] = tag >> 8*2;
    tagarray[3] = tag >> 8*3;
    tagarray[4] = tag >> 8*4;
    tagarray[5] = tag >> 8*5;
    tagarray[6] = tag >> 8*6;
    tagarray[7] = tag >> 8*7;

}


