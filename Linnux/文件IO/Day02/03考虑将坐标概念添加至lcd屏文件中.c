#include "myhead.h"

int main(int argc, char const *argv[])
{
    int fd = open("/dev/fb0", O_RDWR);

    if (fd == -1)
    {
        perror("open /dev/fb0 failed!");
        return -1;
    }
    /*
    // 二维数组
    // int buf[480][800] 首地址指针
    int (*buf)[800] = malloc(800 * 480 * 4);

    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            if (x >= 100 && x <= 250 && y >= 100 && y <= 250)
            {
                buf[y][x] = 0x00aabbcc;
            }
            else
            {
                buf[y][x] = 0x0000ff00;
            }
        }
    }
    */
    // 一维数组 int buf[800 * 480]
    int *buf = malloc(800 * 480 * 4);

    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            if (x >= 400 && x <= 600 && y >= 100 && y <= 300)
            {
                buf[y * 800 + x] = 0x00ffcc00;
            }
            else
            {
                buf[y * 800 + x] = 0x00ffffff;
            }
        }
    }

    write(fd, buf, 800 * 480 * 4);

    free(buf);
    close(fd);

    return 0;
}
