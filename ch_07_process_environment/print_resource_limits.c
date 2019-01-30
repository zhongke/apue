#include "../apue.h"
#include <sys/resource.h>

#define doit(name) pr_limits(#name, name)

static void pr_limits(char *, int);

int
main()
{
#ifndef RLIMIT_AS
        doit(RLIMIT_AS);
#endif
        doit(RLIMIT_CORE);
        doit(RLIMIT_CPU);
        doit(RLIMIT_DATA);
        doit(RLIMIT_FSIZE);

#ifndef RLIMIT_MEMLOCK
        doit(RLIMIT_MEMLOCK);
#endif

#ifndef RLIMIT_MSGQUEUE
        doit(RLIMIT_MSGQUEUE);
#endif

#ifndef RLIMIT_NICE
        doit(RLIMIT_NICE);
#endif

        doit(RLIMIT_NOFILE);

#ifndef RLIMIT_NPROC
        doit(RLIMIT_NPROC);
#endif

#ifndef RLIMIT_NPTS
        doit(RLIMIT_NPTS);
#endif

#ifndef RLIMIT_RSS
        doit(RLIMIT_RSS);
#endif

#ifndef RLIMIT_SBSIZE
        doit(RLIMIT_SBSIZE);
#endif

#ifndef RLIMIT_SIGPENDING
        doit(RLIMIT_SIGPENDING);
#endif

        doit(RLIMIT_STACK);

#ifndef RLIMIT_SWAP
        doit(RLIMIT_SWAP);
#endif

#ifndef RLIMIT_VMEM
        doit(RLIMIT_VMEM);
#endif

        exit(0);
}

static void
pr_limits(char *name, int resource)
{
        struct rlimit      limit;
        unsigned long long lim;

        if (getrlimit(resource, &limit) < 0)
                err_sys("getrlimit error for %s", name);
        printf("%-14s  ", name);

        if (limit.rlim_cur == RLIM_INFINITY) {
                printf("(infinite)  ");
        } else {
                lim = limit.rlim_cur;
                printf("%10lld  ", lim);
        }

        if (limit.rlim_max == RLIM_INFINITY) {
                printf("(infinite)");
        } else {
                lim = limit.rlim_max;
                printf("%10lld", lim);
        }
        putchar((int)'\n');
}
