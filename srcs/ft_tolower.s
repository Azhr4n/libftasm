section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 'A'
	jl end
	cmp rdi, 'Z'
	jg end
	add rdi, 32
end:
	mov rax, rdi
	ret