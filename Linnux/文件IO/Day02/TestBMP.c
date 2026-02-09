#include "myhead.h"
#include "bmp.h"

// 假设的LCD参数，需要根据实际情况修改
#define LCD_WIDTH 800
#define LCD_HEIGHT 480
#define LCD_SIZE (LCD_WIDTH * LCD_HEIGHT * 4) // ARGB8888格式
// BMP文件头结构体
#pragma pack(push, 1)
typedef struct
{
    unsigned short bfType;      // 文件类型，必须是"BM"
    unsigned int bfSize;        // 文件大小
    unsigned short bfReserved1; // 保留字
    unsigned short bfReserved2; // 保留字
    unsigned int bfOffBits;     // 从文件头到实际位图数据的偏移字节数
} BITMAPFILEHEADER;

typedef struct
{
    unsigned int biSize;         // 信息头大小
    int biWidth;                 // 图像宽度
    int biHeight;                // 图像高度
    unsigned short biPlanes;     // 位平面数，必须为1
    unsigned short biBitCount;   // 每像素位数
    unsigned int biCompression;  // 压缩类型
    unsigned int biSizeImage;    // 图像大小
    int biXPelsPerMeter;         // 水平分辨率
    int biYPelsPerMeter;         // 垂直分辨率
    unsigned int biClrUsed;      // 实际使用的颜色数
    unsigned int biClrImportant; // 重要颜色数
} BITMAPINFOHEADER;
#pragma pack(pop)
// LCD显存指针（需要初始化）
unsigned int *lcd_p = NULL;

/**
 * 初始化LCD显存
 * @return 成功返回0，失败返回-1
 */
int lcd_init(void)
{
    // 打开LCD设备文件（根据实际情况修改设备路径）
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("open lcd error");
        return -1;
    }

    // 内存映射
    lcd_p = mmap(NULL, LCD_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (lcd_p == MAP_FAILED)
    {
        perror("mmap lcd error");
        close(lcd_fd);
        return -1;
    }

    close(lcd_fd);
    return 0;
}

/**
 * 清屏函数
 * @param color 清屏颜色（ARGB格式）
 */
void lcd_clear(unsigned int color)
{
    if (!lcd_p)
        return;

    for (int i = 0; i < LCD_WIDTH * LCD_HEIGHT; i++)
    {
        lcd_p[i] = color;
    }
}

/**
 * 显示BMP图片
 * @param bmpFile BMP文件名
 * @param posX    显示位置的X坐标
 * @param posY    显示位置的Y坐标
 * @return 成功返回0，失败返回-1
 */
int bmp_show(char *bmpFile, int posX, int posY)
{
    if (!lcd_p)
    {
        printf("LCD not initialized!\n");
        return -1;
    }

    if (posX < 0 || posY < 0)
    {
        printf("Invalid position!\n");
        return -1;
    }

    // 1. 打开图片文件
    int bmpFd = open(bmpFile, O_RDONLY);
    if (bmpFd == -1)
    {
        perror("open bmp error");
        return -1;
    }

    // 2. 读取文件头
    BITMAPFILEHEADER bfh;
    if (read(bmpFd, &bfh, sizeof(bfh)) != sizeof(bfh))
    {
        perror("read file header error");
        close(bmpFd);
        return -1;
    }

    // 检查文件类型是否为"BM"
    if (bfh.bfType != 0x4D42) // "BM"的十六进制表示
    {
        printf("Not a BMP file: %s\n", bmpFile);
        close(bmpFd);
        return -1;
    }

    // 3. 读取信息头
    BITMAPINFOHEADER bih;
    if (read(bmpFd, &bih, sizeof(bih)) != sizeof(bih))
    {
        perror("read info header error");
        close(bmpFd);
        return -1;
    }

    // 只支持24位BMP
    if (bih.biBitCount != 24)
    {
        printf("Only support 24-bit BMP (current: %d-bit)\n", bih.biBitCount);
        close(bmpFd);
        return -1;
    }

    // 检查是否有压缩（只支持无压缩）
    if (bih.biCompression != 0)
    {
        printf("Compressed BMP not supported\n");
        close(bmpFd);
        return -1;
    }

    int width = bih.biWidth;
    int height = abs(bih.biHeight); // 使用绝对值处理正负高度

    // 4. 计算每行字节数（4字节对齐）
    int line_bytes = width * 3;                     // 每行像素数据的字节数
    int line_bytes_aligned = (line_bytes + 3) & ~3; // 4字节对齐

    // 5. 分配内存
    unsigned char *bmpbuf = malloc(line_bytes_aligned * height);
    if (!bmpbuf)
    {
        perror("malloc error");
        close(bmpFd);
        return -1;
    }

    // 6. 移动到像素数据开始位置
    lseek(bmpFd, bfh.bfOffBits, SEEK_SET);

    // 7. 读取像素数据
    int bytes_read = read(bmpFd, bmpbuf, line_bytes_aligned * height);
    if (bytes_read != line_bytes_aligned * height)
    {
        perror("read pixel data error");
        free(bmpbuf);
        close(bmpFd);
        return -1;
    }

    // 8. 判断BMP图像方向
    // biHeight为正表示图像是倒置的（BMP标准格式）
    // biHeight为负表示图像是正置的
    int is_top_down = (bih.biHeight < 0);

    // 9. 显示图像
    for (int y = 0; y < height; y++)
    {
        // 计算源数据行
        int src_y;
        if (is_top_down)
        {
            // 正置图像：从上到下读取
            src_y = y;
        }
        else
        {
            // 倒置图像：从下到上读取（BMP标准）
            src_y = height - 1 - y;
        }

        unsigned char *src_line = bmpbuf + src_y * line_bytes_aligned;

        // 显示到LCD
        for (int x = 0; x < width; x++)
        {
            int lcd_x = posX + x;
            int lcd_y = posY + y;

            // 检查边界
            if (lcd_x >= LCD_WIDTH || lcd_y >= LCD_HEIGHT || lcd_x < 0 || lcd_y < 0)
                continue;

            // 获取BGR颜色值
            unsigned char b = src_line[x * 3 + 0];
            unsigned char g = src_line[x * 3 + 1];
            unsigned char r = src_line[x * 3 + 2];

            // BGR -> ARGB8888 (Alpha通道设为0xFF不透明)
            unsigned int pixel = 0xFF000000 | (r << 16) | (g << 8) | b;

            // 写入LCD显存
            lcd_p[lcd_y * LCD_WIDTH + lcd_x] = pixel;
        }
    }

    // 10. 清理资源
    free(bmpbuf);
    close(bmpFd);

    printf("Display BMP: %s (%dx%d) at (%d,%d)\n",
           bmpFile, width, height, posX, posY);

    return 0;
}

/**
 * 释放LCD资源
 */
void lcd_deinit(void)
{
    if (lcd_p)
    {
        munmap(lcd_p, LCD_SIZE);
        lcd_p = NULL;
    }
}

/**
 * 测试主函数
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <bmp_file> [x] [y]\n", argv[0]);
        return -1;
    }

    // 初始化LCD
    if (lcd_init() < 0)
    {
        return -1;
    }

    // 清屏为白色
    lcd_clear(0xFFFFFFFF);

    // 解析位置参数
    int posX = 0;
    int posY = 0;

    if (argc >= 3)
        posX = atoi(argv[2]);
    if (argc >= 4)
        posY = atoi(argv[3]);

    // 显示BMP图片
    int ret = bmp_show(argv[1], posX, posY);

    // 暂停一下以便查看结果
    sleep(2);

    // 清理资源
    lcd_deinit();

    return ret;
}