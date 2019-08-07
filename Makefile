NAME1 		= checker
NAME2 		= push_swap

SRC1 		= main_checker.c tools/init.c moves/moves.c tools/display.c moves/moves_s.c moves/moves_p.c \
		moves/moves_r.c moves/moves_rr.c tools/check.c tools/free.c
SRC2 		= main_push.c tools/check.c algo/algo.c tools/init.c moves/moves_p.c  tools/display.c moves/moves_r.c \
	moves/moves_s.c tools/tools.c moves/moves_rr.c tools/free.c algo/algo_end.c moves/moves.c 

HEADER 		= checker.h
HEADER1 	= push_swap.h

SRC_FOLDER	=	srcs
BIN_FOLDER	=	bin
OBJ_FOLDER	=	$(BIN_FOLDER)/obj

OBJ1 		= $(addprefix $(OBJ_FOLDER)/,$(SRC1:.c=.o))
OBJ2		= $(addprefix $(OBJ_FOLDER)/,$(SRC2:.c=.o))
SRCLOCA		= $(shell find $(SRC_FOLDER) -type d)
OBJLOCA		= $(subst $(SRC_FOLDER), $(OBJ_FOLDER), $(SRCLOCA))

YELLOW 		= \033[0;33m
GREEN		= \033[0;32m
END_COLOR	= \033[0m

LIBFT		=	libft/libft.a
LIB 		= 	libft

FLAGS		=	-Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(LIBFT)
		@gcc -o $(NAME1) $(LIBFT) $(OBJ1) test_affichage.c -I SDL2/include -L SDL2/lib -l SDL2-2.0.0 -g
		@printf "$(GREEN)\\nCompilation CHECKER finish \\n$(END_COLOR)"

$(NAME2): $(OBJ2)
		@gcc -o $(NAME2) $(LIBFT) $(OBJ2)  test_affichage.c -I SDL2/include -L SDL2/lib -l SDL2-2.0.0  -g
		@printf "$(GREEN)Compilation PUSH SWAP finish \\n$(END_COLOR)"

$(OBJ_FOLDER)/%.o:	$(SRC_FOLDER)/%.c | $(OBJ_FOLDER)
	@gcc $< -c -o $@ $(FLAGS) -g

$(LIBFT):
	@ make -C $(LIB) --no-print-directory

$(OBJ_FOLDER):
	@mkdir -p $(OBJLOCA)

$(BIN_FOLDER):
	@ mkdir -p $(BIN_FOLDER)

clean :
	@make clean -C libft
	@rm -rf $(BIN_FOLDER)
	@printf "$(GREEN)Clean done $(END_COLOR)\n"

fclean : clean 
	@make fclean -C libft
	@rm -rf $(NAME1) $(NAME2)
	@printf "$(GREEN)Fclean done $(END_COLOR)\n"

re : fclean all

.PHONY : all clean fclean re
