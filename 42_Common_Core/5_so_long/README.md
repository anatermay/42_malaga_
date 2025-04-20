
<div align="center">
	<img src="https://github.com/anatermay/anatermay/blob/main/png/anatermay_header.png" alt="anatermay_github_header_img" width="100%" height="max-content">
</div>
<p align="right" style="font-family: Georgia, 'Times New Roman', Times, serif; font-style: bold; font-size: medium;">
	<i><b>Escritora y Desarrolladora en Formación</b></i>
</p>
<div style="box-shadow: 0 3px 9px 0 #C0C0C0; padding: 16px;">
	<p style="color: #000000; font-family: Georgia, 'Times New Roman', Times, serif; font-size: medium; text-shadow: #640DAD;">¡Hola, soy Ana Ternero Mayorga! 👋 </p>
</div>
<p style="text-align: justify;">Comparto mi viaje en la programación mientras disfruto de la literatura. Este perfil es una ventana a mi progreso, donde comparto mis proyectos y aprendizajes.</p>
<ul>
	<li>Estudiante de programación en lenguaje C en <a href="">42</a>.</li>
	<li>Interesada en Desarrollo Web.</li>
</ul>
<p align="right">
	<b>@anatermay | <i>login: aternero</i></b>
	<a href="https://www.linkedin.com/in/ana-ternero-mayorga/" target="_blank"><img alt="LinkedIn" width="22px" src="https://cdn.jsdelivr.net/npm/simple-icons@v3/icons/linkedin.svg" /></a>
	<a href="https://www.instagram.com/anatermay.git/" target="_blank"><img alt="Instagram" width="22px" src="https://cdn.jsdelivr.net/npm/simple-icons@v3/icons/instagram.svg" /></a>
	<a href="https://profile.intra.42.fr/users/aternero"><img src="https://camo.githubusercontent.com/540caa3799b39a03c6118679241ccbced4c68cab167992bf8b995de53d85c8c4/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4dc3a16c6167612d626c61636b3f7374796c653d666c6174266c6f676f3d3432266c6f676f436f6c6f723d7768697465"></a>
</p>
<p align="center" width="100%">
	<!--- <a href="https://github.com/anatermay/anatermay/blob/main/README-en.md"><img src="https://github.com/anatermay/anatermay/blob/main/png/english.png"></a> --->
	<a href="https://github.com/anatermay/anatermay/blob/main/README.md"><img src="https://github.com/anatermay/anatermay/blob/main/png/spanish.png"></a>
	<a href="https://www.instagram.com/anatermay.git"><img src="https://github.com/anatermay/anatermay/blob/main/png/instagram.png"></a>
	<a href="https://www.threads.com/anatermay/"><img src="https://github.com/anatermay/anatermay/blob/main/png/threads.png"></a>
	<a href="https://www.linkedin.com/in/ana-ternero-mayorga/"><img src="https://github.com/anatermay/anatermay/blob/main/png/linkedin.png"></a>
	<a href="https://www.42malaga.com/"><img src="https://github.com/anatermay/anatermay/blob/main/png/42.png"></a>
</p>


# SO_LONG

<img src="./screenshot.png"><img style="width: 180px; height: 180px" src="./character.png">

## Descripción

so_long es un proyecto de juego 2D del currículo de 42. Enseña a los estudiantes sobre el desarrollo de juegos utilizando C y la biblioteca gráfica MLX42. El objetivo es navegar por un mapa, recoger todos los coleccionables y llegar a la salida en la menor cantidad de movimientos posible. El juego debe validar mapas, gestionar movimientos del jugador y renderizar el estado del juego usando MLX42.

## Dependencias

Este proyecto requiere la biblioteca **MLX42**. Puedes encontrar las instrucciones de instalación en su repositorio de GitHub: MLX42.

## Instalación

1. Clona este repositorio
2. Instala MLX42 siguiendo sus instrucciones.
3. Asegúrate de tener make y gcc instalados.

## Uso

1. Selecciona un tema: El juego incluye tres temas gráficos: fbaa_img, zombie_img y schrodinger_img. Para usar un tema, renombra la carpeta correspondiente a img. Asegúrate de que solo una carpeta se llame img a la vez. Por ejemplo:
	* Para el tema fbaa: mv fbaa_img img
	* Para el tema zombie: mv zombie_img img
	* Para el tema schrodinger: mv schrodinger_img img
2. Compila el proyecto: Ejecuta make para generar el ejecutable.
3. Ejecuta el juego: Usa ./so_long maps/map.ber, reemplazando map.ber con el archivo de mapa deseado de la carpeta maps.
4. Limpieza:
	* make clean para eliminar archivos objeto.
	* make fclean para eliminar el ejecutable y archivos objeto.
	* make re para recompilar todo (equivalente a make fclean && make all).

## Jugabilidad

* Controles: Usa las teclas de flecha o WASD para mover al jugador hacia arriba, abajo, izquierda o derecha.
* Objetivo: Recoge todos los coleccionables (representados por C en el mapa) antes de poder salir por la salida (representada por E).
* Conteo de movimientos: El número de movimientos se muestra en la terminal.
* Salir del juego: Presiona ESC o cierra la ventana.
* Mapas: Los mapas deben estar en formato .ber y ubicarse en la carpeta maps. Para jugar, ejecuta *./so_long maps/level_1_5.ber*.

## Temas

El juego soporta tres temas gráficos, aunque no sean lo más aesthetic del mundo, cada uno con imágenes en formato PNG:

* fbaa: Tema con gráficos personalizados con inspiración en De Sangre y Cenizas.
* zombie: Tema con gráficos de estilo zombie.
* schrodinger: Tema con gráficos inspirados en el gato de schrödinger.

Para cambiar de tema, renombra la carpeta deseada a img.

_NOTA:_ Se incluye referencia a One Piece.

## Solución de problemas

* Error de imágenes faltantes: Asegúrate de que una de las carpetas de imágenes (fbaa_img, zombie_img o schrodinger_img) esté correctamente renombrada como img.
* Error de mapa inválido: Verifica que el archivo de mapa exista en la carpeta maps y esté correctamente formateado. Un mapa válido debe:
  * Ser rectangular.
  * Estar rodeado de paredes (1).
  * Contener exactamente una posición inicial del jugador (P).
  * Contener al menos un coleccionable (C).
  * Contener una salida (E).

## Notas adicionales

* Verificación de fugas de memoria: Para asegurarte de que no hay fugas de memoria, ejecuta el juego con valgrind: valgrind ./so_long maps/map.ber.
* Compatibilidad de plataformas: El juego está diseñado para Linux y macOS.
* Sin características bonus: Este proyecto no incluye características bonus como animaciones, contadores de movimientos en pantalla o enemigos.
* Estructura del código: El código fuente está organizado en varios archivos C, cada uno manejando aspectos como el análisis de mapas, la lógica del juego y el renderizado gráfico.


<p align="right">
	<b>@anatermay | <i>login: aternero</i></b>
	<a href="https://www.linkedin.com/in/ana-ternero-mayorga/" target="_blank"><img alt="LinkedIn" width="22px" src="https://cdn.jsdelivr.net/npm/simple-icons@v3/icons/linkedin.svg" /></a>
	<a href="https://www.instagram.com/anatermay.git/" target="_blank"><img alt="Instagram" width="22px" src="https://cdn.jsdelivr.net/npm/simple-icons@v3/icons/instagram.svg" /></a>
</p>
