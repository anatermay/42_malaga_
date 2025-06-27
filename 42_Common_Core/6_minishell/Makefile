# Variables
NAME			=	minishell
CFLAGS			=	-Wall -Wextra -Werror
FSANITIZE		=	-fsanitize=address
NOPIE			=	-no-pie
RL				=	-lreadline
OBJ_DIR			=	obj
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a

SRCS			=	$(shell find src -type f -name "*.c")
OBJS			=	$(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# Colors
BLUE			=	\033[0;34m
GREEN			=	\033[0;32m
RED				=	\033[0;31m
NC				=	\033[0m

LEAKS_COMPILER	=	@cc -fsanitize=address -g $(OBJS) $(LIBFT) -o $(NAME) $(RL) $(NOPIE)


# Rules
all: $(NAME)

.PHONY: libft

libft:
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT): libft

$(NAME): clear $(LIBFT) $(OBJS)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -g -o $(NAME) $(RL) $(NOPIE)
	@echo "$(GREEN)$(NAME) created$(NC)"
#Removed SANIT.

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo -n "$(BLUE)"
	cc $(CFLAGS) -c $< -o $@
	@echo -n "$(NC)"

clean:
	@echo -n "$(RED)"
	rm -rf obj
	@echo -n "$(NC)"

fclean: clean
	@echo -n "$(RED)"
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo -n "$(NC)"

re: fclean all

clear:
	@clear

test: clear $(LIBFT) $(NAME)
	./$(NAME)

tester: clear $(LIBFT) $(NAME)
# $(LEAKS_COMPILER)
	cd minishell_tester && bash -c "./tester | sed 's/\x1b\[[0-9;]*m//g' | tee errors.txt"
	@cd minishell_tester && sed -i '/Test.*✅/d' errors.txt
	@echo "$(GREEN)Errors results saved to minishell_tester/errors.txt$(NC)"

fast: clear $(LIBFT) $(NAME)
	cd minishell_tester && bash -c "./tester -full-cpu | sed 's/\x1b\[[0-9;]*m//g' | tee errors.txt"
	@cd minishell_tester && sed -i '/Test.*✅/d' errors.txt
	@echo "$(GREEN)Fast parallel testing completed - Results saved to minishell_tester/errors.txt$(NC)"

show: $(LIBFT) $(NAME)

stop: clear $(LIBFT) $(NAME)
	cd minishell_tester && bash  ./tester -stop

warn: clear $(LIBFT) $(NAME)
	cd minishell_tester && bash  ./tester -warn
	
leaks: clear $(LIBFT) $(NAME)
	cd minishell_tester && bash  ./tester -valgrind
	@echo "$(GREEN)Memory leak logs saved to minishell_tester/errors.logs.txt$(NC)"

fast-leaks: clear $(LIBFT) $(NAME)
	cd minishell_tester && bash  ./tester -stop -valgrind -full-cpu
	@echo "$(GREEN)Fast parallel memory leak testing completed - Logs saved to minishell_tester/errors.logs.txt$(NC)"

show: clear $(LIBFT) $(NAME)
# $(LEAKS_COMPILER)
	cd minishell_tester && bash -c ./tester
	
debug: $(LIBFT) $(OBJS)
	cc $(CFLAGS) -g $(OBJS) $(LIBFT) -o $(NAME) $(RL) $(NOPIE)
	gdb ./$(NAME)

sanityzer: clear $(LIBFT) $(OBJS)
	$(LEAKS_COMPILER)

valdgrind: $(LIBFT) $(OBJS) $(NAME)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=readline.supp ./$(NAME)

grademe: clear $(NAME)
	cd 42_minishell_tester && ./grademe.sh

show_leaks:
	@if [ -f minishell_tester/errors.logs.txt ]; then \
		echo "$(BLUE)Memory leak logs:$(NC)"; \
		cat minishell_tester/errors.logs.txt; \
	else \
		echo "$(RED)No memory leak logs found. Run 'make leaks' first.$(NC)"; \
	fi


.PHONY: all clean fclean re clear libft tester_stop show_leaks