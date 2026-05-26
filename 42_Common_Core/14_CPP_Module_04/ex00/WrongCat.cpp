/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:05:06 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:03:44 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "😿\tA wrong cat has born!" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
	std::cout << "😿\tA wrong cat has born!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "😿\tA wrong cat has born!" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "😿\tWrongCat assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "😿\tWrongCat has died!\t\t\t\t👻" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "😿\tMEOW\t💬" << std::endl;
}
