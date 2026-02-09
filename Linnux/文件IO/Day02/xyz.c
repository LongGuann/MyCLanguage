#include "myhead.h"

#define GREEN 0x0000ff00  // 绿色
#define BLACK 0x00000000  // 黑色
#define YELLOW 0x00ffff00 // 黄色
#define RED 0x00ff0000
int main()
{
    // 1、打开液晶屏文件  必须是以可读可写 O_RDWR
    int lcdFd = open("/dev/fb0", O_RDWR);
    if (lcdFd == -1)
    {
        perror("open lcd error");
        return -1;
    }

    // 二维数组
    //   int arr[行][列]
    int colorbuf[480][800] = {0};
    // int (*buf)[800] = malloc(800 *480 *4)
    for (int j = 0; j < 480; j++) // 有多少行
    {
        for (int i = 0; i < 800; i++) // 有多少列
        {
            if (j < 480 / 3) // 前三分之一
            {
                colorbuf[j][i] = 0xFDE850;
            }
            else if (j > 480 / 3 && j < 480 / 3 * 2) // 中间三分之一
            {
                colorbuf[j][i] = 0xAE6AF5;
            }
            else
            {
                colorbuf[j][i] = YELLOW;
            }
        }
    }
    write(lcdFd, colorbuf, sizeof(colorbuf));

    // 4、关闭
    close(lcdFd);

    return 0;
}