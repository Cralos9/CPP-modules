/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:50:26 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/04 12:05:32 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contacts::Contacts(void) {}

Contacts::Contacts(std::string firstname, std::string lastname, std::string nickname, std::string number, std::string secret)
{
	this->_firstname = firstname;
	this->_lastname = lastname;
	this->_nickname = nickname;
	this->_number = number;
	this->_secret = secret;
}

void Contacts::displayContacts(void)
{
	std::cout << CLEAR;
	std::cout << "First Name: " << this->_firstname << std::endl;
	std::cout << "Last Name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_number << std::endl;
	std::cout << "Darkest Secret: " << this->_secret << std::endl << std:: endl;
}

std::string Contacts::getFirstName(void)
{
	return(this->_firstname);
}

std::string Contacts::getLastName(void)
{
	return(this->_lastname);
}

std::string Contacts::getNickname(void)
{
	return(this->_nickname);
}

std::string Contacts::formatWidth(std::string table)
{
	if (table.length() > 10)
		return (table.substr(0, 9) + ".");
	return(table);
}
