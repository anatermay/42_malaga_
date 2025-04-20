NAME 			= so_long
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g
MLX42 			= ./MLX42
LIBFT 			= ./resources/libft
FT_PRINTF		= ./resources/ft_printf
INCLUDES 		= -I$(MLX42)/include -I$(LIBFT)/include -I$(FT_PRINTF) -Iincludes
LIBS 			= -L$(MLX42)/lib -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf

SOURCES_DIRECTORY 		= ./sources
OBJECTS_DIRECTORY 		= ./objects

SOURCES_FILES 		= 0_the_threshold.c \
					1_the_first_guardian.c \
					2_the_world_architect.c \
					3_the_second_guardian.c \
					4_the_maze_explorer.c \
					5_the_windows_engineer.c \
					6_inns_receptionist.c \
					7_detective.c \
					8_leonardo_da_vinci.c \
					9_telesketch.c \
					10_keyboard.c \
					appendix_cleaning_team.c \
					appendix_map.c \

OBJECTS 			= $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES_FILES:.c=.o))

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@mkdir -p $(OBJECTS_DIRECTORY)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)
	@echo "SO_LONG: MAKE\t\t\t\t. . . OK"

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT) > /dev/null
	@echo "SO_LONG: LIBFT\t\t\t\t. . . OK"

$(FT_PRINTF)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF) > /dev/null
	@echo "SO_LONG: FT_PRINTF\t\t\t. . . OK"

all: $(NAME)
	@echo "SO_LONG: MAKE ALL\t\t\t. . . OK"

clean:
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@echo "SO_LONG: MAKE CLEAN\t\t\t. . . OK"

fclean:
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@$(MAKE) -C $(LIBFT) fclean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) fclean > /dev/null
	@$(RM) $(NAME)
	@$(RM) sources/*.o
	@echo "SO_LONG: MAKE FCLEAN\t\t\t. . . OK"

re: fclean all
	@echo "SO_LONG: MAKE RE\t\t\t. . . OK"

.PHONY: all clean fclean re

# *** THE END ________________________________________________________________________*** #
