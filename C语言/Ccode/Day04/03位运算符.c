#include <stdio.h>

int main(int argc, char const *argv[])
{
    char a = 0x0f;

    printf("%#hhx \n", a);
    printf("%#hhx \n", ~a); // 按位取反

    char b = 0b10011100;
    char c = 0b11110101;
    // &位与  0b1001 0100  0x94
    // |位或  0b1111 1101  0xfd
    printf("%#hhx \n", b & c); // 位与运算
    printf("%#hhx \n", b | c);

    // ^ 按位异或  1 ^ 1 = 0  0 ^ 0 = 0   0 ^ 1 = 1  1 ^ 0 = 1
    char d = 0b10010101;
    char e = 0b11111010;
    // 按位异或 0b01101111  0x6f
    printf("%#hhx \n", d ^ e);

    // 问: 你有几种方法交换两个变量的值
    int x = 77, y = 19;

    // 方法一:推荐 中间变量法
    // int temp = x;
    // x = y;
    // y = temp;
    // 方法二: 加减法
    // x = x + y;
    // y = x - y;
    // x = x - y;
    // 方法三: 异或法

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    
    printf("x= %d y=%d \n", x, y);

    return 0;
}
