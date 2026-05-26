/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:49:41 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 14:05:50 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void	defaultTest(void)
{
	int a = 2;
	int b = 3;

	std::cout << "··· EXPECTED OUTPUT ···" << std::endl;
	std::cout << "a = 3, b = 2" << std::endl;
	std::cout << "min(a, b) = 2" << std::endl;
	std::cout << "max(a, b) = 3" << std::endl;
	std::cout << "c = chaine2, d = chaine1" << std::endl;
	std::cout << "min(c, d) = chaine1" << std::endl;
	std::cout << "max(c, d) = chaine2" << std::endl;
	std::cout << "\n\n\n ··· ··· ··· \n··· ATERNERO'S OUTPUT ···" << std::endl;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		defaultTest();
	else if (argc == 2)
	{
		std::cout << "Insufficient arguments to work.\n\n\n" << std::endl;
		defaultTest();
	}
	else if (argc == 3)
	{
		::swap(argv[1], argv[2]);
		std::cout << "SWAP: a = " << argv[1] << ", b = " << argv[2] << std::endl;
		std::cout << "MIN: min( a, b ) = " << ::min(argv[1], argv[2]) << std::endl;
		std::cout << "MAX: max( a, b ) = " << ::max(argv[1], argv[2]) << std::endl;
	}
	else
	{
		std::cout << "Error: Too many arguments.\n\n\n" << std::endl;
		defaultTest();
	}
	return (0);
}
