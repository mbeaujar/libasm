    global ft_strcpy

section .text
    ft_strcpy : 
        xor rax, rax

    while : 
        cmp byte [rsi + rax], 0
        je return
	mov dl, [rsi + rax]
	mov [rdi + rax], dl
        inc rax
        jmp while

    return :
    	mov byte [rdi + rax], 0
        mov rax, rdi
        ret
