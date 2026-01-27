#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("1 \n");
    printf("2 \n");

    int age = 18;
    // 代码 printf("3 \n"); 是否执行受 if语句影响,只有if语句的代码为真时内部代码块才会执行
    if (age >= 28)
    {
        printf("3 \n");
    }

    // if语句内部代码块只有一行时可以省略大括号
    if (age >= 19)
        printf("4 \n");

    // if  else 搭配使用,实现 如果if语句表达式成立执行if语句内的代码,否则执行else语句里的代码
    // if else是非常常用的组合
    int gender = 7; // 假设 1 男  2女
    if (gender == 1)
    {
        printf("你是男生! \n");
    }
    else
    {
        printf("你是女生! \n");
    }

    // if else if 组合
    if (gender == 1)
    {
        printf("你是男生! \n");
    }
    else if (gender == 2)
    {
        printf("你是女生! \n");
    }
    else if (gender == 3)
    {
        printf("你是武装直升机! \n");
    }
    else if (gender == 4)
    {
        printf("你的性别是沃尔玛购物袋! \n");
    }
    else
    {
        printf("你的性别是其他! \n");
    }
    printf("5 \n");
    printf("6 \n");
    printf("7 \n");
    printf("8 \n");
    printf("9 \n");

    int score = 95;

    if (score > 90)
    {
        printf("A \n");
    }
    else if (score > 80)
    {
        printf("B \n");
    }
    else if (score >= 60)
    {
        printf("C \n");
    }
    else
    {
        printf("D \n");
    }

    int money = 100;

    if (money > 9800)
    {
        printf("你是富人 \n");
    }
    if (money >= 110)
    {
        printf("你是中产 \n");
    }
    else
    {
        if (money >= 50)
        {
            printf("你是有钱的底层 \n");
        }
        else if (money >= 10)
        {
            printf("你是普通人 \n");
        }
        else
        {
            printf("你是穷人 \n");
        }

        printf("你是底层 \n");
    }

    return 0;
}
