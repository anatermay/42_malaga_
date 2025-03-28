# **_ NAME _**
NAME	= so_long

# **_ ABBREVIATION _**
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# **_ SOURCES AND RESOURCES _**
MLX42			= ./MLX42

# **_ DIRECTORIES _**
LIBFT_DIR	= ./resources/LIBFT
MLX42_DIR	= ./MLX42

# **_ FILES _**
SOURCES_FILES	= sources/so_long.c \
					sources/game/game_initialize.c \
					sources/graphics/mlx_init.c \
					sources/graphics/novel_graphics_perspective.c \
					sources/resources/novel_editorial.c \
					sources/resources/novel_foot_notes.c \
					sources/worldbuilding/worldbuilding_content_validator.c \
					sources/worldbuilding/worldbuilding_init.c \
					sources/worldbuilding/worldbuilding_validator.c \

# **_ OBJECTS _**
OBJECTS			= $(SOURCES_FILES:.c=.o)

# **_ DEPENDENCIES _**

# **_ COMPILATION RULES _**

# _BONUS_

# **_ ALL _**
all: $(NAME)

$(NAME): $(OBJECTS) 
	@${CC} ${CFLAGS} -o ${NAME} ${OBJECTS} 
	@chmod +x $(NAME)
	@echo "OK"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

# **_ CLEAN _**
clean:
	@rm -f $(OBJECTS) 

# **_ FCLEAN _**
fclean: clean
	@rm -f $(NAME) 

# **_ RE _**
re: fclean all

# **_ PHONY _**
.PHONY: all bonus clean fclean re

# ** ______________________________________________________________________**

echo"       .--.                   .---."
echo"   .---|__|           .-.     |~~~|"
echo".--|===|--|_          |_|     |~~~|--."
echo"|  |===|  |'\     .---!~|  .--|   |--|"
echo"|%%|   |  |.'\    |===| |--|%%|   |  |"
echo"|%%|   |  |\.'\   |   | |__|  |   |  |"
echo"|  |   |  | \  \  |===| |==|  |   |  |      |\      _,,,---,,_"
echo"|  |   |__|  \.'\ |   |_|__|  |~~~|__|ZZZzz /,`.-'`'    -.  ;-;;,_"
echo"|  |===|--|   \.'\|===|~|--|%%|~~~|--|     |,4-  ) )-,_. ,\ (  `'-'"
echo"^--^---'--^    `-'`---^-^--^--^---'--'    '---''(_/--'  `-'\_)  " 

# ** ______________________________________________________________________**
