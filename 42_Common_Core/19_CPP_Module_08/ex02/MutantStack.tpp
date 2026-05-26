/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:53 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:56:13 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()	{ return (this->c.begin()); }

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()	{ return (this->c.end()); }
