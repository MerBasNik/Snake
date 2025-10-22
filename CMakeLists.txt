#cmake_minimum_required(VERSION 4.0)
#project(snake)
#
#set(CMAKE_CXX_STANDARD 20)
#
#set(optimizations, "-Ofast -funrool -loops -mavx2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${optimizations}")
#set(SFML_ROOT "/opt/homebrew/opt/sfml")
#set(SFML_INCLUDE_DIR "/opt/homebrew/include")
#set(SFML_LIBRARY_DIR "/opt/homebrew/lib")
#
#include_directories(${SFML_INCLUDE_DIR})
#link_directories(${SFML_LIBRARY_DIR})
#
## Находим библиотеки SFML
#find_library(SFML_GRAPHICS_LIB sfml-graphics)
#find_library(SFML_WINDOW_LIB sfml-window)
#find_library(SFML_SYSTEM_LIB sfml-system)
#find_library(SFML_AUDIO_LIB sfml-audio)
#find_library(COCOA_LIB Cocoa)
#
#message(STATUS "SFML_GRAPHICS_LIB: ${SFML_GRAPHICS_LIB}")
#message(STATUS "SFML_WINDOW_LIB: ${SFML_WINDOW_LIB}")
#message(STATUS "SFML_SYSTEM_LIB: ${SFML_SYSTEM_LIB}")
#
#find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
#
#add_executable(snake_game
#        main.cpp
#        Src/Game/Game.cpp
#        Src/Field/Field.cpp
#        Src/Apple/Apple.cpp
#        Src/Snake/Snake.cpp
#        Src/Graphics/Graphics.cpp
#)
#
#target_link_libraries(snake_game
#        ${SFML_GRAPHICS_LIB}
#        ${SFML_WINDOW_LIB}
#        ${SFML_SYSTEM_LIB}
#        ${COCOA_LIB}
#)
#
#add_executable(snake main.cpp
#        Src/Field/Field.cpp
#        Src/Field/Field.h
#        Src/Apple/Apple.cpp
#        Src/Apple/Apple.h
#        Src/Snake/Snake.cpp
#        Src/Snake/Snake.h
#        Src/Game/Game.cpp
#        Src/Game/Game.h
#        Src/Graphics/GameGr.cpp
#        Src/Graphics/GameGr.h
#        Src/Graphics/Graphics.cpp
#        Src/Graphics/Graphics.h)

cmake_minimum_required(VERSION 4.0)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)

# Явно указываем пути для Apple Silicon
set(SFML_INCLUDE_DIR "/opt/homebrew/include")
set(SFML_LIBRARY_DIR "/opt/homebrew/lib")

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

add_executable(snake_game
        main.cpp
        temp/Game/Game.cpp
        Src/Field/Field.cpp
        Src/Apple/Apple.cpp
        Src/Snake/Snake.cpp
        Src/Graphics/Graphics.cpp
)

# Прямое указание библиотек
target_link_libraries(snake_game
        sfml-graphics
        sfml-window
        sfml-system
)

# Обязательные фреймворки для macOS
find_library(COCOA_LIB Cocoa)
find_library(IOKIT_LIB IOKit)
find_library(FOUNDATION_LIB Foundation)
target_link_libraries(snake_game
        ${COCOA_LIB}
        ${IOKIT_LIB}
        ${FOUNDATION_LIB}
)