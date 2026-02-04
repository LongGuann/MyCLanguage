#include <stdio.h>

typedef struct node
{
    /* data */
} Node,*PNode; // Node 表示 struct node 类型别名,  PNode 表示 struct node* 类型别名


int main(int argc, char const *argv[])
{
    // 此时 a 不在内存中, 直接存在寄存器中
    // 因为 a 不在内存中,所以他没有内存地址,不可以给该变量使用取址符
    register int a;
    // &a; 错误 a 不在内存中
    // 定义寄存器变量不一定成功（主要看编译器）,如果不成功会自动定义成自动化变量
   
    // int b, *c; // 声明 int 变量 b  和 int * 变量 c

    typedef int b, *c; // 声明 int 类型别名 b, 和 int * 类型别名 c
    return 0;
}
