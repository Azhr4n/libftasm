section .text
	global _ft_strcat

_ft_strcat:
	enter 0, 0
	push rdi
loop:
	cmp byte[rdi], 0
	jz loop2
	inc rdi
	jmp loop
loop2:
	cmp byte[rsi], 0
	jz end
	mov rbx, [rsi]
	mov [rdi], rbx
	inc rdi
	inc rsi
	jmp loop2
end:
	mov byte[rdi], 0
	pop rdi
	mov rax, rdi
	leave
	ret
