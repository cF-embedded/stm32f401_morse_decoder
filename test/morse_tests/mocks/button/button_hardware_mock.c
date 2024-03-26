/******************************************************************************
 *brief: Button driver mocks for TDD source file
 *author: cF-embedded.pl
 ******************************************************************************/

#include "button_hardware_mock.h"

button_state_e_t hardware_mock_state;

system_time_t hardware_system_time;

void mock_button_hardware_init(void) {}

button_state_e_t mock_button_hardware_read_state(void)
{
    return hardware_mock_state;
}

system_time_t mock_button_hardware_get_system_time(void)
{
    return hardware_system_time;
}

void set_mock_button_hardware_read_state(button_state_e_t _hardware_mock_state)
{
    hardware_mock_state = _hardware_mock_state;
}

void set_mock_button_hardware_system_time(system_time_t _hardware_system_time)
{
    hardware_system_time = _hardware_system_time;
}

void setup_button_hardware_with_mocks(button_hardware_s_t* hardware)
{
    hardware->button_hardware_init = mock_button_hardware_init;
    hardware->button_hardware_get_system_time = mock_button_hardware_get_system_time;
}
