/******************************************************************************
 *brief: Morse times dependencies array header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __MORSE_TIMES_H
#define __MORSE_TIMES_H

#define DOT_IN_MS  80
#define DASH_IN_MS (DOT_IN_MS * 3)

#define BREAK_BETWEEN_CHAR_ELEMENTS (DOT_IN_MS * 1)
#define BREAK_BETWEEN_CHAR          (DASH_IN_MS * 1)
#define BREAK_BETWEEN_WORDS         (DASH_IN_MS * 3)

#endif /* __MORSE_TIMES_H */