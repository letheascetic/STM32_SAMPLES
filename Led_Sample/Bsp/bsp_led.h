#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */

// LED0
#define LED0_GPIO_PORT		GPIOB
#define LED0_GPIO_CLK 		RCC_APB2Periph_GPIOB
#define LED0_GPIO_PIN		  GPIO_Pin_5

// LED1
#define LED1_GPIO_PORT		GPIOB
#define LED1_GPIO_CLK 		RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN			GPIO_Pin_0

// LED2
#define LED2_GPIO_PORT		GPIOB
#define LED2_GPIO_CLK 		RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN			GPIO_Pin_1

#define LED_GPIO_PIN_ALL    (LED0_GPIO_PIN|LED1_GPIO_PIN|LED2_GPIO_PIN)


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* 使用标准的固件库控制IO*/
#define LED0(a)	if (a)	\
					GPIO_SetBits(LED0_GPIO_PORT,LED0_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED0_GPIO_PORT,LED0_GPIO_PIN)
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

void LED_GPIO_Config(void);

#endif /* __LED_H */
