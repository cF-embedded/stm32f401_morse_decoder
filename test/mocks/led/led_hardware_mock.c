/******************************************************************************
 *brief: Led driver mocks for TDD source file
 *author: cF-embedded.pl
 ******************************************************************************/

#include "led_hardware_mock.h"
#include <stdbool.h>

bool hardware_mock_led_state = false;

void mock_led_hardware_init(void) {}

void mock_led_hardware_on(void)
{
    hardware_mock_led_state = true;
}

void mock_led_hardware_off(void)
{
    hardware_mock_led_state = false;
}

bool get_mock_led_hardware_state(void)
{
    return hardware_mock_led_state;
}

void setup_led_hardware_with_mocks(led_hardware_s_t* hardware)
{
    hardware->led_hardware_init = mock_led_hardware_init;
    hardware->led_hardware_on = mock_led_hardware_on;
    hardware->led_hardware_off = mock_led_hardware_off;
}
