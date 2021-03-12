global _ft_strcpy

_ft_strcpy:
	mov rax, rdi
main:
	cmp [rsi], byte 0
	je return
	mov dl, [rsi]
	mov [rdi], dl
	inc rdi
	inc rsi
	jmp main

return:
	mov [rdi], byte 0
	ret

