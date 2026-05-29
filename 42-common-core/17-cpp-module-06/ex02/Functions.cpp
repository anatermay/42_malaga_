/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:37:48 by aternero          #+#    #+#             */
/*   Updated: 2026/04/22 21:21:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base	*generate(void)
{
	static bool	seed = false;
	int			nbr = -1;

	if (seed == false) { std::srand(static_cast<unsigned int>(std::time(NULL))); seed = true; }
	nbr = std::rand() % 3;
	if (nbr == 0)
		return (new A());
	if (nbr == 1)
		return (new B());
	return (new C());
}

void	identify(Base* p) {

	if (dynamic_cast<A*>(p) != NULL) { cout << "A" << endl; return ; }
	if (dynamic_cast<B*>(p) != NULL) { cout << "B" << endl; return ; }
	if (dynamic_cast<C*>(p) != NULL) { cout << "C" << endl; return ; }
}

void	identify(Base& p) {

	try {
		Base	&temp = dynamic_cast<A&>(p);
		(void)temp;
		cout << "A" << endl;
		return;
	}
	catch (const std::exception) { }
	try {
		Base	&temp = dynamic_cast<B&>(p);
		(void)temp;
		cout << "B" << endl;
		return;
	}
	catch (const std::exception) { }
	try {
		Base	&temp = dynamic_cast<C&>(p);
		(void)temp;
		cout << "C" << endl;
		return;
	}
	catch (const std::exception) { }
}
