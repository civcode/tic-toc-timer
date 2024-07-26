cmake_minimum_required(VERSION 3.1.0)

project(tictoctimer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE debug)

include_directories (
    ${CMAKE_SOURCE_DIR}/include
)

set(timer_SRC
    ${CMAKE_SOURCE_DIR}/src/tic_toc_timer.cpp
)

add_library(tictoctimer STATIC src/tic_toc_timer.cpp)

target_include_directories(tictoctimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(tic_toc_timer_example example/timer_example.cpp)
target_link_libraries(tic_toc_timer_example tictoctimer)

# Install instructions are needed for FetchContent to work 
install(TARGETS tictoctimer DESTINATION lib)
install(FILES include/tic_toc_timer.h include/tic_toc_timer.tpp DESTINATION include)






