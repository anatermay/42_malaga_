/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:20:46 by aternero          #+#    #+#             */
/*   Updated: 2025/11/15 14:01:39 by aternero         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

// *** FUNCTIONS *** //

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif