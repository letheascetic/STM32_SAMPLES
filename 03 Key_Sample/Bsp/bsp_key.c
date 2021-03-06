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
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
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
* @brief 妫�娴嬫槸鍚︽湁鎸夐敭鎸変笅
* @param GPIOx:鍏蜂綋鐨勭鍙�, x 鍙互鏄紙A...G锛�
* @param GPIO_PIN:鍏蜂綋鐨勭鍙ｄ綅锛� 鍙互鏄� GPIO_PIN_x锛坸 鍙互鏄� 0...15锛�
* @retval 鎸夐敭鐨勭姸鎬�
* @arg KEY_ON:鎸夐敭鎸変笅
* @arg KEY_OFF:鎸夐敭娌℃寜涓�
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

