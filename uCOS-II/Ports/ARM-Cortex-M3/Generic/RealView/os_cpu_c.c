


#define  OS_CPU_GLOBALS
#include <ucos_ii.h>



#if OS_TMR_EN > 0u
static  INT16U  OSTmrCtr;
#endif


#if 0
#define  OS_CPU_CM3_NVIC_ST_CTRL    (*((volatile INT32U *)0xE000E010uL)) 
#define  OS_CPU_CM3_NVIC_ST_RELOAD  (*((volatile INT32U *)0xE000E014uL)) 
#define  OS_CPU_CM3_NVIC_ST_CURRENT (*((volatile INT32U *)0xE000E018uL)) 
#define  OS_CPU_CM3_NVIC_ST_CAL     (*((volatile INT32U *)0xE000E01CuL)) 
#define  OS_CPU_CM3_NVIC_PRIO_ST    (*((volatile INT8U  *)0xE000ED23uL)) 
#define  OS_CPU_CM3_NVIC_ST_CTRL_COUNT                    0x00010000uL   
#define  OS_CPU_CM3_NVIC_ST_CTRL_CLK_SRC                  0x00000004uL   
#define  OS_CPU_CM3_NVIC_ST_CTRL_INTEN                    0x00000002uL   
#define  OS_CPU_CM3_NVIC_ST_CTRL_ENABLE                   0x00000001uL   
#define  OS_CPU_CM3_NVIC_PRIO_MIN                               0xFFu    
#endif

//OS��ʼ��
#if OS_CPU_HOOKS_EN > 0u
void  OSInitHookBegin (void)
{
    INT32U   size;
    OS_STK  *pstk;

                                                          
    pstk = &OS_CPU_ExceptStk[0];
    size = OS_CPU_EXCEPT_STK_SIZE;
    while (size > 0u) {//���쳣��ջ����
        size--;
       *pstk++ = (OS_STK)0;
    }

    OS_CPU_ExceptStkBase = &OS_CPU_ExceptStk[OS_CPU_EXCEPT_STK_SIZE - 1u];

#if OS_TMR_EN > 0u
    OSTmrCtr = 0u;
#endif
}
#endif


#if OS_CPU_HOOKS_EN > 0u
void  OSInitHookEnd (void)
{
}
#endif

//��������
#if OS_CPU_HOOKS_EN > 0u
void  OSTaskCreateHook (OS_TCB *ptcb)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskCreateHook(ptcb);
#else
    (void)ptcb;                                  
#endif
}
#endif


//ɾ������
#if OS_CPU_HOOKS_EN > 0u
void  OSTaskDelHook (OS_TCB *ptcb)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskDelHook(ptcb);
#else
    (void)ptcb;                                 
#endif
}
#endif

//IDLE����
#if OS_CPU_HOOKS_EN > 0u
void  OSTaskIdleHook (void)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskIdleHook();
#endif
}
#endif

//���񷵻�

#if OS_CPU_HOOKS_EN > 0u
void  OSTaskReturnHook (OS_TCB  *ptcb)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskReturnHook(ptcb);
#else
    (void)ptcb;
#endif
}
#endif

//static����

#if OS_CPU_HOOKS_EN > 0u
void  OSTaskStatHook (void)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskStatHook();
#endif
}
#endif

//��ʼ�������ջ

OS_STK *OSTaskStkInit (void (*task)(void *p_arg), void *p_arg, OS_STK *ptos, INT16U opt)
{
    OS_STK *stk;


    (void)opt;                                   
    stk       = ptos;                            //ջ��ָ��

                                                 
    *(stk)    = (INT32U)0x01000000uL;            //��������Ĵ�����ֵ
    *(--stk)  = (INT32U)task;                    //�������
    *(--stk)  = (INT32U)OS_TaskReturn;           //LR
    *(--stk)  = (INT32U)0x12121212uL;            // R12                                                
    *(--stk)  = (INT32U)0x03030303uL;            // R3                                                 
    *(--stk)  = (INT32U)0x02020202uL;            // R2                                                 
    *(--stk)  = (INT32U)0x01010101uL;            // R1                                                 
    *(--stk)  = (INT32U)p_arg;                   // R0                               

                                                 
    *(--stk)  = (INT32U)0x11111111uL;            // R11                                                
    *(--stk)  = (INT32U)0x10101010uL;            // R10                                                
    *(--stk)  = (INT32U)0x09090909uL;            // R9                                                 
    *(--stk)  = (INT32U)0x08080808uL;            // R8                                                 
    *(--stk)  = (INT32U)0x07070707uL;            // R7                                                
    *(--stk)  = (INT32U)0x06060606uL;            // R6                                                 
    *(--stk)  = (INT32U)0x05050505uL;            // R5                                                 
    *(--stk)  = (INT32U)0x04040404uL;            // R4                                                 

    return (stk);
}

//�����л�
#if (OS_CPU_HOOKS_EN > 0u) && (OS_TASK_SW_HOOK_EN > 0u)
void  OSTaskSwHook (void)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskSwHook();
#endif
}
#endif

//TCB��ʼ��
#if OS_CPU_HOOKS_EN > 0u
void  OSTCBInitHook (OS_TCB *ptcb)
{
#if OS_APP_HOOKS_EN > 0u
    App_TCBInitHook(ptcb);
#else
    (void)ptcb;                                  
#endif
}
#endif

//ʱ��Ƭ
#if (OS_CPU_HOOKS_EN > 0u) && (OS_TIME_TICK_HOOK_EN > 0u)
void  OSTimeTickHook (void)
{
#if OS_APP_HOOKS_EN > 0u
    App_TimeTickHook();
#endif

#if OS_TMR_EN > 0u
    OSTmrCtr++;
    if (OSTmrCtr >= (OS_TICKS_PER_SEC / OS_TMR_CFG_TICKS_PER_SEC)) {
        OSTmrCtr = 0;
        OSTmrSignal();
    }
#endif
}
#endif
#if 0
//����ʱ���ж�

void  OS_CPU_SysTickHandler (void)
{
    OS_CPU_SR  cpu_sr;


    OS_ENTER_CRITICAL();                         
    OSIntNesting++;
    OS_EXIT_CRITICAL();

    OSTimeTick();                                

    OSIntExit();                                
}

//��ʼ��ϵͳʱ��

void  OS_CPU_SysTickInit (INT32U  cnts)
{
    OS_CPU_CM3_NVIC_ST_RELOAD = cnts - 1u;
                                                 
    OS_CPU_CM3_NVIC_PRIO_ST   = OS_CPU_CM3_NVIC_PRIO_MIN;
                                                 
    OS_CPU_CM3_NVIC_ST_CTRL  |= OS_CPU_CM3_NVIC_ST_CTRL_CLK_SRC | OS_CPU_CM3_NVIC_ST_CTRL_ENABLE;
                                               
    OS_CPU_CM3_NVIC_ST_CTRL  |= OS_CPU_CM3_NVIC_ST_CTRL_INTEN;
}
#endif
