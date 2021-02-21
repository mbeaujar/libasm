    global ft_strcpy

section .text
    ft_strcpy : 
        xor rax, rax
        xor rbx, rbx

    while : 
        cmp byte [rsi], 0
        je return
        mov al, byte [rsi]
        mov byte [rdi], al
        inc rsi
        inc rdi
        jmp whi

    return : 
        mov rax, rdi
        ret