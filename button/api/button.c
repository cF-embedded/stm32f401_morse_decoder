/******************************************************************************
 *chip: any uC
 *brief: Button driver
 *details: Default configuration , initialize and most significant function
 *author: cF-embedded.pl
 ******************************************************************************/

#include "button.h"
#include <stddef.h>

button_status_e_t button_init(button_s_t* button, button_hardware_s_t hardware)
{
    if(button == NULL)
    {
        return BUTTON_STATUS_ERROR;
    }

    button->hardware = hardware;

    button->hardware.button_hardware_init();
    button->last_state = BUTTON_STATE_RELEASED;
    button->last_debounce_time = 0;

    return BUTTON_STATUS_OK;
}

button_state_e_t button_get_state(button_s_t* button)
{
    if(button == NULL)
    {
        return BUTTON_STATE_RELEASED;
    }

    button->last_state = button->hardware.button_hardware_read_state();
    return button->last_state;
}

button_state_e_t button_get_state_with_debounce(button_s_t* button, const system_time_t debounce_time_ms)
{
    system_time_t current_time = button->hardware.button_hardware_get_system_time();

    button_state_e_t current_state = button->hardware.button_hardware_read_state();

    if((current_time - button->last_debounce_time) > debounce_time_ms)
    {
        if(current_state != button->last_state)
        {
            button->last_debounce_time = current_time;
            button->last_state = current_state;
        }
    }
}
