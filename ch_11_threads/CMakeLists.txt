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
  # 04_thread_cleanup.c
  # 05_thread_mutex.c
  # 06_thread_2_mutex.c
  # 07_thread_mutex_simplify.c
  # 08_thread_mutex_timedlock.c
  # 09_thread_lock.c
  # 10_thread_condition.c
  11_thread_barrier.c

  
)

add_executable(
  thread_test ${sources}
)

target_link_libraries(thread_test
  pthread
)
