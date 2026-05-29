/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:17:09 by aternero          #+#    #+#             */
/*   Updated: 2026/02/02 20:01:57 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB()
{
	std::cout << name << " died." <<  std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << name << " has been armed with a " << weapon.getType() << "." << std::endl;
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack." << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	std::cout << name << " was born." <<  std::endl;
	return ;
}
