/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:45:01 by jo                #+#    #+#             */
/*   Updated: 2020/08/12 15:57:03 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*g_input;
int	g_ok;

void	print(int *mat)// mat 배열에 문자를 넣기 위한 작업
{
	int		i;
	char	c;

	i = 0;
	while (i < 16)// 문자와 줄바꿈 또는 공백을 한꺼번에 적어주므로 i는 31이 아닌 16이다.
	{
		c = mat[i] != -1 ? mat[i] + 48 : '.';// 문자 c는 mat 배열이 -1이 아니면 mat 배열에 있는 수자에 문자 '0'의 아스키 코드인 48을 더해 숫자를 문자로 변환
		write(1, &c, 1);
		write(1, (i + 1) % 4 == 0 ? "\n" : " ", 1);// mat배열의 인덱스 + 1을 4로 나누었을 때 나머지가 0이면 줄바꿈 0이 아니라면 공백을 적어준다.
		i++;
	}
}
// 각 행 열의 방향에서 보이는 상자의 개수를 세어주는 함수
// 이때의 a, b, c, d는 상자 1, 상자 2, 상자 3, 상자 4가 들어있다.
int		count(int a, int b, int c, int d)
{
	int i;// i는 배열의 인덱스
	int res;// 바라볼 때 보이는 상자의 개수
	int last;// 가장 높은 상자
	int ar[4];// 상자가 들어있는 배열
// 상자 1, 상자 2, 상자 3, 상자 4가 배열에 들어가 있다.
	ar[0] = a;
	ar[1] = b;
	ar[2] = c;
	ar[3] = d;
	i = 1;// i가 0이 아니라 1인 이유는 last = ar[0](가장 높은 상자)와 비교하기 위해서이다.
	res = 1;// res는 바라볼 때 보이는 상자의 개수이다. ar[0]에 어떤 높이의 상자가 오더라도 처음은 무조건 보이므로 1부터 시작한다.
	last = ar[0];//
	while (i < 4)// 상자의 개수는 4개 이므로 i < 4이다.
	{   // 가장 높은 상자(last = ar[0])가 상자가 들어가 있는 배열(ar[i])에서
		// 현재 상자(ar[i])보다 작으면
		// 가장 높은 상자는 상자가 들어가 있는 배열의 현재 상자(ar[i])이므로
		// last = ar[i]이다.
		if (last < ar[i])
		{
			last = ar[i];
			// 이때, 가장 높은 상자가 배열의 현재 상자로 바뀌므로
			// 바라볼 때 상자를 가리지 않으므로
			// 상자가 하나 더 보인다.
			// 따라서 보이는 상자의 개수를 하나 더 증가한다.
			res++;
		}
		// 상자가 들어가 있는 배열의 이동(오른쪽으로 한 칸 씩)
		i++;
	}
	// 보이는 상자의 개수를 보여준다.
	return (res);
}

int		ok(int *mat)
{
	int i;
// 이때, i는 g_input 배열의 인덱스
	i = 16;
	while (i--)
		if (i < 8)
		{/* g_input[]은 메인 함수에서 전달되는 문자열의 배열을
			숫자 배열로 바꾼(숫자 문자의 아스키 코드 - 48(‘0’의 아스키 코드)) 배열
			g_input 배열의 숫자와 mat 함수의 보이는 상자 개수를 세어주는 함수인 count와 비교했을 때
			맞지 않는 다면 return 0으로 ok 함수를 빠져나온다.
		    이때, ok(ar) = 0 —> func함수에서 else로 간다.
			맞다면 While로 인해 반복하다가 return 1로 ok함수를 빠져나온다.
		    이대, ok(ar) = 1 —> func함수에서 if 조건에 맞게 된다.
			i < 4 일 때, i 가 0이라면 count(mat[0], mat[4], mat[5], mat[12])와 g_input[0]을 비교
			i < 8 일 때, i가 4라면 count(mat[12], mat[8], mat[4], mat[0])와 g_input[4]를 비교*/
			if (g_input[i] != count(mat[i + (i < 4 ? 0 : 8)],
			mat[i + 4], mat[i + (i < 4 ? 8 : 0)], mat[i + (i < 4 ? 12 : -4)]))
				return (0);
		}
		else if (i < 12)//i < 12일때, i가 8라면 count(mat[0], mat[1], mat[2], mat[3])와 g_input[8]을 비교
		{
			if (g_input[i] != count(mat[(i - 8) * 4],
			mat[(i - 8) * 4 + 1], mat[(i - 8) * 4 + 2], mat[(i - 8) * 4 + 3]))
				return (0);
		}
		else if (i < 16)//i < 16일때, i가 12라면 count(mat[3], mat[2], mat[1], mat[0])와 g_input[12]를 비교
		{
			if (g_input[i] != count(mat[(i - 12) * 4 + 3],
			mat[(i - 12) * 4 + 2], mat[(i - 12) * 4 + 1], mat[(i - 12) * 4]))
				return (0);
		}
	return (1);
}

void	func(int *ar, int line, int index)
{
	int i;
	int i1;
	int flag;

	i = 4;
	/* 이때, line은 가로 줄 [행]
		ex> [0, 1, 2, 3]
			[4, 5, 6, 7]
			[8, 9, 10, 11]
			[12, 13, 14, 15]
	 line이 4이고, ar 배열의 유효성이 1이라면(오류 / 에러 X, 출력 가능) */
	if (line == 4 && ok(ar))
	{
		g_ok = 1;// g_ok를 1로 설정한다. 다른 여러 솔루션이 있더라도 출력하지 않고, 첫 번째로 찾은 방법으로만 출력하기 위해서이다.
		print(ar);// ar 배열을 출력해준다. 이때의 ar배열은 숫자 배열인 mat 배열이다.
	}
	else// line의 개수가 4가 아니거나 ar 배열의 유효성 검사가 되지 않을 경우
		while (i-- && !g_ok)// i가 줄어들고, g_ok가 0일 때(g_ok가 0이란 아직 첫 번째로 방법을 찾지 못했다는 뜻)
		{
			i1 = 4;
			flag = 1;
			while (i1-- && flag)
				if ((index > i1 && ar[i1 + line * 4] == i + 1) ||
				(line > i1 && ar[index + i1 * 4] == i + 1))
					flag = 0;
			ar[index + line * 4] = i + 1;
			if (flag)
				func(ar, index + 1 == 4 ? line + 1 : line,
				index + 1 == 4 ? 0 : index + 1);
		}
}
/*int argc : 메인함수에 전달되는 정보의 개수
  char *argv[] : 메인함수에 전달되는 실질적인 정보 / 문자열의 배열
			첫번째 문자열은 프로그램의 실행경로
			./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2”를 실행하고 싶을 때
			 —> 실행경로 정보 1개와 매개변수 1개이므로
				argc는 2가 된다.
				이때, ./rush-01 4 3 2 라면 */
int		main(int argc, char *argv[])
{
	int *mat;
	int i;// 이때, i는 문자열의 길이 배열을 받는 인덱스이다.

	i = 0;
	if (argc == 2)//argc가 2 일 때만 실행하고, 아니면 i가 31이 아니거나 유효성 검사가 실행X  Error 출력
	{
		g_ok = 0;// 유효성 검사를 false로 둔다.
		g_input = malloc(sizeof(int) * 16);// g_input이란 문자열의 배열을 숫자로 바꿔서 넣어준 int 배열이다.
		mat = malloc(sizeof(int) * 16);// mat이란 결과를 출력하기 전 숫자를 담고 있는 int 배열이다.
		while (argv[1][i] && i != -1)
		{   /*argv[1][I]의 문자열에 4 이상, 0, 음수 가 들어간다면
			else if로 넘어간다.
			이때, else If에서 위의 수가 공백, 탭, 줄바꿈이 아니므로
			i는 -2로 된다.
			다음 i++;를 실행해주면, i는 -1이 되고
			while의 조건에 부합하지 않으므로(i != -1)
			i가 31인 조건에 부합한다면 유효성 검사를 실시하게 되는데
			이때 유효성 검사가 안되면 Error를 출력한다.*/
			if ('1' <= argv[1][i] && argv[1][i] <= '4')
			/* g_input[I /2]는 숫자열이고, argv[1][I]는 문자열이다.
			   따라서, 문자열에서 문자로 선언된 숫자(‘0’ ‘4’ 등)의
			   아스키코드를 빼주어 숫자열에 넣어준다.
			   똑같은 위치에 넣어주어야 하므로 짝수에만 넣어주면 된다.
			   만약, “V4 3 1 1…”홀수에 숫자가 들어간 문자열을 넣어주더라도
			   Error가 발생한다.
			   왜냐하면, 유효성 검사가 실행되지 않기 때문이다.
			   만약, i가 31이고, “11111111111111111111111111111”라고 한다면
			   g_input = {1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1}이고,
			   유효성 검사를 실시할 때, 재귀함수를 못 돌고 나온다.
			   재귀함수 : 하나의 함수에서 자신을 다시 호출하여 작업을 수행하는 방식
			   g_input[i / 2] = argv[1][i] - 48;
			   문자열 argv[1][I]가 숫자가 아니고, 공백, 탭, 줄바꿈이 아닐 때
			   i는 -2로 된다.
			   다음 i++;를 실행해주면, i는 -1이 되고
			   while의 조건에 부합하지 않으므로 (i != -1)
			   i가 31인 조건에 부합한다면 유효성 검사를 실시하게 되는데
			   이때 유효성 검사가 안되면 Error를 출력한다.*/
				g_input[i / 2] = argv[1][i] - 48;
			else if (!(argv[1][i] == ' ' ||
			argv[1][i] == '\t' || argv[1][i] == '\n'))
				i = -2;
			i++;
		}
		// 문자열 argv[1][I]의 길이가 31이면(유효성 검사에 들어가기 전에 오류가 들어갈 수 있지만, 출력될 경우에는 숫자 16개, 띄어쓰기 15개로 총 길이가 31이다.)
		if (i == 31)
			func(mat, 0, 0);// mat 함수의 0, 0부터 func 함수를 실행한다.
		free(g_input);// g_input 메모리를 할당해주었으므로 필수적으로 해제해야 한다.
		free(mat);// mat 메모리를 할당해주었으므로 필수적으로 해제해야 한다.
	}
	// 문자열 배열에서 숫자를 추가하거나 없애면 Error —> I != 31
	// !g_ok란 g_ok가 0이란 뜻이고,
	// 유효성 검사가 실행되지 않더라도 Error 표시
	if (i != 31 || !g_ok)
		write(1, "Error\n", 6);// 오류가 발생할 경우에는 ‘Error’가 표시된 다음 줄바꿈되어야 한다.
}
/* subject에서 각 시선(행마다 두 가지, 열마다 두가지)란 상하좌우를 의미한다.
./rush-01 “4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2”
	4 	3 	2	 1
   4	ㅁ 	ㅁ 	ㅁ 	ㅁ	1
   3	ㅁ 	ㅁ 	ㅁ 	ㅁ	2
   2	ㅁ 	ㅁ 	ㅁ 	ㅁ	2
   1	ㅁ 	ㅁ 	ㅁ 	ㅁ	2
	1	2	2	2
배열의 인덱스 표시
	0	1	2	3
	————————
8	0	1	2	3	12
	————————
9	4	5	6	7	13
	————————
10	8	9	10	11	14
	————————
11	12	13	14	15	15
	————————
	4	5	6	7
경우의 수를 모두 체크해주려 했는데 너무 많아서
1, 2, 3, 4의 경우의 수가 4!이고,
4 X 4
출력된 결과에는 첫 번째로 찾은 방법이 담겨야 합니다.
다른 솔루션이 있을 수도 있지만,
그것을 막아주기 위해 g_ok를 사용했다.
한번 찾으면 필요 없으니까
g_ok를 boolean으로 생각해도 될까?
오류가 발생했다(예외 처리)
매개변수(argc 문자열)가 2가 아닌 경우
ex> ./rush-01 2 3 4 —> 매개변수가 5개(띄어쓰기로 구분)
I(문자열의 길이 배열을 받는 인덱스)가 31
문자 16, 띄어쓰기 15이므로, i는 31 */
