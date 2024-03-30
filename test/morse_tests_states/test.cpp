/******************************************************************************
 *brief: Morse decoder TDD file
 *author: cF-embedded.pl
 ******************************************************************************/

extern "C"
{
#include "../../src/morse/morse.h"
#include "../../src/morse/morse_times.h"
#include "../mocks/button/button_hardware_mock.h"
#include "../mocks/buzzer/buzzer_hardware_mock.h"
#include "../mocks/led/led_hardware_mock.h"
#include "../mocks/timer/timer_hardware_mock.h"
}

#include <gtest/gtest.h>

class morse_decoder_test : public ::testing::Test
{
  protected:
    morse_decoder_s_t morse_decoder;
    void SetUp() override
    {
        button_s_t button;
        button_hardware_s_t hardware_button;
        setup_button_hardware_with_mocks(&hardware_button);
        button_init(&button, hardware_button);

        timer_hardware_s_t hardware_timer;
        setup_timer_hardware_with_mocks(&hardware_timer);

        led_hardware_s_t hardware_led;
        setup_led_hardware_with_mocks(&hardware_led);

        buzzer_hardware_s_t hardware_buzzer;
        setup_buzzer_hardware_with_mocks(&hardware_buzzer);
        morse_decoder_init(&morse_decoder, hardware_led, hardware_buzzer, hardware_timer, &button);
    }

    void TearDown() override {}
};

TEST_F(morse_decoder_test, morse_init_state_after_init)
{
    ASSERT_EQ(morse_decoder.morse_state, MORSE_STATE_INIT);
}

TEST_F(morse_decoder_test, morse_led_is_on_after_pressed_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);

    ASSERT_TRUE(get_mock_led_hardware_state());
}

TEST_F(morse_decoder_test, morse_buzzer_is_on_after_pressed_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);

    ASSERT_TRUE(get_mock_buzzer_hardware_state());
}

TEST_F(morse_decoder_test, morse_button_is_pressed_state_after_pressed_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_state, MORSE_STATE_BUTTON_PRESSED);
}

TEST_F(morse_decoder_test, morse_button_is_released_state_after_pressed_button_before)
{
    morse_decoder.morse_state = MORSE_STATE_BUTTON_PRESSED;
    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);

    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_state, MORSE_STATE_BUTTON_RELEASED);
}

TEST_F(morse_decoder_test, morse_timer_is_clear_after_pressed_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    set_mock_timer_hardware_time(0xFFFF);

    morse_decoder_start(&morse_decoder);

    time_ms_t time = mock_timer_hardware_get_system_time();
    ASSERT_EQ(time, 0);
}

TEST_F(morse_decoder_test, actual_pressed_time_equal_time_after_released_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    morse_decoder_start(&morse_decoder);

    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);
    set_mock_timer_hardware_time(0xFFFF);
    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.actual_pressed_time, 0xFFFF);
}

TEST_F(morse_decoder_test, morse_timer_is_clear_after_released_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    morse_decoder_start(&morse_decoder);

    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);
    set_mock_timer_hardware_time(0xFFFF);
    morse_decoder_start(&morse_decoder);

    time_ms_t time = mock_timer_hardware_get_system_time();
    ASSERT_EQ(time, 0);
}

TEST_F(morse_decoder_test, add_dot_to_buffer_after_button_pressed_for_certain_time)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    morse_decoder_start(&morse_decoder);

    set_mock_timer_hardware_time(DOT_IN_MS + (TIME_OFFSET / 2));
    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);
    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_char[0], '.');
}

TEST_F(morse_decoder_test, add_dash_to_buffer_after_button_pressed_for_certain_time)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    morse_decoder_start(&morse_decoder);

    set_mock_timer_hardware_time(DASH_IN_MS + (TIME_OFFSET / 2));
    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);
    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_char[0], '-');
}

TEST_F(morse_decoder_test, morse_led_is_off_after_button_released)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    morse_decoder_start(&morse_decoder);

    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);
    morse_decoder_start(&morse_decoder);

    ASSERT_FALSE(get_mock_led_hardware_state());
}

TEST_F(morse_decoder_test, morse_buzzer_is_off_after_button_released)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    morse_decoder_start(&morse_decoder);

    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);
    morse_decoder_start(&morse_decoder);

    ASSERT_FALSE(get_mock_buzzer_hardware_state());
}

TEST_F(morse_decoder_test, MORSE_STATE_BUTTON_PRESSED_TOO_LONG_state_after_button_pressed_to_long)
{
    morse_decoder.morse_state = MORSE_STATE_BUTTON_PRESSED;
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    set_mock_timer_hardware_time(BREAK_BETWEEN_WORDS + (TIME_OFFSET / 2));

    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_state, MORSE_STATE_BUTTON_PRESSED_TOO_LONG);
}

TEST_F(morse_decoder_test, morse_char_clear_in_MORSE_STATE_BUTTON_PRESSED_TOO_LONG)
{
    morse_decoder.morse_state = MORSE_STATE_BUTTON_PRESSED;
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    set_mock_timer_hardware_time(BREAK_BETWEEN_WORDS + (TIME_OFFSET / 2));

    morse_decoder_start(&morse_decoder);

    ASSERT_STREQ(morse_decoder.morse_char, "     ");
}

TEST_F(morse_decoder_test, buzzer_off_after_button_pressed_to_long)
{
    morse_decoder.morse_state = MORSE_STATE_INIT;
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);
    set_mock_timer_hardware_time(BREAK_BETWEEN_WORDS + (TIME_OFFSET / 2));

    morse_decoder_start(&morse_decoder);

    ASSERT_FALSE(get_mock_buzzer_hardware_state());
}

TEST_F(morse_decoder_test, led_off_after_button_pressed_to_long)
{
    morse_decoder.morse_state = MORSE_STATE_INIT;
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);
    set_mock_timer_hardware_time(BREAK_BETWEEN_WORDS + (TIME_OFFSET / 2));

    morse_decoder_start(&morse_decoder);

    ASSERT_FALSE(get_mock_led_hardware_state());
}

TEST_F(morse_decoder_test, morse_init_state_after_released_button_in_morse_state_button_pressed_too_long)
{
    morse_decoder.morse_state = MORSE_STATE_BUTTON_PRESSED_TOO_LONG;
    set_mock_button_hardware_read_state(BUTTON_STATE_RELEASED);

    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_state, MORSE_STATE_INIT);
}

TEST_F(morse_decoder_test, morse_state_button_pressed_after_button_pressed_in_break_between_char_elements_time_in_morse_state_button_released)
{
    morse_decoder.morse_state = MORSE_STATE_BUTTON_RELEASED;
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);
    set_mock_timer_hardware_time(BREAK_BETWEEN_CHAR_ELEMENTS + (TIME_OFFSET / 2));

    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_state, MORSE_STATE_BUTTON_PRESSED);
}
