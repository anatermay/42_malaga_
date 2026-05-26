/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:12:54 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 18:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	Array<int> empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = static_cast<int>(i * 10);

	Array<int> copied(numbers);
	copied[0] = 999;

	std::cout << "numbers[0]: " << numbers[0] << std::endl;
	std::cout << "copied[0]: " << copied[0] << std::endl;

	Array<std::string> words(2);
	words[0] = "hello";
	words[1] = "world";
	std::cout << words[0] << " " << words[1] << std::endl;

	try	{
		std::cout << numbers[42] << std::endl;
	}
	catch (const std::exception &e)	{
		std::cout << e.what() << std::endl;
	}

	Array<int> assigned;
	assigned = numbers;
	numbers[1] = -1;
	std::cout << "numbers[1]: " << numbers[1] << std::endl;
	std::cout << "assigned[1]: " << assigned[1] << std::endl;

	return 0;
}
