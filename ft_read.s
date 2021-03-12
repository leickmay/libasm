extern ___error
global _ft_read

_ft_read:

main:
	mov rax, 0x2000003
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