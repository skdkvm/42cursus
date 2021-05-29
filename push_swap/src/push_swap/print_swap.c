/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:27:40 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 18:23:20 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_push(t_stack *from, t_stack *to, char *str)
{
	push(from, to);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void		print_swap(t_stack *s, char *str)
{
	swap(s);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void		print_rotate(t_stack *s, char *str)
{
	rotate(s);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void		print_revers_rotate(t_stack *s, char *str)
{
	revers_rotate(s);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void		print_both(void (*f)(), t_stack *a, t_stack *b, char *str)
{
	f(a);
	f(b);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
