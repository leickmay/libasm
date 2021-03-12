global _ft_strcmp

_ft_strcmp:

main:
	cmp [rsi], byte 0
	je return
	cmp [rdi], byte 0
	je return
	mov al, byte [rsi]
	cmp al, byte [rdi]
	je increment
	jne return

increment:
	inc rdi
	inc rsi
	jmp main

return:
	movzx rax, byte [rdi]
	movzx rdx, byte [rsi]
	sub rax, rdx
	ret