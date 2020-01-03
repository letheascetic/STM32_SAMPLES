/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.1
  * @date    2020-01-03
  * @brief   �������ԣ��ж�ģʽ/EXTIģʽ��
  ******************************************************************************
  */ 

#include "stm32f10x.h" 
#include "bsp_led.h"
#include "bsp_exti.h" 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */ 
int main(void)
{
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();

	/* ��ʼ��EXTI�жϣ����°����ᴥ���жϣ�
    *  �����жϻ����stm32f4xx_it.c�ļ��еĺ���EXTI15_10_IRQHandler�����жϣ���תLED��
	*/
	EXTI_Key_Config(); 

	/* �ȴ��жϣ�����ʹ���жϷ�ʽ��CPU������ѯ���� */
	while(1);
}


