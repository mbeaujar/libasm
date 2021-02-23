	global ft_list_push_front
	extern malloc

;rdi = list  rsi = data

section .text
	ft_list_push_front :
		push rdi
		push rsi

		mov rdi, 16
		call malloc wrt ..plt
		pop rsi
		pop rdi
		cmp rax, 0
		je malloc_fail
		mov [rax], rsi
		mov rcx, [rdi]
		mov [rax + 8], rcx
		mov [rdi], rax

	malloc_fail :
		ret
