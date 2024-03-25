/******************************************************************************
 *brief: Morse decoder
 *details: Genereting characters from morse code
 *author: cF-embedded.pl
 ******************************************************************************/

#include "morse.h"
#include <string.h>

void morse_decoder_init(morse_decoder_s_t* morse_decoder)
{
    morse_decoder->button->hardware.button_hardware_init();
    morse_decoder->led = 0;
    morse_decoder->buzzer = false;
    morse_decoder->timer = 0;
    memset(&morse_decoder->morse_char, 0, sizeof(morse_char_t));
}