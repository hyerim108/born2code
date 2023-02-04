/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:16:48 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:05:12 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*put_parsing(char *line)
{
	int		fd;
	char	*temp;

	temp = NULL;
	line += 2;
	while (ft_isspace(*line))
		line++;
	temp = ft_strd_up(line);
	return (temp);
}

void	parsing_line_check(t_map *map, char *line, char c)
{
	char	*temp;

	temp = put_parsing(line);
	if (!temp)
		error("nothing texture");
	if (c == 'N' && map->no == NULL)
		map->no = temp;
	else if (c == 'S' && map->so == NULL)
		map->so = temp;
	else if (c == 'W' && map->we == NULL)
		map->we = temp;
	else if (c == 'E' && map->ea == NULL)
		map->ea = temp;
	else
		error("another texture");
}

void	parshing_null_check(t_map *map)
{
	if (map->so == NULL || map->we == NULL || map->ea == NULL || \
		map->no == NULL)
		error("No map texture");
	if (map->floor == 0 || map->celling == 0)
		error("No color texture");
}

void	map_parshing_check(t_map *map, t_player *p, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
			i++;
	if (ft_strncmp("NO", line + i, 2) == 0 || \
			ft_strncmp("SO", line + i, 2) == 0 || \
			ft_strncmp("WE", line + i, 2) == 0 || \
			ft_strncmp("EA", line + i, 2) == 0)
		parsing_line_check(map, line + i, line[0 + i]);
	if (ft_strncmp("F", line + i, 1) == 0 || \
			ft_strncmp("C", line + i, 1) == 0)
		parsing_color_check(map, line + i, line[0 + i]);
	if (line[i] == '0' || line[i] == '1')
		map_save(map, p, line);
}

int	map_parshing(char *av, t_param *p)
{
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd <= 0)
		error("file error");
	line = get_next_line(fd);
	while (line)
	{
		p->map.map_line += 1;
		map_parshing_check(&p->map, &p->player, line);
		free(line);
		line = get_next_line(fd);
	}
	parshing_null_check(&p->map);
	free(line);
	if (p->map.map_line == 0)
		error("no map");
	set_map(av, &p->map);
	player_location_setting(&p->player, p->map.map, p->map.height);
	return (1);
}
