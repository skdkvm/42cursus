/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:39 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:06:03 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*ptr;

	if (a == NULL || (*a) == NULL)
	{
		return ;
	}
	ptr = (*a);
	ft_lstadd_back(a, ft_lstnew(ptr->n));
	ft_lstdel_front(a);
}
