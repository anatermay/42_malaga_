/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:21:52 by aternero          #+#    #+#             */
/*   Updated: 2026/02/01 18:54:19 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void		Harl::filterComplain(std::string level)
{
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			levelIndex;

	for (levelIndex = 0; levelIndex < 4; levelIndex++)
	{
		if (levels[levelIndex] == level)
			break ;
	}
	switch (levelIndex)
	{
		case 0:
			std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger.\nI really do!\n" << std::endl;
			// fall through
		case 1:
			std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl;
			// fall through
		case 2:
			std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, where as you started working here just last month.\n" << std::endl;
			// fall through
		case 3:
			std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}

Harl::Harl()	{ }

Harl::~Harl()	{ }