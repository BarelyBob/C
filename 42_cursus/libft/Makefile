SRCS	:=	ft_isascii.c	\
		ft_isdigit.c	\
		ft_putchar.c	\
		ft_putendl.c	\
		ft_putstr.c	\
		ft_strjoin.c	\
		ft_striter.c	\
		ft_tolower.c	\
		ft_memcpy.c	\
		ft_strlen.c	\
		ft_toupper.c	\
		ft_atoi.c	\
		ft_isprint.c	\
		ft_memset.c	\
		ft_isalpha.c	\
		ft_putnbr.c	\
		ft_isalnum.c	\
		ft_strclr.c	\
		ft_bzero.c	\
		ft_strlcpy.c

SRCS_D	:=	srcs/

OBJS_D	:=	objs/

OBJS	:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD	:=	libft.h

HEAD_D	:=	includes/

CFLAGS	:=	-Wall -Wextra -Werror -g3 #-fsanitize=address

AR	:=	ar rcs #verifier si s autorise

NAME	:=	libft.a

all	:	$(NAME)

$(NAME)	:	$(OBJS_D) $(OBJS) #Makefile #retirer pour push
	$(AR) $(CLFAGS) -o $(NAME) $(OBJS)

$(OBJS)	:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD)
	$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)
clean	:
	$(RM) -r $(OBJ) $(OBJS_D)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY: all clean fclean re
