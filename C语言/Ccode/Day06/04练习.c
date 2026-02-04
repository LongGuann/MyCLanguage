#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[] = "www.baidu.com";
    printf("%c \n", str[0]);
    printf("%c \n", 0 [str]);
    printf("%c \n", *str);
    printf("%c \n", *(str + 0));

    printf("%p \n", &str);
    printf("%p \n", &str + 1);
    // 我们发现 %s 本质接受一个地址,%s从这个地址向后读取字符直到\0
    printf("%s \n", str);
    printf("%s \n", str + 10);

    int arr[5];

    scanf("%c", arr); // 等价于scanf("%c", &(arr[0]));

    scanf("%c", arr + 1); // 等价于scanf("%c", &(arr[1]));
    printf("%c", *arr);
    printf("%c", arr + 1);
    return 0;
}
