/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:01:14 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/11 17:11:57 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*arr;
	t_list	*tmp;

	arr = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&arr, del);
			return (0);
		}
		ft_lstadd_back(&arr, tmp);
		lst = lst->next;
	}
	return (arr);
}
