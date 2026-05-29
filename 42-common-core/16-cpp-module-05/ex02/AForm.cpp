/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:20:10 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 20:20:13 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), signGrade(150), executeGrade(150), signedStatus(false)
{
	;
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade), signedStatus(false)
{
	if (this->signGrade < MAX_GRADE || this->executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (this->signGrade > MIN_GRADE || this->executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade),
	  signedStatus(other.signedStatus)
{
	;
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->signedStatus = other.signedStatus;
	return (*this);
}

AForm::~AForm()
{
	;
}

std::string	AForm::getName() const
{
	return (this->name);
}

int	AForm::getSignGrade() const
{
	return (this->signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (this->executeGrade);
}

bool	AForm::isSigned() const
{
	return (this->signedStatus);
}


void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->signedStatus = true;
}

const char	*AForm::InvalidGradeToExecute::what() const throw()
{
	return ("AForm: Invalid grade to execute");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade too low");
}

const char	*AForm::NotSignedToExecute::what() const throw()
{
	return ("AForm: is NOT signed.");
}

std::ostream	&operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << ", AForm sign grade " << f.getSignGrade()
		<< ", AForm execute grade " << f.getExecuteGrade()
		<< ", signed: " << (f.isSigned() ? "yes" : "no");
	return (os);
}
