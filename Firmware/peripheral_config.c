#include "peripheral_config.h"

/**
 * \fn 		void Config_GPIO(void)
 * \brief 	Configure used digital outputs and inputs
 * \param	None
 * \return	None
 */
void GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	/* LEDs as output */
	RCC_AHBPeriphClockCmd(LED_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = LED_PIN ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);

	GPIO_SetBits(LED_GPIO_PORT,LED_PIN);

}

/**
 * \fn 		void Config_uart(BaudRate_TypeDef BaudRate)
 * \brief 	Configure UART1 peripheral
 * \return	None
 */
void UART_Config(void)
{
//	USART_InitTypeDef USART_InitStructure;
//	GPIO_InitTypeDef GPIO_InitStructure;
//
//	/* Enable UART1 TX GPIO clock */
//	RCC_AHB1PeriphClockCmd(U1_GPIO_CLK, ENABLE);
//	/* Enable USART1 clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//
//	/* Connect USART1 to AF*/
//	GPIO_PinAFConfig(U1TX_GPIO_PORT, U1TX_SOURCE, GPIO_AF_USART1);
//	GPIO_PinAFConfig(U1RX_GPIO_PORT, U1RX_SOURCE, GPIO_AF_USART1);
//
//	/* Configure USART Tx as alternate function push-pull */
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_InitStructure.GPIO_Pin = U1TX_PIN;
//	GPIO_Init(U1TX_GPIO_PORT, &GPIO_InitStructure);
//
//	/* Configure USART Rx as alternate function input */
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStructure.GPIO_Pin = U1RX_PIN;
//	GPIO_Init(U1TX_GPIO_PORT, &GPIO_InitStructure);
//
//	USART_InitStructure.USART_BaudRate = 57600; //90000; /*57600 Hand tuned; to be solved with correct HSE/HSI final values*/
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART1, &USART_InitStructure);
//
//	/* Enable USART */
//	USART_Cmd(USART1, ENABLE);
}

void USART_Puts(char* str)
{
	while(*str)
	{
//		while( !(USART1->SR & 0x00000040) );
//		USART_SendData(USART1, *str);
		*str++;
	}
}
