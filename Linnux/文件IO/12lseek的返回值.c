#include "myhead.h"

int main(int argc, char const *argv[])
{
    int fd = open("test.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open test.txt failed!");
        return -1;
    }
    // lseek返回值:  成功偏移后光标距离起始位置的字节数
    //              失败: -1
    // 当参数三位 SEEK_SET 时 参数二不能为负
    ssize_t ret = lseek(fd, 3, SEEK_SET);
    ret = lseek(fd, -1, SEEK_SET);

    printf("lseek ret:%ld \n", ret);

    char buf[50] = "";
    read(fd, buf, 50);

    printf("buf:%s \n", buf);

    // 利用lseek返回值读取文件的大小
    int pfd = open("文件描述符原理.png", O_RDONLY);
    // 将偏移量移动到文件的末尾,lseek返回值就是文件末尾到起始位置的总字节数刚好就是文件的大小
    ssize_t file_size = lseek(pfd,0,SEEK_END);
    printf("文件描述符原理.png 图片大小为 %ld \n", file_size);

    // 注意: 
    // 1. lseek函数可以将文件位置调整到任意的位置，可以是已有数据的地方，也可以是未有数据的地方，假设调整到文件末尾之后的某个地方，那么文件将会形成所谓“空洞”
    //    当参数三位 SEEK_SET 时 参数二不能为负
    // 2. lseek函数只能对普通文件调整文件位置，不能对管道文件调整。
    // 3. lseek函数的返回值是调整后的文件位置距离文件开头的偏移量，单位是字节

    return 0;
}
