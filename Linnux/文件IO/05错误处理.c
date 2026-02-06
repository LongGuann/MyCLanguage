#include "myhead.h"
// 全局错误码
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    printf("%d \n", errno);

    perror("sss");

    open("1.txt", O_RDWR);
    // 如果库函数、系统调用出错了，全局错误码 errno 会随之改变
    printf("%d \n", errno);

    // string.h 提供了一个方法用于将errno转换为对应错误信息字符串
    printf("%s  \n", strerror(errno));

    perror("sss");

    // 如果库函数、系统调用没出错，全局错误码 errno 不会改变
    open("test.txt", O_RDWR);
    printf("%d \n", errno);

    open("/home/gec/Desktop/txt/my.txt", O_RDWR);
    // 新的错误出现,errno错误码就会被更新
    printf("%d \n", errno);
    printf("%s \n", strerror(errno));

    if (open("a.txt", O_RDWR) == -1)
    {
        perror("打开a.txt失败");
    }

    // 2. 使用strerror()，返回错误信息交给用户自行处理：
    if (open("a.txt", O_RDWR) == -1)
    {
        printf("打开a.txt失败: %s\n", strerror(errno));
    }

    return 0;
}
