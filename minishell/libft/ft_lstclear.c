/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:30:45 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:30:45 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*pl;

	new_lst = *lst;
	while (new_lst)
	{
		pl = new_lst->next;
		ft_lstdelone(new_lst, del);
		new_lst = pl;
	}
	*lst = NULL;
}
