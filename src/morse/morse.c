/******************************************************************************
 *brief: Morse decoder
 *details: Genereting characters from morse code
 *author: cF-embedded.pl
 ******************************************************************************/

#include "morse.h"
#include "morse_times.h"
#include <string.h>

void morse_decoder_init(morse_decoder_s_t* morse_decoder, timer_hardware_s_t _timer, button_s_t* _button)
{
    morse_decoder->button = _button;
    morse_decoder->timer = _timer;
    morse_decoder->button->hardware.button_hardware_init();
    morse_decoder->timer.timer_hardware_init();
    morse_decoder->actual_pressed_time = 0;
    morse_decoder->led = false;
    morse_decoder->buzzer = false;
    morse_decoder->morse_state = MORSE_INIT;
    memset(&morse_decoder->morse_char, 0, sizeof(morse_char_s_t));
}

void morse_decoder_start(morse_decoder_s_t* morse_decoder)
{
    switch(morse_decoder->morse_state)
    {
        case MORSE_INIT:
        {
            if(button_get_state(morse_decoder->button) == BUTTON_STATE_PRESSED)
            {
                morse_decoder->morse_state = MORSE_BUTTON_STATE_PRESSED;
                morse_decoder->led = true;
                morse_decoder->buzzer = true;
                morse_decoder->timer.timer_hardware_clear();
            };
            break;
        }
        case MORSE_BUTTON_STATE_PRESSED:
        {
            if(button_get_state(morse_decoder->button) == BUTTON_STATE_RELEASED)
            {
                morse_decoder->morse_state = MORSE_BUTTON_STATE_RELEASED;
                morse_decoder->actual_pressed_time = morse_decoder->timer.timer_hardware_get_system_time();
            }
            break;
        }
    }
}

morse_char_s_t get_morse_decoder_char(morse_decoder_s_t* morse_decoder)
{
    morse_char_s_t morse_char_tmp = {0, 0};
}
