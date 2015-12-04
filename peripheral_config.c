#include "peripheral_config.h"

/**
 * \fn 		void Clock_Config(void)
 * \brief 	Configure clocks
 * \param	None
 * \return	None
 */
void Clock_Config(void)
{
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_OFF);
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
	RCC_HSICmd(ENABLE);
	//RCC_AdjustHSICalibrationValue(16);
	RCC_PLLCmd(DISABLE);

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	SysTick_Config(HSI_VALUE/1000);
}


/**
 * \fn 		void GPIO_Config(void)
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

	/* PWRKEY as output */
	RCC_AHBPeriphClockCmd(PWRKEY_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = PWRKEY_PIN ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(PWRKEY_GPIO_PORT, &GPIO_InitStructure);

	GPIO_ResetBits(PWRKEY_GPIO_PORT,PWRKEY_PIN);

}

/**
 * \fn 		void Config_uart(BaudRate_TypeDef BaudRate)
 * \brief 	Configure UART1 peripheral
 * \return	None
 */
void UART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Enable UART1 TX GPIO clock */
	RCC_AHBPeriphClockCmd(U1_GPIO_CLK, ENABLE);

	/* Enable USART1 clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* Connect USART1 to AF*/
	GPIO_PinAFConfig(U1TX_GPIO_PORT, U1TX_SOURCE, GPIO_AF_1);
	GPIO_PinAFConfig(U1RX_GPIO_PORT, U1RX_SOURCE, GPIO_AF_1);

	/* Configure USART Tx & Rx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = U1TX_PIN|U1RX_PIN;
	GPIO_Init(U1TX_GPIO_PORT, &GPIO_InitStructure);

	/* Enable USART1 IRQ */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);

	/* Enable USART */
	USART_Cmd(USART1, ENABLE);

	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_ITConfig(USART1,USART_IT_TXE,DISABLE);

}

void USART_Puts(char* str)
{
	while(*str)
	{
		while( USART_GetFlagStatus(USART1,USART_FLAG_TXE)==0 );

		USART_SendData(USART1, *str);
		*str++;
	}
}


