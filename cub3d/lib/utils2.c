/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:54 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/24 13:41:34 by hyerimki         ###   ########.fr       */
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
