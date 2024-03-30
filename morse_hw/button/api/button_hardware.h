/******************************************************************************
 *brief: Button driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUTTON_HARDWARE_H
#define __BUTTON_HARDWARE_H

#include "button_types.h"

#define MORSE_BUTTON_PORT GPIOE
#define MORSE_BUTTON_PIN  GPIO_PIN_4

typedef struct
{
    void (*button_hardware_init)(void);
    system_time_t (*button_hardware_get_system_time)(void);
    button_state_e_t (*button_hardware_read_state)(void);
} button_hardware_s_t;

void button_hardware_init(void);
button_state_e_t button_hardware_read_state(void);
system_time_t button_hardware_get_system_time(void);

#endif /* __BUTTON_HARDWARE_H */