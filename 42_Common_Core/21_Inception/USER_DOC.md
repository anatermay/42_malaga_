
<i>
	<p>
		This project has been created as part of the 42 curriculum by <b>aternero</b>.
	</p>
</i>

# # USER_DOC: Inception - User Guide

El proyecto Inception es un ejercicio de aprendizaje que forma parte del currículo de 42, una escuela de programación. Este proyecto se centra en la creación y gestión de una infraestructura web utilizando tecnologías de contenedores, específicamente Docker. El objetivo principal del proyecto es proporcionar a los estudiantes la oportunidad de aprender y aplicar conceptos clave relacionados con la administración de sistemas y el desarrollo de aplicaciones web en un entorno de contenedores.

El propósito de este documento es servir como una guía de usuario para el proyecto Inception, proporcionando instrucciones claras y detalladas sobre cómo desplegar, gestionar y utilizar la infraestructura web creada en el proyecto. A través de esta guía, los usuarios podrán comprender los servicios proporcionados por la infraestructura, configurar el entorno de manera adecuada, acceder a los servicios y monitorear su funcionamiento para garantizar que todo esté funcionando correctamente. Además, se incluirán ejemplos de uso y testers para verificar el correcto funcionamiento de cada servicio, lo que facilitará la experiencia del usuario y garantizará el éxito del proyecto Inception.

## 1. Provided Services

El proyecto Inception proporciona una infraestructura web que incluye los siguientes servicios:
1. **NGINX**: Un servidor web que actúa como un proxy inverso para manejar las solicitudes HTTP y HTTPS, proporcionando una capa de seguridad y rendimiento para la aplicación web.
2. **MariaDB**: Un sistema de gestión de bases de datos relacional que se utiliza para almacenar y gestionar los datos de la aplicación web, proporcionando una solución de almacenamiento eficiente y segura.
3. **WordPress**: Un sistema de gestión de contenido (CMS) que se utiliza para crear y gestionar el sitio web de la aplicación, proporcionando una plataforma fácil de usar para la creación y gestión de contenido web.

## 2. Set up the infrastructure

El proceso de configuración de la infraestructura web del proyecto Inception implica varios pasos clave que deben seguirse para garantizar un despliegue exitoso. A continuación, se detallan los pasos necesarios para configurar la infraestructura:
1. **Clonar el repositorio**: El primer paso es clonar el repositorio del proyecto Inception en tu Máquina Virtual. Esto se puede hacer utilizando el comando `git clone` seguido de la URL del repositorio.
2. **Navegar al directorio del proyecto**: Una vez que hayas clonado el repositorio, debes navegar al directorio del proyecto utilizando el comando `cd` seguido del nombre del directorio del proyecto.
3. **Construir y desplegar los contenedores**: Para construir y desplegar los contenedores de NGINX, MariaDB y WordPress, debes ejecutar el comando `docker-compose up -d` desde el directorio del proyecto. Este comando utilizará el archivo `docker-compose.yml` para construir y desplegar los contenedores de manera eficiente.
4. **Verificar el despliegue**: Después de ejecutar el comando de despliegue, es importante verificar que los contenedores estén funcionando correctamente. Puedes hacer esto utilizando el comando `docker ps` para listar los contenedores en ejecución y asegurarte de que los contenedores de NGINX, MariaDB y WordPress estén activos y funcionando sin problemas.

## 3. Configure the environment

La configuración del entorno para el proyecto Inception implica la gestión de variables de entorno y la configuración de los servicios para garantizar que la infraestructura web funcione correctamente. A continuación, se detallan los pasos necesarios para configurar el entorno:
1. **Configurar variables de entorno**: Es importante configurar las variables de entorno necesarias para cada servicio, como las credenciales de la base de datos para MariaDB y las configuraciones de NGINX. Esto se puede hacer utilizando un archivo `.env` o configurando las variables de entorno directamente en el archivo `docker-compose.yml`.
2. **Configurar NGINX**: Asegúrate de que la configuración de NGINX esté correctamente establecida para manejar las solicitudes HTTP y HTTPS, y que esté configurado para actuar como un proxy inverso para la aplicación web.
3. **Configurar MariaDB**: Verifica que la configuración de MariaDB esté correctamente establecida para permitir la conexión desde WordPress y que las credenciales de la base de datos estén correctamente configuradas.
4. **Configurar WordPress**: Asegúrate de que la configuración de WordPress esté correctamente establecida para conectarse a la base de datos de MariaDB y que esté configurado para funcionar correctamente con NGINX.

Al realizar 'make all' verá lo siguiente:

```bash


╔══════════════════════════════════════════════════════════════════════════════╗
║                          INCEPTION MANDATORY                                 ║
║                  Generador de Entorno e Infraestructura                      ║
║                 ----------------------------------------                     ║
║                       Diseñado para Evaluación 42                            ║
╚══════════════════════════════════════════════════════════════════════════════╝

Iniciando el proceso de configuración guiado.
(Pulsa INTRO en cada paso si deseas utilizar el valor sugerido entre corchetes)

[1/4] 🌐 Configuración del Servidor Web
──────────────────────────────────────────────────
Dominio local [aternero.42.fr]: 
Ruta certificado crt [/etc/nginx/ssl/aternero.crt]: 
Ruta clave privada key [/etc/nginx/ssl/aternero.key]: 
✓ NGINX y Dominio configurados.

[2/4] 🗄️  Configuración de Base de Datos
──────────────────────────────────────────────────
Nombre BD [wordpress]: 
Usuario BD [wpuser]: 
Contraseña de Usuario BD [***]: 
Contraseña ROOT de MariaDB [***]: 
✓ MariaDB configurado.

[3/4] 📝 Configuración de CMS (WordPress)
──────────────────────────────────────────────────
Nombre del Sitio [Inception Project - aternero]: 
Administrador [supervisor]: 
Contraseña Administrador [***]: 
Mail Administrador [supervisor@aternero.42.fr]: 
Segundo Usuario [aternero]: 
Contraseña de aternero [***]: 
Mail de aternero [aternero@aternero.42.fr]: 
✓ WordPress configurado.

[4/4] ⚙️  Procesando e Inyectando Variables
──────────────────────────────────────────────────
✓ Archivo srcs/.env generado exitosamente.

```

Este proceso de configuración guiado te permitirá establecer los parámetros necesarios para cada servicio de manera interactiva, asegurando que la infraestructura web del proyecto Inception esté configurada correctamente para su despliegue y funcionamiento óptimo. Si deseas utilizar los valores sugeridos, simplemente pulsa INTRO en cada paso para aceptar los valores predeterminados, o ingresa tus propios valores personalizados según tus necesidades. Al finalizar el proceso de configuración, el archivo `.env` se generará automáticamente con las variables de entorno necesarias para el despliegue de la infraestructura web.

## 4. Access the services

El acceso a los servicios proporcionados por la infraestructura web del proyecto Inception se realiza a través de la URL configurada durante el proceso de configuración. Para acceder a los servicios, sigue los siguientes pasos:
1. **Acceder a la URL**: Abre un navegador web y navega a la URL configurada durante el proceso de configuración, como `https://aternero.42.fr/`. Asegúrate de utilizar el protocolo HTTPS para acceder a la URL, ya que NGINX está configurado para manejar solicitudes HTTPS utilizando el certificado SSL proporcionado.
	> **Nota**: Es posible que el navegador muestre una advertencia de seguridad debido a que el certificado SSL es autofirmado. Esto es normal y esperado en este caso, ya que el certificado no está emitido por una autoridad de certificación reconocida. Puedes proceder a ignorar la advertencia y continuar accediendo al sitio web de WordPress.
2. **Iniciar sesión en WordPress**: Para acceder al panel de administración de WordPress, navega a `https://aternero.42.fr/wp-login.php` e inicia sesión utilizando las credenciales de administrador configuradas durante el proceso de configuración. Una vez que hayas iniciado sesión, podrás gestionar tu sitio web de WordPress, crear contenido, instalar plugins y personalizar tu sitio según tus necesidades.
	> **Nota**: Asegúrate de utilizar las credenciales correctas para iniciar sesión en WordPress, ya que el acceso al panel de administración es esencial para gestionar tu sitio web de manera efectiva. En '.env' se encuentran las credenciales de administrador y usuario normal que configuraste durante el proceso de configuración bajo los nombres `WP_ADMIN_USER`, `WP_ADMIN_PASSWORD`, `WP_USER` y `WP_USER_PASSWORD`. Para iniciar sesión, utiliza el nombre de usuario y la contraseña correspondientes a tu cuenta de administrador o usuario normal según tus necesidades: WP_ADMIN_USER y WP_ADMIN_PASSWORD para el administrador, o WP_USER y WP_USER_PASSWORD para el usuario normal.
3. **Verificar la conexión a la base de datos**: Para verificar que WordPress esté correctamente conectado a la base de datos de MariaDB, puedes acceder al panel de administración de WordPress y verificar que los datos se estén almacenando correctamente en la base de datos. También puedes utilizar herramientas como phpMyAdmin o la línea de comandos de MariaDB para verificar la conexión y el estado de la base de datos.
	> Para acceder a la base de datos de MariaDB, puedes utilizar el comando `docker exec -it <nombre_del_contenedor_mariadb> mysql -u <usuario_bd> -p` para ingresar a la línea de comandos de MariaDB y verificar la conexión utilizando las credenciales configuradas durante el proceso de configuración.
	> 1. Utiliza el comando 'docker exec -it mariadb mysql -u root -p' para acceder a la línea de comandos de MariaDB.
	> 2. Ingresa la contraseña de root configurada durante el proceso de configuración: `MYSQL_ROOT_PASSWORD`.
	> 3. Una vez que hayas ingresado a la línea de comandos de MariaDB, puedes utilizar comandos como `SHOW DATABASES;`, `USE <nombre_de_la_bd>;` y `SHOW TABLES;` para verificar que la base de datos esté correctamente configurada y que los datos se estén almacenando correctamente.
		> a. `SHOW DATABASES;` para listar las bases de datos disponibles.
		> b. `USE <nombre_de_la_bd>;` para seleccionar la base de datos de WordPress.
		> c. `SHOW TABLES;` para listar las tablas dentro de la base de datos de WordPress y verificar que estén correctamente configuradas.
	> **Nota**: Asegúrate de utilizar las credenciales correctas para acceder a la base de datos de MariaDB, ya que el acceso a la base de datos es esencial para el funcionamiento correcto de WordPress y para gestionar los datos de tu sitio web de manera efectiva. Además, los mensajes no aparecerán hasta que el administrador haya aprobado la publicación de los comentarios, lo que es parte del proceso de moderación de WordPress para garantizar la calidad y seguridad del contenido publicado en tu sitio web.

## 5. Interact with the application

La interacción con la aplicación web desplegada en el proyecto Inception se realiza principalmente a través del panel de administración de WordPress. A continuación, se detallan algunos ejemplos de cómo interactuar con la aplicación:
1. **Crear y gestionar contenido**: Una vez que hayas iniciado sesión en el panel de administración de WordPress, puedes crear y gestionar contenido para tu sitio web. Esto incluye la creación de entradas de blog, páginas, categorías y etiquetas, así como la gestión de medios como imágenes y videos. Puedes utilizar el editor de WordPress para dar formato a tu contenido, agregar enlaces, insertar imágenes y personalizar la apariencia de tu sitio web.
2. **Instalar y configurar plugins**: WordPress ofrece una amplia variedad de plugins que puedes instalar para agregar funcionalidades adicionales a tu sitio web. Puedes acceder a la sección de plugins en el panel de administración de WordPress para buscar, instalar y configurar plugins según tus necesidades. Esto te permite personalizar tu sitio web y agregar características como formularios de contacto, galerías de imágenes, optimización SEO y mucho más.
3. **Personalizar la apariencia del sitio web**: WordPress también ofrece una amplia variedad de temas que puedes utilizar para personalizar la apariencia de tu sitio web. Puedes acceder a la sección de temas en el panel de administración de WordPress para buscar, instalar y activar temas según tus preferencias. Esto te permite cambiar el diseño, los colores, las fuentes y la disposición de tu sitio web para que se adapte a tu estilo y necesidades.
4. **Gestionar usuarios y permisos**: En el panel de administración de WordPress, puedes gestionar los usuarios de tu sitio web y asignarles diferentes roles y permisos. Esto te permite controlar quién tiene acceso a qué partes de tu sitio web y qué acciones pueden realizar. Puedes agregar nuevos usuarios, editar los perfiles de los usuarios existentes y asignarles roles como administrador, editor, autor o suscriptor según sus responsabilidades y necesidades.

## 6. Monitor and shut down the infrastructure

Para monitorear y gestionar la infraestructura web del proyecto Inception, puedes utilizar los siguientes comandos de Docker para verificar el estado de los contenedores, revisar los logs y gestionar los recursos de Docker:
1. **Listar contenedores en ejecución**: Utiliza el comando `docker ps` para listar los contenedores que están actualmente en ejecución. Esto te permitirá verificar que los contenedores de NGINX, MariaDB y WordPress estén activos y funcionando correctamente.
2. **Revisar logs de los contenedores**: Utiliza el comando `docker logs <nombre_del_contenedor>` para revisar los logs de un contenedor específico. Esto te permitirá identificar posibles errores o problemas en los servicios y tomar las medidas necesarias para solucionarlos.
3. **Listar volúmenes de Docker**: Utiliza el comando `docker volume ls` para listar los volúmenes de Docker disponibles. Esto te permitirá verificar que el volumen utilizado para la persistencia de datos de MariaDB esté correctamente configurado y funcionando.
4. **Listar redes de Docker**: Utiliza el comando `docker network ls` para listar las redes de Docker disponibles. Esto te permitirá verificar que la red personalizada 'inception' esté correctamente configurada y funcionando para permitir la comunicación entre los contenedores.
5. **Apagar la infraestructura**: Para apagar la infraestructura web, puedes utilizar el comando `docker-compose down` desde el directorio del proyecto. Esto detendrá y eliminará los contenedores, redes y volúmenes asociados a la infraestructura web del proyecto Inception, permitiéndote liberar los recursos utilizados por la infraestructura cuando ya no los necesites.

## 7. Provided Testers

La infraestructura web del proyecto Inception incluye varios testers que se pueden utilizar para verificar el correcto funcionamiento de cada servicio y proporcionar resultados detallados sobre el estado de cada servicio. A continuación, se detallan los testers proporcionados en el proyecto:

El tester `webcontent.sh` se utiliza para verificar el contenido web de la aplicación desplegada en el proyecto Inception. Este script realiza una serie de pruebas para verificar que el contenido web esté correctamente configurado y accesible a través de la URL configurada. El tester proporciona resultados detallados sobre el estado del contenido web y cualquier error o problema que pueda haber sido identificado durante las pruebas, lo que facilita la identificación y solución de problemas relacionados con el contenido web de la aplicación desplegada en el proyecto Inception.

```bash
$ ./webcontent.sh
```

Además, este tester llama a los dos aneriores, por lo que se puede ejecutar directamente para verificar tanto el correcto funcionamiento de los servicios como el contenido web de la aplicación desplegada en el proyecto Inception.

---


<br>
<div align="center">
<bottom style="background-color: #c0c0c0; color: #000000; padding: 10px; border: 1px solid #640dad;">README</bottom> |
<bottom style="background-color: #640dad; color: #c0c0c0; padding: 10px; border: 1px solid #c0c0c0;">USER_DOC</bottom> |
<bottom style="background-color: #c0c0c0; color: #000000; padding: 10px; border: 1px solid #640dad;">DEV_DOC</bottom>
<br>
<br>
<p>   </p>
<p>   </p>
<p>   </p>
<hr>
<i>
	<p>
		This document is a System Administration related exercise.
	</p>
	<p>
		This file must explain, in clear and simple terms, how an end user or administrator can:
		<ul>
			<li>Understand what service are provided by the stack.</li>
			<li>Start and stop the project.</li>
			<li>Access the website and the administration panel.</li> 
			<li>Locate and manage credentials.
			</li>
			<li>Check that the services are running correctly.</li>
		</ul>
	</p>
</i>
