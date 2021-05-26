NAME	=	libftprintf.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	\
ft_printf.c \
ft_formatprint.c \

B_SRCS	= \

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

all	:	$(NAME)

clean:
		$(MAKE) fclean -C ./libft
		rm -f $(OBJS) $(B_OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

bonus:	$(OBJS) $(B_OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(B_OBJS)

.PHONY:	all clean fclean re bonus
