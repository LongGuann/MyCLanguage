#include <stdio.h>

int main(int argc, char const *argv[])
{

    // 预定义宏是C语言中标准编译器预先定义的宏（官方定义了，不需要我们定义，我们需要时直接使用这些宏就行），常用的预定义宏如下
    printf("%s | %s \n", __DATE__, __TIME__);

    int a = 12;

    printf("%d  ----%d   %s \n", a, __LINE__, __FUNCTION__);

    a++;

    printf("%d  ----%d %s \n", a, __LINE__, __FILE__);
    a += 10;

    return 0;
}
