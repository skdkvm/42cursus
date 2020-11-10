/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:29:09 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/16 04:48:00 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../myheader.h"

void		ft_free(void)
{
	int		n;

	n = 0;
	while (n < g_max_dict)
	{
		free(g_dict[n].str);
		free(g_dict[n].key);
		free(g_dict[n].value);
		n++;
	}
	free(g_dict);
	n = 0;
	while (n < g_max_num + 2)
	{
		free(g_num[n]);
		n++;
	}
	free(g_num);
}

int			main(int argc, char *argv[])
{
	char	*dict_name;
	int		i;

	i = 0;
	dict_name = check_exception(argc, argv);
	if (dict_name == 0)
		return (print_err());
	if (split_num(argc, argv))
		return (print_alloc_err());
	if (make_dict(dict_name))
		return (print_dict_err());
	change_to_word();
	ft_free();
	return (0);
}
