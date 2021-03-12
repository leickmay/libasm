global _ft_strlen

_ft_strlen:

	xor rdx, rdx
main:
	cmp [rdi], byte 0
	je return
	inc rdi
	inc rdx
	jmp main

return:
	mov rax, rdx
	ret
