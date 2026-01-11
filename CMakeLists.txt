cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

set(PROJECT_NAME infinite-chess)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Game/game.cpp

    src/Board/boardTexture.cpp
    src/Board/boardSprite.cpp
    src/Board/board.cpp

    src/Game/window.cpp
    src/Game/callback.cpp
)

add_subdirectory(ext/sfml)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    sfml-graphics
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/res"
    "${CMAKE_BINARY_DIR}/bin/res"
)