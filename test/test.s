section .text
	global _test

_test:
	push ebp
	mov ebp, esp

	mov eax, [ebp+8]

	mov esp, ebp
	pop ebp
	ret