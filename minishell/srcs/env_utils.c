/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:01:19 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:01:45 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell/minishell.h"

int	ft_counter_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	*get_env(t_env *env, char *str)
{
	int			i;
	t_env		*ptr;

	i = 0;
	ptr = env;
	while (ptr)
	{
		if (!ft_strncmp(ptr->content->key, str, 0))
			return (ptr->content->value);
		ptr = ptr->next;
	}
	return (NULL);
}

char	*get_env_char(char **env, char *str)
{
	int		i;
	char	*ptr;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], str, check_equals_sign(env[i]) - 1))
		{
			ptr = env[i];
			return (ptr + (ft_strlen(str) + 1));
		}
	}
	return (NULL);
}
