/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:18:23 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/05 17:16:07 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

typedef struct s_lists
{
	void *content;
	struct s_lists *next;
	int fd;
} t_lists;

int get_next_line(int fd, char **line);
t_lists *ft_lstnew_g(void *content, int fd);
size_t ft_strlen_g(const char *s);
char *ft_strchr_g(const char *s, int c);
char *ft_strdup_g(const char *s);
char *ft_strjoin_g(char const *s1, char const *s2);

#endif
