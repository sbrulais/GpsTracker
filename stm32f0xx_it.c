#include "stm32f0xx_it.h"
#include "stm32f0xx_usart.h"
#include "peripheral_config.h"

uint8_t RxBuffer[512]={0};
uint16_t RxCount=0;

/******************************************************************************/
/*                 STM32F0xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f0xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles USART1 global interrupt request.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{
	static int toggle=0;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		/* Read one byte from the receive data register */
		RxBuffer[RxCount++] = USART_ReceiveData(USART1);

		if(toggle!=0)
		{
			toggle=1;
			GPIO_ResetBits(LED_GPIO_PORT,LED_PIN);
		}
		else
		{
			toggle=0;
			GPIO_SetBits(LED_GPIO_PORT,LED_PIN);
		}

		if(RxCount>5)
		{
			RxCount=0;
		}

	}
	//USART_ClearITPendingBit(USART1,USART_IT_RXNE);

	if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)
	{
//		/* Write one byte to the transmit data register */
//		USART_SendData(USART1, TxBuffer[TxCount++]);
//
//		if(TxCount == NbrOfDataToTransfer)
//		{
//		  /* Disable the USART1 Transmit interrupt */
//		  USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
//		}
	}

	if(USART_GetITStatus(USART1, USART_IT_CM) != RESET)
	{

	}

	if(USART_GetITStatus(USART1, USART_IT_CTS) != RESET)
	{

	}

	if(USART_GetITStatus(USART1, USART_IT_EOB) != RESET)
	{

	}
	if(USART_GetITStatus(USART1, USART_IT_ERR) != RESET)
	{

	}

	if(USART_GetITStatus(USART1, USART_IT_FE) != RESET)
	{

	}

	if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)
	{

	}
}

/**
  * @brief  This function handles EXTI0_IRQ Handler.
  * @param  None
  * @retval None
  */
void EXTI0_1_IRQHandler(void)
{
//    if(EXTI_GetITStatus(USER_BUTTON_EXTI_LINE) != RESET)
//    {
//
//        /* Clear the EXTI line pending bit */
//        EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
//    }
}

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	static uint32_t i=0;
	char str[]={"AT+GMM=?\n"};
	if(i++>900)
	{

		if (i>=1000)
		{
			i=0;
			USART_Puts(str);
			//RxCount=0;
		}
	}else
	{
		//GPIO_ResetBits(LED_GPIO_PORT,LED_PIN);
	}
}

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}


