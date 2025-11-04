# philosophers

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C-brightgreen)
![Rango](https://img.shields.io/badge/Rango-03-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-100%2F100-success)

## 📋 Descripción del Proyecto

`philosophers` es una implementación del clásico problema de ciencias de la computación que explora programación concurrente, hilos y sincronización en C. Este proyecto forma parte del currículo del Common Core de 42 (Rango 03) y está basado en el famoso "Problema de los Filósofos Comensales" introducido por Edsger Dijkstra.

## 🎯 Objetivos

- Comprender e implementar conceptos de hilos usando pthreads
- Aprender sobre condiciones de carrera y cómo prevenirlas
- Implementar sincronización adecuada usando mutex
- Manejar recursos compartidos entre múltiples hilos
- Gestionar el ciclo de vida y comunicación de hilos
- Prevenir deadlocks y manejar seguridad de hilos
- Seguir los estándares de codificación de 42 School (Norminette)

## 🧠 El Problema de los Filósofos Comensales

El problema consiste en N filósofos sentados en una mesa redonda con N tenedores. Cada filósofo alterna entre pensar, comer y dormir. Para comer, un filósofo necesita ambos tenedores adyacentes (izquierdo y derecho). El desafío es diseñar una solución que prevenga deadlock e inanición.

### Las Reglas
- Los filósofos alternan entre **comer**, **dormir** y **pensar**
- Un filósofo necesita **dos tenedores** para comer (izquierdo y derecho)
- Los filósofos no pueden comunicarse entre sí
- Cuando un filósofo termina de comer, deja ambos tenedores y comienza a dormir
- Después de dormir, comienzan a pensar
- La simulación se detiene cuando un filósofo muere o todos han comido suficientes veces

## 📁 Estructura del Proyecto

```
7_philosophers/
├── philo.h                          # Archivo de cabecera principal
├── 0_main.c                         # Punto de entrada del programa principal
├── 1_argument_parsing.c             # Validación de argumentos de línea de comandos
├── 2_init_table.c                   # Inicializar mesa y datos compartidos
├── 3_init_philos.c                  # Inicializar estructuras de filósofos
├── 4_threads.c                      # Creación y gestión de hilos
├── 5_philosophers_routine.c         # Comportamiento principal del filósofo
├── 6_guard.c                        # Hilo monitor (detección de muerte)
├── ft_printf/                       # Implementación personalizada de printf
├── l_atoi.c                         # Conversión de cadena a entero
├── l_atol.c                         # Conversión de cadena a long
├── l_isdigit.c                      # Validación de dígitos
├── l_isspace.c                      # Validación de espacios en blanco
├── l_strcmp.c                       # Comparación de cadenas
├── u_destroyandexit.c               # Funciones de limpieza y salida
├── u_isdeath.c                      # Utilidades de detección de muerte
├── u_isfinished.c                   # Verificación de finalización
├── u_printstatus.c                  # Impresión de estado segura para hilos
├── u_time.c                         # Funciones de gestión de tiempo
├── ft_print_error.c                 # Manejo de errores
├── Makefile                         # Configuración de compilación
└── README_es.md                     # Este archivo
```

## 🚀 Uso

### Prerrequisitos

- Linux o macOS
- Compilador GCC con soporte pthread
- Utilidad Make

### Compilación

```bash
# Clonar y compilar
git clone [repositorio]
cd philosophers
make

# Limpiar archivos objeto
make clean

# Limpiar todo
make fclean

# Recompilar todo
make re
```

### Ejecutar la Simulación

```bash
./philo número_de_filósofos tiempo_para_morir tiempo_para_comer tiempo_para_dormir [número_de_veces_que_cada_filósofo_debe_comer]
```

### Parámetros

| Parámetro | Descripción | Requerido |
|-----------|-------------|-----------|
| `número_de_filósofos` | Número de filósofos (1-200) | ✅ |
| `tiempo_para_morir` | Tiempo en ms antes de que un filósofo muera | ✅ |
| `tiempo_para_comer` | Tiempo en ms para comer | ✅ |
| `tiempo_para_dormir` | Tiempo en ms para dormir | ✅ |
| `número_de_veces_que_cada_filósofo_debe_comer` | Condición de parada (opcional) | ❌ |

### Ejemplos

```bash
# Simulación básica
./philo 5 800 200 200

# Con límite de comidas
./philo 5 800 200 200 7

# Tiempo ajustado (no debería morir)
./philo 4 410 200 200

# Un solo filósofo (debería morir)
./philo 1 800 200 200

# Simulación grande
./philo 100 800 200 200
```

## 💡 Características Principales

### Gestión de Hilos
- **Hilos de Filósofos**: Cada filósofo ejecuta en su propio hilo
- **Hilo Monitor**: Hilo dedicado para verificar condiciones de muerte
- **Sincronización**: Sincronización y comunicación adecuada de hilos
- **Gestión de Ciclo de Vida**: Creación y destrucción limpia de hilos

### Implementación de Mutex
- **Mutex de Tenedores**: Un mutex por tenedor para prevenir acceso compartido
- **Mutex de Impresión**: Asegura impresión atómica de mensajes de estado
- **Mutex de Muerte**: Protege la verificación del estado de muerte
- **Mutex de Comidas**: Sincroniza el conteo de comidas y verificación de finalización

### Prevención de Deadlock
- **Adquisición Ordenada de Locks**: Orden consistente de toma de tenedores
- **Estrategia del Último Filósofo**: Manejo especial para el último filósofo
- **Gestión de Timeouts**: Temporización adecuada para prevenir bloqueo indefinido

## 🎨 Detalles de Implementación

### Estructuras de Datos Principales

```c
typedef struct s_philo
{
    long            id;
    long            meals;
    bool            death;
    bool            finished;
    long            last_meal_time;
    long            start_time;
    t_table         *table;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t meal_mutex;
} t_philo;

typedef struct s_table
{
    long            philos_numb;
    long            die_time;
    long            eat_time;
    long            sleep_time;
    long            must_eat;
    bool            argv_5;
    long            died;
    long            finished;
    long            start_time;
    t_philo         philos[MAX];
    pthread_t       moiras;
    pthread_mutex_t forks[MAX];
    pthread_mutex_t death_mtx;
    pthread_mutex_t print_mtx;
    pthread_mutex_t meal_mtx;
} t_table;
```

### Rutina del Filósofo

```c
void *agora(void *data)
{
    t_philo *philo = (t_philo *)data;
    
    while (!is_dead(philo) && !is_finished(philo))
    {
        take_forks(philo);
        eat(philo);
        sleep_and_think(philo);
    }
    
    return (NULL);
}
```

### Detección de Muerte

El hilo monitor verifica continuamente si algún filósofo ha excedido el tiempo para morir:

```c
void *guard(void *data)
{
    t_table *table = (t_table *)data;
    
    while (!simulation_finished(table))
    {
        check_all_philosophers(table);
        usleep(CHECK_INTERVAL);
    }
    
    return (NULL);
}
```

## 🧪 Escenarios de Prueba

### Pruebas Básicas
```bash
# No debería morir
./philo 1 800 200 200    # Un solo filósofo (muere)
./philo 5 800 200 200    # Caso normal
./philo 4 410 200 200    # Tiempo ajustado

# Debería completarse
./philo 5 800 200 200 7  # Con límite de comidas
./philo 2 800 200 200 5  # Dos filósofos
```

### Pruebas de Estrés
```bash
# Alto número de filósofos
./philo 200 800 200 200

# Tiempo muy ajustado
./philo 4 305 200 100

# Simulación larga
./philo 10 800 200 200 100
```

### Casos Límite
```bash
# Argumentos inválidos
./philo 0 800 200 200     # Cero filósofos
./philo 5 -1 200 200      # Tiempo negativo
./philo abc 800 200 200   # Entrada no numérica
```

## 🚨 Manejo de Errores

El programa maneja varias condiciones de error:
- **Argumentos Inválidos**: Valores no numéricos o fuera de rango
- **Fallos de Creación de Hilos**: Limpieza adecuada en errores de pthread_create
- **Fallos de Inicialización de Mutex**: Limpieza de recursos en errores de mutex
- **Gestión de Memoria**: Limpieza adecuada de todos los recursos asignados

## 📈 Consideraciones de Rendimiento

- **Uso Mínimo de CPU**: Implementación eficiente de sleep usando usleep
- **Eficiencia de Memoria**: Asignación estática para estructuras de filósofos
- **Seguridad de Hilos**: Todo acceso a datos compartidos está adecuadamente sincronizado
- **Escalabilidad**: Soporta hasta 200 filósofos eficientemente

## 🔧 Características Avanzadas

### Gestión de Tiempo
- **Temporización Precisa**: Precisión de microsegundos para todos los cálculos de tiempo
- **Sleep No Bloqueante**: Implementación personalizada de usleep
- **Inicio Sincronizado**: Todos los filósofos comienzan simultáneamente

### Reporte de Estado
```
timestamp_en_ms X ha tomado un tenedor
timestamp_en_ms X está comiendo
timestamp_en_ms X está durmiendo
timestamp_en_ms X está pensando
timestamp_en_ms X murió
```

### Detección de Finalización
- Rastrea cuando todos los filósofos han comido el número requerido de veces
- Terminación elegante cuando se cumplen los objetivos de simulación
- Limpieza adecuada de todos los recursos

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
