#!/bin/sh
# Usamos /bin/sh porque Alpine Linux no tiene bash instalado por defecto.

# Comprobamos si la base de datos del sistema ya está inicializada en el volumen
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Inicializando base de datos MariaDB..."

    # Asigna los permisos correctos al usuario de sistema mysql sobre la carpeta de datos
    chown -R mysql:mysql /var/lib/mysql

    # mariadb-install-db instala las tablas base estructuradas del sistema de MariaDB.
    # --rpm anula el setup de archivos de ejemplo innecesarios para Alpine.
    mariadb-install-db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null

    # Este bloque inyecta en lenguaje SQL las variables de nuestro archivo .env.
    # --bootstrap arranca el demonio de DB sin red, ejecuta el input por stdin (<< EOF) y luego se cierra. Es la forma más limpia y segura.
    mysqld --user=mysql --bootstrap << EOF
USE mysql;
FLUSH PRIVILEGES;

-- Borrar usuarios anónimos por seguridad
DELETE FROM mysql.user WHERE User='';

-- Bloquear el acceso root desde fuera del contenedor local
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

-- Cambiar contraseña de root por la nuestra del .env
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

-- Crear la base de datos para WordPress si no existe
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8 COLLATE utf8_general_ci;

-- Crear nuestro usuario de WordPress de forma segura (IF NOT EXISTS evita crasheos tontos)
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
-- Concederle acceso pleno solo a su base de datos
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';

-- Aplicar los cambios
FLUSH PRIVILEGES;
EOF
    echo "Base de datos creada y securizada exitosamente."
else
    # Si la carpeta /var/lib/mysql/mysql ya existe significa que el volumen persistente de nuestro host
    # ya tiene datos de una ejecución interior, por tanto, nos ahorramos re-crearlo.
    echo "Base de datos ya existente en el volumen persistente. Saltando inicialización..."
fi

# Arrancar el demonio normal de MariaDB en primer plano (consola) para que no muera el contenedor.
# exec sustituye el proceso de la terminal (PID 1) por mysqld, para que Docker pueda apagarlo limpiamente (SIGTERM).
echo "Arrancando MariaDB..."
exec mysqld --user=mysql --console