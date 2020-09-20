CMAKE_MINIMUM_REQUIRED(VERSION 3.17.3)
project(PlantsVsZombies VERSION 1.0.0)

add_compile_options(-std=c99 -Wall -Wextra -Wconversion -Wpedantic -D_REENTRANT)

add_executable(PlantsVsZombiesExecutable main.c)

target_link_libraries(PlantsVsZombiesExecutable SDL2)
target_link_libraries(PlantsVsZombiesExecutable SDL2_image)
