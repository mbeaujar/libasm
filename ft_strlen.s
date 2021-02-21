    global ft_strlen

section .text
    ft_strlen : 
        xor rbx, rbx

    compare : 
        cmp byte [rdi + rbx], 0
        jne increment

    increment : 
        inc rbx

    ret