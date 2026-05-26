/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:04:55 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "🐇\tAn animal has born!" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
	std::cout << "🐇\tAn animal has born!" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.getType();
	std::cout << "🐇\tAn animal has born!" << std::endl;
}

Animal&	Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "🐙\tAnimal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "🐐\tAnimal has died!\t\t\t\t👻" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "🔇\tSilence." << std::endl;
}
