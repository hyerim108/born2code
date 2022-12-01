/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:08:28 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 15:42:20 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count <= 0 || size <= 0)
		str = (char *)malloc(1);
	else
		str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	return (ft_memset(str, 0, count * size));
}
