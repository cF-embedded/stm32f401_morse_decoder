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

TEST_F(morse_decoder_get_char_test, morse_get_A_char)
{
    strcpy(morse_decoder.morse_char, ".-  ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'A');
}

TEST_F(morse_decoder_get_char_test, morse_get_B_char)
{
    strcpy(morse_decoder.morse_char, "-...");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'B');
}

TEST_F(morse_decoder_get_char_test, morse_get_C_char)
{
    strcpy(morse_decoder.morse_char, "-.-.");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'C');
}

TEST_F(morse_decoder_get_char_test, morse_get_D_char)
{
    strcpy(morse_decoder.morse_char, "-.. ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'D');
}

TEST_F(morse_decoder_get_char_test, morse_get_F_char)
{
    strcpy(morse_decoder.morse_char, "..-.");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'F');
}

TEST_F(morse_decoder_get_char_test, morse_get_G_char)
{
    strcpy(morse_decoder.morse_char, "--. ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'G');
}

TEST_F(morse_decoder_get_char_test, morse_get_H_char)
{
    strcpy(morse_decoder.morse_char, "....");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'H');
}

TEST_F(morse_decoder_get_char_test, morse_get_I_char)
{
    strcpy(morse_decoder.morse_char, "..  ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'I');
}

TEST_F(morse_decoder_get_char_test, morse_get_J_char)
{
    strcpy(morse_decoder.morse_char, ".---");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'J');
}

TEST_F(morse_decoder_get_char_test, morse_get_K_char)
{
    strcpy(morse_decoder.morse_char, "-.- ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'K');
}

TEST_F(morse_decoder_get_char_test, morse_get_L_char)
{
    strcpy(morse_decoder.morse_char, ".-..");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'L');
}

TEST_F(morse_decoder_get_char_test, morse_get_M_char)
{
    strcpy(morse_decoder.morse_char, "--  ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'M');
}

TEST_F(morse_decoder_get_char_test, morse_get_N_char)
{
    strcpy(morse_decoder.morse_char, "-.  ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'N');
}

TEST_F(morse_decoder_get_char_test, morse_get_O_char)
{
    strcpy(morse_decoder.morse_char, "--- ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'O');
}

TEST_F(morse_decoder_get_char_test, morse_get_P_char)
{
    strcpy(morse_decoder.morse_char, ".--.");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'P');
}

TEST_F(morse_decoder_get_char_test, morse_get_Q_char)
{
    strcpy(morse_decoder.morse_char, "--.-");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'Q');
}

TEST_F(morse_decoder_get_char_test, morse_get_R_char)
{
    strcpy(morse_decoder.morse_char, ".-. ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'R');
}

TEST_F(morse_decoder_get_char_test, morse_get_S_char)
{
    strcpy(morse_decoder.morse_char, "... ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'S');
}

TEST_F(morse_decoder_get_char_test, morse_get_T_char)
{
    strcpy(morse_decoder.morse_char, "-   ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'T');
}

TEST_F(morse_decoder_get_char_test, morse_get_U_char)
{
    strcpy(morse_decoder.morse_char, "..- ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'U');
}

TEST_F(morse_decoder_get_char_test, morse_get_V_char)
{
    strcpy(morse_decoder.morse_char, "...-");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'V');
}

TEST_F(morse_decoder_get_char_test, morse_get_W_char)
{
    strcpy(morse_decoder.morse_char, ".-- ");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'W');
}

TEST_F(morse_decoder_get_char_test, morse_get_X_char)
{
    strcpy(morse_decoder.morse_char, "-..-");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'X');
}

TEST_F(morse_decoder_get_char_test, morse_get_Y_char)
{
    strcpy(morse_decoder.morse_char, "-.--");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'Y');
}

TEST_F(morse_decoder_get_char_test, morse_get_Z_char)
{
    strcpy(morse_decoder.morse_char, "--..");

    char morse_char = morse_decoder_get_decoded_char(&morse_decoder);
    ASSERT_EQ(morse_char, 'Z');
}
