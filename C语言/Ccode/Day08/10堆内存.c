#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // 栈由系统自动开辟自动释放
    // 堆程序员手动开辟手动释放
    // 堆是唯一可被开发者自定义的区段

    // 相比栈内存，堆的总大小仅受限于物理内存，在物理内存允许的范围内，系统对堆内存的申请不做限制。
    // 相比栈内存，堆内存从下往上增长。

    // void * malloc(size_t size)
    // 参数 size 你想申请的内存字节数
    // 返回值 void *
    //      成功: 申请好的这段堆空间的地址
    //      失败: NULL

    // 申请一段堆内存存放 int 类型数据
    // 堆内存是匿名的，只能由指针来访问。
    int *p = malloc(sizeof(int));

    if (p == NULL)
    {
        perror("申请堆内存失败 \n");
        return -1;
    }else{
        printf("%p",p);
    }

    *p = 77;

    return 0;
}
