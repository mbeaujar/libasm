        global ft_strcmp

section .text
    ft_strcmp : 
        xor rax, rax
        xor rbx, rbx

    while :
        mov al, [rsi]
        mov dl, [rdi] 
        cmp al , dl
        jne return
        inc rsi
        inc rdi
        jmp while

    return : 
        sub rax, rbx
        ret 