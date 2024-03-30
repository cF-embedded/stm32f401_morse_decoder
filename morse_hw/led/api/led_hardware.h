/******************************************************************************
 *brief: Led driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __LED_HARDWARE_H
#define __LED_HARDWARE_H

typedef struct
{
    void (*led_hardware_init)(void);
    void (*led_hardware_on)(void);
    void (*led_hardware_off)(void);
} led_hardware_s_t;

#endif /* __LED_HARDWARE_H */