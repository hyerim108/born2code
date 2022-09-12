/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:14 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/12 15:27:22 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int factor_split(int ac, char **av)
{
    int     index;
    int     size;
    int     check;
    char    **split_data;
    
    size = 0;
    index = 1;
    while (index < ac)
    {
        check = 0;
        while(av[index][check])
        {
            if(!ft_isspace(av[index][check]))
                break;
            check++;
        }
        split_data = ft_split(av[index], ' ');
        size += get_length(split_data);
        index++;
    }
    return (size);
}

int *number_check(int ac, char **av, int size)
{
    int     *num_array;
    int     i;
    char    **split_data;
    int     index;
    
    i = 1;
    index = 0;
    num_array = malloc(sizeof(int) * size);
    while (i < ac)
    {
        split_data = ft_split(av[i], ' ');
        setting_num(num_array, &index, split_data);
        i++;
    }
    return (num_array);
}

void    setting_num(int *num_array, int *index, char **split_data)
{
    int	num;
	int	i;

	i = 0;
	while (split_data[i])
	{
		num = ft_atoi(split_data[i]);
		num_array[*index] = num;
		(*index)++;
		i++;
	}
}
