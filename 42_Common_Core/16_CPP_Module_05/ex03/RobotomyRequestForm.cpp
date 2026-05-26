/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:31:15 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 21:55:16 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Target")
{
	;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
	;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (target);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw (AForm::NotSignedToExecute());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::InvalidGradeToExecute());
	std::cout << "Bzzzzzzzz... drilling noises..." << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed for " << this->getTarget() << std::endl;
}
