/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:16:48 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 18:12:31 by hyerimki         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
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
	free(line);
	if (p->map.map_line == 0)
		error("no map");
	set_map(av, &p->map);
	player_location_setting(&p->player, p->map.map, p->map.height);
	return (1);
}
