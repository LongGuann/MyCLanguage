#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int (*p)[4] = arr;
    int (*p1)[3][4] = &arr;

    printf("%d \n", p[1][2]);
    printf("%d \n", *(*(*p1 + 1) + 2));
    printf("%d \n", (*p1)[1][2]);
    printf("%d \n", p1[0][1][2]);

    // q是一个数组长度为4,里面的元素类型int *
    int a = 12;
    int *q[4] = {&a};
    // int *q1[3][4] q1是个数组长度为3,
    // 子元素类型int *[4] 这个类型是数组类型,数组子元素类型 int *
    int *q1[3][4] = {{&a}, {&a, &a, &a, &a}, {&a}};
    //  int (*q2[3])[4] 数组子元素类型 int (*)[4] 指针指向长度为4 int型数组
    int (*q2[3])[4];
    */

    // int arr[3];

    // int *p = arr;

    // char arr[3];
    // char *p = arr;

    char *arr[3] = {"hello", "world", "aaa"};
    char **p = arr;

    printf("%s \n", arr[0]);
    printf("%c \n", arr[0][1]);
    printf("%s \n", arr[1]);
    printf("%s \n", p[0]);
    printf("%c \n", p[0][1]);
    printf("%s \n", p[1]);
/*
    总结：
    1、在定义语句中，判断这个变量是数组还是指针，通过运算符的优先级判断：  ()  >  [ ]   >  *
    如果变量首先粘住的是[ ]，那么这个变量一定是一个数组
    如果变量首先粘着的是* ,那么这个变量一定是一个指针

2、判断一个指针变量的类型，变量名遇到*号的时候，记住，一定要停下来，剩余的东西都是用来修饰这个指针所指向的内容是怎么样的
    比如：char *(*p)[3] = &buf;  // p 指向 char * [3] 指针数组 //p ---指针数组指针
    比如：char (**p)[3];  // p 指向 char (*) [3] 数组指针 //p ---数组指针指针
    比如：char **p[3];  // p 数组 char ** 二级指针// p ---二级指针数组

*/    

    return 0;
}
