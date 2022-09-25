/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:58:51 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/25 14:58:43 by hyerimki         ###   ########.fr       */
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

int	ft_atoi(char *str, int *result)
{
	long	temp;
	int		n;

	temp = 0;
	n = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		temp *= 10;
		temp += (*str - '0') * n;
		str++;
	}
	if (*str != '\0' || temp > 2147483647 || temp < -2147483648)
		return (0);
	*result = temp;
	return (1);
}
