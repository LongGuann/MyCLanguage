#include "myhead.h"

int main(int argc, char const *argv[])
{
    int fd = open("test.txt", O_RDWR | O_CREAT, 0777);

    if (fd == -1)
    {
        perror("open test.txt failed!");
        return -1;
    }

    // 先写再读
    char wbuf[] = "hello world!";

    ssize_t ret = write(fd, wbuf, strlen(wbuf));

    if (ret == -1)
    {
        perror("write test.txt failed!");
        return -1;
    }

    char rbuf[50] = "";

    ret = read(fd, rbuf, 50);
    // 0:  没有读到数据.原因读写共享偏移量,上面的写操作已经把光标移动到末尾了,
    // 这时候再读取就是末尾向后读取没有数据
    printf("%ld :  %s \n", ret, rbuf);

    // 解决方案lseek
    /*
    #include <sys/types.h>
    #include <unistd.h>
    // 参数1 fd      : 需要修改偏移量的文件描述符
    // 参数2 offset  : 光标向右(整数)向左(负数)偏移的字节数
    // 参数3 whence  : 偏移参照点 SEEK_SET(以文件起始位置) SEEK_CUR (以当前光标所在的位置) SEEK_END(以文件末尾) 偏移
    // 返回值: 光标便宜后距离起始位置的字节数
    off_t lseek(int fd, off_t offset, int whence);
    */

    lseek(fd, 0, SEEK_SET);

    ret = read(fd, rbuf, 5);
    // 0:  没有读到数据.原因读写共享偏移量,上面的写操作已经把光标移动到末尾了,
    // 这时候再读取就是末尾向后读取没有数据
    printf("%ld :  %s \n", ret, rbuf);

    lseek(fd, 2, SEEK_CUR);

    ret = read(fd, rbuf, 5);
    // 0:  没有读到数据.原因读写共享偏移量,上面的写操作已经把光标移动到末尾了,
    // 这时候再读取就是末尾向后读取没有数据
    printf("%ld :  %s \n", ret, rbuf);

    return 0;
}
