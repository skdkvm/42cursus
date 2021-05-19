/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:45:59 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/19 19:18:27 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (1 < argc)
	{
		a = create_stack(INIT_LEN);
		b = create_stack(INIT_LEN);
		if (parse(a, argc, argv) == 0 &&
				do_op(0, a, b) == 0)
		{
			if (is_sorted(a) && b->len == 0)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}
