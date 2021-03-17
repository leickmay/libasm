SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS		=	$(SRCS:.s=.o)

CC			= nasm 

FLAGS		= -f macho64

.s.o:
	$(CC) $(FLAGS) $< -o $(<:.s=.o)

NAME		=	libasm.a

RM			=	rm -f

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)
	
all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

