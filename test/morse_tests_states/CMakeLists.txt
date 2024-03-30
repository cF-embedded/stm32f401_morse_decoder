cmake_minimum_required(VERSION 3.10)
project(morse_tests_states)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_DEBUG "-Og -g")

set(TEST_SOURCES
	test.cpp
	main.cpp
)

set(CPP_SRCS

)

set(C_SRCS
	../../morse/src/morse.c
	../../morse_hw/button/api/button.c
	../mocks/button/button_hardware_mock.c
	../mocks/timer/timer_hardware_mock.c
	../mocks/led/led_hardware_mock.c
	../mocks/buzzer/buzzer_hardware_mock.c
	../mocks/display/display_hardware_mock.c
	../../cbuf/cbuf.c
)

set(INCLUDE_DIRS
	../../morse
	../../morse_hw
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${CMAKE_PROJECT_NAME} ${TEST_SOURCES} ${C_SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTEST_LIBRARIES} pthread)



