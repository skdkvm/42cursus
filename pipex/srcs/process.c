/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:02 by seonggki          #+#    #+#             */
/*   Updated: 2021/09/30 16:40:30 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
//포크 내부에서 실행되는 자식 프로세스 파일을 가져오고 출력을 파이프에 전달하고 exec함수로 닫음
void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);//./pipex <file1> <cmd1> <cmd2> file2 중 file1
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);//fd[1] = stdout_fileno의 값 1으로 지정
	dup2(filein, STDIN_FILENO);//filein = stdin_fileno의 값 0으로 지정
	close(fd[0]);//fd[0] 쓰기 닫음
	execute(argv[2], envp);//./pipex <file1> <cmd1> <cmd2> file2 중 cmd1
}
//파이프에서 데이터를 가져오는 부모 프로세스 표준 출력을 변경 exec 함수로 닫음
void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);//./pipex <file1> <cmd1> <cmd2> file2 중 file2
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);//fd[0] = stdin_fileno의 값 0으로 지정 
	dup2(fileout, STDOUT_FILENO);//fileout = stdout_fileno의 값 1으로 지정
	close(fd[1]);//fd[1] 읽기 닫음
	execute(argv[3], envp);//./pipex <file1> <cmd1> <cmd2> file2 중 cmd2
}