/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:08:17 by aternero          #+#    #+#             */
/*   Updated: 2026/04/13 21:21:46 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
	private:
		AForm	*createPresidential(const std::string &target);
		AForm	*createRobotomy(const std::string &target);
		AForm	*createShrubbery(const std::string &target);
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern	&operator=(const Intern &other);
		AForm	*makeForm(const std::string &formName, const std::string &target);
};

#endif