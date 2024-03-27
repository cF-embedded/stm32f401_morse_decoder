/******************************************************************************
 *brief: Morse decoder types header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_TYPES_H
#define __MORSE_TYPES_H

#include "stdint.h"

typedef uint8_t dot_t;
typedef uint8_t dash_t;

#define MAX_ELEMENTS_LEN 4

typedef char morse_char_t;

typedef enum
{
    MORSE_INIT,
    MORSE_BUTTON_STATE_PRESSED,
    MORSE_BUTTON_STATE_RELEASED,
    MORSE_BREAK_BETTWEN_CHAR_ELEMENTS_ELAPSED,
} morse_states_e_t;

#endif /* __MORSE_TYPES_H */