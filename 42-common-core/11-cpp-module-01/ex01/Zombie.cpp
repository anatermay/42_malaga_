/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:40:12 by aternero          #+#    #+#             */
/*   Updated: 2026/02/02 20:01:57 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
	if (((N - index) + 1) >= 10)
		std::cout << "[" << N - index + 1 << "] Our zombie, " << name << ", already died 💀" << std::endl;
	else
		std::cout << "[0" << N - index + 1 << "] Our zombie, " << name << ", already died 💀" << std::endl;
}

void	Zombie::announce()
{
	if (index >= 10)
		std::cout << "[" << index << "] " << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << "[0" << index << "] " << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name, int index)
{
	this->name = name;
	this->index = index + 1;
	if (index >= 10)
		std::cout << "[" << index << "] A new zombie, " << name << ", was born 🧟" << std::endl;
	else
		std::cout << "[0" << index << "] A new zombie, " << name << ", was born 🧟" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) { }

Zombie::Zombie()
{
	return ;
}

