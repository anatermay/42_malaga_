/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:40:16 by aternero          #+#    #+#             */
/*   Updated: 2025/11/17 13:55:20 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	ft_atoi(const char *str)
{
	int	index;
	int	nbr;
	int	sign;

	index = 0;
	nbr = 0;
	sign = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		nbr = (nbr * 10) + (str[index] - '0');
		index++;
	}
	return (nbr * sign);
}

int	main(int argc, char **argv)
{
	Zombie*		horde;
	int			N;
	int			index;

	if (argc != 3)
	{
		std::cout << "ERROR\n\tUsage: ./zombie <N> <name>" << std::endl;
		return (1);
	}
	N = ft_atoi(argv[1]);
	std::cout << "\n\n\n____________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--- --- --- --- --- --- ZOMBIE HORDE --- --- --- --- --- ---    " << std::endl;
	std::cout << "------------------------------------------------------------\n" << std::endl;
	horde = zombieHorde(N, argv[2]);
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--- --- --- --- --- --- ANNOUNCE --- --- --- --- --- ---    " << std::endl;
	std::cout << "------------------------------------------------------------\n" << std::endl;
	index = 0;
	while (index < N)
	{
		horde[index].announce();
		index++;
	}
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--- --- --- --- --- --- DELETE --- --- --- --- --- ---    " << std::endl;
	std::cout << "------------------------------------------------------------\n" << std::endl;
	delete[] horde;
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "____________________________________________________________\n\n\n" << std::endl;
	return (0);
}
