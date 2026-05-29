/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:26:29 by aternero          #+#    #+#             */
/*   Updated: 2026/04/30 13:46:26 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	ft_atoi(char *str);

void	customTest(char *a, char *b, char *c)
{
	int	arrayA[3] = { ft_atoi(a), ft_atoi(b), ft_atoi(c) };

	std::cout << "\t\t · · · WITHOUT CONST · · ·\n" << std::endl;
	std::cout << "\t\t ··· PRINT VALUES" << std::endl;
	::iter(arrayA, 3, printValue);
	::iter(arrayA, 3, plusOne);
	std::cout << "\t\t ··· PLUS ONE" << std::endl;
	::iter(arrayA, 3, printValue);

	int const	arrayB[3] = { ft_atoi(a), ft_atoi(b), ft_atoi(c) };
	
	std::cout << "\n\n\n\t\t · · · WITH CONST · · ·\n" << std::endl;
	std::cout << "\t\t ··· PRINT VALUES" << std::endl;
	::iter(arrayB, 3, printValue);
	std::cout << "\t\t🚨 DISCLAIMER: Next, you can try the increment, but it will result in a compilation error." << std::endl;
	std::cout << "\t\tIf you still want to proceed, comment out this custom warning and uncomment " << std::endl;
	std::cout << "\t\tthe lines below that are currently commented out." << std::endl;
	/*
	std::cout << "\t\t ··· PLUS ONE" << std::endl;
	 ::iter(arrayB, 3, plusOne);
	std::cout << std::endl; */
	::iter(arrayB, 3, printValue);
}

void	defaultTest(void)
{
	int	arrayA[3] = {0, 1, 2};

	std::cout << "\t\t · · · WITHOUT CONST · · ·\n" << std::endl;
	std::cout << "\t\t ··· PRINT VALUES" << std::endl;
	::iter(arrayA, 3, printValue);
	::iter(arrayA, 3, plusOne);
	std::cout << "\t\t ··· PLUS ONE" << std::endl;
	::iter(arrayA, 3, printValue);

	int	const	arrayB[3] = {0, 1, 2};
	
	std::cout << "\n\n\n\t\t · · · WITH CONST · · ·\n" << std::endl;
	std::cout << "\t\t ··· PRINT VALUES" << std::endl;
	::iter(arrayB, 3, printValue);
	std::cout << "\t\t🚨 DISCLAIMER: Next, you can try the increment, but it will result in a compilation error." << std::endl;
	std::cout << "\t\tIf you still want to proceed, comment out this custom warning and uncomment " << std::endl;
	std::cout << "\t\tthe lines below that are currently commented out." << std::endl;
	
	/* std::cout << "\t\t ··· PLUS ONE" << std::endl;
	 ::iter(arrayB, 3, plusOne);
	std::cout << std::endl; */
	::iter(arrayB, 3, printValue);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		defaultTest();
	else if (argc == 2 || argc == 3)
	{
		std::cout << "Insufficient arguments to work.\n\n\n" << std::endl;
		defaultTest();
	}
	else if (argc == 4)
		customTest(argv[1], argv[2], argv[3]);
	else
	{
		std::cout << "Error: Too many arguments.\n\n\n" << std::endl;
		defaultTest();
	}
	return (0);
}

/*	UTILS	*/

int	ft_atoi(char *str)
{
	int	index = 0;
	int	nbr = 0;
	int	sign = 1;

	while (isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-') { sign = -1; }
		index++;
	}
	while (isdigit(str[index]))
	{
		nbr = (nbr * 10) +  (str[index] - 48);
		index++;
	}
	return (nbr * sign);
}
