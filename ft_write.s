        global _ft_write
        extern __errno_location
; rdi=argv[0] rsi=argv[1] rdx=argv[2] rcx, r8, r9

section .text
    _ft_write :
        mov rax, 0x02000004         ; system call for write mac =0x02000004 linux = 1 
        syscall
        cmp rac, 0
        jl err
        ret

err : 