cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(PROJ_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message("Build type: " ${CMAKE_BUILD_TYPE})

#
# Core project settings
#
project(stm32_f401_morse_decoder)
enable_language(C CXX ASM)

#
# Core MCU flags, CPU, instruction set and FPU setup
# Needs to be set properly for your MCU
#
set(CPU_PARAMETERS
    -mthumb
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
)

# Set linker script
set(linker_script_SRC ${PROJ_PATH}/device/STM32F401CC_FLASH.ld)
set(EXECUTABLE ${CMAKE_PROJECT_NAME})

#
# List of source files to compile
#
set(sources_SRCS
        device/startup_stm32f401vctx.s    
        src/main.c
        src/stm32f4xx_hal_msp.c
        src/stm32f4xx_it.c
        src/system_stm32f4xx.c
        morse/src/morse.c
        morse_hw/button/api/button.c
        periphal/src/dma.c
        periphal/src/gpio.c
        periphal/src/i2c.c
        periphal/src/tim.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
        drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
        cbuf/cbuf.c
    # Put here your source files, one in each line, relative to CMakeLists.txt file location
)

#
# Include directories
#
set(include_path_DIRS
         CMSIS
         inc
         drivers/STM32F4xx_HAL_Driver/Legacy
         drivers/STM32F4xx_HAL_Driver/Inc
         morse/inc
         morse_hw/button/api
         morse_hw/buzzer/api
         morse_hw/display/api
         morse_hw/led/api
         morse_hw/timer/api
         periphal/inc
         cbuf
    # Put here your include dirs, one in each line, relative to CMakeLists.txt file location
)

#
# Symbols definition
#
set(symbols_SYMB
        "DEBUG"
        "STM32F401xC"
        "USE_HAL_DRIVER"
    # Put here your symbols (preprocessor defines), one in each line
    # Encapsulate them with double quotes for safety purpose
)

# Executable files
add_executable(${EXECUTABLE} ${sources_SRCS})

# Include paths
target_include_directories(${EXECUTABLE} PRIVATE ${include_path_DIRS})

# Project symbols
target_compile_definitions(${EXECUTABLE} PRIVATE ${symbols_SYMB})

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    -O0 -g3 -ggdb
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    -T${linker_script_SRC}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    --specs=nosys.specs
    -u _printf_float
    -Wl,--start-group
    -lc
    -lm
    -lstdc++
    -lsupc++
    -Wl,--end-group
    -Wl,--print-memory-usage
)

# Post-build commands
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.bin
    # Add OpenOCD command to flash the MCU
    COMMAND openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program ${EXECUTABLE}.elf verify reset exit"
)