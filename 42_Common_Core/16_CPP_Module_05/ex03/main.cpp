/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:39:05 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 21:51:50 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	Intern			intern;
	Bureaucrat		boss("Boss", 1);
	Bureaucrat		worker("Worker", 150);
	AForm			*presidential = intern.makeForm("presidential pardon", "Arthur");
	AForm			*robotomy = intern.makeForm("robotomy request", "Bender");
	AForm			*shrubbery = intern.makeForm("shrubbery creation", "home");

	static bool seeded = false;
	if (seeded == false)
	{
		srand(time(NULL));
		seeded = true;
	}
	std::cout << boss << std::endl;
	std::cout << worker << std::endl;

	if (presidential)
	{
		worker.signForm(*presidential);
		boss.signForm(*presidential);
		worker.executeForm(*presidential);
		boss.executeForm(*presidential);
		delete presidential;
	}
	if (robotomy)
	{
		boss.signForm(*robotomy);
		boss.executeForm(*robotomy);
		delete robotomy;
	}
	if (shrubbery)
	{
		boss.signForm(*shrubbery);
		boss.executeForm(*shrubbery);
		delete shrubbery;
	}

	return (0);
}
