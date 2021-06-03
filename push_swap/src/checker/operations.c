/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:13:01 by seonggki          #+#    #+#             */
/*   Updated: 2021/06/03 13:28:06 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exec_both(void (*f)(), t_stack *a, t_stack *b)
{
	f(a);
	f(b);
}

static int	stack_instruction(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa", 4) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb", 3) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss", 3) == 0)
		exec_both(&swap, a, b);
	else if (ft_strncmp(line, "pa", 3) == 0)
		push (b, a);
	else if (ft_strncmp(line, "pb", 3) == 0)
		push (a, b);
	else if (ft_strncmp(line, "ra", 3) == 0)
		rotate (a);
	else if (ft_strncmp(line, "rb", 3) == 0)
		rotate (b);
	else if (ft_strncmp(line, "rr", 3) == 0)
		exec_both(&rotate, a, b);
	else if (ft_strncmp(line, "rra", 4) == 0)
		revers_rotate(a);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		revers_rotate(b);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		exec_both(&revers_rotate, a, b);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
