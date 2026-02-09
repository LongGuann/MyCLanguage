#include "myhead.h"
#include "bmp.h"

int main(int argc, char const *argv[])
{
    int bmp_fd = open("./46.bmp", O_RDONLY);
    // 文件头
    struct tagBITMAPFILEHEADER bmp_header;

    ssize_t ret = read(bmp_fd, &bmp_header, sizeof(bmp_header));

    printf("读取文件头信息 %ld 字节\n", ret);

    char *arr = (char *)&bmp_header.bfType;

    printf("%c %c \n", arr[0], arr[1]);

    printf("%#x == 0x4D42\n", bmp_header.bfType);

    printf("整个 BMP 文件的总大小 %d \n", bmp_header.bfSize);

    printf("像素数据相对于文件起始位置的偏移量（即文件头 + 信息头的总字节数） %d \n", bmp_header.bfOffBits);

    struct tagBITMAPINFOHEADER bmp_info;
    ret = read(bmp_fd, &bmp_info, sizeof(bmp_info));
    printf("读取文件信息头 %ld 字节\n", ret);

    printf("信息头本身的大小 %d \n", bmp_info.biSize);
    printf("重点 图像宽度（像素） %d \n", bmp_info.biWidth);
    printf("重点 图像高度（像素） %d \n", bmp_info.biHeight);
    printf("每个像素的位数 %d \n", bmp_info.biBitCount);
    printf("重点 位图的大小，以字节为单位 %d \n", bmp_info.biSizeImage);
    printf("水平分辨率（像素 / 米） %d \n", bmp_info.biXPelsPerMeter);
    printf("垂直分辨率（像素 / 米） %d \n", bmp_info.biYPelsPerMeter);

    // 以后绘制bmp图片时,请让bmp图片宽度保持能被4整除
    // 若图片不能被4整除bmp图片会自己实现像素对齐
    // BMP 格式规定：每一行像素数据的总字节数必须向上取整到 4 的倍数，不足的部分用 0 填充（填充字节无实际意义）。

    close(bmp_fd);
    return 0;
}
