/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:01 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:04:06 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser/parser.h"

int	base_delimiter(char *commands_line, int i)
{
	int		ch;

	ch = commands_line[i];
	if (ch == '\0')
		return (wr_er("bash: syntax error near unexpected token `newline'\n", \
																		258));
	if (ch == '|')
		return (wr_er("bash: syntax error near unexpected token `|'\n", 258));
	if (ch == ';')
		return (wr_er("bash: syntax error near unexpected token `;'\n", 258));
	if (ch == '<' || ch == '>')
		return (wr_er("bash: syntax error near unexpected token `<'\n", 258));
	return (0);
}

int	quotes_delimiter(char *commands_line, int i)
{
	int		ch;
	int		col;

	col = 0;
	if (!(commands_line[i] == '\'' || commands_line[i] == '"'))
		return (0);
	while (commands_line[i] == '\'' || commands_line[i] == '"')
	{
		while (commands_line[i] == '\'' && ++i)
			col++;
		if (col % 2)
			return (0);
		while (commands_line[i] == '\"' && ++i)
			col++;
		if (col % 2)
			return (0);
	}
	ch = commands_line[i];
	if (ch == ' ' || ch == '|' || ch == '<' || ch == '>' || \
		ch == '\t' || ch == '\0' || ch == ';')
		return (wr_er("bash: : No such file or directory\n", 1));
	return (0);
}

int	preparser_delimiter(char *commands_line, int i)
{
	if (base_delimiter(commands_line, i))
		return (1);
	if (quotes_delimiter(commands_line, i))
		return (1);
	return (0);
}

int	precheck_redirect(char *commands_line, int *i)
{
	if (commands_line[*i] != '>' && commands_line[*i] != '<')
		return (0);
	if (commands_line[*i] == '<')
	{
		(*i)++;
		if (commands_line[*i] == '<')
			(*i)++;
	}
	else if (commands_line[*i] == '>')
	{
		(*i)++;
		if (commands_line[*i] == '>')
			(*i)++;
	}
	while (commands_line[*i] == ' ' || commands_line[*i] == '\t')
		(*i)++;
	return (preparser_delimiter(commands_line, *i));
}
