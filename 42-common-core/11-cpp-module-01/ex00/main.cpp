/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:21:52 by aternero          #+#    #+#             */
/*   Updated: 2026/02/17 19:13:21 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	ft_printf(const char *str)
{
	std::cout << "\n" << std::endl;
	std::cout << "--- --- --- --- --- --- NEW ZOMBIE --- --- --- --- --- ---    " << std::endl;
	std::cout << "In this path, you'll create a zombie using new and delete.\nDo you remember malloc? 👿" << std::endl;
	std::cout << "------------------------------------------------------------\n" << std::endl;
	Zombie* zombie = newZombie(str);
	delete zombie;
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "\n--- --- --- --- --- --- RANDOM CHUMP --- --- --- --- --- ---" << std::endl;
	std::cout << "Now, try without new 👼" << std::endl;
	std::cout << "------------------------------------------------------------\n" << std::endl;
	randomChump(str);
	std::cout << "\n____________________________________________________________" << std::endl;
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "\n\n\n" << std::endl;
}

int main(int argc, char** argv)
{
	std::string	arg;
	int			index;

	if (argc == 1)
		ft_printf("Default");
	else
	{
		index = 0;
		while (argv[++index])
			ft_printf(argv[index]);
	}
	return (0);
}
