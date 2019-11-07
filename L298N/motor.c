#include "L298N.h"
#include "delay.h"
#include "motor.h"
#include "pwm.h"

void RightTurn_Init(void)//С����ת����
{    //����
	   TIM_SetCompare1(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	   //����
	   TIM_SetCompare2(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOC,GPIO_Pin_14);     //IN3=1
	   GPIO_ResetBits(GPIOC,GPIO_Pin_13);    //IN4=0
	//����
	   TIM_SetCompare3(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	   //����
	   TIM_SetCompare4(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}
void LeftTurn_Init(void)
{    //����
	   TIM_SetCompare1(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_5);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_4);    //IN2=0
	   //����
	   TIM_SetCompare2(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1
	   GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//����
	   TIM_SetCompare3(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	   //����
	   TIM_SetCompare4(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}

void qianjin_Init(void)//С��ǰ������
{    //����
	   TIM_SetCompare1(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	   //����
	   TIM_SetCompare2(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1
	   GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//����
	   TIM_SetCompare3(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	   //����
	   TIM_SetCompare4(TIM3,700);  	        //����ռ�ձȣ���Խ��Խ��
		 GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}
