/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:12:48 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/04 16:21:22 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *arr, char *backup)
{
	int		size;

	size = 1;
	while (size != 0)
	{
		size = read(fd, arr, BUFFER_SIZE);
		if (size <= 0)
			break ;
		arr[size] = '\0';
		if (!backup)
			backup = ft_strdup("");
		backup = ft_strjoin(backup, arr);
		if (ft_strchr (arr, '\n'))
			break ;
	}
	return (backup);
}

char	*ft_line(char *save)
{
	int		i;
	char	*backup;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\0' || save[0] == '\0')
		return (0);
	backup = ft_substr(save, i + 1, ft_strlen(save) - i);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	save[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*save;
	char		*temp;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	save = ft_read(fd, temp, backup);
	free(temp);
	temp = NULL;
	if (!save)
		return (NULL);
	backup = ft_line(save);
	return (save);
}
