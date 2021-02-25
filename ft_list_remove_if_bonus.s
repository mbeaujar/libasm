	global ft_list_remove_if
; rdi  = t_list **begin_list  rsi = void *data_ref  rdx = cmp()  rcx  = free_fct(void *)

section .text
	ft_list_remove_if :
		push r10 
		push r8
		mov r10, rdi
		mov r12, [rdi]
		mov rdi, r12
		cmp rdi, 0
		je return
		mov r8, [rdi + 8] ; r8 = begin->next
		;cmp r8, 0
		;je return
	
	head : 
		mov r12, [rdi]
		push rdi
		mov rdi, r12
		call rdx
		pop rdi
		cmp rax, 0
		je clear
		mov r10, rdi
		mov rdi, r8
		cmp rdi, 0
		je return
		mov r8, [rdi + 8]
		jmp return

	clear :
		;mov r12, [rdi]
		push rdi
		;mov rdi, r12
		call rcx
		pop rdi
		;jmp return
		mov rdi, r8
		cmp rdi, 0
		je return
		mov r8, [rdi + 8]
		jmp head

	return :
		pop r8
		pop r10
		ret
