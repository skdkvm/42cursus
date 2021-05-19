section .text
	global _ft_write
	extern ___error

_ft_write:
	mov rax, 0x2000004
	syscall
	jc _err
	ret

_err:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1
	ret

; write 함수의 fd, buf, size는 매개변수의 순서와 똑같이 rdi, rsi, rdx를 통해 전달된다.
; syscall를 사용하므로 errno가 출력되도록 작성되어야 한다.
; errno의 주소를 리턴하는 함수
; __error()함수는 외부함수다 (extern)
; __error()함수는 에러번호를 담은 errno의 주소를 리턴한다.
; __error()의 리턴 값 타입은 int*
; __error()함수 사용법 에러가 발생하면 -1을 리턴하고 __error를 사용해서 errno의 값을 세팅
;
; write 함수에서 에러가 발생하면 carry flag 가 1로 바뀌고 rax에 에러 넘버가 저장된다.
; carry flag가 1이 되면 set_error 함수로 jump 한다.
; rax는 사용할 것이기때문에 rcx에 에러 넘버를 백업해둔다.
; *rdi, rsi, rdx는 write 함수에서 사용되므로 추가 저장소는 rcx 등의 다른 레지스터를 사용한다.
; 외부함수인 __error를 호출하면 rax의 에러 넘버를 보고 해당 errno의 주소를 리턴해준다. *여기서 errno는 외부변수
; errno의 주소에 에러 넘버(rcx에 담긴넘버)를 넣어주어 errno를 세팅해준다.
; 마지막으로 rax에 1을 담아 리턴해준다.
; 만약 에러가 발생하지 않는다면 errno에는 변화가 없다. (함수 실행 전 errno가 -1이었다면 실행 후에도 그대로)
; syscall로 write를 호출했을 때 에러가 발생하면 carry flag가 1이 되며 errno를 리턴하게 된다.
; carry flag는 플래그 레지스터 종류 중 하나로 시스템 제어 용도 혹은 어셈블리에서 비교/조건문을 처리용도로 사용되는 상태 레지스터이다.
