# minishell

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C-brightgreen)
![Rango](https://img.shields.io/badge/Rango-03-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-100%2F100-success)

## 📋 Descripción del Proyecto

`minishell` es una implementación personalizada de shell Unix construida desde cero en C. Este proyecto forma parte del currículo del Common Core de 42 (Rango 03) y se enfoca en comprender el comportamiento del shell, gestión de procesos, manejo de señales y análisis de línea de comandos.

## 🎯 Objetivos

- Crear un shell Unix funcional similar a bash
- Implementar análisis y ejecución de comandos
- Manejar pipes, redirecciones y comandos built-in
- Gestionar procesos y manejo de señales
- Soportar variables de entorno y expansiones
- Implementar manejo adecuado de errores y gestión de memoria
- Seguir los estándares de codificación de 42 School (Norminette)

## 🔧 Características Soportadas

### Características Principales del Shell
| Característica | Descripción | Estado |
|----------------|-------------|--------|
| **Ejecución de Comandos** | Ejecutar comandos del sistema con resolución de PATH | ✅ |
| **Comandos Built-in** | `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit` | ✅ |
| **Pipes** | Encadenar comandos con el operador pipe `\|` | ✅ |
| **Redirecciones** | Redirección de entrada/salida `<`, `>`, `>>` | ✅ |
| **Heredoc** | Implementación de here document `<<` | ✅ |
| **Variables de Entorno** | Expansión y gestión de variables | ✅ |
| **Manejo de Señales** | Manejo adecuado de `Ctrl+C`, `Ctrl+D`, `Ctrl+\` | ✅ |
| **Manejo de Comillas** | Análisis de comillas simples y dobles | ✅ |

### Comandos Built-in

| Comando | Descripción | Sintaxis |
|---------|-------------|----------|
| `echo` | Mostrar texto con opción `-n` | `echo [-n] [cadena...]` |
| `cd` | Cambiar directorio con rutas relativas/absolutas | `cd [directorio]` |
| `pwd` | Imprimir directorio de trabajo | `pwd` |
| `export` | Establecer variables de entorno | `export [nombre[=valor]...]` |
| `unset` | Eliminar variables de entorno | `unset [nombre...]` |
| `env` | Mostrar variables de entorno | `env` |
| `exit` | Salir del shell con código de estado opcional | `exit [estado]` |

## 📁 Estructura del Proyecto

```
6_minishell/
├── src/
│   ├── minishell.h                  # Archivo de cabecera principal
│   ├── main.c                       # Bucle principal del programa
│   ├── main_utils.c                 # Utilidades principales
│   ├── buildt-ins/                  # Comandos built-in
│   │   ├── cd.c                     # Implementación del comando cd
│   │   ├── echo.c                   # Implementación del comando echo
│   │   ├── env.c                    # Implementación del comando env
│   │   ├── exit.c                   # Implementación del comando exit
│   │   ├── export.c                 # Implementación del comando export
│   │   ├── pwd.c                    # Implementación del comando pwd
│   │   └── unset.c                  # Implementación del comando unset
│   ├── parser/                      # Análisis y expansión de comandos
│   │   ├── 0_parser_and_expander/   # Lógica principal de análisis
│   │   ├── 1_init_shell_line_t/     # Inicialización de estructura de comandos
│   │   ├── 2_redirect/              # Análisis de redirecciones
│   │   ├── 3_parsing/               # Análisis de línea de comandos
│   │   ├── 4_expand/                # Expansión de variables
│   │   └── utils/                   # Utilidades del parser
│   ├── executer/                    # Ejecución de comandos
│   │   ├── executer.c               # Lógica principal de ejecución
│   │   ├── pipeline.c               # Gestión de pipelines
│   │   ├── child_exec.c             # Ejecución de procesos hijo
│   │   ├── heredoc.c                # Implementación de here document
│   │   └── builtins_handler.c       # Manejo de comandos built-in
│   └── utils/                       # Utilidades generales
├── libft/                           # Biblioteca C personalizada
├── Makefile                         # Configuración de compilación
└── README_es.md                     # Este archivo
```

## 🚀 Uso

### Prerrequisitos

- Linux o macOS
- Biblioteca GNU Readline
- Compilador GCC
- Utilidad Make

### Instalación

```bash
# Clonar el repositorio
git clone [repositorio]
cd minishell

# Instalar biblioteca readline (Ubuntu/Debian)
sudo apt-get install libreadline-dev

# Instalar biblioteca readline (macOS)
brew install readline

# Compilar el proyecto
make
```

### Ejecutar el Shell

```bash
# Iniciar el shell
./minishell

# Deberías ver un prompt similar a:
minishell$ 
```

### Ejemplos de Uso Básico

```bash
# Ejecutar comandos simples
minishell$ ls -la
minishell$ pwd
minishell$ echo "¡Hola, Mundo!"

# Usar pipes
minishell$ ls | grep .c | wc -l

# Usar redirecciones
minishell$ echo "Hola" > salida.txt
minishell$ cat < entrada.txt
minishell$ ls >> log.txt

# Usar heredoc
minishell$ cat << EOF
Esto es un heredoc
Se soportan múltiples líneas
EOF

# Variables de entorno
minishell$ export MI_VAR="Hola"
minishell$ echo $MI_VAR
minishell$ env | grep MI_VAR

# Comandos built-in
minishell$ cd /tmp
minishell$ pwd
minishell$ exit 0
```

## 💡 Características Principales

### Análisis de Comandos
- **Análisis Léxico**: Tokeniza la entrada en comandos, argumentos, operadores
- **Manejo de Comillas**: Maneja adecuadamente comillas simples (`'`) y dobles (`"`)
- **Expansión de Variables**: Expande variables de entorno (`$VAR`, `$?`)
- **Soporte de Comodines**: Expansión básica de nombres de archivo (dependiente de implementación)

### Gestión de Procesos
- **Modelo Fork/Exec**: Crea procesos hijo para ejecución de comandos
- **Implementación de Pipeline**: Conecta comandos a través de pipes
- **Manejo de Señales**: Gestiona interrupciones y señales de control de procesos
- **Seguimiento de Estado de Salida**: Mantiene estados de salida de comandos

### Gestión de Memoria
- **Asignación Dinámica**: Uso eficiente de memoria para estructuras de comandos
- **Prevención de Fugas**: Limpieza adecuada de todos los recursos asignados
- **Manejo de Errores**: Manejo elegante de fallos de asignación

### Características Avanzadas
- **Here Documents**: Redirección de entrada multilínea
- **Gestión de Entorno**: Soporte completo de variables de entorno
- **Resolución de Rutas**: Búsqueda automática de comandos en PATH
- **Reporte de Errores**: Mensajes de error exhaustivos y códigos de estado

## 🧪 Pruebas

El shell maneja varios escenarios complejos:

### Ejecución de Comandos
```bash
# Pipelines complejos
ls -la | grep "^d" | sort | head -5

# Múltiples redirecciones
echo "test" > archivo1 && cat archivo1 >> archivo2

# Expansión de variables de entorno
export PATH="/bin:/usr/bin" && echo $PATH
```

### Manejo de Errores
```bash
# Comandos inválidos
comando_inexistente

# Errores de permisos
./sin_permisos_de_ejecucion

# Errores de sintaxis
ls | | grep test
```

### Gestión de Señales
- **Ctrl+C**: Interrumpe el comando actual, vuelve al prompt
- **Ctrl+D**: Envía EOF, sale del shell elegantemente
- **Ctrl+\\**: Manejo de señal quit

## 🎨 Detalles de Implementación

### Bucle Principal del Shell
```c
int main(int argc, char **argv, char **envs)
{
    t_data *d;
    
    d = init_data(envs);
    setup_signals();
    
    while (42)
    {
        d->line = readline(d->prompt);
        if (!d->line)
            break;
            
        parser_and_commander(d);
        process_input(d);
    }
    
    cleanup_data(d);
    return (d->exit_status);
}
```

### Estructura de Comandos
```c
typedef struct s_shell_line
{
    char                *line;
    char                **cmd;
    t_redirect          *redir;
    int                 empty_quoted_var;
    struct s_shell_line *next;
} t_shell_line;
```

### Gestión de Pipelines
```c
typedef struct s_pipeline
{
    int         pipefd[2];
    int         prev_pipe_read_end;
    int         current_pipe_write_end;
    int         is_last;
    pid_t       *pids;
    int         cmd_count;
    int         cmd_index;
} t_pipeline;
```

## 🚨 Manejo de Errores

El shell proporciona manejo exhaustivo de errores:
- **Errores de Sintaxis**: Uso inválido de pipes, comillas no coincidentes
- **Errores de Comandos**: Comando no encontrado, permiso denegado
- **Errores del Sistema**: Fallos de fork, errores de pipe
- **Errores de Memoria**: Fallos de asignación, limpieza de recursos

## 📈 Rendimiento

- **Análisis Eficiente**: Algoritmos optimizados de tokenización y análisis
- **Gestión de Memoria**: Huella de memoria mínima con limpieza adecuada
- **Control de Procesos**: Implementación eficiente de fork/exec
- **Manejo de Señales**: Procesamiento de señales de baja latencia

## 🔗 Enlaces

- **Autora**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repositorio**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 📊 Progreso del Common Core de 42

Este proyecto forma parte de mi recorrido por el currículo del Common Core de 42:

- **Rango 00**: ✅ libft
- **Rango 01**: ✅ ft_printf, born2beroot, get_next_line
- **Rango 02**: ✅ push_swap, examrank02, so_long, minitalk
- **Rango 03**: ✅ philosophers, examrank03, minishell
- **Rango 04**: 🔄 netpractice (completado), examrank04, cub3d, CPP 00-04

## 🏆 Logro

**Puntuación Final**: 100/100 ✨

---

*Este proyecto fue completado como parte del currículo de 42 School en 42 Málaga.*
