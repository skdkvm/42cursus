/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:38:50 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/05 13:51:47 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int ft_null(char **line, char **stack, char *tmp)
{
	char *save;

	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*stack);
		save = ft_strdup(tmp + 1);
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
	static char *stack[OPEN_MAX];
	char *heap;
	int readcnt;
	char *tmp;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!stack[fd])
		stack[fd] = ft_strdup("");
	if (!(heap = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!(tmp = ft_strchr(stack[fd], '\n')) &&
		   ((readcnt = read(fd, heap, BUFFER_SIZE)) > 0))
	{
		heap[readcnt] = '\0';
		tmp = ft_strjoin(stack[fd], heap);
		free(stack[fd]);
		stack[fd] = tmp;
	}
	if (readcnt < 0)
		return (-1);
	free(heap);
	return (ft_null(line, &stack[fd], tmp));
}
