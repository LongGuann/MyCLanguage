#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[] = "hello";
    char str2[] = "helloS";

    size_t len = strlen(str1); // 5

    int ret = 0; // 默认为0表示没问题

    for (int i = 0; i <= len; i++) // 从字符串首字母直到到\0都要比较
    {
        if (str1[i] - str2[i] != 0)
        {
            ret = str1[i] - str2[i];
            break;
        }
    }

    printf("%d \n",ret);
    

    return 0;
}
