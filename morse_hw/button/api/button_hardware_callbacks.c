#include "button_hardware.h"

const button_hardware_s_t button_hardware = {
    button_hardware_init,
    button_hardware_get_system_time,
    button_hardware_read_state,
};