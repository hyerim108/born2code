/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:17:46 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/15 17:54:26 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	factor_split(int ac, char **av)
{
	int		index;
	int		size;
	int		check;
	char	**split_data;

	size = 0;
	index = 1;
	while (index < ac)
	{
		check = 0;
		while (av[index][check])
		{
			if (!ft_isspace(av[index][check]))
				break;
			check++;
		}
		split_data = ft_split(av[index], ' ');
		size += get_length(split_data);
		index++;
	}
	return (size);
}

int setting_pivot(t_stack *init, int size, int i)
{
    t_stack p;

    p.pivot = 0;
    return (1);
}
