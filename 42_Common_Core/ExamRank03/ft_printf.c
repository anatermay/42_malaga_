/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:57:01 by aternero          #+#    #+#             */
/*   Updated: 2025/04/21 20:20:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief Implementación de una versión simplificada de la función printf.
 *
 * Este archivo contiene una implementación personalizada de la función `ft_printf`,
 * que soporta salida formateada para cadenas, números enteros y números hexadecimales.
 * La función utiliza argumentos variádicos para manejar un número variable de entradas.
 *
 * Funciones:
 * - ft_putstr: Escribe una cadena en la salida estándar.
 * - ft_putnum: Escribe un número en la salida estándar en una base específica.
 * - ft_printf: Función principal que analiza la cadena de formato y gestiona la salida.
 *
 * Uso:
 * - `%s`: Imprime una cadena.
 * - `%d` o `%i`: Imprime un número entero con signo en base 10.
 * - `%x`: Imprime un número entero sin signo en hexadecimal (minúsculas).
 *
 * Limitaciones:
 * - No soporta todos los especificadores de formato disponibles en el printf estándar.
 * - No maneja ancho, precisión o banderas.
 * - Solo soporta un subconjunto limitado de funcionalidades con fines educativos.
 */

/*
 * Para tontos muy muy pero que muy tontos:
 * Este archivo implementa una versión simplificada de la función printf.
 * Básicamente, puedes usarlo para imprimir cadenas (`%s`), números enteros
 * (`%d` o `%i`), y números en hexadecimal (`%x`). No hace cosas avanzadas
 * como manejar anchos, precisiones o banderas. Es como un printf "light".
 * Si no entiendes algo, piensa en esto como una herramienta para escribir
 * cosas en la pantalla de forma básica. ¡No te compliques!
 */


 #include <unistd.h>				// Include the write function
 #include <stdarg.h>				// Include the variable arguments list
 
 void    ft_putstr(char *str, int *len)          // Function to print a string
 {
		 if (!str)
				 str = "(null)";                 // If the string is NULL, print "(null)"
		 while (*str)
				 *len += write(1, str++, 1);     // Write one character at a time and increment the length
 }
 void    ft_putnum(long long int nbr, int base, int *len)
 {
		 char    *hex;
		 hex = "0123456789abcdef";                       // Define the hexadecimal characters
		 if (nbr < 0)                                    // Check if the number is negative  
		 {
				 nbr *= -1;                              // Make the number positive
				 *len += write(1, "-", 1);       
		 }
		 if (nbr >= base)                                // Check if the number is greater than the base
				 ft_putnum((nbr / base), base, len);     // Call the function recursively to print the remaining digits
		 *len += write(1, &hex[nbr % base], 1);          // Write the character corresponding to the digit
 }
 int     ft_printf(const char *format, ...)
 {
		 int     len;
		 va_list ptr;                                    // Define the variable arguments list
		 len = 0;
		 va_start(ptr, format);                          // Start the variable arguments list
		 while (*format)
		 {
				 if ((*format == '%') && *(format + 1))  // Check if the character is a format specifier and there is a character after it
				 {
						 format++;                       // Move to the next character
						 if (*format == 's')
								 ft_putstr(va_arg(ptr, char *), &len);                           // Call the function to print a string
						 else if (*format == 'd' || *format == 'i')
								 ft_putnum((long long int)va_arg(ptr, int), 10, &len);           // Call the function to print a decimal number
						 else if (*format == 'x')
								 ft_putnum((long long int)va_arg(ptr, unsigned int), 16, &len);  // Call the function to print a hexadecimal number
				 }
				 else
						 len += write(1, format, 1);     // Write the character to the console
				 format++;                               // Move to the next character
		 }
		 return (va_end(ptr), len);                      // End the variable arguments list and return the total number of characters printed
 }
 