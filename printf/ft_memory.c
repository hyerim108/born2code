/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:45 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/15 17:21:19 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_mod(unsigned long long nbr, char *base, unsigned int size)
{
	unsigned int	mod;
	int	result;

	result = 0;
	mod = nbr % size;
	if (nbr / size)
		ft_base_mod(nbr / size, base, size);
	ft_putchar(base[mod]);
	result++;
	return (result);
}

unsigned long long	ft_memory(unsigned long long *nbr)
{
	char	*hex;
	int	result;

	result = 0;
	hex = "0123456789abcdef";
	result += ft_putstr("0x");
	result += ft_base_mod(*nbr, hex, 16);
	return (result);
}