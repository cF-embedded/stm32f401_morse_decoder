/******************************************************************************
 *chip: any uC
 *brief: Button driver header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUTTON_H
#define __BUTTON_H

#include "button_hardware.h"
#include "button_types.h"

typedef struct
{
    system_time_t last_debounce_time;
    button_hardware_s_t hardware;
    button_status_e_t status;
    button_state_e_t last_state;
} button_s_t;

button_status_e_t button_init(button_s_t*, button_hardware_s_t);

button_state_e_t button_get_state(button_s_t*);

button_state_e_t button_get_state_with_debounce(button_s_t*, const system_time_t);

#endif /* __BUTTON_H */
