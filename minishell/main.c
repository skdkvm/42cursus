/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:58:35 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 18:58:40 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser/parser.h"

void	print_jordy(void)
{
	int		fd;
	char	*line;

	fd = open("jordy.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
}

void	process_the_line(char *line, char ***new_env, t_env **env_main)
{
	if (line && *line)
		add_history(line);
	write(1, "\033[0m" ANSI_COLOR_GREEN "", 10);
	parser(line, new_env, env_main);
	write(1, "\033[1m" ANSI_COLOR_CYAN "", 10);
}

int	main(int argc, char **argv, char **env)
{
	char	**new_env;
	char	*line;
	t_env	*env_main;
	t_env	*ptr;

	g_error_code_dollar = 0;
	print_jordy();
	env_main = ft_create_env(env);
	new_env = new_env_malloc(env, ft_counter_env(env));
	inc_shlvl(env_main);
	new_env = rewrite_env_parse(&env_main, new_env);
	ptr = env_main;
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_slash);
	line = readline("Minishell-2.🔞 ⌲ ");
	while (line)
	{
		signal(SIGQUIT, ctrl_slash_cat);
		process_the_line(line, &new_env, &env_main);
		line = readline("Minishell-2.🔞 ⌲ ");
		signal(SIGQUIT, ctrl_slash);
	}
	ctrl_d();
	return (g_error_code_dollar);
}
