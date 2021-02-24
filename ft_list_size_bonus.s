		global ft_list_size


section .text
	ft_list_size :
		push r8
		xor rax, rax
		cmp rdi, 0
		je return

	count : 
		inc rax		  ; count++

	while : 
		mov r8, [rdi + 8] ; next dans r8
		mov rdi, r8       ; current devient next
		cmp rdi, 0	  ; next == NULL ?? 
		je return
		jmp count


	return :
		pop r8
		ret
