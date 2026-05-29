/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:40:14 by aternero          #+#    #+#             */
/*   Updated: 2025/12/01 15:43:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

// *** LIBRERIES *** //
#include <iostream>
#include <string>

// *** CLASS DEFINITION *** //

class Zombie
{
	private:
		std::string	name;
	public:
		int		index;
		int		N;
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	setName(std::string name, int index);
		void	announce();
};

// *** FUNCTIONS *** //

Zombie* zombieHorde(int N, std::string name);

#endif
