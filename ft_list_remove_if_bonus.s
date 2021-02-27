	global ft_list_remove_if
; rdi  = t_list **begin_list  rsi = void *data_ref  rdx = cmp()  rcx  = free_fct(void *)

section .text
	ft_list_remove_if :
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
		mov r11, rdi ; r11 = begin_list
		mov rdi, [rdi]
		cmp rdi, 0     ; !begin_list
		je return
		mov r10, [r11]

	while : 
		mov r8, [rdi + 8]
		;cmp r8, 0
		;je end_queue
		push rdx
		push rdi
		mov rdi, [rdi]
		call rdx
		pop rdi
		pop rdx
		je clear
		cmp r8, 0
		je end_queue
		inc r13
		mov r10, rdi
		mov rdi, [rdi + 8]
		jmp while

	clear_head : 
		mov rdi, r8
		mov [r11], rdi
		mov r10, [r11]
		inc r13
		jmp while

	clear :
		push rdi
		push rcx
		push rdx
		push rsi
		;mov rdi, r15
		call rcx
		pop rsi
		pop rdx
		pop rcx
		pop rdi
		;mov r15, 0
		;mov [rdi], r15
		cmp r8, 0
		je clear_end
		cmp r13, 0
		je clear_head
		mov [r10 + 8], r8
	
	clear_inc :
		mov rdi, r8
		jmp while

	clear_end :
		mov r15, 0
		mov [r10 + 8], r15

	end_queue : 
		mov rdi, [r11]
		mov r15, [rdi + 8]
		cmp r15, 0
		je check_empty_queue
		jmp return

	check_empty_queue : 
		push rdx
		push rdi
		mov rdi, [rdi]
		call rdx
		pop rdi
		pop rdx
		je void_queue
		
	return :
		pop r8
		pop r9
		pop r10
		pop r11
		ret

	void_queue :
		push rdi
		push rcx
		push rdx
		push rsi
		;mov rdi, r15
		call rcx
		pop rsi
		pop rdx
		pop rcx
		pop rdi
		mov rdi, 0 
		jmp return

