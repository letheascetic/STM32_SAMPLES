/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.2
  * @date    2020-01-19
  * @brief   按键测试（中断模式/EXTI模式）
  ******************************************************************************
  */ 

#include "stm32f10x.h" 
#include "bsp_led.h"
#include "bsp_exti.h" 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */ 
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();

	/* 初始化EXTI中断，按下按键会触发中断，
     *  触发中断会进入stm32f4xx_it.c文件中的函数EXTI15_10_IRQHandler处理中断，反转LED灯
	*/
	EXTI_Key_Config(); 

	/* 等待中断，由于使用中断方式，CPU不用轮询按键 */
	while(1);
}


