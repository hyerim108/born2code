/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:54:06 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/26 17:56:52 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

void	paste_img(t_param *p)
{
	
}

void	build_map(char *build, t_param *p)
{
	int		fd;
	char	*line;

	fd = open(build, O_RDONLY);
	line = get_next_line(fd);
	p->width = ft_strlen(line) - 1;
	p->height = 0;
	p->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		p->height++;
		if (line)
			p->str_line = ft_strjoin(p->str_line, line);
	}
	close(fd);
	printf("%s\n", p->str_line);
}
