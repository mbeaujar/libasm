	global ft_list_sort

;rdi = t_list **list rsi = cmp()

section .text
	ft_list_sort :
		push r12
		push r11
		push r10
		push r8
		mov rcx, rsi
		cmp qword [rdi], 0
		je return
		mov r12, rdi
		mov rdi, [r12]
		cmp rdi, 0
		je return
		cmp rsi, 0
		je return

	while :
		mov r8, [rdi + 8]
		cmp r8, 0
		je return
		push rcx
		push rdi
		push rsi
		mov rdi, [rdi]
		mov rsi, [r8]
		call rcx
		pop rsi
		pop rdi
		pop rcx
		jg swap
		mov rdi, [rdi + 8]
		jmp while

	swap :
		mov r10, [rdi]
		mov r11, [r8]
		mov [r8], r10
		mov [rdi], r11
		mov rdi, [r12]
		jmp while


	return : 
		pop r8
		pop r10
		pop r11
		pop r12
		ret
