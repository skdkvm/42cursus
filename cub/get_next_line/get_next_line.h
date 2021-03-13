/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:18:23 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/13 15:32:54 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char *ft_strdup_g(const char *src);
char *ft_strjoin_g(char *s1, char *s2);
char *ft_strchr_g(char *s, int c);
int ft_strlen_g(char *str);
int get_next_line(int fd, char **line);

#endif
