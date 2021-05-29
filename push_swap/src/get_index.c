/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:44:19 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 15:06:10 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_index(t_stack *s, int n)
{
	int		i;

	i = 0;
	while (i < s->len)
	{
		if (s->a[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int		get_min_index(t_stack *s)
{
	int		min;
	int		i;

	i = 0;
	min = i;
	while (i < s->len)
	{
		if (s->a[i] < s->a[min])
			min = i;
		i++;
	}
	return (min);
}

int		get_max_index(t_stack *s)
{
	int		max;
	int		i;

	i = 0;
	max = i;
	while (i < s->len)
	{
		if (s->a[max] < s->a[i])
			max = i;
		i++;
	}
	return (max);
}

int		get_median(t_stack *s)
{
	int		i;
	int		res;
	t_stack *tmp;

	i = s->len / 2;
	tmp = dup_stack(s);
	quick_sort(tmp, 0, s->len - 1);
	res = tmp->a[i];
	free_stack(tmp);
	return (res);
}
