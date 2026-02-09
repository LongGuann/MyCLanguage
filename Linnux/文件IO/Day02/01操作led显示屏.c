#include "myhead.h"

#define LCD_PIXEL_SIZE (800 * 480 * 4)

int main(int argc, char const *argv[])
{
    int fd = open("/dev/fb0", O_RDWR);
    if (fd == -1)
    {
        perror("open /dev/fb0 failed!");
        return -1;
    }

    // 6818开发板是800*480分辨率 32位色深的屏幕
    // 向开发板写入写入数据, 应该将 800*480*4字节数据写入到屏幕设备文件中
    // 本质上是一个 int buf[800 * 480] 数组int自身4个字节
    // char buf[800 * 480 * 4]
    int *buf = malloc(LCD_PIXEL_SIZE);

    for (int i = 0; i < 800 * 480; i++)
    {
        // 0xAARRGGBB
        buf[i] = 0x0000ff00;
    }

    // 将上述数据写入到屏幕文件中
    ssize_t ret = write(fd, buf, LCD_PIXEL_SIZE);

    if (ret == -1)
    {
        perror("write lcd failed!");
        return -1;
    }

    free(buf);
    close(fd);

    return 0;
}
