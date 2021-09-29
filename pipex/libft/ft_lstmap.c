/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:04:48 by seonggki          #+#    #+#             */
/*   Updated: 2021/09/29 20:09:19 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	while (lst != NULL)
	{
		a = ft_lstnew(f(lst->content));
		if (!a)
		{
			ft_lstclear(&b, del);
			return (NULL);
		}
		ft_lstadd_back(&b, a);
		lst = lst->next;
	}
	return (b);
}
