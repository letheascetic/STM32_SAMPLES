#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */

// LED0~LED7
#define LED_GPIO_PORT		GPIOC
#define LED_GPIO_CLK 		RCC_APB2Periph_GPIOC
#define LED0_GPIO_PIN		GPIO_Pin_0			        /* 连接到SCL时钟线的GPIO */
#define LED1_GPIO_PIN		GPIO_Pin_1			        /* 连接到SCL时钟线的GPIO */
#define LED2_GPIO_PIN		GPIO_Pin_2			        /* 连接到SCL时钟线的GPIO */
#define LED3_GPIO_PIN		GPIO_Pin_3			        /* 连接到SCL时钟线的GPIO */
#define LED4_GPIO_PIN		GPIO_Pin_4			        /* 连接到SCL时钟线的GPIO */
#define LED5_GPIO_PIN		GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */
#define LED6_GPIO_PIN		GPIO_Pin_6			        /* 连接到SCL时钟线的GPIO */
#define LED7_GPIO_PIN		GPIO_Pin_7			        /* 连接到SCL时钟线的GPIO */
#define LED_GPIO_PIN_ALL    (LED0_GPIO_PIN|LED1_GPIO_PIN|LED2_GPIO_PIN|LED3_GPIO_PIN\
							|LED4_GPIO_PIN|LED5_GPIO_PIN|LED6_GPIO_PIN|LED7_GPIO_PIN)


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* 使用标准的固件库控制IO*/
#define LED0(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED0_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED0_GPIO_PIN)
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED1_GPIO_PIN)
#define LED2(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED2_GPIO_PIN)
#define LED3(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED3_GPIO_PIN)
#define LED4(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED4_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED4_GPIO_PIN)
#define LED5(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED5_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED5_GPIO_PIN)
#define LED6(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED6_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED6_GPIO_PIN)
#define LED7(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED7_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED7_GPIO_PIN)

void LED_GPIO_Config(void);

#endif /* __LED_H */
