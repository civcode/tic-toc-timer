cmake_minimum_required(VERSION 3.0.0)

project(tic-toc-timer)

include_directories (
    ${CMAKE_SOURCE_DIR}/include
)

set(timer_SRC
    ${CMAKE_SOURCE_DIR}/src/tic_toc_timer.cpp
)

add_library(tictoctimer src/tic_toc_timer.cpp)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} tictoctimer)
