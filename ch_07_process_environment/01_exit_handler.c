#include "../apue.h"

static void my_exit1();
static void my_exit2();

int
main()
{
        if (atexit(my_exit2) != 0)
                err_sys("can't register my_exit2");

        if (atexit(my_exit1) != 0)
                err_sys("can't register my_exit1");
        if (atexit(my_exit1) != 0)
                err_sys("can't register my_exit1");

        printf("main is done\n");
        return(0);
}

static void
my_exit1()
{
        printf("first exit handler\n");
}

static void
my_exit2()
{
        printf("second exit handler\n");
}
