#include <stdio.h>

int main(int argc, char const *argv[])
{
    int buf[10] = {1, 2, 3, 4};
    // buf本身表示数组首元素(int 型变量)的地址
    // 指针p存储int地址的变量,  p存储了buf的值,所以p与buf的值相等
    int *p = buf;
    printf("%d \n", buf[3]);
    printf("%d \n", p[3]);
    // 0. 声明时意义不同
    // 1. sizeof时 p 与 buf值不相同
    printf("%ld \n", sizeof(buf));
    printf("%ld \n", sizeof(p));
    // 2. &取地址时 p 与 buf值不相同
    printf("%p \n", &buf);
    printf("%p \n", &p);
    // 除了以上3中情况 p 完全等价 buf

    // 数组指针, 存储的是整个数组的地址
    // 本身buf 类型为 int [10] 指向其类型的指针 int (*)[10]
    int (*p1)[10] = &buf;
    printf("%d \n", (*p1)[2]);
    printf("%d \n", p1[0][2]);

    // 注意 [] 优先级高于 * 笔试题中经常出现判断一个变量时指针还是数组
    // 例子下方p2他就是个数组,存储int型的地址
    int *p2[10];

    return 0;
}
