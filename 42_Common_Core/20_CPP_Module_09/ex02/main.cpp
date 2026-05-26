/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:40:04 by aternero          #+#    #+#             */
/*   Updated: 2026/05/12 16:53:22 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2)   {
        std::cerr << "Error: no arguments." << std::endl;
        return (1);
    }
    try {
        for (int yndex = 1; yndex < argc; yndex++)  {
            if (argv[yndex][0] == '\0')
                throw PmergeMe::InvalidInput();
        }
    }
    catch(const std::exception& e)	{	std::cerr << e.what() << '\n';	return (1);	}
    PmergeMe    toSort;
    toSort.fill(argc, argv);
    toSort.sort();
    toSort.display();
    return (0);
}
