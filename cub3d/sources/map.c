/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:05 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 14:17:53 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_direct(t_player *p, char c)
{
	if (p->status != 0)
		error("Player eyes that already exist");
	p->status =c;
}

void	map_save(t_map *map, t_player *p, char *line)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (!ft_isspace(c) && c != '0' && c != '1' && c != 'N' && c != 'W' \
			&& c != 'E' && c != 'S')
			error("Map Letter Error");
		if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			set_direct(p, c);
		i++;
	}
	if (map->width < i)
		map->width = i;
	if (map->map_first == 0)
		map->map_first = map->map_line;
}

void	map_line_skip(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	while (i < map->map_first - 1)
	{
		line = get_next_line(fd);
		free(line);
		line = NULL;
		i++;
	}
}

void	map_copy(int fd, t_map *map, char **temp)
{
	int		i;
	char	*line;
	char	*str;
	
	i = -1;
	while (++i < map->height + 1)
	{
		line = get_next_line(fd);
		str = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!str)
			error("map_capy malloc Error");
		ft_memset(str, ' ', map->width);
		str[map->width] = '\0';
		ft_strcpy(str, line);
		temp[i] = str;
		free(line);
		line = NULL;
	}
}

void	set_map(char *av, t_map *map)
{
	char	**temp;
	int		fd;

	map->height = map->map_line - map->map_first;
	temp = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!temp)
		error("malloc Error");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error("map file read Error");
	map_line_skip(fd, map);
	map_copy(fd, map, temp);
	map->map = temp;
	map_condition(map, map->map);
	close(fd);
}
