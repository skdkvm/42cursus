;=====================================================================
;	char	*ft_strdup(const char *s1)
;	{
;		char	*str;
;		size_t	i;
;
;		i = 0;
;		str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
;		if (str == 0)
;			return (0);
;		while (s1[i])
;		{
;			str[i] = s1[i];
;			i++;
;		}
;		str[i] = '\0';
;		return (str);
;	}
;=====================================================================
section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:			; ft_strlen(s1 = rdi)
	push rdi		; rdi 의 값을 stack에 백업
	call _ft_strlen ; 동적할당 하기 위해 ft_strlen 호출
	inc rax			; ft_strlen(rdi) + 1
	mov rdi, rax	; 동적할당 한 len 만큼 set 해주고
	call _malloc	; str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	cmp rax, 0		; if (str == 0)
	je exit			;
	mov rdi, rax	; str[i] = s1[i];
	pop rsi			; rdi 레지스터가 가리키고 있는 위치의 스택 공간에서 4byte 만큼을 rsi에 복사, rdi
	call _ft_strcpy	; ft_strcpy(rdi(malloc), rsi(initial rdi))
	ret				; 종료

exit:
	ret				; 종료
