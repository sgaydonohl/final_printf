SRCS		= ft_printf.c \
			LIBFTLIKE/ft_itohex.c LIBFTLIKE/ft_memcpy.c LIBFTLIKE/ft_printnum.c LIBFTLIKE/ft_printunum.c \
			LIBFTLIKE/ft_printhex.c LIBFTLIKE/ft_strlen.c LIBFTLIKE/ft_inarray.c LIBFTLIKE/ft_printptr.c \
			LIBFTLIKE/ft_atoi.c LIBFTLIKE/ft_isdigit.c LIBFTLIKE/ft_ptrlen.c LIBFTLIKE/ft_intlen.c \
			LIBFTLIKE/ft_hexlen.c LIBFTLIKE/ft_uintlen.c \
			SRCS/ft_ifchar.c SRCS/ft_ifint.c SRCS/ft_ifptr.c SRCS/ft_ifstr.c SRCS/ft_ifuint.c SRCS/ft_ifhex.c \
			SRCS/ft_ifpercent.c SRCS/ft_whichattr.c SRCS/ft_addspace.c 

OBJS        = $(SRCS:%.c=%.o)

CFLAGS         = -Werror -Wextra -Wall

NAME        = libftprintf.a

CC             = gcc

HEAD        = INCLUDES/ft_printf.h

all     :
	@make $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o     : %.c
	@$(CC) $(CFLAGS) -I$(HEAD) -o $@ -c $<

clean    :
	@rm -rf $(OBJS)

fclean    :
	@make clean
	@rm -f $(NAME)

re        :
	@make fclean
	@make $(NAME)

.PHONY : all clean fclean re
