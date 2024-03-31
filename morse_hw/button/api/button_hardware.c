#include "button_hardware.h"
#include "../../inc/main.h"

void button_hardware_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOE_CLK_ENABLE();

    /*Configure GPIO pins : PE4 */
    GPIO_InitStruct.Pin = MORSE_BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(MORSE_BUTTON_PORT, &GPIO_InitStruct);
}

button_state_e_t button_hardware_read_state(void)
{
    if(HAL_GPIO_ReadPin(MORSE_BUTTON_PORT, MORSE_BUTTON_PIN) == GPIO_PIN_SET)
    {
        return BUTTON_STATE_RELEASED;
    }
    else
    {
        return BUTTON_STATE_PRESSED;
    }
}

system_time_t button_hardware_get_system_time(void)
{
    return 0;
}
