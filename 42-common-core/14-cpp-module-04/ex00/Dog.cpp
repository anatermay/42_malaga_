/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:08:18 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "🐶\tA dog has born!" << std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	std::cout << "🐶\tA dog has born!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "🐶\tA dog has born!" << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "🦮\tDog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "🐕\tDog has died!\t\t\t\t\t👻" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "🐶\tWOOF\t💬" << std::endl;
}
