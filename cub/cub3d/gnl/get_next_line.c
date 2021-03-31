/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:29:05 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/24 21:06:22 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_nl(int fd, char **line, char **strg, char *nlpt)
{
	char		*temp;

	if (nlpt)
	{
		*line = ft_substr(strg[fd], 0, nlpt - strg[fd]);
		temp = ft_strdup(nlpt + 1);
		if (strg[fd])
			free(strg[fd]);
		strg[fd] = temp;
		return (1);
	}
	else
	{
		*line = ft_substr(strg[fd], 0, ft_strlen(strg[fd]));
		if (strg[fd])
			free(strg[fd]);
		strg[fd] = NULL;
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	static char	*strg[OPEN_MAX];
	char		*buff;
	char		*temp;
	char		*nlpt;
	int			rsize;

	if (!(line) || BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((rsize = read(fd, buff, BUFFER_SIZE)) >= 0)
	{
		buff[rsize] = '\0';
		temp = strg[fd] == NULL ? ft_strdup(buff) : ft_strjoin(strg[fd], buff);
		if (strg[fd])
			free(strg[fd]);
		strg[fd] = temp;
		if ((nlpt = ft_strchr(strg[fd], '\n')) || !(rsize))
			break ;
	}
	free(buff);
	buff = NULL;
	if (rsize == -1)
		return (-1);
	return (get_nl(fd, line, strg, nlpt));
}
