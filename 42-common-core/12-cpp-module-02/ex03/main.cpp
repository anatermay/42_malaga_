/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/08 14:08:58 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iomanip>

void	testPoint(Point const &a, Point const &b, Point const &c, 
				  Point const &point, const std::string &desc, bool expected)
{
	bool	result;
	char	**msg;

	msg = NULL;
	result = bsp(a, b, c, point);
	if (result == true && result == expected)
	{
		std::cout << std::left << std::setw(24) << desc;
		std::cout << " Result: " << "INSIDE" << " [" << "✓ PASS" << "]" << std::endl;
	}
	else if (result == true && result != expected)
	{
		std::cout << std::left << std::setw(24) << desc;
		std::cout << " Result: " << "INSIDE" << " [" << "✗ FAIL" << "]" << std::endl;
	}
	else if (result == false && result == expected)
	{
		std::cout << std::left << std::setw(24) << desc;
		std::cout << " Result: " << "OUTSIDE" << " [" << "✓ PASS" << "]" << std::endl;
	}
	else
	{
		std::cout << std::left << std::setw(24) << desc;
		std::cout << " Result: " << "OUTSIDE" << " [" << "✗ FAIL" << "]" << std::endl;
	}
}

void	tester(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "\n========================================\n";
	std::cout << "  " << "TEST 1: CLEARLY INSIDE POINTS" << "\n";
	std::cout << "========================================\n";
	testPoint(a, b, c, Point(5.0f, 5.0f), "Triangle center (5,5)", true);
	testPoint(a, b, c, Point(5.0f, 2.0f), "Near base (5,2)", true);
	testPoint(a, b, c, Point(3.0f, 3.0f), "Left interior (3,3)", true);
	testPoint(a, b, c, Point(7.0f, 3.0f), "Right interior (7,3)", true);
	std::cout << "\n========================================\n";
	std::cout << "  " << "TEST 2: CLEARLY OUTSIDE POINTS" << "\n";
	std::cout << "========================================\n";
	testPoint(a, b, c, Point(-1.0f, 0.0f), "Left outside (-1,0)", false);
	testPoint(a, b, c, Point(11.0f, 0.0f), "Right outside (11,0)", false);
	testPoint(a, b, c, Point(5.0f, 11.0f), "Top outside (5,11)", false);
	testPoint(a, b, c, Point(5.0f, -1.0f), "Bottom outside (5,-1)", false);
	testPoint(a, b, c, Point(0.0f, 10.0f), "Corner outside (0,10)", false);
	std::cout << "\n========================================\n";
	std::cout << "  " << "TEST 3: POINTS AT VERTICES (must be FALSE)" << "\n";
	std::cout << "========================================\n";
	testPoint(a, b, c, Point(0.0f, 0.0f), "Vertex A (0,0)", false);
	testPoint(a, b, c, Point(10.0f, 0.0f), "Vertex B (10,0)", false);
	testPoint(a, b, c, Point(5.0f, 10.0f), "Vertex C (5,10)", false);
	std::cout << "\n========================================\n";
	std::cout << "  " << "TEST 4: POINTS ON EDGES (must be FALSE)" << "\n";
	std::cout << "========================================\n";
	testPoint(a, b, c, Point(5.0f, 0.0f), "Edge AB middle (5,0)", false);
	testPoint(a, b, c, Point(2.5f, 5.0f), "Edge AC middle (2.5,5)", false);
	testPoint(a, b, c, Point(7.5f, 5.0f), "Edge BC middle (7.5,5)", false);
	testPoint(a, b, c, Point(2.0f, 0.0f), "Edge AB near A (2,0)", false);
	testPoint(a, b, c, Point(8.0f, 0.0f), "Edge AB near B (8,0)", false);
}

int	main(void)
{
	std::cout << "\n========================================\n";
	std::cout << "  " << "VALIDATION SUMMARY" << "\n";
	std::cout << "========================================\n";
	std::cout << "\n✓ INSIDE points tests executed\n";
	std::cout << "✓ OUTSIDE points tests executed\n";
	std::cout << "✓ VERTICES tests (must be FALSE) executed\n";
	std::cout << "✓ EDGES tests (must be FALSE) executed\n";
	std::cout << "Validation according to CPP-02 ex03 subject completed.\n";
	std::cout << "========================================\n\n";
	tester();
	return (0);
}
