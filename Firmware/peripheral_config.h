#ifndef __PERIPHERAL_CONFIG_H
#define __PERIPHERAL_CONFIG_H

#include "stm32f0xx.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_usart.h"
#include "stm32f0xx_misc.h"

/* LED */
#define LED_PIN			GPIO_Pin_6
#define LED_GPIO_PORT	GPIOB
#define LED_GPIO_CLK	RCC_AHBPeriph_GPIOB


/* UART */
#define U1TX_GPIO_PORT 	GPIOA
#define U1TX_PIN 		GPIO_Pin_3
#define U1TX_SOURCE 	GPIO_PinSource3
#define U1RX_GPIO_PORT 	GPIOA
#define U1RX_PIN 		GPIO_Pin_2
#define U1RX_SOURCE 	GPIO_PinSource2
#define U1_GPIO_CLK		RCC_AHBPeriph_GPIOA



void GPIO_Config(void);
void UART_Config(void);
void USART_Puts(char* str);
void SPI_Config(void);

#endif	/* End of __PERIPHERAL_CONFIG_H */
