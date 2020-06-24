/*
 * thread.h
 */

#ifndef APP_THREADS_THREAD_SIGNAL_THREAD_H_
#define APP_THREADS_THREAD_SIGNAL_THREAD_H_

#include "ezRTOS.h"

typedef struct _thread_signal_data_t{
  int delay;
}thread_signal_data_t;

typedef struct _thread_signal_bss_t{
  int ledIndex;
}thread_signal_bss_t;

extern const osThreadHeaderT thread_signal_header;

#define thread_signal_data ((thread_signal_data_t *)THREADDATA)
#define thread_signal_bss ((thread_signal_bss_t *)THREADBSS)

void thread_signal(void *arg);

#endif /* APP_THREADS_THREAD_SIGNAL_THREAD_H_ */
