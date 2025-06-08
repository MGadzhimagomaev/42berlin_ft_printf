NAME		=	libftprintf.a
INCLUDE		=	include
LIBFT		=	libft
SRC_DIR		=	src/

SRC_FILES	=	ft_printf ft_print_char ft_print_str ft_print_num \
				ft_print_hex ft_print_unsigned_num ft_print_ptr

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@

all:		$(NAME)

clean:
	rm -rf	$(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	rm -rf	$(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re