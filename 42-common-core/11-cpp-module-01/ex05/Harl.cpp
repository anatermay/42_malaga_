/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:21:52 by aternero          #+#    #+#             */
/*   Updated: 2025/12/01 14:46:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void		Harl::complain( std::string level )
{
	for (int index = 0; index < 4; index++)
	{
		if (handlers[index].levels == level)
		{
			(this->*handlers[index].f)();
			return ;
		}
	}
	std::cout << "Level not found" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." <<  std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years, where as you started working here just last month." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

Harl::Harl()
{
	handlers[0].levels = "DEBUG";
	handlers[0].f = &Harl::debug;
	handlers[1].levels = "INFO";
	handlers[1].f = &Harl::info;
	handlers[2].levels = "WARNING";
	handlers[2].f = &Harl::warning;
	handlers[3].levels = "ERROR";
	handlers[3].f = &Harl::error;
}

Harl::~Harl()	{ }