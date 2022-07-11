/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:54:42 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/11 17:35:05 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	i = 0;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return ((void *)new_dst);
}
