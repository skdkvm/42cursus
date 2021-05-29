/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:00:19 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 15:00:19 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static int		split_cache(char **line, char **cache)
{
	char		*tmp;
	char		*newline;

	if ((newline = ft_strchr(*cache, '\n')))
	{
		if ((*line = ft_strndup(*cache, newline - *cache))
		&& (tmp = ft_strndup(newline + 1, ft_strlen(newline + 1))))
		{
			free(*cache);
			*cache = tmp;
			return (1);
		}
		if (*line)
			free(*line);
		free(*cache);
		*line = 0;
		*cache = 0;
		return (ERRNO);
	}
	*line = *cache;
	*cache = 0;
	return (0);
}

static int		return_next_line(char **line, char **cache, int n)
{
	if (n < 0)
		return (ERRNO);
	if (!*cache && !(*cache = ft_strndup("", 0)))
		return (ERRNO);
	return (split_cache(line, cache));
}

int				get_next_line(int fd, char **line)
{
	static char	*cache[OPEN_MAX + 1];
	char		*buf;
	char		*tmp;
	int			n;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1
			|| !(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (ERRNO);
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = 0;
		tmp = ft_strjoin(cache[fd], buf);
		free(cache[fd]);
		if (!(cache[fd] = tmp))
		{
			free(buf);
			return (ERRNO);
		}
		if (ft_strchr(cache[fd], '\n'))
			break ;
	}
	free(buf);
	return (return_next_line(line, &cache[fd], n));
}
