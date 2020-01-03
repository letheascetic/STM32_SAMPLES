
#include "bsp_exti.h"


 /**
  * @brief  ����Ƕ�������жϿ�����NVIC
  * @param  ��
  * @retval ��
  */
static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
  
	/* ����NVICΪ���ȼ���1 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
	/* �����ж�Դ��KEY0~KEY4ʹ��ͬһ���ж�Դ[EXTI15_10_IRQn]������ֻ������һ�� */
	NVIC_InitStructure.NVIC_IRQChannel = KEY_INT_EXTI_IRQ;
	/* ������ռ���ȼ� */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	/* ���������ȼ� */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	/* ʹ���ж�ͨ�� */
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
  
}

 /**
  * @brief  ���� IOΪEXTI�жϿڣ��������ж����ȼ�
  * @param  ��
  * @retval ��
  */
void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	/*��������GPIO�ڵ�ʱ�ӣ�����KEY��ʹ��GPIOB������ֻ������һ��*/
	RCC_APB2PeriphClockCmd(KEY_INT_GPIO_CLK, ENABLE);
												
	/* ���� NVIC �ж�*/
	NVIC_Configuration();
	
	/*--------------------------��ʼ��KEY��Ӧ��GPIO-----------------------------*/
	/* ѡ�񰴼��õ���GPIO */	
	GPIO_InitStructure.GPIO_Pin = KEY_INT_GPIO_PIN_ALL;
	/* ����Ϊ�������� */	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY_INT_GPIO_PORT, &GPIO_InitStructure);
	
	/*--------------------------��ʼ��KEY0��Ӧ��EXTI-----------------------------*/
	/* ѡ��EXTI���ź�Դ */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY0_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY0_INT_EXTI_LINE;
	/* EXTIΪ�ж�ģʽ */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* �������ж� */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	/* ʹ���ж� */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/*--------------------------��ʼ��KEY1��Ӧ��EXTI-----------------------------*/
	/* ѡ��EXTI���ź�Դ */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
	/* EXTIΪ�ж�ģʽ */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* �½����ж� */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	/* ʹ���ж� */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/*--------------------------��ʼ��KEY2��Ӧ��EXTI-----------------------------*/
	/* ѡ��EXTI���ź�Դ */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY2_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
	/* EXTIΪ�ж�ģʽ */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* �½����ж� */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	/* ʹ���ж� */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/*--------------------------��ʼ��KEY3��Ӧ��EXTI-----------------------------*/
	/* ѡ��EXTI���ź�Դ */
	GPIO_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE, KEY3_INT_EXTI_PINSOURCE); 
	EXTI_InitStructure.EXTI_Line = KEY3_INT_EXTI_LINE;
	/* EXTIΪ�ж�ģʽ */
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* �½����ж� */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	/* ʹ���ж� */	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}


