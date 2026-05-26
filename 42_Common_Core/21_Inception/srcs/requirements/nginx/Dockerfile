# Penúltima versión estable exigida por Inception
FROM alpine:3.18

# Instalamos nginx y openssl, evitando almacenar archivos de caché para hacer la imagen más ligera
RUN apk update && apk upgrade && \
    apk add --no-cache nginx openssl
    # RUN apk hace una descarga de los paquetes y luego los instala, 
    # por lo que no es necesario limpiar la caché manualmente.
    # \ es para continuar el comando en la siguiente línea, lo que mejora la legibilidad.
    # apk add hace ambas cosas en un solo comando, lo que es más eficiente.
    # Si se hicieran en comandos separados, la caché de apk se llenaría con los archivos 
    # descargados, lo que aumentaría el tamaño de la imagen final.
    # Además, al usar --no-cache, apk no guarda los archivos descargados en la caché, 
    # lo que también ayuda a mantener la imagen más ligera.
    # nginx es el servidor web y proxy inverso que usaremos.
    # openssl es la librería necesaria para generar y gestionar los certificados SSL/TLS.

# Creamos las carpetas necesarias para almacenar los certificados SSL y el archivo de proceso de nginx
RUN mkdir -p /etc/nginx/ssl /run/nginx
    # mkdir -p crea los directorios si no existen, incluyendo sus parent (directorios padres).
    # /etc/nginx/ssl alojará los certificados TLS autogenerados.
    # /run/nginx es donde NGINX normalmente aloja su archivo .pid cuando se ejecuta.

# Copiamos nuestro archivo de configuración local a la carpeta de NGINX en Alpine
COPY conf/nginx.conf /etc/nginx/http.d/default.conf
    # COPY envía archivos desde nuestro host (máquina real) al interior del contenedor durante el build (construcción).
    # Ocupamos el lugar de 'default.conf' para sobrescribir directamente la configuración que NGINX carga por defecto en Alpine.

# Copiamos nuestro script mágico para generar el certificado temporal y lanzar la aplicación
COPY tools/nginx_start.sh /usr/local/bin/nginx_start.sh

# Le damos permisos de ejecución a nuestro script
RUN chmod +x /usr/local/bin/nginx_start.sh
    # chmod +x vuelve al script un ejecutable. Sin este paso, el contenedor no tendría permisos para ejecutar el script y crashearía.

# Declaramos al plano de Docker que NGINX escuchará solo en el 443 tcp
EXPOSE 443
    # EXPOSE le indica a Docker y a otros contenedores en la red Inception en qué puerto escucha este contenedor internamente.
    # No publica el puerto al host de por sí, actúa como documentación de la imagen.

# Declaramos el ENTRYPOINT de la aplicación para que genere el SSL y lance el servidor
CMD ["/usr/local/bin/nginx_start.sh"]
    # CMD es el comando que ejecutará finalmente el contenedor al arrancar (o "Up").
    # Al pasarlo en este formato de array de strings (exec form), Docker no invoca una shell intermedia y lanza este proceso como PID 1 limpio.