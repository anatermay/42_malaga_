# ** ............................................................. ** #
# **                        M A K E F I L E                        ** #
# **                         ~ AnaTerMay ~                         ** #
# **                           @aternero                           ** #
# ** ............................................................. ** #


# ** VARIABLES ** .................................................. //
NAME			=	philo
CC				=	cc
FLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -rf
SANITIZER		=	$(CC) $(FLAGS) -fsanitize=address
HELGRIND		=	valgrind --tool=helgrind -s
DRD				=	valgrind --tool=drd -s
FT_PRINTF_DIR	=	ft_printf
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a

SRC				=	0_main.c \
					1_argument_parsing.c \
					2_init_table.c \
					3_init_philos.c \
					4_threads.c \
					5_philosophers_routine.c \
					6_guard.c \
					l_atoi.c \
					l_atol.c \
					l_isdigit.c \
					l_isspace.c \
					l_strcmp.c \
					u_destroyandexit.c \
					u_isdeath.c \
					u_isfinished.c \
					u_printstatus.c \
					u_time.c

OBJ				=	$(SRC:.c=.o)

# ** RULES ** ...................................................... //

all: $(NAME)
	@clear
	@echo "OK"

%.o:%.c
	@clear
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "OK"

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR) > /dev/null
	@clear
	@echo "FT_PRINTF OK"

$(NAME): $(FT_PRINTF) $(OBJ)
	@clear
	@$(CC) $(FLAGS) $(OBJ) -L $(FT_PRINTF_DIR) -lftprintf -o $@
	@echo "OK"

clean:
	@clear
	@$(RM) $(OBJ)
	@make -C $(FT_PRINTF_DIR) clean > /dev/null
	@clear
	@echo "OK"

fclean: clean
	@clear
	@$(RM) $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean
	@clear
	@echo "OK"

re: fclean all
	@clear
	@echo "OK"

gdb:
	@clear
	@gdb ./$(NAME)

sanitizer:
	@clear
	@$(SANITIZER) -c $(OBJ) -o $(SRC)

test: all
	@clear
	@echo "FIRST_TEST"
	@echo "\n" >> test.txt
	@./$(NAME) 5 800 200 200 5 > test.txt
	@echo "\n" >> test.txt
	@echo "..............................................." >> test.txt
	@echo "\n" >> test.txt
	@echo "WITH VALGRIND"
	@echo "\n" >> test.txt
	@valgrind ./$(NAME) 5 800 200 200 5 >> test.txt

# ** PHONY ** ...................................................... //

.PHONY: all clean fclean re gdb sanitizer test

#test:
#	@make re && valgrind --tool=helgrind -s ./philo 5 800 200 200 7 && make re && valgrind --tool=drd -s ./philo 5 800 200 200 7