# NetPractice

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Redes](https://img.shields.io/badge/Materia-Redes-brightgreen)
![Rango](https://img.shields.io/badge/Rango-04-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-100%2F100-success)

## 📋 Descripción del Proyecto

`NetPractice` es un ejercicio práctico de redes que enseña los fundamentos de configuración de redes, direccionamiento IP y enrutamiento. Este proyecto forma parte del currículo del Common Core de 42 (Rango 04) y se enfoca en comprender conceptos de redes TCP/IP a través de ejercicios de configuración práctica.

## 🎯 Objetivos

- Comprender los fundamentos del stack de protocolos TCP/IP
- Dominar el direccionamiento IP y cálculos de máscara de subred
- Aprender enrutamiento de redes y configuración de gateway
- Practicar notación CIDR y técnicas de subnetting
- Configurar interfaces de red y tablas de enrutamiento
- Solucionar problemas de conectividad de red
- Aplicar conceptos del modelo OSI en escenarios prácticos

## 🌐 Conceptos de Redes Cubiertos

### Fundamentos Principales de Redes
| Concepto | Descripción | Aplicación |
|----------|-------------|------------|
| **Direccionamiento IP** | Estructura de direcciones IPv4 y clases | Configuración de interfaces |
| **Máscaras de Subred** | Identificación de red y host | Segmentación de redes |
| **Notación CIDR** | Enrutamiento Inter-Dominio sin Clases | Asignación eficiente de direcciones |
| **Gateway Predeterminado** | Interfaz de router para tráfico externo | Comunicación entre redes |
| **Tablas de Enrutamiento** | Determinación de rutas para reenvío de paquetes | Dirección de tráfico de red |
| **Interfaces de Red** | Conexiones de red físicas/lógicas | Conectividad de dispositivos |

### Temas Avanzados
- **Subnetting**: Dividir redes en segmentos más pequeños
- **VLSM**: Máscara de Subred de Longitud Variable
- **Agregación de Rutas**: Combinación de múltiples rutas
- **Resolución de Problemas de Red**: Solución de problemas de conectividad

## 📁 Estructura del Proyecto

```
8_netpractice/
├── level1.json                     # Direccionamiento IP básico
├── level2.json                     # Introducción a máscara de subred
├── level3.json                     # Enrutamiento simple
├── level4.json                     # Múltiples interfaces
├── level5.json                     # Configuración de gateway
├── level6.json                     # Subnetting complejo
├── level7.json                     # CIDR y enrutamiento
├── level8.json                     # Escenarios de enrutamiento avanzado
├── level9.json                     # Redes multi-router
├── level10.json                    # Topología de red compleja
└── README_es.md                    # Este archivo
```

## 🚀 Progresión de Niveles

### **Nivel 1-3: Fundamentos**
- Asignación básica de direcciones IP
- Introducción a máscaras de subred
- Conexiones punto a punto simples
- Comprensión de direcciones de red y broadcast

### **Nivel 4-6: Conceptos Intermedios**
- Múltiples interfaces de red
- Configuración de gateway
- Cálculos de máscara de subred
- Segmentación de redes

### **Nivel 7-10: Escenarios Avanzados**
- Tablas de enrutamiento complejas
- Topologías multi-router
- Dominio de notación CIDR
- Simulación de redes del mundo real

## 💡 Resultados de Aprendizaje Clave

### Dominio del Direccionamiento IP
- **Estructura IPv4**: Comprensión del direccionamiento de 32 bits
- **Clases de Direcciones**: Redes Clase A, B y C
- **Privado vs Público**: Rangos de direcciones privadas RFC 1918
- **Red vs Host**: Papel de la máscara de subred en división de direcciones

### Excelencia en Subnetting
- **Cálculos CIDR**: Conversión entre decimal y CIDR
- **Planificación de Subredes**: Diseño eficiente de redes
- **Implementación VLSM**: Tamaños variables de subred
- **Conservación de Direcciones**: Asignación óptima de IP

### Comprensión de Enrutamiento
- **Rutas Predeterminadas**: Configuración de gateway 0.0.0.0/0
- **Enrutamiento Estático**: Entradas manuales en tabla de rutas
- **Especificidad de Rutas**: Coincidencia de prefijo más largo
- **Enrutamiento Multi-salto**: Ruta a través de múltiples routers

## 🧪 Ejemplos de Configuraciones

### Configuración Básica de Red
```json
{
  "ifs": {
    "A1": {"ip": "192.168.1.1", "mask": "255.255.255.0"},
    "B1": {"ip": "192.168.1.2", "mask": "255.255.255.0"}
  },
  "routes": {}
}
```

### Configuración de Gateway
```json
{
  "ifs": {
    "A1": {"ip": "10.0.0.1", "mask": "255.255.255.0"},
    "R1": {"ip": "10.0.0.254", "mask": "255.255.255.0"}
  },
  "routes": {
    "Ar1": {"route": "default", "gate": "10.0.0.254"}
  }
}
```

### Enrutamiento Complejo
```json
{
  "routes": {
    "H3r1": {"gate": "139.111.59.195"},
    "R1r1": {"route": "139.111.59.192/26"},
    "Ir1": {"route": "139.111.59.0/24"}
  }
}
```

## 🔧 Habilidades Técnicas Desarrolladas

### Configuración de Redes
- **Configuración de Interfaces**: Asignación de IP y máscara
- **Gestión de Rutas**: Configuración de rutas estáticas
- **Asignación de Gateway**: Configuración de ruta predeterminada
- **Validación de Red**: Verificación de conectividad

### Esquemas de Direccionamiento
- **Diseño de Subredes**: Planificación eficiente de redes
- **Dominio CIDR**: Direccionamiento sin clases
- **Cálculo de Direcciones**: Competencia en matemáticas de red
- **Resolución de Conflictos**: Prevención de redes superpuestas

### Resolución de Problemas
- **Problemas de Conectividad**: Problemas de accesibilidad de red
- **Problemas de Enrutamiento**: Errores de determinación de rutas
- **Errores de Configuración**: Errores de sintaxis y lógica
- **Aislamiento de Red**: Problemas de segmentación

## 📊 Aplicaciones Prácticas

### Redes Empresariales
- **LANs de Oficina**: Diseño de redes de área local
- **Conectividad de Sucursales**: Configuración de conexión WAN
- **Configuración VLAN**: Segmentación de redes virtuales
- **Zonas de Seguridad**: Estrategias de aislamiento de red

### Redes de Proveedores de Servicios
- **Redes de Clientes**: Asignación de subredes ISP
- **Enrutamiento BGP**: Protocolos de enrutamiento de Internet
- **Ingeniería de Tráfico**: Selección de ruta óptima
- **Escalado de Red**: Acomodación de crecimiento

### Infraestructura en la Nube
- **Diseño VPC**: Nubes privadas virtuales
- **Asignación de Subredes**: Segmentación de recursos
- **Tablas de Rutas**: Control de tráfico
- **ACLs de Red**: Implementación de reglas de seguridad

## 🌟 Logros Clave

### Competencia en Diseño de Redes
✅ **Dominio de Cálculo de Subredes**: Conversión instantánea de CIDR a decimal  
✅ **Configuración de Tablas de Enrutamiento**: Escenarios complejos multi-salto  
✅ **Resolución de Problemas de Red**: Identificación rápida de problemas  
✅ **Planificación de Direcciones**: Estrategias eficientes de asignación IP  

### Comprensión de Protocolos
✅ **Stack TCP/IP**: Comprensión de interacción de capas  
✅ **Modelo OSI**: Aplicación práctica de capas de red  
✅ **Flujo de Paquetes**: Comprensión de comunicación extremo a extremo  
✅ **Seguridad de Red**: Aplicación de principios básicos de seguridad  

## 🔗 Relevancia en el Mundo Real

### Aplicaciones Profesionales
- **Ingeniería de Redes**: Diseño y gestión de infraestructura
- **Administración de Sistemas**: Configuración de redes de servidores
- **Arquitectura en la Nube**: Diseño de redes virtuales
- **DevOps**: Redes de contenedores y service mesh
- **Ciberseguridad**: Seguridad y monitoreo de redes

### Estándares de la Industria
- **Cumplimiento RFC**: Adherencia a estándares de Internet
- **Mejores Prácticas**: Configuraciones estándar de la industria
- **Escalabilidad**: Diseño de redes de grado empresarial
- **Documentación**: Documentación de topología de red

## 🎓 Habilidades Adquiridas

### Competencias Técnicas
- **Diseño de Redes**: Arquitectura de red extremo a extremo
- **Planificación IP**: Asignación estructurada de direcciones
- **Protocolos de Enrutamiento**: Enrutamiento estático y dinámico
- **Segmentación de Redes**: Optimización de seguridad y rendimiento

### Habilidades de Resolución de Problemas
- **Pensamiento Analítico**: Desglose sistemático de problemas
- **Reconocimiento de Patrones**: Identificación de problemas comunes de red
- **Gestión de Configuración**: Enfoque estructurado para configuración
- **Habilidades de Documentación**: Documentación clara de redes

## 🔗 Enlaces

- **Autora**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repositorio**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 📊 Progreso del Common Core de 42

Este proyecto forma parte de mi recorrido por el currículo del Common Core de 42:

- **Rango 00**: ✅ libft
- **Rango 01**: ✅ ft_printf, born2beroot, get_next_line
- **Rango 02**: ✅ push_swap, examrank02, so_long, minitalk
- **Rango 03**: ✅ philosophers, examrank03, minishell
- **Rango 04**: 🔄 netpractice (completado), examrank04, cub3d, CPP 00-04

## 🏆 Logro

**Puntuación Final**: 100/100 ✨

---

*Este proyecto fue completado como parte del currículo de 42 School en 42 Málaga.*
