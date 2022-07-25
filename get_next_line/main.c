#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("41_no_nl", O_RDWR);
	printf("%s", get_next_line(fd));
}