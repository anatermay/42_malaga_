/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:40:20 by aternero          #+#    #+#             */
/*   Updated: 2026/05/12 17:17:57 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)	{
	if (argc != 2)	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	try	{	BitcoinExchange	creditCard(argv[1]);	}
	catch (const std::exception &e)	{	std::cout << e.what() << std::endl; return (1);	}
	/* std::cout << "\nBitcoin was officially launched on January 3, 2009, by Satoshi Nakamoto, when he mined the network’s first block, known as the “genesis block.” This milestone marked the beginning of the peer-to-peer (P2P) network and blockchain technology, enabling transactions without financial intermediaries." << std::endl; */
	return (0);
}
