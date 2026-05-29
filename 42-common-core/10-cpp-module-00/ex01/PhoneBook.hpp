/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:46:39 by aternero          #+#    #+#             */
/*   Updated: 2025/11/04 19:15:52 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// ** LIBRARIES **

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

// ** CLASS **

class Contact
{
	public:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
		void	displayContactName(void)
		{
			std::cout << firstName << " : " << phoneNumber << std::endl;
		}
};

class PhoneBook
{
	public:
		Contact	contactsArray[8];
		int		contactsNumber;
};

#endif