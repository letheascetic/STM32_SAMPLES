#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x.h"

// KEY0~KEY3
#define		KEY_GPIO_PORT		GPIOB
#define		KEY_GPIO_CLK		RCC_APB2Periph_GPIOB
#define		KEY0_GPIO_PIN		GPIO_Pin_12
#define		KEY1_GPIO_PIN		GPIO_Pin_13
#define		KEY2_GPIO_PIN		GPIO_Pin_14
#define		KEY3_GPIO_PIN		GPIO_Pin_15
#define		KEY_GPIO_PIN_ALL	(KEY0_GPIO_PIN|KEY1_GPIO_PIN|KEY2_GPIO_PIN|KEY3_GPIO_PIN)

#define KEY_ON 0
#define KEY_OFF 1

void KEY_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif
