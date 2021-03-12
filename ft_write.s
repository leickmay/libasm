extern ___error
global _ft_write

_ft_write:

main:
	mov rax, 0x2000004
	syscall
	jc error
	ret

error:
	mov rdi, rax
	push rdi
	call ___error
	pop rdi
	mov [rax], rdi
	mov rax, -1
	ret