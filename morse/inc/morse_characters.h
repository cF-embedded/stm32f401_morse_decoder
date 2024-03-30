/******************************************************************************
 *brief: Morse characters array header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_CHARACTERS_H
#define __MORSE_CHARACTERS_H

#include "morse_type.h"

typedef struct
{
    morse_char_t* morse_char;
    char ascii_char;
} morse_char_ascii_char_s_t;

const morse_char_ascii_char_s_t morse_table[] = 
{
    {".-  ", 'A'},
    {"-...", 'B'},
    {"-.-.", 'C'},
    {"-.. ", 'D'},
    {".   ", 'E'},
    {"..-.", 'F'}, 
    {"--. ", 'G'},  
    {"....", 'H'}, 
    {"..  ", 'I'},  
    {".---", 'J'},
    {"-.- ", 'K'},
    {".-..", 'L'},
    {"--  ", 'M'},  
    {"-.  ", 'N'},  
    {"--- ", 'O'},  
    {".--.", 'P'},
    {"--.-", 'Q'},
    {".-. ", 'R'},
    {"... ", 'S'},
    {"-   ", 'T'},
    {"..- ", 'U'},
    {"...-", 'V'},
    {".-- ", 'W'},
    {"-..-", 'X'},
    {"-.--", 'Y'},
    {"--..", 'Z'}
};

#endif /* __MORSE_CHARACTERS_H */
