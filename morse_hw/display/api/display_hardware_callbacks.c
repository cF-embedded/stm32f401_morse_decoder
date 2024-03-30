#include "display_hardware.h"

const display_hardware_s_t display_hardware = {
    display_hardware_init,
    display_hardware_set_char,
    display_hardware_clear,
    display_hardware_set_header,
};