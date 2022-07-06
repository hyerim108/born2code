/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:53:42 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/06 17:52:21 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


size_t	ft_strlcat(char * dst, const char *src, size_t dstsize)
{
	 size_t	i;
	 size_t	d;
	 size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (dstsize < d)
		return (s + dstsize);
	while (*dst)
		dst++;
	if (dstsize != 0)
	{
		while (i + d < dstsize - 1 && *src != '\0')
		{
			*dst++ = *src++;
			i++;
		}
	}
	*dst = '\0';
	return (d + s);
}
