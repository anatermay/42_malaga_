/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:47 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:00:49 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &cont, int nbr)	{
	typename T::iterator	find = std::find(cont.begin(), cont.end(), nbr);
	if (find == cont.end())
		throw ElementAccess();
	return (find);
}
