# 🎓 42 Common Core - Viaje de Programación de Sistemas

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://es.wikipedia.org/wiki/C_(lenguaje_de_programaci%C3%B3n))
[![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)](https://www.linux.org/)
[![Git](https://img.shields.io/badge/Git-F05032?style=flat&logo=git&logoColor=white)](https://git-scm.com/)
[![Unix](https://img.shields.io/badge/Unix-000000?style=flat&logo=unix&logoColor=white)](https://es.wikipedia.org/wiki/Unix)

## 📖 Acerca del Proyecto

Este repositorio muestra mi viaje completo a través del curriculum **42 Common Core**, una educación integral en programación de sistemas en la Escuela 42. Desde programación fundamental en C hasta conceptos avanzados de sistemas, cada proyecto se construye sobre el conocimiento previo mientras introduce nuevos desafíos en ingeniería de software, algoritmos y diseño de sistemas.

## 🎯 Objetivos Educacionales

- Dominar la **programación en C** y gestión de memoria
- Entender la **programación de sistemas Unix/Linux**
- Aprender implementación de **algoritmos y estructuras de datos**
- Desarrollar habilidades de **resolución de problemas** y **depuración**
- Explorar **programación concurrente** y **comunicación entre procesos**
- Construir comprensión de **programación de redes** y **arquitectura de sistemas**

## 📁 Resumen de Proyectos

### 🔧 **Rank 00: Fundamentos**
| Proyecto | Descripción | Tecnologías | Estado |
|----------|-------------|-------------|--------|
| **[libft](./0_libft)** | Implementación de biblioteca C personalizada | `C` `Makefile` | ✅ **100%** |

**Logro Clave**: Reimplementé 43 funciones de la biblioteca estándar de C desde cero, estableciendo una base sólida para todos los proyectos futuros.

### 🔧 **Rank 01: Programación Central**
| Proyecto | Descripción | Tecnologías | Estado |
|----------|-------------|-------------|--------|
| **[ft_printf](./1_ft_printf)** | Función printf personalizada | `C` `Funciones Variádicas` | ✅ **100%** |
| **[get_next_line](./2_get_next_line)** | Función de lectura de archivos | `C` `E/S de Archivos` `Variables Estáticas` | ✅ **100%** |
| **born2beroot** | Proyecto de administración de sistemas | `VirtualBox` `Linux` `Administración de Sistemas` | ✅ **100%** |

### 🔧 **Rank 02: Algoritmos y Gráficos**
| Proyecto | Descripción | Tecnologías | Estado |
|----------|-------------|-------------|--------|
| **[push_swap](./3_push_swap)** | Algoritmo de ordenamiento eficiente | `C` `Algoritmos` `Operaciones de Pila` | ✅ **100%** |
| **[so_long](./5_so_long)** | Juego 2D con biblioteca gráfica | `C` `MLX42` `Desarrollo de Juegos` | ✅ **100%** |
| **[minitalk](./4_minitalk)** | Comunicación entre procesos vía señales | `C` `Señales Unix` `IPC` | ✅ **100%** |
| **examrank02** | Examen: Programación intermedia en C | `C` `Resolución de Problemas` | ✅ **100%** |

### 🔧 **Rank 03: Sistemas Avanzados**
| Proyecto | Descripción | Tecnologías | Estado |
|----------|-------------|-------------|--------|
| **[philosophers](./7_philosophers)** | Concurrencia y threading | `C` `Pthreads` `Mutexes` `Sincronización` | ✅ **100%** |
| **[minishell](./6_minishell)** | Implementación de shell Unix | `C` `Bash` `Gestión de Procesos` | ✅ **100%** |
| **examrank03** | Examen: C avanzado y programación de sistemas | `C` `Programación de Sistemas` | ✅ **100%** |

### 🔧 **Rank 04: Redes y Conceptos Avanzados** (Actual)
| Proyecto | Descripción | Tecnologías | Estado |
|----------|-------------|-------------|--------|
| **[netpractice](./8_netpractice)** | Configuración de redes y subnetting | `TCP/IP` `Subnetting` `Enrutamiento` | ✅ **100%** |
| **examrank04** | Examen: Sistemas avanzados y redes | `C` `Redes` `Sistemas` | 🔄 **En Progreso** |
| **cub3d** | Motor de juego 3D (raycasting) | `C` `MLX42` `Gráficos 3D` `Raycasting` | 🔄 **En Progreso** |
| **CPP 00-04** | Módulos de programación C++ | `C++` `POO` `STL` | 🔄 **En Progreso** |

## 🚀 Aspectos Destacados de los Proyectos

### 📚 **libft - Los Fundamentos**
Una biblioteca C completa que contiene 43+ funciones incluyendo:
- **Manipulación de cadenas**: `ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_split`
- **Gestión de memoria**: `ft_memset`, `ft_memcpy`, `ft_calloc`
- **Operaciones de listas enlazadas**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstmap`
- **Utilidades de caracteres/números**: `ft_isalpha`, `ft_atoi`, `ft_itoa`

### 🖨️ **ft_printf - Dominio de Salida Formateada**
Recreación de la famosa función `printf` soportando:
- **Especificadores de formato**: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- **Funciones variádicas** y **análisis de argumentos**
- **Formateo de cadenas** eficiente en memoria

### 📖 **get_next_line - Excelencia en E/S de Archivos**
Una función que lee archivos línea por línea con:
- **Gestión de buffer** con `BUFFER_SIZE` personalizable
- **Variables estáticas** para estado persistente
- **Prevención de fugas de memoria** y soporte para **múltiples descriptores de archivo**

### 🔄 **push_swap - Optimización de Algoritmos**
Un desafío de ordenamiento implementando:
- **Algoritmos de ordenamiento optimizados** para diferentes tamaños de entrada
- **Operaciones de pila**: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- **Análisis de costos complejo** y **optimización de movimientos**

### 📡 **minitalk - Comunicación entre Procesos**
Comunicación inter-proceso usando señales Unix:
- **Arquitectura cliente-servidor** usando `SIGUSR1` y `SIGUSR2`
- **Transmisión de datos a nivel de bit** y **soporte Unicode**
- **Manejo de errores** y **sistema de confirmación**

### 🎮 **so_long - Desarrollo de Juegos 2D**
Un juego 2D completo con:
- **Integración de biblioteca gráfica MLX42**
- **Animación de sprites** y **gestión de texturas**
- **Validación de mapas** y **detección de colisiones**
- **Movimiento del jugador** y **completado de objetivos**

### 💻 **minishell - Implementación de Shell**
Un shell Unix completamente funcional incluyendo:
- **Análisis de comandos** y **pipeline de ejecución**
- **Comandos integrados**: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Variables de entorno** y **manejo de señales**
- **Redirección** y **operaciones de pipe**

### 🍽️ **philosophers - Dominio de Concurrencia**
El clásico problema de los filósofos cenando con:
- **Multithreading** con `pthreads`
- **Sincronización con mutex** y **prevención de deadlock**
- **Compartición de recursos** y **manejo de condiciones de carrera**
- **Temporización precisa** y **gestión de estados de filósofos**

### 🌐 **netpractice - Fundamentos de Redes**
Ejercicios de configuración de redes cubriendo:
- **Comprensión del protocolo TCP/IP**
- **Subnetting** y **notación CIDR**
- **Tablas de enrutamiento** y **resolución de problemas de red**
- **Aplicación práctica del modelo OSI**

## 🛠️ Tecnologías y Habilidades Dominadas

### **Lenguajes de Programación**
- **Programación en C**: Competencia avanzada con punteros, gestión de memoria y llamadas al sistema
- **Scripting de Shell**: Bash scripting y herramientas de línea de comandos Unix

### **Programación de Sistemas**
- **Gestión de Memoria**: Asignación dinámica, prevención de fugas y optimización
- **Gestión de Procesos**: Fork, exec, wait y comunicación entre procesos
- **E/S de Archivos**: Operaciones de archivos de bajo nivel y gestión de descriptores
- **Manejo de Señales**: Señales Unix y comunicación inter-proceso

### **Concurrencia y Paralelismo**
- **Threading**: POSIX threads (pthreads) y gestión de hilos
- **Sincronización**: Mutexes, semáforos y prevención de condiciones de carrera
- **Prevención de Deadlock**: Gestión de recursos y control de temporización

### **Programación de Redes**
- **Stack TCP/IP**: Comprensión de protocolos de red y arquitectura
- **Subnetting**: Diseño de redes y gestión de direcciones IP
- **Enrutamiento**: Gestión y configuración de tráfico de red

### **Programación Gráfica**
- **Biblioteca MLX42**: Renderizado de gráficos 2D y manejo de eventos
- **Desarrollo de Juegos**: Animación, detección de colisiones e interacción del usuario

### **Herramientas de Desarrollo**
- **Makefile**: Automatización de compilación y gestión de dependencias
- **GDB**: Depuración y análisis de programas
- **Valgrind**: Detección de fugas de memoria y análisis de rendimiento
- **Git**: Control de versiones y desarrollo colaborativo

## 📈 Progresión del Aprendizaje

1. **Rank 00** → Fundamentos de programación en C y funciones de biblioteca
2. **Rank 01** → Manipulación avanzada de cadenas, funciones variádicas y administración de sistemas
3. **Rank 02** → Optimización de ordenamiento, programación gráfica y comunicación entre procesos
4. **Rank 03** → Programación de shell, concurrencia y conceptos avanzados de sistemas
5. **Rank 04** → Protocolos de red, gráficos 3D y programación orientada a objetos

## 🎓 Habilidades Desarrolladas

- **Programación de Sistemas**: Comprensión profunda de internos Unix/Linux
- **Diseño de Algoritmos**: Resolución eficiente de problemas y optimización
- **Gestión de Memoria**: Programación sin fugas y optimización de recursos
- **Programación Concurrente**: Código thread-safe y sincronización
- **Programación de Redes**: Comprensión e implementación de protocolos
- **Calidad de Código**: Código limpio, mantenible y bien documentado
- **Depuración**: Resolución avanzada de problemas y análisis de errores
- **Gestión de Proyectos**: Organización de código grande y colaboración

## 🌟 Logros Destacados

- ✅ **9 Proyectos Completados** con **100% de Éxito**
- ✅ **Actualmente en Rank 04** - Estudiante de nivel avanzado
- ✅ **Cero Fugas de Memoria** en todos los proyectos (verificado con Valgrind)
- ✅ **Cumplimiento de Norm** siguiendo estándares de codificación de 42
- ✅ **Aprendizaje Peer-to-Peer** a través de revisiones de código y colaboración
- ✅ **Dominio de Conceptos Avanzados** en programación de sistemas, redes y concurrencia
- ✅ **Minishell Completado** - Implementación completa de shell Unix
- ✅ **Programación de Redes** - Experiencia en TCP/IP y enrutamiento

## 📊 Estadísticas Generales

**Rank Actual**: 04 🎯  
**Proyectos Completados**: 9/12 ✅  
**Tasa de Éxito**: 100% 🏆  
**Líneas de Código**: 15,000+ 💻  
**Tecnologías Aprendidas**: 20+ 🔧  
**Conceptos Centrales Dominados**: 30+ 🧠

## 🔗 Enlaces

- **Repositorio GitHub**: [42_malaga_](https://github.com/anatermay/42_malaga_)
- **Perfil GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Escuela 42**: [42 Málaga - Fundación Telefónica](https://www.42malaga.com/)

## 📝 Próximos Pasos

Esta base integral en programación de sistemas me ha preparado para:
- **Programación Avanzada en C++** (módulos CPP 00-04)
- **Programación de Gráficos 3D** (motor de raycasting cub3d)
- **Exámenes Avanzados de Sistema** (examrank04)
- **Desarrollo Backend** con lenguajes modernos
- **DevOps y Administración de Sistemas**
- **Programación de Sistemas Embebidos**
- **Seguridad de Redes e Infraestructura**
- **Desarrollo Full-Stack** con fuerte comprensión de sistemas

---

*Esta colección representa dos años de aprendizaje intensivo en programación de sistemas, demostrando progresión desde programación básica en C hasta conceptos avanzados de arquitectura de sistemas y programación de redes.*
