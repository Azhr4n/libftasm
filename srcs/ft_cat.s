section .bss
	buff:
		.data resb 4096
		.len equ $ - buff.data

section .text
	global _ft_cat

_ft_cat:
	enter 0, 0

read:
	push rdi
	lea rsi, [rel buff.data]
	mov rdx, buff.len
	mov rax, 0x2000003
	syscall
	cmp rax, 0
	jl error
	push rax

write:
	mov rdx, rax
	lea rsi, [rel buff.data]
	mov rdi, 1
	mov rax, 0x2000004
	syscall
	pop rcx
	cmp rax, 0
	jl error
	pop rdi
	cmp rcx, 0
	jg read

end:
	leave
	ret

error:
	pop rdi
	leave
	ret
