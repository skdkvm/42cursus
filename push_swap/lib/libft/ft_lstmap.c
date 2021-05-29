/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:58:12 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 14:58:13 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_head;
	t_list		*new;
	void		*data;

	if (!lst || !f)
		return (0);
	data = f(lst->content);
	if (!(new = ft_lstnew(data)))
		return (0);
	new_head = new;
	lst = lst->next;
	while (lst)
	{
		data = f(lst->content);
		if (!(new->next = ft_lstnew(data)))
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	return (new_head);
}
