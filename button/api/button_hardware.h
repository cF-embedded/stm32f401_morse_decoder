/******************************************************************************
 *brief: Button driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUTTON_HARDWARE_H
#define __BUTTON_HARDWARE_H

#include "button_types.h"

typedef struct
{
    void (*button_hardware_init)(void);
    system_time_t (*button_hardware_get_system_time)(void);
    button_state_e_t (*button_hardware_read_state)(void);
} button_hardware_s_t;

#endif /* __BUTTON_HARDWARE_H */