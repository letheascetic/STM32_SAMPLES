/**
  ******************************************************************************
  * @file    main.c
  * @author  ascetic
  * @version V0.1
  * @date    2020-02-10
  * @brief   DMA传输测试
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma.h"


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	uint8_t TransferStatus;

	LED_GPIO_Config();
	LED0_ON;
	
	Delay(0xFFFFFF);  
	DMA_Config(); 
  
	while(DMA_GetFlagStatus(DMA_FLAG_TC)==RESET);
 
	TransferStatus=Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);
	if(TransferStatus==0)  
	{
		LED0_OFF;
		// LED1_ON;
	}
	else
	{ 
		LED0_OFF;
		LED2_ON;
	}

	while (1);
}
/*********************************************END OF FILE**********************/
