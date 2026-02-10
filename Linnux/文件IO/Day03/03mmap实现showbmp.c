#include "myhead.h"
#include "bmp.h"

void show_bmp(char *src_path, int x0, int y0, int (*buf)[800])
{
    int bmp_fd = open(src_path, O_RDONLY);
    if (bmp_fd == -1)
    {
        perror("bmp open failed!");
        return;
    }

    struct tagBITMAPFILEHEADER bmp_header;

    ssize_t ret = read(bmp_fd, &bmp_header, sizeof(bmp_header));

    if (bmp_header.bfType != 0x4D42)
    {
        printf("%s 不是一个bmp图片! \n", src_path);
        close(bmp_fd);
        return;
    }

    struct tagBITMAPINFOHEADER bmp_info;
    ret = read(bmp_fd, &bmp_info, sizeof(bmp_info));
    int width = bmp_info.biWidth;
    int height = bmp_info.biHeight;
    // 读取bmp图片像素信息
    // 装小图片的数组
    unsigned char *bmp_buf = malloc(width * height * 3);
    ret = read(bmp_fd, bmp_buf, width * height * 3);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int i = y * width + x;
            unsigned char b = bmp_buf[i * 3 + 0];
            unsigned char g = bmp_buf[i * 3 + 1];
            unsigned char r = bmp_buf[i * 3 + 2];

            if ((height - 1 - y) + y0 < 480 && x + x0 < 800)
            {
                buf[(height - 1 - y) + y0][x + x0] = 0x0 | b | g << 8 | r << 16;
            }
        }
    }

    close(bmp_fd);
}

int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/fb0", O_RDWR);

    if (lcd_fd == -1)
    {
        perror("open /dev/fb0 failed!");
        return -1;
    }

    // 建立内存映射
    int (*buf)[800] = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);

    if (buf == (void *)-1)
    {
        perror("内存映射失败! \n");
        return -1;
    }

    show_bmp("./4.bmp", 10, 120, buf);
    show_bmp("./1.bmp", 10, 10, buf);
    //show_bmp("./2.bmp", 400, 120, buf);
    show_bmp("./3.bmp", 600, 200, buf);

    // 解除内存映射
    /*
参数：
    addr： 需要撤销映射的内存的起始地址  -> mmap()函数的返回值  
    length：撤销的长度
返回值：
    成功：0
    失败：-1
    */
    munmap(buf, 800 * 480 * 4);
    buf = NULL;
    close(lcd_fd);

    return 0;
}
