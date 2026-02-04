#include <stdio.h>

int main(int argc, char const *argv[])
{
    // a变量名表示一段4字节内存,存储一个整型数字
    int a = 4;
    // 指针就是一个存放其他变量地址的变量
    // 指针的类型就是它指向的那段内存空间的类型后加*号
    int *p1 = &a;

    char str[6] = "hello";
    // str 首元素地址, 存储str的指针就是 "首元素类型 *" 类型
    char *p2 = str; 

    // &str 整个数组,整个数组是 char [6] 类型,存储他的指针就应该是char (*)[6]
    // 因为优先级问题一定要打个小括号
    char (*p3)[6] = &str;

    return 0;
}
