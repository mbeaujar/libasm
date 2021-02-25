	global ft_list_sort

;rdi = t_list *list rsi = cmp()

section .text
	ft_list_sort :
		push r8
		push r12
		push r10
		xor rax, rax
		mov r12, rdi   ; r12 = begin
		mov r8, [rdi + 8] ; r8 = begin->next

	while :
		push r12
		push r8
		push rdi
		push rsi
		call rsi
		pop rsi
		pop rdi
		pop r8
		pop r12
		cmp rax, 0
		je sort

	
	sort : 


	return :
		pop r10
		pop r12
		pop r8
		ret

	
