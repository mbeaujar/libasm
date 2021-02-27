	global ft_list_remove_if
; rdi  = t_list **begin_list  rsi = void *data_ref  rdx = cmp()  rcx  = free_fct(void *)

section .text
	ft_list_remove_if :
		push r11
		push r10
		push r9
		push r8
		cmp rdi, 0 ; !begin_list 
		je return
		cmp rsi, 0 ; !data_ref
		je return
		cmp rdx, 0 ; !cmp() 
		je return
		cmp rcx, 0 ; !free_fct()
		je return
		mov r11, rdi ; r11 = begin_list
		mov rdi, [rdi]
		cmp rdi, 0     ; !*begin_list
		je return
		mov r10, 0 ; previous = 0

	while : 
		mov r8, [rdi + 8]
		cmp r8, 0
		je end_queue
		push rdx
		push rdi
		mov rdi, [rdi]
		call rdx
		pop rdi
		pop rdx
		je clear
		mov r10, rdi
		mov rdi, [rdi + 8]
		jmp while

	clear :
		push rdi
		mov rdi, [rdi]
		call rcx
		push rdi
		cmp r10, 0
		je clear_head
		mov [r10], r8
	
	clear_head :
		mov rdi, [rdi + 8]
		jmp while

	end_queue : 
		mov rdi, [r11] 

	return :
		pop r8
		pop r9
		pop r10
		pop r11
		ret

