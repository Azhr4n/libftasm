section .bss
	buff resb 1

section .text
	global _ft_putnbr

_ft_putnbr:
	enter 0, 0
	mov eax, edi
	test eax, eax
	js neg

init:
	mov rcx, 0

rec:
	mov edx, 0
	mov ebx, 10
	div ebx
	push rdx
	inc rcx
	cmp rax, 0
	je write
	jmp rec

write:
	pop rdx
	dec rcx
	lea rax, [rel buff]
	mov byte[rax], '0'
	add [rax], rdx
	push rcx
	mov rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel buff]
	mov rdx, 1
	syscall
	pop rcx
	cmp rcx, 0
	je end
	jmp write

neg:
	push rax
	lea rcx, [rel buff]
	mov byte[rcx], '-'
	mov rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel buff]
	mov rdx, 1
	syscall
	pop rax
	neg rax
	jmp init

end:
	leave
	ret
