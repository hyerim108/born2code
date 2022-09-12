/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:31:22 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/12 15:42:44 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_length(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(int c)
{
	return (c == 32);
}

int	ft_atoi(char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	result = result * n;
	if (str[i] != '\0' || result > 2147483647 || result < -2147483648)
		print_error();
	return (result);
}
