/******************************************************************************
 *brief: Timer driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __TIMER_HARDWARE_H
#define __TIMER_HARDWARE_H

#include "timer_types.h"

typedef struct
{
    void (*timer_hardware_init)(void);
    time_ms_t (*timer_hardware_get_system_time)(void);
    void (*timer_hardware_clear)(void);
} timer_hardware_s_t;

#endif /* __TIMER_HARDWARE_H */