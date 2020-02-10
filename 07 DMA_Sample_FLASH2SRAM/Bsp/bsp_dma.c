/**
  ******************************************************************************
  * @file    bsp_dma.c
  * @author  ascetic
  * @version V0.1
  * @date    2020-02-10
  * @brief   
  ******************************************************************************
  */ 
	
#include "bsp_dma.h"

void Delay(__IO uint32_t nCount)	 //¼òµ¥µÄÑÓÊ±º¯Êý
{
	for(; nCount != 0; nCount--);
}

void DMA_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	
	// 开启DMA时钟
	RCC_AHBPeriphClockCmd(DMA_CLOCK, ENABLE);
	// 源数据地址
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)aSRC_Const_Buffer;
	// 目标地址
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)aDST_Buffer;
	// 传输方向：Flash到SRAM
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	// 数据量大小
	DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;
	// 外设（Flash）地址递增开启  
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	// 目标（SRAM）地址递增开启
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	// 外设传输数据单位
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	// 内存传输数据单位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;	 
	// 传输模式：一次或循环
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal ;
	//DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;  
	// 优先级
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	// 存储器到存储器传输使能
	DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;
	// 初始化	   
	DMA_Init(DMA_CHANNEL, &DMA_InitStructure);
    // 清除DMA数据流传输完成标志位
    DMA_ClearFlag(DMA_FLAG_TC);
	// 使能DMA
	DMA_Cmd(DMA_CHANNEL,ENABLE);
}

/**
  * 比较数据
  * 完全相同返回1，不相同返回0
  */
uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength)
{
	while(BufferLength--)
	{
		if(*pBuffer != *pBuffer1)
		{
			return 0;
		}
		pBuffer++;
		pBuffer1++;
	}
	return 1;  
}




