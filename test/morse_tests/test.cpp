/******************************************************************************
 *brief: Morse decoder TDD file
 *author: cF-embedded.pl
 ******************************************************************************/

extern "C"
{
#include "../../src/morse/morse.h"
#include "mocks/button/button_hardware_mock.h"
#include "mocks/timer/timer_hardware_mock.h"
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

        morse_decoder_init(&morse_decoder, hardware_timer, &button);
    }

    void TearDown() override {}
};

TEST_F(morse_decoder_test, morse_init_state_after_init)
{
    ASSERT_EQ(morse_decoder.morse_state, MORSE_INIT);
}

TEST_F(morse_decoder_test, morse_led_is_on_after_pressed_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);

    ASSERT_TRUE(morse_decoder.led);
}

TEST_F(morse_decoder_test, morse_buzzer_is_on_after_pressed_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);

    ASSERT_TRUE(morse_decoder.buzzer);
}

TEST_F(morse_decoder_test, morse_button_is_prssed_state_after_pressed_button)
{
    set_mock_button_hardware_read_state(BUTTON_STATE_PRESSED);

    morse_decoder_start(&morse_decoder);

    ASSERT_EQ(morse_decoder.morse_state, MORSE_BUTTON_IS_PRESSED);
}
