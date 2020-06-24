/*
 * button.c
 */

#include "stm32f4_discovery.h"
#include "../share/share.h"

osDevCallT btnInit(osDevIdT devId)
{
  BSP_PB_Init();
  return SYSOK;
}

void EXTI0_IRQHandler(void)
{
  osiEnterIrq();
  int16_t count;

  if((EXTI->PR & EXTI_Line0) != RESET)
  {
    /* Signal semaphore only when semaphore count is 0 */
    osGetSemaphoreCount(share_bss->semLed, &count);
    if(count == 0)
    {
      osSignal(share_bss->semLed);
    }

    /* Clear the EXTI line 0 pending bit */
    EXTI->PR = EXTI_Line0;
  }

  osiLeaveIrq();
}
