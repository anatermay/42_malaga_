/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/07 15:00:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

/*	Binary Space Partitioning (BSP)
	BSP is a technique that recursively divides a space into smaller,
	convex subspaces using hyperplanes as dividers, creating a tree-like data
	structure (BSP tree) that efficiently organizes geometric objects for tasks
	like rendering, collision detection, and visibility determination in
	computer graphics. It helps games and applications quickly figure out what's
	in front of what, optimizing rendering by sorting objects from back-to-front
	or front-to-back, avoiding drawing unnecessary hidden surfaces. 
*/

// *** LIBRARIES *** //

# include <cmath>
# include <iostream>
# include "Fixed.hpp"

// *** CLASS DEFINITION *** //

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;
	public:
		Point();
		Point(float x, float y);
		Point(const Point &other);
		Point	&operator=(const Point &other);
		Fixed	getX() const;
		Fixed	getY() const;
		~Point();
};


// *** ALLOWED FUNCTIONS *** //

//	roundf() - The std::round() in C++ is a standard library function used to
	//	round off the given decimal value which can be in float or double.

// *** FUNCTIONS *** //

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
