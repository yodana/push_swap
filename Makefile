NAME = checker

SRC = main_checker.c init.c moves.c 

HEADER = checker.h

BIN_FOLDER = ./bin/

YELLOW = \033[0;33m

GREEN = \033[0;32m

END_COLOR = \033[0m

OBJ = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bin:
	@mkdir bin

$(NAME): bin $(OBJ)
		@make -C libft
		@gcc -o $(NAME) $(LIB) $(OBJ) -g
		@printf "$(GREEN)Compilation finish $(END_COLOR)"

$(BIN_FOLDER)%.o :%.c
	@gcc $< -c -I $(HEADER) -o $@ -Wall -Wextra -Werror -g

clean :
	@make clean -C libft
	@rm -rf $(BIN_FOLDER)
	@printf "$(GREEN)Clean done $(END_COLOR)\n"

fclean : clean 
	@make fclean -C libft
	@rm -rf $(NAME)
	@printf "$(GREEN)Fclean done $(END_COLOR)\n"

re : fclean all

.PHONY : all clean fclean re
