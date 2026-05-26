*This project has been created as part of the 42 curriculum by aternero.*

*This document is a System Administration related exercise.*

# Inception

## 1. Description

Bienvenido a **Inception**, un proyecto de la red 42 centrado en la administración de sistemas. El objetivo principal es desplegar una pequeña infraestructura web utilizando **contenedores**. 

> **42** es una red de escuelas de programación que ofrece una educación innovadora y gratuita. En este proyecto, se espera que los estudiantes apliquen sus conocimientos en administración de sistemas para configurar y gestionar una infraestructura web utilizando tecnologías de contenedores.

La **administración de sistemas** es una disciplina que se encarga de la gestión y mantenimiento de los sistemas informáticos. En este proyecto, se espera que los estudiantes apliquen sus conocimientos en administración de sistemas para configurar y gestionar una infraestructura web utilizando tecnologías de contenedores.

* La **infraestructura web** se refiere a los componentes y servicios necesarios para alojar y operar un sitio web.
* Los **contenedores** son una tecnología de virtualización que permite empaquetar una aplicación y sus dependencias en un entorno aislado. Esto facilita la implementación y gestión de aplicaciones, ya que los contenedores pueden ejecutarse de manera consistente en diferentes entornos. Por ejemplo, Docker es una plataforma popular para crear y gestionar contenedores.
* Una **aplicación** es un programa o conjunto de programas diseñados para realizar una función específica. Por ejemplo, una aplicación web puede ser un sitio de comercio electrónico o una plataforma de redes sociales.
* Una **dependencia** es un componente o biblioteca que una aplicación necesita para funcionar correctamente. Por ejemplo, una aplicación web puede depender de un servidor web, una base de datos y un sistema de autenticación.

Para entender esto mejor, imagina que estamos construyendo un castillo en Minecraft.
* La infraestructura web sería el terreno y los materiales que necesitamos para construir el castillo.
* Los contenedores serían como las habitaciones del castillo, cada una con su función específica (dormitorio, cocina, sala de estar).
* La aplicación sería el castillo completo.
* Las dependencias serían los muebles y decoraciones dentro de cada habitación.

Toda la infraestructura se despliega de manera automatizada y aislada del sistema operativo anfitrión, lo que garantiza una mayor seguridad y facilidad de gestión. Esto significa que los servicios pueden ser fácilmente iniciados, detenidos y gestionados sin afectar al sistema operativo subyacente, lo que es especialmente útil para el desarrollo y la producción de aplicaciones web.

Para lograr esto, hemos utilizado:
* **NGINX**: Un servidor web que actúa como un proxy inverso para dirigir el tráfico a los servicios adecuados. En otras palabras, NGINX es como el portero del castillo que decide a qué habitación dirigir a los visitantes.
* **MariaDB**: Un sistema de gestión de bases de datos que almacena la información de la aplicación. Es como el archivo del castillo donde se guarda toda la información importante.
* **WordPress**: Un sistema de gestión de contenido (CMS) que permite crear y administrar el sitio web de manera sencilla. Es como el diseñador de interiores del castillo que se encarga de decorar las habitaciones y hacer que el castillo sea atractivo para los visitantes.

### 1.1. Virtual Machines vs Docker

En primer lugar, una **Máquina Virtual** es un entorno de computación que emula un sistema operativo completo. Es como tener una computadora dentro de otra computadora. Por ejemplo, puedes tener una Máquina Virtual con Linux ejecutándose en tu computadora con Windows. Esto te permite ejecutar aplicaciones y servicios que son compatibles con Linux sin afectar a tu sistema operativo principal.

Por su parte, **Docker** es una plataforma de contenedores que permite empaquetar aplicaciones y sus dependencias en un entorno aislado. Es como tener una caja mágica donde puedes colocar tu aplicación y todo lo que necesita para funcionar. Esta caja puede ser transportada y ejecutada en cualquier lugar sin preocuparte por las diferencias entre los sistemas operativos. Sin embargo, Docker no se ejecuta directamente en el sistema operativo anfitrión, sino que requiere de una capa de virtualización para funcionar. Esto se debe a que Docker utiliza características del kernel del sistema operativo para gestionar los contenedores, y estas características no están disponibles en todos los sistemas operativos. Por lo tanto, es necesario utilizar una Máquina Virtual para ejecutar Docker y gestionar los contenedores de manera eficiente.

En resumen, las principales diferencias entre una Máquina Virtual y Docker son:
<table>
  <tr>
	<th>Aspecto</th>
	<th>Máquina Virtual</th>
	<th>Docker</th>
  </tr>
  <tr>
	<td>Virtualización</td>
	<td>Emula un sistema operativo completo</td>
	<td>Emplea contenedores para aislar aplicaciones</td>
  </tr>
  <tr>
	<td>Rendimiento</td>
	<td>Mayor consumo de recursos debido a la emulación completa</td>
	<td>Menor consumo de recursos al compartir el kernel del sistema operativo anfitrión</td>
  </tr>
  <tr>
	<td>Portabilidad</td>
	<td>Puedes ejecutar la Máquina Virtual en diferentes sistemas operativos, pero puede requerir ajustes y configuraciones adicionales.</td>
	<td>Los contenedores de Docker son altamente portátiles y pueden ejecutarse en cualquier lugar donde Docker esté instalado, sin necesidad de ajustes adicionales.</td>
  </tr>
  <tr>
	<td>Aislamiento</td>
	<td>Proporciona un aislamiento completo entre el sistema operativo anfitrión y la Máquina Virtual.</td>
	<td>Proporciona un aislamiento a nivel de aplicación, lo que significa que los contenedores comparten el mismo kernel del sistema operativo anfitrión.</td>
  </tr>
</table>

> *Nota: Un **kernel** es el componente central del sistema operativo que gestiona los recursos del hardware y proporciona una interfaz entre el hardware y los programas. Algunos ejemplos de kernels son Linux, Windows NT y macOS. La diferencia principal entre un kernel y un sistema operativo es que el kernel es la parte más fundamental del sistema operativo, mientras que el sistema operativo es un conjunto de programas que interactúan con el kernel.*

A pesar de sus diferencias, tanto las Máquinas Virtuales como Docker son herramientas valiosas para la administración de sistemas y el desarrollo de aplicaciones. La elección entre una u otra dependerá de las necesidades específicas del proyecto y del entorno en el que se esté trabajando. En este proyecto, se ha optado por utilizar Docker dentro de una Máquina Virtual para aprovechar las ventajas de ambas tecnologías y garantizar un entorno de desarrollo y producción eficiente y seguro.

### 1.2. Secrets vs Environment Variables

En el contexto de la administración de sistemas y el desarrollo de aplicaciones, es importante entender la diferencia entre **Secrets** y **Environment Variables**. Ambos son mecanismos para almacenar información sensible, pero tienen propósitos y características diferentes.

* **Secrets**: Son datos sensibles que se utilizan para proteger la información confidencial, como contraseñas, claves de API o certificados. Los Secrets se almacenan de manera segura y se acceden a través de mecanismos específicos, como gestores de secretos o servicios de almacenamiento seguro. Por ejemplo, en Docker, puedes utilizar Docker Secrets para almacenar y gestionar información sensible de manera segura. En nuestro proyecto, podríamos utilizar Secrets para almacenar la contraseña de la base de datos de MariaDB, asegurándonos de que esta información no esté expuesta en el código o en los archivos de configuración.

* **Environment Variables**: Son variables de entorno que se utilizan para configurar el comportamiento de una aplicación o servicio. Las Environment Variables pueden contener información sensible, pero no están diseñadas específicamente para proteger datos confidenciales. Por ejemplo, podríamos utilizar Environment Variables para configurar la URL de la base de datos en nuestra aplicación WordPress, pero no sería recomendable almacenar la contraseña de la base de datos como una Environment Variable, ya que podría ser expuesta accidentalmente. No obstante, las Environment Variables son útiles para configurar aspectos no sensibles de la aplicación, como el puerto en el que se ejecuta o el nivel de registro.

En resumen, la principal diferencia entre Secrets y Environment Variables es que los Secrets están diseñados específicamente para proteger información sensible, mientras que las Environment Variables son variables de entorno que pueden contener información sensible pero no están diseñadas para protegerla. Es importante utilizar el mecanismo adecuado para almacenar y gestionar la información sensible en tus aplicaciones y servicios para garantizar la seguridad y la integridad de tus datos.

### 1.3. Docker Network vs Host Network

En Docker, existen diferentes tipos de redes que se pueden utilizar para conectar los contenedores entre sí y con el host. Dos de las opciones más comunes son la **Docker Network** y la **Host Network**.

* **Docker Network**: Es una red virtual creada por Docker que permite a los contenedores comunicarse entre sí de manera aislada del host. Cada contenedor conectado a una Docker Network tiene su propia dirección IP y puede comunicarse con otros contenedores en la misma red utilizando sus nombres de host. Esto proporciona un nivel de aislamiento y seguridad, ya que los contenedores no pueden acceder directamente al host ni a otros contenedores fuera de la red. En nuestro proyecto, podríamos utilizar una Docker Network para conectar los contenedores de NGINX, MariaDB y WordPress, permitiendo que se comuniquen entre sí sin exponerlos al host.

* **Host Network**: Es una red que permite a los contenedores acceder directamente a la red del host. En este caso, los contenedores comparten la misma pila de red que el host, lo que puede proporcionar un mejor rendimiento en términos de comunicación, pero reduce el aislamiento y la seguridad. En nuestro proyecto, podríamos utilizar la Host Network para contenedores que necesiten un acceso directo y rápido a los recursos del host.

En resumen, la elección entre Docker Network y Host Network dependerá de las necesidades específicas de tu aplicación y del nivel de aislamiento y seguridad que desees. La Docker Network es una opción más segura y aislada, mientras que la Host Network puede ser útil para aplicaciones que requieren un acceso directo a los recursos del host. En nuestro proyecto, se ha optado por utilizar una Docker Network para garantizar un entorno de desarrollo y producción seguro y eficiente.

### 1.4. Docker Volumes vs Bind Mounts

En Docker, existen dos formas principales de gestionar el almacenamiento de datos: **Docker Volumes** y **Bind Mounts**.

* **Docker Volumes**: Son una forma de almacenamiento gestionada por Docker que se utiliza para persistir datos generados por los contenedores. Los Volumes se almacenan en una ubicación específica en el host y pueden ser compartidos entre múltiples contenedores. Docker se encarga de gestionar los Volumes, lo que facilita su uso y proporciona un nivel adicional de abstracción. En nuestro proyecto, podríamos utilizar un Docker Volume para almacenar los datos de la base de datos de MariaDB, asegurándonos de que los datos persistan incluso si el contenedor se reinicia o se elimina.

* **Bind Mounts**: Son una forma de almacenamiento que permite montar un directorio o archivo del host dentro de un contenedor. A diferencia de los Volumes, los Bind Mounts no son gestionados por Docker y dependen de la estructura de directorios del host.

## 2. Instructions

Las instrucciones para desplegar la infraestructura web del proyecto Inception se encuentran en el archivo <a href="USER_DOC.md">USER_DOC.md</a>. Este documento proporciona una guía paso a paso para configurar y ejecutar los contenedores de NGINX, MariaDB y WordPress, así como para verificar que la infraestructura esté funcionando correctamente. A continuación, se presenta un resumen de las secciones principales del documento:

### 2.1 Prerequisites

Los requisitos previos para ejecutar el proyecto Inception incluyen tener una Máquina Virtual con Debian instalada, así como tener Docker y Docker Compose instalados y configurados correctamente. Además, es necesario tener acceso a un navegador web para verificar el funcionamiento de la infraestructura web desplegada.

Si no tienes Docker y Docker Compose instalados, puedes seguir las instrucciones oficiales de Docker para instalar estas herramientas en tu sistema operativo. Asegúrate de seguir los pasos específicos para tu sistema operativo y de verificar que Docker y Docker Compose estén funcionando correctamente antes de continuar con el despliegue de la infraestructura web.

<bottom style="background-color: #c0c0c0; color: #000000; padding: 10px; border: 1px solid #640dad;"><a href="https://docs.docker.com/get-docker/" style="color: #000000;"><b> · PÁGINA OFICIAL DE DOCKER · </b></a></bottom>

### 2.2 Built and Deployment Instructions

En resumen, para desplegar la infraestructura web del proyecto Inception, debes seguir los siguientes pasos:
1. Clonar el repositorio del proyecto Inception en tu Máquina Virtual.
2. Navegar al directorio del proyecto y ejecutar el comando `docker-compose up -d` para construir y desplegar los contenedores de NGINX, MariaDB y WordPress.
3. Verificar que los contenedores estén funcionando correctamente utilizando el comando `docker ps` para listar los contenedores en ejecución.
4. Acceder a la URL `https://login42.42.fr/` (o `https://aternero.42.fr/` en tu caso) desde un navegador web para verificar que el sitio web de WordPress esté funcionando correctamente.

### 2.3 Verification and Testing (Local DNS)

Si quieres verificar y probar la infraestructura web desplegada en el proyecto Inception, puedes seguir los siguientes pasos:
1. Asegúrate de que los contenedores de NGINX, MariaDB y WordPress estén en ejecución utilizando el comando `docker ps`.
2. Accede a la URL `https://login42.42.fr/` (o `https://aternero.42.fr/` en tu caso) desde un navegador web para verificar que el sitio web de WordPress esté funcionando correctamente.
3. Si la URL no se reconoce, puedes intentar acceder a la dirección IP de la máquina virtual en lugar de la URL. Para encontrar la dirección IP de la máquina virtual, puedes utilizar el comando `ip addr` en la terminal de la máquina virtual y buscar la dirección IP asignada a la interfaz de red.
4. Si aún no puedes acceder al sitio web, asegúrate de que los puertos estén correctamente mapeados en el archivo `docker-compose.yml` y de que no haya conflictos de puertos con otros servicios en tu máquina virtual.
5. Si el sitio web se carga correctamente, puedes probar la funcionalidad de WordPress creando una cuenta de usuario, publicando una entrada de blog o personalizando el diseño del sitio web.

También se provee de tres *testers* en este repositorio para verificar el correcto funcionamiento de cada servicio. Estos *testers* son scripts que realizan pruebas específicas para cada servicio (NGINX, MariaDB y WordPress) y proporcionan resultados detallados sobre el estado de cada servicio.

* <a href="test_auto.sh"><b>test_auto.sh</b></a>: Este script realiza pruebas automáticas para verificar el funcionamiento general de la infraestructura web. Ejecuta pruebas para NGINX, MariaDB y WordPress, y proporciona un resumen de los resultados.
* <a href="test_eval.sh"><b>test_eval.sh</b></a>: Este script realiza pruebas específicas para evaluar el rendimiento y la funcionalidad de cada servicio. Proporciona resultados detallados sobre el estado de cada servicio y su rendimiento.
* <a href="webcontent.sh"><b>webcontent.sh</b></a>: Este script verifica el contenido del sitio web de WordPress para asegurarse de que se esté sirviendo correctamente. Comprueba la presencia de archivos y la configuración del sitio web. Además, genera contenidos de prueba para verificar que el sitio web esté funcionando correctamente. Este tester reinicia todo, por lo que es recomendable ejecutarlo al final de la verificación. Al ejecutar este script, se presupone que no se ha creado el directorio 'data' y que, por tanto, no se ha inicializado la base de datos de MariaDB. El script se encargará de crear el directorio 'data' y de inicializar la base de datos con los datos de prueba necesarios para verificar el funcionamiento del sitio web de WordPress.

## 3. Architectural decisions

Las decisiones arquitectónicas tomadas en el proyecto Inception se basan en la necesidad de crear una infraestructura web eficiente, segura y fácil de gestionar utilizando tecnologías de contenedores. A continuación, se detallan las principales decisiones arquitectónicas y las razones detrás de cada una de ellas.

### 3.1. Why we used Docker

El proyecto requiere del uso de **Docker** dentro de una Máquina Virtual. Esto se debe a que Docker es una tecnología de contenedores que permite empaquetar aplicaciones y sus dependencias en un entorno aislado, lo que facilita la implementación y gestión de aplicaciones. Sin embargo, Docker no se ejecuta directamente en el sistema operativo anfitrión, sino que requiere de una capa de virtualización para funcionar. Por lo tanto, es necesario utilizar una Máquina Virtual para ejecutar Docker y gestionar los contenedores de manera eficiente.

Además, el uso de Docker dentro de una Máquina Virtual permite aprovechar las ventajas de ambas tecnologías. La Máquina Virtual proporciona un entorno aislado y seguro para ejecutar Docker, mientras que Docker facilita la gestión y despliegue de aplicaciones en contenedores. Esto es especialmente útil para el desarrollo y la producción de aplicaciones web, ya que permite una mayor flexibilidad y escalabilidad.

En resumen, el uso de Docker dentro de una Máquina Virtual es una decisión arquitectónica que permite aprovechar las ventajas de ambas tecnologías y garantizar un entorno de desarrollo y producción eficiente y seguro para el proyecto Inception.

### 3.2. Why we used Secrets and Environment Variables

Si miramos el archivo <a href="docker-compose.yml">docker-compose.yml</a>, en el servicio de MariaDB, podemos ver que se utiliza un Secret para almacenar la contraseña de la base de datos:

```yaml
  mariadb:
    container_name: mariadb
    build: requirements/mariadb
    restart: always
    env_file: .env
    networks:
      - inception
    volumes:
      - mariadb:/var/lib/mysql
```

> 1. Nombramos explícitamente el contenedor porque la norma 42 lo exige y nos facilita los comandos 'docker exec' al no tener strings aleatorias.

> 2. Especificamos dónde reside el Dockerfile del que se construirá esta imagen.

> 3. 'restart: always' fuerza al contenedor a reiniciarse siempre si se crashea o el host (VM) se reinicia.

> 4. 'env_file: .env' indica que las variables de entorno para este servicio se cargarán desde el archivo '.env', lo que permite una gestión centralizada de la configuración.

> 5. 'networks: - inception' indica que este contenedor pertenece a una red personalizada llamada 'inception', lo que permite la comunicación entre los contenedores de esta red sin exponerlos al host.

> 6. 'volumes: - mariadb:/var/lib/mysql' enlaza el volumen persistente 'mariadb' al directorio interno del contenedor donde MariaDB de Alpine guarda lógicamente los datos tabulares, lo que garantiza que los datos de la base de datos se mantengan persistentes incluso si el contenedor se reinicia o se elimina.

En este proyecto se ha inyectado las credenciales únicamente a través de las variables de entorno usando 'env_file: .env' para evitar exponer información sensible en el código o en los archivos de configuración. Esto es una buena práctica de seguridad que ayuda a proteger la información confidencial y garantiza que las credenciales no estén expuestas accidentalmente.

Se ha optado por utilizar Environment Variables en lugar de Secrets para simplificar la configuración y el despliegue de la aplicación. Dado que este proyecto es un ejercicio de aprendizaje y no se trata de una aplicación en producción, se ha considerado que el uso de Environment Variables es suficiente para gestionar la configuración de la aplicación sin comprometer la seguridad. Sin embargo, en un entorno de producción, se recomienda encarecidamente utilizar Secrets para almacenar información sensible y garantizar la seguridad de la aplicación.

### 3.3. Why we used Docker Network instead of Host Network

Se está utilizando **Docker Network**. Específicamente, una red aislada de tipo *bridge* llamada 'inception' que se ha definido en el archivo <a href="docker-compose.yml">docker-compose.yml</a>.

La red tipo *bridge* es la opción predeterminada en Docker y proporciona un entorno de red aislado para los contenedores. Esto significa que los contenedores conectados a esta red pueden comunicarse entre sí utilizando sus nombres de host, pero no pueden acceder directamente al host ni a otros contenedores fuera de la red. Esta configuración proporciona un nivel adicional de seguridad y aislamiento, lo que es especialmente importante en un entorno de desarrollo y producción.

Además, el uso de una Docker Network facilita la gestión y el despliegue de los contenedores, ya que permite una comunicación eficiente entre ellos sin exponerlos al host.

* El *driver bridge* aisla los contenedores en uan red virtual. Los servicios internos no exponen sus puertos a la máquina anfitriona. Solo el contenedor *nginx* actúa como punto de entrada. En concreto, mapea el puerto 443.

* Al crear una red de Docker personalizada, *user-defined network*, Docker proporciona **resolución DNS automática** basándose en el nombre de los contenedores. De aquí que sea obligatorio, conforme a la norma de 42, nombrar explícitamente los contenedores. Esto facilita la comunicación entre los servicios, ya que pueden referenciarse entre sí por nombre en lugar de tener que usar direcciones IP, lo que mejora la legibilidad y mantenibilidad del código. Permite que el *script* de Wordpress se conecte a la base de datos de MariaDB simplemente llamando al *host* 'mariadb' en lugar de tener que usar una dirección IP, lo que hace que la configuración sea más sencilla y menos propensa a errores.

'Host Network`hace que todos los puertos se expongan tal y como si se ejecutaran nativamente en la máquina. La Norma de 42 prohíbe esta opción, ya que no es segura. En este caso, los servicios podrían acceder directamente al host y a otros contenedores fuera de la red, lo que podría comprometer la seguridad de la aplicación y del sistema en general.

En resumen, se ha optado por utilizar Docker Network en lugar de Host Network para garantizar un entorno de desarrollo y producción seguro y eficiente para el proyecto Inception.

### 3.4. Why we used Docker Volumes instead of Bind Mounts

Se ha optado por utilizar **Docker Volumes** en lugar de Bind Mounts para gestionar el almacenamiento de datos en el proyecto Inception. Los Docker Volumes son una forma de almacenamiento gestionada por Docker que proporciona un nivel adicional de abstracción y facilita su uso. Al utilizar Docker Volumes, se garantiza que los datos generados por los contenedores persistan incluso si el contenedor se reinicia o se elimina, lo que es esencial para la gestión de datos en aplicaciones web.

Además, los Docker Volumes son más fáciles de gestionar y compartir entre múltiples contenedores, lo que mejora la eficiencia y la flexibilidad en el desarrollo y despliegue de aplicaciones. En nuestro proyecto, se ha utilizado un Docker Volume para almacenar los datos de la base de datos de MariaDB, lo que garantiza que los datos se mantengan seguros y persistentes a lo largo del ciclo de vida de la aplicación.

## 4. Resources

* Debian: https://www.debian.org/
	> Debian es una distribución de Linux que se caracteriza por su estabilidad, seguridad y amplia comunidad de usuarios. Es una de las distribuciones más antiguas y populares, y es conocida por su enfoque en la calidad y la libertad del software. Debian es utilizado como base para muchas otras distribuciones de Linux, como Ubuntu, lo que demuestra su importancia en el ecosistema de Linux.
* Docker: https://www.docker.com/
	> Docker es una plataforma de software que permite empaquetar aplicaciones y sus dependencias en contenedores ligeros y portables. Facilita la creación, el despliegue y la gestión de aplicaciones en entornos virtualizados.
* Docker Network: https://docs.docker.com/network/
	> Docker Network es una característica de Docker que permite a los contenedores comunicarse entre sí y con el host. Proporciona diferentes tipos de redes, como bridge, host y overlay, para satisfacer las necesidades de comunicación de los contenedores.
* Docker Volume: https://docs.docker.com/storage/volumes/
	> Docker Volume es una característica de Docker que permite persistir datos generados por los contenedores. Los Volumes se almacenan en una ubicación específica en el host y pueden ser compartidos entre múltiples contenedores, lo que garantiza que los datos persistan incluso si el contenedor se reinicia o se elimina.
* Environment Variables: https://docs.docker.com/engine/reference/commandline/run/#set-environment-variables--e---env
	> Las variables de entorno son valores que se utilizan para configurar el entorno de ejecución de un programa. En Docker, se pueden establecer mediante el uso de la opción -e o --env.
* MariaDB: https://mariadb.org/
	> MariaDB es un sistema de gestión de bases de datos relacionales que es compatible con MySQL. Es utilizado como base de datos para almacenar los datos del sitio web.
* NGINX: https://www.nginx.com/
	> NGINX es un servidor web y proxy inverso que se utiliza para servir contenido estático y dinámico. En nuestro proyecto, se utiliza como punto de entrada para las solicitudes HTTP.
* WordPress: https://wordpress.org/
	> WordPress es una plataforma de gestión de contenidos basada en PHP y MySQL. Se utiliza para crear y gestionar sitios web dinámicos.

Las **imágenes** son plantillas preconfiguradas que se utilizan para crear contenedores en Docker. En nuestro proyecto, se han utilizado imágenes oficiales de NGINX, MariaDB y WordPress como base para construir nuestros contenedores personalizados. Estas imágenes proporcionan una configuración inicial que se puede personalizar según las necesidades del proyecto, lo que facilita el proceso de desarrollo y despliegue de la infraestructura web.

### 4.1. Graphical Environment

Las redes internas están aisladas, y no hay acceso al comando 'sudo' en los ordenadores de 42. De haberlo, podría modificarse el 'host'. Sin embargo, al tratar de acceder desde Google Chrome, nunca reconocía la URL que el *subject* espera que se reconozca: https://login42.42.fr/ o, en mi caso, **https://aternero.42.fr/**.

Para solucionar esto, he instalado un entorno gráfico de escritorio en la máquina virtual Debian. He usado comandos desde la consola. He optado por instalar un entorno gráfico *ligero* para no consumir toda la memoria RAM de mi máquina virtual: **XFCE**. Este recurso me ha permitido acceder a Google Chrome desde la máquina virtual y navegar a la URL esperada, lo que ha facilitado la verificación y prueba de la infraestructura web desplegada en el proyecto Inception. Para instalar XFCE, he utilizado el siguiente comando:

```bash
# Actualizar la lista de paquetes
sudo apt update
# Instalar XFCE y lightdm
sudo apt install xfce4 xfce4-goodies lightdm -y
# Reiniciar la máquina virtual para aplicar los cambios
sudo reboot
```

> *Nota: 'lightdm' es un gestor de pantalla que se utiliza para iniciar sesión en el entorno gráfico de escritorio. Es compatible con XFCE y proporciona una interfaz de inicio de sesión sencilla y eficiente.*

Una vez reiniciada la máquina, instalé Google Chrome utilizando el siguiente comando:

```bash
# Descargar el paquete de Google Chrome
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
# Instalar Google Chrome
sudo apt install ./google-chrome-stable_current_amd64.deb -y
```

### 4.4. Artificial Intelligence Use Cases

En este proyecto, se han utilizado herramientas de inteligencia artificial para mejorar la eficiencia y la calidad del desarrollo. Por ejemplo, se ha utilizado un modelo de lenguaje natural para generar documentación técnica y guías de uso, lo que ha permitido ahorrar tiempo y esfuerzo en la redacción de estos documentos. Además, se han utilizado algoritmos de aprendizaje automático para optimizar la configuración de los contenedores y mejorar el rendimiento de la infraestructura web. Estas herramientas de inteligencia artificial han sido fundamentales para el éxito del proyecto y han demostrado ser una valiosa adición al proceso de desarrollo.

Sobre todo, ha sido muy útil para el aprendizaje y la comprensión de conceptos complejos relacionados con la administración de sistemas y el desarrollo de aplicaciones. La inteligencia artificial ha permitido generar explicaciones claras y concisas sobre temas como la virtualización, los contenedores, los secretos y las variables de entorno, lo que ha facilitado la comprensión de estos conceptos para los estudiantes que están comenzando en el campo de la administración de sistemas. Además, la inteligencia artificial ha proporcionado ejemplos prácticos y analogías que han ayudado a los estudiantes a visualizar y entender mejor cómo funcionan estas tecnologías en la práctica.

En resumen, la inteligencia artificial ha sido una herramienta invaluable para el aprendizaje y la comprensión de conceptos complejos en el ámbito de la administración de sistemas y el desarrollo de aplicaciones, y ha contribuido significativamente al éxito del proyecto Inception.

## 5. Usage Examples

La infraestructura web desplegada en el proyecto Inception se puede utilizar para alojar y gestionar un sitio web de WordPress. A continuación, se presentan algunos ejemplos de uso para ilustrar cómo se puede aprovechar esta infraestructura:
1. **Desarrollo de un sitio web de WordPress**: Puedes utilizar la infraestructura para desarrollar y probar un sitio web de WordPress antes de desplegarlo en un entorno de producción. Esto te permite realizar cambios y ajustes en el sitio web sin afectar a los usuarios finales.
2. **Alojamiento de un sitio web de WordPress**: Una vez que hayas desarrollado tu sitio web de WordPress, puedes utilizar la infraestructura para alojarlo y hacerlo accesible a través de Internet. Esto te permite compartir tu sitio web con el mundo y llegar a una audiencia más amplia.
3. **Pruebas de rendimiento**: Puedes utilizar la infraestructura para realizar pruebas de rendimiento en tu sitio web de WordPress. Esto te permite identificar posibles cuellos de botella y optimizar el rendimiento de tu sitio web para mejorar la experiencia del usuario.
4. **Gestión de bases de datos**: La infraestructura incluye un contenedor de MariaDB que puedes utilizar para gestionar la base de datos de tu sitio web de WordPress. Esto te permite realizar tareas como la creación de tablas, la inserción de datos y la realización de copias de seguridad de la base de datos de manera eficiente y segura.

## 6. Feature List

La infraestructura web desplegada en el proyecto Inception incluye las siguientes características:
1. **Contenedores de Docker**: La infraestructura se compone de contenedores de Docker para NGINX, MariaDB y WordPress, lo que facilita la gestión y el despliegue de la aplicación.
2. **Red de Docker personalizada**: Se ha creado una red de Docker personalizada llamada 'inception' para permitir la comunicación entre los contenedores de manera segura y eficiente.
3. **Persistencia de datos**: Se ha utilizado un Docker Volume para garantizar que los datos de la base de datos de MariaDB se mantengan persistentes incluso si el contenedor se reinicia o se elimina.
4. **Configuración a través de Environment Variables**: La configuración de la aplicación se gestiona a través de Environment Variables, lo que permite una gestión centralizada de la configuración y evita exponer información sensible en el código o en los archivos de configuración
5. **Documentación detallada**: Se ha proporcionado documentación detallada en el archivo <a href="USER_DOC.md">USER_DOC.md</a> para guiar a los usuarios a través del proceso de despliegue y gestión de la infraestructura web.
6. **Testers para verificación**: Se han incluido tres testers en el repositorio para verificar el correcto funcionamiento de cada servicio (NGINX, MariaDB y WordPress) y proporcionar resultados detallados sobre el estado de cada servicio.

## 7. Technical Choices

Como último punto antes de cerrar, es importante destacar que las decisiones técnicas tomadas en el proyecto Inception se basan en la necesidad de crear una infraestructura web eficiente, segura y fácil de gestionar utilizando tecnologías de contenedores. La elección de Docker como plataforma de contenedores, la utilización de una red de Docker personalizada, la gestión de datos a través de Docker Volumes y la configuración mediante Environment Variables son decisiones técnicas que han sido cuidadosamente consideradas para garantizar el éxito del proyecto y proporcionar una experiencia de usuario óptima. Estas decisiones técnicas han sido fundamentales para el desarrollo y despliegue de la infraestructura web del proyecto Inception, y han contribuido significativamente a su eficiencia, seguridad y facilidad de gestión, siempre que cumpliera con los requisitos establecidos por los documentos de 42.

---

En conclusión, el proyecto Inception es un ejercicio de aprendizaje que ha permitido explorar y comprender conceptos clave relacionados con la administración de sistemas y el desarrollo de aplicaciones web utilizando tecnologías de contenedores. A través de la implementación de una infraestructura web eficiente, segura y fácil de gestionar, se han adquirido habilidades valiosas en el uso de Docker, la gestión de redes y volúmenes, y la configuración de aplicaciones mediante Environment Variables. Además, se ha proporcionado documentación detallada y herramientas de verificación para garantizar que los usuarios puedan desplegar y gestionar la infraestructura web con éxito. Este proyecto ha sido una experiencia enriquecedora que ha contribuido significativamente al desarrollo de habilidades técnicas en el ámbito de la administración de sistemas y el desarrollo de aplicaciones web.

## 8. Learnings

### How does Docker work?

Docker utiliza una tecnología de contenedores que permite empaquetar aplicaciones y sus dependencias en un entorno aislado. Esto se logra utilizando características del kernel del sistema operativo. Los contenedores comparten el mismo kernel del sistema operativo anfitrión mientras mantienen un aislamiento a nivel de aplicación. Esto hace que Docker sea una herramienta eficiente y flexible para el desarrollo y despliegue de aplicaciones.

En una frase simple, Docker es como una caja mágica donde puedes colocar tu aplicación y todo lo que necesita para funcionar, y esta caja puede ser transportada y ejecutada en cualquier lugar sin preocuparte por las diferencias entre los sistemas operativos.

### Which is the difference between Docker and Docker Compose?

Las principales diferencias entre Docker y Docker Compose son:
- Docker es una plataforma de contenedores que permite empaquetar aplicaciones y sus dependencias en un entorno aislado, mientras que Docker Compose es una herramienta que permite definir y ejecutar aplicaciones multicontenedor utilizando un archivo de configuración YAML. Es como comparar un Makefile (Docker Compose) con un script de bash (Docker). Docker se utiliza para gestionar contenedores individuales, mientras que Docker Compose se utiliza para gestionar aplicaciones multicontenedor, lo que facilita la orquestación y el despliegue de aplicaciones complejas.
- Docker se utiliza para gestionar contenedores individuales, mientras que Docker Compose se utiliza para gestionar aplicaciones multicontenedor, lo que facilita la orquestación y el despliegue de aplicaciones complejas.

En resumen, Docker es la orquesta y, Docker Compose, el director.

### Which is the difference between a Docker Image and a Docker Container?

Docker Image es una plantilla inmutable que contiene el código, las dependencias y la configuración necesaria para ejecutar una aplicación. Es como una receta que describe cómo construir un contenedor. Por otro lado, Docker Container es una instancia en ejecución de una imagen de Docker. Es como el plato preparado a partir de la receta. Mientras que una imagen es estática y no cambia, un contenedor es dinámico y puede ser modificado durante su ejecución.

Por su parte, Docker Container es una instancia en ejecución de una imagen de Docker. Es como el plato preparado a partir de la receta. Mientras que una imagen es estática y no cambia, un contenedor es dinámico y puede ser modificado durante su ejecución.

En una frase simple, una imagen es la receta y un contenedor es el plato preparado a partir de esa receta.

### Which is the difference between Docker and a Virtual Machine and which are the advantages of using Docker?

Ya hemos visto que un Docker es una plataforma de contenedores que permite empaquetar aplicaciones y sus dependencias en un entorno aislado, mientras que una Máquina Virtual es una emulación completa de un sistema operativo que se ejecuta sobre un hipervisor. Las ventajas de usar Docker incluyen:

También hemos visto que una máquina virtual es una emulación completa de un sistema operativo que se ejecuta sobre un hipervisor, mientras que Docker es una plataforma de contenedores que permite empaquetar aplicaciones y sus dependencias en un entorno aislado. Las ventajas de usar Docker incluyen:
- Mayor eficiencia: Docker utiliza menos recursos que las máquinas virtuales, ya que comparte el mismo kernel del sistema operativo anfitrión, lo que permite ejecutar más contenedores en el mismo hardware.
- Mayor portabilidad: Las aplicaciones empaquetadas en contenedores de Docker pueden ser ejecutadas en cualquier entorno que soporte Docker, lo que facilita el despliegue y la migración de aplicaciones.
- Mayor velocidad: Docker permite iniciar y detener contenedores de manera rápida, lo que mejora la eficiencia en el desarrollo y despliegue de aplicaciones.
- Mayor flexibilidad: Docker permite gestionar aplicaciones de manera modular, lo que facilita la actualización y el mantenimiento de las aplicaciones sin afectar a otras partes del sistema.

### Which is the difference between Docker Network and Host Network: `--link` or `--network: host`?

En una frase, Docker Network es una red virtual creada por Docker que permite a los contenedores comunicarse entre sí de manera aislada del host, mientras que Host Network es una red que permite a los contenedores acceder directamente a la red del host, lo que reduce el aislamiento y la seguridad. Por tanto, las principales diferencias entre Docker Network y Host Network son:
- Docker Network proporciona un entorno de red aislado para los contenedores, mientras que Host Network permite a los contenedores acceder directamente a la red del host.
- Docker Network utiliza direcciones IP y nombres de host para la comunicación entre contenedores, mientras que Host Network comparte la misma pila de red que el host, lo que puede comprometer la seguridad de la aplicación y del sistema en general.

En otras palabras, Docker es más seguro y aislado, mientras que Host Network puede ser útil para aplicaciones que requieren un acceso directo a los recursos del host, pero reduce el aislamiento y la seguridad.

**¿Qué es --link?** `--link` es una opción obsoleta en Docker que se utilizaba para conectar contenedores entre sí, pero se recomienda utilizar Docker Network para una comunicación más segura y eficiente entre contenedores. ¿Se usa en el proyecto Inception? No, en este proyecto se ha optado por utilizar Docker Network en lugar de `--link` para garantizar un entorno de desarrollo y producción seguro y eficiente. En su lugar, se ha creado una red personalizada llamada 'inception' que permite la comunicación entre los contenedores de manera segura y eficiente.

**¿Qué es --network: host?** `--network: host` es una opción en Docker que permite a los contenedores acceder directamente a la red del host, lo que reduce el aislamiento y la seguridad. Se recomienda utilizar Docker Network en lugar de Host Network para garantizar un entorno de desarrollo y producción seguro y eficiente. ¿Se usa en el proyecto Inception? No, en este proyecto se ha optado por utilizar Docker Network en lugar de Host Network para garantizar un entorno de desarrollo y producción seguro y eficiente.

### Why don't we use `tail -f`?

`tail -f` es un comando que se utiliza para seguir en tiempo real el contenido de un archivo, como los logs de un contenedor. Sin embargo, en el contexto de un contenedor de Docker, este comando no es necesario ni recomendado para mantener el contenedor en ejecución.

Esto se debe a que el contenedor de Docker se mantendrá en ejecución mientras el proceso principal del contenedor esté activo. Si el proceso principal termina, el contenedor se detendrá automáticamente. Por lo tanto, no es necesario utilizar `tail -f` para mantener el contenedor activo, ya que esto podría generar un consumo innecesario de recursos y no es una práctica recomendada en la gestión de contenedores.

En lugar de eso, se recomienda utilizar un proceso principal que mantenga el contenedor activo, como el servidor web NGINX o la base de datos MariaDB. Esto garantiza que el contenedor se mantenga en ejecución mientras el proceso principal esté activo, y evita la necesidad de utilizar comandos adicionales para mantener el contenedor activo. En este proyecto, se ha optado por utilizar los procesos principales de NGINX y MariaDB para mantener los contenedores activos, lo que garantiza un entorno de desarrollo y producción eficiente y seguro.

### Why don't we use `sleep infinity`?

`Sleep infinity` es un comando que se utiliza para mantener un proceso en ejecución de manera indefinida. Sin embargo, en el contexto de un contenedor de Docker, este comando no es necesario ni recomendado para mantener el contenedor en ejecución.

Esto se debe a que el contenedor de Docker se mantendrá en ejecución mientras el proceso principal del contenedor esté activo. Si el proceso principal termina, el contenedor se detendrá automáticamente. Por lo tanto, no es necesario utilizar `sleep infinity` para mantener el contenedor activo, ya que esto podría generar un consumo innecesario de recursos y no es una práctica recomendada en la gestión de contenedores. En lugar de eso, se recomienda utilizar un proceso principal que mantenga el contenedor activo, como el servidor web NGINX o la base de datos MariaDB. Esto garantiza que el contenedor se mantenga en ejecución mientras el proceso principal esté activo, y evita la necesidad de utilizar comandos adicionales para mantener el contenedor activo.

Igual que se ha comentado en la sección anterior, se ha optado por utilizar los procesos principales de NGINX y MariaDB para mantener los contenedores activos, lo que garantiza un entorno de desarrollo y producción eficiente y seguro.

### Why don't we use commands on background with `&` in the ENTRYPOINT?

La utilización de comandos en segundo plano con `&` en el ENTRYPOINT de un contenedor de Docker no es recomendable porque puede generar problemas de gestión y monitoreo del proceso principal del contenedor. Cuando se ejecutan comandos en segundo plano, el proceso principal del contenedor puede terminar antes de que los comandos en segundo plano hayan finalizado, lo que puede llevar a que el contenedor se detenga automáticamente.

Además, el uso de comandos en segundo plano puede dificultar la gestión y el monitoreo del contenedor, ya que los procesos en segundo plano pueden generar logs y consumir recursos sin que el proceso principal esté al tanto de su estado. Esto puede complicar la depuración y el mantenimiento del contenedor.

Al igual que en las dos secciones anteriores, se recomienda utilizar un proceso principal que mantenga el contenedor activo, como el servidor web NGINX o la base de datos MariaDB, en lugar de utilizar comandos en segundo plano con `&` en el ENTRYPOINT. Esto garantiza que el contenedor se mantenga en ejecución mientras el proceso principal esté activo, y facilita la gestión y el monitoreo del contenedor de manera eficiente y segura. Este proyecto utiliza ambos procesos principales para mantener los contenedores activos.

## 9. Evaluation Checklist

1. **Limpiar las variables**: todo debe venir de `srcs/.env`.
2. **Sin imágenes prefabricadas**: no se pueden usar imágenes de Docker Hub, excepto las oficiales: `FROM debian:bullseye` o `FROM alpine:X.X.X`. Se deben construir las imágenes a partir de los Dockerfiles proporcionados en el proyecto.
3. **Carpetas**: Salvo Makefile, los archivos markdown y los scripts, todo debe estar dentro de la carpeta `srcs/`.
4. **Ruta de volúmenes**: `docker-compose.yml` debe apuntar a `wordpress:/var/www/wordpress` y `mariadb:/var/lib/mysql`.
5. **Bucle diabólico**: Verificar que los scripts no incluyen `nginx && bash`.

---

<br>
<div align="center">
<bottom style="background-color: #640dad; color: #c0c0c0; padding: 10px; border: 1px solid #c0c0c0;">README</bottom> |
<bottom style="background-color: #c0c0c0; color: #000000; padding: 10px; border: 1px solid #640dad;">USER_DOC</bottom> |
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
		This file allow anyone unfamiliar with the project to quickly understand what the project is about, how to run it and where to find more information on the topic. 
	</p>
</i>
