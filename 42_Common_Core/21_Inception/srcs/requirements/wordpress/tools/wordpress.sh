#!/bin/sh

cd /var/www/wordpress

# Definir cómo invocar WP-CLI (php81 es el binario disponible en esta imagen)
WP_CLI="php81 -d memory_limit=512M /usr/local/bin/wp --allow-root"

# Descargar y configurar si no existe el fichero base
if [ ! -f "wp-config.php" ]; then
    echo "Descargando ficheros base de WordPress..."
    $WP_CLI core download
    $WP_CLI config create \
        --dbname=${WORDPRESS_DB_NAME} \
        --dbuser=${WORDPRESS_DB_USER} \
        --dbpass=${WORDPRESS_DB_PASSWORD} \
        --dbhost=${WORDPRESS_DB_HOST}
fi

# Bucle de espera vital (Ping): WordPress necesita que MariaDB esté 100% operativo y que haya
# terminado su instalación de tablas principal. El 'depends_on' sólo verifica inicialización.
# Separar este step de la descarga impide brikeos durante fallos de energía o evaluadores impacientes.
echo "Pausando la instalación: Esperando a que MariaDB esté totalmente accesible..."
while ! mariadb -h mariadb -u${WORDPRESS_DB_USER} -p${WORDPRESS_DB_PASSWORD} ${WORDPRESS_DB_NAME} -e "SELECT 1" >/dev/null 2>&1; do
    sleep 2
done
echo "¡MariaDB responde! Verificando estado de instalación del núcleo..."

# Verificación a prueba de balas: Sólo volcará el contenido inicial si wp-cli constata
# que no hay rastro de instalación previa dentro de la propia base de datos remota.
if ! $WP_CLI core is-installed; then
    echo "Instalando tablas en la base de datos..."
    $WP_CLI core install \
        --url=https://${WORDPRESS_URL} \
        --title="${WORDPRESS_TITLE}" \
        --admin_user=${WORDPRESS_ADMIN_USER} \
        --admin_password=${WORDPRESS_ADMIN_PASSWORD} \
        --admin_email=${WORDPRESS_ADMIN_EMAIL}

    $WP_CLI user create ${WORDPRESS_USER} ${WORDPRESS_USER_EMAIL} \
        --role=author \
        --user_pass=${WORDPRESS_USER_PASSWORD}
    echo "WordPress fue instalado y configurado correctamente."
else
    echo "WordPress ya estaba instalado plenamente en la base de datos."
fi

chown -R nobody:nobody /var/www/wordpress
chmod -R 755 /var/www/wordpress

echo "Iniciando PHP-FPM..."
exec php-fpm81 -F
