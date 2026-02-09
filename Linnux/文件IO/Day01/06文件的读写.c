#include "myhead.h"

int main(int argc, char const *argv[])
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open text.txt failed!");
        return -1;
    }

    char arr[50] = "";
    // 参数1 读取文件的文件描述符
    // 参数2 将读取到的内容写入到指定地址的内存中
    // 参数3 想要读取的字节数(可以大于实际文件中的内容)
    // 返回值: 实际读取到的字节数
    ssize_t ret = read(fd, arr, 49);

    printf("ret: %ld \n", ret);
    printf("arr: %s \n", arr);

    close(fd);

    return 0;
}
