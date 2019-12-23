/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.2
  * @date    2019-12-22
  * @brief   ≤‚ ‘key
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
		if (Key_Scan(KEY_GPIO_PORT, KEY0_GPIO_PIN) == KEY_ON)
		{
			LED_Toggle(LED_GPIO_PORT, LED0_GPIO_PIN);
		}
//		if (Key_Scan(KEY_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
//		{
//			LED_Toggle(LED_GPIO_PORT, LED1_GPIO_PIN);
//		}
//		if (Key_Scan(KEY_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON)
//		{
//			LED_Toggle(LED_GPIO_PORT, LED2_GPIO_PIN);
//		}
//		if (Key_Scan(KEY_GPIO_PORT, KEY3_GPIO_PIN) == KEY_ON)
//		{
//			LED_Toggle(LED_GPIO_PORT, LED3_GPIO_PIN);
//		}
	}
}


