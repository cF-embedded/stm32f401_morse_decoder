/******************************************************************************
 *brief: Buzzer driver mocks for TDD header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUZZER_HARDWARE_MOCK_H
#define __BUZZER_HARDWARE_MOCK_H

#include "../../../buzzer/api/buzzer_hardware.h"
#include <stdbool.h>

void mock_buzzer_hardware_init(void);
void mock_buzzer_hardware_on(void);
void mock_buzzer_hardware_off(void);
void setup_buzzer_hardware_with_mocks(buzzer_hardware_s_t*);

/* helper functions for mocks */
bool get_mock_buzzer_hardware_state(void);

#endif /* __BUZZER_HARDWARE_MOCK_H */
