# Penúltima versión estable exigida
FROM alpine:3.18

# Instalar MariaDB y su cliente sin almacenar caché
RUN apk update && apk upgrade && \
    apk add --no-cache mariadb mariadb-client
    # RUN apk hace una descarga de los paquete y luego los instala, 
    # por lo que no es necesario limpiar la caché manualmente.
    # \ es para continuar el comando en la siguiente línea, lo que mejora la legibilidad.
    # apk add hace ambas cosas en un solo comando, lo que es más eficiente.
    # Si se hicieran en comandos separados, la caché de apk se llenaría con los archivos 
    # descargados, lo que aumentaría el tamaño de la imagen final.
    # Además, al usar --no-cache, apk no guarda los archivos descargados en la caché, 
    # lo que también ayuda a mantener la imagen más ligera.
    # mariadb y mariadb-client son los paquetes necesarios para instalar el servidor de 
    # base de datos MariaDB y su cliente, respectivamente.

# Crear el directorio necesario para el socket (.sock) y para los logs de errores
# donde MariaDB guarda su archivo de proceso local y el error.log, si no, el contenedor falla.
RUN mkdir -p /run/mysqld /var/log/mysql; \
    chown -R mysql:mysql /run/mysqld /var/log/mysql

# Copiar nuestro archivo de configuración personalizado
COPY conf/50-server.cnf /etc/my.cnf.d/mariadb-server.cnf

# Copiar el script de inyección de configuración y convertirlo en ejecutable
COPY tools/mariadb.sh /bin/mariadb.sh
RUN chmod +x /bin/mariadb.sh

# Exponemos el puerto estándar 3306 (esto sirve de información entre contenedores)
EXPOSE 3306

# Nuestro entrypoint: la ejecución nunca debe morir para que el contenedor siga "Up"
CMD ["mariadb.sh"]