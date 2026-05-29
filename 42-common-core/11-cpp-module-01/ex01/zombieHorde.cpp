/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:40:10 by aternero          #+#    #+#             */
/*   Updated: 2025/11/17 13:56:24 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int		index;

	horde = new Zombie[N];
	index = 0;
	while (index < N)
	{
		horde[index].setName(name, index);
		horde[index].N = N;
		index++;
	}
	return (horde);
}
