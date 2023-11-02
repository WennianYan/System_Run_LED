/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author           Notes
 * 2023-10-28     WennianYan       the first version
 */

#include <rtdevice.h>
#include "rtthread.h"

void System_Run_LED_entry(void *parameter)
{
    rt_base_t System_Run_LED = rt_pin_get(System_Run_LED_Pin_Name);
    rt_pin_mode(System_Run_LED,PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(System_Run_LED,!(_Bool)rt_pin_read(System_Run_LED));
        rt_thread_mdelay(System_Run_LED_Flash_Time);
    }
}

int System_Run_LED(void)
{
#ifdef RT_USING_HEAP
    rt_thread_t System_Run_LED_tid = RT_NULL;

    /* 初始化并创建动态线程,名称是:System_Run_LED_tid,入口是:System_Run_LED_entry*/
    System_Run_LED_tid = rt_thread_create("System_Run_LED",
                                          System_Run_LED_entry, 
                                          RT_NULL,
                                          System_Run_LED_THREAD_STACK_SIZE,
                                          System_Run_LED_THREAD_PRIORITY,
                                          System_Run_LED_THREAD_TIMESLICE);

    /* 如果获得线程控制块，启动这个线程 */
    if (System_Run_LED_tid != RT_NULL)
        rt_thread_startup(System_Run_LED_tid);
#else
    /* 初始化并创建静态线程，名称是 System_Run_LED_tid,入口是 System_Run_LED_entry */
    static struct rt_thread System_Run_LED_tid;
    static char System_Run_LED_THREAD_STACK[System_Run_LED_THREAD_STACK_SIZE];

    rt_thread_init(&System_Run_LED_tid,
                   "System_Run_LED",
                   System_Run_LED_entry,
                   RT_NULL,
                   &System_Run_LED_THREAD_STACK[0],
                   sizeof(System_Run_LED_THREAD_STACK),
                   System_Run_LED_THREAD_PRIORITY,
                   System_Run_LED_THREAD_TIMESLICE);
                   
    rt_thread_startup(&System_Run_LED_tid);

#endif //#endif RT_USING_HEAP

    return RT_EOK;
}
INIT_APP_EXPORT(System_Run_LED);
