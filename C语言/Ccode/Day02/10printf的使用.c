#include <stdio.h>

int main(int argc, char const *argv[])
{
    // printf 按照指定的字符串模板格式输出数据
    /*
    %s     字符串格式
    %d     整型  int
    %c     字符型  char
    %hd   短整型  short int
    %hhd  字符型的ascii码   char 数据对应的ascii码 的值
    %f      单精度浮点型（实型） float
    %lf    双精度浮点型  double
    %ld   long  int
    %lld   long long int
    %x     十六进制
    %#x   十六进制 并且 十六进制 的前缀 0x也会打印出来
    %o      八进制
    %#o   八进制 并且  八进制的前缀0打印出来
    %e      以科学计数法的方式将浮点数打印出来
    %p     打印内存的地址
    */
    float a = 314;
    printf("%e \n", a);

    // 字段宽度, 表示输出数据最少占几列
    int b = 7;
    printf("A%4dA%-4dA\n", b,b);

    float c = 1.234;
     printf("@%10f@\n", c);


    // scanf  按照指定的字符串模板格式输入数据
    return 0;
}
