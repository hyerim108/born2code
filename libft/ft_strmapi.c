/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:17:07 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/08 17:36:53 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *arr;
	unsigned int i;
	
	arr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!arr)
		return (0);
	i = 0;
	while (s[i])
	{
		arr[i] = (*f)(i, s[i]);
		i++;
	}
	arr[i] = 0;
	return (arr);
}