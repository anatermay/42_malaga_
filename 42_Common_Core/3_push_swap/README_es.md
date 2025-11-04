# push_swap

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C-brightgreen)
![Rango](https://img.shields.io/badge/Rango-02-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-125%2F100-success)

## 📋 Descripción del Proyecto

`push_swap` es un proyecto de algoritmos de ordenación que te desafía a ordenar datos en una pila, con un conjunto limitado de instrucciones, usando el menor número posible de acciones. Este proyecto forma parte del currículo del Common Core de 42 School (Rango 02) y se enfoca en comprender algoritmos, complejidad y estructuras de datos.

## 🎯 Objetivos

- Ordenar una pila de enteros usando dos pilas (A y B) con operaciones mínimas
- Implementar algoritmos de ordenación eficientes para diferentes tamaños de entrada
- Manejar casos extremos y optimizar el rendimiento
- Crear un programa checker para validar las operaciones de ordenación
- Seguir los estándares de codificación de 42 School (Norminette)

## 🔧 Operaciones Disponibles

El programa puede realizar las siguientes operaciones:

| Operación | Descripción |
|-----------|-------------|
| `sa` | Intercambiar los primeros 2 elementos de la pila A |
| `sb` | Intercambiar los primeros 2 elementos de la pila B |
| `ss` | `sa` y `sb` al mismo tiempo |
| `pa` | Empujar el primer elemento de la pila B hacia la pila A |
| `pb` | Empujar el primer elemento de la pila A hacia la pila B |
| `ra` | Rotar la pila A (el primer elemento se convierte en el último) |
| `rb` | Rotar la pila B (el primer elemento se convierte en el último) |
| `rr` | `ra` y `rb` al mismo tiempo |
| `rra` | Rotar inversamente la pila A (el último elemento se convierte en el primero) |
| `rrb` | Rotar inversamente la pila B (el último elemento se convierte en el primero) |
| `rrr` | `rra` y `rrb` al mismo tiempo |

## 📁 Estructura del Proyecto

```
3_push_swap/
├── push_swap.c           # Lógica principal del programa
├── push_swap.h           # Archivo de cabecera con prototipos y estructuras
├── checker.c             # Programa checker bonus
├── checker.h             # Cabecera del checker
├── argv_checker.c        # Funciones de validación de entrada
├── bso.c                 # Funciones de optimización
├── cost_algorithm_0.c    # Algoritmos de cálculo de costos
├── cost_algorithm_1.c    # Cálculos avanzados de costos
├── if_nbr_args.c         # Ordenación para pilas pequeñas
├── memory_handling.c     # Funciones de gestión de memoria
├── min_handling.c        # Manejo de valores mínimos
├── push.c                # Operaciones push (pa, pb)
├── reverse_rotate.c      # Operaciones de rotación inversa (rra, rrb, rrr)
├── rotate.c              # Operaciones de rotación (ra, rb, rr)
├── stack_handling.c      # Funciones utilitarias de pila
├── swap.c                # Operaciones de intercambio (sa, sb, ss)
├── libft.c               # Funciones libft personalizadas
├── libft.h               # Cabecera de libft
├── libft_continue.c      # Funciones adicionales de libft
├── get_next_line.c       # GNL para checker bonus
├── Makefile             # Configuración de compilación
└── README_es.md         # Este archivo
```

## 🚀 Uso

### Compilación

```bash
# Compilar el programa principal
make

# Compilar el checker (bonus)
make bonus

# Limpiar archivos objeto
make clean

# Limpiar todo
make fclean

# Recompilar todo
make re
```

### Ejecutar el Programa

```bash
# Ordenar una lista de enteros
./push_swap 2 1 3 6 5 8

# Usar con números aleatorios
ARG="4 67 3 87 23"; ./push_swap $ARG

# Probar con checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Ejemplos

```bash
# Ejemplo simple con 3 números
./push_swap 2 1 3
# Salida: sa

# Ejemplo más grande
./push_swap 2 1 0
# Salida: 
# sa
# rra

# Verificar si la ordenación es correcta
./push_swap 2 1 0 | ./checker 2 1 0
# Salida: OK
```

## 💡 Estrategia del Algoritmo

La implementación usa diferentes estrategias basadas en el tamaño de la pila:

### Pilas Pequeñas (≤ 5 elementos)
- **2-3 elementos**: Ordenación directa con operaciones mínimas
- **4-5 elementos**: Mover el mínimo a la pila B, ordenar el resto, luego empujar de vuelta

### Pilas Grandes (> 5 elementos)
1. **Indexado**: Asignar índices para crear una representación normalizada
2. **Push Inicial**: Empujar elementos a la pila B basándose en rangos de índices
3. **Análisis de Costos**: Calcular el costo de mover cada elemento a su posición objetivo
4. **Movimientos Óptimos**: Ejecutar los movimientos menos costosos para ordenar eficientemente
5. **Posicionamiento Final**: Posicionar el elemento mínimo en la parte superior

### Características Clave
- **Calculadora de Costos**: Evalúa el número de operaciones necesarias para cada movimiento posible
- **Asignación de Objetivos**: Determina la posición óptima para cada elemento
- **Optimización**: Usa operaciones combinadas (rr, rrr, ss) cuando es beneficioso

## 🧪 Pruebas

El proyecto maneja varios casos extremos:
- Arrays ya ordenados
- Arrays ordenados inversamente
- Números duplicados (manejo de errores)
- Entrada inválida (no numérica, desbordamiento)
- Entrada vacía
- Elemento único

### Benchmarks de Rendimiento
- **3 elementos**: ≤ 3 operaciones
- **5 elementos**: ≤ 12 operaciones
- **100 elementos**: ≤ 700 operaciones (objetivo: < 700)
- **500 elementos**: ≤ 5500 operaciones (objetivo: < 5500)

## 📈 Análisis de Complejidad

- **Complejidad Temporal**: O(n²) en el peor caso, O(n log n) promedio
- **Complejidad Espacial**: O(n) para almacenamiento de pila
- **Recuento de Operaciones**: Optimizado para cumplir los requisitos de 42 School

## 🏆 Características Bonus

El programa checker valida si una secuencia de operaciones ordena correctamente la pila:
- Lee operaciones desde la entrada estándar
- Las ejecuta en la pila proporcionada
- Devuelve "OK" si está ordenada, "KO" si no, "Error" para entrada inválida

## 🔗 Enlaces

- **Autora**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repositorio**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 🏆 Logro

**Puntuación Final**: 125/100 ✨

---

*Este proyecto fue completado como parte del currículo de 42 School en 42 Málaga.*
