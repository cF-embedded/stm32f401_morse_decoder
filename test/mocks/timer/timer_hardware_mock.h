#ifndef __TIMER_HARDWARE_MOCK_H
#define __TIMER_HARDWARE_MOCK_H

#include "../../../morse_hw/timer/api/timer_hardware.h"

void mock_timer_hardware_init(void);

time_ms_t mock_timer_hardware_get_system_time(void);

void mock_timer_hardware_clear(void);

/* helper functions for mocks */
void set_mock_timer_hardware_time(time_ms_t);

void setup_timer_hardware_with_mocks(timer_hardware_s_t*);

#endif /*__TIMER_HARDWARE_MOCK_H */
