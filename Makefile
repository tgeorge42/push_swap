NAME	= push_swap
CC	= cc
FLAG	= -Wall -Wextra -Werror -g3
LIBFT_PATH	= libft/
LIBFT_FILE	= libft.a
LIBFT_LIB	= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
FTPRINTF_PATH	= ft_printf/
FTPRINTF_FILE	= libftprintf.a
FTPRINTF_LIB	= $(addprefix $(FTPRINTF_PATH), $(FTPRINTF_FILE))
SRC_DIR	= ./sources/
INC_DIR	= ./includes/
SRC	= $(addprefix $(SRC_DIR),$(C_FILE))
OBJ	= $(SRC:.c=.o)
C_FILE	= check_pile.c \
					ft_instructions.c \
					push_swap.c \
					ft_algo.c \
					algo_trois.c \
					algo_cinq.c \
					ft_algo_cout1.c \
					ft_algo_cout2.c \
					ft_algo_cout3.c \
					pushandswap.c \
					rotates.c \
					position.c

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@echo "\033[0;33m\nCompiling $(LIBFT_PATH)\n"
	@make -sC $(LIBFT_PATH)
	@echo "\033[1;32mLibft created\n"

printf:
	@echo "\033[0;33m\nCompiling $(FTPRINTF_PATH)\n"
	@make -sC $(FTPRINTF_PATH)
	@echo "\033[1;32mft_printf created\n"

$(NAME): lib printf $(OBJ)
	@echo "\033[0;33m\nCompiling $(NAME)\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBFT_LIB) $(FTPRINTF_LIB) -o $(NAME)
	@echo "\033[1;32m$(NAME) created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting Obj file in $(FTPRINTF_PATH)...\n"
	@make clean -sC $(FTPRINTF_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting Push_Swap object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting Push_Swap executable..."
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_PATH)
	@make fclean -sC $(FTPRINTF_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re