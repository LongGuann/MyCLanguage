#include "myhead.h"

#define BLACK 0xff000000  // 黑色
#define RED 0x00ff0000    // 红色
#define GREEN 0x0000ff00  // 绿色
#define YELLOW 0x00ffff00 // 黄色
#define BLUE 0x89b4e0     // 0x89b4e0

int main()
{
    // 1、打开液晶屏文件/dev/fb0，
    int lcdfd = open("/dev/fb0", O_RDWR);
    if (lcdfd == -1)
    {
        printf("open lcd error\n");
        return -1;
    }
    // 2、颜色
    int color[5] = {BLACK, RED, GREEN, YELLOW, BLUE};
    int colorbuf[800 * 480];
    int index = 0;

    while (1)
    {
        memset(colorbuf, 0, sizeof(colorbuf));
        for (int i = 0; i < 800 * 480; i++)
        {
            colorbuf[i] = color[index];
        }
        // 将准备好的数据 写入 液晶屏文件中
        write(lcdfd, colorbuf, 800 * 480 * 4);

        sleep(1);
        index = (index + 1) % 5;   // 下一次显示另外一种颜色 取余控制在数组范围
        lseek(lcdfd, 0, SEEK_SET); // 偏移文件位置到开头
    }

    // 4、关闭文件
    close(lcdfd);
}
