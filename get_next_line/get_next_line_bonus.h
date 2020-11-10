/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:39:27 by seonggki          #+#    #+#             */
/*   Updated: 2020/11/10 21:41:40 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char			*ft_strdup(const char *src);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
int				ft_strlen(char *str);
int				get_next_line(int fd, char **line);

#endif
