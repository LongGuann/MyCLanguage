#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 29;

    int flag = 1; // flag 是一个假设  1 表示假设他是质数   0 不是质数
//sqirt()开根号  ，数字乘法对称的一个数 乘以 大的数 得到目标结果
//平方根就是对称点，作用：减少循环次数
    for (int i = 2; i < sqrt(num); i++)
    {
        printf("%d ", i);
        if (num % i == 0) // 数字被除自身和1以外其他数整除, 表示不是质数,没有必要继续循环了
        {
            flag = 0;
            break;
        }
    }
    printf("\n");

    printf("flag = %s \n", flag == 1 ? "是质数" : "不是质数");

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         break;
    //     }

    // }

    return 0;
}
