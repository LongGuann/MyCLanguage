#include "myhead.h"

int main(int argc, char const *argv[])
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open test.txt failed!");
        return -1;
    }

    char arr[11] = "";
    ssize_t ret = read(fd, arr, 10);
    printf("ret: %ld, str: %s \n", ret, arr);

    bzero(arr, 10);
    ret = read(fd, arr, 10);
    printf("ret: %ld, str: %s \n", ret, arr);

    bzero(arr, 10);
    ret = read(fd, arr, 10);
    printf("ret: %ld, str: %s \n", ret, arr);

    bzero(arr, 10);
    ret = read(fd, arr, 10);
    printf("ret: %ld, str: %s \n", ret, arr);

    bzero(arr, 10);
    ret = read(fd, arr, 10);
    printf("ret: %ld, str: %s \n", ret, arr);

    return 0;
}
