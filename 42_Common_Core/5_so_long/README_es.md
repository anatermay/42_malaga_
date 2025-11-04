# so_long

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C-brightgreen)
![Rango](https://img.shields.io/badge/Rango-02-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-100%2F100-success)

## 📋 Descripción del Proyecto

`so_long` es un juego 2D de vista cenital construido con la biblioteca gráfica MLX42. Este proyecto forma parte del currículo del Common Core de 42 (Rango 02) y se enfoca en programación gráfica, manejo de eventos y fundamentos de desarrollo de videojuegos en C.

## 🎯 Objetivos

- Crear un juego 2D usando la biblioteca gráfica MLX42
- Implementar análisis y validación de mapas
- Manejar movimiento del jugador y mecánicas del juego
- Gestionar texturas, sprites y renderizado
- Implementar detección de colisiones y lógica del juego
- Seguir los estándares de codificación de 42 School (Norminette)

## 🎮 Mecánicas del Juego

### Elementos del Mapa
| Carácter | Elemento | Descripción |
|----------|----------|-------------|
| `1` | Pared | Barreras infranqueables |
| `0` | Suelo | Espacio vacío transitable |
| `P` | Jugador | Posición inicial (debe ser exactamente 1) |
| `C` | Coleccionable | Objetos a recoger (al menos 1) |
| `E` | Salida | Salida del juego (debe ser exactamente 1) |

### Reglas del Juego
- **Objetivo**: Recoger todos los coleccionables (`C`) y llegar a la salida (`E`)
- **Movimiento**: Usar WASD o teclas de dirección para mover al jugador
- **Condición de Victoria**: Recoger todos los objetos antes de salir
- **Contador de Movimientos**: Mostrar contador de movimientos en terminal
- **Requisitos del Mapa**: Rectangular, rodeado de paredes, camino válido a todos los elementos

## 📁 Estructura del Proyecto

```
5_so_long/
├── header_file/
│   └── so_long.h                    # Archivo de cabecera principal
├── sources/
│   ├── 0_the_threshold.c            # Función principal
│   ├── 1_the_first_guardian.c       # Validación de mapas
│   ├── 2_the_world_architect.c      # Análisis de mapas
│   ├── 3_the_second_guardian.c      # Validación de contenido
│   ├── 4_the_maze_explorer.c        # Búsqueda de caminos
│   ├── 5_the_windows_engineer.c     # Inicialización del juego
│   ├── 6_inns_receptionist.c        # Asignación de memoria
│   ├── 7_detective.c                # Detección de elementos
│   ├── 8_leonardo_da_vinci.c        # Motor de renderizado
│   ├── 9_telesketch.c               # Sistema de movimiento
│   ├── 10_keyboard.c                # Manejo de entradas
│   ├── appendix_cleaning_team.c     # Gestión de memoria
│   └── appendix_map.c               # Utilidades de mapa
├── maps/                            # Niveles del juego
├── img/                             # Sprites del juego
├── MLX42/                           # Biblioteca gráfica
├── resources/                       # libft y ft_printf
├── Makefile                         # Configuración de compilación
└── README_es.md                     # Este archivo
```

## 🚀 Uso

### Prerrequisitos

- Linux o macOS
- Biblioteca gráfica MLX42
- Soporte OpenGL
- Biblioteca GLFW

### Compilación

```bash
# Clonar y compilar
git clone [repositorio]
cd so_long
make

# Limpiar archivos objeto
make clean

# Limpiar todo
make fclean

# Recompilar todo
make re
```

### Ejecutar el Juego

```bash
# Uso básico
./so_long maps/level_0.ber

# Probar diferentes niveles
./so_long maps/level_1_0.ber
./so_long maps/level_2_0.ber
```

### Formato de Mapa

Crear mapas personalizados con extensión `.ber`:

```
11111111111111
1P0C00000000C1
10010000000001
1000C000000001
10000E00000001
11111111111111
```

**Requisitos del Mapa:**
- Forma rectangular
- Rodeado de paredes (`1`)
- Contiene exactamente un jugador (`P`) y una salida (`E`)
- Contiene al menos un coleccionable (`C`)
- Camino válido desde el jugador a todos los coleccionables y la salida

## 💡 Características Principales

### Gráficos y Renderizado
- **Integración MLX42**: Uso de biblioteca gráfica moderna
- **Gestión de Sprites**: Carga de texturas y renderizado de imágenes
- **Renderizado en Tiempo Real**: Actualizaciones gráficas fluidas
- **Sprites Multi-direccionales**: Diferentes orientaciones del jugador

### Sistemas de Juego
- **Validación de Mapas**: Verificación exhaustiva de errores de mapa
- **Algoritmo Flood Fill**: Validación de caminos para asegurar resolubilidad
- **Detección de Colisiones**: Verificación adecuada de paredes y límites
- **Seguimiento de Movimientos**: Contador de pasos con salida en terminal

### Gestión de Memoria
- **Asignación Dinámica**: Uso eficiente de memoria para mapas y sprites
- **Limpieza Adecuada**: Prevención de fugas de memoria
- **Manejo de Errores**: Gestión elegante de fallos

## 🧪 Validación de Mapas

El juego realiza validación exhaustiva de mapas:

### Validación Estructural
- La extensión del archivo debe ser `.ber`
- El mapa debe ser rectangular
- El mapa debe estar completamente rodeado de paredes

### Validación de Contenido
- Exactamente una posición inicial del jugador
- Exactamente una salida
- Al menos un coleccionable
- Solo caracteres válidos (`0`, `1`, `P`, `C`, `E`)

### Validación de Caminos
- El jugador puede alcanzar todos los coleccionables
- El jugador puede alcanzar la salida después de recoger objetos
- Usa algoritmo flood fill para verificación de caminos

## 🎨 Implementación Gráfica

### Sistema de Texturas
```c
typedef struct s_player
{
    mlx_texture_t   *fpj_text;    // Textura frontal
    mlx_texture_t   *lpj_text;    // Textura izquierda
    mlx_texture_t   *rpj_text;    // Textura derecha
    mlx_image_t     *actual;      // Imagen mostrada actualmente
    t_point         point;        // Posición del jugador
}   t_player;
```

### Pipeline de Renderizado
1. **Carga de Texturas**: Cargar sprites desde archivos PNG
2. **Creación de Imágenes**: Convertir texturas a imágenes MLX
3. **Renderizado de Escena**: Dibujar elementos del mapa en orden correcto
4. **Animación del Jugador**: Actualizar sprite del jugador según dirección de movimiento

## 🕹️ Controles

| Tecla | Acción |
|-------|--------|
| `W` / `↑` | Mover Arriba |
| `A` / `←` | Mover Izquierda |
| `S` / `↓` | Mover Abajo |
| `D` / `→` | Mover Derecha |
| `ESC` | Salir del Juego |

## 🚨 Manejo de Errores

El juego maneja varias condiciones de error:
- Argumentos de línea de comandos inválidos
- Archivos de mapa mal formados
- Texturas o sprites faltantes
- Fallos de asignación de memoria
- Contenido o estructura de mapa inválida
- Mapas irresolubles (sin camino válido)

## 📈 Rendimiento

- **Renderizado en Tiempo Real**: Juego a 60 FPS
- **Eficiencia de Memoria**: Huella de memoria mínima
- **Carga Rápida de Mapas**: Algoritmos de análisis optimizados
- **Controles Responsivos**: Manejo de entrada de baja latencia

## 🔗 Enlaces

- **Autora**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repositorio**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 🏆 Logro

**Puntuación Final**: 100/100 ✨

---

*Este proyecto fue completado como parte del currículo de 42 School en 42 Málaga.*
