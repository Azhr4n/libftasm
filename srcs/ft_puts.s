section .text
	global _ft_puts
	extern ft_strlen

section .data
	newline db 10

_ft_puts:
	push rdi
	call ft_strlen
	pop rdi
	mov rsi, rdi
	mov rdi, 1
	mov rcx, rax
	mov rax, 0x2000004
	syscall