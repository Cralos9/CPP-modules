/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:36:22 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/08 14:58:29 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



int main (int argc, char **argv)
{
	if (argc == 2)
		Bitcoin Teste(argv[1]);
	else
		std::cout << "Error: could not open file." << std::endl;
}