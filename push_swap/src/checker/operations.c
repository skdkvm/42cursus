/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:13:01 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/19 18:52:09 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_instruction(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa", 4) == 0)
		swap(a);
	else if (ft_strncom(line, "sb", 3) == 0)
		swap(b);
	else if (ft_strncom(line, "ss", 3) == 0)
		both(swap, a, b);
	else if (ft_strncom(line, "pa", 3) == 0)
		push (b, a);
	else if (ft_strncom(line, "pb", 3) == 0)
		push (a, b);
	else if (ft_strncom(line, "ra", 3) == 0)
		rotate (a);
	else if (ft_strncom(line, "rb", 3) == 0)
		rotate (b);
	else if (ft_strncom(line, "rr", 3) == 0)
		both(&rotate, a, b);
	else if (ft_strncom(line, "rra", 4) == 0)
		revers_rotate(a);
	else if (ft_strncom(line, "rrb", 4) == 0)
		revers_rotate(b);
	else if (ft_strncom(line, "rrr", 4) == 0)
		both(&revers_rotate, a, b);
	else
		return (1);
	return (0);
}

int			operations_start(int fd, t_stack *a, t_stack *b)
{
	char	*line;
	int		n;
	int		error;

	error = 0;
	while ((n = get_next_line(fd, &line)) > 0)
	{
		error |= stack_instruction(line, a, b);
		free(line);
		line = NULL;
	}
	if (ft_strlen(line))
		error |= stack_instruction(line, a, b);
	free(line);
	line = NULL;
	if (error || n == -1)
		return (-1);
	return (0);
}
