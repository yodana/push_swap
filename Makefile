NAME1 = checker

NAME2 = push_swap

SRC1 = main_checker.c init.c moves.c display.c moves_s.c moves_p.c \
		moves_r.c moves_rr.c check.c free.c

SRC2 = main_push.c check.c algo.c init.c moves_p.c  display.c moves_r.c \
	moves_s.c tools.c moves_rr.c free.c algo_end.c

SCRDIR = srcs


HEADER = checker.h

HEADER1 = push_swap.h

BUILDDIR	:=	bin
OBJDIR		:=	$(BUILDDIR)/obj

#BIN_FOLDER = ./bin/

#BIN_FOLDER1 = ./bin/

YELLOW = \033[0;33m

GREEN = \033[0;32m

END_COLOR = \033[0m

OBJ1 = $(addprefix $(OBJDIR)/,$(SRC1:.c=.o))

#OBJ2 = $(addprefix $(BIN_FOLDER1),$(SRC2:.c=.o))
SRCLOCA	= $(shell find $(SRCDIR) -type d)
OBJLOCA	=	$(subst $(SRCDIR), $(OBJDIR), $(SRCLOCA))

LIBFT		=	libft.a
LIB = libft/libft.a 

FLAGS = -Wall -Wextra -Werror

all: $(NAME1)# $(NAME2)

#bin:
#	@mkdir bin

$(NAME1): $(OBJ1) $(LIBFT)
		@gcc -o $(NAME1) $(OBJ1) -g
		@printf "$(GREEN)\\nCompilation CHECKER finish \\n$(END_COLOR)"

#$(NAME2): $(OBJ2)
#		@gcc -o $(NAME2) $(LIB) $(OBJ2) -g
#		@printf "$(GREEN)Compilation PUSH SWAP finish $(END_COLOR)"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@gcc $< -c -I $(HEADER) -o $@ -Wall -Wextra -Werror -g

#$(BIN_FOLDER1)%.o :%.c
#	@gcc $< -c -I $(HEADER1) -o $@ -Wall -Wextra -Werror -g

$(LIB):
	@ make -C $(LIB) --no-print-directory

$(OBJDIR):
	mkdir -p $(OBJLOCA)

$(BUILDDIR):
	@ mkdir -p $(BUILDDIR)

clean :
	@make clean -C libft
	@rm -rf $(BUILDDIR)
	@printf "$(GREEN)Clean done $(END_COLOR)\n"

fclean : clean 
	@make fclean -C libft
	@rm -rf $(NAME1) $(NAME2)
	@printf "$(GREEN)Fclean done $(END_COLOR)\n"

re : fclean all

.PHONY : all clean fclean re
