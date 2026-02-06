#include "myhead.h"

int main(int argc, char const *argv[])
{
    int fd = open("test.txt", O_RDWR | O_APPEND);

    if (fd == -1)
    {
        perror("open test.txt failed!");
        return -1;
    }

    char buf[] = "0123456789";

    // 注意: 参数三写入数据长度不能大于真实要写入的内容,否则会写人垃圾数
    ssize_t ret = write(fd, buf, 40);

    printf("%ld \n", ret);

    return 0;
}
