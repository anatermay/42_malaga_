/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:11:45 by aternero          #+#    #+#             */
/*   Updated: 2026/02/01 18:48:01 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "\n\n\n____________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--- --- --- --- --- --- STRING VARIABLE --- --- --- --- --- ---    " << std::endl;
	std::cout << "------------------------------------------------------------\n" << std::endl;
	std::cout << "[   ] The value of the string variable: " << brain << std::endl;
	std::cout << "[ * ] Memory address pointed by the string variable: NONE" << std::endl;
	std::cout << "[ & ] The memory address of the string variable: " << &brain << std::endl;
	std::cout << "\n____________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--- --- --- --- --- --- stringPTR --- --- --- --- --- ---" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "[   ] The value of stringPTR (address of brain): " << stringPTR << std::endl;
	std::cout << "[ * ] Memory address pointed by stringPTR (value of brain): " << *stringPTR << std::endl;
	std::cout << "[ & ] Memory address of stringPTR: " << &stringPTR << "👀" << std::endl;
	std::cout << "\n____________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--- --- --- --- --- --- stringREF --- --- --- --- --- ---" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "[   ] The value of stringREF (value of brain): " << stringREF << std::endl;
	std::cout << "[ * ] Memory address pointed by stringREF (address of brain): " << &stringREF << std::endl;
	std::cout << "[ & ] Memory address of stringREF: " << &stringREF << std::endl;
	return (0);
}
