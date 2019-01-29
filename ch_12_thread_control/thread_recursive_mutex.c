#include "../apue.h"
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

extern int makethread(void *(*)(void *), void *);

struct to_info
{
   void            (*to_fn)(void *);    /* function */
   void            *to_arg;             /* argument */
   struct timespec to_wait;             /* time to wait */
};

#define SECTONSEC 1000000000    /* seconds to nanoseconds */
#if !defined(CLOCK_REALTIME) || defined(BSD)
#define clock_nanosleep(ID, FL, REQ, REM)    nanosleep((REQ), (REM))
#endif

#ifndef CLOCK_REALTIME
#define CLOCK_REALTIME 0
#define USECTONSEC 1000    /* microseconds to nanoseconds */


void
clock_gettime(int id, struct timespec *tsp)
{
   struct timeval tv;

   gettimeofday(&tv, NULL);
   tsp->tv_sec = tv.tv_sec;
   tsp->tv_nsec = tv.tv_usec * USECTONSEC;
}
#endif

void *
timeout_helper(void *arg)
{
   struct to_info *tip;
   tip = (struct to_info *)arg;
   clock_nanosleep(CLOCK_REALTIME, 0, &tip->to_wait, NULL);
   (*tip->to_fn)(tip->to_arg);
   free(arg);
   return(0);
}
