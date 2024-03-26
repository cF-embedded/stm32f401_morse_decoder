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
    void SetUp() override
    {
        mock_button_hardware_init();
        mock_timer_hardware_init();
    }

    void TearDown() override {}
};
