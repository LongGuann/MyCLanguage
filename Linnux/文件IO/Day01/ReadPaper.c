#include "myhead.h"

int main()
{
	int fd = open("1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open 1.txt failed!");
		return -1;
	}
	char read_arr[512] = "";
	ssize_t ret = read(fd, read_arr, 511);
	while (ret != 0)
	{
		printf("%s", read_arr);
		bzero(read_arr, 511);
		ret = read(fd, read_arr, 511);
	}
	printf("\nThe Papler is END! \n");
	return 0;
}
