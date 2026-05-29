/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:36:59 by aternero          #+#    #+#             */
/*   Updated: 2026/04/22 19:11:33 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*	INCLUDES	*/

# include <stdint.h>
# include <string>
# include "Data.hpp"

/*	DEFINES		*/

/*	CLASSES		*/

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
		Serializer	&operator=(const Serializer &other);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

/*	OTHERS		*/
