/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <tjdrlf0618@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:22:20 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/06 00:08:26 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d", tab[i]);
	}
}

int		main(void)
{
	int arr[5] = {3, 4, 1, 5, 7};
	ft_sort_int_tab(arr, 5);
}
