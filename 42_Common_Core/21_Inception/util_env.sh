#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    util_env.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aternero <aternero@student.42malaga.com>     +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026-04-16 10:00:00 by aternero          #+#    #+#              #
#    Updated: 2026-04-16 10:00:00 by aternero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
# PALETA DE COLORES
# ============================================================================ #
C_RED='\033[0;31m'
C_GREEN='\033[0;32m'
C_YELLOW='\033[1;33m'
C_BLUE='\033[0;34m'
C_MAGENTA='\033[0;35m'
C_CYAN='\033[0;36m'
C_WHITE='\033[1;37m'
C_BOLD='\033[1m'
C_RESET='\033[0m'

# ============================================================================ #
# FUNCIONES AUXILIARES
# ============================================================================ #
prompt_secure() {
    local text="$1"
    local default="$2"
    local pass=""
    
    echo -ne "${C_GREEN}${text} [${C_RED}***${C_GREEN}]: ${C_RESET}" >&2
    read -s pass </dev/tty
    echo "" >&2
    if [ -z "$pass" ]; then
        pass="$default"
    fi
    echo "$pass" | tr -d '\n\r'
}

# ============================================================================ #
# INICIO Y CABECERA
# ============================================================================ #
clear
echo -e "${C_CYAN}${C_BOLD}"
echo "╔══════════════════════════════════════════════════════════════════════════════╗"
echo "║                          INCEPTION MANDATORY                                 ║"
echo "║                  Generador de Entorno e Infraestructura                      ║"
echo "║                 ----------------------------------------                     ║"
echo "║                       Diseñado para Evaluación 42                            ║"
echo "╚══════════════════════════════════════════════════════════════════════════════╝"
echo -e "${C_RESET}"

if [ -f srcs/.env ]; then
    echo -e "${C_YELLOW}⚠️  Se ha detectado un archivo srcs/.env anterior.${C_RESET}"
    echo -e "${C_WHITE}Procediendo a eliminarlo para asegurar una instalación desde cero...${C_RESET}"
    rm -f srcs/.env
    echo -e "${C_GREEN}✓ Limpieza completada.${C_RESET}\n"
fi

# Determinamos el usuario nativo del sistema que está lanzando el script.
# Así evitamos errores de permisos, volúmenes fantasma o inyecciones con usuarios de otro evaluador.
CURRENT_USER="${USER:-$(whoami)}"
DATE_NOW=$(date '+%Y-%m-%d %H:%M:%S')

echo -e "${C_WHITE}Iniciando el proceso de configuración guiado.${C_RESET}"
echo -e "${C_YELLOW}(Pulsa INTRO en cada paso si deseas utilizar el valor sugerido entre corchetes)${C_RESET}\n"

# ---------------------------------------------------------------------------- #
# PASO 1: SISTEMA Y DOMINIO
# ---------------------------------------------------------------------------- #
echo -e "${C_BLUE}${C_BOLD}[1/4] 🌐 Configuración del Servidor Web${C_RESET}"
echo -e "${C_WHITE}──────────────────────────────────────────────────${C_RESET}"
echo -ne "${C_GREEN}Dominio local [${CURRENT_USER}.42.fr]: ${C_RESET}"
read IN_DOMAIN
DOMAIN_NAME=${IN_DOMAIN:-"${CURRENT_USER}.42.fr"}

echo -ne "${C_GREEN}Ruta certificado crt [/etc/nginx/ssl/${CURRENT_USER}.crt]: ${C_RESET}"
read IN_CRT
CERTS_CRT=${IN_CRT:-"/etc/nginx/ssl/${CURRENT_USER}.crt"}

echo -ne "${C_GREEN}Ruta clave privada key [/etc/nginx/ssl/${CURRENT_USER}.key]: ${C_RESET}"
read IN_KEY
CERTS_KEY=${IN_KEY:-"/etc/nginx/ssl/${CURRENT_USER}.key"}

echo -e "${C_GREEN}✓ NGINX y Dominio configurados.\n${C_RESET}"

# ---------------------------------------------------------------------------- #
# PASO 2: MariaDB
# ---------------------------------------------------------------------------- #
echo -e "${C_BLUE}${C_BOLD}[2/4] 🗄️  Configuración de Base de Datos${C_RESET}"
echo -e "${C_WHITE}──────────────────────────────────────────────────${C_RESET}"
echo -ne "${C_GREEN}Nombre BD [wordpress]: ${C_RESET}"
read IN_DB
MYSQL_DATABASE=${IN_DB:-"wordpress"}

echo -ne "${C_GREEN}Usuario BD [wpuser]: ${C_RESET}"
read IN_USER_DB
MYSQL_USER=${IN_USER_DB:-"wpuser"}

CLEAN_DB_PWD=$(prompt_secure "Contraseña de Usuario BD" "wpuserpwd")
CLEAN_ROOT_PWD=$(prompt_secure "Contraseña ROOT de MariaDB" "rootpwd")

echo -e "${C_GREEN}✓ MariaDB configurado.\n${C_RESET}"

# ---------------------------------------------------------------------------- #
# PASO 3: WORDPRESS
# ---------------------------------------------------------------------------- #
echo -e "${C_BLUE}${C_BOLD}[3/4] 📝 Configuración de CMS (WordPress)${C_RESET}"
echo -e "${C_WHITE}──────────────────────────────────────────────────${C_RESET}"
echo -ne "${C_GREEN}Nombre del Sitio [Inception Project - ${CURRENT_USER}]: ${C_RESET}"
read IN_TITLE
WP_TITLE=${IN_TITLE:-"Inception Project - ${CURRENT_USER}"}

echo -ne "${C_GREEN}Administrador [supervisor]: ${C_RESET}"
read IN_ADMIN
WP_ADMIN_USER=${IN_ADMIN:-"supervisor"}
# ¡NUNCA usar "admin"! como usuario, por seguridad y por el subject del proyecto.
CLEAN_WP_ADMIN_PWD=$(prompt_secure "Contraseña Administrador" "adminpwd")

echo -ne "${C_GREEN}Mail Administrador [${WP_ADMIN_USER}@${DOMAIN_NAME}]: ${C_RESET}"
read IN_A_EMAIL
WP_ADMIN_EMAIL=${IN_A_EMAIL:-"${WP_ADMIN_USER}@${DOMAIN_NAME}"}

echo -ne "${C_GREEN}Segundo Usuario [${CURRENT_USER}]: ${C_RESET}"
read IN_WP_USER
WP_USER=${IN_WP_USER:-"${CURRENT_USER}"}

CLEAN_WP_USER_PWD=$(prompt_secure "Contraseña de ${WP_USER}" "userpwd")

echo -ne "${C_GREEN}Mail de ${WP_USER} [${WP_USER}@${DOMAIN_NAME}]: ${C_RESET}"
read IN_U_EMAIL
WP_USER_EMAIL=${IN_U_EMAIL:-"${WP_USER}@${DOMAIN_NAME}"}

echo -e "${C_GREEN}✓ WordPress configurado.\n${C_RESET}"

# ---------------------------------------------------------------------------- #
# PASO 4: GENERACIÓN
# ---------------------------------------------------------------------------- #
echo -e "${C_BLUE}${C_BOLD}[4/4] ⚙️  Procesando e Inyectando Variables${C_RESET}"
echo -e "${C_WHITE}──────────────────────────────────────────────────${C_RESET}"

cat << ENV_EOF > srcs/.env
# **************************************************************************** #
#   ARCHIVO GENERADO AUTOMÁTICAMENTE - $DATE_NOW
#   Autor: $CURRENT_USER
# **************************************************************************** #

# [ SISTEMA ]
CURRENT_USER=${CURRENT_USER}

# [ NGINX ]
DOMAIN_NAME=${DOMAIN_NAME}
CERTS_CRT=${CERTS_CRT}
CERTS_KEY=${CERTS_KEY}

# [ MARIADB ]
MYSQL_DATABASE=${MYSQL_DATABASE}
MYSQL_USER=${MYSQL_USER}
MYSQL_PASSWORD=${CLEAN_DB_PWD}
MYSQL_ROOT_PASSWORD=${CLEAN_ROOT_PWD}

# [ WORDPRESS ]
WORDPRESS_DB_HOST=mariadb:3306
WORDPRESS_DB_NAME=${MYSQL_DATABASE}
WORDPRESS_DB_USER=${MYSQL_USER}
WORDPRESS_DB_PASSWORD=${CLEAN_DB_PWD}

WORDPRESS_URL=${DOMAIN_NAME}
WORDPRESS_TITLE="${WP_TITLE}"
WORDPRESS_ADMIN_USER=${WP_ADMIN_USER}
WORDPRESS_ADMIN_PASSWORD=${CLEAN_WP_ADMIN_PWD}
WORDPRESS_ADMIN_EMAIL=${WP_ADMIN_EMAIL}

WORDPRESS_USER=${WP_USER}
WORDPRESS_USER_PASSWORD=${CLEAN_WP_USER_PWD}
WORDPRESS_USER_EMAIL=${WP_USER_EMAIL}
ENV_EOF

echo -e "${C_GREEN}✓ Archivo srcs/.env generado exitosamente.\n${C_RESET}"

# ============================================================================ #
# RESUMEN FINAL Y ESTRUCTURA
# ============================================================================ #
echo -e "${C_CYAN}${C_BOLD}╔═════════════════════════════════════════════════════════════════════════╗${C_RESET}"
echo -e "${C_CYAN}${C_BOLD}║                       ✅ CONFIGURACIÓN COMPLETADA                       ║${C_RESET}"
echo -e "${C_CYAN}${C_BOLD}╚═════════════════════════════════════════════════════════════════════════╝${C_RESET}"
echo ""
echo -e "${C_WHITE}${C_BOLD}📁 Topología del Proyecto (Inception):${C_RESET}"
echo -e "${C_WHITE}├── ${C_CYAN}📄 srcs/.env${C_RESET}                      ${C_YELLOW}# Credenciales centralizadas${C_RESET}"
echo -e "${C_WHITE}├── ${C_CYAN}📋 Makefile${C_RESET}                  ${C_YELLOW}# Orquestación de comandos (\`make\`)${C_RESET}"
echo -e "${C_WHITE}├── ${C_MAGENTA}🗃️  /home/${CURRENT_USER}/data/${C_RESET} ${C_YELLOW}# Volúmenes Persistentes (Host)${C_RESET}"
echo -e "${C_WHITE}│   ├── ${C_MAGENTA}🗄️  mariadb/${C_RESET}             ${C_YELLOW}# Base de datos física${C_RESET}"
echo -e "${C_WHITE}│   └── ${C_MAGENTA}🌐 wordpress/${C_RESET}           ${C_YELLOW}# Archivos core de WP${C_RESET}"
echo -e "${C_WHITE}└── ${C_CYAN}📁 srcs/${C_RESET}                     ${C_YELLOW}# Código Fuente${C_RESET}"
echo -e "${C_WHITE}    ├── ${C_GREEN}⚙️  docker-compose.yml${C_RESET}    ${C_YELLOW}# Infraestructura Docker${C_RESET}"
echo -e "${C_WHITE}    └── ${C_GREEN}📦 requirements/${C_RESET}         ${C_YELLOW}# Contenedores aislados${C_RESET}"
echo -e "${C_WHITE}        ├── ${C_BLUE}🌐 nginx/${C_RESET}              ${C_YELLOW}# TLS inversa${C_RESET}"
echo -e "${C_WHITE}        ├── ${C_BLUE}🗄️  mariadb/${C_RESET}            ${C_YELLOW}# RDBMS${C_RESET}"
echo -e "${C_WHITE}        └── ${C_BLUE}📝 wordpress/${C_RESET}          ${C_YELLOW}# Intérprete PHP${C_RESET}"
echo ""
echo -e "${C_WHITE}${C_BOLD}🎯 Siguientes Pasos:${C_RESET}"
echo -e "${C_WHITE}  1. Lanza ${C_GREEN}make${C_RESET} en el directorio raíz de Inception.${C_RESET}"
echo -e "${C_WHITE}  2. Asegúrate de añadir ${C_CYAN}${DOMAIN_NAME}${C_RESET} a tu ${C_YELLOW}/etc/hosts${C_RESET}.${C_RESET}"
echo -e "${C_WHITE}  3. Accede desde tu navegador al puerto seguro 443.${C_RESET}"
echo -e "\n${C_GREEN}${C_BOLD}¡Preparado para la evaluación! 🚀${C_RESET}\n"

