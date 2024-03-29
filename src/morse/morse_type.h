/******************************************************************************
 *brief: Morse decoder types header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_TYPES_H
#define __MORSE_TYPES_H

#include "stdint.h"

typedef uint8_t dot_t;
typedef uint8_t dash_t;

/* 4 elements of morse char plus null terminator */
#define MAX_ELEMENTS_LEN (4 + 1)

typedef char morse_char_t;

typedef enum
{
    MORSE_STATE_INIT,
    MORSE_STATE_BUTTON_PRESSED,
    MORSE_STATE_BUTTON_RELEASED,
    MORSE_STATE_BUTTON_PRESSED_TOO_LONG,
    MORSE_STATE_BREAK_BETTWEN_CHAR_ELEMENTS_ELAPSED,
} morse_states_e_t;

#endif /* __MORSE_TYPES_H */