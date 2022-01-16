/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:31:03 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:31:04 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*func(t_list *lst, void *(*f)(void *), t_list	**tmp)
{
	*tmp = ft_lstnew(f(lst->content));
	return (*tmp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	t_list	*tmp;
	t_list	*beg_tmp;
	t_list	*beg_lst;

	size = ft_lstsize(lst);
	if (lst == NULL || func(lst, f, &tmp) == NULL)
		return (NULL);
	beg_tmp = tmp;
	beg_lst = lst;
	while (--size)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			lst = beg_lst;
			ft_lstclear(&beg_tmp, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	lst = beg_lst;
	return (beg_tmp);
}
