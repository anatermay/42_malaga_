/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:45:53 by aternero          #+#    #+#             */
/*   Updated: 2025/11/04 20:24:34 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int yndex = 1; yndex < argc; yndex++)
	{
		for (size_t index = 0; argv[yndex][index]; index++)
			std::cout << static_cast<char>(std::toupper(argv[yndex][index]));
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
