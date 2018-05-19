cmake_minimum_required(VERSION 3.9)
project(yasmin_matam C)

set(CMAKE_C_STANDARD 99)

add_executable(yasmin_matam main.c mainFunctions.c mainFunctions.h animal.c employee.c food.c animal.h employee.h food.h)