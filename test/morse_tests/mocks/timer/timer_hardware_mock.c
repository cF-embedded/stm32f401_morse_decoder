#include "timer_hardware_mock.h"

static time_ms_t mock_time = 0;

void mock_timer_hardware_init(void)
{
    mock_time = 0;
}

time_ms_t mock_timer_hardware_get_system_time(void)
{
    return mock_time;
}

void mock_timer_hardware_clear(void)
{
    mock_time = 0;
}

void set_mock_timer_hardware_time(time_ms_t time)
{
    mock_time = time;
}
