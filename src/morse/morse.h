/******************************************************************************
 *brief: Morse decoder header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_H
#define __MORSE_H

#include "../../button/api/button.h"
#include "morse_type.h"
#include "stdbool.h"
#include "stdint.h"

typedef struct
{
    uint32_t timer;
    morse_char_t morse_char;
    bool led;
    bool buzzer;
    button_s_t* button;
    uint32_t oled_display;
} morse_decoder_s_t;

void morse_decoder_init(morse_decoder_s_t*);

#endif /* __MORSE_H */
