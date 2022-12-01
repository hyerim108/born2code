#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	int i = 0;
	int r = 0;
	char c;
	char *buf = malloc(10000);

	while ((r = read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if(c == '\n')
			break;
	}
	if ((!buf[i - 1] && !r) || r == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	return (buf);
}
