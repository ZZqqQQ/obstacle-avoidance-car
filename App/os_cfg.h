
#ifndef OS_CFG_H
#define OS_CFG_H


                                       
#define OS_APP_HOOKS_EN           0u   // ʹ��APPӦ��HOOK����                                         
#define OS_ARG_CHK_EN             0u   // �������                                                    
#define OS_CPU_HOOKS_EN           1u   // ʹ��OS_CPU HOOK����                                        

#define OS_DEBUG_EN               0u   // ʹ��ϵͳ���Թ���                                           
#define OS_EVENT_MULTI_EN         0u   // ʹ��OSEventPendMulti()����                                  
#define OS_EVENT_NAME_EN          0u   // ʹ���¼�(Sem, Mutex, Mbox and Q)����                       

#define OS_LOWEST_PRIO           63u   // ����������ȼ�                                   
                                       

#define OS_MAX_EVENTS             5u   // �¼����ƿ�������(Ӧ�ó�����)                               
#define OS_MAX_FLAGS              5u   // �¼���־��������(Ӧ�ó�����)                              
#define OS_MAX_MEM_PART           5u   // �ڴ���������                                              
#define OS_MAX_QS                 5u   // ���п��ƿ�������(Ӧ�ó�����)                              
#define OS_MAX_TASKS             10u   // Ӧ�ó������񣩵������                                    

#define OS_SCHED_LOCK_EN          0u   // ʹ��OSSchedLock() �� OSSchedUnlock()����                    

#define OS_TICK_STEP_EN           0u   // ʹ��tick stepping                                            
#define OS_TICKS_PER_SEC        100u   //ÿ��δ���                                                 

#define OS_TLS_TBL_SIZE           0u   // �̱߳��ش洢��(Thread-Local Storage Table)��С            


                                       
#define OS_TASK_TMR_STK_SIZE    128u   // ��ʱ�������ջ��С              
#define OS_TASK_STAT_STK_SIZE   128u   // ͳ�������ջ��С              
#define OS_TASK_IDLE_STK_SIZE   128u   // ���������ջ��С                 


                                       
#define OS_TASK_CHANGE_PRIO_EN    1u   // �������ȼ��л�   
#define OS_TASK_CREATE_EN         1u   // ��������           
#define OS_TASK_CREATE_EXT_EN     1u   // ������չ�汾����     
#define OS_TASK_DEL_EN            1u   // ɾ������             
#define OS_TASK_NAME_EN           1u   // Get,Set��������      
#define OS_TASK_PROFILE_EN        0u   // ����OS_TCB���ܷ���                                          
#define OS_TASK_QUERY_EN          1u   // ��ѯ����(��Ϣ)       
#define OS_TASK_REG_TBL_SIZE      0u   // ������������Ĵ�С                 
#define OS_TASK_STAT_EN           0u   // ʹ��ͳ������                                               
#define OS_TASK_STAT_STK_CHK_EN   0u   // ʹ�ܼ�������ջ                                            
#define OS_TASK_SUSPEND_EN        1u   // ������𡢼���      
#define OS_TASK_SW_HOOK_EN        1u   //  �����л�HOOK����


                                       
#define OS_FLAG_EN                0u   // ʹ��OS_FLAG�¼���־���й���                                
#define OS_FLAG_ACCEPT_EN         0u   //  ���(��ȡ)�¼�״̬ 
#define OS_FLAG_DEL_EN            0u   // ɾ���¼�            
#define OS_FLAG_NAME_EN           0u   // ʹ���¼���־����
#define OS_FLAG_QUERY_EN          0u   // ��ѯ�¼�             
#define OS_FLAG_WAIT_CLR_EN       0u   // ʹ���¼��ȴ��������
#define OS_FLAGS_NBITS           16u   // ����OS_FLAGS����������


                                       
#define OS_MBOX_EN                0u   
#define OS_MBOX_ACCEPT_EN         0u  
#define OS_MBOX_DEL_EN            0u   
#define OS_MBOX_PEND_ABORT_EN     0u   
#define OS_MBOX_POST_EN           0u   
#define OS_MBOX_POST_OPT_EN       0u   
#define OS_MBOX_QUERY_EN          0u  


                                       // �ڴ�ܹ���
#define OS_MEM_EN                 0u
#define OS_MEM_NAME_EN            0u
#define OS_MEM_QUERY_EN           0u


                                       // �����ź���
#define OS_MUTEX_EN               0u  
#define OS_MUTEX_ACCEPT_EN        0u
#define OS_MUTEX_DEL_EN           0u
#define OS_MUTEX_QUERY_EN         0u


                                       //��Ϣ����
#define OS_Q_EN                   0u   
#define OS_Q_ACCEPT_EN            0u   
#define OS_Q_DEL_EN               0u   
#define OS_Q_FLUSH_EN             0u   
#define OS_Q_PEND_ABORT_EN        0u   
#define OS_Q_POST_EN              0u  
#define OS_Q_POST_FRONT_EN        0u 
#define OS_Q_POST_OPT_EN          0u  
#define OS_Q_QUERY_EN             0u 


                                       // �ź���
#define OS_SEM_EN                 0u   
#define OS_SEM_ACCEPT_EN          0u   
#define OS_SEM_DEL_EN             0u   
#define OS_SEM_PEND_ABORT_EN      0u   
#define OS_SEM_QUERY_EN           0u  
#define OS_SEM_SET_EN             0u   


                                       // ʱ�����
#define OS_TIME_DLY_HMSM_EN       0u   
#define OS_TIME_DLY_RESUME_EN     0u   
#define OS_TIME_GET_SET_EN        0u  
#define OS_TIME_TICK_HOOK_EN      0u   


                                       //��ʱ������
#define OS_TMR_EN                 0u   
#define OS_TMR_CFG_MAX           16u  
#define OS_TMR_CFG_NAME_EN        0u   
#define OS_TMR_CFG_WHEEL_SIZE     7u  
#define OS_TMR_CFG_TICKS_PER_SEC 10u  

#endif
