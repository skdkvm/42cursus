/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:13 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:04:15 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser/parser.h"

int	check_single_quotes(char *commands_line, int *i)
{
	if (commands_line[*i] != '\'')
		return (0);
	(*i)++;
	while (commands_line[*i] && !(commands_line[*i] == '\''))
		(*i)++;
	if (!commands_line[*i])
		return (wr_er("Error: Single quote not closed\n", 1));
	return (0);
}

int	check_double_quotes(char *commands_line, int *i)
{
	if (commands_line[*i] != '\"')
		return (0);
	(*i)++;
	while (commands_line[*i] && !(commands_line[*i] == '\"' \
				&& commands_line[*i - 1] != '\\'))
		(*i)++;
	if (!commands_line[*i])
		return (wr_er("Error: Double quote not closed\n", 1));
	return (0);
}

int	check_back_slash(char *commands_line, int *i)
{
	if (commands_line[*i] != '\\')
		return (0);
	(*i)++;
	return (1);
}

int	check_back_slash_at_the_end(char *commands_line)
{
	size_t	i;
	size_t	column_back_slash;

	i = ft_strlen(commands_line) - 1;
	column_back_slash = 1;
	if (commands_line[i--] != '\\')
		return (0);
	while (i && commands_line[i--] == '\\')
		column_back_slash++;
	if (column_back_slash % 2)
		return (wr_er("Error: Back slash at the end of the line\n", 1));
	return (0);
}

int	preparser(char *commands_line)
{
	int		i;

	i = -1;
	check_back_slash_at_the_end(commands_line);
	while (commands_line[++i])
	{
		if (precheck_redirect(commands_line, &i))
			return (1);
		if (check_back_slash(commands_line, &i))
			continue ;
		if (check_single_quotes(commands_line, &i))
			return (1);
		if (check_double_quotes(commands_line, &i))
			return (1);
		if (check_pipe(commands_line, &i))
			return (1);
	}
	return (0);
}
