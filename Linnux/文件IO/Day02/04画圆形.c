#include "myhead.h"
#include <math.h>
// 数学库是动态库 编译时加 -lm

int main(int argc, char const *argv[])
{
    int fd = open("/dev/fb0", O_RDWR);

    if (fd == -1)
    {
        perror("open /dev/fb0 failed!");
        return -1;
    }

    int (*buf)[800] = malloc(800 * 480 * 4);

    // 设置圆心点
    int x0 = 400, y0 = 240;
    // 半径
    int r = 80;

    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            // 直角边的平方小于等于半径的平方,表示该坐标在圆的内部
            if (pow(x0 - x, 2) + pow(y0 - y, 2) <= pow(r, 2))
            {
                buf[y][x] = 0xff00ffff;
            }
            else
            {
                buf[y][x] = 0xffffffff;
            }
        }
    }

    write(fd, buf, 800 * 480 * 4);

    free(buf);
    
    close(fd);

    return 0;
}
