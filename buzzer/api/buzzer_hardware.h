/******************************************************************************
 *brief: Buzzer driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUZZER_HARDWARE_H
#define __BUZZER_HARDWARE_H

typedef struct
{
    void (*buzzer_hardware_init)(void);
    void (*buzzer_hardware_on)(void);
    void (*buzzer_hardware_off)(void);
} buzzer_hardware_s_t;

#endif /* __BUZZER_HARDWARE_H */