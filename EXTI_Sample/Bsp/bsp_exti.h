
#ifndef __BSP_EXTI_H__
#define __BSP_EXTI_H__

#include "stm32f10x.h"

//Òý½Å¶¨Òå
#define KEY_INT_GPIO_PORT		   GPIOB
#define KEY_INT_GPIO_CLK           (RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO)
#define KEY_INT_EXTI_PORTSOURCE    GPIO_PortSourceGPIOB

#define KEY0_INT_GPIO_PIN          GPIO_Pin_12
#define KEY1_INT_GPIO_PIN          GPIO_Pin_13
#define KEY2_INT_GPIO_PIN          GPIO_Pin_14
#define KEY3_INT_GPIO_PIN          GPIO_Pin_15
#define KEY_INT_GPIO_PIN_ALL	   (KEY0_INT_GPIO_PIN | KEY1_INT_GPIO_PIN | KEY2_INT_GPIO_PIN | KEY3_INT_GPIO_PIN)

#define KEY0_INT_EXTI_PINSOURCE    GPIO_PinSource12
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource13
#define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource14
#define KEY3_INT_EXTI_PINSOURCE    GPIO_PinSource15

#define KEY0_INT_EXTI_LINE         EXTI_Line12
#define KEY1_INT_EXTI_LINE         EXTI_Line13
#define KEY2_INT_EXTI_LINE         EXTI_Line14
#define KEY3_INT_EXTI_LINE         EXTI_Line15

#define KEY_INT_EXTI_IRQ           EXTI15_10_IRQn


void EXTI_Key_Config(void);

#endif

