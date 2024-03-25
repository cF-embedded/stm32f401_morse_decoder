/******************************************************************************
 *brief: Morse decoder types header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_TYPES_H
#define __MORSE_TYPES_H

#include "stdint.h"

typedef uint8_t dot_t;
typedef uint8_t dash_t;

typedef struct
{
    dot_t dot;
    dash_t dash;
} morse_char_t;

#endif /* __MORSE_TYPES_H */