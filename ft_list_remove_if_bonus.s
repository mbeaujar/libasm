	global ft_list_remove_if
	extern free
; rdi  = t_list **begin_list  rsi = void *data_ref  rdx = cmp()  rcx  = free_fct(void *)

section .text
	ft_list_remove_if :
		push r13
		push r11
		push r10
		push r9
		push r8
		xor r13, r13
		cmp rdi, 0 ; !*begin_list 
		je return
		cmp rsi, 0 ; !data_ref
		je return
		cmp rdx, 0 ; !cmp() 
		je return
		cmp rcx, 0 ; !free_fct()
		je return
		mov r11, rdi ; r11 = **begin_list
		mov rdi, [rdi]
		cmp rdi, 0     ; !begin_list
		je return
		mov r10, [r11]

	while : 
		mov r8, [rdi + 8] ; next = actual->next
		push rdx
		push rdi
		push rsi
		push rcx
		mov rdi, [rdi] ; rdi = begin->data
		call rdx  ; cmp(begin->data, data_ref)
		pop rcx
		pop rsi
		pop rdi
		pop rdx
		je clear_data
		cmp r8, 0
		je end_queue
		inc r13
		mov r10, rdi   ; previous = actual
		mov rdi, [rdi + 8] ; actual = next
		jmp while

	clear_data : 
		push rdi
		push rsi
		push rcx
		push rdx
		;mov rdi, [rdi] ; rdi = begin->data
		;call rcx    ; free(begin->data)
		pop rdx
		pop rcx
		pop rsi
		pop rdi

	clear_cell : 
		push rdi
		push rsi
		push rcx
		push rdx
		;call free ; free(begin)
		pop rdx
		pop rcx
		pop rsi
		pop rdi
		cmp r13, 0
		je head_next
		cmp r8, 0
		je head_end


	relink_queue : 
		mov [r10 + 8], r8
		mov rdi, r8
		cmp r8, 0
		je end_queue
		jmp while

	
	head_next : 
		mov r15, [r11 + 8]
		mov [r11], r15   ; pointer begin_list++
		mov rdi, [rdi + 8] ; actual = next
		cmp rdi, 0
		je return
		jmp while

	head_end : 
		mov r15, 0
		mov [r10 + 8], r15

	end_queue :
		mov rdi, [r11]

		
	return :
		pop r8
		pop r9
		pop r10
		pop r11
		pop r13
		ret

