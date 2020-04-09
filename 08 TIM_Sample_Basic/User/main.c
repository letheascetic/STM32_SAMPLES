/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.3
  * @date    2020-01-13
  * @brief   xxxxxxx
  ******************************************************************************
  */ 

#include "stm32f10x.h"   
#include "bsp_led.h"
#include "bsp_tim_basic.h"

volatile uint32_t time = 0; // 5us * time

int main(void)
{
	LED_GPIO_Config();
	
	BASIC_TIM_Init();
	
	while(1)
	{
		if(time >= 20)
		{
			time = 0;
			LED0_OFF;
		}
		else if (time == 1)
		{
			LED0_ON;
		}
	}
}


