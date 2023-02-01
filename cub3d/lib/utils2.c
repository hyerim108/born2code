/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:54 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/30 11:04:48 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*new_b;

	i = 0;
	new_b = b;
	while (i < len)
		new_b[i++] = (unsigned char)c;
	return (new_b);
}

char	*ft_strd_up(const char *s1)
{
	char	*arr;
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	arr = malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (0);
	while (i < len - 1)
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!dst)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (src[i])
		i++;
	return (i);
}