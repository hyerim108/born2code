/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:22 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/09 14:22:12 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	start;
    size_t	last;
    size_t	i;
    
    start = 0;
    last = ft_strlen(s1) - 1;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    while (s1[last] && ft_strchr(set, s1[last]))
    {
        if (last < start)
            return (ft_strdup(""));
        last--;
    }
    arr = (char *)malloc(sizeof(char) * (last - start + 2));
    if (!arr)
        return (0);
    ft_strlcpy(arr, &s1[start], last - start + 2);
    return (arr);
}
