extern _ft_strlen
extern _ft_strcpy
extern _malloc

global _ft_strdup

_ft_strdup:

main:
	push rdi
	call _ft_strlen
	inc rax
	mov rdi, rax
	call _malloc
	cmp rax, byte 0
	je error
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret

error:
	ret