
NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -I libft/includes/

MAIN = push_swap

LIBFT = -L libft -lft

ERROR = error_handling

INITIALIZE = initialize_stack

INSTRUCTIONS = instructions_call instructions

LST = lst_functions

SORTING = sorting_utils sorting_two_args sorting_three_args sorting_four_args \
		sorting_five_args sorting_big_args

SRC = $(addsuffix .c, $(addprefix sources/error/, $(ERROR))) \
	  $(addsuffix .c, $(addprefix sources/initialize/, $(INITIALIZE))) \
	  $(addsuffix .c, $(addprefix sources/instructions/, $(INSTRUCTIONS))) \
	  $(addsuffix .c, $(addprefix sources/lst/, $(LST))) \
	  $(addsuffix .c, $(addprefix sources/sorting/, $(SORTING))) \
	  $(addsuffix .c, $(addprefix , $(MAIN)))

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -C libft/
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

.PHONY: clean fclean re test norm
