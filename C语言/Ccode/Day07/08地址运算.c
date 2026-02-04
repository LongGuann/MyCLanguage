#include <stdio.h>

int main(int argc, char const *argv[])
{
    char arr[12] = "hello world";

    char *p1 = arr;

    char (*p2)[12] = &arr;

    printf("%p %p \n", p1, p2);
    printf("%p \n", p1 + 1);
    printf("%p \n", p2 + 1);

    // 强制类型转换
    int *p3 = (int *)arr; // char *

    printf("%p \n", p3 + 1); //  因为p3是个 int型指针这里+1 偏移一个int(4)字节

    // p3 + 1 偏移4字原始数据 "hello world" 其基地址第一个o的地址
    // p3 是int *型, 解引用按整形解引用读四个字节 "o wo" 转为ascii码 字节一 111 字节二 32  字节三 119  字节四 111

    printf("%d \n", *(p3 + 1)); 

    printf("%d \n", *(char *)(p3 + 1));// 解引用用了类型强转 p3解引用是当前地址向后读四个字节,强转变为char *类型再解引用只读一个字节 

    int num = 0xffaabbcc;
    char *pn = (char *)&num;
    *(pn + 1) = 0x99;
    //pn[2] = 0xee;
    printf("%#x \n", num);
    return 0;
}
