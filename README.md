# RoscoeOS

## Overview

This project implements a basic Real-Time Operating System (RTOS) for the STM32F103C8T6 microcontroller using C. The RTOS provides essential features like task management, context switching, and inter-task communication mechanisms such as queues, semaphores, and mutexes.


## Getting Started

### Prerequisites

- **ARM GCC Toolchain**: You need the ARM GCC toolchain to build and compile the project. You can download it from [ARM Developer](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm).
- **ST-Link**: An ST-Link or compatible programmer/debugger for flashing the firmware to the STM32F103C8T6 microcontroller.
- **Make**: A build automation tool to run the provided Makefile.

### Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/parkerstafford/RoscoeOS.git
    cd my_rtos_project
    ```

2. Build the project:
    ```sh
    make
    ```

3. The build output (firmware file) will be in the `build/` directory.

### Flashing the Firmware

Use `st-flash` or a similar tool to flash the firmware to your STM32F103C8T6 microcontroller.

```sh
st-flash write build/RoscoeOS.elf 0x08000000
