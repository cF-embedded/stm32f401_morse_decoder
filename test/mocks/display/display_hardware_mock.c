/******************************************************************************
 *brief: Display driver mocks for TDD source file
 *author: cF-embedded.pl
 ******************************************************************************/

#include "display_hardware_mock.h"
#include <stdbool.h>

void mock_display_hardware_init(void) {}
void mock_display_hardware_set_char(char) {}
void mock_display_hardware_clear(void) {}
void mock_display_hardware_set_header(void) {}

void setup_display_hardware_with_mocks(display_hardware_s_t* hardware)
{
    hardware->display_hardware_init = mock_display_hardware_init;
    hardware->display_hardware_set_char = mock_display_hardware_set_char;
    hardware->display_hardware_clear = mock_display_hardware_clear;
    hardware->display_hardware_set_header = mock_display_hardware_set_header;
}
