#include <stdio.h>

// #define PI

int main(int argc, char const *argv[])
{

#ifdef PI
    printf("程序中是否声明了一个叫 PI 宏\n");
#else
    printf("程序中是没有定义一个叫 PI 宏\n");
#endif

    // 预定义宏  ifdef 一般根据系统提供的宏判断出当前程序运行的平台, 已经开发模式 DEBUG(调试),产品模式

#ifdef __linux__
    printf("你当前运行的平台是linux \n");
#endif

#ifdef __WIN32__
    printf("你当前运行的平台是Windows \n");
#endif

// 在编译时指令 -DXXXXX 给程序手动定义宏
#ifdef DEBUG
    printf("手动设置为 DEBUG 模式 \n");
#else
    printf("正常 模式 \n");
#endif

    return 0;
}
