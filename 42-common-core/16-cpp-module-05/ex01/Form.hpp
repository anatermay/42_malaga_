/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:49:05 by aternero          #+#    #+#             */
/*   Updated: 2026/04/09 20:52:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_H
# define FORM_H

/*	LIBRARIES	*/

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

/*	CLASSES		*/

class Form
{
	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				signedStatus;
		
	public:
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();
		std::string	getName() const;
		int	getSignGrade() const;
		int	getExecuteGrade() const;
		bool	isSigned() const;
		void	beSigned(const Bureaucrat &bureaucrat);
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

std::ostream	&operator<<(std::ostream &os, const Form &b);
	
#endif
