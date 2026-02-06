#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd;
	while(fd = open("/mnt/hgfs/MyCLanguage/Linnux/文件IO/1.txt", O_RDWR | O_APPEND, 0777))
	{
		printf("%d \n", fd);
		
	}
	return 0;
}
