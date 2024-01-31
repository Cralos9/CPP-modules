/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:59:14 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/31 17:56:23 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_id = 0;
}

PhoneBook::~PhoneBook(void) {}

int ft_isdigit(std::string number)
{
	int i = 0;

	while(number[i])
	{
		if(number[i] < '0' || number[i] > '9')
			return(1);
		i++;
	}
	return(0);
}
void PhoneBook::add(void)
{
	std::string firstname, lastname, nickname, number, secret;
	int	current_id;

	std::cout << CLEAR;
	std::cout << "Type contact information" << std::endl;
	std::cout << "First Name: ";
	std::getline(std::cin, firstname);
	std::cout << "Last Name: ";
	std::getline(std::cin, lastname);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, number);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, secret);

	if (firstname.length() < 1 || lastname.length() < 1 || nickname.length() < 1
		|| number.length() < 9 || secret.length() < 1 || ft_isdigit(number))
		{
			std::cout << RED"Contact not added all information must be filled"RESET << std::endl;
			std::cout << YELLOW"Press ENTER to continue."RESET << std::endl;
			std::cin.ignore();
			return ;
		}
	this->_contacts[this->_id++ % 8] = Contacts(firstname, lastname, nickname, number, secret);
	std::cout << std::endl;
	if (this->_id % 8 == 0)
		current_id = 8;
	else
		current_id = this->_id % 8;
	if (this->_id > 8)
	{
		std::cout << GREEN"Oldest contact was overwritten"RESET << std::endl;
		std::cout << YELLOW"Contact added at memory position "<< current_id << RESET << std::endl;
	}
	else
		std::cout << GREEN"Contact added at memory position " << current_id << RESET<< std::endl;
	std::cout << YELLOW"Press ENTER to continue."RESET << std::endl;
	std::cin.ignore();
}

void PhoneBook::_printTable(void)
{
    int i = -1;
    std::string table;

    std::cout << "|  INDEX   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    while (++i < 8)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|";

        table = this->_contacts[i].getFirstName();
        std::cout << std::setw(10) << Contacts::formatWidth(table) << "|";
        table = this->_contacts[i].getLastName();
        std::cout << std::setw(10) << Contacts::formatWidth(table) << "|";
        table = this->_contacts[i].getNickname();
        std::cout << std::setw(10) << Contacts::formatWidth(table) << "|" << std::endl;
    }
    std::cout << std::endl;
}

void PhoneBook::search(void)
{
	std::string input;
	int	index;
	int	maxIndex;

	if (this->_id > 7)
		maxIndex = 8;
	else
		maxIndex = this->_id;
	if (this->_id == 0)
	{
		std::cout << RED"No contacts added yet."RESET<< std::endl;
		std::cout << YELLOW"Press ENTER to back."RESET << std::endl;
		std::cin.ignore();
		return ;
	}
	this->_printTable();
	std::cout << "Available commands:" << std::endl;
	std::cout << "- Memory Position" << std::endl;
	std::cout << "- BACK" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		index = std::atoi(input.c_str());
		if (input == "BACK")
			break ;
		if (index < 1 || index > maxIndex)
		{
			std::cout << YELLOW"Invalid Position"RESET << std::endl;
			continue ;
		}
		else
		{
			this->_contacts[index - 1].displayContacts();
			std::cout << YELLOW"Press ENTER to continue."RESET << std::endl;
			std::cin.ignore();
			break ;
		}
	}
}
