#include "timer_hardware.h"
#include "../../inc/main.h"

volatile static time_ms_t time_increment;

TIM_HandleTypeDef htim1;

void timer_hardware_init(void)
{
    __HAL_RCC_TIM1_CLK_ENABLE();

    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    htim1.Instance = TIM1;
    htim1.Init.Prescaler = 0;
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.Period = 65535;
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim1.Init.RepetitionCounter = 0;
    htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    if(HAL_TIM_Base_Init(&htim1) != HAL_OK)
    {
        Error_Handler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if(HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if(HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }

    time_increment = 0;

    HAL_NVIC_SetPriority(TIM1_BRK_TIM9_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQHandler);
}

time_ms_t time_hardware_get_system_time(void)
{
    return time_increment;
}

void timer_hardware_clear(void)
{
    time_increment = 0;
}

void TIM1_BRK_TIM9_IRQHandler(void)
{
    time_increment++;
}
