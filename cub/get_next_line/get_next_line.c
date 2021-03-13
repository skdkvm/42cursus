/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:34:05 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/13 15:32:20 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_null(char **line, char **stack, char *tmp)
{
	char *save;

	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup_g(*stack);
		save = ft_strdup_g(tmp + 1);
		free(*stack);
		*stack = save;
		return (1);
	}
	*line = *stack;
	*stack = NULL;
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char *stack;
	char *heap;
	int readcnt;
	char *tmp;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!stack)
		stack = ft_strdup_g("");
	if (!(heap = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!(tmp = ft_strchr_g(stack, '\n')) &&
		   ((readcnt = read(fd, heap, BUFFER_SIZE)) > 0))
	{
		heap[readcnt] = '\0';
		tmp = ft_strjoin_g(stack, heap);
		free(stack);
		stack = tmp;
	}
	if (readcnt < 0)
		return (-1);
	free(heap);
	return (ft_null(line, &stack, tmp));
}
