section .text
	global _ft_bzero

_ft_bzero:
	cmp rdi, 0
	je end
	mov rbx, rdi
	mov rax, rsi
loop:
	cmp rax, 0
	jle end
	mov byte[rbx], 0
	inc rbx
	dec rax
	jmp loop
end:
	ret