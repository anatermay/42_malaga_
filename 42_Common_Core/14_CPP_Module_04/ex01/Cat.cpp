/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:58:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "A cat has born!" << std::endl;
	this->brain = new Brain();
	std::cout << "This cat has a brain!" << std::endl;
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << "A cat has born!" << std::endl;
	this->brain = new Brain();
	std::cout << "This cat has a brain!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "A cat has born!" << std::endl;
	this->brain = new Brain(*other.brain);
	std::cout << "This cat has a brain!" << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "This cat lost his brain!" << std::endl;
	std::cout << "Cat has died!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "\t😻\tMEOW" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (brain);
}
