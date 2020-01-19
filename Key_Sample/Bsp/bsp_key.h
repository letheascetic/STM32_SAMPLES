#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x.h"

// KEY0
#define		KEY0_GPIO_CLK			RCC_APB2Periph_GPIOA
#define		KEY0_GPIO_PORT		GPIOA
#define		KEY0_GPIO_PIN			GPIO_Pin_0

#define		KEY1_GPIO_CLK			RCC_APB2Periph_GPIOC
#define		KEY1_GPIO_PORT		GPIOC
#define		KEY1_GPIO_PIN			GPIO_Pin_13

#define KEY_ON 0
#define KEY_OFF 1

void KEY_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif
