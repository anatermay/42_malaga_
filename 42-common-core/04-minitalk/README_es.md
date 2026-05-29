# minitalk

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C-brightgreen)
![Rango](https://img.shields.io/badge/Rango-02-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-121%2F100-success)

## 📋 Descripción del Proyecto

`minitalk` es un programa de comunicación entre cliente y servidor usando señales UNIX. Este proyecto forma parte del currículo del Common Core de 42 School (Rango 02) y se enfoca en comprender la comunicación entre procesos, el manejo de señales y la manipulación de bits en programación C.

## 🎯 Objetivos

- Implementar un sistema de comunicación cliente-servidor usando solo señales UNIX
- Manejar las señales `SIGUSR1` y `SIGUSR2` para la transmisión de datos binarios
- Convertir caracteres a binario y transmitir bit a bit
- Asegurar la entrega confiable de mensajes y el manejo de errores
- Crear una versión bonus con sistema de confirmación
- Seguir los estándares de codificación de 42 School (Norminette)

## 🔧 Comunicación por Señales

El programa usa dos señales UNIX para la comunicación:

| Señal | Valor Binario | Descripción |
|-------|---------------|-------------|
| `SIGUSR1` | 0 | Representa el bit binario 0 |
| `SIGUSR2` | 1 | Representa el bit binario 1 |

### Flujo de Comunicación
1. **Servidor** se inicia y muestra su ID de Proceso (PID)
2. **Cliente** toma el PID del servidor y el mensaje como argumentos
3. **Cliente** convierte cada carácter a binario de 8 bits
4. **Cliente** envía cada bit usando `SIGUSR1` (0) o `SIGUSR2` (1)
5. **Servidor** reconstruye el mensaje bit a bit
6. **Servidor** muestra el mensaje completo

## 📁 Estructura del Proyecto

```
4_minitalk/
├── server.c              # Implementación del servidor
├── client.c              # Implementación del cliente
├── server_bonus.c        # Servidor con confirmación (bonus)
├── client_bonus.c        # Cliente con confirmación (bonus)
├── minitalk.h            # Archivo de cabecera para la parte obligatoria
├── minitalk_bonus.h      # Archivo de cabecera para el bonus
├── Makefile             # Configuración de compilación
└── README_es.md         # Este archivo
```

## 🚀 Uso

### Compilación

```bash
# Compilar versión obligatoria
make

# Compilar versión bonus
make bonus

# Limpiar archivos objeto
make clean

# Limpiar todo
make fclean

# Recompilar todo
make re
```

### Ejecutar el Programa

#### Versión Obligatoria

```bash
# Terminal 1: Iniciar el servidor
./server
# Salida: Server PID: [número]

# Terminal 2: Enviar un mensaje
./client [server_pid] "¡Hola, Mundo!"
```

#### Versión Bonus

```bash
# Terminal 1: Iniciar el servidor bonus
./server_bonus
# Salida: Server PID: [número]

# Terminal 2: Enviar un mensaje con confirmación
./client_bonus [server_pid] "¡Hola, Mundo!"
# Salida: ¡Mensaje enviado exitosamente!
```

### Ejemplos

```bash
# Comunicación básica
./server &
./client 12345 "¡42 School es increíble!"

# Soporte Unicode (bonus)
./server_bonus &
./client_bonus 12345 "¡Hola 🌍!"

# Múltiples mensajes
./server &
./client 12345 "Primer mensaje"
./client 12345 "Segundo mensaje"
```

## 💡 Implementación Técnica

### Manipulación de Bits
- Cada carácter se convierte a su representación binaria de 8 bits
- Los bits se envían del bit menos significativo (LSB) al más significativo (MSB)
- El servidor reconstruye los caracteres acumulando los bits recibidos

### Manejo de Señales
```c
// Manejador de señales del servidor
void server_receptor(int sig, siginfo_t *info, void *context)
{
    static unsigned char val = 0;
    static int bit = 1;
    
    if (sig == SIGUSR1)
        val += 0;      // Binario 0
    if (sig == SIGUSR2)
        val += bit;    // Binario 1
    
    bit <<= 1;         // Mover a la siguiente posición de bit
    
    if (bit == 256)    // Byte completo recibido
    {
        write(1, &val, 1);  // Mostrar carácter
        val = 0;            // Reiniciar para el siguiente carácter
        bit = 1;            // Reiniciar posición de bit
    }
}
```

### Manejo de Errores
- Valida argumentos de línea de comandos
- Maneja fallos en la transmisión de señales
- Gestiona PIDs inválidos
- Implementa mecanismos de timeout (bonus)

## 🏆 Características Bonus

La implementación bonus incluye características adicionales:

### Confirmación del Servidor
- El servidor envía una señal de confirmación de vuelta al cliente
- El cliente espera la confirmación antes de enviar el siguiente bit
- Asegura la entrega confiable del mensaje

### Soporte Unicode
- Maneja caracteres UTF-8 multi-byte
- Soporta emojis y caracteres especiales
- Mantiene la codificación apropiada durante la transmisión

### Manejo de Errores Mejorado
- Mensajes de error comprensivos
- Recuperación elegante de fallos
- Manejo robusto de señales

## 🧪 Pruebas

El proyecto maneja varios escenarios:
- Mensajes de un solo carácter
- Mensajes de texto largos
- Mensajes vacíos
- Caracteres especiales y Unicode
- Múltiples mensajes consecutivos
- PIDs y argumentos inválidos
- Fallos en la transmisión de señales

### Consideraciones de Rendimiento
- Transmisión eficiente bit a bit
- Uso mínimo de memoria
- Procesamiento rápido de señales
- Comunicación de baja latencia

## 📈 Desafíos Técnicos

### Confiabilidad de Señales
- Las señales UNIX no se encolan por defecto
- Riesgo de pérdida de señales durante transmisión rápida
- Solución: Sistema de confirmación implementado en bonus

### Gestión del Orden de Bits
- Orden consistente de bits entre cliente y servidor
- Reconstrucción adecuada de bytes desde bits individuales
- Manejo de caracteres multi-byte

### Sincronización de Procesos
- Coordinar la velocidad de envío del cliente con el procesamiento del servidor
- Prevenir overflow de señales
- Gestionar clientes concurrentes (consideración bonus)

## 🔗 Enlaces

- **Autora**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repositorio**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 🏆 Logro

**Puntuación Final**: 121/100 ✨

---

*Este proyecto fue completado como parte del currículo de 42 School en 42 Málaga.*
