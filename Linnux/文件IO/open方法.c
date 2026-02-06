#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int fd = open("/mnt/hgfs/MyCLanguage/Linnux/文件IO/1.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1)
    {
        perror("open O_CREAT txt failed\n");
    }
    printf("%d\n", fd);
    return 0;
}
