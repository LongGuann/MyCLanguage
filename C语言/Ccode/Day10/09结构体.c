#include <stdio.h>
#include <string.h>

// 结构体数据类型定义
typedef struct dog
{
    char name[10];
    int age;
    int color;
    double weight;
} Dog; // 建议给结构体气的别名首字母大写

typedef struct cat
{
    char name[10];
    int age;
} Cat;

// 因为 typedef 功能与结构体配合实现匿名结构体

typedef struct
{
    char name[20];
    int age;
    char id[19];
    int rank;
} Student;

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    // 声明了一个叫做woof的变量,这个变量的数据类型  struct dog  结构体
    struct dog woof;
    Dog d1;

    // 声明一个变量 tom 他的数据类型是 struct cat
    struct cat tom;
    Cat tom2;

    Student lee;

    // typedef 类型别名, 简化调用
    // 以下方代码为例 给 unsigned long long 起了个别名焦 size_t
    // typedef unsigned long long size_t
    size_t len = strlen("hello");

    typedef unsigned char uchar; // uchar 就是 unsigned char 别名

    uchar a = 255;
    // char a1 = 255;

    printf("%d \n", sizeof(uchar));

    // typedef 会出复杂笔试题

    // int num; // 声明变量 num 其类型为 int
    // typedef int num;  // 创建 int 类型的别名 num

    // int (*arr)[4];// 数组指针
    // typedef int (*arr)[4]; // int (*)[4] 类型别名为 arr

    // int (*func)(int , int); // 函数指针
    typedef int (*func)(int, int); // func是个类型别名特指 int (*)(int , int) 类型

    int (*p)(int a, int b) = add;

    printf("%d \n", p(100, 77));

    func q = add;

    printf("%d \n", q(11, 33));
    return 0;
}
