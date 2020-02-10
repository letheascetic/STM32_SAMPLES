#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"

// LED0
#define LED0_GPIO_PORT		GPIOB
#define LED0_GPIO_CLK 		RCC_APB2Periph_GPIOB
#define LED0_GPIO_PIN			GPIO_Pin_5

// LED1
#define LED1_GPIO_PORT		GPIOB
#define LED1_GPIO_CLK 		RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN			GPIO_Pin_0

// LED2
#define LED2_GPIO_PORT		GPIOB
#define LED2_GPIO_CLK 		RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN			GPIO_Pin_1

#define LED_GPIO_PIN_ALL    (LED0_GPIO_PIN|LED1_GPIO_PIN|LED2_GPIO_PIN)

#define digitalHi(p,i) {p->BSRR=i;} 			//输出高电平
#define digitalLo(p,i) {p->BRR=i;} 				//输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} 	//输出反转状态

#define LED0_TOGGLE digitalToggle(LED0_GPIO_PORT,LED0_GPIO_PIN)
#define LED0_OFF digitalHi(LED0_GPIO_PORT,LED0_GPIO_PIN)
#define LED0_ON digitalLo(LED0_GPIO_PORT,LED0_GPIO_PIN)

#define LED1_TOGGLE digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_TOGGLE digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1


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
