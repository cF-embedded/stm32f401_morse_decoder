/******************************************************************************
 *brief: Button driver mocks for TDD header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUTTON_HARDWARE_MOCK_H
#define __BUTTON_HARDWARE_MOCK_H

#include "../../../../button/api/button_hardware.h"

void mock_button_hardware_init(void);
button_state_e_t mock_button_hardware_read_state(void);
system_time_t mock_button_hardware_get_system_time(void);
void setup_button_hardware_with_mocks(button_hardware_s_t*);

/* helper functions for mocks */
void set_mock_button_hardware_read_state(button_state_e_t);
void set_mock_button_hardware_system_time(system_time_t);

#endif /* __BUTTON_HARDWARE_MOCK_H */
