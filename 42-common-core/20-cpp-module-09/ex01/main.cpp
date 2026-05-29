/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:40:49 by aternero          #+#    #+#             */
/*   Updated: 2026/05/05 21:00:30 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)	{
	if (argc != 2 || argv[1][0] == '\0')	{
		std::cout << "Invalid number or argments" << std::endl;
		return (1);
	}
	try	{
		RPN	test;
		test.start(argv[1]);
	}
	catch(const std::exception& e)	{	std::cerr << e.what() << '\n';	}
	return (0);
}
