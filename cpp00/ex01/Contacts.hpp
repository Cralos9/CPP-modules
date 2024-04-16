/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:50:24 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/24 12:10:16 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>

# define CLEAR "\033c"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

class Contacts
{
	public:
		Contacts(void);
		Contacts(std::string firstname, std::string lastname, std::string nickname, std::string number, std::string secret);
		void displayContacts(void);
		std::string			getFirstName(void);
		std::string			getLastName(void);
		std::string			getNickname(void);
		static std::string	formatWidth(std::string table);

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
};

#endif
