#include <stdio.h>

// 判断一个数字是否为偶数
#define IS_EVEN(x) ((x) % 2 == 0)

// c语言规范复杂宏,多行代码块的宏必须使用do...while(0)
#define PRINT_NUMBERS(n)                        \
    do                                          \
    {                                           \
        int i;                                  \
        for (i = 0; i <= (n); i++)               \
        {                                       \
            if (IS_EVEN(i))                     \
            {                                   \
                printf("num %d is even \n", i); \
            }                                   \
            else                                \
            {                                   \
                printf("num %d is odd \n", i);  \
            }                                   \
        }                                       \
    } while (0)

int main(int argc, char const *argv[])
{
    PRINT_NUMBERS(100);
    return 0;
}
