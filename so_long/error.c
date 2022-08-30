/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:45:53 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/28 20:03:21 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_item_count(t_param *p)
{
	int	i;

	i = 0;
	p->all_tem = 0;
	while (i < ft_strlen(p->str_line))
	{
		if (p->str_line[i] == 'C')
			p->all_tem++;
		i++;
	}
}
