#include "myhead.h"

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("缺少参数,请启动时输入源文件路径 目标文件路径");
        return -1;
    }
    const char *srcPath = argv[1];
    const char *targetPath = argv[2];

    // 判断文件是否存在
    if (access(srcPath, F_OK) == -1)
    {
        printf("%s 文件不存在!", srcPath);
        return -1;
    }

    int srcFd = open(srcPath, O_RDONLY);
    if (srcFd == -1)
    {
        perror("打开源文件失败!");
        return -1;
    }

    // 创建并打开目标文件
    int tFd = open(targetPath, O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (tFd == -1)
    {
        perror("打开目标文件失败!");
        return -1;
    }
    // 第一部拿到源文件的大小
    ssize_t size = lseek(srcFd, 0, SEEK_END);
    lseek(srcFd, 0, SEEK_SET);
    // 创建一个buf
    char *buf = malloc(1024);
    // ret 真实读取了多少内容,total已经拷贝了多少内容
    ssize_t ret = 0, total = 0;
    while (ret = read(srcFd, buf, 1024))
    {
        // 读了多少内容就写多少内容
        write(tFd, buf, ret);
        total += ret;
        system("clear");
        printf("当前进度: %ld/%ld \n", total, size);
    }

    free(buf);
    close(srcFd);
    close(tFd);

    return 0;
}
