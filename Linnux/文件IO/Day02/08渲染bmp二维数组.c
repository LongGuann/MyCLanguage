#include "myhead.h"

int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("open lcd fd failed!");
        return -1;
    }

    // 我们发现bmp图一般情况下格式头占54字节,读取bmp图片时,跳过前54字节之后的每个字节都是像素了
    // bmp图片时24位图,三个字节是一像素
    int bmp_fd = open("./1.bmp", O_RDONLY);

    if (bmp_fd == -1)
    {
        perror("open bmp_fd failed!");
        return -1;
    }

    // bmp 24位图一像素3字节,只能用unsigned char 数组读取
    unsigned char *bmp_buf = malloc(800 * 480 * 3);
    // 跳过头部信息
    lseek(bmp_fd, 54, SEEK_SET);
    read(bmp_fd, bmp_buf, 800 * 480 * 3);

    // 写入6818的lcd屏幕800 * 480 * 4
    int (*buf)[800] = malloc(800 * 480 * 4);


    // bmp图片像素是从下往上从左到右, 颠倒垂直坐标
    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            int index = y * 800 + x;
            unsigned char blue = bmp_buf[index * 3 + 0];
            unsigned char green = bmp_buf[index * 3 + 1];
            unsigned char red = bmp_buf[index * 3 + 2];
            // 479 - y 目的就是上下颠倒
            buf[479 - y][x] =  0x0 | blue | green << 8 | red << 16;
        }
    }

    write(lcd_fd, buf, 800 * 480 * 4);

    free(bmp_buf);
    free(buf);
    close(bmp_fd);
    close(lcd_fd);

    return 0;
}
