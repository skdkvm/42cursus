/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:04:48 by seonggki          #+#    #+#             */
/*   Updated: 2021/09/29 19:53:43 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*new_content;

	if (lst == 0 || f == 0)
		return (0);
	if ((new = ft_lstnew(f(lst->content))) == 0)
		return (0);
	lst = lst->next;
	new_content = new;
	while (lst)
	{
		if ((temp = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		new->next = temp;
		new = temp;
		lst = lst->next;
	}
	return (new_content);
}
