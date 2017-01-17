section .text
	global _ft_strncmp

_ft_strncmp:
	mov rcx, rdx
check_end:
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
	dec rcx
	cmp rcx, 0
	je end
	cmp rax, rdx
	je check_end

end:
	sub rax, rdx
	ret