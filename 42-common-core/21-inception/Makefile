# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aternero <aternero@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026-04-16 10:00:00 by aternero          #+#    #+#              #
#    Updated: 2026-04-16 10:00:00 by aternero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Inluimos las variables del srcs/.env (si existe) y se las pasamos a Docker Compose
-include srcs/.env
export

# ============================================================================ #
# VARIABLES
# ============================================================================ #
NAME= inception
COMPOSE = srcs/docker-compose.yml
# Si CURRENT_USER no está definido en el srcs/.env, usamos el $USER del sistema por defecto
DATA_PATH = /home/$(shell echo $${USER})/data

# ============================================================================ #
# COLORES Y ESTILOS
# ============================================================================ #
DEF_COLOR = \033[0;39m
GRAY= \033[0;90m
RED= \033[0;91m
GREEN= \033[0;92m
YELLOW= \033[0;93m
BLUE= \033[0;94m
MAGENTA = \033[0;95m
CYAN= \033[0;96m
WHITE= \033[0;97m
BOLD= \033[1m

# ============================================================================ #
# TARGET POR DEFECTO
# ============================================================================ #
.DEFAULT_GOAL := help

# ============================================================================ #
# REGLAS PRINCIPALES
# ============================================================================ #
help:
	@echo "$(CYAN)╔══════════════════════════════════════════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(CYAN)║$(BOLD)$(WHITE)                          INCEPTION MANDATORY                                 $(DEF_COLOR)$(CYAN)║$(DEF_COLOR)"
	@echo "$(CYAN)║                  $(GRAY)Generador de Entorno e Infraestructura                      $(CYAN)║$(DEF_COLOR)"
	@echo "$(CYAN)╚══════════════════════════════════════════════════════════════════════════════╝$(DEF_COLOR)"
	@echo ""
	@echo "$(YELLOW)📚 USO DE LAS FLAGS:$(DEF_COLOR)"
	@echo ""
	@echo "  make $(GREEN)all$(DEF_COLOR)      🌟 Prepara todo: configura entorno, construye y levanta contenedores"
	@echo "  make $(GREEN)up$(DEF_COLOR)       🚀 Construye y levanta la infraestructura (el motor principal)"
	@echo ""
	@echo "  make $(RED)down$(DEF_COLOR)     🛑 Detiene la infraestructura y elimina los contenedores"
	@echo "  make $(GREEN)start$(DEF_COLOR)    ▶️  Inicia los contenedores previamente pausados/detenidos"
	@echo "  make $(YELLOW)stop$(DEF_COLOR)     ⏸️  Pausa temporalmente los contenedores activos"
	@echo "  make $(GRAY)status$(DEF_COLOR)   📊 Muestra los procesos y el estado de los contenedores"
	@echo ""
	@echo "  make $(CYAN)env$(DEF_COLOR)      📝 Fuerza la creación manual de un nuevo archivo srcs/.env"
	@echo ""
	@echo "  make $(RED)clean$(DEF_COLOR)    🧹 Borra imágenes, redes huérfanas y contenedores creados"
	@echo "  make $(RED)fclean$(DEF_COLOR)   💣 Purgado total (borra volúmenes /home/$(shell echo $${USER})/data y el srcs/.env)"
	@echo ""
	@echo "  make $(BLUE)re$(DEF_COLOR)       🔄 Reconstruye y levanta todo desde cero nuevamente"
	@echo ""

all:
		@if [ ! -f srcs/.env ]; then \
		./util_env.sh; \
	fi
	@$(MAKE) up

up: $(NAME)

$(NAME): setup
	@echo "$(CYAN)$(BOLD)🚀 Lanzando orquestación con Docker Compose...$(DEF_COLOR)"
	@docker compose -f $(COMPOSE) up -d --build
	@echo "$(GREEN)$(BOLD)✅ ¡Infraestructura de Inception levantada con éxito!$(DEF_COLOR)"

setup: env_file
	@echo "$(YELLOW)⚙️  Configurando directorios de persistencia para $(CURRENT_USER)...$(DEF_COLOR)"
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	@echo "$(GREEN)✓ Directorios montados correctamente.$(DEF_COLOR)"

# ============================================================================ #
# CREADOR INTERACTIVO (.env)
# ============================================================================ #
env_file:
	@if [ ! -f srcs/.env ]; then \
		echo "$(MAGENTA)✨ Archivo srcs/.env no encontrado. Lanzando mago de configuración...$(DEF_COLOR)"; \
		./util_env.sh; \
		echo "$(YELLOW)⚠️  ATENCIÓN: El archivo srcs/.env ha sido generado.$(DEF_COLOR)"; \
		echo "$(YELLOW)Por favor, ejecuta 'make up' de nuevo para cargar las variables correctamente.$(DEF_COLOR)"; \
		exit 1; \
	fi

env:
	@echo "$(MAGENTA)✨ Lanzando mago de configuración de entorno...$(DEF_COLOR)"
	@./util_env.sh
	@echo "$(YELLOW)⚠️  ATENCIÓN: El archivo srcs/.env ha sido generado o actualizado.$(DEF_COLOR)"
	@echo "$(YELLOW)Por favor, ejecuta 'make up' para aplicar los cambios.$(DEF_COLOR)"

# ============================================================================ #
# CONTROLES DEL CONTENEDOR 
# ============================================================================ #
down:
	@echo "$(RED)🛑 Deteniendo contenedores ($(NAME))...$(DEF_COLOR)"
	@docker compose -f $(COMPOSE) down

start:
	@echo "$(GREEN)▶️  Iniciando contenedores...$(DEF_COLOR)"
	@docker compose -f $(COMPOSE) start

stop:
	@echo "$(YELLOW)⏸️  Pausando contenedores...$(DEF_COLOR)"
	@docker compose -f $(COMPOSE) stop

status:
	@echo "$(CYAN)📊 Estado de los contenedores de $(NAME):$(DEF_COLOR)"
	@docker compose -f $(COMPOSE) ps

# ============================================================================ #
# LIMPIEZA
# ============================================================================ #
clean: down
	@echo "$(RED)$(BOLD)🧹 Limpiando imágenes y redes huérfanas...$(DEF_COLOR)"
	@docker compose -f $(COMPOSE) down -v --rmi all --remove-orphans

fclean: clean
	@echo "$(RED)$(BOLD)💣 Purgado agresivo (System Prune + Data Volumes)...$(DEF_COLOR)"
	@sudo rm -rf $(DATA_PATH)
	@rm -f srcs/.env
	@docker system prune -a --volumes -f
	@echo "$(GREEN)$(BOLD)✨ Sistema completamente limpio.$(DEF_COLOR)"

re: fclean all

.PHONY: all help up setup env_file env down start stop status clean fclean re test eval
