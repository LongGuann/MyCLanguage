#include <stdio.h>

int main(int argc, char const *argv[])
{

    // "nihao" 是一个字符串常量,返回首字母地址, 需要char类型地址变量(char *)存储其地址
    char *str1 = "nihao";
    char str_arr[] = "NIHAO";
    char *str2 = str_arr;

    printf("%s \n", str1);
    printf("%c \n", *(str1 + 2));
    printf("%c \n", str1[2]);
    // str1指向的是字符串常量不可修改
    // str1[2] = 'H'; // 段错误

    printf("%s \n", str2);
    printf("%c \n", str2[2]);
    str2[2] = 'h';
    printf("%s \n", str2);

    // 一维数组存字符串常量首字母地址
    char *arr[3] = {"hello", "world", "aaa"};
    // arr数组长度为3 其内部存储的是三个字符串常量的首字母地址
    printf("%ld \n", sizeof(arr));
    printf("%c \n", *(arr[0] + 1));
    printf("%c \n", arr[0][1]);
    printf("%c \n", arr[1][2]);
    // printf("%d \n",  arr[2][4]); // 错误越界, 随机数
    // arr[0][1] = 'E'; // 段错误

    char arr1[3][6] = {"hello", "world", "aaa"};

    printf("%ld \n", sizeof(arr1));
    printf("%s \n", arr1[0]);
    printf("%c \n", arr1[0][1]);
    printf("%d \n", arr1[2][4]); // 正确
    arr1[0][1] = 'E';
    printf("%s \n", arr1[0]);

    int a[2][3] = {1, 2};
    printf("%d", a[1>2][!1]);
    return 0;
}
