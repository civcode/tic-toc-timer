cmake_minimum_required(VERSION 3.1.0)

project(tic-toc-timer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE debug)

set_property(TARGET ${PROJECT_name} PROPERTY CXX_STANDARD 11)

include_directories (
    ${CMAKE_SOURCE_DIR}/include
)

set(timer_SRC
    ${CMAKE_SOURCE_DIR}/src/tic_toc_timer.cpp
    #${CMAKE_SOURCE_DIR}/src/tic_toc_timer.tpp
    #${CMAKE_SOURCE_DIR}/include/tic_toc_timer.tpp
)

add_library(tictoctimer src/tic_toc_timer.cpp)

add_executable(${PROJECT_NAME} example/timer_example.cpp)
target_link_libraries(${PROJECT_NAME} tictoctimer)
