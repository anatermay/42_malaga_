# so_long

## graphics

### illustrations.c

#### load_sprites() - Carga las texturas y sprites.
#### render_sprites() - Dibuja los sprites en la pantalla.
#### draw_player() - Dibuja al jugador en su posición.
#### draw_enemy() - Dibuja los enemigos en el mapa.
#### unload_graphics() - Libera recursos gráficos al final.

### perspective.c

#### update_position() - Calcula nuevas posiciones de los objetos.
#### adjust_perspective() - Ajusta la perspectiva de la cámara.
#### move_object() - Mueve un objeto en la pantalla.
#### set_viewport() - Establece el área visible de la pantalla.
#### reset_perspective() - Restaura la perspectiva inicial.

## header_file

### so_long.h

#### define_player() - Define las propiedades del jugador.
#### declare_sprites() - Declara los sprites y texturas.
#### create_map() - Crea el mapa del juego.
#### define_collision() - Define las colisiones del jugador.
#### declare_game_variables() - Declara las variables del juego.

## mechanics

### character_arc.c

#### move_player() - Mueve al jugador según entradas de teclado.
#### check_collision() - Verifica si el jugador colisiona con objetos.
#### handle_death() - Maneja la lógica de muerte del jugador.
#### pick_up_item() - Lógica para recoger objetos.
#### animate_player() - Controla las animaciones del jugador.

### narrative.c

#### check_victory() - Verifica si el jugador ha ganado.
#### trigger_event() - Activa eventos de la narrativa.
#### update_score() - Actualiza la puntuación del jugador.
#### display_message() - Muestra mensajes narrativos al jugador.
#### reset_game() - Reinicia el juego después de una victoria o derrota.

### turning_pages.c

#### handle_key_input() - Maneja las teclas presionadas.
#### pause_game() - Pausa el juego.
#### close_game() - Cierra la ventana del juego.
#### resume_game() - Reanuda el juego después de pausar.
#### update_game_state() - Actualiza el estado del juego.

## resources

### editorial.c

#### print_error() - Imprime mensajes de error.
#### show_warning() - Muestra advertencias en consola.
#### print_debug() - Imprime mensajes de depuración.
#### display_message() - Muestra mensajes generales.
#### log_to_file() - Registra mensajes en un archivo de log.

### epilogue.c

#### free_resources() - Libera recursos al final del juego.
#### close_window() - Cierra la ventana del juego correctamente.
#### save_game_state() - Guarda el estado del juego.
#### display_end_screen() - Muestra la pantalla de fin de juego.
#### reset_game_variables() - Reinicia las variables del juego.

### foot_notes.c

#### log_info() - Registra información útil durante la ejecución.
#### handle_warnings() - Maneja y muestra advertencias.
#### process_input() - Procesa la entrada del jugador.
#### cleanup_memory() - Limpia la memoria utilizada.
#### print_summary() - Imprime un resumen del juego.

## gnl

### get_next_line.c

#### read_line() - Lee una línea del archivo.
#### handle_buffer() - Maneja el búfer para la lectura de archivos.
#### return_line() - Devuelve la línea leída.
#### clean_buffer() - Limpia el búfer tras leer una línea.
#### close_file() - Cierra el archivo después de leer.

## libft

### libft.c

#### ft_strlen() - Calcula la longitud de una cadena.
#### ft_strcpy() - Copia una cadena de caracteres.
#### ft_memalloc() - Asigna memoria dinámica.
#### ft_strcmp() - Compara dos cadenas.
#### ft_itoa() - Convierte un número entero en una cadena.

## settings

### prologue.c

#### initialize_game() - Inicializa las variables y parámetros del juego.
#### setup_window() - Configura la ventana del juego.
#### set_background() - Establece el fondo de la ventana.
#### set_colors() - Define los colores de la interfaz.
#### configure_game() - Configura la lógica general del juego.

### worldbuilding.c

#### load_map() - Carga el mapa desde un archivo.

The `load_map` function is designed to load a map from a file and validate its structure for a game. It takes a single parameter, a pointer to a `t_play` structure, which contains game-related data, including the path to the map file (`game->ber`).

The function begins by declaring three local variables: `read` (a pointer to a character array), `fd` (an integer for the file descriptor), and `length` (an integer to store the length of each line read from the file). It then attempts to open the map file in read-only mode using the `open` function. If the file cannot be opened (i.e., `fd` is less than 0), it prints an error message "ERROR: Map file not open" and returns `NULL`.

Next, the function reads the first line of the map file using the `get_next_line` function and stores it in `read`. It calculates the length of this line using the `str_lenght` function (note the typo, which should be `str_length`). The function then enters a `while` loop that continues as long as `read` is not `NULL`.

Within the loop, the function checks if the current line of the map is a valid rectangle using the `rectangle_check` function. If this check fails (i.e., returns `FAILURE`), the function returns `FAILURE`. If the check passes, the function processes the current line by calling `cell_to_map`, which presumably updates the game state with the map data. The function then reads the next line from the file.

After all lines have been read and processed, the function closes the file using the `close` function and returns the path to the map file (`game->ber`). This function ensures that the map is properly loaded and validated before being used in the game. However, it contains a typo in the `str_lenght` function call, which should be corrected to `str_length` to avoid compilation errors. Additionally, the function should handle memory deallocation for `read` to prevent memory leaks.

#### validate_map() - Valida la estructura del mapa.

The `validate_map` function in the provided C code is designed to validate a map represented as a string. It takes two parameters: a pointer to a character array `read` and an integer `length`. The function performs two main checks to ensure the validity of the map.

First, it checks if the length of the string `read` is less than or equal to zero or if the first character of the string is a newline character (`'\n'`). This is done using the `str_length` function, which presumably returns the length of the string. If either condition is true, it indicates that the map is empty or starts with an empty line. In this case, the function prints an error message "ERROR: Empty Line.", frees the allocated memory for `read` using `free(read)`, and exits the program with a failure status (`FAILURE`).

Second, the function checks if the length of the string `read` is not equal to the expected `length`. This is again done using the `str_length` function. If the lengths do not match, it indicates that the map is not a rectangle, meaning the rows of the map do not have consistent lengths. In this case, the function prints an error message "Error: Map is not a rectangle.", frees the allocated memory for `read`, and exits the program with a failure status.

It is important to note that there is a typo in the second call to `str_length`, where it is written as `str_lenght`. This typo would cause a compilation error since the function name would not be recognized. Additionally, the function does not return any value, even though its return type is `int`. This should be corrected to ensure proper function behavior.

### map_extension

The `map_extension` function is designed to check if a given file name has the `.ber` extension, which is likely required for map files in the context of the game. It takes a single parameter, `argv`, which is a pointer to a character array representing the file name.

The function begins by declaring an integer variable `index` and initializing it to 0. This variable is used to iterate through each character in the file name. The function then enters a `while` loop that continues until the end of the string is reached (i.e., until `argv[index]` is equal to the null terminator `'\0'`).

Within the loop, the function checks if the current character is a dot (`'.'`). If a dot is found, it further checks the subsequent characters to see if they match the sequence "ber" and are followed by the null terminator. Specifically, it checks if `argv[index + 1]` is 'b', `argv[index + 2]` is 'e', `argv[index + 3]` is 'r', and `argv[index + 4]` is the null terminator. If all these conditions are met, the function returns `SUCCESS`, indicating that the file has the correct `.ber` extension.

If the loop completes without finding the `.ber` extension, the function returns `FAILURE`, indicating that the file does not have the required extension. This function ensures that only files with the correct extension are processed as map files in the game.

#### check_obstacles() - Verifica los obstáculos en el mapa.
#### render_map() - Dibuja el mapa en la pantalla.
#### unload_map() - Libera la memoria del mapa.

# Otros Archivos

## Makefile
## README.md
## SoftwareDevelopmentDocumentation.md
## so_long.c

### main() - Función principal que inicializa y ejecuta el juego.
### initialize_game() - Inicializa las variables y configura el juego.
### game_loop() - El bucle principal del juego que maneja las entradas y actualizaciones.
### render_frame() - Dibuja la pantalla y actualiza la vista del juego.
### close_game() - Cierra el juego correctamente, liberando recursos.