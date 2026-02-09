#include "myhead.h"

int main(int argc, char const *argv[])
{
    int fd = open("/dev/fb0", O_RDWR);

    if (fd == -1)
    {
        perror("open /dev/fb0 failed!");
        return -1;
    }

    int (*buf)[800] = malloc(800 * 480 * 4);

    int x0 = 400, y0 = 240;
    int r = 80;
    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            if (pow(x0 - x, 2) + pow(y0 - y, 2) <= pow(r, 2))
            {
                buf[y][x] = 0x00ff0000;
            }
            else
            {
                buf[y][x] = 0xffffff;
            }
        }
    }

    write(fd, buf, 800 * 480 * 4);

    free(buf);
    close(fd);

    return 0;
}
