        global ft_strcmp

section .text
    ft_strcmp : 
        xor rax, rax
        xor rbx, rbx

    while :
        mov al, [rdi]
        mov bl, [rsi] 
        cmp al , bl
        jne return
        cmp al, 0
        je return
        cmp bl, 0
        je return
        inc rsi
        inc rdi
        jmp while

    return : 
        sub rax, rbx
        ret 