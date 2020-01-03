
#include "bsp_exti.h"


 /**
  * @brief  配置嵌套向量中断控制器NVIC
  * @param  无
  * @retval 无
  */
static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
  
	/* 配置NVIC为优先级组1 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
	/* 配置中断源：KEY0~KEY4使用同一个中断源[EXTI15_10_IRQn]，所以只需配置一次 */
	NVIC_InitStructure.NVIC_IRQChannel = KEY_INT_EXTI_IRQ;
	/* 配置抢占优先级 */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	/* 配置子优先级 */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	/* 使能中断通道 */
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
  
}

 /**
  * @brief  配置 IO为EXTI中断口，并设置中断优先级
  * @param  无
  * @retval 无
  */
void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	/*开启按键GPIO口的时钟，所有KEY都使用GPIOB，所以只需配置一次*/
	RCC_APB2PeriphClockCmd(KEY_INT_GPIO_CLK, ENABLE);
												
	/* 配置 NVIC 中断*/
	NVIC_Configuration();
	
	/*--------------------------初始化KEY对应的GPIO-----------------------------*/
	/* 选择按键用到的GPIO */	
	GPIO_InitStructure.GPIO_Pin = KEY_INT_GPIO_PIN_ALL;
	/* 配置为浮空输入 */	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY_INT_GPIO_PORT, &GPIO_InitStructure);
	
	/*--------------------------初始化KEY0对应的EXTI-----------------------------*/
	/* 选择EXTI的信号源 */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY0_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY0_INT_EXTI_LINE;
	/* EXTI为中断模式 */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* 上升沿中断 */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	/* 使能中断 */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/*--------------------------初始化KEY1对应的EXTI-----------------------------*/
	/* 选择EXTI的信号源 */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
	/* EXTI为中断模式 */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* 下降沿中断 */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	/* 使能中断 */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/*--------------------------初始化KEY2对应的EXTI-----------------------------*/
	/* 选择EXTI的信号源 */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY2_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
	/* EXTI为中断模式 */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* 下降沿中断 */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	/* 使能中断 */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/*--------------------------初始化KEY3对应的EXTI-----------------------------*/
	/* 选择EXTI的信号源 */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY3_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY3_INT_EXTI_LINE;
	/* EXTI为中断模式 */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* 下降沿中断 */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	/* 使能中断 */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}


