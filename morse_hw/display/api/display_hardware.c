#include "display_hardware.h"
#include "../../inc/main.h"
#include "../ssd1306/inc/GFX.h"

#define CHAR_OFFSET 5

I2C_HandleTypeDef hi2c1;
static DMA_HandleTypeDef hdma_i2c1_tx;

/* periphal init */
static void i2c_init(void);
static void dma_init(void);

void display_hardware_init(void)
{
    dma_init();
    i2c_init();
    SSD1306_init();
    SSD1306_display_clear();
}

void display_hardware_set_char(char char_to_display)
{
    static char_x_offset = 0;
    GFX_draw_string(char_x_offset, 5, char_to_display, WHITE, BLACK, 1, 1);
    char_x_offset += CHAR_OFFSET;
    SSD1306_display_repaint();
}

void display_hardware_clear(void)
{
    SSD1306_display_clear();
}

void display_hardware_set_header(void)
{
    GFX_draw_string(20, 20, "cf-embedded.pl", WHITE, BLACK, 1, 1);
    GFX_draw_string(1, 10, "---------------------", WHITE, BLACK, 1, 1);
    SSD1306_display_repaint();
}

static void i2c_init(void)
{
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 400000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = MORSE_DISPLAY_I2C_SCL | MORSE_DISPLAY_I2C_SDA;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(MORSE_DISPLAY_I2C_PORT, &GPIO_InitStruct);

    __HAL_RCC_I2C1_CLK_ENABLE();
    if(HAL_I2C_Init(&hi2c1) != HAL_OK)
    {
        Error_Handler();
    }

    HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
}

static void dma_init(void)
{
    __HAL_RCC_DMA1_CLK_ENABLE();

    hdma_i2c1_tx.Instance = DMA1_Stream6;
    hdma_i2c1_tx.Init.Channel = DMA_CHANNEL_1;
    hdma_i2c1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_i2c1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_i2c1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_i2c1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_i2c1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_i2c1_tx.Init.Mode = DMA_NORMAL;
    hdma_i2c1_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_i2c1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;

    if(HAL_DMA_Init(&hdma_i2c1_tx) != HAL_OK)
    {
        Error_Handler();
    }

    __HAL_LINKDMA(&hi2c1, hdmatx, hdma_i2c1_tx);

    HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}
