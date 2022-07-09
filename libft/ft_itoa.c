/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:29:20 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/09 14:22:36 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	size;

	size = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;

	len = ft_len(n);
	arr = malloc(sizeof(char) * len + 1);
	if (n == -2147483648)
		return ("-2147483648\0");
	arr[len] = 0;
	if (!arr)
		return (0);
	if (n < 0)
		arr[0] = '-';
	while (n)
	{
		len--;
		if (n > 0)
			arr[len] = (n % 10) + '0';
		else
			arr[len] = -(n % 10) + '0';
		n /= 10;
	}
	return (arr);
}

#include	<stdio.h>
int	main()
{
	printf("%s", ft_itoa(-2147483648));
}
