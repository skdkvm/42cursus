/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:20:20 by seonggki          #+#    #+#             */
/*   Updated: 2021/09/30 17:06:45 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
//자식 및 부모 프로세스를 실행하거나 오류표시
int	main(int argc, char **argv, char **envp)
{
	int	fd[2];//두개의 fd를 저장할 배열 0 = 쓰기 / 1 = 읽기
	int	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)//pipe(fd)호출 fd[0],fd[1]에 값을 채움
			error();
		pid1 = fork();//새로 프로세스를 생성 리턴값 0 / 실패시 EOF 리턴
		if (pid1 == -1)
			error();
		if (pid1 == 0)//자식 프로세스
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);//waitpid 부모프로세스 자식 프로세스 모두 각자 실행하고 자식 프로세스가 종료 될때까지 기다림
		parent_process(argv, envp, fd);
		close(fd[0]);//fd[0] 쓰기 닫음
		close(fd[1]);//fd[1] 읽기 닫음
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> file2\n", 1);
	}
	return (0);
}
