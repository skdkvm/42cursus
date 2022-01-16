/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:46 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:04:47 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser/parser.h"

void	replace_shlvl(t_env *tmp, t_env *env, int value)
{
	if (tmp)
	{
		free(tmp->content->value);
		tmp->content->value = ft_itoa(value);
	}
	else
		add_elem_env(env, new_elem_env(), write_env, "SHLVL=1");
}

void	inc_shlvl(t_env *env)
{
	t_env	*tmp;

	tmp = check_export_line(env, "SHLVL");
	if (tmp)
		replace_shlvl(tmp, env, ft_atoi(tmp->content->value) + 1);
	else
		replace_shlvl(tmp, env, 1);
}
