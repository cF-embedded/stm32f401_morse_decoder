#include "timer_hardware.h"

const timer_hardware_s_t timer_hardware = {
    timer_hardware_init,
    timer_hardware_get_system_time,
    timer_hardware_clear,
};