/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:18:23 by seonggki          #+#    #+#             */
/*   Updated: 2020/11/10 21:48:11 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char			*ft_strdup(const char *src);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
int				ft_strlen(char *str);
int				get_next_line(int fd, char **line);

#endif
