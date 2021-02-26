	global ft_list_sort

;rdi = t_list **list rsi = cmp()

section .text
	ft_list_sort :
		push r8
		push r12
		push r10
		push r11
		;jmp return
		cmp rdi, 0
		je return
		cmp rsi, 0
		je return
		mov r12, [rdi] ; r12 = head of the queue
		mov rdi, [rdi] ; rdi = list
		cmp rdi, 0
		je return
		mov r8, [rdi + 8] ; r8 = list->next
		cmp r8, 0
		je return
		jmp comp

	inc :
		mov rdi, r8  ; rdi = list->next
		mov r8, [rdi + 8] ; r8 = list->next->next
		cmp r8, 0
		je end_queue
		
	comp :
		push rdi
		push rsi
		mov rax, rsi
		mov r11, [rdi]
		mov rdi, r11
		mov rsi, [r8]
		call rax
		pop rsi
		pop rdi
		cmp rax, 0
		jg reverse
		jmp inc

	reverse :
		mov r10, [r8]  ; tmp = list->next
		mov r11, [rdi]
		mov [r8], r11  ; r8 = list
		mov [rdi], r10 ; 
		mov rdi, r12
		mov r8, [rdi + 8]
		cmp r8, 0
		je end_queue
		jmp comp

	end_queue :
		mov rdi, r12

	return :
		pop r11
		pop r10
		pop r12
		pop r8
		ret	
