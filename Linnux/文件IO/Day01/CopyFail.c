#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define BUFFER_SIZE 4096

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("用法: %s <源文件> <目标文件>\n", argv[0]);
        return -1;
    }

    const char *source_file = argv[1];
    const char *dest_file = argv[2];

    int src_fd = open(source_file, O_RDONLY);
    if (src_fd == -1)
    {
        perror("打开源文件失败");
        return -1;
    }

    lseek(src_fd, 0, SEEK_SET);

    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1)
    {
        perror("创建目标文件失败");
        close(src_fd);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    printf("开始复制文件: %s -> %s\n", source_file, dest_file);

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
    {
        char *ptr = buffer;
        ssize_t remaining = bytes_read;

        while (remaining > 0)
        {
            bytes_written = write(dest_fd, ptr, remaining);
            if (bytes_written == -1)
            {
                perror("写入失败");
                close(src_fd);
                close(dest_fd);
                return -1;
            }

            remaining -= bytes_written;
            ptr += bytes_written;
        }
    }

    if (bytes_read == -1)
    {
        perror("读取失败");
        close(src_fd);
        close(dest_fd);
        return -1;
    }

    printf("\n文件复制完成\n");

    close(src_fd);
    close(dest_fd);

    return 0;
}