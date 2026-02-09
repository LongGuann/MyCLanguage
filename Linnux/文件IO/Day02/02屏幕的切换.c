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

    // int buf[800 * 480];
    // char buf[800 * 480 * 4]
    unsigned char *buf = malloc(LCD_PIXEL_SIZE);
    while (1)
    {
        for (int i = 0; i < 800 * 480 * 4; i += 4)
        {
            // 设备小端序 +0 Blue, +1 Green, +2 Red, +3 Alpha
            buf[i + 0] = 0xff;
            buf[i + 1] = 0;
            buf[i + 2] = 0;
            buf[i + 3] = 0;
        }
        // 将文件偏移量移回到文件的起始位置
        lseek(fd, 0, SEEK_SET);

        ssize_t ret = write(fd, buf, LCD_PIXEL_SIZE);

        if (ret == -1)
        {
            printf("write lcd failed!");
            return -1;
        }
        sleep(2);

        for (int i = 0; i < 800 * 480 * 4; i += 4)
        {
            // 设备小端序 +0 Blue, +1 Green, +2 Red, +3 Alpha
            buf[i + 0] = 0;
            buf[i + 1] = 0xff;
            buf[i + 2] = 0;
            buf[i + 3] = 0;
        }
        // 将文件偏移量移回到文件的起始位置
        lseek(fd, 0, SEEK_SET);
        ret = write(fd, buf, LCD_PIXEL_SIZE);

        if (ret == -1)
        {
            printf("write lcd failed!");
            return -1;
        }

        sleep(2);

        for (int i = 0; i < 800 * 480 * 4; i += 4)
        {
            // 设备小端序 +0 Blue, +1 Green, +2 Red, +3 Alpha
            buf[i + 0] = 0;
            buf[i + 1] = 0;
            buf[i + 2] = 0xff;
            buf[i + 3] = 0;
        }
        // 将文件偏移量移回到文件的起始位置
        lseek(fd, 0, SEEK_SET);
        ret = write(fd, buf, LCD_PIXEL_SIZE);

        if (ret == -1)
        {
            printf("write lcd failed!");
            return -1;
        }
        sleep(2);
    }

    free(buf);
    close(fd);

    return 0;
}
