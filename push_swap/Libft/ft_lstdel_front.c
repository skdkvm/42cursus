/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:35:32 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/23 16:35:34 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_front(t_list **lst)
{
	t_list	*ptr;
	t_list	*tmp;

	if (lst == 0)
		return ;
	ptr = (*lst);
	tmp = ptr->next;
	ft_lstdelone(ptr);
	(*lst) = tmp;
}
