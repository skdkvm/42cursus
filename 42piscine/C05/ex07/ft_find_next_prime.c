/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:29:53 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/16 02:40:24 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_prime(int n)
{
	int	i;
	int	temp;

	if (n <= 1)
		return (0);
	temp = n / 2;
	i = 2;
	while (i <= temp)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (!is_prime(nb))
		nb++;
	return (nb);
}
