/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.2
  * @date    2019-12-22
  * @brief   测试led
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
