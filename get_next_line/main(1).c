#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *arr;

    fd = open("check.txt", O_RDONLY);
    arr = get_next_line(fd);
    printf("%s", arr);
}

// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line.h"
// int main(void)
// {
// 	int fd;
// 	char buf[100];
// 	fd = open("41_no_nl", O_RDONLY);
// 	if (fd == -1)
// 		printf("file open error");
// 	else
// 	{
// 		read(fd, buf, sizeof(buf));
// 		printf("%s", buf);
// 		close(fd);
// 	}
// 	return(0);
// }