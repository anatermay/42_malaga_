/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:57:50 by aternero          #+#    #+#             */
/*   Updated: 2026/04/09 15:12:23 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "\n========================================\n";
	std::cout << title << "\n";
	std::cout << "========================================\n";
}

int	main(void)
{
	printTitle("EX00 - BASIC VALID CASE");
	try
	{
		Bureaucrat	bob("Bob", 42);
		std::cout << "OK: " << bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	printTitle("EX00 - CONSTRUCTOR LIMITS");
	try
	{
		Bureaucrat	high("TooHigh", 0);
		std::cout << high << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception (grade 0): " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	low("TooLow", 151);
		std::cout << low << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception (grade 151): " << e.what() << std::endl;
	}

	printTitle("EX00 - INCREMENT / DECREMENT");
	try
	{
		Bureaucrat	a("Alice", 2);
		std::cout << "Start: " << a << std::endl;
		a.raiseTheGrade();
		std::cout << "After raise: " << a << std::endl;
		a.raiseTheGrade();
		std::cout << "This line should not appear: " << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception on raise at grade 1: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	z("Zed", 149);
		std::cout << "Start: " << z << std::endl;
		z.lowerTheGrade();
		std::cout << "After lower: " << z << std::endl;
		z.lowerTheGrade();
		std::cout << "This line should not appear: " << z << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception on lower at grade 150: " << e.what() << std::endl;
	}

	printTitle("EX00 - COPY / ASSIGNMENT");
	try
	{
		Bureaucrat	origin("Origin", 60);
		Bureaucrat	copy(origin);
		Bureaucrat	assigned("Assigned", 120);

		std::cout << "origin:   " << origin << std::endl;
		std::cout << "copy:     " << copy << std::endl;
		std::cout << "assigned: " << assigned << std::endl;

		assigned = origin;
		std::cout << "assigned after operator=: " << assigned << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("END OF TESTS");
	return (0);
}
