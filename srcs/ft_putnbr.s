section .bss
	buff resb 1

section .text
	global _ft_putnbr

_ft_putnbr:
	enter 0, 0
	mov rax, rdi

div:
	
	leave
	ret

	mov rdx, 0
	mov rbx, 10
	div rbx

fill:
	lea rcx, [rel buff]
	mov byte[rcx], '0'
	add [rcx], rdx

write:
	push rax
	mov rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel buff]
	mov rdx, 1
	syscall
	pop rax
	cmp rax, 0
	je end
	jmp div

neg:
	;push rax
	;lea rcx, [rel buff]
	;mov byte[rcx], '-'

	;mov rax, 0x2000004
	;mov rdi, 1
	;lea rsi, [rel buff]
	;mov rdx, 1
	;syscall

	;pop rax
	neg rax
	jmp div

end:
	leave
	ret