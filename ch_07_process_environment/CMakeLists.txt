project(chapterFirstExample)
cmake_minimum_required(VERSION 2.6)

include_directories(
  $ENV{GMOCK_HOME}/googletest/include
)

link_directories(
)

add_definitions(-std=c11)


set(
  sources
  ../apue_error.c
  # 01_exit_handler.c
  02_command_process.c
  # variables_longjmp.c
  # print_resource_limits.c
)

add_executable(
  thread_test ${sources}
)

target_link_libraries(thread_test
  pthread
)
