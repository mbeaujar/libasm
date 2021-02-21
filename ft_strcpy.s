    global ft_strcpy

section .text
    ft_strcpy : 
        xor rax, rax

    while : 
        mov al, byte [rsi + rax]
        mov byte [rdi + rax], al
        cmp al, 0
        je return
        inc rax
        jmp while


    return : 
        mov rax, rdi
        ret