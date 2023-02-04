/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:53:31 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 12:03:23 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	setting_color(char **line)
{
	int	num;
	int	i;
	int	t;

	t = 0;
	i = 1;
	num = ft_atoi(*line);
	while (num >= t)
	{
		i *= 10;
		t = i;
		(*line)++;
	}
	while ((**line) && (ft_isspace(**line) || **line == ','))
		(*line)++;
	return (num);
}

void	color_num_check(char *line)
{
	int	count;

	count = 0;
	while (*line != '\n')
	{
		if (*line == ',')
		{
			count++;
			line++;
			while (ft_isspace(*line))
				line++;
		}
		if (!ft_isdigit(*line))
			error("color line No number");
		line++;
	}
	if (count != 2)
		error("color count");
}

void	parsing_color_check(t_map *map, char *line, char c)
{
	t_color	color;

	line += 2;
	while (ft_isspace(*line))
		line++;
	color_num_check(line);
	color.r = setting_color(&line);
	color.g = setting_color(&line);
	color.b = setting_color(&line);
	if (!(color.r >= 0 && color.r <= 255) || !(color.g >= 0 && color.g <= 255) \
			|| !(color.b >= 0 && color.b <= 255))
		error("Color range Error");
	if (c == 'F')
		map->floor = (color.r << 16 | color.g << 8 | color.b);
	else if (c == 'C')
		map->celling = (color.r << 16 | color.g << 8 | color.b);
}
