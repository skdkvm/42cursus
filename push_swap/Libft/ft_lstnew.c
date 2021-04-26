/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:36:24 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/23 16:36:26 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int n)
{
	t_list *ptr;

	if (!(ptr = malloc(sizeof(t_list))))
		return (NULL);
	ptr->n = n;
	ptr->next = NULL;
	return (ptr);
}
