/******************************************************************************
 *brief: Morse decoder TDD file
 *author: cF-embedded.pl
 ******************************************************************************/

extern "C"
{
#include "../../src/morse/morse.h"
#include "../../src/morse/morse_times.h"
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
        button_init(&button, hardware_button);

        timer_hardware_s_t hardware_timer;

        morse_decoder_init(&morse_decoder, hardware_timer, &button);
    }

    void TearDown() override {}
};
