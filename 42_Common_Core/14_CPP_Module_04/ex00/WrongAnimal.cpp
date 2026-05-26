/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:02:08 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:46:47 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Wrong Animal";
	std::cout << "🦀\tA wrong animal has born!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name)
{
	std::cout << "🦅\tA wrong animal has born!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.getType();
	std::cout << "🦆\tA wrong animal has born!" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "🦌\tWrongAnimal assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "🦇\tWrongAnimal has died!\t\t\t\t👻" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "🔇\tSilence." << std::endl;
}
