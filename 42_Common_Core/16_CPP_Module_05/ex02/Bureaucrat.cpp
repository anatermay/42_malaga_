/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:58:45 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 21:47:12 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(42)
{
	;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	;
}

Bureaucrat::~Bureaucrat()
{
	;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	this->grade = other.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::raiseTheGrade()
{
	if (this->grade == MAX_GRADE)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::lowerTheGrade()
{
	if (this->grade == MIN_GRADE)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->name << " signed " << AForm.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << AForm.getName()
			<< " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
