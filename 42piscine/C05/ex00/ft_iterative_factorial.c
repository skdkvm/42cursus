/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:59:50 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/15 18:02:43 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int num;

	if (nb < 0)
	{
		return (0);
	}
	num = 1;
	while (nb)
	{
		num *= nb;
		nb--;
	}
	return (num);
}
