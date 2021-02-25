NAME = libasm
LIB = libasm.a
RM = rm -f
SRCS = ft_write.s ft_read.s ft_strlen.s ft_strcmp.s \
       ft_strcpy.s ft_strdup.s ft_atoi_base_bonus.s \
       ft_list_push_front_bonus.s ft_list_size_bonus.s \
       ft_list_remove_if_bonus.s ft_list_sort_bonus.s

NASM = nasm
NASMFLAGS= -f elf64
OBJS = ${SRCS:.s=.o}

%.o : %.s
	@$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(LIB) $(OBJS)
	@gcc -w -no-pie main.c -L. -lasm 
	@./a.out

bonus : $(NAME)

clean : 
	@$(RM) $(OBJS)

fclean : clean 
	@$(RM) $(LIB)

re : fclean all
