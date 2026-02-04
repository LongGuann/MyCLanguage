#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 优先级 一般情况下 一元 > 二元 > 三元
    // 赋值操作低于上面的运算符

    // a++ b-- 优先级高于 ++a --b
    // * / % 高于 + -
    // && 高于 ||
    // , 表达式优先级最低

    int a = 1, b = 2, c = 3;

    int d = (a++, b--, c += b);

    printf("%d \n", d);

    return 0;
}
