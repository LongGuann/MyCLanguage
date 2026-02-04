#include <stdio.h>

int main(int argc, char const *argv[])
{
    int age = 17;
    age = age + 1;
    printf("hello world\n");

    int year = 2008;
    int M = 1;
    int d = 7;
    int h = 10;
    int m = 28;
    int s = 27;
    // %d 接受一个整形(int)数据,并输出
    printf("%d/1/7 10:15:26 \n", 2028);

    printf("%d/%d/%d %d:%d:%d \n", year, M, d, h, m, s);

    return 0;
}
