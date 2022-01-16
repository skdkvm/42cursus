/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:00:14 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:00:17 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell/minishell.h"

static void	ft_print_env(t_env **env_export, int fd)
{
	t_env	*ptr;

	ptr = *env_export;
	while (ptr)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(ptr->content->key, fd);
		if (ptr->content->value)
		{
			ft_putchar_fd('=', fd);
			ft_putchar_fd('"', fd);
			ft_putstr_fd(ptr->content->value, fd);
			ft_putchar_fd('"', fd);
		}
		ft_putchar_fd('\n', fd);
		ptr = ptr->next;
	}
}

static void	handling_write_export(t_env **env_export,
						char **argv, int args, int fd)
{
	t_env	*tmp;
	t_env	*ptr;

	ptr = *env_export;
	if (check_valid_identifier(argv[args], fd))
	{
		tmp = check_repeat_export(*env_export, argv[args]);
		if (argv[args][check_equals_sign(argv[args])] == '=')
		{
			if (tmp && *env_export == tmp)
				*env_export = delete_head(tmp);
			else if (tmp)
				ptr = delet_elem(tmp, *env_export);
		}
		if (!tmp || argv[args][check_equals_sign(argv[args])] == '=')
			add_elem_env(*env_export, new_elem_env(), write_env, argv[args]);
	}
}

void	ft_export_shell(t_env **env_export, char **argv, int argc, int fd)
{
	int		args;

	args = 1;
	if (argc < 2)
		ft_print_env(env_export, fd);
	else if (argc > 1)
	{
		while (args < argc)
		{
			handling_write_export(env_export, argv, args, fd);
			args++;
		}
	}
}
