//�쳣����
#include "stm32f10x_it.h"
#include "ucos_ii.h"


//����NMI�쳣
void NMI_Handler(void)
{
}

//����HardFault�쳣
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

//�ڴ�����쳣
void MemManage_Handler(void)
{
  while (1)
  {
  }
}

//���������쳣
void BusFault_Handler(void)
{
  while (1)
  {
  }
}

//����ʹ�ô���
void UsageFault_Handler(void)
{
  while (1)
  {
  }
}


void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}


void SysTick_Handler(void)
{
  OSIntEnter();
  OSTimeTick();
  OSIntExit();
}
