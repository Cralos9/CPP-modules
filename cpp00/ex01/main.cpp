/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:22:56 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/02 11:49:59 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main_header()
{
	std::cout << CLEAR;
	std::cout << "Available commands:" << std::endl;
	std::cout << "- ADD" << std::endl;
	std::cout << "- SEARCH" << std::endl;
	std::cout << "- EXIT" << std::endl << std::endl;
	return(0);
}

int main(void)
{
	PhoneBook phonebook;
	std::string input;
	int	invalid_command = 0;

	while(1)
	{
		if(!invalid_command)
			main_header();
		std::cout << "Enter a command:";
		std::getline(std::cin, input);
		if(input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break;
		else
		{
			std::cout << "Invalid command" << std::endl;
			invalid_command = 1;
			continue;
		}
		invalid_command = 0;
	}
	std::cout << CLEAR;
}
