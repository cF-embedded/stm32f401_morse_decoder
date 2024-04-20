# Morse Code for STM32

## Overview

This repository contains a comprehensive API for encoding and decoding Morse code, designed to be used with any STM32 microcontroller equipped with a GPIO and timer functionality. The API offers functionalities for initializing the Morse code handling system, setting the encoding and decoding speed, and managing Morse code operations in a precise and efficient manner.

## Key Features

- **Initialize Morse System**: Set up the Morse code system with specific hardware settings.
- **Control Encoding and Decoding Speed**: Adjust and set the speed for encoding and decoding Morse code.
- **Manage Morse Code Operation**: Start, stop, and update the Morse code processing.
- **Handle Morse Code Input and Output**: Monitor and manage the input and output of Morse signals.

## Core Files

- `morse.h`: Main API declarations for Morse code operations.
- `morse.c`: Implementation of the Morse code encoding and decoding functionalities.
- `morse_characters.h`: Contains definitions of Morse code for each character.
- `morse_times.h`: Timing definitions for standard Morse code timings.
- `morse_type.h`: Data types and enums used across the Morse code API.
- `morse_tests.c`: Unit tests for validating the functionality of the API.

## Testing

- Project includes unit tests using the googletest, ensuring reliability and proper functionality of all Morse code operations.

## Dependencies

- **Standard C Libraries**: Utilized for core functionalities.
- **Google test**: Employed for unit testing.
- **Stm32 HAL**: Hardware abstraction layer from STM company.

## Contribution

- Contributions are welcome. Please adhere to the standard pull request process for proposing changes or enhancements.

## License

- This project is released under the MIT License.

## Author

- Developed by cf-embedded.pl
