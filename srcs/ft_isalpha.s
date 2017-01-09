section .text
	global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jl false
	cmp rdi, 91
	jl true
	cmp rdi, 97
	jl false
	cmp rdi, 123
	jl true
false:
	mov rax, 0
	ret
true:
	mov rax, 1
	ret