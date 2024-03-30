/******************************************************************************
 *brief: Led driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __LED_HARDWARE_H
#define __LED_HARDWARE_H

#define MORSE_LED_PORT GPIOE
#define MORSE_LED_PIN  GPIO_PIN_6

typedef struct
{
    void (*led_hardware_init)(void);
    void (*led_hardware_on)(void);
    void (*led_hardware_off)(void);
} led_hardware_s_t;

void led_hardware_init(void);
void led_hardware_on(void);
void led_hardware_off(void);

#endif /* __LED_HARDWARE_H */