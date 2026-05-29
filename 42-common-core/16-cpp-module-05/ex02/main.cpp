/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:29:15 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 21:51:53 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	section(const std::string &title)
{
	std::cout << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

static void	testGrades(void)
{
	section("1) Grade limits");
	try {
		Bureaucrat	ok("OK", 75);
		std::cout << ok << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected: " << e.what() << std::endl;
	}
	try {
		Bureaucrat	tooHigh("TooHigh", 0);
		(void)tooHigh;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "OK: grade 0 -> GradeTooHighException" << std::endl;
	}
	try {
		Bureaucrat	tooLow("TooLow", 151);
		(void)tooLow;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "OK: grade 151 -> GradeTooLowException" << std::endl;
	}
}

static void	testSignAndExec(void)
{
	section("2) Sign and execute (valid case)");
	Bureaucrat	boss("Boss", 1);
	ShrubberyCreationForm	shrub("Garden");
	boss.signForm(shrub);
	boss.executeForm(shrub);
}

static void	testInsufficientGrades(void)
{
	section("3) Insufficient grades (expected failures)");
	Bureaucrat	almost("Almost", 46); // execute robotomy needs 45
	Bureaucrat	intern("Intern", 150); // sign shrubbery needs 145
	RobotomyRequestForm	robot("Bender");
	ShrubberyCreationForm	shrub("Backyard");

	almost.signForm(robot);
	almost.executeForm(robot);
 	intern.signForm(shrub);
}

static void	testUnsignedExecution(void)
{
	section("4) Execute unsigned form (expected failure)");
	Bureaucrat	boss("Boss", 1);
	PresidentialPardonForm	pardon("Criminal");
	boss.executeForm(pardon);
}

static void	testCompleteWorkflow(void)
{
	section("5) Full workflow");
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	intern("Intern", 150);

	ShrubberyCreationForm	shrub("PublicGarden");
	PresidentialPardonForm	pardon("Convict");

	boss.signForm(shrub);
	boss.executeForm(shrub);
	boss.signForm(pardon);
	boss.executeForm(pardon);

	ShrubberyCreationForm	shrub2("Backyard");
	intern.signForm(shrub2);
	intern.executeForm(shrub2);
}

int	main(void)
{

	static bool seeded = false;
	if (seeded == false)
	{
		srand(time(NULL));
		seeded = true;
	}
	section("CPP05 ex02 quick tests");
	testGrades();
	testSignAndExec();
	testInsufficientGrades();
	testUnsignedExecution();
	testCompleteWorkflow();

	section("Done");
	
	return (0);
}
