/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:00:16 by aternero          #+#    #+#             */
/*   Updated: 2026/04/21 18:32:21 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	defaultTesters(void)
{
	ScalarConverter::convert("0");
	std::cout << "\n·············································································\n" << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << "\n·············································································\n" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "\n·············································································\n" << std::endl;
	ScalarConverter::convert("42.0f");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		defaultTesters();
	else if (argc >= 2)
	{
		for (int index = 1; index < argc; ++index)
			ScalarConverter::convert(argv[index]);
		//std::cout << "\n·············································································\n" << std::endl;
	}
	return (0);
}
