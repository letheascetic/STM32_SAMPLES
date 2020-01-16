/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  ascetic
  * @version V0.2
  * @date    2019-12-22
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  */
  
#include "bsp_led.h"   

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd(LED0_GPIO_CLK | LED1_GPIO_CLK | LED2_GPIO_CLK, ENABLE);
	
		/*********************************LED0**********************************************/
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED0_GPIO_PIN;	
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED0_GPIO_PORT, &GPIO_InitStructure);	
		/*********************************LED1&LED2**********************************************/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);	
		
		/* �ر�����led��	*/
		GPIO_SetBits(LED0_GPIO_PORT, LED0_GPIO_PIN);
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}

/*********************************************END OF FILE**********************/
