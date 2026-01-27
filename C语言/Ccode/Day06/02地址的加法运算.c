#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 地址的加(整数)法运算,本事就是地址指向那段内存的偏移
    int a;
    char b;
    double c;

    printf("a 的地址\t %p \n", &a);         // 0xffffcbfc
    printf("a 的地址 + 1\t %p \n", &a + 1); // 0xffffcc00  +4
    // a是一个int类型的内存他的大小为4, 地址 +1  等于地址偏移一个自身内存(4)的大小

    printf("b 的地址\t %p \n", &b);         // 0xffffcbfb
    printf("b 的地址 + 1\t %p \n", &b + 1); // 0xffffcbfc  +1
    // b是一个char类型的内存他的大小为1, 地址 +1  等于地址偏移一个自身内存(1)的大小

    printf("c 的地址\t %p \n", &c);         // 0xffffcbf0
    printf("c 的地址 + 1\t %p \n", &c + 1); // 0xffffcbf8
    // c是一个double类型的内存他的大小为8, 地址 +1  等于地址偏移一个自身内存(8)的大小

    int arr[5] = {1, 3, 5, 7, 9};

    printf("%p \n", arr);  // 0xffffcbd0 首元素的地址
    printf("%p \n", &arr); // 0xffffcbd0 整个数组的地址

    printf("%p \n", arr + 1);  // 首元素的地址 + 1,偏移1个首元素大小字节(+4) 0xffffcbd4
    printf("%p \n", &arr + 1); // 整个数组的地址 + 1,偏移1个数组自身大小字节(+20)  0xffffcbe4

    // 地址与地址不能相加
    // printf("%p \n",arr + &arr);

    // 相同类型的地址跟地址可以相减, 两个地址之间间隔相同元素大小的偏移量
    int d, e, f;
    printf("d:%p \n e:%p \n f:%p \n", &d, &e, &f);

    printf("%d \n", &d - &f);
    return 0;
}
