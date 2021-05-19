;=====================================================================
;	size_t	ft_strlen(const char *str)
;	{
;		size_t	i;
;
;		i = 0;
;		while (str[i])
;			i++;
;		return (i);
;	}
;=====================================================================
section .text
	global _ft_strlen

_ft_strlen:
	mov rax, 0 ; rax = 0
	jmp count  ; count 레이블로 점프

count:
	cmp BYTE [rdi + rax], 0 ; (rdi + rax)의 주소를 0과 비교해서
	je exit					; 두 값이 같으면 exit레이블로 점프
	inc rax					; 같지 않다면 rax 1증가
	jmp count				; 다시 count 레이블로 무한 루프

exit:
	ret						; 종료
