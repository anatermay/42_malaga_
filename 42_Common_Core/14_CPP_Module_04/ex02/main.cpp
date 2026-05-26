/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:37:58 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

static void	testAnimalArray()
{
	Animal*	animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 10; i++)
		delete animals[i];
}

static void	testDeepCopy()
{
	Cat	firstCat;
	Cat	secondCat(firstCat);
	Dog	firstDog;
	Dog	secondDog;

	firstCat.getBrain()->setIdea(0, "sleep");
	secondCat.getBrain()->setIdea(0, "hunt");
	std::cout << "Cat A idea[0]: " << firstCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat B idea[0]: " << secondCat.getBrain()->getIdea(0) << std::endl;

	firstDog.getBrain()->setIdea(1, "run");
	secondDog = firstDog;
	secondDog.getBrain()->setIdea(1, "guard");
	std::cout << "Dog A idea[1]: " << firstDog.getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog B idea[1]: " << secondDog.getBrain()->getIdea(1) << std::endl;
}

int main()
{
	testAnimalArray();
	std::cout << "-----------------------------" << std::endl;
	testDeepCopy();
	return (0);
}
