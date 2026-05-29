/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:29:34 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 21:39:53 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Target")
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
	;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw (AForm::NotSignedToExecute());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::InvalidGradeToExecute());
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
