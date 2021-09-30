/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:24 by seonggki          #+#    #+#             */
/*   Updated: 2021/09/30 16:59:11 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
//환경 내에서 경로 라인을 찾는 함수 각 명령 경로를 분할하고 테스트한 다음 경로를 반환
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}
//오류 표시
void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
/*
실행하기 전에 명령을 받아서 find_path로 보내는 함수
int execve(const char *path, char *const argv[]. char *const envp[])
대체할 프로세스 경로, 대체할 프로세스의 인수, 임의 지정할 환경 변수
find_path(cmd[0], envp) = 현재 프로세스에서 무슨 프로세스로 대처할지 결정
cmd = char형 포인터 배열을 통해 인수를 받음
envp = 새로 대체될 프로그램의 환경 정보를 임의로 설정
*/
void	execute(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
}
//터미널에서 입력을 읽고 라인을 반환하는 함수
int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
