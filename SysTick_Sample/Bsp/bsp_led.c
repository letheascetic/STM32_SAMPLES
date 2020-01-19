/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  ascetic
  * @version V0.2
  * @date    2019-12-22
  * @brief   led应用函数接口
  ******************************************************************************
  */
  
#include "bsp_led.h"   

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd(LED0_GPIO_CLK | LED1_GPIO_CLK | LED2_GPIO_CLK, ENABLE);
	
		/*********************************LED0**********************************************/
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED0_GPIO_PIN;	
		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED0_GPIO_PORT, &GPIO_InitStructure);	
		/*********************************LED1&LED2**********************************************/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);	
		
		/* 关闭所有led灯	*/
		GPIO_SetBits(LED0_GPIO_PORT, LED0_GPIO_PIN);
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}

/*********************************************END OF FILE**********************/
