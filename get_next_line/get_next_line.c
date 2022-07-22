/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:12:48 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/22 19:37:39 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_line(char *backup)
{
	char	*buf;
	int		i;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i] != '\n' && backup[i])
		i++;
	buf = (char *)malloc(sizeof(char) * (i + 2));
	if (!buf)
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		buf[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		buf[i] = backup[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	ft_read(int fd, char **backup)
{
	char	*arr;
	char	*buf;
	int		size;

	arr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!arr)
		return (0);
	size = read(fd, arr, BUFFER_SIZE);
	if (size <= 0)
	{
		free(arr);
		return (0);
	}
	arr[size] = '\0';
	buf = *backup;
	*backup = ft_strjoin(buf, arr);
	free(arr);
	free(buf);
	return (size);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	int			size;

	size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (size > 0 && !ft_strchr(backup, '\n'))
	{
		size = ft_read(fd, &backup);
		if (size < 0)
			return (0);
	}
	buf = ft_line(backup);
	return (buf);
}
