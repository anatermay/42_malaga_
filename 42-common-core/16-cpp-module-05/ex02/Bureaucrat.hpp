/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:58:11 by aternero          #+#    #+#             */
/*   Updated: 2026/04/12 13:48:49 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/*	LIBRARIES	*/

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

/*	CLASSES		*/

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat			&operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string			getName() const;
		int					getGrade() const;
		void				raiseTheGrade();
		void				lowerTheGrade();
		void				signForm(AForm &AForm);
		void				executeForm(AForm const &form) const;

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

/*	FUNCTIONS	*/
std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);

#endif
