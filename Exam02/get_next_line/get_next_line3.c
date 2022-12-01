#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

char *ft_strdup(char *str)
{
	int len = 0;
	int i = -1;
	char *r_str;

	len = ft_strlen(str);
	r_str = malloc(len + 1);
	if (!r_str)
		return (0);
	while(str[++i])
		r_str[i] = str[i];
	r_str[i] = 0;
	return (r_str);
}

char *get_next_line(int fd)
{
	int i = 0;
	int r = 0;
	char c;
	char buf[7000000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	r = read(fd, &c, 1);
	while (r > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break;
		r = read(fd, &c, 1);
	}
	buf[i] = 0;
	if (i == 0 && r <= 0)
		return (0);
	return (ft_strdup(buf));
}
