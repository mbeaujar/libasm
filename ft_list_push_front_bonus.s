	global ft_list_push_front
	extern malloc

;rdi = list  rsi = data

section .text
	ft_list_push_front : 
		push rdi
		push rbx
		xor rax, rax

		mov rdi, 16
		call malloc wrt ..plt
		pop rdi
		cmp rax, 0
		je malloc_fail
		mov [rax], rsi
		mov [rax + 8], rdi
		mov [rdi], rax

	malloc_fail :
		ret
