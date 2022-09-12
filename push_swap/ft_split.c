/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:42:35 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/12 13:26:11 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

size_t	ft_wordcount(char *s, char c)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			size++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (size);
}

char	*ft_cpy(char *s, char c)
{
	char	*arr;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[size] && s[size] != c)
		size++;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	while (i < size)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	size = ft_wordcount((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (0);
	while (i < size)
	{
		while (*s == c)
			s++;
		arr[i] = ft_cpy((char *)s, c);
		if (!arr[i])
			return (ft_free(arr));
		s += ft_strlen(arr[i]);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
