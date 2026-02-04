#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int a = 12;
    // 此时变量a只读不可修改
    // a = 13;
    // 警告 类型不匹配
    // a 是const int 类型 而我们的指针 int *
    // int *p = &a;
    // *p = 14;
    // printf("%d \n", a);

    const int *p1 = &a; // p1 变量指向 const int型的地址,p1 变量不是只读. const不是修饰变量p1的

    printf("%d \n", *p1);

    // *p1 = 14;

    const int b = 17;

    p1 = &b;

    printf("%d \n", *p1);

    int c = 123, d = 456;

    int *const p = &c;
    // p = &d; // 错误 此处的const用来修饰指针变量p, 指针变量p变为只读不可修改

    // 假如你的指针 指向const int 数据类型的地址, 并且又想让指针变量自身只读

    const int *const p2 = &b;

    // *p2 = 12; b 是 const int 不可修改
    // p2 = &a;  p2 是 const p2 ,p2自身也不可修改

    const int *p3; // 表示指向的内存不可改变,指针自身可变(可以指向其他地址)
    // int const *p3; // 与 const int *p3 等价
    // int *const p3; // 表示指针自身不可变(不可以指向其他地址), 但是指向的那段内存可修改
    const int * const p3; // 表示指针自身不可变, 指向的内存也不可变
    return 0;
}
