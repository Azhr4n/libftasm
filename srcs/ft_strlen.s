section .text
	global _ft_strlen

_ft_strlen:
	sub rcx, rcx
	not rcx
	sub rax, rax
	cld
	repne scasb
	not rcx
	lea rax, [rcx-1]
	ret