#ifndef __USART_H__
#define __USART_H__

#include "stm32f10x.h"

// 串口1 - USART1 (使用APB2总线，不同的USARTx使用不同的APBx总线，查询文档确定)
#define  DEBUG_USARTx                   USART1
#define  DEBUG_USART_CLK                RCC_APB2Periph_USART1
#define  DEBUG_USART_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  DEBUG_USART_BAUDRATE           115200

// USART1 GPIO 引脚定义
#define  DEBUG_USART_GPIO_CLK           RCC_APB2Periph_GPIOA
#define  DEBUG_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd

// USART1 使用PA9/PA10作为TX/RX
#define  DEBUG_USART_TX_GPIO_PORT       GPIOA   
#define  DEBUG_USART_TX_GPIO_PIN        GPIO_Pin_9
#define  DEBUG_USART_RX_GPIO_PORT       GPIOA
#define  DEBUG_USART_RX_GPIO_PIN        GPIO_Pin_10

#define  DEBUG_USART_IRQ                USART1_IRQn
#define  DEBUG_USART_IRQHandler         USART1_IRQHandler

void USART_Config(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif
