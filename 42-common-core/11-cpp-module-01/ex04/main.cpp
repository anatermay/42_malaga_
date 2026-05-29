/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/02/02 14:09:50 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedReplace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4 || argv[2] == std::string(""))
	{
		std::cout << "Error\n\t Invalid number of arguments." << std::endl;
		std::cout << "\tUsage: " << argv[0] << " <filename> <string_to_find> <string_to_replace>" << std::endl;
		return (1);
	}
	SedReplacer sedReplacer(argv[1], argv[2], argv[3]);
	sedReplacer.replaceInFile();
	return (0);
}
