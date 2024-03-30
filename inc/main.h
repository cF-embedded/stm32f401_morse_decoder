/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f401xc.h"
#include "stm32f4xx_hal.h"

    extern I2C_HandleTypeDef hi2c1;

    void Error_Handler(void);

#define PC14_OSC32_IN_Pin        GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port  GPIOC
#define PC15_OSC32_OUT_Pin       GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define PH0_OSC_IN_Pin           GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port     GPIOH
#define PH1_OSC_OUT_Pin          GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port    GPIOH
#define SWDIO_Pin                GPIO_PIN_13
#define SWDIO_GPIO_Port          GPIOA
#define SWCLK_Pin                GPIO_PIN_14
#define SWCLK_GPIO_Port          GPIOA
#define SWO_Pin                  GPIO_PIN_3
#define SWO_GPIO_Port            GPIOB

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
