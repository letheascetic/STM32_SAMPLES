
#include "bsp_tim_basic.h"

// 中断优先级设置
static void BASIC_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // 设置中断组为0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
	// 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ ;	
	// 主优先级0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	// 抢占优先级3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


static void BASIC_TIM_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		
	// 开启定时器时钟，即内部时钟CK_INT=72M
    BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);
	
	// 自动重装载寄存器的值，累计TIM_PERIOD+1个频率后产生一个更新或中断
    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;	

	// 时钟预分频数
    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM_Prescaler;
	
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	// 初始化
    TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);
	
    TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);
	
    TIM_ITConfig(BASIC_TIM, TIM_IT_Update,ENABLE);

    TIM_Cmd(BASIC_TIM, ENABLE);	
}

void BASIC_TIM_Init(void)
{
	BASIC_TIM_NVIC_Config();
	BASIC_TIM_Mode_Config();
}
