/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:25:28 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/05 15:28:05 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest_value(t_list *lst)
{
	int index;
	int smallest_index;
	int smallest;

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
	return (smallest);
}

int	get_largest_value(t_list *lst)
{
	int index;
	int largest_index;
	int largest;

	index = 0;
	largest_index = 0;
	largest = lst->n;

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
	return (largest);
}
