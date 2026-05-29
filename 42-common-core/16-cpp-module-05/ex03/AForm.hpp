/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:49:05 by aternero          #+#    #+#             */
/*   Updated: 2026/04/10 11:27:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

/*	LIBRARIES	*/

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

/*	DEFINES		*/

# define MAX_GRADE 1
# define MIN_GRADE 150

/*	CLASSES		*/

class AForm
{
	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				signedStatus;
		
	public:
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm() = 0;
		std::string	getName() const;
		int	getSignGrade() const;
		int	getExecuteGrade() const;
		virtual std::string	getTarget() const = 0;
		bool	isSigned() const;
		void	beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		class InvalidGradeToExecute : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class NotSignedToExecute : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};
	
/*	...			*/

std::ostream	&operator<<(std::ostream &os, const AForm &b);
	
#endif
