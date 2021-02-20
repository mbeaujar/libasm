NAME = libasm
LIB = libasm.a
RM = rm -f
SRCS = ft_write.s 
NASM = nasm
NASMFLAGS= -f macho64
OBJS = ${SRCS:.s=.o}

%.o : %.s
	@$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)


$(NAME) : $(OBJS)
	@ar rcs $(LIB) $(OBJS)
	@gcc -L. -lasm main.c 
	@./a.out

clean : 
	@$(RM) $(OBJS)

fclean : clean 
	@$(RM) $(LIB)

re : fclean all
