;=====================================================================
;char *ft_strcpy(char *dest, char *src)
;{
;  int i;
;
;  i = 0;
;  while (src[i] != '\0')
;  {
;    dest[i] = src[i];
;    i++;
;  }
;  dest[i] = '\0';
;  return (dest);
;}
;=====================================================================
section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, 0 ; rax = 0;

copy:
	mov cl, BYTE [rsi + rax] ; rsi는 첫번째 매개변수 dest, rdi는 두번째 매개변수 src, cl은 8비트 레지스터
	mov BYTE [rdi + rax], cl ; cl은 8비트이고 BYTE형도 8비트이므로 비교가 가능하다.
	cmp cl, 0 ; 두 값이 같으면
	je exit ; exit레이블로 점프
	inc rax ; rax++
	jmp copy ; copy레이블로 점프

exit:
	mov rax, rdi ; rax = rdi
	ret ; 종료

; (rax가 64비트, eax가 32비트, ax가 16비트) 16비트는 8비트씩 ah와 al로 나뉜다.
; rcx는 ch cl로 나뉜다. cl은 8비트이고 BYTE형도 8비트이므로 비교가 가능하다.
