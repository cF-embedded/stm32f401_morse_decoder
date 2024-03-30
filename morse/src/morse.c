/******************************************************************************
 *brief: Morse decoder
 *details: Genereting characters from morse code
 *author: cF-embedded.pl
 ******************************************************************************/

#include "../inc/morse.h"
#include "../inc/morse_characters.h"
#include "../inc/morse_times.h"
#include <stdbool.h>
#include <string.h>

static void morse_decoder_increment_element(morse_decoder_s_t*);

static void morse_decoder_clean_char(morse_decoder_s_t*);

static void morse_decoder_off_led_buzzer(morse_decoder_s_t*);

static void morse_decoder_on_led_buzzer(morse_decoder_s_t*);

static bool is_in_range(time_ms_t, time_ms_t, time_ms_t);

void morse_decoder_init(
    morse_decoder_s_t* morse_decoder, led_hardware_s_t _led, buzzer_hardware_s_t _buzzer, timer_hardware_s_t _timer, display_hardware_s_t _display, button_s_t* _button)
{
    morse_decoder->button = _button;
    morse_decoder->timer = _timer;
    morse_decoder->led = _led;
    morse_decoder->buzzer = _buzzer;
    morse_decoder->display = _display;
    morse_decoder->display.display_hardware_init();
    morse_decoder->display.display_hardware_set_header();
    morse_decoder->led.led_hardware_init();
    morse_decoder->buzzer.buzzer_hardware_init();
    morse_decoder->button->hardware.button_hardware_init();
    morse_decoder->timer.timer_hardware_init();
    morse_decoder->actual_elapsed_time = 0;
    morse_decoder->morse_state = MORSE_STATE_INIT;
    cbuf_init(&morse_decoder->cbuf);
    morse_decoder_clean_char(morse_decoder);
    morse_decoder->char_index = 0;
}

void morse_decoder_start(morse_decoder_s_t* morse_decoder)
{
    switch(morse_decoder->morse_state)
    {
        case MORSE_STATE_INIT:
        {
            if(button_get_state(morse_decoder->button) == BUTTON_STATE_PRESSED)
            {
                morse_decoder->timer.timer_hardware_clear();
                morse_decoder_on_led_buzzer(morse_decoder);
                morse_decoder->morse_state = MORSE_STATE_BUTTON_PRESSED;
            };
            break;
        }
        case MORSE_STATE_BUTTON_PRESSED:
        {
            if(button_get_state(morse_decoder->button) == BUTTON_STATE_RELEASED)
            {
                morse_decoder->actual_elapsed_time = morse_decoder->timer.timer_hardware_get_system_time();
                morse_decoder->timer.timer_hardware_clear();
                morse_decoder_off_led_buzzer(morse_decoder);
                morse_decoder_increment_element(morse_decoder);
                morse_decoder->morse_state = MORSE_STATE_BUTTON_RELEASED;
            }
            else if(morse_decoder->timer.timer_hardware_get_system_time() > BREAK_BETWEEN_WORDS)
            {
                morse_decoder_clean_char(morse_decoder);
                morse_decoder_off_led_buzzer(morse_decoder);
                morse_decoder->morse_state = MORSE_STATE_BUTTON_PRESSED_TOO_LONG;
            }
            break;
        }
        case MORSE_STATE_BUTTON_PRESSED_TOO_LONG:
        {
            if(button_get_state(morse_decoder->button) == BUTTON_STATE_RELEASED)
            {
                morse_decoder->morse_state = MORSE_STATE_INIT;
            }
            break;
        }
        case MORSE_STATE_BUTTON_RELEASED:
        {
            if(morse_decoder->timer.timer_hardware_get_system_time() > (BREAK_BETWEEN_CHAR_ELEMENTS + TIME_OFFSET))
            {
                morse_decoder->morse_state = MORSE_STATE_BREAK_BETTWEN_CHAR_ELEMENTS_ELAPSED;
            }
            else if(button_get_state(morse_decoder->button) == BUTTON_STATE_PRESSED)
            {
                morse_decoder->timer.timer_hardware_clear();
                morse_decoder_on_led_buzzer(morse_decoder);
                morse_decoder->morse_state = MORSE_STATE_BUTTON_PRESSED;
            }
            break;
        }
        case MORSE_STATE_BREAK_BETTWEN_CHAR_ELEMENTS_ELAPSED:
        {
            char decoded_char = morse_decoder_get_decoded_char(morse_decoder);
            if(decoded_char != ' ')
            {
                cbuf_push(&morse_decoder->cbuf, decoded_char);
            }
            morse_decoder->morse_state = MORSE_STATE_INIT;
            break;
        }
    }

    if(!cbuf_is_empty(&morse_decoder->cbuf))
    {
        char char_to_display = cbuf_pop(&morse_decoder->cbuf);
        morse_decoder->display.display_hardware_set_char(char_to_display);
    }
}

static void morse_decoder_increment_element(morse_decoder_s_t* morse_decoder)
{
    if(is_in_range(morse_decoder->actual_elapsed_time, DOT_IN_MS, DOT_IN_MS + TIME_OFFSET))
    {
        morse_decoder->morse_char[morse_decoder->char_index] = '.';
        morse_decoder->char_index++;
        if(morse_decoder->char_index == MAX_ELEMENTS_LEN)
        {
            morse_decoder->char_index = 0;
        }
    }

    else if(is_in_range(morse_decoder->actual_elapsed_time, DASH_IN_MS, DASH_IN_MS + TIME_OFFSET))
    {
        morse_decoder->morse_char[morse_decoder->char_index] = '-';
        morse_decoder->char_index++;
        if(morse_decoder->char_index == MAX_ELEMENTS_LEN)
        {
            morse_decoder->char_index = 0;
        }
    }
}

static bool is_in_range(time_ms_t time, time_ms_t min, time_ms_t max)
{
    return (time <= max) && (time >= min);
}

char morse_decoder_get_decoded_char(morse_decoder_s_t* morse_decoder)
{
    char decoded_char = ' ';

    for(uint32_t i = 0; i < (sizeof(morse_table) / sizeof(morse_table[0])); i++)
    {
        if(strcmp(morse_decoder->morse_char, morse_table[i].morse_char) == 0)
        {
            decoded_char = morse_table[i].ascii_char;
        }
    }

    return decoded_char;
}

static void morse_decoder_off_led_buzzer(morse_decoder_s_t* morse_decoder)
{
    morse_decoder->led.led_hardware_off();
    morse_decoder->buzzer.buzzer_hardware_off();
}

static void morse_decoder_on_led_buzzer(morse_decoder_s_t* morse_decoder)
{
    morse_decoder->led.led_hardware_on();
    morse_decoder->buzzer.buzzer_hardware_on();
}

static void morse_decoder_clean_char(morse_decoder_s_t* morse_decoder)
{
    memset(morse_decoder->morse_char, ' ', sizeof(morse_decoder->morse_char));
}
