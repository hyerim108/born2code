/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:02:47 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/30 15:06:24 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strdup_new(const char *s1)
{
	char	*arr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	arr = malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (0);
	while (i < len && s1[i] != '\n')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	int		len;
	int		i;
	int		x;
	char	*arr;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (i < ft_strlen(s1))
		arr[x++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2) && s2[i] != '\n')
		arr[x++] = s2[i++];
	arr[x] = '\0';
	free(s1);
	s1 = NULL;
	return (arr);
}
