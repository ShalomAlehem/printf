NAME =	libftprintf.a

LIBFT =	./libft/libft.a

LIST =	ft_printf.c \
		src/ft_char_str.c \
		src/ft_number.c \
		src/ft_hexa.c \


OBJ = $(patsubst %.c,%.o,$(LIST))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all :	$(NAME)

$(NAME) : $(OBJ)
	$(MAKE) all -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $?

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
