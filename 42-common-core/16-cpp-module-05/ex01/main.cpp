/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:57:50 by aternero          #+#    #+#             */
/*   Updated: 2026/04/10 11:00:07 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "\n========================================\n";
	std::cout << title << "\n";
	std::cout << "========================================\n";
}

int	main(void)
{
	printTitle("EX01 - BASIC VALID CASE");
	try
	{
		Bureaucrat	bob("Bob", 42);
		Form		form("Permit", 50, 25);

		std::cout << "OK bureaucrat: " << bob << std::endl;
		std::cout << "OK form:       " << form << std::endl;
		bob.signForm(form);
		std::cout << "After signing:  " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	printTitle("EX01 - BUREAUCRAT CONSTRUCTOR LIMITS");
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

	printTitle("EX01 - FORM CONSTRUCTOR LIMITS");
	try
	{
		Form	invalidHigh("InvalidHigh", 0, 66);
		std::cout << invalidHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception (sign grade 0): " << e.what() << std::endl;
	}
	try
	{
		Form	invalidLow("InvalidLow", 66, 151);
		std::cout << invalidLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception (execute grade 151): " << e.what() << std::endl;
	}

	printTitle("EX01 - SIGNING FLOW");
	try
	{
		Bureaucrat	a("Alice", 70);
		Form		form("TopSecret", 50, 20);

		std::cout << "Start bureaucrat: " << a << std::endl;
		std::cout << "Start form:       " << form << std::endl;
		a.signForm(form);
		std::cout << "After fail:       " << form << std::endl;

		while (a.getGrade() > 50)
			a.raiseTheGrade();
		std::cout << "Promoted bureaucrat: " << a << std::endl;
		a.signForm(form);
		std::cout << "After success:       " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("EX01 - COPY / ASSIGNMENT");
	try
	{
		Bureaucrat	origin("Origin", 60);
		Bureaucrat	copy(origin);
		Bureaucrat	assigned("Assigned", 120);
		Form		base("BaseForm", 40, 30);
		Form		copied(base);
		Form		slot("SlotForm", 80, 80);

		std::cout << "origin:   " << origin << std::endl;
		std::cout << "copy:     " << copy << std::endl;
		std::cout << "assigned: " << assigned << std::endl;
		std::cout << "base:     " << base << std::endl;
		std::cout << "copied:   " << copied << std::endl;
		std::cout << "slot:     " << slot << std::endl;

		assigned = origin;
		std::cout << "assigned after operator=: " << assigned << std::endl;

		slot = base;
		std::cout << "slot after operator=:     " << slot << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("END OF TESTS");
	return (0);
}
