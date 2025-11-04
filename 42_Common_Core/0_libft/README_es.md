# 📚 libft - Implementación de Biblioteca C Personalizada

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://es.wikipedia.org/wiki/C_(lenguaje_de_programaci%C3%B3n))
[![Norm](https://img.shields.io/badge/Norm-v3-blue)](https://github.com/42School/norminette)
[![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen)](https://profile.intra.42.fr/users/aternero)

## 📖 Acerca del Proyecto

**libft** es el proyecto fundamental del curriculum 42 Common Core (Rank 00). Este proyecto requiere implementar una biblioteca C completa que contiene funciones esenciales que replican el comportamiento de las funciones de la biblioteca estándar de C, además de funciones de utilidad adicionales. Sirve como base para todos los proyectos posteriores de 42.

## 🎯 Objetivos del Proyecto

- **Reimplementar** funciones de la biblioteca estándar de C desde cero
- **Comprender** la gestión de memoria de bajo nivel y punteros
- **Dominar** fundamentos de programación en C y mejores prácticas
- **Crear** una biblioteca reutilizable para futuros proyectos de 42
- **Aprender** organización de código y documentación apropiada

## 📁 Estructura del Proyecto

```
libft/
├── libft.h                 # Archivo de cabecera con prototipos de funciones
├── Makefile               # Automatización de construcción
├── ft_*.c                 # 43 implementaciones de funciones
└── README.md              # Documentación del proyecto
```

## 📋 Categorías de Funciones

### 🔤 **Clasificación y Conversión de Caracteres (7 funciones)**
| Función | Descripción | Equivalente Estándar |
|---------|-------------|---------------------|
| `ft_isalpha` | Verificar si el carácter es alfabético | `isalpha` |
| `ft_isdigit` | Verificar si el carácter es numérico | `isdigit` |
| `ft_isalnum` | Verificar si el carácter es alfanumérico | `isalnum` |
| `ft_isascii` | Verificar si el carácter es ASCII | `isascii` |
| `ft_isprint` | Verificar si el carácter es imprimible | `isprint` |
| `ft_toupper` | Convertir a mayúscula | `toupper` |
| `ft_tolower` | Convertir a minúscula | `tolower` |

### 🧵 **Manipulación de Cadenas (11 funciones)**
| Función | Descripción | Equivalente Estándar |
|---------|-------------|---------------------|
| `ft_strlen` | Calcular longitud de cadena | `strlen` |
| `ft_strchr` | Localizar carácter en cadena | `strchr` |
| `ft_strrchr` | Localizar carácter en cadena (reverso) | `strrchr` |
| `ft_strncmp` | Comparar cadenas (n caracteres) | `strncmp` |
| `ft_strlcpy` | Copia de cadena con límite de tamaño | `strlcpy` |
| `ft_strlcat` | Concatenación de cadena con límite de tamaño | `strlcat` |
| `ft_strnstr` | Localizar subcadena | `strnstr` |
| `ft_strdup` | Duplicar cadena | `strdup` |

### 🧠 **Gestión de Memoria (6 funciones)**
| Función | Descripción | Equivalente Estándar |
|---------|-------------|---------------------|
| `ft_memset` | Llenar memoria con byte constante | `memset` |
| `ft_bzero` | Poner a cero una cadena de bytes | `bzero` |
| `ft_memcpy` | Copiar área de memoria | `memcpy` |
| `ft_memmove` | Copiar área de memoria (seguro para solapamiento) | `memmove` |
| `ft_memchr` | Buscar carácter en memoria | `memchr` |
| `ft_memcmp` | Comparar áreas de memoria | `memcmp` |

### 🔢 **Conversión y E/S (7 funciones)**
| Función | Descripción | Equivalente Estándar |
|---------|-------------|---------------------|
| `ft_atoi` | Conversión ASCII a entero | `atoi` |
| `ft_itoa` | Conversión entero a ASCII | *Personalizada* |
| `ft_calloc` | Asignar y poner a cero memoria | `calloc` |
| `ft_putchar_fd` | Salida de carácter a descriptor de archivo | *Personalizada* |
| `ft_putstr_fd` | Salida de cadena a descriptor de archivo | *Personalizada* |
| `ft_putendl_fd` | Salida de cadena + nueva línea a descriptor | *Personalizada* |
| `ft_putnbr_fd` | Salida de número a descriptor de archivo | *Personalizada* |

### ✨ **Funciones Adicionales de Cadenas (6 funciones)**
| Función | Descripción | Propósito |
|---------|-------------|-----------|
| `ft_substr` | Extraer subcadena | Crear subcadena de cadena |
| `ft_strjoin` | Concatenar cadenas | Unir dos cadenas con asignación |
| `ft_strtrim` | Recortar caracteres de cadena | Eliminar caracteres específicos de los extremos |
| `ft_split` | Dividir cadena por delimitador | Dividir cadena en array |
| `ft_strmapi` | Aplicar función a caracteres de cadena | Mapear función con índice |
| `ft_striteri` | Iterar función sobre cadena | Aplicar función a cada carácter |

### 🔗 **Bonus: Funciones de Lista Enlazada (9 funciones)**
| Función | Descripción | Propósito |
|---------|-------------|-----------|
| `ft_lstnew` | Crear nuevo elemento de lista | Creación de lista |
| `ft_lstadd_front` | Agregar elemento al frente de lista | Manipulación de lista |
| `ft_lstadd_back` | Agregar elemento al final de lista | Manipulación de lista |
| `ft_lstsize` | Contar elementos de lista | Información de lista |
| `ft_lstlast` | Obtener último elemento de lista | Navegación de lista |
| `ft_lstdelone` | Eliminar un elemento de lista | Gestión de memoria |
| `ft_lstclear` | Eliminar lista completa | Gestión de memoria |
| `ft_lstiter` | Aplicar función a lista | Iteración de lista |
| `ft_lstmap` | Aplicar función y crear nueva lista | Programación funcional |

## 🛠️ Implementación Técnica

### **Características Principales:**
- **Seguridad de Memoria**: Todas las funciones manejan punteros NULL correctamente
- **Protección contra Desbordamiento de Buffer**: Operaciones con límite de tamaño previenen desbordamientos
- **Cumplimiento de Norm**: Sigue estrictamente los estándares de codificación de 42
- **Sin Fugas de Memoria**: Asignación y desasignación apropiada
- **Diseño Modular**: Cada función en archivo separado para compilación limpia

### **Implementaciones Avanzadas:**

#### `ft_split` - Tokenización de Cadenas
```c
char **ft_split(char const *s, char c);
```
- Divide la cadena `s` usando el delimitador `c`
- Retorna array de cadenas terminado en NULL
- Maneja múltiples delimitadores consecutivos
- Eficiente en memoria con manejo apropiado de errores

#### `ft_itoa` - Conversión de Entero a Cadena
```c
char *ft_itoa(int n);
```
- Convierte cualquier entero (incluyendo `INT_MIN`) a cadena
- Maneja números negativos y casos extremos
- Asignación dinámica de memoria para el tamaño exacto necesario

#### Implementación de Lista Enlazada
```c
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;
```
- Lista enlazada genérica que soporta cualquier tipo de dato
- Conjunto completo de funciones de manipulación
- Gestión de memoria con funciones de eliminación personalizadas

## 🏗️ Sistema de Construcción

### **Objetivos del Makefile:**
```bash
make all        # Compilar biblioteca principal
make bonus      # Compilar con funciones bonus
make clean      # Eliminar archivos objeto
make fclean     # Eliminar todos los archivos generados
make re         # Recompilar todo
```

### **Compilación:**
```bash
gcc -Wall -Wextra -Werror -c *.c
ar rcs libft.a *.o
```

## 🧪 Pruebas y Validación

### **Métodos de Prueba:**
- **Pruebas Unitarias**: Cada función probada individualmente
- **Pruebas de Memoria**: Valgrind para detección de fugas
- **Casos Extremos**: Punteros NULL, cadenas vacías, valores límite
- **Cumplimiento de Norm**: Validación con Norminette
- **Pruebas de Comparación**: Resultados comparados con biblioteca estándar

### **Casos de Prueba Clave:**
- Cadenas vacías y punteros NULL
- Valores enteros máximos/mínimos
- Asignaciones de memoria grandes
- Regiones de memoria solapadas (memmove)
- Unicode y caracteres especiales

## 🎓 Resultados de Aprendizaje

### **Habilidades Técnicas Desarrolladas:**
- **Dominio de Programación en C**: Comprensión profunda de sintaxis y semántica de C
- **Gestión de Memoria**: Asignación manual, desasignación y prevención de fugas
- **Aritmética de Punteros**: Manipulación avanzada y desreferenciación de punteros
- **Estructuras de Datos**: Implementación y manipulación de listas enlazadas
- **Sistemas de Construcción**: Creación de Makefile y gestión de dependencias
- **Organización de Código**: Programación modular y gestión de archivos de cabecera

### **Habilidades de Resolución de Problemas:**
- **Implementación de Algoritmos**: Algoritmos eficientes de cadenas y memoria
- **Manejo de Casos Extremos**: Verificación robusta de errores y validación de entrada
- **Depuración**: Identificación y resolución sistemática de errores
- **Optimización de Código**: Consideraciones de rendimiento en operaciones de bajo nivel

## 🌟 Aspectos Destacados del Proyecto

### **Logros Clave:**
- ✅ **43 Funciones Implementadas** - Subconjunto completo de biblioteca estándar
- ✅ **100% Cumplimiento de Norm** - Adherencia perfecta a estándares de codificación de 42
- ✅ **Cero Fugas de Memoria** - Gestión de memoria verificada con Valgrind
- ✅ **Pruebas Comprensivas** - Cobertura extensa de casos extremos
- ✅ **Bonus Completado** - Implementación completa de lista enlazada
- ✅ **Biblioteca Reutilizable** - Fundación para todos los proyectos futuros de 42

### **Excelencia Técnica:**
- **Optimizado en Rendimiento**: Algoritmos eficientes para todas las operaciones
- **Eficiente en Memoria**: Huella de memoria mínima y asignación óptima
- **Resistente a Errores**: Manejo elegante de todas las condiciones de error
- **Bien Documentado**: Estructura de código clara y comentarios comprensivos

## 📊 Estadísticas del Proyecto

**Total de Funciones**: 43 (34 obligatorias + 9 bonus) ✅  
**Líneas de Código**: 2,000+ 💻  
**Archivos**: 45 archivos fuente + cabecera + Makefile 📄  
**Calificación**: **125/100** (Puntuación perfecta + bonus) 🏆  
**Tiempo de Completado**: 3 semanas ⏱️

## 🔗 Enlaces

- **Repositorio GitHub**: [42_malaga_](https://github.com/anatermay/42_malaga_)
- **Perfil GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Escuela 42**: [42 Málaga - Fundación Telefónica](https://www.42malaga.com/)

## 🚀 Uso en Proyectos Futuros

Esta biblioteca sirve como fundación para proyectos posteriores de 42:
- **ft_printf**: Usa funciones de cadenas y memoria
- **get_next_line**: Utiliza manipulación de cadenas
- **push_swap**: Emplea funciones de lista enlazada
- **minishell**: Aprovecha análisis de cadenas y gestión de memoria
- **Todos los proyectos**: Se benefician de funciones de utilidad robustas

## 📝 Próximos Pasos

Esta biblioteca fundamental permitió la progresión a:
- **Procesamiento Avanzado de Cadenas** (ft_printf)
- **Operaciones de E/S de Archivos** (get_next_line)
- **Implementación de Algoritmos** (push_swap)
- **Programación de Sistemas** (minitalk, philosophers)
- **Programación Gráfica** (so_long)

---

*libft representa la piedra angular de mi educación en 42, estableciendo habilidades fundamentales de programación que permitieron el éxito en todos los proyectos posteriores.*
