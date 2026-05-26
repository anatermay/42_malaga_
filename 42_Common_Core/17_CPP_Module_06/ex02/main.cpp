/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:33:07 by aternero          #+#    #+#             */
/*   Updated: 2026/04/22 21:18:21 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>  // para rand() y srand()
#include <ctime>    // para time()
#include "Base.hpp"
#include "Functions.hpp"

int main(void)
{
	std::cout << "=== Prueba de Identificación de Tipos ===" << std::endl;
	
	// Generar 10 objetos aleatorios para probar
	Base* ptrs[10];
	
	std::cout << std::endl << "1. Probando con punteros (Base*):" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		ptrs[i] = generate();
		std::cout << "Objeto " << (i + 1) << ": ";
		identify(ptrs[i]);
	}
	
	std::cout << std::endl << "2. Probando con referencias (Base&):" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Objeto " << (i + 1) << ": ";
		identify(*ptrs[i]);
	}
	
	// Liberar memoria
	for (int i = 0; i < 10; i++)
		delete ptrs[i];
	
	std::cout << std::endl << "=== Fin de la prueba ===" << std::endl;
	return (0);
}
