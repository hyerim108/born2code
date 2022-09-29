/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:09 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/28 17:19:48 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *init, int size)
{
	init->a = malloc(sizeof(int) * size);
	init->size_a = -1;
	init->b = malloc(sizeof(int) * size);
	init->size_b = -1;
	init->size = size;
	if (!init->a || !init->b)
		exit(1);
}

int	check_number(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (0);
		i++;
	}
	return (1);
}

void	setting_num(t_stack *init, char **av, int ac)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (i < ac)
	{
		j = 0;
		arr = ft_split(av[i++], ' ');
		while (arr[j])
		{
			init->size_a += 1;
			if (!ft_atoi(arr[j++], &init->a[init->size_a]) || \
					!check_number(init->a, init->size_a, init->a[init->size_a]))
				print_error();
		}
		ft_free(arr);
	}
	swap_stack(init);
}

void	swap_stack(t_stack *init)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = init->size_a;
	while (i < j)
	{
		temp = init->a[i];
		init->a[i] = init->a[j];
		init->a[j] = temp;
		i++;
		j--;
	}
}
