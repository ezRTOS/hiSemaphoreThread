/*
 * thread.c
 */

#include "thread.h"

#include "devices/device.h"
#include "share/share.h"

void thread_led(void *arg)
{
  uint32_t ui32LedIndex;
  while(1)
  {
    ostWait(share_bss->semLed, INFINITE);
    ostDevControl(DEV_LED, LED_TOGGLE, ui32LedIndex, 0);
    ui32LedIndex = (ui32LedIndex + 1) % 4;
  }
  return;
}
