cmake_minimum_required(VERSION 3.26)
project(sdl2Template)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/libs/SDL2/include)
set(SDL2_LIB_DIR C:/libs/SDL2/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

if ((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") AND NOT (MINGW)))
    # using GCC or CLANG

    # Both, GCC and Clang support the same option set
    # We first turn on Warnings
    # --> https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
    #
    # -Wall stands for All Warnings
    # -Wextra pushes that a bit further
    # -pedantic sets the compiler to use strict ISO C++
    # -Werror treats all warnings as errors so you have to fix them
    add_compile_options(-Wall -Wextra -pedantic) # -Werror)

    # Sanitizer options
    # The following will turn on Debugging (-g flag) and the Address Sanitizer
    # which is turned on with the -fsanitize=address option to the compiler.
    add_compile_options(-g -fsanitize=address,undefined)

    # When we turn on the sanitizer, you also need to instruct the linker that it
    # will be used which happens with the following link option command.
    add_link_options(-g -fsanitize=address,undefined)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    # MSVC uses a different warning flags
    add_compile_options(/W4 /WX)
    add_compile_options(/fsanitize=address /MTd)

endif()

add_executable(sdl2Template main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
