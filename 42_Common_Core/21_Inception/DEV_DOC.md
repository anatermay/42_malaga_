
<i>
	<p>
		This project has been created as part of the 42 curriculum by <b>aternero</b>.
	</p>
</i>

# # DEV_DOC: Inception - Development and Evaluation Guide

El proyecto Inception es un ejercicio de aprendizaje que forma parte del currículo de 42, una escuela de programación. Este proyecto se centra en la creación y gestión de una infraestructura web utilizando tecnologías de contenedores, específicamente Docker. El objetivo principal del proyecto es proporcionar a los estudiantes la oportunidad de aprender y aplicar conceptos clave relacionados con la administración de sistemas y el desarrollo de aplicaciones web en un entorno de contenedores.

Este archivo de documentación de desarrollo (DEV_DOC) tiene como objetivo proporcionar una guía detallada para los desarrolladores que trabajan en el proyecto Inception, así como para aquellos que están interesados en aprender sobre la creación y gestión de infraestructuras web utilizando Docker. En este documento, se describirán los pasos necesarios para configurar el entorno de desarrollo, construir y lanzar la infraestructura web utilizando Docker Compose, gestionar los contenedores y volúmenes de Docker, y garantizar la persistencia de datos en la infraestructura web del proyecto Inception.

Se proporcionarán instrucciones detalladas sobre cómo configurar el entorno de desarrollo, incluyendo la instalación de Docker y Docker Compose, así como la configuración de las variables de entorno necesarias para el proyecto. Además, se describirán los comandos necesarios para construir y lanzar la infraestructura web utilizando Docker Compose, así como los comandos para gestionar los contenedores y volúmenes de Docker. También se explicará cómo garantizar la persistencia de datos en la infraestructura web del proyecto Inception, lo que es fundamental para asegurar que los datos de la aplicación web se mantengan incluso después de reiniciar los contenedores o la infraestructura web.

## 1. Introduction and Basic Concepts

Inception es un proyecto de aprendizaje que forma parte del currículo de 42, una escuela de programación. Este proyecto se centra en la creación y gestión de una infraestructura web utilizando tecnologías de contenedores, específicamente Docker. El objetivo principal del proyecto es proporcionar a los estudiantes la oportunidad de aprender y aplicar conceptos clave relacionados con la administración de sistemas y el desarrollo de aplicaciones web en un entorno de contenedores.

En este proyecto, se utilizarán varias tecnologías y conceptos clave, incluyendo Docker, Docker Compose, contenedores, volúmenes de Docker, redes de Docker y variables de entorno. Docker es una plataforma de contenedores que permite a los desarrolladores crear, desplegar y gestionar aplicaciones en contenedores. Docker Compose es una herramienta que permite definir y ejecutar aplicaciones multi-contenedor utilizando un archivo de configuración YAML. Los contenedores son unidades ligeras y portátiles que contienen todo lo necesario para ejecutar una aplicación, incluyendo el código, las dependencias y la configuración. Los volúmenes de Docker son áreas de almacenamiento persistente que pueden ser utilizadas por los contenedores para almacenar datos. Las redes de Docker permiten la comunicación entre contenedores y con el mundo exterior. Las variables de entorno son valores configurables que pueden ser utilizados por las aplicaciones para personalizar su comportamiento.

Se implementará una infraestructura web que incluye un servidor web NGINX, una base de datos MariaDB y una aplicación web WordPress. La infraestructura web se configurará utilizando Docker Compose, lo que permitirá a los desarrolladores construir y lanzar la infraestructura de manera eficiente y sencilla. Además, se garantizará la persistencia de datos utilizando volúmenes de Docker, lo que asegurará que los datos de la aplicación web se mantengan incluso después de reiniciar los contenedores o la infraestructura web.

## 2. Prerequisites and Environment (.env)

Los prerrequisitos para el proyecto Inception incluyen la instalación de Docker y Docker Compose en el entorno de desarrollo. Docker es una plataforma de contenedores que permite a los desarrolladores crear, desplegar y gestionar aplicaciones en contenedores, mientras que Docker Compose es una herramienta que permite definir y ejecutar aplicaciones multi-contenedor utilizando un archivo de configuración YAML. Para configurar el entorno de desarrollo, es necesario crear un archivo `.env` en el directorio raíz del proyecto Inception. Este archivo se utilizará para definir las variables de entorno necesarias para la configuración de la infraestructura web del proyecto Inception.

Las variables de entorno que se deben definir en el archivo `.env` incluyen la contraseña de root para la base de datos MariaDB, el nombre de la base de datos, el usuario y la contraseña para acceder a la base de datos, así como cualquier otra variable de entorno necesaria para configurar los servicios de NGINX, MariaDB y WordPress. Estas variables de entorno serán utilizadas por los servicios en el archivo `docker-compose.yml` para configurar correctamente la infraestructura web del proyecto Inception. Es importante asegurarse de que el archivo `.env` esté correctamente configurado y que las variables de entorno estén definidas con valores adecuados para garantizar el correcto funcionamiento de la infraestructura web del proyecto Inception.

> Nota: Es fundamental mantener el archivo `.env` seguro y no compartirlo públicamente, ya que contiene información sensible como contraseñas y credenciales de acceso a la base de datos. Se recomienda agregar el archivo `.env` al archivo `.gitignore` para evitar que se suba al repositorio de código fuente. Además, este archivo se genera automáticamente a partir de un archivo `.env.example` que se proporciona en el proyecto, lo que facilita la configuración del entorno de desarrollo para los desarrolladores que trabajan en el proyecto Inception. No se sube al repositorio para evitar la exposición de información sensible y para permitir a cada desarrollador configurar su propio entorno de desarrollo de manera segura y personalizada.

## 3. Project Architecture and Structure

Sobre la arquitectura y estructura del proyecto Inception, se ha diseñado una infraestructura web que incluye un servidor web NGINX, una base de datos MariaDB y una aplicación web WordPress. La infraestructura web se configura utilizando Docker Compose, lo que permite a los desarrolladores construir y lanzar la infraestructura de manera eficiente y sencilla. La estructura del proyecto se organiza de la siguiente manera:

```
inception/
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
├── Makefile
├── srcs/
│   ├── docker-compose.yml
|   ├── requirements/
|   |   ├──mariadb/
|   |   |   ├── Dockerfile
|   |   |   ├── conf/
|   |   |   |   ├── 50-server.cnf
|   |   |   ├── tools/
|   |   |   |   ├── mariadb.sh
|   |   ├──nginx/
|   |   |   ├── Dockerfile
|   |   |   ├── conf/
|   |   |   |   ├── nginx.conf
|   |   |   ├── tools/
|   |   |   |   ├── nginx_start.sh
|   |   ├──wordpress/
|   |   |   ├── Dockerfile
|   |   |   ├── conf/
|   |   |   |   ├── www.conf
|   |   |   ├── tools/
|   |   |   |   ├── wordpress.sh
```

* `README.md`: Este archivo contiene la descripción general del proyecto Inception, incluyendo los objetivos, la arquitectura y las decisiones técnicas tomadas durante el desarrollo del proyecto.
* `USER_DOC.md`: Este archivo contiene la guía de usuario para el proyecto Inception, proporcionando instrucciones detalladas sobre cómo configurar, construir y lanzar la infraestructura web, así como cómo monitorear y gestionar la infraestructura.
* `DEV_DOC.md`: Este archivo contiene la guía de desarrollo para el proyecto Inception, proporcionando instrucciones detalladas para los desarrolladores sobre cómo configurar el entorno de desarrollo, construir y lanzar la infraestructura web utilizando Docker Compose, gestionar los contenedores y volúmenes de Docker, y garantizar la persistencia de datos en la infraestructura web del proyecto Inception.
* `Makefile`: Este archivo contiene las reglas de Make para automatizar la construcción y el lanzamiento de la infraestructura web del proyecto Inception utilizando Docker Compose.
* `srcs/`: Este directorio contiene los archivos de configuración y los Dockerfiles necesarios para construir los servicios de NGINX, MariaDB y WordPress, así como el archivo `docker-compose.yml` que define la configuración de la infraestructura web del proyecto Inception.

## 4. Orchestration: Makefile and Docker Compose

La orquestación de la infraestructura web del proyecto Inception se realiza utilizando Docker Compose, lo que permite a los desarrolladores definir y ejecutar aplicaciones multi-contenedor de manera eficiente. El archivo `docker-compose.yml` se encuentra en el directorio `srcs/` y define la configuración de los servicios de NGINX, MariaDB y WordPress, incluyendo las imágenes de Docker a utilizar, las variables de entorno, los volúmenes y las redes necesarias para la comunicación entre los servicios.

Recordamos que Docker Compose es una herramienta que permite definir y ejecutar aplicaciones multi-contenedor utilizando un archivo de configuración YAML. En el caso del proyecto Inception, el archivo `docker-compose.yml` define los servicios necesarios para la infraestructura web, incluyendo el servidor web NGINX, la base de datos MariaDB y la aplicación web WordPress. Cada servicio se configura con las imágenes de Docker correspondientes, las variables de entorno necesarias para su funcionamiento, los volúmenes para la persistencia de datos y las redes para la comunicación entre los servicios.

Además, se ha creado un archivo `Makefile` en el directorio raíz del proyecto Inception para automatizar la construcción y el lanzamiento de la infraestructura web utilizando Docker Compose. El `Makefile` contiene reglas para construir las imágenes de Docker, lanzar los contenedores y limpiar los recursos utilizados por la infraestructura web del proyecto Inception. Estas reglas permiten a los desarrolladores ejecutar comandos simples para gestionar la infraestructura web de manera eficiente y sin tener que recordar comandos complejos de Docker Compose.

En concreto, se puede hacer uso de las siguientes reglas desde el directorio raíz del proyecto:

* `make all`: Prepara todo, incluyendo la configuración del entorno, y construye y levanta los contenedores.
* `make up`: Construye y levanta la infraestructura de contenedores.
* `make down`: Detiene la infraestructura y elimina los contenedores.
* `make start`: Inicia los contenedores previamente pausados o detenidos.
* `make stop`: Pausa temporalmente los contenedores activos.
* `make status`: Muestra los procesos y el estado de los contenedores.
* `make env`: Fuerza la creación manual de un nuevo archivo `srcs/.env` llamando al script de configuración.
* `make clean`: Borra las imágenes, redes huérfanas y contenedores creados creados por Docker Compose.
* `make fclean`: Realiza un purgado total, eliminando los volúmenes de datos persistentes y el archivo `srcs/.env`, además de hacer una limpieza del sistema Docker.
* `make re`: Reconstruye y levanta toda la infraestructura desde cero.
* `make test`: Ejecuta el test automático para comprobar el proyecto de forma automática.
* `make eval`: Lanza un asistente interactivo para la evaluación del proyecto.

## 5. Resilience and Data Persistence

La **resiliencia** es la capacidad de un sistema para recuperarse rápidamente de fallos o interrupciones, manteniendo su funcionalidad y rendimiento. En el contexto del proyecto Inception, la resiliencia se logra mediante el uso de contenedores Docker, que permiten aislar los servicios y garantizar que cada uno de ellos pueda reiniciarse automáticamente en caso de fallo.

Además, se pueden configurar políticas de reinicio en el archivo `docker-compose.yml` para asegurar que los contenedores se reinicien automáticamente si se detienen inesperadamente. Esto permite que la infraestructura web del proyecto Inception sea más robusta y capaz de recuperarse rápidamente de cualquier problema que pueda surgir.

Por su parte, la **persistencia de datos** se refiere a la capacidad de un sistema para mantener los datos almacenados incluso después de reiniciar o detener los servicios. En el proyecto Inception, la persistencia de datos se logra mediante el uso de volúmenes de Docker, que permiten almacenar los datos de la base de datos MariaDB y los archivos de WordPress en un almacenamiento persistente fuera de los contenedores. Esto garantiza que los datos se mantengan intactos incluso si los contenedores se reinician o se eliminan.

Los volúmenes de Docker son áreas de almacenamiento persistente que pueden ser utilizadas por los contenedores para almacenar datos. En el proyecto Inception, se utilizan volúmenes para almacenar los datos de la base de datos MariaDB y los archivos de WordPress, lo que garantiza que los datos se mantengan intactos incluso después de reiniciar o detener los servicios.

En el archivo `docker-compose.yml`, se definen los volúmenes necesarios para cada servicio, lo que asegura que los datos importantes no se pierdan y que la infraestructura web del proyecto Inception pueda funcionar de manera continua sin interrupciones debido a la pérdida de datos.

## 6. Quick Assessment Guide

A continuación, se proporciona una guía rápida de evaluación para el proyecto Inception, que incluye los criterios clave que se deben tener en cuenta al evaluar la infraestructura web del proyecto:

1. **Configuración del entorno**: Verificar que el entorno de desarrollo esté correctamente configurado, incluyendo la instalación de Docker y Docker Compose, así como la configuración del archivo `.env` con las variables de entorno necesarias.
2. **Construcción y lanzamiento de la infraestructura**: Evaluar la capacidad para construir y lanzar la infraestructura web utilizando Docker Compose, asegurándose de que los servicios de NGINX, MariaDB y WordPress se inicien correctamente y estén funcionando.
3. **Gestión de contenedores y volúmenes**: Evaluar la capacidad para gestionar los contenedores y volúmenes de Docker, incluyendo la capacidad para iniciar, detener y eliminar contenedores, así como para gestionar los volúmenes de datos persistentes.
4. **Resiliencia y persistencia de datos**: Evaluar la capacidad para garantizar la resiliencia de la infraestructura web mediante la configuración de políticas de reinicio en Docker Compose, así como la capacidad para garantizar la persistencia de datos utilizando volúmenes de Docker.
5. **Documentación y claridad**: Evaluar la calidad de la documentación proporcionada, incluyendo la claridad de las instrucciones y la organización de la información en el archivo `DEV_DOC.md`, así como la calidad de la documentación general del proyecto en el archivo `README.md` y la guía de usuario en el archivo `USER_DOC.md`.

## 7. Provided Testers

Este proyecto incluye varios scripts de prueba que se pueden utilizar para evaluar la funcionalidad y el rendimiento de la infraestructura web del proyecto Inception. Estos scripts de prueba están diseñados para verificar que los servicios de NGINX, MariaDB y WordPress estén funcionando correctamente, así como para evaluar la resiliencia y la persistencia de datos en la infraestructura web del proyecto Inception.

El principal es `webcontent.sh`, que se utiliza para verificar que el contenido web se esté sirviendo correctamente a través del servidor NGINX. Este script realiza una solicitud HTTP al servidor NGINX y verifica que el contenido esperado se esté sirviendo correctamente. Además, se incluyen otros scripts de prueba como `test_auto.sh` y `test_eval.sh`, que se pueden utilizar para realizar pruebas automáticas y evaluaciones interactivas de la infraestructura web del proyecto Inception. Estos scripts de prueba son herramientas valiosas para los desarrolladores que trabajan en el proyecto Inception, ya que les permiten verificar la funcionalidad y el rendimiento de la infraestructura web de manera eficiente y efectiva, lo que es fundamental para garantizar el éxito del proyecto Inception y la satisfacción de los objetivos de aprendizaje establecidos en el currículo de 42.

Al ejecutar `./webcontent.sh`, el script se encarga de preparar todo el entorno de WordPress para que tenga contenido base con el que realizar las pruebas.

El script `webcontent.sh` automatiza la inyección de contenido inicial en WordPress. En concreto, realiza las siguientes acciones:
- Ejecuta `make re` para reiniciar y reconstruir toda la infraestructura desde cero.
- Se mantiene a la espera hasta verificar que el *core* de WordPress está completamente instalado a través del comando `wp core is-installed` utilizando `wp-cli` dentro del contenedor.
- Actualiza las URLs del sitio y del *home* (`siteurl` y `home`) de WordPress apuntando al dominio configurado (`https://aternero.42.fr`). Esto se incluye para evitar problemas de redirección y asegurar que el contenido se sirva correctamente a través del servidor NGINX.
- Crea automáticamente varias publicaciones (posts) haciendo referencia a la película Origen (Inception) a modo de contenido inicial (Regla Nº1, El Tótem, etc.).
- Finalmente, tras inyectar el contenido, muestra el estado de los contenedores con `docker ps` y ejecuta de forma secuencial los otros scripts de comprobación (`test_auto.sh` y `test_eval.sh`).

En segundo lugar, el script `test_auto.sh` se encarga de realizar una validación estricta, automatizada y pedagógica de toda la infraestructura. Actúa como un test de "abogado del diablo" para comprobar rigurosamente los requisitos del *subject* de Inception y la estricta hoja de evaluación de 42. Se divide en cinco fases principales:

- **Fase 1 (Estructura y Makefile)**: Verifica que los volúmenes existan físicamente en el directorio asociado del host (`/home/$USER/data/...`) y que el `Makefile` contenga todas las reglas obligatorias (`all`, `clean`, `fclean`, `re`, `down`).
- **Fase 2 (Normas anti-hacks)**: Revisa el `docker-compose.yml` y los `Dockerfiles` garantizando que las imágenes base sean Alpine o Debian. Se asegura de que no se usen directivas prohibidas (`network_mode: host`, `links`, tags `latest`) ni comandos trampa para forzar a mantener los contenedores vivos de forma artificial (como `tail -f`, `sleep infinity` o bucles `while true`).
- **Fase 3 (Red y Puertos)**: Comprueba la existencia de la red aislada de Docker, asegurando que el puerto 80 queda inaccesible (inhabilitado por seguridad), que únicamente se expone el puerto 443 para HTTPS, y certifica que los puertos internos de MariaDB (3306) y WordPress (9000) no son accesibles desde el host.
- **Fase 4 (SSL, WordPress y Base de Datos)**: Confirma que la negociación SSL se realiza bajo protocolos seguros (TLSv1.2 o TLSv1.3). Conecta con la base de datos para constatar que las tablas de WordPress existen (verificando la interconexión de contenedores) y de forma estricta inspecciona que el usuario administrador de WordPress no contravenga la normativa llamándose "admin" o "Admin".
- **Fase 5 (Persistencia Host-Guest)**: Somete a estrés los volúmenes mediante la creación de un archivo de prueba en MariaDB, procediendo a borrar por completo el contenedor, lanzándolo nuevamente (`make up`) y verificando que el dato ha persistido frente a una recreación del contenedor, certificando así la validez de los volúmenes expuestos.

En tercer lugar, el script `test_eval.sh` sirve como un asistente interactivo diseñado específicamente para acompañar al evaluador durante la corrección del proyecto (peer-evaluation). A diferencia del test automático, este script está basado exactamente en los criterios de la hoja de evaluación oficial de 42 (`en_eval.pdf`) y funciona pausando su ejecución paso a paso pidiendo confirmación al evaluador. De esta forma, permite verificar visualmente cada punto crítico:

- **1. Preliminares y Configuración general**: Comprueba que no hay contraseñas hardcodeadas en texto plano en los archivos de configuración y que el `Makefile` posee las reglas obligatorias exigidas por el *subject*.
- **2. Docker-Compose y Contenedores**: Verifica la creación de la red *bridge* en Docker asegurando el aislamiento, el uso de imágenes permitidas (Alpine o Debian) y certifica la ausencia de redes de anfitrión (`network_mode: host`) o comandos prohíbidos en los *entrypoints* (como bucles de espera infinitos).
- **3. NGINX, WordPress y MariaDB**: Guía al evaluador para comprobar la negociación segura con TLS (v1.2/1.3), validar las normativas de nombre en los perfiles *admin* de WordPress, y corroborar el flujo de conexión verificando que la base de datos aloja de manera efectiva las tablas del CMS.
- **4. Prueba Final (Persistencia)**: Automatiza frente a los ojos del evaluador la auténtica prueba de fuego del proyecto: generar un archivo virtual de validación en la base de datos, tumbar de manera agresiva todos los contenedores con un `make down`, levantar el sistema otra vez mediante `make up`, y constatar de manera verídica y transparente la recuperación de aquel documento a través de los volúmenes del sistema.

---
<br>
<div align="center">
<bottom style="background-color: #c0c0c0; color: #000000; padding: 10px; border: 1px solid #640dad;">README</bottom> |
<bottom style="background-color: #c0c0c0; color: #000000; padding: 10px; border: 1px solid #640dad;">USER_DOC</bottom> |
<bottom style="background-color: #640dad; color: #c0c0c0; padding: 10px; border: 1px solid #c0c0c0;">DEV_DOC</bottom>
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
		This file must describe how a developer can:
		<ul>
			<li>Set up the environment from scratch.</li>
			<li>Build and launch the project using the Makefile and Docker Compose.</li>
			<li>Use relevant commands to manage the containers and volumes.</li> 
			<li>Identify where the project data is stored and how it persists.
			</li>
		</ul>
	</p>
</i>