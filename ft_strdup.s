	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy
	extern __errno_location

section .text
	ft_strdup : 
		call ft_strlen wrt ..plt
		inc rax
		push rdi
		mov rdi, rax
		call malloc wrt ..plt
		cmp rax, 0
		je error
		mov rdi, rax
		pop rbx
		mov rsi, rbx
		call ft_strcpy wrt ..plt

	return :
		ret 
	
	error : 
		push rax
		call __errno_location wrt ..plt
		mov [rax], rdi
		mov rax, -1
		ret
