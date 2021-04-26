/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:37:19 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 20:26:48 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				n;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int n);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);
void				ft_lstiter(t_list *lst, void (*f)(int));
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
int					ft_strcmp(char *s1, char *s2);
void				ft_lstdel_back(t_list **lst);
void				ft_lstdel_front(t_list **lst);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);
void				ft_puts(char *str);
int					split_cnt(int *arr, char const *s, char c);
void				str_cnt(int *arr, int *str_len);
void				fill_splited(int *arr, char **splited, char const *s);
char				**ft_split(char const *s, char c);

#endif
