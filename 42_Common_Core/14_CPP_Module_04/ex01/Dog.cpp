/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:58:16 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "A dog has born!" << std::endl;
	this->brain = new Brain();
	std::cout << "This dog has a brain!" << std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	std::cout << "A dog has born!" << std::endl;
	this->brain = new Brain();
	std::cout << "This dog has a brain!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "A dog has born!" << std::endl;
	this->brain = new Brain(*other.brain);
	std::cout << "This dog has a brain!" << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "This dog lost his brain!" << std::endl;
	std::cout << "Dog has died!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "\t🐶\tWOOF" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (brain);
}
