/************************************BSP.c***********************************/
/*                    ʱ�ӣ�IO���Լ��������������ʼ��                      */
/*           Initialize clock, IO port and some of other peripheral         */
/*  				���ӿƼ���ѧǶ��ʽ����С��һ���Ȩ����                  */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC        */
/****************************************************************************/
#include "bsp.h"

void RCC_Configuration(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_GPIOB  | 
                         RCC_APB2Periph_GPIOC  | RCC_APB2Periph_GPIOD  | 
                         RCC_APB2Periph_GPIOE  | RCC_APB2Periph_GPIOF  | 
                         RCC_APB2Periph_AFIO, ENABLE); //ʹ��APB2ʱ�� enable clock of APB2
}

void GPIO_Basic_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //Ƶ��(50M) frequency(50MHz)
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������(����ʽ���) output type(pull-push output)
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}


//��ʱ��4���� setting of tim4
void hcsr04_NVIC()
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
			
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;             
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;         
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;       
	NVIC_Init(&NVIC_InitStructure);
}

//IO�ڳ�ʼ�� ��������ʼ�� initialization of IO port and other initialization
void Hcsr04Init()
{  
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(HCSR04_CLK, ENABLE);
   
    GPIO_InitStructure.GPIO_Pin =FRONT_HCSR04_TRIG | LEFT_HCSR04_TRIG|RIGHT_HCSR04_TRIG;      
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(HCSR04_PORT, &GPIO_InitStructure);
    GPIO_ResetBits(HCSR04_PORT,FRONT_HCSR04_TRIG | LEFT_HCSR04_TRIG|RIGHT_HCSR04_TRIG);
 
	
	
	  GPIO_InitStructure.GPIO_Pin =   FRONT_HCSR04_ECHO|LEFT_HCSR04_ECHO|RIGHT_HCSR04_ECHO;     
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(HCSR04_PORT, &GPIO_InitStructure);  
    GPIO_ResetBits(HCSR04_PORT,FRONT_HCSR04_ECHO|LEFT_HCSR04_ECHO|RIGHT_HCSR04_ECHO);

          
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);   
     
    TIM_DeInit(TIM2);
    TIM_TimeBaseStructure.TIM_Period = (1000-1); 
    TIM_TimeBaseStructure.TIM_Prescaler =(72-1); 
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);          
        
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);  
    TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);    
    hcsr04_NVIC();
    TIM_Cmd(TIM4,DISABLE);     
}


void L298N1_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;//����GPIO��ʼ���ṹ�� declare of GPIO initialization structure
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE); //ʹ��APB2ʱ��������PA�˿�ʱ�� enable clock PA port under APB2 clock bus
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	                  
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_12; //PA8��PA12�˿����� configure PA8 and PA12
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //������� pull-push output
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//IO���ٶ�Ϊ50MHz set speed of IO port at 50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);	 //�����趨������ʼ��PA11|PA12 configure PA11 and PA12 according to parameter
 //GPIO_SetBits(GPIOA,GPIO_Pin_12|GPIO_Pin_11);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_15; //PA3�˿����� configure PA3
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //������� pull-push output
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO���ٶ�Ϊ50MHz set speed of IO port at 50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure); //�����趨������ʼ��PA3|PA4 configure PA3 and PA4 according to parameter
 //GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_15);

}

void L298N2_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_6;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);
 //GPIO_SetBits(GPIOA,GPIO_Pin_4);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);
 //GPIO_ResetBits(GPIOA,GPIO_Pin_5);                            

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 //GPIO_SetBits(GPIOC,GPIO_Pin_14);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 //GPIO_Rese336tBits(GPIOC,GPIO_Pin_13);
}

void BSP_Initializes(void)
{
	
  RCC_Configuration();
  GPIO_Basic_Configuration();

	NVIC_Configuration();
	uart_init(9600);
	Hcsr04Init();
	L298N1_Init();
	L298N2_Init();
	TIM2_PWM_Init(899, 0);
}
