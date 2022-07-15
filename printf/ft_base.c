/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:10:24 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/15 17:07:13 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int ft_mod(unsigned int nbr, char *base, int len)
{
	int	mod;
	int	result;

	mod = nbr % len;
	result = 0;
	if (nbr / len)
		result += ft_mod(nbr / len, base, len);
	result += ft_putchar(base[mod]);
	return (result);
}

int	ft_base(char c, unsigned int nbr)
{
	char	*hex;
	char	*hex_b;
	int		result;

	result = 0;
	hex = "0123456789abcdef";
	hex_b = "0123456789ABCDEF";
	if (c == 'x')
		result += ft_mod(nbr, hex, 16);
	else if(c == 'X')
		result += ft_mod(nbr, hex_b, 16);
	return (result);
}
