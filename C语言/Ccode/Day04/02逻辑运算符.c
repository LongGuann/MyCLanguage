#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 逻辑非(取反)
    int age = 17;
    if (!(age >= 18))
    {
        printf("测试 \n");
    }

    int num = 0;
    // if (num != 0) // num 非0
    if (num) // 真是非0   假0
    {
        printf("num不等于零 \n");
    }

    if (num == 0)
    if (!num)
    {
        printf("num等于零 \n");
    }
    

    return 0;
}
