/******************************************************************************
 *brief: Led driver mocks for TDD header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __LED_HARDWARE_MOCK_H
#define __LED_HARDWARE_MOCK_H

#include "../../../led/api/led_hardware.h"
#include <stdbool.h>

void mock_led_hardware_init(void);
void mock_led_hardware_on(void);
void mock_led_hardware_off(void);
void setup_led_hardware_with_mocks(led_hardware_s_t*);

/* helper functions for mocks */
bool get_mock_led_hardware_state(void);

#endif /* __LED_HARDWARE_MOCK_H */
