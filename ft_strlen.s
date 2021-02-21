    global ft_strlen

section .text
    ft_strlen : 
        xor rax, rax                ; init rax à 0 // meilleur en mémoire qu'un mov
        dec rax                     ; decremente pour -1
    while : 
        inc rax                     ; incremente pour etre a 0 + recursiv
        cmp byte [rdi + rax], 0     ; check si on est à la fin de la chaine 
        jne while                   ; si cmp n'est pas égal alors on re appel la fct
        ret