/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  ascetic
  * @version V0.3
  * @date    2020-01-19
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
	
	RCC_APB2PeriphClockCmd(KEY0_GPIO_CLK | KEY1_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = KEY0_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY0_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
}

/**
* @brief 检测是否有按键按下
* @param GPIOx:具体的端口, x 可以是（A...G）
* @param GPIO_PIN:具体的端口位， 可以是 GPIO_PIN_x（x 可以是 0...15）
* @retval 按键的状态
* @arg KEY_ON:按键按下
* @arg KEY_OFF:按键没按下
*/
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
		while (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
		return KEY_ON;
	} else
		return KEY_OFF;
}

void Delay(__IO uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

