#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd;

	fd = open("42", O_RDONLY);
	printf("%s", get_next_line(fd));
	// system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	// while (1);
}
