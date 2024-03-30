#include "led_hardware.h"
#include "../../inc/main.h"

void led_hardware_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOE_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(MORSE_LED_PORT, MORSE_LED_PIN, GPIO_PIN_RESET);

    /*Configure GPIO pin : PE6 */
    GPIO_InitStruct.Pin = MORSE_LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(MORSE_LED_PORT, &GPIO_InitStruct);
}

void led_hardware_on(void)
{
    HAL_GPIO_WritePin(MORSE_LED_PORT, MORSE_LED_PIN, GPIO_PIN_SET);
}

void led_hardware_off(void)
{
    HAL_GPIO_WritePin(MORSE_LED_PORT, MORSE_LED_PIN, GPIO_PIN_RESET);
}
