/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:21:52 by aternero          #+#    #+#             */
/*   Updated: 2025/12/01 15:36:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}
	Harl	harl;
    std::cout << "Filtering complaints at level: " << argv[1] << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Levels' Order is: DEBUG < INFO < WARNING < ERROR\n" << std::endl;
	harl.filterComplain(argv[1]);
	return (0);
}
