/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:17:37 by aternero          #+#    #+#             */
/*   Updated: 2025/11/17 15:21:57 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon()
{
	std::cout << "Weapon " << type << " destroyed." <<  std::endl;
	return ;
}

void	Weapon::setType(std::string type)
{
	std::cout << "Weapon " << this->type << " changed to " << type << "." << std::endl;
	this->type = type;
}

const std::string	&Weapon::getType() const
{
	return (type);
}

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Weapon " << type << " created." <<  std::endl;
	return ;
}
