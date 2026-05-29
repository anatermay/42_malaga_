/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:27:16 by aternero          #+#    #+#             */
/*   Updated: 2026/04/22 20:51:22 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*	INCLUDES	*/

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Base.hpp"
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <exception>

using std::cout; using std::endl;

/*	CLASSES		*/

/*	OTHERS		*/

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);
