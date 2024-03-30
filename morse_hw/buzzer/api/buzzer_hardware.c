#include "buzzer_hardware.h"
#include "../../inc/main.h"

void buzzer_hardware_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOE_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(MORSE_BUZZER_PORT, MORSE_BUZZER_PORT_PIN, GPIO_PIN_RESET);

    /*Configure GPIO pin : PE6 */
    GPIO_InitStruct.Pin = MORSE_BUZZER_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(MORSE_BUZZER_PORT, &GPIO_InitStruct);
}

void buzzer_hardware_on(void)
{
    HAL_GPIO_WritePin(MORSE_BUZZER_PORT, MORSE_BUZZER_PIN, GPIO_PIN_SET);
}

void buzzer_hardware_off(void)
{
    HAL_GPIO_WritePin(MORSE_BUZZER_PORT, MORSE_BUZZER_PIN, GPIO_PIN_RESET);
}
