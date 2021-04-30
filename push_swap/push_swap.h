/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:31:34 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:57:42 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		swap(t_list *lst1, t_list *lst2);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
int			check_argv(int start, int len, char **argv);
int			call_command(t_list **a_start, t_list **b_start);
int			check_descending(t_list *a, t_list *b);
void		print_stack(t_list *stack);
void		print_process(char *command, t_list *a, t_list *b);
#endif
