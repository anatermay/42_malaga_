/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 15:06:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	char	character;

	character = 'a';
	for (int index = 0; index < 100; index++)
	{
		this->ideas[index] = character;
		character++;
		if (character > 'z')
			character = 'a';
	}
	std::cout << "A brain has been created!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int index = 0; index < 100; index++)
		this->ideas[index] = other.getIdea(index);
	std::cout << "A brain has been created!" << std::endl;
}

Brain&	Brain::operator=(const Brain &other)
{
	for (int index = 0; index <= 99; index++)
	{
		if (this->ideas[index] != other.ideas[index])
			this->ideas[index] = other.ideas[index];
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain has been destroyed!" << std::endl;
}

void			Brain::setIdea(int index, std::string text)
{
	if (index < 0 || index >= 100)
		return ;
	this->ideas[index] = text;
}

std::string		Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (this->ideas[index]);
}
