/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 14:07:42 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*	j = new Dog();
	std::cout << "\n" << "It's a " << j->getType() << " that greets you:" << std::endl;
	j->makeSound();

	std::cout << "\n" << "··· ··· ··· ··· ··· ··· ··· ··· ···" << "\n" << std::endl;

	const Animal*	i = new Cat();
	std::cout << "\n" << "It's a " << i->getType() << " that greets you:" << std::endl;
	i->makeSound();

	std::cout << "\n" << "··· ··· ··· ··· ··· ··· ··· ··· ···" << "\n" << std::endl;

	const Animal*	meta = new Animal();
	meta->makeSound();

	std::cout << "\n" << "··· ··· ··· ··· ··· ··· ··· ··· ···" << std::endl;
	std::cout << "··· ··· ···WRONG ANIMALS··· ··· ···" << std::endl;
	std::cout << "··· ··· ··· ··· ··· ··· ··· ··· ···" << "\n" << std::endl;

	const	WrongAnimal*	x = new WrongAnimal();
	x->makeSound();

	std::cout << "\n" << "··· ··· ··· ··· ··· ··· ··· ··· ···" << "\n" << std::endl;

	const	WrongAnimal*	y = new WrongCat();
	std::cout << "\n" << "It's a " << y->getType() << " that greets you..." << std::endl;
	y->makeSound();
	std::cout << "Ups\n\n\n" << std::endl;

	delete y;
	delete x;
	delete meta;
	delete i;
	delete j;

	return (0);
}
