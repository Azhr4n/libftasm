section .text
	global _ft_strcmp

_ft_strcmp:
	movzx rax, byte[rdi]
	movzx rdx, byte[rsi]
	cmp rax, 0
	jne check
	cmp rdx, 0
	jne check
	jmp end

check:
	inc rsi
	inc rdi
	cmp rax, rdx
	je _ft_strcmp

end:
	sub rax, rdx
	ret