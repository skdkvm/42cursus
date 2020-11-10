/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myheader.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:13:19 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/16 00:33:04 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYHEADER_H
# define MYHEADER_H

# define BUF_SIZE 2048

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_dict
{
	char		*str;
	char		*key;
	char		*value;
}				t_dict;

t_dict			*g_dict;
char			**g_num;
char			*g_result;
int				g_size;
int				g_max_num;
int				g_max_dict;

void			ft_free(void);

void			print_word(void);
int				zero_row(int index);
int				match_word(char *cmp_str);

char			*check_exception(int argc, char *argv[]);
int				is_number(char *str);

int				change_to_word();
int				change_for_num(int index);
int				change_for_ten(int index);
int				change_for_unit(int index);

int				open_dict(char *dict_name, char *buf);
int				allocate_dict(int max_row);
int				split_in_line(int index, char *str);
int				split_dict(char *buf);
int				make_dict(char *dict_name);

int				print_err();
int				print_dict_err();
int				print_alloc_err();

int				ft_malloc(int argc, char *argv[]);
void			init_input(int argc, char *argv[], int col);
int				split_num(int argc, char *argv[]);

int				ft_strlen(char *str);
int				ft_strcmp(char *str1, char *str2);
void			ft_strcat(char *g_result, char *src);

#endif
