/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:02:55 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/24 20:02:55 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_write_two(int num)
{
	if (num == 7)
		ft_putstr_fd("7번: Error\n벽이 '1'이 아닙니다.\n", 1);
	if (num == 8)
		ft_putstr_fd("8번: Error\n지도 크기가 작습니다.\n", 1);
	if (num == 9)
		ft_putstr_fd("9번: Error\n유저가 하나가 아닙니다.\n", 1);
	if (num == 10)
		ft_putstr_fd("10번: Error\n지도에 유저가 없음.\n", 1);
	if (num == 11)
		ft_putstr_fd("11번: Error\n지도에서 잘못된 입력 값.\n", 1);
	if (num == 12)
		ft_putstr_fd("12번: Error\n파일이 이미 끝났습니다.\n", 1);
	if (num == 13)
		ft_putstr_fd("13번: Error\n정보가 부족합니다.\n", 1);
	if (num == 14)
		ft_putstr_fd("14번: Error\n할당 에러.\n", 1);
	if (num == 15)
		ft_putstr_fd("15번: Error\nbmp 파일 열기 오류.\n", 1);
}

void	error_write(int num)
{
	if (num == 0)
		ft_putstr_fd("0번: Error\n잘못된 값.\n", 1);
	if (num == 1)
		ft_putstr_fd("1번: Error\n이름이 이상하다.\n", 1);
	if (num == 2)
		ft_putstr_fd("2번: Error\n\"저장 안됨.\"\n", 1);
	if (num == 3)
		ft_putstr_fd("3번: Error\n파일 읽기 에러.\n", 1);
	if (num == 4)
		ft_putstr_fd("4번: Error\n맵 크기가 이상해요.\n", 1);
	if (num == 5)
		ft_putstr_fd("5번: Error\n파일 경로가 이상해요.\n", 1);
	if (num == 6)
		ft_putstr_fd("6번: Error\n색상이 틀립니다.\n", 1);
	error_write_two(num);
	exit(0);
}
