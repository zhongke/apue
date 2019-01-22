project(chapterFirstExample)
cmake_minimum_required(VERSION 2.6)

include_directories(
  $ENV{GMOCK_HOME}/googletest/include
)

link_directories(
)

# add_definitions(-std=c++17)


set(
  sources
  ../apue_error.c
  01_print_thread.c
  
)

add_executable(
  test ${sources}
)
