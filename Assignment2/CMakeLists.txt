cmake_minimum_required(VERSION 3.0.0)
project(Assignment2 VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(fork-join fork-join.c)
add_executable(rendezvous rendezvous.c)
add_executable(barrier barrier.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
#target_include_directories(fork-join PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")