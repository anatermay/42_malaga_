/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:13:36 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 21:36:17 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	;
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern()
{
	;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string	forms[3];
	AForm		*(Intern::*creators[3])(const std::string &target) = {
		&Intern::createPresidential,
		&Intern::createRobotomy,
		&Intern::createShrubbery
	};

	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";
	for (int yndex = 0; yndex < 3; yndex++)
	{
		if (forms[yndex] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*creators[yndex])(target));
		}
	}
	std::cout << "Error\nThe requested form type was not found." << std::endl;
	return (NULL);
}

AForm	*Intern::createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
