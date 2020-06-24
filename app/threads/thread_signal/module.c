/*
 * module.c
 */

#include "thread.h"

__attribute__ ((section(".thread_data"))) const thread_signal_data_t const_thread_signal_data = {
  .delay = 500
};

__attribute__ ((section(".thread_header"))) const osThreadHeaderT thread_signal_header = \
    {thread_signal, 1500, 1024, (uint32_t)&const_thread_signal_data, sizeof(thread_signal_data_t), sizeof(thread_signal_bss_t), 0, "thread_signal"};


