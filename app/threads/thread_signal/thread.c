/*
 * thread.c
 */

#include "thread.h"

#include "devices/device.h"
#include "share/share.h"

void thread_signal(void *arg)
{
  while(1)
  {
    osSignal(share_bss->semLed);
    ostSleep(thread_signal_data->delay);
  }
  return;
}
