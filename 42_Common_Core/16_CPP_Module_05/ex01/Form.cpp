/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:49:02 by aternero          #+#    #+#             */
/*   Updated: 2026/04/09 20:52:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), signGrade(150), executeGrade(150), signedStatus(false)
{
	;
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade), signedStatus(false)
{
	if (this->signGrade < MAX_GRADE || this->executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (this->signGrade > MIN_GRADE || this->executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade),
	  signedStatus(other.signedStatus)
{
	;
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		this->signedStatus = other.signedStatus;
	return (*this);
}

Form::~Form()
{
	;
}

std::string	Form::getName() const
{
	return (this->name);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

int	Form::getExecuteGrade() const
{
	return (this->executeGrade);
}

bool	Form::isSigned() const
{
	return (this->signedStatus);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->signedStatus = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade too low");
}

std::ostream	&operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << ", form sign grade " << f.getSignGrade()
		<< ", form execute grade " << f.getExecuteGrade()
		<< ", signed: " << (f.isSigned() ? "yes" : "no");
	return (os);
}
