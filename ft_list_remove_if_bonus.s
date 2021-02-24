	global ft_list_remove_if

; rdi  = t_list **begin_list  rsi = void *data_ref  rdx = cmp()  rcx  = free_fct(void *)

section .text
	ft_list_remove_if :
		push r10 
		push r8
		xor r8, r8
		xor r10, r10
		xor rax, rax
		cmp rdi, 0
		je return

	while_first :
		;jmp return
		cmp qword [rdi], 0
		je return
		;jmp return 
		mov r8, [rdi + 8]    ; next dans r8 
		push rdi
		push rsi
		call rdx
		pop rsi
		pop rdi
		cmp rax, 0 	     ; return cmp == 0 ?? 
		je clear_first
		;jmp return
		cmp qword [rdi], 0
		je return
		mov r10, rdi	     ; old devient curr
		mov rdi, r8	     ; curr devient next
		jmp while

	clear_first :
		jmp return
		push rdi
		call rcx	     ; clear la cellule
		pop rdi
		;jmp return
		mov rdi, r8	     ; curr devient next
		jmp while_first

	while :
		;jmp return
		;jmp return
		mov r8, [rdi + 8]    ; r8 devient next
		push rdi
		push rsi
		call rdx
		pop rsi
		pop rdi
		cmp rax, 0
		je clear
		mov r10, rdi	     ; old devient curr
		mov rdi, r8	     ; curr devient next
		jmp while

	clear :
		;jmp return
		push rdi
		call rcx
		pop rdi
		mov r10, r8 	     ; old -> next
		mov rdi, r8	     ; curr devient next
		jmp while


	return :
		pop r8
		pop r10
		ret
