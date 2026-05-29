# Penúltima versión estable de Alpine
FROM alpine:3.18

# Instalamos PHP y WP-CLI (instalador por línea de comandos oficial de WP)
# 'mariadb-client' es clave para que wp-cli pueda comprobar la conexión a la base de datos
RUN apk update && \
    apk add --no-cache \
    php81 \
    php81-fpm \
    php81-mysqli \
    php81-json \
    php81-curl \
    php81-dom \
    php81-exif \
    php81-fileinfo \
    php81-mbstring \
    php81-openssl \
    php81-xml \
    php81-zip \
    php81-phar \
    wget \
    mariadb-client
    # RUN apk hace una descarga de los paquetes y luego los instala, 
    # por lo que no es necesario limpiar la caché manualmente.
    # \ es para continuar el comando en la siguiente línea, lo que mejora la legibilidad.
    # apk add hace ambas cosas en un solo comando, lo que es más eficiente.
    # Si se hicieran en comandos separados, la caché de apk se llenaría con los archivos 
    # descargados, lo que aumentaría el tamaño de la imagen final.
    # Además, al usar --no-cache, apk no guarda los archivos descargados en la caché, 
    # lo que también ayuda a mantener la imagen más ligera.
    # Los paquetes php81-* son las dependencias necesarias para que WordPress funcione.
    # wget es necesario para descargar wp-cli e instalar WordPress.
    # mariadb-client es clave para que wp-cli pueda conectar y gestionar la base de datos MariaDB.

# Descargar wp-cli e instalarlo globalmente
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp
    # wget descarga el binario wp-cli.phar desde el repositorio de GitHub oficial.
    # chmod +x le otorga permisos de ejecución al archivo descargado.
    # mv mueve y renombra el archivo al directorio binario estándar de Alpine,
    # con el nombre corto 'wp', haciéndolo accesible desde cualquier lugar.

# Archivo de configuración que enlaza el puerto 9000
COPY conf/www.conf /etc/php81/php-fpm.d/www.conf
    # COPY envía el archivo de nuestro host al contenedor durante el despliegue.
    # El archivo 'www.conf' está preconfigurado para indicarle a PHP-FPM 
    # que escuche peticiones en el puerto 9000 (el que enlazará NGINX por FastCGI).

# Carpeta principal donde vivirá WordPress (coincidirá con el volumen a compartir)
RUN mkdir -p /var/www/wordpress && \
    chown -R nobody:nobody /var/www/wordpress
    # mkdir -p pre-crea la estructura de carpetas web.
    # chown asume al usuario 'nobody' (un usuario con escasos privilegios por defecto en Linux)
    # la propiedad de estos directorios, una buena práctica de seguridad.

# Copiar nuestro script mágico a la imagen
COPY tools/wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/wordpress.sh
    # Copiamos el entrypoint (.sh) a la carpeta bin global del contenedor 
    # y nos aseguramos de que sea ejecutable mediante el comando chmod.

# Exponemos el puerto 9000 para FastCGI
EXPOSE 9000
    # EXPOSE le indica al daemon de Docker que este contenedor oirá el tráfico por 
    # el puerto 9000. NGINX pasará los scripts .php a este puerto usando FastCGI.

# El entrypoint mantendrá todo con vida
CMD ["/usr/local/bin/wordpress.sh"]
    # CMD es el comando final a ejecutar al arrancar el contenedor.
    # Mediante este script, descargaremos WP-CLI, iniciaremos nuestra BD
    # y arrancaremos php-fpm en el plano frontal (foreground) para mantener este contenedor en marcha.