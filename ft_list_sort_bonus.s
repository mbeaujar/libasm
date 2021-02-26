	global ft_list_sort

;rdi = t_list **list rsi = cmp()

section .text
	ft_list_sort :
		push r8
		push r12
		push r10
		cmp rdi, 0
		je return
		cmp rsi, 0
		je return
		mov r12, [rdi]
		mov rdi, [rdi]
		mov r8, [rdi + 8] 
	cmp :
		push rdi
		push rsi
		mov rax, rsi
		mov rdi, [rdi]
		mov rsi, r8
		call rax
		pop rsi
		pop rdi
		cmp rax, 0


	return : 
		pop r10
		pop r12
		pop r8
		ret	
