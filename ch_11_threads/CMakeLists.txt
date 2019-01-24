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
  # 01_thread_create.c
  # 02_thread_exit.c
  03_thread_exit_stack.c
  
)

add_executable(
  thread_test ${sources}
)

target_link_libraries(thread_test
  pthread
)
