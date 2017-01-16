section .text
	global _ft_strlen

_ft_strlen:			;http://www.int80h.org/strlen/
	push rdi
	mov rdi, [rsp + 8]

	sub rcx, rcx
	not rcx
	sub al, al
	cld
	repne scasb
	not rcx
	lea rax, [rcx - 1]

	pop rdi
	ret