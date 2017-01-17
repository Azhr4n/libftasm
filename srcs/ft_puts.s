section .data
	newline db 10
	nullmsg:
		.string db "(null)"
		.len equ $ - nullmsg.string

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	cmp rdi, 0
	je null
	enter 0, 0
	push rdi
	call _ft_strlen
	mov rdx, rax
	pop rsi
	mov rdi, 1
	mov rax, 0x2000004
	syscall
	cmp rax, -1
	je end
	jmp nl

null:
	mov rdi, 1
	lea rsi, [rel nullmsg.string]
	mov rdx, nullmsg.len
	mov rax, 0x2000004
	syscall

nl:
	mov rdx, 1
	lea rsi, [rel newline]
	mov rax, 0x2000004
	syscall
	mov rax, 10
	leave
	ret

end:
	leave
	ret