/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.2
  * @date    2019-12-22
  * @brief   ����led
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"

#define SOFT_DELAY Delay(0x3FFFFF);

void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 

	while (1)
	{
		LED2(OFF);
		LED0(ON);
		SOFT_DELAY;
		
		LED0(OFF);
		LED1(ON);
		SOFT_DELAY;
		
		LED1(OFF);
		LED2(ON);
		SOFT_DELAY;	
	}
}

void Delay(__IO uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
