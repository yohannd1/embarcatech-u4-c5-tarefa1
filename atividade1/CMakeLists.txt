cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(atividade1 C CXX ASM)

pico_sdk_init()

add_executable(atividade1
    src/main.c
)

pico_set_program_name(atividade1 "atividade1")
pico_set_program_version(atividade1 "0.1")

pico_enable_stdio_uart(atividade1 1)
pico_enable_stdio_usb(atividade1 1)

target_include_directories(atividade1 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(atividade1
    pico_stdlib
    hardware_timer
)

pico_add_extra_outputs(atividade1)
