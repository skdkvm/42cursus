/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:47:19 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 18:34:19 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483748
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define INIT_LEN 8
# define LIMIT_LEN 30

typedef struct	s_stack
{
	int	*a;
	int	len;
	int	max_len;
}				t_stack;

t_stack		*create_stack(int size);
t_stack 	*dup_stack(t_stack *s);
void		free_stack(t_stack *s);
void		quick_sort(t_stack *s, int start, int end);

void		pop_front(t_stack *s);
void		push_front(t_stack *s, int n);
void		push_back(t_stack *s, int n);

void		push(t_stack *from, t_stack *to);
void		swap(t_stack *s);
void		rotate(t_stack *s);
void		revers_rotate(t_stack *s);

int			get_index(t_stack *s, int n);
int			get_min_index(t_stack *s);
int			get_max_index(t_stack *s);
int			get_median(t_stack *s);

void		print_push(t_stack *from, t_stack *to, char *str);
void		print_swap(t_stack *s, char *str);
void		print_rotate(t_stack *s, char *str);
void		print_revers_rotate(t_stack *s, char *str);
void		print_both(void (*f)(), t_stack *a, t_stack *b, char *str);

int			parse(t_stack *s, int argc, char **argv);
int			operations_start(int fd, t_stack *a, t_stack *b);
int			is_sorted(t_stack *s);
void		both(void (*f)(), t_stack *a, t_stack *b);

void		split_chunk(t_stack *pivot, t_stack *a);
int			get_chunk_len(t_stack *pivot, t_stack *a);
void		sort_to_rotate(t_stack *a);

void		push_chunk_to_b(
				t_stack *a, t_stack *b, t_stack *pivot, int chunk_len);
void		empty_b(t_stack *a, t_stack *b);
void		recursive_split_b(t_stack *a, t_stack *b, t_stack *pivot);

#endif
