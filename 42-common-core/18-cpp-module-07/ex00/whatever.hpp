/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:50:12 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 12:19:23 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/*	INCLUDES	*/

# include <iostream>

/*	TEMPLATES	*/

template <typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T		&min(T &a, T &b)
{
	if (a == b)
		return (b);
	return (a < b ? a : b);
}

template <typename T>
T		&max(T &a, T &b)
{
	if (a == b)
		return (b);
	return (a > b ? a : b);
}

#endif
