/******************************************************************************
 *brief: Display driver mocks for TDD header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __DISPLAY_HARDWARE_MOCK_H
#define __DISPLAY_HARDWARE_MOCK_H

#include "../../../morse_hw/display/api/display_hardware.h"
#include <stdbool.h>

void mock_display_hardware_init(void);
void mock_display_hardware_set_char(char);
void mock_display_hardware_clear(void);
void mock_display_hardware_set_header(void);
void setup_display_hardware_with_mocks(display_hardware_s_t*);

#endif /* __DISPLAY_HARDWARE_MOCK_H */
