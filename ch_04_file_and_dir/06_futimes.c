#include "../apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
        int i, fd;
        struct stat statbuf;
        struct timespec times[2];

        for (i = 0; i < argc; ++i) {
                /* fetch current times */
                if (stat(argv[i], &statbuf) < 0) {
                        err_ret("%s: stat error", argv[i]);
                        continue;
                }

                /* truncate */
                if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {
                        err_ret("%s: open error", argv[i]);
                        continue;
                }
                times[0] = statbuf.st_atime;
                times[0] = statbuf.st_mtime;

                /* reset times */
                if (futimes(fd, times) < 0)
                        err_ret("%s: futimes error", argv[i]);
                close(fd);
        }
        exit(0);
}
