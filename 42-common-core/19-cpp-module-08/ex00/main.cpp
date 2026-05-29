/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:25 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:03:52 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	std::cout << "=== Pruebas de easyfind ===" << std::endl << std::endl;

	// Test 1: Vector - Encontrado
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(5);
		vec.push_back(99);

		std::cout << "Test 1 - Vector (buscando 42): ";
		try {
			std::vector<int>::iterator it = easyfind(vec, 42);
			std::cout << "✓ Encontrado en posición " << (it - vec.begin()) << std::endl;
		} catch (const std::exception& e) {
			std::cout << "✗ Excepción: " << e.what() << std::endl;
		}
	}

	// Test 2: Vector - No encontrado
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		std::cout << "Test 2 - Vector (buscando 999): ";
		try {
			easyfind(vec, 999);
			std::cout << "✗ No debería llegar aquí" << std::endl;
		} catch (const std::exception& e) {
			std::cout << "✓ Excepción correcta: " << e.what() << std::endl;
		}
	}

	// Test 3: List - Múltiples ocurrencias (debe encontrar la primera)
	{
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(20);
		lst.push_back(30);

		std::cout << "Test 3 - List (buscando 20): ";
		try {
			std::list<int>::iterator it = easyfind(lst, 20);
			std::cout << "✓ Primera ocurrencia encontrada en valor: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "✗ Error inesperado: " << e.what() << std::endl;
		}
	}

	// Test 4: Deque
	{
		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);
		deq.push_back(400);

		std::cout << "Test 4 - Deque (buscando 300): ";
		try {
			std::deque<int>::iterator it = easyfind(deq, 300);
			std::cout << "✓ Encontrado en valor: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "✗ Error: " << e.what() << std::endl;
		}
	}

	// Test 5: Contenedor vacío
	{
		std::vector<int> empty;
		std::cout << "Test 5 - Vector vacío: ";
		try {
			easyfind(empty, 42);
			std::cout << "✗ No debería llegar aquí" << std::endl;
		} catch (const std::exception& e) {
			std::cout << "✓ Excepción correcta: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "=== Todas las pruebas completadas ===" << std::endl;
	return (0);
}
