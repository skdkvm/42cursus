/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:59:33 by seushin           #+#    #+#             */
/*   Updated: 2021/02/24 22:13:37 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_content(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*start;
	int		count;
	int		len;

	start = lst;
	len = ft_lstsize(lst);
	while (len--)
	{
		count = len;
		start = lst;
		while (count-- && start->next)
		{
			if (cmp(start->content, start->next->content) > 0)
				swap_content(&start->content, &start->next->content);
			start = start->next;
		}
	}
}
