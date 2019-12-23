/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  ascetic
  * @version V0.2
  * @date    2019-12-22
  * @brief   key api
  ******************************************************************************
  */ 


#include "bsp_key.h"

#define SOFT_DELAY Delay(0x00FFFF);

void Delay(__IO u32 nCount); 

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = KEY_GPIO_PIN_ALL;
	
	// ���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStructure);
}

/**
* @brief ����Ƿ��а�������
* @param GPIOx:����Ķ˿�, x �����ǣ�A...G��
* @param GPIO_PIN:����Ķ˿�λ�� ������ GPIO_PIN_x��x ������ 0...15��
* @retval ������״̬
* @arg KEY_ON:��������
* @arg KEY_OFF:����û����
*/
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t key_status = KEY_OFF;
	if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {

		SOFT_DELAY;
		if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
		{
			key_status = KEY_ON;
			while (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
		}
		return key_status;
	} else
		return key_status;
}

void Delay(__IO uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

