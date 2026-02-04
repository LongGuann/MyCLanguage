#include <stdio.h>

int main(int argc, char const *argv[])
{
    // getchar它的主要功能是从标准输入（通常是键盘, 带缓冲区）读取一个字符。
    // 这个函数在 <stdio.h> 头文件中声明，
    // 并且返回一个 int 类型的值。这个返回值是读取字符的ASCII码值，如果读取失败或者到达文件末尾，它会返回一个特殊的值 EOF，即“文件结束”标志。

    int num = getchar();

    printf("%c \n", num);

    num = getchar();

    printf("%c \n", num);

    num = getchar();

    printf("%c \n", num);

    num = getchar();

    printf("%c \n", num);

    return 0;
}
