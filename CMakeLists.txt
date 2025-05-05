cmake_minimum_required(VERSION 3.1.0)

project(tictoc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE debug)

include_directories (
    ${CMAKE_SOURCE_DIR}/include
)

set(SOURCE
)

add_library(tictoc STATIC src/timer.cpp)

target_include_directories(tictoc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(example example/example.cpp)
target_link_libraries(example tictoc)

# Install instructions are needed for FetchContent to work 
install(TARGETS tictoc DESTINATION lib)
install(FILES include/tictoc/timer.hpp include/tictoc/timer.tpp DESTINATION include/tictoc)

