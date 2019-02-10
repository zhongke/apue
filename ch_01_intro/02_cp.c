#include "../apue.h"

#define BUFFSIZE 4096

int
main()
{
        int n;
        char buf[BUFSIZE];

        while ((n = read_lock(STDIN_FILENO, buf, BUFFSIZE)) > 0)
                if (write_lock(STDOUT_FILENO, buf, n) != n)
                        err_sys("write error");

        if (n < 0)
                err_sys("read error");

        exit(0);
}
