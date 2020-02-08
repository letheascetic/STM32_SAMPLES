
#ifndef __BSP_EXTI_H__
#define __BSP_EXTI_H__

#include "stm32f10x.h"

//引脚定义
#define KEY0_INT_GPIO_PORT		    GPIOA
#define KEY0_INT_GPIO_CLK           (RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO)
#define KEY0_INT_GPIO_PIN           GPIO_Pin_0
#define KEY0_INT_EXTI_PORTSOURCE    GPIO_PortSourceGPIOA
#define KEY0_INT_EXTI_PINSOURCE		GPIO_PinSource0
#define KEY0_INT_EXTI_LINE			EXTI_Line0
#define KEY0_INT_EXTI_IRQ 			EXTI0_IRQn
#define KEY0_IRQHandler 			EXTI0_IRQHandler

#define KEY1_INT_GPIO_PORT		    GPIOC
#define KEY1_INT_GPIO_CLK           (RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO)
#define KEY1_INT_GPIO_PIN           GPIO_Pin_13
#define KEY1_INT_EXTI_PORTSOURCE    GPIO_PortSourceGPIOC
#define KEY1_INT_EXTI_PINSOURCE		GPIO_PinSource13
#define KEY1_INT_EXTI_LINE			EXTI_Line13
#define KEY1_INT_EXTI_IRQ 			EXTI15_10_IRQn
#define KEY1_IRQHandler 			EXTI15_10_IRQHandler

void EXTI_Key_Config(void);

#endif

