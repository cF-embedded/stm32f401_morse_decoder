/******************************************************************************
 *brief: Buzzer driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUZZER_HARDWARE_H
#define __BUZZER_HARDWARE_H

#define MORSE_BUZZER_PORT GPIOE
#define MORSE_BUZZER_PIN  GPIO_PIN_5

typedef struct
{
    void (*buzzer_hardware_init)(void);
    void (*buzzer_hardware_on)(void);
    void (*buzzer_hardware_off)(void);
} buzzer_hardware_s_t;

void buzzer_hardware_init(void);
void buzzer_hardware_on(void);
void buzzer_hardware_off(void);

#endif /* __BUZZER_HARDWARE_H */