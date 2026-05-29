/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/02/26 18:57:18 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "=== TEST 1: Default Constructor ===" << std::endl;
	ClapTrap	trap1;
	std::cout << std::endl;
	std::cout << "=== TEST 2: Parametrized Constructor ===" << std::endl;
	ClapTrap	trap2("Bot");
	std::cout << std::endl;
	std::cout << "=== TEST 3: Normal Attack (has energy) ===" << std::endl;
	trap2.attack("Enemy");
	std::cout << std::endl;
	std::cout << "=== TEST 4: Normal Repair (has energy) ===" << std::endl;
	trap2.beRepaired(3);
	std::cout << std::endl;
	std::cout << "=== TEST 5: Take Damage ===" << std::endl;
	trap2.takeDamage(5);
	std::cout << std::endl;
	std::cout << "=== TEST 6: Drain Energy with multiple attacks ===" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		trap2.attack("Target");
	}
	std::cout << std::endl;
	std::cout << "=== TEST 7: Try to Attack without Energy (should fail) ===" << std::endl;
	trap2.attack("Target");
	std::cout << std::endl;
	std::cout << "=== TEST 8: Try to Repair without Energy (should fail) ===" << std::endl;
	trap2.beRepaired(5);
	std::cout << std::endl;
	std::cout << "=== TEST 9: Take Lethal Damage ===" << std::endl;
	trap2.takeDamage(100);
	std::cout << std::endl;
	std::cout << "=== TEST 10: Try to Act with 0 HP (should fail) ===" << std::endl;
	trap2.attack("Dead");
	trap2.beRepaired(10);
	std::cout << std::endl;
	std::cout << "=== TEST 11: Copy Constructor ===" << std::endl;
	ClapTrap	trap3(trap1);
	std::cout << std::endl;
	std::cout << "=== TEST 12: Assignment Operator ===" << std::endl;
	ClapTrap	trap4;
	trap4 = trap2;
	std::cout << std::endl;
	std::cout << "=== TEST 13: Destruction Order ===" << std::endl;
	{
		ClapTrap	localTrap("LocalBot");
		localTrap.attack("Something");
	}
	std::cout << std::endl;
	std::cout << "=== END OF TESTS (destructors will be called in reverse order) ===" << std::endl;
	return (0);
}
