/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:39:41 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/05 13:45:02 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_chunk(t_list *lst, int start, int end)
{
	while (lst)
	{
		if ((lst->n >= start) && (lst->n <= end))
			return (1);
		lst = lst->next;
	}
	return (-1);
}

int		find_first(t_list *lst, int start, int end)
{
	int i;

	i = 0;
	while (lst)
	{
		if ((lst->n >= start) && (lst->n <= end))
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

int		find_last(t_list *lst, int start, int end)
{
	int i;
	int last;

	i = 0;
	last = -1;
	while (lst)
	{
		if ((lst->n >= start) && (lst->n <= end))
			last = i;
		i++;
		lst = lst->next;
	}
	return (-1);
}
