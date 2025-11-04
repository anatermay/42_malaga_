/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:58:24 by aternero          #+#    #+#             */
/*   Updated: 2025/11/04 20:12:47 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	openFile(PhoneBook &thePhoneBook)
{
	std::string userExit;
	int			userInput;

	std::cout << "\n\t♦ Enter the index of the contact to display or EXIT to cancel: ";
	if (userExit == "EXIT")
		return (-2);
	std::cin >> userInput;
	if (std::cin.eof())
		return (-1);
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t\tInvalid selection" << std::endl;
		return (0);
	}
	std::cin.ignore();
	if (userInput < 1 || userInput > thePhoneBook.contactsNumber)
	{
		std::cout << "\n\t⚠️  Invalid index. Please enter a number between 1 and " << thePhoneBook.contactsNumber << ".\n" << std::endl;
		std::cout << "\tHowever, if you want to cancel, enter EXIT" << std::endl;
		return (0);
	}
	std::cout << "\n\t✓ You selected index: " << userInput << std::endl;
	std::cout << "\n\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << "\t📋 CONTACT DETAILS:" << std::endl;
	std::cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << "\t► First Name: " << thePhoneBook.contactsArray[userInput - 1].firstName << std::endl;
	std::cout << "\t► Last Name: " << thePhoneBook.contactsArray[userInput - 1].lastName << std::endl;
	std::cout << "\t► Nickname: " << thePhoneBook.contactsArray[userInput - 1].nickName << std::endl;
	std::cout << "\t► Phone Number: " << thePhoneBook.contactsArray[userInput - 1].phoneNumber << std::endl;
	std::cout << "\t► Darkest Secret: " << thePhoneBook.contactsArray[userInput - 1].darkestSecret << std::endl;
	std::cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
	return (0);
}

void	phoneBookMenu(std::string userInput, int)
{
	std::cout << "│";
	if (userInput.size() > 10)
	{
		userInput.resize(9);
		std::cout << userInput << ".";
	}
	else
		std::cout << std::setw(10) << userInput;
}

int	searchContacts(PhoneBook &thePhoneBook)
{
	int	index;
	int	yndex;

	std::cout << "\n\t🔍 Searching contacts in the phone book..." << std::endl;
	if (thePhoneBook.contactsNumber == 0)
	{
		std::cout << "\n\t⚠️  The phone book is empty. Please add contacts first.\n" << std::endl;
		return (0);
	}
	std::cout << "\n\t┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "\t│   Index  │First Name│Last Name │ Nickname │" << std::endl;
	std::cout << "\t├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	yndex = 0;
	while (yndex < thePhoneBook.contactsNumber)
	{
		std::cout << "\t│";
		index = thePhoneBook.contactsArray[yndex].index;
		index++;
		std::cout << std::setw(10) << index;
		phoneBookMenu(thePhoneBook.contactsArray[yndex].firstName, yndex);
		phoneBookMenu(thePhoneBook.contactsArray[yndex].lastName, yndex);
		phoneBookMenu(thePhoneBook.contactsArray[yndex].nickName, yndex);
		std::cout << "│" << std::endl;
		yndex++;
	}
	std::cout << "\t└──────────┴──────────┴──────────┴──────────┘\n" << std::endl;
	return (openFile(thePhoneBook));
}

int	userData(Contact &newContact)
{
	while (1)
	{
		std::cout << "\n\t► Enter first name: ";
		std::getline(std::cin, newContact.firstName);
		if (std::cin.eof())
			return (-1);
		if (newContact.firstName.empty())
			std::cout << "\t⚠️  First name cannot be empty. Please try again.\n" << std::endl;
		std::cout << "\t► Enter last name: ";
		std::getline(std::cin, newContact.lastName);
		if (std::cin.eof())
			return (-1);
		if (newContact.lastName.empty())
			std::cout << "\t⚠️  Last name cannot be empty. Please try again.\n" << std::endl;
		std::cout << "\t► Enter nickname: ";
		std::getline(std::cin, newContact.nickName);
		if (std::cin.eof())
			return (-1);
		if (newContact.nickName.empty())
			std::cout << "\t⚠️  Nickname cannot be empty. Please try again.\n" << std::endl;
		std::cout << "\t► Enter phone number: ";
		std::getline(std::cin, newContact.phoneNumber);
		if (std::cin.eof())
			return (-1);
		if (newContact.phoneNumber.empty())
			std::cout << "\t⚠️  Phone number cannot be empty. Please try again.\n" << std::endl;
		std::cout << "\t► Enter darkest secret: ";
		std::getline(std::cin, newContact.darkestSecret);
		if (std::cin.eof())
			return (-1);
		if (newContact.darkestSecret.empty())
			std::cout << "\t⚠️  Darkest secret cannot be empty. Please try again.\n" << std::endl;
		break ;
	}
	return (0);
}

int	addContact(PhoneBook &thePhoneBook, int index)
{
	Contact	newContact;

	std::cout << "\n\t📝 Adding a new contact to the phone book..." << std::endl;
	std::cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	if (userData(newContact) == -1)
		return (-1);
	if (newContact.firstName.empty() || newContact.lastName.empty()
		|| newContact.nickName.empty() || newContact.phoneNumber.empty()
		|| newContact.darkestSecret.empty())
		return (index);
	if (index >= 8)
		index = 0;
	thePhoneBook.contactsArray[index] = newContact;
	thePhoneBook.contactsArray[index].index = index;
	if (thePhoneBook.contactsNumber < 8)
		thePhoneBook.contactsNumber++;
	std::cout << "\n\t★ Contact added successfully! 📱" << std::endl;
	std::cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
	return (index + 1);
}

int	main()
{
	PhoneBook	thePhoneBook;
	std::string command;
	int			index;

	std::cout << "\n\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << "\t🎮 Welcome to your phone book!!! 📲" << std::endl;
	std::cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
	index = 0;
	thePhoneBook.contactsNumber = 0;
	while (1)
	{
		std::cout << "\n\t► Please, select an option: ADD, SEARCH or EXIT.\n\n";
		std::cout << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			index = addContact(thePhoneBook, index);
			if (index == -1)
				break ;
		}
		else if (command == "SEARCH")
		{
			if (searchContacts(thePhoneBook) == -1)
				break ;
		}
		else if (command == "EXIT" || std::cin.eof())
			return (0);
		else
			std::cout << "\n\t❌ Invalid command. Please use: ADD, SEARCH or EXIT.\n" << std::endl;
	}
	return (0);
}
