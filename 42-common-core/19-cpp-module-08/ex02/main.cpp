/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:38:43 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 22:00:56 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void printSection(const std::string& title) {
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main() {
	printSection("Test básico de MutantStack");
	MutantStack<int> mstack;
	std::cout << "Pushing: 5, 17" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Pop! Nuevo size: " << mstack.size() << std::endl;

	std::cout << "Pushing: 3, 5, 737, 0" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterando MutantStack:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	for (; it != ite; ++it)
		std::cout << "  Valor: " << *it << std::endl;

	printSection("Comparando con std::list");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Iterando std::list:" << std::endl;
	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
		std::cout << "  Valor: " << *lit << std::endl;

	printSection("Test de copia y asignación");
	MutantStack<int> copyStack(mstack);
	std::cout << "Iterando copia (constructor de copia):" << std::endl;
	for (MutantStack<int>::iterator cit = copyStack.begin(); cit != copyStack.end(); ++cit)
		std::cout << "  Valor: " << *cit << std::endl;

	MutantStack<int> assignStack;
	assignStack = mstack;
	std::cout << "Iterando asignación (operator=):" << std::endl;
	for (MutantStack<int>::iterator ait = assignStack.begin(); ait != assignStack.end(); ++ait)
		std::cout << "  Valor: " << *ait << std::endl;

	std::cout << "\n=== Todas las pruebas completadas ===" << std::endl;
	return 0;
}
