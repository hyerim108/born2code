/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:45:53 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/04 17:50:49 by hyerimki         ###   ########.fr       */
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
	int	another;

	i = 0;
	people = 0;
	e = 0;
	another = 0;
	p->all_tem = 0;
	while (i < ft_strlen(p->str_line))
	{
		if (p->str_line[i] == 'E')
			e++;
		else if (p->str_line[i] == 'C')
			p->all_tem++;
		else if (p->str_line[i] == 'P')
			people++;
		else if (p->str_line[i] != '0' && p->str_line[i] != '1')
			another++;
		i++;
	}
	map_error_print(e, people, another, p);
}

void	map_wall_check(t_param *p)
{
	int	i;

	i = 0;
	if (p->width * p->height != ft_strlen(p->str_line))
		error("No rectangle!");
	while (i < ft_strlen(p->str_line))
	{
		if (i < p->width)
		{
			if (p->str_line[i] != '1')
				error("no wall\n");
		}
		else if (i > ft_strlen(p->str_line) - p->width)
		{
			if (p->str_line[i] != '1')
				error("no wall\n");
		}
		else if (i % p->width == 0 || i % p->width == p->width - 1)
		{
			if (p->str_line[i] != '1')
				error("no wall\n");
		}
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	map_error_print(int e, int people, int another, t_param *p)
{
	if (e != 1)
		error("Exit error\n");
	if (people != 1)
		error("People error\n");
	if (p->all_tem <= 0)
		error("Collection error\n");
	if (another > 0)
		error("unnecessary characters\n");
}
