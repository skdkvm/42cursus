/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:52 by seonggki          #+#    #+#             */
/*   Updated: 2021/06/03 12:43:54 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	int	top;

	if (from->len == 0)
		return ;
	top = from->a[0];
	pop_front(from);
	push_front(to, top);
}

void	swap(t_stack *s)
{
	int	tmp;

	if (s->len < 2)
		return ;
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
}

void	rotate(t_stack *s)
{
	int	tmp;

	if (s->len < 2)
		return ;
	tmp = s->a[0];
	ft_memmove(s->a, (s->a + 1), (s->len - 1) * sizeof(int));
	s->a[s->len - 1] = tmp;
}

void	revers_rotate(t_stack *s)
{
	int	tmp;

	if (s->len < 2)
		return ;
	tmp = s->a[s->len - 1];
	ft_memmove((s->a + 1), s->a, (s->len - 1) * sizeof(int));
	s->a[0] = tmp;
}
