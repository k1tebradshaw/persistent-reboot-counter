cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(persistent_reboot_counter C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(persistent_reboot_counter main.c)

pico_enable_stdio_usb(persistent_reboot_counter 1)
pico_enable_stdio_uart(persistent_reboot_counter 0)

target_link_libraries(persistent_reboot_counter pico_stdlib hardware_watchdog)

pico_add_extra_outputs(persistent_reboot_counter)
