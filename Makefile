SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS		=	$(SRCS:.s=.o)

CC			= nasm 

FLAGS		= -f macho64

NAME		=	libasm.a

RM			=	rm -f

$(NAME):	$(SRCS)
	nasm -f macho64 ft_strlen.s
	nasm -f macho64 ft_strcpy.s
	nasm -f macho64 ft_strcmp.s
	nasm -f macho64 ft_write.s
	nasm -f macho64 ft_read.s
	nasm -f macho64 ft_strdup.s
	ar -rcs $(NAME) $(OBJS)
	
all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

