#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // 想在堆空间中申请下面结构的数据
    //  char arr[4];
    //  堆内存是飞地,只能用指针接受其返回值(堆的基地址)
    //  你想让这段堆内存是char arr[4]效果, 你就应该使用该数组首元素地址类型指针接受malloc返回值
    //  这样指针用起来感觉跟数组是一样
    char *str = malloc(4);

    if (str == NULL)
    {
        perror("申请堆空间失败 !");
        return -1;
    }

    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = '\0';
    printf("%s \n", str);

    // 变长数组替代方案就是malloc
    int len;
    printf("你输入你想指定数组长度?\n");
    scanf("%d", &len);

    if (len < 1)
    {
        printf("长度有误! \n");
        return -1;
    }

    // int arr[len]; // 变长数组兼容性不好,而且也不适合大内存数据
    int *arr = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        arr[i] = i * 2;
        printf("arr[%d] = %d \n", i, arr[i]);
    }

    return 0;
}
