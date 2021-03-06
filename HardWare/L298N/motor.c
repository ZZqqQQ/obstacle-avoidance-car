/************************************motor.c***********************************/
/* 每个车轮由两个输出引脚控制，通过让四个车轮向指定方向转动来达到前进，后退和 */
/*                                 转弯的效果                                 */
/*   Each wheel is controlled by two output pins. By turning the four wheels  */
/*    in the specified direction, the forward, backward and turning effects   */
/*                                  are achieved.                             */ 
/*  				电子科技大学嵌入式避障小车一组版权所有                    */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC          */
/******************************************************************************/
#include "L298N.h"
#include "delay.h"
#include "motor.h"
#include "pwm.h"

void LeftTurn_Init(void)//小车左转函数 function of letting vehicle turn left
{    //右轮
	TIM_SetCompare1(TIM3,500);  	        //产生占空比，数越大越慢 generate duty cycle
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	//左轮
	TIM_SetCompare2(TIM3,500);  	        
	 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//右轮
	TIM_SetCompare3(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	//左轮
	TIM_SetCompare4(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}
void RightTurn_Init(void)//小车前进函数
{    //右轮
	TIM_SetCompare1(TIM3,500);  	        //产生占空比，数越大越慢 generate duty cycle
	 GPIO_SetBits(GPIOA,GPIO_Pin_5);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);    //IN2=0
	//左轮
	TIM_SetCompare2(TIM3,500);  	        
	 GPIO_SetBits(GPIOC,GPIO_Pin_14);     //IN3=1
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);    //IN4=0
	//右轮
	TIM_SetCompare3(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	//左轮
	TIM_SetCompare4(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}

void qianjin_Init(void){   
	//右轮
	TIM_SetCompare1(TIM3,660);  	        //产生占空比，数越大越慢 generate duty cycle
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	//左轮
	TIM_SetCompare2(TIM3,690);
	 GPIO_SetBits(GPIOC,GPIO_Pin_14);     //IN3=1                                                               
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);    //IN4=0
	//右轮
	TIM_SetCompare3(TIM3,690);
	 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	//左轮
	TIM_SetCompare4(TIM3,660);
	 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}

void RollBack_Init(){
	TIM_SetCompare1(TIM3,400);					//产生占空比，数越大越慢 generate duty cycle
	GPIO_SetBits(GPIOA,GPIO_Pin_5);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);    //IN2=0
	//左轮
	TIM_SetCompare2(TIM3,400);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1                                                               
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//右轮
	TIM_SetCompare3(TIM3,400);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	//左轮
	TIM_SetCompare4(TIM3,400);
	GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}

void Rotate_Init(void){
	TIM_SetCompare1(TIM3,600);  	        //产生占空比，数越大越慢
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	//左轮
	TIM_SetCompare2(TIM3,600);  	        //产生占空比，数越大越慢
	 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1                                                               
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//右轮
	TIM_SetCompare3(TIM3,600);  	        //产生占空比，数越大越慢
	 GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	//左轮
	TIM_SetCompare4(TIM3,600);  	        //产生占空比，数越大越慢
	 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}
