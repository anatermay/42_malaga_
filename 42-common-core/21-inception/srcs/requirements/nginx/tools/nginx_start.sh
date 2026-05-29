#!/bin/sh

# Reemplazamos las directivas de configuración usando expresiones regulares anchas (.*)
# Esto asegura que la sustitución sea destructiva e idempotente, por lo que no importa
# si el servicio se reinicia y el dominio ya había sido inyectado antes: siempre forzará el del .env.
sed -i "s|server_name .*|server_name ${DOMAIN_NAME};|g" /etc/nginx/http.d/default.conf
sed -i "s|ssl_certificate .*|ssl_certificate ${CERTS_CRT};|g" /etc/nginx/http.d/default.conf
sed -i "s|ssl_certificate_key .*|ssl_certificate_key ${CERTS_KEY};|g" /etc/nginx/http.d/default.conf
# Con esto, cada vez que NGINX se levanta, "lee" la variable de tu .env (sea tu login, evaltester, 
# o lo que pongas) y re-escribe el interior del archivo de configuración de forma segura. 100% a prueba de fallos.

# Verificamos si el certificado ya fue generado para no reescribirlo cada vez
if [ ! -f "${CERTS_CRT}" ]; then
    echo "NGINX: Generando certificados SSL auto-firmados para ${DOMAIN_NAME}..."
    
    # Creamos un certificado self-signed válido por 1 año usando OpenSSL sin pedir datos interactivos (-subj)
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout "${CERTS_KEY}" \
        -out "${CERTS_CRT}" \
        -subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=42/CN=${DOMAIN_NAME}/UID=${CURRENT_USER}"
        # openssl req es el comando para generar certificados y claves.
        # -x509 indica que queremos un certificado auto-firmado.
        # -nodes significa "no DES", lo que indica que la clave privada no estará cifrada 
        # con una contraseña, lo que es necesario para que nginx pueda leerla sin intervención humana.
        # -days 365 establece la validez del certificado en 365 días.
        # -newkey rsa:2048 genera una nueva clave RSA de 2048 bits.
        # -keyout especifica la ruta donde se guardará la clave privada.
        # -out especifica la ruta donde se guardará el certificado.
        # -subj permite proporcionar toda la información del certificado en una sola línea, 
        # evitando el modo interactivo.
        # Debemos sustituir los valores de C, ST, L, O, OU, CN y UID por los datos que correspondan 
        # a nuestro dominio y organización.
        # C=ES: País (Country)
        # ST=Madrid: Estado o provincia (State or Province)
        # L=Madrid: Localidad (Locality)
        # O=42: Organización (Organization)
        # OU=42: Unidad organizativa (Organizational Unit)
        # CN=${DOMAIN_NAME} para que openssl firme el certificaddo con el el nombre local y con el 
        # usuario de sistema...
        # UID=login42: Identificador de usuario (User ID), que es un campo opcional pero puede 
        # ser útil para identificar el propietario del certificado.
        # Cambiaremos estos valores por los que correspondan a nuestro dominio y organización,
        # asegurándonos de que el CN coincida con el dominio que vamos a usar para evitar problemas 
        # de confianza en los navegadores.
        # login debe ser el mismo que indicamos en el .env para el dominio, ya que el certificado 
        # debe coincidir con el dominio que vamos a usar.
    
    echo "NGINX: Certificados SSL creados de forma exitosa."
fi

# Ejecutamos nginx en modo primer plano para que el contenedor de Docker no se muera.
echo "NGINX: Iniciando el servidor web en primer plano..."

# Por defecto nginx es un demonio (background), pero Docker requiere un proceso activo (foreground).
exec nginx -g "daemon off;"
    # con nginx -h estamos diciendo a nginx que ejecute el comando "daemon off", 
    # lo que hace que nginx se ejecute en primer plano.
    # daemon off es una directiva de nginx que le indica que no se ejecute como 
    # un proceso en segundo plano (daemon), sino que permanezca en primer plano. 
    # Esto es necesario en un entorno de contenedores como Docker, ya que el contenedor 
    # se detendrá si el proceso principal (nginx) termina. 
    # Al mantener nginx en primer plano, el contenedor seguirá activo mientras nginx 
    # esté funcionando.