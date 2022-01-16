/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:16:33 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:16:35 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_commands
{
	int					pipe;
	int					fd_flag;
	int					fd_out;
	int					fd_in;
	char				*fd_in_name;
	int					argc;
	char				*name;
	char				**argv;
	int					*delete_fd;
	int					colun_del_fd;
	struct s_commands	*next;
}						t_commands;

#endif
