;=====================================================================
;	int ft_strcmp(const char *s1, const char *s2)
;	{
;		int i;
;
;		i = 0;
;		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
;		{
;			i++;
;		}
;		return (s1[i] - s2[i]);
;	}
;=====================================================================
section .text
    global _ft_strcmp

_ft_strcmp:
	mov rax, 0 ; rax = 0;
	mov rbx, 0 ; rbx = 0;
	mov rcx, 0 ; rcx = 0;
	jmp compare ; JMP는 jump의 약자로써 원하는 레이블로 점프하는 명령어

compare:
	mov al, BYTE [rdi + rcx] ; rdi에는 const char *s1 이 rsi에는 const char *s2가 저장
	mov bl, BYTE [rsi + rcx] ; rdi와 rsi에서 한 바이트씩을 al과 bl에 저장
	cmp al, bl ; 비교한다.
	jne diff ; 값이 다르다면 diff로 점프
	je	same ; 두 값이 같으면 same 레이블로 점프.

diff:
	sub rax, rbx ; 이 둘의 차를
	ret ; 리턴

same:
	cmp al, 0 ; 값이 같고 al이 끝에 도달했다면
	je 	end ; Jump if Equal의 약자로 CMP로 두 값을 비교했을 때 두 값이 같으면 원하는 레이블로 점프하는 명령어(end로 점프)
	inc rcx ; rcx를 1씩 증가시킨다
	jmp compare ; 값이 같고 아직 끝에 도달하지 않았다면 루프를 돈다.(compare 레이블로 점프)

end:
	mov rax, 0 ; 0을 리턴하고
	ret ; 종료한다.
