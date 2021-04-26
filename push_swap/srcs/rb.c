/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:41 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:06:34 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **b)
{
	t_list	*ptr;

	if (b == NULL || (*b) == NULL)
	{
		return ;
	}
	ptr = (*b);
	ft_lstadd_back(b, ft_lstnew(ptr->n));
	ft_lstdel_front(b);
}
