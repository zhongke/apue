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
  # 01_makethread.c
  # 02_thread_recursive_mutex.c
  # 03_env_non_reentrant.c
  # 04_env_reentrant.c
  # 05_env_compatible.c
  06_sync_signal.c

  
)

add_executable(
  thread_test ${sources}
)

target_link_libraries(thread_test
  pthread
)
