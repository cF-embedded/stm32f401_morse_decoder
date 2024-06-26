/******************************************************************************
 *brief: Morse decoder header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_H
#define __MORSE_H

#include "../../cbuf/cbuf.h"
#include "../../morse_hw/button/api/button.h"
#include "../../morse_hw/buzzer/api/buzzer_hardware.h"
#include "../../morse_hw/display/api/display_hardware.h"
#include "../../morse_hw/led/api/led_hardware.h"
#include "../../morse_hw/timer/api/timer_hardware.h"
#include "morse_type.h"
#include "stdbool.h"
#include "stdint.h"


typedef struct
{
    time_ms_t actual_elapsed_time;
    timer_hardware_s_t timer;
    uint8_t char_index;
    morse_char_t morse_char[MAX_ELEMENTS_LEN];
    led_hardware_s_t led;
    buzzer_hardware_s_t buzzer;
    button_s_t* button;
    cbuf_s_t cbuf;
    display_hardware_s_t display;
    morse_states_e_t morse_state;
} morse_decoder_s_t;

void morse_decoder_init(morse_decoder_s_t*, led_hardware_s_t, buzzer_hardware_s_t, timer_hardware_s_t, display_hardware_s_t, button_s_t*);
void morse_decoder_start(morse_decoder_s_t*);
char morse_decoder_get_decoded_char(morse_decoder_s_t*);

#endif /* __MORSE_H */
