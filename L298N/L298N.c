#include "L298N.h"

void L298N_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;                 //����GPIO��ʼ���ṹ��
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE); //ʹ��APB2ʱ��������PA�˿�ʱ��	
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	                  
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_12; //PA12��PA12�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //�����趨������ʼ��PA11|PA12
 GPIO_SetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_12);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_15;//PA3�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //�����趨������ʼ��PA3|PA4
 GPIO_ResetBits(GPIOA,GPIO_Pin_11|GPIO_Pin_15);

}
