
NAME = push_swap

CC = gcc 

CFLAGS = -I srcs/includes/ -I libft/includes/

LIBFT = -L libft -lft

SRCS = func_order list_funcs lst_utils main operations sorting utils utils2 op_norm

SRC = $(addsuffix .c, $(addprefix srcs/, $(SRCS)))

OBJ = $(SRC:c=o) 

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make bonus -C libft/
	@echo "\033[0;32mCompiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) 
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating push_swap objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@



clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re test
