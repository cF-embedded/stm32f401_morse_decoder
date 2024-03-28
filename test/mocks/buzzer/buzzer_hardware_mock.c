/******************************************************************************
 *brief: Buzzer driver mocks for TDD source file
 *author: cF-embedded.pl
 ******************************************************************************/

#include "buzzer_hardware_mock.h"
#include <stdbool.h>

bool hardware_mock_buzzer_state = false;

void mock_buzzer_hardware_init(void) {}

void mock_buzzer_hardware_on(void)
{
    hardware_mock_buzzer_state = true;
}

void mock_buzzer_hardware_off(void)
{
    hardware_mock_buzzer_state = false;
}

bool get_mock_buzzer_hardware_state(void)
{
    return hardware_mock_buzzer_state;
}

void setup_buzzer_hardware_with_mocks(buzzer_hardware_s_t* hardware)
{
    hardware->buzzer_hardware_init = mock_buzzer_hardware_init;
    hardware->buzzer_hardware_on = mock_buzzer_hardware_on;
    hardware->buzzer_hardware_off = mock_buzzer_hardware_off;
}
