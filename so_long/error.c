/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:45:53 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/31 18:03:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_error_check(t_param *p)
{
	map_wall_check(p);
	map_item_count(p);
}

void	map_item_count(t_param *p)
{
	int	i;
	int	people;
	int	e;

	i = 0;
	people = 0;
	e = 0;
	p->all_tem = 0;
	while (i < ft_strlen(p->str_line))
	{
		if (p->str_line[i] == 'E')
			e = 1;
		else if (p->str_line[i] == 'C')
			p->all_tem++;
		else if (p->str_line[i] == 'P')
			people = 1;
		i++;
	}
	if (e == 0)
		error("Exit error\n");
	if (people == 0)
		error("People error\n");
	if (p->all_tem == 0)
		error("Collection error\n");
}

void	map_wall_check(t_param *p)
{
	int	i;

	i = 0;
	if (p->width * p->height != ft_strlen(p->str_line))
		error("No rectangle");
}
