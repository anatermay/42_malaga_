/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/27 13:14:39 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "=== TEST 1: Default Constructor ===" << std::endl;
	ScavTrap	trap1;
	std::cout << std::endl;
	std::cout << "=== TEST 2: Parametrized Constructor ===" << std::endl;
	ScavTrap	trap2("Bot");
	std::cout << std::endl;
	std::cout << "=== TEST 3: Normal Attack (has energy) ===" << std::endl;
	trap2.attack("Enemy");
	std::cout << std::endl;
	std::cout << "··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ···" << std::endl;
	std::cout << "=== TEST 4: Guard Gate Mode === ··· ··· ··· ··· ··· ···" << std::endl;
	trap2.guardGate();
	std::cout << "··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ··· ···\n" << std::endl;
	std::cout << "=== TEST 5: Normal Repair (has energy) ===" << std::endl;
	trap2.beRepaired(3);
	std::cout << std::endl;
	std::cout << "=== TEST 6: Take Damage ===" << std::endl;
	trap2.takeDamage(5);
	std::cout << std::endl;
	std::cout << "=== TEST 7: Drain Energy with multiple attacks ===" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		trap2.attack("Target");
	}
	std::cout << std::endl;
	std::cout << "=== TEST 8: Try to Attack without Energy (should fail) ===" << std::endl;
	trap2.attack("Target");
	std::cout << std::endl;
	std::cout << "=== TEST 9: Try to Repair without Energy (should fail) ===" << std::endl;
	trap2.beRepaired(5);
	std::cout << std::endl;
	std::cout << "=== TEST 10: Take Lethal Damage ===" << std::endl;
	trap2.takeDamage(100);
	std::cout << std::endl;
	std::cout << "=== TEST 11: Try to Act with 0 HP (should fail) ===" << std::endl;
	trap2.attack("Dead");
	trap2.beRepaired(10);
	std::cout << std::endl;
	std::cout << "=== TEST 12: Copy Constructor ===" << std::endl;
	ScavTrap	trap3(trap1);
	std::cout << std::endl;
	std::cout << "=== TEST 13: Assignment Operator ===" << std::endl;
	ScavTrap	trap4;
	trap4 = trap2;
	std::cout << std::endl;
	std::cout << "=== TEST 14: Destruction Order ===" << std::endl;
	{
		ScavTrap	localTrap("LocalBot");
		localTrap.attack("Something");
	}
	std::cout << std::endl;
	std::cout << "=== END OF TESTS (destructors will be called in reverse order) ===" << std::endl;
	return (0);
}
