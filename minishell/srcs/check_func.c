/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:01:02 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:01:49 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell/minishell.h"

int	check_equals_sign(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '=' && argv[i] != '\0')
		i++;
	return (i);
}

int	check_env_line(char **env, char *key)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (!ft_strncmp(env[i], key, j))
			return (1);
		i++;
	}
	return (0);
}

t_env	*check_export_line(t_env *env, char *str)
{
	t_env	*ptr;
	int		len;

	ptr = env;
	len = check_equals_sign(str);
	while (ptr)
	{
		if (ptr->content->value && !ft_strncmp(ptr->content->key, str, \
				ft_strlen(ptr->content->key)))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int	**create_pipe_fd(int count)
{
	int		**fd;
	int		i;

	i = 0;
	fd = (int **)malloc(sizeof(int *) * count + 1);
	fd[count] = NULL;
	while (i < count)
		fd[i++] = (int *)malloc(sizeof(int) * 2);
	return (fd);
}
