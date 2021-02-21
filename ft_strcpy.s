    global ft_strcpy

section .text
    ft_strcpy : 
        xor rax, rax
        xor rbx, rbx

    while : 
        mov al, [rdi]
        mov bl, [rsi]
        cmp bl, 0
        je return
        mov bl [rsi], al [rdi]
        inc rdi
        int rsi
        jmp while


    return : 
        ret