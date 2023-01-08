cmake_minimum_required(VERSION 3.10)

# set the project name
project(ChainOfResponsibility LANGUAGES CXX)

add_compile_options(
    -Werror
    -Wall
    -Wextra
    -Wpedantic
)

# add the executable
add_executable(${CMAKE_PROJECT_NAME} 
    main.cpp)