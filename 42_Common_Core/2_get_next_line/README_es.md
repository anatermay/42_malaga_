# get_next_line

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C-brightgreen)
![Rango](https://img.shields.io/badge/Rango-01-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-100%2F100-success)

## 📋 Descripción del Proyecto

`get_next_line` es una función en C que lee un archivo de texto línea por línea, independientemente del tamaño del buffer. Este proyecto forma parte del currículo del Common Core de 42 (Rango 01) y se enfoca en manipulación de archivos, variables estáticas y asignación dinámica de memoria.

## 🎯 Objetivos

- Leer un archivo línea por línea usando un tamaño de buffer configurable
- Manejar múltiples descriptores de archivo simultáneamente (bonus)
- Gestionar la memoria eficientemente para evitar fugas
- Usar variables estáticas para mantener el estado entre llamadas a funciones
- Trabajar con descriptores de archivo y llamadas al sistema
- Seguir los estándares de codificación de 42 School (Norminette)

## 🔧 Prototipo de la Función

```c
char *get_next_line(int fd);
```

### Parámetros
- `fd`: Descriptor de archivo desde el cual leer

### Valor de Retorno
- Retorna la siguiente línea del archivo (incluyendo el carácter de nueva línea `\n`)
- Retorna `NULL` cuando el archivo se ha leído completamente o ocurre un error

## 📁 Estructura del Proyecto

```
2_get_next_line/
├── get_next_line.c         # Implementación de la función principal
├── get_next_line.h         # Archivo de cabecera con prototipos
├── get_next_line_utils.c   # Funciones de utilidad
├── get_next_line_bonus.c   # Bonus: múltiples descriptores de archivo
├── get_next_line_bonus.h   # Cabecera para la parte bonus
├── get_next_line_utils_bonus.c # Funciones de utilidad para bonus
└── README_es.md           # Este archivo
```

## 🚀 Uso

### Compilación

```bash
# Compilar con tamaño de buffer personalizado
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c

# Compilar versión bonus
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Uso Básico

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("archivo.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

### Bonus: Múltiples Descriptores de Archivo

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line1, *line2;
    
    fd1 = open("archivo1.txt", O_RDONLY);
    fd2 = open("archivo2.txt", O_RDONLY);
    
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    
    printf("Archivo 1: %s", line1);
    printf("Archivo 2: %s", line2);
    
    free(line1);
    free(line2);
    close(fd1);
    close(fd2);
    
    return (0);
}
```

## 💡 Características Principales

### Implementación Central
- **Gestión de Buffer**: Lectura eficiente con `BUFFER_SIZE` configurable
- **Variables Estáticas**: Mantiene el estado entre llamadas a funciones
- **Memoria Dinámica**: Asignación y liberación adecuada
- **Análisis de Líneas**: Maneja correctamente nuevas líneas y fin de archivo

### Características Bonus
- **Múltiples Descriptores de Archivo**: Puede manejar la lectura de múltiples archivos simultáneamente
- **Estado Independiente**: Cada descriptor de archivo mantiene su propio estado de lectura

### Funciones de Utilidad
- `ft_strlen()`: Calcular longitud de cadena
- `ft_strchr()`: Encontrar carácter en cadena
- `ft_strjoin()`: Unir dos cadenas con gestión adecuada de memoria

## 🧪 Pruebas

La función maneja varios escenarios:
- Archivos vacíos
- Archivos sin saltos de línea
- Archivos con solo saltos de línea
- Archivos grandes con diferentes tamaños de buffer
- Múltiples descriptores de archivo (bonus)
- Descriptores de archivo inválidos
- Fallos de asignación de memoria

## 📈 Rendimiento

- **Complejidad Temporal**: O(n) donde n es el tamaño del archivo
- **Complejidad Espacial**: O(BUFFER_SIZE + longitud_línea)
- **Eficiencia de Memoria**: Solo asigna memoria para la línea actual
- **Optimización de Buffer**: Tamaño de buffer configurable para diferentes casos de uso

## 🔧 Configuración

El tamaño del buffer puede configurarse en tiempo de compilación:

```bash
# Buffer pequeño para pruebas
gcc -D BUFFER_SIZE=1 ...

# Buffer grande para rendimiento
gcc -D BUFFER_SIZE=8192 ...

# Tamaño de buffer por defecto
gcc -D BUFFER_SIZE=4069 ...
```

## 🚨 Manejo de Errores

- Retorna `NULL` para descriptores de archivo inválidos
- Maneja fallos de asignación de memoria elegantemente
- Gestiona apropiadamente errores de lectura de archivos
- Previene fugas de memoria en todos los escenarios

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
