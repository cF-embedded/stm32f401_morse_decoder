/******************************************************************************
 *brief: Morse decoder TDD file
 *author: cF-embedded.pl
 ******************************************************************************/

extern "C"
{
#include "../../src/morse/morse.h"
#include "../../src/morse/morse_type.h"
#include "../mocks/button/button_hardware_mock.h"
#include "../mocks/timer/timer_hardware_mock.h"
#include <string.h>
}

#include <gtest/gtest.h>

class morse_decoder_get_char_test : public ::testing::Test
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

TEST_F(morse_decoder_get_char_test, morse_get_E_char)
{
    strcpy(morse_decoder.morse_char, ".   ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'E');
}
