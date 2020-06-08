#include "bsp.h"

void TIM2_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;                         //����GPIO��ʼ���ṹ��
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;              //������ʱ����ʼ���ṹ��
	TIM_OCInitTypeDef  TIM_OCInitStructure;                      //������ʱ������Ƚϳ�ʼ���ṹ��
  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);         //ʹ�ܶ�ʱ��3
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);        //ʹ��GPIO����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);                                
	                                                                     	
  aaaaaaaaaaaaaa
  /*���ø�����Ϊ�����������,���TIM_CH2|TIM_CH3��PWM���岨��*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              //�����֪�������������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;         //TIM3_CH3|TIM3_CH4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);                       //�����趨������ʼ��PA7
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
  
	TIM_TimeBaseStructure.TIM_Period = arr;                      //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc;                    //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;                 //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);              //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
   
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;            //ѡ��ʱ��ģʽ:TIM������ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;                           //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);                     //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIM3
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  
	                          	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH3Ԥװ��ʹ��	 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH3Ԥװ��ʹ��	 
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH3Ԥװ��ʹ��	 
	TIM_OC4PreloadConfig(TIM3, TIM_TRGOSource_Enable);         //CH4Ԥװ��ʹ��
  
  TIM_ARRPreloadConfig(TIM3, ENABLE);                          //ʹ��TIM3��ARR�ϵ�Ԥװ�ؼĴ���	
	TIM_CtrlPWMOutputs(TIM3,ENABLE);                             //MOE �����ʹ��
	TIM_Cmd(TIM3, ENABLE);                                       //ʹ��TIM3
	
	
}

