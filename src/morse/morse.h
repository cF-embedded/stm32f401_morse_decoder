/******************************************************************************
 *brief: Morse decoder header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_H
#define __MORSE_H

#include "../../button/api/button.h"
#include "../../timer/api/timer_hardware.h"
#include "morse_type.h"
#include "stdbool.h"
#include "stdint.h"

typedef struct
{
    time_ms_t actual_pressed_time;
    timer_hardware_s_t timer;
    uint8_t char_index;
    morse_char_t morse_char[MAX_ELEMENTS_LEN];
    bool led;
    bool buzzer;
    button_s_t* button;
    uint32_t oled_display;
    morse_states_e_t morse_state;
} morse_decoder_s_t;

void morse_decoder_init(morse_decoder_s_t*, timer_hardware_s_t, button_s_t*);
void morse_decoder_start(morse_decoder_s_t*);
morse_char_t get_morse_decoder_char(morse_decoder_s_t*);

#endif /* __MORSE_H */
