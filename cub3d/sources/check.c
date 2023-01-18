/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/18 15:10:28 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void	map_condition(t_map *map, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height + 1)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0' || str[i][j] == 'W' || str[i][j] == 'E' || \
					str[i][j] == 'S' || str[i][j] == 'N')
			{
				if (i == 0 || j == 0 || i == map->height || !str[i][j + 1])
					error("first or last line No Wall");
				else if (ft_isspace(str[i][j + 1]) || \
						ft_isspace(str[i][j - 1]) \
						|| ft_isspace(str[i + 1][j]) \
						|| ft_isspace(str[i - 1][j]))
					error("No surround Wall");
			}
            j++;
		}
        i++;
	}
	
}

void	player_location_setting(t_player *play, char **str, int size)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'W' || str[i][j] == 'E' || str[i][j] == 'S' || \
				str[i][j] == 'N')
			{
				play->pocus_x = i;
				play->pocus_y = j;
				str[i][j] = 0;
			}
			j++;
		}
		i++;
	}
}
