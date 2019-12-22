#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* ����LED���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED���� */

// LED0~LED7
#define LED_GPIO_PORT		GPIOC
#define LED_GPIO_CLK 		RCC_APB2Periph_GPIOC
#define LED0_GPIO_PIN		GPIO_Pin_0			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED1_GPIO_PIN		GPIO_Pin_1			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED2_GPIO_PIN		GPIO_Pin_2			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED3_GPIO_PIN		GPIO_Pin_3			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED4_GPIO_PIN		GPIO_Pin_4			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED5_GPIO_PIN		GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED6_GPIO_PIN		GPIO_Pin_6			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED7_GPIO_PIN		GPIO_Pin_7			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LED_GPIO_PIN_ALL    (LED0_GPIO_PIN|LED1_GPIO_PIN|LED2_GPIO_PIN|LED3_GPIO_PIN\
							|LED4_GPIO_PIN|LED5_GPIO_PIN|LED6_GPIO_PIN|LED7_GPIO_PIN)


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* ʹ�ñ�׼�Ĺ̼������IO*/
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
