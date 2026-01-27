#include <stdio.h>

int main(int argc, char const *argv[])
{
    // while循环与for循环的区别:
    // 一般来说，while更注重循环条件，
    // for更注重循环次数。 
    // 当然它们是可以相互替换的。
    int M = 777;
    printf("请输入月份! \n");
    //  while (scanf("%d", &M) == 0)
    while (!scanf("%d", &M))
    {
        printf("输入失败!请重新输入! \n");
        while (getchar() != '\n') // 清除从缓冲区刷新出来的垃圾
            ; //表示函数是空
        
    }
    // for (; scanf("%d", &M) == 0; )
    // {
    //     printf("输入失败!请重新输入! \n");
    //     while (getchar() != '\n') //清除从缓冲区刷新出来的垃圾
    //     {
            
    //     }
    // }
    


    printf("你输入的值为 %d \n", M);
    return 0;
}
