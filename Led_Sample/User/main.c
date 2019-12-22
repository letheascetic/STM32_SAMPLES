/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"

#define SOFT_DELAY Delay(0x0FFFFF);

void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	/* LED 端口初始化 */
	LED_GPIO_Config();	 

	while (1)
	{
		LED7(OFF);
		LED0(ON);
		SOFT_DELAY;
		
		LED0(OFF);
		LED1(ON);
		SOFT_DELAY;
		
		LED1(OFF);
		LED2(ON);
		SOFT_DELAY;

		LED2(OFF);
		LED3(ON);
		SOFT_DELAY;
		
		LED3(OFF);
		LED4(ON);
		SOFT_DELAY;

		LED4(OFF);
		LED5(ON);
		SOFT_DELAY;
		
		LED5(OFF);
		LED6(ON);
		SOFT_DELAY;

		LED6(OFF);
		LED7(ON);
		SOFT_DELAY;		
	}
}

void Delay(__IO uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
