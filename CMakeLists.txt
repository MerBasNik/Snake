cmake_minimum_required(VERSION 4.0)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)

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

target_link_libraries(snake_game
        sfml-graphics
        sfml-window
        sfml-system
)

find_library(COCOA_LIB Cocoa)
find_library(IOKIT_LIB IOKit)
find_library(FOUNDATION_LIB Foundation)
target_link_libraries(snake_game
        ${COCOA_LIB}
        ${IOKIT_LIB}
        ${FOUNDATION_LIB}
)