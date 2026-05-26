/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:39:52 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:39:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void printTest(const std::string& desc, void (*test)()) {
	std::cout << "\n=== " << desc << " ===" << std::endl;
	try {
		test();
	} catch (const std::exception& e) {
		std::cout << "✗ Excepción: " << e.what() << std::endl;
	}
}

void testBasic() {
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
}

void testExceedLimit() {
	Span sp(2);
	sp.addNumber(1);
	sp.addNumber(2);
	try {
		sp.addNumber(3);
		std::cout << "✗ No debería llegar aquí" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "✓ Excepción esperada: " << e.what() << std::endl;
	}
}

void testNoNumbers() {
	Span sp(10);
	try {
		sp.shortestSpan();
		std::cout << "✗ No debería llegar aquí" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "✓ Excepción esperada: " << e.what() << std::endl;
	}
	try {
		sp.longestSpan();
		std::cout << "✗ No debería llegar aquí" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "✓ Excepción esperada: " << e.what() << std::endl;
	}
}

void testOneNumber() {
	Span sp(10);
	sp.addNumber(42);
	try {
		sp.shortestSpan();
		std::cout << "✗ No debería llegar aquí" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "✓ Excepción esperada: " << e.what() << std::endl;
	}
}

void testNegativeNumbers() {
	Span sp(3);
	sp.addNumber(-10);
	sp.addNumber(0);
	sp.addNumber(10);
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
}

int main() {
	printTest("Test básico (subject)", testBasic);
	printTest("Excepción por exceso de números", testExceedLimit);
	printTest("Excepción por no tener números", testNoNumbers);
	printTest("Excepción con solo un número", testOneNumber);
	printTest("Números negativos y cero", testNegativeNumbers);

	std::cout << "\n=== Todas las pruebas completadas ===" << std::endl;
	return 0;
}
