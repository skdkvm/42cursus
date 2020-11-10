/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:28:34 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/16 00:33:32 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../myheader.h"

int			is_number(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

char		*check_exception(int argc, char *argv[])
{
	char	*dict_name;

	dict_name = NULL;
	if (argc != 2 && argc != 3)
		return (0);
	if (!is_number(argv[argc - 1]))
		return (0);
	if (ft_strcmp(argv[argc - 1], "") == 0)
		return (0);
	if (argc == 2)
		dict_name = "numbers.dict.txt";
	else
		dict_name = argv[1];
	return (dict_name);
}
