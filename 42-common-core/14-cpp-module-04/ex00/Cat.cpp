/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 15:18:20 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat is born!" << std::endl;
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << "Cat is born!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat is born!" << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat has died!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "\t😻\tMEOW" << std::endl;
}
