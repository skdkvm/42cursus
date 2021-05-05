/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:56:14 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/05 15:04:38 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_larger(t_list *lst, int top)
{
	while (lst)
	{
		if (lst->n > top)
			return (lst->n);
		lst = lst->next;
	}
	return (top);
}

int	get_smallest_larger(t_list *lst, int top)
{
	int	index;
	int larger_index;
	int small_larger;

	index = 0;
	larger_index = -1;
	small_larger = get_first_larger(lst, top);
	while (lst)
	{
		if ((lst->n > top) && (lst->n <=small_larger))
		{
			small_larger = lst->n;
			larger_index = index;
		}
		index++;
		lst = lst->next;
	}
	return (larger_index);
}

int	get_smallest(t_list *lst)
{
	int	index;
	int smallest_index;
	int	smallest;

	index = 0;
	smallest_index = 0;
	smallest = lst->n;
	while (lst)
	{
		if (smallest > lst->n)
		{
			smallest = lst->n;
			smallest_index = index;
		}
		index++;
		lst = lst->next;
	}
	return (smallest_index);
}

int	get_largest(t_list *lst)
{
	int	index;
	int largest_index;
	int largest;

	index = 0;
	largest_index = 0;
	largest = lst->n;
	if (lst == NULL)
		return (-1);
	while (lst)
	{
		if (lst->n > largest)
		{
			largest = lst->n;
			largest_index = index;
		}
		index++;
		lst = lst->next;
	}
	return (largest_index);
}
