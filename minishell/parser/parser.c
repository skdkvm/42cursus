/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:03:44 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:03:47 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser/parser.h"

void	find_delimiter_word(char **p_command_line, size_t *i, \
						 t_commands **command)
{
	char	*command_line;

	skip_spases_tabs(p_command_line, *i);
	command_line = *p_command_line;
	if (command_line[*i] == '>' || command_line[*i] == '<' || \
		(*command)->fd_flag)
	{
		if ((*command)->fd_flag || *i == 0)
			replace_redirect(*command, p_command_line, i);
		else
		{
			replace_redirect(*command, p_command_line, i);
			save_command(p_command_line, i, *command);
		}
	}
	else
		save_command(p_command_line, i, *command);
}

void	check_end_word(char **p_command_line, size_t *i, t_commands **command)
{
	char	*command_line;

	command_line = *p_command_line;
	if (command_line[*i] == ' ' || command_line[*i] == '\t' || \
		command_line[*i] == ';' || command_line[*i] == '\n' || \
		command_line[*i] == '>' || command_line[*i] == '\0' || \
		command_line[*i] == '<')
	{
		find_delimiter_word(p_command_line, i, command);
	}
	else if (command_line[*i] == '|')
	{
		delete_one_char(p_command_line, *i);
		if (*i != 0)
			save_command(p_command_line, i, *command);
		(*command)->pipe = 1;
		(*command)->next = init_command();
		fd_control(command);
		*command = (*command)->next;
		skip_spases_tabs(p_command_line, *i);
	}
}

void	replacing_line_part(char **p_commands_line, char **env,
							t_commands **command, size_t *i)
{
	replace_single_quotes(p_commands_line, i);
	replace_double_quotes(p_commands_line, env, i);
	replace_dollar(p_commands_line, env, i);
	replace_normal_char(p_commands_line, i);
	check_end_word(p_commands_line, i, command);
}

t_commands	*get_one_command(char **p_commands_line, char **env)
{
	size_t		i;
	t_commands	*first;
	t_commands	*command;
	char		*command_line;

	i = 0;
	first = init_command();
	command = first;
	skip_spases_tabs(p_commands_line, i);
	command_line = *p_commands_line;
	while (command_line[i] && command_line[i] != '\n' && command_line[i] != ';')
	{
		if (replace_back_slash(&command_line, &i))
		{
			check_end_word(&command_line, &i, &command);
			continue ;
		}
		replacing_line_part(&command_line, env, &command, &i);
	}
	command->argv = malloc_argv(command->argc, command->argv);
	*p_commands_line = ft_substr(command_line, command_line[i] == ';', -1);
	free(command_line);
	fd_control(&first);
	return (first);
}

void	parser(char *commands_line, char ***env, t_env **env_main)
{
	t_commands		*command;

	if (!commands_line)
		return ;
	if (preparser(commands_line))
	{
		free(commands_line);
		return ;
	}
	command = NULL;
	while (*commands_line)
	{
		command = get_one_command(&commands_line, *env);
		if (check_command(command))
			start_cmd(command, env, env_main);
		else
		{
			if (command)
				free_command(&command);
			break ;
		}
		if (command)
			free_command(&command);
	}
	free(commands_line);
}
