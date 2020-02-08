/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.1
  * @date    2020-01-19
  * @brief   Systick系统时钟测试
  ******************************************************************************
  */ 

#include "stm32f10x.h"   
#include "bsp_led.h"
#include "bsp_systick.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */ 
int main(void)
{
	LED_GPIO_Config();
	
	/* 配置SysTick 为10us中断一次 */
	SysTick_Init();
	
	while (1) {
		LED0( ON ); 
	    Delay_us(100000);    	// 100000 * 10us = 1000ms
		LED0( OFF );
	  
		LED1( ON );
	    Delay_us(100000);		// 100000 * 10us = 1000ms
		LED1( OFF );
	
		LED2( ON );
	    Delay_us(100000);		// 100000 * 10us = 1000ms
		LED2( OFF );
	}
	
}


