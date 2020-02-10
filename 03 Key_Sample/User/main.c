/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.2
  * @date    2019-12-22
  * @brief   
  ******************************************************************************
  */ 

#include "stm32f10x.h"
#include "bsp_key.h"
#include "bsp_led.h"

int main(void)
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	while(1)
	{
		if (Key_Scan(KEY0_GPIO_PORT, KEY0_GPIO_PIN) == KEY_ON)
		{
			LED0_TOGGLE;
		}

		if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
		{
			LED1_TOGGLE;
		}	
	}
}


