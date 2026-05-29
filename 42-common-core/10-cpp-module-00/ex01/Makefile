# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 18:54:41 by aternero          #+#    #+#              #
#    Updated: 2025/11/13 19:23:24 by aternero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ** ***.***.***   ...   >>   ...   VARIABLES   ...   <<   ...   ***.***.*** **
CXX			= c++
NAME		= phonebook
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SOURCES		= PhoneBook.cpp
OBJECTS		= $(SOURCES:.cpp=.o)
RM			= rm -f

# ** ***.***.***   ...   >>   ...   DEPENDENCIES   ...   <<   ...   ***.***.*** **

%.o:%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "LINK: OK.\n\tFichero ejecutable creado: $(NAME) 📄"

# ** ***.***.***   ...   >>   ...   RULES   ...   <<   ...   ***.***.*** **

# ** Regla ALL

all: $(NAME)
	@echo "MAKE: OK.\n\tEjecutable creado: $(NAME) ✅"

# ** Regla CLEAN

clean:
	@$(RM) $(OBJECTS)
	@echo "MAKE CLEAN: OK.\n\tFicheros $(OBJECTS) eliminados. 🧹"

# ** Regla FCLEAN

fclean: clean
	@$(RM) $(NAME)
	@echo "MAKE FCLEAN: OK.\n\tEjecutable $(NAME) eliminado. 🧼"

# ** Regla RE

re: fclean all
	@echo "MAKE RE: OK.\n\tProyecto recompilado. 🔄"

# ** Regla .PHONY

.PHONY: all clean fclean re

# ** ***.***.***   ...   >>   ...   END   ...   <<   ...   ***.***.*** **