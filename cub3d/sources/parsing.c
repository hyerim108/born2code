/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:16:48 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/16 18:30:22 by hyerimki         ###   ########.fr       */
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
	if (c == 'N' && map->NO == NULL)
		map->NO = temp;
	else if (c == 'S' && map->SO == NULL)
		map->SO = temp;
	else if (c == 'W' && map->WE == NULL)
		map->WE = temp;
	else if (c == 'E' && map->EA == NULL)
		map->EA = temp;
	else
		error("another texture");
}

int	map_parshing_check(t_map *map, t_player *p, char *line)
{
	int	i;

	i = 0;
	if (ft_strncmp("NO ", line, 3) == 0 || ft_strncmp("SO ", line, 3) == 0 || \
			ft_strncmp("WE ", line, 3) == 0 || ft_strncmp("EA ", line, 3) == 0)
		parsing_line_check(map, line, line[0]);
	else if (ft_strncmp("F ", line, 2) == 0 || ft_strncmp("C ", line, 2) == 0)
		parsing_color_check(map, line, line[0]);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '0' || line[i] == '1')
		map_save(map, p, line);
	return (1);
}

int	map_parshing(char *av, t_param *p)
{
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd <= 0)
		error("file error");
	line = get_next_line(fd);
	while (line){
        p->map.map_line += 1;
		if (map_parshing_check(&p->map, &p->player, line) == 0)
			error("map parshing Error");
		line = get_next_line(fd);
	}
    if (p->map.map_line == 0)
        error("no map");
    set_map(av, &p->map);
	player_location_setting(&p->player,p->map.map, p->map.height);
	return (1);
}
